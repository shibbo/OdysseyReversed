# genLinkerScript.py
# Generates a linker script based on a given symbol map and base address offset
import sys

symbolExceptions = [ 
					"_init", 
					"_fini", 
					"__nnDetailNintendoSdkRuntimeObjectFileRefer", 
					"__nnDetailNintendoSdkRuntimeObjectFile", 
					"__nnDetailNintendoSdkNsoFileRefer",
					"hysteresis_decision",
					"celt_lcg_rand",
					"compute_band_energies",
				]
symbolPrefixes = [ 
					"Curl", # some curl stuff
					"curl", # moar curl
					"_Z",   # literally everything
					"pfnc_",
					"mem",
					"str",
					"alloc",
					"free",
					"nndetailCrypto",
					"nnutil",
					"Libz",
					"nnmem",
					"nnos",
					"nnsocket",
					"celt",
					"encode",
					"ec",
					"opus",
					"silk",
					"nnssl",
					"FS",
					"FSS",
					"fs",
					"fnt",
					"fsg",
					"nnfont",
					"nvcec",
					"nvdc",
					"hdcp",
					"Nv",
					"app",
					"glslc",
					"multimedia",
					"cuda",
					"nvgr",
					"nngpio",
					"nvn",
					"nn",
					"pthread",
					"sem",
					"__nnmusl",
					"jpeg",
					"video",
					"TVMR",
					"aacDecoder",
					"FDK",
					"pcmDmx",
					"sbrDecoder",
					"voAAC",
					"Bitstream",
					"PV"
	]

if len(sys.argv) < 3:
	print("Syntax: genLinkerScript.py <map> <type>\n")
	print("Types: main, subsdk0, sdk")
	sys.exit()

# open our map file
with open(sys.argv[1], "r") as f:
	lines = f.readlines()
	
# we need to skip a few lines first
curLine = 0

nameSplit = sys.argv[1].split(".")
fileName = nameSplit[0]

# open our new generated linker
with open(f"{fileName}.ld", "w") as linker:
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
		for prefix in symbolPrefixes:
			if symbolName.startswith(prefix):
				isValid = True
				break
		
		if symbolName in symbolExceptions:
			isValid = True
		
		if not isValid:
			continue

		# we need to strip _0 at the end since IDA generates this for some reason
		if symbolName.endswith("_0"):
				symbolName = symbolName[:-2]
				
		type = sys.argv[2]
		
		if type == "main":
			linker.write(f"{symbolName} = {address} - 0x01BCE000;\n")
		elif type == "subsdk0":
			linker.write(f"{symbolName} = {address} - 0x0071D000;\n")
		elif type == "sdk":
			linker.write(f"{symbolName} = {address} - __sdk_start;\n")
		else:
			print("Unknown NSO type!")
			sys.exit(1)
	
print("Linker script generated.")