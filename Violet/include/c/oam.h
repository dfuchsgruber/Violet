#ifndef H_OAMS
#define H_OAMS


#define GFX_ANIM_VFLIP 0x80
#define GFX_ANIM_HFLIP 0x40

#define GFX_ANIM_LOOP_START 0xFFFC
#define GFX_ANIM_JUMP_LOOP_START 0xFFFD
#define GFX_ANIM_JUMP 0xFFFE
#define GFX_ANIM_END 0xFFFF

#define ATTR0_ROTSCALE 0x100
#define ATTR0_DSIZE 0x200
#define ATTR0_OBJDISABLE 0x200
#define ATTR0_MODE_SEMI_NORMAL 0
#define ATTR0_MODE_SEMI_TRANSPARENT 0x400
#define ATTR0_MODE_OBJ_WINDOW 0x600
#define ATTR0_MOSAIC 0x1000
#define ATTR0_COLMODE 0x2000
#define ATTR0_SHAPE_SQUARE 0
#define ATTR0_SHAPE_HORIZONTAL 0x4000
#define ATTR0_SHAPE_VERTICAL 0x8000

#define ATTR1_HFLIP 0x1000
#define ATTR1_VFLIP 0x2000
#define ATTR1_SIZE_8_8 0
#define ATTR1_SIZE_16_8 0
#define ATTR1_SIZE_8_16 0
#define ATTR1_SIZE_16_16 0x4000
#define ATTR1_SIZE_32_8 0x4000
#define ATTR1_SIZE_8_32 0x4000
#define ATTR1_SIZE_32_32 0x8000
#define ATTR1_SIZE_32_16 0x8000
#define ATTR1_SIZE_16_32 0x8000
#define ATTR1_SIZE_64_64 0xC000
#define ATTR1_SIZE_64_32 0xC000
#define ATTR1_SIZE_32_64 0xC000

#define ATTR2_PRIO(x) (x<<10)

#define GRAPHIC_SIZE_4BPP(width, height) (width * height / 2)
#define GRAPHIC_SIZE_8BPP(width, height) (width * height)

struct oam_object;
typedef struct oam_object oam_object;
struct gfx_frame;
typedef struct gfx_frame gfx_frame;

typedef struct {
    const void *pal;
    u16 tag;
    u16 field_6;
} palette;

typedef struct gfx_frame {
    u16 data;
    u16 duration;
} gfx_frame;

typedef struct graphic {
    const void *sprite;
    u16 size;
    u16 tag;
} graphic;

#define ROTSCALE_ANIM_DURATION_SET_TO_VALUES 0
#define ROTSCALE_ANIM_LOOP_START 0x7FFC
#define ROTSCALE_ANIM_JUMP_LOOP_START 0x7FFD
#define ROTSCALE_ANIM_JUMP 0x7FFE
#define ROTSCALE_ANIM_END 0x7FFF

typedef union rotscale_frame {
  struct {
    s16 affine_x_value;
    s16 affine_y_value;
    u8 rotation;
    u8 duration;
    u16 field_6;
  } affine;
  struct {
    u16 command;
    u16 parameter;
    u16 field_4;
    u16 field_6;
  } command;
} rotscale_frame;

typedef struct sprite {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 rotscale;
} sprite;

typedef struct {
    u16 tiles_tag;
    u16 pal_tag;
    sprite *oam;
    gfx_frame **animation;
    graphic *graphics;
    rotscale_frame **rotscale;
    void (*callback)(oam_object *self);
} oam_template;

extern oam_template gp_oam_template; // Multi-use oam template

#define OAM_FLAG_ACTIVE 0x1
#define OAM_FLAG_CENTERED 0x2
#define OAM_FLAG_INVISIBLE 0x4
#define OAM_FLAG_HFLIP 0x100
#define OAM_FLAG_VFLIP 0x200
#define OAM_FLAG_GFX_ANIM_START 0x400
#define OAM_FLAG_ROTSCALE_ANIM_START 0x800
#define OAM_FLAG_GFX_ANIM_END 0x1000
#define OAM_FLAG_GFX_ROTSCALE_ANIM_END 0x2000
#define OAM_FLAG_SPRITES 0x4000

