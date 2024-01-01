#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "cutscene_script.h"
#include "superstate.h"
#include "color.h"
#include "bg.h"
#include "text.h"
#include "save.h"
#include "debug.h"
#include "math.h"
#include "bios.h"
#include "music.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "pokemon/cry.h"
#include "flags.h"
#include "io.h"
#include "vars.h"
#include "fading.h"
#include "dma.h"

EWRAM animation_engine_state_t *animation_engine_state = 0;

static void cmdx3B_loop_sound_with_pan_and_volume_decay(animation_engine_state_t*mem);
static void cmdx3C_task_new(animation_engine_state_t*mem);


extern const u8 cutscene_script_elite_four_founders[];
extern const u8 cutscene_script_darkqueen_fade_to[];
extern const u8 cutscene_script_darkqueen_fade_from[];
extern const u8 cutscene_script_mistral_yin_yang[];
extern const u8 cutscene_script_future[];
extern const u8 cutscene_script_groudon_diserakt[];
extern const u8 cutscene_script_groudon[];
extern const u8 cutscene_script_groudon_fade[];
extern const u8 cutscene_script_groudon_red[];
extern const u8 cutscene_script_groudon_grey[];
extern const u8 cutscene_script_arc_scrim[];
extern const u8 cutscene_script_difficulty_setting[];
extern const u8 cutscene_script_difficulty_setting_fade_to_dark[];
extern const u8 cutscene_script_intro[];
extern const u8 cutscene_script_staraptor_to[];
extern const u8 cutscene_script_staraptor_from[];
extern const u8 cutscene_script_aktania_meteor[];
extern const u8 cutscene_script_aktania_beam[];
extern const u8 cutscene_script_aktania_sky[];
extern const u8 cutscene_script_ardeal_tower[];
extern const u8 cutscene_script_unown_shrine[];

const u8 *const cutscene_scripts[NUM_CUTSCENES] = {
    [CUTSCENE_ELITE_FOUR_FOUNDERS] = cutscene_script_elite_four_founders,
    [CUTSCENE_DARK_QUEEN_FADE_TO_DARK] = cutscene_script_darkqueen_fade_to,
    [CUTSCENE_DARK_QUEEN_FADE_FROM_DARK] = cutscene_script_darkqueen_fade_from,
    [CUTSCENE_MISTRAL_YING_YANG] = cutscene_script_mistral_yin_yang,
    [CUTSCENE_FUTURE_LANDSCAPE] = cutscene_script_future,
    [CUTSCENE_GROUDON_TESERAKT] = cutscene_script_groudon_diserakt,
    [CUTSCENE_GROUDON] = cutscene_script_groudon,
    [CUTSCENE_GROUDON_FADE_TO_DARK] = cutscene_script_groudon_fade,
    [CUTSCENE_GROUDON_FADE_TO_RED] = cutscene_script_groudon_red,
    [CUTSCENE_GROUDON_FADE_TO_GREY] = cutscene_script_groudon_grey,
    [CUTSCENE_ARC_SCRIM] = cutscene_script_arc_scrim,
    [CUTSCENE_DIFFICULTY_SETTING] = cutscene_script_difficulty_setting,
    [CUTSCENE_DIFFICULTY_SETTING_FADE_TO_DARK] = cutscene_script_difficulty_setting_fade_to_dark,
    [CUTSCENE_PROLOUGE] = cutscene_script_intro,
    [CUTSCENE_STARAPTOR_FLY_TO] = cutscene_script_staraptor_to,
    [CUTSCENE_STARAPTOR_FLY_FROM] = cutscene_script_staraptor_from,
    [CUTSCENE_AKTANIA_METEORITE] = cutscene_script_aktania_meteor,
    [CUTSCENE_AKTANIA_BEAM] = cutscene_script_aktania_beam,
    [CUTSCENE_AKTANIA_SKY] = cutscene_script_aktania_sky,
    [CUTSCENE_ARDEAL_TOWER] = cutscene_script_ardeal_tower,
    [CUTSCENE_UNOWN_SHRINE] = cutscene_script_unown_shrine,
};

