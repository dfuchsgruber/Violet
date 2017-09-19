import agb

rom = agb.Agbrom(path=agb.FRDPATH)

fd = open("D:/temp/wildpointers.txt", "w+")
fd.write(rom.pointer_dump(0x3C9B04, "wild_pokemon"))
fd.close()