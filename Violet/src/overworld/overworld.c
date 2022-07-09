#include "types.h"
#include "agbmemory.h"
#include "save.h"
#include "constants/flags.h"
#include "flags.h"
#include "debug.h"
#include "oam.h"
#include "overworld/palette.h"
#include "overworld/effect.h"
#include "overworld/sprite.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "overworld/npc.h"
#include "color.h"
#include "bios.h"
#include "map/event.h"
#include "prng.h"
#include "callbacks.h"
#include "battle/whiteout.h"
#include "berry.h"
#include "rtc.h"
#include "constants/person_script_stds.h"
#include "constants/pokemon_types.h"
#include "math.h"
#include "vars.h"
#include "mugshot.h"
#include "overworld/step_callback.h"
#include "overworld/detector.h"

#define DEBUG_OVERWORLD 0
#if DEBUG_OVERWORLD
    #define OW_DEBUG(...) DEBUG (__VA_ARGS__)
#else
    #define OW_DEBUG(...) 
#endif


static u8 aggressive_wild_pokemon_get_spawn_rate(u16 flag) {
    switch (flag) {
        case FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_0:
        case FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_1:
        case FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_2:
        case FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_3:
            return 100; // 0-3 spawn always
        case FLAG_AGGRESIVE_WILD_SPAWN_75_PERCENT:
            return 75;
        case FLAG_AGGRESIVE_WILD_SPAWN_50_PERCENT:
            return 50;
        case FLAG_AGGRESIVE_WILD_SPAWN_25_PERCENT:
            return 25;
        case FLAG_AGGRESIVE_WILD_SPAWN_5_PERCENT:
            return 5;
    }
    return 0;
}

static u16 aggresive_wild_pokemon_flags[] = {
    FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_0, FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_1, FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_2, FLAG_AGGRESIVE_WILD_SPAWN_ALWAYS_3,
    FLAG_AGGRESIVE_WILD_SPAWN_75_PERCENT, FLAG_AGGRESIVE_WILD_SPAWN_50_PERCENT, FLAG_AGGRESIVE_WILD_SPAWN_25_PERCENT, FLAG_AGGRESIVE_WILD_SPAWN_5_PERCENT
};

void map_reset_temporary_flags_and_vars() {
    memset(save1->flags, 0, 4); // Flags 0 - 32
    memset(save1->vars, 0, 16 * 2); // Vars 0x4000 - 0x4016
    clearflag(0x803);
    clearflag(0x804);
    clearflag(STRENGTH_USED);                   
    clearflag(FLAG_IN_BATTLE);
    clearflag(0x842);
    setflag(POKERADAR_POKEMON_SPAWNED);
    clearflag(FLAG_PLAYER_ON_LADDER);
    for (size_t i = 0; i < ARRAY_COUNT(aggresive_wild_pokemon_flags); i++) {
        u16 flag = aggresive_wild_pokemon_flags[i];
        if ((rnd16() % 100) < aggressive_wild_pokemon_get_spawn_rate(flag)) {
            clearflag(flag);
        } else {
            setflag(flag);
        }
    }

}

overworld_sprite *overworld_get_by_person(map_event_person *person) {
    if (person->overworld_index == OVERWORLD_SPRITE_POKEMON_32_32) {
        return overworld_sprite_get_by_species(person->value);
    } else if (person->overworld_index == OVERWORLD_SPRITE_POKEMON_64_64) {
        return overworld_sprite_get_by_species(person->value);
    } else if (person->overworld_index == OVERWORLD_SPRITE_BERRY) {
        switch (person->script_std) {
            case PERSON_BERRY_TREE:
                return overworld_sprite_get_by_berry_tree_idx((u8)(person->value));
            case PERSON_STATIC_BERRY_TREE:
                return overworld_sprite_get_by_berry_idx((u8)(ITEM_IDX_TO_BERRY_IDX(person->value)), BERRY_STAGE_BERRIES, false); 
        }
    } else if (person->overworld_index == OVERWORLD_SPRITE_MISC) {
        switch (person->script_std) {
            case PERSON_MUSHROOM:
                return overworld_sprite_get_by_mushroom_idx(person->value);
            case PERSON_SHELL:
                return overworld_sprite_get_by_shell_idx(person->value);
            case PERSON_TRASH_CAN:
                return overworld_sprite_get_by_trash_idx(person->value);
        }
    } else if (person->overworld_index == OVERWORLD_SPRITE_STRENGTH_BOULDER) {
        return overworld_sprite_get_by_boulder_person_script_std(person->script_std, person->value);
    } else if (person->overworld_index == OVERWORLD_SPRITE_TUTOR_CRYSTAL) {
        return overworld_sprite_get_by_tutor_crystal_type(person->value);
    }
    // OW_DEBUG("Falling back to default sprite showing %d\n", person->overworld_index);
    return overworld_get(person->overworld_index);
}

overworld_sprite *overworld_get_by_npc(npc *n) {
    map_event_person *person = map_get_person(n->overworld_id, n->map, n->bank);
    // OW_DEBUG("Ow get by npc: npc is @0x%x\n", n);
    // if (person)
        // OW_DEBUG("Has person at 0x%x with sprite %d\n", person, person->overworld_index);
    if (person)
        return overworld_get_by_person(person);
    else // Hiro and camera can not be found...
        return overworld_get(n->sprite);
}