static void (*const commands[])(animation_engine_state_t*) = {
        cmdx00_end,
        cmdx01_call,
        cmdx02_jump,
        cmdx03_oam_new,
        cmdx04_oam_delete,
        cmdx05_oam_vram_load,
        cmdx06_oam_vram_free,
        cmdx07_oam_despawn,
        cmdx08_spawn_callback,
        cmdx09_bg_reset,
        cmdx0A_bg_setup,
        cmdx0B_bg_sync_and_show,
        cmdx0C_bg_hide,
        cmdx0D_bg_display_sync,
        cmdx0E_bg_override,
        cmdx0F_load_obj_pal,
        cmdx10_free_obj_pal,
        cmdx11_get_io,
        cmdx12_set_io_to_var,
        cmdx13_set_io_to_value,
        cmdx14_prepare_tbox,
        cmd_nop,
        cmdx16_clear_textbox,
        cmd_nop,
        cmd_nop,
        cmdx19_objmove,
        cutscene_script_cmdx1A, // cmd_x1A_callasm function in Assembler Code
        cmdx1B_gfx_anim_set,
        cmdx1C_rs_anim_set,
        cmdx1D_loadpal,
        cmdx1E_fade,
        cmdx1F_invertcolors,
        cmdx20_sound,
        cmdx21_song,
        cmdx22_cry,
        cmdx23_maintain,
        cmdx24_script_notify,
        cmdx25_oam_reset,
        cmdx26_callback_reset,
        cmdx27_dma3_controller_reset,
        cmdx28_bg_displacement_reset,
        cmdx29_bg_vmap_init,
        cmdx2A_bg_vmap_drop,
        cmdx2B_bg_scroll,
        cmdx2C_mapreload,
        cmdx2D_force_pals_to_black,
        cmdx2E_bg_clear_map,
        cmdx2F_setvar,
        cmdx30_fade_obj_pal,
        cmdx31_tbox_flush,
        cmdx32_pal_restore_force_current,
        cmdx33_jump_if_female,
        cmdx34_setflag,
        cmdx35_pal_restore_snapshot,
        cmdx36_load_obj_pal_from_struct,
        cmdx37_obj_move_trace,
        cmdx38_tbox_and_interrupt,
        cmdx39_pause,
        cmdx3A_task_delete_all,
        cmdx3B_loop_sound_with_pan_and_volume_decay,
        cmdx3C_task_new,
};

void special_cutscene_show() {
    cutscene_script_initiatlize(cutscene_scripts[*var_access(0x8004)]);
}

void cutscene_script_initiatlize(const u8 *script) {
    u8 callback_id = big_callback_new(cutscene_script_callback, 0);
    animation_engine_state = (animation_engine_state_t*) malloc_and_clear(sizeof(animation_engine_state_t ));
    big_callback_set_int(callback_id, 1, (int)animation_engine_state);
    DEBUG("Ae script %x initializing...\n", script);
    animation_engine_state->script = script;
    animation_engine_state->callback_id = callback_id;
    animation_engine_state->active = true;
    animation_engine_state->paused = false;
    animation_engine_state->delayed = 0;
    animation_engine_state->root = cutscene_script_task_setup();
}

void cutscene_script_callback(u8 callback_id) {
    animation_engine_state_t *mem = (animation_engine_state_t *)big_callback_get_int(callback_id, 1);
    cutscene_script_tasks_execute(mem->root);
    if (mem->paused) 
        return;
    if (mem->delayed > 0) {
        --mem->delayed;
        return;
    }
    while (!mem->paused && mem->delayed <= 0 && mem->active) {
        // DEBUG("Script offset is %x\n", mem->script);
        u8 command = cutscene_script_read_byte(mem);
        // DEBUG("Running ae command %d\n", command);
        if (command == 0xFF) break;
        commands[command](mem);
    }
    if (!(mem->active)) {
        big_callback_delete(callback_id);
        free(mem);
        return;
    }
    mem->current_frame++;
}

u8 cutscene_script_read_byte(animation_engine_state_t *mem) {
    return *(mem->script++);
}

u16 cutscene_script_read_param(animation_engine_state_t *mem) {
    u16 result = cutscene_script_read_hword(mem);
    if ((u16) (result - 0x8000) < 0x10) {
        result = mem->vars[(result - 0x8000)];
    }
    return result;
}

u32 cutscene_script_read_word(animation_engine_state_t *mem) {
    u32 word = (u32)UNALIGNED_32_GET(mem->script);
    mem->script += 4;
    return word;
}

u16 cutscene_script_get_hword(animation_engine_state_t *mem) {
    return (u16)UNALIGNED_16_GET(mem->script);
}

u16 cutscene_script_read_hword(animation_engine_state_t *mem) {
    u16 hword = cutscene_script_get_hword(mem);
    mem->script += 2;
    return hword;
}

void cmd_nop(animation_engine_state_t*mem) {
    (void)mem;
}

void cmdx00_end(animation_engine_state_t *mem) {
    if (mem->stack_size == 0) {
        mem->active = false;
    } else {
        mem->script = mem->stack[mem->stack_size];
        mem->stack_size--;
    }
}

void cmdx01_call(animation_engine_state_t *mem) {
    u8 *subscript = (u8*)cutscene_script_read_word(mem);
    if (mem->stack_size < ARRAY_COUNT(mem->stack)) {
        mem->stack[mem->stack_size] = mem->script;
        ++mem->stack_size;
        mem->script = subscript;
    }
}

void cmdx02_jump(animation_engine_state_t *mem) {
    u8 *target = (u8*) cutscene_script_read_word(mem);
    mem->script = target;
}

void cmdx03_oam_new(animation_engine_state_t *mem) {
    oam_template* template = (oam_template*) (cutscene_script_read_word(mem));
    s16 x = (s16) (cutscene_script_read_hword(mem));
    s16 y = (s16) (cutscene_script_read_hword(mem));
    u8 priority = cutscene_script_read_byte(mem);
    u16 target = (u16) (cutscene_script_read_hword(mem) - 0x8000);
    if (target < 0x10) {
        mem->vars[target] = oam_new_forward_search(template, x, y, priority);
    }
}

void cmdx04_oam_delete(animation_engine_state_t *mem) {

    u16 id = cutscene_script_read_hword(mem);

    if (id >= 0x8000) {
        id = mem->vars[id - 0x8000];
    }
    oam_delete(&oams[id]);
}

