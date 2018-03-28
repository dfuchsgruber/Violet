#ifndef H_ABILITIES
#define H_ABILITIES

// Constants
#include "abilities.h"

#define ABILITY_CNT 0x71

void stance_change_change_species(u8 target, u16 species);

extern u8 ability_names[ABILITY_CNT][0xD];
u8 *ability_descriptions[ABILITY_CNT];


#endif
