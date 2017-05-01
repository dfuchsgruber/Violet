import sys, getopt, ntpath, os

STATE_NONE = 0
STATE_PLAIN = 1
STATE_ARRAY = 2
STATE_IGNORE = 3
STATE_EXPECT_END = 4

def main(argv):
	try:
		opts, args = getopt.getopt(argv, "ht:o:i:a:l:", ["help"])
	except getopt.GetoptError:
		sys.exit(2)
	
	infile = None
	outfile = None
	tablefile = None
	language = None
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
		if opt == "-l":
			language = arg
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
	if not language:
		print("Error: No language specified")
		sys.exit(2)
	
	parse_file(infile, outfile, tablefile, terminator, language)

def print_help():
	print("--String parser for custom encoding--\n\nUsage:\n-o {name}\tOutput file name" \
	+"\n-i {name}\tInput file name\n-t {name}\tTable file\n-a {hex/dec}\tTerminating byte to append [default = 0xFF]\nInput file follows format:" \
	+"\n\tsymbol:\n\t\t=...\nTable file follows format:\n\tsegment = value (.e.g.: 's = 0x44')" \
	+"\n\n\nThe content of a string file is somewhat descriptive\n'.string {symbol_name} {language}\\n=...\\n.end' introduces a new plain string" \
	+"\n'.array {symbol_name} {language} {element_width}\\n=Elem1\\n=Elem2\\n...\\n.end' introduces a new array of same sized strings (filled by terminating byte)"\
	+"\nLines starting with '#' are ignored (use for comments)\nA block is only translated if the language equals the -l param of str2s (not case sensitive)")
	
	
def raise_parsing_error(line, text):
	""" Raises an error during parsing of text """
	raise Exception("Error during parsing line "+str(line)+": "+text)

def raise_parsing_warning(line, text):
	""" Raises and prints a warning during parsing of text"""
	print("Warning during parsing line ", line, ":", text)

def parse_file(infile, outfile, tablefile, terminator, language):
	table = parse_table(tablefile)
	infile = open(infile, "r+")
	content = infile.read()
	infile.close()
	
	line_cnt = 0
	current_symbol = ""
	symbols = {}
	state = STATE_NONE
	array_element_width = None
	
	#now we parse linewise
	expected_string = False
	for line in content.split("\n"):
		line_cnt += 1
		line = line.strip("\n\r\t")
		line = line.lstrip(" ")
		if len(line):
			#parse non empty line
			if not line[0] == '#':  #Ignore comment lines

                            tokens = line.split(" ")
                            if state == STATE_NONE:
                                    #Expect a .string or .array directive
                                    if(tokens[0] == ".string"):
                                            #Parse str directive
                                            if len(tokens) < 2: raise_parsing_error(line_cnt, "Expected symbol name")
                                            if len(tokens) < 3: raise_parsing_error(line_cnt, "Expected language")
                                            if tokens[2].lower() == language.lower() or tokens[2] == "_":
                                                    #Language match, translate the single string block
                                                    current_symbol = tokens[1]
                                                    state = STATE_PLAIN #Now we expect plain text
                                            else:
                                                    state = STATE_IGNORE #Ignore every line until .end directive
                                    elif(tokens[0] == ".array"):
                                    #Parse array directive
                                            if len(tokens) < 2: raise_parsing_error(line_cnt, "Expected symbol name")
                                            if len(tokens) < 3: raise_parsing_error(line_cnt, "Expected language")
                                            if len(tokens) < 4: raise_parsing_error(line_cnt, "Expected element width")
                                            if tokens[2].lower() == language.lower() or tokens[2] == "_":
                                                    #Language match, wait for text inputs
                                                    try: array_element_width = int(tokens[3], 0)
                                                    except: raise_parsing_error(line_cnt, "Invalid element width")
                                                    current_symbol = tokens[1]
                                                    symbols[current_symbol] = [] #Empty array to collect bytes into
                                                    state = STATE_ARRAY
                                            else:
                                                    state = STATE_IGNORE #Ignore every line until .end directive

                                    else: raise_parsing_error(line_cnt, "Unkown directive '"+tokens[0]+"'")
                            elif state == STATE_IGNORE:
                                    #Ignore everything up to an .end directive
                                    if(tokens[0] == ".end"): state = STATE_NONE
                            elif state == STATE_EXPECT_END:
                            #Expect an .end directive
                                    if(tokens[0] != ".end"): raise_parsing_error(line_cnt, "Expected .end directive")
                                    state = STATE_NONE
                            elif state == STATE_PLAIN:
                                    #Expect "="
                                    if(line[0] != "="): raise_parsing_error(line_cnt, "Expected string prefix '='")
                                    symbols[current_symbol] = parse_str(line[1:], table, terminator)
                                    state = STATE_EXPECT_END
                            elif state == STATE_ARRAY:
                            #Expect any number of "=" inputs and fill them up to element width or .end directive
                                    if(tokens[0] == ".end"):
                                    #End of array input feed 
                                            state = STATE_NONE
                                            continue
                                    if(line[0] != "="): raise_parsing_error(line_cnt, "Expected string prefix '='")
                                    bytes = parse_str(line[1:], table, terminator)
                                    while len(bytes) < array_element_width:
                                            bytes.append(terminator)
                                    if len(bytes) > array_element_width:
                                            #Truncate
                                            bytes = bytes[0:array_element_width]
                                            bytes[array_element_width-1] = terminator
                                            raise_parsing_warning(line_cnt, "String exceeds array width, auto-truncated.")
                                    symbols[current_symbol] += bytes
		
	
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
		content += ".global "+symbol+"\n\n"+symbol+":\n\t.byte "
		#Create bytechain
		bytestr = None
		#print(symbols[symbol])
		for byte in symbols[symbol]:
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