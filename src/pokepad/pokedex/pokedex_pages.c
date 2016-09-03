#include "types.h"
#include "basestats.h"
#include "pokedex.h"

// Habitat gras, page 0
u16 pokedex_habitat_gras_page_0[4] = {
	POKEMON_BRONZEL, POKEMON_BRONZONG, POKEMON_IGNIVOR, POKEMON_RAMOTH
};
// Habitat gras, page 1
u16 pokedex_habitat_gras_page_1[4] = {
	POKEMON_ZIGZACHS, POKEMON_GERADAKS, POKEMON_FIFFYEN, POKEMON_MAGNAYEN
};
// Habitat gras, page 2
u16 pokedex_habitat_gras_page_2[3] = {
	POKEMON_NIDORANW, POKEMON_NIDORINA, POKEMON_NIDOQUEEN
};
// Habitat gras, page 3
u16 pokedex_habitat_gras_page_3[3] = {
	POKEMON_NIDORANM, POKEMON_NIDORINO, POKEMON_NIDOKING
};
// Habitat gras, page 4
u16 pokedex_habitat_gras_page_4[4] = {
	POKEMON_DODU, POKEMON_DODRI, POKEMON_SCHWALBINI, POKEMON_SCHWALBOSS
};
// Habitat gras, page 5
u16 pokedex_habitat_gras_page_5[4] = {
	POKEMON_ZOBIRIS, POKEMON_ROSELIA, POKEMON_SHNEBEDECK, POKEMON_REXBLISAR
};
// Habitat gras, page 6
u16 pokedex_habitat_gras_page_6[3] = {
	POKEMON_LICHTEL, POKEMON_LATERNECTO, POKEMON_SKLELABRA
};
// Habitat gras, page 7
u16 pokedex_habitat_gras_page_7[4] = {
	POKEMON_MYRAPLA, POKEMON_DUFLOR, POKEMON_GIFLOR, POKEMON_BLUBELLA
};
// Habitat gras, page 8
u16 pokedex_habitat_gras_page_8[2] = {
	POKEMON_PARAGONI, POKEMON_TROMBORK
};
// Habitat gras, page 9
u16 pokedex_habitat_gras_page_9[3] = {
	POKEMON_FLABEBE, POKEMON_PUMMELUFF, POKEMON_KNUDDELUFF
};
// Habitat gras, page 10
u16 pokedex_habitat_gras_page_10[3] = {
	POKEMON_VOLTILAMM, POKEMON_WAATY, POKEMON_AMPHAROS
};
// Habitat gras, page 11
u16 pokedex_habitat_gras_page_11[2] = {
	POKEMON_PORENTA, POKEMON_SCHLURP
};
// Habitat gras, page 12
u16 pokedex_habitat_gras_page_12[2] = {
	POKEMON_SICHLOR, POKEMON_SCHEROX
};
// Habitat gras, page 13
u16 pokedex_habitat_gras_page_13[4] = {
	POKEMON_TRAUMATO, POKEMON_HYPNO, POKEMON_SCHLUPPUCK, POKEMON_SCHLUKWECH
};
// Habitat gras, page 14
u16 pokedex_habitat_gras_page_14[2] = {
	POKEMON_KANGAMA, POKEMON_SKORGRO
};
// Habitat gras, page 15
u16 pokedex_habitat_gras_page_15[2] = {
	POKEMON_TAUROS, POKEMON_MILTANK
};
// Habitat gras, page 16
u16 pokedex_habitat_gras_page_16[4] = {
	POKEMON_VULPIX, POKEMON_VULNONA, POKEMON_PONITA, POKEMON_GALLOPA
};
// Habitat gras, page 17
u16 pokedex_habitat_gras_page_17[4] = {
	POKEMON_ELEKID, POKEMON_ELEKTEK, POKEMON_FRIZELBLIZ, POKEMON_VOLTENSO
};
// Habitat gras, page 18
u16 pokedex_habitat_gras_page_18[2] = {
	POKEMON_SENGO, POKEMON_VIPITIS
};
// Habitat gras, page 19
u16 pokedex_habitat_gras_page_19[2] = {
	POKEMON_PLUSLE, POKEMON_MINUN
};
// Habitat gras, page 20
u16 pokedex_habitat_gras_page_20[2] = {
	POKEMON_FUKANO, POKEMON_ARKANI
};
// Habitat gras, page 21
u16 pokedex_habitat_gras_page_21[2] = {
	POKEMON_FORMEO, POKEMON_PALIMPALIM
};
// Habitat gras, page 22
u16 pokedex_habitat_gras_page_22[3] = {
	POKEMON_BISASAM, POKEMON_BISAKNOSP, POKEMON_BISAFLOR
};
// Habitat gras, page 23
u16 pokedex_habitat_gras_page_23[3] = {
	POKEMON_ENDIVIE, POKEMON_LORBLATT, POKEMON_MEGANIE
};
// Habitat gras, page 24
u16 pokedex_habitat_gras_page_24[3] = {
	POKEMON_FEURIGEL, POKEMON_IGELAVAR, POKEMON_TORNUPTO
};
// Habitat gras, page 25
u16 pokedex_habitat_gras_page_25[3] = {
	POKEMON_WELUNO, POKEMON_ORTHODOS, POKEMON_ZERBERTRES
};
// Habitat gras, page 26
u16 pokedex_habitat_gras_page_26[3] = {
	POKEMON_RAIKOU, POKEMON_ENTEI, POKEMON_SUICUNE
};
pokedex_page pokedex_habitat_gras_pages [27] = {
	{ pokedex_habitat_gras_page_0, 4},
	{ pokedex_habitat_gras_page_1, 4},
	{ pokedex_habitat_gras_page_2, 3},
	{ pokedex_habitat_gras_page_3, 3},
	{ pokedex_habitat_gras_page_4, 4},
	{ pokedex_habitat_gras_page_5, 4},
	{ pokedex_habitat_gras_page_6, 3},
	{ pokedex_habitat_gras_page_7, 4},
	{ pokedex_habitat_gras_page_8, 2},
	{ pokedex_habitat_gras_page_9, 3},
	{ pokedex_habitat_gras_page_10, 3},
	{ pokedex_habitat_gras_page_11, 2},
	{ pokedex_habitat_gras_page_12, 2},
	{ pokedex_habitat_gras_page_13, 4},
	{ pokedex_habitat_gras_page_14, 2},
	{ pokedex_habitat_gras_page_15, 2},
	{ pokedex_habitat_gras_page_16, 4},
	{ pokedex_habitat_gras_page_17, 4},
	{ pokedex_habitat_gras_page_18, 2},
	{ pokedex_habitat_gras_page_19, 2},
	{ pokedex_habitat_gras_page_20, 2},
	{ pokedex_habitat_gras_page_21, 2},
	{ pokedex_habitat_gras_page_22, 3},
	{ pokedex_habitat_gras_page_23, 3},
	{ pokedex_habitat_gras_page_24, 3},
	{ pokedex_habitat_gras_page_25, 3},
	{ pokedex_habitat_gras_page_26, 3}
};

