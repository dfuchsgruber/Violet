import violet
import img_dump
import constants
import os, sys

vdata = violet.violet_open()

#Std
img_dump.dump_png("D:/temp/tbstd.png", vdata, violet.pointer(vdata, 0x14FA2C), 16, 9*8, 0x4711DC, 16, depth=4)

#Nickname
img_dump.dump_png("D:/temp/nickname.png", vdata, 0, 8, 8, violet.pointer(vdata, 0x3E1Be4), 0x60, depth=8)

