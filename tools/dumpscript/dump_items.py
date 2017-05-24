import agb
import pstring
import constants

violet = agb.Agbrom()
bpre = agb.Agbrom(agb.FREPATH)
pstring_factory = pstring.PString("../table.tbl")

ger_item_base = violet.pointer(0x1C8)
en_item_base = bpre.pointer(0x1C8)

item_out = ""
for i in range(0, len(constants.item_table)):
    item_out += "{\n\t//" + constants.item_table[i] + "\n\t"
    ger_off = ger_item_base + 0x2C * i
    en_off = en_item_base + 0x2C * i
    ger_name = [constants.byte_to_pchar(byte) for byte in pstring_factory.str2hex(pstring.decap_by_delimiters(pstring_factory.hex2str(violet, ger_off)))]
    en_name = [constants.byte_to_pchar(byte) for byte in pstring_factory.str2hex(pstring.decap_by_delimiters(pstring_factory.hex2str(bpre, en_off)))]
    ger_name += (["0"] * (14-len(ger_name)))
    en_name += (["0"] * (14-len(en_name)))
    ger_name = "P99_PROCTECT({" + ", ".join(ger_name) + "})"
    en_name = "P99_PROTECT({" + ", ".join(en_name) + "})"
    item_out += "PSTRING(" + ger_name + ", " + en_name + "),\n"
    item_out += "\t" + hex(violet.u16(ger_off + 14)) + ", //index\n"
    item_out += "\t" + str(violet.u16(ger_off + 16)) + ", //price\n"
    item_out += "\t" + str(violet.u8(ger_off + 18)) + ", //holding_effect_id\n"
    item_out += "\t" + str(violet.u8(ger_off + 19)) + ", //holding_effect_param\n"
    item_out += "\tstr_item_desc_" + hex(i)[1:] + "_" + constants.item_table[i].lower() + ",\n"
    item_out += "\t" + str(violet.u16(ger_off + 24)) + ", //field_18\n"
    item_out += "\t" + constants.pockets[(violet.u8(ger_off + 26))] + ", //pocket\n"
    item_out += "\t" + str(violet.u8(ger_off + 27)) + ", //type\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 28)) + ", //field_usage\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 32)) + ", //battle_usage1\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 36)) + ", //battle_usage2\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 40)) + ", //field_28\n"
    item_out += "},"

open("D:/temp/item.c", "w+").write(item_out)

refs = violet.get_references(ger_item_base)
open("D:/temp/item_refs.asm", "w+").write("\n\n".join([".org "+hex(ref + 0x08000000)+"\n\t.word items\n" for ref in refs]))

for i in range(1, 0x1C): 
    if len(violet.get_references(ger_item_base + i)): 
        print(violet.get_references(ger_item_base + i))

    
print(hex(ger_item_base))