// Habitat wald, page 0
u16 pokedex_habitat_wald_page_0[3] = {
	POKEMON_DARTIRI, POKEMON_DARTIGNIS, POKEMON_FIARO
};
// Habitat wald, page 1
u16 pokedex_habitat_wald_page_1[3] = {
	POKEMON_HORNLIU, POKEMON_KOKUNA, POKEMON_BIBOR
};
// Habitat wald, page 2
u16 pokedex_habitat_wald_page_2[3] = {
	POKEMON_WAUMPEL, POKEMON_SCHALOKO, POKEMON_PAPINELLA
};
// Habitat wald, page 3
u16 pokedex_habitat_wald_page_3[2] = {
	POKEMON_PANEKON, POKEMON_PUDOX
};
// Habitat wald, page 4
u16 pokedex_habitat_wald_page_4[3] = {
	POKEMON_STARALILI, POKEMON_STARAVIA, POKEMON_STARAPTOR
};
// Habitat wald, page 5
u16 pokedex_habitat_wald_page_5[4] = {
	POKEMON_GLAZIOLA, POKEMON_RESLADERO, POKEMON_NATU, POKEMON_XATU
};
// Habitat wald, page 6
u16 pokedex_habitat_wald_page_6[3] = {
	POKEMON_MAGNEZONE, POKEMON_PIKACHU, POKEMON_RAICHU
};
// Habitat wald, page 7
u16 pokedex_habitat_wald_page_7[3] = {
	POKEMON_KNOFENSA, POKEMON_ULTRIGARIA, POKEMON_SARZENIA
};
// Habitat wald, page 8
u16 pokedex_habitat_wald_page_8[4] = {
	POKEMON_FOLIPURBA, POKEMON_FEELINARA, POKEMON_KNILZ, POKEMON_KAPILZ
};
// Habitat wald, page 9
u16 pokedex_habitat_wald_page_9[3] = {
	POKEMON_SAMURZEL, POKEMON_BLANAS, POKEMON_TENGULIST
};
// Habitat wald, page 10
u16 pokedex_habitat_wald_page_10[3] = {
	POKEMON_WATTZAPF, POKEMON_VOLTULA, POKEMON_AMBIDIFFEL
};
// Habitat wald, page 11
u16 pokedex_habitat_wald_page_11[4] = {
	POKEMON_LEDYBA, POKEMON_LEDIAN, POKEMON_WEBARAK, POKEMON_ARIADOS
};
// Habitat wald, page 12
u16 pokedex_habitat_wald_page_12[3] = {
	POKEMON_NINCADA, POKEMON_NINJASK, POKEMON_NINJATOM
};
// Habitat wald, page 13
u16 pokedex_habitat_wald_page_13[2] = {
	POKEMON_VOLBEAT, POKEMON_ILLUMISE
};
// Habitat wald, page 14
u16 pokedex_habitat_wald_page_14[2] = {
	POKEMON_TANNZA, POKEMON_FORSTELLKA
};
// Habitat wald, page 15
u16 pokedex_habitat_wald_page_15[3] = {
	POKEMON_BUMMELZ, POKEMON_MUNTIER, POKEMON_LETARKING
};
// Habitat wald, page 16
u16 pokedex_habitat_wald_page_16[2] = {
	POKEMON_ENECO, POKEMON_ENEKORO
};
// Habitat wald, page 17
u16 pokedex_habitat_wald_page_17[2] = {
	POKEMON_KRAMURX, POKEMON_KRYPPUK
};
// Habitat wald, page 18
u16 pokedex_habitat_wald_page_18[3] = {
	POKEMON_OWEI, POKEMON_KOKOWEI, POKEMON_MOGELBAUM
};
// Habitat wald, page 19
u16 pokedex_habitat_wald_page_19[3] = {
	POKEMON_GRIFFEL, POKEMON_VOLUMINAS, POKEMON_KECLEON
};
// Habitat wald, page 20
u16 pokedex_habitat_wald_page_20[2] = {
	POKEMON_PINSIR, POKEMON_SKARABORN
};
// Habitat wald, page 21
u16 pokedex_habitat_wald_page_21[3] = {
	POKEMON_WABLU, POKEMON_ALTARIA, POKEMON_TROPIUS
};
// Habitat wald, page 22
u16 pokedex_habitat_wald_page_22[2] = {
	POKEMON_ZWIRRLICHT, POKEMON_ZWIRRKLOP
};
// Habitat wald, page 23
u16 pokedex_habitat_wald_page_23[2] = {
	POKEMON_TOGEPI, POKEMON_TOGETIC
};
// Habitat wald, page 24
u16 pokedex_habitat_wald_page_24[3] = {
	POKEMON_LOCKSCHAL, POKEMON_STICHSCHAL, POKEMON_STAHLSTICH
};
// Habitat wald, page 25
u16 pokedex_habitat_wald_page_25[1] = {
	POKEMON_CELEBI
};
pokedex_page pokedex_habitat_wald_pages [26] = {
	{ pokedex_habitat_wald_page_0, 3},
	{ pokedex_habitat_wald_page_1, 3},
	{ pokedex_habitat_wald_page_2, 3},
	{ pokedex_habitat_wald_page_3, 2},
	{ pokedex_habitat_wald_page_4, 3},
	{ pokedex_habitat_wald_page_5, 4},
	{ pokedex_habitat_wald_page_6, 3},
	{ pokedex_habitat_wald_page_7, 3},
	{ pokedex_habitat_wald_page_8, 4},
	{ pokedex_habitat_wald_page_9, 3},
	{ pokedex_habitat_wald_page_10, 3},
	{ pokedex_habitat_wald_page_11, 4},
	{ pokedex_habitat_wald_page_12, 3},
	{ pokedex_habitat_wald_page_13, 2},
	{ pokedex_habitat_wald_page_14, 2},
	{ pokedex_habitat_wald_page_15, 3},
	{ pokedex_habitat_wald_page_16, 2},
	{ pokedex_habitat_wald_page_17, 2},
	{ pokedex_habitat_wald_page_18, 3},
	{ pokedex_habitat_wald_page_19, 3},
	{ pokedex_habitat_wald_page_20, 2},
	{ pokedex_habitat_wald_page_21, 3},
	{ pokedex_habitat_wald_page_22, 2},
	{ pokedex_habitat_wald_page_23, 2},
	{ pokedex_habitat_wald_page_24, 3},
	{ pokedex_habitat_wald_page_25, 1}
};

