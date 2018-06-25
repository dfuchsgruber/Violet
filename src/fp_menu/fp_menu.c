#include "types.h"
#include "bg.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "fp_menu.h"
#include "field_move.h"
#include "pokemon/basestat.h"
#include "pokemon/sprites.h"
#include "pokemon/cry.h"
#include "color.h"
#include "superstate.h"
#include "constants/pokemon_attributes.h"
#include "language.h"
#include "agbmemory.h"
#include "io.h"
#include "bios.h"
#include "music.h"
#include "overworld/map_control.h"
#include "overworld/pokemon_party_menu.h"
#include "fading.h"

extern const unsigned short gfx_fp_menu_arrow_upTiles[];
extern const unsigned short gfx_fp_menu_arrow_leftTiles[];
extern const unsigned short gfx_fp_menu_bgMap[];
extern const unsigned short gfx_fp_menu_bgTiles[];
extern const unsigned short gfx_fp_menu_bgPal[];
extern const unsigned short gfx_fp_menu_arrow_upPal[];

void fp_menu_init(u8 self) {
    fmem->fp_mem = (fp_memory*) malloc_and_clear(sizeof (fp_memory));
    fmem->fp_mem->poke_index = *pokemon_party_menu_current_index;
    fadescreen_all(1, 0);
    callback1_set(fp_menu_callback_init);
    big_callback_delete(self);
}

bg_config fp_menu_bg_configs[2] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 1},
};

tboxdata fp_menu_tboxes [] = {
    {0, 3, 1, 8, 2, 15, 1}, //0 := pokemon name
    {0, 13, 7, 3, 2, 15, 17}, //1 := sum of evs
    {0, 13, 4, 2, 2, 15, 25}, //2 := lvl
    {0, 21, 4, 3, 2, 15, 29}, //3-9 := stats
    {0, 26, 4, 3, 2, 15, 35},
    {0, 21, 7, 3, 2, 15, 41},
    {0, 26, 7, 3, 2, 15, 47},
    {0, 21, 10, 3, 2, 15, 53},
    {0, 26, 10, 3, 2, 15, 59},
    {0, 3, 12, 8, 2, 15, 65}, //9 := stat name
    {0, 15, 15, 3, 2, 15, 95}, //10 := usable
    {0, 24, 15, 3, 2, 15, 101}, //11 := used
    {0, 15, 18, 3, 2, 15, 107}, //12 := bonus
    {0xFF, 0, 0, 0, 0, 0, 0}
};

tbox_font_colormap fp_menu_fontcolmap_std = {
    0, 2, 1, 3
};

tbox_font_colormap fp_menu_fontcolmap_red = {
    0, 5, 1, 3
};

tbox_font_colormap fp_menu_fontcolmap_blue = {
    0, 9, 1, 3
};

u8 fp_menu_attributes_fp_applied[6] = {//Mapping hp, atk, def, int, satk, sdef to their respective contest attributes
    ATTRIBUTE_COOLNESS, ATTRIBUTE_BEAUTY, ATTRIBUTE_CUTENESS, ATTRIBUTE_SMARTNESS, ATTRIBUTE_TOUGHNESS, ATTRIBUTE_SHEEN
};

sprite fp_menu_oam_poke_sprite = {0, 0xC000, 0x0, 0x0};

oam_template fp_menu_oam_poke_template = {
    0xA000,
    0xA000,
    &fp_menu_oam_poke_sprite,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    fp_menu_pokepic_callback
};

sprite fp_menu_arrow_sprite_down = {0, 0x4000, 0, 0};
sprite fp_menu_arrow_sprite_up = {0, 0x6000, 0, 0};
sprite fp_menu_arrow_sprite_left = {0, 0x4000, 0, 0};
sprite fp_menu_arrow_sprite_right = {0, 0x5000, 0, 0};


graphic fp_menu_graphic_arrow_vertical = {
    &gfx_fp_menu_arrow_upTiles,
    0x80,
    0xA001
};

graphic fp_menu_graphic_arrow_horizontal = {
    &gfx_fp_menu_arrow_leftTiles,
    0x80,
    0xA002
};

