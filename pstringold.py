
import sys, getopt, ntpath, os

STATE_NONE = 0
STATE_PLAIN = 1
STATE_ARRAY = 2
STATE_IGNORE = 3
STATE_EXPECT_END = 4


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

def parse_file(content, table, terminator):

	
	line_cnt = 0
	current_symbol = ""
	symbols = {}
	meta = {"plain" : {}, "array" : {}}
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
                                            lan = tokens[2]
                                            current_symbol = tokens[1]
                                            state = STATE_PLAIN #Now we expect plain text
                                    elif(tokens[0] == ".array"):
                                    #Parse array directive
                                            if len(tokens) < 2: raise_parsing_error(line_cnt, "Expected symbol name")
                                            if len(tokens) < 3: raise_parsing_error(line_cnt, "Expected language")
                                            if len(tokens) < 4: raise_parsing_error(line_cnt, "Expected element width")
                                            lan = tokens[2]
                                            try: array_element_width = int(tokens[3], 0)
                                            except: raise_parsing_error(line_cnt, "Invalid element width")
                                            current_symbol = tokens[1]
                                            symbols[current_symbol] = [] #Empty array to collect bytes into
                                            meta["array"][current_symbol] = lan, array_element_width, []
                                            state = STATE_ARRAY

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
                                    meta["plain"][current_symbol] = lan, parse_str(line[1:], table, terminator)
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
                                    meta["array"][current_symbol][2].append(bytes)
                                    symbols[current_symbol] += bytes
		
	
	return meta

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
	
	