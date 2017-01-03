#include "types.h"
#include "pokemon.h"
#include "basestats.h"
#include "abilities.h"
#include "item.h"
#include "gfx.h"

graphic pokemon_backsprites[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    {(void*) 0x8d0098c, 0x800, 0x0},
    // POKEMON_BISASAM
    {(void*) 0x87b14c8, 0x800, 0x1},
    // POKEMON_BISAKNOSP
    {(void*) 0x87bfb1c, 0x800, 0x2},
    // POKEMON_BISAFLOR
    {(void*) 0x8d31608, 0x800, 0x3},
    // POKEMON_GLUMANDA
    {(void*) 0x87c86f8, 0x800, 0x4},
    // POKEMON_GLUTEXO
    {(void*) 0x877c740, 0x800, 0x5},
    // POKEMON_GLURAK
    {(void*) 0x8d338e0, 0x800, 0x6},
    // POKEMON_SCHIGGY
    {(void*) 0x87cb214, 0x800, 0x7},
    // POKEMON_SCHILLOK
    {(void*) 0x87d3998, 0x800, 0x8},
    // POKEMON_TURTOK
    {(void*) 0x879d608, 0x800, 0x9},
    // POKEMON_DARTIRI
    {(void*) 0x87aad70, 0x800, 0xa},
    // POKEMON_DARTIGNIS
    {(void*) 0x87da81c, 0x800, 0xb},
    // POKEMON_FIARO
    {(void*) 0x8d3793c, 0x800, 0xc},
    // POKEMON_HORNLIU
    {(void*) 0x87e5004, 0x800, 0xd},
    // POKEMON_KOKUNA
    {(void*) 0x87ebe08, 0x800, 0xe},
    // POKEMON_BIBOR
    {(void*) 0x87ec54c, 0x800, 0xf},
    // POKEMON_STARALILI
    {(void*) 0x890ba7c, 0x800, 0x10},
    // POKEMON_STARAVIA
    {(void*) 0x890c48c, 0x800, 0x11},
    // POKEMON_STARAPTOR
    {(void*) 0x890cf78, 0x800, 0x12},
    // POKEMON_BRONZEL
    {(void*) 0x87ed088, 0x800, 0x13},
    // POKEMON_BRONZONG
    {(void*) 0x87ed7f8, 0x800, 0x14},
    // POKEMON_MAEHIKEL
    {(void*) 0x87ee420, 0x800, 0x15},
    // POKEMON_CHEVRUMM
    {(void*) 0x87ef0c4, 0x800, 0x16},
    // POKEMON_PARAGONI
    {(void*) 0x87d7728, 0x800, 0x17},
    // POKEMON_TROMBORK
    {(void*) 0x87f0648, 0x800, 0x18},
    // POKEMON_PIKACHU
    {(void*) 0x87f0e04, 0x800, 0x19},
    // POKEMON_RAICHU
    {(void*) 0x87f11a0, 0x800, 0x1a},
    // POKEMON_SANDAN
    {(void*) 0x87f182c, 0x800, 0x1b},
    // POKEMON_SANDAMER
    {(void*) 0x8d42748, 0x800, 0x1c},
    // POKEMON_NIDORANW
    {(void*) 0x88b8618, 0x800, 0x1d},
    // POKEMON_NIDORINA
    {(void*) 0x87f1f10, 0x800, 0x1e},
    // POKEMON_NIDOQUEEN
    {(void*) 0x8d448d8, 0x800, 0x1f},
    // POKEMON_NIDORANM
    {(void*) 0x8d45398, 0x800, 0x20},
    // POKEMON_NIDORINO
    {(void*) 0x8d45ec0, 0x800, 0x21},
    // POKEMON_NIDOKING
    {(void*) 0x8d46c28, 0x800, 0x22},
    // POKEMON_FLOETTE
    {(void*) 0x87f2f74, 0x800, 0x23},
    // POKEMON_FLORGES
    {(void*) 0x87f3868, 0x800, 0x24},
    // POKEMON_VULPIX
    {(void*) 0x87f3fac, 0x800, 0x25},
    // POKEMON_VULNONA
    {(void*) 0x8d49888, 0x800, 0x26},
    // POKEMON_PUMMELUFF
    {(void*) 0x8d4a368, 0x800, 0x27},
    // POKEMON_KNUDDELUFF
    {(void*) 0x87bdebc, 0x800, 0x28},
    // POKEMON_ZUBAT
    {(void*) 0x87f4bbc, 0x800, 0x29},
    // POKEMON_GOLBAT
    {(void*) 0x87f5354, 0x800, 0x2a},
    // POKEMON_MYRAPLA
    {(void*) 0x87f5938, 0x800, 0x2b},
    // POKEMON_DUFLOR
    {(void*) 0x87f5ff0, 0x800, 0x2c},
    // POKEMON_GIFLOR
    {(void*) 0x8d4e184, 0x800, 0x2d},
    // POKEMON_FOLIPURBA
    {(void*) 0x87f6b8c, 0x800, 0x2e},
    // POKEMON_FEELINARA
    {(void*) 0x87f76fc, 0x800, 0x2f},
    // POKEMON_WATTZAPF
    {(void*) 0x8d501d8, 0x800, 0x30},
    // POKEMON_VOLTULA
    {(void*) 0x8d50d7c, 0x800, 0x31},
    // POKEMON_DIGDA
    {(void*) 0x8d517a0, 0x800, 0x32},
    // POKEMON_DIGDRI
    {(void*) 0x8d52148, 0x800, 0x33},
    // POKEMON_KASTADUR
    {(void*) 0x8786ea4, 0x800, 0x34},
    // POKEMON_TENTANTEL
    {(void*) 0x87f8858, 0x800, 0x35},
    // POKEMON_ENTON
    {(void*) 0x8d540b0, 0x800, 0x36},
    // POKEMON_ENTORON
    {(void*) 0x87f8c60, 0x800, 0x37},
    // POKEMON_MENKI
    {(void*) 0x8d55608, 0x800, 0x38},
    // POKEMON_RASAFF
    {(void*) 0x8d5616c, 0x800, 0x39},
    // POKEMON_FUKANO
    {(void*) 0x8d56c74, 0x800, 0x3a},
    // POKEMON_ARKANI
    {(void*) 0x87fa124, 0x800, 0x3b},
    // POKEMON_GRAMOKLES
    {(void*) 0x939a3d8, 0x800, 0x3c},
    // POKEMON_DUOKLES
    {(void*) 0x9399c8c, 0x800, 0x3d},
    // POKEMON_DURENGARD
    {(void*) 0x88b947c, 0x800, 0x3e},
    // POKEMON_ABRA
    {(void*) 0x87fbab0, 0x800, 0x3f},
    // POKEMON_KADABRA
    {(void*) 0x87fbe0c, 0x800, 0x40},
    // POKEMON_SIMSALA
    {(void*) 0x87fc718, 0x800, 0x41},
    // POKEMON_MACHOLLO
    {(void*) 0x87fce7c, 0x800, 0x42},
    // POKEMON_MASCHOCK
    {(void*) 0x8d5d194, 0x800, 0x43},
    // POKEMON_MACHOMEI
    {(void*) 0x8d5de40, 0x800, 0x44},
    // POKEMON_KNOFENSA
    {(void*) 0x87fd46c, 0x800, 0x45},
    // POKEMON_ULTRIGARIA
    {(void*) 0x87fdac4, 0x800, 0x46},
    // POKEMON_SARZENIA
    {(void*) 0x87fe214, 0x800, 0x47},
    // POKEMON_TENTACHA
    {(void*) 0x87fe96c, 0x800, 0x48},
    // POKEMON_TENTOXA
    {(void*) 0x8d61640, 0x800, 0x49},
    // POKEMON_KLEINSTEIN
    {(void*) 0x87fef68, 0x800, 0x4a},
    // POKEMON_GEOROK
    {(void*) 0x87ff6c8, 0x800, 0x4b},
    // POKEMON_GEOWAZ
    {(void*) 0x88ad6c0, 0x800, 0x4c},
    // POKEMON_PONITA
    {(void*) 0x87ffa0c, 0x800, 0x4d},
    // POKEMON_GALLOPA
    {(void*) 0x8d64dd0, 0x800, 0x4e},
    // POKEMON_FLEGMON
    {(void*) 0x88ae274, 0x800, 0x4f},
    // POKEMON_LAHMUS
    {(void*) 0x8d66498, 0x800, 0x50},
    // POKEMON_MAGNETILO
    {(void*) 0x88ae7c4, 0x800, 0x51},
    // POKEMON_MAGNETON
    {(void*) 0x88af5a0, 0x800, 0x52},
    // POKEMON_PORENTA
    {(void*) 0x8d68350, 0x800, 0x53},
    // POKEMON_DODU
    {(void*) 0x8d68e14, 0x800, 0x54},
    // POKEMON_DODRI
    {(void*) 0x8d699d8, 0x800, 0x55},
    // POKEMON_JURBO
    {(void*) 0x8d6a5d0, 0x800, 0x56},
    // POKEMON_JUGONG
    {(void*) 0x8d6b0f8, 0x800, 0x57},
    // POKEMON_SLEIMA
    {(void*) 0x88b0584, 0x800, 0x58},
    // POKEMON_SLEIMOK
    {(void*) 0x88b0cc0, 0x800, 0x59},
    // POKEMON_MUSCHAS
    {(void*) 0x8d6cfac, 0x800, 0x5a},
    // POKEMON_AUSTOS
    {(void*) 0x8d6db64, 0x800, 0x5b},
    // POKEMON_NEBULAK
    {(void*) 0x88b18e0, 0x800, 0x5c},
    // POKEMON_ALPOLLO
    {(void*) 0x88b1cc0, 0x800, 0x5d},
    // POKEMON_GENGAR
    {(void*) 0x88b2468, 0x800, 0x5e},
    // POKEMON_ONIX
    {(void*) 0x88b2834, 0x800, 0x5f},
    // POKEMON_TRAUMATO
    {(void*) 0x88b2d40, 0x800, 0x60},
    // POKEMON_HYPNO
    {(void*) 0x88b309c, 0x800, 0x61},
    // POKEMON_KRABBY
    {(void*) 0x8d72ae0, 0x800, 0x62},
    // POKEMON_KINGLER
    {(void*) 0x88b38a8, 0x800, 0x63},
    // POKEMON_VOLTOBAL
    {(void*) 0x8d74154, 0x800, 0x64},
    // POKEMON_LEKTROBAL
    {(void*) 0x937a790, 0x800, 0x65},
    // POKEMON_OWEI
    {(void*) 0x8d75504, 0x800, 0x66},
    // POKEMON_KOKOWEI
    {(void*) 0x937afb0, 0x800, 0x67},
    // POKEMON_TRAGOSSO
    {(void*) 0x937b3a0, 0x800, 0x68},
    // POKEMON_KNOGGA
    {(void*) 0x937b760, 0x800, 0x69},
    // POKEMON_KICKLEE
    {(void*) 0x937bb10, 0x800, 0x6a},
    // POKEMON_NOCKCHAN
    {(void*) 0x937c2a4, 0x800, 0x6b},
    // POKEMON_SCHLURP
    {(void*) 0x937cb1c, 0x800, 0x6c},
    // POKEMON_SMOGON
    {(void*) 0x937d1d8, 0x800, 0x6d},
    // POKEMON_SMOGMOG
    {(void*) 0x88b5694, 0x800, 0x6e},
    // POKEMON_RIHORN
    {(void*) 0x937d5d0, 0x800, 0x6f},
    // POKEMON_RIZEROS
    {(void*) 0x8d7c694, 0x800, 0x70},
    // POKEMON_CHANEIRA
    {(void*) 0x937df00, 0x800, 0x71},
    // POKEMON_ZOBIRIS
    {(void*) 0x8a33ec8, 0x800, 0x72},
    // POKEMON_KANGAMA
    {(void*) 0x8d7e9d8, 0x800, 0x73},
    // POKEMON_SEEPER
    {(void*) 0x8d7f4e4, 0x800, 0x74},
    // POKEMON_SEEMON
    {(void*) 0x937e330, 0x800, 0x75},
    // POKEMON_QUABBEL
    {(void*) 0x890d97c, 0x800, 0x76},
    // POKEMON_APOQUALLYP
    {(void*) 0x890e550, 0x800, 0x77},
    // POKEMON_STERNDU
    {(void*) 0x937ea84, 0x800, 0x78},
    // POKEMON_STARMIE
    {(void*) 0x937f22c, 0x800, 0x79},
    // POKEMON_TRAUNFUGIL
    {(void*) 0x8a34750, 0x800, 0x7a},
    // POKEMON_SICHLOR
    {(void*) 0x937f6c0, 0x800, 0x7b},
    // POKEMON_GALAGLADI
    {(void*) 0x879e008, 0x800, 0x7c},
    // POKEMON_ELEKTEK
    {(void*) 0x937fb70, 0x800, 0x7d},
    // POKEMON_MAGMAR
    {(void*) 0x9380410, 0x800, 0x7e},
    // POKEMON_PINSIR
    {(void*) 0x9380cc4, 0x800, 0x7f},
    // POKEMON_TAUROS
    {(void*) 0x8d87eb8, 0x800, 0x80},
    // POKEMON_KARPADOR
    {(void*) 0x9381450, 0x800, 0x81},
    // POKEMON_GARADOS
    {(void*) 0x8d89668, 0x800, 0x82},
    // POKEMON_LAPRAS
    {(void*) 0x88b60c4, 0x800, 0x83},
    // POKEMON_DITTO
    {(void*) 0x8d8ad0c, 0x800, 0x84},
    // POKEMON_EVOLI
    {(void*) 0x8d8b660, 0x800, 0x85},
    // POKEMON_AQUANA
    {(void*) 0x8a29c80, 0x800, 0x86},
    // POKEMON_BLITZA
    {(void*) 0x8a290b8, 0x800, 0x87},
    // POKEMON_FLAMARA
    {(void*) 0x89119e0, 0x800, 0x88},
    // POKEMON_PORYGON
    {(void*) 0x9382520, 0x800, 0x89},
    // POKEMON_AMONITAS
    {(void*) 0x8d8ec1c, 0x800, 0x8a},
    // POKEMON_AMOROSO
    {(void*) 0x9382ff8, 0x800, 0x8b},
    // POKEMON_KABUTO
    {(void*) 0x938362c, 0x800, 0x8c},
    // POKEMON_KABUTOPS
    {(void*) 0x9383da8, 0x800, 0x8d},
    // POKEMON_AERODACTYL
    {(void*) 0x8d918e4, 0x800, 0x8e},
    // POKEMON_RELAXO
    {(void*) 0x9384b60, 0x800, 0x8f},
    // POKEMON_ARKTOS
    {(void*) 0x938530c, 0x800, 0x90},
    // POKEMON_ZAPDOS
    {(void*) 0x8d93acc, 0x800, 0x91},
    // POKEMON_LAVADOS
    {(void*) 0x9385b50, 0x800, 0x92},
    // POKEMON_DRATINI
    {(void*) 0x9385f20, 0x800, 0x93},
    // POKEMON_DRAGONIR
    {(void*) 0x8d95c3c, 0x800, 0x94},
    // POKEMON_DRAGORAN
    {(void*) 0x93862a0, 0x800, 0x95},
    // POKEMON_MEWTU
    {(void*) 0x88b6904, 0x800, 0x96},
    // POKEMON_MEW
    {(void*) 0x891233c, 0x800, 0x97},
    // POKEMON_ENDIVIE
    {(void*) 0x8912b18, 0x800, 0x98},
    // POKEMON_LORBLATT
    {(void*) 0x891352c, 0x800, 0x99},
    // POKEMON_MEGANIE
    {(void*) 0x8914214, 0x800, 0x9a},
    // POKEMON_FEURIGEL
    {(void*) 0x88b71cc, 0x800, 0x9b},
    // POKEMON_IGELAVAR
    {(void*) 0x88b7cb8, 0x800, 0x9c},
    // POKEMON_TORNUPTO
    {(void*) 0x8916280, 0x800, 0x9d},
    // POKEMON_KARNIMANI
    {(void*) 0x8916ccc, 0x800, 0x9e},
    // POKEMON_TYRACROC
    {(void*) 0x8917614, 0x800, 0x9f},
    // POKEMON_IMPERGATOR
    {(void*) 0x8918330, 0x800, 0xa0},
    // POKEMON_IGNIVOR
    {(void*) 0x93867e0, 0x800, 0xa1},
    // POKEMON_RAMOTH
    {(void*) 0x9386f64, 0x800, 0xa2},
    // POKEMON_GLAZIOLA
    {(void*) 0x9387738, 0x800, 0xa3},
    // POKEMON_RESLADERO
    {(void*) 0x8da117c, 0x800, 0xa4},
    // POKEMON_LEDYBA
    {(void*) 0x8da1c3c, 0x800, 0xa5},
    // POKEMON_LEDIAN
    {(void*) 0x938862c, 0x800, 0xa6},
    // POKEMON_WEBARAK
    {(void*) 0x9388d28, 0x800, 0xa7},
    // POKEMON_ARIADOS
    {(void*) 0x8da3c34, 0x800, 0xa8},
    // POKEMON_IKSBAT
    {(void*) 0x8da47cc, 0x800, 0xa9},
    // POKEMON_LAMPI
    {(void*) 0x93897f4, 0x800, 0xaa},
    // POKEMON_LANTURN
    {(void*) 0x9389f88, 0x800, 0xab},
    // POKEMON_MAGNEZONE
    {(void*) 0x8863970, 0x800, 0xac},
    // POKEMON_TOGEKISS
    {(void*) 0x8918fbc, 0x800, 0xad},
    // POKEMON_FLABEBE
    {(void*) 0x9394ff0, 0x800, 0xae},
    // POKEMON_TOGEPI
    {(void*) 0x87d4eb4, 0x800, 0xaf},
    // POKEMON_TOGETIC
    {(void*) 0x8da8998, 0x800, 0xb0},
    // POKEMON_NATU
    {(void*) 0x938aff0, 0x800, 0xb1},
    // POKEMON_XATU
    {(void*) 0x8da9c60, 0x800, 0xb2},
    // POKEMON_VOLTILAMM
    {(void*) 0x8daa6fc, 0x800, 0xb3},
    // POKEMON_WAATY
    {(void*) 0x8dab160, 0x800, 0xb4},
    // POKEMON_AMPHAROS
    {(void*) 0x8dabc48, 0x800, 0xb5},
    // POKEMON_BLUBELLA
    {(void*) 0x8dac6a0, 0x800, 0xb6},
    // POKEMON_MARILL
    {(void*) 0x8dad0f8, 0x800, 0xb7},
    // POKEMON_AZUMARILL
    {(void*) 0x938c9d8, 0x800, 0xb8},
    // POKEMON_MOGELBAUM
    {(void*) 0x938d04c, 0x800, 0xb9},
    // POKEMON_CLAVION
    {(void*) 0x93b1440, 0x800, 0xba},
    // POKEMON_LICHTEL
    {(void*) 0x879275c, 0x800, 0xbb},
    // POKEMON_LATERNECTO
    {(void*) 0x8797570, 0x800, 0xbc},
    // POKEMON_SKLELABRA
    {(void*) 0x8db0ed4, 0x800, 0xbd},
    // POKEMON_GRIFFEL
    {(void*) 0x938e1dc, 0x800, 0xbe},
    // POKEMON_SHNEBEDECK
    {(void*) 0x8919998, 0x800, 0xbf},
    // POKEMON_REXBLISAR
    {(void*) 0x891a714, 0x800, 0xc0},
    // POKEMON_AMBIDIFFEL
    {(void*) 0x891b450, 0x800, 0xc1},
    // POKEMON_FELINO
    {(void*) 0x938e85c, 0x800, 0xc2},
    // POKEMON_MORLORD
    {(void*) 0x8db4ec8, 0x800, 0xc3},
    // POKEMON_PSIANA
    {(void*) 0x938ec30, 0x800, 0xc4},
    // POKEMON_NACHTARA
    {(void*) 0x8db63cc, 0x800, 0xc5},
    // POKEMON_KRAMURX
    {(void*) 0x8db6e30, 0x800, 0xc6},
    // POKEMON_LASCHOKING
    {(void*) 0x938f4b0, 0x800, 0xc7},
    // POKEMON_KRAMSHEF
    {(void*) 0x8861d8c, 0x800, 0xc8},
    // POKEMON_ICOGNITO
    {(void*) 0x8db8d88, 0x800, 0xc9},
    // POKEMON_FROSDEDJE
    {(void*) 0x8c48858, 0x800, 0xca},
    // POKEMON_SKORGRO
    {(void*) 0x8862dbc, 0x800, 0xcb},
    // POKEMON_TANNZA
    {(void*) 0x938f900, 0x800, 0xcc},
    // POKEMON_FORSTELLKA
    {(void*) 0x9390118, 0x800, 0xcd},
    // POKEMON_ELEVOLTEK
    {(void*) 0x891c25c, 0x800, 0xce},
    // POKEMON_SKORGLA
    {(void*) 0x8dbce84, 0x800, 0xcf},
    // POKEMON_STAHLOS
    {(void*) 0x8dbdb90, 0x800, 0xd0},
    // POKEMON_SNUBBULL
    {(void*) 0x8dbe6dc, 0x800, 0xd1},
    // POKEMON_GRANBULL
    {(void*) 0x8dbf200, 0x800, 0xd2},
    // POKEMON_MAMUTEL
    {(void*) 0x891cf68, 0x800, 0xd3},
    // POKEMON_SCHEROX
    {(void*) 0x93912d0, 0x800, 0xd4},
    // POKEMON_POTTROTT
    {(void*) 0x9391a04, 0x800, 0xd5},
    // POKEMON_SKARABORN
    {(void*) 0x8dc1dfc, 0x800, 0xd6},
    // POKEMON_KRYPPUK
    {(void*) 0x8dc2d20, 0x800, 0xd7},
    // POKEMON_TEDDIURSA
    {(void*) 0x9392024, 0x800, 0xd8},
    // POKEMON_URSARING
    {(void*) 0x8dc427c, 0x800, 0xd9},
    // POKEMON_SCHNECKMAG
    {(void*) 0x9392a98, 0x800, 0xda},
    // POKEMON_MAGCARGO
    {(void*) 0x8dc5780, 0x800, 0xdb},
    // POKEMON_QUIEKEL
    {(void*) 0x9393510, 0x800, 0xdc},
    // POKEMON_KEIFEL
    {(void*) 0x8dc6bd8, 0x800, 0xdd},
    // POKEMON_CORASONN
    {(void*) 0x8dc757c, 0x800, 0xde},
    // POKEMON_REMORAID
    {(void*) 0x8dc7f14, 0x800, 0xdf},
    // POKEMON_OCTILLERY
    {(void*) 0x8dc89cc, 0x800, 0xe0},
    // POKEMON_BOTOGEL
    {(void*) 0x8dc9464, 0x800, 0xe1},
    // POKEMON_SCHLURPLEK
    {(void*) 0x877c404, 0x800, 0xe2},
    // POKEMON_PANZAERON
    {(void*) 0x8dcad20, 0x800, 0xe3},
    // POKEMON_HUNDUSTER
    {(void*) 0x8dcb74c, 0x800, 0xe4},
    // POKEMON_HUNDEMON
    {(void*) 0x9395b78, 0x800, 0xe5},
    // POKEMON_SEEDRAKING
    {(void*) 0x9395f10, 0x800, 0xe6},
    // POKEMON_PHANPY
    {(void*) 0x8dcd870, 0x800, 0xe7},
    // POKEMON_DONPHAN
    {(void*) 0x9396660, 0x800, 0xe8},
    // POKEMON_PORYGON2
    {(void*) 0x8dcee0c, 0x800, 0xe9},
    // POKEMON_VOLUMINAS
    {(void*) 0x8dcf9ac, 0x800, 0xea},
    // POKEMON_TRAUNMAGIL
    {(void*) 0x8a35964, 0x800, 0xeb},
    // POKEMON_RABAUZ
    {(void*) 0x8dd0f1c, 0x800, 0xec},
    // POKEMON_KAPOERA
    {(void*) 0x8dd1a34, 0x800, 0xed},
    // POKEMON_KUSSILLA
    {(void*) 0x93978bc, 0x800, 0xee},
    // POKEMON_ELEKID
    {(void*) 0x9397eec, 0x800, 0xef},
    // POKEMON_MAGBY
    {(void*) 0x8dd3b60, 0x800, 0xf0},
    // POKEMON_MILTANK
    {(void*) 0x8dd462c, 0x800, 0xf1},
    // POKEMON_HEITEIRA
    {(void*) 0x8dd5220, 0x800, 0xf2},
    // POKEMON_RAIKOU
    {(void*) 0x8dd5ed8, 0x800, 0xf3},
    // POKEMON_ENTEI
    {(void*) 0x8dd6cec, 0x800, 0xf4},
    // POKEMON_SUICUNE
    {(void*) 0x8dd7b04, 0x800, 0xf5},
    // POKEMON_LARVITAR
    {(void*) 0x9399154, 0x800, 0xf6},
    // POKEMON_PUPITAR
    {(void*) 0x8dd90b8, 0x800, 0xf7},
    // POKEMON_DESPOTAR
    {(void*) 0x8dd9d9c, 0x800, 0xf8},
    // POKEMON_LUGIA
    {(void*) 0x8ddaabc, 0x800, 0xf9},
    // POKEMON_HO_OH
    {(void*) 0x8ddb954, 0x800, 0xfa},
    // POKEMON_CELEBI
    {(void*) 0x8ddc44c, 0x800, 0xfb},
    // POKEMON_BISAFLORM
    {(void*) 0x8a1ec24, 0x800, 0xfc},
    // POKEMON_GLURAKM
    {(void*) 0x888f4f4, 0x800, 0xfd},
    // POKEMON_AQUANAM
    {(void*) 0x8a2b2c8, 0x800, 0xfe},
    // POKEMON_BLITZAM
    {(void*) 0x8a2a700, 0x800, 0xff},
    // POKEMON_FLAMARM
    {(void*) 0x8a2587c, 0x800, 0x100},
    // POKEMON_DURENGARDA
    {(void*) 0x8a03304, 0x800, 0x101},
    // POKEMON_IN
    {(void*) 0x8a04ed0, 0x800, 0x102},
    // POKEMON_GAME
    {(void*) 0x8a05d38, 0x800, 0x103},
    // POKEMON_TURTOKM
    {(void*) 0x8a06ae8, 0x800, 0x104},
    // POKEMON_AMPHARAOSM
    {(void*) 0x8a21e80, 0x800, 0x105},
    // POKEMON_GENGARM
    {(void*) 0x8a2790c, 0x800, 0x106},
    // POKEMON_BIBORM
    {(void*) 0x877cab8, 0x800, 0x107},
    // POKEMON_ALTARIAM
    {(void*) 0x8a2eb5c, 0x800, 0x108},
    // POKEMON_GEOWAZM
    {(void*) 0x8a2f868, 0x800, 0x109},
    // POKEMON_SENGOM
    {(void*) 0x8a31b04, 0x800, 0x10a},
    // POKEMON_VIPITISM
    {(void*) 0x8a32ed0, 0x800, 0x10b},
    // POKEMON_ZOBIRISM
    {(void*) 0x8a36f94, 0x800, 0x10c},
    // POKEMON_10d
    {(void*) 0x8ddcdd8, 0x800, 0x10d},
    // POKEMON_10e
    {(void*) 0x8ddcdd8, 0x800, 0x10e},
    // POKEMON_10f
    {(void*) 0x8ddcdd8, 0x800, 0x10f},
    // POKEMON_110
    {(void*) 0x8ddcdd8, 0x800, 0x110},
    // POKEMON_111
    {(void*) 0x8ddcdd8, 0x800, 0x111},
    // POKEMON_112
    {(void*) 0x8ddcdd8, 0x800, 0x112},
    // POKEMON_113
    {(void*) 0x8ddcdd8, 0x800, 0x113},
    // POKEMON_114
    {(void*) 0x8ddcdd8, 0x800, 0x114},
    // POKEMON_LOCKSCHAL
    {(void*) 0x8a38830, 0x800, 0x115},
    // POKEMON_STICHSCHAL
    {(void*) 0x8a39130, 0x800, 0x116},
    // POKEMON_STAHLSTICH
    {(void*) 0x8a39d38, 0x800, 0x117},
    // POKEMON_WELUNO
    {(void*) 0x8769b00, 0x800, 0x118},
    // POKEMON_ORTHODOS
    {(void*) 0x87741a4, 0x800, 0x119},
    // POKEMON_ZERBERTRES
    {(void*) 0x878c15c, 0x800, 0x11a},
    // POKEMON_SEEKID
    {(void*) 0x8a3a7fc, 0x800, 0x11b},
    // POKEMON_SEESKULL
    {(void*) 0x8a3b07c, 0x800, 0x11c},
    // POKEMON_SKULLYDRA
    {(void*) 0x8a3bbac, 0x800, 0x11d},
    // POKEMON_FIFFYEN
    {(void*) 0x8de3ca4, 0x800, 0x11e},
    // POKEMON_MAGNAYEN
    {(void*) 0x8de4878, 0x800, 0x11f},
    // POKEMON_ZIGZACHS
    {(void*) 0x88bbbac, 0x800, 0x120},
    // POKEMON_GERADAKS
    {(void*) 0x8de5f50, 0x800, 0x121},
    // POKEMON_WAUMPEL
    {(void*) 0x939ae78, 0x800, 0x122},
    // POKEMON_SCHALOKO
    {(void*) 0x939b494, 0x800, 0x123},
    // POKEMON_PAPINELLA
    {(void*) 0x88bc674, 0x800, 0x124},
    // POKEMON_PANEKON
    {(void*) 0x939ba14, 0x800, 0x125},
    // POKEMON_PUDOX
    {(void*) 0x939c400, 0x800, 0x126},
    // POKEMON_LOTURZEL
    {(void*) 0x939cab4, 0x800, 0x127},
    // POKEMON_LOMBRERO
    {(void*) 0x939d160, 0x800, 0x128},
    // POKEMON_KAPPALORES
    {(void*) 0x939da04, 0x800, 0x129},
    // POKEMON_SAMURZEL
    {(void*) 0x8deba98, 0x800, 0x12a},
    // POKEMON_BLANAS
    {(void*) 0x939e278, 0x800, 0x12b},
    // POKEMON_TENGULIST
    {(void*) 0x939e5b0, 0x800, 0x12c},
    // POKEMON_NINCADA
    {(void*) 0x8deda9c, 0x800, 0x12d},
    // POKEMON_NINJASK
    {(void*) 0x8dee534, 0x800, 0x12e},
    // POKEMON_NINJATOM
    {(void*) 0x939f3dc, 0x800, 0x12f},
    // POKEMON_SCHWALBINI
    {(void*) 0x939fb18, 0x800, 0x130},
    // POKEMON_SCHWALBOSS
    {(void*) 0x8df054c, 0x800, 0x131},
    // POKEMON_KNILZ
    {(void*) 0x93a008c, 0x800, 0x132},
    // POKEMON_KAPILZ
    {(void*) 0x8df1a94, 0x800, 0x133},
    // POKEMON_PANDIR
    {(void*) 0x8df25e4, 0x800, 0x134},
    // POKEMON_WINGULL
    {(void*) 0x8df2fcc, 0x800, 0x135},
    // POKEMON_PELIPPER
    {(void*) 0x8df3b24, 0x800, 0x136},
    // POKEMON_GEHWEIHER
    {(void*) 0x93a125c, 0x800, 0x137},
    // POKEMON_MASKEREGEN
    {(void*) 0x93a1978, 0x800, 0x138},
    // POKEMON_WAILMER
    {(void*) 0x93a219c, 0x800, 0x139},
    // POKEMON_WAILORD
    {(void*) 0x8df6424, 0x800, 0x13a},
    // POKEMON_ENECO
    {(void*) 0x93a2be4, 0x800, 0x13b},
    // POKEMON_ENEKORO
    {(void*) 0x93a3350, 0x800, 0x13c},
    // POKEMON_KECLEON
    {(void*) 0x8df847c, 0x800, 0x13d},
    // POKEMON_PUPPANCE
    {(void*) 0x93a3e1c, 0x800, 0x13e},
    // POKEMON_LEPUMENTAS
    {(void*) 0x93a4608, 0x800, 0x13f},
    // POKEMON_NASGNET
    {(void*) 0x891f7c8, 0x800, 0x140},
    // POKEMON_MAGBRANT
    {(void*) 0x8920880, 0x800, 0x141},
    // POKEMON_ZWIRRFINST
    {(void*) 0x8921520, 0x800, 0x142},
    // POKEMON_SCHMERBE
    {(void*) 0x93a4b50, 0x800, 0x143},
    // POKEMON_WELSAR
    {(void*) 0x93a529c, 0x800, 0x144},
    // POKEMON_LIEBISKUS
    {(void*) 0x93a5868, 0x800, 0x145},
    // POKEMON_KREBSCORPS
    {(void*) 0x93a5eac, 0x800, 0x146},
    // POKEMON_KREBUTACK
    {(void*) 0x8dfee50, 0x800, 0x147},
    // POKEMON_BARSCHWA
    {(void*) 0x93a6a24, 0x800, 0x148},
    // POKEMON_MILOTIC
    {(void*) 0x93a7308, 0x800, 0x149},
    // POKEMON_KANIVANHA
    {(void*) 0x93a7a84, 0x800, 0x14a},
    // POKEMON_TOHAIDO
    {(void*) 0x8e01b08, 0x800, 0x14b},
    // POKEMON_KNACKLION
    {(void*) 0x93a810c, 0x800, 0x14c},
    // POKEMON_VIBRAVA
    {(void*) 0x93a8784, 0x800, 0x14d},
    // POKEMON_LIBELLDRA
    {(void*) 0x8e03ac4, 0x800, 0x14e},
    // POKEMON_RIOLU
    {(void*) 0x8921e80, 0x800, 0x14f},
    // POKEMON_LUCARIO
    {(void*) 0x89227c8, 0x800, 0x150},
    // POKEMON_FRIZELBLIZ
    {(void*) 0x93a8e78, 0x800, 0x151},
    // POKEMON_VOLTENSO
    {(void*) 0x93a95c8, 0x800, 0x152},
    // POKEMON_CAMAUB
    {(void*) 0x93a9c84, 0x800, 0x153},
    // POKEMON_CAMERUPT
    {(void*) 0x93aa448, 0x800, 0x154},
    // POKEMON_SEEMOPS
    {(void*) 0x93aaad8, 0x800, 0x155},
    // POKEMON_SEEJONG
    {(void*) 0x88bd284, 0x800, 0x156},
    // POKEMON_WALRAISA
    {(void*) 0x93aad80, 0x800, 0x157},
    // POKEMON_TUSKA
    {(void*) 0x93ab514, 0x800, 0x158},
    // POKEMON_NOKTUSKA
    {(void*) 0x93ab910, 0x800, 0x159},
    // POKEMON_SCHNEPPKE
    {(void*) 0x93abd70, 0x800, 0x15a},
    // POKEMON_FIRNONTOR
    {(void*) 0x8e0c7d0, 0x800, 0x15b},
    // POKEMON_LUNASTEIN
    {(void*) 0x8e0d318, 0x800, 0x15c},
    // POKEMON_SONNFEL
    {(void*) 0x93acd5c, 0x800, 0x15d},
    // POKEMON_AZURILL
    {(void*) 0x8e0ea50, 0x800, 0x15e},
    // POKEMON_SPOINK
    {(void*) 0x93ad7bc, 0x800, 0x15f},
    // POKEMON_GROINK
    {(void*) 0x93adf50, 0x800, 0x160},
    // POKEMON_PLUSLE
    {(void*) 0x93ae5d0, 0x800, 0x161},
    // POKEMON_MINUN
    {(void*) 0x93aeba0, 0x800, 0x162},
    // POKEMON_FLUNKIFER
    {(void*) 0x8e11d90, 0x800, 0x163},
    // POKEMON_MEDITIE
    {(void*) 0x93af674, 0x800, 0x164},
    // POKEMON_MEDITALIS
    {(void*) 0x93afd8c, 0x800, 0x165},
    // POKEMON_WABLU
    {(void*) 0x8e13d9c, 0x800, 0x166},
    // POKEMON_ALTARIA
    {(void*) 0x8e149a0, 0x800, 0x167},
    // POKEMON_ISSO
    {(void*) 0x8e15420, 0x800, 0x168},
    // POKEMON_ZWIRRLICHT
    {(void*) 0x93b0910, 0x800, 0x169},
    // POKEMON_ZWIRRKLOP
    {(void*) 0x93b1094, 0x800, 0x16a},
    // POKEMON_ROSELIA
    {(void*) 0x8e17398, 0x800, 0x16b},
    // POKEMON_BUMMELZ
    {(void*) 0x93b1a88, 0x800, 0x16c},
    // POKEMON_MUNTIER
    {(void*) 0x93b1e00, 0x800, 0x16d},
    // POKEMON_LETARKING
    {(void*) 0x93b26bc, 0x800, 0x16e},
    // POKEMON_SCHLUPPUCK
    {(void*) 0x93b2d84, 0x800, 0x16f},
    // POKEMON_SCHLUKWECH
    {(void*) 0x8e1aa9c, 0x800, 0x170},
    // POKEMON_TROPIUS
    {(void*) 0x8e1b7cc, 0x800, 0x171},
    // POKEMON_KAUMALAT
    {(void*) 0x8c0d9e8, 0x800, 0x172},
    // POKEMON_KNARKSEL
    {(void*) 0x8c0e630, 0x800, 0x173},
    // POKEMON_KNAKRACK
    {(void*) 0x8c0f384, 0x800, 0x174},
    // POKEMON_PERLU
    {(void*) 0x93b3874, 0x800, 0x175},
    // POKEMON_AALABYSS
    {(void*) 0x8e1f0b8, 0x800, 0x176},
    // POKEMON_SAGANABYSS
    {(void*) 0x8e1fb8c, 0x800, 0x177},
    // POKEMON_ABSOL
    {(void*) 0x88bdcf0, 0x800, 0x178},
    // POKEMON_SHUPPET
    {(void*) 0x88be5cc, 0x800, 0x179},
    // POKEMON_BANETTE
    {(void*) 0x8828f20, 0x800, 0x17a},
    // POKEMON_VIPITIS
    {(void*) 0x8e225e4, 0x800, 0x17b},
    // POKEMON_SENGO
    {(void*) 0x8e232ac, 0x800, 0x17c},
    // POKEMON_RELICANTH
    {(void*) 0x8e23e24, 0x800, 0x17d},
    // POKEMON_STOLLUNIOR
    {(void*) 0x93b5170, 0x800, 0x17e},
    // POKEMON_STOLLRAK
    {(void*) 0x93b58cc, 0x800, 0x17f},
    // POKEMON_STOLLOSS
    {(void*) 0x8e25f10, 0x800, 0x180},
    // POKEMON_FORMEO
    {(void*) 0x93b6dcc, 0x800, 0x181},
    // POKEMON_VOLBEAT
    {(void*) 0x88d1e04, 0x800, 0x182},
    // POKEMON_ILLUMISE
    {(void*) 0x93b7990, 0x800, 0x183},
    // POKEMON_LILIEP
    {(void*) 0x93b849c, 0x800, 0x184},
    // POKEMON_WIELIE
    {(void*) 0x93b8cbc, 0x800, 0x185},
    // POKEMON_ANORITH
    {(void*) 0x93b9528, 0x800, 0x186},
    // POKEMON_ARMALDO
    {(void*) 0x93b9880, 0x800, 0x187},
    // POKEMON_TRASLA
    {(void*) 0x93ba030, 0x800, 0x188},
    // POKEMON_KIRLIA
    {(void*) 0x8e2d2c4, 0x800, 0x189},
    // POKEMON_GUARDEVOIR
    {(void*) 0x93ba740, 0x800, 0x18a},
    // POKEMON_KINDWURM
    {(void*) 0x93badd8, 0x800, 0x18b},
    // POKEMON_DRASCHEL
    {(void*) 0x8e2f29c, 0x800, 0x18c},
    // POKEMON_BRUTALANDA
    {(void*) 0x93bba14, 0x800, 0x18d},
    // POKEMON_TANHEL
    {(void*) 0x93bc030, 0x800, 0x18e},
    // POKEMON_METANG
    {(void*) 0x93bc3f0, 0x800, 0x18f},
    // POKEMON_METAGROSS
    {(void*) 0x93bcc58, 0x800, 0x190},
    // POKEMON_REGIROCK
    {(void*) 0x93bd64c, 0x800, 0x191},
    // POKEMON_REGICE
    {(void*) 0x93be028, 0x800, 0x192},
    // POKEMON_REGISTEEL
    {(void*) 0x93be8d4, 0x800, 0x193},
    // POKEMON_KYOGRE
    {(void*) 0x8e350cc, 0x800, 0x194},
    // POKEMON_GROUDON
    {(void*) 0x8e35d48, 0x800, 0x195},
    // POKEMON_RAYQUAZA
    {(void*) 0x93bfd2c, 0x800, 0x196},
    // POKEMON_LATIAS
    {(void*) 0x93c00f0, 0x800, 0x197},
    // POKEMON_LATIOS
    {(void*) 0x8e382bc, 0x800, 0x198},
    // POKEMON_JIRACHI
    {(void*) 0x8e38d98, 0x800, 0x199},
    // POKEMON_DEOXYS
    {(void*) 0x8a37dd4, 0x800, 0x19a},
    // POKEMON_PALIMPALIM
    {(void*) 0x93c0f80, 0x800, 0x19b},
    // POKEMON_EGG
    {(void*) 0x8e3b4cc, 0x800, 0x19c},
    // POKEMON_ICOGNITO_B
    {(void*) 0x8e3b878, 0x800, 0x19d},
    // POKEMON_ICOGNITO_C
    {(void*) 0x8e3c090, 0x800, 0x19e},
    // POKEMON_ICOGNITO_D
    {(void*) 0x8e3c934, 0x800, 0x19f},
    // POKEMON_ICOGNITO_E
    {(void*) 0x8e3d144, 0x800, 0x1a0},
    // POKEMON_ICOGNITO_F
    {(void*) 0x8e3d938, 0x800, 0x1a1},
    // POKEMON_ICOGNITO_G
    {(void*) 0x8e3e130, 0x800, 0x1a2},
    // POKEMON_ICOGNITO_H
    {(void*) 0x8e3e9c0, 0x800, 0x1a3},
    // POKEMON_ICOGNITO_I
    {(void*) 0x8e3f21c, 0x800, 0x1a4},
    // POKEMON_ICOGNITO_J
    {(void*) 0x8e3f988, 0x800, 0x1a5},
    // POKEMON_ICOGNITO_K
    {(void*) 0x8e40140, 0x800, 0x1a6},
    // POKEMON_ICOGNITO_L
    {(void*) 0x8e408e8, 0x800, 0x1a7},
    // POKEMON_ICOGNITO_M
    {(void*) 0x8e410e0, 0x800, 0x1a8},
    // POKEMON_ICOGNITO_N
    {(void*) 0x8e41980, 0x800, 0x1a9},
    // POKEMON_ICOGNITO_O
    {(void*) 0x8e42224, 0x800, 0x1aa},
    // POKEMON_ICOGNITO_P
    {(void*) 0x8e42a84, 0x800, 0x1ab},
    // POKEMON_ICOGNITO_Q
    {(void*) 0x8e431fc, 0x800, 0x1ac},
    // POKEMON_ICOGNITO_R
    {(void*) 0x8e4396c, 0x800, 0x1ad},
    // POKEMON_ICOGNITO_S
    {(void*) 0x8e4411c, 0x800, 0x1ae},
    // POKEMON_ICOGNITO_T
    {(void*) 0x8e44920, 0x800, 0x1af},
    // POKEMON_ICOGNITO_U
    {(void*) 0x8e450ec, 0x800, 0x1b0},
    // POKEMON_ICOGNITO_V
    {(void*) 0x8e45924, 0x800, 0x1b1},
    // POKEMON_ICOGNITO_W
    {(void*) 0x8e46128, 0x800, 0x1b2},
    // POKEMON_ICOGNITO_X
    {(void*) 0x8e468f0, 0x800, 0x1b3},
    // POKEMON_ICOGNITO_Y
    {(void*) 0x8e470b8, 0x800, 0x1b4},
    // POKEMON_ICOGNITO_Z
    {(void*) 0x8e4785c, 0x800, 0x1b5},
    // POKEMON_ICOGNITO_EXCLAMATION
    {(void*) 0x8e47fc8, 0x800, 0x1b6},
    // POKEMON_ICOGNITO_QUESTION
    {(void*) 0x8e4874c, 0x800, 0x1b7},
    // POKEMON_TEST
    {gfx_pkmn_groudon_emperor_backspriteTiles, 0x800, 0x1b8}

};