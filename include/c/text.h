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
    } tboxdata;

    typedef struct {
        tboxdata boxdata;
        u16 *virtual_tileset;
    } tbox;
    
    tbox *tboxes = (tbox*)0x020204B4;
    
#define TBOX_SYNC_MAP 1
#define TBOX_SYNC_SET 2
#define TBOX_SYNC_MAP_AND_SET 3
    void tbox_sync(u8 box_id, u8 sync_type);
    

    tboxdata* tbox_data_new(tboxdata *space, u8 bg_id, u8 x, u8 y, u8 w, u8 h, u8 pal, u16 start_tile);
    void tbox_flush(u8 box_id, u8 pixel);
    void tbox_flush_map(u8 box_id);
    /**
     * 
     * @param font usually 2
     * @param str
     * @param unkown usually 0
     * @return probably in pixels
     */
    u8 string_get_width(u8 font, const u8 *str, s16 unkown);
    u8 tbox_new(tboxdata *boxdata);
    void tbox_tilemap_draw(u8 boxid);
    void tbox_print_string(u8 box_id, u8 font, u16 x_start, u16 y_start, u8 line_distance_u, u8 line_distance_l, u8* font_col_map, u8 print_charbase, u8 text[]);
    void tbox_sync_with_virtual_bg_and_init_all(tboxdata *boxes);
    void tbox_border_init(u8 box_id, u16 set_displace, u16 dest_color);
    void tbox_border_draw(u8 box_id, u16 map_displace, u8 dest_pal);
    void tbox_border_flush(u8 box_id);
    
    u8 *strbuf = (u8*) 0x02021D18;
    u8 *buffer0 = (u8*) 0x02021CD0;

#ifdef	__cplusplus
}
#endif

#endif	/* TEXT_H */

