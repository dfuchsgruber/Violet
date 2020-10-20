import violet
import img_dump
import constants
import os, sys

vdata = violet.violet_open()

pal_off = violet.pointer(vdata, 0x078A04)
img_offs = [0x0136f400, 0x0136f800, 0x0136fc00, 0x0136f800, 0x0136f400]

out = "D:/temp/ts/deoxys"

for i in range (0, len(img_offs)):
    img_dump.dump_png(out+str(i)+".png", vdata, img_offs[i], 88, 56, pal_off, 16, img_lz77=True, pal_lz77=False)

start_button_tiles = violet.pointer(vdata, 0x078A14)
start_button_pal = violet.pointer(vdata, 0x78A10)

img_dump.dump_png("D:/temp/ts/start.png", vdata, start_button_tiles, 8, 8, start_button_pal, 16, img_lz77=True, pal_lz77=False)

title_tiles = violet.pointer(vdata, 0x789FC)
title_pal = violet.pointer(vdata, 0x789F8)

img_dump.dump_png("D:/temp/ts/title.png", vdata, title_tiles, 8, 8, title_pal, 12*16, img_lz77=True, pal_lz77=False, depth=8)

bg_tiles = violet.pointer(vdata, 0x78A1C)

img_dump.dump_png("D:/temp/ts/bg.png", vdata, bg_tiles, 8, 8, title_pal+32*12, 16, img_lz77=True, pal_lz77=False)