oam_template fp_menu_oam_arrow_template_down = {
    0xA001,
    0xA001,
    &fp_menu_arrow_sprite_down,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    oam_null_callback
};

oam_template fp_menu_oam_arrow_template_up = {
    0xA001,
    0xA001,
    &fp_menu_arrow_sprite_up,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    oam_null_callback
};

oam_template fp_menu_oam_arrow_template_left = {
    0xA002,
    0xA001,
    &fp_menu_arrow_sprite_left,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    oam_null_callback
};

oam_template fp_menu_oam_arrow_template_right = {
    0xA002,
    0xA001,
    &fp_menu_arrow_sprite_right,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    OAM_ROTSCALE_ANIM_TABLE_NULL,
    oam_null_callback
};

void fp_menu_callback_init() {
    generic_callback1();
    if (!fading_is_active()) {
        big_callback_delete_all();
        pokemon_party_menu_free();
        oam_reset();
        oam_palette_allocation_reset();
        bg_reset(0);
        bg_setup(0, fp_menu_bg_configs, 2);
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_display_sync();
        bg_virtual_map_displace(0, 0, 0);
        bg_virtual_set_displace(0, 0, 0);
        bg_virtual_map_displace(1, 0, 0);
        bg_virtual_set_displace(1, 0, 0);
        io_set(0x10, 0);
        io_set(0x12, 0);
        io_set(0x14, 0);
        io_set(0x16, 0);

        //we init the backgrounds

        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        void *bg0map = malloc_and_clear(0x800);
        void *bg1map = malloc_and_clear(0x800);
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        lz77uncompwram(gfx_fp_menu_bgMap, bg1map);
        lz77uncompvram(gfx_fp_menu_bgTiles, (void*) 0x06000000);


        //init the textboxes
        tbox_sync_with_virtual_bg_and_init_all(fp_menu_tboxes);

        //init the oams
        u16 tile_pokepic = oam_vram_alloc(64);
        oam_vram_allocation_table_add(0xA000, tile_pokepic, 64);
        fmem->fp_mem->pal_pokepic = oam_allocate_palette(0xA000);
        fmem->fp_mem->tile_pokepic = tile_pokepic;
        fmem->fp_mem->oam_pokepic = oam_new_forward_search(&fp_menu_oam_poke_template, 64, 56, 0);
        oams[fmem->fp_mem->oam_pokepic].y2 = -96;

        //arrows
        oam_load_graphic(&fp_menu_graphic_arrow_vertical);
        oam_load_graphic(&fp_menu_graphic_arrow_horizontal);
        u8 arrow_pal = oam_allocate_palette(0xA001);
        fmem->fp_mem->oam_arrows[0] = oam_new_forward_search(&fp_menu_oam_arrow_template_down, 16, 32, 0);
        fmem->fp_mem->oam_arrows[1] = oam_new_forward_search(&fp_menu_oam_arrow_template_up, 16, 76, 0);
        fmem->fp_mem->oam_arrows[2] = oam_new_forward_search(&fp_menu_oam_arrow_template_left, 12, 100, 0);
        fmem->fp_mem->oam_arrows[3] = oam_new_forward_search(&fp_menu_oam_arrow_template_right, 124, 100, 0);
        big_callback_new(fp_menu_callback_arrow_anim, 0);


        fp_menu_pokemon_load();

        //load palettes
        pal_decompress(gfx_fp_menu_bgPal, 0, 32);
        pal_decompress(gfx_fp_menu_arrow_upPal, (u16) (256 + arrow_pal * 16), 32);

        callback1_set(fp_menu_callback_show);
        pal_set_all_to_black(); //we avoid the 1frame show of a pal

        bg_virtual_sync(0);
        bg_virtual_sync(1);
    }
}

void fp_menu_callback_show() {
    if (!fading_is_active()) {
        oams[fmem->fp_mem->oam_pokepic].y2 = 0;
        fadescreen_all(0, 0);
        callback1_set(fp_menu_callback_idle);
    }
    generic_callback1();
}