typedef struct oam_object {
    sprite final_oam;
    gfx_frame **animation_table;
    u32 *gfx_table;
    u32 *rotscale_table;
    oam_template *oam_template;
    u32 field18;
    void (*callback)(oam_object*);
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    u8 x_centre;
    u8 y_centre;
    u8 anim_number;
    u8 anim_frame;
    u8 anim_delay;
    u8 counter;
    u16 private[8];
    u16 flags;
    u16 base_tile;
    u8 sprite_idx : 6;
    u8 sprite_mode : 2;
    u8 priority_on_layer;
} oam_object;

extern oam_object oams[];

extern rotscale_frame *oam_rotscale_anim_table_null[];
extern gfx_frame *oam_gfx_anim_table_null[];

typedef struct { // Subject to change, I guess...
  u8 y_offset;
  u8 frames;
  u8 field_2;
  u8 field_3;
} sprite_coordinates_t;


extern u8 oam_rotscale_disabled;

/**
 * Allocates an rotation-scale group in the OAM RAM
 * @return The id of the allocated rotation-scale group
 */
u8 rotscale_alloc();

/**
 * Resets all oam_object objects at oams.
 */
void oam_reset();

/**
 * Creates a new oam object by forward searching the buffer for free entries
 * @param template Oam template to construct the oam object from
 * @param x X-coordinate of the oam's center
 * @param y Y-coordinate of the oam's center
 * @param prio The priority relative to other oams on the same layer (0 being lowest)
 */
u8 oam_new_forward_search(oam_template *template, s16 x, s16 y, u8 prio);

/**
 * Creates a new oam object by backward searching the buffer for free entries
 * @param template Oam template to construct the oam object from
 * @param x X-coordinate of the oam's center
 * @param y Y-coordinate of the oam's center
 * @param prio The priority relative to other oams on the same layer (0 being lowest)
 */
u8 oam_new_backward_search(oam_template * template, s16 x, s16 y, u8 prio);

/**
 * Allocates oam vram and decompresses a graphic resource into the allocated vram. Places the
 * graphic's tag in the oam vram allocation table.
 * @param graphic The graphic resource to load
 * @return The oam vram tile id that was allocated
 */
u16 oam_load_graphic(graphic*g);

/**
 * Frees allocated oam vram an oam holds but keeps the graphic's tag in the oam vram allocation
 * table.
 * @param oam The oam that holds the graphic to free
 */
void oam_free_graphic_keep_tag(oam_object* oam);

/**
 * Frees the allocated oam vram an oam (also deletes the entry in the oam vram allocation table)
 * @param oam The oam that holds the graphic to free
 */
void oam_free_graphic(oam_object* oam);

/**
 * Frees the vram allocated for a gfx tag.
 * @param tag the tag 
 **/
void oam_free_vram_by_tag (u16 tag);

/**
 * Allocates an oam palette and places a tag in the oam palette allocation table
 * @param tag Tag to identify the palette
 * @param The id of the oam palette (0-15) or 0xFF if no palette is availible
 */
u8 oam_allocate_palette(u16 tag);

/**
 * Returns the tag associated with a oam palette tag by scanning the oam palette allocation table.
 * @param pal_id The oam palette id (0-15)
 * @return The tag associated with the palette or 0xFFFF if no tag is associated with this palette
 */
u16 oam_palette_get_tag(u8 pal_id);

/**
 * Frees an allocated oam palette based on a palette tag.
 * @param tag The tag of the palette to free
 */
void oam_palette_free(u16 tag);

/**
 * Clears an oam object (but does not free resources held by the object).
 * @param oam The oam object to clear
 */
