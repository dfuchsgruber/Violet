import agb
import pstring

sfactory = pstring.PString("../table.tbl")
rom = agb.Agbrom()

output = ".array trainerclasses 13"
trainer_class_names_offset = 0x23E428

for i in range(0, 256):
    offset = trainer_class_names_offset + 13 * i
    try:
        c = sfactory.hex2str(rom, offset)
        c = c[0] + c[1:].lower()
        output += "\t="+c.upper()+"\n"
    except Exception as e: 
        print(i)
        print(e)
        break

output += "\n.end\n"

open("D:/temp/trainerclasses.txt", "w+").write(output)