void fp_menu_callback_idle() {
    generic_callback1();
    if (!fading_is_active()) {
        pokemon *target = &player_pokemon[fmem->fp_mem->poke_index];
        u8 stat = fmem->fp_mem->stat_index;
        u8 pokemon_cnt = pokemon_get_number_in_party();
        if (big_callback_is_active(fp_menu_callback_poke_jump)) return; //we have to wait for interaction
        if (fmem->fp_mem->delay) {
            fmem->fp_mem->delay--;
            return;
        }

        //Now we can interagate with the player
        if (super->keys_new.keys.B) {
            oams[fmem->fp_mem->oam_pokepic].private[2] = 1; //prevent the color animation to appear during fadeout
            play_sound(5);
            callback1_set(fp_menu_callback_return);
            fadescreen_all(1, 0);
        } else if (super->keys_new.keys.A) {
            //Check if the stat can be increased
            int fp_earned = (int) pokemon_get_attribute(target, (u8) (ATTRIBUTE_HP_EV + stat), NULL);
            u8 fp_used = pokemon_get_fp_applied(target, stat);
            int fp_applied_sum = fp_menu_get_sum_applied(target) * 4;
            if (fp_applied_sum < 507 && fp_earned - fp_used * 4 > 3) {
                //Possible to add another
                pokemon_set_fp_applied(target, stat, (u8) (fp_used + 1));
                pokemon_calculate_stats(target);
                fp_menu_stats_load(target);
                play_sound(84);
            } else {
                play_sound(26);
            }
        } else if (super->keys_new.keys.left) {
            fmem->fp_mem->stat_index = (u8) ((stat + 5) % 6);
            fp_menu_stat_load(target);
            play_sound(5);
        } else if (super->keys_new.keys.right) {
            fmem->fp_mem->stat_index = (u8) ((stat + 1) % 6);
            fp_menu_stat_load(target);
            play_sound(5);
        } else if (super->keys_new.keys.down) {
            u8 next_index = fmem->fp_mem->poke_index;
            do {
                next_index = (u8) ((next_index + 1) % pokemon_cnt);
                if (!pokemon_get_attribute(&player_pokemon[next_index], ATTRIBUTE_IS_EGG, NULL)) {
                    //load this pokemon
                    fmem->fp_mem->poke_index = next_index;
                    fmem->fp_mem->pokepic_loading_state = 0;
                    callback1_set(fp_menu_callback_pokemon_load);
                }
            } while (next_index != fmem->fp_mem->poke_index);
        } else if (super->keys_new.keys.up) {
            u8 next_index = fmem->fp_mem->poke_index;
            do {
                next_index = (u8) ((next_index + pokemon_cnt - 1) % pokemon_cnt);
                if (!pokemon_get_attribute(&player_pokemon[next_index], ATTRIBUTE_IS_EGG, NULL)) {
                    //load this pokemon
                    fmem->fp_mem->poke_index = next_index;
                    fmem->fp_mem->pokepic_loading_state = 0;
                    callback1_set(fp_menu_callback_pokemon_load);
                }
            } while (next_index != fmem->fp_mem->poke_index);
        }
    }
}

void fp_menu_callback_pokemon_load() {
    generic_callback1();
    switch (fmem->fp_mem->pokepic_loading_state) {
        case 1:
            oams[fmem->fp_mem->oam_pokepic].y2 = -96; //disable the oam temporarily
            break;
        case 2:
            fp_menu_pokemon_load();
            oams[fmem->fp_mem->oam_pokepic].y2 = -0; //disable the oam temporarily
            callback1_set(fp_menu_callback_idle);
            break;
    }
    fmem->fp_mem->pokepic_loading_state++;
}

void fp_menu_callback_return() {
    if (!fading_is_active()) {
        u8 *team_index = (u8*) 0x0203B16C;
        *team_index = fmem->fp_mem->poke_index;

        //Drop maps
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(fmem->fp_mem);
        tbox_free_all();
        callback1_set((void*) 0x8122df5);
    }
    generic_callback1();

}

