""" Module to reduce an image to 16 colors and dump the palette file together with the new image"""

import sys
import getopt
import os
import png


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
            if outpath.lower().endswith(".pal"):
              outpath = os.path.splitext(outpath)[0]

    if not inpath:
        raise Exception("No input file specified")

    if not outpath:
        outpath = os.path.splitext(inpath)[0] + "_indexed"
     
    fd_img = open(inpath, "rb")
    width, height, pmap, attributes = png.Reader(fd_img).read()
    fd_img.close()

    if attributes["bitdepth"] != 4: raise Exception("Expected 4bpp input picture!")
    original_palette = attributes["palette"]
    palette_bin = []
    for r, g, b in original_palette:
        ir, ig, ib = r & 0xF8, g & 0xF8, b & 0xF8
        palette_bin += [ir, ig, ib]

    #Output the palette
    fd = open(outpath + ".pal", "wb")
    fd.write(bytes(palette_bin))
    fd.close()



if __name__ == "__main__":
    #call from main with shell -i input -o outfile"
    main(sys.argv[1:])