static bool oam_palette_tag_is_npc_palette(u16 tag) {
    if (tag >= 0x1100 && tag < 0x1120) return true;
    if (tag >= OW_PAL_TAG_POKEMON_BASE && tag < OW_PAL_TAG_END) return true;
    return false;
}

u8 palette_get_gamma_type(u8 pal_idx) {
    if (pal_idx < 13)
        return GAMMA_NORMAL; // Tileset palettes are affected by the standard gamma shift
    if (pal_idx >= 13 && pal_idx < 16)
        return GAMMA_NONE; // Text-Palettes are unaffected by gamma shifts
    // For overworld palettes we need to figure out the pal type by its tag
    u16 tag = oam_palette_get_tag((u8)(pal_idx - 16));
    if (tag == 0xFFFF)
        return GAMMA_NONE;
    else if (NPC_PAL_TAG_IS_REFLECTION_TAG(tag))
        return GAMMA_ALTERNATIVE;
    else if (oam_palette_tag_is_npc_palette(tag))
        return GAMMA_ALTERNATIVE;
    else if (IS_MUGSHOT_PAL_TAG(tag))
        return GAMMA_NONE;
    else
        return GAMMA_NORMAL;
}

void overworld_npc_palettes_initialize(u8 mode) {
    // Don't reserve any palettes whatsoever
    (void)mode;
    oam_palette_allocation_reset();
}

static palette overworld_palette_roman = {
    .pal = gfx_ow_romanPal, .tag = OW_PAL_TAG_ROMAN,
};

static palette overworld_palette_rosalie = {
    .pal = gfx_ow_rosaliePal, .tag = OW_PAL_TAG_ROSALIE,
};

static palette overworld_palette_icarus = {
    .pal = gfx_ow_icarusPal, .tag = OW_PAL_TAG_ICARUS,
};

static palette overworld_palette_apple = {
    .pal = gfx_ow_applePal, .tag = OW_PAL_TAG_APPLE,
};

static palette overworld_palette_secret_power_vine = {
    .pal = gfx_overworld_secret_power_vinesPal, .tag = OW_PAL_TAG_SECRET_POWER_VINES,
}; 

static palette overworld_palette_secret_power_cave = {
    .pal = gfx_overworld_secret_power_cavePal, .tag = OW_PAL_TAG_SECRET_POWER_CAVE,
}; 

static palette overworld_palette_recipe = {
    .pal = gfx_ow_recipe2Pal, .tag = OW_PAL_TAG_RECIPE,
}; 

static palette overworld_palette_upstream = {
    .pal = gfx_ow_upstreamPal, .tag = OW_PAL_TAG_UPSTREAM,
}; 

static palette overworld_palette_faun = {
    .pal = gfx_ow_faunPal, .tag = OW_PAL_TAG_FAUN,
}; 

palette overworld_palette_blue_gear = {
    .pal = gfx_ow_blue_gearPal, .tag = OW_PAL_TAG_BLUE_GEAR,
};

palette overworld_palette_red_gear = {
    .pal = gfx_ow_red_gearPal, .tag = OW_PAL_TAG_RED_GEAR,
};

palette overworld_palette_green_gear = {
    .pal = gfx_ow_green_gearPal, .tag = OW_PAL_TAG_GREEN_GEAR,
};

palette overworld_palette_yellow_gear = {
    .pal = gfx_ow_yellow_gearPal, .tag = OW_PAL_TAG_YELLOW_GEAR,
};

