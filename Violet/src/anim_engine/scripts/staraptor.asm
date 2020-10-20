.include "anim_engine.s"

.global ae_script_staraptor_to
.global ae_script_staraptor_from


.align 4
ae_script_staraptor_to:
    fadescreen 0 0 512 16 0 16
    pause 16
    //maintain
    pause 1
    script_notify //BGN Auto Align off
    oam_reset
    //callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bgcnfgs 1
    bg_sync_and_show 1
    bg_sync
    bg_vmap_init 1 0x800
    bg_override 1 gfx_anim_staraptor_bgTiles 0x1000 0 COPYSET
    bg_override 1 gfx_anim_staraptor_bgMap 0x800 0 COPYMAP
    obj_vram_load anim_staraptor_front_graphic
    obj_vram_load anim_staraptor_back_graphic
    load_obj_pal 0xCD72 gfx_anim_staraptor_backPal UNCOMP RESTORE
    load_obj_pal 0xCD73 gfx_ow_pal_hiroinePal COPY RESTORE
    loadpal gfx_anim_staraptor_bgPal 0 32 UNCOMP RESTORE
    oam_new anim_staraptor_front_template 120 100 0 0x8000
    jump_if_female load_female_template 17
    oam_new anim_staraptor_hiro_template_to 118 90 1 0x8001
    jump after_loading_template 17 
load_female_template:
    oam_new anim_staraptor_hiroine_template_to 118 90 1 0x8001
after_loading_template:
    oam_new anim_staraptor_back_template 120 100 2 0x8002
    bg_scroll 1 800 2400 0
    pause 1
    set_io_to_val 0 0x16
    fadescreen 0 0 512 16 16 0
    pause 16
    sound 150
    pause 48
    sound 150
    pause 48
    sound 151
    oam_move 0x8000 50 150 0
    oam_move 0x8001 50 150 0
    oam_move 0x8002 50 150 0
    pause 64
    fadescreen 0 0 512 16 0 16
    pause 32
    force_pals_to_black
    //mapreload
    pause 1
    script_notify
    end

ae_script_staraptor_from:
    fadescreen 0 0 512 16 0 16
    pause 16
    //maintain
    pause 1
    script_notify //BGN Auto Align off
    oam_reset
    //callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bgcnfgs 1
    bg_sync_and_show 1
    bg_sync
    bg_vmap_init 1 0x800
    bg_override 1 gfx_anim_staraptor_bgTiles 0x1000 0 COPYSET
    bg_override 1 gfx_anim_staraptor_bgMap 0x800 0 COPYMAP
    obj_vram_load anim_staraptor_front_graphic
    obj_vram_load anim_staraptor_back_graphic
    load_obj_pal 0xCD72 gfx_anim_staraptor_backPal UNCOMP RESTORE
    load_obj_pal 0xCD73 gfx_ow_pal_hiroinePal COPY RESTORE
    loadpal gfx_anim_staraptor_bgPal 0 32 UNCOMP RESTORE
    oam_new anim_staraptor_front_flipped_template 120 100 0 0x8000
    jump_if_female load_female_template_b 17
    oam_new anim_staraptor_hiro_template_from 118 90 1 0x8001
    jump after_loading_template_b 17 
load_female_template_b:
    oam_new anim_staraptor_hiroine_template_from 118 90 1 0x8001
after_loading_template_b:
    oam_new anim_staraptor_back_flipped_template 120 100 2 0x8002
    bg_scroll 1 800 0xFCE0 0
    pause 1
    set_io_to_val 0 0x16
    fadescreen 0 0 512 16 16 0
    pause 16
    sound 150
    pause 48
    sound 150
    pause 48
    sound 151
    oam_move 0x8000 50 0xFF6A 0
    oam_move 0x8001 50 0xFF6A 0
    oam_move 0x8002 50 0xFF6A 0
    pause 64
    fadescreen 0 0 512 16 0 16
    pause 32
    force_pals_to_black
    //mapreload
    pause 1
    script_notify
    end

.align 4
bgcnfgs:
    bg_setup_cnfg 1 0 30 0 0 1
    
