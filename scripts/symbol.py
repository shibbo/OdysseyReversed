from . import demangler as d

class SymbolTable():
	def __init__(self):
		self.func_dict = dict()
	
	def __getitem__(self, key):
		address = self.func_dict.get(key)
		return address
		
	def add(self, name, address):
		self.func_dict[name] = address + 0x1BD2000
		
	def doesKeyExist(self, name):
		if name in dict.keys():
			return True
		else:
			return False
		
	def getDict(self):
		return self.func_dict
		
	@staticmethod
	def appendSymbols(path):
		table = SymbolTable()
		
		with open(path, "r") as f:
			lines = f.readlines()

		i = 0
		isValidMap = False

		for line in lines:
			# we want to skip the first 4 lines
			if i == 3:
				if line.startswith('SYMBOL TABLE:'):
					isValidMap = True
					continue
					
			i += 1
					
			if isValidMap:
				new_line = line.replace(r'\ŧ', ' ')
				new_line = new_line.strip('\r')
				new_line = new_line.strip('\n')
				
				line_strip = new_line.split(' ')
				
				if line_strip[0] == '':
					continue
					
				func_address = int(line_strip[0], 0x10)
				
				# our function name is always the last element
				func_name = line_strip[len(line_strip) - 1]

				if len(func_name) == 0:
					continue

				demangled_sym = d.demangle(func_name)

				if demangled_sym == None or demangled_sym == '':
					continue
					
				table.add(demangled_sym, func_address)
				
		return table