static palette *overworld_npc_palette_get_by_tag(u16 tag) {
    if (tag >= OW_PAL_TAG_POKEMON_BASE && tag < OW_PAL_TAG_POKEMON_END) {
        return overworld_palette_get_by_species((u16)(tag - OW_PAL_TAG_POKEMON_BASE));
    }
    if (tag >= OW_PAL_TAG_BERRY_BASE && tag < (OW_PAL_TAG_BERRY_BASE + NUM_OW_PAL_TAGS_BERRY)) {
        return overworld_palette_berry_get_by_tag(tag);
    }
    if (tag >= OW_PAL_TAG_TUTOR_CRYSTAL_BASE && tag < (OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_UNLICHT + 1)) {
        return overworld_palette_tutor_crystal_get_by_tag(tag);
    }
    switch (tag) {
        case OW_PAL_TAG_MUSHROOM: return overworld_palette_get_by_mushroom();
        case OW_PAL_TAG_SHELL: return overworld_palette_get_by_shell();
        case OW_PAL_TAG_SPECIAL_SHELL: return overworld_palette_get_by_special_shell();
        case OW_PAL_TAG_BOULDER_GYM_PUZZLE: return overworld_palette_get_gym_puzzle_boulder();
        case OW_PAL_TAG_BOULDER_HAY_BALE: return overworld_palette_get_hay_bale_boulder();
        case OW_PAL_TAG_ROMAN: return &overworld_palette_roman;
        case OW_PAL_TAG_MEGA_STONE: return overworld_palette_get_mega_stone();
        case OW_PAL_TAG_ROSALIE: return &overworld_palette_rosalie;
        case OW_PAL_TAG_ICARUS: return &overworld_palette_icarus;
        case OW_PAL_TAG_TRASH: return overworld_palette_get_by_trash();
        case OW_PAL_TAG_SECRET_POWER_VINES: return &overworld_palette_secret_power_vine;
        case OW_PAL_TAG_SECRET_POWER_CAVE: return &overworld_palette_secret_power_cave;
        case OW_PAL_TAG_APPLE: return &overworld_palette_apple;
        case OW_PAL_TAG_RECIPE: return &overworld_palette_recipe;
        case OW_PAL_TAG_UPSTREAM: return &overworld_palette_upstream;
        case OW_PAL_TAG_FAUN: return &overworld_palette_faun;
        case OW_PAL_TAG_BLUE_GEAR: return &overworld_palette_blue_gear;
        case OW_PAL_TAG_RED_GEAR: return &overworld_palette_red_gear;
        case OW_PAL_TAG_GREEN_GEAR: return &overworld_palette_green_gear;
        case OW_PAL_TAG_YELLOW_GEAR: return &overworld_palette_yellow_gear;
    }
    u8 idx = overworld_npc_palette_get_idx(tag);
    // OW_DEBUG("Tag 0x%x is at idx %d in pal-table.\n", tag, idx);
    if (idx != 0xFF) {
        return overworld_npc_palettes + idx;
    }
    return NULL;
}

u8 oam_palette_load_if_not_present_and_apply_shaders(palette *pal) {
    if (!pal)
        return 0xFF;
    u8 oam_pal_idx = oam_palette_get_index(pal->tag);
    if (oam_pal_idx == 0xFF) {
        oam_pal_idx =  oam_palette_load_if_not_present(pal); 
        pal_apply_shaders_by_oam_palette_idx(oam_pal_idx);
        OW_DEBUG("Applied blend to oam palette with tag 0x%x (pal_idx %d)\n", pal->tag, oam_pal_idx);
    }
    return oam_pal_idx;
}

u8 overworld_npc_palette_load(u16 tag) {
    OW_DEBUG("Loading oam palette for tag 0x%x\n", tag);
    palette *pal = overworld_npc_palette_get_by_tag(tag);
    if (pal) {
       return oam_palette_load_if_not_present_and_apply_shaders(pal); 
    }
    return 0xFF;
}

void overworld_npc_load_palette_by_template(oam_template *template) {
    // OW_DEBUG("Find palette 0x%x via template\n", template->pal_tag);
    if (template->pal_tag != 0xFFFF) {
        // OW_DEBUG("Loading oam pal from tag 0x%x\n", template->pal_tag);
        overworld_npc_palette_load(template->pal_tag);
    }
}

void overworld_npc_update_palette(npc *n, oam_object *oam) {
    overworld_sprite *sprite = overworld_get_by_npc(n);
    u8 pal_idx = overworld_npc_palette_load(sprite->pal_tag);
    oam->final_oam.attr2 = (u16)((pal_idx << 12) | (oam->final_oam.attr2 & ~(15 << 12)));
}

