#include "types.h"
#include "oams.h"
#include "pokemon.h"

palette pokemon_pals[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    {(void*) 0x8d00bd0, 0x0, 0x0},
    // POKEMON_BISASAM
    {(void*) 0x8d2fe6c, 0x1, 0x0},
    // POKEMON_BISAKNOSP
    {(void*) 0x87bff00, 0x2, 0x0},
    // POKEMON_BISAFLOR
    {(void*) 0x8d315e0, 0x3, 0x0},
    // POKEMON_GLUMANDA
    {(void*) 0x8d321b8, 0x4, 0x0},
    // POKEMON_GLUTEXO
    {(void*) 0x8d32c58, 0x5, 0x0},
    // POKEMON_GLURAK
    {(void*) 0x87c8f14, 0x6, 0x0},
    // POKEMON_SCHIGGY
    {(void*) 0x8d343d0, 0x7, 0x0},
    // POKEMON_SCHILLOK
    {(void*) 0x87d3d88, 0x8, 0x0},
    // POKEMON_TURTOK
    {(void*) 0x879da58, 0x9, 0x0},
    // POKEMON_DARTIRI
    {(void*) 0x87ab07c, 0xa, 0x0},
    // POKEMON_DARTIGNIS
    {(void*) 0x87dab34, 0xb, 0x0},
    // POKEMON_FIARO
    {(void*) 0x87e4d44, 0xc, 0x0},
    // POKEMON_HORNLIU
    {(void*) 0x87e52d4, 0xd, 0x0},
    // POKEMON_KOKUNA
    {(void*) 0x87ec0a0, 0xe, 0x0},
    // POKEMON_BIBOR
    {(void*) 0x87ec9a4, 0xf, 0x0},
    // POKEMON_STARALILI
    {(void*) 0x890ba54, 0x10, 0x0},
    // POKEMON_STARAVIA
    {(void*) 0x890c464, 0x11, 0x0},
    // POKEMON_STARAPTOR
    {(void*) 0x890cf50, 0x12, 0x0},
    // POKEMON_BRONZEL
    {(void*) 0x8d3c4f8, 0x13, 0x0},
    // POKEMON_BRONZONG
    {(void*) 0x87edc4c, 0x14, 0x0},
    // POKEMON_MAEHIKEL
    {(void*) 0x87ee788, 0x15, 0x0},
    // POKEMON_CHEVRUMM
    {(void*) 0x8d3e5f8, 0x16, 0x0},
    // POKEMON_PARAGONI
    {(void*) 0x87d7a98, 0x17, 0x0},
    // POKEMON_TROMBORK
    {(void*) 0x87f0a94, 0x18, 0x0},
    // POKEMON_PIKACHU
    {(void*) 0x87f1138, 0x19, 0x0},
    // POKEMON_RAICHU
    {(void*) 0x87f14d4, 0x1a, 0x0},
    // POKEMON_SANDAN
    {(void*) 0x87f1b58, 0x1b, 0x0},
    // POKEMON_SANDAMER
    {(void*) 0x8757738, 0x1c, 0x0},
    // POKEMON_NIDORANW
    {(void*) 0x88b85f0, 0x1d, 0x0},
    // POKEMON_NIDORINA
    {(void*) 0x87f22c4, 0x1e, 0x0},
    // POKEMON_NIDOQUEEN
    {(void*) 0x87f2768, 0x1f, 0x0},
    // POKEMON_NIDORANM
    {(void*) 0x8d45370, 0x20, 0x0},
    // POKEMON_NIDORINO
    {(void*) 0x87f2b94, 0x21, 0x0},
    // POKEMON_NIDOKING
    {(void*) 0x877b338, 0x22, 0x0},
    // POKEMON_FLOETTE
    {(void*) 0x8d47748, 0x23, 0x0},
    // POKEMON_FLORGES
    {(void*) 0x87f3be4, 0x24, 0x0},
    // POKEMON_VULPIX
    {(void*) 0x87f4330, 0x25, 0x0},
    // POKEMON_VULNONA
    {(void*) 0x87f4840, 0x26, 0x0},
    // POKEMON_PUMMELUFF
    {(void*) 0x87b4d04, 0x27, 0x0},
    // POKEMON_KNUDDELUFF
    {(void*) 0x87be1b8, 0x28, 0x0},
    // POKEMON_ZUBAT
    {(void*) 0x87f4ed0, 0x29, 0x0},
    // POKEMON_GOLBAT
    {(void*) 0x87f5668, 0x2a, 0x0},
    // POKEMON_MYRAPLA
    {(void*) 0x87f5c18, 0x2b, 0x0},
    // POKEMON_DUFLOR
    {(void*) 0x87f6390, 0x2c, 0x0},
    // POKEMON_GIFLOR
    {(void*) 0x8d4e15c, 0x2d, 0x0},
    // POKEMON_FOLIPURBA
    {(void*) 0x8d4ec84, 0x2e, 0x0},
    // POKEMON_FEELINARA
    {(void*) 0x87f7af0, 0x2f, 0x0},
    // POKEMON_WATTZAPF
    {(void*) 0x877cf98, 0x30, 0x0},
    // POKEMON_VOLTULA
    {(void*) 0x877d004, 0x31, 0x0},
    // POKEMON_DIGDA
    {(void*) 0x8785d50, 0x32, 0x0},
    // POKEMON_DIGDRI
    {(void*) 0x8785db0, 0x33, 0x0},
    // POKEMON_KASTADUR
    {(void*) 0x8786e7c, 0x34, 0x0},
    // POKEMON_TENTANTEL
    {(void*) 0x87f8bf0, 0x35, 0x0},
    // POKEMON_ENTON
    {(void*) 0x87912f8, 0x36, 0x0},
    // POKEMON_ENTORON
    {(void*) 0x87f8fa8, 0x37, 0x0},
    // POKEMON_MENKI
    {(void*) 0x87f931c, 0x38, 0x0},
    // POKEMON_RASAFF
    {(void*) 0x87f97a4, 0x39, 0x0},
    // POKEMON_FUKANO
    {(void*) 0x87f9b5c, 0x3a, 0x0},
    // POKEMON_ARKANI
    {(void*) 0x87fa540, 0x3b, 0x0},
    // POKEMON_GRAMOKLES
    {(void*) 0x939a6d0, 0x3c, 0x0},
    // POKEMON_DUOKLES
    {(void*) 0x9399fd4, 0x3d, 0x0},
    // POKEMON_DURENGARD
    {(void*) 0x88b9454, 0x3e, 0x0},
    // POKEMON_ABRA
    {(void*) 0x87fbd9c, 0x3f, 0x0},
    // POKEMON_KADABRA
    {(void*) 0x87fc204, 0x40, 0x0},
    // POKEMON_SIMSALA
    {(void*) 0x87fcb10, 0x41, 0x0},
    // POKEMON_MACHOLLO
    {(void*) 0x87fd164, 0x42, 0x0},
    // POKEMON_MASCHOCK
    {(void*) 0x8d5d16c, 0x43, 0x0},
    // POKEMON_MACHOMEI
    {(void*) 0x8d5de18, 0x44, 0x0},
    // POKEMON_KNOFENSA
    {(void*) 0x87fd728, 0x45, 0x0},
    // POKEMON_ULTRIGARIA
    {(void*) 0x8d5f3a0, 0x46, 0x0},
    // POKEMON_SARZENIA
    {(void*) 0x87fe5c4, 0x47, 0x0},
    // POKEMON_TENTACHA
    {(void*) 0x8d609e8, 0x48, 0x0},
    // POKEMON_TENTOXA
    {(void*) 0x8d61618, 0x49, 0x0},
    // POKEMON_KLEINSTEIN
    {(void*) 0x87ff268, 0x4a, 0x0},
    // POKEMON_GEOROK
    {(void*) 0x8d62ba0, 0x4b, 0x0},
    // POKEMON_GEOWAZ
    {(void*) 0x8d636b4, 0x4c, 0x0},
    // POKEMON_PONITA
    {(void*) 0x87ffdb4, 0x4d, 0x0},
    // POKEMON_GALLOPA
    {(void*) 0x88adf2c, 0x4e, 0x0},
    // POKEMON_FLEGMON
    {(void*) 0x88ae530, 0x4f, 0x0},
    // POKEMON_LAHMUS
    {(void*) 0x8d66470, 0x50, 0x0},
    // POKEMON_MAGNETILO
    {(void*) 0x88aea4c, 0x51, 0x0},
    // POKEMON_MAGNETON
    {(void*) 0x88af95c, 0x52, 0x0},
    // POKEMON_PORENTA
    {(void*) 0x88aee68, 0x53, 0x0},
    // POKEMON_DODU
    {(void*) 0x88afcbc, 0x54, 0x0},
    // POKEMON_DODRI
    {(void*) 0x88b01bc, 0x55, 0x0},
    // POKEMON_JURBO
    {(void*) 0x8792094, 0x56, 0x0},
    // POKEMON_JUGONG
    {(void*) 0x8d6b0d4, 0x57, 0x0},
    // POKEMON_SLEIMA
    {(void*) 0x88b0880, 0x58, 0x0},
    // POKEMON_SLEIMOK
    {(void*) 0x88b1034, 0x59, 0x0},
    // POKEMON_MUSCHAS
    {(void*) 0x88b136c, 0x5a, 0x0},
    // POKEMON_AUSTOS
    {(void*) 0x88b1880, 0x5b, 0x0},
    // POKEMON_NEBULAK
    {(void*) 0x88b1c58, 0x5c, 0x0},
    // POKEMON_ALPOLLO
    {(void*) 0x88b2068, 0x5d, 0x0},
    // POKEMON_GENGAR
    {(void*) 0x88b27cc, 0x5e, 0x0},
    // POKEMON_ONIX
    {(void*) 0x88b2ce0, 0x5f, 0x0},
    // POKEMON_TRAUMATO
    {(void*) 0x88b3034, 0x60, 0x0},
    // POKEMON_HYPNO
    {(void*) 0x88b3478, 0x61, 0x0},
    // POKEMON_KRABBY
    {(void*) 0x88b3840, 0x62, 0x0},
    // POKEMON_KINGLER
    {(void*) 0x88b3c3c, 0x63, 0x0},
    // POKEMON_VOLTOBAL
    {(void*) 0x937a43c, 0x64, 0x0},
    // POKEMON_LEKTROBAL
    {(void*) 0x937aa34, 0x65, 0x0},
    // POKEMON_OWEI
    {(void*) 0x937aaa0, 0x66, 0x0},
    // POKEMON_KOKOWEI
    {(void*) 0x8d760a0, 0x67, 0x0},
    // POKEMON_TRAGOSSO
    {(void*) 0x937b6e8, 0x68, 0x0},
    // POKEMON_KNOGGA
    {(void*) 0x937baa8, 0x69, 0x0},
    // POKEMON_KICKLEE
    {(void*) 0x937be98, 0x6a, 0x0},
    // POKEMON_NOCKCHAN
    {(void*) 0x937c69c, 0x6b, 0x0},
    // POKEMON_SCHLURP
    {(void*) 0x937ce2c, 0x6c, 0x0},
    // POKEMON_SMOGON
    {(void*) 0x937d568, 0x6d, 0x0},
    // POKEMON_SMOGMOG
    {(void*) 0x88b566c, 0x6e, 0x0},
    // POKEMON_RIHORN
    {(void*) 0x937d984, 0x6f, 0x0},
    // POKEMON_RIZEROS
    {(void*) 0x8d7c66c, 0x70, 0x0},
    // POKEMON_CHANEIRA
    {(void*) 0x937e1dc, 0x71, 0x0},
    // POKEMON_ZOBIRIS
    {(void*) 0x937e250, 0x72, 0x0},
    // POKEMON_KANGAMA
    {(void*) 0x88b4878, 0x73, 0x0},
    // POKEMON_SEEPER
    {(void*) 0x937e2c0, 0x74, 0x0},
    // POKEMON_SEEMON
    {(void*) 0x937e708, 0x75, 0x0},
    // POKEMON_QUABBEL
    {(void*) 0x890d954, 0x76, 0x0},
    // POKEMON_APOQUALLYP
    {(void*) 0x890e528, 0x77, 0x0},
    // POKEMON_STERNDU
    {(void*) 0x8d821d0, 0x78, 0x0},
    // POKEMON_STARMIE
    {(void*) 0x8d82c48, 0x79, 0x0},
    // POKEMON_TRAUNFUGIL
    {(void*) 0x937f660, 0x7a, 0x0},
    // POKEMON_SICHLOR
    {(void*) 0x937fb04, 0x7b, 0x0},
    // POKEMON_GALAGLADI
    {(void*) 0x879dfe0, 0x7c, 0x0},
    // POKEMON_ELEKTEK
    {(void*) 0x937ff1c, 0x7d, 0x0},
    // POKEMON_MAGMAR
    {(void*) 0x9380800, 0x7e, 0x0},
    // POKEMON_PINSIR
    {(void*) 0x9381070, 0x7f, 0x0},
    // POKEMON_TAUROS
    {(void*) 0x8d87e90, 0x80, 0x0},
    // POKEMON_KARPADOR
    {(void*) 0x8d888fc, 0x81, 0x0},
    // POKEMON_GARADOS
    {(void*) 0x9381e24, 0x82, 0x0},
    // POKEMON_LAPRAS
    {(void*) 0x88b6430, 0x83, 0x0},
    // POKEMON_DITTO
    {(void*) 0x9382090, 0x84, 0x0},
    // POKEMON_EVOLI
    {(void*) 0x93823e0, 0x85, 0x0},
    // POKEMON_AQUANA
    {(void*) 0x9382450, 0x86, 0x0},
    // POKEMON_BLITZA
    {(void*) 0x93824b0, 0x87, 0x0},
    // POKEMON_FLAMARA
    {(void*) 0x89119b8, 0x88, 0x0},
    // POKEMON_PORYGON
    {(void*) 0x9382828, 0x89, 0x0},
    // POKEMON_AMONITAS
    {(void*) 0x9382b44, 0x8a, 0x0},
    // POKEMON_AMOROSO
    {(void*) 0x938334c, 0x8b, 0x0},
    // POKEMON_KABUTO
    {(void*) 0x93838c4, 0x8c, 0x0},
    // POKEMON_KABUTOPS
    {(void*) 0x93841dc, 0x8d, 0x0},
    // POKEMON_AERODACTYL
    {(void*) 0x93846e0, 0x8e, 0x0},
    // POKEMON_RELAXO
    {(void*) 0x8d92404, 0x8f, 0x0},
    // POKEMON_ARKTOS
    {(void*) 0x938561c, 0x90, 0x0},
    // POKEMON_ZAPDOS
    {(void*) 0x9385ae4, 0x91, 0x0},
    // POKEMON_LAVADOS
    {(void*) 0x9385eb4, 0x92, 0x0},
    // POKEMON_DRATINI
    {(void*) 0x93861b4, 0x93, 0x0},
    // POKEMON_DRAGONIR
    {(void*) 0x9386230, 0x94, 0x0},
    // POKEMON_DRAGORAN
    {(void*) 0x9386620, 0x95, 0x0},
    // POKEMON_MEWTU
    {(void*) 0x88b6cdc, 0x96, 0x0},
    // POKEMON_MEW
    {(void*) 0x8912314, 0x97, 0x0},
    // POKEMON_ENDIVIE
    {(void*) 0x8912af0, 0x98, 0x0},
    // POKEMON_LORBLATT
    {(void*) 0x8913504, 0x99, 0x0},
    // POKEMON_MEGANIE
    {(void*) 0x89141ec, 0x9a, 0x0},
    // POKEMON_FEURIGEL
    {(void*) 0x88b71a4, 0x9b, 0x0},
    // POKEMON_IGELAVAR
    {(void*) 0x88b7c90, 0x9c, 0x0},
    // POKEMON_TORNUPTO
    {(void*) 0x9386710, 0x9d, 0x0},
    // POKEMON_KARNIMANI
    {(void*) 0x9386670, 0x9e, 0x0},
    // POKEMON_TYRACROC
    {(void*) 0x89175ec, 0x9f, 0x0},
    // POKEMON_IMPERGATOR
    {(void*) 0x9386770, 0xa0, 0x0},
    // POKEMON_IGNIVOR
    {(void*) 0x8d9f224, 0xa1, 0x0},
    // POKEMON_RAMOTH
    {(void*) 0x8d9fc6c, 0xa2, 0x0},
    // POKEMON_GLAZIOLA
    {(void*) 0x9387a50, 0xa3, 0x0},
    // POKEMON_RESLADERO
    {(void*) 0x9387e90, 0xa4, 0x0},
    // POKEMON_LEDYBA
    {(void*) 0x8da1c14, 0xa5, 0x0},
    // POKEMON_LEDIAN
    {(void*) 0x9388a28, 0xa6, 0x0},
    // POKEMON_WEBARAK
    {(void*) 0x9388fa4, 0xa7, 0x0},
    // POKEMON_ARIADOS
    {(void*) 0x93893f0, 0xa8, 0x0},
    // POKEMON_IKSBAT
    {(void*) 0x9389460, 0xa9, 0x0},
    // POKEMON_LAMPI
    {(void*) 0x9389b80, 0xaa, 0x0},
    // POKEMON_LANTURN
    {(void*) 0x8da5ccc, 0xab, 0x0},
    // POKEMON_MAGNEZONE
    {(void*) 0x8863948, 0xac, 0x0},
    // POKEMON_TOGEKISS
    {(void*) 0x8918f94, 0xad, 0x0},
    // POKEMON_FLABEBE
    {(void*) 0x93952f0, 0xae, 0x0},
    // POKEMON_TOGEPI
    {(void*) 0x87d4e8c, 0xaf, 0x0},
    // POKEMON_TOGETIC
    {(void*) 0x938ad34, 0xb0, 0x0},
    // POKEMON_NATU
    {(void*) 0x938b258, 0xb1, 0x0},
    // POKEMON_XATU
    {(void*) 0x938b5f4, 0xb2, 0x0},
    // POKEMON_VOLTILAMM
    {(void*) 0x8daa6d4, 0xb3, 0x0},
    // POKEMON_WAATY
    {(void*) 0x938bc5c, 0xb4, 0x0},
    // POKEMON_AMPHAROS
    {(void*) 0x938c038, 0xb5, 0x0},
    // POKEMON_BLUBELLA
    {(void*) 0x8dac678, 0xb6, 0x0},
    // POKEMON_MARILL
    {(void*) 0x938c620, 0xb7, 0x0},
    // POKEMON_AZUMARILL
    {(void*) 0x938ccb4, 0xb8, 0x0},
    // POKEMON_MOGELBAUM
    {(void*) 0x938d3c8, 0xb9, 0x0},
    // POKEMON_CLAVION
    {(void*) 0x93b1718, 0xba, 0x0},
    // POKEMON_LICHTEL
    {(void*) 0x8792734, 0xbb, 0x0},
    // POKEMON_LATERNECTO
    {(void*) 0x8797548, 0xbc, 0x0},
    // POKEMON_SKLELABRA
    {(void*) 0x938de60, 0xbd, 0x0},
    // POKEMON_GRIFFEL
    {(void*) 0x938e584, 0xbe, 0x0},
    // POKEMON_SHNEBEDECK
    {(void*) 0x8919970, 0xbf, 0x0},
    // POKEMON_REXBLISAR
    {(void*) 0x891a6ec, 0xc0, 0x0},
    // POKEMON_AMBIDIFFEL
    {(void*) 0x891b428, 0xc1, 0x0},
    // POKEMON_FELINO
    {(void*) 0x938eb44, 0xc2, 0x0},
    // POKEMON_MORLORD
    {(void*) 0x938ebc0, 0xc3, 0x0},
    // POKEMON_PSIANA
    {(void*) 0x938ef58, 0xc4, 0x0},
    // POKEMON_NACHTARA
    {(void*) 0x938efc0, 0xc5, 0x0},
    // POKEMON_KRAMURX
    {(void*) 0x938f030, 0xc6, 0x0},
    // POKEMON_LASCHOKING
    {(void*) 0x938f86c, 0xc7, 0x0},
    // POKEMON_KRAMSHEF
    {(void*) 0x8861d64, 0xc8, 0x0},
    // POKEMON_ICOGNITO
    {(void*) 0x8db8d68, 0xc9, 0x0},
    // POKEMON_FROSDEDJE
    {(void*) 0x8c48830, 0xca, 0x0},
    // POKEMON_SKORGRO
    {(void*) 0x8862d94, 0xcb, 0x0},
    // POKEMON_TANNZA
    {(void*) 0x938fc64, 0xcc, 0x0},
    // POKEMON_FORSTELLKA
    {(void*) 0x939042c, 0xcd, 0x0},
    // POKEMON_ELEVOLTEK
    {(void*) 0x891c234, 0xce, 0x0},
    // POKEMON_SKORGLA
    {(void*) 0x93904a0, 0xcf, 0x0},
    // POKEMON_STAHLOS
    {(void*) 0x9390a90, 0xd0, 0x0},
    // POKEMON_SNUBBULL
    {(void*) 0x9390de4, 0xd1, 0x0},
    // POKEMON_GRANBULL
    {(void*) 0x9391260, 0xd2, 0x0},
    // POKEMON_MAMUTEL
    {(void*) 0x891cf40, 0xd3, 0x0},
    // POKEMON_SCHEROX
    {(void*) 0x9391684, 0xd4, 0x0},
    // POKEMON_POTTROTT
    {(void*) 0x9391c90, 0xd5, 0x0},
    // POKEMON_SKARABORN
    {(void*) 0x9391d00, 0xd6, 0x0},
    // POKEMON_KRYPPUK
    {(void*) 0x8dc2cf8, 0xd7, 0x0},
    // POKEMON_TEDDIURSA
    {(void*) 0x93922a0, 0xd8, 0x0},
    // POKEMON_URSARING
    {(void*) 0x9392780, 0xd9, 0x0},
    // POKEMON_SCHNECKMAG
    {(void*) 0x9392d94, 0xda, 0x0},
    // POKEMON_MAGCARGO
    {(void*) 0x9393280, 0xdb, 0x0},
    // POKEMON_QUIEKEL
    {(void*) 0x9393760, 0xdc, 0x0},
    // POKEMON_KEIFEL
    {(void*) 0x9393b14, 0xdd, 0x0},
    // POKEMON_CORASONN
    {(void*) 0x9393e7c, 0xde, 0x0},
    // POKEMON_REMORAID
    {(void*) 0x9394188, 0xdf, 0x0},
    // POKEMON_OCTILLERY
    {(void*) 0x8dc89a4, 0xe0, 0x0},
    // POKEMON_BOTOGEL
    {(void*) 0x88b9db4, 0xe1, 0x0},
    // POKEMON_SCHLURPLEK
    {(void*) 0x8dca108, 0xe2, 0x0},
    // POKEMON_PANZAERON
    {(void*) 0x9395340, 0xe3, 0x0},
    // POKEMON_HUNDUSTER
    {(void*) 0x93956a0, 0xe4, 0x0},
    // POKEMON_HUNDEMON
    {(void*) 0x9395ea4, 0xe5, 0x0},
    // POKEMON_SEEDRAKING
    {(void*) 0x9396310, 0xe6, 0x0},
    // POKEMON_PHANPY
    {(void*) 0x93965f8, 0xe7, 0x0},
    // POKEMON_DONPHAN
    {(void*) 0x8dce3f0, 0xe8, 0x0},
    // POKEMON_PORYGON2
    {(void*) 0x9396980, 0xe9, 0x0},
    // POKEMON_VOLUMINAS
    {(void*) 0x9396e1c, 0xea, 0x0},
    // POKEMON_TRAUNMAGIL
    {(void*) 0x8a3593c, 0xeb, 0x0},
    // POKEMON_RABAUZ
    {(void*) 0x9397154, 0xec, 0x0},
    // POKEMON_KAPOERA
    {(void*) 0x93975c8, 0xed, 0x0},
    // POKEMON_KUSSILLA
    {(void*) 0x9397b5c, 0xee, 0x0},
    // POKEMON_ELEKID
    {(void*) 0x939824c, 0xef, 0x0},
    // POKEMON_MAGBY
    {(void*) 0x939854c, 0xf0, 0x0},
    // POKEMON_MILTANK
    {(void*) 0x8dd4604, 0xf1, 0x0},
    // POKEMON_HEITEIRA
    {(void*) 0x9398d7c, 0xf2, 0x0},
    // POKEMON_RAIKOU
    {(void*) 0x9398df0, 0xf3, 0x0},
    // POKEMON_ENTEI
    {(void*) 0x9398e50, 0xf4, 0x0},
    // POKEMON_SUICUNE
    {(void*) 0x8dd7adc, 0xf5, 0x0},
    // POKEMON_LARVITAR
    {(void*) 0x9399424, 0xf6, 0x0},
    // POKEMON_PUPITAR
    {(void*) 0x8dd9090, 0xf7, 0x0},
    // POKEMON_DESPOTAR
    {(void*) 0x9399490, 0xf8, 0x0},
    // POKEMON_LUGIA
    {(void*) 0x9399500, 0xf9, 0x0},
    // POKEMON_HO_OH
    {(void*) 0x8ddb92c, 0xfa, 0x0},
    // POKEMON_CELEBI
    {(void*) 0x93997c0, 0xfb, 0x0},
    // POKEMON_BISAFLORM
    {(void*) 0x8a1ebfc, 0xfc, 0x0},
    // POKEMON_GLURAKM
    {(void*) 0x888f4cc, 0xfd, 0x0},
    // POKEMON_AQUANAM
    {(void*) 0x8a2b2a0, 0xfe, 0x0},
    // POKEMON_BLITZAM
    {(void*) 0x8a2a6d8, 0xff, 0x0},
    // POKEMON_FLAMARM
    {(void*) 0x8a25854, 0x100, 0x0},
    // POKEMON_DURENGARDA
    {(void*) 0x8a032dc, 0x101, 0x0},
    // POKEMON_IN
    {(void*) 0x8a04ea8, 0x102, 0x0},
    // POKEMON_GAME
    {(void*) 0x8a05d10, 0x103, 0x0},
    // POKEMON_TURTOKM
    {(void*) 0x8a06ac0, 0x104, 0x0},
    // POKEMON_AMPHARAOSM
    {(void*) 0x8a21e58, 0x105, 0x0},
    // POKEMON_GENGARM
    {(void*) 0x8a278e4, 0x106, 0x0},
    // POKEMON_BIBORM
    {(void*) 0x8744df4, 0x107, 0x0},
    // POKEMON_ALTARIAM
    {(void*) 0x8a2eb34, 0x108, 0x0},
    // POKEMON_GEOWAZM
    {(void*) 0x8a2f840, 0x109, 0x0},
    // POKEMON_SENGOM
    {(void*) 0x8a31adc, 0x10a, 0x0},
    // POKEMON_VIPITISM
    {(void*) 0x8a32ea8, 0x10b, 0x0},
    // POKEMON_ZOBIRISM
    {(void*) 0x8a36f6c, 0x10c, 0x0},
    // POKEMON_10d
    {(void*) 0x8ddcdc4, 0x10d, 0x0},
    // POKEMON_10e
    {(void*) 0x8ddcdc4, 0x10e, 0x0},
    // POKEMON_10f
    {(void*) 0x8ddcdc4, 0x10f, 0x0},
    // POKEMON_110
    {(void*) 0x8ddcdc4, 0x110, 0x0},
    // POKEMON_111
    {(void*) 0x8ddcdc4, 0x111, 0x0},
    // POKEMON_112
    {(void*) 0x8ddcdc4, 0x112, 0x0},
    // POKEMON_113
    {(void*) 0x8ddcdc4, 0x113, 0x0},
    // POKEMON_114
    {(void*) 0x8ddcdc4, 0x114, 0x0},
    // POKEMON_LOCKSCHAL
    {(void*) 0x8a38808, 0x115, 0x0},
    // POKEMON_STICHSCHAL
    {(void*) 0x8a39108, 0x116, 0x0},
    // POKEMON_STAHLSTICH
    {(void*) 0x8a39d10, 0x117, 0x0},
    // POKEMON_WELUNO
    {(void*) 0x8769ad8, 0x118, 0x0},
    // POKEMON_ORTHODOS
    {(void*) 0x877417c, 0x119, 0x0},
    // POKEMON_ZERBERTRES
    {(void*) 0x878c134, 0x11a, 0x0},
    // POKEMON_SEEKID
    {(void*) 0x8a3a7d4, 0x11b, 0x0},
    // POKEMON_SEESKULL
    {(void*) 0x8a3b054, 0x11c, 0x0},
    // POKEMON_SKULLYDRA
    {(void*) 0x8a3bb84, 0x11d, 0x0},
    // POKEMON_FIFFYEN
    {(void*) 0x939aa50, 0x11e, 0x0},
    // POKEMON_MAGNAYEN
    {(void*) 0x939aac0, 0x11f, 0x0},
    // POKEMON_ZIGZACHS
    {(void*) 0x88bbb84, 0x120, 0x0},
    // POKEMON_GERADAKS
    {(void*) 0x939ab30, 0x121, 0x0},
    // POKEMON_WAUMPEL
    {(void*) 0x939b168, 0x122, 0x0},
    // POKEMON_SCHALOKO
    {(void*) 0x8de7230, 0x123, 0x0},
    // POKEMON_PAPINELLA
    {(void*) 0x88bc64c, 0x124, 0x0},
    // POKEMON_PANEKON
    {(void*) 0x939bcbc, 0x125, 0x0},
    // POKEMON_PUDOX
    {(void*) 0x8de9088, 0x126, 0x0},
    // POKEMON_LOTURZEL
    {(void*) 0x939cdc8, 0x127, 0x0},
    // POKEMON_LOMBRERO
    {(void*) 0x939d494, 0x128, 0x0},
    // POKEMON_KAPPALORES
    {(void*) 0x939de44, 0x129, 0x0},
    // POKEMON_SAMURZEL
    {(void*) 0x939deb0, 0x12a, 0x0},
    // POKEMON_BLANAS
    {(void*) 0x8dec4ac, 0x12b, 0x0},
    // POKEMON_TENGULIST
    {(void*) 0x939e95c, 0x12c, 0x0},
    // POKEMON_NINCADA
    {(void*) 0x8deda74, 0x12d, 0x0},
    // POKEMON_NINJASK
    {(void*) 0x8dee50c, 0x12e, 0x0},
    // POKEMON_NINJATOM
    {(void*) 0x939f7cc, 0x12f, 0x0},
    // POKEMON_SCHWALBINI
    {(void*) 0x939fda0, 0x130, 0x0},
    // POKEMON_SCHWALBOSS
    {(void*) 0x8df0524, 0x131, 0x0},
    // POKEMON_KNILZ
    {(void*) 0x93a0370, 0x132, 0x0},
    // POKEMON_KAPILZ
    {(void*) 0x93a0804, 0x133, 0x0},
    // POKEMON_PANDIR
    {(void*) 0x93a0870, 0x134, 0x0},
    // POKEMON_WINGULL
    {(void*) 0x93a0b60, 0x135, 0x0},
    // POKEMON_PELIPPER
    {(void*) 0x93a0fd8, 0x136, 0x0},
    // POKEMON_GEHWEIHER
    {(void*) 0x93a14fc, 0x137, 0x0},
    // POKEMON_MASKEREGEN
    {(void*) 0x93a1dbc, 0x138, 0x0},
    // POKEMON_WAILMER
    {(void*) 0x93a2408, 0x139, 0x0},
    // POKEMON_WAILORD
    {(void*) 0x93a284c, 0x13a, 0x0},
    // POKEMON_ENECO
    {(void*) 0x93a2f30, 0x13b, 0x0},
    // POKEMON_ENEKORO
    {(void*) 0x93a3700, 0x13c, 0x0},
    // POKEMON_KECLEON
    {(void*) 0x93a3b28, 0x13d, 0x0},
    // POKEMON_PUPPANCE
    {(void*) 0x93a40f8, 0x13e, 0x0},
    // POKEMON_LEPUMENTAS
    {(void*) 0x93a4a7c, 0x13f, 0x0},
    // POKEMON_NASGNET
    {(void*) 0x93a4ae0, 0x140, 0x0},
    // POKEMON_MAGBRANT
    {(void*) 0x8920858, 0x141, 0x0},
    // POKEMON_ZWIRRFINST
    {(void*) 0x89214f8, 0x142, 0x0},
    // POKEMON_SCHMERBE
    {(void*) 0x93a4e24, 0x143, 0x0},
    // POKEMON_WELSAR
    {(void*) 0x93a5604, 0x144, 0x0},
    // POKEMON_LIEBISKUS
    {(void*) 0x93a5a7c, 0x145, 0x0},
    // POKEMON_KREBSCORPS
    {(void*) 0x93a61e0, 0x146, 0x0},
    // POKEMON_KREBUTACK
    {(void*) 0x8dfee28, 0x147, 0x0},
    // POKEMON_BARSCHWA
    {(void*) 0x93a6dc4, 0x148, 0x0},
    // POKEMON_MILOTIC
    {(void*) 0x93a76c0, 0x149, 0x0},
    // POKEMON_KANIVANHA
    {(void*) 0x93a7dcc, 0x14a, 0x0},
    // POKEMON_TOHAIDO
    {(void*) 0x93a7e30, 0x14b, 0x0},
    // POKEMON_KNACKLION
    {(void*) 0x93a8388, 0x14c, 0x0},
    // POKEMON_VIBRAVA
    {(void*) 0x93a8aac, 0x14d, 0x0},
    // POKEMON_LIBELLDRA
    {(void*) 0x93a8b20, 0x14e, 0x0},
    // POKEMON_RIOLU
    {(void*) 0x8921e58, 0x14f, 0x0},
    // POKEMON_LUCARIO
    {(void*) 0x89227a0, 0x150, 0x0},
    // POKEMON_FRIZELBLIZ
    {(void*) 0x93a917c, 0x151, 0x0},
    // POKEMON_VOLTENSO
    {(void*) 0x93a9940, 0x152, 0x0},
    // POKEMON_CAMAUB
    {(void*) 0x93a9f44, 0x153, 0x0},
    // POKEMON_CAMERUPT
    {(void*) 0x93aa7c4, 0x154, 0x0},
    // POKEMON_SEEMOPS
    {(void*) 0x93aad0c, 0x155, 0x0},
    // POKEMON_SEEJONG
    {(void*) 0x88bd25c, 0x156, 0x0},
    // POKEMON_WALRAISA
    {(void*) 0x93ab17c, 0x157, 0x0},
    // POKEMON_TUSKA
    {(void*) 0x93ab8a4, 0x158, 0x0},
    // POKEMON_NOKTUSKA
    {(void*) 0x93abd08, 0x159, 0x0},
    // POKEMON_SCHNEPPKE
    {(void*) 0x8e0bc8c, 0x15a, 0x0},
    // POKEMON_FIRNONTOR
    {(void*) 0x93ac4e8, 0x15b, 0x0},
    // POKEMON_LUNASTEIN
    {(void*) 0x93ac884, 0x15c, 0x0},
    // POKEMON_SONNFEL
    {(void*) 0x93ad194, 0x15d, 0x0},
    // POKEMON_AZURILL
    {(void*) 0x93ad4d0, 0x15e, 0x0},
    // POKEMON_SPOINK
    {(void*) 0x93ada84, 0x15f, 0x0},
    // POKEMON_GROINK
    {(void*) 0x8e0fe88, 0x160, 0x0},
    // POKEMON_PLUSLE
    {(void*) 0x93ae8b4, 0x161, 0x0},
    // POKEMON_MINUN
    {(void*) 0x93aee98, 0x162, 0x0},
    // POKEMON_FLUNKIFER
    {(void*) 0x93af310, 0x163, 0x0},
    // POKEMON_MEDITIE
    {(void*) 0x93af9ac, 0x164, 0x0},
    // POKEMON_MEDITALIS
    {(void*) 0x8e132f4, 0x165, 0x0},
    // POKEMON_WABLU
    {(void*) 0x93b0120, 0x166, 0x0},
    // POKEMON_ALTARIA
    {(void*) 0x93b0580, 0x167, 0x0},
    // POKEMON_ISSO
    {(void*) 0x93b089c, 0x168, 0x0},
    // POKEMON_ZWIRRLICHT
    {(void*) 0x93b0bd4, 0x169, 0x0},
    // POKEMON_ZWIRRKLOP
    {(void*) 0x93b13dc, 0x16a, 0x0},
    // POKEMON_ROSELIA
    {(void*) 0x8e17370, 0x16b, 0x0},
    // POKEMON_BUMMELZ
    {(void*) 0x93b1d98, 0x16c, 0x0},
    // POKEMON_MUNTIER
    {(void*) 0x8e189e4, 0x16d, 0x0},
    // POKEMON_LETARKING
    {(void*) 0x93b2ac8, 0x16e, 0x0},
    // POKEMON_SCHLUPPUCK
    {(void*) 0x93b3014, 0x16f, 0x0},
    // POKEMON_SCHLUKWECH
    {(void*) 0x93b3404, 0x170, 0x0},
    // POKEMON_TROPIUS
    {(void*) 0x93b3470, 0x171, 0x0},
    // POKEMON_KAUMALAT
    {(void*) 0x8c0d9c0, 0x172, 0x0},
    // POKEMON_KNARKSEL
    {(void*) 0x8c0e608, 0x173, 0x0},
    // POKEMON_KNAKRACK
    {(void*) 0x8c0f35c, 0x174, 0x0},
    // POKEMON_PERLU
    {(void*) 0x93b3b14, 0x175, 0x0},
    // POKEMON_AALABYSS
    {(void*) 0x93b401c, 0x176, 0x0},
    // POKEMON_SAGANABYSS
    {(void*) 0x93b4404, 0x177, 0x0},
    // POKEMON_ABSOL
    {(void*) 0x88bdcc8, 0x178, 0x0},
    // POKEMON_SHUPPET
    {(void*) 0x88be5a4, 0x179, 0x0},
    // POKEMON_BANETTE
    {(void*) 0x93b4550, 0x17a, 0x0},
    // POKEMON_VIPITIS
    {(void*) 0x93b49f8, 0x17b, 0x0},
    // POKEMON_SENGO
    {(void*) 0x93b4a60, 0x17c, 0x0},
    // POKEMON_RELICANTH
    {(void*) 0x93b4e94, 0x17d, 0x0},
    // POKEMON_STOLLUNIOR
    {(void*) 0x93b542c, 0x17e, 0x0},
    // POKEMON_STOLLRAK
    {(void*) 0x93b5c08, 0x17f, 0x0},
    // POKEMON_STOLLOSS
    {(void*) 0x93b6238, 0x180, 0x0},
    // POKEMON_FORMEO
    {(void*) 0x93b785c, 0x181, 0x0},
    // POKEMON_VOLBEAT
    {(void*) 0x88d1ddc, 0x182, 0x0},
    // POKEMON_ILLUMISE
    {(void*) 0x8e28fb4, 0x183, 0x0},
    // POKEMON_LILIEP
    {(void*) 0x93b8814, 0x184, 0x0},
    // POKEMON_WIELIE
    {(void*) 0x93b9174, 0x185, 0x0},
    // POKEMON_ANORITH
    {(void*) 0x93b9814, 0x186, 0x0},
    // POKEMON_ARMALDO
    {(void*) 0x93b9d5c, 0x187, 0x0},
    // POKEMON_TRASLA
    {(void*) 0x93ba29c, 0x188, 0x0},
    // POKEMON_KIRLIA
    {(void*) 0x93ba310, 0x189, 0x0},
    // POKEMON_GUARDEVOIR
    {(void*) 0x93baa8c, 0x18a, 0x0},
    // POKEMON_KINDWURM
    {(void*) 0x93bb0d0, 0x18b, 0x0},
    // POKEMON_DRASCHEL
    {(void*) 0x93bb468, 0x18c, 0x0},
    // POKEMON_BRUTALANDA
    {(void*) 0x93bbd20, 0x18d, 0x0},
    // POKEMON_TANHEL
    {(void*) 0x93bc390, 0x18e, 0x0},
    // POKEMON_METANG
    {(void*) 0x93bc760, 0x18f, 0x0},
    // POKEMON_METAGROSS
    {(void*) 0x93bd078, 0x190, 0x0},
    // POKEMON_REGIROCK
    {(void*) 0x93bdaf4, 0x191, 0x0},
    // POKEMON_REGICE
    {(void*) 0x93be3bc, 0x192, 0x0},
    // POKEMON_REGISTEEL
    {(void*) 0x93bec20, 0x193, 0x0},
    // POKEMON_KYOGRE
    {(void*) 0x93bf188, 0x194, 0x0},
    // POKEMON_GROUDON
    {(void*) 0x8e35d20, 0x195, 0x0},
    // POKEMON_RAYQUAZA
    {(void*) 0x93c0084, 0x196, 0x0},
    // POKEMON_LATIAS
    {(void*) 0x8e376d4, 0x197, 0x0},
    // POKEMON_LATIOS
    {(void*) 0x93c08d4, 0x198, 0x0},
    // POKEMON_JIRACHI
    {(void*) 0x93c0c80, 0x199, 0x0},
    // POKEMON_DEOXYS
    {(void*) 0x8a37dac, 0x19a, 0x0},
    // POKEMON_PALIMPALIM
    {(void*) 0x93c1258, 0x19b, 0x0},
    // POKEMON_EGG
    {(void*) 0x8e3b680, 0x19c, 0x0},
    // POKEMON_ICOGNITO_B
    {(void*) 0x8db8d68, 0x19d, 0x0},
    // POKEMON_ICOGNITO_C
    {(void*) 0x8db8d68, 0x19e, 0x0},
    // POKEMON_ICOGNITO_D
    {(void*) 0x8db8d68, 0x19f, 0x0},
    // POKEMON_ICOGNITO_E
    {(void*) 0x8db8d68, 0x1a0, 0x0},
    // POKEMON_ICOGNITO_F
    {(void*) 0x8db8d68, 0x1a1, 0x0},
    // POKEMON_ICOGNITO_G
    {(void*) 0x8db8d68, 0x1a2, 0x0},
    // POKEMON_ICOGNITO_H
    {(void*) 0x8db8d68, 0x1a3, 0x0},
    // POKEMON_ICOGNITO_I
    {(void*) 0x8db8d68, 0x1a4, 0x0},
    // POKEMON_ICOGNITO_J
    {(void*) 0x8db8d68, 0x1a5, 0x0},
    // POKEMON_ICOGNITO_K
    {(void*) 0x8db8d68, 0x1a6, 0x0},
    // POKEMON_ICOGNITO_L
    {(void*) 0x8db8d68, 0x1a7, 0x0},
    // POKEMON_ICOGNITO_M
    {(void*) 0x8db8d68, 0x1a8, 0x0},
    // POKEMON_ICOGNITO_N
    {(void*) 0x8db8d68, 0x1a9, 0x0},
    // POKEMON_ICOGNITO_O
    {(void*) 0x8db8d68, 0x1aa, 0x0},
    // POKEMON_ICOGNITO_P
    {(void*) 0x8db8d68, 0x1ab, 0x0},
    // POKEMON_ICOGNITO_Q
    {(void*) 0x8db8d68, 0x1ac, 0x0},
    // POKEMON_ICOGNITO_R
    {(void*) 0x8db8d68, 0x1ad, 0x0},
    // POKEMON_ICOGNITO_S
    {(void*) 0x8db8d68, 0x1ae, 0x0},
    // POKEMON_ICOGNITO_T
    {(void*) 0x8db8d68, 0x1af, 0x0},
    // POKEMON_ICOGNITO_U
    {(void*) 0x8db8d68, 0x1b0, 0x0},
    // POKEMON_ICOGNITO_V
    {(void*) 0x8db8d68, 0x1b1, 0x0},
    // POKEMON_ICOGNITO_W
    {(void*) 0x8db8d68, 0x1b2, 0x0},
    // POKEMON_ICOGNITO_X
    {(void*) 0x8db8d68, 0x1b3, 0x0},
    // POKEMON_ICOGNITO_Y
    {(void*) 0x8db8d68, 0x1b4, 0x0},
    // POKEMON_ICOGNITO_Z
    {(void*) 0x8db8d68, 0x1b5, 0x0},
    // POKEMON_ICOGNITO_EXCLAMATION
    {(void*) 0x8db8d68, 0x1b6, 0x0},
    // POKEMON_ICOGNITO_QUESTION
    {(void*) 0x8db8d68, 0x1b7, 0x0},
    // POKEMON_TEST
    {(void*) 0x93c0084, 0x1b8, 0x0}
};