// Habitat kueste, page 0
u16 pokedex_habitat_kueste_page_0[2] = {
	POKEMON_QUABBEL, POKEMON_APOQUALLYP
};
// Habitat kueste, page 1
u16 pokedex_habitat_kueste_page_1[4] = {
	POKEMON_KARPADOR, POKEMON_GARADOS, POKEMON_KRABBY, POKEMON_KINGLER
};
// Habitat kueste, page 2
u16 pokedex_habitat_kueste_page_2[4] = {
	POKEMON_KREBSCORPS, POKEMON_KREBUTACK, POKEMON_SCHMERBE, POKEMON_WELSAR
};
// Habitat kueste, page 3
u16 pokedex_habitat_kueste_page_3[3] = {
	POKEMON_LOTURZEL, POKEMON_LOMBRERO, POKEMON_KAPPALORES
};
// Habitat kueste, page 4
u16 pokedex_habitat_kueste_page_4[2] = {
	POKEMON_GEHWEIHER, POKEMON_MASKEREGEN
};
// Habitat kueste, page 5
u16 pokedex_habitat_kueste_page_5[4] = {
	POKEMON_ENTON, POKEMON_ENTORON, POKEMON_FELINO, POKEMON_MORLORD
};
// Habitat kueste, page 6
u16 pokedex_habitat_kueste_page_6[4] = {
	POKEMON_GRAMOKLES, POKEMON_DUOKLES, POKEMON_DURENGARD, POKEMON_CLAVION
};
// Habitat kueste, page 7
u16 pokedex_habitat_kueste_page_7[3] = {
	POKEMON_AZURILL, POKEMON_MARILL, POKEMON_AZUMARILL
};
// Habitat kueste, page 8
u16 pokedex_habitat_kueste_page_8[3] = {
	POKEMON_FLEGMON, POKEMON_LAHMUS, POKEMON_LASCHOKING
};
// Habitat kueste, page 9
u16 pokedex_habitat_kueste_page_9[2] = {
	POKEMON_BARSCHWA, POKEMON_MILOTIC
};
// Habitat kueste, page 10
u16 pokedex_habitat_kueste_page_10[2] = {
	POKEMON_ANORITH, POKEMON_ARMALDO
};
// Habitat kueste, page 11
u16 pokedex_habitat_kueste_page_11[3] = {
	POKEMON_DRATINI, POKEMON_DRAGONIR, POKEMON_DRAGORAN
};
// Habitat kueste, page 12
u16 pokedex_habitat_kueste_page_12[3] = {
	POKEMON_SCHIGGY, POKEMON_SCHILLOK, POKEMON_TURTOK
};
// Habitat kueste, page 13
u16 pokedex_habitat_kueste_page_13[3] = {
	POKEMON_KARNIMANI, POKEMON_TYRACROC, POKEMON_IMPERGATOR
};
// Habitat kueste, page 14
u16 pokedex_habitat_kueste_page_14[3] = {
	POKEMON_SEEKID, POKEMON_SEESKULL, POKEMON_SKULLYDRA
};
// Habitat kueste, page 15
u16 pokedex_habitat_kueste_page_15[2] = {
	POKEMON_LATIAS, POKEMON_LATIOS
};
pokedex_page pokedex_habitat_kueste_pages [16] = {
	{ pokedex_habitat_kueste_page_0, 2},
	{ pokedex_habitat_kueste_page_1, 4},
	{ pokedex_habitat_kueste_page_2, 4},
	{ pokedex_habitat_kueste_page_3, 3},
	{ pokedex_habitat_kueste_page_4, 2},
	{ pokedex_habitat_kueste_page_5, 4},
	{ pokedex_habitat_kueste_page_6, 4},
	{ pokedex_habitat_kueste_page_7, 3},
	{ pokedex_habitat_kueste_page_8, 3},
	{ pokedex_habitat_kueste_page_9, 2},
	{ pokedex_habitat_kueste_page_10, 2},
	{ pokedex_habitat_kueste_page_11, 3},
	{ pokedex_habitat_kueste_page_12, 3},
	{ pokedex_habitat_kueste_page_13, 3},
	{ pokedex_habitat_kueste_page_14, 3},
	{ pokedex_habitat_kueste_page_15, 2}
};

