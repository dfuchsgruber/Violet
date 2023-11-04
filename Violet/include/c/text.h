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

    enum {
        TBOX_FONT_STD = 2,
        TBOX_FONT_UNOWN = 5,
        TBOX_FONT_BRAILLE = 6,
    };

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
     * @brief Replaces all occurences of one character with another.
     * 
     * @param src Source string.
     * @param dst Destination for the new string.
     * @param find The character to replace.
     * @param replace The character to replace with.
     * @return u8* The destination (for command chaining)
     */
    u8 *string_replace(const u8 *src, u8 *dst, u8 find, u8 replace);
    
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

    #define PIXEL_FILL(col_idx) (((col_idx) & 0xF) | (((col_idx) & 0xF) << 4))

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
     * @brief Draws a frame around a box with the given box tiles at a start_tile and the pal idx
     * 
     * @param tbox_idx the tbox to draw the border of
     * @param copy_to_vram if tiles should be copied to vram
     * @param start_tile to which tile to copy
     * @param pal_idx the pal idx
     */
    void tbox_draw_std_frame_by_base_tile_and_pal(u8 tbox_idx, u8 copy_to_vram, u16 start_tile, u8 pal_idx);

    /**
     * Calculates the width (in pixels) of a string
     * @param font Font of the string (usually 2)
     * @param str The string to determine width of
     * @param letter_spacing Additional letter spacing
     * @return The string width in pixels
     */
    u8 string_get_width(u8 font, const u8 *str, s16 letter_spacing);

    /**
     * Creates a new textbox
     * @param boxdata The tboxdata instance to create the textbox from
     * @return The id of the newly created textbox
     */
    u8 tbox_new(const tboxdata *boxdata);

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
        u8 line_spacing, const tbox_font_colormap *color_map, u8 speed, const u8 *str);

    #define TBOX_SETUP_TAIL {.bg_id = 0xFF}

    /**
     * Initializes multiple boxes on the virtual background
     * @param boxes Array of tboxdata instances terminated by a tbox on bg 0xFF
     */
    void tbox_sync_with_virtual_bg_and_init_all(const tboxdata *boxes);

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
     * Proceeds a textbox printer and returns if the printing is active.
     * @param tbox_idx the box to proceed
     * @return if the printer in this box is active
     **/
    bool tbox_printer_proceed_and_is_active(u8 tbox_idx);

    /**
     * Uses a big callback to display a text on tbox 0 and bg0. Also loads the gfx beforehand to tile 256 and the pal to slot 15.
     * @param callback_idx the callback to use
     * @param font the font
     * @param str the text to display
     * @param continuation the function the callback executes once the text has been printed
     **/ 
    void tbox_load_gfx_and_print_string_on_bg0_and_continue(u8 callback_idx, u8 font, const u8 *str, void (*continuation)(u8));

    /**
     * Removes a tbox that is initialized with frame type "message" (i.e. it clears the actual text and the frame around it)
     * @param tbox_idx the index of the textbox
     * @param copy_to_vram if the changes shall trigger a vram copy request
     */
    void tbox_clear_message(u8 tbox_idx, u8 copy_to_vram);

#define TBOX_FRAME_STD_NUM_TILES 9
    /**
     * Initializes the border of a textbox with a standard grey frame
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses
     */
    void tbox_init_frame_std(u8 box_id, u16 set_displace, u16 dst_color);


#define TBOX_FRAME_STD_BASE_TILE 0x214
#define TBOX_FRAME_STD_PAL_IDX 14

    /**
     * Loads gfx and palette of the standard border to a tbox at the standard tile and palette position.
     * @param box_idx The tbox to load the border to
     * @param copy_to_vram Whether the loaded gfx is to be synched with vram by enqueuing a copy request
     **/
    void tbox_init_frame_std_at_default_tile_and_pal(u8 box_idx, bool copy_to_vram);
    

#define TBOX_FRAME_SET_STYLE_NUM_TILES 9

    /**
     * Initializes the border of a textbox for context menus with the border according to the
     * style set by the player.
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses
     */
    void tbox_init_frame_set_style(u8 box_id, u16 set_displace, u16 dst_color);

