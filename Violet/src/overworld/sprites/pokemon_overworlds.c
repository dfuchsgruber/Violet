#include "types.h"
#include "overworld/sprite.h"
#include "color.h"
#include "constants/species.h"
#include "debug.h" 

static palette ow_pokemon_pals[] = {
    [0] = {.pal = gfx_ow_bisasamPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISASAM},
    [POKEMON_BISASAM] = {.pal = gfx_ow_bisasamPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISASAM},
    [POKEMON_BISAKNOSP] = {.pal = gfx_ow_bisaknospPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISAKNOSP},
    [POKEMON_BISAFLOR] = {.pal = gfx_ow_bisaflorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISAFLOR},
    [POKEMON_GLUMANDA] = {.pal = gfx_ow_glumandaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLUMANDA},
    [POKEMON_GLUTEXO] = {.pal = gfx_ow_glutexoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLUTEXO},
    [POKEMON_GLURAK] = {.pal = gfx_ow_glurakPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLURAK},
    [POKEMON_SCHIGGY] = {.pal = gfx_ow_schiggyPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHIGGY},
    [POKEMON_SCHILLOK] = {.pal = gfx_ow_schillokPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHILLOK},
    [POKEMON_TURTOK] = {.pal = gfx_ow_turtokPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TURTOK},
    [POKEMON_DARTIRI] = {.pal = gfx_ow_dartiriPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DARTIRI},
    [POKEMON_DARTIGNIS] = {.pal = gfx_ow_dartignisPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DARTIGNIS},
    [POKEMON_FIARO] = {.pal = gfx_ow_fiaroPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FIARO},
    [POKEMON_HORNLIU] = {.pal = gfx_ow_hornliuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HORNLIU},
    [POKEMON_KOKUNA] = {.pal = gfx_ow_kokunaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KOKUNA},
    [POKEMON_BIBOR] = {.pal = gfx_ow_biborPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BIBOR},
    [POKEMON_STARALILI] = {.pal = gfx_ow_staraliliPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARALILI},
    [POKEMON_STARAVIA] = {.pal = gfx_ow_staraviaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARAVIA},
    [POKEMON_STARAPTOR] = {.pal = gfx_ow_staraptorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARAPTOR},
    [POKEMON_BRONZEL] = {.pal = gfx_ow_bronzelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BRONZEL},
    [POKEMON_BRONZONG] = {.pal = gfx_ow_bronzongPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BRONZONG},
    [POKEMON_MAEHIKEL] = {.pal = gfx_ow_maehikelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAEHIKEL},
    [POKEMON_CHEVRUMM] = {.pal = gfx_ow_chevrummPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CHEVRUMM},
    [POKEMON_PARAGONI] = {.pal = gfx_ow_paragoniPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PARAGONI},
    [POKEMON_TROMBORK] = {.pal = gfx_ow_tromborkPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TROMBORK},
    [POKEMON_PIKACHU] = {.pal = gfx_ow_pikachuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PIKACHU},
    [POKEMON_RAICHU] = {.pal = gfx_ow_raichuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAICHU},
    [POKEMON_SANDAN] = {.pal = gfx_ow_sandanPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SANDAN},
    [POKEMON_SANDAMER] = {.pal = gfx_ow_sandamerPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SANDAMER},
    [POKEMON_NIDORANW] = {.pal = gfx_ow_nidoranwPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORANW},
    [POKEMON_NIDORINA] = {.pal = gfx_ow_nidorinaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORINA},
    [POKEMON_NIDOQUEEN] = {.pal = gfx_ow_nidoqueenPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDOQUEEN},
    [POKEMON_NIDORANM] = {.pal = gfx_ow_nidoranmPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORANM},
    [POKEMON_NIDORINO] = {.pal = gfx_ow_nidorinoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORINO},
    [POKEMON_NIDOKING] = {.pal = gfx_ow_nidokingPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDOKING},
    [POKEMON_FLOETTE] = {.pal = gfx_ow_floettePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLOETTE},
    [POKEMON_FLORGES] = {.pal = gfx_ow_florgesPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLORGES},
    [POKEMON_VULPIX] = {.pal = gfx_ow_vulpixPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VULPIX},
    [POKEMON_VULNONA] = {.pal = gfx_ow_vulnonaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VULNONA},
    [POKEMON_PUMMELUFF] = {.pal = gfx_ow_pummeluffPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUMMELUFF},
    [POKEMON_KNUDDELUFF] = {.pal = gfx_ow_knuddeluffPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNUDDELUFF},
    [POKEMON_ZUBAT] = {.pal = gfx_ow_zubatPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZUBAT},
    [POKEMON_GOLBAT] = {.pal = gfx_ow_golbatPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GOLBAT},
    [POKEMON_MYRAPLA] = {.pal = gfx_ow_myraplaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MYRAPLA},
    [POKEMON_DUFLOR] = {.pal = gfx_ow_duflorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DUFLOR},
    [POKEMON_GIFLOR] = {.pal = gfx_ow_giflorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GIFLOR},
    [POKEMON_FOLIPURBA] = {.pal = gfx_ow_folipurbaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FOLIPURBA},
    [POKEMON_FEELINARA] = {.pal = gfx_ow_feelinaraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FEELINARA},
    [POKEMON_WATTZAPF] = {.pal = gfx_ow_wattzapfPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WATTZAPF},
    [POKEMON_VOLTULA] = {.pal = gfx_ow_voltulaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTULA},
    [POKEMON_DIGDA] = {.pal = gfx_ow_digdaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DIGDA},
    [POKEMON_DIGDRI] = {.pal = gfx_ow_digdriPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DIGDRI},
    [POKEMON_KASTADUR] = {.pal = gfx_ow_kastadurPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KASTADUR},
    [POKEMON_TENTANTEL] = {.pal = gfx_ow_tentantelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENTANTEL},
    [POKEMON_ENTON] = {.pal = gfx_ow_entonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENTON},
    [POKEMON_ENTORON] = {.pal = gfx_ow_entoronPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENTORON},
    [POKEMON_MENKI] = {.pal = gfx_ow_menkiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MENKI},
    [POKEMON_RASAFF] = {.pal = gfx_ow_rasaffPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RASAFF},
    [POKEMON_FUKANO] = {.pal = gfx_ow_fukanoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FUKANO},
    [POKEMON_ARKANI] = {.pal = gfx_ow_arkaniPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARKANI},
    [POKEMON_GRAMOKLES] = {.pal = gfx_ow_gramoklesPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GRAMOKLES},
    [POKEMON_DUOKLES] = {.pal = gfx_ow_duoklesPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DUOKLES},
    [POKEMON_DURENGARD] = {.pal = gfx_ow_durengardPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DURENGARD},
    [POKEMON_ABRA] = {.pal = gfx_ow_abraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ABRA},
    [POKEMON_KADABRA] = {.pal = gfx_ow_kadabraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KADABRA},
    [POKEMON_SIMSALA] = {.pal = gfx_ow_simsalaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SIMSALA},
    [POKEMON_MACHOLLO] = {.pal = gfx_ow_macholloPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MACHOLLO},
    [POKEMON_MASCHOCK] = {.pal = gfx_ow_maschockPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MASCHOCK},
    [POKEMON_MACHOMEI] = {.pal = gfx_ow_machomeiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MACHOMEI},
    [POKEMON_KNOFENSA] = {.pal = gfx_ow_knofensaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNOFENSA},
    [POKEMON_ULTRIGARIA] = {.pal = gfx_ow_ultrigariaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ULTRIGARIA},
    [POKEMON_SARZENIA] = {.pal = gfx_ow_sarzeniaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SARZENIA},
    [POKEMON_TENTACHA] = {.pal = gfx_ow_tentachaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENTACHA},
    [POKEMON_TENTOXA] = {.pal = gfx_ow_tentoxaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENTOXA},
    [POKEMON_KLEINSTEIN] = {.pal = gfx_ow_kleinsteinPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KLEINSTEIN},
    [POKEMON_GEOROK] = {.pal = gfx_ow_georokPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GEOROK},
    [POKEMON_GEOWAZ] = {.pal = gfx_ow_geowazPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GEOWAZ},
    [POKEMON_PONITA] = {.pal = gfx_ow_ponitaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PONITA},
    [POKEMON_GALLOPA] = {.pal = gfx_ow_gallopaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GALLOPA},
    [POKEMON_FLEGMON] = {.pal = gfx_ow_flegmonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLEGMON},
    [POKEMON_LAHMUS] = {.pal = gfx_ow_lahmusPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAHMUS},
    [POKEMON_MAGNETILO] = {.pal = gfx_ow_magnetiloPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNETILO},
    [POKEMON_MAGNETON] = {.pal = gfx_ow_magnetonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNETON},
    [POKEMON_PORENTA] = {.pal = gfx_ow_porentaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORENTA},
    [POKEMON_DODU] = {.pal = gfx_ow_doduPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DODU},
    [POKEMON_DODRI] = {.pal = gfx_ow_dodriPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DODRI},
    [POKEMON_JUROB] = {.pal = gfx_ow_jurobPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_JUROB},
    [POKEMON_JUGONG] = {.pal = gfx_ow_jugongPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_JUGONG},
    [POKEMON_SLEIMA] = {.pal = gfx_ow_sleimaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SLEIMA},
    [POKEMON_SLEIMOK] = {.pal = gfx_ow_sleimokPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SLEIMOK},
    [POKEMON_MUSCHAS] = {.pal = gfx_ow_muschasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MUSCHAS},
    [POKEMON_AUSTOS] = {.pal = gfx_ow_austosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AUSTOS},
    [POKEMON_NEBULAK] = {.pal = gfx_ow_nebulakPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NEBULAK},
    [POKEMON_ALPOLLO] = {.pal = gfx_ow_alpolloPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ALPOLLO},
    [POKEMON_GENGAR] = {.pal = gfx_ow_gengarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GENGAR},
    [POKEMON_ONIX] = {.pal = gfx_ow_onixPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ONIX},
    [POKEMON_TRAUMATO] = {.pal = gfx_ow_traumatoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAUMATO},
    [POKEMON_HYPNO] = {.pal = gfx_ow_hypnoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HYPNO},
    [POKEMON_KRABBY] = {.pal = gfx_ow_krabbyPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRABBY},
    [POKEMON_KINGLER] = {.pal = gfx_ow_kinglerPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KINGLER},
    [POKEMON_VOLTOBAL] = {.pal = gfx_ow_voltobalPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTOBAL},
    [POKEMON_LEKTROBAL] = {.pal = gfx_ow_lektrobalPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEKTROBAL},
    [POKEMON_OWEI] = {.pal = gfx_ow_oweiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_OWEI},
    [POKEMON_KOKOWEI] = {.pal = gfx_ow_kokoweiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KOKOWEI},
    [POKEMON_TRAGOSSO] = {.pal = gfx_ow_tragossoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAGOSSO},
    [POKEMON_KNOGGA] = {.pal = gfx_ow_knoggaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNOGGA},
    [POKEMON_KICKLEE] = {.pal = gfx_ow_kickleePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KICKLEE},
    [POKEMON_NOCKCHAN] = {.pal = gfx_ow_nockchanPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NOCKCHAN},
    [POKEMON_SCHLURP] = {.pal = gfx_ow_schlurpPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHLURP},
    [POKEMON_SMOGON] = {.pal = gfx_ow_smogonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SMOGON},
    [POKEMON_SMOGMOG] = {.pal = gfx_ow_smogmogPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SMOGMOG},
    [POKEMON_RIHORN] = {.pal = gfx_ow_rihornPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIHORN},
    [POKEMON_RIZEROS] = {.pal = gfx_ow_rizerosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIZEROS},
    [POKEMON_CHANEIRA] = {.pal = gfx_ow_chaneiraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CHANEIRA},
    [POKEMON_ZOBIRIS] = {.pal = gfx_ow_zobirisPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZOBIRIS},
    [POKEMON_KANGAMA] = {.pal = gfx_ow_kangamaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KANGAMA},
    [POKEMON_SEEPER] = {.pal = gfx_ow_seeperPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEPER},
    [POKEMON_SEEMON] = {.pal = gfx_ow_seemonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEMON},
    [POKEMON_QUABBEL] = {.pal = gfx_ow_quabbelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_QUABBEL},
    [POKEMON_APOQUALLYP] = {.pal = gfx_ow_apoquallypPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_APOQUALLYP},
    [POKEMON_STERNDU] = {.pal = gfx_ow_sternduPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STERNDU},
    [POKEMON_STARMIE] = {.pal = gfx_ow_starmiePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARMIE},
    [POKEMON_TRAUNFUGIL] = {.pal = gfx_ow_traunfugilPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAUNFUGIL},
    [POKEMON_SICHLOR] = {.pal = gfx_ow_sichlorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SICHLOR},
    [POKEMON_GALAGLADI] = {.pal = gfx_ow_galagladiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GALAGLADI},
    [POKEMON_ELEKTEK] = {.pal = gfx_ow_elektekPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ELEKTEK},
    [POKEMON_MAGMAR] = {.pal = gfx_ow_magmarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGMAR},
    [POKEMON_PINSIR] = {.pal = gfx_ow_pinsirPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PINSIR},
    [POKEMON_TAUROS] = {.pal = gfx_ow_taurosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TAUROS},
    [POKEMON_KARPADOR] = {.pal = gfx_ow_karpadorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KARPADOR},
    [POKEMON_GARADOS] = {.pal = gfx_ow_garadosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GARADOS},
    [POKEMON_LAPRAS] = {.pal = gfx_ow_laprasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAPRAS},
    [POKEMON_DITTO] = {.pal = gfx_ow_dittoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DITTO},
    [POKEMON_EVOLI] = {.pal = gfx_ow_evoliPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_EVOLI},
    [POKEMON_AQUANA] = {.pal = gfx_ow_aquanaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AQUANA},
    [POKEMON_BLITZA] = {.pal = gfx_ow_blitzaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BLITZA},
    [POKEMON_FLAMARA] = {.pal = gfx_ow_flamaraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLAMARA},
    [POKEMON_PORYGON] = {.pal = gfx_ow_porygonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORYGON},
    [POKEMON_AMONITAS] = {.pal = gfx_ow_amonitasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMONITAS},
    [POKEMON_AMOROSO] = {.pal = gfx_ow_amorosoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMOROSO},
    [POKEMON_KABUTO] = {.pal = gfx_ow_kabutoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KABUTO},
    [POKEMON_KABUTOPS] = {.pal = gfx_ow_kabutopsPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KABUTOPS},
    [POKEMON_AERODACTYL] = {.pal = gfx_ow_aerodactylPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AERODACTYL},
    [POKEMON_RELAXO] = {.pal = gfx_ow_relaxoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RELAXO},
    [POKEMON_ARKTOS] = {.pal = gfx_ow_arktosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARKTOS},
    [POKEMON_ZAPDOS] = {.pal = gfx_ow_zapdosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZAPDOS},
    [POKEMON_LAVADOS] = {.pal = gfx_ow_lavadosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAVADOS},
    [POKEMON_DRATINI] = {.pal = gfx_ow_dratiniPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRATINI},
    [POKEMON_DRAGONIR] = {.pal = gfx_ow_dragonirPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRAGONIR},
    [POKEMON_DRAGORAN] = {.pal = gfx_ow_dragoranPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRAGORAN},
    [POKEMON_MEWTU] = {.pal = gfx_ow_mewtuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEWTU},
    [POKEMON_MEW] = {.pal = gfx_ow_mewPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEW},
    [POKEMON_ENDIVIE] = {.pal = gfx_ow_endiviePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENDIVIE},
    [POKEMON_LORBLATT] = {.pal = gfx_ow_lorblattPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LORBLATT},
    [POKEMON_MEGANIE] = {.pal = gfx_ow_meganiePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEGANIE},
    [POKEMON_FEURIGEL] = {.pal = gfx_ow_feurigelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FEURIGEL},
    [POKEMON_IGELAVAR] = {.pal = gfx_ow_igelavarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IGELAVAR},
    [POKEMON_TORNUPTO] = {.pal = gfx_ow_tornuptoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TORNUPTO},
    [POKEMON_KARNIMANI] = {.pal = gfx_ow_karnimaniPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KARNIMANI},
    [POKEMON_TYRACROC] = {.pal = gfx_ow_tyracrocPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TYRACROC},
    [POKEMON_IMPERGATOR] = {.pal = gfx_ow_impergatorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IMPERGATOR},
    [POKEMON_IGNIVOR] = {.pal = gfx_ow_ignivorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IGNIVOR},
    [POKEMON_RAMOTH] = {.pal = gfx_ow_ramothPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAMOTH},
    [POKEMON_GLAZIOLA] = {.pal = gfx_ow_glaziolaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLAZIOLA},
    [POKEMON_RESLADERO] = {.pal = gfx_ow_resladeroPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RESLADERO},
    [POKEMON_LEDYBA] = {.pal = gfx_ow_ledybaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEDYBA},
    [POKEMON_LEDIAN] = {.pal = gfx_ow_ledianPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEDIAN},
    [POKEMON_WEBARAK] = {.pal = gfx_ow_webarakPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WEBARAK},
    [POKEMON_ARIADOS] = {.pal = gfx_ow_ariadosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARIADOS},
    [POKEMON_IKSBAT] = {.pal = gfx_ow_iksbatPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IKSBAT},
    [POKEMON_LAMPI] = {.pal = gfx_ow_lampiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAMPI},
    [POKEMON_LANTURN] = {.pal = gfx_ow_lanturnPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LANTURN},
    [POKEMON_MAGNEZONE] = {.pal = gfx_ow_magnezonePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNEZONE},
    [POKEMON_TOGEKISS] = {.pal = gfx_ow_togekissPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOGEKISS},
    [POKEMON_FLABEBE] = {.pal = gfx_ow_flabebePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLABEBE},
    [POKEMON_TOGEPI] = {.pal = gfx_ow_togepiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOGEPI},
    [POKEMON_TOGETIC] = {.pal = gfx_ow_togeticPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOGETIC},
    [POKEMON_NATU] = {.pal = gfx_ow_natuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NATU},
    [POKEMON_XATU] = {.pal = gfx_ow_xatuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_XATU},
    [POKEMON_VOLTILAMM] = {.pal = gfx_ow_voltilammPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTILAMM},
    [POKEMON_WAATY] = {.pal = gfx_ow_waatyPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAATY},
    [POKEMON_AMPHAROS] = {.pal = gfx_ow_ampharosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMPHAROS},
    [POKEMON_BLUBELLA] = {.pal = gfx_ow_blubellaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BLUBELLA},
    [POKEMON_MARILL] = {.pal = gfx_ow_marillPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MARILL},
    [POKEMON_AZUMARILL] = {.pal = gfx_ow_azumarillPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AZUMARILL},
    [POKEMON_MOGELBAUM] = {.pal = gfx_ow_mogelbaumPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MOGELBAUM},
    [POKEMON_CLAVION] = {.pal = gfx_ow_clavionPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CLAVION},
    [POKEMON_LICHTEL] = {.pal = gfx_ow_lichtelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LICHTEL},
    [POKEMON_LATERNECTO] = {.pal = gfx_ow_laternectoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LATERNECTO},
    [POKEMON_SKELABRA] = {.pal = gfx_ow_skelabraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKELABRA},
    [POKEMON_GRIFFEL] = {.pal = gfx_ow_griffelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GRIFFEL},
    [POKEMON_SHNEBEDECK] = {.pal = gfx_ow_shnebedeckPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SHNEBEDECK},
    [POKEMON_REXBLISAR] = {.pal = gfx_ow_rexblisarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REXBLISAR},
    [POKEMON_AMBIDIFFEL] = {.pal = gfx_ow_ambidiffelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMBIDIFFEL},
    [POKEMON_FELINO] = {.pal = gfx_ow_felinoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FELINO},
    [POKEMON_MORLORD] = {.pal = gfx_ow_morlordPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MORLORD},
    [POKEMON_PSIANA] = {.pal = gfx_ow_psianaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PSIANA},
    [POKEMON_NACHTARA] = {.pal = gfx_ow_nachtaraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NACHTARA},
    [POKEMON_KRAMURX] = {.pal = gfx_ow_kramurxPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRAMURX},
    [POKEMON_LASCHOKING] = {.pal = gfx_ow_laschokingPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LASCHOKING},
    [POKEMON_KRAMSHEF] = {.pal = gfx_ow_kramshefPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRAMSHEF},
    [POKEMON_ICOGNITO] = {.pal = gfx_ow_icognitoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO},
    [POKEMON_FROSDEDJE] = {.pal = gfx_ow_frosdedjePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FROSDEDJE},
    [POKEMON_SKORGRO] = {.pal = gfx_ow_skorgroPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKORGRO},
    [POKEMON_TANNZA] = {.pal = gfx_ow_tannzaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TANNZA},
    [POKEMON_FORSTELLKA] = {.pal = gfx_ow_forstellkaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FORSTELLKA},
    [POKEMON_ELEVOLTEK] = {.pal = gfx_ow_elevoltekPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ELEVOLTEK},
    [POKEMON_SKORGLA] = {.pal = gfx_ow_skorglaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKORGLA},
    [POKEMON_STAHLOS] = {.pal = gfx_ow_stahlosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STAHLOS},
    [POKEMON_SNUBBULL] = {.pal = gfx_ow_snubbullPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SNUBBULL},
    [POKEMON_GRANBULL] = {.pal = gfx_ow_granbullPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GRANBULL},
    [POKEMON_MAMUTEL] = {.pal = gfx_ow_mamutelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAMUTEL},
    [POKEMON_SCHEROX] = {.pal = gfx_ow_scheroxPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHEROX},
    [POKEMON_FLUFFELUFF] = {.pal = gfx_ow_fluffeluffPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLUFFELUFF},
    [POKEMON_SKARABORN] = {.pal = gfx_ow_skarabornPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKARABORN},
    [POKEMON_KRYPPUK] = {.pal = gfx_ow_kryppukPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRYPPUK},
    [POKEMON_TEDDIURSA] = {.pal = gfx_ow_teddiursaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TEDDIURSA},
    [POKEMON_URSARING] = {.pal = gfx_ow_ursaringPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_URSARING},
    [POKEMON_SCHNECKMAG] = {.pal = gfx_ow_schneckmagPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHNECKMAG},
    [POKEMON_MAGCARGO] = {.pal = gfx_ow_magcargoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGCARGO},
    [POKEMON_QUIEKEL] = {.pal = gfx_ow_quiekelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_QUIEKEL},
    [POKEMON_KEIFEL] = {.pal = gfx_ow_keifelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KEIFEL},
    [POKEMON_MAMPFAXO] = {.pal = gfx_ow_mampfaxoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAMPFAXO},
    [POKEMON_REMORAID] = {.pal = gfx_ow_remoraidPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REMORAID},
    [POKEMON_OCTILLERY] = {.pal = gfx_ow_octilleryPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_OCTILLERY},
    [POKEMON_BOTOGEL] = {.pal = gfx_ow_botogelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BOTOGEL},
    [POKEMON_SCHLURPLEK] = {.pal = gfx_ow_schlurplekPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHLURPLEK},
    [POKEMON_PANZAERON] = {.pal = gfx_ow_panzaeronPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PANZAERON},
    [POKEMON_HUNDUSTER] = {.pal = gfx_ow_hundusterPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HUNDUSTER},
    [POKEMON_HUNDEMON] = {.pal = gfx_ow_hundemonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HUNDEMON},
    [POKEMON_SEEDRAKING] = {.pal = gfx_ow_seedrakingPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEDRAKING},
    [POKEMON_PHANPY] = {.pal = gfx_ow_phanpyPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PHANPY},
    [POKEMON_DONPHAN] = {.pal = gfx_ow_donphanPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DONPHAN},
    [POKEMON_PORYGON2] = {.pal = gfx_ow_porygon2Pal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORYGON2},
    [POKEMON_VOLUMINAS] = {.pal = gfx_ow_voluminasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLUMINAS},
    [POKEMON_TRAUNMAGIL] = {.pal = gfx_ow_traunmagilPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAUNMAGIL},
    [POKEMON_RABAUZ] = {.pal = gfx_ow_rabauzPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RABAUZ},
    [POKEMON_KAPOERA] = {.pal = gfx_ow_kapoeraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAPOERA},
    [POKEMON_ELEKID] = {.pal = gfx_ow_elekidPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ELEKID},
    [POKEMON_MAGBY] = {.pal = gfx_ow_magbyPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGBY},
    [POKEMON_MILTANK] = {.pal = gfx_ow_miltankPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MILTANK},
    [POKEMON_HEITEIRA] = {.pal = gfx_ow_heiteiraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HEITEIRA},
    [POKEMON_RAIKOU] = {.pal = gfx_ow_raikouPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAIKOU},
    [POKEMON_ENTEI] = {.pal = gfx_ow_enteiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENTEI},
    [POKEMON_SUICUNE] = {.pal = gfx_ow_suicunePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SUICUNE},
    [POKEMON_LARVITAR] = {.pal = gfx_ow_larvitarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LARVITAR},
    [POKEMON_PUPITAR] = {.pal = gfx_ow_pupitarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUPITAR},
    [POKEMON_DESPOTAR] = {.pal = gfx_ow_despotarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DESPOTAR},
    [POKEMON_LUGIA] = {.pal = gfx_ow_lugiaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LUGIA},
    [POKEMON_HO_OH] = {.pal = gfx_ow_ho_ohPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HO_OH},
    [POKEMON_CELEBI] = {.pal = gfx_ow_celebiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CELEBI},
	[POKEMON_ROTOM_FORST] = {.pal = gfx_ow_rotom_frostPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_FORST},
	[POKEMON_ROTOM_HEAT] = {.pal = gfx_ow_rotom_heatPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_HEAT},
	[POKEMON_ROTOM_GRASS] = {.pal = gfx_ow_rotom_mowPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_GRASS},
	[POKEMON_ROTOM_WASH] = {.pal = gfx_ow_rotom_washPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_WASH},
	[POKEMON_ROTOM_WIND] = {.pal = gfx_ow_rotom_fanPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_WIND},
    [POKEMON_DURENGARD_OFFENSIVE] = {.pal = gfx_ow_durengardaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DURENGARD_OFFENSIVE},
    [POKEMON_FIFFYEN] = {.pal = gfx_ow_fiffyenPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FIFFYEN},
    [POKEMON_MAGNAYEN] = {.pal = gfx_ow_magnayenPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNAYEN},
    [POKEMON_ZIGZACHS] = {.pal = gfx_ow_zigzachsPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZIGZACHS},
    [POKEMON_GERADAKS] = {.pal = gfx_ow_geradaksPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GERADAKS},
    [POKEMON_WAUMPEL] = {.pal = gfx_ow_waumpelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAUMPEL},
    [POKEMON_SCHALOKO] = {.pal = gfx_ow_schalokoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHALOKO},
    [POKEMON_PAPINELLA] = {.pal = gfx_ow_papinellaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PAPINELLA},
    [POKEMON_PANEKON] = {.pal = gfx_ow_panekonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PANEKON},
    [POKEMON_PUDOX] = {.pal = gfx_ow_pudoxPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUDOX},
    [POKEMON_LOTURZEL] = {.pal = gfx_ow_loturzelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LOTURZEL},
    [POKEMON_LOMBRERO] = {.pal = gfx_ow_lombreroPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LOMBRERO},
    [POKEMON_KAPPALORES] = {.pal = gfx_ow_kappaloresPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAPPALORES},
    [POKEMON_SAMURZEL] = {.pal = gfx_ow_samurzelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SAMURZEL},
    [POKEMON_BLANAS] = {.pal = gfx_ow_blanasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BLANAS},
    [POKEMON_TENGULIST] = {.pal = gfx_ow_tengulistPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENGULIST},
    [POKEMON_NINCADA] = {.pal = gfx_ow_nincadaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NINCADA},
    [POKEMON_NINJASK] = {.pal = gfx_ow_ninjaskPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NINJASK},
    [POKEMON_NINJATOM] = {.pal = gfx_ow_ninjatomPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NINJATOM},
    [POKEMON_SCHWALBINI] = {.pal = gfx_ow_schwalbiniPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHWALBINI},
    [POKEMON_SCHWALBOSS] = {.pal = gfx_ow_schwalbossPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHWALBOSS},
    [POKEMON_KNILZ] = {.pal = gfx_ow_knilzPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNILZ},
    [POKEMON_KAPILZ] = {.pal = gfx_ow_kapilzPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAPILZ},
    [POKEMON_PANDIR] = {.pal = gfx_ow_pandirPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PANDIR},
    [POKEMON_WINGULL] = {.pal = gfx_ow_wingullPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WINGULL},
    [POKEMON_PELIPPER] = {.pal = gfx_ow_pelipperPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PELIPPER},
    [POKEMON_GEHWEIHER] = {.pal = gfx_ow_gehweiherPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GEHWEIHER},
    [POKEMON_MASKEREGEN] = {.pal = gfx_ow_maskeregenPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MASKEREGEN},
    [POKEMON_WAILMER] = {.pal = gfx_ow_wailmerPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAILMER},
    [POKEMON_WAILORD] = {.pal = gfx_ow_wailordPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAILORD},
    [POKEMON_ENECO] = {.pal = gfx_ow_enecoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENECO},
    [POKEMON_ENEKORO] = {.pal = gfx_ow_enekoroPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENEKORO},
    [POKEMON_KECLEON] = {.pal = gfx_ow_kecleonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KECLEON},
    [POKEMON_PUPPANCE] = {.pal = gfx_ow_puppancePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUPPANCE},
    [POKEMON_LEPUMENTAS] = {.pal = gfx_ow_lepumentasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEPUMENTAS},
    [POKEMON_NASGNET] = {.pal = gfx_ow_nasgnetPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NASGNET},
    [POKEMON_MAGBRANT] = {.pal = gfx_ow_magbrantPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGBRANT},
    [POKEMON_ZWIRRFINST] = {.pal = gfx_ow_zwirrfinstPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZWIRRFINST},
    [POKEMON_SCHMERBE] = {.pal = gfx_ow_schmerbePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHMERBE},
    [POKEMON_WELSAR] = {.pal = gfx_ow_welsarPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WELSAR},
    [POKEMON_RIHORNIOR] = {.pal = gfx_ow_rihorniorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIHORNIOR},
    [POKEMON_KREBSCORPS] = {.pal = gfx_ow_krebscorpsPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KREBSCORPS},
    [POKEMON_KREBUTACK] = {.pal = gfx_ow_krebutackPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KREBUTACK},
    [POKEMON_BARSCHWA] = {.pal = gfx_ow_barschwaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BARSCHWA},
    [POKEMON_MILOTIC] = {.pal = gfx_ow_miloticPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MILOTIC},
    [POKEMON_KANIVANHA] = {.pal = gfx_ow_kanivanhaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KANIVANHA},
    [POKEMON_TOHAIDO] = {.pal = gfx_ow_tohaidoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOHAIDO},
    [POKEMON_KNACKLION] = {.pal = gfx_ow_knacklionPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNACKLION},
    [POKEMON_VIBRAVA] = {.pal = gfx_ow_vibravaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VIBRAVA},
    [POKEMON_LIBELLDRA] = {.pal = gfx_ow_libelldraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LIBELLDRA},
    [POKEMON_RIOLU] = {.pal = gfx_ow_rioluPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIOLU},
    [POKEMON_LUCARIO] = {.pal = gfx_ow_lucarioPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LUCARIO},
    [POKEMON_FRIZELBLIZ] = {.pal = gfx_ow_frizelblizPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FRIZELBLIZ},
    [POKEMON_VOLTENSO] = {.pal = gfx_ow_voltensoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTENSO},
    [POKEMON_CAMAUB] = {.pal = gfx_ow_camaubPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CAMAUB},
    [POKEMON_CAMERUPT] = {.pal = gfx_ow_cameruptPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CAMERUPT},
    [POKEMON_SEEMOPS] = {.pal = gfx_ow_seemopsPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEMOPS},
    [POKEMON_SEEJONG] = {.pal = gfx_ow_seejongPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEJONG},
    [POKEMON_WALRAISA] = {.pal = gfx_ow_walraisaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WALRAISA},
    [POKEMON_TUSKA] = {.pal = gfx_ow_tuskaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TUSKA},
    [POKEMON_NOKTUSKA] = {.pal = gfx_ow_noktuskaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NOKTUSKA},
    [POKEMON_SCHNEPPKE] = {.pal = gfx_ow_schneppkePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHNEPPKE},
    [POKEMON_FIRNONTOR] = {.pal = gfx_ow_firnontorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FIRNONTOR},
    [POKEMON_LUNASTEIN] = {.pal = gfx_ow_lunasteinPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LUNASTEIN},
    [POKEMON_SONNFEL] = {.pal = gfx_ow_sonnfelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SONNFEL},
    [POKEMON_AZURILL] = {.pal = gfx_ow_azurillPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AZURILL},
    [POKEMON_SPOINK] = {.pal = gfx_ow_spoinkPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SPOINK},
    [POKEMON_GROINK] = {.pal = gfx_ow_groinkPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GROINK},
    [POKEMON_PICHU] = {.pal = gfx_ow_pichuPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PICHU},
    [POKEMON_ROTOM] = {.pal = gfx_ow_rotomPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM},
    [POKEMON_FLUNKIFER] = {.pal = gfx_ow_flunkiferPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLUNKIFER},
    [POKEMON_MEDITIE] = {.pal = gfx_ow_meditiePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEDITIE},
    [POKEMON_MEDITALIS] = {.pal = gfx_ow_meditalisPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEDITALIS},
    [POKEMON_WABLU] = {.pal = gfx_ow_wabluPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WABLU},
    [POKEMON_ALTARIA] = {.pal = gfx_ow_altariaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ALTARIA},
    [POKEMON_KLINGPLIM] = {.pal = gfx_ow_klingplimPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KLINGPLIM},
    [POKEMON_ZWIRRLICHT] = {.pal = gfx_ow_zwirrlichtPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZWIRRLICHT},
    [POKEMON_ZWIRRKLOP] = {.pal = gfx_ow_zwirrklopPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZWIRRKLOP},
    [POKEMON_PORYGON_Z] = {.pal = gfx_ow_porygon_zPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORYGON_Z},
    [POKEMON_BUMMELZ] = {.pal = gfx_ow_bummelzPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BUMMELZ},
    [POKEMON_MUNTIER] = {.pal = gfx_ow_muntierPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MUNTIER},
    [POKEMON_LETARKING] = {.pal = gfx_ow_letarkingPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LETARKING},
    [POKEMON_MOLUNK] = {.pal = gfx_ow_molunkPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MOLUNK},
    [POKEMON_AMFIRA] = {.pal = gfx_ow_amfiraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMFIRA},
    [POKEMON_TROPIUS] = {.pal = gfx_ow_tropiusPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TROPIUS},
    [POKEMON_KAUMALAT] = {.pal = gfx_ow_kaumalatPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAUMALAT},
    [POKEMON_KNARKSEL] = {.pal = gfx_ow_knarkselPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNARKSEL},
    [POKEMON_KNAKRACK] = {.pal = gfx_ow_knakrackPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNAKRACK},
    [POKEMON_PERLU] = {.pal = gfx_ow_perluPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PERLU},
    [POKEMON_AALABYSS] = {.pal = gfx_ow_aalabyssPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AALABYSS},
    [POKEMON_SAGANABYSS] = {.pal = gfx_ow_saganabyssPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SAGANABYSS},
    [POKEMON_ABSOL] = {.pal = gfx_ow_absolPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ABSOL},
    [POKEMON_SHUPPET] = {.pal = gfx_ow_shuppetPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SHUPPET},
    [POKEMON_BANETTE] = {.pal = gfx_ow_banettePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BANETTE},
    [POKEMON_VIPITIS] = {.pal = gfx_ow_vipitisPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VIPITIS},
    [POKEMON_SENGO] = {.pal = gfx_ow_sengoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SENGO},
    [POKEMON_RELICANTH] = {.pal = gfx_ow_relicanthPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RELICANTH},
    [POKEMON_STOLLUNIOR] = {.pal = gfx_ow_stolluniorPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STOLLUNIOR},
    [POKEMON_STOLLRAK] = {.pal = gfx_ow_stollrakPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STOLLRAK},
    [POKEMON_STOLLOSS] = {.pal = gfx_ow_stollossPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STOLLOSS},
    [POKEMON_FORMEO] = {.pal = gfx_ow_formeoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FORMEO},
    [POKEMON_WONNEIRA] = {.pal = gfx_ow_wonneiraPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WONNEIRA},
    [POKEMON_MOBAI] = {.pal = gfx_ow_mobaiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MOBAI},
    [POKEMON_LILIEP] = {.pal = gfx_ow_liliepPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LILIEP},
    [POKEMON_WIELIE] = {.pal = gfx_ow_wieliePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WIELIE},
    [POKEMON_ANORITH] = {.pal = gfx_ow_anorithPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ANORITH},
    [POKEMON_ARMALDO] = {.pal = gfx_ow_armaldoPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARMALDO},
    [POKEMON_TRASLA] = {.pal = gfx_ow_traslaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRASLA},
    [POKEMON_KIRLIA] = {.pal = gfx_ow_kirliaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KIRLIA},
    [POKEMON_GUARDEVOIR] = {.pal = gfx_ow_guardevoirPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GUARDEVOIR},
    [POKEMON_KINDWURM] = {.pal = gfx_ow_kindwurmPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KINDWURM},
    [POKEMON_DRASCHEL] = {.pal = gfx_ow_draschelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRASCHEL},
    [POKEMON_BRUTALANDA] = {.pal = gfx_ow_brutalandaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BRUTALANDA},
    [POKEMON_TANHEL] = {.pal = gfx_ow_tanhelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TANHEL},
    [POKEMON_METANG] = {.pal = gfx_ow_metangPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_METANG},
    [POKEMON_METAGROSS] = {.pal = gfx_ow_metagrossPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_METAGROSS},
    [POKEMON_REGIROCK] = {.pal = gfx_ow_regirockPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REGIROCK},
    [POKEMON_REGICE] = {.pal = gfx_ow_regicePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REGICE},
    [POKEMON_REGISTEEL] = {.pal = gfx_ow_registeelPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REGISTEEL},
    [POKEMON_KYOGRE] = {.pal = gfx_ow_kyogrePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KYOGRE},
    [POKEMON_GROUDON] = {.pal = gfx_ow_groudonPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GROUDON},
    [POKEMON_RAYQUAZA] = {.pal = gfx_ow_rayquazaPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAYQUAZA},
    [POKEMON_LATIAS] = {.pal = gfx_ow_latiasPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LATIAS},
    [POKEMON_LATIOS] = {.pal = gfx_ow_latiosPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LATIOS},
    [POKEMON_JIRACHI] = {.pal = gfx_ow_jirachiPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_JIRACHI},
    [POKEMON_DEOXYS] = {.pal = gfx_ow_deoxysPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DEOXYS},
    [POKEMON_PALIMPALIM] = {.pal = gfx_ow_palimpalimPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PALIMPALIM},
    [POKEMON_ICOGNITO_B] = {.pal = gfx_ow_icognito_bPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_B},
    [POKEMON_ICOGNITO_C] = {.pal = gfx_ow_icognito_cPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_C},
    [POKEMON_ICOGNITO_D] = {.pal = gfx_ow_icognito_dPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_D},
    [POKEMON_ICOGNITO_E] = {.pal = gfx_ow_icognito_ePal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_E},
    [POKEMON_ICOGNITO_F] = {.pal = gfx_ow_icognito_fPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_F},
    [POKEMON_ICOGNITO_G] = {.pal = gfx_ow_icognito_gPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_G},
    [POKEMON_ICOGNITO_H] = {.pal = gfx_ow_icognito_hPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_H},
    [POKEMON_ICOGNITO_I] = {.pal = gfx_ow_icognito_iPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_I},
    [POKEMON_ICOGNITO_J] = {.pal = gfx_ow_icognito_jPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_J},
    [POKEMON_ICOGNITO_K] = {.pal = gfx_ow_icognito_kPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_K},
    [POKEMON_ICOGNITO_L] = {.pal = gfx_ow_icognito_lPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_L},
    [POKEMON_ICOGNITO_M] = {.pal = gfx_ow_icognito_mPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_M},
    [POKEMON_ICOGNITO_N] = {.pal = gfx_ow_icognito_nPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_N},
    [POKEMON_ICOGNITO_O] = {.pal = gfx_ow_icognito_oPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_O},
    [POKEMON_ICOGNITO_P] = {.pal = gfx_ow_icognito_pPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_P},
    [POKEMON_ICOGNITO_Q] = {.pal = gfx_ow_icognito_qPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_Q},
    [POKEMON_ICOGNITO_R] = {.pal = gfx_ow_icognito_rPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_R},
    [POKEMON_ICOGNITO_S] = {.pal = gfx_ow_icognito_sPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_S},
    [POKEMON_ICOGNITO_T] = {.pal = gfx_ow_icognito_tPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_T},
    [POKEMON_ICOGNITO_U] = {.pal = gfx_ow_icognito_uPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_U},
    [POKEMON_ICOGNITO_V] = {.pal = gfx_ow_icognito_vPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_V},
    [POKEMON_ICOGNITO_W] = {.pal = gfx_ow_icognito_wPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_W},
    [POKEMON_ICOGNITO_X] = {.pal = gfx_ow_icognito_xPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_X},
    [POKEMON_ICOGNITO_Y] = {.pal = gfx_ow_icognito_yPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_Y},
    [POKEMON_ICOGNITO_Z] = {.pal = gfx_ow_icognito_zPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_Z},
    [POKEMON_ICOGNITO_EXCLAMATION] = {.pal = gfx_ow_icognito_exclamationPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_EXCLAMATION},
    [POKEMON_ICOGNITO_QUESTION] = {.pal = gfx_ow_icognito_questionPal, .tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_QUESTION},
};

