#include "types.h"
#include "vars.h"
#include "text.h"
#include "language.h"

static const u8 str_badge1[] = LANGDEP(PSTRING("Antikorden"), PSTRING("Relic Badge"));
static const u8 str_badge2[] = LANGDEP(PSTRING("Waldorden"), PSTRING("Forest Badge"));
static const u8 str_badge3[] = LANGDEP(PSTRING("Lotusorden"), PSTRING("Lotus Badge"));
static const u8 str_badge4[] = LANGDEP(PSTRING("Magmaorden"), PSTRING("Magma Badge"));
static const u8 str_badge5[] = LANGDEP(PSTRING("Ruheorden"), PSTRING("Calm Badge"));

static const u8 str_gym1[] = LANGDEP(PSTRING("Antikarena"), PSTRING("Relic Gym"));
static const u8 str_gym2[] = LANGDEP(PSTRING("Waldarena"), PSTRING("Forest Gym"));
static const u8 str_gym3[] = LANGDEP(PSTRING("Lotusarena"), PSTRING("Focus Gym"));
static const u8 str_gym4[] = LANGDEP(PSTRING("Magmaarena"), PSTRING("Magma Gym"));
static const u8 str_gym5[] = LANGDEP(PSTRING("Ruhearena"), PSTRING("Calm Gym"));

const u8 *const badge_names[8] = {
    str_badge1,
    str_badge2,
    str_badge3,
    str_badge4,
    str_badge5,
};

const u8 *const gym_names[8] = {
    str_gym1,
    str_gym2,
    str_gym3,
    str_gym4,
    str_gym5,
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