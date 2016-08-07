/* 
 * File:   text.h
 * Author: Domi
 *
 * Created on 6. August 2016, 16:55
 */

#ifndef TEXT_H
#define	TEXT_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        u8 bg_id;
        u8 x;
        u8 y;
        u8 w;
        u8 h;
        u8 pal;
        u16 start_tile;
    }tboxdata;

    typedef struct{
        tboxdata boxdata;
        void *virtual_tileset;
    }tbox;
    
    tboxdata* tbox_data_new(tboxdata *space, u8 bg_id, u8 x, u8 y, u8 w, u8 h, u8 pal, u16 start_tile);
    void tbox_flush (u8 box_id, u8 pixel);
    u8 tbox_new(tboxdata *boxdata);
    void tbox_tilemap_draw(u8 boxid);
    void tbox_print_string (u8 box_id, u8 font, u8 unkown, u8 border_distance, u8 line_distance_u, u8 line_distance_l, u8* font_col_map, u8 print_charbase, u8 text[]);
    void tbox_sync_with_virtual_bg_and_init_all(tboxdata *boxes);

#ifdef	__cplusplus
}
#endif

#endif	/* TEXT_H */