// Habitat wasser, page 0
u16 pokedex_habitat_wasser_page_0[2] = {
	POKEMON_TENTACHA, POKEMON_TENTOXA
};
// Habitat wasser, page 1
u16 pokedex_habitat_wasser_page_1[2] = {
	POKEMON_WINGULL, POKEMON_PELIPPER
};
// Habitat wasser, page 2
u16 pokedex_habitat_wasser_page_2[2] = {
	POKEMON_STERNDU, POKEMON_STARMIE
};
// Habitat wasser, page 3
u16 pokedex_habitat_wasser_page_3[4] = {
	POKEMON_LAMPI, POKEMON_LANTURN, POKEMON_REMORAID, POKEMON_OCTILLERY
};
// Habitat wasser, page 4
u16 pokedex_habitat_wasser_page_4[2] = {
	POKEMON_MUSCHAS, POKEMON_AUSTOS
};
// Habitat wasser, page 5
u16 pokedex_habitat_wasser_page_5[3] = {
	POKEMON_PERLU, POKEMON_AALABYSS, POKEMON_SAGANABYSS
};
// Habitat wasser, page 6
u16 pokedex_habitat_wasser_page_6[4] = {
	POKEMON_MAMUTEL, POKEMON_CORASONN, POKEMON_SCHLURPLEK, POKEMON_LIEBISKUS
};
// Habitat wasser, page 7
u16 pokedex_habitat_wasser_page_7[2] = {
	POKEMON_JURBO, POKEMON_JUGONG
};
// Habitat wasser, page 8
u16 pokedex_habitat_wasser_page_8[3] = {
	POKEMON_SEEMOPS, POKEMON_SEEJONG, POKEMON_WALRAISA
};
// Habitat wasser, page 9
u16 pokedex_habitat_wasser_page_9[4] = {
	POKEMON_KANIVANHA, POKEMON_TOHAIDO, POKEMON_WAILMER, POKEMON_WAILORD
};
// Habitat wasser, page 10
u16 pokedex_habitat_wasser_page_10[3] = {
	POKEMON_SEEPER, POKEMON_SEEMON, POKEMON_SEEDRAKING
};
// Habitat wasser, page 11
u16 pokedex_habitat_wasser_page_11[1] = {
	POKEMON_RELICANTH
};
// Habitat wasser, page 12
u16 pokedex_habitat_wasser_page_12[1] = {
	POKEMON_LAPRAS
};
// Habitat wasser, page 13
u16 pokedex_habitat_wasser_page_13[4] = {
	POKEMON_AMONITAS, POKEMON_AMOROSO, POKEMON_KABUTO, POKEMON_KABUTOPS
};
// Habitat wasser, page 14
u16 pokedex_habitat_wasser_page_14[2] = {
	POKEMON_LILIEP, POKEMON_WIELIE
};
// Habitat wasser, page 15
u16 pokedex_habitat_wasser_page_15[1] = {
	POKEMON_KYOGRE
};
pokedex_page pokedex_habitat_wasser_pages [16] = {
	{ pokedex_habitat_wasser_page_0, 2},
	{ pokedex_habitat_wasser_page_1, 2},
	{ pokedex_habitat_wasser_page_2, 2},
	{ pokedex_habitat_wasser_page_3, 4},
	{ pokedex_habitat_wasser_page_4, 2},
	{ pokedex_habitat_wasser_page_5, 3},
	{ pokedex_habitat_wasser_page_6, 4},
	{ pokedex_habitat_wasser_page_7, 2},
	{ pokedex_habitat_wasser_page_8, 3},
	{ pokedex_habitat_wasser_page_9, 4},
	{ pokedex_habitat_wasser_page_10, 3},
	{ pokedex_habitat_wasser_page_11, 1},
	{ pokedex_habitat_wasser_page_12, 1},
	{ pokedex_habitat_wasser_page_13, 4},
	{ pokedex_habitat_wasser_page_14, 2},
	{ pokedex_habitat_wasser_page_15, 1}
};

