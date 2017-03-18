import lz77
import png
import array

def img_to_tiles(data, tile_cnt, depth=4):
    """ Collects 8x8 Tiles from the img raw data """
    tiles = []
    for i in range(0, tile_cnt):
        #Loop to collect a tile
        tile_off = i * int(8 * 8 * depth / 8)
        tile = []
        for j in range(0, int(8 * 8 * depth / 8)):
            pixel_off = tile_off + j
            if depth == 4:
                tile.append(data[pixel_off] & 0xF)
                tile.append((data[pixel_off] >> 4) & 0xF)
            elif depth == 8:
                tile.append(data[pixel_off])
            else: raise Exception("Unsupported bit-depth", depth)
        tiles.append(tile)
    return tiles

def tiles_to_rows(tiles, tile_width, tile_height):
    """ Builds png rows from a tile list"""
    rows = []
    for i in range(0, tile_height):
        tile_line_off = tile_width * i
        for j in range(0, 8):
            #Build 8 rows out of one tile line
            row = []
            for x in range(0, tile_width):
                #Iterate pixelwise through all the tiles
                tile = tiles[tile_line_off + x] #All Pixels inside the right tile
                pixels = tile[8 * j : 8 * (j+1)]
                row += pixels
            rows.append(row)
    return rows

def pal(data, color_cnt):
    """ Reads 16-Bit Palette entries from data and transforms it into an png rgb pal"""
    palette = []
    for i in range(0, color_cnt):
        gbapal = data[2 * i] | (data[2 * i + 1]) << 8
        red = gbapal & 31
        green = (gbapal >> 5) & 31
        blue = (gbapal >> 10) & 31
        palette.append((red * 8, green * 8, blue * 8))
    return palette

def dump_png(path, data, img_offset, width, height, pal_offset, col_cnt, img_lz77=False, pal_lz77=False, depth=4, pal_start_color=0):
    """ Dumps a png with pal from data """
    #First get picture
    img_data = data[img_offset:]
    if img_lz77: img_data = lz77.decomp(img_data)
    tile_width = width >> 3
    tile_height = height >> 3
    img_tiles = img_to_tiles(img_data, tile_width * tile_height, depth=depth)
    img_rows = tiles_to_rows(img_tiles, tile_width, tile_height)

    #Now get the palette
    pal_data = data[pal_offset:]
    if pal_lz77: pal_data = lz77.decomp(pal_data)
    pal_data = ([0,0] * pal_start_color) + pal_data
    img_pal = pal(pal_data, col_cnt+pal_start_color)

    outfile = open(path, "wb")
    pngwriter = png.Writer(width, height, palette=img_pal, bitdepth=depth)
    pngwriter.write(outfile, img_rows)
    outfile.close()

