import agb
import img_dump
import lz77
import pysetex
import png

#This module quickdumps a png with a palette of a tileset (for editing in right pal)

TSNUM = 2
TSPAL = 1
COLS = 16 * 7
PATH = "D:/temp/ts2p1.png"

rom = agb.Agbrom(path=agb.STDPATH)

bytecnt = COLS * 2
table = pysetex.DEFAULT_TABLE
off = table + 24 * TSNUM

pal_mode = rom.u8(off + 1)
pal_off = rom.pointer(off + 0x8)

if pal_mode == 0:
    pal_data = rom.array(pal_off, bytecnt)
elif pal_mode == 1:
    pal_off += 0xE0
    pal_data = rom.array(pal_off, bytecnt)
else:
    pal_data = lz77.decomp(rom, pal_off)

pal_data = pal_data[32 * TSPAL : 32 * (TSPAL + 1)]

#First get picture
img_data = rom.array(0, (8 * 8 * 4) >> 3)
tile_width = 8 >> 3
tile_height = 8 >> 3
img_tiles = img_dump.img_to_tiles(img_data, tile_width * tile_height, depth=4)
img_rows = img_dump.tiles_to_rows(img_tiles, tile_width, tile_height)


img_pal = img_dump.pal(pal_data, 16)
    
fp = open(PATH, "wb")

pngwriter = png.Writer(8, 8, palette=img_pal, bitdepth=4)
pngwriter.write(fp, img_rows)
fp.close()