palette pokemon_shiny_pals[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    {(void*) 0x8d00be8, 0x1f4, 0x0},
    // POKEMON_BISASAM
    {(void*) 0x8d30158, 0x1f5, 0x0},
    // POKEMON_BISAKNOSP
    {(void*) 0x87bff2c, 0x1f6, 0x0},
    // POKEMON_BISAFLOR
    {(void*) 0x8d31ad0, 0x1f7, 0x0},
    // POKEMON_GLUMANDA
    {(void*) 0x8d32464, 0x1f8, 0x0},
    // POKEMON_GLUTEXO
    {(void*) 0x8d32f74, 0x1f9, 0x0},
    // POKEMON_GLURAK
    {(void*) 0x87c8f48, 0x1fa, 0x0},
    // POKEMON_SCHIGGY
    {(void*) 0x8d34680, 0x1fb, 0x0},
    // POKEMON_SCHILLOK
    {(void*) 0x87d3db4, 0x1fc, 0x0},
    // POKEMON_TURTOK
    {(void*) 0x879da8c, 0x1fd, 0x0},
    // POKEMON_DARTIRI
    {(void*) 0x8d368bc, 0x1fe, 0x0},
    // POKEMON_DARTIGNIS
    {(void*) 0x87dab5c, 0x1ff, 0x0},
    // POKEMON_FIARO
    {(void*) 0x87e4d78, 0x200, 0x0},
    // POKEMON_HORNLIU
    {(void*) 0x87e5300, 0x201, 0x0},
    // POKEMON_KOKUNA
    {(void*) 0x87ec0d8, 0x202, 0x0},
    // POKEMON_BIBOR
    {(void*) 0x87ec9d0, 0x203, 0x0},
    // POKEMON_STARALILI
    {(void*) 0x890bff8, 0x204, 0x0},
    // POKEMON_STARAVIA
    {(void*) 0x890c8e4, 0x205, 0x0},
    // POKEMON_STARAPTOR
    {(void*) 0x890d378, 0x206, 0x0},
    // POKEMON_BRONZEL
    {(void*) 0x8d3c7d8, 0x207, 0x0},
    // POKEMON_BRONZONG
    {(void*) 0x87edc80, 0x208, 0x0},
    // POKEMON_MAEHIKEL
    {(void*) 0x87ee7bc, 0x209, 0x0},
    // POKEMON_CHEVRUMM
    {(void*) 0x87ef4cc, 0x20a, 0x0},
    // POKEMON_PARAGONI
    {(void*) 0x87d7acc, 0x20b, 0x0},
    // POKEMON_TROMBORK
    {(void*) 0x87f0ac8, 0x20c, 0x0},
    // POKEMON_PIKACHU
    {(void*) 0x87f116c, 0x20d, 0x0},
    // POKEMON_RAICHU
    {(void*) 0x87f1508, 0x20e, 0x0},
    // POKEMON_SANDAN
    {(void*) 0x87f1b8c, 0x20f, 0x0},
    // POKEMON_SANDAMER
    {(void*) 0x875776c, 0x210, 0x0},
    // POKEMON_NIDORANW
    {(void*) 0x88b8a60, 0x211, 0x0},
    // POKEMON_NIDORINA
    {(void*) 0x87f22f0, 0x212, 0x0},
    // POKEMON_NIDOQUEEN
    {(void*) 0x87f27a0, 0x213, 0x0},
    // POKEMON_NIDORANM
    {(void*) 0x8d456cc, 0x214, 0x0},
    // POKEMON_NIDORINO
    {(void*) 0x87f2bc8, 0x215, 0x0},
    // POKEMON_NIDOKING
    {(void*) 0x877b364, 0x216, 0x0},
    // POKEMON_FLOETTE
    {(void*) 0x87f3370, 0x217, 0x0},
    // POKEMON_FLORGES
    {(void*) 0x87f3c10, 0x218, 0x0},
    // POKEMON_VULPIX
    {(void*) 0x87f4364, 0x219, 0x0},
    // POKEMON_VULNONA
    {(void*) 0x87f4878, 0x21a, 0x0},
    // POKEMON_PUMMELUFF
    {(void*) 0x87b4d3c, 0x21b, 0x0},
    // POKEMON_KNUDDELUFF
    {(void*) 0x87be1e4, 0x21c, 0x0},
    // POKEMON_ZUBAT
    {(void*) 0x87f4f04, 0x21d, 0x0},
    // POKEMON_GOLBAT
    {(void*) 0x87f569c, 0x21e, 0x0},
    // POKEMON_MYRAPLA
    {(void*) 0x87f5c50, 0x21f, 0x0},
    // POKEMON_DUFLOR
    {(void*) 0x87f63bc, 0x220, 0x0},
    // POKEMON_GIFLOR
    {(void*) 0x8d4e5d0, 0x221, 0x0},
    // POKEMON_FOLIPURBA
    {(void*) 0x8d4ef4c, 0x222, 0x0},
    // POKEMON_FEELINARA
    {(void*) 0x87f7b28, 0x223, 0x0},
    // POKEMON_WATTZAPF
    {(void*) 0x877cfcc, 0x224, 0x0},
    // POKEMON_VOLTULA
    {(void*) 0x877d038, 0x225, 0x0},
    // POKEMON_DIGDA
    {(void*) 0x8785d7c, 0x226, 0x0},
    // POKEMON_DIGDRI
    {(void*) 0x8785ddc, 0x227, 0x0},
    // POKEMON_KASTADUR
    {(void*) 0x8787248, 0x228, 0x0},
    // POKEMON_TENTANTEL
    {(void*) 0x87f8c28, 0x229, 0x0},
    // POKEMON_ENTON
    {(void*) 0x8791330, 0x22a, 0x0},
    // POKEMON_ENTORON
    {(void*) 0x87f8fd4, 0x22b, 0x0},
    // POKEMON_MENKI
    {(void*) 0x87f9354, 0x22c, 0x0},
    // POKEMON_RASAFF
    {(void*) 0x87f97d8, 0x22d, 0x0},
    // POKEMON_FUKANO
    {(void*) 0x87f9b90, 0x22e, 0x0},
    // POKEMON_ARKANI
    {(void*) 0x87fa574, 0x22f, 0x0},
    // POKEMON_GRAMOKLES
    {(void*) 0x939a704, 0x230, 0x0},
    // POKEMON_DUOKLES
    {(void*) 0x9399ffc, 0x231, 0x0},
    // POKEMON_DURENGARD
    {(void*) 0x88b99d4, 0x232, 0x0},
    // POKEMON_ABRA
    {(void*) 0x87fbdd4, 0x233, 0x0},
    // POKEMON_KADABRA
    {(void*) 0x87fc230, 0x234, 0x0},
    // POKEMON_SIMSALA
    {(void*) 0x87fcb44, 0x235, 0x0},
    // POKEMON_MACHOLLO
    {(void*) 0x87fd198, 0x236, 0x0},
    // POKEMON_MASCHOCK
    {(void*) 0x87576dc, 0x237, 0x0},
    // POKEMON_MACHOMEI
    {(void*) 0x8770290, 0x238, 0x0},
    // POKEMON_KNOFENSA
    {(void*) 0x87fd75c, 0x239, 0x0},
    // POKEMON_ULTRIGARIA
    {(void*) 0x8d5f6c4, 0x23a, 0x0},
    // POKEMON_SARZENIA
    {(void*) 0x87fe5f8, 0x23b, 0x0},
    // POKEMON_TENTACHA
    {(void*) 0x8d60cdc, 0x23c, 0x0},
    // POKEMON_TENTOXA
    {(void*) 0x8d619dc, 0x23d, 0x0},
    // POKEMON_KLEINSTEIN
    {(void*) 0x87ff28c, 0x23e, 0x0},
    // POKEMON_GEOROK
    {(void*) 0x87ff9d8, 0x23f, 0x0},
    // POKEMON_GEOWAZ
    {(void*) 0x8d6399c, 0x240, 0x0},
    // POKEMON_PONITA
    {(void*) 0x87ffde8, 0x241, 0x0},
    // POKEMON_GALLOPA
    {(void*) 0x88adf60, 0x242, 0x0},
    // POKEMON_FLEGMON
    {(void*) 0x88ae564, 0x243, 0x0},
    // POKEMON_LAHMUS
    {(void*) 0x8772a54, 0x244, 0x0},
    // POKEMON_MAGNETILO
    {(void*) 0x88aea78, 0x245, 0x0},
    // POKEMON_MAGNETON
    {(void*) 0x88af988, 0x246, 0x0},
    // POKEMON_PORENTA
    {(void*) 0x8d686bc, 0x247, 0x0},
    // POKEMON_DODU
    {(void*) 0x88afcf4, 0x248, 0x0},
    // POKEMON_DODRI
    {(void*) 0x88b01f0, 0x249, 0x0},
    // POKEMON_JURBO
    {(void*) 0x87920c8, 0x24a, 0x0},
    // POKEMON_JUGONG
    {(void*) 0x8d6b38c, 0x24b, 0x0},
    // POKEMON_SLEIMA
    {(void*) 0x88b08b8, 0x24c, 0x0},
    // POKEMON_SLEIMOK
    {(void*) 0x88b106c, 0x24d, 0x0},
    // POKEMON_MUSCHAS
    {(void*) 0x88b13a4, 0x24e, 0x0},
    // POKEMON_AUSTOS
    {(void*) 0x88b18ac, 0x24f, 0x0},
    // POKEMON_NEBULAK
    {(void*) 0x88b1c8c, 0x250, 0x0},
    // POKEMON_ALPOLLO
    {(void*) 0x88b209c, 0x251, 0x0},
    // POKEMON_GENGAR
    {(void*) 0x88b2800, 0x252, 0x0},
    // POKEMON_ONIX
    {(void*) 0x88b2d10, 0x253, 0x0},
    // POKEMON_TRAUMATO
    {(void*) 0x88b3068, 0x254, 0x0},
    // POKEMON_HYPNO
    {(void*) 0x88b34ac, 0x255, 0x0},
    // POKEMON_KRABBY
    {(void*) 0x88b3874, 0x256, 0x0},
    // POKEMON_KINGLER
    {(void*) 0x88b3c70, 0x257, 0x0},
    // POKEMON_VOLTOBAL
    {(void*) 0x937a474, 0x258, 0x0},
    // POKEMON_LEKTROBAL
    {(void*) 0x937aa68, 0x259, 0x0},
    // POKEMON_OWEI
    {(void*) 0x937aad4, 0x25a, 0x0},
    // POKEMON_KOKOWEI
    {(void*) 0x8d76494, 0x25b, 0x0},
    // POKEMON_TRAGOSSO
    {(void*) 0x937b720, 0x25c, 0x0},
    // POKEMON_KNOGGA
    {(void*) 0x937badc, 0x25d, 0x0},
    // POKEMON_KICKLEE
    {(void*) 0x937becc, 0x25e, 0x0},
    // POKEMON_NOCKCHAN
    {(void*) 0x937c6d0, 0x25f, 0x0},
    // POKEMON_SCHLURP
    {(void*) 0x937ce58, 0x260, 0x0},
    // POKEMON_SMOGON
    {(void*) 0x937d594, 0x261, 0x0},
    // POKEMON_SMOGMOG
    {(void*) 0x88b5c90, 0x262, 0x0},
    // POKEMON_RIHORN
    {(void*) 0x937d9a8, 0x263, 0x0},
    // POKEMON_RIZEROS
    {(void*) 0x937dec8, 0x264, 0x0},
    // POKEMON_CHANEIRA
    {(void*) 0x937e210, 0x265, 0x0},
    // POKEMON_ZOBIRIS
    {(void*) 0x937e284, 0x266, 0x0},
    // POKEMON_KANGAMA
    {(void*) 0x88b48a4, 0x267, 0x0},
    // POKEMON_SEEPER
    {(void*) 0x937e2f8, 0x268, 0x0},
    // POKEMON_SEEMON
    {(void*) 0x937e73c, 0x269, 0x0},
    // POKEMON_QUABBEL
    {(void*) 0x890de20, 0x26a, 0x0},
    // POKEMON_APOQUALLYP
    {(void*) 0x890eb38, 0x26b, 0x0},
    // POKEMON_STERNDU
    {(void*) 0x937edcc, 0x26c, 0x0},
    // POKEMON_STARMIE
    {(void*) 0x8d82f14, 0x26d, 0x0},
    // POKEMON_TRAUNFUGIL
    {(void*) 0x937f68c, 0x26e, 0x0},
    // POKEMON_SICHLOR
    {(void*) 0x937fb38, 0x26f, 0x0},
    // POKEMON_GALAGLADI
    {(void*) 0x879e680, 0x270, 0x0},
    // POKEMON_ELEKTEK
    {(void*) 0x937ff54, 0x271, 0x0},
    // POKEMON_MAGMAR
    {(void*) 0x9380834, 0x272, 0x0},
    // POKEMON_PINSIR
    {(void*) 0x93810a4, 0x273, 0x0},
    // POKEMON_TAUROS
    {(void*) 0x8d8816c, 0x274, 0x0},
    // POKEMON_KARPADOR
    {(void*) 0x8d88c54, 0x275, 0x0},
    // POKEMON_GARADOS
    {(void*) 0x9381e50, 0x276, 0x0},
    // POKEMON_LAPRAS
    {(void*) 0x88b6464, 0x277, 0x0},
    // POKEMON_DITTO
    {(void*) 0x93820c0, 0x278, 0x0},
    // POKEMON_EVOLI
    {(void*) 0x9382414, 0x279, 0x0},
    // POKEMON_AQUANA
    {(void*) 0x938247c, 0x27a, 0x0},
    // POKEMON_BLITZA
    {(void*) 0x93824e8, 0x27b, 0x0},
    // POKEMON_FLAMARA
    {(void*) 0x8911f14, 0x27c, 0x0},
    // POKEMON_PORYGON
    {(void*) 0x938285c, 0x27d, 0x0},
    // POKEMON_AMONITAS
    {(void*) 0x9382b78, 0x27e, 0x0},
    // POKEMON_AMOROSO
    {(void*) 0x9383380, 0x27f, 0x0},
    // POKEMON_KABUTO
    {(void*) 0x93838f8, 0x280, 0x0},
    // POKEMON_KABUTOPS
    {(void*) 0x9384210, 0x281, 0x0},
    // POKEMON_AERODACTYL
    {(void*) 0x938470c, 0x282, 0x0},
    // POKEMON_RELAXO
    {(void*) 0x8d92648, 0x283, 0x0},
    // POKEMON_ARKTOS
    {(void*) 0x9385648, 0x284, 0x0},
    // POKEMON_ZAPDOS
    {(void*) 0x9385b18, 0x285, 0x0},
    // POKEMON_LAVADOS
    {(void*) 0x9385ee8, 0x286, 0x0},
    // POKEMON_DRATINI
    {(void*) 0x93861ec, 0x287, 0x0},
    // POKEMON_DRAGONIR
    {(void*) 0x9386264, 0x288, 0x0},
    // POKEMON_DRAGORAN
    {(void*) 0x8d96c04, 0x289, 0x0},
    // POKEMON_MEWTU
    {(void*) 0x88b6d14, 0x28a, 0x0},
    // POKEMON_MEW
    {(void*) 0x8912770, 0x28b, 0x0},
    // POKEMON_ENDIVIE
    {(void*) 0x8912fa8, 0x28c, 0x0},
    // POKEMON_LORBLATT
    {(void*) 0x8913a3c, 0x28d, 0x0},
    // POKEMON_MEGANIE
    {(void*) 0x8914834, 0x28e, 0x0},
    // POKEMON_FEURIGEL
    {(void*) 0x88b77ec, 0x28f, 0x0},
    // POKEMON_IGELAVAR
    {(void*) 0x88b826c, 0x290, 0x0},
    // POKEMON_TORNUPTO
    {(void*) 0x938673c, 0x291, 0x0},
    // POKEMON_KARNIMANI
    {(void*) 0x93866a4, 0x292, 0x0},
    // POKEMON_TYRACROC
    {(void*) 0x8917b58, 0x293, 0x0},
    // POKEMON_IMPERGATOR
    {(void*) 0x93867a4, 0x294, 0x0},
    // POKEMON_IGNIVOR
    {(void*) 0x8d9f4f0, 0x295, 0x0},
    // POKEMON_RAMOTH
    {(void*) 0x8d9ffbc, 0x296, 0x0},
    // POKEMON_GLAZIOLA
    {(void*) 0x9387a88, 0x297, 0x0},
    // POKEMON_RESLADERO
    {(void*) 0x9387ec4, 0x298, 0x0},
    // POKEMON_LEDYBA
    {(void*) 0x8da1f6c, 0x299, 0x0},
    // POKEMON_LEDIAN
    {(void*) 0x9388a54, 0x29a, 0x0},
    // POKEMON_WEBARAK
    {(void*) 0x9388fd0, 0x29b, 0x0},
    // POKEMON_ARIADOS
    {(void*) 0x9389424, 0x29c, 0x0},
    // POKEMON_IKSBAT
    {(void*) 0x938948c, 0x29d, 0x0},
    // POKEMON_LAMPI
    {(void*) 0x9389bb4, 0x29e, 0x0},
    // POKEMON_LANTURN
    {(void*) 0x8da5ff4, 0x29f, 0x0},
    // POKEMON_MAGNEZONE
    {(void*) 0x8863db8, 0x2a0, 0x0},
    // POKEMON_TOGEKISS
    {(void*) 0x8919460, 0x2a1, 0x0},
    // POKEMON_FLABEBE
    {(void*) 0x9395318, 0x2a2, 0x0},
    // POKEMON_TOGEPI
    {(void*) 0x87d52fc, 0x2a3, 0x0},
    // POKEMON_TOGETIC
    {(void*) 0x938ad68, 0x2a4, 0x0},
    // POKEMON_NATU
    {(void*) 0x938b284, 0x2a5, 0x0},
    // POKEMON_XATU
    {(void*) 0x938b620, 0x2a6, 0x0},
    // POKEMON_VOLTILAMM
    {(void*) 0x8daa9f0, 0x2a7, 0x0},
    // POKEMON_WAATY
    {(void*) 0x938bc88, 0x2a8, 0x0},
    // POKEMON_AMPHAROS
    {(void*) 0x938c06c, 0x2a9, 0x0},
    // POKEMON_BLUBELLA
    {(void*) 0x8dac9c4, 0x2aa, 0x0},
    // POKEMON_MARILL
    {(void*) 0x938c654, 0x2ab, 0x0},
    // POKEMON_AZUMARILL
    {(void*) 0x938cce8, 0x2ac, 0x0},
    // POKEMON_MOGELBAUM
    {(void*) 0x938d3fc, 0x2ad, 0x0},
    // POKEMON_CLAVION
    {(void*) 0x93b174c, 0x2ae, 0x0},
    // POKEMON_LICHTEL
    {(void*) 0x8792b38, 0x2af, 0x0},
    // POKEMON_LATERNECTO
    {(void*) 0x8797904, 0x2b0, 0x0},
    // POKEMON_SKLELABRA
    {(void*) 0x938de98, 0x2b1, 0x0},
    // POKEMON_GRIFFEL
    {(void*) 0x938e5b8, 0x2b2, 0x0},
    // POKEMON_SHNEBEDECK
    {(void*) 0x8919ea8, 0x2b3, 0x0},
    // POKEMON_REXBLISAR
    {(void*) 0x891acb4, 0x2b4, 0x0},
    // POKEMON_AMBIDIFFEL
    {(void*) 0x891ba14, 0x2b5, 0x0},
    // POKEMON_FELINO
    {(void*) 0x938eb7c, 0x2b6, 0x0},
    // POKEMON_MORLORD
    {(void*) 0x938ebf8, 0x2b7, 0x0},
    // POKEMON_PSIANA
    {(void*) 0x938ef8c, 0x2b8, 0x0},
    // POKEMON_NACHTARA
    {(void*) 0x938eff8, 0x2b9, 0x0},
    // POKEMON_KRAMURX
    {(void*) 0x938f064, 0x2ba, 0x0},
    // POKEMON_LASCHOKING
    {(void*) 0x938f898, 0x2bb, 0x0},
    // POKEMON_KRAMSHEF
    {(void*) 0x8862340, 0x2bc, 0x0},
    // POKEMON_ICOGNITO
    {(void*) 0x8db8f88, 0x2bd, 0x0},
    // POKEMON_FROSDEDJE
    {(void*) 0x938f8d0, 0x2be, 0x0},
    // POKEMON_SKORGRO
    {(void*) 0x88632b8, 0x2bf, 0x0},
    // POKEMON_TANNZA
    {(void*) 0x938fc98, 0x2c0, 0x0},
    // POKEMON_FORSTELLKA
    {(void*) 0x9390460, 0x2c1, 0x0},
    // POKEMON_ELEVOLTEK
    {(void*) 0x891c7a0, 0x2c2, 0x0},
    // POKEMON_SKORGLA
    {(void*) 0x93904d4, 0x2c3, 0x0},
    // POKEMON_STAHLOS
    {(void*) 0x9390ab4, 0x2c4, 0x0},
    // POKEMON_SNUBBULL
    {(void*) 0x9390e10, 0x2c5, 0x0},
    // POKEMON_GRANBULL
    {(void*) 0x9391298, 0x2c6, 0x0},
    // POKEMON_MAMUTEL
    {(void*) 0x891d464, 0x2c7, 0x0},
    // POKEMON_SCHEROX
    {(void*) 0x93916b8, 0x2c8, 0x0},
    // POKEMON_POTTROTT
    {(void*) 0x9391cc4, 0x2c9, 0x0},
    // POKEMON_SKARABORN
    {(void*) 0x9391d38, 0x2ca, 0x0},
    // POKEMON_KRYPPUK
    {(void*) 0x8dc3044, 0x2cb, 0x0},
    // POKEMON_TEDDIURSA
    {(void*) 0x93922d8, 0x2cc, 0x0},
    // POKEMON_URSARING
    {(void*) 0x93927ac, 0x2cd, 0x0},
    // POKEMON_SCHNECKMAG
    {(void*) 0x9392dc8, 0x2ce, 0x0},
    // POKEMON_MAGCARGO
    {(void*) 0x93932b4, 0x2cf, 0x0},
    // POKEMON_QUIEKEL
    {(void*) 0x9393794, 0x2d0, 0x0},
    // POKEMON_KEIFEL
    {(void*) 0x9393b48, 0x2d1, 0x0},
    // POKEMON_CORASONN
    {(void*) 0x9393eb4, 0x2d2, 0x0},
    // POKEMON_REMORAID
    {(void*) 0x93941c0, 0x2d3, 0x0},
    // POKEMON_OCTILLERY
    {(void*) 0x8dc8c84, 0x2d4, 0x0},
    // POKEMON_BOTOGEL
    {(void*) 0x88b9de8, 0x2d5, 0x0},
    // POKEMON_SCHLURPLEK
    {(void*) 0x877c714, 0x2d6, 0x0},
    // POKEMON_PANZAERON
    {(void*) 0x939536c, 0x2d7, 0x0},
    // POKEMON_HUNDUSTER
    {(void*) 0x93956d8, 0x2d8, 0x0},
    // POKEMON_HUNDEMON
    {(void*) 0x9395ed8, 0x2d9, 0x0},
    // POKEMON_SEEDRAKING
    {(void*) 0x9396344, 0x2da, 0x0},
    // POKEMON_PHANPY
    {(void*) 0x939662c, 0x2db, 0x0},
    // POKEMON_DONPHAN
    {(void*) 0x8dce714, 0x2dc, 0x0},
    // POKEMON_PORYGON2
    {(void*) 0x93969b4, 0x2dd, 0x0},
    // POKEMON_VOLUMINAS
    {(void*) 0x9396e50, 0x2de, 0x0},
    // POKEMON_TRAUNMAGIL
    {(void*) 0x8a35f18, 0x2df, 0x0},
    // POKEMON_RABAUZ
    {(void*) 0x939718c, 0x2e0, 0x0},
    // POKEMON_KAPOERA
    {(void*) 0x93975fc, 0x2e1, 0x0},
    // POKEMON_KUSSILLA
    {(void*) 0x9397b90, 0x2e2, 0x0},
    // POKEMON_ELEKID
    {(void*) 0x9398284, 0x2e3, 0x0},
    // POKEMON_MAGBY
    {(void*) 0x9398584, 0x2e4, 0x0},
    // POKEMON_MILTANK
    {(void*) 0x8dd49c8, 0x2e5, 0x0},
    // POKEMON_HEITEIRA
    {(void*) 0x9398db4, 0x2e6, 0x0},
    // POKEMON_RAIKOU
    {(void*) 0x9398e1c, 0x2e7, 0x0},
    // POKEMON_ENTEI
    {(void*) 0x9398e7c, 0x2e8, 0x0},
    // POKEMON_SUICUNE
    {(void*) 0x8dd7fe0, 0x2e9, 0x0},
    // POKEMON_LARVITAR
    {(void*) 0x9399458, 0x2ea, 0x0},
    // POKEMON_PUPITAR
    {(void*) 0x8dd93f0, 0x2eb, 0x0},
    // POKEMON_DESPOTAR
    {(void*) 0x93994c4, 0x2ec, 0x0},
    // POKEMON_LUGIA
    {(void*) 0x8ddae90, 0x2ed, 0x0},
    // POKEMON_HO_OH
    {(void*) 0x8ddbd64, 0x2ee, 0x0},
    // POKEMON_CELEBI
    {(void*) 0x93997f4, 0x2ef, 0x0},
    // POKEMON_BISAFLORM
    {(void*) 0x8a1f388, 0x2f0, 0x0},
    // POKEMON_GLURAKM
    {(void*) 0x888fc58, 0x2f1, 0x0},
    // POKEMON_AQUANAM
    {(void*) 0x8a2b7b4, 0x2f2, 0x0},
    // POKEMON_BLITZAM
    {(void*) 0x8a2acd8, 0x2f3, 0x0},
    // POKEMON_FLAMARM
    {(void*) 0x8a25ed0, 0x2f4, 0x0},
    // POKEMON_DURENGARDA
    {(void*) 0x8a03aa0, 0x2f5, 0x0},
    // POKEMON_IN
    {(void*) 0x8a054f0, 0x2f6, 0x0},
    // POKEMON_GAME
    {(void*) 0x8a06310, 0x2f7, 0x0},
    // POKEMON_TURTOKM
    {(void*) 0x8a07064, 0x2f8, 0x0},
    // POKEMON_AMPHARAOSM
    {(void*) 0x8a2251c, 0x2f9, 0x0},
    // POKEMON_GENGARM
    {(void*) 0x8a27fa8, 0x2fa, 0x0},
    // POKEMON_BIBORM
    {(void*) 0x8744e20, 0x2fb, 0x0},
    // POKEMON_ALTARIAM
    {(void*) 0x8a2f168, 0x2fc, 0x0},
    // POKEMON_GEOWAZM
    {(void*) 0x8a2fc44, 0x2fd, 0x0},
    // POKEMON_SENGOM
    {(void*) 0x8a32000, 0x2fe, 0x0},
    // POKEMON_VIPITISM
    {(void*) 0x8a336b4, 0x2ff, 0x0},
    // POKEMON_ZOBIRISM
    {(void*) 0x8a3760c, 0x300, 0x0},
    // POKEMON_10d
    {(void*) 0x8ddcf5c, 0x301, 0x0},
    // POKEMON_10e
    {(void*) 0x8ddcf5c, 0x302, 0x0},
    // POKEMON_10f
    {(void*) 0x8ddcf5c, 0x303, 0x0},
    // POKEMON_110
    {(void*) 0x8ddcf5c, 0x304, 0x0},
    // POKEMON_111
    {(void*) 0x8ddcf5c, 0x305, 0x0},
    // POKEMON_112
    {(void*) 0x8ddcf5c, 0x306, 0x0},
    // POKEMON_113
    {(void*) 0x8ddcf5c, 0x307, 0x0},
    // POKEMON_114
    {(void*) 0x8ddcf5c, 0x308, 0x0},
    // POKEMON_LOCKSCHAL
    {(void*) 0x8a38bf8, 0x309, 0x0},
    // POKEMON_STICHSCHAL
    {(void*) 0x8a396bc, 0x30a, 0x0},
    // POKEMON_STAHLSTICH
    {(void*) 0x8a3a468, 0x30b, 0x0},
    // POKEMON_WELUNO
    {(void*) 0x8769e24, 0x30c, 0x0},
    // POKEMON_ORTHODOS
    {(void*) 0x87745fc, 0x30d, 0x0},
    // POKEMON_ZERBERTRES
    {(void*) 0x878c734, 0x30e, 0x0},
    // POKEMON_SEEKID
    {(void*) 0x8a3abb4, 0x30f, 0x0},
    // POKEMON_SEESKULL
    {(void*) 0x8a3b4a0, 0x310, 0x0},
    // POKEMON_SKULLYDRA
    {(void*) 0x8a3c104, 0x311, 0x0},
    // POKEMON_FIFFYEN
    {(void*) 0x939aa84, 0x312, 0x0},
    // POKEMON_MAGNAYEN
    {(void*) 0x939aaf4, 0x313, 0x0},
    // POKEMON_ZIGZACHS
    {(void*) 0x88bc098, 0x314, 0x0},
    // POKEMON_GERADAKS
    {(void*) 0x939ab64, 0x315, 0x0},
    // POKEMON_WAUMPEL
    {(void*) 0x939b19c, 0x316, 0x0},
    // POKEMON_SCHALOKO
    {(void*) 0x8de7474, 0x317, 0x0},
    // POKEMON_PAPINELLA
    {(void*) 0x88bcd48, 0x318, 0x0},
    // POKEMON_PANEKON
    {(void*) 0x939bcf4, 0x319, 0x0},
    // POKEMON_PUDOX
    {(void*) 0x8de9308, 0x31a, 0x0},
    // POKEMON_LOTURZEL
    {(void*) 0x939cdfc, 0x31b, 0x0},
    // POKEMON_LOMBRERO
    {(void*) 0x939d4c8, 0x31c, 0x0},
    // POKEMON_KAPPALORES
    {(void*) 0x939de78, 0x31d, 0x0},
    // POKEMON_SAMURZEL
    {(void*) 0x939dee4, 0x31e, 0x0},
    // POKEMON_BLANAS
    {(void*) 0x8dec79c, 0x31f, 0x0},
    // POKEMON_TENGULIST
    {(void*) 0x939e990, 0x320, 0x0},
    // POKEMON_NINCADA
    {(void*) 0x8dedd54, 0x321, 0x0},
    // POKEMON_NINJASK
    {(void*) 0x8dee900, 0x322, 0x0},
    // POKEMON_NINJATOM
    {(void*) 0x939f800, 0x323, 0x0},
    // POKEMON_SCHWALBINI
    {(void*) 0x939fdd4, 0x324, 0x0},
    // POKEMON_SCHWALBOSS
    {(void*) 0x8df0884, 0x325, 0x0},
    // POKEMON_KNILZ
    {(void*) 0x93a03a8, 0x326, 0x0},
    // POKEMON_KAPILZ
    {(void*) 0x93a0838, 0x327, 0x0},
    // POKEMON_PANDIR
    {(void*) 0x93a08a4, 0x328, 0x0},
    // POKEMON_WINGULL
    {(void*) 0x93a0b94, 0x329, 0x0},
    // POKEMON_PELIPPER
    {(void*) 0x93a1004, 0x32a, 0x0},
    // POKEMON_GEHWEIHER
    {(void*) 0x93a1530, 0x32b, 0x0},
    // POKEMON_MASKEREGEN
    {(void*) 0x93a1df0, 0x32c, 0x0},
    // POKEMON_WAILMER
    {(void*) 0x93a243c, 0x32d, 0x0},
    // POKEMON_WAILORD
    {(void*) 0x93a2880, 0x32e, 0x0},
    // POKEMON_ENECO
    {(void*) 0x93a2f68, 0x32f, 0x0},
    // POKEMON_ENEKORO
    {(void*) 0x93a3734, 0x330, 0x0},
    // POKEMON_KECLEON
    {(void*) 0x93a3b5c, 0x331, 0x0},
    // POKEMON_PUPPANCE
    {(void*) 0x93a412c, 0x332, 0x0},
    // POKEMON_LEPUMENTAS
    {(void*) 0x93a4aa8, 0x333, 0x0},
    // POKEMON_NASGNET
    {(void*) 0x93a4b18, 0x334, 0x0},
    // POKEMON_MAGBRANT
    {(void*) 0x8920ea0, 0x335, 0x0},
    // POKEMON_ZWIRRFINST
    {(void*) 0x8921ac0, 0x336, 0x0},
    // POKEMON_SCHMERBE
    {(void*) 0x93a4e5c, 0x337, 0x0},
    // POKEMON_WELSAR
    {(void*) 0x93a5638, 0x338, 0x0},
    // POKEMON_LIEBISKUS
    {(void*) 0x93a5ab0, 0x339, 0x0},
    // POKEMON_KREBSCORPS
    {(void*) 0x93a6214, 0x33a, 0x0},
    // POKEMON_KREBUTACK
    {(void*) 0x8dff234, 0x33b, 0x0},
    // POKEMON_BARSCHWA
    {(void*) 0x93a6df8, 0x33c, 0x0},
    // POKEMON_MILOTIC
    {(void*) 0x93a76f4, 0x33d, 0x0},
    // POKEMON_KANIVANHA
    {(void*) 0x93a7df8, 0x33e, 0x0},
    // POKEMON_TOHAIDO
    {(void*) 0x93a7e64, 0x33f, 0x0},
    // POKEMON_KNACKLION
    {(void*) 0x93a83c0, 0x340, 0x0},
    // POKEMON_VIBRAVA
    {(void*) 0x93a8ae0, 0x341, 0x0},
    // POKEMON_LIBELLDRA
    {(void*) 0x93a8b4c, 0x342, 0x0},
    // POKEMON_RIOLU
    {(void*) 0x8922238, 0x343, 0x0},
    // POKEMON_LUCARIO
    {(void*) 0x8922d20, 0x344, 0x0},
    // POKEMON_FRIZELBLIZ
    {(void*) 0x93a91b0, 0x345, 0x0},
    // POKEMON_VOLTENSO
    {(void*) 0x93a996c, 0x346, 0x0},
    // POKEMON_CAMAUB
    {(void*) 0x93a9f78, 0x347, 0x0},
    // POKEMON_CAMERUPT
    {(void*) 0x93aa7f0, 0x348, 0x0},
    // POKEMON_SEEMOPS
    {(void*) 0x93aad44, 0x349, 0x0},
    // POKEMON_SEEJONG
    {(void*) 0x88bd694, 0x34a, 0x0},
    // POKEMON_WALRAISA
    {(void*) 0x93ab1b0, 0x34b, 0x0},
    // POKEMON_TUSKA
    {(void*) 0x93ab8d0, 0x34c, 0x0},
    // POKEMON_NOKTUSKA
    {(void*) 0x93abd34, 0x34d, 0x0},
    // POKEMON_SCHNEPPKE
    {(void*) 0x8e0bf98, 0x34e, 0x0},
    // POKEMON_FIRNONTOR
    {(void*) 0x93ac51c, 0x34f, 0x0},
    // POKEMON_LUNASTEIN
    {(void*) 0x93ac8bc, 0x350, 0x0},
    // POKEMON_SONNFEL
    {(void*) 0x93ad1c8, 0x351, 0x0},
    // POKEMON_AZURILL
    {(void*) 0x93ad508, 0x352, 0x0},
    // POKEMON_SPOINK
    {(void*) 0x93adab8, 0x353, 0x0},
    // POKEMON_GROINK
    {(void*) 0x93ae300, 0x354, 0x0},
    // POKEMON_PLUSLE
    {(void*) 0x93ae8ec, 0x355, 0x0},
    // POKEMON_MINUN
    {(void*) 0x93aeecc, 0x356, 0x0},
    // POKEMON_FLUNKIFER
    {(void*) 0x93af344, 0x357, 0x0},
    // POKEMON_MEDITIE
    {(void*) 0x93af9e0, 0x358, 0x0},
    // POKEMON_MEDITALIS
    {(void*) 0x8e13654, 0x359, 0x0},
    // POKEMON_WABLU
    {(void*) 0x93b0158, 0x35a, 0x0},
    // POKEMON_ALTARIA
    {(void*) 0x93b05b8, 0x35b, 0x0},
    // POKEMON_ISSO
    {(void*) 0x93b08d4, 0x35c, 0x0},
    // POKEMON_ZWIRRLICHT
    {(void*) 0x93b0c08, 0x35d, 0x0},
    // POKEMON_ZWIRRKLOP
    {(void*) 0x93b1408, 0x35e, 0x0},
    // POKEMON_ROSELIA
    {(void*) 0x8e17760, 0x35f, 0x0},
    // POKEMON_BUMMELZ
    {(void*) 0x93b1dcc, 0x360, 0x0},
    // POKEMON_MUNTIER
    {(void*) 0x8e18cd4, 0x361, 0x0},
    // POKEMON_LETARKING
    {(void*) 0x93b2afc, 0x362, 0x0},
    // POKEMON_SCHLUPPUCK
    {(void*) 0x93b304c, 0x363, 0x0},
    // POKEMON_SCHLUKWECH
    {(void*) 0x93b3438, 0x364, 0x0},
    // POKEMON_TROPIUS
    {(void*) 0x93b34a8, 0x365, 0x0},
    // POKEMON_KAUMALAT
    {(void*) 0x8c0dfc0, 0x366, 0x0},
    // POKEMON_KNARKSEL
    {(void*) 0x93b34e0, 0x367, 0x0},
    // POKEMON_KNAKRACK
    {(void*) 0x93b3510, 0x368, 0x0},
    // POKEMON_PERLU
    {(void*) 0x93b3b40, 0x369, 0x0},
    // POKEMON_AALABYSS
    {(void*) 0x93b4050, 0x36a, 0x0},
    // POKEMON_SAGANABYSS
    {(void*) 0x93b4438, 0x36b, 0x0},
    // POKEMON_ABSOL
    {(void*) 0x88be1c8, 0x36c, 0x0},
    // POKEMON_SHUPPET
    {(void*) 0x88bea00, 0x36d, 0x0},
    // POKEMON_BANETTE
    {(void*) 0x93b4584, 0x36e, 0x0},
    // POKEMON_VIPITIS
    {(void*) 0x93b4a2c, 0x36f, 0x0},
    // POKEMON_SENGO
    {(void*) 0x93b4a94, 0x370, 0x0},
    // POKEMON_RELICANTH
    {(void*) 0x93b4ec8, 0x371, 0x0},
    // POKEMON_STOLLUNIOR
    {(void*) 0x93b5464, 0x372, 0x0},
    // POKEMON_STOLLRAK
    {(void*) 0x93b5c3c, 0x373, 0x0},
    // POKEMON_STOLLOSS
    {(void*) 0x93b626c, 0x374, 0x0},
    // POKEMON_FORMEO
    {(void*) 0x93b78f0, 0x375, 0x0},
    // POKEMON_VOLBEAT
    {(void*) 0x88d23a4, 0x376, 0x0},
    // POKEMON_ILLUMISE
    {(void*) 0x8e292f8, 0x377, 0x0},
    // POKEMON_LILIEP
    {(void*) 0x93b8848, 0x378, 0x0},
    // POKEMON_WIELIE
    {(void*) 0x93b91a8, 0x379, 0x0},
    // POKEMON_ANORITH
    {(void*) 0x93b9848, 0x37a, 0x0},
    // POKEMON_ARMALDO
    {(void*) 0x93b9d88, 0x37b, 0x0},
    // POKEMON_TRASLA
    {(void*) 0x93ba2d0, 0x37c, 0x0},
    // POKEMON_KIRLIA
    {(void*) 0x93ba348, 0x37d, 0x0},
    // POKEMON_GUARDEVOIR
    {(void*) 0x93baac0, 0x37e, 0x0},
    // POKEMON_KINDWURM
    {(void*) 0x93bb104, 0x37f, 0x0},
    // POKEMON_DRASCHEL
    {(void*) 0x93bb49c, 0x380, 0x0},
    // POKEMON_BRUTALANDA
    {(void*) 0x93bbd54, 0x381, 0x0},
    // POKEMON_TANHEL
    {(void*) 0x93bc3bc, 0x382, 0x0},
    // POKEMON_METANG
    {(void*) 0x93bc78c, 0x383, 0x0},
    // POKEMON_METAGROSS
    {(void*) 0x93bd0a4, 0x384, 0x0},
    // POKEMON_REGIROCK
    {(void*) 0x93bdb28, 0x385, 0x0},
    // POKEMON_REGICE
    {(void*) 0x93be3f4, 0x386, 0x0},
    // POKEMON_REGISTEEL
    {(void*) 0x93bec54, 0x387, 0x0},
    // POKEMON_KYOGRE
    {(void*) 0x93bf1b4, 0x388, 0x0},
    // POKEMON_GROUDON
    {(void*) 0x8e361b0, 0x389, 0x0},
    // POKEMON_RAYQUAZA
    {(void*) 0x93c00b8, 0x38a, 0x0},
    // POKEMON_LATIAS
    {(void*) 0x8e379f8, 0x38b, 0x0},
    // POKEMON_LATIOS
    {(void*) 0x93c0900, 0x38c, 0x0},
    // POKEMON_JIRACHI
    {(void*) 0x93c0cb4, 0x38d, 0x0},
    // POKEMON_DEOXYS
    {(void*) 0x8a38484, 0x38e, 0x0},
    // POKEMON_PALIMPALIM
    {(void*) 0x93c128c, 0x38f, 0x0},
    // POKEMON_EGG
    {(void*) 0x8e3b680, 0x390, 0x0},
    // POKEMON_ICOGNITO_B
    {(void*) 0x8db8f88, 0x391, 0x0},
    // POKEMON_ICOGNITO_C
    {(void*) 0x8db8f88, 0x392, 0x0},
    // POKEMON_ICOGNITO_D
    {(void*) 0x8db8f88, 0x393, 0x0},
    // POKEMON_ICOGNITO_E
    {(void*) 0x8db8f88, 0x394, 0x0},
    // POKEMON_ICOGNITO_F
    {(void*) 0x8db8f88, 0x395, 0x0},
    // POKEMON_ICOGNITO_G
    {(void*) 0x8db8f88, 0x396, 0x0},
    // POKEMON_ICOGNITO_H
    {(void*) 0x8db8f88, 0x397, 0x0},
    // POKEMON_ICOGNITO_I
    {(void*) 0x8db8f88, 0x398, 0x0},
    // POKEMON_ICOGNITO_J
    {(void*) 0x8db8f88, 0x399, 0x0},
    // POKEMON_ICOGNITO_K
    {(void*) 0x8db8f88, 0x39a, 0x0},
    // POKEMON_ICOGNITO_L
    {(void*) 0x8db8f88, 0x39b, 0x0},
    // POKEMON_ICOGNITO_M
    {(void*) 0x8db8f88, 0x39c, 0x0},
    // POKEMON_ICOGNITO_N
    {(void*) 0x8db8f88, 0x39d, 0x0},
    // POKEMON_ICOGNITO_O
    {(void*) 0x8db8f88, 0x39e, 0x0},
    // POKEMON_ICOGNITO_P
    {(void*) 0x8db8f88, 0x39f, 0x0},
    // POKEMON_ICOGNITO_Q
    {(void*) 0x8db8f88, 0x3a0, 0x0},
    // POKEMON_ICOGNITO_R
    {(void*) 0x8db8f88, 0x3a1, 0x0},
    // POKEMON_ICOGNITO_S
    {(void*) 0x8db8f88, 0x3a2, 0x0},
    // POKEMON_ICOGNITO_T
    {(void*) 0x8db8f88, 0x3a3, 0x0},
    // POKEMON_ICOGNITO_U
    {(void*) 0x8db8f88, 0x3a4, 0x0},
    // POKEMON_ICOGNITO_V
    {(void*) 0x8db8f88, 0x3a5, 0x0},
    // POKEMON_ICOGNITO_W
    {(void*) 0x8db8f88, 0x3a6, 0x0},
    // POKEMON_ICOGNITO_X
    {(void*) 0x8db8f88, 0x3a7, 0x0},
    // POKEMON_ICOGNITO_Y
    {(void*) 0x8db8f88, 0x3a8, 0x0},
    // POKEMON_ICOGNITO_Z
    {(void*) 0x8db8f88, 0x3a9, 0x0},
    // POKEMON_ICOGNITO_EXCLAMATION
    {(void*) 0x8db8f88, 0x3aa, 0x0},
    // POKEMON_ICOGNITO_QUESTION
    {(void*) 0x8db8f88, 0x3ab, 0x0},
    // POKEMON_TEST
    {(void*) 0x93c00b8, 0x3ac, 0x0},
};