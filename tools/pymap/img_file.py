import png
import PIL.Image as Image

class Img_file:
    
    def __init__(self, path):
        image = Image.open(path)
        image = self._make_color_transparent(image)
        self.tiles = self._img_to_tiles(image)
        self.key = path
        self.palette = image.palette.palette


    def _img_to_tiles(self, image):
        width, height = image.size
        tiles = []
        #Splitting the image into tiles
        for y in range(0, height >> 3):
            for x in range(0, width >> 3):
                box = (x * 8, y * 8, min((x + 1) * 8, width), min((y + 1) * 8, height))
                tiles.append(image.crop(box))
        return tiles

    def _make_color_transparent(self, image, color=None):
        if not color:
            colors = image.palette.palette
            color = (colors[0], colors[1], colors[2])
        temp_image = image.convert("RGBA")
        data = [(color[0], color[1], color[2], 0) if pixel[0] == color[0] and pixel[1] == color[1] and pixel[2] == color[2] else pixel for pixel in temp_image.getdata()]
        temp_image.putdata(data)
        return temp_image

    def _tile_to_str(self, tile):
        str = ""
        for pixel in tile.getdata():
            str += hex(pixel[0]) + hex(pixel[1]) + hex(pixel[2])
        return str

    def _show_tiles(self, tiles):
        joined = Image.new("RGBA", (len(tiles) * 8, 8))
        for i in range(0, len(tiles)):
            joined.paste(tiles[i], (i*8, 0))
        joined.show()




