#!/usr/bin/env python3
import os
import pstringold
from pokestring import pstring

table = pstringold.parse_table("table.tbl")
ps = pstring.Pstring("charmap.txt", terminator=0xFF)

class Stream:
    def __init__(self, bytes):
        self.bytes = bytes
    def u8(self, offset):
        return self.bytes[offset]



def magic(filepath):
    with open(filepath, "r") as f:
        content = f.read()
    data = pstringold.parse_file(content, table, 0xFF)
    plain = data["plain"]
    array = data["array"]

    output = ""
    for symbol in plain:
        lan, bytes = plain[symbol]
        stream = Stream(bytes)
        string = ps.hex2str(Stream(bytes), 0)
        output += """
.global {0}

{0}:
    .string {1} "{2}"
        
        """.format(symbol, lan, string)
    
    for symbol in array:

        lan, size, members = array[symbol]
        output += """
.global {0}

{0}:
        """.format(symbol)
        for bytes in members:
            output += "\t.stringpad {0} {1}\n".format(
                lan, int(size) 
            )
    fname, ext = os.path.splitext(filepath)
    fname = fname.replace("_strings", "")

    asfile = fname + ".asm"

    # Create or append
    if os.path.isfile(asfile):
        with open(asfile, "a", encoding="utf-8") as f:
            f.write(output)
        
    else:
        with open(asfile, "w+", encoding="utf-8") as f:
            f.write(output)
    
    os.remove(filepath)



    #if len(array.keys()): print(data)



for root, _, files in os.walk("map"):
        for file in files:
            if file.endswith(".txt"):
                magic(os.path.join(root, file))

for root, _, files in os.walk("./asset/string"):
        for file in files:
            if file.endswith(".txt"):
                try: magic(os.path.join(root, file))
                except Exception as e: 
                    print(os.path.join(root, file))
                    print(e)        



                