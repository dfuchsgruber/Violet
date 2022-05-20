#include "types.h"
#include "text.h"

u8 *string_replace(u8 *src, u8 *dst, u8 find, u8 replace) {
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