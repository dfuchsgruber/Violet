/*
 * sprite.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_SPRITE_H_
#define INCLUDE_C_OVERWORLD_SPRITE_H_

/*
 * File:   overworld_sprites.h
 * Author: Domi
 *
 * Created on 16. Juni 2016, 11:14
 */


#include "types.h"
#include "oam.h"
#include "color.h"
#include "overworld/npc.h"
#include "map/event.h"

#define OVERWORLD_SPRITE_STRENGTH_BOULDER 97
#define OVERWORLD_SPRITE_ROMAN 179
#define OVERWORLD_SPRITE_MISC 236
#define OVERWORLD_SPRITE_BERRY 237
#define OVERWORLD_SPRITE_POKEMON_32_32 238
#define OVERWORLD_SPRITE_POKEMON_64_64 239

extern gfx_frame *ow_anim_standard_npc[];
extern gfx_frame *ow_anim_ho_oh[];
extern gfx_frame *ow_anim_hiro[];
extern gfx_frame *ow_anim_hiro_sit[];
extern gfx_frame *ow_anim_hiro_call[];
extern gfx_frame *ow_anim_hiro_rod[];
extern gfx_frame *ow_anim_hiro_call2[];
extern gfx_frame *ow_anim_hiro_bike[];
extern gfx_frame *ow_anim_none[];

extern subsprite_table ow_formation_16_32;
extern subsprite_table ow_formation_128_64;
extern subsprite_table ow_formation_32_32;
extern subsprite_table ow_formation_64_64;
extern subsprite_table ow_formation_16_16;

extern sprite ow_final_oam_16_32;
extern sprite ow_final_oam_128_64;
extern sprite ow_final_oam_64_64;
extern sprite ow_final_oam_32_32;
extern sprite ow_final_oam_16_16;


typedef struct overworld_sprite {
    u16 tiles_tag; //Tiles tag
    u16 pal_tag; //0x1100 + PalID
    u16 unknown; //usually 0x11FF
    u16 size; //in bytes, e.g. for 32x16 := 0x100
    u16 width;
    u16 height;
    u8 palette_slot : 4;
    u8 shadow_size : 2;
    u8 inanimate : 1;
    u8 disable_reflection : 1; // unused in violet
    u8 field_D;
    u8 field_E;
    u8 field_F;
    sprite *final_oam; //NSE := Pointer 1
    subsprite_table *subsprite_table; //NSE := Pointer 2
    gfx_frame **gfx_animation; //NSE := Anim Pointer
    graphic *graphics; //NSE := equals Pointer 3
    rotscale_frame **rotscale_animation; //No NSE equal
} overworld_sprite;


#define OW_PAL_TAG_POKEMON_BASE 0x2000
#define OW_PAL_TAG_POKEMON_END 0x2200
#define OW_PAL_TAG_MUSHROOM 0x2E00
#define OW_PAL_TAG_SHELL 0x2E01
#define OW_PAL_TAG_BOULDER_GYM_PUZZLE 0x2E02
#define OW_PAL_TAG_MEGA_STONE 0x2E03
#define OW_PAL_TAG_ROMAN 0x2E04
#define OW_PAL_TAG_END 0x3000

/**
 * Returns the palette of an overworld species.
 * @param species the species to get the palette of
 * @return the palette structure
 **/
palette *overworld_palette_get_by_species(u16 species);
/**
 * Returns the overworld sprite of an overworld species.
 * @param species the species to get the overworld sprite of
 * @return the overworld sprite.
 **/
overworld_sprite *overworld_sprite_get_by_species(u16 species);

/**
 * Returns the overworld sprite idx that is to be used for a species.
 * @param the species to find a suitable sprite for
 * @return the overworld sprite idx to use for this species, e.g. in a person
 **/
u8 overworld_get_sprite_idx_by_species(u16 species);

/**
 * Gets the overworld sprite associated with a npc
 * @param npc the npc to get the sprite of
 * @return the overworld sprite
 **/
overworld_sprite *overworld_get_by_npc(npc *n);

/**
 * Returns the overworld sprite of a mushroom
 * @param mushroom_idx which mushroom to get
 * @return the overworld sprite
 **/
overworld_sprite *overworld_sprite_get_by_mushroom_idx(u16 mushroom_idx);

/**
 * Returns the overworld palette of a mushroom
 * @return the palette sprite
 **/
palette *overworld_palette_get_by_mushroom();

/**
 * Returns the overworld sprite of a shell
 * @param mushroom_idx which shell to get
 * @return the overworld sprite
 **/
overworld_sprite *overworld_sprite_get_by_shell_idx(u16 shell_idx);

/**
 * Returns the overworld palette of a shell
 * @return the palette sprite
 **/
palette *overworld_palette_get_by_shell();

/**
 * Gets the sprite of a boulder.
 * @param person_script_std person's script std that indicates the boulder picture
 * @param value flags of the person
 * @return the overworld sprite
 **/
overworld_sprite *overworld_sprite_get_by_boulder_person_script_std(u8 person_script_std, u16 value);

/**
 * Returns the overworld palette of the first gym's puzzle boulders
 * @return the palette
 **/
palette *overworld_palette_get_gym_puzzle_boulder();

/**
 * Returns the overworld palette of the mega stone npc
 * @return the palette
 **/
palette *overworld_palette_get_mega_stone();

/**
 * Frees a npc palette if currently no active npc is using this palette.
 * @param slot the palette to free
 **/
void npc_free_palette_if_unused_by_slot(u8 slot);

/**
 * Updates the palette of a npc by, if neccesary, also loading the palette
 * @param npc the npc to update
 * @param oam the oam object to update
 **/
void overworld_npc_update_palette(npc *n, oam_object *oam);

/**
 * Sets the priority of the oam (oam attribute) according to the oams height
 * @param o the oam to set the height of
 * @param height the height
 **/
void oam_set_priority_by_height(oam_object *o, u8 height);

/**
 * Sets the subspriority (relative to other oams of the same priority) of an oam according to a height
 * @param o the oam to set the subpriority of
 * @param height the height
 * @param relative_priority priority relative to oams of the same height (simply an offset to the subpriority)
 **/
void oam_set_subpriority_by_height(oam_object *o, u8 height, u8 relative_priority);

/**
 * Creates a oam that would correspond to a person, but doesn't intialize any npc for it
 * @param person the person associated (mainyl used to determine the graphic shown)
 * @param a1 t.b.d.
 * @param x the x coordinate (in blocks)
 * @param y the y coordinate (in blocks)
 * @param z the height
 * @param direction in which direction the oam should face
 * @return oam_idx the idx of the oam created
 **/
u8 overworld_create_oam_by_person(map_event_person *person, u8 a1, s16 x, s16 y, u8 z, u8 direction);

/**
 * Creates an oam for a given overworld npc, but assigns a custom callback to it.
 * @param n the npc to base the oam on
 * @param callback the callback for the sprite
 * @param x the x coordinate
 * @param y the y coordinate
 * @param subpriority priority relative to other oams on this layer
 * @return the idx of the oam or 64 on failure
 **/
u8 overworld_create_oam_with_callback_by_npc(npc *n, void (*callback)(oam_object*), s16 x, s16 y, u8 subpriority);

/**
 * Starts the boulder push animation and pushes the boulder
 * @param npc_idx the npc to move
 * @param direction in which direction
 **/
void boulder_animation_start(u8 npc_idx, u8 direction);

/**
 * Attempts to do a boulder push
 * @param x x coordinate of the boulder
 * @param y y coordinate of the boulder
 * @param direction in which direction to push the boulder
 * @return if the boulder push attempt was sucessful, i.e. if a boulder push animation was triggered
 **/
bool boulder_push_attempt(s16 x, s16 y, u8 direction);

