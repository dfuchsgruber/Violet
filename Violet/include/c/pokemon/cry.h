/*
 * pokemon_cry.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_CRY_H_
#define INCLUDE_C_POKEMON_CRY_H_

#include "types.h"
#include "pokemon/count.h"

typedef struct {
    u8 header[4];
    void *data;
    u8 vol_curve[4];
} pokemon_cry;

pokemon_cry pokemon_cries_forward[POKEMON_CNT];
pokemon_cry pokemon_cries_backward[POKEMON_CNT];

/**
 * Checks if a cry is playing and clears the cry songs.
 * @return if a cry is playing.
 **/
bool cry_is_playing_or_clear_cry_songs();

/**
 * Plays the cry of a pokemon
 * @param species The species to play the cry of
 * @param feature Feature for the cry
 */
void pokemon_play_cry(u16 species, u8 feature);

/**
 * Big callback to proceed the cry delay and return the volume to normal once the cry has finished.
 * @param self self-reference in the big_callback list
 */
void cry_proceed(u8 self);

/**
 * Checks if a cry has finished and if so, clears something (maybe volume related?). This
 * function is recommended to be checked in each frame after a cry has been launched.
 * @return if any cry has finished (i.e. cry_proceed is not an active big_callback)
 */
bool cry_has_finished();

// Extern cries from wav2agb

