

import sys

def decomp(data):
    """ Decomps lz77 compressed data specified by GBATEK """
    if (data[0] >> 4) & 0xF != 1: raise Exception("Lz77 Error: Data is not lz77 compressed")
    size = data[1] + (data[2] << 8) + (data[3] << 16) #LE read of bit 8-31 of size field
    out = [33] * size
    off = 4 #Data starts at offset = 0x4
    dst = 0
    while size:
        enc = data[off]
        off += 1
        for i in range(7, -1, -1):
            if enc & (1 << i):
                #Reference to literal chain
                ref = data[off] + (data[off+1] << 8)
                off += 2

                #Decode literal Reference
                disp = (ref >> 8) | ((ref & 0xF) << 8)
                length = ((ref >> 4) & 0xF) + 3 #Length+3 by GBATEK specs

                #Output the literal 
                for j in range(0, length):
                    try:
                        out[dst] = out[dst-disp-1]
                    except Exception as e:
                        print("Warning in lz77 decomp, malformed data :"+str(e))
                        out[dst] = 0
                    dst += 1
                    size -= 1
                    if not size: return out

            else:
                #New literal, raw dump
                out[dst] = data[off]
                off += 1
                dst += 1
                size -= 1
                if not size: return out
    return out
                
