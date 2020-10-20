.include "anim_engine.s"

.global ae_script_groudon_diserakt

.align 4
ae_script_groudon_diserakt:
    fadescreen 0 0 512 64 0 16
    pause 64
    maintain
    @dma3_reset
    pause 1
    oam_reset
    callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bgcnfgs 2
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x800
    bg_override 0 gfx_groudon_diserakt_frontTiles 0x4000 0 COPYSET
    bg_override 0 gfx_groudon_diserakt_frontMap 0x800 0 COPYMAP
    bg_override 1 gfx_groudon_magmaTiles 0x4000 0 COPYSET
    bg_override 1 gfx_groudon_magmaMap 0x800 0 COPYMAP
    loadpal gfx_groudon_magmaPal 16 32 UNCOMP RESTORE
    load_obj_pal 0xA0A1 gfx_groudon_diseraktPal UNCOMP RESTORE
    obj_vram_load graphic_groudon_diserakt
    oam_new oam_template_groudon_diserakt 108 100 0 0x8000
    set_io_to_val 10 0x10
    pause 1
    fadescreen 0 0 512 64 16 0
    spawn_big_cb groudon_bg_scroll_diserakt_cb 0 1
    .hword 0
    pause 64
    spawn_big_cb groudon_anim_diserakt_cb 0 4
    .hword 0,0,0,0
    pause 8 * 64
    setvar 0x8001 1
    pause 1
    mapreload
    script_notify
    end

.align 4
bgcnfgs:
    bg_setup_cnfg 0 1 31 0 0 0
    bg_setup_cnfg 1 2 28 0 0 1

