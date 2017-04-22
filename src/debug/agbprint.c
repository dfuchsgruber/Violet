#include "types.h"
#include "romfuncs.h"
#include "utils.h"

#include <stdarg.h>

/*****************
 * AUTHOR: Sbird *
 *               *
 *****************/
void dprint(const char * sz)
{
    __asm__ __volatile__(
        "mov r2, %0\n"
        "ldr r0, =0xc0ded00d\n"
        "mov r1, #0\n"
        "and r0, r0, r0\n":
        :
        "r" (sz):
        "r0", "r1", "r2");
}

u32 mini_strlen(const char * s) {
    u32 len = 0;
    while (s[len] != '\0') len++;
    return len;
}

u32 mini_itoa(int value, u32 radix, u32 uppercase, u32 unsig, char * buffer, u32 zero_pad) {
    char * pbuffer = buffer;
    s32 negative = 0;
    u32 i, len;
    /* No support for unusual radixes. */
    if (radix > 16)
        return 0;
    if (value < 0 && !unsig) {
        negative = 1;
        value = -value;
    }
    /* This builds the string back to front ... */
    do {
        u32 digit = __aeabi_uidivmod(value, radix); * (pbuffer++) = (digit < 10 ? '0' + digit : (uppercase ? 'A' : 'a') + digit - 10);
        value /= radix;
    } while (value > 0);
    for (i = (pbuffer - buffer); i < zero_pad; i++)
        * (pbuffer++) = '0';
    if (negative)
    {
        * (pbuffer++) = '-'; * (pbuffer) = '\0';
    }
    /* ... now we reverse it (could do it recursively but will
     * conserve the stack space) */
    len = (pbuffer - buffer);
    for (i = 0; i < len / 2; i++) {
        char j = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = j;
    }
    return len;
}

int mini_vsnprintf(char * buffer, u32 buffer_len,
    const char * fmt, va_list va)
{
    char * pbuffer = buffer;
    char bf[24];
    char ch;
    int _putc(char ch)
    {
        if ((u32)((pbuffer - buffer) + 1) >= buffer_len)
            return 0;
        * (pbuffer++) = ch;
        * (pbuffer) = '\0';
        return 1;
    }
    int _puts(char * s, u32 len)
    {
        u32 i;
        if (buffer_len - (pbuffer - buffer) - 1 < len)
            len = buffer_len - (pbuffer - buffer) - 1;
        /* Copy to buffer */
        for (i = 0; i < len; i++)
            * (pbuffer++) = s[i];
        * (pbuffer) = '\0';
        return len;
    }
    while ((ch = * (fmt++))) {
        if ((u32)((pbuffer - buffer) + 1) >= buffer_len)
            break;
        if (ch != '%')
            _putc(ch);
        else {
            char zero_pad = 0;
            char * ptr;
            u32 len;
            ch = * (fmt++);
            /* Zero padding requested */
            if (ch == '0') {
                ch = * (fmt++);
                if (ch == '\0')
                    return pbuffer - buffer;
                if (ch >= '0' && ch <= '9')
                    zero_pad = ch - '0';
                ch = * (fmt++);
            }
            switch (ch) {
            case 0:
                return pbuffer - buffer;
            case 'u':
            case 'd':
                len = mini_itoa(va_arg(va, u32), 10, 0, (ch == 'u'), bf, zero_pad);
                _puts(bf, len);
                break;
            case 'x':
            case 'X':
                len = mini_itoa(va_arg(va, u32), 16, (ch == 'X'), 1, bf, zero_pad);
                _puts(bf, len);
                break;
            case 'c':
                _putc((char)(va_arg(va, int)));
                break;
            case 's':
                ptr = va_arg(va, char * );
                _puts(ptr, mini_strlen(ptr));
                break;
            default:
                _putc(ch);
                break;
            }
        }
    }
        return pbuffer - buffer;
}

void dprintf(const char * str, ...)
    //---------------------------------------------------------------------------------
    {
        char* __outstr = malloc(256);
        va_list args;
        va_start(args, str);
        mini_vsnprintf(__outstr, 256, str, args);
        va_end(args);
        dprint(__outstr);
        free(__outstr);
    }
