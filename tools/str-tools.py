import sys, getopt, ntpath, os
import agb

STDINFILE = path=agb.FRDPATH#"C:/Users/Domi/Dropbox/Pokemon Violet/Pokemon Violet.gba"
STDTABLEFILE = "../table.tbl"

def main(argv):
    try:
        opts, args = getopt.getopt(argv, "ht:i:a:", ["help"])
    except getopt.GetoptError:
        print("opterr")
        sys.exit(2)

    infile = STDINFILE
    tablefile = STDTABLEFILE
    terminator = 0xFF
    
    #Parse the options
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print_help()
            sys.exit(0)
        if opt == "-i":
            infile = arg
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
        sys.exit(2)
    if not tablefile:
        print("Error: Missing table file")
        sys.exit(2)

    table, rev_table = parse_table(tablefile)
    print("Table file read.")
    infile = open(infile, "rb")
    bytes = bytearray(infile.read())
    infile.close()
    print("Input file read and buffered.")
    promt(table, rev_table, bytes, terminator)

def promt(table, rev_table, bytes, terminator):
    while True:
        try:
            usr_cmd = input(">>>").split(" ")
            if usr_cmd[0].lower() in ("h", "help"):
                print_help()
            elif usr_cmd[0].lower() in ("f", "findall"):
                pattern = parse_str(usr_cmd[1], table, terminator)
                for occurence in findall(bytes, pattern, rev_table):
                    print("Found at", str(hex(0x8000000+occurence)), "\t", context(bytes, occurence, pattern, rev_table))
            elif usr_cmd[0].lower() in ("r", "replaceall"):
                bytes = replaceall(bytes, parse_str(usr_cmd[1], table, terminator), parse_str(usr_cmd[2], table, terminator), rev_table)
            elif usr_cmd[0].lower() in ("w", "wb", "writeback"):
                f = STDINFILE
                try: f = usr_cmd[1]
                except: pass
                if not f: raise("No output file to writeback!")
                f = open(f, "wb")
                f.write(bytes)
                f.close()
                print("Bytes were written back into file.")
            elif usr_cmd[0].lower() in ("td", "tabledump"):
                #tb offset size cnt outname
                table_dump(bytes, usr_cmd[1], usr_cmd[2], usr_cmd[3], usr_cmd[4], rev_table, terminator)
            elif usr_cmd[0].lower() in ("q", "quit", "e", "exit"):
                sys.exit(0)
            elif usr_cmd[0].lower() in ("fr", "findrefs"):
                pattern = parse_str(usr_cmd[1], table, terminator)
                occurences = findall(bytes, pattern, rev_table)
                for occurence in occurences:
                    print("Found at", str(hex(0x8000000+occurence)), "\t", context(bytes, occurence, pattern, rev_table))
                    refs = findall(bytes, bytearray([occurence & 0xFF, (occurence >> 8) & 0xFF, (occurence >> 16) & 0xFF, ((occurence >> 24) & 0xFF) + 8]), rev_table)
                    for ref in refs: print("\tref at\t" + str(hex(0x08000000 + ref)))
            elif usr_cmd[0].lower() in ("frr", "findrefsandrepoint"):
                pattern = parse_str(usr_cmd[1], table, terminator)
                label = usr_cmd[2]
                xrefs = []
                occurences = findall(bytes, pattern, rev_table)
                for occurence in occurences:
                    print("Found at", str(hex(0x8000000+occurence)), "\t", context(bytes, occurence, pattern, rev_table))
                    refs = findall(bytes, bytearray([occurence & 0xFF, (occurence >> 8) & 0xFF, (occurence >> 16) & 0xFF, ((occurence >> 24) & 0xFF) + 8]), rev_table)
                    xrefs += refs
                    for ref in refs: print("\tref at\t" + str(hex(0x08000000 + ref)))
                for ref in xrefs:
                    print(".org " + str(hex(0x08000000 + ref)))
                    print("\t.word", label)

            elif usr_cmd[0].lower() in ("d", "dump"):
                offset = int(usr_cmd[1], 0)
                if offset > 0x08000000: offset = offset - 0x08000000
                s = "@" + hex(offset) + ":\n\t"
                while True:
                    byte = bytes[offset]
                    s += rev_table[byte]
                    offset += 1
                    if byte == terminator: break
                print(s)
                     
        except Exception as e:
            print(e)

def replaceall(bytes, pattern, pattern_new, rev_table):
    if len(pattern_new) != len(pattern): print("Warning! Patterns differ in length.", pattern, len(pattern), pattern_new, len(pattern_new))
    occurrences = []
    i = -1
    while True:
        j = bytes.find(pattern, i+1)
        if j <= i: break
        i = j
        occurrences.append(i)
    
    for occurence in occurrences:
        print("Found at", str(hex(0x8000000+occurence)), "\t", context(bytes, occurence, pattern, rev_table))
        conf = input(">>> Replace this occurence? [y/n/q=quit]")
        if conf[0] == "y":
            bytes[occurence:occurence+len(pattern)] = pattern_new
        elif conf[0] == "q":
            break
    return bytes
            

def table_dump(bytes, offset, size, cnt, outfile, rev_table, term):
    print(offset, size, cnt, outfile)
    offset = int(offset, 0)
    size = int(size, 0)
    cnt = int(cnt, 0)
    o = ""
    for i in range(0, cnt):
        for j in range(0, size):
            b = int(bytes[offset+(i*size)+j])
            if b == term: break
            o += str(rev_table[b])
        o += " "+str(i)+"\n"
    print("done")
    outfile = open(outfile, "w+")
    outfile.write(o.upper())
    outfile.close()


def context(bytes, off, pattern, rev_table):
    s = ""
    off -= 16
    if off < 0: off = 0
    for i in range(0, len(pattern)+32):
        try:
            s += rev_table[bytes[off+i]]
        except: s += "?"            
    return s
            
def findall(bytes, pattern, rev_table):
    occurrences = []
    i = -1
    while True:
        j = bytes.find(pattern, i+1)
        if j <= i: break
        i = j
        occurrences.append(i)
    return occurrences

    


def print_help():
    print("--String parser for custom encoding--\n\nUsage:\n-o {name}\tOutput file name" \
    +"\n-i {name}\tInput file name\n-t {name}\tTable file\n-a {hex/dec}\tTerminating byte to append [default = 0xFF]\n"
    +"---When entered console you are promted for further commands---\nfindall string\tLists all occurences of string"
    +"\nreplaceall string new\tReplaces all occurences of string with new. Asks for confirmation [y/n]")


def parse_table(tablefile):
    tablefile = open(tablefile, "r+")
    content = tablefile.read()
    table = {}
    rev_table = {}
    for line in content.split("\n"):
        #parse the segments and corresponding values
        tokens = line.split(" ")
        if len(tokens) == 3 and tokens[1] == "=":
            try:
                if(tokens[0] == ''):
                    tokens[0] = ' '
                table[tokens[0]] = int(tokens[2], 0)
                if int(tokens[2], 0) not in rev_table:
                    rev_table[int(tokens[2], 0)] = tokens[0]
                if table[tokens[0]] > 255:
                    raise
            except:
                print("Error: Invalid byte representation '"+tokens[2]+"' of segment "+tokens[0])
                sys.exit(1)
    tablefile.close()
    return table, rev_table

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
        
    return bytearray(bytes)


if __name__ == "__main__":
    main(sys.argv[1:])