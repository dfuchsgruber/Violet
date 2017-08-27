import pymap.pymap_gui
import sys
import pymap.ow_imgs
import img_dump
import agb

if __name__ == "__main__": pymap.pymap_gui.shell(sys.argv[1:], pymap.ow_imgs.Ow_imgs(img_dump.dump_png_fp, agb.Agbrom))