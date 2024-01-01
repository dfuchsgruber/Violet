.include "cutscene_script.s"

.global cutscene_script_groudon

.align 4
cutscene_script_groudon:
    fadescreen 0 0 512 128 0 16
    pause 128
    maintain
    @dma3_reset
    pause 1
    oam_reset
    callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bgcnfgs 3
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x1000
    bg_vmap_init 2 0x800
    pause 1
    bg_override 0 gfx_groudon_magma_frontTiles 0x4000 0 COPYSET
    bg_override 0 gfx_groudon_magma_frontMap 0x800 0 COPYMAP
    bg_override 1 gfx_groudon_bodyTiles 0x3000 0 COPYSET
    bg_override 1 gfx_groudon_bodyMap 0x1000 0 COPYMAP
    bg_override 2 gfx_groudon_magmaTiles 0x4000 0 COPYSET
    bg_override 2 gfx_groudon_magmaMap 0x800 0 COPYMAP
    loadpal gfx_groudon_bodyPal 0 32 UNCOMP RESTORE
    pause 1
    loadpal gfx_groudon_magmaPal 16 32 UNCOMP RESTORE
    load_obj_pal 0xA0A0 gfx_groudon_arm_leftPal UNCOMP RESTORE
    obj_vram_load graphic_groudon_head
    obj_vram_load graphic_groudon_arm_left
    obj_vram_load graphic_groudon_arm_right
    obj_vram_load graphic_groudon_leg_left
    obj_vram_load graphic_groudon_leg_right
    pause 1
    oam_new oam_template_groudon_head 76+80 72+60 0 0x8000
    oam_new oam_template_groudon_arm_left 118+80 88+60 0 0x8001
    oam_new oam_template_groudon_arm_right 72+80 90+60 0 0x8002
    oam_new oam_template_groudon_leg_left 148+80 118+60 0 0x8003
    oam_new oam_template_groudon_leg_right 100+80 112+60 0 0x8004
    pause 1
    set_io_to_val -14 0x12
    set_io_to_val -80 0x14
    set_io_to_val -60 0x16
    pause 1
    //spawn_big_cb groudon_bg_scroll_cb 0 3
    //.hword 0,0,0
    //spawn_big_cb groudon_bg_scroll_all 0 0
    fadescreen 0 16 240 128 16 0
    pause 4 * 64
    sound 202
    fade_obj_pal 0 0xA0A0 1 1 32 16 0
    pause 32
    cry 0x195 0
    pause 2 * 64
    sound 0xCF
    fadescreen 0 0 16 32 16 15
    fade_obj_pal 0 0xA0A0 2 14 32 16 15
    spawn_big_cb groudon_anim_earthquake_cb 0 4
    .hword 32, 1, 64, 2
    spawn_big_cb groudon_anim_step_cb 0 1
    .hword 32
    pause 100
    sound 0xCF
    fadescreen 0 0 16 32 15 14
    fade_obj_pal 0 0xA0A0 2 14 32 15 14
    spawn_big_cb groudon_anim_earthquake_cb 0 4
    .hword 32, 1, 64, 2
    spawn_big_cb groudon_anim_step_cb 0 1
    .hword 32
    pause 100
    sound 0xCF
    fadescreen 0 0 16 32 14 11
    fade_obj_pal 0 0xA0A0 2 14 32 14 11
    spawn_big_cb groudon_anim_earthquake_cb 0 4
    .hword 32, 1, 64, 2
    spawn_big_cb groudon_anim_step_cb 0 1
    .hword 32
    pause 100
    sound 0xCF
    fadescreen 0 0 16 32 11 7
    fade_obj_pal 0 0xA0A0 2 14 32 11 7
    spawn_big_cb groudon_anim_earthquake_cb 0 4
    .hword 32, 1, 64, 2
    spawn_big_cb groudon_anim_step_cb 0 1
    .hword 32
    pause 100
    sound 0xCF
    fadescreen 0 0 16 32 7 0
    fade_obj_pal 0 0xA0A0 2 14 32 7 0
    spawn_big_cb groudon_anim_earthquake_cb 0 4
    .hword 32, 1, 64, 2
    spawn_big_cb groudon_anim_step_cb 0 1
    .hword 32
    pause 10 * 64
    sound 0xCF
    cry 0x195 0
    spawn_big_cb groudon_anim_earthquake_cb 0 4
    .hword 64, 2, 128, 2
    pause 5 * 64
    mapreload
    script_notify
    end

.align 4
bgcnfgs:
    bg_setup_cnfg 0 1 31 0 0 0
    bg_setup_cnfg 1 2 28 1 0 1
    bg_setup_cnfg 2 0 26 0 0 2

