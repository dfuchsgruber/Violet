/* 
 * File:   bg.h
 * Author: Domi
 *
 * Created on 25. Juni 2016, 16:57
 */

#ifndef BG_H
#define	BG_H

#include "text.h"
#include "anim_engine.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define MAP_BGN_AUTO_ALIGN_OFF 0x916
    typedef struct {
        u32 bg_id : 2;
        u32 char_base : 2;
        u32 map_base : 5;
        u32 size : 2;
        u32 color_mode : 1;
        u32 priority : 2;
    } bg_config;

    void bg_setup(u8 tile_mode, bg_config configs[], u8 config_cnt);

    void *gp_tmp_buf = (void*)0x0201C000;

#ifdef	__cplusplus
}
#endif

#endif	/* BG_H */

