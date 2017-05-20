import agb

rom = agb.Agbrom()

pointer = bytearray([0x98, 0xE9, 0x23, 0x08])
offset = 0
hits = []
while True:
    try:
        offset = rom.bytes.index(pointer, offset) + 4
        hits.append(offset-4)
    except Exception as e:
        print(e)
        break
    

fd = open("D:/temp/trainerpointers.txt", "w+")
fd.write("\n\n".join([".org " + hex(0x8000000 + off) + "\n\t.word trainers" for off in hits]))
fd.close()