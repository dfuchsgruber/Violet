#!/usr/bin/env python3

from pymap import mapheader
import sys

""" Generates a sorted list of all tiles
of the fata morgana feature that
change when the players distance towards
them changes 

Usage: python fata_morgana_gen.py [mappath] [output assembly] [symbol] [symbol number blocks]

"""

def main(args):
    header = mapheader.load(args[0], None, instanciate_ts=False)
    blocks = []
    for y in range(header.footer.height):
        for x in range(header.footer.width):
            block = header.footer.blocks[y][x] & 0x3FF
            if(block < 0x320): continue
            blocks.append((x, y, block))
    
    output = ".global " + args[2] + "\n"
    output += ".global " + args[3] + "\n"
    output += ".align 4\n"
    output += args[3] + ":\n"
    output += ".word " + str(len(blocks)) + "\n\n"
    output += ".align 4\n"
    output += args[2] + ":\n"
    for x, y, block in blocks:
        output += ".hword " + ",".join(map(hex, (x + 7, y + 7, block))) + "\n"
    output += "\n"
    f = open(args[1], "w+")
    f.write(output)
    f.close()
    





if __name__ == "__main__":
    main(sys.argv[1:])