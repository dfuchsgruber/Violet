VIOLETPATH = "C:/Users/Domi/Dropbox/Pokemon Violet/Pokemon Violet.gba"

def violet_open():
    #First open PKMN Violet
    vfile = open(VIOLETPATH, "rb")
    vdata = [int(byte) for byte in bytearray(vfile.read())]
    print("Violets Data successfully read.")
    vfile.close()
    return vdata

def read_16(vdata, off):
    """ Reads LE 16 bit halfword from array """
    return vdata[off] | (vdata[off+1] << 8)

def read_32(vdata, off):
    """ Reads LE 32 bit word from array """
    return vdata[off] | (vdata[off+1] << 8) | (vdata[off+2] << 16) | (vdata[off+3] << 24)

def pointer(vdata, off):
    """ Interprets an offset as pointer and returns the referenced ROM Offset"""
    return read_32(vdata, off) - 0x8000000