void overworld_npc_reflection_brighten_palette(u8 pal_idx) {
    for (int i = 0; i < 16; i++) {
        color_t c = pals[256 + 16 * pal_idx + i];
        c.rgb.red = (u16)(MIN(31, c.rgb.red + 5) & 31);
        c.rgb.green = (u16)(MIN(31, c.rgb.green + 5) & 31);
        c.rgb.blue = (u16)(MIN(31, c.rgb.blue + 10) & 31);
        // OW_DEBUG("Old color 0x%x, new color 0x%x\n", pals[256 + 16 * pal_idx + i], c);
        pals[256 + 16 * pal_idx + i] = c;
    }
    // cpuset(pal_restore + 256 + 16 * pal_idx, pals + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
    cpuset(pals + 256 + 16 * pal_idx, pal_restore + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
}

// static color_t reflection_blue_channel = {.rgb = {.red = 12, .green = 20, .blue = 27}}; 

void overworld_npc_load_reflection_palette(npc *n, oam_object *oam) {
    overworld_sprite *sprite = overworld_get_by_npc(n);
    u16 tag = sprite->pal_tag;
    u16 reflection_tag = NPC_PAL_TAG_TO_REFLECTION_TAG(tag);
    OW_DEBUG("Try to set up reflection tag 0x%x for tag 0x%x\n", reflection_tag, tag);
    u8 pal_idx = oam_palette_get_index(reflection_tag);
    if (pal_idx != 0xFF) {
        oam->final_oam.attr2 = (u16)((pal_idx << 12) | (oam->final_oam.attr2 & ~(15 << 12)));
        return;
    }
    // OW_DEBUG("Reflection tag not yet allocated...\n");
    palette *pal = overworld_npc_palette_get_by_tag(tag);
    if (pal == NULL) 
        return; // The original palette doesn't exist...
    palette reflection_palette = *pal;
    reflection_palette.tag = reflection_tag;
    pal_idx = oam_palette_get_index(reflection_palette.tag);
    if (pal_idx == 0xFF) {
        OW_DEBUG("Reflection palette apply shaders and brighten.\n");
        pal_idx = oam_palette_load_if_not_present_and_apply_shaders(&reflection_palette); 
        OW_DEBUG("Reflection palette before brightening, color idx 3: 0x%x\n", pal_restore[256 + 16 * pal_idx + 3]);
        overworld_npc_reflection_brighten_palette(pal_idx);
        OW_DEBUG("Reflection palette after brightening, color idx 3: 0x%x\n", pal_restore[256 + 16 * pal_idx + 3]);
    }
    // pal_alpha_blending((u16)(256 + 16 * pal_idx), 16, 6, reflection_blue_channel);
    // cpuset(pals + 256 + 16 * pal_idx, pal_restore + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
    pal_oam_apply_fading(pal_idx);
    if (big_callback_is_active(whiteout_callback_print_text)){ // This causes issues somehow...
        OW_DEBUG("Reflection palette while whiting out...\n");
        int zero = 0;
        cpuset(&zero, pals + 16 * (pal_idx + 16), CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
    }
    OW_DEBUG("Reflection palette set up done.\n");
    oam->final_oam.attr2 = (u16)((pal_idx << 12) | (oam->final_oam.attr2 & ~(15 << 12)));
    // OW_DEBUG("Created reflective pal at slot %d\n", pal_idx);
    // OW_DEBUG("Attribute2 is 0x%x\n", oam->final_oam.attr2);
}

void npc_free_palette_if_unused(u16 tag) {
    OW_DEBUG("Attempting to free npc palette 0x%x\n", tag);
    if (tag == 0xFFFF || tag == 0x1200) // 0x1200 is the tag for weather effects, we mustn't release those
        return;
    u8 slot = oam_palette_get_index(tag);
    if (slot == 0xFF)
        return;
    for (int i = 0; i < 16; i++) {
        if (!npcs[i].flags.active) continue;
        oam_object *oam = oams + npcs[i].oam_id;
        if (((oam->final_oam.attr2 >> 12) & 0xF) == slot) {
            return; // This palette is still referenced by at least one npc
        }
    }
    
    if (tag == 0x1200) // This tag is used by weather effects, we never can release this palette...
        return; 
    oam_palette_free(tag);
    // OW_DEBUG("Released palette %d with tag 0x%x\n", pal_idx, tag);
}

void npc_free_palette_if_unused_by_slot(u8 slot) {
    u16 tag = oam_palette_get_tag(slot);
    if (tag == 0xFFFF) return;
    npc_free_palette_if_unused(tag);
}

void npc_free_resources(npc *n) {
    if (n->flags.has_rage_sprite) {
        npc_delete_rage_sprite(n->oam_surf);
    }
    graphic tmp;
    tmp.size = overworld_get_by_npc(n)->size;
    oams[n->oam_id].gfx_table = &tmp;
    u8 pal_idx = (u8)((oams[n->oam_id].final_oam.attr2 >> 12) & 0xF);
    OW_DEBUG("Deleted resources for npc 0x%x with oam %d\n", n, n->oam_id);
    oam_delete(oams + n->oam_id);
    npc_free_palette_if_unused_by_slot(pal_idx);
}


void overworld_effect_surfing_pokemon_setup_oam(u8 oam_idx) {
    // Only the setup-part for the surfing pokemon (the blob below the hiro)
    oam_object *o = oams + oam_idx;
    o->flags |= OAM_FLAG_CENTERED;
    o->private[2] = (u16)overworld_effect_state.height;
    o->private[3] = 0;
    o->private[6] = 0xFFFF;
    o->private[7] = 0xFFFF;
    // Allocate (or rather match) the player palette
    // This oam has a tag of 0xFFFF so that it can't kill the player palette once it despawns...
    u8 pal_idx = overworld_npc_palette_load(0x1100);
    o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
}

oam_object *overworld_effect_fly_allocate_pal(u8 oam_idx) { // Probably for fly...
    oam_object *o = oams + oam_idx;
    u8 pal_idx = overworld_npc_palette_load(0x1100);
    o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
    return o; // We return this so that we can remove more code for the patch... (ugly, hacky, call it whatever you want...)
}

static const u16 overworld_effect_shadow_vertical_offsets[4] = {4, 4, 4, 16,};
static const u8 overworld_effect_shadow_template_idxs[4] = {0, 1, 2, 3};

extern color_t gfx_npc_player_palette_vanilla[16];

u32 overworld_effect_shadow(void) {
    u8 npc_idx = npc_get_by_person_idx((u8)(overworld_effect_state.x), (u8)(overworld_effect_state.y), (u8)(overworld_effect_state.height));
    overworld_sprite *ow = overworld_get_by_npc(npcs + npc_idx);
    u8 oam_idx = oam_new_backward_search(overworld_effect_oam_templates[overworld_effect_shadow_template_idxs[ow->shadow_size]], 0, 0, 0x94);
    if (oam_idx != 64) {
        oam_object *o = oams + oam_idx;
        o->flags |= OAM_FLAG_CENTERED;
        o->private[0] = (u16)overworld_effect_state.x;
        o->private[1] = (u16)overworld_effect_state.y;
        o->private[2] = (u16)overworld_effect_state.height;
        o->private[3] = (u16)((ow->height / 2) - overworld_effect_shadow_vertical_offsets[ow->shadow_size]);
        palette pal = {0};
        pal.tag = TAG_PLAYER_PALETTE_VANILLA;
        pal.pal = gfx_npc_player_palette_vanilla;
        u8 pal_idx = oam_palette_load_if_not_present_and_apply_shaders(&pal);
        o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
    }
    return 0;
}


void overworld_effect_emotion_bubble_start(oam_object *o, u16 arg2, u8 anim_idx) {
    u8 pal_idx = overworld_npc_palette_load(0x1100);
    o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
    o->flags |= OAM_FLAG_CENTERED;
    o->private[0] = (u16)overworld_effect_state.x;
    o->private[1] = (u16)overworld_effect_state.y;
    o->private[2] = (u16)overworld_effect_state.height;
    o->private[6] = 0xFFFB;
    o->private[7] = arg2;
    oam_gfx_anim_start(o, anim_idx);
}

void overworld_effect_show_warp_arrow(u8 oam_idx, u8 direction, s16 x, s16 y) {
    // OW_DEBUG("Arrow at %d, %d\n", x, y);
    oam_object *o = oams + oam_idx;
    if ((o->flags & OAM_FLAG_INVISIBLE) || (s16)(o->private[0]) != x || (s16)(o->private[1]) != y) { // This is a super hacky way by the game engine to check if there already is an arrow...
        s16 oam_x = 0, oam_y = 0;
        map_position_to_oam_position((s16)x, (s16)y, &oam_x, &oam_y);
        o->x = (s16)(oam_x + 8);
        o->y = (s16)(oam_y + 8);
        // OW_DEBUG("Create arrow with screen coordinates. %d, %d", oam_x, oam_y);
        o->flags &= (u16)(~(OAM_FLAG_INVISIBLE));
        o->private[0] = (u16)x;
        o->private[1] = (u16)y;
        u8 pal_idx = overworld_npc_palette_load(0x1100);
        o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
        oam_gfx_anim_start(o, (u8)(direction - 1));
    }
}

u8 overworld_effect_warp_arrow_and_detector_arrow_new() {
    OW_DEBUG("new warp arrow\n");
    u8 oam_idx = oam_new_backward_search(&overworld_effect_arrow_template, 0, 0, 0x52);
    if (oam_idx < NUM_OAMS) {
        oam_object *o = oams + oam_idx;
        o->final_oam.attr2 = (u16)((o->final_oam.attr2 & (~ATTR2_PRIO(3))) | ATTR2_PRIO(1));
        o->flags |= OAM_FLAG_INVISIBLE | OAM_FLAG_CENTERED;
    }
    return oam_idx;
}

extern oam_template oam_template_item_finder_arrow;

void itemfinder_create_arrow_sprite(u8 anim_idx, u8 direction) {
    // OW_DEBUG("Item finder create arrow in direction %d\n", direction);
    u8 oam_idx = oam_new_forward_search(&oam_template_item_finder_arrow, 120, 76, 0);
    oam_object *o = oams + oam_idx;
    oam_gfx_anim_start(o, anim_idx);
    o->private[7] = anim_idx;
    o->private[0] = 0;
    o->private[3] = 0;
    o->private[4] = 0;
    o->private[5] = 120;
    o->private[6] = 76;
    switch (direction) {
        case DIR_NONE: {
            switch(player_get_facing()) {
                case DIR_LEFT:
                    o->private[1] = (u16)(-100);
                    o->private[2] = 0;
                    oam_rotscale_anim_init(o, 0);
                    break;
                case DIR_UP:
                    o->private[1] = 0;
                    o->private[2] = (u16)(-100);
                    oam_rotscale_anim_init(o, 3);
                    break;
                case DIR_RIGHT:
                    o->private[1] = (u16)(100);
                    o->private[2] = 0;
                    oam_rotscale_anim_init(o, 2);
                    break;
                case DIR_DOWN:
                    o->private[1] = 0;
                    o->private[2] = (u16)(100);
                    oam_rotscale_anim_init(o, 1);
                    break;
            }
            break;
        }
        case DIR_DOWN:
            o->private[1] = 0;
            o->private[2] = (u16)(-100);
            oam_rotscale_anim_init(o, 3);
            break;
        case DIR_UP:
            o->private[1] = (u16)(100);
            o->private[2] = 0;
            oam_rotscale_anim_init(o, 2);
            break;
        case DIR_LEFT:
            o->private[1] = 0;
            o->private[2] = (u16)(100);
            oam_rotscale_anim_init(o, 1);
            break;
        case DIR_RIGHT:
            o->private[1] = (u16)(-100);
            o->private[2] = 0;
            oam_rotscale_anim_init(o, 0);
            break;
    }
}

void item_finder_oam_callback_star(oam_object *self);

u8 item_finder_create_star() {
    u8 oam_idx = oam_new_forward_search(&oam_template_item_finder_arrow, 120, 76, 0);
    oam_object *o = oams + oam_idx;
    o->callback = item_finder_oam_callback_star;
    oam_gfx_anim_start(o, 4);
    o->private[7] = 0;
    o->private[0] = 0;
    o->private[3] = 0;
    o->private[4] = 0;
    o->private[5] = 120;
    o->private[6] = 76;
    o->private[1] = 0;
    o->private[2] = (u16)(-100);
    return oam_idx;
}

extern graphic graphic_item_finder_arrow;
extern color_t gfx_item_finder_arrowPal[];

palette palette_item_finder_arrow = {
    .pal = gfx_item_finder_arrowPal, .tag = ITEM_FINDER_TAG,
};

void item_finder_load_gfx_and_pal() {
    oam_load_graphic_uncompressed(&graphic_item_finder_arrow);
    oam_palette_load_if_not_present_and_apply_shaders(&palette_item_finder_arrow);
}

void item_finder_free_gfx_and_pal() {
    oam_palette_free(ITEM_FINDER_TAG);
    oam_free_vram_by_tag(ITEM_FINDER_TAG);
}


static void overworld_create_oam_template_by_overworld_sprite_with_callback(overworld_sprite *sprite, u16 movement_callback_idx, oam_template *template, subsprite_table **subsprites) {
    template->tiles_tag = sprite->tiles_tag;
    template->pal_tag = sprite->pal_tag;
    template->oam = sprite->final_oam;
    template->animation = sprite->gfx_animation;
    template->rotscale = sprite->rotscale_animation;
    template->graphics = sprite->graphics;
    // We don't give a damn about this quest log stuff
    template->callback = npc_movements_oam_callbacks[movement_callback_idx];
    if (sprite->subsprite_table)
        *subsprites = sprite->subsprite_table;
}

void overworld_create_oam_template_by_npc_with_movement_callback(npc *n, u16 movement_callback_idx, oam_template *template, subsprite_table **subsprites) {
    overworld_sprite *sprite = overworld_get_by_npc(n);
    overworld_create_oam_template_by_overworld_sprite_with_callback(sprite, movement_callback_idx, template, subsprites);
}

void overworld_create_oam_template_by_person(map_event_person *person, oam_template *template, subsprite_table **subsprites) {
    overworld_sprite *sprite = overworld_get_by_person(person);
    overworld_create_oam_template_by_overworld_sprite_with_callback(sprite, person->behavior, template, subsprites);
}

static graphic graphics_rage[] = {
    [RAGE_SPRITE_RAGE] = {gfx_ow_rageTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16)},
    [RAGE_SPRITE_QUESTION_MARK] = {gfx_ow_rageTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16)},
};

