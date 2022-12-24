import agb

rom = agb.Agbrom()

bsc_table = rom.pointer(0x162E8)
bscs = ""

for i in range(0, 256):
    bsc = rom.u32(bsc_table + i * 4)
    bscs += (".word "+hex(bsc) + "@"+hex(i)+"\n")

open("D:/temp/attack_bscs.asm", "w+").write(bscs)

refs = rom.get_references(bsc_table)
open("D:/temp/attack_bscs_refs.asm", "w+").write("\n\n".join([".org "+hex(off + 0x08000000)+"\n\t.word attack_effects\n" for off in refs]))

