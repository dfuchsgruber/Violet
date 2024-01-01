.include "anim_engine.s" 

.global cutscene_script_unown_shrine

.equ LIGHTNING_TAG, 0x1AAB

cutscene_script_unown_shrine:
    fadescreen 0 0 512 16 0 16
    pause 16 + 1
    maintain
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
    bg_vmap_init 1 0x800
    bg_vmap_init 2 0x800
    pause 1
    set_io_to_val 0 0x12
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0 0x1a
    set_io_to_val 0 0x1c
    @ Load gfx
    bg_override 2 gfx_cutscene_unown_shrine_clouds_bgTiles 0x3000 0 COPYSET
    pause 1
    bg_override 1 gfx_cutscene_unown_shrine_shrine_bgTiles 0x3000 0 COPYSET
    pause 1
    bg_override 0 gfx_cutscene_unown_shrine_grass_bgTiles 0x3000 0 COPYSET
    pause 1
    bg_override 2 gfx_cutscene_unown_shrine_clouds_bgMap 0x800 0 COPYMAP
    bg_override 1 gfx_cutscene_unown_shrine_shrine_bgMap 0x800 0 COPYMAP
    bg_override 0 gfx_cutscene_unown_shrine_grass_bgMap 0x800 0 COPYMAP
    pause 1
    loadpal gfx_cutscene_unown_shrine_clouds_bgPal 0 32 UNCOMP RESTORE
    loadpal gfx_cutscene_unown_shrine_grass_bgPal 16 32 UNCOMP RESTORE
    loadpal gfx_cutscene_unown_shrine_shrine_bgPal 32 32 UNCOMP RESTORE
    load_obj_pal LIGHTNING_TAG, gfx_cutscene_unown_shrine_lightningPal, UNCOMP, 0
    pause 1
    // obj_vram_load unown_shrine_lightning_graphic
    anim_task_new 0, unown_shrine_animation_lightning_callback, 256
    pause 1
    sound 227
    fadescreen 0 0 512 16 16 4
    pause 240
    fadescreen 0 0 512 16 4 0
    pause 100
    mapreload
    script_notify
    end

.align 4
bg_configurations:
    bg_setup_cnfg 0 0 31 BG_SIZE_256x256 0 0
    bg_setup_cnfg 1 1 28 BG_SIZE_256x256 0 1
    bg_setup_cnfg 2 2 30 BG_SIZE_256x256 0 2
