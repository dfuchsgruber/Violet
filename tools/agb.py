VIOLETPATH = "C:/Users/Domi/Dropbox/Pokemon Violet/Pokemon Violet.gba"

class Agbrom:
    
    def __init__(self, path=VIOLETPATH):
        fd = open(path, "rb")
        self.bytes = bytearray(fd.read())
        fd.close()

    def u8(self, off):
        return int(self.bytes[off]) & 0xFFF

    def u16(self, off):
        return (int(self.bytes[off]) & 0xFF) | (int(self.bytes[off + 1]) << 8)

    def u32(self, off):
        return (int(self.bytes[off]) & 0xFF) | (int(self.bytes[off + 1]) << 8) | (int(self.bytes[off + 2]) << 16) | (int(self.bytes[off + 3]) << 24)

    def pointer(self, off):
        return self.u32(off) - 0x8000000

    def array(self, off, size):
        return [self.u8(off + i) for i in range (0, size)]