// Habitat hoehle, page 0
u16 pokedex_habitat_hoehle_page_0[3] = {
	POKEMON_ZUBAT, POKEMON_GOLBAT, POKEMON_IKSBAT
};
// Habitat hoehle, page 1
u16 pokedex_habitat_hoehle_page_1[4] = {
	POKEMON_DIGDA, POKEMON_DIGDRI, POKEMON_ONIX, POKEMON_STAHLOS
};
// Habitat hoehle, page 2
u16 pokedex_habitat_hoehle_page_2[4] = {
	POKEMON_QUIEKEL, POKEMON_KEIFEL, POKEMON_SCHNEPPKE, POKEMON_FIRNONTOR
};
// Habitat hoehle, page 3
u16 pokedex_habitat_hoehle_page_3[3] = {
	POKEMON_KAUMALAT, POKEMON_KNARKSEL, POKEMON_KNAKRACK
};
// Habitat hoehle, page 4
u16 pokedex_habitat_hoehle_page_4[3] = {
	POKEMON_KRAMSHEF, POKEMON_ELEVOLTEK, POKEMON_NASGNET
};
// Habitat hoehle, page 5
u16 pokedex_habitat_hoehle_page_5[2] = {
	POKEMON_ZWIRRFINST, POKEMON_FLUNKIFER
};
// Habitat hoehle, page 6
u16 pokedex_habitat_hoehle_page_6[3] = {
	POKEMON_NEBULAK, POKEMON_ALPOLLO, POKEMON_GENGAR
};
// Habitat hoehle, page 7
u16 pokedex_habitat_hoehle_page_7[2] = {
	POKEMON_ISSO, POKEMON_FROSDEDJE
};
// Habitat hoehle, page 8
u16 pokedex_habitat_hoehle_page_8[2] = {
	POKEMON_LUNASTEIN, POKEMON_SONNFEL
};
// Habitat hoehle, page 9
u16 pokedex_habitat_hoehle_page_9[3] = {
	POKEMON_REGIROCK, POKEMON_REGICE, POKEMON_REGISTEEL
};
pokedex_page pokedex_habitat_hoehle_pages [10] = {
	{ pokedex_habitat_hoehle_page_0, 3},
	{ pokedex_habitat_hoehle_page_1, 4},
	{ pokedex_habitat_hoehle_page_2, 4},
	{ pokedex_habitat_hoehle_page_3, 3},
	{ pokedex_habitat_hoehle_page_4, 3},
	{ pokedex_habitat_hoehle_page_5, 2},
	{ pokedex_habitat_hoehle_page_6, 3},
	{ pokedex_habitat_hoehle_page_7, 2},
	{ pokedex_habitat_hoehle_page_8, 2},
	{ pokedex_habitat_hoehle_page_9, 3}
};

