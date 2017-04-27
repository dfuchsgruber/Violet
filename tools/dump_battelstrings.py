import agb
import pstring

rom = agb.Agbrom()
factory = pstring.PString("../table.tbl")

strings = []
string_names = []

string_table = rom.pointer(0xCF194)

for i in range(0, 0x187):
    print(i)
    offset = string_table + 4 * i
    strings.append(".string str_battle_x"+hex(i+12)[2:]+" GER\n\t="+factory.hex2str(rom,rom.pointer(offset))+"\n.end")
    string_names.append(".word str_battle_x"+hex(i+12)[2:])

open("D:/temp/battlestrings.txt", "w+", encoding="ascii").write("\n\n".join(strings))
open("D:/temp/battlestring_table.asm", "w+").write("\n\n".join(string_names))