void fp_menu_pokemon_load() {
    pokemon *target = &player_pokemon[fmem->fp_mem->poke_index];
    int species = pokemon_get_attribute(target, ATTRIBUTE_SPECIES, NULL);

    int *obj_vram = (int*) 0x06010000; //we declare it as int, because we have not better declaration
    lz77uncompvram(pokemon_frontsprites[species].sprite, &obj_vram[8 * fmem->fp_mem->tile_pokepic]);

    //to load the pal we determine if the pokemon is shiny
    pid_t poke_pid = {.value = (u32)pokemon_get_attribute(target, ATTRIBUTE_PID, 0)};
    if (poke_pid.fields.shinyness <= 512) {
        pal_decompress(pokemon_shiny_pals[species].pal, (u16) (256 + 16 * fmem->fp_mem->pal_pokepic), 32);
    } else {
        pal_decompress(pokemon_pals[species].pal, (u16) (256 + 16 * fmem->fp_mem->pal_pokepic), 32);
    }

    //print the nickname
    pokemon_get_attribute(target, ATTRIBUTE_NICKNAME, strbuf);
    tbox_flush_set(0, 0);
    tbox_tilemap_draw(0);
    tbox_print_string(0, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, strbuf);

    //print the level
    itoa(strbuf, pokemon_get_attribute(target, ATTRIBUTE_LEVEL, NULL), 0, 2);
    tbox_flush_set(2, 0);
    tbox_tilemap_draw(2);
    tbox_print_string(2, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, strbuf);

    fp_menu_stats_load(target);

    //spawn the movement callback for the pokemon jumping
    big_callback_new(fp_menu_callback_poke_jump, 0);

    pokemon_play_cry((u16) species, 0);

}

u16 fp_menu_get_sum_applied(pokemon *target) {

    int i;
    u16 sum = 0;
    for (i = 0; i < 6; i++)
        sum = (u16) (sum + pokemon_get_fp_applied(target, i));
    return sum;
}

void fp_menu_stats_load(pokemon *target) {
    //print the stats
    
    //determining which stat to print red (boosted) and which one blue (nerved)
    u8 nature = pokemon_get_nature(target);
    int stat_boosted = (nature / 5) + 1;
    int stat_nerved = (nature % 5) + 1;
    int i; 
    for (i = 0; i < 6; i++) {
        u8 *str = itoa(strbuf, pokemon_get_attribute(target, (u8) (ATTRIBUTE_TOTAL_HP + i), NULL), 0, 3);
        u8 box_id = (u8) (3 + i);
        tbox_flush_set(box_id, 0);
        tbox_font_colormap fontcolmap = fp_menu_fontcolmap_std;
        if (i == stat_boosted && i != stat_nerved) {
            fontcolmap = fp_menu_fontcolmap_red;
            u8 str_plus[] = PSTRING("+");
            strcat(str, str_plus);
        } else if (i == stat_nerved && i != stat_boosted) {
            fontcolmap = fp_menu_fontcolmap_blue;
            u8 str_minus[] = PSTRING("-");
            strcat(str, str_minus);
        }
        tbox_tilemap_draw(box_id);
        tbox_print_string(box_id, 2, 0, 0, 0, 0, &fontcolmap, 0, strbuf);
    }

    //print the sum of evs
    int ev_sum =  4 * fp_menu_get_sum_applied(target);
    itoa(strbuf, ev_sum, 0, 3);
    tbox_flush_set(1, 0);
    tbox_tilemap_draw(1);
    tbox_print_string(1, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, strbuf);

    fp_menu_stat_load(target);
}

