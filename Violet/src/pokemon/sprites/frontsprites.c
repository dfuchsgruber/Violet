#include "types.h"
#include "oam.h"
#include "pokemon/count.h"
#include "pokemon/sprites.h"
#include "pokemon/virtual.h"
#include "constants/species.h"

graphic pokemon_frontsprites[POKEMON_CNT] = {
    {gfx_pkmn_species_000_pokemon_pokemon_0_frontspriteTiles, 0x800, 0},
    {gfx_pkmn_species_001_pokemon_bisasam_frontspriteTiles, 0x800, 1},
    {gfx_pkmn_species_002_pokemon_bisaknosp_frontspriteTiles, 0x800, 2},
    {gfx_pkmn_species_003_pokemon_bisaflor_frontspriteTiles, 0x800, 3},
    {gfx_pkmn_species_004_pokemon_glumanda_frontspriteTiles, 0x800, 4},
    {gfx_pkmn_species_005_pokemon_glutexo_frontspriteTiles, 0x800, 5},
    {gfx_pkmn_species_006_pokemon_glurak_frontspriteTiles, 0x800, 6},
    {gfx_pkmn_species_007_pokemon_schiggy_frontspriteTiles, 0x800, 7},
    {gfx_pkmn_species_008_pokemon_schillok_frontspriteTiles, 0x800, 8},
    {gfx_pkmn_species_009_pokemon_turtok_frontspriteTiles, 0x800, 9},
    {gfx_pkmn_species_010_pokemon_dartiri_frontspriteTiles, 0x800, 10},
    {gfx_pkmn_species_011_pokemon_dartignis_frontspriteTiles, 0x800, 11},
    {gfx_pkmn_species_012_pokemon_fiaro_frontspriteTiles, 0x800, 12},
    {gfx_pkmn_species_013_pokemon_hornliu_frontspriteTiles, 0x800, 13},
    {gfx_pkmn_species_014_pokemon_kokuna_frontspriteTiles, 0x800, 14},
    {gfx_pkmn_species_015_pokemon_bibor_frontspriteTiles, 0x800, 15},
    {gfx_pkmn_species_016_pokemon_staralili_frontspriteTiles, 0x800, 16},
    {gfx_pkmn_species_017_pokemon_staravia_frontspriteTiles, 0x800, 17},
    {gfx_pkmn_species_018_pokemon_staraptor_frontspriteTiles, 0x800, 18},
    {gfx_pkmn_species_019_pokemon_bronzel_frontspriteTiles, 0x800, 19},
    {gfx_pkmn_species_020_pokemon_bronzong_frontspriteTiles, 0x800, 20},
    {gfx_pkmn_species_021_pokemon_maehikel_frontspriteTiles, 0x800, 21},
    {gfx_pkmn_species_022_pokemon_chevrumm_frontspriteTiles, 0x800, 22},
    {gfx_pkmn_species_023_pokemon_paragoni_frontspriteTiles, 0x800, 23},
    {gfx_pkmn_species_024_pokemon_trombork_frontspriteTiles, 0x800, 24},
    {gfx_pkmn_species_025_pokemon_pikachu_frontspriteTiles, 0x800, 25},
    {gfx_pkmn_species_026_pokemon_raichu_frontspriteTiles, 0x800, 26},
    {gfx_pkmn_species_027_pokemon_sandan_frontspriteTiles, 0x800, 27},
    {gfx_pkmn_species_028_pokemon_sandamer_frontspriteTiles, 0x800, 28},
    {gfx_pkmn_species_029_pokemon_nidoranw_frontspriteTiles, 0x800, 29},
    {gfx_pkmn_species_030_pokemon_nidorina_frontspriteTiles, 0x800, 30},
    {gfx_pkmn_species_031_pokemon_nidoqueen_frontspriteTiles, 0x800, 31},
    {gfx_pkmn_species_032_pokemon_nidoranm_frontspriteTiles, 0x800, 32},
    {gfx_pkmn_species_033_pokemon_nidorino_frontspriteTiles, 0x800, 33},
    {gfx_pkmn_species_034_pokemon_nidoking_frontspriteTiles, 0x800, 34},
    {gfx_pkmn_species_035_pokemon_floette_frontspriteTiles, 0x800, 35},
    {gfx_pkmn_species_036_pokemon_florges_frontspriteTiles, 0x800, 36},
    {gfx_pkmn_species_037_pokemon_vulpix_frontspriteTiles, 0x800, 37},
    {gfx_pkmn_species_038_pokemon_vulnona_frontspriteTiles, 0x800, 38},
    {gfx_pkmn_species_039_pokemon_pummeluff_frontspriteTiles, 0x800, 39},
    {gfx_pkmn_species_040_pokemon_knuddeluff_frontspriteTiles, 0x800, 40},
    {gfx_pkmn_species_041_pokemon_zubat_frontspriteTiles, 0x800, 41},
    {gfx_pkmn_species_042_pokemon_golbat_frontspriteTiles, 0x800, 42},
    {gfx_pkmn_species_043_pokemon_myrapla_frontspriteTiles, 0x800, 43},
    {gfx_pkmn_species_044_pokemon_duflor_frontspriteTiles, 0x800, 44},
    {gfx_pkmn_species_045_pokemon_giflor_frontspriteTiles, 0x800, 45},
    {gfx_pkmn_species_046_pokemon_folipurba_frontspriteTiles, 0x800, 46},
    {gfx_pkmn_species_047_pokemon_feelinara_frontspriteTiles, 0x800, 47},
    {gfx_pkmn_species_048_pokemon_wattzapf_frontspriteTiles, 0x800, 48},
    {gfx_pkmn_species_049_pokemon_voltula_frontspriteTiles, 0x800, 49},
    {gfx_pkmn_species_050_pokemon_digda_frontspriteTiles, 0x800, 50},
    {gfx_pkmn_species_051_pokemon_digdri_frontspriteTiles, 0x800, 51},
    {gfx_pkmn_species_052_pokemon_kastadur_frontspriteTiles, 0x800, 52},
    {gfx_pkmn_species_053_pokemon_tentantel_frontspriteTiles, 0x800, 53},
    {gfx_pkmn_species_054_pokemon_enton_frontspriteTiles, 0x800, 54},
    {gfx_pkmn_species_055_pokemon_entoron_frontspriteTiles, 0x800, 55},
    {gfx_pkmn_species_056_pokemon_menki_frontspriteTiles, 0x800, 56},
    {gfx_pkmn_species_057_pokemon_rasaff_frontspriteTiles, 0x800, 57},
    {gfx_pkmn_species_058_pokemon_fukano_frontspriteTiles, 0x800, 58},
    {gfx_pkmn_species_059_pokemon_arkani_frontspriteTiles, 0x800, 59},
    {gfx_pkmn_species_060_pokemon_gramokles_frontspriteTiles, 0x800, 60},
    {gfx_pkmn_species_061_pokemon_duokles_frontspriteTiles, 0x800, 61},
    {gfx_pkmn_species_062_pokemon_durengard_frontspriteTiles, 0x800, 62},
    {gfx_pkmn_species_063_pokemon_abra_frontspriteTiles, 0x800, 63},
    {gfx_pkmn_species_064_pokemon_kadabra_frontspriteTiles, 0x800, 64},
    {gfx_pkmn_species_065_pokemon_simsala_frontspriteTiles, 0x800, 65},
    {gfx_pkmn_species_066_pokemon_machollo_frontspriteTiles, 0x800, 66},
    {gfx_pkmn_species_067_pokemon_maschock_frontspriteTiles, 0x800, 67},
    {gfx_pkmn_species_068_pokemon_machomei_frontspriteTiles, 0x800, 68},
    {gfx_pkmn_species_069_pokemon_knofensa_frontspriteTiles, 0x800, 69},
    {gfx_pkmn_species_070_pokemon_ultrigaria_frontspriteTiles, 0x800, 70},
    {gfx_pkmn_species_071_pokemon_sarzenia_frontspriteTiles, 0x800, 71},
    {gfx_pkmn_species_072_pokemon_tentacha_frontspriteTiles, 0x800, 72},
    {gfx_pkmn_species_073_pokemon_tentoxa_frontspriteTiles, 0x800, 73},
    {gfx_pkmn_species_074_pokemon_kleinstein_frontspriteTiles, 0x800, 74},
    {gfx_pkmn_species_075_pokemon_georok_frontspriteTiles, 0x800, 75},
    {gfx_pkmn_species_076_pokemon_geowaz_frontspriteTiles, 0x800, 76},
    {gfx_pkmn_species_077_pokemon_ponita_frontspriteTiles, 0x800, 77},
    {gfx_pkmn_species_078_pokemon_gallopa_frontspriteTiles, 0x800, 78},
    {gfx_pkmn_species_079_pokemon_flegmon_frontspriteTiles, 0x800, 79},
    {gfx_pkmn_species_080_pokemon_lahmus_frontspriteTiles, 0x800, 80},
    {gfx_pkmn_species_081_pokemon_magnetilo_frontspriteTiles, 0x800, 81},
    {gfx_pkmn_species_082_pokemon_magneton_frontspriteTiles, 0x800, 82},
    {gfx_pkmn_species_083_pokemon_porenta_frontspriteTiles, 0x800, 83},
    {gfx_pkmn_species_084_pokemon_dodu_frontspriteTiles, 0x800, 84},
    {gfx_pkmn_species_085_pokemon_dodri_frontspriteTiles, 0x800, 85},
    {gfx_pkmn_species_086_pokemon_jurbo_frontspriteTiles, 0x800, 86},
    {gfx_pkmn_species_087_pokemon_jugong_frontspriteTiles, 0x800, 87},
    {gfx_pkmn_species_088_pokemon_sleima_frontspriteTiles, 0x800, 88},
    {gfx_pkmn_species_089_pokemon_sleimok_frontspriteTiles, 0x800, 89},
    {gfx_pkmn_species_090_pokemon_muschas_frontspriteTiles, 0x800, 90},
    {gfx_pkmn_species_091_pokemon_austos_frontspriteTiles, 0x800, 91},
    {gfx_pkmn_species_092_pokemon_nebulak_frontspriteTiles, 0x800, 92},
    {gfx_pkmn_species_093_pokemon_alpollo_frontspriteTiles, 0x800, 93},
    {gfx_pkmn_species_094_pokemon_gengar_frontspriteTiles, 0x800, 94},
    {gfx_pkmn_species_095_pokemon_onix_frontspriteTiles, 0x800, 95},
    {gfx_pkmn_species_096_pokemon_traumato_frontspriteTiles, 0x800, 96},
    {gfx_pkmn_species_097_pokemon_hypno_frontspriteTiles, 0x800, 97},
    {gfx_pkmn_species_098_pokemon_krabby_frontspriteTiles, 0x800, 98},
    {gfx_pkmn_species_099_pokemon_kingler_frontspriteTiles, 0x800, 99},
    {gfx_pkmn_species_100_pokemon_voltobal_frontspriteTiles, 0x800, 100},
    {gfx_pkmn_species_101_pokemon_lektrobal_frontspriteTiles, 0x800, 101},
    {gfx_pkmn_species_102_pokemon_owei_frontspriteTiles, 0x800, 102},
    {gfx_pkmn_species_103_pokemon_kokowei_frontspriteTiles, 0x800, 103},
    {gfx_pkmn_species_104_pokemon_tragosso_frontspriteTiles, 0x800, 104},
    {gfx_pkmn_species_105_pokemon_knogga_frontspriteTiles, 0x800, 105},
    {gfx_pkmn_species_106_pokemon_kicklee_frontspriteTiles, 0x800, 106},
    {gfx_pkmn_species_107_pokemon_nockchan_frontspriteTiles, 0x800, 107},
    {gfx_pkmn_species_108_pokemon_schlurp_frontspriteTiles, 0x800, 108},
    {gfx_pkmn_species_109_pokemon_smogon_frontspriteTiles, 0x800, 109},
    {gfx_pkmn_species_110_pokemon_smogmog_frontspriteTiles, 0x800, 110},
    {gfx_pkmn_species_111_pokemon_rihorn_frontspriteTiles, 0x800, 111},
    {gfx_pkmn_species_112_pokemon_rizeros_frontspriteTiles, 0x800, 112},
    {gfx_pkmn_species_113_pokemon_chaneira_frontspriteTiles, 0x800, 113},
    {gfx_pkmn_species_114_pokemon_zobiris_frontspriteTiles, 0x800, 114},
    {gfx_pkmn_species_115_pokemon_kangama_frontspriteTiles, 0x800, 115},
    {gfx_pkmn_species_116_pokemon_seeper_frontspriteTiles, 0x800, 116},
    {gfx_pkmn_species_117_pokemon_seemon_frontspriteTiles, 0x800, 117},
    {gfx_pkmn_species_118_pokemon_quabbel_frontspriteTiles, 0x800, 118},
    {gfx_pkmn_species_119_pokemon_apoquallyp_frontspriteTiles, 0x800, 119},
    {gfx_pkmn_species_120_pokemon_sterndu_frontspriteTiles, 0x800, 120},
    {gfx_pkmn_species_121_pokemon_starmie_frontspriteTiles, 0x800, 121},
    {gfx_pkmn_species_122_pokemon_traunfugil_frontspriteTiles, 0x800, 122},
    {gfx_pkmn_species_123_pokemon_sichlor_frontspriteTiles, 0x800, 123},
    {gfx_pkmn_species_124_pokemon_galagladi_frontspriteTiles, 0x800, 124},
    {gfx_pkmn_species_125_pokemon_elektek_frontspriteTiles, 0x800, 125},
    {gfx_pkmn_species_126_pokemon_magmar_frontspriteTiles, 0x800, 126},
    {gfx_pkmn_species_127_pokemon_pinsir_frontspriteTiles, 0x800, 127},
    {gfx_pkmn_species_128_pokemon_tauros_frontspriteTiles, 0x800, 128},
    {gfx_pkmn_species_129_pokemon_karpador_frontspriteTiles, 0x800, 129},
    {gfx_pkmn_species_130_pokemon_garados_frontspriteTiles, 0x800, 130},
    {gfx_pkmn_species_131_pokemon_lapras_frontspriteTiles, 0x800, 131},
    {gfx_pkmn_species_132_pokemon_ditto_frontspriteTiles, 0x800, 132},
    {gfx_pkmn_species_133_pokemon_evoli_frontspriteTiles, 0x800, 133},
    {gfx_pkmn_species_134_pokemon_aquana_frontspriteTiles, 0x800, 134},
    {gfx_pkmn_species_135_pokemon_blitza_frontspriteTiles, 0x800, 135},
    {gfx_pkmn_species_136_pokemon_flamara_frontspriteTiles, 0x800, 136},
    {gfx_pkmn_species_137_pokemon_porygon_frontspriteTiles, 0x800, 137},
    {gfx_pkmn_species_138_pokemon_amonitas_frontspriteTiles, 0x800, 138},
    {gfx_pkmn_species_139_pokemon_amoroso_frontspriteTiles, 0x800, 139},
    {gfx_pkmn_species_140_pokemon_kabuto_frontspriteTiles, 0x800, 140},
    {gfx_pkmn_species_141_pokemon_kabutops_frontspriteTiles, 0x800, 141},
    {gfx_pkmn_species_142_pokemon_aerodactyl_frontspriteTiles, 0x800, 142},
    {gfx_pkmn_species_143_pokemon_relaxo_frontspriteTiles, 0x800, 143},
    {gfx_pkmn_species_144_pokemon_arktos_frontspriteTiles, 0x800, 144},
    {gfx_pkmn_species_145_pokemon_zapdos_frontspriteTiles, 0x800, 145},
    {gfx_pkmn_species_146_pokemon_lavados_frontspriteTiles, 0x800, 146},
    {gfx_pkmn_species_147_pokemon_dratini_frontspriteTiles, 0x800, 147},
    {gfx_pkmn_species_148_pokemon_dragonir_frontspriteTiles, 0x800, 148},
    {gfx_pkmn_species_149_pokemon_dragoran_frontspriteTiles, 0x800, 149},
    {gfx_pkmn_species_150_pokemon_mewtu_frontspriteTiles, 0x800, 150},
    {gfx_pkmn_species_151_pokemon_mew_frontspriteTiles, 0x800, 151},
    {gfx_pkmn_species_152_pokemon_endivie_frontspriteTiles, 0x800, 152},
    {gfx_pkmn_species_153_pokemon_lorblatt_frontspriteTiles, 0x800, 153},
    {gfx_pkmn_species_154_pokemon_meganie_frontspriteTiles, 0x800, 154},
    {gfx_pkmn_species_155_pokemon_feurigel_frontspriteTiles, 0x800, 155},
    {gfx_pkmn_species_156_pokemon_igelavar_frontspriteTiles, 0x800, 156},
    {gfx_pkmn_species_157_pokemon_tornupto_frontspriteTiles, 0x800, 157},
    {gfx_pkmn_species_158_pokemon_karnimani_frontspriteTiles, 0x800, 158},
    {gfx_pkmn_species_159_pokemon_tyracroc_frontspriteTiles, 0x800, 159},
    {gfx_pkmn_species_160_pokemon_impergator_frontspriteTiles, 0x800, 160},
    {gfx_pkmn_species_161_pokemon_ignivor_frontspriteTiles, 0x800, 161},
    {gfx_pkmn_species_162_pokemon_ramoth_frontspriteTiles, 0x800, 162},
    {gfx_pkmn_species_163_pokemon_glaziola_frontspriteTiles, 0x800, 163},
    {gfx_pkmn_species_164_pokemon_resladero_frontspriteTiles, 0x800, 164},
    {gfx_pkmn_species_165_pokemon_ledyba_frontspriteTiles, 0x800, 165},
    {gfx_pkmn_species_166_pokemon_ledian_frontspriteTiles, 0x800, 166},
    {gfx_pkmn_species_167_pokemon_webarak_frontspriteTiles, 0x800, 167},
    {gfx_pkmn_species_168_pokemon_ariados_frontspriteTiles, 0x800, 168},
    {gfx_pkmn_species_169_pokemon_iksbat_frontspriteTiles, 0x800, 169},
    {gfx_pkmn_species_170_pokemon_lampi_frontspriteTiles, 0x800, 170},
    {gfx_pkmn_species_171_pokemon_lanturn_frontspriteTiles, 0x800, 171},
    {gfx_pkmn_species_172_pokemon_magnezone_frontspriteTiles, 0x800, 172},
    {gfx_pkmn_species_173_pokemon_togekiss_frontspriteTiles, 0x800, 173},
    {gfx_pkmn_species_174_pokemon_flabebe_frontspriteTiles, 0x800, 174},
    {gfx_pkmn_species_175_pokemon_togepi_frontspriteTiles, 0x800, 175},
    {gfx_pkmn_species_176_pokemon_togetic_frontspriteTiles, 0x800, 176},
    {gfx_pkmn_species_177_pokemon_natu_frontspriteTiles, 0x800, 177},
    {gfx_pkmn_species_178_pokemon_xatu_frontspriteTiles, 0x800, 178},
    {gfx_pkmn_species_179_pokemon_voltilamm_frontspriteTiles, 0x800, 179},
    {gfx_pkmn_species_180_pokemon_waaty_frontspriteTiles, 0x800, 180},
    {gfx_pkmn_species_181_pokemon_ampharos_frontspriteTiles, 0x800, 181},
    {gfx_pkmn_species_182_pokemon_blubella_frontspriteTiles, 0x800, 182},
    {gfx_pkmn_species_183_pokemon_marill_frontspriteTiles, 0x800, 183},
    {gfx_pkmn_species_184_pokemon_azumarill_frontspriteTiles, 0x800, 184},
    {gfx_pkmn_species_185_pokemon_mogelbaum_frontspriteTiles, 0x800, 185},
    {gfx_pkmn_species_186_pokemon_clavion_frontspriteTiles, 0x800, 186},
    {gfx_pkmn_species_187_pokemon_lichtel_frontspriteTiles, 0x800, 187},
    {gfx_pkmn_species_188_pokemon_laternecto_frontspriteTiles, 0x800, 188},
    {gfx_pkmn_species_189_pokemon_sklelabra_frontspriteTiles, 0x800, 189},
    {gfx_pkmn_species_190_pokemon_griffel_frontspriteTiles, 0x800, 190},
    {gfx_pkmn_species_191_pokemon_shnebedeck_frontspriteTiles, 0x800, 191},
    {gfx_pkmn_species_192_pokemon_rexblisar_frontspriteTiles, 0x800, 192},
    {gfx_pkmn_species_193_pokemon_ambidiffel_frontspriteTiles, 0x800, 193},
    {gfx_pkmn_species_194_pokemon_felino_frontspriteTiles, 0x800, 194},
    {gfx_pkmn_species_195_pokemon_morlord_frontspriteTiles, 0x800, 195},
    {gfx_pkmn_species_196_pokemon_psiana_frontspriteTiles, 0x800, 196},
    {gfx_pkmn_species_197_pokemon_nachtara_frontspriteTiles, 0x800, 197},
    {gfx_pkmn_species_198_pokemon_kramurx_frontspriteTiles, 0x800, 198},
    {gfx_pkmn_species_199_pokemon_laschoking_frontspriteTiles, 0x800, 199},
    {gfx_pkmn_species_200_pokemon_kramshef_frontspriteTiles, 0x800, 200},
    {gfx_pkmn_species_201_pokemon_icognito_frontspriteTiles, 0x800, 201},
    {gfx_pkmn_species_202_pokemon_frosdedje_frontspriteTiles, 0x800, 202},
    {gfx_pkmn_species_203_pokemon_skorgro_frontspriteTiles, 0x800, 203},
    {gfx_pkmn_species_204_pokemon_tannza_frontspriteTiles, 0x800, 204},
    {gfx_pkmn_species_205_pokemon_forstellka_frontspriteTiles, 0x800, 205},
    {gfx_pkmn_species_206_pokemon_elevoltek_frontspriteTiles, 0x800, 206},
    {gfx_pkmn_species_207_pokemon_skorgla_frontspriteTiles, 0x800, 207},
    {gfx_pkmn_species_208_pokemon_stahlos_frontspriteTiles, 0x800, 208},
    {gfx_pkmn_species_209_pokemon_snubbull_frontspriteTiles, 0x800, 209},
    {gfx_pkmn_species_210_pokemon_granbull_frontspriteTiles, 0x800, 210},
    {gfx_pkmn_species_211_pokemon_mamutel_frontspriteTiles, 0x800, 211},
    {gfx_pkmn_species_212_pokemon_scherox_frontspriteTiles, 0x800, 212},
    {gfx_pkmn_species_213_pokemon_fluffeluff_frontspriteTiles, 0x800, 213},
    {gfx_pkmn_species_214_pokemon_skaraborn_frontspriteTiles, 0x800, 214},
    {gfx_pkmn_species_215_pokemon_kryppuk_frontspriteTiles, 0x800, 215},
    {gfx_pkmn_species_216_pokemon_teddiursa_frontspriteTiles, 0x800, 216},
    {gfx_pkmn_species_217_pokemon_ursaring_frontspriteTiles, 0x800, 217},
    {gfx_pkmn_species_218_pokemon_schneckmag_frontspriteTiles, 0x800, 218},
    {gfx_pkmn_species_219_pokemon_magcargo_frontspriteTiles, 0x800, 219},
    {gfx_pkmn_species_220_pokemon_quiekel_frontspriteTiles, 0x800, 220},
    {gfx_pkmn_species_221_pokemon_keifel_frontspriteTiles, 0x800, 221},
    {gfx_pkmn_species_222_pokemon_mampfaxo_frontspriteTiles, 0x800, 222},
    {gfx_pkmn_species_223_pokemon_remoraid_frontspriteTiles, 0x800, 223},
    {gfx_pkmn_species_224_pokemon_octillery_frontspriteTiles, 0x800, 224},
    {gfx_pkmn_species_225_pokemon_botogel_frontspriteTiles, 0x800, 225},
    {gfx_pkmn_species_226_pokemon_schlurplek_frontspriteTiles, 0x800, 226},
    {gfx_pkmn_species_227_pokemon_panzaeron_frontspriteTiles, 0x800, 227},
    {gfx_pkmn_species_228_pokemon_hunduster_frontspriteTiles, 0x800, 228},
    {gfx_pkmn_species_229_pokemon_hundemon_frontspriteTiles, 0x800, 229},
    {gfx_pkmn_species_230_pokemon_seedraking_frontspriteTiles, 0x800, 230},
    {gfx_pkmn_species_231_pokemon_phanpy_frontspriteTiles, 0x800, 231},
    {gfx_pkmn_species_232_pokemon_donphan_frontspriteTiles, 0x800, 232},
    {gfx_pkmn_species_233_pokemon_porygon2_frontspriteTiles, 0x800, 233},
    {gfx_pkmn_species_234_pokemon_voluminas_frontspriteTiles, 0x800, 234},
    {gfx_pkmn_species_235_pokemon_traunmagil_frontspriteTiles, 0x800, 235},
    {gfx_pkmn_species_236_pokemon_rabauz_frontspriteTiles, 0x800, 236},
    {gfx_pkmn_species_237_pokemon_kapoera_frontspriteTiles, 0x800, 237},
    {gfx_pkmn_species_238_pokemon_sen_long_frontspriteTiles, 0x800, 238},
    {gfx_pkmn_species_239_pokemon_elekid_frontspriteTiles, 0x800, 239},
    {gfx_pkmn_species_240_pokemon_magby_frontspriteTiles, 0x800, 240},
    {gfx_pkmn_species_241_pokemon_miltank_frontspriteTiles, 0x800, 241},
    {gfx_pkmn_species_242_pokemon_heiteira_frontspriteTiles, 0x800, 242},
    {gfx_pkmn_species_243_pokemon_raikou_frontspriteTiles, 0x800, 243},
    {gfx_pkmn_species_244_pokemon_entei_frontspriteTiles, 0x800, 244},
    {gfx_pkmn_species_245_pokemon_suicune_frontspriteTiles, 0x800, 245},
    {gfx_pkmn_species_246_pokemon_larvitar_frontspriteTiles, 0x800, 246},
    {gfx_pkmn_species_247_pokemon_pupitar_frontspriteTiles, 0x800, 247},
    {gfx_pkmn_species_248_pokemon_despotar_frontspriteTiles, 0x800, 248},
    {gfx_pkmn_species_249_pokemon_lugia_frontspriteTiles, 0x800, 249},
    {gfx_pkmn_species_250_pokemon_ho_oh_frontspriteTiles, 0x800, 250},
    {gfx_pkmn_species_251_pokemon_celebi_frontspriteTiles, 0x800, 251},
    {gfx_pkmn_rotom_heat_frontspriteTiles, 0x800, 252},
    {gfx_pkmn_rotom_wash_frontspriteTiles, 0x800, 253},
    {gfx_pkmn_rotom_frost_frontspriteTiles, 0x800, 254},
    {gfx_pkmn_rotom_fan_frontspriteTiles, 0x800, 255},
    {gfx_pkmn_rotom_mow_frontspriteTiles, 0x800, 256},
    {gfx_pkmn_species_257_pokemon_durengarda_frontspriteTiles, 0x800, 257},
    {gfx_pkmn_mega_sandamer_frontspriteTiles, 0x800, 258},
    {gfx_pkmn_mega_lahmus_frontspriteTiles, 0x800, 259},
    {gfx_pkmn_mega_maskeregen_frontspriteTiles, 0x800, 260},
    {gfx_pkmn_species_261_pokemon_ampharaosm_frontspriteTiles, 0x800, 261},
    {gfx_pkmn_species_262_pokemon_banette_mega_frontspriteTiles, 0x800, 262},
    {gfx_pkmn_species_263_pokemon_biborm_frontspriteTiles, 0x800, 263},
    {gfx_pkmn_species_264_pokemon_altariam_frontspriteTiles, 0x800, 264},
    {gfx_pkmn_species_265_pokemon_geowazm_frontspriteTiles, 0x800, 265},
    {gfx_pkmn_species_266_pokemon_sengom_frontspriteTiles, 0x800, 266},
    {gfx_pkmn_species_267_pokemon_vipitism_frontspriteTiles, 0x800, 267},
    {gfx_pkmn_species_268_pokemon_zobirism_frontspriteTiles, 0x800, 268},
    {gfx_pkmn_species_269_pokemon_tropius_mega_frontspriteTiles, 0x800, 269},
    {gfx_pkmn_species_270_pokemon_octillery_mega_frontspriteTiles, 0x800, 270},
    {gfx_pkmn_species_271_pokemon_rasaff_mega_frontspriteTiles, 0x800, 271},
    {gfx_pkmn_species_272_pokemon_110_frontspriteTiles, 0x800, 272},
    {gfx_pkmn_species_273_pokemon_111_frontspriteTiles, 0x800, 273},
    {gfx_pkmn_species_274_pokemon_112_frontspriteTiles, 0x800, 274},
    {gfx_pkmn_species_275_pokemon_113_frontspriteTiles, 0x800, 275},
    {gfx_pkmn_species_276_pokemon_114_frontspriteTiles, 0x800, 276},
    {gfx_pkmn_species_277_pokemon_lockschal_frontspriteTiles, 0x800, 277},
    {gfx_pkmn_species_278_pokemon_stichschal_frontspriteTiles, 0x800, 278},
    {gfx_pkmn_species_279_pokemon_stahlstich_frontspriteTiles, 0x800, 279},
    {gfx_pkmn_species_280_pokemon_weluno_frontspriteTiles, 0x800, 280},
    {gfx_pkmn_species_281_pokemon_orthodos_frontspriteTiles, 0x800, 281},
    {gfx_pkmn_species_282_pokemon_zerbertres_frontspriteTiles, 0x800, 282},
    {gfx_pkmn_species_283_pokemon_seekid_frontspriteTiles, 0x800, 283},
    {gfx_pkmn_species_284_pokemon_seeskull_frontspriteTiles, 0x800, 284},
    {gfx_pkmn_species_285_pokemon_skullydra_frontspriteTiles, 0x800, 285},
    {gfx_pkmn_species_286_pokemon_fiffyen_frontspriteTiles, 0x800, 286},
    {gfx_pkmn_species_287_pokemon_magnayen_frontspriteTiles, 0x800, 287},
    {gfx_pkmn_species_288_pokemon_zigzachs_frontspriteTiles, 0x800, 288},
    {gfx_pkmn_species_289_pokemon_geradaks_frontspriteTiles, 0x800, 289},
    {gfx_pkmn_species_290_pokemon_waumpel_frontspriteTiles, 0x800, 290},
    {gfx_pkmn_species_291_pokemon_schaloko_frontspriteTiles, 0x800, 291},
    {gfx_pkmn_species_292_pokemon_papinella_frontspriteTiles, 0x800, 292},
    {gfx_pkmn_species_293_pokemon_panekon_frontspriteTiles, 0x800, 293},
    {gfx_pkmn_species_294_pokemon_pudox_frontspriteTiles, 0x800, 294},
    {gfx_pkmn_species_295_pokemon_loturzel_frontspriteTiles, 0x800, 295},
    {gfx_pkmn_species_296_pokemon_lombrero_frontspriteTiles, 0x800, 296},
    {gfx_pkmn_species_297_pokemon_kappalores_frontspriteTiles, 0x800, 297},
    {gfx_pkmn_species_298_pokemon_samurzel_frontspriteTiles, 0x800, 298},
    {gfx_pkmn_species_299_pokemon_blanas_frontspriteTiles, 0x800, 299},
    {gfx_pkmn_species_300_pokemon_tengulist_frontspriteTiles, 0x800, 300},
    {gfx_pkmn_species_301_pokemon_nincada_frontspriteTiles, 0x800, 301},
    {gfx_pkmn_species_302_pokemon_ninjask_frontspriteTiles, 0x800, 302},
    {gfx_pkmn_species_303_pokemon_ninjatom_frontspriteTiles, 0x800, 303},
    {gfx_pkmn_species_304_pokemon_schwalbini_frontspriteTiles, 0x800, 304},
    {gfx_pkmn_species_305_pokemon_schwalboss_frontspriteTiles, 0x800, 305},
    {gfx_pkmn_species_306_pokemon_knilz_frontspriteTiles, 0x800, 306},
    {gfx_pkmn_species_307_pokemon_kapilz_frontspriteTiles, 0x800, 307},
    {gfx_pkmn_species_308_pokemon_pandir_frontspriteTiles, 0x800, 308},
    {gfx_pkmn_species_309_pokemon_wingull_frontspriteTiles, 0x800, 309},
    {gfx_pkmn_species_310_pokemon_pelipper_frontspriteTiles, 0x800, 310},
    {gfx_pkmn_species_311_pokemon_gehweiher_frontspriteTiles, 0x800, 311},
    {gfx_pkmn_species_312_pokemon_maskeregen_frontspriteTiles, 0x800, 312},
    {gfx_pkmn_species_313_pokemon_wailmer_frontspriteTiles, 0x800, 313},
    {gfx_pkmn_species_314_pokemon_wailord_frontspriteTiles, 0x800, 314},
    {gfx_pkmn_species_315_pokemon_eneco_frontspriteTiles, 0x800, 315},
    {gfx_pkmn_species_316_pokemon_enekoro_frontspriteTiles, 0x800, 316},
    {gfx_pkmn_species_317_pokemon_kecleon_frontspriteTiles, 0x800, 317},
    {gfx_pkmn_species_318_pokemon_puppance_frontspriteTiles, 0x800, 318},
    {gfx_pkmn_species_319_pokemon_lepumentas_frontspriteTiles, 0x800, 319},
    {gfx_pkmn_species_320_pokemon_nasgnet_frontspriteTiles, 0x800, 320},
    {gfx_pkmn_species_321_pokemon_magbrant_frontspriteTiles, 0x800, 321},
    {gfx_pkmn_species_322_pokemon_zwirrfinst_frontspriteTiles, 0x800, 322},
    {gfx_pkmn_species_323_pokemon_schmerbe_frontspriteTiles, 0x800, 323},
    {gfx_pkmn_species_324_pokemon_welsar_frontspriteTiles, 0x800, 324},
    {gfx_pkmn_species_325_pokemon_liebiskus_frontspriteTiles, 0x800, 325},
    {gfx_pkmn_species_326_pokemon_krebscorps_frontspriteTiles, 0x800, 326},
    {gfx_pkmn_species_327_pokemon_krebutack_frontspriteTiles, 0x800, 327},
    {gfx_pkmn_species_328_pokemon_barschwa_frontspriteTiles, 0x800, 328},
    {gfx_pkmn_species_329_pokemon_milotic_frontspriteTiles, 0x800, 329},
    {gfx_pkmn_species_330_pokemon_kanivanha_frontspriteTiles, 0x800, 330},
    {gfx_pkmn_species_331_pokemon_tohaido_frontspriteTiles, 0x800, 331},
    {gfx_pkmn_species_332_pokemon_knacklion_frontspriteTiles, 0x800, 332},
    {gfx_pkmn_species_333_pokemon_vibrava_frontspriteTiles, 0x800, 333},
    {gfx_pkmn_species_334_pokemon_libelldra_frontspriteTiles, 0x800, 334},
    {gfx_pkmn_species_335_pokemon_riolu_frontspriteTiles, 0x800, 335},
    {gfx_pkmn_species_336_pokemon_lucario_frontspriteTiles, 0x800, 336},
    {gfx_pkmn_species_337_pokemon_frizelbliz_frontspriteTiles, 0x800, 337},
    {gfx_pkmn_species_338_pokemon_voltenso_frontspriteTiles, 0x800, 338},
    {gfx_pkmn_species_339_pokemon_camaub_frontspriteTiles, 0x800, 339},
    {gfx_pkmn_species_340_pokemon_camerupt_frontspriteTiles, 0x800, 340},
    {gfx_pkmn_species_341_pokemon_seemops_frontspriteTiles, 0x800, 341},
    {gfx_pkmn_species_342_pokemon_seejong_frontspriteTiles, 0x800, 342},
    {gfx_pkmn_species_343_pokemon_walraisa_frontspriteTiles, 0x800, 343},
    {gfx_pkmn_species_344_pokemon_tuska_frontspriteTiles, 0x800, 344},
    {gfx_pkmn_species_345_pokemon_noktuska_frontspriteTiles, 0x800, 345},
    {gfx_pkmn_species_346_pokemon_schneppke_frontspriteTiles, 0x800, 346},
    {gfx_pkmn_species_347_pokemon_firnontor_frontspriteTiles, 0x800, 347},
    {gfx_pkmn_species_348_pokemon_lunastein_frontspriteTiles, 0x800, 348},
    {gfx_pkmn_species_349_pokemon_sonnfel_frontspriteTiles, 0x800, 349},
    {gfx_pkmn_species_350_pokemon_azurill_frontspriteTiles, 0x800, 350},
    {gfx_pkmn_species_351_pokemon_spoink_frontspriteTiles, 0x800, 351},
    {gfx_pkmn_species_352_pokemon_groink_frontspriteTiles, 0x800, 352},
    {gfx_pkmn_pichu_frontspriteTiles, 0x800, 353},
    {gfx_pkmn_rotom_frontspriteTiles, 0x800, 354},
    {gfx_pkmn_species_355_pokemon_flunkifer_frontspriteTiles, 0x800, 355},
    {gfx_pkmn_species_356_pokemon_meditie_frontspriteTiles, 0x800, 356},
    {gfx_pkmn_species_357_pokemon_meditalis_frontspriteTiles, 0x800, 357},
    {gfx_pkmn_species_358_pokemon_wablu_frontspriteTiles, 0x800, 358},
    {gfx_pkmn_species_359_pokemon_altaria_frontspriteTiles, 0x800, 359},
    {gfx_pkmn_species_360_pokemon_klingplim_frontspriteTiles, 0x800, 360},
    {gfx_pkmn_species_361_pokemon_zwirrlicht_frontspriteTiles, 0x800, 361},
    {gfx_pkmn_species_362_pokemon_zwirrklop_frontspriteTiles, 0x800, 362},
    {gfx_pkmn_species_363_pokemon_porygon_z_frontspriteTiles, 0x800, 363},
    {gfx_pkmn_species_364_pokemon_bummelz_frontspriteTiles, 0x800, 364},
    {gfx_pkmn_species_365_pokemon_muntier_frontspriteTiles, 0x800, 365},
    {gfx_pkmn_species_366_pokemon_letarking_frontspriteTiles, 0x800, 366},
    {gfx_pkmn_molunk_frontspriteTiles, 0x800, 367}, 
    {gfx_pkmn_amfira_frontspriteTiles, 0x800, 368},
    {gfx_pkmn_species_369_pokemon_tropius_frontspriteTiles, 0x800, 369},
    {gfx_pkmn_species_370_pokemon_kaumalat_frontspriteTiles, 0x800, 370},
    {gfx_pkmn_species_371_pokemon_knarksel_frontspriteTiles, 0x800, 371},
    {gfx_pkmn_species_372_pokemon_knakrack_frontspriteTiles, 0x800, 372},
    {gfx_pkmn_species_373_pokemon_perlu_frontspriteTiles, 0x800, 373},
    {gfx_pkmn_species_374_pokemon_aalabyss_frontspriteTiles, 0x800, 374},
    {gfx_pkmn_species_375_pokemon_saganabyss_frontspriteTiles, 0x800, 375},
    {gfx_pkmn_species_376_pokemon_absol_frontspriteTiles, 0x800, 376},
    {gfx_pkmn_species_377_pokemon_shuppet_frontspriteTiles, 0x800, 377},
    {gfx_pkmn_species_378_pokemon_banette_frontspriteTiles, 0x800, 378},
    {gfx_pkmn_species_379_pokemon_vipitis_frontspriteTiles, 0x800, 379},
    {gfx_pkmn_species_380_pokemon_sengo_frontspriteTiles, 0x800, 380},
    {gfx_pkmn_species_381_pokemon_relicanth_frontspriteTiles, 0x800, 381},
    {gfx_pkmn_species_382_pokemon_stollunior_frontspriteTiles, 0x800, 382},
    {gfx_pkmn_species_383_pokemon_stollrak_frontspriteTiles, 0x800, 383},
    {gfx_pkmn_species_384_pokemon_stolloss_frontspriteTiles, 0x800, 384},
    {(void*)0x08E26780, 0x800, 385}, // Keep Formeo's original tiles
    {gfx_pkmn_species_386_pokemon_wonneira_frontspriteTiles, 0x800, 386},
    {gfx_pkmn_species_387_pokemon_mobai_frontspriteTiles, 0x800, 387},
    {gfx_pkmn_species_388_pokemon_liliep_frontspriteTiles, 0x800, 388},
    {gfx_pkmn_species_389_pokemon_wielie_frontspriteTiles, 0x800, 389},
    {gfx_pkmn_species_390_pokemon_anorith_frontspriteTiles, 0x800, 390},
    {gfx_pkmn_species_391_pokemon_armaldo_frontspriteTiles, 0x800, 391},
    {gfx_pkmn_species_392_pokemon_trasla_frontspriteTiles, 0x800, 392},
    {gfx_pkmn_species_393_pokemon_kirlia_frontspriteTiles, 0x800, 393},
    {gfx_pkmn_species_394_pokemon_guardevoir_frontspriteTiles, 0x800, 394},
    {gfx_pkmn_species_395_pokemon_kindwurm_frontspriteTiles, 0x800, 395},
    {gfx_pkmn_species_396_pokemon_draschel_frontspriteTiles, 0x800, 396},
    {gfx_pkmn_species_397_pokemon_brutalanda_frontspriteTiles, 0x800, 397},
    {gfx_pkmn_species_398_pokemon_tanhel_frontspriteTiles, 0x800, 398},
    {gfx_pkmn_species_399_pokemon_metang_frontspriteTiles, 0x800, 399},
    {gfx_pkmn_species_400_pokemon_metagross_frontspriteTiles, 0x800, 400},
    {gfx_pkmn_species_401_pokemon_regirock_frontspriteTiles, 0x800, 401},
    {gfx_pkmn_species_402_pokemon_regice_frontspriteTiles, 0x800, 402},
    {gfx_pkmn_species_403_pokemon_registeel_frontspriteTiles, 0x800, 403},
    {gfx_pkmn_species_404_pokemon_kyogre_frontspriteTiles, 0x800, 404},
    {gfx_pkmn_species_405_pokemon_groudon_frontspriteTiles, 0x800, 405},
    {gfx_pkmn_species_406_pokemon_rayquaza_frontspriteTiles, 0x800, 406},
    {gfx_pkmn_species_407_pokemon_latias_frontspriteTiles, 0x800, 407},
    {gfx_pkmn_species_408_pokemon_latios_frontspriteTiles, 0x800, 408},
    {gfx_pkmn_species_409_pokemon_jirachi_frontspriteTiles, 0x800, 409},
    {gfx_pkmn_species_410_pokemon_deoxys_frontspriteTiles, 0x800, 410},
    {gfx_pkmn_species_411_pokemon_palimpalim_frontspriteTiles, 0x800, 411},
    {gfx_pkmn_species_412_pokemon_egg_frontspriteTiles, 0x800, 412},
    {gfx_pkmn_species_413_pokemon_icognito_b_frontspriteTiles, 0x800, 413},
    {gfx_pkmn_species_414_pokemon_icognito_c_frontspriteTiles, 0x800, 414},
    {gfx_pkmn_species_415_pokemon_icognito_d_frontspriteTiles, 0x800, 415},
    {gfx_pkmn_species_416_pokemon_icognito_e_frontspriteTiles, 0x800, 416},
    {gfx_pkmn_species_417_pokemon_icognito_f_frontspriteTiles, 0x800, 417},
    {gfx_pkmn_species_418_pokemon_icognito_g_frontspriteTiles, 0x800, 418},
    {gfx_pkmn_species_419_pokemon_icognito_h_frontspriteTiles, 0x800, 419},
    {gfx_pkmn_species_420_pokemon_icognito_i_frontspriteTiles, 0x800, 420},
    {gfx_pkmn_species_421_pokemon_icognito_j_frontspriteTiles, 0x800, 421},
    {gfx_pkmn_species_422_pokemon_icognito_k_frontspriteTiles, 0x800, 422},
    {gfx_pkmn_species_423_pokemon_icognito_l_frontspriteTiles, 0x800, 423},
    {gfx_pkmn_species_424_pokemon_icognito_m_frontspriteTiles, 0x800, 424},
    {gfx_pkmn_species_425_pokemon_icognito_n_frontspriteTiles, 0x800, 425},
    {gfx_pkmn_species_426_pokemon_icognito_o_frontspriteTiles, 0x800, 426},
    {gfx_pkmn_species_427_pokemon_icognito_p_frontspriteTiles, 0x800, 427},
    {gfx_pkmn_species_428_pokemon_icognito_q_frontspriteTiles, 0x800, 428},
    {gfx_pkmn_species_429_pokemon_icognito_r_frontspriteTiles, 0x800, 429},
    {gfx_pkmn_species_430_pokemon_icognito_s_frontspriteTiles, 0x800, 430},
    {gfx_pkmn_species_431_pokemon_icognito_t_frontspriteTiles, 0x800, 431},
    {gfx_pkmn_species_432_pokemon_icognito_u_frontspriteTiles, 0x800, 432},
    {gfx_pkmn_species_433_pokemon_icognito_v_frontspriteTiles, 0x800, 433},
    {gfx_pkmn_species_434_pokemon_icognito_w_frontspriteTiles, 0x800, 434},
    {gfx_pkmn_species_435_pokemon_icognito_x_frontspriteTiles, 0x800, 435},
    {gfx_pkmn_species_436_pokemon_icognito_y_frontspriteTiles, 0x800, 436},
    {gfx_pkmn_species_437_pokemon_icognito_z_frontspriteTiles, 0x800, 437},
    {gfx_pkmn_species_438_pokemon_icognito_exclamation_frontspriteTiles, 0x800, 438},
    {gfx_pkmn_species_439_pokemon_icognito_question_frontspriteTiles, 0x800, 439},
    {gfx_pkmn_species_440_pokemon_groudon_e_frontspriteTiles, 0x800, 440},
    {gfx_pkmn_species_441_pokemon_kecleon_p_frontspriteTiles, 0x800, 441}
};
