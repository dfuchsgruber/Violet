import agb
import pstring
import constants

#rom = agb.Agbrom()
pstring_factory = pstring.PString("../table.tbl")
rom = agb.Agbrom("D:/Hacking/1695 - Pokemon Fire Red (U)(Independent).gba")

description_table = rom.pointer(0x1C4)

descriptions = []

for i in range(0, 0x4d):
    ability_descr = rom.pointer(description_table + i * 4)
    descriptions.append(pstring_factory.hex2str(rom, ability_descr))

#Dump the descriptions
lines = [".string ability_descr_"+hex(i)+" EN\n\t="+descriptions[i]+"\n.end\n" for i in range(0, len(descriptions))]
open("D:/temp/ability_descriptions_en.txt", "w+").write("\n\n".join(lines))

lines = [".word ability_descr_"+hex(i) for i in range(0, len(descriptions))]
open("D:/temp/ability_descriptions.asm", "w+").write("\n".join(lines))
