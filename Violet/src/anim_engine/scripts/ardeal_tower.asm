.include "anim_engine.s"

.global ae_script_ardeal_tower

.equ HIRO_GFX, 0x1337
.equ SLASH_GFX, 0x1338
.equ LUCIUS_GFX, 0x1339

ae_script_ardeal_tower:
    fadescreen 0x7FFF 0 512 8 0 16
    pause 8
    maintain
    pause 1
    @ Reset
    oam_reset
    callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bg_configurations 3
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x1000
    bg_vmap_init 2 0x800
    pause 1
    @ Load gfx
    bg_override 2 gfx_ardeal_tower_bg3Tiles 0x3000 0 COPYSET
    pause 1
    bg_override 1 gfx_ardeal_tower_bg2Tiles 0x3000 0 COPYSET
    pause 1
    bg_override 0 gfx_ardeal_tower_bg1Tiles 0x3000 0 COPYSET
    pause 1
    bg_override 2 gfx_ardeal_tower_bg3Map 0x800 0 COPYMAP
    bg_override 1 gfx_ardeal_tower_bg2Map 0x800 0 COPYMAP
    bg_override 0 gfx_ardeal_tower_bg1Map 0x800 0 COPYMAP
    pause 1
    loadpal gfx_ardeal_tower_bg3Pal 0 32 UNCOMP RESTORE
    load_obj_pal HIRO_GFX, gfx_ardeal_tower_hiro_hitPal, UNCOMP, RESTORE
    load_obj_pal SLASH_GFX, gfx_ardeal_tower_slashPal, UNCOMP, RESTORE
    load_obj_pal LUCIUS_GFX, gfx_ardeal_tower_luciusPal, UNCOMP, RESTORE
    pause 1
    obj_vram_load ae_animation_ardeal_tower_hiro_falling_graphic
    obj_vram_load ae_animation_ardeal_tower_slash_graphic
    obj_vram_load ae_animation_ardeal_tower_lucius_graphic
    oam_new ae_animation_ardeal_tower_hiro_falling_oam_template 128 50 0 0x8000
    oam_new ae_animation_ardeal_tower_lucius_oam_template 112 52 0 0x8002

    bg_scroll 1, 4000, -250, 0
    pause 1
    fadescreen 0x7FFF 0 512 16 16 0
    pause 16


    oam_new ae_animation_ardeal_tower_slash_oam_template 120 50 0 0x8001
    pause 8

    oam_move 0x8000, 8, 32, -2
    pause 8
    oam_move 0x8000, 64, 4, 0
    pause 48
    fadescreen 0 0 512 16 0 16
    pause 16
    bg_hide 0
    bg_sync
    oam_reset
    callback_reset
    anim_tasks_delete_all
    bg_override 2 gfx_ardeal_tower_hiro_falling_bgTiles 0x3000 0 COPYSET
    bg_override 2 gfx_ardeal_tower_hiro_falling_bgMap 0x800 0 COPYMAP
    loadpal gfx_ardeal_tower_hiro_falling1Pal, 0, 32, UNCOMP, RESTORE
    loadpal gfx_ardeal_tower_hiro_falling_bgPal, 16, 32, UNCOMP, RESTORE
    pause 1
    bg_scroll 2, 1000, 0, -8000
    pause 1
    spawn_big_cb animation_ardeal_tower_falling_bg_animation, 5, 2
        .hword 0, 0 // Delay and frame
    pause 1
    fadescreen 0 0 512 16 16 0
    pause 256
    bg_scroll 1, 16, 0, -256
    pause 96
    mapreload
    script_notify
    end

.align 4
bg_configurations:
    bg_setup_cnfg 0 0 31 BG_SIZE_256x256 0 0
    bg_setup_cnfg 1 1 28 BG_SIZE_256x512 0 1
    bg_setup_cnfg 2 2 30 BG_SIZE_256x256 0 2