#define TBOX_FRAME_MESSAGE_NUM_TILES 20
    /**
     * Initializes the border of a textbox to display messages with default style.
     * @param box_id The id of the textbox
     * @param set_displace Offset of the border in pixels
     * @param dst_color The first color the border uses (probably wrong tho)
     */
    void tbox_init_frame_message(u8 box_id, u16 set_displace, u16 dst_color);

    /**
     * @brief Flushes the set of a tbox, draws its tilemap and the frame at a given position for a message type frame (`TBOX_FRAME_MESSAGE_NUM_TILES` tiles)
     * 
     * @param box_idx in which tbox to draw
     * @param copy_to_vram if the changes should be copied to vram
     * @param base_tile the tile where the frame lies
     * @param pal_idx the pal used by the frame
     */
    void tbox_draw_frame_message_and_flush_set(u8 box_idx, u8 copy_to_vram, u16 base_tile, u16 pal_idx);

    /**
     * Draws the border of a textbox
     * @param box_id The id of the textbox
     * @param tile the tile index the border uses
     * @param dst_pal The palette the border uses
     */
    void tbox_frame_draw_outer(u8 box_id, u16 tile, u8 dest_pal);

    /**
     * Flushes the tilemap of a tbox and its frame (the 1x1 frame around it)
     * @param box_id The id of the textbox
     */
    void tbox_flush_map_and_frame(u8 box_id);
    
    /**
     * Frees a textbox
     * @param box_id The id of the textbox
     */
    void tbox_free(u8 box_id);

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
    void string_decrypt(u8* dst, const u8* src);

    /**
     * Executes all textbox related requests for the next frame
     */
    void tbox_proceed();

    /**
     * Flushes and frees a textbox if it is present
     * @param box_id_ptr offset of the tbox id
     */
    void tbox_flush_and_free_if_present(u8 *box_id_ptr);


    typedef struct {
        u8 width;
        u8 height;
        u16 offset;
    } move_info_gfx_t;

    enum {
        MOVE_INFO_NONE = 0,
        MOVE_INFO_TYPE_BASE = 1,
        MOVE_INFO_TYPE = 19,
        MOVE_INFO_POWER,
        MOVE_INFO_ACCURACY,
        MOVE_INFO_PP,
        MOVE_INFO_EFFECT,
        MOVE_INFO_CATEGORY,
        MOVE_INFO_PHYSICAL,
        MOVE_INFO_SPECIAL,
        MOVE_INFO_STATUS,
    };

    /**
     * Draws the icon for a type on a textbox
     * @param box_id the box id
     * @param type_p1 the type to draw
     * @param x_offset the x displacement
     * @param y_offset the y displacement
     */
    void tbox_blit_move_info_icon(u8 box_id, u8 type_p1, u16 x_offset, u16 y_offset);

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

    #define TBOX_COPY_TILEMAP 1
    #define TBOX_COPY_TILESET 2

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
    void tbox_print_string_parametrized(u8 tbox_idx, u8 font, const u8 *text, u16 x_offset, u16 y_offset, u8 speed, void (*callback)(void*, u16));
    
    /**
     * Concatenates two strings (appends second to first string)
     * @param first the first string
     * @param second the second string
     * @return the offset of the terminating byte of the first string
     */
    u8* strcat(u8* first, const u8* second);

    /**
     * Copies a string
     * @param dst the destination
     * @param src the source string
     * @return the destination offset
     */
    u8* strcpy(u8* dst, const u8* src);

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
    const u8 *str_null_to_empty(const u8 *src);

    /**
     * Gets a normal string placeholder (such as PLAYER, RIVAL, ...)
     * @param placeholder which placeholder to get
     * @return the string
     **/
    const u8 *string_get_placeholder(u8 placeholder);

    /**
     * Gets the name of a trainer.
     * @param trainer_idx the idx of the trainer to get the name of
     * @return the name of the trainer
     **/
    const u8 *trainer_get_name(u16 trainer_idx);

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
    void tbox_blit(u8 tbox_idx, const u8 *src, u16 src_x, u16 src_y, u16 src_width, u16 src_height, u16 dst_x,
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
    void tbox_blit_with_transparent_color(u8 tbox_idx, const u8 *src, u16 src_x, u16 src_y, u16 src_width, u16 src_height, u16 dst_x,
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

    /**
     * Creates a new tbox on a given box measure.
     * @param x upper left coordinate
     * @param y upper left coordinate
     * @param width the width of the box
     * @param height the height of the box
     * @return the idx of the tbox created
     **/
    u8 tbox_new_by_box(u8 x, u8 y, u8 width, u8 height);

    /**
     * Prints money into a tbox
     * @param tbox_idx in which box to draw the money
     * @param start_tile first tile to use
     * @param pal_idx which palette to use
     * @param amount the amount to print
     **/
    void tbox_print_money(u8 tbox_idx, u16 start_tile, u8 pal_idx, u32 amount);

    enum
    {
        FONT_ATTRIBUTE_MAX_LETTER_WIDTH,
        FONT_ATTRIBUTE_MAX_LETTER_HEIGHT,
        FONT_ATTRIBUTE_LETTER_SPACING,
        FONT_ATTRIBUTE_LINE_SPACING,
        FONT_ATTRIBUTE_UNKNOWN,   // dunno what this is yet
        FONT_ATTRIBUTE_COLOR_FOREGROUND,
        FONT_ATTRIBUTE_COLOR_BACKGROUND,
        FONT_ATTRIBUTE_COLOR_SHADOW
    };

    /**
     * @brief Gets an attribute associated with a font
     * 
     * @param font the font of which to get attributes
     * @param attribute the attirbute to get
     * @return u8 the value
     */
    u8 font_get_attribute(u8 font, u8 attribute);

    /**
     * @brief Prints an amount of money in a box and also draws the frame around the box
     * 
     * @param tbox_idx the box to print money in
     * @param frame_start_tile the start tile of the frame
     * @param frame_pal_idx the pal idx of the frame
     * @param money the amount of money to print
     */
    void tbox_print_money_and_frame(u8 tbox_idx, u16 frame_start_tile, u8 frame_pal_idx, u32 money);

    /**
     * @brief Updates the money amount displayed in a box drawn by `tbox_print_money_and_frame`
     * 
     * @param tbox_idx the tbox to update
     * @param amount the new amount
     * @param font in which font (standard is 0)
     */
    void tbox_update_money(u8 tbox_idx, u32 amount, u8 font);

    /**
     * @brief Prints a money string that is right-aligned at an offset in the tbox
     * 
     * @param tbox_idx the box in which to print
     * @param x horizontal offset of the upper left corner of the (space-padded) money quantity
     * @param y vertical offset of the upper left corner of the (space-padded) money quantity
     * @param amount the amount to print
     * @param speed in which speed to print
     */
    void tbox_print_money_at(u8 tbox_idx, u8 x, u8 y, u32 amount, u8 speed);

    /**
     * @brief Prints a string in a tbox with explicitly set font colors
     * Line and letter spacing are set to 1, x is set to 0 and y to 1
     * 
     * @param tbox_idx the box to print in
     * @param font the font in which to print
     * @param str the text to print
     * @param speed with which speed
     * @param callback a printer callback
     * @param color_body the color of the text body
     * @param color_background the color of the text background
     * @param shadow_color the color of the text shadow
     * @return u16 
     */
    u16 tbox_print_string_set_font_colors_and_spacing_1(u8 tbox_idx, u8 font, const u8 *str, u8 speed, 
        void (*callback)(tbox*, u16), u8 color_body, u8 color_background, u8 shadow_color);

    /**
     * @brief Initializes the frame of a message textbox and draws the corresponding tilemap
     * 
     * @param tbox_idx the tbox to initilaize
     * @param copy_to_vram if the changes should be copied to the vram
     */
    void tbox_init_frame_message_and_draw_tilemap(u8 tbox_idx, bool copy_to_vram);

    extern u8 overworld_tbox_state;

    typedef struct {
        u8 can_a_b_speed_up_printing:1;
        u8 use_alternate_down_arrow:1;
        u8 use_auto_scroll:1;
        u8 force_mid_text_speed:1;
    } tbox_printer_flags_t;

    extern tbox_printer_flags_t tbox_printer_flags;

    extern u8 strbuf[];
    extern u8 buffer0[];
    extern u8 buffer1[];
    extern u8 buffer2[];
    extern const u8 str_types[][7];
    extern const u8 str_types_long[][8];

    enum {
        PERSON_NAME_MALE = 0,
        PERSON_NAME_FEMALE = 1,
    };
    extern const u8 person_names[2][128][12];

#ifdef	__cplusplus
}
#endif

#endif	/* TEXT_H */