// Habitat berg, page 0
u16 pokedex_habitat_berg_page_0[3] = {
	POKEMON_KLEINSTEIN, POKEMON_GEOROK, POKEMON_GEOWAZ
};
// Habitat berg, page 1
u16 pokedex_habitat_berg_page_1[4] = {
	POKEMON_MENKI, POKEMON_RASAFF, POKEMON_SPOINK, POKEMON_GROINK
};
// Habitat berg, page 2
u16 pokedex_habitat_berg_page_2[3] = {
	POKEMON_MACHOLLO, POKEMON_MASCHOCK, POKEMON_MACHOMEI
};
// Habitat berg, page 3
u16 pokedex_habitat_berg_page_3[3] = {
	POKEMON_TOGEKISS, POKEMON_FLOETTE, POKEMON_FLORGES
};
// Habitat berg, page 4
u16 pokedex_habitat_berg_page_4[2] = {
	POKEMON_TRAGOSSO, POKEMON_KNOGGA
};
// Habitat berg, page 5
u16 pokedex_habitat_berg_page_5[4] = {
	POKEMON_SCHNECKMAG, POKEMON_MAGCARGO, POKEMON_CAMAUB, POKEMON_CAMERUPT
};
// Habitat berg, page 6
u16 pokedex_habitat_berg_page_6[4] = {
	POKEMON_RIOLU, POKEMON_LUCARIO, POKEMON_MEDITIE, POKEMON_MEDITALIS
};
// Habitat berg, page 7
u16 pokedex_habitat_berg_page_7[4] = {
	POKEMON_POTTROTT, POKEMON_TEDDIURSA, POKEMON_URSARING, POKEMON_BOTOGEL
};
// Habitat berg, page 8
u16 pokedex_habitat_berg_page_8[2] = {
	POKEMON_SKORGLA, POKEMON_PANDIR
};
// Habitat berg, page 9
u16 pokedex_habitat_berg_page_9[3] = {
	POKEMON_MAGBY, POKEMON_MAGMAR, POKEMON_MAGBRANT
};
// Habitat berg, page 10
u16 pokedex_habitat_berg_page_10[3] = {
	POKEMON_STOLLUNIOR, POKEMON_STOLLRAK, POKEMON_STOLLOSS
};
// Habitat berg, page 11
u16 pokedex_habitat_berg_page_11[3] = {
	POKEMON_LARVITAR, POKEMON_PUPITAR, POKEMON_DESPOTAR
};
// Habitat berg, page 12
u16 pokedex_habitat_berg_page_12[1] = {
	POKEMON_RELAXO
};
// Habitat berg, page 13
u16 pokedex_habitat_berg_page_13[1] = {
	POKEMON_ABSOL
};
// Habitat berg, page 14
u16 pokedex_habitat_berg_page_14[1] = {
	POKEMON_AERODACTYL
};
// Habitat berg, page 15
u16 pokedex_habitat_berg_page_15[3] = {
	POKEMON_GLUMANDA, POKEMON_GLUTEXO, POKEMON_GLURAK
};
// Habitat berg, page 16
u16 pokedex_habitat_berg_page_16[1] = {
	POKEMON_JIRACHI
};
pokedex_page pokedex_habitat_berg_pages [17] = {
	{ pokedex_habitat_berg_page_0, 3},
	{ pokedex_habitat_berg_page_1, 4},
	{ pokedex_habitat_berg_page_2, 3},
	{ pokedex_habitat_berg_page_3, 3},
	{ pokedex_habitat_berg_page_4, 2},
	{ pokedex_habitat_berg_page_5, 4},
	{ pokedex_habitat_berg_page_6, 4},
	{ pokedex_habitat_berg_page_7, 4},
	{ pokedex_habitat_berg_page_8, 2},
	{ pokedex_habitat_berg_page_9, 3},
	{ pokedex_habitat_berg_page_10, 3},
	{ pokedex_habitat_berg_page_11, 3},
	{ pokedex_habitat_berg_page_12, 1},
	{ pokedex_habitat_berg_page_13, 1},
	{ pokedex_habitat_berg_page_14, 1},
	{ pokedex_habitat_berg_page_15, 3},
	{ pokedex_habitat_berg_page_16, 1}
};

