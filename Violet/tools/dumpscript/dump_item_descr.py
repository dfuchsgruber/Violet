import agb
import pstring
import constants

violet = agb.Agbrom()
bpre = agb.Agbrom(agb.FREPATH)
pstring_factory = pstring.PString("../table.tbl")

ger_item_base = violet.pointer(0x1C8)
en_item_base = bpre.pointer(0x1C8)


ger_out = ""
en_out = ""
for i in range(0, len(constants.item_table)):
    ger_off = ger_item_base + 0x2C * i
    en_off = en_item_base + 0x2C * i
    ger_desc = violet.pointer(ger_off + 20)
    en_desc = bpre.pointer(en_off + 20)
    ger_desc = pstring_factory.hex2str(violet, ger_desc)
    en_desc = pstring_factory.hex2str(bpre, en_desc)
    ger_out += ".string str_item_desc_" + hex(i)[1:] + "_" + constants.item_table[i].lower() + " " + "GER\n"
    ger_out += "\t=" + ger_desc + "\n\.end\n\n"
    en_out += ".string str_item_desc_" + hex(i)[1:] + "_" + constants.item_table[i].lower() + " " + "EN\n"
    en_out += "\t=" + en_desc + "\n\.end\n\n"

header = "\n".join(["extern u8 str_item_desc_" + hex(i)[1:] + "_" + constants.item_table[i].lower() + "[];" for i in range(0, len(constants.item_table))])

open("D:/temp/item_desc_ger.txt", "w+").write(ger_out)
open("D:/temp/item_desc_en.txt", "w+").write(en_out)
open("D:/temp/item_desc.h", "w+").write(header)