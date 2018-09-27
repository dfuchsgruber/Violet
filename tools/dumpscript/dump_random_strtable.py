import agb
import pstring

rom = agb.Agbrom()
sfactory = pstring.PString("../table.tbl")

BASENAME = "str_pc_"
TABLE = 0x3D2E50

#FORMAT: {stringpointer, attribute}
"""
strings = []
for i in range(0, 0x1F):
    str_off = rom.pointer(TABLE + i * 8)
    attr = rom.u32(TABLE + 4 + i * 8)
    s = sfactory.hex2str(rom, str_off)
    triple = BASENAME + str(i), attr, s
    strings.append(triple)

fd = open(BASENAME + "patches.asm", "w+")
out = ""
for (name, attr, string) in strings:
    out += ".word " + name + ", " + str(attr) + "\n"
fd.write(out)

fd = open(BASENAME + "strings.txt", "w+")
out = ""
for (name, attr, string) in strings:
    out += ".string " + name + " GER\n\t=" + string + "\n.end\n\n"
    out += ".string " + name + " EN\n\t=" + string + "\n.end\n\n"
fd.write(out)
"""

#FORMAT: {stringpointer}

strings = []
for i in range(0, 0x26):
    str_off = rom.pointer(TABLE + i * 4)
    s = sfactory.hex2str(rom, str_off)
    tuple = BASENAME + str(i), s
    strings.append(tuple)

fd = open(BASENAME + "patches.asm", "w+")
out = ""
for (name, string) in strings:
    out += ".word " + name + "\n"
fd.write(out)

fd = open(BASENAME + "strings.txt", "w+")
out = ""
for (name, string) in strings:
    out += ".string " + name + " GER\n\t=" + string + "\n.end\n\n"
    out += ".string " + name + " EN\n\t=" + string + "\n.end\n\n"
fd.write(out)
