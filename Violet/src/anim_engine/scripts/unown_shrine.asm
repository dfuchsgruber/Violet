.include "anim_engine.s"

.global ae_script_unown_shrine

ae_script_unown_shrine:
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
    set_io_to_val (-80) & 0xFFFF, 0x16
    pause 1
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
    pause 1
    fadescreen 0 0 512 16 16 0
    pause 1000
    mapreload
    script_notify
    end

.align 4
bg_configurations:
    bg_setup_cnfg 0 0 31 BG_SIZE_256x256 0 0
    bg_setup_cnfg 1 1 28 BG_SIZE_256x256 0 1
    bg_setup_cnfg 2 2 30 BG_SIZE_256x256 0 2