void cmdx05_oam_vram_load(animation_engine_state_t *mem) {
    graphic* resource = (graphic*) cutscene_script_read_word(mem);
    oam_load_graphic(resource);
}

void cmdx06_oam_vram_free(animation_engine_state_t *mem) {
    u16 oam_id = cutscene_script_read_param(mem);
    oam_object* oam = (oam_object*) (oam_id * 0x44 + 0x0202063c);
    oam_free_graphic(oam);
}

void cmdx07_oam_despawn(animation_engine_state_t *mem) {
    u8 oam_id = (u8) cutscene_script_read_param(mem);
    oam_object* oam = &oams[oam_id];
    oam_free(oam);
}

void cmdx08_spawn_callback(animation_engine_state_t *mem) {
    void* function = (void*) cutscene_script_read_word(mem);
    u8 priority = cutscene_script_read_byte(mem);
    u8 length = cutscene_script_read_byte(mem);
    u8 idx = big_callback_new(function, priority);
    for (int i = 0; i < length; i++) {
        big_callbacks[idx].params[i] = cutscene_script_read_hword(mem);
    }
}

void cmdx09_bg_reset(animation_engine_state_t *mem) {
    if (bg_get_tilemap(0))
        free(bg_get_tilemap(0));
    if (bg_get_tilemap(1))
        free(bg_get_tilemap(1));
    if (bg_get_tilemap(2))
        free(bg_get_tilemap(2));
    if (bg_get_tilemap(3))
        free(bg_get_tilemap(3));
    bg_reset(cutscene_script_read_byte(mem));
}

void cmdx0A_bg_setup(animation_engine_state_t *mem) {
    bg_setup(cutscene_script_read_byte(mem), (bg_config*) cutscene_script_read_word(mem), cutscene_script_read_byte(mem));
}

void cmdx0B_bg_sync_and_show(animation_engine_state_t *mem) {
    bg_sync_display_and_show(cutscene_script_read_byte(mem));
}

void cmdx0C_bg_hide(animation_engine_state_t *mem) {
    bg_hide(cutscene_script_read_byte(mem));
}

void cmdx0D_bg_display_sync() {
    bg_display_sync();
}

void cmdx0E_bg_override(animation_engine_state_t *mem) {
    u8 bgid = cutscene_script_read_byte(mem);
    void* graphic = (void*) cutscene_script_read_word(mem);
    u16 size = cutscene_script_read_hword(mem);
    u16 start = cutscene_script_read_hword(mem);
    u8 mode = cutscene_script_read_byte(mem);

    void* buffer = malloc(size);
    if(!buffer)
        return;
    lz77uncompwram(graphic, buffer);
    bg_copy_vram(bgid, buffer, size, start, mode);

    // Callback to free the allocated ressource
    cutscene_script_task *t = cutscene_script_task_new(0, cutscene_script_bg_free_task, sizeof(void*), mem->root);
    *(void**)(t->vars) = buffer;
}



void cmdx0F_load_obj_pal(animation_engine_state_t *mem) {

    u8 pal_id = oam_allocate_palette(cutscene_script_read_hword(mem));
    
    void* pal = (void*) cutscene_script_read_word(mem);
    u8 mode = cutscene_script_read_byte(mem);
    u8 force = cutscene_script_read_byte(mem);
    if(pal_id == 0xFF)return;
    if(mode){
        lz77uncompwram(pal, pal_tmp);
        pal = pal_tmp;
    }
    cpuset(pal, &pal_restore[(pal_id + 16) * 16], 16);
    if(force) cpuset(pal, &pals[(pal_id + 16) * 16], 16);
}

void cmdx10_free_obj_pal(animation_engine_state_t *mem) {
    oam_palette_free(cutscene_script_read_hword(mem));
}

void cmdx11_get_io(animation_engine_state_t *mem) {
    u16 var = (u16) (cutscene_script_read_hword(mem) - 0x8000);
    u16 ioreg = cutscene_script_read_hword(mem);
    if (var < 0x10) {
        mem->vars[var] = io_get(ioreg);
    }
}

void cmdx12_set_io_to_var(animation_engine_state_t *mem) {
    u16 var = (u16) (cutscene_script_read_hword(mem) - 0x8000);
    u16 ioreg = cutscene_script_read_hword(mem);
    if (var < 0x10) {
        io_set(ioreg, mem->vars[var]);
    }
}

void cmdx13_set_io_to_value(animation_engine_state_t *mem) {
    u16 val = cutscene_script_read_hword(mem);
    u16 ioreg = cutscene_script_read_hword(mem);
    io_set(ioreg, val);
}

void cmdx14_prepare_tbox(animation_engine_state_t *mem) {
    u16 target_var = (u16) (cutscene_script_read_hword(mem) - 0x8000);
    u8 bgid = cutscene_script_read_byte(mem);
    u8 x = cutscene_script_read_byte(mem);
    u8 y = cutscene_script_read_byte(mem);
    u8 w = cutscene_script_read_byte(mem);
    u8 h = cutscene_script_read_byte(mem);
    u8 palID = cutscene_script_read_byte(mem);
    u16 startTile = cutscene_script_read_hword(mem);
    if (target_var < 0x10) {
        tboxdata boxdata;
        tbox_data_new(&boxdata, bgid, x, y, w, h, palID, startTile);
        u8 boxid = tbox_new(&boxdata);
        tbox_flush_set(boxid, 0);
        tbox_tilemap_draw(boxid);
        mem->vars[target_var] = boxid;
    }
}

