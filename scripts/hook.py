# hook.py by RicBent
# System for processing .hks files for creating patches

import sys
import os
import struct
import re
import subprocess
import binascii

from . import arm
from . import ips
from . import nso
from . import symbol

def fatal(msg):
	print(msg)
	sys.exit(1)

def run_proc(cmd):
	proc = subprocess.Popen(cmd.split(), shell=False)
	proc.communicate()
	return proc.wait()
	
class HookException(Exception):
	def __init__(self, hook, message):
		super().__init__(message)
		self.hook = hook

class Hook():
	def __init__(self, type, path, line, name, dict):
		self.type = type
		self.name = name
		self.path = path
		self.line = line

		address_found = False
		try:
			for key in ['address', 'addr']:
				if key in dict:
					self.address = int(dict[key], 0)
					address_found = True
					break
		except ValueError:
			raise Exception('Parsing address failed')
		if address_found == False:
			raise Exception('No address given')

	def write_ips(self, stream, sym_table):
		raise NotImplementedError('Pure virtual function called')


	@staticmethod
	def parse_symbol(dict):
		for key in ['symbol', 'sym', 'function', 'func']:
			if key in dict:
				return dict[key]
		raise Exception('No symbol given')
	
	@staticmethod
	def from_data(path, line, name, dict):
		if not 'type' in dict:
			raise Exception('No type given')

		hook_type = dict['type']
		
		branch_hook_types = [		 
			'b', 'beq', 'bne', 'bcs', 'bcc', 'bmi', 'bpl', 'bvs', 'bvc', 'bhi', 'bls', 'bge', 'blt', 'bgt', 'ble', 'bal',
			'bl', 'bleq', 'blne', 'blcs', 'blcc', 'blmi', 'blpl', 'blvs', 'blvc', 'blhi', 'blls', 'blge', 'bllt', 'blgt', 'blle', 'blal'
		]

		if hook_type in branch_hook_types:
			return BranchHook(hook_type, path, line, name, dict)

		if hook_type in ['patch', 'data']:
			return PatchHook(hook_type, path, line, name, dict)

		if hook_type == 'nop':
			return NopHook(hook_type, path, line, name, dict)

		if hook_type in ['instruction', 'instr']:
			return InstructionHook(hook_type, path, line, name, dict)

		raise Exception('Invalid hook type \"%s\"' % hook_type)


class BranchHook(Hook):
	def __init__(self, type, path, line, name, dict):
		super().__init__(type, path, line, name, dict)
		self.symbol = Hook.parse_symbol(dict)

	def write_ips(self, stream, sym_table):
		dst_addr = sym_table[self.symbol]

		if dst_addr == None:
			raise HookException(self, f"Symbol \"{self.symbol}\" not found!")
		
		link = self.type.startswith('bl')
		condition = self.type[2 if link else 1:]
		instruction = arm.make_branch_instruction(self.address, dst_addr, link)

		ips.writeRec(stream, self.address + nso.NsoHeader().size, instruction)


class PatchHook(Hook):
	def __init__(self, type, path, line, name, dict):
		super().__init__(type, path, line, name, dict)

		if not 'data' in dict:
			raise Exception('Patch data not specified!')

		data_str = dict['data']
		data_segs = data_str.split(':')

		data_types_int = {
			's8':	'b',
			'u8':	'B',
			's16':	'h',
			'u16':	'H',
			's32':	'i',
			'u32':	'I',
			's64':	'q',
			'u64':	'Q'
		}

		data_types_float = {
			'f32':	'f',
			'f64':	'd'
		}

		if len(data_segs) == 2:

			type_str = data_segs[0].strip()
			data_str = data_segs[1].strip()

			try:
				if type_str in data_types_int:
					self.data = struct.pack('<%s' % data_types_int[type_str], int(data_str, 0))
				elif type_str in data_types_float:
					self.data = struct.pack('<%s' % data_types_float[type_str], float(data_str))
				else:
					raise Exception('Invalid data type!')
			except ValueError:
				raise Exception('Parsing data failed!')

		elif len(data_segs) == 1:
			try:
				self.data = binascii.unhexlify(dict['data'])
			except:
				raise Exception('Prasing patch data failed!')
			if len(self.data) == 0:
				raise Exception('Patch data may not be empty!')

		else:
			raise Exception('Patch data is invalid!')

	def write_ips(self, stream, sym_table):
		ips.writeRec(stream, self.address + nso.NsoHeader().size, self.data)

