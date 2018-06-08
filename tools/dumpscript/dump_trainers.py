#!/usr/bin/env python3

from agb import agbrom
from pymap import project
from pokestring import pstring

rom = agbrom.Agbrom("/media/d/romhacking/violetbuilt.gba")
trainer_base = rom.pointer(0xfb84)
ps = pstring.Pstring("/media/d/romhacking/Violet_Sources/charmap.txt")

proj = project.Project.load_project("/media/d/romhacking/Violet_Sources/proj.pmp")
consts = proj.constants

trainers = []
parties = []
headers = []

    

def ai_to_str(ai):
    strategies = []
    for i in range(32):
        if ai & (1 << i):
            try: strategies.append(consts.constantize(1 << i, "trainer_ai_flags"))
            except: strategies.append(hex(1 << i))
    if len(strategies): return " | ".join(strategies)
    else: return "TRAINER_AI_STRATEGY_NONE"


for i in range(0, 0xB3):
    offset = trainer_base + i * 0x28
    trainer = "{\n\t//Trainer "+hex(i)+"\n"
    structure = rom.u8(offset) & 3
    trainer += "\t"+("true" if structure & 1 else "false") + ",// Custom moves\n"
    trainer += "\t"+("true" if structure & 2 else "false") + ",// Custom items\n"
    trainer += "\t"+hex(rom.u8(offset) >> 2) + ",// field_0_filler\n"
    trainer += "\t"+consts.constantize(rom.u8(offset+1), "trainerclasses") + ",\n"
    trainer += "\t{"+hex(rom.u8(offset+2) & 0x7F)+", "+("true" if rom.u8(offset+2) & 0x80 else "false") + "},//Encounter and gender\n"
    trainer += "\t"+hex(rom.u8(offset+3))+",// sprite\n"

    #Name as PCHAR ARRAY
    name = ps.hex2str(rom, offset + 4)
    trainer += "\tLANGDEP(PSTRING(\"{0}\"), PSTRING(\"{0}\")),\n".format(name)
    trainer += "\t{" + ", ".join([
        consts.constantize(rom.u8(offset+16+2*j), "items") for j in range (0, 4)])+"},\n"
    trainer += "\t" +("true" if rom.u32(offset+24) else "false") + ",//Dual battle\n"
    trainer += "\t" + ai_to_str(rom.u16(offset+28)) + ",\n"
    trainer += "\t" + hex(rom.u16(offset+30)) + ",// field_1E\n"
    pokemon_cnt = rom.u8(offset+32)
    trainer += "\t" + str(pokemon_cnt) + ",// Pokemon Count\n"
    trainer += "\t" + hex(rom.u8(offset+33)) + ",// field_21\n"
    trainer += "\t" + hex(rom.u8(offset+34)) + ",// field_22\n"
    trainer += "\t" + hex(rom.u8(offset+35)) + ",// field_23\n"
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
                consts.constantize(rom.u16(party_offset+4), "species")
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
                consts.constantize(rom.u16(party_offset+4), "species"),
                consts.constantize(rom.u16(party_offset+6), "items")
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
                consts.constantize(rom.u16(party_offset+4), "species"),
                consts.constantize(rom.u16(party_offset+6), "attacks"),
                consts.constantize(rom.u16(party_offset+8), "attacks"),
                consts.constantize(rom.u16(party_offset+10), "attacks"),
                consts.constantize(rom.u16(party_offset+12), "attacks")
            ])
            pkmn += ")"
            party_offset += 16
        elif structure == 3:
            #custom item, custom attack
            pkmn += "\tTRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES("
            pkmn += ", ".join([
                hex(rom.u8(party_offset) & 31),
                hex((rom.u8(party_offset) >> 5) & 1),
                ("true" if (rom.u8(party_offset) >> 6) & 1 else "false"),
                ("true" if (rom.u8(party_offset) >> 7) & 1 else "false"),
                str(rom.u8(party_offset+2)), #level
                consts.constantize(rom.u16(party_offset+4), "species"),
                consts.constantize(rom.u16(party_offset+6), "items"),
                consts.constantize(rom.u16(party_offset+8), "attacks"),
                consts.constantize(rom.u16(party_offset+10), "attacks"),
                consts.constantize(rom.u16(party_offset+12), "attacks"),
                consts.constantize(rom.u16(party_offset+14), "attacks")
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

open("trainerparties.txt", "w+").write("\n\n".join(parties))
open("trainers.txt", "w+").write(",".join(trainers))
open("trainerhead.txt", "w+").write("\n".join(headers))




