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

    def findall(self, bytes, unaligned=False):
        results = []
        position = -1
        bytes = bytearray(bytes)
        while True:
            position = self.bytes.find(bytes, position+1)
            if position >= 0:
                if position % 4 == 0 or unaligned:
                    results.append(position)
                else:
                    print("Warning. Found unaligned reference at "+hex(position))
                    
            else:
                break
        return results
    
    def get_references(self, offset):
        offset += 0x08000000
        bytes = [
            offset & 0xFF,
            (offset >> 8) & 0xFF,
            (offset >> 16) & 0xFF,
            (offset >> 24) & 0xFF
        ]
        return self.findall(bytes)
