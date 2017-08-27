import pstring
import agb

rom = agb.Agbrom()
ps = pstring.PString("../table.tbl")

out = ".align 4\n.global map_namespaces\nmap_namespaces:\n" + "\n".join(["\tstr_mapnamespace_" + str(i + 0x58) for i in range(109)]) + "\n\n"
consts = {}

sout = ""

namespaces = 0x3F1504
for i in range(109):
    name = ps.hex2str(rom, rom.pointer(namespaces + i * 4))
    sout += ".string str_mapnamespace_" + str(i + 0x58) + " GER\n\t=" + name + "\n.end\n\n" 
    consts[i + 0x58] = pstring.cap(name)

fd = open("D:/temp/namespaces.txt", "w+")
fd.write(sout)
fd.close()

fd = open("D:/temp/namespaces.s", "w+")
fd.write(out)
fd.close()

fd = open("D:/temp/namespaces_const.py", "w+")
fd.write(str(consts))
fd.close()

fd = open("D:/temp/namespaceptr.s", "w+")
fd.write(rom.pointer_dump(namespaces, "map_namespaces"))
fd.close()
