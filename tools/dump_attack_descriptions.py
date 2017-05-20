import agb
import constants
import pstring

pstring_factory = pstring.PString("../table.tbl")

rom = agb.Agbrom("D:/Hacking/bprd.gba")
#rom = agb.Agbrom(agb.FREPATH)

desc_table = rom.pointer(0x137c64)
#desc_table = rom.pointer(0x137c40)

out = ""

for i in range(0, 354):
    str_off = rom.pointer(desc_table + i * 4)
    out += ".string str_attack_desc_" + constants.attack_table[i+1].lower() + " GER\n\t=" + pstring_factory.hex2str(rom, str_off) + "\n.end\n\n"

open("D:/temp/attack_descr_de.txt", "w+").write(out)

out = ""
for i in range(0, len(constants.attack_table)):
    out += "\t.word str_attack_desc_" + constants.attack_table[i].lower() + "\n"

open("D:/temp/attack_descr_refs.asm", "w+").write(out)