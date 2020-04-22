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

    #define TBOX_FONT_STD 2
    #define TBOX_FONT_BRAILLE 6

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

#define ITOA_NO_PADDING 0
#define ITOA_PAD_SPACES 1
#define ITOA_PAD_ZEROS 2

    /**
     * Transforms an integer into a string
     * @param dst Destination of the string
     * @param value The value to transform
     * @param mode how to pad the string
     * @param num_chars the maximal number of characters the string should have. If the number
     * exceeds this value, '?' is displayed
     * @return dst
     */
    u8* itoa(u8* dst, int value, int padding, u8 num_chars);

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
     * Checks if a printer is active for a certain box.
     * @param box_idx the box to check
     * @return if a text printer is active
     **/
    bool tbox_printer_is_active(u8 box_idx);

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
    void tbox_print_string(u8 box_id, u8 font, u16 x, u16 y, u8 letter_spacing,
        u8 line_spacing, tbox_font_colormap* color_map, u8 speed, u8* str);

    /**
     * Initializes multiple boxes on the virtual background
     * @param boxes Array of tboxdata instances terminated by a tbox on bg 0xFF
     */
    void tbox_sync_with_virtual_bg_and_init_all(tboxdata *boxes);

    /**
     * Returns the speed value used for tboxes according to the user settings.
     * @return the speed value used for tboxes according to the user settings
     */
    u8 tbox_get_set_speed();

    /**
     * Uses a big callback to display a text and sets the callback function to a continuation
     * afterwards.
     * @param callback_idx the callback to use
     * @param box_idx the box to display the message in
     * @param border_start_tile the tile the border is located at
     * @param border_palette the palette is located at
     * @param font the font to display the message in
     * @param speed the speed to display the message in
     * @param text the text to display
     * @param continuation the function the callback executes after the text has been printed
     */
    void tbox_print_string_and_continue(u8 callback_idx, u8 box_idx, u16 border_start_tile,
        u8 border_palette, u8 font, u8 speed, const u8 *text, void (*continuation)(u8));

    /**
     * Removes a dialog textbox.
     * @param tbox_idx the index of the textbox
     * @param copy_to_vram if the changes shall trigger a vram copy request
     */
    void tbox_remove_dialog(u8 tbox_idx, u8 copy_to_vram);

#define TBOX_MESSAGE_NUM_TILES 0x28
    /**
     * Loads tileset and palette of the standard textbox gfx for messages.
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses
     */
    void tbox_message_init(u8 box_id, u16 set_displace, u16 dst_color);

#define TBOX_CONTEXT_BORDER_NUM_TILES 0x12 // 0x12 Tiles are copied but it seems only 0x8 are used

    /**
     * Initializes the border of a textbox for context menus with the border according to the
     * style set by the player.
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses
     */
    void tbox_context_init_border_set_style(u8 box_id, u16 set_displace, u16 dst_color);

