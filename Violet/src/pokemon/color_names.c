#include "types.h"
#include "pokemon/basestat.h"
#include "constants/pokemon_colors.h"
#include "language.h"

static const u8 str_color_none[] = LANGDEP(PSTRING("Keine"), PSTRING("None"));
static const u8 str_color_blue[] = LANGDEP(PSTRING("Blau"), PSTRING("Blue"));
static const u8 str_color_bown[] = LANGDEP(PSTRING("Braun"), PSTRING("Brown"));
static const u8 str_color_yellow[] = LANGDEP(PSTRING("Gelb"), PSTRING("Yellow"));
static const u8 str_color_grey[] = LANGDEP(PSTRING("Grau"), PSTRING("Grey"));
static const u8 str_color_green[] = LANGDEP(PSTRING("Grün"), PSTRING("Green"));
static const u8 str_color_pink[] = LANGDEP(PSTRING("Rosa"), PSTRING("Pink"));
static const u8 str_color_red[] = LANGDEP(PSTRING("Rot"), PSTRING("Red"));
static const u8 str_color_black[] = LANGDEP(PSTRING("Schwarz"), PSTRING("Black"));
static const u8 str_color_violet[] = LANGDEP(PSTRING("Violett"), PSTRING("Violet"));
static const u8 str_color_white[] = LANGDEP(PSTRING("Weiß"), PSTRING("White"));

const u8 *const pokemon_color_names[NUM_POKEMON_COLORS] = {
    [POKEMON_COLOR_NONE] = str_color_none,
    [POKEMON_COLOR_BLAU] = str_color_blue,
    [POKEMON_COLOR_BRAUN] = str_color_bown,
    [POKEMON_COLOR_GELB] = str_color_yellow,
    [POKEMON_COLOR_GRAU] = str_color_grey,
    [POKEMON_COLOR_GRUEN] = str_color_green,
    [POKEMON_COLOR_ROSA] = str_color_pink,
    [POKEMON_COLOR_ROT] = str_color_red,
    [POKEMON_COLOR_SCHWARZ] = str_color_black,
    [POKEMON_COLOR_VIOLETT] = str_color_violet,
    [POKEMON_COLOR_WEISS] = str_color_white,
};