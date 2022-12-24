#!/usr/bin/env python

from pokestring import pstring
from agb import agbrom
from pymap import constants


with open("../../map/proj.pmp.config") as f:
    conf = eval(f.read())["macro"]


vrom = agbrom.Agbrom("../../../violetbuilt.gba")
erom = agbrom.Agbrom("../../base/bpre.gba")
const = constants.Constants("../../map/proj.pmp.constants", conf)
ps = pstring.Pstring("../../charmap.txt")


vtable = 0x149B7D0
etable = 0x44E850


data_out = ""
ger_out = ""
en_out = ""

for i in range(0, 387):
    voff = vtable + i * 0x24
    eoff = etable + i * 0x24

    vs_category = ps.hex2str(vrom, voff).capitalize()
    es_category = ps.hex2str(erom, eoff).capitalize()
    print(i, vs_category, es_category)


    data_out += "{\n\t//Entry " + str(i) + "\n\tLANGDEP(PSTRING(\"{0}\"), PSTRING(\"{1}\")),\n".format(
        vs_category, es_category
    )
    height = vrom.u16(voff + 12)
    weight = vrom.u16(voff + 14)
    data_out += "\t" + str(height) + ", " + str(weight) + ",//Height & weight\n"

    vpage0 = ps.hex2str(vrom, vrom.pointer(voff + 0x10))
    vpage1 = ps.hex2str(vrom, vrom.pointer(voff + 0x14))

    epage0 = ps.hex2str(erom, erom.pointer(eoff + 0x10))
    epage1 = ps.hex2str(erom, erom.pointer(eoff + 0x14))

    ger_out += ".string str_pokedex_data_" + str(i) + "_page_0 GER\n\t=" + vpage0 + "\n.end\n\n"
    ger_out += ".string str_pokedex_data_" + str(i) + "_page_1 GER\n\t=" + vpage1 + "\n.end\n\n"

    en_out += ".string str_pokedex_data_" + str(i) + "_page_0 EN\n\t=" + epage0 + "\n.end\n\n"
    en_out += ".string str_pokedex_data_" + str(i) + "_page_1 EN\n\t=" + epage1 + "\n.end\n\n"
 
    data_out += "\tstr_pokedex_data_" + str(i) + "_page_0, str_pokedex_data_" + str(i) + "_page_1,\n"
    data_out += "\t" + str(vrom.u16(voff + 0x18)) + ",//unused\n"

    poke_scale = vrom.u16(voff + 0x1A)
    poke_displacement = vrom.u16(voff + 0x1C)

    data_out += "\t" + str(poke_scale) + ", " + str(poke_displacement) + ",//Pokemon scale, displacement\n" 

    trainer_scale = vrom.u16(voff + 0x1E)
    trainer_displacement = vrom.u16(voff + 0x20) 

    data_out += "\t" + str(trainer_scale) + ", " + str(trainer_displacement) + ",//Trainer scale, displacement\n"
    data_out += "\t" + str(vrom.u16(voff + 0x22)) + ",//unused\n"
    data_out +="},\n"

"""
fd = open("../asset/string/pokedex/pages_ger.txt", "w+")
fd.write(ger_out)
fd.close()

fd = open("../asset/string/pokedex/pages_en.txt", "w+")
fd.write(en_out)
fd.close()
"""

fd = open("dex_out.txt", "w+")
fd.write(data_out)
fd.close()

