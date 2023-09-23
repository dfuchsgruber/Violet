#ifndef H_OAMS
#define H_OAMS

#include "types.h"

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
#define ATTR0_SHAPE_MASK (ATTR0_SHAPE_HORIZONTAL | ATTR0_SHAPE_VERTICAL)

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
#define ATTR1_SIZE_MASK 0xC000

#define ATTR2_PRIO(x) ((x)<<10)
#define ATTR2_PRIO_MASK (ATTR2_PRIO(3))

#define GRAPHIC_SIZE_4BPP(width, height) ((width) * (height) / 2)
#define GRAPHIC_SIZE_4BPP_TO_NUM_TILES(width, height) (GRAPHIC_SIZE_4BPP(width, height) / GRAPHIC_SIZE_4BPP(8, 8))
#define GRAPHIC_SIZE_8BPP(width, height) ((width) * (height))
#define GRAPHIC_SIZE_8BPP_TO_NUM_TILES(width, height) (GRAPHIC_SIZE_8BPP(width, height) / GRAPHIC_SIZE_8BPP(8, 8))

#define GRAPHIC_ARRAY_4BPP(index, array, width, height) [(index)] = {.sprite = (array) + GRAPHIC_SIZE_4BPP(width, height) * index, .size = GRAPHIC_SIZE_4BPP(width, height)}
#define GRAPHIC_ARRAY_8BPP(index, array, width, height) [(index)] = {.sprite = (array) + GRAPHIC_SIZE_8BPP(width, height) * index, .size = GRAPHIC_SIZE_8BPP(width, height)}

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
    s8 rotation;
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
    const sprite *oam;
    const gfx_frame *const *animation;
    const graphic *graphics;
    const rotscale_frame *const *rotscale;
    void (*callback)(oam_object *self);
} oam_template;

extern oam_template gp_oam_template; // Multi-use oam template

#define OAM_FLAG_ACTIVE 0x1
#define OAM_FLAG_CENTERED 0x2
#define OAM_FLAG_INVISIBLE 0x4
#define OAM_FLAG_IN_GROUP 0x8
#define OAM_FLAG_HFLIP 0x100
#define OAM_FLAG_VFLIP 0x200
#define OAM_FLAG_GFX_ANIM_START 0x400
#define OAM_FLAG_ROTSCALE_ANIM_START 0x800
#define OAM_FLAG_GFX_ANIM_END 0x1000
#define OAM_FLAG_ROTSCALE_ANIM_END 0x2000
#define OAM_FLAG_SPRITES 0x4000

typedef struct {
  s8 x;
  s8 y;
  u16 shape : 2;
  u16 size : 2;
  u16 tile_offset : 10;
  u16 priority : 2;
} subsprite;

typedef struct {
  u8 num_subsprites;
  const subsprite *subsprites;
} subsprite_table;

enum {
    SUBSPRITES_OFF,
    SUBSPRITES_ON,
    SUBSPRITES_ON_AND_IGNORE_PRIORITY,
};

typedef struct {
  s8 width;
  s8 height;
  u16 filler;
} oam_size_t;

// Indexed by [shape][size]
extern const oam_size_t oam_sizes[3][4];

typedef struct oam_object {
    sprite final_oam;
    const gfx_frame *const *animation_table;
    const graphic *gfx_table;
    const rotscale_frame *const *rotscale_table;
    const oam_template *oam_template;
    const subsprite_table *subsprites;
    void (*callback)(oam_object*);
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    s8 x_centre;
    s8 y_centre;
    u8 anim_number;
    u8 anim_frame;
    u8 anim_delay : 6;
    u8 gfx_anim_paused : 1;
    u8 rotscale_anim_paused : 1;
    u8 counter;
    u16 private[8];
    u16 flags;
    u16 base_tile;
    u8 sprite_idx : 6;
    u8 sprite_mode : 2;
    u8 priority_on_layer;
} oam_object;

#define NUM_OAMS 64

#define NUM_OAM_VRAM_TILES 1024

extern u8 oam_vram_allocation[NUM_OAM_VRAM_TILES / 8];

extern u8 oam_visible_cnt; // Only oams oam_order[0], ... oam_order[oam_num_to_render - 1] have to be rendered in a vblank
extern u8 oam_active_cnt;
extern u8 oam_buffer_size; // `super` only wants this many GBA OAMs at most
extern u8 oam_copy_requests_enabled;
extern u8 oam_copy_requests_cnt;

