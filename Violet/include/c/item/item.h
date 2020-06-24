/*
 * item.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_ITEM_ITEM_H_
#define INCLUDE_C_ITEM_ITEM_H_


#include "constants/items.h"
#include "item/item_effect.h"
#include "oam.h"

typedef struct {
    u8 name[14];
    u16 index;
    u16 price;
    u8 holding_effect_id;
    u8 holding_effect_param;
    u8 *description;
    u8 importance;
    u8 exit_bag_on_use;
    u8 pocket;
    u8 type;
    void (*field_usage)(u8);
    void (*battle_usage_1)(u8);
    void (*battle_usage_2)(u8);
    void (*field_28)(u8);
} item;

item items[ITEM_CNT];


typedef struct {
	u8 hold_effect;
	u8 type;
} item_hold_effect_type_boost_stru;

#define ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE 17

extern item_hold_effect_type_boost_stru
item_hold_effect_type_boosts[ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE];

void (*item_callback_after_pokemon_selected)(u8, void (*)(u8));

#define ITEM_HAS_TABLE_EFFECT(item) ((item) >= ITEM_TRANK && (item) <= (ITEM_ENIGMABEERE))

/**
 * Copies an items name
 * @param item_idx which items name to copy
 * @param dst where to copy the name to
 **/
void item_strcpy(u16 item_idx, u8 *dst);

/**
 * Gets the name of an item.
 * @param item_idx the item to get the name of
 * @return offset of the item's name
 **/
u8 *item_get_name(u16 item_idx);

/**
 * Returns the holding effect parameter of an item.
 * @param item_id The item id
 * @return The effect parameter
 */
u8 item_get_hold_effect_parameter(u16 item_id);
/**
 * Returns the holding effect  of an item.
 * @param item_id The item id
 * @return The effect
 */
u8 item_get_hold_effect(u16 item_id);

/**
 * Returns the description effect of an item.
 * @param item_id The item idx
 * @return The description
 */
u8 *item_get_description(u16 item_idx);

/**
 * Select the target of an item effect
 * @param self the own callback id
 */
void item_select_target_pokemon(u8 self);

/**
 * Removes a number of exemplars of items from the player's bag
 * @param item_id the item to remove
 * @param count the number of exemplars to remove
 */
void item_remove(u16 item_id, u16 count);

/**
 * Callback that waits for the text renderer to finish and returns to the bag afterwards
 * @param self the own callback id
 */
void item_callback_wait_for_text_render_and_return_to_bag(u8 self);

/**
 * Callback to execute once the field usage of the item has failed
 * @param self the own callback id
 */
void item_field_usage_failure(u8 self);

/**
 * Item function to print a string (appears in the bag or overworld)
 * @param cb_id the own callback id
 * @param unknown TODO
 * @param unknown2 TODO
 * @param str the string to print
 */
void item_print_string(u8 cb_id, u8 unknown, u8 unknown2, u8 *str);

/**
 * Adds a certain amount of exemplars of an item to the player's bag
 * @param item the item
 * @param cnt the number of exemplars to add
 */
void item_add(u16 item, u16 cnt);

/**
 * Removes an item from the player's pc
 * @param item the item to remove
 * @param quantity the amount of exemplars to remove
 */
void item_remove_from_pc(u16 item, u16 quantity);

/**
 * Checks if the player's bag contains a certain amount if exemplars or an item
 * @param item the item to check
 * @param quantity the amount
 * @return if the player's bag contains the item(s)
 */
bool item_check(u16 item, u16 quantity);
/**
 * Checks if the player's bag has room for item(s).
 * @param item the item to check
 * @param quantity the amount
 * @return if the player's bag can hold this much items
 **/
bool item_has_room(u16 item, u16 quantity);

/**
 * Item function for items that use an effect from the effect table.
 * @param self reference to the callback
 **/
void item_field_by_effect_table(u8 self);

/**
 * Gets the price of an item.
 * @param item_idx the item to get the price of
 * @return the item price
 **/
u16 item_get_price(u16 item_idx);

/**
 * Prints a string in the bag and continues with a contnmuation function.
 * @param callback_idx self-reference
 * @param font the font in which to print
 * @param str the string to print
 * @param continuation the continuation function after printing the string
 **/
void bag_print_string(u8 callback_idx, u8 font, u8 *str, void (*continuation)(u8));

/**
 * Callback function that continues the bag functionality after a context menu has been executed
 * @param self self-reference
 **/
void bag_return_from_context_menu(u8 self);

/**
 * Initializes the animation for closing the bag, i.e. closing Win0
 **/
void bag_initialize_close_animation();

/**
 * Initializes fading to dark and then conitinues with the exit continuation of the bag
 * @param self self-reference
 **/
void item_menu_fade_and_continue(u8 self);

/**
 * Battle function for pokéballs
 * @param self self-reference
 **/
void item_pokeball_battle(u8 self);

/**
 * Gets the pocket of an item
 * @param item the item to get the pocket of
 * @return pocket the pocket of the item
 **/
u8 item_get_pocket(u16 item);

u16 tm_hm_to_attack[58];

/**
 * Creates a new oam for an item with the standard template
 * @param tiles_tag which tiles tag to associate with the oam
 * @param pal_tag which pal tag to associate with the oam
 * @param item_idx which item to show
 * @return the oam idx
 **/
u8 item_oam_new(u16 tiles_tag, u16 pal_tag, u16 item_idx);

/**
 * Creates a new oam for an item using a template. Tile and Pal tag are set due to the function's arguments.
 * @param template the oam template used to create the oams
 * @param tiles_tag which tiles tag to associate with the oam
 * @param pal_tag which pal tag to associate with the oam
 * @param item_idx which item to show
 * @return the oam idx
 **/
u8 item_oam_new_by_template(const oam_template *template, u16 tiles_tag, u16 pal_tag, u16 item_idx);

/**
 * Gets the gfx or pal of an item
 * @param item the item to get the resource of
 * @param get_palette a bool indicating if the palette should be retrieved
 * @return the resource
 **/
const u8 *item_get_resource(u16 item, u8 get_palette);

/**
 * Checks how many copies of an item the bag has
 * @param item_idx the item to check
 * @return count the number of copies of this item in the bag
 **/
u16 item_get_count(u16 item_idx);

typedef struct {
    const u8 *gfx;
    const u8 *pal;
} item_gfx_pair;

