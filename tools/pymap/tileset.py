class Tileset:

    def __init__(self, is_primary):
        self.is_primary = is_primary
        palette_count = 7 if is_primary else 5
        self.palettes = [None for i in range(0, palette_count)]
        self.image = None

    def load_image(self, image):
        self.image = image

    def load_palette(self, palette, slot):
        self.palettes[slot] = palette

    def get_image(self, active_slot):
        if not self.image: raise Exception("Tileset holds no image file")
        if not self.palettes[active_slot]: raise Exception("Palette not defined")

    