// Habitat wildnis, page 0
u16 pokedex_habitat_wildnis_page_0[2] = {
	POKEMON_MAEHIKEL, POKEMON_CHEVRUMM
};
// Habitat wildnis, page 1
u16 pokedex_habitat_wildnis_page_1[4] = {
	POKEMON_SANDAN, POKEMON_SANDAMER, POKEMON_RIHORN, POKEMON_RIZEROS
};
// Habitat wildnis, page 2
u16 pokedex_habitat_wildnis_page_2[2] = {
	POKEMON_MAGNETILO, POKEMON_MAGNETON
};
// Habitat wildnis, page 3
u16 pokedex_habitat_wildnis_page_3[4] = {
	POKEMON_HUNDUSTER, POKEMON_HUNDEMON, POKEMON_PHANPY, POKEMON_DONPHAN
};
// Habitat wildnis, page 4
u16 pokedex_habitat_wildnis_page_4[2] = {
	POKEMON_TUSKA, POKEMON_NOKTUSKA
};
// Habitat wildnis, page 5
u16 pokedex_habitat_wildnis_page_5[3] = {
	POKEMON_KNACKLION, POKEMON_VIBRAVA, POKEMON_LIBELLDRA
};
// Habitat wildnis, page 6
u16 pokedex_habitat_wildnis_page_6[1] = {
	POKEMON_PANZAERON
};
// Habitat wildnis, page 7
u16 pokedex_habitat_wildnis_page_7[2] = {
	POKEMON_PUPPANCE, POKEMON_LEPUMENTAS
};
// Habitat wildnis, page 8
u16 pokedex_habitat_wildnis_page_8[3] = {
	POKEMON_KINDWURM, POKEMON_DRASCHEL, POKEMON_BRUTALANDA
};
// Habitat wildnis, page 9
u16 pokedex_habitat_wildnis_page_9[3] = {
	POKEMON_TANHEL, POKEMON_METANG, POKEMON_METAGROSS
};
// Habitat wildnis, page 10
u16 pokedex_habitat_wildnis_page_10[1] = {
	POKEMON_GROUDON
};
pokedex_page pokedex_habitat_wildnis_pages [11] = {
	{ pokedex_habitat_wildnis_page_0, 2},
	{ pokedex_habitat_wildnis_page_1, 4},
	{ pokedex_habitat_wildnis_page_2, 2},
	{ pokedex_habitat_wildnis_page_3, 4},
	{ pokedex_habitat_wildnis_page_4, 2},
	{ pokedex_habitat_wildnis_page_5, 3},
	{ pokedex_habitat_wildnis_page_6, 1},
	{ pokedex_habitat_wildnis_page_7, 2},
	{ pokedex_habitat_wildnis_page_8, 3},
	{ pokedex_habitat_wildnis_page_9, 3},
	{ pokedex_habitat_wildnis_page_10, 1}
};

