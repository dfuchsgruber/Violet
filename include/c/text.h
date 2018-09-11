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
    

    /**
     * Returns the amount of digits a number in base 10
     * @param value The value to calculate the number of digits in base 10
     * @return The number of digits in base 10
     */
    u8 digits_dec(int value);

    /**
     * Transforms an integer into a string
     * @param dst Destination of the string
     * @param value The value to transform
     * @param mode Mode of transformation (base)
     * @param charlength Size in characters
     * @return dst
     */
    u8* itoa(u8* dst, int value, u8 mode, u8 charlength);

    extern tbox tboxes[];
    

    /**
     * Frees all textboxes.
     */
    void tbox_free_all();


#define TBOX_SYNC_MAP 1
#define TBOX_SYNC_SET 2
#define TBOX_SYNC_MAP_AND_SET 3

    /**
     * Synchronizes tilemap and/or tileset of a textbox
     * @param box_id The id of the textbox
     * @param sync_type What should be synchronized
     */
    void tbox_sync(u8 box_id, u8 sync_type);
    
    /**
     * Creates a new textbox data instance at given memory
     * @param target The memory to instanciate the textbox in
     * @param bg_id Bg to show textbox on
     * @param x X-Coordinate of the textbox (in tiles)
     * @param y Y-Coordinate of the textbox (in tiles)
     * @param w Width of the textbox (in tiles)
     * @param h Height of the textbox (in tiles)
     * @param pal Palette id the textbox uses (0-15)
     * @param start_tile The first tile on the bg tileset the textbox uses
     * @return target
     */
    tboxdata* tbox_data_new(tboxdata *target, u8 bg_id, u8 x, u8 y, u8 w, u8 h, u8 pal,
        u16 start_tile);

    /**
     * Flushes the tileset of a textbox with a pixel value (4-Bit)
     * @param box_id The id of the textbox to flush the tileset
     * @param tile 8-Bit value (two 4-Bit values) to set the tileset pixels to
     */
    void tbox_flush_set(u8 box_id, u8 tile);

    /**
     * Flushes the tilemap of a textbox with zeroes
     * @param box_id The id of the textbox to flush the tilemap
     */
    void tbox_flush_map(u8 box_id);

    /**
     * Calculates the width (in pixels) of a string
     * @param font Font of the string (usually 2)
     * @param str The string to determine width of
     * @param unkown Usually set to zero
     * @return The string width in pixels
     */
    u8 string_get_width(u8 font, const u8 *str, s16 unkown);

    /**
     * Creates a new textbox
     * @param boxdata The tboxdata instance to create the textbox from
     * @return The id of the newly created textbox
     */
    u8 tbox_new(tboxdata *boxdata);

    /**
     * Draws the tilemap of a textbox on the corresponding bg
     * @param box_id The id of the textbox
     */
    void tbox_tilemap_draw(u8 box_id);

    typedef struct{
      u8 background;
      u8 body;
      u8 edge;
      u8 shadow;
    } tbox_font_colormap;

    /**
     * Prints a string on a textbox
     * @param box_id Textbox id to print string on
     * @param font Font to print text in (usually 2)
     * @param x Horizontal pixel displacement
     * @param y Vertical pixel displacement
     * @param line_spacing_upper Line spacing in pixels
     * @param line_spacing_lower Line spcaing in pixels (no idea why 2 times)
     * @param color_map Maps components of the string to color indices of the textboxes palette
     * @param print_charabase If 0 tileset is printed, if 0xFF only cached? (no idea honestly...)
     * @param str The string to print
     */
    void tbox_print_string(u8 box_id, u8 font, u16 x, u16 y, u8 line_spacing_upper,
        u8 line_spacing_lower, tbox_font_colormap* color_map, u8 print_charbase, u8* str);

    /**
     * Initializes multiple boxes on the virtual background
     * @param boxes Array of tboxdata instances terminated by a tbox on bg 0xFF
     */
    void tbox_sync_with_virtual_bg_and_init_all(tboxdata *boxes);

    /**
     * Initializes the border of a textbox
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses (probably wrong tho)
     */
    void tbox_border_init(u8 box_id, u16 set_displace, u16 dst_color);

    /**
     * Draws the border of a textbox
     * @param box_id The id of the textbox
     * @param map_displace Offset of border in tiles (i.e. on the tilemap)
     * @param dst_pal The palette the border uses
     */
    void tbox_border_draw(u8 box_id, u16 map_displace, u8 dest_pal);

    /**
     * Flushes the border of a textbox
     * @param box_id The id of the textbox
     */
    void tbox_border_flush(u8 box_id);
    
    /**
     * Frees a textbox
     * @param box_id The id of the textbox
     */
    void tbox_free(u8 box_id);

    /**
     * Decrypts a string (i.e. buffers and constants)
     * @param dst Memory where to place the decrypted string at
     * @param src The undecrypted string
     */
    void string_decrypt(u8* dst, u8* src);

    /**
     * Executes all textbox related requests for the next frame
     */
    void tbox_proceed();

    /**
     * Flushes and frees a textbox if it is present
     * @param box_id_ptr offset of the tbox id
     */
    void tbox_flush_and_free_if_present(u8 *box_id_ptr);

    /**
     * Draws the icon for a type on a textbox
     * @param box_id the box id
     * @param type_p1 the type to draw
     * @param additional the x displacement
     * @param y_pixel the y displacement
     */
    void tbox_draw_type_icon_by_type_p1(u8 box_id, u8 type_p1, u16 additional, u16 y_pixel);

    /**
     * Clears the bottom line of the tbox (sets tile to color 0)
     * @param box_id the box id to clear
     */
    void tbox_clear_bottom_line(u8 box_id);

    /**
     * Concatenates two strings (appends second to first string)
     * @param first the first string
     * @param second the second string
     * @return the offset of the terminating byte of the first string
     */
    u8* strcat(u8* first, u8* second);

    /**
     * Copies a string
     * @param dst the destination
     * @param src the source string
     * @return the destination offset
     */
    u8* strcpy(u8* dst, u8* src);

    extern u8 strbuf[];
    extern u8 buffer0[];

#ifdef	__cplusplus
}
#endif

#endif	/* TEXT_H */