void cmdx15_display_text_inst(animation_engine_state_t *mem) {
    u8 boxid = (u8) cutscene_script_read_param(mem);
    u8 font_id = cutscene_script_read_byte(mem);
    u8 unkown = cutscene_script_read_byte(mem);
    u8 border_distance = cutscene_script_read_byte(mem);
    u8 line_distance_u = cutscene_script_read_byte(mem);
    u8 line_distance_l = cutscene_script_read_byte(mem);
    tbox_font_colormap *font_map = (tbox_font_colormap*) cutscene_script_read_word(mem);
    u8 display_flag = cutscene_script_read_byte(mem);
    u8* string = (u8*) cutscene_script_read_word(mem);
    u8 bgid = cutscene_script_read_byte(mem);

    //decrypting string
    u8* ram_buffer = (u8*) 0x02021D18;
    string_decrypt(ram_buffer, string);

    tbox_flush_set(boxid, 0);
    tbox_print_string(boxid, font_id, unkown, border_distance, line_distance_u, line_distance_l, font_map, display_flag, ram_buffer);
    bg_copy_vram(bgid, bg_get_tilemap(bgid), 0x800, 0x0, 0x2);

}

void cmdx16_clear_textbox(animation_engine_state_t *mem) {
    u8 boxid = (u8) cutscene_script_read_param(mem);
    tbox_flush_set(boxid, 0);
    tbox_flush_map(boxid);
    tbox_free(boxid);
    bg_copy_vram(0, bg_get_tilemap(0), 0x800, 0x0, 0x2);
}


void cmdx19_objmove(animation_engine_state_t *mem) {
    u8 oam_id = (u8) cutscene_script_read_param(mem);
    u16 duration = cutscene_script_read_hword(mem);
    s16 x = (s16) (cutscene_script_read_hword(mem));
    s16 y = (s16) (cutscene_script_read_hword(mem));

    if (duration == 0) {
        oam_object* oam = (oam_object*) (0x0202063c + oam_id * 0x44);
        oam-> x = (s16) (oam->x + x);
        oam-> y = (s16) (oam->y + y);
    } else {
        //spawn a new callback
        cutscene_script_task *t = cutscene_script_task_new(0, _obj_move_linear_trace,
                5 * sizeof(u16), mem->root);
        
        DEBUG("Spawned linear trace @%x\n", t);
        u16 *vars = (u16*)(t->vars);
        vars[0] = oam_id;
        vars[1] = (u16) x;
        vars[2] = (u16) y;
        vars[3] = duration;
        vars[4] = 0x0; //frame count
    }
}

void _obj_move_linear_trace(cutscene_script_task *self) {
    u16 *vars = (u16*)(self->vars);
    u8 oam_id = (u8) (vars[0]);
    oam_object* oam = &oams[oam_id];
    s16 x = (s16) (vars[1]);
    s16 y = (s16) (vars[2]);
    u16 d = vars[3];
    u16 t = vars[4];


    vars[4]++; //incrementing frame count 
    //calculating the movement in this frame by this formula mov_x(t) = x*t/d - (t-1)*x/d
    int x_mov = (x * t) / d - ((t - 1) * x) / d;
    int y_mov = (y * t) / d - ((t - 1) * y) / d;

    oam -> x = (s16) ((oam -> x) + x_mov);
    oam -> y = (s16) ((oam -> y) + y_mov);

    if (vars[4] == vars[3]) {
        cutscene_script_task_delete(self);
    }
}

void cmdx1B_gfx_anim_set(animation_engine_state_t *mem) {
    u16 oam_id = cutscene_script_read_param(mem);
    u8 anim_id = cutscene_script_read_byte(mem);
    oam_gfx_anim_start(oams + oam_id, anim_id);
    oam_gfx_anim_init(oams + oam_id, 0);
}

void cmdx1C_rs_anim_set(animation_engine_state_t *mem) {
    u16 oam_id = cutscene_script_read_param(mem);
    u8 anim_id = cutscene_script_read_byte(mem);

    oam_object* oam = (oam_object*) (oam_id * 0x44 + 0x0202063c);
    oam_rotscale_anim_init(oam, anim_id);

}

void cmdx1D_loadpal(animation_engine_state_t *mem) {
    void *pal = (void*) cutscene_script_read_word(mem);
    u16 destcol = cutscene_script_read_hword(mem);
    u16 bytecount = cutscene_script_read_hword(mem);
    u8 cflag = cutscene_script_read_byte(mem); //compressed flag: if 0x1 data is compressed
    u8 force = cutscene_script_read_byte(mem);

    if (cflag) {
        lz77uncompwram(pal, pal_tmp);
        pal = pal_tmp;
    }

    cpuset(pal, &pal_restore[destcol], CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(bytecount));
    if (force) {
        cpuset(pal, &pals[destcol], CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(bytecount));
    }

}

