# build.py
# Main building script

import sys
sys.path.insert(0, '/scripts/')
from scripts import hook
import os
import re
import platform
import subprocess

# RLTD is size 0x00004000, so this is where we begin our main module
main_starting_addr = 0x00004000
# our size of main is 0x014B1000
main_size = 0x014B1000
# build id is needed to identify IPS patches
build_id = 'B424BE150A8E7D78701CBE7A439D9EBF'
#subsdk0 is after main
subsdk0_size = 0x0071D000

# in order to get to our code starting point, 
# we need to take the start of main, add the size of main, and add the size of the subsdk0
code_addr = main_starting_addr + main_size + subsdk0_size
nso_name = 'subsdk1'
ips_name = build_id + '.ips'

def fatal(msg):
	print(msg)
	sys.exit(1)

def run_proc(cmd):
	cmd_split = re.findall(r'(?:[^\s,"]|"(?:\\.|[^"])*")+', cmd)
	proc = subprocess.Popen(cmd_split, shell=False)
	proc.communicate()
	return proc.wait()

def command_available(cmd):
	test_cmd = "which" if platform.system() != "Windows" else "where"
	try: 
		rc = subprocess.call([test_cmd, cmd], stdout=open(os.devnull, 'wb'), stderr=open(os.devnull, 'wb'))
		return rc == 0
	except: 
		return False
		
def main(argc, argv):
	required_commands = ['make', 'aarch64-none-elf-g++', 'aarch64-none-elf-objdump', 'elf2nso', 'python']

	for cmd in required_commands:
		if command_available(cmd) == False:
			fatal(f"Required command \"{cmd}\" is not available!")
			
	print("Environment ready...")
	
	if 'make' in argv:
		run_proc('make')
		
		print("Correcting incorrect MOD0...")
		
		subprocess.run("tools/nsnsotool OdysseyReversed.nso")

		with open("OdysseyReversed.nso", 'r+b') as nso_file:
			nso = nso_file.read()
			mod0_offset = nso.find(b'MOD0')
			nso_file.seek(mod0_offset + 8)
			bss_start = nso_file.read(4)
			nso_file.seek(mod0_offset + 24)
			nso_file.write(bss_start)
			nso_file.close()
			
		print("Corrected.")
		
	if 'ips' in argv:
		# we need to generate our .sym first
		print("Writing symbol map...")
		with open('output.sym', 'w') as f:
			p = subprocess.Popen('aarch64-none-elf-objdump -t OdysseyReversed.elf', stdout=f, stderr=f)
			p.communicate()
			p.wait()
		
		print("Creating IPS patch...")

		hook.setupHooks("hooks", "output.sym", hex(code_addr - main_starting_addr), ips_name)
	
	if 'clean' in argv:
		run_proc('make clean')
	
if __name__ == '__main__':
	main(len(sys.argv), sys.argv)