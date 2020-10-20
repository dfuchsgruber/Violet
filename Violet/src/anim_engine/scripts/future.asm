.include "anim_engine.s"

.global ae_script_future


ae_script_future:
    fadescreen 0 0 512 32 3 16
    pause 32
    maintain
    pause 1
    oam_reset
    callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bgcnfgs 4
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync_and_show 3
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x800
    bg_vmap_init 2 0x800
    bg_vmap_init 3 0x800
    bg_override 3 gfx_future_layer_3Tiles 0x3000 0 COPYSET
    bg_override 3 gfx_future_layer_3Map 0x800 0 COPYMAP
    loadpal gfx_future_layer_3Pal 0 32 UNCOMP RESTORE
    bg_override 2 gfx_future_layer_2Tiles 0x3000 0 COPYSET
    bg_override 2 gfx_future_layer_2Map 0x800 0 COPYMAP
    loadpal gfx_future_layer_2Pal 16 32 UNCOMP RESTORE
    bg_override 1 gfx_future_layer_1Tiles 0x3000 0 COPYSET
    bg_override 1 gfx_future_layer_1Map 0x800 0 COPYMAP
    loadpal gfx_future_layer_1Pal 32 32 UNCOMP RESTORE
    pause 1
    fadescreen 0 0 512 32 16 0
    bg_scroll 3 6000 100 0
    bg_scroll 2 6000 1000 0
    bg_scroll 1 6000 2000 0
    pause 250
    fadescreen 0 0 512 32 0 16
    pause 16
    force_pals_to_black
    pause 1
    mapreload
    script_notify
    end

.align 4
bgcnfgs:
    bg_setup_cnfg 0 2 31 0 0 0
    bg_setup_cnfg 1 0 30 0 0 1
    bg_setup_cnfg 2 1 29 0 0 2
    bg_setup_cnfg 3 3 28 0 0 3

