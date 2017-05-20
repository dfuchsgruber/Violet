import agb
import constants

rom = agb.Agbrom()
move_table = rom.pointer(0x3E97C)



output = ""

for i in range(0, len(constants.species_table)):
    moveset = rom.pointer(move_table + i * 4)
    output += "pokemon_move moveset_"+constants.species_table[i].lower()+"[] = {\n"
    while True:
        try: data = rom.u16(moveset)
        except:
            output += "\t{0x1FF, 0x7F}\n"
            break
        if data == 0xFFFF: 
            output += "\t{0x1FF, 0x7F}\n"
            break
        try: move = constants.attack_table[data & 0x1FF]
        except: 
            print("malformed move for pokemon ",constants.species_table[i])
            move = "0"
        level = data >> 9
        if level > 100 : level = 0
        #print(constants.species_table[i], move, level)
        output += "\t{" + move + ", " + str(level) + "},\n"
        moveset += 2
    output += "};\n\n"

output += "\n\n" + ",\n".join(["\tNULL" if i in range(0x19C, 0x1B8) else "\t&moveset_"+constants.species_table[i].lower() for i in range(0, len(constants.species_table))])

open("D:/temp/movesets.txt", "w+").write(output)