typedef struct {
  const void *src;
  void *dst;
  u16 size;
  u16 filler;
} oam_copy_request_t;

extern oam_copy_request_t oam_copy_requests[64];

extern s16 coordinate_camera_x_offset;
extern s16 coordinate_camera_y_offset;

extern const oam_object oam_object_empty;

extern const rotscale_frame *oam_rotscale_anim_table_null[];
extern const gfx_frame *oam_gfx_anim_table_null[];

typedef struct { // Subject to change, I guess...
  u8 y_offset;
  u8 frames;
  u8 field_2;
  u8 field_3;
} sprite_coordinates_t;

enum {
  OAM_ALLOC_FREE_START = NUM_OAMS,
  OAM_ALLOC_ACTIVE_START,
  OAM_ALLOC_ACTIVE_MIDDLE, // this thing is there to separate elements that have been inserted FIFO and LIFO (front and back)
  OAM_ALLOC_ACTIVE_END,
  OAM_ALLOC_LIST_SIZE,
};

typedef struct {
  u8 previous;
  u8 next;
} oam_alloc_list_element_t;

typedef struct {
    u8 next;
    u8 previous;
} oam_group_list_element_t;

typedef struct {
    u8 oam_idx;
    u8 subsprite_idx;
} oams_to_sort_t;

extern u8 oam_rotscale_disabled;
extern oam_object oams[NUM_OAMS + 1];
extern u16 oam_priorities[NUM_OAMS];
extern u8 oam_order[NUM_OAMS];
extern EWRAM oam_alloc_list_element_t oam_allocation_list[OAM_ALLOC_LIST_SIZE];
extern EWRAM oam_group_list_element_t oam_groups[NUM_OAMS];
extern EWRAM oams_to_sort_t oams_to_sort[NUM_OAMS]; // These oams will be sorted. Subsprites are listed as entries each here.
extern EWRAM u8 oam_order_sorted[NUM_OAMS]; // Indices refering to `oams_to_sort

/**
 * Adds an oam to an oam group
 * @param oam_idx the oam to add to the group
 * @param group_head the group to add to (identified by a single oam, the group head)
 **/
void oam_add_to_group(u8 oam_idx, u8 group_head);

/**
 * Sets the subsprite table of an oam
 * @param o the oam to set the table of
 * @param subsprites the subsprite table to set
 **/
void oam_set_subsprite_table(oam_object *o, const subsprite_table *subsprites);

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
u8 oam_new_forward_search(const oam_template *template, s16 x, s16 y, u8 prio);

/**
 * Creates a new oam object by backward searching the buffer for free entries
 * @param template Oam template to construct the oam object from
 * @param x X-coordinate of the oam's center
 * @param y Y-coordinate of the oam's center
 * @param prio The priority relative to other oams on the same layer (0 being lowest)
 */
u8 oam_new_backward_search(const oam_template * template, s16 x, s16 y, u8 prio);

/**
 * Allocates oam vram and decompresses a graphic resource into the allocated vram. Places the
 * graphic's tag in the oam vram allocation table.
 * @param graphic The graphic resource to load
 * @return The oam vram tile id that was allocated
 */
u16 oam_load_graphic(const graphic*g);

/**
 * Loads lz77 compressed graphic by allocating heap space, decompressing and then copying.
 * @param g the graphic to load
 * @return if the graphic could be loaded
 **/
bool oam_load_graphic_using_heap(const graphic *g);

/**
 * Loads lz77 compressed palette by allocating heap space, decompressing and then copying.
 * @param p the palette to load
 * @return if the palette could be loaded
 **/
bool oam_load_palette_using_heap(const palette *p);

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
 * Loads (and possibly allocates) a oam palette, if it is not already present.
 * @param p the palettes struct, referring to an uncompressed color array
 * @return the idx of the palette or 0xFF on failure
 **/
u8 oam_palette_load_if_not_present(const palette *p);

/**
 * Loads (and possibly allocates) a oam palette, if it is not already present and applies shaders if and only if it was not present.
 * @param p the palettes struct, referring to an uncompressed color array
 * @return the idx of the palette or 0xFF on failure
 **/
u8 oam_palette_load_if_not_present_and_apply_shaders(const palette *p);
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
 * Sets rotation and scale of a oam matrix
 * @param matrix_idx the matrix to set
 * @param x_scale the x_scale in multiples of 0x100
 * @param y_scale the y_scale in multiples of 0x100
 * @param rotation the rotation from [0, 255]
 **/
