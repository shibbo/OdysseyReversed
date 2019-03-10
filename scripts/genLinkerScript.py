# genLinkerScript.py
# Generates a linker script based on a given symbol map and base address offset
import sys

symbolExceptions = [ "_init", "_fini", "__nnDetailNintendoSdkRuntimeObjectFileRefer", "__nnDetailNintendoSdkRuntimeObjectFile", "__nnDetailNintendoSdkNsoFileRefer" ]
symbolPrefixes = [ 
					"Curl", # some curl stuff
					"curl", # moar curl
					"_ZG",  # guards
					"_ZN",  # regular variables
					"_ZT",  # typeinfo / vtables
					"_ZZ",
					"pfnc_",
					"mem",
					"str"
]

if len(sys.argv) < 3:
	print("Syntax: genLinkerScript.py <map> <sizeFromMain>\n")
	sys.exit()

# open our map file
with open(sys.argv[1], "r") as f:
	lines = f.readlines()
	
# we need to skip a few lines first
curLine = 0

# open our new generated linker
with open("syms.ld", "w") as linker:
	for line in lines:
	
		# skip the first 4 useless lines
		if curLine < 4:
			curLine += 1
			continue

		# each line is structured as such:
		#  00000000:0000007100000160       _fini
		firstSplit = line.split(" ")
		
		addressSplit = firstSplit[1].split(":")
		address = addressSplit[1]
		
		symbolName = firstSplit[8]
		symbolName = symbolName.strip("\n\r")
		
		# the last few numbers are important, the higher ones are not
		address = address[9:]
		address = "0x" + address

		isValid = False
	
		# we check to see if this symbol has a prefix that we need to keep
		for i in range(9):
			if symbolName.startswith(symbolPrefixes[i]):
				isValid = True
				break
		
		if symbolName in symbolExceptions:
			isValid = True
		
		if not isValid:
			continue

		# sdk functions have a _0 at the end because they are duplicated due to the originals being imported
		# so IDA adds a _0 at the end...we need to strip this
		if "_ZN2nn" in symbolName:
			symbolName = symbolName.strip("_0")
		
		linker.write(f"{symbolName} = {address} - {sys.argv[2]};\n")
	
print("Linker script generated.")