void cmdx1E_fade(animation_engine_state_t *mem) {
    u16 color = cutscene_script_read_hword(mem);
    u16 dcol = cutscene_script_read_hword(mem);
    u16 ncol = cutscene_script_read_hword(mem);
    u16 duration = cutscene_script_read_hword(mem);
    u8 from_intensity = cutscene_script_read_byte(mem);
    u8 to_intensity = cutscene_script_read_byte(mem);

    //initing a callback
    cutscene_script_task *t = cutscene_script_task_new(0, cutscene_script_fader, 7 * sizeof(u16), mem->root);
    
    u16 *vars = (u16*)(t->vars);
    vars[0] = color;
    vars[1] = dcol;
    vars[2] = ncol;
    vars[3] = duration;
    vars[4] = 0; //current frame
    vars[5] = from_intensity;
    vars[6] = to_intensity;

    cutscene_script_fader(t);

}

void cutscene_script_fader(cutscene_script_task *self) {

    u16 *vars = (u16*)(self->vars);
    u16 duration = vars[3];
    u16 current_frame = vars[4]++;
    u8 intensity;
    if (duration) {

        int d = vars[6] - vars[5];
        d *= current_frame;
        d /= duration;
        intensity = (u8) (d + vars[5]);

    } else {
        //Instant palload
        intensity = (u8) vars[6];
    }

    //now we do the fading loop
    int c = vars[1];
    int max = vars[2] + c;
    color_t over = {vars[0]};
    while (c < max) {
        color_t b = pal_restore[c];
        color_t n = color_alpha_blend(b, over, intensity);
        pals[c] = n;
        c++;
    }

    if (current_frame >= duration) {
        cutscene_script_task_delete(self);
    }
}

void cmdx1F_invertcolors(animation_engine_state_t *mem) {
    u16 startcol = cutscene_script_read_hword(mem);
    u16 ncol = cutscene_script_read_hword(mem);
    if (ncol != 0) {
        u16* palcopyram = (u16*) 0x020371F8;
        u16* palram = (u16*) 0x020375F8;

        //start a inversion loop
        for (int i = startcol; i < ncol + startcol; i++) {
            u16 oc = palcopyram[i];
            int red = 0x1F - (oc & 0x1F);
            int blue = 0x3E0 - (oc & 0x3E0);
            int green = 0x7C00 - (oc & 0x7C00);
            palcopyram[i] = (u16) (red | blue | green);
            palram[i] = (u16) (red | blue | green);
        }
    }
}

void cmdx20_sound(animation_engine_state_t *mem) {
    u16 soundid = cutscene_script_read_hword(mem);
    play_sound(soundid);
}

void cmdx21_song(animation_engine_state_t *mem) {
    u16 songid = cutscene_script_read_hword(mem);
    u8 feature = cutscene_script_read_byte(mem);
    playsong1(songid, feature);
}

void cmdx22_cry(animation_engine_state_t *mem) {
    u16 pokeid = cutscene_script_read_hword(mem);
    u8 feature = cutscene_script_read_byte(mem);
    pokemon_play_cry(pokeid, feature);
}

static void generic_callback1_and_vblank_handler_set() {
    vblank_handler_set(generic_vblank_handler);
    callback1_set(generic_callback1);
}

void cmdx23_maintain() {
    callback1_set(generic_callback1_and_vblank_handler_set);
}

void cmdx24_script_notify() {
    *((bool*) 0x03000EA8) = false;
}

void cmdx25_oam_reset() {
    oam_palette_allocation_reset();
    oam_reset();
}

void cmdx26_callback_reset(animation_engine_state_t*mem) {
    //we must not remove the engine callback
    u8 self = mem->callback_id;
    u8 i;
    for (i = 0; i < 0x10; i++) {
        if (i != self) {
            big_callback_delete(i);
        }
    }
}

void cmdx27_dma3_controller_reset() {
    dma3_controller_reset();
}

void cmdx28_bg_displacement_reset() {
    int i;
    for (i = 0; i < 4; i++) {
        bg_virtual_map_displace((u8) i, 0, 0);
        bg_virtual_set_displace((u8) i, 0, 0);
    }
}

void cmdx29_bg_vmap_init(animation_engine_state_t*mem) {
    u8 bg_id = cutscene_script_read_byte(mem);
    u16 size = cutscene_script_read_hword(mem);
    void *map = malloc_and_clear(size);
    bg_set_tilemap(bg_id, map);
    bg_copy_vram(bg_id, map, size, 0, 2);
}

void cmdx2A_bg_vmap_drop(animation_engine_state_t*mem) {
    u8 bg_id = cutscene_script_read_byte(mem);
    free(bg_get_tilemap(bg_id));
    bg_set_tilemap(bg_id, NULL);
}

void cmdx2B_bg_scroll(animation_engine_state_t*mem) {
    u8 bg_id = cutscene_script_read_byte(mem);
    u16 duration = cutscene_script_read_hword(mem);
    u16 hdelta = cutscene_script_read_hword(mem);
    u16 vdelta = cutscene_script_read_hword(mem);
    cutscene_script_task *t = cutscene_script_task_new(15, cutscene_script_bg_scroller, 5 * sizeof(u16), mem->root);
    u16 *vars = (u16*)(t->vars);
    vars[0] = bg_id;
    vars[1] = duration;
    vars[2] = hdelta;
    vars[3] = vdelta;
    vars[4] = 0;
    cutscene_script_bg_scroller(t);
}