class InstructionHook(Hook):
	def __init__(self, type, path, line, name, dict):
		super().__init__(type, path, line, name, dict)

		instruction_found = False
		for key in ['instruction', 'instr']:
			if key in dict:
				self.instruction = dict[key]
				instruction_found = True
				break

		if instruction_found == False:
			raise Exception('Instruction not specified!')

	def write_ips(self, stream, sym_table):
		ips.writeRec(stream, self.address + nso.NsoHeader().size, arm.assemble_instruction(self.instruction))

class NopHook(Hook):
	def __init__(self, type, path, line, name, dict):
		super().__init__(type, path, line, name, dict)

	def write_ips(self, stream, sym_table):
		ips.writeRec(stream, self.address + nso.NsoHeader().size, "1F2003D5")

def loadHooks(path):
	hooks = []

	f = open(path, "r")

	curr_name = ''
	curr_dict = {}
	curr_hook_line = -1

	for line_idx, line in enumerate(f):
		
		try:
			comment_start = line.index('@')
			line_sanitized = line[:comment_start]
		except:
			line_sanitized = line
			pass

		line_sanitized = line_sanitized.replace('\t', ' ')
		line_sanitized = line_sanitized.replace('\r', '')
		line_sanitized = line_sanitized.replace('\n', '')

		if not line_sanitized.startswith(' '):

			line_sanitized = line_sanitized.replace(':', '')
			line_sanitized = line_sanitized.replace('=', '')
			line_sanitized = line_sanitized.strip()

			if line_sanitized != '':
				# new hook
				if curr_name != '':
					try:
						hooks.append(Hook.from_data(path, curr_hook_line, curr_name, curr_dict))
					except Exception as e:
						print(f"{path}:{curr_hook_line}: parsing hook \"{curr_name}\" failed: {str(e)}")
						sys.exit(1)

				curr_name = line_sanitized
				curr_dict = {}
				curr_hook_line = line_idx + 1

		else:
			line_sanitized = line_sanitized.strip()

			try:
				space_idx = line_sanitized.index(' ')
				colon_idx = line_sanitized.rfind(':', 0, space_idx)
				if colon_idx > 0 and colon_idx < space_idx:
					line_sanitized[colon_idx] = ' '
			except:
				line_sanitized = line_sanitized.replace(':', ' ', 1)
				pass

			try:
				idx = line_sanitized.index(' ')
				key = line_sanitized[:idx].lower()
				value = line_sanitized[idx:].lstrip()
				curr_dict[key] = value
			except:
				pass
	
	if curr_name != '':
		try:
			hooks.append(Hook.from_data(path, curr_hook_line, curr_name, curr_dict))
		except Exception as e:
			print(f"{path}:{curr_hook_line}: parsing hook \"{curr_name}\" failed: {str(e)}")
			sys.exit(1)
		
	f.close()

	return hooks
	
def setupHooks(hooksPath, symbolMap, symbolAddr, outIPS):
	# Parse relocate symbol table
	if os.path.isfile(symbolMap) == False:
		fatal("Symbol table file does not exist!")

	try:
		sym_offset = int(symbolAddr, 0)
	except:
		fatal("Symbol table offset is invalid!")

	try:
		sym_table = symbol.SymbolTable.appendSymbols(symbolMap)
	except:
		fatal('Opening symbol table failed!')

	# Load hooks
	hks_path = hooksPath

	hooks = []

	if os.path.isfile(hks_path):
		hooks += loadHooks(hks_path)
	
	elif os.path.isdir(hks_path):
		for file in os.listdir(hks_path):
			hks_file = os.fsdecode(file)
			if hks_file.endswith(".hks"): 
				hooks += loadHooks(os.path.join(hks_path, hks_file))

	else:
		fatal("Hooks path is invalid!")

	# Apply hooks
	out_path = outIPS

	try:
		out_file = open(out_path, "wb")
	except:
		fatal('Opening output file failed!')

	ips.writeHeader(out_file)
	
	for hook in hooks:
		try:
			hook.write_ips(out_file, sym_table)
		except Exception as e:
			print(f"{hook.path}:{hook.line}: applying hook \"{hook.name}\" failed: {str(e)}")
			sys.exit(1)
	
	ips.writeEOF(out_file)

	out_file.close()

	print(f"Hook IPS written to {out_path}")