import sys, getopt, ntpath, os

def main(argv):
	try:
		opts, args = getopt.getopt(argv, "ht:o:i:a:", ["help"])
	except getopt.GetoptError:
		sys.exit(2)
	
	infile = None
	outfile = None
	tablefile = None
	terminator = 0xFF
	
	#Parse the options
	for opt, arg in opts:
		if opt in ("-h", "--help"):
			print_help()
			sys.exit(0)
		if opt == "-i":
			infile = arg
		if opt == "-o":
			outfile = arg
		if opt == "-t":
			tablefile = arg
		if opt == "-a":
			try:
				terminator = int(arg, 0)
				if terminator > 255:
					raise
			except:
				print("Error: '"+arg+"' is not valid byte value to append")
				sys.exit(2)
			
	if not infile:
		print("Error: Missing input file")
		sys.exit(2)
	if not outfile:
		print("Error: Missing output file")
		sys.exit(2)
	if not tablefile:
		print("Error: Missing table file")
		sys.exit(2)

	parse_file(infile, outfile, tablefile, terminator)

def print_help():
	print("--String parser for custom encoding--\n\nUsage:\n-o {name}\tOutput file name" \
	+"\n-i {name}\tInput file name\n-t {name}\tTable file\n-a {hex/dec}\tTerminating byte to append [default = 0xFF]\nInput file follows format:" \
	+"\n\tsymbol:\n\t\t=...\nTable file follows format:\n\tsegment = value (.e.g.: 's = 0x44')" \
	+"\n\n++ use '@create ref' in line before symbol defintion to create reference label (for C files) called '{symbol}_ref'")
	
	
def parse_file(infile, outfile, tablefile, terminator):
	table = parse_table(tablefile)
	infile = open(infile, "r+")
	content = infile.read()
	infile.close()
	
	line_cnt = 0
	symbol = None
	symbols = {}
	create_ref = False
	
	#now we parse linewise
	expected_string = False
	for line in content.split("\n"):
		line = line.strip("\n\r\t")
		line = line.lstrip(" ")
		if len(line):
			#parse non empty line
			if expected_string:
				if line[0] != "=":
					print("Error in line "+str(line_cnt)+": Expected '='")
					sys.exit(1)
				symbols[symbol] = [parse_str(line[1:], table, terminator), create_ref]
				#print(symbols)
				expected_string = False
				create_ref = False
			else:
				if line == "@create ref":
					create_ref = True
					continue
				if line[-1] != ":":
					print("Error in line "+str(line_cnt)+": Expected ':' at end of symbol")
					sys.exit(1)
				symbol = line[:-1]
				expected_string = True
		
		line_cnt += 1
	
	to_s(outfile, symbols)

def parse_str(string, table, terminator):

	bytes = []
	while len(string):
	
		match = None
		for segment in table:
			try:
				index = string.index(segment)
				if not index:
					match = segment
					break
			except:
				pass
		
		if not match:
			print("Error: Could not parse first char in '"+string+"'")
			sys.exit(1)

		string = string[len(match):]
		bytes.append(table[match])

	bytes.append(terminator)
		
	return bytes
	
def to_s(outfile, symbols):
	
	content = ""
	for symbol in symbols:
		if symbols[symbol][1]: #If this is true we create a ref symbol
			content += ".global "+symbol+"_ref\n\n.align 4\n"+symbol+"_ref:\n\t.word "+symbol+"\n\n"
		content += ".global "+symbol+"\n\n"+symbol+":\n\t.byte "
		#Create bytechain
		bytestr = None
		#print(symbols[symbol])
		for byte in symbols[symbol][0]:
			if bytestr:
				bytestr += ", "+str(byte)
			else:
				bytestr = str(byte)
		content += bytestr+"\n\n"
	
	outfile = open(outfile, "w+")
	outfile.write(content)
	outfile.close()
	
def parse_table(tablefile):
	tablefile = open(tablefile, "r+")
	content = tablefile.read()
	table = {}
	for line in content.split("\n"):
		#parse the segments and corresponding values
		tokens = line.split(" ")
		if len(tokens) == 3 and tokens[1] == "=":
			try:
				if(tokens[0] == ''):
					tokens[0] = ' '
				table[tokens[0]] = int(tokens[2], 0)
				if table[tokens[0]] > 255:
					raise
			except:
				print("Error: Invalid byte representation '"+tokens[2]+"' of segment "+tokens[0])
				sys.exit(1)
	tablefile.close()
	return table
	
	
if __name__ == "__main__":
	main(sys.argv[1:])