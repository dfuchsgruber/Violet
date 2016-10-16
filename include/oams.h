#ifndef H_OAMS
#define H_OAMS
#define OAM_OBJECT(x) ((oam_object*)((x*0x44)+0x0202063C))

#define ROTSCALE_TABLE_NULL (rotscale_frame**)0x08231BCC
#define GFX_ANIM_TABLE_NULL (gfx_frame**)0x08231Bc0


struct oam_object;
typedef struct oam_object oam_object;
struct gfx_frame;
typedef struct gfx_frame gfx_frame;


typedef struct palette {
	void *pal;
	u16 tag;
	u16 field_6;
} palette;

typedef struct gfx_frame {
  u16 data;
  u16 duration;
} gfx_frame;

typedef struct graphic {
  void *sprite;
  u16 size;
  u16 tag;
} graphic;

typedef struct rotscale_frame {
  u16 scale_delta_x;
  u16 scale_delta_y;
  u8 rot_delta;
  u8 duration;
  u16 field_6;
}  rotscale_frame;

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

typedef struct oam_object {
  sprite final_oam;
  gfx_frame **animation_table;
  u32 *gfx_table;
  u32 *rotscale_table;
  oam_template *oam_template;
  u32 field18;
  u32 *callback;
  u16 x;
  u16 y;
  s16 x2;
  s16 y2;
  u8 x_centre;
  u8 y_centre;
  u8 anim_number;
  u8 anim_frame;
  u8 anim_delay;
  u8 counter;
  u16 private[8];
  u8 bitfield2;
  u8 bitfield;
  u16 base_tile;
  u8 field42;
  u8 field43;
} oam_object;

oam_object* oams = (oam_object*)0x0202063C;

u8 generate_oam_forward_search(oam_template* template, s16 x, s16 y, u8 unkown);

u16 load_and_alloc_obj_vram_lz77 (graphic*g);
void free_vram_for_obj_without_tag_remove (oam_object* oam);
void free_obj_vram_by_object (oam_object* oam);

u8 generate_oam_backward_search(oam_template* template, s16 x, s16 y, u8 unkown);
u8 allocate_obj_pal(u16 paltag);
u16 get_paltag_by_allocated_pal(u8 palid);
void free_obj_pal (u16 paltag);
void clear_oam_entry (oam_object* oam);
void oam_despawn (oam_object* oam);
u8 get_id_of_vramobj_alloc_list_element (u16 tag);
void gfx_init_animation (oam_object* oam, u8 next_frame);
void rotscal_new_animation (oam_object* oam, u8 animation_index);
u8 get_obj_pal_by_tag(u16 tag);
u16 get_obj_tile_by_tag(u16 tag);

void oam_null_callback(oam_object *self);

#endif