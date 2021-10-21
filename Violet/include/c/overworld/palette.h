#ifndef H_OVERWORLD_PALETTE
#define H_OVERWORLD_PALETTE

#include "oam.h"
#include "types.h"

extern oam_template *overworld_effect_oam_templates[36];

extern palette overworld_npc_palettes[18]; // Standard npc palettes, we don't touch those but add own

/**
 * Gets the index of a overworld npc palette in the table
 * @param tag the tag to get
 * @return the idx in the table or 0xFF on failure
 */
u8 overworld_npc_palette_get_idx(u16 tag);

// This might be whack, we might want to change that at some later point
#define NPC_PAL_TAG_TO_REFLECTION_TAG(tag) ((tag | 0x4000))
#define NPC_PAL_TAG_IS_REFLECTION_TAG(tag) (((tag & 0x4000) != 0))

#endif
