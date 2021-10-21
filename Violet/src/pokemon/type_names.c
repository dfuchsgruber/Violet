#include "constants/pokemon_types.h"
#include "language.h"
#include "text.h"
#include "types.h"
#include "vars.h"

static u8 str_normal[] = LANGDEP(PSTRING("Normal"), PSTRING("Normal"));
static u8 str_kampf[] = LANGDEP(PSTRING("Kampf"), PSTRING("Fighting"));
static u8 str_flug[] = LANGDEP(PSTRING("Flug"), PSTRING("Flying"));
static u8 str_gift[] = LANGDEP(PSTRING("Gift"), PSTRING("Poison"));
static u8 str_boden[] = LANGDEP(PSTRING("Boden"), PSTRING("Ground"));
static u8 str_gestein[] = LANGDEP(PSTRING("Gestein"), PSTRING("Rock"));
static u8 str_kaefer[] = LANGDEP(PSTRING("Käfer"), PSTRING("Bug"));
static u8 str_geist[] = LANGDEP(PSTRING("Geist"), PSTRING("Ghost"));
static u8 str_stahl[] = LANGDEP(PSTRING("Stahl"), PSTRING("Steel"));
static u8 str_fee[] = LANGDEP(PSTRING("Fee"), PSTRING("Fairy"));
static u8 str_feuer[] = LANGDEP(PSTRING("Feuer"), PSTRING("Fire"));
static u8 str_wasser[] = LANGDEP(PSTRING("Wasser"), PSTRING("Water"));
static u8 str_pflanze[] = LANGDEP(PSTRING("Pflanze"), PSTRING("Grass"));
static u8 str_elektro[] = LANGDEP(PSTRING("Elektro"), PSTRING("Electric"));
static u8 str_psycho[] = LANGDEP(PSTRING("Psycho"), PSTRING("Psychic"));
static u8 str_eis[] = LANGDEP(PSTRING("Eis"), PSTRING("Ice"));
static u8 str_drache[] = LANGDEP(PSTRING("Drache"), PSTRING("Dragon"));
static u8 str_unlicht[] = LANGDEP(PSTRING("Unlicht"), PSTRING("Dark"));

u8 *str_pokemon_type_names[] = {
    [TYPE_NORMAL] = str_normal,
    [TYPE_KAMPF] = str_kampf,
    [TYPE_FLUG] = str_flug,
    [TYPE_GIFT] = str_gift,
    [TYPE_BODEN] = str_boden,
    [TYPE_GESTEIN] = str_gestein,
    [TYPE_KAEFER] = str_kaefer,
    [TYPE_GEIST] = str_geist,
    [TYPE_STAHL] = str_stahl,
    [TYPE_FEE] = str_fee,
    [TYPE_FEUER] = str_feuer,
    [TYPE_WASSER] = str_wasser,
    [TYPE_PFLANZE] = str_pflanze,
    [TYPE_ELEKTRO] = str_elektro,
    [TYPE_PSYCHO] = str_psycho,
    [TYPE_EIS] = str_eis,
    [TYPE_DRACHE] = str_drache,
    [TYPE_UNLICHT] = str_unlicht,
};

void special_buffer_type_name() {
    u16 type = *var_access(0x8004);
    u16 buffer_idx = *var_access(0x8005);
    switch (buffer_idx) {
        case 0:
            strcpy(buffer0, str_pokemon_type_names[type]);
            break;
        case 1:
            strcpy(buffer1, str_pokemon_type_names[type]);
            break;
        case 2:
            strcpy(buffer2, str_pokemon_type_names[type]);
            break;
    }
}
