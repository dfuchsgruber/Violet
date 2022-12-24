import agb
import constants

#read maps
fd = open("maps2export.txt", "r+")
maps2export = fd.read()
fd.close()
maps2export = maps2export.replace("\r\n", "").split(",")

rom = agb.Agbrom(path=agb.VIOLETPATH)
wild_table = rom.pointer(0x828F4)

#For runtime scan entire table once
index_table = {}
i = 0
while True:
    off = wild_table + i * 0x14
    bank = rom.u8(off)
    mapid = rom.u8(off + 1)
    if bank == 0xFF and mapid == 0xFF: break
    index_table[bank, mapid] = i
    i += 1



outtable = ""

def export_data(offset, size, name, chances):
    out = "@// Wild data " + name + "\n.global " + name + "\n.align 4\n" + name + ":\n"
    frequency = rom.u8(offset)
    fields = rom.array(offset + 1, 3)
    entries = rom.pointer(offset + 4)
    out += ".byte " + hex(frequency) + " @// Frequency in 1/256\n"
    out += ".byte " + ", ".join(map(str, fields)) + "\n"
    out += ".word " + name + "_entries\n\n"

    #Append the entries
    out += ".align 4\n"
    out += name + "_entries:\n"
    for i in range(size):
        level_min = str(rom.u8(entries + i * 4))
        level_max = str(rom.u8(entries + i * 4 + 1))
        species = constants.species(rom.u16(entries + i * 4 + 2))
        out += ".byte " + level_min + ", " + level_max + " @//Level range\n"
        out += ".hword " + species + " @// " + chances[i] + " percent\n"

    return out + "\n"

chances_grass = list(map(lambda c: str(c) + " percent", [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]))
chances_water = list(map(lambda c: str(c) + " percent", [60, 30, 5, 4, 1]))
chances_other = list(map(lambda c: str(c) + " percent", [60, 30, 5, 4, 1]))
chances_rod = [
    (70, "rod"), (30, "rod"), (60, "profi rod"), (20, "profi rod"), (20, "profi rod"), (40, "super rod"),
    (40, "super rod"), (15, "super rod"), (4, "super rod"), (1, "super rod")
]
chances_rod = list(map(lambda c: str(c[0]) + " percent, " + c[1], chances_rod))


for pair in maps2export:
    pair = pair.strip().split(".")
    bank = int(pair[0])
    mapid = int(pair[1])
    if (bank, mapid) not in index_table: continue
    off = wild_table + index_table[bank, mapid] * 0x14
    outtable += "@// " + str(bank) + "." + str(mapid) + "\n"
    outtable += "\t.byte " + ", ".join(map(str, rom.array(off, 4))) + "\n"
    outtable += "\t.word "
    data = ".include \"" + constants.STDPREAMBLE + "\"\n\n"
    basesym = "map_" + str(bank) + "_" + str(mapid)
    grass_off = rom.nullable_pointer(off + 4)
    if grass_off:
        #Export grass data
        data += export_data(grass_off, 12, basesym + "_wild_grass", chances_grass)
        outtable += basesym + "_wild_grass, "
    else:
        outtable += "0, "
    water_off = rom.nullable_pointer(off + 8)
    if water_off:
        #Export water data
        data += export_data(water_off, 5, basesym + "_wild_water", chances_water)
        outtable += basesym + "_wild_water, "
    else:
        outtable += "0, "
    other_off = rom.nullable_pointer(off + 12)
    if other_off:
        #Export other data
        data += export_data(other_off, 5, basesym + "_wild_other", chances_other)
        outtable += basesym + "_wild_other, "
    else:
        outtable += "0, "
    rod_off = rom.nullable_pointer(off + 16)
    if rod_off:
        #Export rod data
        data += export_data(rod_off, 10, basesym + "_wild_rod", chances_rod)
        outtable += basesym + "_wild_rod "
    else:
        outtable += "0 "
    dir = "../map/" + str(bank) + "/" + str(mapid)
    print(dir + "/wild_pokemon.asm")
    fd = open(dir + "/wild_pokemon.asm", "w+")
    fd.write(data)
    fd.close()
    
    outtable += "\n"


open("D:/temp/wildtable.s", "w+").write(outtable)
        
    


