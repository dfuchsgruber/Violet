#include "math.h"
#include "types.h"
#include "save.h"
#include "callbacks.h"
#include "bg.h"
#include "text.h"
#include "superstate.h"
#include "oam.h"
#include "debug.h"
#include "fading.h"
#include "constants/vars.h"
#include "language.h"
#include "flags.h"
#include "constants/flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "bios.h"
#include "music.h"
#include "overworld/map_control.h"
#include "io.h"
#include "overworld/script.h"
#include "transparency.h"
#include "rtc.h"
#include "math.h"
#include "callbacks.h"
#include "trainerschool_test.h"

#define TEST_TIME (60 * 60) // 1 minutes?

bg_config trainerschool_test_bg_configs[3] = {
    {0, 2, 31, 0, 0, 1}, //text on bg0
    {1, 1, 30, 0, 0, 0}, //bg1 is above bg0 to show paper sliding
    {2, 0, 29, 0, 0, 2}
};

tboxdata trainerschool_test_tboxes [] = {
    {0, 8, 1, 12, 8, 0, 1}, //0 := question
    {0, 9, 10, 14, 2, 0, 97}, //1 + x = answer x
    {0, 9, 12, 14, 2, 0, 125},
    {0, 9, 14, 14, 2, 0, 153},
    {0, 9, 16, 14, 2, 0, 181},
    {0, 9, 18, 14, 2, 0, 209},
    {0xFF, 0, 0, 0, 0, 0, 0}
};

extern const short gfx_trainerschool_page_0Tiles[];
extern const short gfx_trainerschool_page_0Map[];
extern const short gfx_trainerschool_page_1Tiles[];
extern const short gfx_trainerschool_page_1Map[];
extern const short gfx_trainerschool_page_2Tiles[];
extern const short gfx_trainerschool_page_2Map[];
extern const short gfx_trainerschool_paperTiles[];
extern const short gfx_trainerschool_paperMap[];
extern const short gfx_trainerschool_paperPal[];
extern const short gfx_trainerschool_correctTiles[];
extern const short gfx_trainerschool_correctPal[];
extern const short gfx_trainerschool_wrongTiles[];
extern const u8 gfx_trainerschool_clockTiles[];
extern const short gfx_trainerschool_clockPal[];

static tbox_font_colormap trainerschool_test_fontcolmap_std = {
    0, 6, 7, 3
};

static graphic trainerschool_test_graphic_correct = {
    &gfx_trainerschool_correctTiles,
    0x800,
    0xA0E0
};

static graphic trainerschool_test_graphic_wrong = {
    &gfx_trainerschool_wrongTiles,
    0x800,
    0xA0E1
};

/**
static graphic trainerschool_graphic_clock = {
    &gfx_trainerschool_clockTiles,
    GRAPHIC_SIZE_4BPP(32, 512),
    0xA0E2,
};
**/

static sprite trainerschool_test_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, 
    .attr1 = ATTR1_SIZE_64_64, 
    .attr2 = ATTR2_PRIO(0),
};

static sprite trainerschool_clock_sprite = {
    .attr0 = ATTR0_SHAPE_VERTICAL | ATTR0_ROTSCALE | ATTR0_DSIZE, 
    .attr1 = ATTR1_SIZE_32_64, 
    .attr2 = ATTR2_PRIO(0), 
};


static rotscale_frame trainerschool_test_rotscal_anim[] = {
    {.affine = {0x200, 0x200, 0, 0, 0}}, {.affine = {-36, -36, 0, 12, 0}},
    {.command = {ROTSCALE_ANIM_END, 0, 0, 0}}
};