void fp_menu_stat_load(pokemon *target) {
    u8 stat = fmem->fp_mem->stat_index;

    //load the stats name
    tbox_flush_set(9, 0);
    tbox_tilemap_draw(9);
    tbox_print_string(9, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, fp_menu_names[stat]);

    int fp_earned = (int) pokemon_get_attribute(target, (u8) (ATTRIBUTE_HP_EV + stat), NULL);
    int fp_applied = pokemon_get_fp_applied(target, stat) * 4;
    int fp_free = (fp_earned - fp_applied) & (~3);

    //We create a copy of the pokemon without any fp_applied to get the bonus as difference
    memcpy(opponent_pokemon, target, sizeof (pokemon));
    pokemon_set_fp_applied(opponent_pokemon, stat, 0);
    pokemon_calculate_stats(opponent_pokemon);

    int stat_bonus = (int) pokemon_get_attribute(target, (u8) (ATTRIBUTE_TOTAL_HP + stat), NULL) -
            (int) pokemon_get_attribute(opponent_pokemon, (u8) (ATTRIBUTE_TOTAL_HP + stat), NULL);

    //print availble
    itoa(strbuf, fp_free, 0, 3);
    tbox_flush_set(10, 0);
    tbox_tilemap_draw(10);
    tbox_print_string(10, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, strbuf);

    //print used
    itoa(strbuf, fp_applied, 0, 3);
    tbox_flush_set(12, 0);
    tbox_tilemap_draw(12);
    tbox_print_string(12, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, strbuf);

    //print bonus
    itoa(strbuf, stat_bonus, 0, 3);
    tbox_flush_set(11, 0);
    tbox_tilemap_draw(11);
    tbox_print_string(11, 2, 0, 0, 0, 0, &fp_menu_fontcolmap_std, 0, strbuf);

}

void pokemon_set_fp_applied(pokemon *target, int stat, u8 value) {
    u8 attribute = fp_menu_attributes_fp_applied[stat];
    u8 original_value = (u8) pokemon_get_attribute(target, attribute, NULL) & 0xC0;
    original_value |= value;
    pokemon_set_attribute(target, attribute, &original_value);
}

u8 pokemon_get_fp_applied(pokemon *target, int stat) {
    return (u8) pokemon_get_attribute(target, fp_menu_attributes_fp_applied[stat], NULL);
}

color fp_menu_pokepic_anim_colors[6] = {
    //For each stat we have a color the animation fades into
    {0x372a},
    {0x31df},
    {0x4Dcd},
    {0x7FB7},
    {0x439F},
    {0x3212}
};

void fp_menu_pokepic_callback(oam_object *self) {
    //Do the color fading
    if (!fading_is_active() && !self->private[2]) {
        if (self->private[0]) {
            //decrement
            if (!--(self->private[1]))
                self->private[0] = 0;
        } else {
            //increment
            if (++(self->private[1]) == 24)
                self->private[0] = 1;
        }
        //Blend the pals
        int i;
        for (i = 0; i < 16; i++) {
            int index = fmem->fp_mem->pal_pokepic * 16 + 256 + i;
            pals[index] = color_alpha_blend(pal_restore[index], fp_menu_pokepic_anim_colors[fmem->fp_mem->stat_index], (u8) (self->private[1] / 3));
        }
    }
}

void fp_menu_callback_poke_jump(u8 self) {
    u8 oam_id = fmem->fp_mem->oam_pokepic;
    if (big_callbacks[self].params[0]) {
        //decrease
        if (!++oams[oam_id].y2) {
            big_callbacks[self].params[0] = 0; //switch to increase
            if (++big_callbacks[self].params[1] == 2)
                big_callback_delete(self); //This counter counts the times the pokemon has come to ground 
        }
    } else {
        //increase
        if (--oams[oam_id].y2 == -8) {
            big_callbacks[self].params[0] = 1;
        }
    }
}

void fp_menu_callback_arrow_anim(u8 self) {
    s16 d;
    if (big_callbacks[self].params[0]) {
        //decrease
        d = -1;
        if (!--big_callbacks[self].params[1])
            big_callbacks[self].params[0] = 0;
    } else {
        d = 1;
        if (++big_callbacks[self].params[1] == 15)
            big_callbacks[self].params[0] = 1;
    }
    if (big_callbacks[self].params[1] % 3) return; //every 3th frame we do a movemen
    oams[fmem->fp_mem->oam_arrows[0]].y2 = (s16) (oams[fmem->fp_mem->oam_arrows[0]].y2 + d);
    oams[fmem->fp_mem->oam_arrows[1]].y2 = (s16) (oams[fmem->fp_mem->oam_arrows[1]].y2 - d);
    oams[fmem->fp_mem->oam_arrows[2]].x2 = (s16) (oams[fmem->fp_mem->oam_arrows[2]].x2 + d);
    oams[fmem->fp_mem->oam_arrows[3]].x2 = (s16) (oams[fmem->fp_mem->oam_arrows[3]].x2 - d);

}