void cutscene_script_bg_scroller(cutscene_script_task *self) {
    u16 *vars = (u16*)(self->vars);
    u8 bg_id = (u8) vars[0];
    u16 duration = vars[1];
    u16 current_frame = ++(vars[4]);
    s16 hdelta = (s16) vars[2];
    s16 vdelta = (s16) vars[3];
    u16 bg_hreg = (u16)(0x10 + 4 * bg_id);
    u16 bg_vreg = (u16)(0x12 + 4 * bg_id);
    u16 x = io_get(bg_hreg);
    u16 y = io_get(bg_vreg);
    if (duration) {
        int x_0 = ((current_frame - 1) * hdelta) / duration;
        int x_1 = (current_frame * hdelta) / duration;
        int y_0 = ((current_frame - 1) * vdelta) / duration;
        int y_1 = (current_frame * vdelta) / duration;
        //DEBUG("Frame %d: x_0 %d, x_1 %d, y_0 %d, y_1, %d\n", current_frame, x_0, x_1, y_0, y_1);f
        io_set(bg_hreg, (u16)(x + x_1 - x_0));
        io_set(bg_vreg, (u16)(y + y_1 - y_0));

    } else {
        io_set(bg_hreg, (u16)(x + hdelta));
        io_set(bg_hreg, (u16)(y + hdelta));
    }

    if (duration <= current_frame) {
        cutscene_script_task_delete(self);
    }
}

void ae_mapreloader() {
    generic_callback1();
    if ((*((u8*) 0x02037AB8 + 7)) & 0x80) {
        return;
    }
    int i;
    for (i = 0; i < 512; i++) {
        pal_restore[i].value = 0x0;
        pals[i].value = 0x0;
    }
    map_reload();
}

void cmdx2C_mapreload() {
    fadescreen_all(1, 0);
    super.callback1 = ae_mapreloader;
}

void cmdx2D_force_pals_to_black() {
    int i;
    for (i = 0; i < 512; i++) {
        pal_restore[i].value = 0;
        pals[i].value = 0;
    }
}

void cutscene_script_bg_free_task(cutscene_script_task *self) {
    void **vars = (void**)(self->vars);
    free(*vars);
    if(cutscene_script_task_delete(self) < 0){
        ERROR("Error at deleting bg free task!\n");
    }
}

void cmdx2E_bg_clear_map(animation_engine_state_t*mem) {
    u8 bg_id = cutscene_script_read_byte(mem);
    u16 size = cutscene_script_read_hword(mem);
    int n = 0;
    cpuset(&n, bg_get_tilemap(bg_id), (size / 4) || 0x5000000);
    bg_virtual_sync(bg_id);
}

void cmdx2F_setvar(animation_engine_state_t*mem) {
    int var = cutscene_script_read_hword(mem) - 0x8000;
    u16 val = cutscene_script_read_hword(mem);
    mem->vars[var] = val;
}

void cmdx30_fade_obj_pal(animation_engine_state_t*mem){
    u16 color = cutscene_script_read_hword(mem);
    u16 tag = cutscene_script_read_hword(mem);
    u8 start_col = cutscene_script_read_byte(mem);
    u8 col_count = cutscene_script_read_byte(mem);
    u16 duration = cutscene_script_read_hword(mem);
    u8 from_intensity = cutscene_script_read_byte(mem);
    u8 to_intensity = cutscene_script_read_byte(mem);
    
    int pal_id = oam_palette_get_index(tag) + 16;
    u16 dcol = (u16)(16 * pal_id + start_col);
    u16 ncol = col_count;
    cutscene_script_task *t = cutscene_script_task_new(0, cutscene_script_fader, 7 * sizeof(u16), mem->root);
    u16 *vars = (u16*)(t->vars);
    vars[0] = color;
    vars[1] = dcol;
    vars[2] = ncol;
    vars[3] = duration;
    vars[4] = 0; //current frame
    vars[5] = from_intensity;
    vars[6] = to_intensity;

    cutscene_script_fader(t);
    
}

void cmdx31_tbox_flush(animation_engine_state_t*mem){
    u8 box_id = (u8)cutscene_script_read_param(mem);
    u8 flush = cutscene_script_read_byte(mem);
    tbox_flush_set(box_id, flush);
}

void cmdx32_pal_restore_force_current(animation_engine_state_t*mem){
    u16 first_col = cutscene_script_read_hword(mem);
    u16 col_cnt = cutscene_script_read_hword(mem);
    int i;
    for(i = 0; i < col_cnt; i++){
        pal_restore[first_col + i] = pals[first_col + i];
    }
    
}

void cmdx33_jump_if_female(animation_engine_state_t*mem){
    u8 *target = (u8*)cutscene_script_read_word(mem);
    u16 target_frame = cutscene_script_read_hword(mem);
    if(save2->player_is_female){
        mem->script = target;
        mem->current_frame = target_frame;
    }
   
}

void cmdx34_setflag(animation_engine_state_t*mem){
    u16 flag = cutscene_script_read_hword(mem);
    if(cutscene_script_read_byte(mem)) setflag(flag);
    else clearflag(flag);
}

