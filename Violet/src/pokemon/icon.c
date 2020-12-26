#include "types.h"
#include "pokemon/count.h"
#include "pokemon/sprites.h"

 const void *pokemon_icons[POKEMON_CNT] = {

    gfx_pkmn_species_000_pokemon_pokemon_0_iconTiles,
    gfx_pkmn_species_001_pokemon_bisasam_iconTiles,
    gfx_pkmn_species_002_pokemon_bisaknosp_iconTiles,
    gfx_pkmn_species_003_pokemon_bisaflor_iconTiles,
    gfx_pkmn_species_004_pokemon_glumanda_iconTiles,
    gfx_pkmn_species_005_pokemon_glutexo_iconTiles,
    gfx_pkmn_species_006_pokemon_glurak_iconTiles,
    gfx_pkmn_species_007_pokemon_schiggy_iconTiles,
    gfx_pkmn_species_008_pokemon_schillok_iconTiles,
    gfx_pkmn_species_009_pokemon_turtok_iconTiles,
    gfx_pkmn_species_010_pokemon_dartiri_iconTiles,
    gfx_pkmn_species_011_pokemon_dartignis_iconTiles,
    gfx_pkmn_species_012_pokemon_fiaro_iconTiles,
    gfx_pkmn_species_013_pokemon_hornliu_iconTiles,
    gfx_pkmn_species_014_pokemon_kokuna_iconTiles,
    gfx_pkmn_species_015_pokemon_bibor_iconTiles,
    gfx_pkmn_species_016_pokemon_staralili_iconTiles,
    gfx_pkmn_species_017_pokemon_staravia_iconTiles,
    gfx_pkmn_species_018_pokemon_staraptor_iconTiles,
    gfx_pkmn_species_019_pokemon_bronzel_iconTiles,
    gfx_pkmn_species_020_pokemon_bronzong_iconTiles,
    gfx_pkmn_species_021_pokemon_maehikel_iconTiles,
    gfx_pkmn_species_022_pokemon_chevrumm_iconTiles,
    gfx_pkmn_species_023_pokemon_paragoni_iconTiles,
    gfx_pkmn_species_024_pokemon_trombork_iconTiles,
    gfx_pkmn_species_025_pokemon_pikachu_iconTiles,
    gfx_pkmn_species_026_pokemon_raichu_iconTiles,
    gfx_pkmn_species_027_pokemon_sandan_iconTiles,
    gfx_pkmn_species_028_pokemon_sandamer_iconTiles,
    gfx_pkmn_species_029_pokemon_nidoranw_iconTiles,
    gfx_pkmn_species_030_pokemon_nidorina_iconTiles,
    gfx_pkmn_species_031_pokemon_nidoqueen_iconTiles,
    gfx_pkmn_species_032_pokemon_nidoranm_iconTiles,
    gfx_pkmn_species_033_pokemon_nidorino_iconTiles,
    gfx_pkmn_species_034_pokemon_nidoking_iconTiles,
    gfx_pkmn_species_035_pokemon_floette_iconTiles,
    gfx_pkmn_species_036_pokemon_florges_iconTiles,
    gfx_pkmn_species_037_pokemon_vulpix_iconTiles,
    gfx_pkmn_species_038_pokemon_vulnona_iconTiles,
    gfx_pkmn_species_039_pokemon_pummeluff_iconTiles,
    gfx_pkmn_species_040_pokemon_knuddeluff_iconTiles,
    gfx_pkmn_species_041_pokemon_zubat_iconTiles,
    gfx_pkmn_species_042_pokemon_golbat_iconTiles,
    gfx_pkmn_species_043_pokemon_myrapla_iconTiles,
    gfx_pkmn_species_044_pokemon_duflor_iconTiles,
    gfx_pkmn_species_045_pokemon_giflor_iconTiles,
    gfx_pkmn_species_046_pokemon_folipurba_iconTiles,
    gfx_pkmn_species_047_pokemon_feelinara_iconTiles,
    gfx_pkmn_species_048_pokemon_wattzapf_iconTiles,
    gfx_pkmn_species_049_pokemon_voltula_iconTiles,
    gfx_pkmn_species_050_pokemon_digda_iconTiles,
    gfx_pkmn_species_051_pokemon_digdri_iconTiles,
    gfx_pkmn_species_052_pokemon_kastadur_iconTiles,
    gfx_pkmn_species_053_pokemon_tentantel_iconTiles,
    gfx_pkmn_species_054_pokemon_enton_iconTiles,
    gfx_pkmn_species_055_pokemon_entoron_iconTiles,
    gfx_pkmn_species_056_pokemon_menki_iconTiles,
    gfx_pkmn_species_057_pokemon_rasaff_iconTiles,
    gfx_pkmn_species_058_pokemon_fukano_iconTiles,
    gfx_pkmn_species_059_pokemon_arkani_iconTiles,
    gfx_pkmn_species_060_pokemon_gramokles_iconTiles,
    gfx_pkmn_species_061_pokemon_duokles_iconTiles,
    gfx_pkmn_species_062_pokemon_durengard_iconTiles,
    gfx_pkmn_species_063_pokemon_abra_iconTiles,
    gfx_pkmn_species_064_pokemon_kadabra_iconTiles,
    gfx_pkmn_species_065_pokemon_simsala_iconTiles,
    gfx_pkmn_species_066_pokemon_machollo_iconTiles,
    gfx_pkmn_species_067_pokemon_maschock_iconTiles,
    gfx_pkmn_species_068_pokemon_machomei_iconTiles,
    gfx_pkmn_species_069_pokemon_knofensa_iconTiles,
    gfx_pkmn_species_070_pokemon_ultrigaria_iconTiles,
    gfx_pkmn_species_071_pokemon_sarzenia_iconTiles,
    gfx_pkmn_species_072_pokemon_tentacha_iconTiles,
    gfx_pkmn_species_073_pokemon_tentoxa_iconTiles,
    gfx_pkmn_species_074_pokemon_kleinstein_iconTiles,
    gfx_pkmn_species_075_pokemon_georok_iconTiles,
    gfx_pkmn_species_076_pokemon_geowaz_iconTiles,
    gfx_pkmn_species_077_pokemon_ponita_iconTiles,
    gfx_pkmn_species_078_pokemon_gallopa_iconTiles,
    gfx_pkmn_species_079_pokemon_flegmon_iconTiles,
    gfx_pkmn_species_080_pokemon_lahmus_iconTiles,
    gfx_pkmn_species_081_pokemon_magnetilo_iconTiles,
    gfx_pkmn_species_082_pokemon_magneton_iconTiles,
    gfx_pkmn_species_083_pokemon_porenta_iconTiles,
    gfx_pkmn_species_084_pokemon_dodu_iconTiles,
    gfx_pkmn_species_085_pokemon_dodri_iconTiles,
    gfx_pkmn_species_086_pokemon_jurbo_iconTiles,
    gfx_pkmn_species_087_pokemon_jugong_iconTiles,
    gfx_pkmn_species_088_pokemon_sleima_iconTiles,
    gfx_pkmn_species_089_pokemon_sleimok_iconTiles,
    gfx_pkmn_species_090_pokemon_muschas_iconTiles,
    gfx_pkmn_species_091_pokemon_austos_iconTiles,
    gfx_pkmn_species_092_pokemon_nebulak_iconTiles,
    gfx_pkmn_species_093_pokemon_alpollo_iconTiles,
    gfx_pkmn_species_094_pokemon_gengar_iconTiles,
    gfx_pkmn_species_095_pokemon_onix_iconTiles,
    gfx_pkmn_species_096_pokemon_traumato_iconTiles,
    gfx_pkmn_species_097_pokemon_hypno_iconTiles,
    gfx_pkmn_species_098_pokemon_krabby_iconTiles,
    gfx_pkmn_species_099_pokemon_kingler_iconTiles,
    gfx_pkmn_species_100_pokemon_voltobal_iconTiles,
    gfx_pkmn_species_101_pokemon_lektrobal_iconTiles,
    gfx_pkmn_species_102_pokemon_owei_iconTiles,
    gfx_pkmn_species_103_pokemon_kokowei_iconTiles,
    gfx_pkmn_species_104_pokemon_tragosso_iconTiles,
    gfx_pkmn_species_105_pokemon_knogga_iconTiles,
    gfx_pkmn_species_106_pokemon_kicklee_iconTiles,
    gfx_pkmn_species_107_pokemon_nockchan_iconTiles,
    gfx_pkmn_species_108_pokemon_schlurp_iconTiles,
    gfx_pkmn_species_109_pokemon_smogon_iconTiles,
    gfx_pkmn_species_110_pokemon_smogmog_iconTiles,
    gfx_pkmn_species_111_pokemon_rihorn_iconTiles,
    gfx_pkmn_species_112_pokemon_rizeros_iconTiles,
    gfx_pkmn_species_113_pokemon_chaneira_iconTiles,
    gfx_pkmn_species_114_pokemon_zobiris_iconTiles,
    gfx_pkmn_species_115_pokemon_kangama_iconTiles,
    gfx_pkmn_species_116_pokemon_seeper_iconTiles,
    gfx_pkmn_species_117_pokemon_seemon_iconTiles,
    gfx_pkmn_species_118_pokemon_quabbel_iconTiles,
    gfx_pkmn_species_119_pokemon_apoquallyp_iconTiles,
    gfx_pkmn_species_120_pokemon_sterndu_iconTiles,
    gfx_pkmn_species_121_pokemon_starmie_iconTiles,
    gfx_pkmn_species_122_pokemon_traunfugil_iconTiles,
    gfx_pkmn_species_123_pokemon_sichlor_iconTiles,
    gfx_pkmn_species_124_pokemon_galagladi_iconTiles,
    gfx_pkmn_species_125_pokemon_elektek_iconTiles,
    gfx_pkmn_species_126_pokemon_magmar_iconTiles,
    gfx_pkmn_species_127_pokemon_pinsir_iconTiles,
    gfx_pkmn_species_128_pokemon_tauros_iconTiles,
    gfx_pkmn_species_129_pokemon_karpador_iconTiles,
    gfx_pkmn_species_130_pokemon_garados_iconTiles,
    gfx_pkmn_species_131_pokemon_lapras_iconTiles,
    gfx_pkmn_species_132_pokemon_ditto_iconTiles,
    gfx_pkmn_species_133_pokemon_evoli_iconTiles,
    gfx_pkmn_species_134_pokemon_aquana_iconTiles,
    gfx_pkmn_species_135_pokemon_blitza_iconTiles,
    gfx_pkmn_species_136_pokemon_flamara_iconTiles,
    gfx_pkmn_species_137_pokemon_porygon_iconTiles,
    gfx_pkmn_species_138_pokemon_amonitas_iconTiles,
    gfx_pkmn_species_139_pokemon_amoroso_iconTiles,
    gfx_pkmn_species_140_pokemon_kabuto_iconTiles,
    gfx_pkmn_species_141_pokemon_kabutops_iconTiles,
    gfx_pkmn_species_142_pokemon_aerodactyl_iconTiles,
    gfx_pkmn_species_143_pokemon_relaxo_iconTiles,
    gfx_pkmn_species_144_pokemon_arktos_iconTiles,
    gfx_pkmn_species_145_pokemon_zapdos_iconTiles,
    gfx_pkmn_species_146_pokemon_lavados_iconTiles,
    gfx_pkmn_species_147_pokemon_dratini_iconTiles,
    gfx_pkmn_species_148_pokemon_dragonir_iconTiles,
    gfx_pkmn_species_149_pokemon_dragoran_iconTiles,
    gfx_pkmn_species_150_pokemon_mewtu_iconTiles,
    gfx_pkmn_species_151_pokemon_mew_iconTiles,
    gfx_pkmn_species_152_pokemon_endivie_iconTiles,
    gfx_pkmn_species_153_pokemon_lorblatt_iconTiles,
    gfx_pkmn_species_154_pokemon_meganie_iconTiles,
    gfx_pkmn_species_155_pokemon_feurigel_iconTiles,
    gfx_pkmn_species_156_pokemon_igelavar_iconTiles,
    gfx_pkmn_species_157_pokemon_tornupto_iconTiles,
    gfx_pkmn_species_158_pokemon_karnimani_iconTiles,
    gfx_pkmn_species_159_pokemon_tyracroc_iconTiles,
    gfx_pkmn_species_160_pokemon_impergator_iconTiles,
    gfx_pkmn_species_161_pokemon_ignivor_iconTiles,
    gfx_pkmn_species_162_pokemon_ramoth_iconTiles,
    gfx_pkmn_species_163_pokemon_glaziola_iconTiles,
    gfx_pkmn_species_164_pokemon_resladero_iconTiles,
    gfx_pkmn_species_165_pokemon_ledyba_iconTiles,
    gfx_pkmn_species_166_pokemon_ledian_iconTiles,
    gfx_pkmn_species_167_pokemon_webarak_iconTiles,
    gfx_pkmn_species_168_pokemon_ariados_iconTiles,
    gfx_pkmn_species_169_pokemon_iksbat_iconTiles,
    gfx_pkmn_species_170_pokemon_lampi_iconTiles,
    gfx_pkmn_species_171_pokemon_lanturn_iconTiles,
    gfx_pkmn_species_172_pokemon_magnezone_iconTiles,
    gfx_pkmn_species_173_pokemon_togekiss_iconTiles,
    gfx_pkmn_species_174_pokemon_flabebe_iconTiles,
    gfx_pkmn_species_175_pokemon_togepi_iconTiles,
    gfx_pkmn_species_176_pokemon_togetic_iconTiles,
    gfx_pkmn_species_177_pokemon_natu_iconTiles,
    gfx_pkmn_species_178_pokemon_xatu_iconTiles,
    gfx_pkmn_species_179_pokemon_voltilamm_iconTiles,
    gfx_pkmn_species_180_pokemon_waaty_iconTiles,
    gfx_pkmn_species_181_pokemon_ampharos_iconTiles,
    gfx_pkmn_species_182_pokemon_blubella_iconTiles,
    gfx_pkmn_species_183_pokemon_marill_iconTiles,
    gfx_pkmn_species_184_pokemon_azumarill_iconTiles,
    gfx_pkmn_species_185_pokemon_mogelbaum_iconTiles,
    gfx_pkmn_species_186_pokemon_clavion_iconTiles,
    gfx_pkmn_species_187_pokemon_lichtel_iconTiles,
    gfx_pkmn_species_188_pokemon_laternecto_iconTiles,
    gfx_pkmn_species_189_pokemon_sklelabra_iconTiles,
    gfx_pkmn_species_190_pokemon_griffel_iconTiles,
    gfx_pkmn_species_191_pokemon_shnebedeck_iconTiles,
    gfx_pkmn_species_192_pokemon_rexblisar_iconTiles,
    gfx_pkmn_species_193_pokemon_ambidiffel_iconTiles,
    gfx_pkmn_species_194_pokemon_felino_iconTiles,
    gfx_pkmn_species_195_pokemon_morlord_iconTiles,
    gfx_pkmn_species_196_pokemon_psiana_iconTiles,
    gfx_pkmn_species_197_pokemon_nachtara_iconTiles,
    gfx_pkmn_species_198_pokemon_kramurx_iconTiles,
    gfx_pkmn_species_199_pokemon_laschoking_iconTiles,
    gfx_pkmn_species_200_pokemon_kramshef_iconTiles,
    gfx_pkmn_species_201_pokemon_icognito_iconTiles,
    gfx_pkmn_species_202_pokemon_frosdedje_iconTiles,
    gfx_pkmn_species_203_pokemon_skorgro_iconTiles,
    gfx_pkmn_species_204_pokemon_tannza_iconTiles,
    gfx_pkmn_species_205_pokemon_forstellka_iconTiles,
    gfx_pkmn_species_206_pokemon_elevoltek_iconTiles,
    gfx_pkmn_species_207_pokemon_skorgla_iconTiles,
    gfx_pkmn_species_208_pokemon_stahlos_iconTiles,
    gfx_pkmn_species_209_pokemon_snubbull_iconTiles,
    gfx_pkmn_species_210_pokemon_granbull_iconTiles,
    gfx_pkmn_species_211_pokemon_mamutel_iconTiles,
    gfx_pkmn_species_212_pokemon_scherox_iconTiles,
    gfx_pkmn_species_213_pokemon_fluffeluff_iconTiles,
    gfx_pkmn_species_214_pokemon_skaraborn_iconTiles,
    gfx_pkmn_species_215_pokemon_kryppuk_iconTiles,
    gfx_pkmn_species_216_pokemon_teddiursa_iconTiles,
    gfx_pkmn_species_217_pokemon_ursaring_iconTiles,
    gfx_pkmn_species_218_pokemon_schneckmag_iconTiles,
    gfx_pkmn_species_219_pokemon_magcargo_iconTiles,
    gfx_pkmn_species_220_pokemon_quiekel_iconTiles,
    gfx_pkmn_species_221_pokemon_keifel_iconTiles,
    gfx_pkmn_species_222_pokemon_mampfaxo_iconTiles,
    gfx_pkmn_species_223_pokemon_remoraid_iconTiles,
    gfx_pkmn_species_224_pokemon_octillery_iconTiles,
    gfx_pkmn_species_225_pokemon_botogel_iconTiles,
    gfx_pkmn_species_226_pokemon_schlurplek_iconTiles,
    gfx_pkmn_species_227_pokemon_panzaeron_iconTiles,
    gfx_pkmn_species_228_pokemon_hunduster_iconTiles,
    gfx_pkmn_species_229_pokemon_hundemon_iconTiles,
    gfx_pkmn_species_230_pokemon_seedraking_iconTiles,
    gfx_pkmn_species_231_pokemon_phanpy_iconTiles,
    gfx_pkmn_species_232_pokemon_donphan_iconTiles,
    gfx_pkmn_species_233_pokemon_porygon2_iconTiles,
    gfx_pkmn_species_234_pokemon_voluminas_iconTiles,
    gfx_pkmn_species_235_pokemon_traunmagil_iconTiles,
    gfx_pkmn_species_236_pokemon_rabauz_iconTiles,
    gfx_pkmn_species_237_pokemon_kapoera_iconTiles,
    gfx_pkmn_species_238_pokemon_sen_long_iconTiles,
    gfx_pkmn_species_239_pokemon_elekid_iconTiles,
    gfx_pkmn_species_240_pokemon_magby_iconTiles,
    gfx_pkmn_species_241_pokemon_miltank_iconTiles,
    gfx_pkmn_species_242_pokemon_heiteira_iconTiles,
    gfx_pkmn_species_243_pokemon_raikou_iconTiles,
    gfx_pkmn_species_244_pokemon_entei_iconTiles,
    gfx_pkmn_species_245_pokemon_suicune_iconTiles,
    gfx_pkmn_species_246_pokemon_larvitar_iconTiles,
    gfx_pkmn_species_247_pokemon_pupitar_iconTiles,
    gfx_pkmn_species_248_pokemon_despotar_iconTiles,
    gfx_pkmn_species_249_pokemon_lugia_iconTiles,
    gfx_pkmn_species_250_pokemon_ho_oh_iconTiles,
    gfx_pkmn_species_251_pokemon_celebi_iconTiles,
    gfx_pkmn_rotom_heat_iconTiles,
    gfx_pkmn_rotom_wash_iconTiles,
    gfx_pkmn_rotom_frost_iconTiles,
    gfx_pkmn_rotom_fan_iconTiles,
    gfx_pkmn_rotom_mow_iconTiles,
    gfx_pkmn_species_257_pokemon_durengarda_iconTiles,
    gfx_pkmn_mega_sandamer_iconTiles,
    gfx_pkmn_mega_lahmus_iconTiles,
    gfx_pkmn_species_260_pokemon_turtokm_iconTiles,
    gfx_pkmn_species_261_pokemon_ampharaosm_iconTiles,
    gfx_pkmn_species_262_pokemon_banette_mega_iconTiles,
    gfx_pkmn_species_263_pokemon_biborm_iconTiles,
    gfx_pkmn_species_264_pokemon_altariam_iconTiles,
    gfx_pkmn_species_265_pokemon_geowazm_iconTiles,
    gfx_pkmn_species_266_pokemon_sengom_iconTiles,
    gfx_pkmn_species_267_pokemon_vipitism_iconTiles,
    gfx_pkmn_species_268_pokemon_zobirism_iconTiles,
    gfx_pkmn_species_269_pokemon_tropius_mega_iconTiles,
    gfx_pkmn_species_270_pokemon_octillery_mega_iconTiles,
    gfx_pkmn_species_271_pokemon_rasaff_mega_iconTiles,
    gfx_pkmn_species_272_pokemon_110_iconTiles,
    gfx_pkmn_species_273_pokemon_111_iconTiles,
    gfx_pkmn_species_274_pokemon_112_iconTiles,
    gfx_pkmn_species_275_pokemon_113_iconTiles,
    gfx_pkmn_species_276_pokemon_114_iconTiles,
    gfx_pkmn_species_277_pokemon_lockschal_iconTiles,
    gfx_pkmn_species_278_pokemon_stichschal_iconTiles,
    gfx_pkmn_species_279_pokemon_stahlstich_iconTiles,
    gfx_pkmn_species_280_pokemon_weluno_iconTiles,
    gfx_pkmn_species_281_pokemon_orthodos_iconTiles,
    gfx_pkmn_species_282_pokemon_zerbertres_iconTiles,
    gfx_pkmn_species_283_pokemon_seekid_iconTiles,
    gfx_pkmn_species_284_pokemon_seeskull_iconTiles,
    gfx_pkmn_species_285_pokemon_skullydra_iconTiles,
    gfx_pkmn_species_286_pokemon_fiffyen_iconTiles,
    gfx_pkmn_species_287_pokemon_magnayen_iconTiles,
    gfx_pkmn_species_288_pokemon_zigzachs_iconTiles,
    gfx_pkmn_species_289_pokemon_geradaks_iconTiles,
    gfx_pkmn_species_290_pokemon_waumpel_iconTiles,
    gfx_pkmn_species_291_pokemon_schaloko_iconTiles,
    gfx_pkmn_species_292_pokemon_papinella_iconTiles,
    gfx_pkmn_species_293_pokemon_panekon_iconTiles,
    gfx_pkmn_species_294_pokemon_pudox_iconTiles,
    gfx_pkmn_species_295_pokemon_loturzel_iconTiles,
    gfx_pkmn_species_296_pokemon_lombrero_iconTiles,
    gfx_pkmn_species_297_pokemon_kappalores_iconTiles,
    gfx_pkmn_species_298_pokemon_samurzel_iconTiles,
    gfx_pkmn_species_299_pokemon_blanas_iconTiles,
    gfx_pkmn_species_300_pokemon_tengulist_iconTiles,
    gfx_pkmn_species_301_pokemon_nincada_iconTiles,
    gfx_pkmn_species_302_pokemon_ninjask_iconTiles,
    gfx_pkmn_species_303_pokemon_ninjatom_iconTiles,
    gfx_pkmn_species_304_pokemon_schwalbini_iconTiles,
    gfx_pkmn_species_305_pokemon_schwalboss_iconTiles,
    gfx_pkmn_species_306_pokemon_knilz_iconTiles,
    gfx_pkmn_species_307_pokemon_kapilz_iconTiles,
    gfx_pkmn_species_308_pokemon_pandir_iconTiles,
    gfx_pkmn_species_309_pokemon_wingull_iconTiles,
    gfx_pkmn_species_310_pokemon_pelipper_iconTiles,
    gfx_pkmn_species_311_pokemon_gehweiher_iconTiles,
    gfx_pkmn_species_312_pokemon_maskeregen_iconTiles,
    gfx_pkmn_species_313_pokemon_wailmer_iconTiles,
    gfx_pkmn_species_314_pokemon_wailord_iconTiles,
    gfx_pkmn_species_315_pokemon_eneco_iconTiles,
    gfx_pkmn_species_316_pokemon_enekoro_iconTiles,
    gfx_pkmn_species_317_pokemon_kecleon_iconTiles,
    gfx_pkmn_species_318_pokemon_puppance_iconTiles,
    gfx_pkmn_species_319_pokemon_lepumentas_iconTiles,
    gfx_pkmn_species_320_pokemon_nasgnet_iconTiles,
    gfx_pkmn_species_321_pokemon_magbrant_iconTiles,
    gfx_pkmn_species_322_pokemon_zwirrfinst_iconTiles,
    gfx_pkmn_species_323_pokemon_schmerbe_iconTiles,
    gfx_pkmn_species_324_pokemon_welsar_iconTiles,
    gfx_pkmn_species_325_pokemon_rihornior_iconTiles,
    gfx_pkmn_species_326_pokemon_krebscorps_iconTiles,
    gfx_pkmn_species_327_pokemon_krebutack_iconTiles,
    gfx_pkmn_species_328_pokemon_barschwa_iconTiles,
    gfx_pkmn_species_329_pokemon_milotic_iconTiles,
    gfx_pkmn_species_330_pokemon_kanivanha_iconTiles,
    gfx_pkmn_species_331_pokemon_tohaido_iconTiles,
    gfx_pkmn_species_332_pokemon_knacklion_iconTiles,
    gfx_pkmn_species_333_pokemon_vibrava_iconTiles,
    gfx_pkmn_species_334_pokemon_libelldra_iconTiles,
    gfx_pkmn_species_335_pokemon_riolu_iconTiles,
    gfx_pkmn_species_336_pokemon_lucario_iconTiles,
    gfx_pkmn_species_337_pokemon_frizelbliz_iconTiles,
    gfx_pkmn_species_338_pokemon_voltenso_iconTiles,
    gfx_pkmn_species_339_pokemon_camaub_iconTiles,
    gfx_pkmn_species_340_pokemon_camerupt_iconTiles,
    gfx_pkmn_species_341_pokemon_seemops_iconTiles,
    gfx_pkmn_species_342_pokemon_seejong_iconTiles,
    gfx_pkmn_species_343_pokemon_walraisa_iconTiles,
    gfx_pkmn_species_344_pokemon_tuska_iconTiles,
    gfx_pkmn_species_345_pokemon_noktuska_iconTiles,
    gfx_pkmn_species_346_pokemon_schneppke_iconTiles,
    gfx_pkmn_species_347_pokemon_firnontor_iconTiles,
    gfx_pkmn_species_348_pokemon_lunastein_iconTiles,
    gfx_pkmn_species_349_pokemon_sonnfel_iconTiles,
    gfx_pkmn_species_350_pokemon_azurill_iconTiles,
    gfx_pkmn_species_351_pokemon_spoink_iconTiles,
    gfx_pkmn_species_352_pokemon_groink_iconTiles,
    gfx_pkmn_pichu_iconTiles,
    gfx_pkmn_rotom_iconTiles,
    gfx_pkmn_species_355_pokemon_flunkifer_iconTiles,
    gfx_pkmn_species_356_pokemon_meditie_iconTiles,
    gfx_pkmn_species_357_pokemon_meditalis_iconTiles,
    gfx_pkmn_species_358_pokemon_wablu_iconTiles,
    gfx_pkmn_species_359_pokemon_altaria_iconTiles,
    gfx_pkmn_species_360_pokemon_klingplim_iconTiles,
    gfx_pkmn_species_361_pokemon_zwirrlicht_iconTiles,
    gfx_pkmn_species_362_pokemon_zwirrklop_iconTiles,
    gfx_pkmn_species_363_pokemon_porygon_z_iconTiles,
    gfx_pkmn_species_364_pokemon_bummelz_iconTiles,
    gfx_pkmn_species_365_pokemon_muntier_iconTiles,
    gfx_pkmn_species_366_pokemon_letarking_iconTiles,
    gfx_pkmn_molunk_iconTiles,
    gfx_pkmn_amfira_iconTiles,
    gfx_pkmn_species_369_pokemon_tropius_iconTiles,
    gfx_pkmn_species_370_pokemon_kaumalat_iconTiles,
    gfx_pkmn_species_371_pokemon_knarksel_iconTiles,
    gfx_pkmn_species_372_pokemon_knakrack_iconTiles,
    gfx_pkmn_species_373_pokemon_perlu_iconTiles,
    gfx_pkmn_species_374_pokemon_aalabyss_iconTiles,
    gfx_pkmn_species_375_pokemon_saganabyss_iconTiles,
    gfx_pkmn_species_376_pokemon_absol_iconTiles,
    gfx_pkmn_species_377_pokemon_shuppet_iconTiles,
    gfx_pkmn_species_378_pokemon_banette_iconTiles,
    gfx_pkmn_species_379_pokemon_vipitis_iconTiles,
    gfx_pkmn_species_380_pokemon_sengo_iconTiles,
    gfx_pkmn_species_381_pokemon_relicanth_iconTiles,
    gfx_pkmn_species_382_pokemon_stollunior_iconTiles,
    gfx_pkmn_species_383_pokemon_stollrak_iconTiles,
    gfx_pkmn_species_384_pokemon_stolloss_iconTiles,
    gfx_pkmn_species_385_pokemon_formeo_iconTiles,
    gfx_pkmn_species_386_pokemon_wonneira_iconTiles,
    gfx_pkmn_species_387_pokemon_mobai_iconTiles,
    gfx_pkmn_species_388_pokemon_liliep_iconTiles,
    gfx_pkmn_species_389_pokemon_wielie_iconTiles,
    gfx_pkmn_species_390_pokemon_anorith_iconTiles,
    gfx_pkmn_species_391_pokemon_armaldo_iconTiles,
    gfx_pkmn_species_392_pokemon_trasla_iconTiles,
    gfx_pkmn_species_393_pokemon_kirlia_iconTiles,
    gfx_pkmn_species_394_pokemon_guardevoir_iconTiles,
    gfx_pkmn_species_395_pokemon_kindwurm_iconTiles,
    gfx_pkmn_species_396_pokemon_draschel_iconTiles,
    gfx_pkmn_species_397_pokemon_brutalanda_iconTiles,
    gfx_pkmn_species_398_pokemon_tanhel_iconTiles,
    gfx_pkmn_species_399_pokemon_metang_iconTiles,
    gfx_pkmn_species_400_pokemon_metagross_iconTiles,
    gfx_pkmn_species_401_pokemon_regirock_iconTiles,
    gfx_pkmn_species_402_pokemon_regice_iconTiles,
    gfx_pkmn_species_403_pokemon_registeel_iconTiles,
    gfx_pkmn_species_404_pokemon_kyogre_iconTiles,
    gfx_pkmn_species_405_pokemon_groudon_iconTiles,
    gfx_pkmn_species_406_pokemon_rayquaza_iconTiles,
    gfx_pkmn_species_407_pokemon_latias_iconTiles,
    gfx_pkmn_species_408_pokemon_latios_iconTiles,
    gfx_pkmn_species_409_pokemon_jirachi_iconTiles,
    gfx_pkmn_species_410_pokemon_deoxys_iconTiles,
    gfx_pkmn_species_411_pokemon_palimpalim_iconTiles,
    gfx_pkmn_species_412_pokemon_egg_iconTiles,
    gfx_pkmn_species_413_pokemon_icognito_b_iconTiles,
    gfx_pkmn_species_414_pokemon_icognito_c_iconTiles,
    gfx_pkmn_species_415_pokemon_icognito_d_iconTiles,
    gfx_pkmn_species_416_pokemon_icognito_e_iconTiles,
    gfx_pkmn_species_417_pokemon_icognito_f_iconTiles,
    gfx_pkmn_species_418_pokemon_icognito_g_iconTiles,
    gfx_pkmn_species_419_pokemon_icognito_h_iconTiles,
    gfx_pkmn_species_420_pokemon_icognito_i_iconTiles,
    gfx_pkmn_species_421_pokemon_icognito_j_iconTiles,
    gfx_pkmn_species_422_pokemon_icognito_k_iconTiles,
    gfx_pkmn_species_423_pokemon_icognito_l_iconTiles,
    gfx_pkmn_species_424_pokemon_icognito_m_iconTiles,
    gfx_pkmn_species_425_pokemon_icognito_n_iconTiles,
    gfx_pkmn_species_426_pokemon_icognito_o_iconTiles,
    gfx_pkmn_species_427_pokemon_icognito_p_iconTiles,
    gfx_pkmn_species_428_pokemon_icognito_q_iconTiles,
    gfx_pkmn_species_429_pokemon_icognito_r_iconTiles,
    gfx_pkmn_species_430_pokemon_icognito_s_iconTiles,
    gfx_pkmn_species_431_pokemon_icognito_t_iconTiles,
    gfx_pkmn_species_432_pokemon_icognito_u_iconTiles,
    gfx_pkmn_species_433_pokemon_icognito_v_iconTiles,
    gfx_pkmn_species_434_pokemon_icognito_w_iconTiles,
    gfx_pkmn_species_435_pokemon_icognito_x_iconTiles,
    gfx_pkmn_species_436_pokemon_icognito_y_iconTiles,
    gfx_pkmn_species_437_pokemon_icognito_z_iconTiles,
    gfx_pkmn_species_438_pokemon_icognito_exclamation_iconTiles,
    gfx_pkmn_species_439_pokemon_icognito_question_iconTiles,
    gfx_pkmn_species_440_pokemon_groudon_e_iconTiles,
    gfx_pkmn_species_441_pokemon_kecleon_p_iconTiles
    
};