extern u8 gfx_ow_bisasamTiles[];
extern color_t gfx_ow_bisasamPal[16];
extern u8 gfx_ow_bisaknospTiles[];
extern color_t gfx_ow_bisaknospPal[16];
extern u8 gfx_ow_bisaflorTiles[];
extern color_t gfx_ow_bisaflorPal[16];
extern u8 gfx_ow_glumandaTiles[];
extern color_t gfx_ow_glumandaPal[16];
extern u8 gfx_ow_glutexoTiles[];
extern color_t gfx_ow_glutexoPal[16];
extern u8 gfx_ow_glurakTiles[];
extern color_t gfx_ow_glurakPal[16];
extern u8 gfx_ow_schiggyTiles[];
extern color_t gfx_ow_schiggyPal[16];
extern u8 gfx_ow_schillokTiles[];
extern color_t gfx_ow_schillokPal[16];
extern u8 gfx_ow_turtokTiles[];
extern color_t gfx_ow_turtokPal[16];
extern u8 gfx_ow_dartiriTiles[];
extern color_t gfx_ow_dartiriPal[16];
extern u8 gfx_ow_dartignisTiles[];
extern color_t gfx_ow_dartignisPal[16];
extern u8 gfx_ow_fiaroTiles[];
extern color_t gfx_ow_fiaroPal[16];
extern u8 gfx_ow_hornliuTiles[];
extern color_t gfx_ow_hornliuPal[16];
extern u8 gfx_ow_kokunaTiles[];
extern color_t gfx_ow_kokunaPal[16];
extern u8 gfx_ow_biborTiles[];
extern color_t gfx_ow_biborPal[16];
extern u8 gfx_ow_staraliliTiles[];
extern color_t gfx_ow_staraliliPal[16];
extern u8 gfx_ow_staraviaTiles[];
extern color_t gfx_ow_staraviaPal[16];
extern u8 gfx_ow_staraptorTiles[];
extern color_t gfx_ow_staraptorPal[16];
extern u8 gfx_ow_bronzelTiles[];
extern color_t gfx_ow_bronzelPal[16];
extern u8 gfx_ow_bronzongTiles[];
extern color_t gfx_ow_bronzongPal[16];
extern u8 gfx_ow_maehikelTiles[];
extern color_t gfx_ow_maehikelPal[16];
extern u8 gfx_ow_chevrummTiles[];
extern color_t gfx_ow_chevrummPal[16];
extern u8 gfx_ow_paragoniTiles[];
extern color_t gfx_ow_paragoniPal[16];
extern u8 gfx_ow_tromborkTiles[];
extern color_t gfx_ow_tromborkPal[16];
extern u8 gfx_ow_pikachuTiles[];
extern color_t gfx_ow_pikachuPal[16];
extern u8 gfx_ow_raichuTiles[];
extern color_t gfx_ow_raichuPal[16];
extern u8 gfx_ow_sandanTiles[];
extern color_t gfx_ow_sandanPal[16];
extern u8 gfx_ow_sandamerTiles[];
extern color_t gfx_ow_sandamerPal[16];
extern u8 gfx_ow_nidoranwTiles[];
extern color_t gfx_ow_nidoranwPal[16];
extern u8 gfx_ow_nidorinaTiles[];
extern color_t gfx_ow_nidorinaPal[16];
extern u8 gfx_ow_nidoqueenTiles[];
extern color_t gfx_ow_nidoqueenPal[16];
extern u8 gfx_ow_nidoranmTiles[];
extern color_t gfx_ow_nidoranmPal[16];
extern u8 gfx_ow_nidorinoTiles[];
extern color_t gfx_ow_nidorinoPal[16];
extern u8 gfx_ow_nidokingTiles[];
extern color_t gfx_ow_nidokingPal[16];
extern u8 gfx_ow_floetteTiles[];
extern color_t gfx_ow_floettePal[16];
extern u8 gfx_ow_florgesTiles[];
extern color_t gfx_ow_florgesPal[16];
extern u8 gfx_ow_vulpixTiles[];
extern color_t gfx_ow_vulpixPal[16];
extern u8 gfx_ow_vulnonaTiles[];
extern color_t gfx_ow_vulnonaPal[16];
extern u8 gfx_ow_pummeluffTiles[];
extern color_t gfx_ow_pummeluffPal[16];
extern u8 gfx_ow_knuddeluffTiles[];
extern color_t gfx_ow_knuddeluffPal[16];
extern u8 gfx_ow_zubatTiles[];
extern color_t gfx_ow_zubatPal[16];
extern u8 gfx_ow_golbatTiles[];
extern color_t gfx_ow_golbatPal[16];
extern u8 gfx_ow_myraplaTiles[];
extern color_t gfx_ow_myraplaPal[16];
extern u8 gfx_ow_duflorTiles[];
extern color_t gfx_ow_duflorPal[16];
extern u8 gfx_ow_giflorTiles[];
extern color_t gfx_ow_giflorPal[16];
extern u8 gfx_ow_folipurbaTiles[];
extern color_t gfx_ow_folipurbaPal[16];
extern u8 gfx_ow_feelinaraTiles[];
extern color_t gfx_ow_feelinaraPal[16];
extern u8 gfx_ow_wattzapfTiles[];
extern color_t gfx_ow_wattzapfPal[16];
extern u8 gfx_ow_voltulaTiles[];
extern color_t gfx_ow_voltulaPal[16];
extern u8 gfx_ow_digdaTiles[];
extern color_t gfx_ow_digdaPal[16];
extern u8 gfx_ow_digdriTiles[];
extern color_t gfx_ow_digdriPal[16];
extern u8 gfx_ow_kastadurTiles[];
extern color_t gfx_ow_kastadurPal[16];
extern u8 gfx_ow_tentantelTiles[];
extern color_t gfx_ow_tentantelPal[16];
extern u8 gfx_ow_entonTiles[];
extern color_t gfx_ow_entonPal[16];
extern u8 gfx_ow_entoronTiles[];
extern color_t gfx_ow_entoronPal[16];
extern u8 gfx_ow_menkiTiles[];
extern color_t gfx_ow_menkiPal[16];
extern u8 gfx_ow_rasaffTiles[];
extern color_t gfx_ow_rasaffPal[16];
extern u8 gfx_ow_fukanoTiles[];
extern color_t gfx_ow_fukanoPal[16];
extern u8 gfx_ow_arkaniTiles[];
extern color_t gfx_ow_arkaniPal[16];
extern u8 gfx_ow_gramoklesTiles[];
extern color_t gfx_ow_gramoklesPal[16];
extern u8 gfx_ow_duoklesTiles[];
extern color_t gfx_ow_duoklesPal[16];
extern u8 gfx_ow_durengardTiles[];
extern color_t gfx_ow_durengardPal[16];
extern u8 gfx_ow_abraTiles[];
extern color_t gfx_ow_abraPal[16];
extern u8 gfx_ow_kadabraTiles[];
extern color_t gfx_ow_kadabraPal[16];
extern u8 gfx_ow_simsalaTiles[];
extern color_t gfx_ow_simsalaPal[16];
extern u8 gfx_ow_macholloTiles[];
extern color_t gfx_ow_macholloPal[16];
extern u8 gfx_ow_maschockTiles[];
extern color_t gfx_ow_maschockPal[16];
extern u8 gfx_ow_machomeiTiles[];
extern color_t gfx_ow_machomeiPal[16];
extern u8 gfx_ow_knofensaTiles[];
extern color_t gfx_ow_knofensaPal[16];
extern u8 gfx_ow_ultrigariaTiles[];
extern color_t gfx_ow_ultrigariaPal[16];
extern u8 gfx_ow_sarzeniaTiles[];
extern color_t gfx_ow_sarzeniaPal[16];
extern u8 gfx_ow_tentachaTiles[];
extern color_t gfx_ow_tentachaPal[16];
extern u8 gfx_ow_tentoxaTiles[];
extern color_t gfx_ow_tentoxaPal[16];
extern u8 gfx_ow_kleinsteinTiles[];
extern color_t gfx_ow_kleinsteinPal[16];
extern u8 gfx_ow_georokTiles[];
extern color_t gfx_ow_georokPal[16];
extern u8 gfx_ow_geowazTiles[];
extern color_t gfx_ow_geowazPal[16];
extern u8 gfx_ow_ponitaTiles[];
extern color_t gfx_ow_ponitaPal[16];
extern u8 gfx_ow_gallopaTiles[];
extern color_t gfx_ow_gallopaPal[16];
extern u8 gfx_ow_flegmonTiles[];
extern color_t gfx_ow_flegmonPal[16];
extern u8 gfx_ow_lahmusTiles[];
extern color_t gfx_ow_lahmusPal[16];
extern u8 gfx_ow_magnetiloTiles[];
extern color_t gfx_ow_magnetiloPal[16];
extern u8 gfx_ow_magnetonTiles[];
extern color_t gfx_ow_magnetonPal[16];
extern u8 gfx_ow_porentaTiles[];
extern color_t gfx_ow_porentaPal[16];
extern u8 gfx_ow_doduTiles[];
extern color_t gfx_ow_doduPal[16];
extern u8 gfx_ow_dodriTiles[];
extern color_t gfx_ow_dodriPal[16];
extern u8 gfx_ow_jurobTiles[];
extern color_t gfx_ow_jurobPal[16];
extern u8 gfx_ow_jugongTiles[];
extern color_t gfx_ow_jugongPal[16];
extern u8 gfx_ow_sleimaTiles[];
extern color_t gfx_ow_sleimaPal[16];
extern u8 gfx_ow_sleimokTiles[];
extern color_t gfx_ow_sleimokPal[16];
extern u8 gfx_ow_muschasTiles[];
extern color_t gfx_ow_muschasPal[16];
extern u8 gfx_ow_austosTiles[];
extern color_t gfx_ow_austosPal[16];
extern u8 gfx_ow_nebulakTiles[];
extern color_t gfx_ow_nebulakPal[16];
extern u8 gfx_ow_alpolloTiles[];
extern color_t gfx_ow_alpolloPal[16];
extern u8 gfx_ow_gengarTiles[];
extern color_t gfx_ow_gengarPal[16];
extern u8 gfx_ow_onixTiles[];
extern color_t gfx_ow_onixPal[16];
extern u8 gfx_ow_traumatoTiles[];
extern color_t gfx_ow_traumatoPal[16];
extern u8 gfx_ow_hypnoTiles[];
extern color_t gfx_ow_hypnoPal[16];
extern u8 gfx_ow_krabbyTiles[];
extern color_t gfx_ow_krabbyPal[16];
extern u8 gfx_ow_kinglerTiles[];
extern color_t gfx_ow_kinglerPal[16];
extern u8 gfx_ow_voltobalTiles[];
extern color_t gfx_ow_voltobalPal[16];
extern u8 gfx_ow_lektrobalTiles[];
extern color_t gfx_ow_lektrobalPal[16];
extern u8 gfx_ow_oweiTiles[];
extern color_t gfx_ow_oweiPal[16];
extern u8 gfx_ow_kokoweiTiles[];
extern color_t gfx_ow_kokoweiPal[16];
extern u8 gfx_ow_tragossoTiles[];
extern color_t gfx_ow_tragossoPal[16];
extern u8 gfx_ow_knoggaTiles[];
extern color_t gfx_ow_knoggaPal[16];
extern u8 gfx_ow_kickleeTiles[];
extern color_t gfx_ow_kickleePal[16];
extern u8 gfx_ow_nockchanTiles[];
extern color_t gfx_ow_nockchanPal[16];
extern u8 gfx_ow_schlurpTiles[];
extern color_t gfx_ow_schlurpPal[16];
extern u8 gfx_ow_smogonTiles[];
extern color_t gfx_ow_smogonPal[16];
extern u8 gfx_ow_smogmogTiles[];
extern color_t gfx_ow_smogmogPal[16];
extern u8 gfx_ow_rihornTiles[];
extern color_t gfx_ow_rihornPal[16];
extern u8 gfx_ow_rizerosTiles[];
extern color_t gfx_ow_rizerosPal[16];
extern u8 gfx_ow_chaneiraTiles[];
extern color_t gfx_ow_chaneiraPal[16];
extern u8 gfx_ow_zobirisTiles[];
extern color_t gfx_ow_zobirisPal[16];
extern u8 gfx_ow_kangamaTiles[];
extern color_t gfx_ow_kangamaPal[16];
extern u8 gfx_ow_seeperTiles[];
extern color_t gfx_ow_seeperPal[16];
extern u8 gfx_ow_seemonTiles[];
extern color_t gfx_ow_seemonPal[16];
extern u8 gfx_ow_quabbelTiles[];
extern color_t gfx_ow_quabbelPal[16];
extern u8 gfx_ow_apoquallypTiles[];
extern color_t gfx_ow_apoquallypPal[16];
extern u8 gfx_ow_sternduTiles[];
extern color_t gfx_ow_sternduPal[16];
extern u8 gfx_ow_starmieTiles[];
extern color_t gfx_ow_starmiePal[16];
extern u8 gfx_ow_traunfugilTiles[];
extern color_t gfx_ow_traunfugilPal[16];
extern u8 gfx_ow_sichlorTiles[];
extern color_t gfx_ow_sichlorPal[16];
extern u8 gfx_ow_galagladiTiles[];
extern color_t gfx_ow_galagladiPal[16];
extern u8 gfx_ow_elektekTiles[];
extern color_t gfx_ow_elektekPal[16];
extern u8 gfx_ow_magmarTiles[];
extern color_t gfx_ow_magmarPal[16];
extern u8 gfx_ow_pinsirTiles[];
extern color_t gfx_ow_pinsirPal[16];
extern u8 gfx_ow_taurosTiles[];
extern color_t gfx_ow_taurosPal[16];
extern u8 gfx_ow_karpadorTiles[];
extern color_t gfx_ow_karpadorPal[16];
extern u8 gfx_ow_garadosTiles[];
extern color_t gfx_ow_garadosPal[16];
extern u8 gfx_ow_laprasTiles[];
extern color_t gfx_ow_laprasPal[16];
extern u8 gfx_ow_dittoTiles[];
extern color_t gfx_ow_dittoPal[16];
extern u8 gfx_ow_evoliTiles[];
extern color_t gfx_ow_evoliPal[16];
extern u8 gfx_ow_aquanaTiles[];
extern color_t gfx_ow_aquanaPal[16];
extern u8 gfx_ow_blitzaTiles[];
extern color_t gfx_ow_blitzaPal[16];
extern u8 gfx_ow_flamaraTiles[];
extern color_t gfx_ow_flamaraPal[16];
extern u8 gfx_ow_porygonTiles[];
extern color_t gfx_ow_porygonPal[16];
extern u8 gfx_ow_amonitasTiles[];
extern color_t gfx_ow_amonitasPal[16];
extern u8 gfx_ow_amorosoTiles[];
extern color_t gfx_ow_amorosoPal[16];
extern u8 gfx_ow_kabutoTiles[];
extern color_t gfx_ow_kabutoPal[16];
extern u8 gfx_ow_kabutopsTiles[];
extern color_t gfx_ow_kabutopsPal[16];
extern u8 gfx_ow_aerodactylTiles[];
extern color_t gfx_ow_aerodactylPal[16];
extern u8 gfx_ow_relaxoTiles[];
extern color_t gfx_ow_relaxoPal[16];
extern u8 gfx_ow_arktosTiles[];
extern color_t gfx_ow_arktosPal[16];
extern u8 gfx_ow_zapdosTiles[];
extern color_t gfx_ow_zapdosPal[16];
extern u8 gfx_ow_lavadosTiles[];
extern color_t gfx_ow_lavadosPal[16];
extern u8 gfx_ow_dratiniTiles[];
extern color_t gfx_ow_dratiniPal[16];
extern u8 gfx_ow_dragonirTiles[];
extern color_t gfx_ow_dragonirPal[16];
extern u8 gfx_ow_dragoranTiles[];
extern color_t gfx_ow_dragoranPal[16];
extern u8 gfx_ow_mewtuTiles[];
extern color_t gfx_ow_mewtuPal[16];
extern u8 gfx_ow_mewTiles[];
extern color_t gfx_ow_mewPal[16];
extern u8 gfx_ow_endivieTiles[];
extern color_t gfx_ow_endiviePal[16];
extern u8 gfx_ow_lorblattTiles[];
extern color_t gfx_ow_lorblattPal[16];
extern u8 gfx_ow_meganieTiles[];
extern color_t gfx_ow_meganiePal[16];
extern u8 gfx_ow_feurigelTiles[];
extern color_t gfx_ow_feurigelPal[16];
extern u8 gfx_ow_igelavarTiles[];
extern color_t gfx_ow_igelavarPal[16];
extern u8 gfx_ow_tornuptoTiles[];
extern color_t gfx_ow_tornuptoPal[16];
extern u8 gfx_ow_karnimaniTiles[];
extern color_t gfx_ow_karnimaniPal[16];
extern u8 gfx_ow_tyracrocTiles[];
extern color_t gfx_ow_tyracrocPal[16];
extern u8 gfx_ow_impergatorTiles[];
extern color_t gfx_ow_impergatorPal[16];
extern u8 gfx_ow_ignivorTiles[];
extern color_t gfx_ow_ignivorPal[16];
extern u8 gfx_ow_ramothTiles[];
extern color_t gfx_ow_ramothPal[16];
extern u8 gfx_ow_glaziolaTiles[];
extern color_t gfx_ow_glaziolaPal[16];
extern u8 gfx_ow_resladeroTiles[];
extern color_t gfx_ow_resladeroPal[16];
extern u8 gfx_ow_ledybaTiles[];
extern color_t gfx_ow_ledybaPal[16];
extern u8 gfx_ow_ledianTiles[];
extern color_t gfx_ow_ledianPal[16];
extern u8 gfx_ow_webarakTiles[];
extern color_t gfx_ow_webarakPal[16];
extern u8 gfx_ow_ariadosTiles[];
extern color_t gfx_ow_ariadosPal[16];
extern u8 gfx_ow_iksbatTiles[];
extern color_t gfx_ow_iksbatPal[16];
extern u8 gfx_ow_lampiTiles[];
extern color_t gfx_ow_lampiPal[16];
extern u8 gfx_ow_lanturnTiles[];
extern color_t gfx_ow_lanturnPal[16];
extern u8 gfx_ow_magnezoneTiles[];
extern color_t gfx_ow_magnezonePal[16];
extern u8 gfx_ow_togekissTiles[];
extern color_t gfx_ow_togekissPal[16];
extern u8 gfx_ow_flabebeTiles[];
extern color_t gfx_ow_flabebePal[16];
extern u8 gfx_ow_togepiTiles[];
extern color_t gfx_ow_togepiPal[16];
extern u8 gfx_ow_togeticTiles[];
extern color_t gfx_ow_togeticPal[16];
extern u8 gfx_ow_natuTiles[];
extern color_t gfx_ow_natuPal[16];
extern u8 gfx_ow_xatuTiles[];
extern color_t gfx_ow_xatuPal[16];
extern u8 gfx_ow_voltilammTiles[];
extern color_t gfx_ow_voltilammPal[16];
extern u8 gfx_ow_waatyTiles[];
extern color_t gfx_ow_waatyPal[16];
extern u8 gfx_ow_ampharosTiles[];
extern color_t gfx_ow_ampharosPal[16];
extern u8 gfx_ow_blubellaTiles[];
extern color_t gfx_ow_blubellaPal[16];
extern u8 gfx_ow_marillTiles[];
extern color_t gfx_ow_marillPal[16];
extern u8 gfx_ow_azumarillTiles[];
extern color_t gfx_ow_azumarillPal[16];
extern u8 gfx_ow_mogelbaumTiles[];
extern color_t gfx_ow_mogelbaumPal[16];
extern u8 gfx_ow_clavionTiles[];
extern color_t gfx_ow_clavionPal[16];
extern u8 gfx_ow_lichtelTiles[];
extern color_t gfx_ow_lichtelPal[16];
extern u8 gfx_ow_laternectoTiles[];
extern color_t gfx_ow_laternectoPal[16];
extern u8 gfx_ow_skelabraTiles[];
extern color_t gfx_ow_skelabraPal[16];
extern u8 gfx_ow_griffelTiles[];
extern color_t gfx_ow_griffelPal[16];
extern u8 gfx_ow_shnebedeckTiles[];
extern color_t gfx_ow_shnebedeckPal[16];
extern u8 gfx_ow_rexblisarTiles[];
extern color_t gfx_ow_rexblisarPal[16];
extern u8 gfx_ow_ambidiffelTiles[];
extern color_t gfx_ow_ambidiffelPal[16];
extern u8 gfx_ow_felinoTiles[];
extern color_t gfx_ow_felinoPal[16];
extern u8 gfx_ow_morlordTiles[];
extern color_t gfx_ow_morlordPal[16];
extern u8 gfx_ow_psianaTiles[];
extern color_t gfx_ow_psianaPal[16];
extern u8 gfx_ow_nachtaraTiles[];
extern color_t gfx_ow_nachtaraPal[16];
extern u8 gfx_ow_kramurxTiles[];
extern color_t gfx_ow_kramurxPal[16];
extern u8 gfx_ow_laschokingTiles[];
extern color_t gfx_ow_laschokingPal[16];
extern u8 gfx_ow_kramshefTiles[];
extern color_t gfx_ow_kramshefPal[16];
extern u8 gfx_ow_icognitoTiles[];
extern color_t gfx_ow_icognitoPal[16];
extern u8 gfx_ow_frosdedjeTiles[];
extern color_t gfx_ow_frosdedjePal[16];
extern u8 gfx_ow_skorgroTiles[];
extern color_t gfx_ow_skorgroPal[16];
extern u8 gfx_ow_tannzaTiles[];
extern color_t gfx_ow_tannzaPal[16];
extern u8 gfx_ow_forstellkaTiles[];
extern color_t gfx_ow_forstellkaPal[16];
extern u8 gfx_ow_elevoltekTiles[];
extern color_t gfx_ow_elevoltekPal[16];
extern u8 gfx_ow_skorglaTiles[];
extern color_t gfx_ow_skorglaPal[16];
extern u8 gfx_ow_stahlosTiles[];
extern color_t gfx_ow_stahlosPal[16];
extern u8 gfx_ow_snubbullTiles[];
extern color_t gfx_ow_snubbullPal[16];
extern u8 gfx_ow_granbullTiles[];
extern color_t gfx_ow_granbullPal[16];
extern u8 gfx_ow_mamutelTiles[];
extern color_t gfx_ow_mamutelPal[16];
extern u8 gfx_ow_scheroxTiles[];
extern color_t gfx_ow_scheroxPal[16];
extern u8 gfx_ow_fluffeluffTiles[];
extern color_t gfx_ow_fluffeluffPal[16];
extern u8 gfx_ow_skarabornTiles[];
extern color_t gfx_ow_skarabornPal[16];
extern u8 gfx_ow_kryppukTiles[];
extern color_t gfx_ow_kryppukPal[16];
extern u8 gfx_ow_teddiursaTiles[];
extern color_t gfx_ow_teddiursaPal[16];
extern u8 gfx_ow_ursaringTiles[];
extern color_t gfx_ow_ursaringPal[16];
extern u8 gfx_ow_schneckmagTiles[];
extern color_t gfx_ow_schneckmagPal[16];
extern u8 gfx_ow_magcargoTiles[];
extern color_t gfx_ow_magcargoPal[16];
extern u8 gfx_ow_quiekelTiles[];
extern color_t gfx_ow_quiekelPal[16];
extern u8 gfx_ow_keifelTiles[];
extern color_t gfx_ow_keifelPal[16];
extern u8 gfx_ow_mampfaxoTiles[];
extern color_t gfx_ow_mampfaxoPal[16];
extern u8 gfx_ow_remoraidTiles[];
extern color_t gfx_ow_remoraidPal[16];
extern u8 gfx_ow_octilleryTiles[];
extern color_t gfx_ow_octilleryPal[16];
extern u8 gfx_ow_botogelTiles[];
extern color_t gfx_ow_botogelPal[16];
extern u8 gfx_ow_schlurplekTiles[];
extern color_t gfx_ow_schlurplekPal[16];
extern u8 gfx_ow_panzaeronTiles[];
extern color_t gfx_ow_panzaeronPal[16];
extern u8 gfx_ow_hundusterTiles[];
extern color_t gfx_ow_hundusterPal[16];
extern u8 gfx_ow_hundemonTiles[];
extern color_t gfx_ow_hundemonPal[16];
extern u8 gfx_ow_seedrakingTiles[];
extern color_t gfx_ow_seedrakingPal[16];
extern u8 gfx_ow_phanpyTiles[];
extern color_t gfx_ow_phanpyPal[16];
extern u8 gfx_ow_donphanTiles[];
extern color_t gfx_ow_donphanPal[16];
extern u8 gfx_ow_porygon2Tiles[];
extern color_t gfx_ow_porygon2Pal[16];
extern u8 gfx_ow_voluminasTiles[];
extern color_t gfx_ow_voluminasPal[16];
extern u8 gfx_ow_traunmagilTiles[];
extern color_t gfx_ow_traunmagilPal[16];
extern u8 gfx_ow_rabauzTiles[];
extern color_t gfx_ow_rabauzPal[16];
extern u8 gfx_ow_kapoeraTiles[];
extern color_t gfx_ow_kapoeraPal[16];
extern u8 gfx_ow_elekidTiles[];
extern color_t gfx_ow_elekidPal[16];
extern u8 gfx_ow_magbyTiles[];
extern color_t gfx_ow_magbyPal[16];
extern u8 gfx_ow_miltankTiles[];
extern color_t gfx_ow_miltankPal[16];
extern u8 gfx_ow_heiteiraTiles[];
extern color_t gfx_ow_heiteiraPal[16];
extern u8 gfx_ow_raikouTiles[];
extern color_t gfx_ow_raikouPal[16];
extern u8 gfx_ow_enteiTiles[];
extern color_t gfx_ow_enteiPal[16];
extern u8 gfx_ow_suicuneTiles[];
extern color_t gfx_ow_suicunePal[16];
extern u8 gfx_ow_larvitarTiles[];
extern color_t gfx_ow_larvitarPal[16];
extern u8 gfx_ow_pupitarTiles[];
extern color_t gfx_ow_pupitarPal[16];
extern u8 gfx_ow_despotarTiles[];
extern color_t gfx_ow_despotarPal[16];
extern u8 gfx_ow_lugiaTiles[];
extern color_t gfx_ow_lugiaPal[16];
extern u8 gfx_ow_ho_ohTiles[];
extern color_t gfx_ow_ho_ohPal[16];
extern u8 gfx_ow_celebiTiles[];
extern color_t gfx_ow_celebiPal[16];
extern u8 gfx_ow_durengardaTiles[];
extern color_t gfx_ow_durengardaPal[16];
extern u8 gfx_ow_fiffyenTiles[];
extern color_t gfx_ow_fiffyenPal[16];
extern u8 gfx_ow_magnayenTiles[];
extern color_t gfx_ow_magnayenPal[16];
extern u8 gfx_ow_zigzachsTiles[];
extern color_t gfx_ow_zigzachsPal[16];
extern u8 gfx_ow_geradaksTiles[];
extern color_t gfx_ow_geradaksPal[16];
extern u8 gfx_ow_waumpelTiles[];
extern color_t gfx_ow_waumpelPal[16];
extern u8 gfx_ow_schalokoTiles[];
extern color_t gfx_ow_schalokoPal[16];
extern u8 gfx_ow_papinellaTiles[];
extern color_t gfx_ow_papinellaPal[16];
extern u8 gfx_ow_panekonTiles[];
extern color_t gfx_ow_panekonPal[16];
extern u8 gfx_ow_pudoxTiles[];
extern color_t gfx_ow_pudoxPal[16];
extern u8 gfx_ow_loturzelTiles[];
extern color_t gfx_ow_loturzelPal[16];
extern u8 gfx_ow_lombreroTiles[];
extern color_t gfx_ow_lombreroPal[16];
extern u8 gfx_ow_kappaloresTiles[];
extern color_t gfx_ow_kappaloresPal[16];
extern u8 gfx_ow_samurzelTiles[];
extern color_t gfx_ow_samurzelPal[16];
extern u8 gfx_ow_blanasTiles[];
extern color_t gfx_ow_blanasPal[16];
extern u8 gfx_ow_tengulistTiles[];
extern color_t gfx_ow_tengulistPal[16];
extern u8 gfx_ow_nincadaTiles[];
extern color_t gfx_ow_nincadaPal[16];
extern u8 gfx_ow_ninjaskTiles[];
extern color_t gfx_ow_ninjaskPal[16];
extern u8 gfx_ow_ninjatomTiles[];
extern color_t gfx_ow_ninjatomPal[16];
extern u8 gfx_ow_schwalbiniTiles[];
extern color_t gfx_ow_schwalbiniPal[16];
extern u8 gfx_ow_schwalbossTiles[];
extern color_t gfx_ow_schwalbossPal[16];
extern u8 gfx_ow_knilzTiles[];
extern color_t gfx_ow_knilzPal[16];
extern u8 gfx_ow_kapilzTiles[];
extern color_t gfx_ow_kapilzPal[16];
extern u8 gfx_ow_pandirTiles[];
extern color_t gfx_ow_pandirPal[16];
extern u8 gfx_ow_wingullTiles[];
extern color_t gfx_ow_wingullPal[16];
extern u8 gfx_ow_pelipperTiles[];
extern color_t gfx_ow_pelipperPal[16];
extern u8 gfx_ow_gehweiherTiles[];
extern color_t gfx_ow_gehweiherPal[16];
extern u8 gfx_ow_maskeregenTiles[];
extern color_t gfx_ow_maskeregenPal[16];
extern u8 gfx_ow_wailmerTiles[];
extern color_t gfx_ow_wailmerPal[16];
extern u8 gfx_ow_wailordTiles[];
extern color_t gfx_ow_wailordPal[16];
extern u8 gfx_ow_enecoTiles[];
extern color_t gfx_ow_enecoPal[16];
extern u8 gfx_ow_enekoroTiles[];
extern color_t gfx_ow_enekoroPal[16];
extern u8 gfx_ow_kecleonTiles[];
extern color_t gfx_ow_kecleonPal[16];
extern u8 gfx_ow_puppanceTiles[];
extern color_t gfx_ow_puppancePal[16];
extern u8 gfx_ow_lepumentasTiles[];
extern color_t gfx_ow_lepumentasPal[16];
extern u8 gfx_ow_nasgnetTiles[];
extern color_t gfx_ow_nasgnetPal[16];
extern u8 gfx_ow_magbrantTiles[];
extern color_t gfx_ow_magbrantPal[16];
extern u8 gfx_ow_zwirrfinstTiles[];
extern color_t gfx_ow_zwirrfinstPal[16];
extern u8 gfx_ow_schmerbeTiles[];
extern color_t gfx_ow_schmerbePal[16];
extern u8 gfx_ow_welsarTiles[];
extern color_t gfx_ow_welsarPal[16];
extern u8 gfx_ow_rihorniorTiles[];
extern color_t gfx_ow_rihorniorPal[16];
extern u8 gfx_ow_krebscorpsTiles[];
extern color_t gfx_ow_krebscorpsPal[16];
extern u8 gfx_ow_krebutackTiles[];
extern color_t gfx_ow_krebutackPal[16];
extern u8 gfx_ow_barschwaTiles[];
extern color_t gfx_ow_barschwaPal[16];
extern u8 gfx_ow_miloticTiles[];
extern color_t gfx_ow_miloticPal[16];
extern u8 gfx_ow_kanivanhaTiles[];
extern color_t gfx_ow_kanivanhaPal[16];
extern u8 gfx_ow_tohaidoTiles[];
extern color_t gfx_ow_tohaidoPal[16];
extern u8 gfx_ow_knacklionTiles[];
extern color_t gfx_ow_knacklionPal[16];
extern u8 gfx_ow_vibravaTiles[];
extern color_t gfx_ow_vibravaPal[16];
extern u8 gfx_ow_libelldraTiles[];
extern color_t gfx_ow_libelldraPal[16];
extern u8 gfx_ow_rioluTiles[];
extern color_t gfx_ow_rioluPal[16];
extern u8 gfx_ow_lucarioTiles[];
extern color_t gfx_ow_lucarioPal[16];
extern u8 gfx_ow_frizelblizTiles[];
extern color_t gfx_ow_frizelblizPal[16];
extern u8 gfx_ow_voltensoTiles[];
extern color_t gfx_ow_voltensoPal[16];
extern u8 gfx_ow_camaubTiles[];
extern color_t gfx_ow_camaubPal[16];
extern u8 gfx_ow_cameruptTiles[];
extern color_t gfx_ow_cameruptPal[16];
extern u8 gfx_ow_seemopsTiles[];
extern color_t gfx_ow_seemopsPal[16];
extern u8 gfx_ow_seejongTiles[];
extern color_t gfx_ow_seejongPal[16];
extern u8 gfx_ow_walraisaTiles[];
extern color_t gfx_ow_walraisaPal[16];
extern u8 gfx_ow_tuskaTiles[];
extern color_t gfx_ow_tuskaPal[16];
extern u8 gfx_ow_noktuskaTiles[];
extern color_t gfx_ow_noktuskaPal[16];
extern u8 gfx_ow_schneppkeTiles[];
extern color_t gfx_ow_schneppkePal[16];
extern u8 gfx_ow_firnontorTiles[];
extern color_t gfx_ow_firnontorPal[16];
extern u8 gfx_ow_lunasteinTiles[];
extern color_t gfx_ow_lunasteinPal[16];
extern u8 gfx_ow_sonnfelTiles[];
extern color_t gfx_ow_sonnfelPal[16];
extern u8 gfx_ow_azurillTiles[];
extern color_t gfx_ow_azurillPal[16];
extern u8 gfx_ow_spoinkTiles[];
extern color_t gfx_ow_spoinkPal[16];
extern u8 gfx_ow_groinkTiles[];
extern color_t gfx_ow_groinkPal[16];
extern u8 gfx_ow_plusleTiles[];
extern color_t gfx_ow_pluslePal[16];
extern u8 gfx_ow_minunTiles[];
extern color_t gfx_ow_minunPal[16];
extern u8 gfx_ow_flunkiferTiles[];
extern color_t gfx_ow_flunkiferPal[16];
extern u8 gfx_ow_meditieTiles[];
extern color_t gfx_ow_meditiePal[16];
extern u8 gfx_ow_meditalisTiles[];
extern color_t gfx_ow_meditalisPal[16];
extern u8 gfx_ow_wabluTiles[];
extern color_t gfx_ow_wabluPal[16];
extern u8 gfx_ow_altariaTiles[];
extern color_t gfx_ow_altariaPal[16];
extern u8 gfx_ow_klingplimTiles[];
extern color_t gfx_ow_klingplimPal[16];
extern u8 gfx_ow_zwirrlichtTiles[];
extern color_t gfx_ow_zwirrlichtPal[16];
extern u8 gfx_ow_zwirrklopTiles[];
extern color_t gfx_ow_zwirrklopPal[16];
extern u8 gfx_ow_porygon_zTiles[];
extern color_t gfx_ow_porygon_zPal[16];
extern u8 gfx_ow_bummelzTiles[];
extern color_t gfx_ow_bummelzPal[16];
extern u8 gfx_ow_muntierTiles[];
extern color_t gfx_ow_muntierPal[16];
extern u8 gfx_ow_letarkingTiles[];
extern color_t gfx_ow_letarkingPal[16];
extern u8 gfx_ow_schluppuckTiles[];
extern color_t gfx_ow_schluppuckPal[16];
extern u8 gfx_ow_schlukwechTiles[];
extern color_t gfx_ow_schlukwechPal[16];
extern u8 gfx_ow_tropiusTiles[];
extern color_t gfx_ow_tropiusPal[16];
extern u8 gfx_ow_kaumalatTiles[];
extern color_t gfx_ow_kaumalatPal[16];
extern u8 gfx_ow_knarkselTiles[];
extern color_t gfx_ow_knarkselPal[16];
extern u8 gfx_ow_knakrackTiles[];
extern color_t gfx_ow_knakrackPal[16];
extern u8 gfx_ow_perluTiles[];
extern color_t gfx_ow_perluPal[16];
extern u8 gfx_ow_aalabyssTiles[];
extern color_t gfx_ow_aalabyssPal[16];
extern u8 gfx_ow_saganabyssTiles[];
extern color_t gfx_ow_saganabyssPal[16];
extern u8 gfx_ow_absolTiles[];
extern color_t gfx_ow_absolPal[16];
extern u8 gfx_ow_shuppetTiles[];
extern color_t gfx_ow_shuppetPal[16];
extern u8 gfx_ow_banetteTiles[];
extern color_t gfx_ow_banettePal[16];
extern u8 gfx_ow_vipitisTiles[];
extern color_t gfx_ow_vipitisPal[16];
extern u8 gfx_ow_sengoTiles[];
extern color_t gfx_ow_sengoPal[16];
extern u8 gfx_ow_relicanthTiles[];
extern color_t gfx_ow_relicanthPal[16];
extern u8 gfx_ow_stolluniorTiles[];
extern color_t gfx_ow_stolluniorPal[16];
extern u8 gfx_ow_stollrakTiles[];
extern color_t gfx_ow_stollrakPal[16];
extern u8 gfx_ow_stollossTiles[];
extern color_t gfx_ow_stollossPal[16];
extern u8 gfx_ow_formeoTiles[];
extern color_t gfx_ow_formeoPal[16];
extern u8 gfx_ow_wonneiraTiles[];
extern color_t gfx_ow_wonneiraPal[16];
extern u8 gfx_ow_mobaiTiles[];
extern color_t gfx_ow_mobaiPal[16];
extern u8 gfx_ow_liliepTiles[];
extern color_t gfx_ow_liliepPal[16];
extern u8 gfx_ow_wielieTiles[];
extern color_t gfx_ow_wieliePal[16];
extern u8 gfx_ow_anorithTiles[];
extern color_t gfx_ow_anorithPal[16];
extern u8 gfx_ow_armaldoTiles[];
extern color_t gfx_ow_armaldoPal[16];
extern u8 gfx_ow_traslaTiles[];
extern color_t gfx_ow_traslaPal[16];
extern u8 gfx_ow_kirliaTiles[];
extern color_t gfx_ow_kirliaPal[16];
extern u8 gfx_ow_guardevoirTiles[];
extern color_t gfx_ow_guardevoirPal[16];
extern u8 gfx_ow_kindwurmTiles[];
extern color_t gfx_ow_kindwurmPal[16];
extern u8 gfx_ow_draschelTiles[];
extern color_t gfx_ow_draschelPal[16];
extern u8 gfx_ow_brutalandaTiles[];
extern color_t gfx_ow_brutalandaPal[16];
extern u8 gfx_ow_tanhelTiles[];
extern color_t gfx_ow_tanhelPal[16];
extern u8 gfx_ow_metangTiles[];
extern color_t gfx_ow_metangPal[16];
extern u8 gfx_ow_metagrossTiles[];
extern color_t gfx_ow_metagrossPal[16];
extern u8 gfx_ow_regirockTiles[];
extern color_t gfx_ow_regirockPal[16];
extern u8 gfx_ow_regiceTiles[];
extern color_t gfx_ow_regicePal[16];
extern u8 gfx_ow_registeelTiles[];
extern color_t gfx_ow_registeelPal[16];
extern u8 gfx_ow_kyogreTiles[];
extern color_t gfx_ow_kyogrePal[16];
extern u8 gfx_ow_groudonTiles[];
extern color_t gfx_ow_groudonPal[16];
extern u8 gfx_ow_rayquazaTiles[];
extern color_t gfx_ow_rayquazaPal[16];
extern u8 gfx_ow_latiasTiles[];
extern color_t gfx_ow_latiasPal[16];
extern u8 gfx_ow_latiosTiles[];
extern color_t gfx_ow_latiosPal[16];
extern u8 gfx_ow_jirachiTiles[];
extern color_t gfx_ow_jirachiPal[16];
extern u8 gfx_ow_deoxysTiles[];
extern color_t gfx_ow_deoxysPal[16];
extern u8 gfx_ow_palimpalimTiles[];
extern color_t gfx_ow_palimpalimPal[16];
extern u8 gfx_ow_icognito_bTiles[];
extern color_t gfx_ow_icognito_bPal[16];
extern u8 gfx_ow_icognito_cTiles[];
extern color_t gfx_ow_icognito_cPal[16];
extern u8 gfx_ow_icognito_dTiles[];
extern color_t gfx_ow_icognito_dPal[16];
extern u8 gfx_ow_icognito_eTiles[];
extern color_t gfx_ow_icognito_ePal[16];
extern u8 gfx_ow_icognito_fTiles[];
extern color_t gfx_ow_icognito_fPal[16];
extern u8 gfx_ow_icognito_gTiles[];
extern color_t gfx_ow_icognito_gPal[16];
extern u8 gfx_ow_icognito_hTiles[];
extern color_t gfx_ow_icognito_hPal[16];
extern u8 gfx_ow_icognito_iTiles[];
extern color_t gfx_ow_icognito_iPal[16];
extern u8 gfx_ow_icognito_jTiles[];
extern color_t gfx_ow_icognito_jPal[16];
extern u8 gfx_ow_icognito_kTiles[];
extern color_t gfx_ow_icognito_kPal[16];
extern u8 gfx_ow_icognito_lTiles[];
extern color_t gfx_ow_icognito_lPal[16];
extern u8 gfx_ow_icognito_mTiles[];
extern color_t gfx_ow_icognito_mPal[16];
extern u8 gfx_ow_icognito_nTiles[];
extern color_t gfx_ow_icognito_nPal[16];
extern u8 gfx_ow_icognito_oTiles[];
extern color_t gfx_ow_icognito_oPal[16];
extern u8 gfx_ow_icognito_pTiles[];
extern color_t gfx_ow_icognito_pPal[16];
extern u8 gfx_ow_icognito_qTiles[];
extern color_t gfx_ow_icognito_qPal[16];
extern u8 gfx_ow_icognito_rTiles[];
extern color_t gfx_ow_icognito_rPal[16];
extern u8 gfx_ow_icognito_sTiles[];
extern color_t gfx_ow_icognito_sPal[16];
extern u8 gfx_ow_icognito_tTiles[];
extern color_t gfx_ow_icognito_tPal[16];
extern u8 gfx_ow_icognito_uTiles[];
extern color_t gfx_ow_icognito_uPal[16];
extern u8 gfx_ow_icognito_vTiles[];
extern color_t gfx_ow_icognito_vPal[16];
extern u8 gfx_ow_icognito_wTiles[];
extern color_t gfx_ow_icognito_wPal[16];
extern u8 gfx_ow_icognito_xTiles[];
extern color_t gfx_ow_icognito_xPal[16];
extern u8 gfx_ow_icognito_yTiles[];
extern color_t gfx_ow_icognito_yPal[16];
extern u8 gfx_ow_icognito_zTiles[];
extern color_t gfx_ow_icognito_zPal[16];
extern u8 gfx_ow_icognito_exclamationTiles[];
extern color_t gfx_ow_icognito_exclamationPal[16];
extern u8 gfx_ow_icognito_questionTiles[];
extern color_t gfx_ow_icognito_questionPal[16];
extern const unsigned short gfx_ow_deoxys_normal_0Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_1Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_2Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_3Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_4Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_5Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_6Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_7Tiles[];
extern const unsigned short gfx_ow_deoxys_normal_8Tiles[];
extern const unsigned short gfx_ow_registeel_0Tiles[];
extern const unsigned short gfx_ow_registeel_1Tiles[];
extern const unsigned short gfx_ow_registeel_2Tiles[];
extern const unsigned short gfx_ow_registeel_3Tiles[];
extern const unsigned short gfx_ow_registeel_4Tiles[];
extern const unsigned short gfx_ow_registeel_5Tiles[];
extern const unsigned short gfx_ow_registeel_6Tiles[];
extern const unsigned short gfx_ow_registeel_7Tiles[];
extern const unsigned short gfx_ow_registeel_8Tiles[];
extern const unsigned short gfx_ow_regice_0Tiles[];
extern const unsigned short gfx_ow_regice_1Tiles[];
extern const unsigned short gfx_ow_regice_2Tiles[];
extern const unsigned short gfx_ow_regice_3Tiles[];
extern const unsigned short gfx_ow_regice_4Tiles[];
extern const unsigned short gfx_ow_regice_5Tiles[];
extern const unsigned short gfx_ow_regice_6Tiles[];
extern const unsigned short gfx_ow_regice_7Tiles[];
extern const unsigned short gfx_ow_regice_8Tiles[];
extern const unsigned short gfx_ow_regirock_0Tiles[];
extern const unsigned short gfx_ow_regirock_1Tiles[];
extern const unsigned short gfx_ow_regirock_2Tiles[];
extern const unsigned short gfx_ow_regirock_3Tiles[];
extern const unsigned short gfx_ow_regirock_4Tiles[];
extern const unsigned short gfx_ow_regirock_5Tiles[];
extern const unsigned short gfx_ow_regirock_6Tiles[];
extern const unsigned short gfx_ow_regirock_7Tiles[];
extern const unsigned short gfx_ow_regirock_8Tiles[];
extern const unsigned short gfx_ow_voltilamm_0Tiles[];
extern const unsigned short gfx_ow_voltilamm_1Tiles[];
extern const unsigned short gfx_ow_voltilamm_2Tiles[];
extern const unsigned short gfx_ow_voltilamm_3Tiles[];
extern const unsigned short gfx_ow_voltilamm_4Tiles[];
extern const unsigned short gfx_ow_voltilamm_5Tiles[];
extern const unsigned short gfx_ow_voltilamm_6Tiles[];
extern const unsigned short gfx_ow_voltilamm_7Tiles[];
extern const unsigned short gfx_ow_voltilamm_8Tiles[];
extern const unsigned short gfx_ow_staralili_0Tiles[];
extern const unsigned short gfx_ow_staralili_1Tiles[];
extern const unsigned short gfx_ow_staralili_2Tiles[];
extern const unsigned short gfx_ow_staralili_3Tiles[];
extern const unsigned short gfx_ow_staralili_4Tiles[];
extern const unsigned short gfx_ow_staralili_5Tiles[];
extern const unsigned short gfx_ow_staralili_6Tiles[];
extern const unsigned short gfx_ow_staralili_7Tiles[];
extern const unsigned short gfx_ow_staralili_8Tiles[];
extern const unsigned short gfx_ow_larissa_0Tiles[];
extern const unsigned short gfx_ow_larissa_1Tiles[];
extern const unsigned short gfx_ow_larissa_2Tiles[];
extern const unsigned short gfx_ow_larissa_3Tiles[];
extern const unsigned short gfx_ow_larissa_4Tiles[];
extern const unsigned short gfx_ow_larissa_5Tiles[];
extern const unsigned short gfx_ow_larissa_6Tiles[];
extern const unsigned short gfx_ow_larissa_7Tiles[];
extern const unsigned short gfx_ow_larissa_8Tiles[];
extern const unsigned short gfx_ow_elise_0Tiles[];
extern const unsigned short gfx_ow_elise_1Tiles[];
extern const unsigned short gfx_ow_elise_2Tiles[];
extern const unsigned short gfx_ow_elise_3Tiles[];
extern const unsigned short gfx_ow_elise_4Tiles[];
extern const unsigned short gfx_ow_elise_5Tiles[];
extern const unsigned short gfx_ow_elise_6Tiles[];
extern const unsigned short gfx_ow_elise_7Tiles[];
extern const unsigned short gfx_ow_elise_8Tiles[];
extern const unsigned short gfx_ow_faun_young_0Tiles[];
extern const unsigned short gfx_ow_faun_young_1Tiles[];
extern const unsigned short gfx_ow_faun_young_2Tiles[];
extern const unsigned short gfx_ow_faun_young_3Tiles[];
extern const unsigned short gfx_ow_faun_young_4Tiles[];
extern const unsigned short gfx_ow_faun_young_5Tiles[];
extern const unsigned short gfx_ow_faun_young_6Tiles[];
extern const unsigned short gfx_ow_faun_young_7Tiles[];
extern const unsigned short gfx_ow_faun_young_8Tiles[];
extern const unsigned short gfx_ow_egg_0Tiles[];
extern const unsigned short gfx_ow_rin_0Tiles[];
extern const unsigned short gfx_ow_rin_1Tiles[];
extern const unsigned short gfx_ow_rin_2Tiles[];
extern const unsigned short gfx_ow_rin_3Tiles[];
extern const unsigned short gfx_ow_rin_4Tiles[];
extern const unsigned short gfx_ow_rin_5Tiles[];
extern const unsigned short gfx_ow_rin_6Tiles[];
extern const unsigned short gfx_ow_rin_7Tiles[];
extern const unsigned short gfx_ow_rin_8Tiles[];
extern const unsigned short gfx_ow_blaise_0Tiles[];
extern const unsigned short gfx_ow_blaise_1Tiles[];
extern const unsigned short gfx_ow_blaise_2Tiles[];
extern const unsigned short gfx_ow_blaise_3Tiles[];
extern const unsigned short gfx_ow_blaise_4Tiles[];
extern const unsigned short gfx_ow_blaise_5Tiles[];
extern const unsigned short gfx_ow_blaise_6Tiles[];
extern const unsigned short gfx_ow_blaise_7Tiles[];
extern const unsigned short gfx_ow_blaise_8Tiles[];
extern const unsigned short gfx_ow_mia_0Tiles[];
extern const unsigned short gfx_ow_mia_1Tiles[];
extern const unsigned short gfx_ow_mia_2Tiles[];
extern const unsigned short gfx_ow_mia_3Tiles[];
extern const unsigned short gfx_ow_mia_4Tiles[];
extern const unsigned short gfx_ow_mia_5Tiles[];
extern const unsigned short gfx_ow_mia_6Tiles[];
extern const unsigned short gfx_ow_mia_7Tiles[];
extern const unsigned short gfx_ow_mia_8Tiles[];
extern const u8 gfx_ow_lesterTiles[];
extern const unsigned short gfx_ow_faun_0Tiles[];
extern const unsigned short gfx_ow_faun_1Tiles[];
extern const unsigned short gfx_ow_faun_2Tiles[];
extern const unsigned short gfx_ow_faun_3Tiles[];
extern const unsigned short gfx_ow_faun_4Tiles[];
extern const unsigned short gfx_ow_faun_5Tiles[];
extern const unsigned short gfx_ow_faun_6Tiles[];
extern const unsigned short gfx_ow_faun_7Tiles[];
extern const unsigned short gfx_ow_faun_8Tiles[];
extern const unsigned short gfx_ow_revolutionary_0Tiles[];
extern const unsigned short gfx_ow_revolutionary_1Tiles[];
extern const unsigned short gfx_ow_revolutionary_2Tiles[];
extern const unsigned short gfx_ow_revolutionary_3Tiles[];
extern const unsigned short gfx_ow_revolutionary_4Tiles[];
extern const unsigned short gfx_ow_revolutionary_5Tiles[];
extern const unsigned short gfx_ow_revolutionary_6Tiles[];
extern const unsigned short gfx_ow_revolutionary_7Tiles[];
extern const unsigned short gfx_ow_revolutionary_8Tiles[];
extern const unsigned short gfx_ow_rival_0Tiles[];
extern const unsigned short gfx_ow_rival_1Tiles[];
extern const unsigned short gfx_ow_rival_2Tiles[];
extern const unsigned short gfx_ow_rival_3Tiles[];
extern const unsigned short gfx_ow_rival_4Tiles[];
extern const unsigned short gfx_ow_rival_5Tiles[];
extern const unsigned short gfx_ow_rival_6Tiles[];
extern const unsigned short gfx_ow_rival_7Tiles[];
extern const unsigned short gfx_ow_rival_8Tiles[];
extern const unsigned short gfx_ow_tann_0Tiles[];
extern const unsigned short gfx_ow_tann_1Tiles[];
extern const unsigned short gfx_ow_tann_2Tiles[];
extern const unsigned short gfx_ow_tann_3Tiles[];
extern const unsigned short gfx_ow_tann_4Tiles[];
extern const unsigned short gfx_ow_tann_5Tiles[];
extern const unsigned short gfx_ow_tann_6Tiles[];
extern const unsigned short gfx_ow_tann_7Tiles[];
extern const unsigned short gfx_ow_tann_8Tiles[];
extern const unsigned short gfx_ow_felix_0Tiles[];
extern const unsigned short gfx_ow_felix_1Tiles[];
extern const unsigned short gfx_ow_felix_2Tiles[];
extern const unsigned short gfx_ow_felix_3Tiles[];
extern const unsigned short gfx_ow_felix_4Tiles[];
extern const unsigned short gfx_ow_felix_5Tiles[];
extern const unsigned short gfx_ow_felix_6Tiles[];
extern const unsigned short gfx_ow_felix_7Tiles[];
extern const unsigned short gfx_ow_felix_8Tiles[];
extern const unsigned short gfx_ow_albus_0Tiles[];
extern const unsigned short gfx_ow_albus_1Tiles[];
extern const unsigned short gfx_ow_albus_2Tiles[];
extern const unsigned short gfx_ow_albus_3Tiles[];
extern const unsigned short gfx_ow_albus_4Tiles[];
extern const unsigned short gfx_ow_albus_5Tiles[];
extern const unsigned short gfx_ow_albus_6Tiles[];
extern const unsigned short gfx_ow_albus_7Tiles[];
extern const unsigned short gfx_ow_albus_8Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_0Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_1Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_2Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_3Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_4Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_5Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_6Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_7Tiles[];
extern const unsigned short gfx_ow_violet_grunt_f_8Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_0Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_1Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_2Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_3Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_4Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_5Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_6Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_7Tiles[];
extern const unsigned short gfx_ow_violet_grunt_m_8Tiles[];
extern const unsigned short gfx_ow_primus_0Tiles[];
extern const unsigned short gfx_ow_primus_1Tiles[];
extern const unsigned short gfx_ow_primus_2Tiles[];
extern const unsigned short gfx_ow_primus_3Tiles[];
extern const unsigned short gfx_ow_primus_4Tiles[];
extern const unsigned short gfx_ow_primus_5Tiles[];
extern const unsigned short gfx_ow_primus_6Tiles[];
extern const unsigned short gfx_ow_primus_7Tiles[];
extern const unsigned short gfx_ow_primus_8Tiles[];
extern const unsigned short gfx_ow_hiro_call_bike_0Tiles[];
extern const unsigned short gfx_ow_hiro_call_bike_1Tiles[];
extern const unsigned short gfx_ow_hiro_call_bike_2Tiles[];
extern const unsigned short gfx_ow_hiro_call_bike_3Tiles[];
extern const unsigned short gfx_ow_hiro_call_bike_4Tiles[];
extern const unsigned short gfx_ow_hiro_call_bike_5Tiles[];
extern const unsigned short gfx_ow_hiro_call2_0Tiles[];
extern const unsigned short gfx_ow_hiro_call2_1Tiles[];
extern const unsigned short gfx_ow_hiro_call2_2Tiles[];
extern const unsigned short gfx_ow_hiro_call2_3Tiles[];
extern const unsigned short gfx_ow_hiro_call2_4Tiles[];
extern const unsigned short gfx_ow_hiro_call2_5Tiles[];
extern const unsigned short gfx_ow_hiro_call2_6Tiles[];
extern const unsigned short gfx_ow_hiro_call2_7Tiles[];
extern const unsigned short gfx_ow_hiro_call2_8Tiles[];
extern const unsigned short gfx_ow_hiro_rod_0Tiles[];
extern const unsigned short gfx_ow_hiro_rod_1Tiles[];
extern const unsigned short gfx_ow_hiro_rod_2Tiles[];
extern const unsigned short gfx_ow_hiro_rod_3Tiles[];
extern const unsigned short gfx_ow_hiro_rod_4Tiles[];
extern const unsigned short gfx_ow_hiro_rod_5Tiles[];
extern const unsigned short gfx_ow_hiro_rod_6Tiles[];
extern const unsigned short gfx_ow_hiro_rod_7Tiles[];
extern const unsigned short gfx_ow_hiro_rod_8Tiles[];
extern const unsigned short gfx_ow_hiro_rod_9Tiles[];
extern const unsigned short gfx_ow_hiro_rod_10Tiles[];
extern const unsigned short gfx_ow_hiro_rod_11Tiles[];
extern const unsigned short gfx_ow_hiro_call_0Tiles[];
extern const unsigned short gfx_ow_hiro_call_1Tiles[];
extern const unsigned short gfx_ow_hiro_call_2Tiles[];
extern const unsigned short gfx_ow_hiro_call_3Tiles[];
extern const unsigned short gfx_ow_hiro_call_4Tiles[];
extern const unsigned short gfx_ow_hiro_call_5Tiles[];
extern const unsigned short gfx_ow_hiro_call_6Tiles[];
extern const unsigned short gfx_ow_hiro_call_7Tiles[];
extern const unsigned short gfx_ow_hiro_call_8Tiles[];
extern const unsigned short gfx_ow_hiro_sit_0Tiles[];
extern const unsigned short gfx_ow_hiro_sit_1Tiles[];
extern const unsigned short gfx_ow_hiro_sit_2Tiles[];
extern const unsigned short gfx_ow_hiro_sit_3Tiles[];
extern const unsigned short gfx_ow_hiro_sit_4Tiles[];
extern const unsigned short gfx_ow_hiro_sit_5Tiles[];
extern const unsigned short gfx_ow_hiro_sit_6Tiles[];
extern const unsigned short gfx_ow_hiro_sit_7Tiles[];
extern const unsigned short gfx_ow_hiro_sit_8Tiles[];
extern const unsigned short gfx_ow_hiro_sit_9Tiles[];
extern const unsigned short gfx_ow_hiro_sit_10Tiles[];
extern const unsigned short gfx_ow_hiro_sit_11Tiles[];
extern const unsigned short gfx_ow_hiro_0Tiles[];
extern const unsigned short gfx_ow_hiro_1Tiles[];
extern const unsigned short gfx_ow_hiro_2Tiles[];
extern const unsigned short gfx_ow_hiro_3Tiles[];
extern const unsigned short gfx_ow_hiro_4Tiles[];
extern const unsigned short gfx_ow_hiro_5Tiles[];
extern const unsigned short gfx_ow_hiro_6Tiles[];
extern const unsigned short gfx_ow_hiro_7Tiles[];
extern const unsigned short gfx_ow_hiro_8Tiles[];
extern const unsigned short gfx_ow_hiro_9Tiles[];
extern const unsigned short gfx_ow_hiro_10Tiles[];
extern const unsigned short gfx_ow_hiro_11Tiles[];
extern const unsigned short gfx_ow_hiro_12Tiles[];
extern const unsigned short gfx_ow_hiro_13Tiles[];
extern const unsigned short gfx_ow_hiro_14Tiles[];
extern const unsigned short gfx_ow_hiro_15Tiles[];
extern const unsigned short gfx_ow_hiro_16Tiles[];
extern const unsigned short gfx_ow_hiro_17Tiles[];
extern const unsigned short gfx_ow_hiro_18Tiles[];
extern const unsigned short gfx_ow_hiro_19Tiles[];
extern const unsigned short gfx_ow_hiroine_0Tiles[];
extern const unsigned short gfx_ow_hiroine_1Tiles[];
extern const unsigned short gfx_ow_hiroine_2Tiles[];
extern const unsigned short gfx_ow_hiroine_3Tiles[];
extern const unsigned short gfx_ow_hiroine_4Tiles[];
extern const unsigned short gfx_ow_hiroine_5Tiles[];
extern const unsigned short gfx_ow_hiroine_6Tiles[];
extern const unsigned short gfx_ow_hiroine_7Tiles[];
extern const unsigned short gfx_ow_hiroine_8Tiles[];
extern const unsigned short gfx_ow_hiroine_9Tiles[];
extern const unsigned short gfx_ow_hiroine_10Tiles[];
extern const unsigned short gfx_ow_hiroine_11Tiles[];
extern const unsigned short gfx_ow_hiroine_12Tiles[];
extern const unsigned short gfx_ow_hiroine_13Tiles[];
extern const unsigned short gfx_ow_hiroine_14Tiles[];
extern const unsigned short gfx_ow_hiroine_15Tiles[];
extern const unsigned short gfx_ow_hiroine_16Tiles[];
extern const unsigned short gfx_ow_hiroine_17Tiles[];
extern const unsigned short gfx_ow_hiroine_18Tiles[];
extern const unsigned short gfx_ow_hiroine_19Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_0Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_1Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_2Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_3Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_4Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_5Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_6Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_7Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_8Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_9Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_10Tiles[];
extern const unsigned short gfx_ow_hiroine_rod_11Tiles[];
extern const unsigned short gfx_ow_hiroine_call_0Tiles[];
extern const unsigned short gfx_ow_hiroine_call_1Tiles[];
extern const unsigned short gfx_ow_hiroine_call_2Tiles[];
extern const unsigned short gfx_ow_hiroine_call_3Tiles[];
extern const unsigned short gfx_ow_hiroine_call_4Tiles[];
extern const unsigned short gfx_ow_hiroine_call_5Tiles[];
extern const unsigned short gfx_pskate_0Tiles[];
extern const unsigned short gfx_pskate_1Tiles[];
extern const unsigned short gfx_pskate_2Tiles[];
extern const unsigned short gfx_pskate_3Tiles[];
extern const unsigned short gfx_pskate_4Tiles[];
extern const unsigned short gfx_pskate_5Tiles[];
extern const unsigned short gfx_pskate_6Tiles[];
extern const unsigned short gfx_pskate_7Tiles[];
extern const unsigned short gfx_pskate_8Tiles[];
extern const unsigned short gfx_pskatef_0Tiles[];
extern const unsigned short gfx_pskatef_1Tiles[];
extern const unsigned short gfx_pskatef_2Tiles[];
extern const unsigned short gfx_pskatef_3Tiles[];
extern const unsigned short gfx_pskatef_4Tiles[];
extern const unsigned short gfx_pskatef_5Tiles[];
extern const unsigned short gfx_pskatef_6Tiles[];
extern const unsigned short gfx_pskatef_7Tiles[];
extern const unsigned short gfx_pskatef_8Tiles[];
extern const unsigned short gfx_ow_igva_0Tiles[];
extern const unsigned short gfx_ow_igva_0Tiles[];
extern const unsigned short gfx_ow_igva_1Tiles[];
extern const unsigned short gfx_ow_igva_1Tiles[];
extern const unsigned short gfx_ow_igva_2Tiles[];
extern const unsigned short gfx_ow_igva_2Tiles[];
extern const unsigned short gfx_ow_igva_3Tiles[];
extern const unsigned short gfx_ow_igva_3Tiles[];
extern const unsigned short gfx_ow_igva_4Tiles[];
extern const unsigned short gfx_ow_igva_4Tiles[];
extern const unsigned short gfx_ow_igva_5Tiles[];
extern const unsigned short gfx_ow_igva_5Tiles[];
extern const unsigned short gfx_ow_igva_6Tiles[];
extern const unsigned short gfx_ow_igva_6Tiles[];
extern const unsigned short gfx_ow_igva_7Tiles[];
extern const unsigned short gfx_ow_igva_7Tiles[];
extern const unsigned short gfx_ow_igva_8Tiles[];
extern const unsigned short gfx_ow_igva_8Tiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_bbshipTiles[];
extern const unsigned short gfx_ow_mpirate_0Tiles[];
extern const unsigned short gfx_ow_mpirate_0Tiles[];
extern const unsigned short gfx_ow_mpirate_1Tiles[];
extern const unsigned short gfx_ow_mpirate_1Tiles[];
extern const unsigned short gfx_ow_mpirate_2Tiles[];
extern const unsigned short gfx_ow_mpirate_2Tiles[];
extern const unsigned short gfx_ow_mpirate_3Tiles[];
extern const unsigned short gfx_ow_mpirate_3Tiles[];
extern const unsigned short gfx_ow_mpirate_4Tiles[];
extern const unsigned short gfx_ow_mpirate_4Tiles[];
extern const unsigned short gfx_ow_mpirate_5Tiles[];
extern const unsigned short gfx_ow_mpirate_5Tiles[];
extern const unsigned short gfx_ow_mpirate_6Tiles[];
extern const unsigned short gfx_ow_mpirate_6Tiles[];
extern const unsigned short gfx_ow_mpirate_7Tiles[];
extern const unsigned short gfx_ow_mpirate_7Tiles[];
extern const unsigned short gfx_ow_mpirate_8Tiles[];
extern const unsigned short gfx_ow_mpirate_8Tiles[];
extern const unsigned short gfx_ow_shape_animal_0Tiles[];
extern const unsigned short gfx_ow_shape_animal_0Tiles[];
extern const unsigned short gfx_ow_shape_animal_1Tiles[];
extern const unsigned short gfx_ow_shape_animal_1Tiles[];
extern const unsigned short gfx_ow_shape_animal_2Tiles[];
extern const unsigned short gfx_ow_shape_animal_2Tiles[];
extern const unsigned short gfx_ow_shape_animal_0Tiles[];
extern const unsigned short gfx_ow_shape_animal_0Tiles[];
extern const unsigned short gfx_ow_shape_animal_1Tiles[];
extern const unsigned short gfx_ow_shape_animal_1Tiles[];
extern const unsigned short gfx_ow_shape_animal_2Tiles[];
extern const unsigned short gfx_ow_shape_animal_2Tiles[];
extern const unsigned short gfx_ow_shape_human_0Tiles[];
extern const unsigned short gfx_ow_shape_human_0Tiles[];
extern const unsigned short gfx_ow_shape_human_1Tiles[];
extern const unsigned short gfx_ow_shape_human_1Tiles[];
extern const unsigned short gfx_ow_shape_human_2Tiles[];
extern const unsigned short gfx_ow_shape_human_2Tiles[];
extern const unsigned short gfx_ow_shape_human_0Tiles[];
extern const unsigned short gfx_ow_shape_human_0Tiles[];
extern const unsigned short gfx_ow_shape_human_1Tiles[];
extern const unsigned short gfx_ow_shape_human_1Tiles[];
extern const unsigned short gfx_ow_shape_human_2Tiles[];
extern const unsigned short gfx_ow_shape_human_2Tiles[];
extern const unsigned short gfx_ow_shape_tail_0Tiles[];
extern const unsigned short gfx_ow_shape_tail_0Tiles[];
extern const unsigned short gfx_ow_shape_tail_1Tiles[];
extern const unsigned short gfx_ow_shape_tail_1Tiles[];
extern const unsigned short gfx_ow_shape_tail_2Tiles[];
extern const unsigned short gfx_ow_shape_tail_2Tiles[];
extern const unsigned short gfx_ow_shape_tail_0Tiles[];
extern const unsigned short gfx_ow_shape_tail_0Tiles[];
extern const unsigned short gfx_ow_shape_tail_1Tiles[];
extern const unsigned short gfx_ow_shape_tail_1Tiles[];
extern const unsigned short gfx_ow_shape_tail_2Tiles[];
extern const unsigned short gfx_ow_shape_tail_2Tiles[];
extern const unsigned short gfx_ow_shape_snake_0Tiles[];
extern const unsigned short gfx_ow_shape_snake_0Tiles[];
extern const unsigned short gfx_ow_shape_snake_1Tiles[];
extern const unsigned short gfx_ow_shape_snake_1Tiles[];
extern const unsigned short gfx_ow_shape_snake_2Tiles[];
extern const unsigned short gfx_ow_shape_snake_2Tiles[];
extern const unsigned short gfx_ow_shape_snake_0Tiles[];
extern const unsigned short gfx_ow_shape_snake_0Tiles[];
extern const unsigned short gfx_ow_shape_snake_1Tiles[];
extern const unsigned short gfx_ow_shape_snake_1Tiles[];
extern const unsigned short gfx_ow_shape_snake_2Tiles[];
extern const unsigned short gfx_ow_shape_snake_2Tiles[];
extern const unsigned short gfx_ow_shape_winsect_0Tiles[];
extern const unsigned short gfx_ow_shape_winsect_0Tiles[];
extern const unsigned short gfx_ow_shape_winsect_1Tiles[];
extern const unsigned short gfx_ow_shape_winsect_1Tiles[];
extern const unsigned short gfx_ow_shape_winsect_2Tiles[];
extern const unsigned short gfx_ow_shape_winsect_2Tiles[];
extern const unsigned short gfx_ow_shape_winsect_0Tiles[];
extern const unsigned short gfx_ow_shape_winsect_0Tiles[];
extern const unsigned short gfx_ow_shape_winsect_1Tiles[];
extern const unsigned short gfx_ow_shape_winsect_1Tiles[];
extern const unsigned short gfx_ow_shape_winsect_2Tiles[];
extern const unsigned short gfx_ow_shape_winsect_2Tiles[];
extern const unsigned short gfx_ow_shape_winged_0Tiles[];
extern const unsigned short gfx_ow_shape_winged_0Tiles[];
extern const unsigned short gfx_ow_shape_winged_1Tiles[];
extern const unsigned short gfx_ow_shape_winged_1Tiles[];
extern const unsigned short gfx_ow_shape_winged_2Tiles[];
extern const unsigned short gfx_ow_shape_winged_2Tiles[];
extern const unsigned short gfx_ow_shape_winged_0Tiles[];
extern const unsigned short gfx_ow_shape_winged_0Tiles[];
extern const unsigned short gfx_ow_shape_winged_1Tiles[];
extern const unsigned short gfx_ow_shape_winged_1Tiles[];
extern const unsigned short gfx_ow_shape_winged_2Tiles[];
extern const unsigned short gfx_ow_shape_winged_2Tiles[];
extern const unsigned short gfx_ow_shape_insect_0Tiles[];
extern const unsigned short gfx_ow_shape_insect_0Tiles[];
extern const unsigned short gfx_ow_shape_insect_1Tiles[];
extern const unsigned short gfx_ow_shape_insect_1Tiles[];
extern const unsigned short gfx_ow_shape_insect_2Tiles[];
extern const unsigned short gfx_ow_shape_insect_2Tiles[];
extern const unsigned short gfx_ow_shape_insect_0Tiles[];
extern const unsigned short gfx_ow_shape_insect_0Tiles[];
extern const unsigned short gfx_ow_shape_insect_1Tiles[];
extern const unsigned short gfx_ow_shape_insect_1Tiles[];
extern const unsigned short gfx_ow_shape_insect_2Tiles[];
extern const unsigned short gfx_ow_shape_insect_2Tiles[];
extern const unsigned short gfx_ow_shape_head_0Tiles[];
extern const unsigned short gfx_ow_shape_head_0Tiles[];
extern const unsigned short gfx_ow_shape_head_1Tiles[];
extern const unsigned short gfx_ow_shape_head_1Tiles[];
extern const unsigned short gfx_ow_shape_head_2Tiles[];
extern const unsigned short gfx_ow_shape_head_2Tiles[];
extern const unsigned short gfx_ow_shape_head_0Tiles[];
extern const unsigned short gfx_ow_shape_head_0Tiles[];
extern const unsigned short gfx_ow_shape_head_1Tiles[];
extern const unsigned short gfx_ow_shape_head_1Tiles[];
extern const unsigned short gfx_ow_shape_head_2Tiles[];
extern const unsigned short gfx_ow_shape_head_2Tiles[];
extern const unsigned short gfx_ow_shape_arms_0Tiles[];
extern const unsigned short gfx_ow_shape_arms_0Tiles[];
extern const unsigned short gfx_ow_shape_arms_1Tiles[];
extern const unsigned short gfx_ow_shape_arms_1Tiles[];
extern const unsigned short gfx_ow_shape_arms_2Tiles[];
extern const unsigned short gfx_ow_shape_arms_2Tiles[];
extern const unsigned short gfx_ow_shape_arms_0Tiles[];
extern const unsigned short gfx_ow_shape_arms_0Tiles[];
extern const unsigned short gfx_ow_shape_arms_1Tiles[];
extern const unsigned short gfx_ow_shape_arms_1Tiles[];
extern const unsigned short gfx_ow_shape_arms_2Tiles[];
extern const unsigned short gfx_ow_shape_arms_2Tiles[];
extern const unsigned short gfx_ow_shape_legs_0Tiles[];
extern const unsigned short gfx_ow_shape_legs_0Tiles[];
extern const unsigned short gfx_ow_shape_legs_1Tiles[];
extern const unsigned short gfx_ow_shape_legs_1Tiles[];
extern const unsigned short gfx_ow_shape_legs_2Tiles[];
extern const unsigned short gfx_ow_shape_legs_2Tiles[];
extern const unsigned short gfx_ow_shape_legs_0Tiles[];
extern const unsigned short gfx_ow_shape_legs_0Tiles[];
extern const unsigned short gfx_ow_shape_legs_1Tiles[];
extern const unsigned short gfx_ow_shape_legs_1Tiles[];
extern const unsigned short gfx_ow_shape_legs_2Tiles[];
extern const unsigned short gfx_ow_shape_legs_2Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_0Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_0Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_1Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_1Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_2Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_2Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_0Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_0Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_1Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_1Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_2Tiles[];
extern const unsigned short gfx_ow_shape_tentacles_2Tiles[];
extern const unsigned short gfx_ow_shape_fish_0Tiles[];
extern const unsigned short gfx_ow_shape_fish_0Tiles[];
extern const unsigned short gfx_ow_shape_fish_1Tiles[];
extern const unsigned short gfx_ow_shape_fish_1Tiles[];
extern const unsigned short gfx_ow_shape_fish_2Tiles[];
extern const unsigned short gfx_ow_shape_fish_2Tiles[];
extern const unsigned short gfx_ow_shape_fish_0Tiles[];
extern const unsigned short gfx_ow_shape_fish_0Tiles[];
extern const unsigned short gfx_ow_shape_fish_1Tiles[];
extern const unsigned short gfx_ow_shape_fish_1Tiles[];
extern const unsigned short gfx_ow_shape_fish_2Tiles[];
extern const unsigned short gfx_ow_shape_fish_2Tiles[];
extern const unsigned short gfx_ow_shape_ball_0Tiles[];
extern const unsigned short gfx_ow_shape_ball_0Tiles[];
extern const unsigned short gfx_ow_shape_ball_1Tiles[];
extern const unsigned short gfx_ow_shape_ball_1Tiles[];
extern const unsigned short gfx_ow_shape_ball_2Tiles[];
extern const unsigned short gfx_ow_shape_ball_2Tiles[];
extern const unsigned short gfx_ow_shape_ball_0Tiles[];
extern const unsigned short gfx_ow_shape_ball_0Tiles[];
extern const unsigned short gfx_ow_shape_ball_1Tiles[];
extern const unsigned short gfx_ow_shape_ball_1Tiles[];
extern const unsigned short gfx_ow_shape_ball_2Tiles[];
extern const unsigned short gfx_ow_shape_ball_2Tiles[];
extern const unsigned short gfx_ow_shape_multi_0Tiles[];
extern const unsigned short gfx_ow_shape_multi_0Tiles[];
extern const unsigned short gfx_ow_shape_multi_1Tiles[];
extern const unsigned short gfx_ow_shape_multi_1Tiles[];
extern const unsigned short gfx_ow_shape_multi_2Tiles[];
extern const unsigned short gfx_ow_shape_multi_2Tiles[];
extern const unsigned short gfx_ow_shape_multi_0Tiles[];
extern const unsigned short gfx_ow_shape_multi_0Tiles[];
extern const unsigned short gfx_ow_shape_multi_1Tiles[];
extern const unsigned short gfx_ow_shape_multi_1Tiles[];
extern const unsigned short gfx_ow_shape_multi_2Tiles[];
extern const unsigned short gfx_ow_shape_multi_2Tiles[];
extern const unsigned short gfx_ow_mistral_0Tiles[];
extern const unsigned short gfx_ow_mistral_0Tiles[];
extern const unsigned short gfx_ow_mistral_1Tiles[];
extern const unsigned short gfx_ow_mistral_1Tiles[];
extern const unsigned short gfx_ow_mistral_2Tiles[];
extern const unsigned short gfx_ow_mistral_2Tiles[];
extern const unsigned short gfx_ow_mistral_3Tiles[];
extern const unsigned short gfx_ow_mistral_3Tiles[];
extern const unsigned short gfx_ow_mistral_4Tiles[];
extern const unsigned short gfx_ow_mistral_4Tiles[];
extern const unsigned short gfx_ow_mistral_5Tiles[];
extern const unsigned short gfx_ow_mistral_5Tiles[];
extern const unsigned short gfx_ow_mistral_6Tiles[];
extern const unsigned short gfx_ow_mistral_6Tiles[];
extern const unsigned short gfx_ow_mistral_7Tiles[];
extern const unsigned short gfx_ow_mistral_7Tiles[];
extern const unsigned short gfx_ow_mistral_8Tiles[];
extern const unsigned short gfx_ow_mistral_8Tiles[];
extern const unsigned short gfx_ow_manus_0Tiles[];
extern const unsigned short gfx_ow_manus_0Tiles[];
extern const unsigned short gfx_ow_manus_1Tiles[];
extern const unsigned short gfx_ow_manus_1Tiles[];
extern const unsigned short gfx_ow_manus_2Tiles[];
extern const unsigned short gfx_ow_manus_2Tiles[];
extern const unsigned short gfx_ow_manus_3Tiles[];
extern const unsigned short gfx_ow_manus_3Tiles[];
extern const unsigned short gfx_ow_manus_4Tiles[];
extern const unsigned short gfx_ow_manus_4Tiles[];
extern const unsigned short gfx_ow_manus_5Tiles[];
extern const unsigned short gfx_ow_manus_5Tiles[];
extern const unsigned short gfx_ow_manus_6Tiles[];
extern const unsigned short gfx_ow_manus_6Tiles[];
extern const unsigned short gfx_ow_manus_7Tiles[];
extern const unsigned short gfx_ow_manus_7Tiles[];
extern const unsigned short gfx_ow_manus_8Tiles[];
extern const unsigned short gfx_ow_manus_8Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_1Tiles[];
extern const unsigned short gfx_ow_altaria_1Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_1Tiles[];
extern const unsigned short gfx_ow_altaria_0Tiles[];
extern const unsigned short gfx_ow_altaria_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_fem_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_0Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_1Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_2Tiles[];
extern const unsigned short gfx_ow_cloudrider_male_2Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_1Tiles[];
extern const unsigned short gfx_ow_moltres_1Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_1Tiles[];
extern const unsigned short gfx_ow_moltres_0Tiles[];
extern const unsigned short gfx_ow_moltres_1Tiles[];
extern const unsigned short gfx_ow_diserakt_0Tiles[];
extern const unsigned short gfx_ow_diserakt_0Tiles[];
extern const unsigned short gfx_ow_diserakt_2Tiles[];
extern const unsigned short gfx_ow_diserakt_2Tiles[];
extern const unsigned short gfx_ow_diserakt_1Tiles[];
extern const unsigned short gfx_ow_diserakt_1Tiles[];
extern const unsigned short gfx_ow_diserakt_0Tiles[];
extern const unsigned short gfx_ow_diserakt_0Tiles[];
extern const unsigned short gfx_ow_diserakt_2Tiles[];
extern const unsigned short gfx_ow_diserakt_2Tiles[];
extern const unsigned short gfx_ow_diserakt_1Tiles[];
extern const unsigned short gfx_ow_diserakt_1Tiles[];
extern const unsigned short gfx_ow_groudon_0Tiles[];
extern const unsigned short gfx_ow_groudon_0Tiles[];
extern const unsigned short gfx_ow_groudon_0Tiles[];
extern const unsigned short gfx_ow_groudon_0Tiles[];
extern const unsigned short gfx_ow_groudon_1Tiles[];
extern const unsigned short gfx_ow_groudon_1Tiles[];
extern const unsigned short gfx_ow_groudon_2Tiles[];
extern const unsigned short gfx_ow_groudon_2Tiles[];
extern const unsigned short gfx_ow_groudon_1Tiles[];
extern const unsigned short gfx_ow_groudon_2Tiles[];
extern const unsigned short gfx_ow_groudon_1Tiles[];
extern const unsigned short gfx_ow_groudon_2Tiles[];
extern const unsigned short gfx_ow_rubys_0Tiles[];
extern const unsigned short gfx_ow_rubys_0Tiles[];
extern const unsigned short gfx_ow_rubys_1Tiles[];
extern const unsigned short gfx_ow_rubys_1Tiles[];
extern const unsigned short gfx_ow_rubys_2Tiles[];
extern const unsigned short gfx_ow_rubys_2Tiles[];
extern const unsigned short gfx_ow_rubys_3Tiles[];
extern const unsigned short gfx_ow_rubys_3Tiles[];
extern const unsigned short gfx_ow_rubys_4Tiles[];
extern const unsigned short gfx_ow_rubys_4Tiles[];
extern const unsigned short gfx_ow_rubys_5Tiles[];
extern const unsigned short gfx_ow_rubys_5Tiles[];
extern const unsigned short gfx_ow_rubys_6Tiles[];
extern const unsigned short gfx_ow_rubys_6Tiles[];
extern const unsigned short gfx_ow_rubys_7Tiles[];
extern const unsigned short gfx_ow_rubys_7Tiles[];
extern const unsigned short gfx_ow_rubys_8Tiles[];
extern const unsigned short gfx_ow_rubys_8Tiles[];
extern const unsigned short gfx_ow_hiroine_sit_0Tiles[];
extern const unsigned short gfx_ow_hiroine_sit_1Tiles[];
extern const unsigned short gfx_ow_hiroine_sit_2Tiles[];
extern const unsigned short gfx_ow_botogel_0Tiles[];
extern const unsigned short gfx_ow_botogel_1Tiles[];
extern const unsigned short gfx_ow_botogel_2Tiles[];
extern const unsigned short gfx_ow_mother_0Tiles[];
extern const unsigned short gfx_ow_mother_1Tiles[];
extern const unsigned short gfx_ow_mother_2Tiles[];
extern const unsigned short gfx_ow_mother_3Tiles[];
extern const unsigned short gfx_ow_mother_4Tiles[];
extern const unsigned short gfx_ow_mother_5Tiles[];
extern const unsigned short gfx_ow_mother_6Tiles[];
extern const unsigned short gfx_ow_mother_7Tiles[];
extern const unsigned short gfx_ow_mother_8Tiles[];
extern const unsigned short gfx_ow_drampaTiles[];
extern const unsigned short gfx_ow_blackbeardTiles[];
extern const unsigned short gfx_ow_teahTiles[];
extern const unsigned short gfx_ow_narcissaTiles[];
extern const unsigned short gfx_ow_harrenfeld_0Tiles[];
extern const unsigned short gfx_ow_harrenfeld_1Tiles[];
extern const unsigned short gfx_ow_harrenfeld_2Tiles[];
extern const unsigned short gfx_ow_harrenfeld_3Tiles[];
extern const unsigned short gfx_ow_harrenfeld_4Tiles[];
extern const unsigned short gfx_ow_harrenfeld_5Tiles[];
extern const unsigned short gfx_ow_harrenfeld_6Tiles[];
extern const unsigned short gfx_ow_harrenfeld_7Tiles[];
extern const unsigned short gfx_ow_harrenfeld_8Tiles[];
extern const unsigned short gfx_ow_butler_0Tiles[];
extern const unsigned short gfx_ow_butler_1Tiles[];
extern const unsigned short gfx_ow_butler_2Tiles[];
extern const unsigned short gfx_ow_butler_3Tiles[];
extern const unsigned short gfx_ow_butler_4Tiles[];
extern const unsigned short gfx_ow_butler_5Tiles[];
extern const unsigned short gfx_ow_butler_6Tiles[];
extern const unsigned short gfx_ow_butler_7Tiles[];
extern const unsigned short gfx_ow_butler_8Tiles[];
extern const unsigned short gfx_ow_lucius_0Tiles[];
extern const unsigned short gfx_ow_lucius_1Tiles[];
extern const unsigned short gfx_ow_lucius_2Tiles[];
extern const unsigned short gfx_ow_lucius_3Tiles[];
extern const unsigned short gfx_ow_lucius_4Tiles[];
extern const unsigned short gfx_ow_lucius_5Tiles[];
extern const unsigned short gfx_ow_lucius_6Tiles[];
extern const unsigned short gfx_ow_lucius_7Tiles[];
extern const unsigned short gfx_ow_lucius_8Tiles[];
extern const u8 gfx_ow_luckyTiles[];
extern const u8 gfx_ow_chefTiles[];
extern const u8 gfx_ow_mega_stoneTiles[];
extern const u8 gfx_ow_lester_youngTiles[];
extern const u8 gfx_ow_romanTiles[];

