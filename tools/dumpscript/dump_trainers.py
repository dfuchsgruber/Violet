import agb
import constants

rom = agb.Agbrom()
trainer_base = 0x23E998

trainers = []
parties = []
headers = []

def pchar_to_str(c):
    for pchar in constants.pchar_dict:
        if constants.pchar_dict[pchar] == c: return pchar
    return hex(c)
    

def ai_to_str(ai):
    strategies = []
    for i in range(0, 32):
        if ai & (1 << i):
            try: strategies.append(constants.trainer_ai[i])
            except: strategies.append(hex(1 << i))
    if len(strategies): return " | ".join(strategies)
    else: return "TRAINER_AI_STRATEGY_NONE"


for i in range(0, 0x2E7):
    offset = trainer_base + i * 0x28
    trainer = "{\n\t//Trainer "+hex(i)+"\n"
    structure = rom.u8(offset) & 3
    trainer += "\t"+("true" if structure & 1 else "false") + ",//Custom moves\n"
    trainer += "\t"+("true" if structure & 2 else "false") + ",//Custom items\n"
    trainer += "\t"+hex(rom.u8(offset) >> 2) + ",//field_0_filler\n"
    trainer += "\t"+constants.trainerclasses[rom.u8(offset+1)]+",\n"
    trainer += "\t{"+hex(rom.u8(offset+2) & 0x7F)+", "+("true" if rom.u8(offset+2) & 0x80 else "false") + "},//Encounter and gender\n"
    trainer += "\t"+hex(rom.u8(offset+3))+",//sprite\n"

    #Name as PCHAR ARRAY
    trainer += "\t{" + ", ".join([pchar_to_str(rom.u8(offset+4+j)) for j in range(0, 12)]) + "},\n"
    trainer += "\t{" + ", ".join([constants.item_table[rom.u8(offset+16+2*j)] for j in range (0, 4)])+"},\n"
    trainer += "\t" +("true" if rom.u32(offset+24) else "false") + ",//Dual battle\n"
    trainer += "\t" + ai_to_str(rom.u16(offset+28)) + ",\n"
    trainer += "\t" + hex(rom.u16(offset+30)) + ",//field_1E\n"
    pokemon_cnt = rom.u8(offset+32)
    trainer += "\t" + str(pokemon_cnt) + ",//Pokemon Count\n"
    trainer += "\t" + hex(rom.u8(offset+33)) + ",//field_21\n"
    trainer += "\t" + hex(rom.u8(offset+34)) + ",//field_22\n"
    trainer += "\t" + hex(rom.u8(offset+35)) + ",//field_23\n"
    trainer += "\t(trainer_pokemon*) trainer_party_"+hex(i)[1:]+"\n"
    #trainer += "\tNULL\n"
    trainer += "}"

    party_offset = rom.pointer(offset+36)

    #Build the party
    pkmns = []
    for j in range(0, pokemon_cnt):
        pkmn = ""
        if structure == 0:
            #default item, default attack
            pkmn += "\tTRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES("
            pkmn += ",".join([
                hex(rom.u8(party_offset) & 31),
                hex((rom.u8(party_offset) >> 5) & 1),
                ("true" if (rom.u8(party_offset) >> 6) & 1 else "false"),
                ("true" if (rom.u8(party_offset) >> 7) & 1 else "false"),
                str(rom.u8(party_offset+2)), #level
                constants.species_table[rom.u16(party_offset+4)]
            ])
            pkmn += ")"
            party_offset += 8
        elif structure == 2:
            #custom item, default attack
            pkmn += "\tTRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES("
            pkmn += ",".join([
                hex(rom.u8(party_offset) & 31),
                hex((rom.u8(party_offset) >> 5) & 1),
                ("true" if (rom.u8(party_offset) >> 6) & 1 else "false"),
                ("true" if (rom.u8(party_offset) >> 7) & 1 else "false"),
                str(rom.u8(party_offset+2)), #level
                constants.species_table[rom.u16(party_offset+4)],
                constants.item_table[rom.u16(party_offset+6)]
            ])
            pkmn += ")"
            party_offset += 8
        elif structure == 1:
            #default item, custom attack
            pkmn += "\tTRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES("
            pkmn += ",".join([
                hex(rom.u8(party_offset) & 31),
                hex((rom.u8(party_offset) >> 5) & 1),
                ("true" if (rom.u8(party_offset) >> 6) & 1 else "false"),
                ("true" if (rom.u8(party_offset) >> 7) & 1 else "false"),
                str(rom.u8(party_offset+2)), #level
                constants.species_table[rom.u16(party_offset+4)],
                constants.attack_table[rom.u16(party_offset+6)],
                constants.attack_table[rom.u16(party_offset+8)],
                constants.attack_table[rom.u16(party_offset+10)],
                constants.attack_table[rom.u16(party_offset+12)]
            ])
            pkmn += ")"
            party_offset += 16
        elif structure == 3:
            #custom item, custom attack
            pkmn += "\tTRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES("
            pkmn += ",".join([
                hex(rom.u8(party_offset) & 31),
                hex((rom.u8(party_offset) >> 5) & 1),
                ("true" if (rom.u8(party_offset) >> 6) & 1 else "false"),
                ("true" if (rom.u8(party_offset) >> 7) & 1 else "false"),
                str(rom.u8(party_offset+2)), #level
                constants.species_table[rom.u16(party_offset+4)],
                constants.item_table[rom.u16(party_offset+6)],
                constants.attack_table[rom.u16(party_offset+8)],
                constants.attack_table[rom.u16(party_offset+10)],
                constants.attack_table[rom.u16(party_offset+12)],
                constants.attack_table[rom.u16(party_offset+14)]
            ])
            pkmn += ")"
            party_offset += 16
        else: raise Exception("Undefined structure "+str(structure))
        pkmns.append(pkmn)

    party = {
        0:"trainer_pokemon_default_item_default_attacks",
        1:"trainer_pokemon_default_item_custom_attacks",
        2:"trainer_pokemon_custom_item_default_attacks",
        3:"trainer_pokemon_custom_item_custom_attacks",
        }[structure] + " trainer_party_"+hex(i)[1:] + "[] = {\n" + ",\n".join(pkmns) + "\n};"
            
    declaration = {
        0:"trainer_pokemon_default_item_default_attacks",
        1:"trainer_pokemon_default_item_custom_attacks",
        2:"trainer_pokemon_custom_item_default_attacks",
        3:"trainer_pokemon_custom_item_custom_attacks",
        }[structure] + " trainer_party_"+hex(i)[1:] + "["+str(pokemon_cnt)+"];"
    parties.append(party)
    headers.append(declaration)
    trainers.append(trainer)

open("D:/temp/trainerparties.txt", "w+").write("\n\n".join(parties))
open("D:/temp/trainers.txt", "w+").write(",".join(trainers))
open("D:/temp/trainerhead.txt", "w+").write("\n".join(headers))




