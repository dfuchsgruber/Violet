import agb
import img_dump

rom = agb.Agbrom(path="D:/Hacking/bprd.gba")
img_dump.dump_png("D:/temp/tss.png", rom, 0x26D2A0, 128, 48, 0x26D6E4, 16, img_lz77=True)