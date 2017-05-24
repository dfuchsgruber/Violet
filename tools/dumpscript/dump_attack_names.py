import agb
import pstring
import constants

#rom = agb.Agbrom()
rom = agb.Agbrom(agb.FREPATH)

pstring_factory = pstring.PString("../table.tbl")

name_base = rom.pointer(0x148)


out = ".array attack_names EN 13\n"

for i in range(0, 353):
    off = name_base + 13 * i
    name = pstring_factory.hex2str(rom, off).replace("_", " ")
    tokens = [token.lower().capitalize() for token in name.split(" ")]
    out += "\t=" + " ".join(tokens) + "\n"

out += ".end\n"

open("D:/temp/attack_names_en.txt", "w+").write(out)