extern const u8 gfx_ow_mushroomTiles[];
extern const color_t gfx_ow_mushroomPal[];
extern const u8 gfx_ow_shellTiles[];
extern const color_t gfx_ow_shellPal[];
extern const u8 gfx_ow_boulder_gym_puzzleTiles[];
extern const color_t gfx_ow_boulder_gym_puzzlePal[];
extern const color_t gfx_ow_mega_stonePal[];
extern const color_t gfx_ow_romanPal[];

extern overworld_sprite overworld_sprite_strength_boulder;

#define OVERWORLD_PLAYER_PICTURE_CONTEXT_WALKING 0
#define OVERWORLD_PLAYER_PICTURE_CONTEXT_BIKING 1

/**
 * Gets the picture of the player in a given context.
 * @param context the context the player is in
 * @return the picture of the player
 **/
u8 player_get_overworld_picture(u8 context);


/**
 * Finds the overworld_sprite structure of a picture idx.
 * @param picture the picture of the overworld
 * @return sprite the overworld_sprite structure
 **/
overworld_sprite *overworld_get(u16 picture);

/**
 * Translates map coordinates to coordinates for an oam.
 * @param map_x the x on the map in blocks
 * @param map_y the y on the map in blocks
 * @param oam_x resulting oam x coordinate
 * @param oam_y resulting oam y coordinate
 **/
void map_position_to_oam_position(s16 map_x, s16 map_y, s16 *oam_x, s16 *oam_y);

/**
 * Callback that handles (probably) applymovement stuff and movements for an npc while a script is not active
 * @param self self-reference
 **/
void npc_oam_callback_script_not_active (oam_object *self);

#endif /* INCLUDE_C_OVERWORLD_SPRITE_H_ */