// Habitat stadt, page 0
u16 pokedex_habitat_stadt_page_0[4] = {
	POKEMON_KASTADUR, POKEMON_TENTANTEL, POKEMON_SNUBBULL, POKEMON_GRANBULL
};
// Habitat stadt, page 1
u16 pokedex_habitat_stadt_page_1[4] = {
	POKEMON_SLEIMA, POKEMON_SLEIMOK, POKEMON_SMOGON, POKEMON_SMOGMOG
};
// Habitat stadt, page 2
u16 pokedex_habitat_stadt_page_2[2] = {
	POKEMON_SHUPPET, POKEMON_BANETTE
};
// Habitat stadt, page 3
u16 pokedex_habitat_stadt_page_3[3] = {
	POKEMON_ABRA, POKEMON_KADABRA, POKEMON_SIMSALA
};
// Habitat stadt, page 4
u16 pokedex_habitat_stadt_page_4[3] = {
	POKEMON_TRASLA, POKEMON_KIRLIA, POKEMON_GUARDEVOIR
};
// Habitat stadt, page 5
u16 pokedex_habitat_stadt_page_5[4] = {
	POKEMON_KUSSILLA, POKEMON_GALAGLADI, POKEMON_TRAUNFUGIL, POKEMON_TRAUNMAGIL
};
// Habitat stadt, page 6
u16 pokedex_habitat_stadt_page_6[4] = {
	POKEMON_RABAUZ, POKEMON_KICKLEE, POKEMON_NOCKCHAN, POKEMON_KAPOERA
};
// Habitat stadt, page 7
u16 pokedex_habitat_stadt_page_7[2] = {
	POKEMON_CHANEIRA, POKEMON_HEITEIRA
};
// Habitat stadt, page 8
u16 pokedex_habitat_stadt_page_8[4] = {
	POKEMON_VOLTOBAL, POKEMON_LEKTROBAL, POKEMON_PORYGON, POKEMON_PORYGON2
};
// Habitat stadt, page 9
u16 pokedex_habitat_stadt_page_9[1] = {
	POKEMON_DITTO
};
// Habitat stadt, page 10
u16 pokedex_habitat_stadt_page_10[4] = {
	POKEMON_EVOLI, POKEMON_AQUANA, POKEMON_BLITZA, POKEMON_FLAMARA
};
// Habitat stadt, page 11
u16 pokedex_habitat_stadt_page_11[2] = {
	POKEMON_PSIANA, POKEMON_NACHTARA
};
pokedex_page pokedex_habitat_stadt_pages [12] = {
	{ pokedex_habitat_stadt_page_0, 4},
	{ pokedex_habitat_stadt_page_1, 4},
	{ pokedex_habitat_stadt_page_2, 2},
	{ pokedex_habitat_stadt_page_3, 3},
	{ pokedex_habitat_stadt_page_4, 3},
	{ pokedex_habitat_stadt_page_5, 4},
	{ pokedex_habitat_stadt_page_6, 4},
	{ pokedex_habitat_stadt_page_7, 2},
	{ pokedex_habitat_stadt_page_8, 4},
	{ pokedex_habitat_stadt_page_9, 1},
	{ pokedex_habitat_stadt_page_10, 4},
	{ pokedex_habitat_stadt_page_11, 2}
};

// Habitat selten, page 0
u16 pokedex_habitat_selten_page_0[1] = {
	POKEMON_ICOGNITO
};
// Habitat selten, page 1
u16 pokedex_habitat_selten_page_1[3] = {
	POKEMON_ARKTOS, POKEMON_ZAPDOS, POKEMON_LAVADOS
};
// Habitat selten, page 2
u16 pokedex_habitat_selten_page_2[1] = {
	POKEMON_LUGIA
};
// Habitat selten, page 3
u16 pokedex_habitat_selten_page_3[1] = {
	POKEMON_HO_OH
};
// Habitat selten, page 4
u16 pokedex_habitat_selten_page_4[1] = {
	POKEMON_RAYQUAZA
};
// Habitat selten, page 5
u16 pokedex_habitat_selten_page_5[1] = {
	POKEMON_DEOXYS
};
// Habitat selten, page 6
u16 pokedex_habitat_selten_page_6[1] = {
	POKEMON_MEWTU
};
// Habitat selten, page 7
u16 pokedex_habitat_selten_page_7[1] = {
	POKEMON_MEW
};

u16 pokedex_habitat_selten_page_8[1] = {
    POKEMON_TEST
};
pokedex_page pokedex_habitat_selten_pages [9] = {
	{ pokedex_habitat_selten_page_0, 1},
	{ pokedex_habitat_selten_page_1, 3},
	{ pokedex_habitat_selten_page_2, 1},
	{ pokedex_habitat_selten_page_3, 1},
	{ pokedex_habitat_selten_page_4, 1},
	{ pokedex_habitat_selten_page_5, 1},
	{ pokedex_habitat_selten_page_6, 1},
	{ pokedex_habitat_selten_page_7, 1},
        { pokedex_habitat_selten_page_8, 1}
};



pokedex_habitat pokedex_habitats [9] = {
	{pokedex_habitat_gras_pages, 27},
	{pokedex_habitat_wald_pages, 26},
	{pokedex_habitat_kueste_pages, 16},
	{pokedex_habitat_wasser_pages, 16},
	{pokedex_habitat_hoehle_pages, 10},
	{pokedex_habitat_berg_pages, 17},
	{pokedex_habitat_wildnis_pages, 11},
	{pokedex_habitat_stadt_pages, 12},
	{pokedex_habitat_selten_pages, 9}
};


