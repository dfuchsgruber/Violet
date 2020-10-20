import agb
import constants

rom = agb.Agbrom()
attack_anims = rom.pointer(0x72534)

out = ""
for i in range(0, len(constants.attack_table)):
    script_off = rom.u32(attack_anims + i * 4)
    out += ".word " + hex(script_off) + " @//" + constants.attack_table[i].lower() + "\n"

open("D:/temp/attack_anims.asm", "w+").write(out)

refs = rom.get_references(attack_anims)
open("D:/temp/attack_anims_refs.asm", "w+").write("\n\n".join([".org " + hex(ref) + "\n\t.word attack_anims" for ref in refs]))