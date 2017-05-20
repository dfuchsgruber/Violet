import agb

rom = agb.Agbrom()

offset = rom.pointer(0x738C4)
out = "{\n"
for i in range(0, 48):
    charbase = rom.u32(offset + i * 12)
    pal = rom.u32(offset + i * 12 + 4)
    mapbase = rom.u32(offset + i * 12 + 8)
    out += "\t{" + ", ".join(["(void*)" + hex(val) for val in [charbase, pal, mapbase]]) + "}, //" + hex(i) + "\n"
out += "};\n"
open("D:/temp/attack_anim_bgs.c", "w+").write(out) 