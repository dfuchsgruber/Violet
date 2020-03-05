.include "anim_engine.s"

.global ae_script_arc_scrim



ae_script_arc_scrim:
frame 0
    fadescreen 0 0 512 16 0 16
    endframe

frame 16
    maintain
    @dma3_reset
    endframe

frame 17
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
    bg_vmap_init 1 0x800
    bg_vmap_init 2 0x800
    bg_override 2 gfx_arc_scrim_backTiles 0x4000 0 COPYSET
    bg_override 1 gfx_arc_scrim_frontTiles 0x4000 0 COPYSET
    bg_override 0 gfx_arc_scrim_textTiles 0x4000 0 COPYSET
    bg_override 2 gfx_arc_scrim_backMap 0x800 0 COPYMAP
    bg_override 1 gfx_arc_scrim_frontMap 0x800 0 COPYMAP
    bg_override 0 gfx_arc_scrim_textMap 0x800 0 COPYMAP
    loadpal gfx_arc_scrim_backPal 0 32 UNCOMP RESTORE
    endframe

frame 18
    bg_scroll 1 8000 0xF830 0
    fadescreen 0 0 512 16 16 0
    endframe


frame 400
    fadescreen 0 0 512 16 0 16
    endframe

frame 420
    force_pals_to_black
    callasm 0x80553AD 5
    .word 2, 33, 0, 0, 0
    callasm 0x0807E3D5 0
    callasm 0x08055A05 0
    end
    endframe

.align 4
bgcnfgs:
    bg_setup_cnfg 0 2 31 0 0 0
    bg_setup_cnfg 1 1 28 0 0 1
    bg_setup_cnfg 2 0 30 0 0 2

