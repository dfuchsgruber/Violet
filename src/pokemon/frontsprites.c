#include "types.h"
#include "oams.h"
#include "pokemon.h"
#include "gfx.h"

graphic pokemon_frontsprites[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    {(void*) 0x8d00748, 0x800, 0x0},
    // POKEMON_BISASAM
    {(void*) 0x87b1200, 0x800, 0x1},
    // POKEMON_BISAKNOSP
    {(void*) 0x87bf744, 0x800, 0x2},
    // POKEMON_BISAFLOR
    {(void*) 0x87c06e8, 0x800, 0x3},
    // POKEMON_GLUMANDA
    {(void*) 0x87c841c, 0x800, 0x4},
    // POKEMON_GLUTEXO
    {(void*) 0x8d328ac, 0x800, 0x5},
    // POKEMON_GLURAK
    {(void*) 0x87c89ac, 0x800, 0x6},
    // POKEMON_SCHIGGY
    {(void*) 0x87caf4c, 0x800, 0x7},
    // POKEMON_SCHILLOK
    {(void*) 0x87d35a8, 0x800, 0x8},
    // POKEMON_TURTOK
    {(void*) 0x8d3562c, 0x800, 0x9},
    // POKEMON_DARTIRI
    {(void*) 0x8d363b4, 0x800, 0xa},
    // POKEMON_DARTIGNIS
    {(void*) 0x87da4b4, 0x800, 0xb},
    // POKEMON_FIARO
    {(void*) 0x87e4874, 0x800, 0xc},
    // POKEMON_HORNLIU
    {(void*) 0x87e4dac, 0x800, 0xd},
    // POKEMON_KOKUNA
    {(void*) 0x87ebb98, 0x800, 0xe},
    // POKEMON_BIBOR
    {(void*) 0x87ec110, 0x800, 0xf},
    // POKEMON_STARALILI
    {(void*) 0x890b6f8, 0x800, 0x10},
    // POKEMON_STARAVIA
    {(void*) 0x890c01c, 0x800, 0x11},
    // POKEMON_STARAPTOR
    {(void*) 0x890c90c, 0x800, 0x12},
    // POKEMON_BRONZEL
    {(void*) 0x87ece08, 0x800, 0x13},
    // POKEMON_BRONZONG
    {(void*) 0x87ed378, 0x800, 0x14},
    // POKEMON_MAEHIKEL
    {(void*) 0x87ee0b8, 0x800, 0x15},
    // POKEMON_CHEVRUMM
    {(void*) 0x87eebf4, 0x800, 0x16},
    // POKEMON_PARAGONI
    {(void*) 0x8d3ed60, 0x800, 0x17},
    // POKEMON_TROMBORK
    {(void*) 0x87f010c, 0x800, 0x18},
    // POKEMON_PIKACHU
    {(void*) 0x87f0afc, 0x800, 0x19},
    // POKEMON_RAICHU
    {(void*) 0x8d40d0c, 0x800, 0x1a},
    // POKEMON_SANDAN
    {(void*) 0x87f153c, 0x800, 0x1b},
    // POKEMON_SANDAMER
    {(void*) 0x8d42308, 0x800, 0x1c},
    // POKEMON_NIDORANW
    {(void*) 0x88b8294, 0x800, 0x1d},
    // POKEMON_NIDORINA
    {(void*) 0x87f1bc0, 0x800, 0x1e},
    // POKEMON_NIDOQUEEN
    {(void*) 0x87f2324, 0x800, 0x1f},
    // POKEMON_NIDORANM
    {(void*) 0x8d450e4, 0x800, 0x20},
    // POKEMON_NIDORINO
    {(void*) 0x87f27d8, 0x800, 0x21},
    // POKEMON_NIDOKING
    {(void*) 0x8d466c4, 0x800, 0x22},
    // POKEMON_FLOETTE
    {(void*) 0x87f2bfc, 0x800, 0x23},
    // POKEMON_FLORGES
    {(void*) 0x87f339c, 0x800, 0x24},
    // POKEMON_VULPIX
    {(void*) 0x87f3c44, 0x800, 0x25},
    // POKEMON_VULNONA
    {(void*) 0x87f4398, 0x800, 0x26},
    // POKEMON_PUMMELUFF
    {(void*) 0x87b4a70, 0x800, 0x27},
    // POKEMON_KNUDDELUFF
    {(void*) 0x8d4aa0c, 0x800, 0x28},
    // POKEMON_ZUBAT
    {(void*) 0x87f48b0, 0x800, 0x29},
    // POKEMON_GOLBAT
    {(void*) 0x87f4f38, 0x800, 0x2a},
    // POKEMON_MYRAPLA
    {(void*) 0x87f56d0, 0x800, 0x2b},
    // POKEMON_DUFLOR
    {(void*) 0x87f5c88, 0x800, 0x2c},
    // POKEMON_GIFLOR
    {(void*) 0x87f63f0, 0x800, 0x2d},
    // POKEMON_FOLIPURBA
    {(void*) 0x87f680c, 0x800, 0x2e},
    // POKEMON_FEELINARA
    {(void*) 0x87f7328, 0x800, 0x2f},
    // POKEMON_WATTZAPF
    {(void*) 0x8d4fe90, 0x800, 0x30},
    // POKEMON_VOLTULA
    {(void*) 0x8d50950, 0x800, 0x31},
    // POKEMON_DIGDA
    {(void*) 0x8d51568, 0x800, 0x32},
    // POKEMON_DIGDRI
    {(void*) 0x8d51df4, 0x800, 0x33},
    // POKEMON_KASTADUR
    {(void*) 0x8786b44, 0x800, 0x34},
    // POKEMON_TENTANTEL
    {(void*) 0x87f83dc, 0x800, 0x35},
    // POKEMON_ENTON
    {(void*) 0x8d53da4, 0x800, 0x36},
    // POKEMON_ENTORON
    {(void*) 0x8d54794, 0x800, 0x37},
    // POKEMON_MENKI
    {(void*) 0x87f9008, 0x800, 0x38},
    // POKEMON_RASAFF
    {(void*) 0x87f938c, 0x800, 0x39},
    // POKEMON_FUKANO
    {(void*) 0x87f980c, 0x800, 0x3a},
    // POKEMON_ARKANI
    {(void*) 0x87f9bc4, 0x800, 0x3b},
    // POKEMON_GRAMOKLES
    {(void*) 0x939a030, 0x800, 0x3c},
    // POKEMON_DUOKLES
    {(void*) 0x9399830, 0x800, 0x3d},
    // POKEMON_DURENGARD
    {(void*) 0x88b8e7c, 0x800, 0x3e},
    // POKEMON_ABRA
    {(void*) 0x87fb794, 0x800, 0x3f},
    // POKEMON_KADABRA
    {(void*) 0x8d5aa58, 0x800, 0x40},
    // POKEMON_SIMSALA
    {(void*) 0x87fc264, 0x800, 0x41},
    // POKEMON_MACHOLLO
    {(void*) 0x87fcb78, 0x800, 0x42},
    // POKEMON_MASCHOCK
    {(void*) 0x8d5cda0, 0x800, 0x43},
    // POKEMON_MACHOMEI
    {(void*) 0x8d5d92c, 0x800, 0x44},
    // POKEMON_KNOFENSA
    {(void*) 0x87fd1cc, 0x800, 0x45},
    // POKEMON_ULTRIGARIA
    {(void*) 0x87fd790, 0x800, 0x46},
    // POKEMON_SARZENIA
    {(void*) 0x87fddd4, 0x800, 0x47},
    // POKEMON_TENTACHA
    {(void*) 0x87fe62c, 0x800, 0x48},
    // POKEMON_TENTOXA
    {(void*) 0x8d61124, 0x800, 0x49},
    // POKEMON_KLEINSTEIN
    {(void*) 0x87fecb8, 0x800, 0x4a},
    // POKEMON_GEOROK
    {(void*) 0x87ff2b0, 0x800, 0x4b},
    // POKEMON_GEOWAZ
    {(void*) 0x88ad22c, 0x800, 0x4c},
    // POKEMON_PONITA
    {(void*) 0x8d63de4, 0x800, 0x4d},
    // POKEMON_GALLOPA
    {(void*) 0x88ada44, 0x800, 0x4e},
    // POKEMON_FLEGMON
    {(void*) 0x88adf94, 0x800, 0x4f},
    // POKEMON_LAHMUS
    {(void*) 0x8d65fd0, 0x800, 0x50},
    // POKEMON_MAGNETILO
    {(void*) 0x88ae598, 0x800, 0x51},
    // POKEMON_MAGNETON
    {(void*) 0x88af190, 0x800, 0x52},
    // POKEMON_PORENTA
    {(void*) 0x88aeab0, 0x800, 0x53},
    // POKEMON_DODU
    {(void*) 0x88af9c0, 0x800, 0x54},
    // POKEMON_DODRI
    {(void*) 0x88afd2c, 0x800, 0x55},
    // POKEMON_JURBO
    {(void*) 0x8d6a284, 0x800, 0x56},
    // POKEMON_JUGONG
    {(void*) 0x8d6ad04, 0x800, 0x57},
    // POKEMON_SLEIMA
    {(void*) 0x88b0224, 0x800, 0x58},
    // POKEMON_SLEIMOK
    {(void*) 0x88b08f0, 0x800, 0x59},
    // POKEMON_MUSCHAS
    {(void*) 0x88b10a4, 0x800, 0x5a},
    // POKEMON_AUSTOS
    {(void*) 0x88b13dc, 0x800, 0x5b},
    // POKEMON_NEBULAK
    {(void*) 0x8d6e3b4, 0x800, 0x5c},
    // POKEMON_ALPOLLO
    {(void*) 0x8d6ef00, 0x800, 0x5d},
    // POKEMON_GENGAR
    {(void*) 0x88b20d4, 0x800, 0x5e},
    // POKEMON_ONIX
    {(void*) 0x8d7053c, 0x800, 0x5f},
    // POKEMON_TRAUMATO
    {(void*) 0x8d711e0, 0x800, 0x60},
    // POKEMON_HYPNO
    {(void*) 0x8d71bc4, 0x800, 0x61},
    // POKEMON_KRABBY
    {(void*) 0x88b34e0, 0x800, 0x62},
    // POKEMON_KINGLER
    {(void*) 0x8d732b4, 0x800, 0x63},
    // POKEMON_VOLTOBAL
    {(void*) 0x937a200, 0x800, 0x64},
    // POKEMON_LEKTROBAL
    {(void*) 0x937a4b0, 0x800, 0x65},
    // POKEMON_OWEI
    {(void*) 0x8d75150, 0x800, 0x66},
    // POKEMON_KOKOWEI
    {(void*) 0x937ab10, 0x800, 0x67},
    // POKEMON_TRAGOSSO
    {(void*) 0x8d768dc, 0x800, 0x68},
    // POKEMON_KNOGGA
    {(void*) 0x8d77348, 0x800, 0x69},
    // POKEMON_KICKLEE
    {(void*) 0x8d77e4c, 0x800, 0x6a},
    // POKEMON_NOCKCHAN
    {(void*) 0x937bf00, 0x800, 0x6b},
    // POKEMON_SCHLURP
    {(void*) 0x937c710, 0x800, 0x6c},
    // POKEMON_SMOGON
    {(void*) 0x937ce90, 0x800, 0x6d},
    // POKEMON_SMOGMOG
    {(void*) 0x88b4f3c, 0x800, 0x6e},
    // POKEMON_RIHORN
    {(void*) 0x8d7b5d4, 0x800, 0x6f},
    // POKEMON_RIZEROS
    {(void*) 0x937d9d0, 0x800, 0x70},
    // POKEMON_CHANEIRA
    {(void*) 0x8d7cf2c, 0x800, 0x71},
    // POKEMON_ZOBIRIS
    {(void*) 0x8a33ab4, 0x800, 0x72},
    // POKEMON_KANGAMA
    {(void*) 0x88b4380, 0x800, 0x73},
    // POKEMON_SEEPER
    {(void*) 0x8d7f250, 0x800, 0x74},
    // POKEMON_SEEMON
    {(void*) 0x8d7fc0c, 0x800, 0x75},
    // POKEMON_QUABBEL
    {(void*) 0x890d3a0, 0x800, 0x76},
    // POKEMON_APOQUALLYP
    {(void*) 0x890de40, 0x800, 0x77},
    // POKEMON_STERNDU
    {(void*) 0x937e770, 0x800, 0x78},
    // POKEMON_STARMIE
    {(void*) 0x937ee00, 0x800, 0x79},
    // POKEMON_TRAUNFUGIL
    {(void*) 0x8a34394, 0x800, 0x7a},
    // POKEMON_SICHLOR
    {(void*) 0x8d83ebc, 0x800, 0x7b},
    // POKEMON_GALAGLADI
    {(void*) 0x879db18, 0x800, 0x7c},
    // POKEMON_ELEKTEK
    {(void*) 0x8d85694, 0x800, 0x7d},
    // POKEMON_MAGMAR
    {(void*) 0x937ff90, 0x800, 0x7e},
    // POKEMON_PINSIR
    {(void*) 0x9380870, 0x800, 0x7f},
    // POKEMON_TAUROS
    {(void*) 0x8d87a30, 0x800, 0x80},
    // POKEMON_KARPADOR
    {(void*) 0x93810e0, 0x800, 0x81},
    // POKEMON_GARADOS
    {(void*) 0x9381850, 0x800, 0x82},
    // POKEMON_LAPRAS
    {(void*) 0x88b5cbc, 0x800, 0x83},
    // POKEMON_DITTO
    {(void*) 0x9381e90, 0x800, 0x84},
    // POKEMON_EVOLI
    {(void*) 0x93820f0, 0x800, 0x85},
    // POKEMON_AQUANA
    {(void*) 0x8a296b8, 0x800, 0x86},
    // POKEMON_BLITZA
    {(void*) 0x8a28b4c, 0x800, 0x87},
    // POKEMON_FLAMARA
    {(void*) 0x891143c, 0x800, 0x88},
    // POKEMON_PORYGON
    {(void*) 0x8d8df8c, 0x800, 0x89},
    // POKEMON_AMONITAS
    {(void*) 0x9382890, 0x800, 0x8a},
    // POKEMON_AMOROSO
    {(void*) 0x9382bb0, 0x800, 0x8b},
    // POKEMON_KABUTO
    {(void*) 0x93833c0, 0x800, 0x8c},
    // POKEMON_KABUTOPS
    {(void*) 0x9383930, 0x800, 0x8d},
    // POKEMON_AERODACTYL
    {(void*) 0x9384250, 0x800, 0x8e},
    // POKEMON_RELAXO
    {(void*) 0x9384740, 0x800, 0x8f},
    // POKEMON_ARKTOS
    {(void*) 0x9384dc0, 0x800, 0x90},
    // POKEMON_ZAPDOS
    {(void*) 0x9385680, 0x800, 0x91},
    // POKEMON_LAVADOS
    {(void*) 0x8d94250, 0x800, 0x92},
    // POKEMON_DRATINI
    {(void*) 0x8d94ec8, 0x800, 0x93},
    // POKEMON_DRAGONIR
    {(void*) 0x8d9587c, 0x800, 0x94},
    // POKEMON_DRAGORAN
    {(void*) 0x8d96394, 0x800, 0x95},
    // POKEMON_MEWTU
    {(void*) 0x88b6498, 0x800, 0x96},
    // POKEMON_MEW
    {(void*) 0x8911f38, 0x800, 0x97},
    // POKEMON_ENDIVIE
    {(void*) 0x8912794, 0x800, 0x98},
    // POKEMON_LORBLATT
    {(void*) 0x8912fd0, 0x800, 0x99},
    // POKEMON_MEGANIE
    {(void*) 0x8913a64, 0x800, 0x9a},
    // POKEMON_FEURIGEL
    {(void*) 0x88b6ddc, 0x800, 0x9b},
    // POKEMON_IGELAVAR
    {(void*) 0x88b7814, 0x800, 0x9c},
    // POKEMON_TORNUPTO
    {(void*) 0x8915bbc, 0x800, 0x9d},
    // POKEMON_KARNIMANI
    {(void*) 0x8916934, 0x800, 0x9e},
    // POKEMON_TYRACROC
    {(void*) 0x8917170, 0x800, 0x9f},
    // POKEMON_IMPERGATOR
    {(void*) 0x8917b80, 0x800, 0xa0},
    // POKEMON_IGNIVOR
    {(void*) 0x8d9ef48, 0x800, 0xa1},
    // POKEMON_RAMOTH
    {(void*) 0x9386ae0, 0x800, 0xa2},
    // POKEMON_GLAZIOLA
    {(void*) 0x93873f0, 0x800, 0xa3},
    // POKEMON_RESLADERO
    {(void*) 0x9387ac0, 0x800, 0xa4},
    // POKEMON_LEDYBA
    {(void*) 0x9387f00, 0x800, 0xa5},
    // POKEMON_LEDIAN
    {(void*) 0x9388270, 0x800, 0xa6},
    // POKEMON_WEBARAK
    {(void*) 0x9388a90, 0x800, 0xa7},
    // POKEMON_ARIADOS
    {(void*) 0x9389010, 0x800, 0xa8},
    // POKEMON_IKSBAT
    {(void*) 0x8da43f4, 0x800, 0xa9},
    // POKEMON_LAMPI
    {(void*) 0x93894c0, 0x800, 0xaa},
    // POKEMON_LANTURN
    {(void*) 0x9389bf0, 0x800, 0xab},
    // POKEMON_MAGNEZONE
    {(void*) 0x88632e0, 0x800, 0xac},
    // POKEMON_TOGEKISS
    {(void*) 0x8918a74, 0x800, 0xad},
    // POKEMON_FLABEBE
    {(void*) 0x9394cc0, 0x800, 0xae},
    // POKEMON_TOGEPI
    {(void*) 0x87d4bd4, 0x800, 0xaf},
    // POKEMON_TOGETIC
    {(void*) 0x938aaa0, 0x800, 0xb0},
    // POKEMON_NATU
    {(void*) 0x938ada0, 0x800, 0xb1},
    // POKEMON_XATU
    {(void*) 0x938b2c0, 0x800, 0xb2},
    // POKEMON_VOLTILAMM
    {(void*) 0x938b650, 0x800, 0xb3},
    // POKEMON_WAATY
    {(void*) 0x938b930, 0x800, 0xb4},
    // POKEMON_AMPHAROS
    {(void*) 0x938bcc0, 0x800, 0xb5},
    // POKEMON_BLUBELLA
    {(void*) 0x938c0a0, 0x800, 0xb6},
    // POKEMON_MARILL
    {(void*) 0x938c340, 0x800, 0xb7},
    // POKEMON_AZUMARILL
    {(void*) 0x938c690, 0x800, 0xb8},
    // POKEMON_MOGELBAUM
    {(void*) 0x938cd20, 0x800, 0xb9},
    // POKEMON_CLAVION
    {(void*) 0x938d430, 0x800, 0xba},
    // POKEMON_LICHTEL
    {(void*) 0x8792434, 0x800, 0xbb},
    // POKEMON_LATERNECTO
    {(void*) 0x879715c, 0x800, 0xbc},
    // POKEMON_SKLELABRA
    {(void*) 0x8db0b40, 0x800, 0xbd},
    // POKEMON_GRIFFEL
    {(void*) 0x938ded0, 0x800, 0xbe},
    // POKEMON_SHNEBEDECK
    {(void*) 0x8919484, 0x800, 0xbf},
    // POKEMON_REXBLISAR
    {(void*) 0x8919ed0, 0x800, 0xc0},
    // POKEMON_AMBIDIFFEL
    {(void*) 0x891acd4, 0x800, 0xc1},
    // POKEMON_FELINO
    {(void*) 0x938e5f0, 0x800, 0xc2},
    // POKEMON_MORLORD
    {(void*) 0x8db4b2c, 0x800, 0xc3},
    // POKEMON_PSIANA
    {(void*) 0x8db560c, 0x800, 0xc4},
    // POKEMON_NACHTARA
    {(void*) 0x8db6090, 0x800, 0xc5},
    // POKEMON_KRAMURX
    {(void*) 0x8db6b28, 0x800, 0xc6},
    // POKEMON_LASCHOKING
    {(void*) 0x938f0a0, 0x800, 0xc7},
    // POKEMON_KRAMSHEF
    {(void*) 0x88616ec, 0x800, 0xc8},
    // POKEMON_ICOGNITO
    {(void*) 0x8db8b94, 0x800, 0xc9},
    // POKEMON_FROSDEDJE
    {(void*) 0x8c48290, 0x800, 0xca},
    // POKEMON_SKORGRO
    {(void*) 0x88626f8, 0x800, 0xcb},
    // POKEMON_TANNZA
    {(void*) 0x8dba9ec, 0x800, 0xcc},
    // POKEMON_FORSTELLKA
    {(void*) 0x938fcd0, 0x800, 0xcd},
    // POKEMON_ELEVOLTEK
    {(void*) 0x891ba3c, 0x800, 0xce},
    // POKEMON_SKORGLA
    {(void*) 0x8dbca34, 0x800, 0xcf},
    // POKEMON_STAHLOS
    {(void*) 0x9390510, 0x800, 0xd0},
    // POKEMON_SNUBBULL
    {(void*) 0x9390ae0, 0x800, 0xd1},
    // POKEMON_GRANBULL
    {(void*) 0x9390e50, 0x800, 0xd2},
    // POKEMON_MAMUTEL
    {(void*) 0x891c7c8, 0x800, 0xd3},
    // POKEMON_SCHEROX
    {(void*) 0x8dc037c, 0x800, 0xd4},
    // POKEMON_POTTROTT
    {(void*) 0x93916f0, 0x800, 0xd5},
    // POKEMON_SKARABORN
    {(void*) 0x8dc19e4, 0x800, 0xd6},
    // POKEMON_KRYPPUK
    {(void*) 0x9004db8, 0x800, 0xd7},
    // POKEMON_TEDDIURSA
    {(void*) 0x9391d70, 0x800, 0xd8},
    // POKEMON_URSARING
    {(void*) 0x9392310, 0x800, 0xd9},
    // POKEMON_SCHNECKMAG
    {(void*) 0x93927e0, 0x800, 0xda},
    // POKEMON_MAGCARGO
    {(void*) 0x9392e00, 0x800, 0xdb},
    // POKEMON_QUIEKEL
    {(void*) 0x93932f0, 0x800, 0xdc},
    // POKEMON_KEIFEL
    {(void*) 0x93937d0, 0x800, 0xdd},
    // POKEMON_CORASONN
    {(void*) 0x9393b80, 0x800, 0xde},
    // POKEMON_REMORAID
    {(void*) 0x9393ef0, 0x800, 0xdf},
    // POKEMON_OCTILLERY
    {(void*) 0x8dc8670, 0x800, 0xe0},
    // POKEMON_BOTOGEL
    {(void*) 0x88b9a00, 0x800, 0xe1},
    // POKEMON_SCHLURPLEK
    {(void*) 0x8dc9c6c, 0x800, 0xe2},
    // POKEMON_PANZAERON
    {(void*) 0x8dca818, 0x800, 0xe3},
    // POKEMON_HUNDUSTER
    {(void*) 0x93953a0, 0x800, 0xe4},
    // POKEMON_HUNDEMON
    {(void*) 0x9395710, 0x800, 0xe5},
    // POKEMON_SEEDRAKING
    {(void*) 0x8dcc9a8, 0x800, 0xe6},
    // POKEMON_PHANPY
    {(void*) 0x9396380, 0x800, 0xe7},
    // POKEMON_DONPHAN
    {(void*) 0x8dcdf7c, 0x800, 0xe8},
    // POKEMON_PORYGON2
    {(void*) 0x8dceb5c, 0x800, 0xe9},
    // POKEMON_VOLUMINAS
    {(void*) 0x93969f0, 0x800, 0xea},
    // POKEMON_TRAUNMAGIL
    {(void*) 0x8a3541c, 0x800, 0xeb},
    // POKEMON_RABAUZ
    {(void*) 0x9396e90, 0x800, 0xec},
    // POKEMON_KAPOERA
    {(void*) 0x93971c0, 0x800, 0xed},
    // POKEMON_KUSSILLA
    {(void*) 0x9397630, 0x800, 0xee},
    // POKEMON_ELEKID
    {(void*) 0x9397bd0, 0x800, 0xef},
    // POKEMON_MAGBY
    {(void*) 0x93982c0, 0x800, 0xf0},
    // POKEMON_MILTANK
    {(void*) 0x93985c0, 0x800, 0xf1},
    // POKEMON_HEITEIRA
    {(void*) 0x9398980, 0x800, 0xf2},
    // POKEMON_RAIKOU
    {(void*) 0x8dd5934, 0x800, 0xf3},
    // POKEMON_ENTEI
    {(void*) 0x8dd66c8, 0x800, 0xf4},
    // POKEMON_SUICUNE
    {(void*) 0x8dd7558, 0x800, 0xf5},
    // POKEMON_LARVITAR
    {(void*) 0x9398eb0, 0x800, 0xf6},
    // POKEMON_PUPITAR
    {(void*) 0x8dd8da0, 0x800, 0xf7},
    // POKEMON_DESPOTAR
    {(void*) 0x8dd9838, 0x800, 0xf8},
    // POKEMON_LUGIA
    {(void*) 0x8dda5d0, 0x800, 0xf9},
    // POKEMON_HO_OH
    {(void*) 0x8ddb2d8, 0x800, 0xfa},
    // POKEMON_CELEBI
    {(void*) 0x9399530, 0x800, 0xfb},
    // POKEMON_BISAFLORM
    {(void*) 0x8a1e388, 0x800, 0xfc},
    // POKEMON_GLURAKM
    {(void*) 0x888ed20, 0x800, 0xfd},
    // POKEMON_AQUANAM
    {(void*) 0x8a2ad00, 0x800, 0xfe},
    // POKEMON_BLITZAM
    {(void*) 0x8a2a194, 0x800, 0xff},
    // POKEMON_FLAMARM
    {(void*) 0x8a2526c, 0x800, 0x100},
    // POKEMON_DURENGARDA
    {(void*) 0x8a02ab0, 0x800, 0x101},
    // POKEMON_IN
    {(void*) 0x8a046b0, 0x800, 0x102},
    // POKEMON_GAME
    {(void*) 0x8a05518, 0x800, 0x103},
    // POKEMON_TURTOKM
    {(void*) 0x8a06338, 0x800, 0x104},
    // POKEMON_AMPHARAOSM
    {(void*) 0x8a21804, 0x800, 0x105},
    // POKEMON_GENGARM
    {(void*) 0x8a27210, 0x800, 0x106},
    // POKEMON_BIBORM
    {(void*) 0x877bfac, 0x800, 0x107},
    // POKEMON_ALTARIAM
    {(void*) 0x8a2e3bc, 0x800, 0x108},
    // POKEMON_GEOWAZM
    {(void*) 0x8a2f190, 0x800, 0x109},
    // POKEMON_SENGOM
    {(void*) 0x8a313d0, 0x800, 0x10a},
    // POKEMON_VIPITISM
    {(void*) 0x8a327f8, 0x800, 0x10b},
    // POKEMON_ZOBIRISM
    {(void*) 0x8a36b00, 0x800, 0x10c},
    // POKEMON_10d
    {(void*) 0x8ddcc40, 0x800, 0x10d},
    // POKEMON_10e
    {(void*) 0x8ddcc40, 0x800, 0x10e},
    // POKEMON_10f
    {(void*) 0x8ddcc40, 0x800, 0x10f},
    // POKEMON_110
    {(void*) 0x8ddcc40, 0x800, 0x110},
    // POKEMON_111
    {(void*) 0x8ddcc40, 0x800, 0x111},
    // POKEMON_112
    {(void*) 0x8ddcc40, 0x800, 0x112},
    // POKEMON_113
    {(void*) 0x8ddcc40, 0x800, 0x113},
    // POKEMON_114
    {(void*) 0x8ddcc40, 0x800, 0x114},
    // POKEMON_LOCKSCHAL
    {(void*) 0x8a384ac, 0x800, 0x115},
    // POKEMON_STICHSCHAL
    {(void*) 0x8a38c1c, 0x800, 0x116},
    // POKEMON_STAHLSTICH
    {(void*) 0x8a396e0, 0x800, 0x117},
    // POKEMON_WELUNO
    {(void*) 0x8769758, 0x800, 0x118},
    // POKEMON_ORTHODOS
    {(void*) 0x8773d10, 0x800, 0x119},
    // POKEMON_ZERBERTRES
    {(void*) 0x878ba3c, 0x800, 0x11a},
    // POKEMON_SEEKID
    {(void*) 0x8a3a48c, 0x800, 0x11b},
    // POKEMON_SEESKULL
    {(void*) 0x8a3abd8, 0x800, 0x11c},
    // POKEMON_SKULLYDRA
    {(void*) 0x8a3b4c4, 0x800, 0x11d},
    // POKEMON_FIFFYEN
    {(void*) 0x939a740, 0x800, 0x11e},
    // POKEMON_MAGNAYEN
    {(void*) 0x8de4418, 0x800, 0x11f},
    // POKEMON_ZIGZACHS
    {(void*) 0x88bb760, 0x800, 0x120},
    // POKEMON_GERADAKS
    {(void*) 0x8de5bb8, 0x800, 0x121},
    // POKEMON_WAUMPEL
    {(void*) 0x939aba0, 0x800, 0x122},
    // POKEMON_SCHALOKO
    {(void*) 0x939b1d0, 0x800, 0x123},
    // POKEMON_PAPINELLA
    {(void*) 0x88bc0c0, 0x800, 0x124},
    // POKEMON_PANEKON
    {(void*) 0x939b740, 0x800, 0x125},
    // POKEMON_PUDOX
    {(void*) 0x939c030, 0x800, 0x126},
    // POKEMON_LOTURZEL
    {(void*) 0x939c820, 0x800, 0x127},
    // POKEMON_LOMBRERO
    {(void*) 0x939ce30, 0x800, 0x128},
    // POKEMON_KAPPALORES
    {(void*) 0x939d500, 0x800, 0x129},
    // POKEMON_SAMURZEL
    {(void*) 0x8deb7dc, 0x800, 0x12a},
    // POKEMON_BLANAS
    {(void*) 0x939df20, 0x800, 0x12b},
    // POKEMON_TENGULIST
    {(void*) 0x8decbe4, 0x800, 0x12c},
    // POKEMON_NINCADA
    {(void*) 0x939e9d0, 0x800, 0x12d},
    // POKEMON_NINJASK
    {(void*) 0x939ec90, 0x800, 0x12e},
    // POKEMON_NINJATOM
    {(void*) 0x939f070, 0x800, 0x12f},
    // POKEMON_SCHWALBINI
    {(void*) 0x939f840, 0x800, 0x130},
    // POKEMON_SCHWALBOSS
    {(void*) 0x8df0160, 0x800, 0x131},
    // POKEMON_KNILZ
    {(void*) 0x939fe10, 0x800, 0x132},
    // POKEMON_KAPILZ
    {(void*) 0x93a03e0, 0x800, 0x133},
    // POKEMON_PANDIR
    {(void*) 0x8df22bc, 0x800, 0x134},
    // POKEMON_WINGULL
    {(void*) 0x93a08e0, 0x800, 0x135},
    // POKEMON_PELIPPER
    {(void*) 0x93a0bd0, 0x800, 0x136},
    // POKEMON_GEHWEIHER
    {(void*) 0x93a1040, 0x800, 0x137},
    // POKEMON_MASKEREGEN
    {(void*) 0x93a1570, 0x800, 0x138},
    // POKEMON_WAILMER
    {(void*) 0x93a1e30, 0x800, 0x139},
    // POKEMON_WAILORD
    {(void*) 0x93a2470, 0x800, 0x13a},
    // POKEMON_ENECO
    {(void*) 0x93a28c0, 0x800, 0x13b},
    // POKEMON_ENEKORO
    {(void*) 0x93a2fa0, 0x800, 0x13c},
    // POKEMON_KECLEON
    {(void*) 0x93a3770, 0x800, 0x13d},
    // POKEMON_PUPPANCE
    {(void*) 0x93a3b90, 0x800, 0x13e},
    // POKEMON_LEPUMENTAS
    {(void*) 0x93a4170, 0x800, 0x13f},
    // POKEMON_NASGNET
    {(void*) 0x891f3e8, 0x800, 0x140},
    // POKEMON_MAGBRANT
    {(void*) 0x892002c, 0x800, 0x141},
    // POKEMON_ZWIRRFINST
    {(void*) 0x8920ec8, 0x800, 0x142},
    // POKEMON_SCHMERBE
    {(void*) 0x8dfc1f0, 0x800, 0x143},
    // POKEMON_WELSAR
    {(void*) 0x93a4e90, 0x800, 0x144},
    // POKEMON_LIEBISKUS
    {(void*) 0x93a5670, 0x800, 0x145},
    // POKEMON_KREBSCORPS
    {(void*) 0x93a5af0, 0x800, 0x146},
    // POKEMON_KREBUTACK
    {(void*) 0x93a6250, 0x800, 0x147},
    // POKEMON_BARSCHWA
    {(void*) 0x93a6740, 0x800, 0x148},
    // POKEMON_MILOTIC
    {(void*) 0x93a6e30, 0x800, 0x149},
    // POKEMON_KANIVANHA
    {(void*) 0x93a7730, 0x800, 0x14a},
    // POKEMON_TOHAIDO
    {(void*) 0x8e01750, 0x800, 0x14b},
    // POKEMON_KNACKLION
    {(void*) 0x93a7ea0, 0x800, 0x14c},
    // POKEMON_VIBRAVA
    {(void*) 0x93a8400, 0x800, 0x14d},
    // POKEMON_LIBELLDRA
    {(void*) 0x8e035ac, 0x800, 0x14e},
    // POKEMON_RIOLU
    {(void*) 0x8921ae8, 0x800, 0x14f},
    // POKEMON_LUCARIO
    {(void*) 0x892225c, 0x800, 0x150},
    // POKEMON_FRIZELBLIZ
    {(void*) 0x93a8b80, 0x800, 0x151},
    // POKEMON_VOLTENSO
    {(void*) 0x93a91f0, 0x800, 0x152},
    // POKEMON_CAMAUB
    {(void*) 0x93a99a0, 0x800, 0x153},
    // POKEMON_CAMERUPT
    {(void*) 0x93a9fb0, 0x800, 0x154},
    // POKEMON_SEEMOPS
    {(void*) 0x93aa830, 0x800, 0x155},
    // POKEMON_SEEJONG
    {(void*) 0x88bcd70, 0x800, 0x156},
    // POKEMON_WALRAISA
    {(void*) 0x8e096a8, 0x800, 0x157},
    // POKEMON_TUSKA
    {(void*) 0x93ab1f0, 0x800, 0x158},
    // POKEMON_NOKTUSKA
    {(void*) 0x8e0ae20, 0x800, 0x159},
    // POKEMON_SCHNEPPKE
    {(void*) 0x8e0b9c8, 0x800, 0x15a},
    // POKEMON_FIRNONTOR
    {(void*) 0x93ac090, 0x800, 0x15b},
    // POKEMON_LUNASTEIN
    {(void*) 0x93ac550, 0x800, 0x15c},
    // POKEMON_SONNFEL
    {(void*) 0x93ac900, 0x800, 0x15d},
    // POKEMON_AZURILL
    {(void*) 0x93ad200, 0x800, 0x15e},
    // POKEMON_SPOINK
    {(void*) 0x93ad540, 0x800, 0x15f},
    // POKEMON_GROINK
    {(void*) 0x93adaf0, 0x800, 0x160},
    // POKEMON_PLUSLE
    {(void*) 0x93ae330, 0x800, 0x161},
    // POKEMON_MINUN
    {(void*) 0x93ae930, 0x800, 0x162},
    // POKEMON_FLUNKIFER
    {(void*) 0x93aef50, 0x800, 0x163},
    // POKEMON_MEDITIE
    {(void*) 0x93af380, 0x800, 0x164},
    // POKEMON_MEDITALIS
    {(void*) 0x93afa20, 0x800, 0x165},
    // POKEMON_WABLU
    {(void*) 0x8e13a9c, 0x800, 0x166},
    // POKEMON_ALTARIA
    {(void*) 0x93b0190, 0x800, 0x167},
    // POKEMON_ISSO
    {(void*) 0x93b05f0, 0x800, 0x168},
    // POKEMON_ZWIRRLICHT
    {(void*) 0x8e15af8, 0x800, 0x169},
    // POKEMON_ZWIRRKLOP
    {(void*) 0x93b0c40, 0x800, 0x16a},
    // POKEMON_ROSELIA
    {(void*) 0x8e17004, 0x800, 0x16b},
    // POKEMON_BUMMELZ
    {(void*) 0x93b1780, 0x800, 0x16c},
    // POKEMON_MUNTIER
    {(void*) 0x8e185e8, 0x800, 0x16d},
    // POKEMON_LETARKING
    {(void*) 0x93b21a0, 0x800, 0x16e},
    // POKEMON_SCHLUPPUCK
    {(void*) 0x93b2b30, 0x800, 0x16f},
    // POKEMON_SCHLUKWECH
    {(void*) 0x93b3080, 0x800, 0x170},
    // POKEMON_TROPIUS
    {(void*) 0x8e1b22c, 0x800, 0x171},
    // POKEMON_KAUMALAT
    {(void*) 0x8c0d51c, 0x800, 0x172},
    // POKEMON_KNARKSEL
    {(void*) 0x8c0dfe8, 0x800, 0x173},
    // POKEMON_KNAKRACK
    {(void*) 0x8c0ec88, 0x800, 0x174},
    // POKEMON_PERLU
    {(void*) 0x93b3540, 0x800, 0x175},
    // POKEMON_AALABYSS
    {(void*) 0x93b3b80, 0x800, 0x176},
    // POKEMON_SAGANABYSS
    {(void*) 0x93b4090, 0x800, 0x177},
    // POKEMON_ABSOL
    {(void*) 0x88bd6bc, 0x800, 0x178},
    // POKEMON_SHUPPET
    {(void*) 0x88be1ec, 0x800, 0x179},
    // POKEMON_BANETTE
    {(void*) 0x8828b40, 0x800, 0x17a},
    // POKEMON_VIPITIS
    {(void*) 0x93b45c0, 0x800, 0x17b},
    // POKEMON_SENGO
    {(void*) 0x8e22eb8, 0x800, 0x17c},
    // POKEMON_RELICANTH
    {(void*) 0x93b4ad0, 0x800, 0x17d},
    // POKEMON_STOLLUNIOR
    {(void*) 0x93b4f00, 0x800, 0x17e},
    // POKEMON_STOLLRAK
    {(void*) 0x93b54a0, 0x800, 0x17f},
    // POKEMON_STOLLOSS
    {(void*) 0x93b5c70, 0x800, 0x180},
    // POKEMON_FORMEO
    {(void*) 0x93b62a0, 0x800, 0x181},
    // POKEMON_VOLBEAT
    {(void*) 0x88d194c, 0x800, 0x182},
    // POKEMON_ILLUMISE
    {(void*) 0x8e28c40, 0x800, 0x183},
    // POKEMON_LILIEP
    {(void*) 0x93b8120, 0x800, 0x184},
    // POKEMON_WIELIE
    {(void*) 0x93b8880, 0x800, 0x185},
    // POKEMON_ANORITH
    {(void*) 0x93b91e0, 0x800, 0x186},
    // POKEMON_ARMALDO
    {(void*) 0x8e2b89c, 0x800, 0x187},
    // POKEMON_TRASLA
    {(void*) 0x93b9dc0, 0x800, 0x188},
    // POKEMON_KIRLIA
    {(void*) 0x8e2cfa0, 0x800, 0x189},
    // POKEMON_GUARDEVOIR
    {(void*) 0x93ba380, 0x800, 0x18a},
    // POKEMON_KINDWURM
    {(void*) 0x93bab00, 0x800, 0x18b},
    // POKEMON_DRASCHEL
    {(void*) 0x93bb140, 0x800, 0x18c},
    // POKEMON_BRUTALANDA
    {(void*) 0x93bb4d0, 0x800, 0x18d},
    // POKEMON_TANHEL
    {(void*) 0x93bbd90, 0x800, 0x18e},
    // POKEMON_METANG
    {(void*) 0x8e30f54, 0x800, 0x18f},
    // POKEMON_METAGROSS
    {(void*) 0x93bc7c0, 0x800, 0x190},
    // POKEMON_REGIROCK
    {(void*) 0x93bd0e0, 0x800, 0x191},
    // POKEMON_REGICE
    {(void*) 0x93bdb60, 0x800, 0x192},
    // POKEMON_REGISTEEL
    {(void*) 0x93be430, 0x800, 0x193},
    // POKEMON_KYOGRE
    {(void*) 0x93bec90, 0x800, 0x194},
    // POKEMON_GROUDON
    {(void*) 0x93bf1f0, 0x800, 0x195},
    // POKEMON_RAYQUAZA
    {(void*) 0x93bf810, 0x800, 0x196},
    // POKEMON_LATIAS
    {(void*) 0x8e372b0, 0x800, 0x197},
    // POKEMON_LATIOS
    {(void*) 0x93c0430, 0x800, 0x198},
    // POKEMON_JIRACHI
    {(void*) 0x93c0940, 0x800, 0x199},
    // POKEMON_DEOXYS
    {(void*) 0x8a37634, 0x800, 0x19a},
    // POKEMON_PALIMPALIM
    {(void*) 0x93c0cf0, 0x800, 0x19b},
    // POKEMON_EGG
    {(void*) 0x8e3b4cc, 0x800, 0x19c},
    // POKEMON_ICOGNITO_B
    {(void*) 0x8e3b6a0, 0x800, 0x19d},
    // POKEMON_ICOGNITO_C
    {(void*) 0x8e3be7c, 0x800, 0x19e},
    // POKEMON_ICOGNITO_D
    {(void*) 0x8e3c73c, 0x800, 0x19f},
    // POKEMON_ICOGNITO_E
    {(void*) 0x8e3cf8c, 0x800, 0x1a0},
    // POKEMON_ICOGNITO_F
    {(void*) 0x8e3d744, 0x800, 0x1a1},
    // POKEMON_ICOGNITO_G
    {(void*) 0x8e3df54, 0x800, 0x1a2},
    // POKEMON_ICOGNITO_H
    {(void*) 0x8e3e77c, 0x800, 0x1a3},
    // POKEMON_ICOGNITO_I
    {(void*) 0x8e3f084, 0x800, 0x1a4},
    // POKEMON_ICOGNITO_J
    {(void*) 0x8e3f7c4, 0x800, 0x1a5},
    // POKEMON_ICOGNITO_K
    {(void*) 0x8e3ff70, 0x800, 0x1a6},
    // POKEMON_ICOGNITO_L
    {(void*) 0x8e40738, 0x800, 0x1a7},
    // POKEMON_ICOGNITO_M
    {(void*) 0x8e40ebc, 0x800, 0x1a8},
    // POKEMON_ICOGNITO_N
    {(void*) 0x8e41788, 0x800, 0x1a9},
    // POKEMON_ICOGNITO_O
    {(void*) 0x8e41fec, 0x800, 0x1aa},
    // POKEMON_ICOGNITO_P
    {(void*) 0x8e428e4, 0x800, 0x1ab},
    // POKEMON_ICOGNITO_Q
    {(void*) 0x8e43048, 0x800, 0x1ac},
    // POKEMON_ICOGNITO_R
    {(void*) 0x8e437c8, 0x800, 0x1ad},
    // POKEMON_ICOGNITO_S
    {(void*) 0x8e43f34, 0x800, 0x1ae},
    // POKEMON_ICOGNITO_T
    {(void*) 0x8e44770, 0x800, 0x1af},
    // POKEMON_ICOGNITO_U
    {(void*) 0x8e44ed4, 0x800, 0x1b0},
    // POKEMON_ICOGNITO_V
    {(void*) 0x8e45740, 0x800, 0x1b1},
    // POKEMON_ICOGNITO_W
    {(void*) 0x8e45f54, 0x800, 0x1b2},
    // POKEMON_ICOGNITO_X
    {(void*) 0x8e4672c, 0x800, 0x1b3},
    // POKEMON_ICOGNITO_Y
    {(void*) 0x8e46ee0, 0x800, 0x1b4},
    // POKEMON_ICOGNITO_Z
    {(void*) 0x8e476ac, 0x800, 0x1b5},
    // POKEMON_ICOGNITO_EXCLAMATION
    {(void*) 0x8e47e38, 0x800, 0x1b6},
    // POKEMON_ICOGNITO_QUESTION
    {(void*) 0x8e48590, 0x800, 0x1b7},
    // POKEMON_TEST
    {gfx_pkmn_groudon_emperor_frontspriteTiles, 0x800, 0x1b8}
};