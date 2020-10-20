/*
 * pokedex_order_before_alpha_2_2.c
 *
 *  Created on: Sep 26, 2018
 *      Author: dominik
 */
#include "types.h"
#include "pokemon/count.h"
#include "pokepad/pokedex/operator.h"
#include "mega.h"
#include "save.h"
#include "agbmemory.h"
#include "pokemon/virtual.h"
#include "version.h"
#include "constants/pokemon_attributes.h"
#include "prng.h"

void version_alpha_2_2_fix_pid(box_pokemon *target) {
	if (box_pokemon_get_attribute(target, ATTRIBUTE_SPECIES, 0) == 0) return;
	_pid_t_old old = {.value = (u32)box_pokemon_get_attribute(target, ATTRIBUTE_PID, 0)};
	pid_t p = {.value = 0};
	p.fields.ability = old.fields.ability;
	p.fields.gender_partial = old.fields.gender_partial;
	p.fields.is_shiny = old.fields.shinyness <= 512 ? 1 : 0;
	int nature = old.fields.nature;
	if (nature >= 25) nature /= 2;
	p.fields.nature = (u8)(nature & 31);
	p.fields.form = 0;
	p.fields.hidden_power_type = (u8)((rnd16() % 18) & 31);
	p.fields.hidden_power_strength = (u8)(rnd16() & 7);
	box_pokemon_set_attribute(target, ATTRIBUTE_PID, &p);
}