void oam_set_rotation_and_scale(u8 matrix_idx, s16 x_scale, s16 y_scale, u8 rotation);

/**
 * Attempts to set rotation and scale of an oam object if it has a matrix. It pauses the current affine anim.
 * @param o the object to set parameters of
 * @param recalculate_center_vector if the center vector will be recalculated
 * @param x_scale the horizontal scaling in multiples of 0x100
 * @param y_scale the vertical scaling in multiples of 0x100
 * @param rotation the angle in [0, 0xFFFF]
 **/
void oam_try_set_rotation_and_scale(oam_object *o, bool recalculate_center_vector, s16 x_scale, s16 y_scale, u16 rotation);

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
void oam_animations_proceed();

/**
 * Executes the animation of one oam
 * @param o the oam to execute the animation of
 **/
void oam_animation_proceed(oam_object *o);

/**
 * Returns the index of the affine group the oam uses or 0 if the oam does not use affine
 * transformations.
 * @param o the object to get the rotscale group of
 * @return the index of the affine group or 0
 */
u8 oam_rotscale_get(const oam_object *o);

/**
 * Flips an oam (i.e. turns the current flip if set)
 * @param o the oam object to flip
 * @param horizontal_flip if horizontal flip shall be changed
 * @param vertical_flip if vertical flip shall be changed
 */
void oam_flip(oam_object *o, bool horizontal_flip, bool vertical_flip);

/**
 * Clears an oam and releases tiles which are not from a pre-loaded graphic with tag but its spritesheet.
 * @param o the oam to clear
 **/
void oam_delete(oam_object *o);

/**
 * Allocates tiles for a oam graphic and copies it into vram.
 * @param g the graphic to copy, the sprite is expected to be uncompressed
 * @return t the tile where to graphic was copied to or 0xFFFF on failure
 **/
u16 oam_load_graphic_uncompressed(const graphic *g);

/**
 * Starts a certain gfx animation.
 * @param o the oam to start the animation of
 * @param anim_idx the animation to start
 **/
void oam_gfx_anim_start(oam_object *o, u8 anim_idx);

/**
 * Starts a certain gfx animation, if the selected animation is not already running.
 * @param o the oam to start the animation of
 * @param anim_idx the animation to start
 **/
void oam_gfx_anim_start_if_not_current(oam_object *o, u8 anim_idx);

/**
 * Resets the oam attribute buffer.
 * @param first the first oam to reset
 * @param the last oam oam (exclusive) to reset
 **/
void oam_buffer_reset(u8 first, u8 last);

/**
 * Calculates the coordinates of the center w.r.t. the upper left corner of an oam. 
 * @param o the oam
 * @param shape its shape
 * @param size its size (accordint to the GBA specs)
 * @param affine_mode (rotscale and dsize)
 **/
void oam_calculate_center_coordinates(oam_object *o, u8 shape, u8 size, u8 affine_mode);

/**
 * Updates the base tile of an oam based on where the gfx animation points in the sheet that was loaded to vram.
 * @param o the object
 **/
void oam_update_base_tile_by_gfx_animation(oam_object *o);

/**
 * Initializes the affine animation of an oam
 * @param o the object
 **/
void oam_rotscale_animation_initialize(oam_object *o);

/**
 * Copies all rotscale (affine) groups to `super`'s oam buffer.
 **/
void oam_copy_rotscale_to_buffer();

enum {
  OAM_ALLOCATE_AT_START,
  OAM_ALLOCATE_AT_END,
};

/**
 * Allocates a free oam idx
 * @return the oam idx or NUM_OAMS if None was free
 **/
u8 oam_allocate(u8 where);

/**
 * Copies an oam by allocating at the beginning of the list
 * @param src the object to copy
 * @param x the x coordinate to set for the new oam
 * @param y the y coordinate to set for the new oam
 * @param priority_on_layer its priority on the layer
 * @return the idx of the oam_object or NUM_OAMS if no slot could be allocated
 **/
u8 oam_copy_forward_search(const oam_object *src, s16 x, s16 y, u8 priority_on_layer);

/**
 * Copies an oam by allocating at the end of the list
 * @param src the object to copy
 * @param x the x coordinate to set for the new oam
 * @param y the y coordinate to set for the new oam
 * @param priority_on_layer its priority on the layer
 * @return the idx of the oam_object or NUM_OAMS if no slot could be allocated
 **/
u8 oam_copy_backward_search(const oam_object *src, s16 x, s16 y, u8 priority_on_layer);

#endif
