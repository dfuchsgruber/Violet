#include "types.h"
#include "vars.h"
#include "text.h"
#include "language.h"

static const u8 str_badge1[] = LANGDEP(PSTRING("Antikorden"), PSTRING("Relic Badge"));
static const u8 str_badge2[] = LANGDEP(PSTRING("Waldorden"), PSTRING("Forest Badge"));
static const u8 str_badge3[] = LANGDEP(PSTRING("Fokusorden"), PSTRING("Focus Badge"));
static const u8 str_badge4[] = LANGDEP(PSTRING("Magmaorden"), PSTRING("Magma Badge"));
static const u8 str_badge5[] = LANGDEP(PSTRING("Ruheorden"), PSTRING("Calm Badge"));

const u8 *const badge_names[8] = {
    str_badge1,
    str_badge2,
    str_badge3,
    str_badge4,
    str_badge5,
};

void special_buffer_badge_name() {
    u8 *buffer;
    switch(*var_access(0x8005)) {
        case 0: buffer = buffer0; break;
        case 1: buffer = buffer1; break;
        case 2: buffer = buffer2; break;
        default: return;
    }
    strcpy(buffer, badge_names[*var_access(0x8004)]);
}