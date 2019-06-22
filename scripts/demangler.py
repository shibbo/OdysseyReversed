# demangler.py
# Demangles a symbol with only the function name
# very barebones, don't expect too much functionality

def demangle(sym):
	demangled = ""

	# if the symbol doesn't start with _Z it is most likely just a function marked external;
	# thus, not mangled at all
	if sym[:2] != "_Z":
		demangled = sym
		return demangled
	# it is possible we are dealing with a standard function with no class nor any external stuff
	# so we need to handle these differently, since the third character will be the length
	elif sym[2].isdigit():
		curPosition = 2
		partLen = ""
		
		while True:
			if sym[curPosition].isdigit():
				partLen += sym[curPosition]
				curPosition += 1
			else:
				break

		return sym[curPosition:curPosition + int(partLen)]
		
	# are we dealing with a function here?
	if sym[:3] == "_ZN":
		isDemangled = True
		isCtorOrDtor = False
		curPosition = 3

		while isDemangled:
			partLen = ""
			# it is possible for there to be more than one character for the length (ie. 15)
			while True:
				if sym[curPosition].isdigit():
					partLen += sym[curPosition]
					curPosition += 1
				else:
					# it is possible that this is a constructor or destructor!
					# we need to get the last part of the symbol since that is the ctor / dtor name
					if sym[curPosition] == "C":
						curSymStrip = demangled.split("::")
						demangled += "::"
						demangled += curSymStrip[-1]
						isCtorOrDtor = True
					elif sym[curPosition] == "D":
						curSymStrip = demangled.split("::")
						demangled += "::~"
						demangled += curSymStrip[-1]
						isCtorOrDtor = True
					break
					
			# if this is a constructor or destructor symbol, we just stop here
			if isCtorOrDtor or partLen == '':
				break
				
			# if we already have our first segment, we append :: onto it and get ready for our next symbol
			if demangled != "":
				demangled += "::"
				
			demangled += sym[curPosition:curPosition + int(partLen)]

			curPosition += int(partLen)
			
		return demangled