import agb
import pstring

#rom = agb.Agbrom()
rom = agb.Agbrom(agb.FREPATH)

pstring_factory = pstring.PString("../table.tbl")

name_base = rom.pointer(0x144)

out = ".array pokemon_names EN 11\n"
for i in range(0, 411):
    name_off = name_base + i * 11
    name = pstring_factory.hex2str(rom, name_off).lower().capitalize()
    out += "\t=" + name + "\n"
out += ".end\n"

open("D:/temp/pokenames_en.txt", "w+").write(out)
