from pymap import config

STDPATH = config.STDROM
VIOLETPATH = "C:/Users/Domi/Dropbox/Pokemon Violet/Pokemon Violet.gba"
FREPATH = "D:/Hacking/1695 - Pokemon Fire Red (U)(Independent).gba"
FRDPATH = "D:/Hacking/bprd.gba"

class Agbrom:
    
    def __init__(self, path=STDPATH):
        fd = open(path, "rb")
        self.bytes = bytearray(fd.read())
        fd.close()
        self.path = path

    def u8(self, off):
        return int(self.bytes[off]) & 0xFFF

    def u16(self, off):
        return (int(self.bytes[off]) & 0xFF) | (int(self.bytes[off + 1]) << 8)

    def u32(self, off):
        return (int(self.bytes[off]) & 0xFF) | (int(self.bytes[off + 1]) << 8) | (int(self.bytes[off + 2]) << 16) | (int(self.bytes[off + 3]) << 24)

    def s8(self, off):
        value = self.u8(off)
        return (value & 0x7F) - (value & 0x80)

    def s16(self, off):
        value = self.u16(off)
        return (value & 0x7FFF)  - (value & 0x8000)

    def _int(self, off):
        value = self.u32(off)
        return (value & 0x7FFFFFFF) - (value & 0x80000000)

    def pointer(self, off):
        return self.u32(off) - 0x8000000

    def nullable_pointer(self, off):
        """ Same as pointer but returns None if pointer is 0 """
        u32 = self.u32(off)
        if u32 == 0: return None
        return u32 - 0x8000000

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

    def pointer_dump(self, offset, label):
        refs = self.get_references(offset)
        return "\n".join([".org " + hex(offset + 0x8000000) + "\n\t.word " + label + "\n" for offset in refs])
