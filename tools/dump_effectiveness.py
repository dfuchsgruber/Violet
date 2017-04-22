import agb
import constants

rom = agb.Agbrom()
effectiveness_table = rom.pointer(0x1E8C8)
references = rom.get_references(effectiveness_table)
print(references)
scanning = True
output = ""

while scanning:
    attacker = rom.u8(effectiveness_table)
    if attacker == 0xFF: scanning = False
    try: attacker = constants.type_table[attacker]
    except: attacker = hex(attacker)
    effectiveness_table += 1
    defender = rom.u8(effectiveness_table)
    try: defender = constants.type_table[defender]
    except: defender = hex(defender)
    effectiveness_table += 1
    multiplicator = str(rom.u8(effectiveness_table))
    effectiveness_table += 1
    output += "{" + ", ".join([attacker, defender, multiplicator]) + "},\n"

open("D:/temp/effectiveness.c", "w+").write(output)
open("D:/temp/effectiveness_refs.asm", "w+").write("\n\n".join([".org "+hex(reference + 0x08000000) + "\n\t.word type_effectivenesses" for reference in references]))