u16 pokedex_order_old[POKEMON_CNT - 1] = {
    // POKEMON_BISASAM
    0x1,
    // POKEMON_BISAKNOSP
    0x2,
    // POKEMON_BISAFLOR
    0x3,
    // POKEMON_GLUMANDA
    0x4,
    // POKEMON_GLUTEXO
    0x5,
    // POKEMON_GLURAK
    0x6,
    // POKEMON_SCHIGGY
    0x7,
    // POKEMON_SCHILLOK
    0x8,
    // POKEMON_TURTOK
    0x9,
    // POKEMON_DARTIRI
    0xa,
    // POKEMON_DARTIGNIS
    0xb,
    // POKEMON_FIARO
    0xc,
    // POKEMON_HORNLIU
    0xd,
    // POKEMON_KOKUNA
    0xe,
    // POKEMON_BIBOR
    0xf,
    // POKEMON_STARALILI
    0x10,
    // POKEMON_STARAVIA
    0x11,
    // POKEMON_STARAPTOR
    0x12,
    // POKEMON_BRONZEL
    0x13,
    // POKEMON_BRONZONG
    0x14,
    // POKEMON_MAEHIKEL
    0x15,
    // POKEMON_CHEVRUMM
    0x16,
    // POKEMON_PARAGONI
    0x17,
    // POKEMON_TROMBORK
    0x18,
    // POKEMON_PIKACHU
    0x19,
    // POKEMON_RAICHU
    0x1a,
    // POKEMON_SANDAN
    0x1b,
    // POKEMON_SANDAMER
    0x1c,
    // POKEMON_NIDORANW
    0x1d,
    // POKEMON_NIDORINA
    0x1e,
    // POKEMON_NIDOQUEEN
    0x1f,
    // POKEMON_NIDORANM
    0x20,
    // POKEMON_NIDORINO
    0x21,
    // POKEMON_NIDOKING
    0x22,
    // POKEMON_FLOETTE
    0x23,
    // POKEMON_FLORGES
    0x24,
    // POKEMON_VULPIX
    0x25,
    // POKEMON_VULNONA
    0x26,
    // POKEMON_PUMMELUFF
    0x27,
    // POKEMON_KNUDDELUFF
    0x28,
    // POKEMON_ZUBAT
    0x29,
    // POKEMON_GOLBAT
    0x2a,
    // POKEMON_MYRAPLA
    0x2b,
    // POKEMON_DUFLOR
    0x2c,
    // POKEMON_GIFLOR
    0x2d,
    // POKEMON_FOLIPURBA
    0x2e,
    // POKEMON_FEELINARA
    0x2f,
    // POKEMON_WATTZAPF
    0x30,
    // POKEMON_VOLTULA
    0x31,
    // POKEMON_DIGDA
    0x32,
    // POKEMON_DIGDRI
    0x33,
    // POKEMON_KASTADUR
    0x34,
    // POKEMON_TENTANTEL
    0x35,
    // POKEMON_ENTON
    0x36,
    // POKEMON_ENTORON
    0x37,
    // POKEMON_MENKI
    0x38,
    // POKEMON_RASAFF
    0x39,
    // POKEMON_FUKANO
    0x3a,
    // POKEMON_ARKANI
    0x3b,
    // POKEMON_GRAMOKLES
    0x3c,
    // POKEMON_DUOKLES
    0x3d,
    // POKEMON_DURENGARD
    0x3e,
    // POKEMON_ABRA
    0x3f,
    // POKEMON_KADABRA
    0x40,
    // POKEMON_SIMSALA
    0x41,
    // POKEMON_MACHOLLO
    0x42,
    // POKEMON_MASCHOCK
    0x43,
    // POKEMON_MACHOMEI
    0x44,
    // POKEMON_KNOFENSA
    0x45,
    // POKEMON_ULTRIGARIA
    0x46,
    // POKEMON_SARZENIA
    0x47,
    // POKEMON_TENTACHA
    0x48,
    // POKEMON_TENTOXA
    0x49,
    // POKEMON_KLEINSTEIN
    0x4a,
    // POKEMON_GEOROK
    0x4b,
    // POKEMON_GEOWAZ
    0x4c,
    // POKEMON_PONITA
    0x4d,
    // POKEMON_GALLOPA
    0x4e,
    // POKEMON_FLEGMON
    0x4f,
    // POKEMON_LAHMUS
    0x50,
    // POKEMON_MAGNETILO
    0x51,
    // POKEMON_MAGNETON
    0x52,
    // POKEMON_PORENTA
    0x53,
    // POKEMON_DODU
    0x54,
    // POKEMON_DODRI
    0x55,
    // POKEMON_JURBO
    0x56,
    // POKEMON_JUGONG
    0x57,
    // POKEMON_SLEIMA
    0x58,
    // POKEMON_SLEIMOK
    0x59,
    // POKEMON_MUSCHAS
    0x5a,
    // POKEMON_AUSTOS
    0x5b,
    // POKEMON_NEBULAK
    0x5c,
    // POKEMON_ALPOLLO
    0x5d,
    // POKEMON_GENGAR
    0x5e,
    // POKEMON_ONIX
    0x5f,
    // POKEMON_TRAUMATO
    0x60,
    // POKEMON_HYPNO
    0x61,
    // POKEMON_KRABBY
    0x62,
    // POKEMON_KINGLER
    0x63,
    // POKEMON_VOLTOBAL
    0x64,
    // POKEMON_LEKTROBAL
    0x65,
    // POKEMON_OWEI
    0x66,
    // POKEMON_KOKOWEI
    0x67,
    // POKEMON_TRAGOSSO
    0x68,
    // POKEMON_KNOGGA
    0x69,
    // POKEMON_KICKLEE
    0x6a,
    // POKEMON_NOCKCHAN
    0x6b,
    // POKEMON_SCHLURP
    0x6c,
    // POKEMON_SMOGON
    0x6d,
    // POKEMON_SMOGMOG
    0x6e,
    // POKEMON_RIHORN
    0x6f,
    // POKEMON_RIZEROS
    0x70,
    // POKEMON_CHANEIRA
    0x71,
    // POKEMON_ZOBIRIS
    0x72,
    // POKEMON_KANGAMA
    0x73,
    // POKEMON_SEEPER
    0x74,
    // POKEMON_SEEMON
    0x75,
    // POKEMON_QUABBEL
    0x76,
    // POKEMON_APOQUALLYP
    0x77,
    // POKEMON_STERNDU
    0x78,
    // POKEMON_STARMIE
    0x79,
    // POKEMON_TRAUNFUGIL
    0x7a,
    // POKEMON_SICHLOR
    0x7b,
    // POKEMON_GALAGLADI
    0x7c,
    // POKEMON_ELEKTEK
    0x7d,
    // POKEMON_MAGMAR
    0x7e,
    // POKEMON_PINSIR
    0x7f,
    // POKEMON_TAUROS
    0x80,
    // POKEMON_KARPADOR
    0x81,
    // POKEMON_GARADOS
    0x82,
    // POKEMON_LAPRAS
    0x83,
    // POKEMON_DITTO
    0x84,
    // POKEMON_EVOLI
    0x85,
    // POKEMON_AQUANA
    0x86,
    // POKEMON_BLITZA
    0x87,
    // POKEMON_FLAMARA
    0x88,
    // POKEMON_PORYGON
    0x89,
    // POKEMON_AMONITAS
    0x8a,
    // POKEMON_AMOROSO
    0x8b,
    // POKEMON_KABUTO
    0x8c,
    // POKEMON_KABUTOPS
    0x8d,
    // POKEMON_AERODACTYL
    0x8e,
    // POKEMON_RELAXO
    0x8f,
    // POKEMON_ARKTOS
    0x90,
    // POKEMON_ZAPDOS
    0x91,
    // POKEMON_LAVADOS
    0x92,
    // POKEMON_DRATINI
    0x93,
    // POKEMON_DRAGONIR
    0x94,
    // POKEMON_DRAGORAN
    0x95,
    // POKEMON_MEWTU
    0x96,
    // POKEMON_MEW
    0x97,
    // POKEMON_ENDIVIE
    0x98,
    // POKEMON_LORBLATT
    0x99,
    // POKEMON_MEGANIE
    0x9a,
    // POKEMON_FEURIGEL
    0x9b,
    // POKEMON_IGELAVAR
    0x9c,
    // POKEMON_TORNUPTO
    0x9d,
    // POKEMON_KARNIMANI
    0x9e,
    // POKEMON_TYRACROC
    0x9f,
    // POKEMON_IMPERGATOR
    0xa0,
    // POKEMON_IGNIVOR
    0xa1,
    // POKEMON_RAMOTH
    0xa2,
    // POKEMON_GLAZIOLA
    0xa3,
    // POKEMON_RESLADERO
    0xa4,
    // POKEMON_LEDYBA
    0xa5,
    // POKEMON_LEDIAN
    0xa6,
    // POKEMON_WEBARAK
    0xa7,
    // POKEMON_ARIADOS
    0xa8,
    // POKEMON_IKSBAT
    0xa9,
    // POKEMON_LAMPI
    0xaa,
    // POKEMON_LANTURN
    0xab,
    // POKEMON_MAGNEZONE
    0xac,
    // POKEMON_TOGEKISS
    0xad,
    // POKEMON_FLABEBE
    0xae,
    // POKEMON_TOGEPI
    0xaf,
    // POKEMON_TOGETIC
    0xb0,
    // POKEMON_NATU
    0xb1,
    // POKEMON_XATU
    0xb2,
    // POKEMON_VOLTILAMM
    0xb3,
    // POKEMON_WAATY
    0xb4,
    // POKEMON_AMPHAROS
    0xb5,
    // POKEMON_BLUBELLA
    0xb6,
    // POKEMON_MARILL
    0xb7,
    // POKEMON_AZUMARILL
    0xb8,
    // POKEMON_MOGELBAUM
    0xb9,
    // POKEMON_CLAVION
    0xba,
    // POKEMON_LICHTEL
    0xbb,
    // POKEMON_LATERNECTO
    0xbc,
    // POKEMON_SKLELABRA
    0xbd,
    // POKEMON_GRIFFEL
    0xbe,
    // POKEMON_SHNEBEDECK
    0xbf,
    // POKEMON_REXBLISAR
    0xc0,
    // POKEMON_AMBIDIFFEL
    0xc1,
    // POKEMON_FELINO
    0xc2,
    // POKEMON_MORLORD
    0xc3,
    // POKEMON_PSIANA
    0xc4,
    // POKEMON_NACHTARA
    0xc5,
    // POKEMON_KRAMURX
    0xc6,
    // POKEMON_LASCHOKING
    0xc7,
    // POKEMON_KRAMSHEF
    0xc8,
    // POKEMON_ICOGNITO
    0xc9,
    // POKEMON_FROSDEDJE
    0xca,
    // POKEMON_SKORGRO
    0xcb,
    // POKEMON_TANNZA
    0xcc,
    // POKEMON_FORSTELLKA
    0xcd,
    // POKEMON_ELEVOLTEK
    0xce,
    // POKEMON_SKORGLA
    0xcf,
    // POKEMON_STAHLOS
    0xd0,
    // POKEMON_SNUBBULL
    0xd1,
    // POKEMON_GRANBULL
    0xd2,
    // POKEMON_MAMUTEL
    0xd3,
    // POKEMON_SCHEROX
    0xd4,
    // POKEMON_POTTROTT
    0xd5,
    // POKEMON_SKARABORN
    0xd6,
    // POKEMON_KRYPPUK
    0xd7,
    // POKEMON_TEDDIURSA
    0xd8,
    // POKEMON_URSARING
    0xd9,
    // POKEMON_SCHNECKMAG
    0xda,
    // POKEMON_MAGCARGO
    0xdb,
    // POKEMON_QUIEKEL
    0xdc,
    // POKEMON_KEIFEL
    0xdd,
    // POKEMON_CORASONN
    0xde,
    // POKEMON_REMORAID
    0xdf,
    // POKEMON_OCTILLERY
    0xe0,
    // POKEMON_BOTOGEL
    0xe1,
    // POKEMON_SCHLURPLEK
    0xe2,
    // POKEMON_PANZAERON
    0xe3,
    // POKEMON_HUNDUSTER
    0xe4,
    // POKEMON_HUNDEMON
    0xe5,
    // POKEMON_SEEDRAKING
    0xe6,
    // POKEMON_PHANPY
    0xe7,
    // POKEMON_DONPHAN
    0xe8,
    // POKEMON_PORYGON2
    0xe9,
    // POKEMON_VOLUMINAS
    0xea,
    // POKEMON_TRAUNMAGIL
    0xeb,
    // POKEMON_RABAUZ
    0xec,
    // POKEMON_KAPOERA
    0xed,
    // POKEMON_KUSSILLA
    0xee,
    // POKEMON_ELEKID
    0xef,
    // POKEMON_MAGBY
    0xf0,
    // POKEMON_MILTANK
    0xf1,
    // POKEMON_HEITEIRA
    0xf2,
    // POKEMON_RAIKOU
    0xf3,
    // POKEMON_ENTEI
    0xf4,
    // POKEMON_SUICUNE
    0xf5,
    // POKEMON_LARVITAR
    0xf6,
    // POKEMON_PUPITAR
    0xf7,
    // POKEMON_DESPOTAR
    0xf8,
    // POKEMON_LUGIA
    0xf9,
    // POKEMON_HO_OH
    0xfa,
    // POKEMON_CELEBI
    0xfb,
    // POKEMON_BISAFLORM
    0,
    // POKEMON_GLURAKM
    0,
    // POKEMON_AQUANAM
    0,
    // POKEMON_BLITZAM
    0,
    // POKEMON_FLAMARM
    0,
    // POKEMON_DURENGARDA
    0,
    // POKEMON_IN
    0,
    // POKEMON_GAME
    0,
    // POKEMON_TURTOKM
    0,
    // POKEMON_AMPHARAOSM
    0,
    // POKEMON_GENGARM
    0,
    // POKEMON_BIBORM
    0,
    // POKEMON_ALTARIAM
    0,
    // POKEMON_GEOWAZM
    0,
    // POKEMON_SENGOM
    0,
    // POKEMON_VIPITISM
    0,
    // POKEMON_ZOBIRISM
    0,
    // POKEMON_10d
    0,
    // POKEMON_10e
    0,
    // POKEMON_10f
    0,
    // POKEMON_110
    0,
    // POKEMON_111
    0,
    // POKEMON_112
    0,
    // POKEMON_113
    0,
    // POKEMON_114
    0,
    // POKEMON_LOCKSCHAL
    0xfc,
    // POKEMON_STICHSCHAL
    0xfd,
    // POKEMON_STAHLSTICH
    0xfe,
    // POKEMON_WELUNO
    0xff,
    // POKEMON_ORTHODOS
    0x100,
    // POKEMON_ZERBERTRES
    0x101,
    // POKEMON_SEEKID
    0x102,
    // POKEMON_SEESKULL
    0x103,
    // POKEMON_SKULLYDRA
    0x104,
    // POKEMON_FIFFYEN
    0x105,
    // POKEMON_MAGNAYEN
    0x106,
    // POKEMON_ZIGZACHS
    0x107,
    // POKEMON_GERADAKS
    0x108,
    // POKEMON_WAUMPEL
    0x109,
    // POKEMON_SCHALOKO
    0x10a,
    // POKEMON_PAPINELLA
    0x10b,
    // POKEMON_PANEKON
    0x10c,
    // POKEMON_PUDOX
    0x10d,
    // POKEMON_LOTURZEL
    0x10e,
    // POKEMON_LOMBRERO
    0x10f,
    // POKEMON_KAPPALORES
    0x110,
    // POKEMON_SAMURZEL
    0x111,
    // POKEMON_BLANAS
    0x112,
    // POKEMON_TENGULIST
    0x113,
    // POKEMON_NINCADA
    0x122,
    // POKEMON_NINJASK
    0x123,
    // POKEMON_NINJATOM
    0x124,
    // POKEMON_SCHWALBINI
    0x114,
    // POKEMON_SCHWALBOSS
    0x115,
    // POKEMON_KNILZ
    0x11d,
    // POKEMON_KAPILZ
    0x11e,
    // POKEMON_PANDIR
    0x147,
    // POKEMON_WINGULL
    0x116,
    // POKEMON_PELIPPER
    0x117,
    // POKEMON_GEHWEIHER
    0x11b,
    // POKEMON_MASKEREGEN
    0x11c,
    // POKEMON_WAILMER
    0x140,
    // POKEMON_WAILORD
    0x141,
    // POKEMON_ENECO
    0x12c,
    // POKEMON_ENEKORO
    0x12d,
    // POKEMON_KECLEON
    0x160,
    // POKEMON_PUPPANCE
    0x157,
    // POKEMON_LEPUMENTAS
    0x158,
    // POKEMON_NASGNET
    0x12b,
    // POKEMON_MAGBRANT
    0x144,
    // POKEMON_ZWIRRFINST
    0x12e,
    // POKEMON_SCHMERBE
    0x153,
    // POKEMON_WELSAR
    0x154,
    // POKEMON_LIEBISKUS
    0x172,
    // POKEMON_KREBSCORPS
    0x155,
    // POKEMON_KREBUTACK
    0x156,
    // POKEMON_BARSCHWA
    0x15d,
    // POKEMON_MILOTIC
    0x15e,
    // POKEMON_KANIVANHA
    0x13e,
    // POKEMON_TOHAIDO
    0x13f,
    // POKEMON_KNACKLION
    0x148,
    // POKEMON_VIBRAVA
    0x149,
    // POKEMON_LIBELLDRA
    0x14a,
    // POKEMON_RIOLU
    0x128,
    // POKEMON_LUCARIO
    0x129,
    // POKEMON_FRIZELBLIZ
    0x135,
    // POKEMON_VOLTENSO
    0x136,
    // POKEMON_CAMAUB
    0x142,
    // POKEMON_CAMERUPT
    0x143,
    // POKEMON_SEEMOPS
    0x16b,
    // POKEMON_SEEJONG
    0x16c,
    // POKEMON_WALRAISA
    0x16d,
    // POKEMON_TUSKA
    0x14b,
    // POKEMON_NOKTUSKA
    0x14c,
    // POKEMON_SCHNEPPKE
    0x169,
    // POKEMON_FIRNONTOR
    0x16a,
    // POKEMON_LUNASTEIN
    0x151,
    // POKEMON_SONNFEL
    0x152,
    // POKEMON_AZURILL
    0x12a,
    // POKEMON_SPOINK
    0x145,
    // POKEMON_GROINK
    0x146,
    // POKEMON_PLUSLE
    0x137,
    // POKEMON_MINUN
    0x138,
    // POKEMON_FLUNKIFER
    0x12f,
    // POKEMON_MEDITIE
    0x133,
    // POKEMON_MEDITALIS
    0x134,
    // POKEMON_WABLU
    0x14d,
    // POKEMON_ALTARIA
    0x14e,
    // POKEMON_ISSO
    0x168,
    // POKEMON_ZWIRRLICHT
    0x163,
    // POKEMON_ZWIRRKLOP
    0x164,
    // POKEMON_PORYGON_Z
    0x13b,
    // POKEMON_BUMMELZ
    0x11f,
    // POKEMON_MUNTIER
    0x120,
    // POKEMON_LETARKING
    0x121,
    // POKEMON_SCHLUPPUCK
    0x13c,
    // POKEMON_SCHLUKWECH
    0x13d,
    // POKEMON_TROPIUS
    0x165,
    // POKEMON_KAUMALAT
    0x125,
    // POKEMON_KNARKSEL
    0x126,
    // POKEMON_KNAKRACK
    0x127,
    // POKEMON_PERLU
    0x16e,
    // POKEMON_AALABYSS
    0x16f,
    // POKEMON_SAGANABYSS
    0x170,
    // POKEMON_ABSOL
    0x167,
    // POKEMON_SHUPPET
    0x161,
    // POKEMON_BANETTE
    0x162,
    // POKEMON_VIPITIS
    0x150,
    // POKEMON_SENGO
    0x14f,
    // POKEMON_RELICANTH
    0x171,
    // POKEMON_STOLLUNIOR
    0x130,
    // POKEMON_STOLLRAK
    0x131,
    // POKEMON_STOLLOSS
    0x132,
    // POKEMON_FORMEO
    0x15f,
    // POKEMON_VOLBEAT
    0x139,
    // POKEMON_ILLUMISE
    0x13a,
    // POKEMON_LILIEP
    0x159,
    // POKEMON_WIELIE
    0x15a,
    // POKEMON_ANORITH
    0x15b,
    // POKEMON_ARMALDO
    0x15c,
    // POKEMON_TRASLA
    0x118,
    // POKEMON_KIRLIA
    0x119,
    // POKEMON_GUARDEVOIR
    0x11a,
    // POKEMON_KINDWURM
    0x173,
    // POKEMON_DRASCHEL
    0x174,
    // POKEMON_BRUTALANDA
    0x175,
    // POKEMON_TANHEL
    0x176,
    // POKEMON_METANG
    0x177,
    // POKEMON_METAGROSS
    0x178,
    // POKEMON_REGIROCK
    0x179,
    // POKEMON_REGICE
    0x17a,
    // POKEMON_REGISTEEL
    0x17b,
    // POKEMON_KYOGRE
    0x17e,
    // POKEMON_GROUDON
    0x17f,
    // POKEMON_RAYQUAZA
    0x180,
    // POKEMON_LATIAS
    0x17c,
    // POKEMON_LATIOS
    0x17d,
    // POKEMON_JIRACHI
    0x181,
    // POKEMON_DEOXYS
    0x182,
    // POKEMON_PALIMPALIM
    0x166,
    // POKEMON_EGG
    0x0,
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
	0x0
};