void cmdx35_pal_restore_snapshot(animation_engine_state_t*mem){
    if(cutscene_script_read_byte(mem)){
        //Create snapshot pal_restore
        if(mem->pal_restore_save){
            DEBUG("Warning: Trying to snapshot pal restore when there is already a snapshot!\n");
        }
        mem->pal_restore_save = malloc(sizeof(color_t) * 1024);
        // Do not save the restore! This causes mapreload to not fade into black
        // cpuset(pal_restore, mem->pal_restore_save, 0x4000100);
        cpuset(pal_tmp, &(mem->pal_restore_save[512]), 0x4000100);
        DEBUG("Pal restore snap alloc\n");
    }else{
        if(!mem->pal_restore_save){
            DEBUG("Warning: Trying to load a not present snapshot for pal restore\n");
        }
        //cpuset(mem->pal_restore_save, pal_restore, 0x4000100);
        cpuset(&(mem->pal_restore_save[512]), pal_tmp, 0x4000100);
        free(mem->pal_restore_save);
        mem->pal_restore_save = NULL;
        DEBUG("Pal restore snap free\n");
    }
}

void cmdx36_load_obj_pal_from_struct(animation_engine_state_t*mem){
    palette *p = (palette*)cutscene_script_read_word(mem);
    u8 pal_id = oam_allocate_palette(p->tag);
    u8 mode = cutscene_script_read_byte(mem);
    u8 force = cutscene_script_read_byte(mem);
    if (pal_id == 0xFF) return;
    
    const void *pal = p->pal;
    if(mode){
        lz77uncompwram(pal, pal_tmp);
        pal = pal_tmp;
    }
    
    cpuset(pal, &pal_restore[(pal_id + 16) * 16], 16);
    if(force) cpuset(pal, &pals[(pal_id + 16) * 16], 16);
}


void _obj_move_trig_trace(cutscene_script_task *self){
    u16 *vars = (u16*)(self->vars);
    //trace @%x with vars @%x\n", self, vars);
    u8 oam_id = (u8)vars[0];
    u16 duration = vars[1];
    if(duration == vars[2]++){
        cutscene_script_task_delete(self);
    }
    u16 frame = vars[2];
    s16 amplitude = (s16)vars[3];
    int period = vars[4];
    bool on_y_axis = vars[5];
    int trig_func = vars[6];
    FIXED fperiod = INT_TO_FIXED(period);
    FIXED famplitude = INT_TO_FIXED(amplitude);
    FIXED fx = FIXED_DIV(INT_TO_FIXED(frame), fperiod);
    FIXED fxprev = FIXED_DIV(INT_TO_FIXED(frame - 1), fperiod);
    FIXED (*eval_func)(FIXED);
    switch(trig_func){
        case 0: //sine function
        	eval_func = FIXED_SIN;
            break;
        case 1: //cosine function
        	eval_func = FIXED_COS;
            break;
        case 2: //tangens function
        	eval_func = FIXED_TAN;
            break;
        case 3: //sine function
            eval_func = FIXED_TRIANGLE_SIN;
            break;
        case 4: //cosine function
            eval_func = FIXED_TRIANGLE_COS;
            break;
        case 5: //tangens function
            eval_func = FIXED_TRIANGLE_TAN;
            break;
        default: return;
    }

    // Evaluate the function at the current and previous frame
    int current = FIXED_TO_INT(FIXED_MUL(famplitude, eval_func(fx)));
    int prev = FIXED_TO_INT(FIXED_MUL(famplitude, eval_func(fxprev)));
    int d = current - prev;
    if(on_y_axis)oams[oam_id].y = (s16)(oams[oam_id].y + d);
    else oams[oam_id].x = (s16)(oams[oam_id].x + d);
}





void cmdx37_obj_move_trace(animation_engine_state_t*mem){
    u8 oam_id = (u8)cutscene_script_read_param(mem);
    u16 duration = cutscene_script_read_hword(mem);
    u8 trace = cutscene_script_read_byte(mem);
    switch(trace){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:{
            //Trigonometric functions
            u8 on_y_axis = cutscene_script_read_byte(mem);
            u16 amplitude = cutscene_script_read_hword(mem);
            u16 period = cutscene_script_read_hword(mem);
            size_t size_var_space = 7 * sizeof(u16);
            cutscene_script_task *t = cutscene_script_task_new(0, _obj_move_trig_trace, size_var_space, mem->root);
            u16 *var_space = (u16*)(t->vars);
            var_space[0] = oam_id;
            var_space[1] = duration;
            var_space[2] = 0;
            var_space[3] = amplitude;
            var_space[4] = period;
            var_space[5] = on_y_axis;
            var_space[6] = trace;
            DEBUG("Spawned trig trace task @%x\n", t);
            break;
        }
        case 6:{
            //Linear function
            u16 dx = cutscene_script_read_hword(mem);
            u16 dy = cutscene_script_read_hword(mem);
            cutscene_script_task *t = cutscene_script_task_new(0, _obj_move_linear_trace,
                5 * sizeof(u16), mem->root);
            u16 *vars = (u16*)(t->vars);
            vars[0] = oam_id;
            vars[1] = (u16) dx;
            vars[2] = (u16) dy;
            vars[3] = duration;
            vars[4] = 0x0; //frame count
            break;
        }
        default:
            ERROR("Trace %d not specified\n", trace);
    }
}

