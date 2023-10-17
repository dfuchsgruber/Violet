/* 
 * File:   bg.h
 * Author: Domi
 *
 * Created on 25. Juni 2016, 16:57
 */

#ifndef BG_H
#define	BG_H
#include "types.h"
#include "text.h"
#include "vram.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        u32 bg_id : 2;
        u32 char_base : 2;
        u32 map_base : 5;
        u32 size : 2;
        u32 color_mode : 1;
        u32 priority : 2;
    } bg_config;

    /**
     * Sets all four bgs up according to the configurations passed.
     * @param tile_mode Tile mode to use
     * @param bg_configs Pointer to the configurations for each bg
     * @param config_cnt The number of configurations passed
     */
    void bg_setup(u8 tile_mode, const bg_config *configs, u8 config_cnt);

    /**
     * Applies configurations to a bg.
     * @param bgid The id of the bg to apply configurations to
     * @param charbase The charbase bits of the bg
     * @param mapbase The mapbase bits of the bg
     * @param size The size bits of the bg
     * @param colmode The colmode bit of the bg
     * @param priority The priority of the bg
     * @param mosaic The mosaic bit of the bg
     * @param unkown TODO
     */
    void apply_bg_configs(u8 bgid, u8 charbase, u8 mapbase, u8 size, u8 colmode, u8 priority,
        u8 mosaic, u8 unkown);

    /**
     * Updates the bg settings and sets the bg to visible in the next frame.
     * @param bgid The background to update and show
     */
    void bg_update_and_show(u8 bgid);


#define BG_COPY_TILESET 1
#define BG_COPY_TILEMAP 2

    /**
     * Appends a request to the bg vram copy queue. The data will be copied to the requested
     * destination in the next frame by the DMA.
     * @param bgid The bg id to target
     * @param src Source data (uncompressed)
     * @param size Source data size
     * @param offset Offset from the destination in bytes
     * @param mode Target either the tileset (BG_COPY_TILESET) or tilemap (BG_COPY_TILEMAP)
     */
    void bg_copy_vram(u8 bgid, const void* src, u16 size, u16 offset, u8 mode);


    /**
     * Returns the tilemap associated with a background.
     * @param bgid The bg id to target
     * @return Pointer to the tilemap
     */
    bg_tile* bg_get_tilemap(u8 bgid);

    /**
     * Resets all bgs
     * @param unkown TODO (usually 0)
     */
    void bg_reset(u8 unkown);
    
    /**
     * @brief Resets the bg cntrl IO registers and displacements for all backgrounds
     * 
     */
    void bg_reset_control_and_displacement();

    /**
     * Synchronizes a bg with its dispcntrl and makes it visible
     * @param bg_id The id of the bg to target
     */
    void bg_sync_display_and_show(u8 bg_id);

    /**
     * Makes a bg invisible
     * @param The bg id
     */
    void bg_hide(u8 bg_id);

    /**
     * Synchronizes the display control of all bgs with their respective settings
     */
    void bg_display_sync();

    /**
     * Sets the virutal tilemap of a bg
     * @param bg_id Id of the bg
     * @param tilemap The tilemap to set
     */
    void bg_set_tilemap(u8 bg_id, void* tilemap);

    /**
     * Sets the virtual bg tilemap displacement
     * @param bg_id the bg id
     * @param value the displacement
     * @param mode the tile mode
     */
    void bg_virtual_map_displace(u8 bg_id, u16 value, int mode);

    /**
    * Sets the virtual bg tileset displacement
    * @param bg_id the bg id
    * @param value the displacement
    * @param mode the tile mode
    */
    void bg_virtual_set_displace(u8 bg_id, u16 value, int mode);

    /**
     * Pushes a request to copy the virtual bg tilemap to vram
     * To that end, the active vblank callback should call `bg_virtual_sync_reqeust_proceed`
     * @param bg_id the bg id
     */
    void bg_virtual_sync_reqeust_push(u8 bg_id);

    /**
     * @brief Resets all copy requests for bg syncs.
     * 
     */
    void bg_vritual_sync_reset();

    /**
     * Syncs a bg with its virutal settings
     * @param bg_id the bg id
     */
    void bg_virtual_sync(u8 bg_id);

    /**
     * Decompresses and loads a resource to the vram of a bg
     * @param bg_id the bg id
     * @param src the lz77 compressed source
     * @param size the size (uncompressed)
     * @param offset displacement (vertical)
     * @param is_tilemap if the resource is a tilemap (if false it is treated as tileset)
     * @return TODO
     */
    int bg_decompress_vram(u8 bg_id, const void *src, size_t size, u16 offset,
        bool is_tilemap);

    /**
     * Copies a graphic to the tileset of a bg.
     * @param bg_idx the bg 
     * @param src the tiles to copy
     * @param size how many bytes to copy
     * @param offset where in the charbase to place the tiles
     **/
    void bg_load_tileset(u8 bg_idx, const void *src, size_t size, u16 offset);

    /**
     * Fills a bg's virtual tilemap with a tile
     * @param bg_idx the bg to fill
     * @param tile with which tile to fill
     * @param x upper left x coordiante
     * @param y upper left y coordinate
     * @param w width of the rectangle to fill
     * @param h height of the rectangle to fill
     * @param pal the palette idx each tile is associated with
     **/
    void bg_fill_map_with_rectangle(u8 bg_idx, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);

    /**
     * Copies data to a rectangle on a bg
     * @param bg_idx to which bg to copy to
     * @param src the data to copy
     * @param x upper left x coordinate of the rectangle
     * @param y upper left y coordiante of the rectangle
     * @param w width of the rectangle
     * @param h height of the rectangle
     **/
    void bg_copy_rectangle(u8 bg_idx, const u16 *src, u8 x, u8 y, u8 w, u8 h);

    /**
     * General purpose free memory ?
     */
    extern u8 gp_tmp_buf[];

    enum
    {
        BG_ATTR_CHARBASEINDEX = 1,
        BG_ATTR_MAPBASEINDEX = 2,
        BG_ATTR_SCREENSIZE = 3,
        BG_ATTR_PALETTEMODE = 4,
        BG_ATTR_MOSAIC = 5,
        BG_ATTR_WRAPAROUND = 6,
        BG_ATTR_PRIORITY = 7,
        BG_ATTR_MAPSIZE = 8,
        BG_ATTR_BGTYPE = 9,
        BG_ATTR_BASETILE = 10
    };

    /**
     * Sets a bg attribute. Use bg_sync_display_and_show to apply the changes.
     * @param bg_idx the bg to affect
     * @param attribute which attribute to set
     * @param value to which value to set the attribute
     **/
    void bg_set_attribute(u8 bg_idx, u8 attribute, u8 value);

    /**
     * Copies all request for copying bg virtual tilemaps to vram. This should be called in the cb1 callback.
     **/
    void bg_virtual_sync_reqeust_proceed();

    /**
     * @brief Resets all IO scroll registers for bgs to 0
     * 
     */
    void bg_reset_scroll();

#ifdef	__cplusplus
}
#endif

#endif	/* BG_H */