u8 pokemon_icon_usage[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    0x0,
    // POKEMON_BISASAM
    0x1,
    // POKEMON_BISAKNOSP
    0x1,
    // POKEMON_BISAFLOR
    0x1,
    // POKEMON_GLUMANDA
    0x0,
    // POKEMON_GLUTEXO
    0x0,
    // POKEMON_GLURAK
    0x0,
    // POKEMON_SCHIGGY
    0x0,
    // POKEMON_SCHILLOK
    0x2,
    // POKEMON_TURTOK
    0x2,
    // POKEMON_DARTIRI
    0x2,
    // POKEMON_DARTIGNIS
    0x2,
    // POKEMON_FIARO
    0x2,
    // POKEMON_HORNLIU
    0x1,
    // POKEMON_KOKUNA
    0x2,
    // POKEMON_BIBOR
    0x2,
    // POKEMON_STARALILI
    0x0,
    // POKEMON_STARAVIA
    0x0,
    // POKEMON_STARAPTOR
    0x0,
    // POKEMON_BRONZEL
    0x0,
    // POKEMON_BRONZONG
    0x0,
    // POKEMON_MAEHIKEL
    0x1,
    // POKEMON_CHEVRUMM
    0x1,
    // POKEMON_PARAGONI
    0x1,
    // POKEMON_TROMBORK
    0x1,
    // POKEMON_PIKACHU
    0x2,
    // POKEMON_RAICHU
    0x0,
    // POKEMON_SANDAN
    0x2,
    // POKEMON_SANDAMER
    0x2,
    // POKEMON_NIDORANW
    0x2,
    // POKEMON_NIDORINA
    0x2,
    // POKEMON_NIDOQUEEN
    0x2,
    // POKEMON_NIDORANM
    0x2,
    // POKEMON_NIDORINO
    0x2,
    // POKEMON_NIDOKING
    0x2,
    // POKEMON_FLOETTE
    0x1,
    // POKEMON_FLORGES
    0x0,
    // POKEMON_VULPIX
    0x2,
    // POKEMON_VULNONA
    0x1,
    // POKEMON_PUMMELUFF
    0x0,
    // POKEMON_KNUDDELUFF
    0x0,
    // POKEMON_ZUBAT
    0x2,
    // POKEMON_GOLBAT
    0x2,
    // POKEMON_MYRAPLA
    0x1,
    // POKEMON_DUFLOR
    0x0,
    // POKEMON_GIFLOR
    0x0,
    // POKEMON_FOLIPURBA
    0x1,
    // POKEMON_FEELINARA
    0x0,
    // POKEMON_WATTZAPF
    0x1,
    // POKEMON_VOLTULA
    0x1,
    // POKEMON_DIGDA
    0x2,
    // POKEMON_DIGDRI
    0x2,
    // POKEMON_KASTADUR
    0x2,
    // POKEMON_TENTANTEL
    0x2,
    // POKEMON_ENTON
    0x1,
    // POKEMON_ENTORON
    0x2,
    // POKEMON_MENKI
    0x1,
    // POKEMON_RASAFF
    0x2,
    // POKEMON_FUKANO
    0x0,
    // POKEMON_ARKANI
    0x0,
    // POKEMON_GRAMOKLES
    0x2,
    // POKEMON_DUOKLES
    0x1,
    // POKEMON_DURENGARD
    0x2,
    // POKEMON_ABRA
    0x2,
    // POKEMON_KADABRA
    0x2,
    // POKEMON_SIMSALA
    0x2,
    // POKEMON_MACHOLLO
    0x0,
    // POKEMON_MASCHOCK
    0x2,
    // POKEMON_MACHOMEI
    0x0,
    // POKEMON_KNOFENSA
    0x1,
    // POKEMON_ULTRIGARIA
    0x1,
    // POKEMON_SARZENIA
    0x1,
    // POKEMON_TENTACHA
    0x2,
    // POKEMON_TENTOXA
    0x2,
    // POKEMON_KLEINSTEIN
    0x1,
    // POKEMON_GEOROK
    0x1,
    // POKEMON_GEOWAZ
    0x1,
    // POKEMON_PONITA
    0x0,
    // POKEMON_GALLOPA
    0x0,
    // POKEMON_FLEGMON
    0x0,
    // POKEMON_LAHMUS
    0x0,
    // POKEMON_MAGNETILO
    0x0,
    // POKEMON_MAGNETON
    0x0,
    // POKEMON_PORENTA
    0x1,
    // POKEMON_DODU
    0x2,
    // POKEMON_DODRI
    0x2,
    // POKEMON_JURBO
    0x2,
    // POKEMON_JUGONG
    0x2,
    // POKEMON_SLEIMA
    0x2,
    // POKEMON_SLEIMOK
    0x2,
    // POKEMON_MUSCHAS
    0x2,
    // POKEMON_AUSTOS
    0x2,
    // POKEMON_NEBULAK
    0x2,
    // POKEMON_ALPOLLO
    0x2,
    // POKEMON_GENGAR
    0x2,
    // POKEMON_ONIX
    0x2,
    // POKEMON_TRAUMATO
    0x2,
    // POKEMON_HYPNO
    0x1,
    // POKEMON_KRABBY
    0x2,
    // POKEMON_KINGLER
    0x2,
    // POKEMON_VOLTOBAL
    0x0,
    // POKEMON_LEKTROBAL
    0x0,
    // POKEMON_OWEI
    0x0,
    // POKEMON_KOKOWEI
    0x1,
    // POKEMON_TRAGOSSO
    0x1,
    // POKEMON_KNOGGA
    0x1,
    // POKEMON_KICKLEE
    0x2,
    // POKEMON_NOCKCHAN
    0x2,
    // POKEMON_SCHLURP
    0x1,
    // POKEMON_SMOGON
    0x2,
    // POKEMON_SMOGMOG
    0x2,
    // POKEMON_RIHORN
    0x1,
    // POKEMON_RIZEROS
    0x1,
    // POKEMON_CHANEIRA
    0x0,
    // POKEMON_ZOBIRIS
    0x2,
    // POKEMON_KANGAMA
    0x1,
    // POKEMON_SEEPER
    0x0,
    // POKEMON_SEEMON
    0x0,
    // POKEMON_QUABBEL
    0x0,
    // POKEMON_APOQUALLYP
    0x0,
    // POKEMON_STERNDU
    0x2,
    // POKEMON_STARMIE
    0x2,
    // POKEMON_TRAUNFUGIL
    0x0,
    // POKEMON_SICHLOR
    0x1,
    // POKEMON_GALAGLADI
    0x1,
    // POKEMON_ELEKTEK
    0x1,
    // POKEMON_MAGMAR
    0x0,
    // POKEMON_PINSIR
    0x2,
    // POKEMON_TAUROS
    0x2,
    // POKEMON_KARPADOR
    0x0,
    // POKEMON_GARADOS
    0x0,
    // POKEMON_LAPRAS
    0x2,
    // POKEMON_DITTO
    0x2,
    // POKEMON_EVOLI
    0x2,
    // POKEMON_AQUANA
    0x0,
    // POKEMON_BLITZA
    0x0,
    // POKEMON_FLAMARA
    0x0,
    // POKEMON_PORYGON
    0x0,
    // POKEMON_AMONITAS
    0x0,
    // POKEMON_AMOROSO
    0x0,
    // POKEMON_KABUTO
    0x2,
    // POKEMON_KABUTOPS
    0x2,
    // POKEMON_AERODACTYL
    0x0,
    // POKEMON_RELAXO
    0x1,
    // POKEMON_ARKTOS
    0x0,
    // POKEMON_ZAPDOS
    0x0,
    // POKEMON_LAVADOS
    0x0,
    // POKEMON_DRATINI
    0x0,
    // POKEMON_DRAGONIR
    0x0,
    // POKEMON_DRAGORAN
    0x2,
    // POKEMON_MEWTU
    0x2,
    // POKEMON_MEW
    0x0,
    // POKEMON_ENDIVIE
    0x1,
    // POKEMON_LORBLATT
    0x1,
    // POKEMON_MEGANIE
    0x1,
    // POKEMON_FEURIGEL
    0x1,
    // POKEMON_IGELAVAR
    0x1,
    // POKEMON_TORNUPTO
    0x1,
    // POKEMON_KARNIMANI
    0x2,
    // POKEMON_TYRACROC
    0x2,
    // POKEMON_IMPERGATOR
    0x2,
    // POKEMON_IGNIVOR
    0x1,
    // POKEMON_RAMOTH
    0x1,
    // POKEMON_GLAZIOLA
    0x0,
    // POKEMON_RESLADERO
    0x0,
    // POKEMON_LEDYBA
    0x0,
    // POKEMON_LEDIAN
    0x0,
    // POKEMON_WEBARAK
    0x1,
    // POKEMON_ARIADOS
    0x0,
    // POKEMON_IKSBAT
    0x2,
    // POKEMON_LAMPI
    0x2,
    // POKEMON_LANTURN
    0x0,
    // POKEMON_MAGNEZONE
    0x0,
    // POKEMON_TOGEKISS
    0x1,
    // POKEMON_FLABEBE
    0x1,
    // POKEMON_TOGEPI
    0x2,
    // POKEMON_TOGETIC
    0x2,
    // POKEMON_NATU
    0x0,
    // POKEMON_XATU
    0x0,
    // POKEMON_VOLTILAMM
    0x2,
    // POKEMON_WAATY
    0x0,
    // POKEMON_AMPHAROS
    0x0,
    // POKEMON_BLUBELLA
    0x1,
    // POKEMON_MARILL
    0x2,
    // POKEMON_AZUMARILL
    0x2,
    // POKEMON_MOGELBAUM
    0x1,
    // POKEMON_CLAVION
    0x2,
    // POKEMON_LICHTEL
    0x2,
    // POKEMON_LATERNECTO
    0x2,
    // POKEMON_SKLELABRA
    0x2,
    // POKEMON_GRIFFEL
    0x2,
    // POKEMON_SHNEBEDECK
    0x1,
    // POKEMON_REXBLISAR
    0x1,
    // POKEMON_AMBIDIFFEL
    0x2,
    // POKEMON_FELINO
    0x0,
    // POKEMON_MORLORD
    0x0,
    // POKEMON_PSIANA
    0x2,
    // POKEMON_NACHTARA
    0x2,
    // POKEMON_KRAMURX
    0x2,
    // POKEMON_LASCHOKING
    0x0,
    // POKEMON_KRAMSHEF
    0x2,
    // POKEMON_ICOGNITO
    0x0,
    // POKEMON_FROSDEDJE
    0x0,
    // POKEMON_SKORGRO
    0x2,
    // POKEMON_TANNZA
    0x0,
    // POKEMON_FORSTELLKA
    0x2,
    // POKEMON_ELEVOLTEK
    0x1,
    // POKEMON_SKORGLA
    0x2,
    // POKEMON_STAHLOS
    0x0,
    // POKEMON_SNUBBULL
    0x0,
    // POKEMON_GRANBULL
    0x2,
    // POKEMON_MAMUTEL
    0x2,
    // POKEMON_SCHEROX
    0x0,
    // POKEMON_FLUFFELUFF
    0x0,
    // POKEMON_SKARABORN
    0x2,
    // POKEMON_KRYPPUK
    0x0,
    // POKEMON_TEDDIURSA
    0x0,
    // POKEMON_URSARING
    0x2,
    // POKEMON_SCHNECKMAG
    0x0,
    // POKEMON_MAGCARGO
    0x0,
    // POKEMON_QUIEKEL
    0x2,
    // POKEMON_KEIFEL
    0x2,
    // POKEMON_CORASONN
    0x2,
    // POKEMON_REMORAID
    0x0,
    // POKEMON_OCTILLERY
    0x0,
    // POKEMON_BOTOGEL
    0x0,
    // POKEMON_SCHLURPLEK
    0x1,
    // POKEMON_PANZAERON
    0x0,
    // POKEMON_HUNDUSTER
    0x0,
    // POKEMON_HUNDEMON
    0x0,
    // POKEMON_SEEDRAKING
    0x0,
    // POKEMON_PHANPY
    0x0,
    // POKEMON_DONPHAN
    0x0,
    // POKEMON_PORYGON2
    0x0,
    // POKEMON_VOLUMINAS
    0x0,
    // POKEMON_TRAUNMAGIL
    0x2,
    // POKEMON_RABAUZ
    0x2,
    // POKEMON_KAPOERA
    0x2,
    // POKEMON_SEN_LONG
    0x0,
    // POKEMON_ELEKID
    0x1,
    // POKEMON_MAGBY
    0x1,
    // POKEMON_MILTANK
    0x1,
    // POKEMON_HEITEIRA
    0x1,
    // POKEMON_RAIKOU
    0x0,
    // POKEMON_ENTEI
    0x2,
    // POKEMON_SUICUNE
    0x0,
    // POKEMON_LARVITAR
    0x1,
    // POKEMON_PUPITAR
    0x0,
    // POKEMON_DESPOTAR
    0x1,
    // POKEMON_LUGIA
    0x0,
    // POKEMON_HO_OH
    0x1,
    // POKEMON_CELEBI
    0x1,
    // POKEMON_ROTOM_HEAT
    0x0,
    // POKEMON_ROTOM_WASH
    0x0,
    // POKEMON_ROTOM_FORST
    0x0,
    // POKEMON_ROTOM_WIND
    0x0,
    // POKEMON_ROTOM_GRASS
    0x0,
    // POKEMON_DURENGARD_OFFENSIVE
    0x2,
    // POKEMONmega_sandamer_
    0x2,
    // POKEMON_MEGA_LAHMUS
    0x0,
    // POKEMON_TURTOKM
    0x2,
    // POKEMON_AMPHARAOSM
    0x1,
    // POKEMON_BANETTE_MEGA
    0x0,
    // POKEMON_BIBORM
    0x0,
    // POKEMON_ALTARIAM
    0x0,
    // POKEMON_GEOWAZM
    0x1,
    // POKEMON_SENGOM
    0x0,
    // POKEMON_VIPITISM
    0x2,
    // POKEMON_ZOBIRISM
    0x2,
    // POKEMON_tropius_mega
    0x1,
    // pokemon_octillery_mega
    0x0,
    // pokemon_rasaff_mega
    0x2,
    // POKEMON_110
    0x0,
    // POKEMON_111
    0x0,
    // POKEMON_112
    0x0,
    // POKEMON_113
    0x0,
    // POKEMON_114
    0x0,
    // POKEMON_LOCKSCHAL
    0x1,
    // POKEMON_STICHSCHAL
    0x1,
    // POKEMON_STAHLSTICH
    0x1,
    // POKEMON_WELUNO
    0x0,
    // POKEMON_ORTHODOS
    0x0,
    // POKEMON_ZERBERTRES
    0x0,
    // POKEMON_SEEKID
    0x2,
    // POKEMON_SEESKULL
    0x2,
    // POKEMON_SKULLYDRA
    0x2,
    // POKEMON_FIFFYEN
    0x2,
    // POKEMON_MAGNAYEN
    0x2,
    // POKEMON_ZIGZACHS
    0x2,
    // POKEMON_GERADAKS
    0x2,
    // POKEMON_WAUMPEL
    0x0,
    // POKEMON_SCHALOKO
    0x2,
    // POKEMON_PAPINELLA
    0x0,
    // POKEMON_PANEKON
    0x2,
    // POKEMON_PUDOX
    0x1,
    // POKEMON_LOTURZEL
    0x1,
    // POKEMON_LOMBRERO
    0x1,
    // POKEMON_KAPPALORES
    0x1,
    // POKEMON_SAMURZEL
    0x1,
    // POKEMON_BLANAS
    0x1,
    // POKEMON_TENGULIST
    0x0,
    // POKEMON_NINCADA
    0x1,
    // POKEMON_NINJASK
    0x1,
    // POKEMON_NINJATOM
    0x1,
    // POKEMON_SCHWALBINI
    0x2,
    // POKEMON_SCHWALBOSS
    0x2,
    // POKEMON_KNILZ
    0x1,
    // POKEMON_KAPILZ
    0x1,
    // POKEMON_PANDIR
    0x1,
    // POKEMON_WINGULL
    0x0,
    // POKEMON_PELIPPER
    0x0,
    // POKEMON_GEHWEIHER
    0x2,
    // POKEMON_MASKEREGEN
    0x0,
    // POKEMON_WAILMER
    0x2,
    // POKEMON_WAILORD
    0x0,
    // POKEMON_ENECO
    0x0,
    // POKEMON_ENEKORO
    0x2,
    // POKEMON_KECLEON
    0x1,
    // POKEMON_PUPPANCE
    0x1,
    // POKEMON_LEPUMENTAS
    0x0,
    // POKEMON_NASGNET
    0x0,
    // POKEMON_MAGBRANT
    0x0,
    // POKEMON_ZWIRRFINST
    0x2,
    // POKEMON_SCHMERBE
    0x0,
    // POKEMON_WELSAR
    0x0,
    // POKEMON_LIEBISKUS
    0x0,
    // POKEMON_KREBSCORPS
    0x0,
    // POKEMON_KREBUTACK
    0x0,
    // POKEMON_BARSCHWA
    0x2,
    // POKEMON_MILOTIC
    0x0,
    // POKEMON_KANIVANHA
    0x0,
    // POKEMON_TOHAIDO
    0x0,
    // POKEMON_KNACKLION
    0x1,
    // POKEMON_VIBRAVA
    0x1,
    // POKEMON_LIBELLDRA
    0x1,
    // POKEMON_RIOLU
    0x2,
    // POKEMON_LUCARIO
    0x2,
    // POKEMON_FRIZELBLIZ
    0x1,
    // POKEMON_VOLTENSO
    0x0,
    // POKEMON_CAMAUB
    0x1,
    // POKEMON_CAMERUPT
    0x0,
    // POKEMON_SEEMOPS
    0x2,
    // POKEMON_SEEJONG
    0x2,
    // POKEMON_WALRAISA
    0x0,
    // POKEMON_TUSKA
    0x1,
    // POKEMON_NOKTUSKA
    0x1,
    // POKEMON_SCHNEPPKE
    0x2,
    // POKEMON_FIRNONTOR
    0x0,
    // POKEMON_LUNASTEIN
    0x1,
    // POKEMON_SONNFEL
    0x0,
    // POKEMON_AZURILL
    0x2,
    // POKEMON_SPOINK
    0x0,
    // POKEMON_GROINK
    0x2,
    // POKEMON_PICHU
    0x1,
    // POKEMON_ROTOM
    0x0,
    // POKEMON_FLUNKIFER
    0x2,
    // POKEMON_MEDITIE
    0x0,
    // POKEMON_MEDITALIS
    0x0,
    // POKEMON_WABLU
    0x0,
    // POKEMON_ALTARIA
    0x0,
    // POKEMON_ISSO
    0x2,
    // POKEMON_ZWIRRLICHT
    0x0,
    // POKEMON_ZWIRRKLOP
    0x0,
    // POKEMON_ROSELIA
    0x0,
    // POKEMON_BUMMELZ
    0x2,
    // POKEMON_MUNTIER
    0x2,
    // POKEMON_LETARKING
    0x1,
    // POKEMON_MOLUNK
    0x0,
    // POKEMON_AMFIRA
    0x0,
    // POKEMON_TROPIUS
    0x1,
    // POKEMON_KAUMALAT
    0x0,
    // POKEMON_KNARKSEL
    0x0,
    // POKEMON_KNAKRACK
    0x0,
    // POKEMON_PERLU
    0x0,
    // POKEMON_AALABYSS
    0x0,
    // POKEMON_SAGANABYSS
    0x0,
    // POKEMON_ABSOL
    0x0,
    // POKEMON_SHUPPET
    0x0,
    // POKEMON_BANETTE
    0x0,
    // POKEMON_VIPITIS
    0x2,
    // POKEMON_SENGO
    0x0,
    // POKEMON_RELICANTH
    0x1,
    // POKEMON_STOLLUNIOR
    0x2,
    // POKEMON_STOLLRAK
    0x2,
    // POKEMON_STOLLOSS
    0x2,
    // POKEMON_FORMEO
    0x0,
    // POKEMON_VOLBEAT
    0x0,
    // POKEMON_ILLUMISE
    0x1,
    // POKEMON_LILIEP
    0x2,
    // POKEMON_WIELIE
    0x0,
    // POKEMON_ANORITH
    0x0,
    // POKEMON_ARMALDO
    0x0,
    // POKEMON_TRASLA
    0x1,
    // POKEMON_KIRLIA
    0x1,
    // POKEMON_GUARDEVOIR
    0x1,
    // POKEMON_KINDWURM
    0x2,
    // POKEMON_DRASCHEL
    0x2,
    // POKEMON_BRUTALANDA
    0x0,
    // POKEMON_TANHEL
    0x0,
    // POKEMON_METANG
    0x0,
    // POKEMON_METAGROSS
    0x0,
    // POKEMON_REGIROCK
    0x2,
    // POKEMON_REGICE
    0x2,
    // POKEMON_REGISTEEL
    0x2,
    // POKEMON_KYOGRE
    0x2,
    // POKEMON_GROUDON
    0x0,
    // POKEMON_RAYQUAZA
    0x1,
    // POKEMON_LATIAS
    0x0,
    // POKEMON_LATIOS
    0x2,
    // POKEMON_JIRACHI
    0x0,
    // POKEMON_DEOXYS
    0x0,
    // POKEMON_PALIMPALIM
    0x0,
    // POKEMON_EGG
    0x1,
    // POKEMON_ICOGNITO_B
    0x0,
    // POKEMON_ICOGNITO_C
    0x0,
    // POKEMON_ICOGNITO_D
    0x0,
    // POKEMON_ICOGNITO_E
    0x0,
    // POKEMON_ICOGNITO_F
    0x0,
    // POKEMON_ICOGNITO_G
    0x0,
    // POKEMON_ICOGNITO_H
    0x0,
    // POKEMON_ICOGNITO_I
    0x0,
    // POKEMON_ICOGNITO_J
    0x0,
    // POKEMON_ICOGNITO_K
    0x0,
    // POKEMON_ICOGNITO_L
    0x0,
    // POKEMON_ICOGNITO_M
    0x0,
    // POKEMON_ICOGNITO_N
    0x0,
    // POKEMON_ICOGNITO_O
    0x0,
    // POKEMON_ICOGNITO_P
    0x0,
    // POKEMON_ICOGNITO_Q
    0x0,
    // POKEMON_ICOGNITO_R
    0x0,
    // POKEMON_ICOGNITO_S
    0x0,
    // POKEMON_ICOGNITO_T
    0x0,
    // POKEMON_ICOGNITO_U
    0x0,
    // POKEMON_ICOGNITO_V
    0x0,
    // POKEMON_ICOGNITO_W
    0x0,
    // POKEMON_ICOGNITO_X
    0x0,
    // POKEMON_ICOGNITO_Y
    0x0,
    // POKEMON_ICOGNITO_Z
    0x0,
    // POKEMON_ICOGNITO_EXCLAMATION
    0x0,
    // POKEMON_ICOGNITO_QUESTION
    0x0,
    // POKEMON_GROUDON_REGENT
    0x0,
	// POKEMON_KECLEON_PURPLE
	0x2
};
