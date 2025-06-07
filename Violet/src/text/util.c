#include "types.h"
#include "text.h"

u8 *string_replace(const u8 *src, u8 *dst, u8 find, u8 replace) {
    for (int i = 0;;i++) {
        if (src[i] == 0xFF)
            return dst;
        else if (src[i] == find) {
            dst[i] = replace;
        } else {
            dst[i] = src[i];
        }
    }
    return NULL;
}

u8 *itoa_circled(u8 *dst, u8 value) {
    if (value > 9 || value < 1) {
        *dst = 0xAC; // Question mark '?'
        dst[1] = 0xFF;
        return dst + 2;
    } else {
        dst[0] = 0xF9;
        dst[1] = (u8)(0xA + value - 1);
        dst[2] = 0xFF;
        return dst + 3;
    }
}