void version_transfer_pokedex() {
	// First save the old pokedex flags (extensions are not used so far...)
	u8 *old_seen = malloc_and_clear(sizeof(u8) * 52);
	u8 *old_caught = malloc_and_clear(sizeof(u8) * 52);
	for (int i = 0; i < 52; i++) {
		old_seen[i] = save2->pokedex_seen_flags[i];
		old_caught[i] = save2->pokedex_caught_flags[i];
		save2->pokedex_seen_flags[i] = 0;
		save2->pokedex_caught_flags[i] = 0;
	}
	// Now iterate over all specieses and transfer their seen / caught to back to the save2 memory
	for (int i = 0; i < POKEMON_CNT - 1; i++) {
		int flag_old = pokedex_order_old[i] - 1;
		int flag_new = pokedex_order[i] - 1;
		int byte_old = flag_old / 8;
		int byte_new = flag_new / 8;
		int bit_old = flag_old & 7;
		int bit_new = flag_new & 7;
		if (old_seen[byte_old] & (1 << bit_old)) {
			save2->pokedex_seen_flags[byte_new] |= (u8)(1 << bit_new);
		}
		if (old_caught[byte_old] & (1 << bit_old)){
			save2->pokedex_caught_flags[byte_new] |= (u8)(1 << bit_new);
		}
	}
	free(old_seen);
	free(old_caught);
}

