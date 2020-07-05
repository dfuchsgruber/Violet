/* 
 * File:   mugshot.h
 * Author: Domi
 *
 * Created on 16. Juni 2016, 15:07
 */

#ifndef MUGSHOT_H
#define	MUGSHOT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "types.h"
#include "constants/mugshot_emotions.h"

    typedef struct mugshot {
        const void *gfx[MUGSHOT_EMOTION_COUNT]; // lz77 compressed
        const void *pal; // lz77 compressed
        u8 *name;
    } mugshot;

    /**
     * Creates the oam for a given mugshot and stores its idx in the floating memory
     * @param side side to display the mugshot (0 = left, 1 = right)
     * @param idx index of the mugshot to display
     * @param emotion index of the emotion to display
     */
    void mugshot_create_oam(int side, int idx, int emotion);

    /**
     * Creates the text for a given mugshot and stores its idx in the floating memory
     * @param side side to display the mugshot text (0 = left, 1 = right)
     * @param text pointer to the text to display
     */
    void mugshot_create_text(int side, u8 *text);

    /**
     * Special to show a mugshot. Index to display given in 0x8000, the side given in 0x8001.
     */
    void special_mugshot_show();

    /**
     * Special to delete the currently present mugshot.
     */
    void special_mugshot_delete();

    /**
     * Big callback to remove the mugshot oam. This is implemented as callback, since first
     * the oam is moved offscreen and only afterwards the graphics are destroyed. This way
     * when a new mugshot is created the same frame, no artifacts are shown onscreen.
     * @param self the callback id
     */
    void mugshot_delete_oam(u8 self);

    /**
     * Big callback to remove the mugshot text.
     * @param self the callback id
     */
    void mugshot_delete_text(u8 self);

    /**
     * Shows a name above the textbox without any graphic. The text is given in pointerbank #0 of
     * the overworld script engine, the side in 0x8000.
     */
    void special_show_name();

    /**
     * Deletes a name over the textbox.
     */
    void special_delete_name();

    extern const unsigned short gfx_mug_mistralTiles[];
    extern const unsigned short gfx_mug_mistralPal[];
    extern const unsigned short gfx_mug_hiroTiles[];
    extern const unsigned short gfx_mug_hiroPal[];
    extern const unsigned short gfx_mug_hiro_angryTiles[];
    extern const unsigned short gfx_mug_hiro_annoyedTiles[];
    extern const unsigned short gfx_mug_hiro_happyTiles[];
    extern const unsigned short gfx_mug_hiro_sadTiles[];
    extern const unsigned short gfx_mug_hiro_scaredTiles[];
    extern const unsigned short gfx_mug_hiro_shockedTiles[];
    extern const unsigned short gfx_mug_hiro_thoughtfulTiles[];
    extern const unsigned short gfx_mug_hiroineTiles[];
    extern const unsigned short gfx_mug_hiroinePal[];
    extern const unsigned short gfx_mug_hiroine_angryTiles[];
    extern const unsigned short gfx_mug_hiroine_annoyedTiles[];
    extern const unsigned short gfx_mug_hiroine_happyTiles[];
    extern const unsigned short gfx_mug_hiroine_sadTiles[];
    extern const unsigned short gfx_mug_hiroine_scaredTiles[];
    extern const unsigned short gfx_mug_hiroine_shockedTiles[];
    extern const unsigned short gfx_mug_hiroine_thoughtfulTiles[];
    extern const unsigned short gfx_mug_lesterTiles[];
    extern const unsigned short gfx_mug_lesterPal[];
    extern const unsigned short gfx_mug_igvaTiles[];
    extern const unsigned short gfx_mug_igvaPal[];
    extern const unsigned short gfx_mug_blackbeardTiles[];
    extern const unsigned short gfx_mug_blackbeard_shockedTiles[];
    extern const unsigned short gfx_mug_blackbeard_angryTiles[];
    extern const unsigned short gfx_mug_blackbeard_happyTiles[];
    extern const unsigned short gfx_mug_blackbeardPal[];
    extern const unsigned short gfx_mug_rinTiles[];
    extern const unsigned short gfx_mug_rinPal[];
    extern const unsigned short gfx_mug_rivalTiles[];
    extern const unsigned short gfx_mug_rival_angryTiles[];
    extern const unsigned short gfx_mug_rival_annoyedTiles[];
    extern const unsigned short gfx_mug_rival_happyTiles[];
    extern const unsigned short gfx_mug_rival_sadTiles[];
    extern const unsigned short gfx_mug_rival_scaredTiles[];
    extern const unsigned short gfx_mug_rival_shockedTiles[];
    extern const unsigned short gfx_mug_rival_thoughtfulTiles[];
    extern const unsigned short gfx_mug_rivalPal[];
    extern const unsigned short gfx_mug_brixTiles[];
    extern const unsigned short gfx_mug_brixPal[];
    extern const unsigned short gfx_mug_mayTiles[];
    extern const unsigned short gfx_mug_may_angryTiles[];
    extern const unsigned short gfx_mug_may_annoyedTiles[];
    extern const unsigned short gfx_mug_may_happyTiles[];
    extern const unsigned short gfx_mug_may_sadTiles[];
    extern const unsigned short gfx_mug_may_scaredTiles[];
    extern const unsigned short gfx_mug_may_shockedTiles[];
    extern const unsigned short gfx_mug_may_thoughtfulTiles[];
    extern const unsigned short gfx_mug_may_evilTiles[];
    extern const unsigned short gfx_mug_mayPal[];
    extern const unsigned short gfx_mug_felixTiles[];
    extern const unsigned short gfx_mug_felixPal[];
    extern const unsigned short gfx_mug_felixTiles[];
    extern const unsigned short gfx_mug_felix_angryTiles[];
    extern const unsigned short gfx_mug_felix_annoyedTiles[];
    extern const unsigned short gfx_mug_felix_happyTiles[];
    extern const unsigned short gfx_mug_felix_sadTiles[];
    extern const unsigned short gfx_mug_felix_scaredTiles[];
    extern const unsigned short gfx_mug_felix_shockedTiles[];
    extern const unsigned short gfx_mug_felix_thoughtfulTiles[];
    extern const unsigned short gfx_mug_felixPal[];
    extern const unsigned short gfx_mug_blaiseTiles[];
    extern const unsigned short gfx_mug_blaise_angryTiles[];
    extern const unsigned short gfx_mug_blaise_annoyedTiles[];
    extern const unsigned short gfx_mug_blaise_happyTiles[];
    extern const unsigned short gfx_mug_blaise_sadTiles[];
    extern const unsigned short gfx_mug_blaise_scaredTiles[];
    extern const unsigned short gfx_mug_blaise_shockedTiles[];
    extern const unsigned short gfx_mug_blaise_thoughtfulTiles[];
    extern const unsigned short gfx_mug_blaisePal[];
    extern const unsigned short gfx_mug_tannTiles[];
    extern const unsigned short gfx_mug_tannPal[];
    extern const unsigned short gfx_mug_faunTiles[];
    extern const unsigned short gfx_mug_faun_angryTiles[];
    extern const unsigned short gfx_mug_faun_seriousTiles[];
    extern const unsigned short gfx_mug_faun_shockedTiles[];
    extern const unsigned short gfx_mug_faunPal[];
    extern const unsigned short gfx_mug_eliseTiles[];
    extern const unsigned short gfx_mug_elisePal[];
    extern const unsigned short gfx_mug_emerysTiles[];
    extern const unsigned short gfx_mug_emerysPal[];
    extern const unsigned short gfx_mug_rubysTiles[];
    extern const unsigned short gfx_mug_rubysPal[];
    extern const unsigned short gfx_mug_saphiraTiles[];
    extern const unsigned short gfx_mug_saphiraPal[];
    extern const unsigned short gfx_mug_harrenfeldTiles[];
    extern const unsigned short gfx_mug_harrenfeldPal[];
    extern const unsigned short gfx_mug_albusTiles[];
    extern const unsigned short gfx_mug_albusPal[];
    extern const unsigned short gfx_mug_faun_youngTiles[];
    extern const unsigned short gfx_mug_faun_youngPal[];
    extern const unsigned short gfx_pkmn_species_251_pokemon_celebi_frontspriteTiles[];
    extern const unsigned short gfx_pkmn_species_251_pokemon_celebi_frontspritePal[];
    extern const unsigned short gfx_mug_larissaTiles[];
    extern const unsigned short gfx_mug_larissaPal[];
    extern const unsigned short gfx_mug_primusTiles[];
    extern const unsigned short gfx_mug_primusPal[];
    extern const unsigned short gfx_mug_teahTiles[];
    extern const unsigned short gfx_mug_teahPal[];
    extern const unsigned short gfx_mug_narcissaTiles[];
    extern const unsigned short gfx_mug_narcissaPal[];
    extern const unsigned short gfx_mug_luciusTiles[];
    extern const unsigned short gfx_mug_luciusPal[];
    extern const unsigned short gfx_mug_luckyTiles[];
    extern const unsigned short gfx_mug_luckyPal[];
    extern const unsigned short gfx_mug_lucky_scaredTiles[];
    extern const unsigned short gfx_mug_lucky_shockedTiles[];

    extern u8 str_mug_mistral[];
    extern u8 str_mug_hiro[];
    extern u8 str_mug_lester[];
    extern u8 str_mug_igva[];
    extern u8 str_mug_blackbeard[];
    extern u8 str_mug_rin[];
    extern u8 str_mug_rival[];
    extern u8 str_mug_brix[];
    extern u8 str_mug_may[];
    extern u8 str_mug_felix[];
    extern u8 str_mug_felix[];
    extern u8 str_mug_blaise[];
    extern u8 str_mug_tann[];
    extern u8 str_mug_faun[];
    extern u8 str_mug_elise[];
    extern u8 str_mug_emerys[];
    extern u8 str_mug_rubys[];
    extern u8 str_mug_saphira[];
    extern u8 str_mug_harrenfeld[];
    extern u8 str_mug_albus[];
    extern u8 str_mug_larissa[];
    extern u8 str_mug_primus[];
    extern u8 str_mug_celebi[];
    extern u8 str_mug_teah[];
    extern u8 str_mug_narcissa[];
    extern u8 str_mug_lucius[];
    extern u8 str_mug_lucky[];

#ifdef	__cplusplus
}
#endif

#endif	/* MUGSHOT_H */

