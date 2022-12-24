import agb
import pstring

pstring_factory = pstring.PString("../table.tbl")

vrom = agb.Agbrom()
erom = agb.Agbrom(agb.FREPATH)

dout = []
eout = []
dbase = vrom.pointer(0x1c0)
ebase = erom.pointer(0x1c0)
for i in range(0, 0x71):
    doff = dbase + 13 * i
    eoff = ebase + 13 * i
    print(i, hex(vrom.pointer(doff)), hex(erom.pointer(eoff)))
    dout.append(pstring_factory.hex2str(vrom, doff).capitalize())
    eout.append(pstring_factory.hex2str(erom, eoff).capitalize() if i < 0x4E else pstring_factory.hex2str(vrom, doff).capitalize())

open("D:/temp/ability_names_ger.txt", "w+").write("\n".join(["="+m for m in dout]))
open("D:/temp/ability_names_en.txt", "w+").write("\n".join(["="+m for m in eout]))
    

    