void oam_clear(oam_object* oam);

/**
 * Clears an oam object and frees all resources held by it
 * @param oam The oam object to free
 */
void oam_free(oam_object* oam);

/**
 * Returns the index of a oam graphic tag in the oam vram allocation table
 * @param tag The tag to look for.
 * @return The index in the oam vram allocation table or 0xFF if not present
 */
u8 oam_vram_allocation_table_get_index(u16 tag);

/**
 * Initializes the gfx animation of an oam object
 * @param oam The oam object whose gfx animation will be initialized
 * @param frame The frame to start the animation in
 */
void oam_gfx_anim_init(oam_object* oam, u8 frame);

/**
 * Initializes the rotation-scale animation of an oam object
 * @param oam The oam object whose rotation-scale animation will be initialized
 * @param index Animation index in the oam's rotation-scale animation table
 */
void oam_rotscale_anim_init(oam_object* oam, u8 index);

/**
 * Returns the oam palette associated with a certain tag
 * @param The palette tag to search for
 * @return The palette index or 0xFF if no match
 */
u8 oam_palette_get_index(u16 tag);

/**
 * Gets the oam vram tile associated with a graphic tag by scanning the oam vram allocation table.
 * @param tag The tag to search for
 * @return The first tile of the graphic on the oam tileset in VRAM or 0xFFFF if no match
 */
u16 oam_vram_get_tile(u16 tag);

/**
 * Allocates oam vram tiles
 * @param tiles the number of tiles to allocate
 * @return the first tile that was allocated (0xFFFF on failure)
 */
u16 oam_vram_alloc(u16 tiles);

/**
 * Adds a tile to the oam vram allocation table
 * @param tag the tag to identify the allocation entry with
 * @param tile the first allocated tile
 * @param tiles the number of tiles allocated
 */
void oam_vram_allocation_table_add(u16 tag, u16 tile, u16 tiles);

/**
 * Frees the rotation-scale group of an oam object
 * @param The oam object whose rotation-scale groups should be freed.
 */
void oam_rotscale_free(oam_object *oam);

/**
 * Sets the values of a oam rotation-scale group
 * @param id The id of the rotation-scale group
 * @param pa PA value
 * @param pb PB value
 * @param pc PC value
 * @param pd PD value
 */
void oam_rotscale_set(u8 id, u16 v0, u16 v1, u16 v2, u16 v3);

/**
 * A null callback for an oam object
 * @param self Reference to the oam object itself
 */
void oam_null_callback(oam_object *self);

/**
 * Resets the oam palette allocation table
 */
void oam_palette_allocation_reset();

/**
 * Executes all oam callbacks for the next frame
 */
void oam_proceed();

/**
 * Creates OAM RAM objects of the oam object structs and places them in the OAM RAM
 */
void oam_attributes_copy();

/**
 * Executes all oam animations for the next frame (gfx and rotscal)
 */
void oam_anim_proceed();

/**
 * Returns the index of the affine group the oam uses or 0 if the oam does not use affine
 * transformations.
 * @param o the object to get the rotscale group of
 * @return the index of the affine group or 0
 */
u8 oam_rotscale_get(oam_object *o);

/**
 * Flips an oam (i.e. turns the current flip if set)
 * @param o the oam object to flip
 * @param horizontal_flip if horizontal flip shall be changed
 * @param vertical_flip if vertical flip shall be changed
 */
void oam_flip(oam_object *o, bool horizontal_flip, bool vertical_flip);

/**
 * Clears an oam and releases all tiles used for its gfx animation.
 * @param o the oam to clear
 **/
void oam_clear_and_free_vram(oam_object *o);

/**
 * Allocates tiles for a oam graphic and copies it into vram.
 * @param g the graphic to copy, the sprite is expected to be uncompressed
 * @return t the tile where to graphic was copied to or 0xFFFF on failure
 **/
u16 oam_load_graphic_uncompressed(graphic *g);

#endif