static gfx_frame gfx_animation_rage[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame gfx_animation_question_mark[] = {
    {.data = 1, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame *gfx_animations_rage[] = {gfx_animation_rage, gfx_animation_question_mark};

static rotscale_frame rotscale_animation_rage_grow[] = {
    {.affine = {.affine_x_value = 16, .affine_y_value = 16, .rotation = 0, .duration = 0}},
    {.affine = {.affine_x_value = 256 / 16, .affine_y_value = 256 / 16, .rotation = 0, .duration = 15}},
    {.affine = {.affine_x_value = 0, .affine_y_value = 0, .rotation = 0, .duration = 11}},
    {.affine = {.affine_x_value = -256 / 16, .affine_y_value = -256 / 16, .rotation = 0, .duration = 14}},
    {.command = {.command = ROTSCALE_ANIM_END}},
};

static rotscale_frame rotscale_animation_rage_idle[] = {
    {.affine = {.affine_x_value = 256, .affine_y_value = 256, .rotation = 0, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}},
};

static rotscale_frame *rotscale_animations_rage[] = {
    [0] = rotscale_animation_rage_idle,
    [1] = rotscale_animation_rage_grow,
};

static sprite sprite_rage = {
    .attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1),
};

static void oam_callback_rage(oam_object *self) {
    u8 npc_idx = (u8)self->private[0];
    // Since the sprite is centered, use half the circle 
    if (overworld_effect_is_oam_outside_camera_view(npcs[npc_idx].dest_x, npcs[npc_idx].dest_y, 16, 16)) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        self->x = oams[npcs[npc_idx].oam_id].x; // A bit hacky, but w/e
        self->y = oams[npcs[npc_idx].oam_id].y;
        u16 *position = self->private + 1;
        u16 *frame = self->private + 2;
        switch (self->private[3]) {
            case RAGE_SPRITE_RAGE:
                if (++*frame >= 16 + 16 + 8) {
                    *frame = 0;
                    *position = (u16)(*position ^ 1);
                    oam_rotscale_anim_init(self, 1);
                    if (*position) {
                        self->x2 = -3;
                        self->y2 = -5;
                    } else {
                        self->x2 = 2;
                        self->y2 = -2;
                    }
                }
                break;
            case RAGE_SPRITE_QUESTION_MARK:
                self->y2 = (s16) (FIXED_TO_INT(FIXED_MUL(INT_TO_FIXED(2), FIXED_SIN(FIXED_DIV(INT_TO_FIXED(*frame), INT_TO_FIXED(64))))) - 12);
                *frame = (u16)((*frame + 1) % 64);
                break;
        }
    }
}

static oam_template oam_template_rage = {
    .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_RAGE_SIGN, .oam = &sprite_rage,
    .animation = gfx_animations_rage, .graphics = graphics_rage,
    .rotscale = rotscale_animations_rage, .callback = oam_callback_rage,
};

static palette palette_rage = {.pal = gfx_ow_ragePal, .tag = OW_PAL_TAG_RAGE_SIGN};

static bool npc_rage_sprite_active() {
    for (u8 i = 0; i < NUM_NPCS; i++) {
        if (npcs[i].flags.active && npcs[i].flags.has_rage_sprite)
            return true;
    }
    return false;
}

void npc_delete_rage_sprite(u8 oam_idx) {
    oam_free_graphic(oams + oam_idx);
    if (!npc_rage_sprite_active()) {
        OW_DEBUG("Rage effect sprite palette freed, not in use anymore.\n");
        oam_palette_free(OW_PAL_TAG_RAGE_SIGN);
    }
    oam_rotscale_free(oams + oam_idx);
    oam_delete(oams + oam_idx);
}

void special_delete_rage_sprite() {
    u8 person_idx = (u8)*var_access(0x8004);
    u8 npc_idx = npc_get_by_person_idx(person_idx, save1->map, save1->bank);
    if (npc_idx < NUM_NPCS && npcs[npc_idx].flags.has_rage_sprite) {
        npc_delete_rage_sprite(npcs[npc_idx].oam_surf);
        npcs[npc_idx].flags.has_rage_sprite = 0;
    }
}

u8 overworld_create_rage_sprite(u8 npc_idx, u8 type) {
    OW_DEBUG("Create rage sprite for person %d\n", npcs[npc_idx].overworld_id);
    oam_palette_load_if_not_present_and_apply_shaders(&palette_rage);
    u8 oam_idx = oam_new_backward_search(&oam_template_rage, 0, 0, 0);
    if (oam_idx < 64) {
        oam_object *o = oams + oam_idx;
        o->x_centre = -8;
        o->y_centre = -8;
        o->y = (s16)(o->y + o->y_centre);
        o->flags |= OAM_FLAG_CENTERED;
        o->private[0] = npc_idx;
        o->private[3] = type;
        u8 z = npcs[npc_idx].height.current;
        oam_set_priority_by_height(o, z);
        oam_set_subpriority_by_height(z, o, 0);
        oam_gfx_anim_start(o, type);
        o->callback(o);
    }   
    return oam_idx;
}

u8 overworld_create_oam_by_person(map_event_person *person, u8 a1, s16 x, s16 y, u8 z, u8 direction) {
    overworld_sprite *ow = overworld_get_by_person(person);
    oam_template template = {0};
    subsprite_table *subsprites = NULL;
    overworld_create_oam_template_by_person(person, &template, &subsprites);
    x = (s16)(x + 7);
    y = (s16)(y + 7);
    overworld_effect_ow_coordinates_to_screen_coordinates(&x, &y, 8, 16);
    overworld_npc_load_palette_by_template(&template);
    u8 oam_idx = oam_new_backward_search(&template, x, y, 0);
    if (oam_idx < 64) {
        oam_object *o = oams + oam_idx;
        o->x_centre = (s8)(-(ow->width >> 1));
        o->y_centre = (s8)(-(ow->height >> 1));
        o->y = (s16)(o->y + o->y_centre);
        o->flags |= OAM_FLAG_CENTERED;
        o->private[0] = a1;
        o->private[1] = z;
        if (subsprites) {
            oam_set_subsprite_table(o, subsprites);
            o->sprite_mode = 2;
        }
        oam_set_priority_by_height(o, z);
        oam_set_subpriority_by_height(z, o, 1);
        oam_gfx_anim_start(o, npc_get_animation_idx_by_facing(direction));
    }
    return oam_idx;
}

u8 overworld_create_npc_and_oam_by_person(map_event_person *person, u8 map, u8 bank, s16 cam_x, s16 cam_y) {
    oam_template template;
    subsprite_table *subsprite_tables = NULL;
    graphic g;
    overworld_sprite *ow = overworld_get_by_person(person);
    overworld_create_oam_template_by_person(person, &template, &subsprite_tables);
    g.size = ow->size;
    template.graphics = &g;
    u8 npc_idx = npc_create_with_oam_by_person(person, &template, map, bank, cam_x, cam_y);
    if (npc_idx >= NUM_NPCS) 
        return NUM_NPCS;
    oams[npcs[npc_idx].oam_id].gfx_table = ow->graphics;
    if (subsprite_tables)
        oam_set_subsprite_table(oams + npcs[npc_idx].oam_id, subsprite_tables);
    if (person->script_std == PERSON_AGGRESSIVE_POKEMON) {
        npcs[npc_idx].flags.has_rage_sprite = 1;
        npcs[npc_idx].oam_surf = overworld_create_rage_sprite(npc_idx, RAGE_SPRITE_RAGE);
    } else if (npcs[npc_idx].overworld_id == 254) {
        npcs[npc_idx].flags.has_rage_sprite = 1;
        npcs[npc_idx].oam_surf = overworld_create_rage_sprite(npc_idx, RAGE_SPRITE_QUESTION_MARK);
    }
    return npc_idx;
}

void overworld_create_rage_if_needed(u8 npc_idx) {
    map_event_person *p = map_get_person(npcs[npc_idx].overworld_id, npcs[npc_idx].map, npcs[npc_idx].bank);
    if (p && p->script_std == PERSON_AGGRESSIVE_POKEMON) {
        npcs[npc_idx].flags.has_rage_sprite = 1;
        npcs[npc_idx].oam_surf = overworld_create_rage_sprite(npc_idx, RAGE_SPRITE_RAGE);
    } else if (npcs[npc_idx].overworld_id == 254) {
        npcs[npc_idx].flags.has_rage_sprite = 1;
        npcs[npc_idx].oam_surf = overworld_create_rage_sprite(npc_idx, RAGE_SPRITE_QUESTION_MARK);
    }
}

u8 overworld_create_oam_with_callback_by_npc(npc *n, void (*callback)(oam_object*), s16 x, s16 y, u8 subpriority) {
    oam_template template;
    subsprite_table *subsprites;
    overworld_create_oam_template_by_npc_with_movement_callback(n, 0, &template, &subsprites);
    template.callback = callback;
    overworld_npc_load_palette_by_template(&template);
    u8 oam_idx = oam_new_backward_search(&template, x, y, subpriority);
    if (oam_idx < 64 && subsprites != NULL) {
        oam_set_subsprite_table(oams + oam_idx, subsprites);
        oams[oam_idx].sprite_mode = 2;
        overworld_create_rage_if_needed(npc_get_by_person_idx(n->overworld_id, n->map, n->bank));
    }
    return oam_idx;
}


void big_callback_time_based_events(u8 self) {
    if (!ow_script_is_active()) {
        ambient_cry_proceed(big_callbacks[self].params + 1, big_callbacks[self].params + 2);
        time_based_events_proceed(big_callbacks[self].params + 0);
    }
}

void overworld_big_callbacks_initialize() {
    if (!big_callback_is_active(overworld_step_callback_proceed)) {
        u8 cb_idx = big_callback_new(overworld_step_callback_proceed, 0x50);
        big_callbacks[cb_idx].params[0] = OVERWORLD_STEP_CALLBACK_NONE;
    }
    if (!big_callback_is_active(big_callback_time_based_events)) {
        big_callback_new(big_callback_time_based_events, 0x50);
    }
    if (!big_callback_is_active(overworld_static_detector_callback)) {
        u8 cb_idx = big_callback_new(overworld_static_detector_callback, 0x50);
        // Set x and y coordinates of the callback to something invalid, so it will be updated imideatly when the oam is present
        big_callbacks[cb_idx].params[DETECTOR_CB_VAR_OAM_IDX_ARROW] = overworld_effect_static_detector_arrow_new();
        big_callbacks[cb_idx].params[DETECTOR_CB_VAR_X] = 0xFFFF;
        big_callbacks[cb_idx].params[DETECTOR_CB_VAR_Y] = 0xFFFF;
        OW_DEBUG("New detector field callback.\n");
    }
}

void player_npc_set_invisible() {
    //
    u8 npc_idx = npc_get_by_person_idx(0xFF, save1->map, save1->bank);
    if (npc_idx < NUM_NPCS) {
        npcs[npc_idx].flags.invisible = 1;
        npcs[npc_idx].flags.jump_landing_ground_effect_disabled = 1;
        npcs[npc_idx].flags.covering_ground_effects_disabled = 1;
        npcs[npc_idx].flags.trigger_ground_effects_on_move = 0;
        npcs[npc_idx].flags.trigger_ground_effects_on_stop = 0;
    }
}

void overworld_npc_gfx_animation_new() {
    u8 ow_idx = (u8)*var_access(0x8004);
    u8 anim_idx = (u8)*var_access(0x8005);
    u8 npc_idx = npc_get_by_person_idx(ow_idx, save1->map, save1->bank);
    if (npc_idx < 16) {
        oam_gfx_anim_start(oams + npcs[npc_idx].oam_id, anim_idx);
    }
}

u8 npc_create_camera(u8 picture,u8 behaviour,u8 person_idx,s16 x,s16 y,u8 level) {
    map_event_person p;
    memset(&p, 0, sizeof(map_event_person)); // The vanilla game excludes this, resulting in undefined flags for camera overworlds...
    p.target_index = person_idx;
    p.overworld_index = picture;
    p.x = (s16)(x - 7);
    p.y = (s16)(y - 7);
    p.level = level;
    p.behavior = behaviour;
    return npc_create_camera_by_person(&p);
}

u16 person_get_flag(u8 person_idx, u8 map_idx, u8 bank) {
    map_event_person *person = map_get_person(person_idx, map_idx, bank);
    if (!person) // Bug-fix from initial game: Attempted to read from NULL, which results in undefined behaviour on emulators.
        return 0;
    else
        return person->flag;
}