extern u8 cry_661[];
extern u8 cry_662[];
extern u8 cry_663[];
extern u8 cry_396[];
extern u8 cry_397[];
extern u8 cry_398[];
extern u8 cry_436[];
extern u8 cry_437[];
extern u8 cry_672[];
extern u8 cry_673[];
extern u8 cry_708[];
extern u8 cry_709[];
extern u8 cry_669[];
extern u8 cry_670[];
extern u8 cry_671[];
extern u8 cry_470[];
extern u8 cry_700[];
extern u8 cry_595[];
extern u8 cry_596[];
extern u8 cry_597[];
extern u8 cry_598[];
extern u8 cry_679[];
extern u8 cry_680[];
extern u8 cry_681[];
extern u8 cry_302[];
extern u8 cry_592[];
extern u8 cry_593[];
extern u8 cry_200[];
extern u8 cry_475[];
extern u8 cry_636[];
extern u8 cry_637[];
extern u8 cry_471[];
extern u8 cry_701[];
extern u8 cry_462[];
extern u8 cry_468[];
extern u8 cry_707[];
extern u8 cry_607[];
extern u8 cry_608[];
extern u8 cry_609[];
extern u8 cry_459[];
extern u8 cry_460[];
extern u8 cry_424[];
extern u8 cry_430[];
extern u8 cry_478[];
extern u8 cry_472[];
extern u8 cry_466[];
extern u8 cry_473[];
extern u8 cry_442[];
extern u8 cry_463[];
extern u8 cry_476[];
extern u8 cry_429[];
extern u8 cry_467[];
extern u8 cry_477[];
extern u8 cry_447[];
extern u8 cry_448[];
extern u8 cry_443[];
extern u8 cry_444[];
extern u8 cry_445[];
extern u8 cry_115[];
extern u8 cry_474[];
extern u8 cry_464[];
extern u8 cry_446[];
extern u8 cry_780[];
extern u8 cry_440[];
extern u8 cry_438[];
extern u8 cry_433[];
extern u8 cry_172[];
extern u8 cry_479[];
extern u8 cry_757[];
extern u8 cry_758[];
extern u8 cry_icognito[];
extern u8 cry_bisasam[];
extern u8 cry_bisaknosp[];
extern u8 cry_bisaflor[];
extern u8 cry_glumanda[];
extern u8 cry_glutexo[];
extern u8 cry_glurak[];
extern u8 cry_schiggy[];
extern u8 cry_schillok[];
extern u8 cry_turtok[];
extern u8 cry_hornliu[];
extern u8 cry_kokuna[];
extern u8 cry_bibor[];
extern u8 cry_pikachu[];
extern u8 cry_raichu[];
extern u8 cry_sandan[];
extern u8 cry_sandamer[];
extern u8 cry_nidoranw[];
extern u8 cry_nidorina[];
extern u8 cry_nidoqueen[];
extern u8 cry_nidoranm[];
extern u8 cry_nidorino[];
extern u8 cry_nidoking[];
extern u8 cry_vulpix[];
extern u8 cry_vulnona[];
extern u8 cry_pummeluff[];
extern u8 cry_knuddeluff[];
extern u8 cry_zubat[];
extern u8 cry_golbat[];
extern u8 cry_myrapla[];
extern u8 cry_duflor[];
extern u8 cry_giflor[];
extern u8 cry_digda[];
extern u8 cry_digdri[];
extern u8 cry_enton[];
extern u8 cry_entoron[];
extern u8 cry_menki[];
extern u8 cry_rasaff[];
extern u8 cry_fukano[];
extern u8 cry_arkani[];
extern u8 cry_abra[];
extern u8 cry_kadabra[];
extern u8 cry_simsala[];
extern u8 cry_machollo[];
extern u8 cry_maschock[];
extern u8 cry_machomei[];
extern u8 cry_knofensa[];
extern u8 cry_ultrigaria[];
extern u8 cry_sarzenia[];
extern u8 cry_tentacha[];
extern u8 cry_tentoxa[];
extern u8 cry_kleinstein[];
extern u8 cry_georok[];
extern u8 cry_geowaz[];
extern u8 cry_ponita[];
extern u8 cry_gallopa[];
extern u8 cry_flegmon[];
extern u8 cry_lahmus[];
extern u8 cry_magnetilo[];
extern u8 cry_magneton[];
extern u8 cry_porenta[];
extern u8 cry_dodu[];
extern u8 cry_dodri[];
extern u8 cry_jurob[];
extern u8 cry_jugong[];
extern u8 cry_sleima[];
extern u8 cry_sleimok[];
extern u8 cry_muschas[];
extern u8 cry_austos[];
extern u8 cry_nebulak[];
extern u8 cry_alpollo[];
extern u8 cry_gengar[];
extern u8 cry_onix[];
extern u8 cry_traumato[];
extern u8 cry_hypno[];
extern u8 cry_krabby[];
extern u8 cry_kingler[];
extern u8 cry_voltobal[];
extern u8 cry_lektrobal[];
extern u8 cry_owei[];
extern u8 cry_kokowei[];
extern u8 cry_tragosso[];
extern u8 cry_knogga[];
extern u8 cry_kicklee[];
extern u8 cry_nockchan[];
extern u8 cry_schlurp[];
extern u8 cry_smogon[];
extern u8 cry_smogmog[];
extern u8 cry_rihorn[];
extern u8 cry_rizeros[];
extern u8 cry_chaneira[];
extern u8 cry_seeper[];
extern u8 cry_seemon[];
extern u8 cry_sterndu[];
extern u8 cry_starmie[];
extern u8 cry_sichlor[];
extern u8 cry_elektek[];
extern u8 cry_magmar[];
extern u8 cry_pinsir[];
extern u8 cry_tauros[];
extern u8 cry_karpador[];
extern u8 cry_garados[];
extern u8 cry_lapras[];
extern u8 cry_ditto[];
extern u8 cry_evoli[];
extern u8 cry_aquana[];
extern u8 cry_blitza[];
extern u8 cry_flamara[];
extern u8 cry_porygon[];
extern u8 cry_amonitas[];
extern u8 cry_amoroso[];
extern u8 cry_kabuto[];
extern u8 cry_kabutops[];
extern u8 cry_aerodactyl[];
extern u8 cry_relaxo[];
extern u8 cry_arktos[];
extern u8 cry_zapdos[];
extern u8 cry_lavados[];
extern u8 cry_dratini[];
extern u8 cry_dragonir[];
extern u8 cry_dragoran[];
extern u8 cry_mewtu[];
extern u8 cry_mew[];
extern u8 cry_endivie[];
extern u8 cry_lorblatt[];
extern u8 cry_meganie[];
extern u8 cry_feurigel[];
extern u8 cry_igelavar[];
extern u8 cry_tornupto[];
extern u8 cry_karnimani[];
extern u8 cry_tyracroc[];
extern u8 cry_impergator[];
extern u8 cry_ledyba[];
extern u8 cry_ledian[];
extern u8 cry_webarak[];
extern u8 cry_ariados[];
extern u8 cry_iksbat[];
extern u8 cry_lampi[];
extern u8 cry_lanturn[];
extern u8 cry_togepi[];
extern u8 cry_togetic[];
extern u8 cry_natu[];
extern u8 cry_xatu[];
extern u8 cry_voltilamm[];
extern u8 cry_waaty[];
extern u8 cry_ampharos[];
extern u8 cry_blubella[];
extern u8 cry_marill[];
extern u8 cry_azumarill[];
extern u8 cry_mogelbaum[];
extern u8 cry_griffel[];
extern u8 cry_felino[];
extern u8 cry_morlord[];
extern u8 cry_psiana[];
extern u8 cry_nachtara[];
extern u8 cry_kramurx[];
extern u8 cry_laschoking[];
extern u8 cry_tannza[];
extern u8 cry_forstellka[];
extern u8 cry_skorgla[];
extern u8 cry_stahlos[];
extern u8 cry_snubbull[];
extern u8 cry_granbull[];
extern u8 cry_scherox[];
extern u8 cry_fluffeluff[];
extern u8 cry_skaraborn[];
extern u8 cry_teddiursa[];
extern u8 cry_ursaring[];
extern u8 cry_schneckmag[];
extern u8 cry_magcargo[];
extern u8 cry_quiekel[];
extern u8 cry_keifel[];
extern u8 cry_remoraid[];
extern u8 cry_octillery[];
extern u8 cry_botogel[];
extern u8 cry_panzaeron[];
extern u8 cry_hunduster[];
extern u8 cry_hundemon[];
extern u8 cry_seedraking[];
extern u8 cry_phanpy[];
extern u8 cry_donphan[];
extern u8 cry_porygon2[];
extern u8 cry_rabauz[];
extern u8 cry_kapoera[];
extern u8 cry_elekid[];
extern u8 cry_magby[];
extern u8 cry_miltank[];
extern u8 cry_heiteira[];
extern u8 cry_raikou[];
extern u8 cry_entei[];
extern u8 cry_suicune[];
extern u8 cry_larvitar[];
extern u8 cry_pupitar[];
extern u8 cry_despotar[];
extern u8 cry_lugia[];
extern u8 cry_ho_oh[];
extern u8 cry_celebi[];
extern u8 cry_tropius[];
extern u8 cry_firnontor[];
extern u8 cry_lockschal[];
extern u8 cry_stichschal[];
extern u8 cry_stahlstich[];
extern u8 cry_weluno[];
extern u8 cry_orthodos[];
extern u8 cry_zerbertres[];
extern u8 cry_seekid[];
extern u8 cry_seeskull[];
extern u8 cry_skullydra[];
extern u8 cry_fiffyen[];
extern u8 cry_magnayen[];
extern u8 cry_zigzachs[];
extern u8 cry_geradaks[];
extern u8 cry_waumpel[];
extern u8 cry_schaloko[];
extern u8 cry_papinella[];
extern u8 cry_panekon[];
extern u8 cry_pudox[];
extern u8 cry_loturzel[];
extern u8 cry_lombrero[];
extern u8 cry_kappalores[];
extern u8 cry_samurzel[];
extern u8 cry_blanas[];
extern u8 cry_tengulist[];
extern u8 cry_nincada[];
extern u8 cry_ninjask[];
extern u8 cry_ninjatom[];
extern u8 cry_schwalbini[];
extern u8 cry_schwalboss[];
extern u8 cry_knilz[];
extern u8 cry_kapilz[];
extern u8 cry_pandir[];
extern u8 cry_wingull[];
extern u8 cry_pelipper[];
extern u8 cry_gehweiher[];
extern u8 cry_maskeregen[];
extern u8 cry_wailmer[];
extern u8 cry_wailord[];
extern u8 cry_eneco[];
extern u8 cry_enekoro[];
extern u8 cry_kecleon[];
extern u8 cry_puppance[];
extern u8 cry_lepumentas[];
extern u8 cry_nasgnet[];
extern u8 cry_schmerbe[];
extern u8 cry_welsar[];
extern u8 cry_krebscorps[];
extern u8 cry_krebutack[];
extern u8 cry_barschwa[];
extern u8 cry_milotic[];
extern u8 cry_kanivanha[];
extern u8 cry_tohaido[];
extern u8 cry_knacklion[];
extern u8 cry_vibrava[];
extern u8 cry_libelldra[];
extern u8 cry_frizelbliz[];
extern u8 cry_voltenso[];
extern u8 cry_camaub[];
extern u8 cry_camerupt[];
extern u8 cry_seemops[];
extern u8 cry_seejong[];
extern u8 cry_walraisa[];
extern u8 cry_tuska[];
extern u8 cry_noktuska[];
extern u8 cry_schneppke[];
extern u8 cry_lunastein[];
extern u8 cry_sonnfel[];
extern u8 cry_azurill[];
extern u8 cry_spoink[];
extern u8 cry_groink[];
extern u8 cry_flunkifer[];
extern u8 cry_meditie[];
extern u8 cry_meditalis[];
extern u8 cry_wablu[];
extern u8 cry_altaria[];
extern u8 cry_zwirrlicht[];
extern u8 cry_zwirrklop[];
extern u8 cry_bummelz[];
extern u8 cry_muntier[];
extern u8 cry_letarking[];
extern u8 cry_perlu[];
extern u8 cry_aalabyss[];
extern u8 cry_saganabyss[];
extern u8 cry_absol[];
extern u8 cry_shuppet[];
extern u8 cry_banette[];
extern u8 cry_vipitis[];
extern u8 cry_sengo[];
extern u8 cry_relicanth[];
extern u8 cry_stollunior[];
extern u8 cry_stollrak[];
extern u8 cry_stolloss[];
extern u8 cry_formeo[];
extern u8 cry_liliep[];
extern u8 cry_wielie[];
extern u8 cry_anorith[];
extern u8 cry_armaldo[];
extern u8 cry_trasla[];
extern u8 cry_kirlia[];
extern u8 cry_guardevoir[];
extern u8 cry_kindwurm[];
extern u8 cry_draschel[];
extern u8 cry_brutalanda[];
extern u8 cry_tanhel[];
extern u8 cry_metang[];
extern u8 cry_metagross[];
extern u8 cry_regirock[];
extern u8 cry_regice[];
extern u8 cry_registeel[];
extern u8 cry_kyogre[];
extern u8 cry_groudon[];
extern u8 cry_rayquaza[];
extern u8 cry_latias[];
extern u8 cry_latios[];
extern u8 cry_jirachi[];
extern u8 cry_deoxys[];
extern u8 cry_palimpalim[];

#endif /* INCLUDE_C_POKEMON_CRY_H_ */