/**
static gfx_frame trainerschool_clock_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 8}, {.data = 32, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 1},
    {.data = 64, .duration = 0}, {.data = 64, .duration = 8}, {.data = 96, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 5},
    {.data = 128, .duration = 0}, {.data = 128, .duration = 8}, {.data = 160, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 9},
    {.data = 192, .duration = 0}, {.data = 192, .duration = 8}, {.data = 224, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 13},
};
**/
static gfx_frame trainerschool_clock_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 8}, {.data = 1, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 0},
    {.data = 2, .duration = 0}, {.data = 2, .duration = 8}, {.data = 3, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 0},
    {.data = 4, .duration = 0}, {.data = 4, .duration = 8}, {.data = 5, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 0},
    {.data = 6, .duration = 0}, {.data = 6, .duration = 8}, {.data = 7, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 0},
};

static graphic trainerschool_clock_gfx_table[] = {
    {gfx_trainerschool_clockTiles + 0 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 1 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 2 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 3 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 4 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 5 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 6 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
    {gfx_trainerschool_clockTiles + 7 * GRAPHIC_SIZE_4BPP(32, 64), .size = GRAPHIC_SIZE_4BPP(32, 64)},
};

static gfx_frame *trainerschool_clock_gfx_animations[] = {
    trainerschool_clock_gfx_animation + 0, trainerschool_clock_gfx_animation + 4, trainerschool_clock_gfx_animation + 8,
    trainerschool_clock_gfx_animation + 12,
};

static rotscale_frame trainerschool_clock_rotscale_animation[] = {
    {.affine = {0x100, 0x100, 0, 0, 0}},
    {.affine = {0, 0, 1, 3, 0}},
    {.affine = {0, 0, 0, 24, 0}},
    {.affine = {0, 0, (-1), 6, 0}},
    {.affine = {0, 0, 0, 24, 0}},
    {.affine = {0, 0, 1, 3, 0}},
    {.command = {ROTSCALE_ANIM_JUMP, 1, 0, 0}}
};

static rotscale_frame *trainerschool_test_rotscale_table[] = {trainerschool_test_rotscal_anim};
static rotscale_frame *trainerschool_clock_rotscale_animations[] = {trainerschool_clock_rotscale_animation};


static oam_template trainerschool_test_oam_template_correct = {
    0xA0E0, 0xA0E0,
    &trainerschool_test_sprite,
    oam_gfx_anim_table_null,
    NULL,
    trainerschool_test_rotscale_table,
    oam_null_callback,
};

static oam_template trainerschool_test_oam_template_wrong = {
    0xA0E1, 0xA0E0,
    &trainerschool_test_sprite,
    oam_gfx_anim_table_null,
    NULL,
    trainerschool_test_rotscale_table,
    oam_null_callback,
};

static void trainerschool_clock_callback(oam_object *self) {
    if (TRAINER_SCHOOL_TEST_STATE->finished) {
        return;
    }
    u8 anim_idx = (u8)(TRAINER_SCHOOL_TEST_STATE->timer * 4 / TEST_TIME);
    // DEBUG("Anim idx %d\n", anim_idx);
    DEBUG("Timer %d\n", TRAINER_SCHOOL_TEST_STATE->timer);
    if (anim_idx != self->anim_number) {
        self->anim_number = anim_idx;
        oam_gfx_anim_init(self, 0);
    }
    int frame = self->private[2]; // [0 to 63]
    self->private[2] = (u16)((self->private[2] + 1) % 64);
    // If 90% of the time is used up, the timer will fade red
    if ((TRAINER_SCHOOL_TEST_STATE->timer * 10 / TEST_TIME) >= 9) {
        (void)frame;
        if (!fading_control.active) {
            u8 alpha = (u8)MAX(0, 4 + sine((s16)(frame * 4), 4));
            u8 pal_idx = oam_palette_get_index(self->oam_template->pal_tag);
            color_t col_red = {.rgb = {.red = 31, .blue = 0, .green = 0}};
            pal_alpha_blending((u16)(256 + 16 * pal_idx), 16, alpha, col_red);
        }
        self->x2 = sine((s16)((frame % 16) * 16), 3);
    }
}

static oam_template trainerschool_test_oam_template_clock = {
    0xFFFF, 0xA0E2,
    &trainerschool_clock_sprite,
    trainerschool_clock_gfx_animations,
    trainerschool_clock_gfx_table,
    trainerschool_clock_rotscale_animations,
    trainerschool_clock_callback,
};

u8 str_trainerschool_test_list[] = PSTRING("-");
u8 str_trainerschool_test_cursor[] = PSTRING("▶");

void trainerschool_test_load_answers(){
    u8 question = TRAINER_SCHOOL_TEST_STATE->current_question;
    DEBUG("Question %d\n", question);
    int i;
    for(i = 0; i < 5; i++){
        DEBUG("Printing answer %d\n", i);
        tbox_flush_set((u8)(i + 1), 0);
        tbox_tilemap_draw((u8)(i + 1));
        
        if(i < trainerschool_test_questions[question].answer_cnt){
            strcpy(strbuf, 
                    TRAINER_SCHOOL_TEST_STATE->cursor == i ? str_trainerschool_test_cursor :
                    str_trainerschool_test_list);
            strcat(strbuf, trainerschool_test_questions[question].answers[i]);
            tbox_print_string((u8)(i + 1), 2, 0, 0, 0, 0, 
                    &trainerschool_test_fontcolmap_std, 0,
                    strbuf);
            
        }else{
            DEBUG("clearing answer %d\n", i);
            //tbox_flush_map((u8)(i + 1));
            u8 str_none[] = {0xFF};
            tbox_print_string((u8)(i + 1), 2, 0, 0, 0, 0, 
                    &trainerschool_test_fontcolmap_std, 0,
                    str_none);
        }
    }
}

void trainerschool_test_load_question(){
    u8 question = TRAINER_SCHOOL_TEST_STATE->current_question;
    TRAINER_SCHOOL_TEST_STATE->cursor = 0;
    //Print question
    
    tbox_flush_set(0, 0);
    tbox_tilemap_draw(0);
    tbox_print_string(0, 2, 0, 0, 0, 0, &trainerschool_test_fontcolmap_std, 0,
            trainerschool_test_questions[question].question);
    trainerschool_test_load_answers();
}

void trainerschool_test_done(){
    generic_callback1();
    if(!fading_is_active()){
        // clearflag(MAP_BGN_AUTO_ALIGN_OFF);   
        overworld_script_resume();
        callback1_set(map_reload);
    }
}

void trainerschool_test_question_done(){
    generic_callback1();
    if(TRAINER_SCHOOL_TEST_STATE->delay) TRAINER_SCHOOL_TEST_STATE->delay--;
    else{
        switch(TRAINER_SCHOOL_TEST_STATE->frame){
            case 0:
                TRAINER_SCHOOL_TEST_STATE->current_question++;
                if(TRAINER_SCHOOL_TEST_STATE->current_question == 10){
                    TRAINER_SCHOOL_TEST_STATE->finished = 1;
                    fadescreen_all(1, 0);
                    callback1_set(trainerschool_test_done);
                    return;
                }
                trainerschool_test_load_question(); //load next question
                play_sound(30);
                bg_sync_display_and_show(1);
                bg_display_sync();
                oam_rotscale_free(&oams[TRAINER_SCHOOL_TEST_STATE->answer_oam]);
                oam_delete(&oams[TRAINER_SCHOOL_TEST_STATE->answer_oam]);
                lz77uncompwram(gfx_trainerschool_page_0Tiles, gp_tmp_buf);
                lz77uncompwram(gfx_trainerschool_page_0Map, bg_get_tilemap(1));
                bg_copy_vram(1, gp_tmp_buf, 0x1000, 0, 1);
                bg_copy_vram(1, bg_get_tilemap(1), 0x800, 0, 2);
                TRAINER_SCHOOL_TEST_STATE->delay = 10;
                TRAINER_SCHOOL_TEST_STATE->frame++;
                break;
            case 1:
                lz77uncompwram(gfx_trainerschool_page_1Tiles, gp_tmp_buf);
                lz77uncompwram(gfx_trainerschool_page_1Map, bg_get_tilemap(1));
                bg_copy_vram(1, gp_tmp_buf, 0x1000, 0, 1);
                bg_copy_vram(1, bg_get_tilemap(1), 0x800, 0, 2);
                TRAINER_SCHOOL_TEST_STATE->delay = 10;
                TRAINER_SCHOOL_TEST_STATE->frame++;
                break;
            case 2:
                lz77uncompwram(gfx_trainerschool_page_2Tiles, gp_tmp_buf);
                lz77uncompwram(gfx_trainerschool_page_2Map, bg_get_tilemap(1));
                bg_copy_vram(1, gp_tmp_buf, 0x1000, 0, 1);
                bg_copy_vram(1, bg_get_tilemap(1), 0x800, 0, 2);
                TRAINER_SCHOOL_TEST_STATE->delay = 10;
                TRAINER_SCHOOL_TEST_STATE->frame++;
                break;
            default:
                bg_hide(1);
                bg_display_sync();
                callback1_set(trainerschool_test_idle);
                break;
        }
    }
}

void trainerschool_times_up() {
    generic_callback1();
    if (!fading_control.active) {
        if (TRAINER_SCHOOL_TEST_STATE->delay) {
            TRAINER_SCHOOL_TEST_STATE->delay--;
            return;
        }
        fadescreen_all(1, 0);
        callback1_set(trainerschool_test_done);
    }

}


void trainerschool_test_idle(){
    generic_callback1();
    TRAINER_SCHOOL_TEST_STATE->timer++;
    if (TRAINER_SCHOOL_TEST_STATE->timer >= TEST_TIME) {
        TRAINER_SCHOOL_TEST_STATE->finished = 1;
        TRAINER_SCHOOL_TEST_STATE->delay = 64;
        play_sound(26);
        callback1_set(trainerschool_times_up);
        return;
    }
    if(super.keys_new.keys.down){
        TRAINER_SCHOOL_TEST_STATE->cursor++;
        TRAINER_SCHOOL_TEST_STATE->cursor = 
        (u8)(TRAINER_SCHOOL_TEST_STATE->cursor %
                trainerschool_test_questions[TRAINER_SCHOOL_TEST_STATE->current_question].answer_cnt);
        play_sound(5);
        trainerschool_test_load_answers();
    }else if(super.keys_new.keys.up){
        if(!TRAINER_SCHOOL_TEST_STATE->cursor)TRAINER_SCHOOL_TEST_STATE->cursor = (u8)
                (trainerschool_test_questions[TRAINER_SCHOOL_TEST_STATE->current_question].answer_cnt - 1);
        else TRAINER_SCHOOL_TEST_STATE->cursor--;
        play_sound(5);
        trainerschool_test_load_answers();
    }else if(super.keys_new.keys.A){
        s16 y = (s16)(TRAINER_SCHOOL_TEST_STATE->cursor * 16 + 83);
        u8 question = TRAINER_SCHOOL_TEST_STATE->current_question;
        if(trainerschool_test_questions[question].correct_answer == TRAINER_SCHOOL_TEST_STATE->cursor){
            //correct answer
            fanfare(269);
            play_sound(12);
            (*var_access(TRAINERSCHOOL_CORRECT_ANSWERS))++;
            TRAINER_SCHOOL_TEST_STATE->answer_oam = oam_new_forward_search(
                &trainerschool_test_oam_template_correct, 168, y, 0);
            TRAINER_SCHOOL_TEST_STATE->delay = 0xC0;
            TRAINER_SCHOOL_TEST_STATE->frame = 0;
            callback1_set(trainerschool_test_question_done);
        }else{
            fanfare(271);
            play_sound(12);
            TRAINER_SCHOOL_TEST_STATE->answer_oam = oam_new_forward_search(
                &trainerschool_test_oam_template_wrong, 168, y, 0);
            TRAINER_SCHOOL_TEST_STATE->delay = 0xC0;
            TRAINER_SCHOOL_TEST_STATE->frame = 0;
            callback1_set(trainerschool_test_question_done);
        }
    }
}

void trainerschool_exam_init_components(){
    generic_callback1();
    if(!fading_is_active()){
        //init gfx and stuff
        
        big_callback_delete_all();
        oam_reset();
        oam_palette_allocation_reset();
        bg_reset(0);
        bg_setup(0, trainerschool_test_bg_configs, 3);
        
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_display_sync();
        bg_virtual_map_displace(0, 0, 0);
        bg_virtual_set_displace(0, 0, 0);
        bg_virtual_map_displace(1, 0, 0);
        bg_virtual_set_displace(1, 0, 0);
        bg_virtual_map_displace(2, 0, 0);
        bg_virtual_set_displace(2, 0, 0);
        io_set(0x10, 0);
        io_set(0x12, 4);
        io_set(0x14, 0);
        io_set(0x16, 0);
        io_set(0x18, 0);
        io_set(0x1A, 0);
        
        void *bg0map = malloc_and_clear(0x800);
        void *bg1map = malloc_and_clear(0x800);
        void *bg2map = malloc_and_clear(0x800);
        
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        
        lz77uncompwram(gfx_trainerschool_paperMap, bg2map);
        lz77uncompvram(gfx_trainerschool_paperTiles, (void*) 0x06000000);
        lz77uncompvram(gfx_trainerschool_page_0Tiles, (void*) 0x06004000);
        bg_copy_vram(0, bg0map, 0x800, 0, 2);
        bg_copy_vram(1, bg1map, 0x800, 0, 2);
        bg_copy_vram(2, bg2map, 0x800, 0, 2);
        pal_decompress(gfx_trainerschool_paperPal, 0, 32);
        u8 pal_id = oam_allocate_palette(0xA0E0);
        pal_decompress(gfx_trainerschool_correctPal, (u16)(256 + pal_id * 16), 32);
        pal_decompress(gfx_trainerschool_clockPal, (u16)(256 + oam_allocate_palette(0xA0E2) * 16), 16 * sizeof(color_t));
        pal_copy(tbox_palette_transparent, 15 * 16, 16 * sizeof(color_t));
        pal_set_all_to_black(); //we avoid the 1frame show of a pal
        

        tbox_sync_with_virtual_bg_and_init_all(trainerschool_test_tboxes);
        trainerschool_test_load_question();

        
        oam_load_graphic(&trainerschool_test_graphic_correct);
        oam_load_graphic(&trainerschool_test_graphic_wrong);
        // oam_load_graphic(&trainerschool_graphic_clock);
        oam_new_forward_search(&trainerschool_test_oam_template_clock, 212, 48, 1);
        
        
        fadescreen_all(0, 0);
        callback1_set(trainerschool_test_idle);
        vblank_handler_set(generic_vblank_handler);

        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
    }
}

void trainerschool_exam_init(){
    generic_callback1();
    *var_access(TRAINERSCHOOL_CORRECT_ANSWERS) = 0;
    fmem.gp_state = (trainerschool_test_memory*) malloc_and_clear(sizeof(trainerschool_test_memory));
    TRAINER_SCHOOL_TEST_STATE->current_question = 0;
    TRAINER_SCHOOL_TEST_STATE->timer = 0;
    TRAINER_SCHOOL_TEST_STATE->finished = 0;
    fadescreen_all(1, 0);
    callback1_set(trainerschool_exam_init_components);
    vblank_handler_set(generic_vblank_handler);
    // setflag(MAP_BGN_AUTO_ALIGN_OFF);
}