static graphic overworld_gfxs_bisasam[] = {
	[0] = {.sprite = gfx_ow_bisasamTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_bisasamTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_bisasamTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_bisasamTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_bisasamTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_bisasamTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_bisasamTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_bisasamTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_bisasamTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_bisaknosp[] = {
	[0] = {.sprite = gfx_ow_bisaknospTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_bisaknospTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_bisaknospTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_bisaknospTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_bisaknospTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_bisaknospTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_bisaknospTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_bisaknospTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_bisaknospTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_bisaflor[] = {
	[0] = {.sprite = gfx_ow_bisaflorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_bisaflorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_bisaflorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_bisaflorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_bisaflorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_bisaflorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_bisaflorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_bisaflorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_bisaflorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_glumanda[] = {
	[0] = {.sprite = gfx_ow_glumandaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_glumandaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_glumandaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_glumandaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_glumandaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_glumandaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_glumandaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_glumandaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_glumandaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_glutexo[] = {
	[0] = {.sprite = gfx_ow_glutexoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_glutexoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_glutexoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_glutexoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_glutexoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_glutexoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_glutexoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_glutexoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_glutexoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_glurak[] = {
	[0] = {.sprite = gfx_ow_glurakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_glurakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_glurakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_glurakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_glurakTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_glurakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_glurakTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_glurakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_glurakTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schiggy[] = {
	[0] = {.sprite = gfx_ow_schiggyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schiggyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schiggyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schiggyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schiggyTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schiggyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schiggyTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schiggyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schiggyTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schillok[] = {
	[0] = {.sprite = gfx_ow_schillokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schillokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schillokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schillokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schillokTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schillokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schillokTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schillokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schillokTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_turtok[] = {
	[0] = {.sprite = gfx_ow_turtokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_turtokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_turtokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_turtokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_turtokTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_turtokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_turtokTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_turtokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_turtokTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dartiri[] = {
	[0] = {.sprite = gfx_ow_dartiriTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dartiriTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dartiriTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dartiriTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dartiriTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dartiriTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dartiriTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dartiriTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dartiriTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dartignis[] = {
	[0] = {.sprite = gfx_ow_dartignisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dartignisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dartignisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dartignisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dartignisTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dartignisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dartignisTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dartignisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dartignisTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_fiaro[] = {
	[0] = {.sprite = gfx_ow_fiaroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_fiaroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_fiaroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_fiaroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_fiaroTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_fiaroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_fiaroTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_fiaroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_fiaroTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_hornliu[] = {
	[0] = {.sprite = gfx_ow_hornliuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_hornliuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_hornliuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_hornliuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_hornliuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_hornliuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_hornliuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_hornliuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_hornliuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kokuna[] = {
	[0] = {.sprite = gfx_ow_kokunaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kokunaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kokunaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kokunaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kokunaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kokunaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kokunaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kokunaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kokunaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_bibor[] = {
	[0] = {.sprite = gfx_ow_biborTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_biborTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_biborTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_biborTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_biborTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_biborTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_biborTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_biborTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_biborTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_staralili[] = {
	[0] = {.sprite = gfx_ow_staraliliTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_staraliliTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_staraliliTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_staraliliTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_staraliliTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_staraliliTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_staraliliTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_staraliliTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_staraliliTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_staravia[] = {
	[0] = {.sprite = gfx_ow_staraviaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_staraviaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_staraviaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_staraviaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_staraviaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_staraviaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_staraviaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_staraviaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_staraviaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_staraptor[] = {
	[0] = {.sprite = gfx_ow_staraptorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_staraptorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_staraptorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_staraptorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_staraptorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_staraptorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_staraptorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_staraptorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_staraptorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_bronzel[] = {
	[0] = {.sprite = gfx_ow_bronzelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_bronzelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_bronzelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_bronzelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_bronzelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_bronzelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_bronzelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_bronzelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_bronzelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_bronzong[] = {
	[0] = {.sprite = gfx_ow_bronzongTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_bronzongTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_bronzongTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_bronzongTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_bronzongTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_bronzongTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_bronzongTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_bronzongTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_bronzongTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_maehikel[] = {
	[0] = {.sprite = gfx_ow_maehikelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_maehikelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_maehikelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_maehikelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_maehikelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_maehikelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_maehikelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_maehikelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_maehikelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_chevrumm[] = {
	[0] = {.sprite = gfx_ow_chevrummTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_chevrummTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_chevrummTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_chevrummTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_chevrummTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_chevrummTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_chevrummTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_chevrummTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_chevrummTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_paragoni[] = {
	[0] = {.sprite = gfx_ow_paragoniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_paragoniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_paragoniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_paragoniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_paragoniTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_paragoniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_paragoniTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_paragoniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_paragoniTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_trombork[] = {
	[0] = {.sprite = gfx_ow_tromborkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tromborkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tromborkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tromborkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tromborkTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tromborkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tromborkTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tromborkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tromborkTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pikachu[] = {
	[0] = {.sprite = gfx_ow_pikachuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pikachuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pikachuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pikachuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pikachuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pikachuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pikachuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pikachuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pikachuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_raichu[] = {
	[0] = {.sprite = gfx_ow_raichuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_raichuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_raichuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_raichuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_raichuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_raichuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_raichuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_raichuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_raichuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sandan[] = {
	[0] = {.sprite = gfx_ow_sandanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sandanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sandanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sandanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sandanTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sandanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sandanTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sandanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sandanTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sandamer[] = {
	[0] = {.sprite = gfx_ow_sandamerTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sandamerTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sandamerTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sandamerTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sandamerTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sandamerTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sandamerTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sandamerTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sandamerTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nidoranw[] = {
	[0] = {.sprite = gfx_ow_nidoranwTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nidoranwTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nidoranwTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nidoranwTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nidoranwTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nidoranwTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nidoranwTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nidoranwTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nidoranwTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nidorina[] = {
	[0] = {.sprite = gfx_ow_nidorinaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nidorinaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nidorinaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nidorinaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nidorinaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nidorinaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nidorinaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nidorinaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nidorinaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nidoqueen[] = {
	[0] = {.sprite = gfx_ow_nidoqueenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nidoqueenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nidoqueenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nidoqueenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nidoqueenTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nidoqueenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nidoqueenTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nidoqueenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nidoqueenTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nidoranm[] = {
	[0] = {.sprite = gfx_ow_nidoranmTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nidoranmTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nidoranmTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nidoranmTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nidoranmTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nidoranmTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nidoranmTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nidoranmTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nidoranmTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nidorino[] = {
	[0] = {.sprite = gfx_ow_nidorinoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nidorinoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nidorinoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nidorinoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nidorinoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nidorinoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nidorinoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nidorinoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nidorinoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nidoking[] = {
	[0] = {.sprite = gfx_ow_nidokingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nidokingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nidokingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nidokingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nidokingTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nidokingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nidokingTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nidokingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nidokingTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_floette[] = {
	[0] = {.sprite = gfx_ow_floetteTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_floetteTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_floetteTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_floetteTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_floetteTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_floetteTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_floetteTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_floetteTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_floetteTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_florges[] = {
	[0] = {.sprite = gfx_ow_florgesTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_florgesTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_florgesTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_florgesTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_florgesTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_florgesTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_florgesTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_florgesTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_florgesTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_vulpix[] = {
	[0] = {.sprite = gfx_ow_vulpixTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_vulpixTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_vulpixTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_vulpixTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_vulpixTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_vulpixTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_vulpixTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_vulpixTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_vulpixTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_vulnona[] = {
	[0] = {.sprite = gfx_ow_vulnonaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_vulnonaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_vulnonaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_vulnonaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_vulnonaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_vulnonaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_vulnonaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_vulnonaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_vulnonaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pummeluff[] = {
	[0] = {.sprite = gfx_ow_pummeluffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pummeluffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pummeluffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pummeluffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pummeluffTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pummeluffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pummeluffTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pummeluffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pummeluffTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knuddeluff[] = {
	[0] = {.sprite = gfx_ow_knuddeluffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knuddeluffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knuddeluffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knuddeluffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knuddeluffTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knuddeluffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knuddeluffTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knuddeluffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knuddeluffTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zubat[] = {
	[0] = {.sprite = gfx_ow_zubatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zubatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zubatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zubatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zubatTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zubatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zubatTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zubatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zubatTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_golbat[] = {
	[0] = {.sprite = gfx_ow_golbatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_golbatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_golbatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_golbatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_golbatTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_golbatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_golbatTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_golbatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_golbatTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_myrapla[] = {
	[0] = {.sprite = gfx_ow_myraplaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_myraplaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_myraplaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_myraplaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_myraplaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_myraplaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_myraplaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_myraplaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_myraplaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_duflor[] = {
	[0] = {.sprite = gfx_ow_duflorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_duflorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_duflorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_duflorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_duflorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_duflorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_duflorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_duflorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_duflorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_giflor[] = {
	[0] = {.sprite = gfx_ow_giflorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_giflorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_giflorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_giflorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_giflorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_giflorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_giflorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_giflorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_giflorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_folipurba[] = {
	[0] = {.sprite = gfx_ow_folipurbaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_folipurbaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_folipurbaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_folipurbaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_folipurbaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_folipurbaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_folipurbaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_folipurbaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_folipurbaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_feelinara[] = {
	[0] = {.sprite = gfx_ow_feelinaraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_feelinaraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_feelinaraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_feelinaraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_feelinaraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_feelinaraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_feelinaraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_feelinaraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_feelinaraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wattzapf[] = {
	[0] = {.sprite = gfx_ow_wattzapfTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wattzapfTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wattzapfTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wattzapfTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wattzapfTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wattzapfTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wattzapfTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wattzapfTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wattzapfTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_voltula[] = {
	[0] = {.sprite = gfx_ow_voltulaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_voltulaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_voltulaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_voltulaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_voltulaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_voltulaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_voltulaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_voltulaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_voltulaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_digda[] = {
	[0] = {.sprite = gfx_ow_digdaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_digdaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_digdaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_digdaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_digdaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_digdaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_digdaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_digdaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_digdaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_digdri[] = {
	[0] = {.sprite = gfx_ow_digdriTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_digdriTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_digdriTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_digdriTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_digdriTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_digdriTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_digdriTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_digdriTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_digdriTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kastadur[] = {
	[0] = {.sprite = gfx_ow_kastadurTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kastadurTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kastadurTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kastadurTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kastadurTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kastadurTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kastadurTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kastadurTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kastadurTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tentantel[] = {
	[0] = {.sprite = gfx_ow_tentantelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tentantelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tentantelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tentantelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tentantelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tentantelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tentantelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tentantelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tentantelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_enton[] = {
	[0] = {.sprite = gfx_ow_entonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_entonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_entonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_entonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_entonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_entonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_entonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_entonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_entonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_entoron[] = {
	[0] = {.sprite = gfx_ow_entoronTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_entoronTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_entoronTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_entoronTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_entoronTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_entoronTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_entoronTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_entoronTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_entoronTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_menki[] = {
	[0] = {.sprite = gfx_ow_menkiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_menkiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_menkiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_menkiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_menkiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_menkiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_menkiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_menkiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_menkiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rasaff[] = {
	[0] = {.sprite = gfx_ow_rasaffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rasaffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rasaffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rasaffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rasaffTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rasaffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rasaffTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rasaffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rasaffTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_fukano[] = {
	[0] = {.sprite = gfx_ow_fukanoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_fukanoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_fukanoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_fukanoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_fukanoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_fukanoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_fukanoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_fukanoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_fukanoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_arkani[] = {
	[0] = {.sprite = gfx_ow_arkaniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_arkaniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_arkaniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_arkaniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_arkaniTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_arkaniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_arkaniTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_arkaniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_arkaniTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_gramokles[] = {
	[0] = {.sprite = gfx_ow_gramoklesTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_gramoklesTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_gramoklesTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_gramoklesTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_gramoklesTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_gramoklesTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_gramoklesTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_gramoklesTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_gramoklesTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_duokles[] = {
	[0] = {.sprite = gfx_ow_duoklesTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_duoklesTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_duoklesTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_duoklesTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_duoklesTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_duoklesTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_duoklesTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_duoklesTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_duoklesTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_durengard[] = {
	[0] = {.sprite = gfx_ow_durengardTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_durengardTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_durengardTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_durengardTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_durengardTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_durengardTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_durengardTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_durengardTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_durengardTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_abra[] = {
	[0] = {.sprite = gfx_ow_abraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_abraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_abraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_abraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_abraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_abraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_abraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_abraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_abraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kadabra[] = {
	[0] = {.sprite = gfx_ow_kadabraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kadabraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kadabraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kadabraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kadabraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kadabraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kadabraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kadabraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kadabraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_simsala[] = {
	[0] = {.sprite = gfx_ow_simsalaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_simsalaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_simsalaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_simsalaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_simsalaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_simsalaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_simsalaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_simsalaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_simsalaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_machollo[] = {
	[0] = {.sprite = gfx_ow_macholloTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_macholloTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_macholloTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_macholloTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_macholloTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_macholloTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_macholloTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_macholloTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_macholloTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_maschock[] = {
	[0] = {.sprite = gfx_ow_maschockTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_maschockTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_maschockTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_maschockTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_maschockTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_maschockTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_maschockTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_maschockTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_maschockTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_machomei[] = {
	[0] = {.sprite = gfx_ow_machomeiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_machomeiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_machomeiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_machomeiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_machomeiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_machomeiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_machomeiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_machomeiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_machomeiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knofensa[] = {
	[0] = {.sprite = gfx_ow_knofensaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knofensaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knofensaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knofensaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knofensaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knofensaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knofensaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knofensaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knofensaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ultrigaria[] = {
	[0] = {.sprite = gfx_ow_ultrigariaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ultrigariaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ultrigariaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ultrigariaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ultrigariaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ultrigariaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ultrigariaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ultrigariaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ultrigariaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sarzenia[] = {
	[0] = {.sprite = gfx_ow_sarzeniaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sarzeniaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sarzeniaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sarzeniaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sarzeniaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sarzeniaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sarzeniaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sarzeniaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sarzeniaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tentacha[] = {
	[0] = {.sprite = gfx_ow_tentachaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tentachaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tentachaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tentachaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tentachaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tentachaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tentachaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tentachaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tentachaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tentoxa[] = {
	[0] = {.sprite = gfx_ow_tentoxaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tentoxaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tentoxaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tentoxaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tentoxaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tentoxaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tentoxaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tentoxaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tentoxaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kleinstein[] = {
	[0] = {.sprite = gfx_ow_kleinsteinTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kleinsteinTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kleinsteinTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kleinsteinTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kleinsteinTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kleinsteinTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kleinsteinTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kleinsteinTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kleinsteinTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_georok[] = {
	[0] = {.sprite = gfx_ow_georokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_georokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_georokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_georokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_georokTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_georokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_georokTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_georokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_georokTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_geowaz[] = {
	[0] = {.sprite = gfx_ow_geowazTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_geowazTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_geowazTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_geowazTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_geowazTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_geowazTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_geowazTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_geowazTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_geowazTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ponita[] = {
	[0] = {.sprite = gfx_ow_ponitaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ponitaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ponitaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ponitaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ponitaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ponitaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ponitaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ponitaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ponitaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_gallopa[] = {
	[0] = {.sprite = gfx_ow_gallopaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_gallopaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_gallopaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_gallopaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_gallopaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_gallopaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_gallopaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_gallopaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_gallopaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_flegmon[] = {
	[0] = {.sprite = gfx_ow_flegmonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_flegmonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_flegmonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_flegmonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_flegmonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_flegmonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_flegmonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_flegmonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_flegmonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lahmus[] = {
	[0] = {.sprite = gfx_ow_lahmusTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lahmusTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lahmusTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lahmusTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lahmusTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lahmusTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lahmusTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lahmusTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lahmusTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magnetilo[] = {
	[0] = {.sprite = gfx_ow_magnetiloTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magnetiloTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magnetiloTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magnetiloTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magnetiloTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magnetiloTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magnetiloTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magnetiloTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magnetiloTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magneton[] = {
	[0] = {.sprite = gfx_ow_magnetonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magnetonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magnetonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magnetonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magnetonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magnetonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magnetonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magnetonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magnetonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_porenta[] = {
	[0] = {.sprite = gfx_ow_porentaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_porentaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_porentaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_porentaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_porentaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_porentaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_porentaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_porentaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_porentaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dodu[] = {
	[0] = {.sprite = gfx_ow_doduTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_doduTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_doduTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_doduTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_doduTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_doduTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_doduTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_doduTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_doduTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dodri[] = {
	[0] = {.sprite = gfx_ow_dodriTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dodriTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dodriTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dodriTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dodriTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dodriTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dodriTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dodriTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dodriTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_jurob[] = {
	[0] = {.sprite = gfx_ow_jurobTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_jurobTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_jurobTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_jurobTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_jurobTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_jurobTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_jurobTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_jurobTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_jurobTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_jugong[] = {
	[0] = {.sprite = gfx_ow_jugongTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_jugongTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_jugongTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_jugongTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_jugongTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_jugongTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_jugongTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_jugongTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_jugongTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sleima[] = {
	[0] = {.sprite = gfx_ow_sleimaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sleimaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sleimaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sleimaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sleimaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sleimaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sleimaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sleimaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sleimaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sleimok[] = {
	[0] = {.sprite = gfx_ow_sleimokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sleimokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sleimokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sleimokTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sleimokTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sleimokTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sleimokTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sleimokTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sleimokTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_muschas[] = {
	[0] = {.sprite = gfx_ow_muschasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_muschasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_muschasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_muschasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_muschasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_muschasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_muschasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_muschasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_muschasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_austos[] = {
	[0] = {.sprite = gfx_ow_austosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_austosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_austosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_austosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_austosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_austosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_austosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_austosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_austosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nebulak[] = {
	[0] = {.sprite = gfx_ow_nebulakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nebulakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nebulakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nebulakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nebulakTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nebulakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nebulakTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nebulakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nebulakTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_alpollo[] = {
	[0] = {.sprite = gfx_ow_alpolloTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_alpolloTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_alpolloTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_alpolloTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_alpolloTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_alpolloTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_alpolloTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_alpolloTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_alpolloTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_gengar[] = {
	[0] = {.sprite = gfx_ow_gengarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_gengarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_gengarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_gengarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_gengarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_gengarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_gengarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_gengarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_gengarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_onix[] = {
	[0] = {.sprite = gfx_ow_onixTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_onixTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_onixTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_onixTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_onixTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_onixTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_onixTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_onixTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_onixTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_traumato[] = {
	[0] = {.sprite = gfx_ow_traumatoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_traumatoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_traumatoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_traumatoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_traumatoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_traumatoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_traumatoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_traumatoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_traumatoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_hypno[] = {
	[0] = {.sprite = gfx_ow_hypnoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_hypnoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_hypnoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_hypnoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_hypnoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_hypnoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_hypnoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_hypnoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_hypnoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_krabby[] = {
	[0] = {.sprite = gfx_ow_krabbyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_krabbyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_krabbyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_krabbyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_krabbyTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_krabbyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_krabbyTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_krabbyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_krabbyTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kingler[] = {
	[0] = {.sprite = gfx_ow_kinglerTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kinglerTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kinglerTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kinglerTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kinglerTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kinglerTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kinglerTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kinglerTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kinglerTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_voltobal[] = {
	[0] = {.sprite = gfx_ow_voltobalTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_voltobalTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_voltobalTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_voltobalTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_voltobalTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_voltobalTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_voltobalTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_voltobalTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_voltobalTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lektrobal[] = {
	[0] = {.sprite = gfx_ow_lektrobalTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lektrobalTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lektrobalTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lektrobalTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lektrobalTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lektrobalTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lektrobalTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lektrobalTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lektrobalTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_owei[] = {
	[0] = {.sprite = gfx_ow_oweiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_oweiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_oweiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_oweiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_oweiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_oweiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_oweiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_oweiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_oweiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kokowei[] = {
	[0] = {.sprite = gfx_ow_kokoweiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kokoweiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kokoweiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kokoweiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kokoweiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kokoweiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kokoweiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kokoweiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kokoweiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tragosso[] = {
	[0] = {.sprite = gfx_ow_tragossoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tragossoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tragossoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tragossoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tragossoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tragossoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tragossoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tragossoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tragossoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knogga[] = {
	[0] = {.sprite = gfx_ow_knoggaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knoggaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knoggaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knoggaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knoggaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knoggaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knoggaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knoggaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knoggaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kicklee[] = {
	[0] = {.sprite = gfx_ow_kickleeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kickleeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kickleeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kickleeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kickleeTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kickleeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kickleeTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kickleeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kickleeTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nockchan[] = {
	[0] = {.sprite = gfx_ow_nockchanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nockchanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nockchanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nockchanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nockchanTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nockchanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nockchanTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nockchanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nockchanTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schlurp[] = {
	[0] = {.sprite = gfx_ow_schlurpTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schlurpTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schlurpTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schlurpTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schlurpTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schlurpTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schlurpTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schlurpTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schlurpTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_smogon[] = {
	[0] = {.sprite = gfx_ow_smogonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_smogonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_smogonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_smogonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_smogonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_smogonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_smogonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_smogonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_smogonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_smogmog[] = {
	[0] = {.sprite = gfx_ow_smogmogTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_smogmogTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_smogmogTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_smogmogTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_smogmogTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_smogmogTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_smogmogTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_smogmogTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_smogmogTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rihorn[] = {
	[0] = {.sprite = gfx_ow_rihornTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rihornTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rihornTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rihornTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rihornTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rihornTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rihornTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rihornTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rihornTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rizeros[] = {
	[0] = {.sprite = gfx_ow_rizerosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rizerosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rizerosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rizerosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rizerosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rizerosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rizerosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rizerosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rizerosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_chaneira[] = {
	[0] = {.sprite = gfx_ow_chaneiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_chaneiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_chaneiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_chaneiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_chaneiraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_chaneiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_chaneiraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_chaneiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_chaneiraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zobiris[] = {
	[0] = {.sprite = gfx_ow_zobirisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zobirisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zobirisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zobirisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zobirisTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zobirisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zobirisTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zobirisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zobirisTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kangama[] = {
	[0] = {.sprite = gfx_ow_kangamaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kangamaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kangamaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kangamaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kangamaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kangamaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kangamaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kangamaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kangamaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_seeper[] = {
	[0] = {.sprite = gfx_ow_seeperTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_seeperTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_seeperTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_seeperTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_seeperTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_seeperTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_seeperTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_seeperTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_seeperTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_seemon[] = {
	[0] = {.sprite = gfx_ow_seemonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_seemonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_seemonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_seemonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_seemonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_seemonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_seemonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_seemonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_seemonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_quabbel[] = {
	[0] = {.sprite = gfx_ow_quabbelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_quabbelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_quabbelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_quabbelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_quabbelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_quabbelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_quabbelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_quabbelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_quabbelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_apoquallyp[] = {
	[0] = {.sprite = gfx_ow_apoquallypTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_apoquallypTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_apoquallypTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_apoquallypTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_apoquallypTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_apoquallypTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_apoquallypTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_apoquallypTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_apoquallypTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sterndu[] = {
	[0] = {.sprite = gfx_ow_sternduTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sternduTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sternduTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sternduTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sternduTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sternduTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sternduTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sternduTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sternduTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_starmie[] = {
	[0] = {.sprite = gfx_ow_starmieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_starmieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_starmieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_starmieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_starmieTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_starmieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_starmieTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_starmieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_starmieTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_traunfugil[] = {
	[0] = {.sprite = gfx_ow_traunfugilTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_traunfugilTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_traunfugilTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_traunfugilTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_traunfugilTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_traunfugilTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_traunfugilTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_traunfugilTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_traunfugilTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sichlor[] = {
	[0] = {.sprite = gfx_ow_sichlorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sichlorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sichlorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sichlorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sichlorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sichlorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sichlorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sichlorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sichlorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_galagladi[] = {
	[0] = {.sprite = gfx_ow_galagladiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_galagladiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_galagladiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_galagladiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_galagladiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_galagladiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_galagladiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_galagladiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_galagladiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_elektek[] = {
	[0] = {.sprite = gfx_ow_elektekTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_elektekTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_elektekTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_elektekTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_elektekTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_elektekTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_elektekTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_elektekTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_elektekTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magmar[] = {
	[0] = {.sprite = gfx_ow_magmarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magmarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magmarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magmarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magmarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magmarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magmarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magmarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magmarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pinsir[] = {
	[0] = {.sprite = gfx_ow_pinsirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pinsirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pinsirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pinsirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pinsirTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pinsirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pinsirTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pinsirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pinsirTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tauros[] = {
	[0] = {.sprite = gfx_ow_taurosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_taurosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_taurosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_taurosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_taurosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_taurosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_taurosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_taurosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_taurosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_karpador[] = {
	[0] = {.sprite = gfx_ow_karpadorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_karpadorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_karpadorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_karpadorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_karpadorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_karpadorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_karpadorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_karpadorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_karpadorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_garados[] = {
	[0] = {.sprite = gfx_ow_garadosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_garadosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_garadosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_garadosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_garadosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_garadosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_garadosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_garadosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_garadosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lapras[] = {
	[0] = {.sprite = gfx_ow_laprasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_laprasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_laprasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_laprasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_laprasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_laprasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_laprasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_laprasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_laprasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ditto[] = {
	[0] = {.sprite = gfx_ow_dittoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dittoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dittoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dittoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dittoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dittoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dittoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dittoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dittoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_evoli[] = {
	[0] = {.sprite = gfx_ow_evoliTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_evoliTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_evoliTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_evoliTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_evoliTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_evoliTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_evoliTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_evoliTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_evoliTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_aquana[] = {
	[0] = {.sprite = gfx_ow_aquanaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_aquanaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_aquanaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_aquanaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_aquanaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_aquanaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_aquanaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_aquanaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_aquanaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_blitza[] = {
	[0] = {.sprite = gfx_ow_blitzaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_blitzaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_blitzaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_blitzaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_blitzaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_blitzaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_blitzaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_blitzaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_blitzaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_flamara[] = {
	[0] = {.sprite = gfx_ow_flamaraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_flamaraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_flamaraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_flamaraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_flamaraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_flamaraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_flamaraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_flamaraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_flamaraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_porygon[] = {
	[0] = {.sprite = gfx_ow_porygonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_porygonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_porygonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_porygonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_porygonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_porygonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_porygonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_porygonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_porygonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_amonitas[] = {
	[0] = {.sprite = gfx_ow_amonitasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_amonitasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_amonitasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_amonitasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_amonitasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_amonitasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_amonitasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_amonitasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_amonitasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_amoroso[] = {
	[0] = {.sprite = gfx_ow_amorosoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_amorosoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_amorosoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_amorosoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_amorosoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_amorosoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_amorosoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_amorosoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_amorosoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kabuto[] = {
	[0] = {.sprite = gfx_ow_kabutoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kabutoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kabutoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kabutoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kabutoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kabutoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kabutoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kabutoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kabutoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kabutops[] = {
	[0] = {.sprite = gfx_ow_kabutopsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kabutopsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kabutopsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kabutopsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kabutopsTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kabutopsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kabutopsTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kabutopsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kabutopsTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_aerodactyl[] = {
	[0] = {.sprite = gfx_ow_aerodactylTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_aerodactylTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_aerodactylTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_aerodactylTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_aerodactylTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_aerodactylTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_aerodactylTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_aerodactylTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_aerodactylTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_relaxo[] = {
	[0] = {.sprite = gfx_ow_relaxoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_relaxoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_relaxoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_relaxoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_relaxoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_relaxoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_relaxoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_relaxoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_relaxoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_arktos[] = {
	[0] = {.sprite = gfx_ow_arktosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_arktosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_arktosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_arktosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_arktosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_arktosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_arktosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_arktosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_arktosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zapdos[] = {
	[0] = {.sprite = gfx_ow_zapdosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zapdosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zapdosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zapdosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zapdosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zapdosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zapdosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zapdosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zapdosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lavados[] = {
	[0] = {.sprite = gfx_ow_lavadosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lavadosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lavadosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lavadosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lavadosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lavadosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lavadosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lavadosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lavadosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dratini[] = {
	[0] = {.sprite = gfx_ow_dratiniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dratiniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dratiniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dratiniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dratiniTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dratiniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dratiniTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dratiniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dratiniTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dragonir[] = {
	[0] = {.sprite = gfx_ow_dragonirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dragonirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dragonirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dragonirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dragonirTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dragonirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dragonirTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dragonirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dragonirTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_dragoran[] = {
	[0] = {.sprite = gfx_ow_dragoranTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_dragoranTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_dragoranTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_dragoranTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_dragoranTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_dragoranTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_dragoranTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_dragoranTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_dragoranTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_mewtu[] = {
	[0] = {.sprite = gfx_ow_mewtuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_mewtuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_mewtuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_mewtuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_mewtuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_mewtuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_mewtuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_mewtuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_mewtuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_mew[] = {
	[0] = {.sprite = gfx_ow_mewTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_mewTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_mewTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_mewTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_mewTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_mewTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_mewTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_mewTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_mewTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_endivie[] = {
	[0] = {.sprite = gfx_ow_endivieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_endivieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_endivieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_endivieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_endivieTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_endivieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_endivieTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_endivieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_endivieTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lorblatt[] = {
	[0] = {.sprite = gfx_ow_lorblattTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lorblattTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lorblattTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lorblattTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lorblattTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lorblattTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lorblattTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lorblattTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lorblattTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_meganie[] = {
	[0] = {.sprite = gfx_ow_meganieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_meganieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_meganieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_meganieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_meganieTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_meganieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_meganieTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_meganieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_meganieTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_feurigel[] = {
	[0] = {.sprite = gfx_ow_feurigelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_feurigelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_feurigelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_feurigelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_feurigelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_feurigelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_feurigelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_feurigelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_feurigelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_igelavar[] = {
	[0] = {.sprite = gfx_ow_igelavarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_igelavarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_igelavarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_igelavarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_igelavarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_igelavarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_igelavarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_igelavarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_igelavarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tornupto[] = {
	[0] = {.sprite = gfx_ow_tornuptoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tornuptoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tornuptoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tornuptoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tornuptoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tornuptoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tornuptoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tornuptoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tornuptoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_karnimani[] = {
	[0] = {.sprite = gfx_ow_karnimaniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_karnimaniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_karnimaniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_karnimaniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_karnimaniTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_karnimaniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_karnimaniTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_karnimaniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_karnimaniTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tyracroc[] = {
	[0] = {.sprite = gfx_ow_tyracrocTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tyracrocTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tyracrocTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tyracrocTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tyracrocTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tyracrocTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tyracrocTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tyracrocTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tyracrocTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_impergator[] = {
	[0] = {.sprite = gfx_ow_impergatorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_impergatorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_impergatorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_impergatorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_impergatorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_impergatorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_impergatorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_impergatorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_impergatorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ignivor[] = {
	[0] = {.sprite = gfx_ow_ignivorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ignivorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ignivorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ignivorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ignivorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ignivorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ignivorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ignivorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ignivorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ramoth[] = {
	[0] = {.sprite = gfx_ow_ramothTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ramothTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ramothTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ramothTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ramothTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ramothTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ramothTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ramothTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ramothTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_glaziola[] = {
	[0] = {.sprite = gfx_ow_glaziolaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_glaziolaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_glaziolaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_glaziolaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_glaziolaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_glaziolaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_glaziolaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_glaziolaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_glaziolaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_resladero[] = {
	[0] = {.sprite = gfx_ow_resladeroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_resladeroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_resladeroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_resladeroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_resladeroTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_resladeroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_resladeroTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_resladeroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_resladeroTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ledyba[] = {
	[0] = {.sprite = gfx_ow_ledybaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ledybaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ledybaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ledybaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ledybaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ledybaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ledybaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ledybaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ledybaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ledian[] = {
	[0] = {.sprite = gfx_ow_ledianTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ledianTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ledianTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ledianTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ledianTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ledianTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ledianTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ledianTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ledianTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_webarak[] = {
	[0] = {.sprite = gfx_ow_webarakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_webarakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_webarakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_webarakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_webarakTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_webarakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_webarakTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_webarakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_webarakTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ariados[] = {
	[0] = {.sprite = gfx_ow_ariadosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ariadosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ariadosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ariadosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ariadosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ariadosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ariadosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ariadosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ariadosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_iksbat[] = {
	[0] = {.sprite = gfx_ow_iksbatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_iksbatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_iksbatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_iksbatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_iksbatTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_iksbatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_iksbatTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_iksbatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_iksbatTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lampi[] = {
	[0] = {.sprite = gfx_ow_lampiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lampiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lampiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lampiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lampiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lampiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lampiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lampiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lampiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lanturn[] = {
	[0] = {.sprite = gfx_ow_lanturnTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lanturnTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lanturnTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lanturnTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lanturnTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lanturnTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lanturnTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lanturnTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lanturnTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magnezone[] = {
	[0] = {.sprite = gfx_ow_magnezoneTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magnezoneTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magnezoneTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magnezoneTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magnezoneTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magnezoneTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magnezoneTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magnezoneTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magnezoneTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_togekiss[] = {
	[0] = {.sprite = gfx_ow_togekissTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_togekissTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_togekissTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_togekissTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_togekissTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_togekissTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_togekissTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_togekissTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_togekissTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_flabebe[] = {
	[0] = {.sprite = gfx_ow_flabebeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_flabebeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_flabebeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_flabebeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_flabebeTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_flabebeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_flabebeTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_flabebeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_flabebeTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_togepi[] = {
	[0] = {.sprite = gfx_ow_togepiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_togepiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_togepiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_togepiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_togepiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_togepiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_togepiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_togepiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_togepiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_togetic[] = {
	[0] = {.sprite = gfx_ow_togeticTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_togeticTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_togeticTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_togeticTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_togeticTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_togeticTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_togeticTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_togeticTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_togeticTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_natu[] = {
	[0] = {.sprite = gfx_ow_natuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_natuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_natuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_natuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_natuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_natuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_natuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_natuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_natuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_xatu[] = {
	[0] = {.sprite = gfx_ow_xatuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_xatuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_xatuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_xatuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_xatuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_xatuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_xatuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_xatuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_xatuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_voltilamm[] = {
	[0] = {.sprite = gfx_ow_voltilammTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_voltilammTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_voltilammTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_voltilammTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_voltilammTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_voltilammTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_voltilammTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_voltilammTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_voltilammTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_waaty[] = {
	[0] = {.sprite = gfx_ow_waatyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_waatyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_waatyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_waatyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_waatyTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_waatyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_waatyTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_waatyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_waatyTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ampharos[] = {
	[0] = {.sprite = gfx_ow_ampharosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ampharosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ampharosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ampharosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ampharosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ampharosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ampharosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ampharosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ampharosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_blubella[] = {
	[0] = {.sprite = gfx_ow_blubellaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_blubellaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_blubellaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_blubellaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_blubellaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_blubellaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_blubellaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_blubellaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_blubellaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_marill[] = {
	[0] = {.sprite = gfx_ow_marillTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_marillTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_marillTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_marillTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_marillTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_marillTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_marillTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_marillTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_marillTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_azumarill[] = {
	[0] = {.sprite = gfx_ow_azumarillTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_azumarillTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_azumarillTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_azumarillTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_azumarillTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_azumarillTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_azumarillTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_azumarillTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_azumarillTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_mogelbaum[] = {
	[0] = {.sprite = gfx_ow_mogelbaumTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_mogelbaumTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_mogelbaumTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_mogelbaumTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_mogelbaumTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_mogelbaumTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_mogelbaumTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_mogelbaumTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_mogelbaumTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_clavion[] = {
	[0] = {.sprite = gfx_ow_clavionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_clavionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_clavionTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_clavionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_clavionTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_clavionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_clavionTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_clavionTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_clavionTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lichtel[] = {
	[0] = {.sprite = gfx_ow_lichtelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lichtelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lichtelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lichtelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lichtelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lichtelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lichtelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lichtelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lichtelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_laternecto[] = {
	[0] = {.sprite = gfx_ow_laternectoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_laternectoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_laternectoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_laternectoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_laternectoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_laternectoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_laternectoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_laternectoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_laternectoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_skelabra[] = {
	[0] = {.sprite = gfx_ow_skelabraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_skelabraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_skelabraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_skelabraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_skelabraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_skelabraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_skelabraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_skelabraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_skelabraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_griffel[] = {
	[0] = {.sprite = gfx_ow_griffelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_griffelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_griffelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_griffelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_griffelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_griffelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_griffelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_griffelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_griffelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_shnebedeck[] = {
	[0] = {.sprite = gfx_ow_shnebedeckTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_shnebedeckTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_shnebedeckTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_shnebedeckTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_shnebedeckTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_shnebedeckTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_shnebedeckTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_shnebedeckTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_shnebedeckTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rexblisar[] = {
	[0] = {.sprite = gfx_ow_rexblisarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rexblisarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rexblisarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rexblisarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rexblisarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rexblisarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rexblisarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rexblisarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rexblisarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ambidiffel[] = {
	[0] = {.sprite = gfx_ow_ambidiffelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ambidiffelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ambidiffelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ambidiffelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ambidiffelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ambidiffelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ambidiffelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ambidiffelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ambidiffelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_felino[] = {
	[0] = {.sprite = gfx_ow_felinoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_felinoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_felinoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_felinoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_felinoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_felinoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_felinoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_felinoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_felinoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_morlord[] = {
	[0] = {.sprite = gfx_ow_morlordTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_morlordTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_morlordTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_morlordTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_morlordTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_morlordTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_morlordTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_morlordTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_morlordTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_psiana[] = {
	[0] = {.sprite = gfx_ow_psianaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_psianaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_psianaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_psianaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_psianaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_psianaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_psianaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_psianaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_psianaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nachtara[] = {
	[0] = {.sprite = gfx_ow_nachtaraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nachtaraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nachtaraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nachtaraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nachtaraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nachtaraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nachtaraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nachtaraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nachtaraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kramurx[] = {
	[0] = {.sprite = gfx_ow_kramurxTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kramurxTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kramurxTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kramurxTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kramurxTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kramurxTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kramurxTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kramurxTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kramurxTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_laschoking[] = {
	[0] = {.sprite = gfx_ow_laschokingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_laschokingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_laschokingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_laschokingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_laschokingTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_laschokingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_laschokingTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_laschokingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_laschokingTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kramshef[] = {
	[0] = {.sprite = gfx_ow_kramshefTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kramshefTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kramshefTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kramshefTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kramshefTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kramshefTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kramshefTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kramshefTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kramshefTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito[] = {
	[0] = {.sprite = gfx_ow_icognitoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognitoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognitoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognitoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognitoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognitoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognitoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognitoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognitoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_frosdedje[] = {
	[0] = {.sprite = gfx_ow_frosdedjeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_frosdedjeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_frosdedjeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_frosdedjeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_frosdedjeTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_frosdedjeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_frosdedjeTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_frosdedjeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_frosdedjeTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_skorgro[] = {
	[0] = {.sprite = gfx_ow_skorgroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_skorgroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_skorgroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_skorgroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_skorgroTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_skorgroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_skorgroTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_skorgroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_skorgroTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tannza[] = {
	[0] = {.sprite = gfx_ow_tannzaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tannzaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tannzaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tannzaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tannzaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tannzaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tannzaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tannzaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tannzaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_forstellka[] = {
	[0] = {.sprite = gfx_ow_forstellkaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_forstellkaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_forstellkaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_forstellkaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_forstellkaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_forstellkaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_forstellkaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_forstellkaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_forstellkaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_elevoltek[] = {
	[0] = {.sprite = gfx_ow_elevoltekTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_elevoltekTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_elevoltekTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_elevoltekTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_elevoltekTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_elevoltekTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_elevoltekTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_elevoltekTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_elevoltekTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_skorgla[] = {
	[0] = {.sprite = gfx_ow_skorglaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_skorglaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_skorglaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_skorglaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_skorglaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_skorglaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_skorglaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_skorglaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_skorglaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_stahlos[] = {
	[0] = {.sprite = gfx_ow_stahlosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_stahlosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_stahlosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_stahlosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_stahlosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_stahlosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_stahlosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_stahlosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_stahlosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_snubbull[] = {
	[0] = {.sprite = gfx_ow_snubbullTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_snubbullTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_snubbullTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_snubbullTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_snubbullTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_snubbullTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_snubbullTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_snubbullTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_snubbullTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_granbull[] = {
	[0] = {.sprite = gfx_ow_granbullTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_granbullTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_granbullTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_granbullTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_granbullTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_granbullTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_granbullTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_granbullTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_granbullTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_mamutel[] = {
	[0] = {.sprite = gfx_ow_mamutelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_mamutelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_mamutelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_mamutelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_mamutelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_mamutelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_mamutelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_mamutelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_mamutelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_scherox[] = {
	[0] = {.sprite = gfx_ow_scheroxTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_scheroxTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_scheroxTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_scheroxTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_scheroxTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_scheroxTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_scheroxTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_scheroxTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_scheroxTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_fluffeluff[] = {
	[0] = {.sprite = gfx_ow_fluffeluffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_fluffeluffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_fluffeluffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_fluffeluffTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_fluffeluffTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_fluffeluffTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_fluffeluffTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_fluffeluffTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_fluffeluffTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_skaraborn[] = {
	[0] = {.sprite = gfx_ow_skarabornTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_skarabornTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_skarabornTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_skarabornTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_skarabornTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_skarabornTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_skarabornTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_skarabornTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_skarabornTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kryppuk[] = {
	[0] = {.sprite = gfx_ow_kryppukTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kryppukTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kryppukTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kryppukTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kryppukTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kryppukTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kryppukTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kryppukTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kryppukTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_teddiursa[] = {
	[0] = {.sprite = gfx_ow_teddiursaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_teddiursaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_teddiursaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_teddiursaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_teddiursaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_teddiursaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_teddiursaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_teddiursaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_teddiursaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ursaring[] = {
	[0] = {.sprite = gfx_ow_ursaringTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ursaringTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ursaringTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ursaringTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ursaringTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ursaringTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ursaringTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ursaringTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ursaringTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schneckmag[] = {
	[0] = {.sprite = gfx_ow_schneckmagTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schneckmagTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schneckmagTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schneckmagTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schneckmagTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schneckmagTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schneckmagTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schneckmagTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schneckmagTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magcargo[] = {
	[0] = {.sprite = gfx_ow_magcargoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magcargoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magcargoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magcargoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magcargoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magcargoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magcargoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magcargoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magcargoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_quiekel[] = {
	[0] = {.sprite = gfx_ow_quiekelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_quiekelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_quiekelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_quiekelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_quiekelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_quiekelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_quiekelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_quiekelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_quiekelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_keifel[] = {
	[0] = {.sprite = gfx_ow_keifelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_keifelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_keifelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_keifelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_keifelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_keifelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_keifelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_keifelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_keifelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_mampfaxo[] = {
	[0] = {.sprite = gfx_ow_mampfaxoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_mampfaxoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_mampfaxoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_mampfaxoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_mampfaxoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_mampfaxoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_mampfaxoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_mampfaxoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_mampfaxoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_remoraid[] = {
	[0] = {.sprite = gfx_ow_remoraidTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_remoraidTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_remoraidTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_remoraidTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_remoraidTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_remoraidTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_remoraidTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_remoraidTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_remoraidTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_octillery[] = {
	[0] = {.sprite = gfx_ow_octilleryTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_octilleryTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_octilleryTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_octilleryTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_octilleryTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_octilleryTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_octilleryTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_octilleryTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_octilleryTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_botogel[] = {
	[0] = {.sprite = gfx_ow_botogelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_botogelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_botogelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_botogelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_botogelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_botogelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_botogelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_botogelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_botogelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schlurplek[] = {
	[0] = {.sprite = gfx_ow_schlurplekTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schlurplekTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schlurplekTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schlurplekTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schlurplekTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schlurplekTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schlurplekTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schlurplekTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schlurplekTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_panzaeron[] = {
	[0] = {.sprite = gfx_ow_panzaeronTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_panzaeronTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_panzaeronTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_panzaeronTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_panzaeronTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_panzaeronTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_panzaeronTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_panzaeronTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_panzaeronTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_hunduster[] = {
	[0] = {.sprite = gfx_ow_hundusterTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_hundusterTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_hundusterTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_hundusterTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_hundusterTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_hundusterTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_hundusterTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_hundusterTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_hundusterTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_hundemon[] = {
	[0] = {.sprite = gfx_ow_hundemonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_hundemonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_hundemonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_hundemonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_hundemonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_hundemonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_hundemonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_hundemonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_hundemonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_seedraking[] = {
	[0] = {.sprite = gfx_ow_seedrakingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_seedrakingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_seedrakingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_seedrakingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_seedrakingTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_seedrakingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_seedrakingTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_seedrakingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_seedrakingTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_phanpy[] = {
	[0] = {.sprite = gfx_ow_phanpyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_phanpyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_phanpyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_phanpyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_phanpyTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_phanpyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_phanpyTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_phanpyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_phanpyTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_donphan[] = {
	[0] = {.sprite = gfx_ow_donphanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_donphanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_donphanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_donphanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_donphanTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_donphanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_donphanTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_donphanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_donphanTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_porygon2[] = {
	[0] = {.sprite = gfx_ow_porygon2Tiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_porygon2Tiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_porygon2Tiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_porygon2Tiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_porygon2Tiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_porygon2Tiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_porygon2Tiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_porygon2Tiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_porygon2Tiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_voluminas[] = {
	[0] = {.sprite = gfx_ow_voluminasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_voluminasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_voluminasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_voluminasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_voluminasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_voluminasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_voluminasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_voluminasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_voluminasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_traunmagil[] = {
	[0] = {.sprite = gfx_ow_traunmagilTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_traunmagilTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_traunmagilTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_traunmagilTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_traunmagilTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_traunmagilTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_traunmagilTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_traunmagilTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_traunmagilTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rabauz[] = {
	[0] = {.sprite = gfx_ow_rabauzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rabauzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rabauzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rabauzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rabauzTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rabauzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rabauzTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rabauzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rabauzTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kapoera[] = {
	[0] = {.sprite = gfx_ow_kapoeraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kapoeraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kapoeraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kapoeraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kapoeraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kapoeraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kapoeraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kapoeraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kapoeraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_elekid[] = {
	[0] = {.sprite = gfx_ow_elekidTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_elekidTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_elekidTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_elekidTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_elekidTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_elekidTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_elekidTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_elekidTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_elekidTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magby[] = {
	[0] = {.sprite = gfx_ow_magbyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magbyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magbyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magbyTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magbyTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magbyTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magbyTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magbyTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magbyTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_miltank[] = {
	[0] = {.sprite = gfx_ow_miltankTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_miltankTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_miltankTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_miltankTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_miltankTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_miltankTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_miltankTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_miltankTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_miltankTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_heiteira[] = {
	[0] = {.sprite = gfx_ow_heiteiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_heiteiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_heiteiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_heiteiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_heiteiraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_heiteiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_heiteiraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_heiteiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_heiteiraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_raikou[] = {
	[0] = {.sprite = gfx_ow_raikouTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_raikouTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_raikouTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_raikouTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_raikouTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_raikouTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_raikouTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_raikouTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_raikouTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_entei[] = {
	[0] = {.sprite = gfx_ow_enteiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_enteiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_enteiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_enteiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_enteiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_enteiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_enteiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_enteiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_enteiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_suicune[] = {
	[0] = {.sprite = gfx_ow_suicuneTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_suicuneTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_suicuneTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_suicuneTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_suicuneTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_suicuneTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_suicuneTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_suicuneTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_suicuneTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_larvitar[] = {
	[0] = {.sprite = gfx_ow_larvitarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_larvitarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_larvitarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_larvitarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_larvitarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_larvitarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_larvitarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_larvitarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_larvitarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pupitar[] = {
	[0] = {.sprite = gfx_ow_pupitarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pupitarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pupitarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pupitarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pupitarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pupitarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pupitarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pupitarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pupitarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_despotar[] = {
	[0] = {.sprite = gfx_ow_despotarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_despotarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_despotarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_despotarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_despotarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_despotarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_despotarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_despotarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_despotarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lugia[] = {
	[0] = {.sprite = gfx_ow_lugiaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lugiaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lugiaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lugiaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lugiaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lugiaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lugiaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lugiaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lugiaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ho_oh[] = {
	[0] = {.sprite = gfx_ow_ho_ohTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ho_ohTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ho_ohTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ho_ohTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ho_ohTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ho_ohTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ho_ohTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ho_ohTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ho_ohTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_celebi[] = {
	[0] = {.sprite = gfx_ow_celebiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_celebiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_celebiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_celebiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_celebiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_celebiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_celebiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_celebiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_celebiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_durengarda[] = {
	[0] = {.sprite = gfx_ow_durengardaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_durengardaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_durengardaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_durengardaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_durengardaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_durengardaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_durengardaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_durengardaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_durengardaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rotom_heat[] = {
	[0] = {.sprite = gfx_ow_rotom_heatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rotom_heatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rotom_heatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rotom_heatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rotom_heatTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rotom_heatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rotom_heatTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rotom_heatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rotom_heatTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rotom_wash[] = {
	[0] = {.sprite = gfx_ow_rotom_washTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rotom_washTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rotom_washTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rotom_washTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rotom_washTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rotom_washTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rotom_washTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rotom_washTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rotom_washTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rotom_mow[] = {
	[0] = {.sprite = gfx_ow_rotom_mowTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rotom_mowTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rotom_mowTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rotom_mowTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rotom_mowTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rotom_mowTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rotom_mowTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rotom_mowTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rotom_mowTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rotom_fan[] = {
	[0] = {.sprite = gfx_ow_rotom_fanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rotom_fanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rotom_fanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rotom_fanTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rotom_fanTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rotom_fanTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rotom_fanTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rotom_fanTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rotom_fanTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rotom_frost[] = {
	[0] = {.sprite = gfx_ow_rotom_frostTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rotom_frostTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rotom_frostTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rotom_frostTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rotom_frostTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rotom_frostTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rotom_frostTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rotom_frostTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rotom_frostTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_fiffyen[] = {
	[0] = {.sprite = gfx_ow_fiffyenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_fiffyenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_fiffyenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_fiffyenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_fiffyenTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_fiffyenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_fiffyenTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_fiffyenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_fiffyenTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magnayen[] = {
	[0] = {.sprite = gfx_ow_magnayenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magnayenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magnayenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magnayenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magnayenTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magnayenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magnayenTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magnayenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magnayenTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zigzachs[] = {
	[0] = {.sprite = gfx_ow_zigzachsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zigzachsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zigzachsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zigzachsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zigzachsTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zigzachsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zigzachsTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zigzachsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zigzachsTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_geradaks[] = {
	[0] = {.sprite = gfx_ow_geradaksTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_geradaksTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_geradaksTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_geradaksTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_geradaksTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_geradaksTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_geradaksTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_geradaksTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_geradaksTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_waumpel[] = {
	[0] = {.sprite = gfx_ow_waumpelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_waumpelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_waumpelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_waumpelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_waumpelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_waumpelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_waumpelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_waumpelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_waumpelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schaloko[] = {
	[0] = {.sprite = gfx_ow_schalokoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schalokoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schalokoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schalokoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schalokoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schalokoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schalokoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schalokoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schalokoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_papinella[] = {
	[0] = {.sprite = gfx_ow_papinellaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_papinellaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_papinellaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_papinellaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_papinellaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_papinellaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_papinellaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_papinellaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_papinellaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_panekon[] = {
	[0] = {.sprite = gfx_ow_panekonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_panekonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_panekonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_panekonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_panekonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_panekonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_panekonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_panekonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_panekonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pudox[] = {
	[0] = {.sprite = gfx_ow_pudoxTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pudoxTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pudoxTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pudoxTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pudoxTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pudoxTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pudoxTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pudoxTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pudoxTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_loturzel[] = {
	[0] = {.sprite = gfx_ow_loturzelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_loturzelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_loturzelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_loturzelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_loturzelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_loturzelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_loturzelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_loturzelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_loturzelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lombrero[] = {
	[0] = {.sprite = gfx_ow_lombreroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lombreroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lombreroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lombreroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lombreroTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lombreroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lombreroTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lombreroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lombreroTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kappalores[] = {
	[0] = {.sprite = gfx_ow_kappaloresTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kappaloresTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kappaloresTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kappaloresTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kappaloresTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kappaloresTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kappaloresTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kappaloresTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kappaloresTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_samurzel[] = {
	[0] = {.sprite = gfx_ow_samurzelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_samurzelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_samurzelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_samurzelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_samurzelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_samurzelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_samurzelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_samurzelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_samurzelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_blanas[] = {
	[0] = {.sprite = gfx_ow_blanasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_blanasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_blanasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_blanasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_blanasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_blanasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_blanasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_blanasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_blanasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tengulist[] = {
	[0] = {.sprite = gfx_ow_tengulistTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tengulistTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tengulistTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tengulistTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tengulistTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tengulistTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tengulistTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tengulistTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tengulistTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nincada[] = {
	[0] = {.sprite = gfx_ow_nincadaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nincadaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nincadaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nincadaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nincadaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nincadaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nincadaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nincadaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nincadaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ninjask[] = {
	[0] = {.sprite = gfx_ow_ninjaskTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ninjaskTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ninjaskTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ninjaskTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ninjaskTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ninjaskTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ninjaskTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ninjaskTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ninjaskTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_ninjatom[] = {
	[0] = {.sprite = gfx_ow_ninjatomTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_ninjatomTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_ninjatomTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_ninjatomTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_ninjatomTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_ninjatomTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_ninjatomTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_ninjatomTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_ninjatomTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schwalbini[] = {
	[0] = {.sprite = gfx_ow_schwalbiniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schwalbiniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schwalbiniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schwalbiniTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schwalbiniTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schwalbiniTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schwalbiniTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schwalbiniTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schwalbiniTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},

};

static graphic overworld_gfxs_schwalboss[] = {
	[0] = {.sprite = gfx_ow_schwalbossTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schwalbossTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schwalbossTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schwalbossTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schwalbossTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schwalbossTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schwalbossTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schwalbossTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schwalbossTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knilz[] = {
	[0] = {.sprite = gfx_ow_knilzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knilzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knilzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knilzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knilzTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knilzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knilzTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knilzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knilzTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kapilz[] = {
	[0] = {.sprite = gfx_ow_kapilzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kapilzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kapilzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kapilzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kapilzTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kapilzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kapilzTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kapilzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kapilzTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pandir[] = {
	[0] = {.sprite = gfx_ow_pandirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pandirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pandirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pandirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pandirTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pandirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pandirTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pandirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pandirTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wingull[] = {
	[0] = {.sprite = gfx_ow_wingullTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wingullTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wingullTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wingullTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wingullTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wingullTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wingullTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wingullTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wingullTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pelipper[] = {
	[0] = {.sprite = gfx_ow_pelipperTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pelipperTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pelipperTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pelipperTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pelipperTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pelipperTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pelipperTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pelipperTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pelipperTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_gehweiher[] = {
	[0] = {.sprite = gfx_ow_gehweiherTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_gehweiherTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_gehweiherTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_gehweiherTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_gehweiherTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_gehweiherTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_gehweiherTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_gehweiherTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_gehweiherTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_maskeregen[] = {
	[0] = {.sprite = gfx_ow_maskeregenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_maskeregenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_maskeregenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_maskeregenTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_maskeregenTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_maskeregenTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_maskeregenTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_maskeregenTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_maskeregenTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wailmer[] = {
	[0] = {.sprite = gfx_ow_wailmerTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wailmerTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wailmerTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wailmerTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wailmerTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wailmerTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wailmerTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wailmerTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wailmerTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wailord[] = {
	[0] = {.sprite = gfx_ow_wailordTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wailordTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wailordTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wailordTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wailordTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wailordTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wailordTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wailordTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wailordTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_eneco[] = {
	[0] = {.sprite = gfx_ow_enecoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_enecoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_enecoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_enecoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_enecoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_enecoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_enecoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_enecoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_enecoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_enekoro[] = {
	[0] = {.sprite = gfx_ow_enekoroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_enekoroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_enekoroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_enekoroTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_enekoroTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_enekoroTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_enekoroTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_enekoroTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_enekoroTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kecleon[] = {
	[0] = {.sprite = gfx_ow_kecleonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kecleonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kecleonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kecleonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kecleonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kecleonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kecleonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kecleonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kecleonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_puppance[] = {
	[0] = {.sprite = gfx_ow_puppanceTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_puppanceTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_puppanceTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_puppanceTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_puppanceTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_puppanceTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_puppanceTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_puppanceTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_puppanceTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lepumentas[] = {
	[0] = {.sprite = gfx_ow_lepumentasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lepumentasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lepumentasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lepumentasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lepumentasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lepumentasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lepumentasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lepumentasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lepumentasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_nasgnet[] = {
	[0] = {.sprite = gfx_ow_nasgnetTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_nasgnetTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_nasgnetTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_nasgnetTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_nasgnetTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_nasgnetTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_nasgnetTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_nasgnetTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_nasgnetTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_magbrant[] = {
	[0] = {.sprite = gfx_ow_magbrantTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_magbrantTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_magbrantTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_magbrantTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_magbrantTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_magbrantTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_magbrantTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_magbrantTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_magbrantTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zwirrfinst[] = {
	[0] = {.sprite = gfx_ow_zwirrfinstTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zwirrfinstTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zwirrfinstTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zwirrfinstTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zwirrfinstTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zwirrfinstTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zwirrfinstTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zwirrfinstTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zwirrfinstTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schmerbe[] = {
	[0] = {.sprite = gfx_ow_schmerbeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schmerbeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schmerbeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schmerbeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schmerbeTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schmerbeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schmerbeTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schmerbeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schmerbeTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_welsar[] = {
	[0] = {.sprite = gfx_ow_welsarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_welsarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_welsarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_welsarTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_welsarTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_welsarTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_welsarTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_welsarTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_welsarTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rihornior[] = {
	[0] = {.sprite = gfx_ow_rihorniorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rihorniorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rihorniorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rihorniorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rihorniorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rihorniorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rihorniorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rihorniorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rihorniorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_krebscorps[] = {
	[0] = {.sprite = gfx_ow_krebscorpsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_krebscorpsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_krebscorpsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_krebscorpsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_krebscorpsTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_krebscorpsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_krebscorpsTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_krebscorpsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_krebscorpsTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_krebutack[] = {
	[0] = {.sprite = gfx_ow_krebutackTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_krebutackTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_krebutackTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_krebutackTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_krebutackTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_krebutackTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_krebutackTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_krebutackTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_krebutackTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_barschwa[] = {
	[0] = {.sprite = gfx_ow_barschwaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_barschwaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_barschwaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_barschwaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_barschwaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_barschwaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_barschwaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_barschwaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_barschwaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_milotic[] = {
	[0] = {.sprite = gfx_ow_miloticTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_miloticTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_miloticTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_miloticTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_miloticTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_miloticTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_miloticTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_miloticTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_miloticTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kanivanha[] = {
	[0] = {.sprite = gfx_ow_kanivanhaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kanivanhaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kanivanhaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kanivanhaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kanivanhaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kanivanhaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kanivanhaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kanivanhaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kanivanhaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tohaido[] = {
	[0] = {.sprite = gfx_ow_tohaidoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tohaidoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tohaidoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tohaidoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tohaidoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tohaidoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tohaidoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tohaidoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tohaidoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knacklion[] = {
	[0] = {.sprite = gfx_ow_knacklionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knacklionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knacklionTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knacklionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knacklionTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knacklionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knacklionTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knacklionTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knacklionTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_vibrava[] = {
	[0] = {.sprite = gfx_ow_vibravaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_vibravaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_vibravaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_vibravaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_vibravaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_vibravaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_vibravaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_vibravaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_vibravaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_libelldra[] = {
	[0] = {.sprite = gfx_ow_libelldraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_libelldraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_libelldraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_libelldraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_libelldraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_libelldraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_libelldraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_libelldraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_libelldraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_riolu[] = {
	[0] = {.sprite = gfx_ow_rioluTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rioluTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rioluTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rioluTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rioluTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rioluTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rioluTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rioluTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rioluTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lucario[] = {
	[0] = {.sprite = gfx_ow_lucarioTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lucarioTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lucarioTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lucarioTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lucarioTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lucarioTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lucarioTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lucarioTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lucarioTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_frizelbliz[] = {
	[0] = {.sprite = gfx_ow_frizelblizTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_frizelblizTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_frizelblizTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_frizelblizTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_frizelblizTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_frizelblizTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_frizelblizTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_frizelblizTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_frizelblizTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_voltenso[] = {
	[0] = {.sprite = gfx_ow_voltensoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_voltensoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_voltensoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_voltensoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_voltensoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_voltensoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_voltensoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_voltensoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_voltensoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_camaub[] = {
	[0] = {.sprite = gfx_ow_camaubTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_camaubTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_camaubTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_camaubTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_camaubTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_camaubTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_camaubTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_camaubTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_camaubTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_camerupt[] = {
	[0] = {.sprite = gfx_ow_cameruptTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_cameruptTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_cameruptTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_cameruptTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_cameruptTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_cameruptTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_cameruptTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_cameruptTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_cameruptTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_seemops[] = {
	[0] = {.sprite = gfx_ow_seemopsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_seemopsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_seemopsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_seemopsTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_seemopsTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_seemopsTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_seemopsTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_seemopsTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_seemopsTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_seejong[] = {
	[0] = {.sprite = gfx_ow_seejongTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_seejongTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_seejongTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_seejongTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_seejongTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_seejongTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_seejongTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_seejongTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_seejongTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_walraisa[] = {
	[0] = {.sprite = gfx_ow_walraisaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_walraisaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_walraisaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_walraisaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_walraisaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_walraisaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_walraisaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_walraisaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_walraisaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tuska[] = {
	[0] = {.sprite = gfx_ow_tuskaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tuskaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tuskaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tuskaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tuskaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tuskaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tuskaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tuskaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tuskaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_noktuska[] = {
	[0] = {.sprite = gfx_ow_noktuskaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_noktuskaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_noktuskaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_noktuskaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_noktuskaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_noktuskaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_noktuskaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_noktuskaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_noktuskaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_schneppke[] = {
	[0] = {.sprite = gfx_ow_schneppkeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_schneppkeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_schneppkeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_schneppkeTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_schneppkeTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_schneppkeTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_schneppkeTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_schneppkeTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_schneppkeTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_firnontor[] = {
	[0] = {.sprite = gfx_ow_firnontorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_firnontorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_firnontorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_firnontorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_firnontorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_firnontorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_firnontorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_firnontorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_firnontorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_lunastein[] = {
	[0] = {.sprite = gfx_ow_lunasteinTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_lunasteinTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_lunasteinTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_lunasteinTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_lunasteinTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_lunasteinTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_lunasteinTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_lunasteinTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_lunasteinTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sonnfel[] = {
	[0] = {.sprite = gfx_ow_sonnfelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sonnfelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sonnfelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sonnfelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sonnfelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sonnfelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sonnfelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sonnfelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sonnfelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_azurill[] = {
	[0] = {.sprite = gfx_ow_azurillTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_azurillTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_azurillTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_azurillTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_azurillTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_azurillTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_azurillTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_azurillTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_azurillTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_spoink[] = {
	[0] = {.sprite = gfx_ow_spoinkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_spoinkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_spoinkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_spoinkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_spoinkTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_spoinkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_spoinkTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_spoinkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_spoinkTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_groink[] = {
	[0] = {.sprite = gfx_ow_groinkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_groinkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_groinkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_groinkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_groinkTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_groinkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_groinkTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_groinkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_groinkTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_pichu[] = {
	[0] = {.sprite = gfx_ow_pichuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_pichuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_pichuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_pichuTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_pichuTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_pichuTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_pichuTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_pichuTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_pichuTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rotom[] = {
	[0] = {.sprite = gfx_ow_rotomTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rotomTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rotomTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rotomTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rotomTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rotomTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rotomTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rotomTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rotomTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_flunkifer[] = {
	[0] = {.sprite = gfx_ow_flunkiferTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_flunkiferTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_flunkiferTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_flunkiferTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_flunkiferTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_flunkiferTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_flunkiferTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_flunkiferTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_flunkiferTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_meditie[] = {
	[0] = {.sprite = gfx_ow_meditieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_meditieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_meditieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_meditieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_meditieTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_meditieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_meditieTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_meditieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_meditieTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_meditalis[] = {
	[0] = {.sprite = gfx_ow_meditalisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_meditalisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_meditalisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_meditalisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_meditalisTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_meditalisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_meditalisTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_meditalisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_meditalisTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wablu[] = {
	[0] = {.sprite = gfx_ow_wabluTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wabluTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wabluTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wabluTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wabluTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wabluTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wabluTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wabluTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wabluTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_altaria[] = {
	[0] = {.sprite = gfx_ow_altariaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_altariaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_altariaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_altariaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_altariaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_altariaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_altariaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_altariaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_altariaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_klingplim[] = {
	[0] = {.sprite = gfx_ow_klingplimTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_klingplimTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_klingplimTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_klingplimTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_klingplimTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_klingplimTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_klingplimTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_klingplimTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_klingplimTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zwirrlicht[] = {
	[0] = {.sprite = gfx_ow_zwirrlichtTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zwirrlichtTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zwirrlichtTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zwirrlichtTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zwirrlichtTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zwirrlichtTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zwirrlichtTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zwirrlichtTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zwirrlichtTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_zwirrklop[] = {
	[0] = {.sprite = gfx_ow_zwirrklopTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_zwirrklopTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_zwirrklopTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_zwirrklopTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_zwirrklopTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_zwirrklopTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_zwirrklopTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_zwirrklopTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_zwirrklopTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_porygon_z[] = {
	[0] = {.sprite = gfx_ow_porygon_zTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_porygon_zTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_porygon_zTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_porygon_zTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_porygon_zTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_porygon_zTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_porygon_zTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_porygon_zTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_porygon_zTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_bummelz[] = {
	[0] = {.sprite = gfx_ow_bummelzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_bummelzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_bummelzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_bummelzTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_bummelzTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_bummelzTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_bummelzTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_bummelzTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_bummelzTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_muntier[] = {
	[0] = {.sprite = gfx_ow_muntierTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_muntierTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_muntierTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_muntierTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_muntierTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_muntierTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_muntierTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_muntierTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_muntierTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_letarking[] = {
	[0] = {.sprite = gfx_ow_letarkingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_letarkingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_letarkingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_letarkingTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_letarkingTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_letarkingTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_letarkingTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_letarkingTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_letarkingTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_molunk[] = {
	[0] = {.sprite = gfx_ow_molunkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_molunkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_molunkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_molunkTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_molunkTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_molunkTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_molunkTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_molunkTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_molunkTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_amfira[] = {
	[0] = {.sprite = gfx_ow_amfiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_amfiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_amfiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_amfiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_amfiraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_amfiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_amfiraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_amfiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_amfiraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tropius[] = {
	[0] = {.sprite = gfx_ow_tropiusTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tropiusTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tropiusTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tropiusTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tropiusTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tropiusTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tropiusTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tropiusTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tropiusTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kaumalat[] = {
	[0] = {.sprite = gfx_ow_kaumalatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kaumalatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kaumalatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kaumalatTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kaumalatTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kaumalatTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kaumalatTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kaumalatTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kaumalatTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knarksel[] = {
	[0] = {.sprite = gfx_ow_knarkselTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knarkselTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knarkselTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knarkselTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knarkselTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knarkselTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knarkselTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knarkselTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knarkselTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_knakrack[] = {
	[0] = {.sprite = gfx_ow_knakrackTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_knakrackTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_knakrackTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_knakrackTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_knakrackTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_knakrackTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_knakrackTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_knakrackTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_knakrackTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_perlu[] = {
	[0] = {.sprite = gfx_ow_perluTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_perluTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_perluTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_perluTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_perluTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_perluTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_perluTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_perluTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_perluTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_aalabyss[] = {
	[0] = {.sprite = gfx_ow_aalabyssTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_aalabyssTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_aalabyssTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_aalabyssTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_aalabyssTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_aalabyssTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_aalabyssTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_aalabyssTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_aalabyssTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_saganabyss[] = {
	[0] = {.sprite = gfx_ow_saganabyssTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_saganabyssTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_saganabyssTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_saganabyssTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_saganabyssTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_saganabyssTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_saganabyssTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_saganabyssTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_saganabyssTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_absol[] = {
	[0] = {.sprite = gfx_ow_absolTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_absolTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_absolTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_absolTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_absolTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_absolTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_absolTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_absolTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_absolTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_shuppet[] = {
	[0] = {.sprite = gfx_ow_shuppetTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_shuppetTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_shuppetTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_shuppetTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_shuppetTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_shuppetTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_shuppetTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_shuppetTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_shuppetTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_banette[] = {
	[0] = {.sprite = gfx_ow_banetteTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_banetteTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_banetteTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_banetteTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_banetteTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_banetteTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_banetteTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_banetteTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_banetteTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_vipitis[] = {
	[0] = {.sprite = gfx_ow_vipitisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_vipitisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_vipitisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_vipitisTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_vipitisTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_vipitisTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_vipitisTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_vipitisTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_vipitisTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_sengo[] = {
	[0] = {.sprite = gfx_ow_sengoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_sengoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_sengoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_sengoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_sengoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_sengoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_sengoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_sengoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_sengoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_relicanth[] = {
	[0] = {.sprite = gfx_ow_relicanthTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_relicanthTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_relicanthTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_relicanthTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_relicanthTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_relicanthTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_relicanthTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_relicanthTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_relicanthTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_stollunior[] = {
	[0] = {.sprite = gfx_ow_stolluniorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_stolluniorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_stolluniorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_stolluniorTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_stolluniorTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_stolluniorTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_stolluniorTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_stolluniorTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_stolluniorTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_stollrak[] = {
	[0] = {.sprite = gfx_ow_stollrakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_stollrakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_stollrakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_stollrakTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_stollrakTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_stollrakTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_stollrakTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_stollrakTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_stollrakTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_stolloss[] = {
	[0] = {.sprite = gfx_ow_stollossTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_stollossTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_stollossTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_stollossTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_stollossTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_stollossTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_stollossTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_stollossTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_stollossTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_formeo[] = {
	[0] = {.sprite = gfx_ow_formeoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_formeoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_formeoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_formeoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_formeoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_formeoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_formeoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_formeoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_formeoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wonneira[] = {
	[0] = {.sprite = gfx_ow_wonneiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wonneiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wonneiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wonneiraTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wonneiraTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wonneiraTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wonneiraTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wonneiraTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wonneiraTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_mobai[] = {
	[0] = {.sprite = gfx_ow_mobaiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_mobaiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_mobaiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_mobaiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_mobaiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_mobaiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_mobaiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_mobaiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_mobaiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_liliep[] = {
	[0] = {.sprite = gfx_ow_liliepTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_liliepTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_liliepTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_liliepTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_liliepTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_liliepTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_liliepTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_liliepTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_liliepTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_wielie[] = {
	[0] = {.sprite = gfx_ow_wielieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_wielieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_wielieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_wielieTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_wielieTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_wielieTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_wielieTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_wielieTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_wielieTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_anorith[] = {
	[0] = {.sprite = gfx_ow_anorithTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_anorithTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_anorithTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_anorithTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_anorithTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_anorithTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_anorithTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_anorithTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_anorithTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_armaldo[] = {
	[0] = {.sprite = gfx_ow_armaldoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_armaldoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_armaldoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_armaldoTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_armaldoTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_armaldoTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_armaldoTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_armaldoTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_armaldoTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_trasla[] = {
	[0] = {.sprite = gfx_ow_traslaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_traslaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_traslaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_traslaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_traslaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_traslaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_traslaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_traslaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_traslaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kirlia[] = {
	[0] = {.sprite = gfx_ow_kirliaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kirliaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kirliaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kirliaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kirliaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kirliaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kirliaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kirliaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kirliaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_guardevoir[] = {
	[0] = {.sprite = gfx_ow_guardevoirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_guardevoirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_guardevoirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_guardevoirTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_guardevoirTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_guardevoirTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_guardevoirTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_guardevoirTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_guardevoirTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kindwurm[] = {
	[0] = {.sprite = gfx_ow_kindwurmTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kindwurmTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kindwurmTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kindwurmTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kindwurmTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kindwurmTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kindwurmTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kindwurmTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kindwurmTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_draschel[] = {
	[0] = {.sprite = gfx_ow_draschelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_draschelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_draschelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_draschelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_draschelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_draschelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_draschelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_draschelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_draschelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_brutalanda[] = {
	[0] = {.sprite = gfx_ow_brutalandaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_brutalandaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_brutalandaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_brutalandaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_brutalandaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_brutalandaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_brutalandaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_brutalandaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_brutalandaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_tanhel[] = {
	[0] = {.sprite = gfx_ow_tanhelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_tanhelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_tanhelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_tanhelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_tanhelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_tanhelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_tanhelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_tanhelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_tanhelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_metang[] = {
	[0] = {.sprite = gfx_ow_metangTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_metangTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_metangTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_metangTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_metangTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_metangTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_metangTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_metangTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_metangTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_metagross[] = {
	[0] = {.sprite = gfx_ow_metagrossTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_metagrossTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_metagrossTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_metagrossTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_metagrossTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_metagrossTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_metagrossTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_metagrossTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_metagrossTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_regirock[] = {
	[0] = {.sprite = gfx_ow_regirockTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_regirockTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_regirockTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_regirockTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_regirockTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_regirockTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_regirockTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_regirockTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_regirockTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_regice[] = {
	[0] = {.sprite = gfx_ow_regiceTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_regiceTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_regiceTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_regiceTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_regiceTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_regiceTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_regiceTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_regiceTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_regiceTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_registeel[] = {
	[0] = {.sprite = gfx_ow_registeelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_registeelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_registeelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_registeelTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_registeelTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_registeelTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_registeelTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_registeelTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_registeelTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_kyogre[] = {
	[0] = {.sprite = gfx_ow_kyogreTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_kyogreTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_kyogreTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_kyogreTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_kyogreTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_kyogreTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_kyogreTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_kyogreTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_kyogreTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_groudon[] = {
	[0] = {.sprite = gfx_ow_groudonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_groudonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_groudonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_groudonTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_groudonTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_groudonTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_groudonTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_groudonTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_groudonTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_rayquaza[] = {
	[0] = {.sprite = gfx_ow_rayquazaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_rayquazaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_rayquazaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_rayquazaTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_rayquazaTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_rayquazaTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_rayquazaTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_rayquazaTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_rayquazaTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_latias[] = {
	[0] = {.sprite = gfx_ow_latiasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_latiasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_latiasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_latiasTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_latiasTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_latiasTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_latiasTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_latiasTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_latiasTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_latios[] = {
	[0] = {.sprite = gfx_ow_latiosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_latiosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_latiosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_latiosTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_latiosTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_latiosTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_latiosTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_latiosTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_latiosTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_jirachi[] = {
	[0] = {.sprite = gfx_ow_jirachiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_jirachiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_jirachiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_jirachiTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_jirachiTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_jirachiTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_jirachiTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_jirachiTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_jirachiTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_deoxys[] = {
	[0] = {.sprite = gfx_ow_deoxysTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_deoxysTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_deoxysTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_deoxysTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_deoxysTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_deoxysTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_deoxysTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_deoxysTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_deoxysTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_palimpalim[] = {
	[0] = {.sprite = gfx_ow_palimpalimTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_palimpalimTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_palimpalimTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_palimpalimTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_palimpalimTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_palimpalimTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_palimpalimTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_palimpalimTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_palimpalimTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_b[] = {
	[0] = {.sprite = gfx_ow_icognito_bTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_bTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_bTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_bTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_bTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_bTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_bTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_bTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_bTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_c[] = {
	[0] = {.sprite = gfx_ow_icognito_cTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_cTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_cTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_cTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_cTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_cTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_cTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_cTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_cTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_d[] = {
	[0] = {.sprite = gfx_ow_icognito_dTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_dTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_dTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_dTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_dTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_dTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_dTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_dTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_dTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_e[] = {
	[0] = {.sprite = gfx_ow_icognito_eTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_eTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_eTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_eTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_eTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_eTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_eTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_eTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_eTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_f[] = {
	[0] = {.sprite = gfx_ow_icognito_fTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_fTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_fTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_fTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_fTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_fTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_fTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_fTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_fTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_g[] = {
	[0] = {.sprite = gfx_ow_icognito_gTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_gTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_gTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_gTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_gTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_gTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_gTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_gTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_gTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_h[] = {
	[0] = {.sprite = gfx_ow_icognito_hTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_hTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_hTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_hTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_hTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_hTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_hTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_hTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_hTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_i[] = {
	[0] = {.sprite = gfx_ow_icognito_iTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_iTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_iTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_iTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_iTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_iTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_iTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_iTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_iTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_j[] = {
	[0] = {.sprite = gfx_ow_icognito_jTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_jTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_jTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_jTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_jTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_jTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_jTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_jTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_jTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_k[] = {
	[0] = {.sprite = gfx_ow_icognito_kTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_kTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_kTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_kTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_kTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_kTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_kTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_kTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_kTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_l[] = {
	[0] = {.sprite = gfx_ow_icognito_lTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_lTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_lTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_lTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_lTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_lTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_lTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_lTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_lTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_m[] = {
	[0] = {.sprite = gfx_ow_icognito_mTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_mTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_mTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_mTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_mTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_mTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_mTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_mTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_mTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_n[] = {
	[0] = {.sprite = gfx_ow_icognito_nTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_nTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_nTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_nTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_nTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_nTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_nTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_nTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_nTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_o[] = {
	[0] = {.sprite = gfx_ow_icognito_oTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_oTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_oTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_oTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_oTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_oTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_oTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_oTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_oTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_p[] = {
	[0] = {.sprite = gfx_ow_icognito_pTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_pTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_pTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_pTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_pTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_pTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_pTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_pTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_pTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_q[] = {
	[0] = {.sprite = gfx_ow_icognito_qTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_qTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_qTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_qTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_qTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_qTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_qTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_qTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_qTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_r[] = {
	[0] = {.sprite = gfx_ow_icognito_rTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_rTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_rTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_rTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_rTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_rTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_rTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_rTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_rTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_s[] = {
	[0] = {.sprite = gfx_ow_icognito_sTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_sTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_sTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_sTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_sTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_sTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_sTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_sTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_sTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_t[] = {
	[0] = {.sprite = gfx_ow_icognito_tTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_tTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_tTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_tTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_tTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_tTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_tTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_tTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_tTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_u[] = {
	[0] = {.sprite = gfx_ow_icognito_uTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_uTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_uTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_uTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_uTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_uTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_uTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_uTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_uTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_v[] = {
	[0] = {.sprite = gfx_ow_icognito_vTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_vTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_vTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_vTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_vTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_vTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_vTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_vTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_vTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_w[] = {
	[0] = {.sprite = gfx_ow_icognito_wTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_wTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_wTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_wTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_wTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_wTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_wTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_wTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_wTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_x[] = {
	[0] = {.sprite = gfx_ow_icognito_xTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_xTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_xTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_xTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_xTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_xTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_xTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_xTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_xTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_y[] = {
	[0] = {.sprite = gfx_ow_icognito_yTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_yTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_yTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_yTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_yTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_yTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_yTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_yTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_yTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_z[] = {
	[0] = {.sprite = gfx_ow_icognito_zTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_zTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_zTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_zTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_zTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_zTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_zTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_zTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_zTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_exclamation[] = {
	[0] = {.sprite = gfx_ow_icognito_exclamationTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_exclamationTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_exclamationTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_exclamationTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_exclamationTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_exclamationTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_exclamationTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_exclamationTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_exclamationTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};

static graphic overworld_gfxs_icognito_question[] = {
	[0] = {.sprite = gfx_ow_icognito_questionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_icognito_questionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[2] = {.sprite = gfx_ow_icognito_questionTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[3] = {.sprite = gfx_ow_icognito_questionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[4] = {.sprite = gfx_ow_icognito_questionTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[5] = {.sprite = gfx_ow_icognito_questionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[6] = {.sprite = gfx_ow_icognito_questionTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[7] = {.sprite = gfx_ow_icognito_questionTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
	[8] = {.sprite = gfx_ow_icognito_questionTiles + 5 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0},
};



static overworld_sprite overworlds_pokemon[] = {
    [POKEMON_BISASAM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISASAM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bisasam, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BISAKNOSP] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISAKNOSP,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bisaknosp, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BISAFLOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BISAFLOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bisaflor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GLUMANDA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLUMANDA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_glumanda, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GLUTEXO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLUTEXO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_glutexo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GLURAK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLURAK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_glurak, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHIGGY] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHIGGY,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schiggy, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHILLOK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHILLOK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schillok, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TURTOK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TURTOK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_turtok, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DARTIRI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DARTIRI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dartiri, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DARTIGNIS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DARTIGNIS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dartignis, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FIARO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FIARO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_fiaro, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_HORNLIU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HORNLIU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_hornliu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KOKUNA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KOKUNA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kokuna, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BIBOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BIBOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bibor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STARALILI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARALILI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_staralili, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STARAVIA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARAVIA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_staravia, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STARAPTOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARAPTOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_staraptor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BRONZEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BRONZEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bronzel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BRONZONG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BRONZONG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bronzong, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAEHIKEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAEHIKEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_maehikel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_CHEVRUMM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CHEVRUMM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_chevrumm, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PARAGONI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PARAGONI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_paragoni, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TROMBORK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TROMBORK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_trombork, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PIKACHU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PIKACHU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pikachu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RAICHU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAICHU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_raichu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SANDAN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SANDAN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sandan, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SANDAMER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SANDAMER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sandamer, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NIDORANW] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORANW,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nidoranw, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NIDORINA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORINA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nidorina, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NIDOQUEEN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDOQUEEN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nidoqueen, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NIDORANM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORANM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nidoranm, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NIDORINO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDORINO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nidorino, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NIDOKING] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NIDOKING,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nidoking, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLOETTE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLOETTE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_floette, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLORGES] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLORGES,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_florges, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VULPIX] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VULPIX,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_vulpix, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VULNONA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VULNONA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_vulnona, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PUMMELUFF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUMMELUFF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pummeluff, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNUDDELUFF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNUDDELUFF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knuddeluff, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZUBAT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZUBAT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zubat, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GOLBAT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GOLBAT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_golbat, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MYRAPLA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MYRAPLA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_myrapla, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DUFLOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DUFLOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_duflor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GIFLOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GIFLOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_giflor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FOLIPURBA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FOLIPURBA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_folipurba, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FEELINARA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FEELINARA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_feelinara, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WATTZAPF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WATTZAPF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wattzapf, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VOLTULA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTULA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_voltula, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DIGDA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DIGDA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_digda, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DIGDRI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DIGDRI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_digdri, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KASTADUR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KASTADUR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kastadur, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TENTANTEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENTANTEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tentantel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ENTON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENTON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_enton, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ENTORON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENTORON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_entoron, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MENKI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MENKI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_menki, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RASAFF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RASAFF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rasaff, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FUKANO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FUKANO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_fukano, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ARKANI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARKANI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_arkani, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GRAMOKLES] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GRAMOKLES,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_gramokles, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DUOKLES] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DUOKLES,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_duokles, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DURENGARD] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DURENGARD,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_durengard, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ABRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ABRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_abra, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KADABRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KADABRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kadabra, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SIMSALA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SIMSALA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_simsala, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MACHOLLO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MACHOLLO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_machollo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MASCHOCK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MASCHOCK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_maschock, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MACHOMEI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MACHOMEI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_machomei, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNOFENSA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNOFENSA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knofensa, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ULTRIGARIA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ULTRIGARIA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ultrigaria, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SARZENIA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SARZENIA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sarzenia, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TENTACHA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENTACHA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tentacha, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TENTOXA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENTOXA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tentoxa, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KLEINSTEIN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KLEINSTEIN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kleinstein, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GEOROK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GEOROK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_georok, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GEOWAZ] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GEOWAZ,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_geowaz, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PONITA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PONITA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ponita, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GALLOPA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GALLOPA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_gallopa, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLEGMON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLEGMON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_flegmon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LAHMUS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAHMUS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lahmus, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGNETILO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNETILO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magnetilo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGNETON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNETON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magneton, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PORENTA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORENTA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_porenta, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DODU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DODU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dodu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DODRI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DODRI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dodri, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_JUROB] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_JUROB,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_jurob, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_JUGONG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_JUGONG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_jugong, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SLEIMA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SLEIMA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sleima, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SLEIMOK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SLEIMOK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sleimok, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MUSCHAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MUSCHAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_muschas, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AUSTOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AUSTOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_austos, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NEBULAK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NEBULAK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nebulak, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ALPOLLO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ALPOLLO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_alpollo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GENGAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GENGAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_gengar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ONIX] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ONIX,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_onix, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TRAUMATO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAUMATO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_traumato, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_HYPNO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HYPNO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_hypno, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KRABBY] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRABBY,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_krabby, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KINGLER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KINGLER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kingler, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VOLTOBAL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTOBAL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_voltobal, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LEKTROBAL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEKTROBAL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lektrobal, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_OWEI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_OWEI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_owei, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KOKOWEI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KOKOWEI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kokowei, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TRAGOSSO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAGOSSO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tragosso, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNOGGA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNOGGA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knogga, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KICKLEE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KICKLEE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kicklee, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NOCKCHAN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NOCKCHAN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nockchan, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHLURP] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHLURP,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schlurp, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SMOGON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SMOGON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_smogon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SMOGMOG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SMOGMOG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_smogmog, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RIHORN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIHORN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rihorn, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RIZEROS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIZEROS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rizeros, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_CHANEIRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CHANEIRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_chaneira, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZOBIRIS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZOBIRIS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zobiris, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KANGAMA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KANGAMA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kangama, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SEEPER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEPER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_seeper, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SEEMON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEMON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_seemon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_QUABBEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_QUABBEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_quabbel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_APOQUALLYP] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_APOQUALLYP,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_apoquallyp, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STERNDU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STERNDU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sterndu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STARMIE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STARMIE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_starmie, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TRAUNFUGIL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAUNFUGIL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_traunfugil, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SICHLOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SICHLOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sichlor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GALAGLADI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GALAGLADI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_galagladi, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ELEKTEK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ELEKTEK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_elektek, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGMAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGMAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magmar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PINSIR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PINSIR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pinsir, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TAUROS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TAUROS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tauros, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KARPADOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KARPADOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_karpador, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GARADOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GARADOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_garados, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LAPRAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAPRAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lapras, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DITTO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DITTO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ditto, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_EVOLI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_EVOLI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_evoli, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AQUANA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AQUANA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_aquana, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BLITZA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BLITZA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_blitza, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLAMARA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLAMARA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_flamara, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PORYGON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORYGON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_porygon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AMONITAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMONITAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_amonitas, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AMOROSO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMOROSO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_amoroso, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KABUTO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KABUTO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kabuto, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KABUTOPS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KABUTOPS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kabutops, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AERODACTYL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AERODACTYL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_aerodactyl, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RELAXO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RELAXO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_relaxo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ARKTOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARKTOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_arktos, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZAPDOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZAPDOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zapdos, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LAVADOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAVADOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lavados, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DRATINI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRATINI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dratini, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DRAGONIR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRAGONIR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dragonir, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DRAGORAN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRAGORAN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_dragoran, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MEWTU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEWTU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_mewtu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MEW] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEW,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_mew, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ENDIVIE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENDIVIE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_endivie, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LORBLATT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LORBLATT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lorblatt, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MEGANIE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEGANIE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_meganie, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FEURIGEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FEURIGEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_feurigel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_IGELAVAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IGELAVAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_igelavar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TORNUPTO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TORNUPTO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tornupto, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KARNIMANI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KARNIMANI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_karnimani, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TYRACROC] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TYRACROC,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tyracroc, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_IMPERGATOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IMPERGATOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_impergator, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_IGNIVOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IGNIVOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ignivor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RAMOTH] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAMOTH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ramoth, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GLAZIOLA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GLAZIOLA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_glaziola, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RESLADERO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RESLADERO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_resladero, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LEDYBA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEDYBA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ledyba, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LEDIAN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEDIAN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ledian, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WEBARAK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WEBARAK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_webarak, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ARIADOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARIADOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ariados, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_IKSBAT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_IKSBAT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_iksbat, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LAMPI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LAMPI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lampi, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LANTURN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LANTURN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lanturn, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGNEZONE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNEZONE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magnezone, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TOGEKISS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOGEKISS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_togekiss, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLABEBE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLABEBE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_flabebe, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TOGEPI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOGEPI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_togepi, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TOGETIC] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOGETIC,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_togetic, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NATU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NATU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_natu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_XATU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_XATU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_xatu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VOLTILAMM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTILAMM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_voltilamm, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WAATY] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAATY,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_waaty, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AMPHAROS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMPHAROS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ampharos, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BLUBELLA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BLUBELLA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_blubella, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MARILL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MARILL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_marill, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AZUMARILL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AZUMARILL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_azumarill, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MOGELBAUM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MOGELBAUM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_mogelbaum, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_CLAVION] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CLAVION,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_clavion, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LICHTEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LICHTEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lichtel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LATERNECTO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LATERNECTO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_laternecto, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SKELABRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKELABRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_skelabra, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GRIFFEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GRIFFEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_griffel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SHNEBEDECK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SHNEBEDECK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_shnebedeck, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_REXBLISAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REXBLISAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rexblisar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AMBIDIFFEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMBIDIFFEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ambidiffel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FELINO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FELINO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_felino, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MORLORD] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MORLORD,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_morlord, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PSIANA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PSIANA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_psiana, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NACHTARA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NACHTARA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nachtara, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KRAMURX] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRAMURX,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kramurx, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LASCHOKING] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LASCHOKING,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_laschoking, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KRAMSHEF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRAMSHEF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kramshef, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FROSDEDJE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FROSDEDJE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_frosdedje, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SKORGRO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKORGRO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_skorgro, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TANNZA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TANNZA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tannza, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FORSTELLKA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FORSTELLKA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_forstellka, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ELEVOLTEK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ELEVOLTEK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_elevoltek, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SKORGLA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKORGLA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_skorgla, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STAHLOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STAHLOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_stahlos, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SNUBBULL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SNUBBULL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_snubbull, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GRANBULL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GRANBULL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_granbull, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAMUTEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAMUTEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_mamutel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHEROX] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHEROX,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_scherox, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLUFFELUFF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLUFFELUFF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_fluffeluff, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SKARABORN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SKARABORN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_skaraborn, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KRYPPUK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KRYPPUK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kryppuk, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TEDDIURSA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TEDDIURSA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_teddiursa, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_URSARING] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_URSARING,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ursaring, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHNECKMAG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHNECKMAG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schneckmag, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGCARGO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGCARGO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magcargo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_QUIEKEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_QUIEKEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_quiekel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KEIFEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KEIFEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_keifel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAMPFAXO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAMPFAXO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_mampfaxo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_REMORAID] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REMORAID,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_remoraid, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_OCTILLERY] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_OCTILLERY,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_octillery, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BOTOGEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BOTOGEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_botogel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHLURPLEK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHLURPLEK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schlurplek, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PANZAERON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PANZAERON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_panzaeron, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_HUNDUSTER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HUNDUSTER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_hunduster, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_HUNDEMON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HUNDEMON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_hundemon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SEEDRAKING] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEDRAKING,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_seedraking, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PHANPY] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PHANPY,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_phanpy, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DONPHAN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DONPHAN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_donphan, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PORYGON2] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORYGON2,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_porygon2, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VOLUMINAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLUMINAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_voluminas, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TRAUNMAGIL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRAUNMAGIL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_traunmagil, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RABAUZ] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RABAUZ,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rabauz, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KAPOERA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAPOERA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kapoera, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ELEKID] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ELEKID,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_elekid, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGBY] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGBY,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magby, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MILTANK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MILTANK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_miltank, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_HEITEIRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HEITEIRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_heiteira, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RAIKOU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAIKOU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_raikou, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ENTEI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENTEI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_entei, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SUICUNE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SUICUNE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_suicune, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LARVITAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LARVITAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_larvitar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PUPITAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUPITAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pupitar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DESPOTAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DESPOTAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_despotar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LUGIA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LUGIA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lugia, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_HO_OH] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_HO_OH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ho_oh, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_CELEBI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CELEBI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_celebi, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DURENGARD_OFFENSIVE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DURENGARD_OFFENSIVE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_durengarda, .rotscale_animation = oam_rotscale_anim_table_null,
    },
	[POKEMON_ROTOM_HEAT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_HEAT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rotom_heat, .rotscale_animation = oam_rotscale_anim_table_null,
    },
	[POKEMON_ROTOM_WASH] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_WASH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rotom_wash, .rotscale_animation = oam_rotscale_anim_table_null,
    },
	[POKEMON_ROTOM_WIND] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_WIND,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rotom_fan, .rotscale_animation = oam_rotscale_anim_table_null,
    },
	[POKEMON_ROTOM_FORST] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_FORST,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rotom_frost, .rotscale_animation = oam_rotscale_anim_table_null,
    },
	[POKEMON_ROTOM_GRASS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM_GRASS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rotom_mow, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FIFFYEN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FIFFYEN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_fiffyen, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGNAYEN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGNAYEN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magnayen, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZIGZACHS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZIGZACHS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zigzachs, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GERADAKS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GERADAKS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_geradaks, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WAUMPEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAUMPEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_waumpel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHALOKO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHALOKO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schaloko, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PAPINELLA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PAPINELLA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_papinella, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PANEKON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PANEKON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_panekon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PUDOX] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUDOX,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pudox, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LOTURZEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LOTURZEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_loturzel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LOMBRERO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LOMBRERO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lombrero, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KAPPALORES] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAPPALORES,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kappalores, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SAMURZEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SAMURZEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_samurzel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BLANAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BLANAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_blanas, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TENGULIST] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TENGULIST,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tengulist, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NINCADA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NINCADA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nincada, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NINJASK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NINJASK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ninjask, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NINJATOM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NINJATOM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_ninjatom, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHWALBINI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHWALBINI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schwalbini, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHWALBOSS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHWALBOSS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schwalboss, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNILZ] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNILZ,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knilz, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KAPILZ] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAPILZ,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kapilz, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PANDIR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PANDIR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pandir, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WINGULL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WINGULL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wingull, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PELIPPER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PELIPPER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pelipper, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GEHWEIHER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GEHWEIHER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_gehweiher, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MASKEREGEN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MASKEREGEN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_maskeregen, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WAILMER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAILMER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wailmer, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WAILORD] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WAILORD,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wailord, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ENECO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENECO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_eneco, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ENEKORO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ENEKORO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_enekoro, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KECLEON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KECLEON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kecleon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PUPPANCE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PUPPANCE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_puppance, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LEPUMENTAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LEPUMENTAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lepumentas, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NASGNET] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NASGNET,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_nasgnet, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MAGBRANT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MAGBRANT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_magbrant, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZWIRRFINST] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZWIRRFINST,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zwirrfinst, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHMERBE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHMERBE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schmerbe, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WELSAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WELSAR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_welsar, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RIHORNIOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIHORNIOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rihornior, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KREBSCORPS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KREBSCORPS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_krebscorps, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KREBUTACK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KREBUTACK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_krebutack, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BARSCHWA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BARSCHWA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_barschwa, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MILOTIC] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MILOTIC,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_milotic, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KANIVANHA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KANIVANHA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kanivanha, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TOHAIDO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TOHAIDO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tohaido, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNACKLION] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNACKLION,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knacklion, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VIBRAVA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VIBRAVA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_vibrava, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LIBELLDRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LIBELLDRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_libelldra, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RIOLU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RIOLU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_riolu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LUCARIO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LUCARIO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lucario, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FRIZELBLIZ] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FRIZELBLIZ,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_frizelbliz, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VOLTENSO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VOLTENSO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_voltenso, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_CAMAUB] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CAMAUB,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_camaub, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_CAMERUPT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_CAMERUPT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_camerupt, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SEEMOPS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEMOPS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_seemops, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SEEJONG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SEEJONG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_seejong, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WALRAISA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WALRAISA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_walraisa, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TUSKA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TUSKA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tuska, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_NOKTUSKA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_NOKTUSKA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_noktuska, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SCHNEPPKE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SCHNEPPKE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_schneppke, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FIRNONTOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FIRNONTOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_firnontor, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LUNASTEIN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LUNASTEIN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_lunastein, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SONNFEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SONNFEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sonnfel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AZURILL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AZURILL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_azurill, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SPOINK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SPOINK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_spoink, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GROINK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GROINK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_groink, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PICHU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PICHU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_pichu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ROTOM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ROTOM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rotom, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FLUNKIFER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FLUNKIFER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_flunkifer, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MEDITIE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEDITIE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_meditie, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MEDITALIS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MEDITALIS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_meditalis, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WABLU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WABLU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wablu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ALTARIA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ALTARIA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_altaria, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KLINGPLIM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KLINGPLIM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_klingplim, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZWIRRLICHT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZWIRRLICHT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zwirrlicht, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ZWIRRKLOP] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ZWIRRKLOP,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_zwirrklop, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PORYGON_Z] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PORYGON_Z,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_porygon_z, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BUMMELZ] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BUMMELZ,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_bummelz, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MUNTIER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MUNTIER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_muntier, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LETARKING] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LETARKING,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_letarking, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MOLUNK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MOLUNK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_molunk, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AMFIRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AMFIRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_amfira, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TROPIUS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TROPIUS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tropius, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KAUMALAT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KAUMALAT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kaumalat, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNARKSEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNARKSEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knarksel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KNAKRACK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KNAKRACK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_knakrack, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PERLU] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PERLU,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_perlu, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_AALABYSS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_AALABYSS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_aalabyss, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SAGANABYSS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SAGANABYSS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_saganabyss, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ABSOL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ABSOL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_absol, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SHUPPET] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SHUPPET,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_shuppet, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BANETTE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BANETTE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_banette, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_VIPITIS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_VIPITIS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_vipitis, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_SENGO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_SENGO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_sengo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RELICANTH] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RELICANTH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_relicanth, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STOLLUNIOR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STOLLUNIOR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_stollunior, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STOLLRAK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STOLLRAK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_stollrak, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_STOLLOSS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_STOLLOSS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_stolloss, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_FORMEO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_FORMEO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_formeo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WONNEIRA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WONNEIRA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wonneira, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_MOBAI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_MOBAI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_mobai, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LILIEP] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LILIEP,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_liliep, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_WIELIE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_WIELIE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_wielie, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ANORITH] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ANORITH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_anorith, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ARMALDO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ARMALDO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_armaldo, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TRASLA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TRASLA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_trasla, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KIRLIA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KIRLIA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kirlia, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GUARDEVOIR] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GUARDEVOIR,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_guardevoir, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KINDWURM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KINDWURM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kindwurm, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DRASCHEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DRASCHEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_draschel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_BRUTALANDA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_BRUTALANDA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_brutalanda, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_TANHEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_TANHEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_tanhel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_METANG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_METANG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_metang, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_METAGROSS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_METAGROSS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_metagross, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_REGIROCK] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REGIROCK,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_regirock, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_REGICE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REGICE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_regice, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_REGISTEEL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_REGISTEEL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_registeel, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_KYOGRE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_KYOGRE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_kyogre, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_GROUDON] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_GROUDON,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_groudon, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_RAYQUAZA] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_RAYQUAZA,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(64, 64), .width = 64, .height = 64,
        .final_oam = &ow_final_oam_64_64, .subsprite_table = &ow_formation_64_64, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_rayquaza, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LATIAS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LATIAS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_latias, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_LATIOS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_LATIOS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_latios, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_JIRACHI] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_JIRACHI,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_jirachi, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_DEOXYS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_DEOXYS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_deoxys, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_PALIMPALIM] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_PALIMPALIM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_palimpalim, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_B] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_B,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_b, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_C] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_C,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_c, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_D] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_D,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_d, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_E] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_E,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_e, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_F] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_F,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_f, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_G] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_G,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_g, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_H] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_H,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_h, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_I] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_I,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_i, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_J] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_J,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_j, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_K] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_K,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_k, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_L] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_L,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_l, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_M] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_M,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_m, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_N] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_N,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_n, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_O] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_O,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_o, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_P] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_P,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_p, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_Q] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_Q,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_q, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_R] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_R,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_r, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_S] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_S,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_s, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_T] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_T,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_t, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_U] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_U,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_u, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_V] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_V,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_v, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_W] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_W,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_w, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_X] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_X,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_x, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_Y] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_Y,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_y, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_Z] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_Z,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_z, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_EXCLAMATION] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_EXCLAMATION,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_exclamation, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [POKEMON_ICOGNITO_QUESTION] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_POKEMON_BASE + POKEMON_ICOGNITO_QUESTION,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = ow_anim_standard_npc,
        .graphics = overworld_gfxs_icognito_question, .rotscale_animation = oam_rotscale_anim_table_null,
    },

};

overworld_sprite *overworld_sprite_get_by_species(u16 species) {
    return overworlds_pokemon + species;
}

palette *overworld_palette_get_by_species(u16 species) {
    return ow_pokemon_pals + species;
}

u8 overworld_get_sprite_idx_by_species(u16 species) {
	overworld_sprite *sprite = overworld_sprite_get_by_species(species);
	if (sprite->width == 32 && sprite->height == 32)
		return OVERWORLD_SPRITE_POKEMON_32_32;
	if (sprite->width == 64 && sprite->height == 64)
		return OVERWORLD_SPRITE_POKEMON_64_64;
	derrf("No overworld sprite idx associated with measures %d, %d\n", sprite->width, sprite->height);
	return 0;
}