struct cmd_x38_tbox_waiting_struct {
    u8 tbox_idx;
    u8 proceed_boxes;
    animation_engine_state_t*script_state;
};

static void cmdx38_wait_for_tbox(cutscene_script_task *self) {
    struct cmd_x38_tbox_waiting_struct *waiting_struct = (struct cmd_x38_tbox_waiting_struct*)self->vars;
    if (waiting_struct->proceed_boxes)
        tbox_proceed();
    if (!tbox_printer_is_active(waiting_struct->tbox_idx)) {
        waiting_struct->script_state->paused = false;
        cutscene_script_task_delete(self);
    }
}

void cmdx38_tbox_and_interrupt(animation_engine_state_t*mem) {
    u8 tbox_idx = (u8) cutscene_script_read_param(mem);
    u8 font = cutscene_script_read_byte(mem);
    u16 x = cutscene_script_read_hword(mem);
    u16 y = cutscene_script_read_hword(mem);
    u8 letter_spacing = cutscene_script_read_byte(mem);
    u8 line_spacing = cutscene_script_read_byte(mem);
    tbox_font_colormap* font_colormap = (tbox_font_colormap*) cutscene_script_read_word(mem);
    u8 speed = (u8)cutscene_script_read_byte(mem);
    if (speed == 0x80) {
        speed = tbox_get_set_speed();
    }
    string_decrypt(strbuf, (u8*) cutscene_script_read_word(mem));
    u8 proceed_boxes = cutscene_script_read_byte(mem);
    tbox_print_string(tbox_idx, font, x, y, letter_spacing, line_spacing, font_colormap, speed, strbuf);
    cutscene_script_task *t = cutscene_script_task_new(127, cmdx38_wait_for_tbox, sizeof(struct cmd_x38_tbox_waiting_struct), mem->root);
    struct cmd_x38_tbox_waiting_struct *waiting_struct = (struct cmd_x38_tbox_waiting_struct*)t->vars;
    waiting_struct->tbox_idx = tbox_idx;
    waiting_struct->script_state = mem;
    waiting_struct->proceed_boxes = proceed_boxes;
    mem->paused = true;
    bg_copy_vram(tboxes[tbox_idx].boxdata.bg_id, bg_get_tilemap(tboxes[tbox_idx].boxdata.bg_id), 0x800, 0, BG_COPY_TILEMAP);
}

void cmdx39_pause(animation_engine_state_t*mem) {
    mem->delayed = (int)cutscene_script_read_word(mem);
}

void cmdx3A_task_delete_all(animation_engine_state_t*mem) {
    cutscene_script_task_delete_all(mem->root);
}


typedef struct {
    u16 sound;
    s8 pan;
    s8 pan_increment;
    u16 volume;
    s16 volume_increment;
    u8 num_loops;
    u16 loop_duration;
    u16 delay;
} task_loop_sound_control;

static void task_loop_sound_with_pan_and_volume(cutscene_script_task *self) {
    task_loop_sound_control *ctrl = (task_loop_sound_control*)self->vars;
    if (ctrl->delay) {
        ctrl->delay--;
        return;
    }
    if (ctrl->num_loops <= 0) {
        cutscene_script_task_delete(self);
        return;
    }
    ctrl->num_loops--;
    ctrl->delay = ctrl->loop_duration;
    mplay_sound_effect_0_and_1_play_with_pan(ctrl->sound, ctrl->pan);
    volume_set(mplay_info_sound_effect_0, 0xFFFF, ctrl->volume);
    volume_set(mplay_info_sound_effect_1, 0xFFFF, ctrl->volume);
    ctrl->pan = (s8)(ctrl->pan + ctrl->pan_increment);
    ctrl->volume = (u16)(ctrl->volume + ctrl->volume_increment);
}


static void cmdx3B_loop_sound_with_pan_and_volume_decay(animation_engine_state_t*mem) {
    cutscene_script_task *task = cutscene_script_task_new(0, task_loop_sound_with_pan_and_volume, sizeof(task_loop_sound_control), mem->root);
    task_loop_sound_control *ctrl = (task_loop_sound_control*)task->vars;
    ctrl->sound = cutscene_script_read_hword(mem);
    ctrl->pan = (s8)cutscene_script_read_byte(mem);
    ctrl->pan_increment = (s8)cutscene_script_read_byte(mem);
    ctrl->volume = cutscene_script_read_hword(mem);
    ctrl->volume_increment = (s16)cutscene_script_read_hword(mem);
    ctrl->num_loops = cutscene_script_read_byte(mem);
    ctrl->loop_duration = cutscene_script_read_hword(mem);
    ctrl->delay = 0;
}

static void cmdx3C_task_new(animation_engine_state_t*mem) {
    int priority = (int)cutscene_script_read_word(mem);
    void (*callback)(struct cutscene_script_task*) = (void (*)(struct cutscene_script_task*))cutscene_script_read_word(mem);
    size_t var_size = (size_t)cutscene_script_read_word(mem);
    DEBUG("New task with prop %d, callback 0x%x, size %d\n", priority, callback, var_size);
    cutscene_script_task_new(priority, callback, var_size, mem->root);
}