#define TBOX_MESSAGE_BORDER_NUM_TILES 0x8
    /**
     * Initializes the border of a textbox to display messages with default style.
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses (probably wrong tho)
     */
    void tbox_message_init_border(u8 box_id, u16 set_displace, u16 dst_color);

    /**
     * Draws the border of a textbox
     * @param box_id The id of the textbox
     * @param tile the tile index the border uses
     * @param dst_pal The palette the border uses
     */
    void tbox_border_draw(u8 box_id, u16 tile, u8 dest_pal);

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
     * Frees a textbox
     * @param box_id The id of the textbox
     */
    void tbox_free_2(u8 box_idx);

    /**
     * Flushes the tilest and border of a textbox.
     * @param box_idx the box to flush
     * @param tile the tile pattern to flush with
     **/
    void tbox_flush_all(u8 box_idx, u8 tile);

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
     * @param x_offset the x displacement
     * @param y_offset the y displacement
     */
    void tbox_draw_type_icon_by_type_p1(u8 box_id, u8 type_p1, u16 x_offset, u16 y_offset);

    /**
     * Clears the bottom line of the tbox (sets tile to color 0)
     * @param box_id the box id to clear
     */
    void tbox_clear_bottom_line(u8 box_id);

    /**
     * Loads palette and tiles for a message textbox (i.e. with border style from options)
     **/
    void tbox_load_message_gfx_and_pal();

    /**
     * Prints a box (tiles and tilemap) that uses a normal frame.
     * @param tbox_idx the box to print
     * @param copy_to_vram if the data should be copied to vram or only be stored in the tbox buffer
     **/
    void tbox_print_std_frame(u8 tbox_idx, bool copy_to_vram);

    /**
     * Copies the data of a tbox to the vram.
     * @param tbox_idx the box to copy the data of
     * @param mode if the tileset and / or tilemap will be copied
     **/
    void tbox_copy_to_vram(u8 tbox_idx, u8 mode);

    /**
     * Adds a new text printer with certain parameters.
     * @param tbox_idx the box to print in
     * @param font the font to use
     * @param text the text to print
     * @param x_offset the horizontal offset
     * @param y_offset the vertical offset
     * @param speed the speed in which to print
     * @param callback the callback for the printer after each char is printed
     **/
    void tbox_print_string_parametrized(u8 tbox_idx, u8 font, u8 *text, u16 x_offset, u16 y_offset, u8 speed, void (*callback)(void*, u16));
    
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

    /**
     * Transforms the type of a pokemon into a string
     * @param dst destination for the string
     * @param type the type to load
     * @return first character after the string ends
     */
    u8 *typetoa(u8 *dst, u8 type);

    /**
     * Transforms the type of a pokemon into a string that has at most 8 characters. No
     * abbreviations.
     * @param dst destination for the string
     * @param type the type to load
     * @return first character after the string ends
     */
    u8 *typetoa_long(u8 *dst, u8 type);

    /**
     * Transforms null pointers to an empty string.
     * @param src the string to check
     * @return if src was NULL, an empty string is returned. Otherwise, src is kept as is
     **/
    u8 *str_null_to_empty(u8 *src);

    /**
     * Gets a normal string placeholder (such as PLAYER, RIVAL, ...)
     * @param placeholder which placeholder to get
     * @return the string
     **/
    u8 *string_get_placeholder(u8 placeholder);

    /**
     * Gets the name of a trainer.
     * @param trainer_idx the idx of the trainer to get the name of
     * @return the name of the trainer
     **/
    u8 *trainer_get_name(u16 trainer_idx);

    /**
     * Checks if the overworld textbox is a sign
     * @return if the overworld textbox is a sign
     **/
    bool overworld_tbox_is_sign();


    /**
     * Loads gfx and palette of a signpost textbox
     **/
    void tbox_load_sign_gfx_and_pal();

    enum {
        TBOX_ATTRIBUTE_BG = 0,
        TBOX_ATTRIBUTE_X,
        TBOX_ATTRIBUTE_Y,
        TBOX_ATTRIBUTE_WIDTH,
        TBOX_ATTRIBUTE_HEIGHT,
        TBOX_ATTRIBUTE_PAL,
        TBOX_ATTRIBUTE_TILE,
        TBOX_ATTRIBUTE_VIRTUAL_TILESET,
    };

    /**
     * Gets an attribute of a textbox
     * @param tbox_idx the textbox to get an attribute of
     * @param attribute which attribute to get
     **/
    int tbox_get_attribute(u8 tbox_idx, u8 attribute);

    /**
     * Blits pixels from a source bitmap to a textbox.
     * @param tbox_idx the tbox to blit into
     * @param src the source bitmap
     * @param src_x upper_left x coordinate of the rectangle to copy in the source image
     * @param src_y upper_left y coordinate of the rectangle to copy in the source image
     * @param src_width width of the source image
     * @param src_height height of the source image
     * @param dst_x upper left x coordinate of where to put the bitmap in the tbox
     * @param dst_y upper left y coordiante of where to put the bitmap in the tbox
     * @param src_width width of the rectangle to copy
     * @param src_height height of the rectangle to copy
     **/
    void tbox_blit(u8 tbox_idx, u8 *src, u16 src_x, u16 src_y, u16 src_width, u16 src_height, u16 dst_x,
              u16 dst_y, u16 width, u16 height);
    
    /**
     * Fills a rectangle of a textbox.
     * @param box_idx the box to fill
     * @param fill_value the value with which to fill (4-bit)
     * @param x the x coordiante
     * @param y the y coordiante
     * @param width the width of the rectangle to fill
     * @param height the height of the rectangle to fill
     **/
    void tbox_fill_rectangle(u8 box_idx, u8 fill_value, u16 x, u16 y, u16 width, u16 height);

    #define BLIT_TRANSPARENT_COLOR_NONE 0xFF

    /**
     * Blits pixels from a source bitmap to a textbox, using an arbitrary color that is ignored (i.e. transparent).
     * @param tbox_idx the tbox to blit into
     * @param src the source bitmap
     * @param src_x upper_left x coordinate of the rectangle to copy in the source image
     * @param src_y upper_left y coordinate of the rectangle to copy in the source image
     * @param src_width width of the source image
     * @param src_height height of the source image
     * @param dst_x upper left x coordinate of where to put the bitmap in the tbox
     * @param dst_y upper left y coordiante of where to put the bitmap in the tbox
     * @param src_width width of the rectangle to copy
     * @param src_height height of the rectangle to copy
     * @param transparent_color the color idx to ignore, i.e. have it transparent
     **/
    void tbox_blit_with_transparent_color(u8 tbox_idx, u8 *src, u16 src_x, u16 src_y, u16 src_width, u16 src_height, u16 dst_x,
              u16 dst_y, u16 width, u16 height, u8 transparent_color);

    /**
     * Removes the task of the overworld textbox, if present.
     **/
    void overworld_tbox_remove_task();

    /**
     * Sets the sign flag for the overworld textbox, i.e. makes it such that it displayed in the style of sign
     **/
    void overworld_tbox_set_sign();

    /**
     * Loads the standard textbox palette to a certain color.
     * @param offset to which color to load it at.
     **/
    void tbox_load_std_frame_palette_at(u16 offset);

    extern u8 overworld_tbox_state;

    extern u8 strbuf[];
    extern u8 buffer0[];
    extern u8 buffer1[];
    extern u8 buffer2[];
    extern u8 str_types[][7];
    extern u8 str_types_long[][8];

#ifdef	__cplusplus
}
#endif

#endif	/* TEXT_H */

