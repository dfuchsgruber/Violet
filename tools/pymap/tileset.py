
import json
import image, palette, agbimg

PATH_UNSAFED = "unsafed"

class Tileset:

    def __init__(self, is_primary):
        self.path = PATH_UNSAFED
        self.is_primary = is_primary
        palette_count = 7 if is_primary else 5
        self.palettes = [palette.Palette() for i in range(0, palette_count)]
        self.image = image.Image() 
        #self.image = agbimg.Agb_image()
        self.symbol = "0"
        self.gfx = "0"
        self.init_func = "0"

        number_blocks = 0x280 if is_primary else 384
        self.blocks = [[0] * 8 for i in range(number_blocks)]
        self.behaviours = [0] * number_blocks

    def load_image_file(self, path):
        self.image.load_image_file(path)
        #self.image.load_png(path)
        if self.is_primary and self.image.width * self.image.height != 128 * 320:
            raise Exception("Image must contain 128 * 320 (=40.960) pixels")
        if not self.is_primary and self.image.width * self.image.height != 128 * 192:
            raise Exception("Image must contain 128 * 192 (=24.576) pixels")


    def load_palette(self, path, slot):
        self.palettes[slot].load_palette_file(path)

    def get_image(self, colors, tiles_per_line, tiles_per_row):
        if not self.image: raise Exception("Tileset holds no image file")
        return self.image.get_image(tiles_per_line, tiles_per_row, colors)

    def get_tile(self, tile_id, colors, hflip, vflip):
        """ Returns a single tile as image with certain palette """
        if not self.image: raise Exception("Tileset holds no image file")
        return self.image.get_tile(tile_id, colors, hflip, vflip)



    def save(self, path):
        data = {
            "image" : self.image.key,
            "palettes" : [p.key for p in self.palettes],
            "is_primary" : self.is_primary,
            "blocks" : self.blocks,
            "behaviours" : self.behaviours,
            "symbol" : self.symbol,
            "gfx" : self.gfx,
            "init_func" : self.init_func,
        }
        self.path = path
        fd = open(path, "w+")
        json.dump(data, fd)
        fd.close()

def from_file(path):
    """ Instanciates the class from a json file"""
    fd = open(path, "r+")
    data = json.load(fd)
    fd.close()
    t = Tileset(data["is_primary"])
    t.load_image_file(data["image"])
    palette_keys = data["palettes"]
    for i in range(0, len(palette_keys)):
        t.load_palette(palette_keys[i], i)
    t.blocks = data["blocks"]
    t.behaviours = data["behaviours"]
    t.path = path
    t.symbol = data["symbol"]
    t.gfx = data["gfx"]
    t.init_func = data["init_func"]
    return t

