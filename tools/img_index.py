""" Module to reduce an image to 16 colors and dump the palette file together with the new image"""

import PIL.Image as Image
import sys
import getopt
import os
import png
import numpy as np
import json

def pal_to_agb(pal):
    transformed = []
    for intensity in pal:
        transformed.append(intensity & 0xF8)
    return bytes(bytearray(transformed))


def main(argv):
    try:
        opts, args = getopt.getopt(argv, "hi:o:", ["help"])
    except getopt.GetoptError:
        sys.exit(2)
    inpath, outpath = None, None
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print("usage: python img_index.py -i inputfile -o outputfile")
            sys.exit(0)
        elif opt == "-i":
            inpath = arg
        elif opt == "-o":
            outpath = arg
            if outpath.lower().endswith(".png"):
              outpath = os.path.splitext(outpath)[0]

    if not inpath:
        raise Exception("No input file specified")

    if not outpath:
        outpath = os.path.splitext(inpath)[0] + "_indexed"
     
    image = Image.open(inpath)
    converted = image.convert("P", palette=Image.ADAPTIVE, colors=16)
    converted.palette.palette = pal_to_agb(converted.palette.palette)


    palette = converted.palette

    #Output the Image
    converted.save(outpath + ".png", "PNG")

    #Output the palette
    fd = open(outpath + ".pal", "w+")
    fd.write(json.dumps(str(palette.palette)))
    fd.close()



if __name__ == "__main__":
    #call from main with shell -i input -o basename"
    main(sys.argv[1:])