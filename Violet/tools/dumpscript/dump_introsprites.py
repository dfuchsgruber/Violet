import violet
import img_dump
import constants
import os, sys

vdata = violet.violet_open()

#Male
img_dump.dump_png("D:/temp/introhiromal.png", vdata, violet.pointer(vdata, 0x13127C), 64, 96, 
violet.pointer(vdata, 0x131278), 32, img_lz77=True, pal_lz77=False, depth=8, pal_start_color=0x40)

#Female
img_dump.dump_png("D:/temp/introhirofem.png", vdata, violet.pointer(vdata, 0x131294), 64, 96, 
violet.pointer(vdata, 0x131290), 32, img_lz77=True, pal_lz77=False, depth=8, pal_start_color=0x40)

#Rival
img_dump.dump_png("D:/temp/introrival.png", vdata, violet.pointer(vdata, 0x1312B4),64, 96, 
violet.pointer(vdata, 0x1312B0), 32, img_lz77=True, pal_lz77=False, depth=8, pal_start_color=0x60)

#Oak
img_dump.dump_png("D:/temp/introoak.png", vdata, violet.pointer(vdata, 0x131354), 64, 96, 
violet.pointer(vdata, 0x131350), 32, img_lz77=True, pal_lz77=False, depth=8, pal_start_color=0x60)

#Ground
img_dump.dump_png("D:/temp/introgroundpal.png", vdata, 0, 8, 8, violet.pointer(vdata, 0x463FF0), 16, depth=4)

#BG
img_dump.dump_png("D:/temp/introbgpal.png", vdata, 0, 8, 8, violet.pointer(vdata, 0x12ED88), 0x40, depth=8, pal_start_color=0)

#Tbpal
img_dump.dump_png("D:/temp/introtbpal.png", vdata, 0, 8, 8, 0x4711DC, 0x50, depth=8, pal_start_color=0)