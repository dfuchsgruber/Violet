import agb
import pstring

rom = agb.Agbrom()
ps = pstring.PString("../table.tbl")

def choice(off, items):
    for i in range(items):
        soff = rom.pointer(off + 4 * i)
        print(ps.hex2str(rom, soff))

