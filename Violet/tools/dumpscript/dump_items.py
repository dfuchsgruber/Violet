#!/usr/bin/env python3

from pokestring import pstring
from agb import agbrom
from pymap import constants


with open("../../map/proj.pmp.config") as f:
    conf = eval(f.read())["macro"]


violet = agbrom.Agbrom("../../../violetbuilt.gba")
bpre = agbrom.Agbrom("../../base/bpre.gba")
const = constants.Constants("../../map/proj.pmp.constants", conf)
ps = pstring.Pstring("../../charmap.txt")

ger_item_base = violet.pointer(0x1C8)
en_item_base = bpre.pointer(0x1C8)

item_out = ""
for i in range(0, len(const.values("items"))):
    item_out += "{\n\t//" + const.constantize(i, "items") + "\n\t"
    ger_off = ger_item_base + 0x2C * i
    en_off = en_item_base + 0x2C * i
    ger_name = ps.hex2str(violet, ger_off)
    print(ger_name)
    en_name = ps.hex2str(bpre, en_off)
    print(en_name)
    item_out += "LANGDEP(PSTRING(\"{0}\"), PSTRING(\"{1}\")),\n".format(ger_name, en_name)
    item_out += "\t" + hex(violet.u16(ger_off + 14)) + ", //index\n"
    item_out += "\t" + str(violet.u16(ger_off + 16)) + ", //price\n"
    item_out += "\t" + str(violet.u8(ger_off + 18)) + ", //holding_effect_id\n"
    item_out += "\t" + str(violet.u8(ger_off + 19)) + ", //holding_effect_param\n"
    item_out += "\tstr_item_desc_" + hex(i)[1:] + "_" + const.constantize(i, "items").lower() + ",\n"
    item_out += "\t" + str(violet.u16(ger_off + 24)) + ", //field_18\n"
    item_out += "\t" + const.constantize(violet.u8(ger_off + 26), "item_pockets") + ", //pocket\n"
    item_out += "\t" + str(violet.u8(ger_off + 27)) + ", //type\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 28)) + ", //field_usage\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 32)) + ", //battle_usage1\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 36)) + ", //battle_usage2\n"
    item_out += "\t(void(*)(u8))" + hex(violet.u32(ger_off + 40)) + ", //field_28\n"
    item_out += "},"

with open("items.c", "w+") as f:
    f.write(item_out)
