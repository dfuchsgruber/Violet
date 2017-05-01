import agb
import pstring

sfactory = pstring.PString("../table.tbl")
rom = agb.Agbrom()
#rom = agb.Agbrom(agb.FREPATH)

output = ".array trainerclasses 13 GER\n"
trainer_class_names_offset = 0x23E428
#trainer_class_names_offset = 0x23E5C8

for i in range(0, 256):
    if not i % 4: output += "\t#"+hex(i)+"\n"
    offset = trainer_class_names_offset + 13 * i
    try:
        c = sfactory.hex2str(rom, offset)
        tokens = [token.lower().capitalize() for token in c.split("_")]



        output += "\t="+" ".join(tokens).replace("\\  ", "\\__")+"\n"
    except Exception as e: 
        print(i)
        print(e)
        break

output += "\n.end\n"

open("D:/temp/trainerclasses_de.txt", "w+").write(output)

refs = rom.get_references(trainer_class_names_offset)

open("D:/temp/trainerclasses_refs.asm", "w+").write("\n\n".join([".org "+hex(ref)+"\n\t.word trainerclasses" for ref in refs]))