extern const u8 gfx_item_noneTiles[];
extern const u8 gfx_item_nonePal[];
extern const u8 gfx_item_meisterballTiles[];
extern const u8 gfx_item_meisterballPal[];
extern const u8 gfx_item_hyperballTiles[];
extern const u8 gfx_item_hyperballPal[];
extern const u8 gfx_item_superballTiles[];
extern const u8 gfx_item_superballPal[];
extern const u8 gfx_item_pokeballTiles[];
extern const u8 gfx_item_pokeballPal[];
extern const u8 gfx_item_safariballTiles[];
extern const u8 gfx_item_safariballPal[];
extern const u8 gfx_item_netzballTiles[];
extern const u8 gfx_item_netzballPal[];
extern const u8 gfx_item_tauchballTiles[];
extern const u8 gfx_item_tauchballPal[];
extern const u8 gfx_item_nestballTiles[];
extern const u8 gfx_item_nestballPal[];
extern const u8 gfx_item_wiederballTiles[];
extern const u8 gfx_item_wiederballPal[];
extern const u8 gfx_item_timerballTiles[];
extern const u8 gfx_item_timerballPal[];
extern const u8 gfx_item_luxusballTiles[];
extern const u8 gfx_item_luxusballPal[];
extern const u8 gfx_item_premierballTiles[];
extern const u8 gfx_item_premierballPal[];
extern const u8 gfx_item_trankTiles[];
extern const u8 gfx_item_trankPal[];
extern const u8 gfx_item_gegengiftTiles[];
extern const u8 gfx_item_gegengiftPal[];
extern const u8 gfx_item_feuerheilerTiles[];
extern const u8 gfx_item_feuerheilerPal[];
extern const u8 gfx_item_eisheilerTiles[];
extern const u8 gfx_item_eisheilerPal[];
extern const u8 gfx_item_aufweckerTiles[];
extern const u8 gfx_item_aufweckerPal[];
extern const u8 gfx_item_para_heilerTiles[];
extern const u8 gfx_item_para_heilerPal[];
extern const u8 gfx_item_top_genesungTiles[];
extern const u8 gfx_item_top_genesungPal[];
extern const u8 gfx_item_top_trankTiles[];
extern const u8 gfx_item_top_trankPal[];
extern const u8 gfx_item_hypertrankTiles[];
extern const u8 gfx_item_hypertrankPal[];
extern const u8 gfx_item_supertrankTiles[];
extern const u8 gfx_item_supertrankPal[];
extern const u8 gfx_item_hyperheilerTiles[];
extern const u8 gfx_item_hyperheilerPal[];
extern const u8 gfx_item_beleberTiles[];
extern const u8 gfx_item_beleberPal[];
extern const u8 gfx_item_top_beleberTiles[];
extern const u8 gfx_item_top_beleberPal[];
extern const u8 gfx_item_co_mixTiles[];
extern const u8 gfx_item_co_mixPal[];
extern const u8 gfx_item_c_saftTiles[];
extern const u8 gfx_item_c_saftPal[];
extern const u8 gfx_item_c_serumTiles[];
extern const u8 gfx_item_c_serumPal[];
extern const u8 gfx_item_kuhmuh_milchTiles[];
extern const u8 gfx_item_kuhmuh_milchPal[];
extern const u8 gfx_item_energiestaubTiles[];
extern const u8 gfx_item_energiestaubPal[];
extern const u8 gfx_item_kraftwurzelTiles[];
extern const u8 gfx_item_kraftwurzelPal[];
extern const u8 gfx_item_heilpuderTiles[];
extern const u8 gfx_item_heilpuderPal[];
extern const u8 gfx_item_vitalkrautTiles[];
extern const u8 gfx_item_vitalkrautPal[];
extern const u8 gfx_item_aetherTiles[];
extern const u8 gfx_item_aetherPal[];
extern const u8 gfx_item_top_aetherTiles[];
extern const u8 gfx_item_top_aetherPal[];
extern const u8 gfx_item_elixierTiles[];
extern const u8 gfx_item_elixierPal[];
extern const u8 gfx_item_top_elixierTiles[];
extern const u8 gfx_item_top_elixierPal[];
extern const u8 gfx_item_lavakeksTiles[];
extern const u8 gfx_item_lavakeksPal[];
extern const u8 gfx_item_blaue_floeteTiles[];
extern const u8 gfx_item_blaue_floetePal[];
extern const u8 gfx_item_gelbe_floeteTiles[];
extern const u8 gfx_item_gelbe_floetePal[];
extern const u8 gfx_item_rote_floeteTiles[];
extern const u8 gfx_item_rote_floetePal[];
extern const u8 gfx_item_schw_floeteTiles[];
extern const u8 gfx_item_schw_floetePal[];
extern const u8 gfx_item_weisse_floeteTiles[];
extern const u8 gfx_item_weisse_floetePal[];
extern const u8 gfx_item_beerensaftTiles[];
extern const u8 gfx_item_beerensaftPal[];
extern const u8 gfx_item_zauberascheTiles[];
extern const u8 gfx_item_zauberaschePal[];
extern const u8 gfx_item_kuestensalzTiles[];
extern const u8 gfx_item_kuestensalzPal[];
extern const u8 gfx_item_kuestenschaleTiles[];
extern const u8 gfx_item_kuestenschalePal[];
extern const u8 gfx_item_purpurstueckTiles[];
extern const u8 gfx_item_purpurstueckPal[];
extern const u8 gfx_item_indigostueckTiles[];
extern const u8 gfx_item_indigostueckPal[];
extern const u8 gfx_item_gelbstueckTiles[];
extern const u8 gfx_item_gelbstueckPal[];
extern const u8 gfx_item_gruenstueckTiles[];
extern const u8 gfx_item_gruenstueckPal[];
extern const u8 gfx_item_magmaisiererTiles[];
extern const u8 gfx_item_magmaisiererPal[];
extern const u8 gfx_item_stromisiererTiles[];
extern const u8 gfx_item_stromisiererPal[];
extern const u8 gfx_item_schoenschuppeTiles[];
extern const u8 gfx_item_schoenschuppePal[];
extern const u8 gfx_item_dubiosdiscTiles[];
extern const u8 gfx_item_dubiosdiscPal[];
extern const u8 gfx_item_duesterumhangTiles[];
extern const u8 gfx_item_duesterumhangPal[];
extern const u8 gfx_item_schuetzerTiles[];
extern const u8 gfx_item_schuetzerPal[];
extern const u8 gfx_item_leben_orbTiles[];
extern const u8 gfx_item_leben_orbPal[];
extern const u8 gfx_item_evolithTiles[];
extern const u8 gfx_item_evolithPal[];
extern const u8 gfx_item_scharfzahnTiles[];
extern const u8 gfx_item_scharfzahnPal[];
extern const u8 gfx_item_ovaler_steinTiles[];
extern const u8 gfx_item_ovaler_steinPal[];
extern const u8 gfx_item_item_3eTiles[];
extern const u8 gfx_item_item_3ePal[];
extern const u8 gfx_item_kp_plusTiles[];
extern const u8 gfx_item_kp_plusPal[];
extern const u8 gfx_item_proteinTiles[];
extern const u8 gfx_item_proteinPal[];
extern const u8 gfx_item_eisenTiles[];
extern const u8 gfx_item_eisenPal[];
extern const u8 gfx_item_carbonTiles[];
extern const u8 gfx_item_carbonPal[];
extern const u8 gfx_item_kalziumTiles[];
extern const u8 gfx_item_kalziumPal[];
extern const u8 gfx_item_sonderbonbonTiles[];
extern const u8 gfx_item_sonderbonbonPal[];
extern const u8 gfx_item_ap_plusTiles[];
extern const u8 gfx_item_ap_plusPal[];
extern const u8 gfx_item_zinkTiles[];
extern const u8 gfx_item_zinkPal[];
extern const u8 gfx_item_ap_topTiles[];
extern const u8 gfx_item_ap_topPal[];
extern const u8 gfx_item_goldbonbonTiles[];
extern const u8 gfx_item_goldbonbonPal[];
extern const u8 gfx_item_megablockTiles[];
extern const u8 gfx_item_megablockPal[];
extern const u8 gfx_item_angriffplusTiles[];
extern const u8 gfx_item_angriffplusPal[];
extern const u8 gfx_item_x_angriffTiles[];
extern const u8 gfx_item_x_angriffPal[];
extern const u8 gfx_item_x_abwehrTiles[];
extern const u8 gfx_item_x_abwehrPal[];
extern const u8 gfx_item_x_tempoTiles[];
extern const u8 gfx_item_x_tempoPal[];
extern const u8 gfx_item_x_trefferTiles[];
extern const u8 gfx_item_x_trefferPal[];
extern const u8 gfx_item_x_spezialTiles[];
extern const u8 gfx_item_x_spezialPal[];
extern const u8 gfx_item_pokepuppeTiles[];
extern const u8 gfx_item_pokepuppePal[];
extern const u8 gfx_item_eneco_ruteTiles[];
extern const u8 gfx_item_eneco_rutePal[];
extern const u8 gfx_item_suessbonbonTiles[];
extern const u8 gfx_item_suessbonbonPal[];
extern const u8 gfx_item_superschutzTiles[];
extern const u8 gfx_item_superschutzPal[];
extern const u8 gfx_item_top_schutzTiles[];
extern const u8 gfx_item_top_schutzPal[];
extern const u8 gfx_item_fluchtseilTiles[];
extern const u8 gfx_item_fluchtseilPal[];
extern const u8 gfx_item_schutzTiles[];
extern const u8 gfx_item_schutzPal[];
extern const u8 gfx_item_wunderstaubTiles[];
extern const u8 gfx_item_wunderstaubPal[];
extern const u8 gfx_item_item_58Tiles[];
extern const u8 gfx_item_item_58Pal[];
extern const u8 gfx_item_item_59Tiles[];
extern const u8 gfx_item_item_59Pal[];
extern const u8 gfx_item_item_5aTiles[];
extern const u8 gfx_item_item_5aPal[];
extern const u8 gfx_item_item_5bTiles[];
extern const u8 gfx_item_item_5bPal[];
extern const u8 gfx_item_item_5cTiles[];
extern const u8 gfx_item_item_5cPal[];
extern const u8 gfx_item_sonnensteinTiles[];
extern const u8 gfx_item_sonnensteinPal[];
extern const u8 gfx_item_mondsteinTiles[];
extern const u8 gfx_item_mondsteinPal[];
extern const u8 gfx_item_feuersteinTiles[];
extern const u8 gfx_item_feuersteinPal[];
extern const u8 gfx_item_donnersteinTiles[];
extern const u8 gfx_item_donnersteinPal[];
extern const u8 gfx_item_wassersteinTiles[];
extern const u8 gfx_item_wassersteinPal[];
extern const u8 gfx_item_blattsteinTiles[];
extern const u8 gfx_item_blattsteinPal[];
extern const u8 gfx_item_linkkabelTiles[];
extern const u8 gfx_item_linkkabelPal[];
extern const u8 gfx_item_finstersteinTiles[];
extern const u8 gfx_item_finstersteinPal[];
extern const u8 gfx_item_leuchtsteinTiles[];
extern const u8 gfx_item_leuchtsteinPal[];
extern const u8 gfx_item_funkelsteinTiles[];
extern const u8 gfx_item_funkelsteinPal[];
extern const u8 gfx_item_minipilzTiles[];
extern const u8 gfx_item_minipilzPal[];
extern const u8 gfx_item_riesenpilzTiles[];
extern const u8 gfx_item_riesenpilzPal[];
extern const u8 gfx_item_spv_orb_nTiles[];
extern const u8 gfx_item_spv_orb_nPal[];
extern const u8 gfx_item_perleTiles[];
extern const u8 gfx_item_perlePal[];
extern const u8 gfx_item_riesenperleTiles[];
extern const u8 gfx_item_riesenperlePal[];
extern const u8 gfx_item_sternenstaubTiles[];
extern const u8 gfx_item_sternenstaubPal[];
extern const u8 gfx_item_sternenstueckTiles[];
extern const u8 gfx_item_sternenstueckPal[];
extern const u8 gfx_item_nuggetTiles[];
extern const u8 gfx_item_nuggetPal[];
extern const u8 gfx_item_herzschuppeTiles[];
extern const u8 gfx_item_herzschuppePal[];
extern const u8 gfx_item_angr_orb_pTiles[];
extern const u8 gfx_item_angr_orb_pPal[];
extern const u8 gfx_item_angr_orb_nTiles[];
extern const u8 gfx_item_angr_orb_nPal[];
extern const u8 gfx_item_vert_orb_pTiles[];
extern const u8 gfx_item_vert_orb_pPal[];
extern const u8 gfx_item_vert_orb_nTiles[];
extern const u8 gfx_item_vert_orb_nPal[];
extern const u8 gfx_item_init_orb_pTiles[];
extern const u8 gfx_item_init_orb_pPal[];
extern const u8 gfx_item_init_orb_nTiles[];
extern const u8 gfx_item_init_orb_nPal[];
extern const u8 gfx_item_spa_orb_pTiles[];
extern const u8 gfx_item_spa_orb_pPal[];
extern const u8 gfx_item_spa_orb_nTiles[];
extern const u8 gfx_item_spa_orb_nPal[];
extern const u8 gfx_item_spv_orb_pTiles[];
extern const u8 gfx_item_spv_orb_pPal[];
extern const u8 gfx_item_79Tiles[];
extern const u8 gfx_item_79Pal[];
extern const u8 gfx_item_hafenbriefTiles[];
extern const u8 gfx_item_hafenbriefPal[];
extern const u8 gfx_item_glitzerbriefTiles[];
extern const u8 gfx_item_glitzerbriefPal[];
extern const u8 gfx_item_eilbriefTiles[];
extern const u8 gfx_item_eilbriefPal[];
extern const u8 gfx_item_waldbriefTiles[];
extern const u8 gfx_item_waldbriefPal[];
extern const u8 gfx_item_wellenbriefTiles[];
extern const u8 gfx_item_wellenbriefPal[];
extern const u8 gfx_item_perlenbriefTiles[];
extern const u8 gfx_item_perlenbriefPal[];
extern const u8 gfx_item_dunkelbriefTiles[];
extern const u8 gfx_item_dunkelbriefPal[];
extern const u8 gfx_item_tropenbriefTiles[];
extern const u8 gfx_item_tropenbriefPal[];
extern const u8 gfx_item_traumbriefTiles[];
extern const u8 gfx_item_traumbriefPal[];
extern const u8 gfx_item_edelbriefTiles[];
extern const u8 gfx_item_edelbriefPal[];
extern const u8 gfx_item_retrobriefTiles[];
extern const u8 gfx_item_retrobriefPal[];
extern const u8 gfx_item_amrenabeereTiles[];
extern const u8 gfx_item_amrenabeerePal[];
extern const u8 gfx_item_maronbeereTiles[];
extern const u8 gfx_item_maronbeerePal[];
extern const u8 gfx_item_pirsifbeereTiles[];
extern const u8 gfx_item_pirsifbeerePal[];
extern const u8 gfx_item_fragiabeereTiles[];
extern const u8 gfx_item_fragiabeerePal[];
extern const u8 gfx_item_wilbirbeereTiles[];
extern const u8 gfx_item_wilbirbeerePal[];
extern const u8 gfx_item_jonagobeereTiles[];
extern const u8 gfx_item_jonagobeerePal[];
extern const u8 gfx_item_sinelbeereTiles[];
extern const u8 gfx_item_sinelbeerePal[];
extern const u8 gfx_item_persimbeereTiles[];
extern const u8 gfx_item_persimbeerePal[];
extern const u8 gfx_item_prunusbeereTiles[];
extern const u8 gfx_item_prunusbeerePal[];
extern const u8 gfx_item_tsitrubeereTiles[];
extern const u8 gfx_item_tsitrubeerePal[];
extern const u8 gfx_item_giefebeereTiles[];
extern const u8 gfx_item_giefebeerePal[];
extern const u8 gfx_item_wikibeereTiles[];
extern const u8 gfx_item_wikibeerePal[];
extern const u8 gfx_item_magobeereTiles[];
extern const u8 gfx_item_magobeerePal[];
extern const u8 gfx_item_gauvebeereTiles[];
extern const u8 gfx_item_gauvebeerePal[];
extern const u8 gfx_item_yapabeereTiles[];
extern const u8 gfx_item_yapabeerePal[];
extern const u8 gfx_item_himmihbeereTiles[];
extern const u8 gfx_item_himmihbeerePal[];
extern const u8 gfx_item_morbbeereTiles[];
extern const u8 gfx_item_morbbeerePal[];
extern const u8 gfx_item_nanabbeereTiles[];
extern const u8 gfx_item_nanabbeerePal[];
extern const u8 gfx_item_nirbebeereTiles[];
extern const u8 gfx_item_nirbebeerePal[];
extern const u8 gfx_item_sananabeereTiles[];
extern const u8 gfx_item_sananabeerePal[];
extern const u8 gfx_item_granabeereTiles[];
extern const u8 gfx_item_granabeerePal[];
extern const u8 gfx_item_setangbeereTiles[];
extern const u8 gfx_item_setangbeerePal[];
extern const u8 gfx_item_qualotbeereTiles[];
extern const u8 gfx_item_qualotbeerePal[];
extern const u8 gfx_item_honmelbeereTiles[];
extern const u8 gfx_item_honmelbeerePal[];
extern const u8 gfx_item_labrusbeereTiles[];
extern const u8 gfx_item_labrusbeerePal[];
extern const u8 gfx_item_tamotbeereTiles[];
extern const u8 gfx_item_tamotbeerePal[];
extern const u8 gfx_item_saimbeereTiles[];
extern const u8 gfx_item_saimbeerePal[];
extern const u8 gfx_item_magostbeereTiles[];
extern const u8 gfx_item_magostbeerePal[];
extern const u8 gfx_item_rabutabeereTiles[];
extern const u8 gfx_item_rabutabeerePal[];
extern const u8 gfx_item_tronzibeereTiles[];
extern const u8 gfx_item_tronzibeerePal[];
extern const u8 gfx_item_kiwanbeereTiles[];
extern const u8 gfx_item_kiwanbeerePal[];
extern const u8 gfx_item_pallmbeereTiles[];
extern const u8 gfx_item_pallmbeerePal[];
extern const u8 gfx_item_wasmelbeereTiles[];
extern const u8 gfx_item_wasmelbeerePal[];
extern const u8 gfx_item_durinbeereTiles[];
extern const u8 gfx_item_durinbeerePal[];
extern const u8 gfx_item_myrtilbeereTiles[];
extern const u8 gfx_item_myrtilbeerePal[];
extern const u8 gfx_item_lydzibeereTiles[];
extern const u8 gfx_item_lydzibeerePal[];
extern const u8 gfx_item_linganbeereTiles[];
extern const u8 gfx_item_linganbeerePal[];
extern const u8 gfx_item_salkabeereTiles[];
extern const u8 gfx_item_salkabeerePal[];
extern const u8 gfx_item_tahaybeereTiles[];
extern const u8 gfx_item_tahaybeerePal[];
extern const u8 gfx_item_apikobeereTiles[];
extern const u8 gfx_item_apikobeerePal[];
extern const u8 gfx_item_lansatbeereTiles[];
extern const u8 gfx_item_lansatbeerePal[];
extern const u8 gfx_item_krambobeereTiles[];
extern const u8 gfx_item_krambobeerePal[];
extern const u8 gfx_item_enigmabeereTiles[];
extern const u8 gfx_item_enigmabeerePal[];
extern const u8 gfx_item_item_b0Tiles[];
extern const u8 gfx_item_item_b0Pal[];
extern const u8 gfx_item_wahlglasTiles[];
extern const u8 gfx_item_wahlglasPal[];
extern const u8 gfx_item_wahlschalTiles[];
extern const u8 gfx_item_wahlschalPal[];
extern const u8 gfx_item_blendpuderTiles[];
extern const u8 gfx_item_blendpuderPal[];
extern const u8 gfx_item_schlohkrautTiles[];
extern const u8 gfx_item_schlohkrautPal[];
extern const u8 gfx_item_machobandTiles[];
extern const u8 gfx_item_machobandPal[];
extern const u8 gfx_item_ep_teilerTiles[];
extern const u8 gfx_item_ep_teilerPal[];
extern const u8 gfx_item_flinkklaueTiles[];
extern const u8 gfx_item_flinkklauePal[];
extern const u8 gfx_item_sanftglockeTiles[];
extern const u8 gfx_item_sanftglockePal[];
extern const u8 gfx_item_mentalkrautTiles[];
extern const u8 gfx_item_mentalkrautPal[];
extern const u8 gfx_item_wahlbandTiles[];
extern const u8 gfx_item_wahlbandPal[];
extern const u8 gfx_item_king_steinTiles[];
extern const u8 gfx_item_king_steinPal[];
extern const u8 gfx_item_silberstaubTiles[];
extern const u8 gfx_item_silberstaubPal[];
extern const u8 gfx_item_muenzamulettTiles[];
extern const u8 gfx_item_muenzamulettPal[];
extern const u8 gfx_item_schutzbandTiles[];
extern const u8 gfx_item_schutzbandPal[];
extern const u8 gfx_item_seelentauTiles[];
extern const u8 gfx_item_seelentauPal[];
extern const u8 gfx_item_abysszahnTiles[];
extern const u8 gfx_item_abysszahnPal[];
extern const u8 gfx_item_abyssplatteTiles[];
extern const u8 gfx_item_abyssplattePal[];
extern const u8 gfx_item_rauchballTiles[];
extern const u8 gfx_item_rauchballPal[];
extern const u8 gfx_item_ewigsteinTiles[];
extern const u8 gfx_item_ewigsteinPal[];
extern const u8 gfx_item_fokus_bandTiles[];
extern const u8 gfx_item_fokus_bandPal[];
extern const u8 gfx_item_gluecks_eiTiles[];
extern const u8 gfx_item_gluecks_eiPal[];
extern const u8 gfx_item_scope_linseTiles[];
extern const u8 gfx_item_scope_linsePal[];
extern const u8 gfx_item_metallmantelTiles[];
extern const u8 gfx_item_metallmantelPal[];
extern const u8 gfx_item_ueberresteTiles[];
extern const u8 gfx_item_ueberrestePal[];
extern const u8 gfx_item_drachenhautTiles[];
extern const u8 gfx_item_drachenhautPal[];
extern const u8 gfx_item_kugelblitzTiles[];
extern const u8 gfx_item_kugelblitzPal[];
extern const u8 gfx_item_pudersandTiles[];
extern const u8 gfx_item_pudersandPal[];
extern const u8 gfx_item_granitsteinTiles[];
extern const u8 gfx_item_granitsteinPal[];
extern const u8 gfx_item_wundersaatTiles[];
extern const u8 gfx_item_wundersaatPal[];
extern const u8 gfx_item_schattenglasTiles[];
extern const u8 gfx_item_schattenglasPal[];
extern const u8 gfx_item_schwarzgurtTiles[];
extern const u8 gfx_item_schwarzgurtPal[];
extern const u8 gfx_item_magnetTiles[];
extern const u8 gfx_item_magnetPal[];
extern const u8 gfx_item_zauberwasserTiles[];
extern const u8 gfx_item_zauberwasserPal[];
extern const u8 gfx_item_hackattackTiles[];
extern const u8 gfx_item_hackattackPal[];
extern const u8 gfx_item_giftstichTiles[];
extern const u8 gfx_item_giftstichPal[];
extern const u8 gfx_item_ewiges_eisTiles[];
extern const u8 gfx_item_ewiges_eisPal[];
extern const u8 gfx_item_bannstickerTiles[];
extern const u8 gfx_item_bannstickerPal[];
extern const u8 gfx_item_kruemmloeffelTiles[];
extern const u8 gfx_item_kruemmloeffelPal[];
extern const u8 gfx_item_holzkohleTiles[];
extern const u8 gfx_item_holzkohlePal[];
extern const u8 gfx_item_drachenzahnTiles[];
extern const u8 gfx_item_drachenzahnPal[];
extern const u8 gfx_item_seidenschalTiles[];
extern const u8 gfx_item_seidenschalPal[];
extern const u8 gfx_item_up_gradeTiles[];
extern const u8 gfx_item_up_gradePal[];
extern const u8 gfx_item_seegesangTiles[];
extern const u8 gfx_item_seegesangPal[];
extern const u8 gfx_item_seerauchTiles[];
extern const u8 gfx_item_seerauchPal[];
extern const u8 gfx_item_laxrauchTiles[];
extern const u8 gfx_item_laxrauchPal[];
extern const u8 gfx_item_lucky_punchTiles[];
extern const u8 gfx_item_lucky_punchPal[];
extern const u8 gfx_item_metallstaubTiles[];
extern const u8 gfx_item_metallstaubPal[];
extern const u8 gfx_item_kampfknochenTiles[];
extern const u8 gfx_item_kampfknochenPal[];
extern const u8 gfx_item_lauchstangeTiles[];
extern const u8 gfx_item_lauchstangePal[];
extern const u8 gfx_item_bisaflornitTiles[];
extern const u8 gfx_item_bisaflornitPal[];
extern const u8 gfx_item_gluraknitTiles[];
extern const u8 gfx_item_gluraknitPal[];
extern const u8 gfx_item_turtoknitTiles[];
extern const u8 gfx_item_turtoknitPal[];
extern const u8 gfx_item_terrasornitTiles[];
extern const u8 gfx_item_terrasornitPal[];
extern const u8 gfx_item_zerbernitTiles[];
extern const u8 gfx_item_zerbernitPal[];
extern const u8 gfx_item_skullydranitTiles[];
extern const u8 gfx_item_skullydranitPal[];
extern const u8 gfx_item_aquananitTiles[];
extern const u8 gfx_item_aquananitPal[];
extern const u8 gfx_item_flamaranitTiles[];
extern const u8 gfx_item_flamaranitPal[];
extern const u8 gfx_item_blitzanitTiles[];
extern const u8 gfx_item_blitzanitPal[];
extern const u8 gfx_item_ampharosnitTiles[];
extern const u8 gfx_item_ampharosnitPal[];
extern const u8 gfx_item_gengarnitTiles[];
extern const u8 gfx_item_gengarnitPal[];
extern const u8 gfx_item_bibornitTiles[];
extern const u8 gfx_item_bibornitPal[];
extern const u8 gfx_item_magmaherzTiles[];
extern const u8 gfx_item_magmaherzPal[];
extern const u8 gfx_item_geowaznitTiles[];
extern const u8 gfx_item_geowaznitPal[];
extern const u8 gfx_item_tropiusnitTiles[];
extern const u8 gfx_item_tropiusnitPal[];
extern const u8 gfx_item_octillerynitTiles[];
extern const u8 gfx_item_octillerynitPal[];
extern const u8 gfx_item_item_f2Tiles[];
extern const u8 gfx_item_item_f2Pal[];
extern const u8 gfx_item_item_f3Tiles[];
extern const u8 gfx_item_item_f3Pal[];
extern const u8 gfx_item_item_f4Tiles[];
extern const u8 gfx_item_item_f4Pal[];
extern const u8 gfx_item_item_f5Tiles[];
extern const u8 gfx_item_item_f5Pal[];
extern const u8 gfx_item_item_f6Tiles[];
extern const u8 gfx_item_item_f6Pal[];
extern const u8 gfx_item_item_f7Tiles[];
extern const u8 gfx_item_item_f7Pal[];
extern const u8 gfx_item_lahmrauchTiles[];
extern const u8 gfx_item_lahmrauchPal[];
extern const u8 gfx_item_eisbrockenTiles[];
extern const u8 gfx_item_eisbrockenPal[];
extern const u8 gfx_item_nassbrockenTiles[];
extern const u8 gfx_item_nassbrockenPal[];
extern const u8 gfx_item_glattbrockenTiles[];
extern const u8 gfx_item_glattbrockenPal[];
extern const u8 gfx_item_heissbrockenTiles[];
extern const u8 gfx_item_heissbrockenPal[];
extern const u8 gfx_item_lichtlehmTiles[];
extern const u8 gfx_item_lichtlehmPal[];
extern const u8 gfx_item_steinrauchTiles[];
extern const u8 gfx_item_steinrauchPal[];
extern const u8 gfx_item_scheuchrauchTiles[];
extern const u8 gfx_item_scheuchrauchPal[];
extern const u8 gfx_item_gluecksrauchTiles[];
extern const u8 gfx_item_gluecksrauchPal[];
extern const u8 gfx_item_koederTiles[];
extern const u8 gfx_item_koederPal[];
extern const u8 gfx_item_goldkoederTiles[];
extern const u8 gfx_item_goldkoederPal[];
extern const u8 gfx_item_leuchtkoederTiles[];
extern const u8 gfx_item_leuchtkoederPal[];
extern const u8 gfx_item_muenzkorbTiles[];
extern const u8 gfx_item_muenzkorbPal[];
extern const u8 gfx_item_detektorTiles[];
extern const u8 gfx_item_detektorPal[];
extern const u8 gfx_item_angelTiles[];
extern const u8 gfx_item_angelPal[];
extern const u8 gfx_item_profiangelTiles[];
extern const u8 gfx_item_profiangelPal[];
extern const u8 gfx_item_superangelTiles[];
extern const u8 gfx_item_superangelPal[];
extern const u8 gfx_item_bootsticketTiles[];
extern const u8 gfx_item_bootsticketPal[];
extern const u8 gfx_item_wettb_karteTiles[];
extern const u8 gfx_item_wettb_kartePal[];
extern const u8 gfx_item_item_10bTiles[];
extern const u8 gfx_item_item_10bPal[];
extern const u8 gfx_item_wailmerkanneTiles[];
extern const u8 gfx_item_wailmerkannePal[];
extern const u8 gfx_item_devon_warenTiles[];
extern const u8 gfx_item_devon_warenPal[];
extern const u8 gfx_item_aschetascheTiles[];
extern const u8 gfx_item_aschetaschePal[];
extern const u8 gfx_item_geisterschluesselTiles[];
extern const u8 gfx_item_geisterschluesselPal[];
extern const u8 gfx_item_kunstradTiles[];
extern const u8 gfx_item_kunstradPal[];
extern const u8 gfx_item_boxTiles[];
extern const u8 gfx_item_boxPal[];
extern const u8 gfx_item_briefTiles[];
extern const u8 gfx_item_briefPal[];
extern const u8 gfx_item_aeon_ticketTiles[];
extern const u8 gfx_item_aeon_ticketPal[];
extern const u8 gfx_item_spiritkernTiles[];
extern const u8 gfx_item_spiritkernPal[];
extern const u8 gfx_item_blaue_kugelTiles[];
extern const u8 gfx_item_blaue_kugelPal[];
extern const u8 gfx_item_scannerTiles[];
extern const u8 gfx_item_scannerPal[];
extern const u8 gfx_item_wuestenglasTiles[];
extern const u8 gfx_item_wuestenglasPal[];
extern const u8 gfx_item_meteoritTiles[];
extern const u8 gfx_item_meteoritPal[];
extern const u8 gfx_item_goldschluesselTiles[];
extern const u8 gfx_item_goldschluesselPal[];
extern const u8 gfx_item_zellenschluesselTiles[];
extern const u8 gfx_item_zellenschluesselPal[];
extern const u8 gfx_item_k4_schluesselTiles[];
extern const u8 gfx_item_k4_schluesselPal[];
extern const u8 gfx_item_k6_schluesselTiles[];
extern const u8 gfx_item_k6_schluesselPal[];
extern const u8 gfx_item_l_schluesselTiles[];
extern const u8 gfx_item_l_schluesselPal[];
extern const u8 gfx_item_wurzelfossilTiles[];
extern const u8 gfx_item_wurzelfossilPal[];
extern const u8 gfx_item_klauenfossilTiles[];
extern const u8 gfx_item_klauenfossilPal[];
extern const u8 gfx_item_devon_scopeTiles[];
extern const u8 gfx_item_devon_scopePal[];
extern const u8 gfx_item_tm01Tiles[];
extern const u8 gfx_item_tm01Pal[];
extern const u8 gfx_item_tm02Tiles[];
extern const u8 gfx_item_tm02Pal[];
extern const u8 gfx_item_tm03Tiles[];
extern const u8 gfx_item_tm03Pal[];
extern const u8 gfx_item_tm04Tiles[];
extern const u8 gfx_item_tm04Pal[];
extern const u8 gfx_item_tm05Tiles[];
extern const u8 gfx_item_tm05Pal[];
extern const u8 gfx_item_tm06Tiles[];
extern const u8 gfx_item_tm06Pal[];
extern const u8 gfx_item_tm07Tiles[];
extern const u8 gfx_item_tm07Pal[];
extern const u8 gfx_item_tm08Tiles[];
extern const u8 gfx_item_tm08Pal[];
extern const u8 gfx_item_tm09Tiles[];
extern const u8 gfx_item_tm09Pal[];
extern const u8 gfx_item_tm10Tiles[];
extern const u8 gfx_item_tm10Pal[];
extern const u8 gfx_item_tm11Tiles[];
extern const u8 gfx_item_tm11Pal[];
extern const u8 gfx_item_tm12Tiles[];
extern const u8 gfx_item_tm12Pal[];
extern const u8 gfx_item_tm13Tiles[];
extern const u8 gfx_item_tm13Pal[];
extern const u8 gfx_item_tm14Tiles[];
extern const u8 gfx_item_tm14Pal[];
extern const u8 gfx_item_tm15Tiles[];
extern const u8 gfx_item_tm15Pal[];
extern const u8 gfx_item_tm16Tiles[];
extern const u8 gfx_item_tm16Pal[];
extern const u8 gfx_item_tm17Tiles[];
extern const u8 gfx_item_tm17Pal[];
extern const u8 gfx_item_tm18Tiles[];
extern const u8 gfx_item_tm18Pal[];
extern const u8 gfx_item_tm19Tiles[];
extern const u8 gfx_item_tm19Pal[];
extern const u8 gfx_item_tm20Tiles[];
extern const u8 gfx_item_tm20Pal[];
extern const u8 gfx_item_tm21Tiles[];
extern const u8 gfx_item_tm21Pal[];
extern const u8 gfx_item_tm22Tiles[];
extern const u8 gfx_item_tm22Pal[];
extern const u8 gfx_item_tm23Tiles[];
extern const u8 gfx_item_tm23Pal[];
extern const u8 gfx_item_tm24Tiles[];
extern const u8 gfx_item_tm24Pal[];
extern const u8 gfx_item_tm25Tiles[];
extern const u8 gfx_item_tm25Pal[];
extern const u8 gfx_item_tm26Tiles[];
extern const u8 gfx_item_tm26Pal[];
extern const u8 gfx_item_tm27Tiles[];
extern const u8 gfx_item_tm27Pal[];
extern const u8 gfx_item_tm28Tiles[];
extern const u8 gfx_item_tm28Pal[];
extern const u8 gfx_item_tm29Tiles[];
extern const u8 gfx_item_tm29Pal[];
extern const u8 gfx_item_tm30Tiles[];
extern const u8 gfx_item_tm30Pal[];
extern const u8 gfx_item_tm31Tiles[];
extern const u8 gfx_item_tm31Pal[];
extern const u8 gfx_item_tm32Tiles[];
extern const u8 gfx_item_tm32Pal[];
extern const u8 gfx_item_tm33Tiles[];
extern const u8 gfx_item_tm33Pal[];
extern const u8 gfx_item_tm34Tiles[];
extern const u8 gfx_item_tm34Pal[];
extern const u8 gfx_item_tm35Tiles[];
extern const u8 gfx_item_tm35Pal[];
extern const u8 gfx_item_tm36Tiles[];
extern const u8 gfx_item_tm36Pal[];
extern const u8 gfx_item_tm37Tiles[];
extern const u8 gfx_item_tm37Pal[];
extern const u8 gfx_item_tm38Tiles[];
extern const u8 gfx_item_tm38Pal[];
extern const u8 gfx_item_tm39Tiles[];
extern const u8 gfx_item_tm39Pal[];
extern const u8 gfx_item_tm40Tiles[];
extern const u8 gfx_item_tm40Pal[];
extern const u8 gfx_item_tm41Tiles[];
extern const u8 gfx_item_tm41Pal[];
extern const u8 gfx_item_tm42Tiles[];
extern const u8 gfx_item_tm42Pal[];
extern const u8 gfx_item_tm43Tiles[];
extern const u8 gfx_item_tm43Pal[];
extern const u8 gfx_item_tm44Tiles[];
extern const u8 gfx_item_tm44Pal[];
extern const u8 gfx_item_tm45Tiles[];
extern const u8 gfx_item_tm45Pal[];
extern const u8 gfx_item_tm46Tiles[];
extern const u8 gfx_item_tm46Pal[];
extern const u8 gfx_item_tm47Tiles[];
extern const u8 gfx_item_tm47Pal[];
extern const u8 gfx_item_tm48Tiles[];
extern const u8 gfx_item_tm48Pal[];
extern const u8 gfx_item_tm49Tiles[];
extern const u8 gfx_item_tm49Pal[];
extern const u8 gfx_item_tm50Tiles[];
extern const u8 gfx_item_tm50Pal[];
extern const u8 gfx_item_vm01Tiles[];
extern const u8 gfx_item_vm01Pal[];
extern const u8 gfx_item_vm02Tiles[];
extern const u8 gfx_item_vm02Pal[];
extern const u8 gfx_item_vm03Tiles[];
extern const u8 gfx_item_vm03Pal[];
extern const u8 gfx_item_vm04Tiles[];
extern const u8 gfx_item_vm04Pal[];
extern const u8 gfx_item_vm05Tiles[];
extern const u8 gfx_item_vm05Pal[];
extern const u8 gfx_item_vm06Tiles[];
extern const u8 gfx_item_vm06Pal[];
extern const u8 gfx_item_vm07Tiles[];
extern const u8 gfx_item_vm07Pal[];
extern const u8 gfx_item_vm08Tiles[];
extern const u8 gfx_item_vm08Pal[];
extern const u8 gfx_item_schwarzpulverTiles[];
extern const u8 gfx_item_schwarzpulverPal[];
extern const u8 gfx_item_vierblattTiles[];
extern const u8 gfx_item_vierblattPal[];
extern const u8 gfx_item_zugangskarteTiles[];
extern const u8 gfx_item_zugangskartePal[];
extern const u8 gfx_item_pokefloeteTiles[];
extern const u8 gfx_item_pokefloetePal[];
extern const u8 gfx_item__oeffnerTiles[];
extern const u8 gfx_item__oeffnerPal[];
extern const u8 gfx_item_alte_karteTiles[];
extern const u8 gfx_item_alte_kartePal[];
extern const u8 gfx_item_pkmcorderTiles[];
extern const u8 gfx_item_pkmcorderPal[];
extern const u8 gfx_item_altbernsteinTiles[];
extern const u8 gfx_item_altbernsteinPal[];
extern const u8 gfx_item_tueroeffnerTiles[];
extern const u8 gfx_item_tueroeffnerPal[];
extern const u8 gfx_item_liftoeffnerTiles[];
extern const u8 gfx_item_liftoeffnerPal[];
extern const u8 gfx_item_helixfossilTiles[];
extern const u8 gfx_item_helixfossilPal[];
extern const u8 gfx_item_domfossilTiles[];
extern const u8 gfx_item_domfossilPal[];
extern const u8 gfx_item_silph_scopeTiles[];
extern const u8 gfx_item_silph_scopePal[];
extern const u8 gfx_item_fahrradTiles[];
extern const u8 gfx_item_fahrradPal[];
extern const u8 gfx_item_karteTiles[];
extern const u8 gfx_item_kartePal[];
extern const u8 gfx_item_kampffahnderTiles[];
extern const u8 gfx_item_kampffahnderPal[];
extern const u8 gfx_item_ruhmesdateiTiles[];
extern const u8 gfx_item_ruhmesdateiPal[];
extern const u8 gfx_item_vmtm_boxTiles[];
extern const u8 gfx_item_vmtm_boxPal[];
extern const u8 gfx_item_beerentueteTiles[];
extern const u8 gfx_item_beerentuetePal[];
extern const u8 gfx_item_lehrkanalTiles[];
extern const u8 gfx_item_lehrkanalPal[];
extern const u8 gfx_item_tri_passTiles[];
extern const u8 gfx_item_tri_passPal[];
extern const u8 gfx_item_bunt_passTiles[];
extern const u8 gfx_item_bunt_passPal[];
extern const u8 gfx_item_mega_amulettTiles[];
extern const u8 gfx_item_mega_amulettPal[];
extern const u8 gfx_item_geheimticketTiles[];
extern const u8 gfx_item_geheimticketPal[];
extern const u8 gfx_item_auroraticketTiles[];
extern const u8 gfx_item_auroraticketPal[];
extern const u8 gfx_item_puderdoeschenTiles[];
extern const u8 gfx_item_puderdoeschenPal[];
extern const u8 gfx_item_rubinTiles[];
extern const u8 gfx_item_rubinPal[];
extern const u8 gfx_item_saphirTiles[];
extern const u8 gfx_item_saphirPal[];
extern const u8 gfx_item_naTiles[];
extern const u8 gfx_item_naPal[];
extern const u8 gfx_item_bodenjuwelTiles[];
extern const u8 gfx_item_bodenjuwelPal[];
extern const u8 gfx_item_dracojuwelTiles[];
extern const u8 gfx_item_dracojuwelPal[];
extern const u8 gfx_item_eisjuwelTiles[];
extern const u8 gfx_item_eisjuwelPal[];
extern const u8 gfx_item_elektrojuwelTiles[];
extern const u8 gfx_item_elektrojuwelPal[];
extern const u8 gfx_item_feejuwelTiles[];
extern const u8 gfx_item_feejuwelPal[];
extern const u8 gfx_item_feuerjuwelTiles[];
extern const u8 gfx_item_feuerjuwelPal[];
extern const u8 gfx_item_flugjuwelTiles[];
extern const u8 gfx_item_flugjuwelPal[];
extern const u8 gfx_item_geisterjuwelTiles[];
extern const u8 gfx_item_geisterjuwelPal[];
extern const u8 gfx_item_gesteinjuwelTiles[];
extern const u8 gfx_item_gesteinjuwelPal[];
extern const u8 gfx_item_giftjuwelTiles[];
extern const u8 gfx_item_giftjuwelPal[];
extern const u8 gfx_item_kaeferjuwelTiles[];
extern const u8 gfx_item_kaeferjuwelPal[];
extern const u8 gfx_item_kampfjuwelTiles[];
extern const u8 gfx_item_kampfjuwelPal[];
extern const u8 gfx_item_normaljuwelTiles[];
extern const u8 gfx_item_normaljuwelPal[];
extern const u8 gfx_item_pflanzejuwelTiles[];
extern const u8 gfx_item_pflanzejuwelPal[];
extern const u8 gfx_item_pyschojuwelTiles[];
extern const u8 gfx_item_pyschojuwelPal[];
extern const u8 gfx_item_stahljuwelTiles[];
extern const u8 gfx_item_stahljuwelPal[];
extern const u8 gfx_item_unlichtjuwelTiles[];
extern const u8 gfx_item_unlichtjuwelPal[];
extern const u8 gfx_item_wasserjuwelTiles[];
extern const u8 gfx_item_wasserjuwelPal[];


#endif /* INCLUDE_C_ITEM_ITEM_H_ */
