#include "types.h"
#include "pokemon/count.h"

u32 pokemon_player_y[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    0x88,
    // POKEMON_BISASAM
    0x1064,
    // POKEMON_BISAKNOSP
    0xa76,
    // POKEMON_BISAFLOR
    0xa86,
    // POKEMON_GLUMANDA
    0xa66,
    // POKEMON_GLUTEXO
    0x777,
    // POKEMON_GLURAK
    0x487,
    // POKEMON_SCHIGGY
    0xf75,
    // POKEMON_SCHILLOK
    0xa86,
    // POKEMON_TURTOK
    0xa86,
    // POKEMON_DARTIRI
    0xf55,
    // POKEMON_DARTIGNIS
    0xb65,
    // POKEMON_FIARO
    0x587,
    // POKEMON_HORNLIU
    0x756,
    // POKEMON_KOKUNA
    0xc46,
    // POKEMON_BIBOR
    0x586,
    // POKEMON_STARALILI
    0x66,
    // POKEMON_STARAVIA
    0x85,
    // POKEMON_STARAPTOR
    0x87,
    // POKEMON_BRONZEL
    0xd75,
    // POKEMON_BRONZONG
    0xd75,
    // POKEMON_MAEHIKEL
    0x865,
    // POKEMON_CHEVRUMM
    0xa87,
    // POKEMON_PARAGONI
    0x966,
    // POKEMON_TROMBORK
    0x577,
    // POKEMON_PIKACHU
    0x777,
    // POKEMON_RAICHU
    0x866,
    // POKEMON_SANDAN
    0xd65,
    // POKEMON_SANDAMER
    0xb86,
    // POKEMON_NIDORANW
    0xd55,
    // POKEMON_NIDORINA
    0xa86,
    // POKEMON_NIDOQUEEN
    0x677,
    // POKEMON_NIDORANM
    0x856,
    // POKEMON_NIDORINO
    0x986,
    // POKEMON_NIDOKING
    0x388,
    // POKEMON_FLOETTE
    0x65,
    // POKEMON_FLORGES
    0x976,
    // POKEMON_VULPIX
    0x976,
    // POKEMON_VULNONA
    0x687,
    // POKEMON_PUMMELUFF
    0x65,
    // POKEMON_KNUDDELUFF
    0x66,
    // POKEMON_ZUBAT
    0x776,
    // POKEMON_GOLBAT
    0xd87,
    // POKEMON_MYRAPLA
    0x966,
    // POKEMON_DUFLOR
    0xb76,
    // POKEMON_GIFLOR
    0x687,
    // POKEMON_FOLIPURBA
    0x63,
    // POKEMON_FEELINARA
    0x487,
    // POKEMON_WATTZAPF
    0x1677,
    // POKEMON_VOLTULA
    0xb77,
    // POKEMON_DIGDA
    0x1054,
    // POKEMON_DIGDRI
    0x1166,
    // POKEMON_KASTADUR
    0xf65,
    // POKEMON_TENTANTEL
    0xe87,
    // POKEMON_ENTON
    0x967,
    // POKEMON_ENTORON
    0x577,
    // POKEMON_MENKI
    0x876,
    // POKEMON_RASAFF
    0xa77,
    // POKEMON_FUKANO
    0x866,
    // POKEMON_ARKANI
    0x387,
    // POKEMON_GRAMOKLES
    0x74,
    // POKEMON_DUOKLES
    0x65,
    // POKEMON_DURENGARD
    0x86,
    // POKEMON_ABRA
    0xc55,
    // POKEMON_KADABRA
    0x886,
    // POKEMON_SIMSALA
    0x687,
    // POKEMON_MACHOLLO
    0x665,
    // POKEMON_MASCHOCK
    0x876,
    // POKEMON_MACHOMEI
    0x767,
    // POKEMON_KNOFENSA
    0xb66,
    // POKEMON_ULTRIGARIA
    0xb66,
    // POKEMON_SARZENIA
    0x687,
    // POKEMON_TENTACHA
    0x956,
    // POKEMON_TENTOXA
    0xb86,
    // POKEMON_KLEINSTEIN
    0xb66,
    // POKEMON_GEOROK
    0xa75,
    // POKEMON_GEOWAZ
    0xb84,
    // POKEMON_PONITA
    0x466,
    // POKEMON_GALLOPA
    0x87,
    // POKEMON_FLEGMON
    0xd85,
    // POKEMON_LAHMUS
    0x986,
    // POKEMON_MAGNETILO
    0x643,
    // POKEMON_MAGNETON
    0x666,
    // POKEMON_PORENTA
    0x966,
    // POKEMON_DODU
    0x666,
    // POKEMON_DODRI
    0x388,
    // POKEMON_JURBO
    0xd66,
    // POKEMON_JUGONG
    0x577,
    // POKEMON_SLEIMA
    0xd75,
    // POKEMON_SLEIMOK
    0x885,
    // POKEMON_MUSCHAS
    0x1676,
    // POKEMON_AUSTOS
    0x787,
    // POKEMON_NEBULAK
    0x685,
    // POKEMON_ALPOLLO
    0x476,
    // POKEMON_GENGAR
    0x886,
    // POKEMON_ONIX
    0x78,
    // POKEMON_TRAUMATO
    0x965,
    // POKEMON_HYPNO
    0x566,
    // POKEMON_KRABBY
    0xf66,
    // POKEMON_KINGLER
    0x577,
    // POKEMON_VOLTOBAL
    0xa55,
    // POKEMON_LEKTROBAL
    0x765,
    // POKEMON_OWEI
    0x1265,
    // POKEMON_KOKOWEI
    0x887,
    // POKEMON_TRAGOSSO
    0xa76,
    // POKEMON_KNOGGA
    0x866,
    // POKEMON_KICKLEE
    0x465,
    // POKEMON_NOCKCHAN
    0x665,
    // POKEMON_SCHLURP
    0xd85,
    // POKEMON_SMOGON
    0x366,
    // POKEMON_SMOGMOG
    0x985,
    // POKEMON_RIHORN
    0xb85,
    // POKEMON_RIZEROS
    0x588,
    // POKEMON_CHANEIRA
    0xb85,
    // POKEMON_ZOBIRIS
    0xd85,
    // POKEMON_KANGAMA
    0x677,
    // POKEMON_SEEPER
    0xe66,
    // POKEMON_SEEMON
    0x666,
    // POKEMON_QUABBEL
    0x66,
    // POKEMON_APOQUALLYP
    0x76,
    // POKEMON_STERNDU
    0x675,
    // POKEMON_STARMIE
    0x485,
    // POKEMON_TRAUNFUGIL
    0x985,
    // POKEMON_SICHLOR
    0x387,
    // POKEMON_GALAGLADI
    0x85,
    // POKEMON_ELEKTEK
    0x466,
    // POKEMON_MAGMAR
    0x277,
    // POKEMON_PINSIR
    0x666,
    // POKEMON_TAUROS
    0xd85,
    // POKEMON_KARPADOR
    0x676,
    // POKEMON_GARADOS
    0x588,
    // POKEMON_LAPRAS
    0x377,
    // POKEMON_DITTO
    0x1254,
    // POKEMON_EVOLI
    0xa66,
    // POKEMON_AQUANA
    0x566,
    // POKEMON_BLITZA
    0x687,
    // POKEMON_FLAMARA
    0x867,
    // POKEMON_PORYGON
    0xd65,
    // POKEMON_AMONITAS
    0xc66,
    // POKEMON_AMOROSO
    0x766,
    // POKEMON_KABUTO
    0x1165,
    // POKEMON_KABUTOPS
    0x677,
    // POKEMON_AERODACTYL
    0xa86,
    // POKEMON_RELAXO
    0xd86,
    // POKEMON_ARKTOS
    0x565,
    // POKEMON_ZAPDOS
    0xc76,
    // POKEMON_LAVADOS
    0x587,
    // POKEMON_DRATINI
    0x866,
    // POKEMON_DRAGONIR
    0x478,
    // POKEMON_DRAGORAN
    0x187,
    // POKEMON_MEWTU
    0x178,
    // POKEMON_MEW
    0x688,
    // POKEMON_ENDIVIE
    0xa56,
    // POKEMON_LORBLATT
    0x566,
    // POKEMON_MEGANIE
    0x278,
    // POKEMON_FEURIGEL
    0x976,
    // POKEMON_IGELAVAR
    0x87,
    // POKEMON_TORNUPTO
    0x387,
    // POKEMON_KARNIMANI
    0xa66,
    // POKEMON_TYRACROC
    0x267,
    // POKEMON_IMPERGATOR
    0x288,
    // POKEMON_IGNIVOR
    0xc67,
    // POKEMON_RAMOTH
    0x266,
    // POKEMON_GLAZIOLA
    0x666,
    // POKEMON_RESLADERO
    0xf68,
    // POKEMON_LEDYBA
    0x876,
    // POKEMON_LEDIAN
    0x377,
    // POKEMON_WEBARAK
    0x1273,
    // POKEMON_ARIADOS
    0x986,
    // POKEMON_IKSBAT
    0x187,
    // POKEMON_LAMPI
    0xb86,
    // POKEMON_LANTURN
    0x686,
    // POKEMON_MAGNEZONE
    0xc66,
    // POKEMON_TOGEKISS
    0x65,
    // POKEMON_FLABEBE
    0xc66,
    // POKEMON_TOGEPI
    0xd54,
    // POKEMON_TOGETIC
    0x666,
    // POKEMON_NATU
    0xf54,
    // POKEMON_XATU
    0x676,
    // POKEMON_VOLTILAMM
    0x666,
    // POKEMON_WAATY
    0x766,
    // POKEMON_AMPHAROS
    0x388,
    // POKEMON_BLUBELLA
    0xc66,
    // POKEMON_MARILL
    0xd75,
    // POKEMON_AZUMARILL
    0x86,
    // POKEMON_MOGELBAUM
    0x566,
    // POKEMON_CLAVION
    0x66,
    // POKEMON_LICHTEL
    0xe66,
    // POKEMON_LATERNECTO
    0xc65,
    // POKEMON_SKLELABRA
    0x87,
    // POKEMON_GRIFFEL
    0x366,
    // POKEMON_SHNEBEDECK
    0x56,
    // POKEMON_REXBLISAR
    0x66,
    // POKEMON_AMBIDIFFEL
    0x77,
    // POKEMON_FELINO
    0xf85,
    // POKEMON_MORLORD
    0x576,
    // POKEMON_PSIANA
    0x676,
    // POKEMON_NACHTARA
    0x287,
    // POKEMON_KRAMURX
    0xa66,
    // POKEMON_LASCHOKING
    0x366,
    // POKEMON_KRAMSHEF
    0x266,
    // POKEMON_ICOGNITO
    0x836,
    // POKEMON_FROSDEDJE
    0x75,
    // POKEMON_SKORGRO
    0x87,
    // POKEMON_TANNZA
    0xd65,
    // POKEMON_FORSTELLKA
    0x1084,
    // POKEMON_ELEVOLTEK
    0x85,
    // POKEMON_SKORGLA
    0x287,
    // POKEMON_STAHLOS
    0x88,
    // POKEMON_SNUBBULL
    0xc76,
    // POKEMON_GRANBULL
    0x887,
    // POKEMON_MAMUTEL
    0x677,
    // POKEMON_SCHEROX
    0x477,
    // POKEMON_FLUFFELUFF
    0,
    // POKEMON_SKARABORN
    0x277,
    // POKEMON_KRYPPUK
    0xa66,
    // POKEMON_TEDDIURSA
    0xa66,
    // POKEMON_URSARING
    0x288,
    // POKEMON_SCHNECKMAG
    0x666,
    // POKEMON_MAGCARGO
    0x876,
    // POKEMON_QUIEKEL
    0xf63,
    // POKEMON_KEIFEL
    0x875,
    // POKEMON_CORASONN
    0xc65,
    // POKEMON_REMORAID
    0xc75,
    // POKEMON_OCTILLERY
    0xa66,
    // POKEMON_BOTOGEL
    0x667,
    // POKEMON_SCHLURPLEK
    0xd85,
    // POKEMON_PANZAERON
    0x187,
    // POKEMON_HUNDUSTER
    0xa55,
    // POKEMON_HUNDEMON
    0x687,
    // POKEMON_SEEDRAKING
    0x787,
    // POKEMON_PHANPY
    0xc65,
    // POKEMON_DONPHAN
    0x985,
    // POKEMON_PORYGON2
    0xb76,
    // POKEMON_VOLUMINAS
    0x478,
    // POKEMON_TRAUNMAGIL
    0x76,
    // POKEMON_RABAUZ
    0xa66,
    // POKEMON_KAPOERA
    0x687,
    // POKEMON_KUSSILLA
    0x956,
    // POKEMON_ELEKID
    0xa66,
    // POKEMON_MAGBY
    0xa66,
    // POKEMON_MILTANK
    0x687,
    // POKEMON_HEITEIRA
    0x1085,
    // POKEMON_RAIKOU
    0x686,
    // POKEMON_ENTEI
    0xb87,
    // POKEMON_SUICUNE
    0x388,
    // POKEMON_LARVITAR
    0x666,
    // POKEMON_PUPITAR
    0x867,
    // POKEMON_DESPOTAR
    0x188,
    // POKEMON_LUGIA
    0x88,
    // POKEMON_HO_OH
    0x188,
    // POKEMON_CELEBI
    0x766,
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
    0x88,
    // POKEMON_MEGA_SANDAMER
    0x188,
    // POKEMON_MEGA_LAHMUS
    0,
    // POKEMON_MEGA_MASKEREGEN
    0,
    // POKEMON_AMPHARAOSM
    0x188,
    // POKEMON_GENGARM
    0x588,
    // POKEMON_BIBORM
    0x88,
    // POKEMON_ALTARIAM
    0x88,
    // POKEMON_GEOWAZM
    0x88,
    // POKEMON_SENGOM
    0x88,
    // POKEMON_VIPITISM
    0x88,
    // POKEMON_ZOBIRISM
    0x88,
    // POKEMON_tropius_mega
    0x87,
    // POKEMON_10e
    0x188,
    // POKEMON_10f
    0x188,
    // POKEMON_110
    0x188,
    // POKEMON_111
    0x188,
    // POKEMON_112
    0x188,
    // POKEMON_113
    0x188,
    // POKEMON_114
    0x188,
    // POKEMON_LOCKSCHAL
    0x87,
    // POKEMON_STICHSCHAL
    0x86,
    // POKEMON_STAHLSTICH
    0x988,
    // POKEMON_WELUNO
    0x67,
    // POKEMON_ORTHODOS
    0x88,
    // POKEMON_ZERBERTRES
    0x88,
    // POKEMON_SEEKID
    0x77,
    // POKEMON_SEESKULL
    0x87,
    // POKEMON_SKULLYDRA
    0x87,
    // POKEMON_FIFFYEN
    0x76,
    // POKEMON_MAGNAYEN
    0x487,
    // POKEMON_ZIGZACHS
    0xb76,
    // POKEMON_GERADAKS
    0x685,
    // POKEMON_WAUMPEL
    0x676,
    // POKEMON_SCHALOKO
    0xd83,
    // POKEMON_PAPINELLA
    0x88,
    // POKEMON_PANEKON
    0x673,
    // POKEMON_PUDOX
    0x83,
    // POKEMON_LOTURZEL
    0xc75,
    // POKEMON_LOMBRERO
    0x686,
    // POKEMON_KAPPALORES
    0x686,
    // POKEMON_SAMURZEL
    0x686,
    // POKEMON_BLANAS
    0x676,
    // POKEMON_TENGULIST
    0x986,
    // POKEMON_NINCADA
    0x1483,
    // POKEMON_NINJASK
    0xd86,
    // POKEMON_NINJATOM
    0x677,
    // POKEMON_SCHWALBINI
    0x1064,
    // POKEMON_SCHWALBOSS
    0x686,
    // POKEMON_KNILZ
    0x85,
    // POKEMON_KAPILZ
    0x387,
    // POKEMON_PANDIR
    0x677,
    // POKEMON_WINGULL
    0xd85,
    // POKEMON_PELIPPER
    0x687,
    // POKEMON_GEHWEIHER
    0x986,
    // POKEMON_MASKEREGEN
    0x88,
    // POKEMON_WAILMER
    0x883,
    // POKEMON_WAILORD
    0xe83,
    // POKEMON_ENECO
    0x686,
    // POKEMON_ENEKORO
    0x86,
    // POKEMON_KECLEON
    0x687,
    // POKEMON_PUPPANCE
    0x886,
    // POKEMON_LEPUMENTAS
    0x787,
    // POKEMON_NASGNET
    0xa85,
    // POKEMON_MAGBRANT
    0x86,
    // POKEMON_ZWIRRFINST
    0x76,
    // POKEMON_SCHMERBE
    0x966,
    // POKEMON_WELSAR
    0xb86,
    // POKEMON_LIEBISKUS
    0,
    // POKEMON_KREBSCORPS
    0x877,
    // POKEMON_KREBUTACK
    0x787,
    // POKEMON_BARSCHWA
    0x667,
    // POKEMON_MILOTIC
    0x268,
    // POKEMON_KANIVANHA
    0xa87,
    // POKEMON_TOHAIDO
    0x388,
    // POKEMON_KNACKLION
    0xa75,
    // POKEMON_VIBRAVA
    0xc74,
    // POKEMON_LIBELLDRA
    0x388,
    // POKEMON_RIOLU
    0xd76,
    // POKEMON_LUCARIO
    0xe87,
    // POKEMON_FRIZELBLIZ
    0xd84,
    // POKEMON_VOLTENSO
    0x87,
    // POKEMON_CAMAUB
    0x686,
    // POKEMON_CAMERUPT
    0xd84,
    // POKEMON_SEEMOPS
    0xc64,
    // POKEMON_SEEJONG
    0xb86,
    // POKEMON_WALRAISA
    0x87,
    // POKEMON_TUSKA
    0xc85,
    // POKEMON_NOKTUSKA
    0x87,
    // POKEMON_SCHNEPPKE
    0xa76,
    // POKEMON_FIRNONTOR
    0xa85,
    // POKEMON_LUNASTEIN
    0x887,
    // POKEMON_SONNFEL
    0x287,
    // POKEMON_AZURILL
    0x686,
    // POKEMON_SPOINK
    0x456,
    // POKEMON_GROINK
    0x287,
    // POKEMON_PLUSLE
    0,
    // POKEMON_MINUN
    0,
    // POKEMON_FLUNKIFER
    0x687,
    // POKEMON_MEDITIE
    0x976,
    // POKEMON_MEDITALIS
    0x68,
    // POKEMON_WABLU
    0xf86,
    // POKEMON_ALTARIA
    0xa87,
    // POKEMON_ISSO
    0xb77,
    // POKEMON_ZWIRRLICHT
    0x766,
    // POKEMON_ZWIRRKLOP
    0x286,
    // POKEMON_PORYGON_Z
    0x886,
    // POKEMON_BUMMELZ
    0xd85,
    // POKEMON_MUNTIER
    0x86,
    // POKEMON_LETARKING
    0x686,
    // POKEMON_SCHLUPPUCK
    0,
    // POKEMON_SCHLUKWECH
    0,
    // POKEMON_TROPIUS
    0x87,
    // POKEMON_KAUMALAT
    0x1385,
    // POKEMON_KNARKSEL
    0x86,
    // POKEMON_KNAKRACK
    0x88,
    // POKEMON_PERLU
    0xc85,
    // POKEMON_AALABYSS
    0x468,
    // POKEMON_SAGANABYSS
    0x977,
    // POKEMON_ABSOL
    0x378,
    // POKEMON_SHUPPET
    0x677,
    // POKEMON_BANETTE
    0x565,
    // POKEMON_VIPITIS
    0x88,
    // POKEMON_SENGO
    0x688,
    // POKEMON_RELICANTH
    0xc86,
    // POKEMON_STOLLUNIOR
    0x854,
    // POKEMON_STOLLRAK
    0xf84,
    // POKEMON_STOLLOSS
    0x587,
    // POKEMON_FORMEO
    0x645,
    // POKEMON_VOLBEAT
    0x376,
    // POKEMON_ILLUMISE
    0x867,
    // POKEMON_LILIEP
    0x886,
    // POKEMON_WIELIE
    0x77,
    // POKEMON_ANORITH
    0x1383,
    // POKEMON_ARMALDO
    0x77,
    // POKEMON_TRASLA
    0xd45,
    // POKEMON_KIRLIA
    0x657,
    // POKEMON_GUARDEVOIR
    0x677,
    // POKEMON_KINDWURM
    0x666,
    // POKEMON_DRASCHEL
    0xc85,
    // POKEMON_BRUTALANDA
    0x477,
    // POKEMON_TANHEL
    0xa66,
    // POKEMON_METANG
    0xd84,
    // POKEMON_METAGROSS
    0x683,
    // POKEMON_REGIROCK
    0xa86,
    // POKEMON_REGICE
    0xb85,
    // POKEMON_REGISTEEL
    0xb85,
    // POKEMON_KYOGRE
    0x1284,
    // POKEMON_GROUDON
    0x887,
    // POKEMON_RAYQUAZA
    0x78,
    // POKEMON_LATIAS
    0x88,
    // POKEMON_LATIOS
    0x88,
    // POKEMON_JIRACHI
    0x687,
    // POKEMON_DEOXYS
    0x787,
    // POKEMON_PALIMPALIM
    0x947,
    // POKEMON_EGG
    0xa36,
    // POKEMON_ICOGNITO_B
    0x956,
    // POKEMON_ICOGNITO_C
    0x667,
    // POKEMON_ICOGNITO_D
    0x856,
    // POKEMON_ICOGNITO_E
    0xa56,
    // POKEMON_ICOGNITO_F
    0xa66,
    // POKEMON_ICOGNITO_G
    0x557,
    // POKEMON_ICOGNITO_H
    0x866,
    // POKEMON_ICOGNITO_I
    0x737,
    // POKEMON_ICOGNITO_J
    0x946,
    // POKEMON_ICOGNITO_K
    0x757,
    // POKEMON_ICOGNITO_L
    0xa46,
    // POKEMON_ICOGNITO_M
    0xd65,
    // POKEMON_ICOGNITO_N
    0xd65,
    // POKEMON_ICOGNITO_O
    0x866,
    // POKEMON_ICOGNITO_P
    0xa46,
    // POKEMON_ICOGNITO_Q
    0xf55,
    // POKEMON_ICOGNITO_R
    0xc45,
    // POKEMON_ICOGNITO_S
    0x457,
    // POKEMON_ICOGNITO_T
    0xd45,
    // POKEMON_ICOGNITO_U
    0xd65,
    // POKEMON_ICOGNITO_V
    0xb56,
    // POKEMON_ICOGNITO_W
    0xd55,
    // POKEMON_ICOGNITO_X
    0xf55,
    // POKEMON_ICOGNITO_Y
    0xa46,
    // POKEMON_ICOGNITO_Z
    0xa46,
    // POKEMON_ICOGNITO_EXCLAMATION
    0x637,
    // POKEMON_ICOGNITO_QUESTION
    0x647,
    // POKEMON_GROUDON
    0x887,
    // POKEMON_KECLEON_PURPLE
    0x687
};

u32 pokemon_enemy_y[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    0x88,
    // POKEMON_BISASAM
    0x1055,
    // POKEMON_BISAKNOSP
    0xa66,
    // POKEMON_BISAFLOR
    0x487,
    // POKEMON_GLUMANDA
    0xd55,
    // POKEMON_GLUTEXO
    0x976,
    // POKEMON_GLURAK
    0x188,
    // POKEMON_SCHIGGY
    0xc65,
    // POKEMON_SCHILLOK
    0x976,
    // POKEMON_TURTOK
    0x587,
    // POKEMON_DARTIRI
    0x754,
    // POKEMON_DARTIGNIS
    0x54,
    // POKEMON_FIARO
    0x76,
    // POKEMON_HORNLIU
    0xc54,
    // POKEMON_KOKUNA
    0xa45,
    // POKEMON_BIBOR
    0x86,
    // POKEMON_STARALILI
    0x555,
    // POKEMON_STARAVIA
    0x567,
    // POKEMON_STARAPTOR
    0x88,
    // POKEMON_BRONZEL
    0x965,
    // POKEMON_BRONZONG
    0x76,
    // POKEMON_MAEHIKEL
    0x455,
    // POKEMON_CHEVRUMM
    0x88,
    // POKEMON_PARAGONI
    0x65,
    // POKEMON_TROMBORK
    0x78,
    // POKEMON_PIKACHU
    0x967,
    // POKEMON_RAICHU
    0x88,
    // POKEMON_SANDAN
    0xb56,
    // POKEMON_SANDAMER
    0x777,
    // POKEMON_NIDORANW
    0xe54,
    // POKEMON_NIDORINA
    0xb66,
    // POKEMON_NIDOQUEEN
    0x278,
    // POKEMON_NIDORANM
    0xc55,
    // POKEMON_NIDORINO
    0x866,
    // POKEMON_NIDOKING
    0x288,
    // POKEMON_FLOETTE
    0x55,
    // POKEMON_FLORGES
    0x67,
    // POKEMON_VULPIX
    0xc65,
    // POKEMON_VULNONA
    0x288,
    // POKEMON_PUMMELUFF
    0xd55,
    // POKEMON_KNUDDELUFF
    0x367,
    // POKEMON_ZUBAT
    0x66,
    // POKEMON_GOLBAT
    0x88,
    // POKEMON_MYRAPLA
    0xb45,
    // POKEMON_DUFLOR
    0x866,
    // POKEMON_GIFLOR
    0x376,
    // POKEMON_FOLIPURBA
    0x464,
    // POKEMON_FEELINARA
    0x386,
    // POKEMON_WATTZAPF
    0x1057,
    // POKEMON_VOLTULA
    0xc87,
    // POKEMON_DIGDA
    0x1154,
    // POKEMON_DIGDRI
    0xc75,
    // POKEMON_KASTADUR
    0x955,
    // POKEMON_TENTANTEL
    0x376,
    // POKEMON_ENTON
    0x956,
    // POKEMON_ENTORON
    0x677,
    // POKEMON_MENKI
    0x966,
    // POKEMON_RASAFF
    0x677,
    // POKEMON_FUKANO
    0xc65,
    // POKEMON_ARKANI
    0x288,
    // POKEMON_GRAMOKLES
    0x74,
    // POKEMON_DUOKLES
    0x76,
    // POKEMON_DURENGARD
    0x77,
    // POKEMON_ABRA
    0xb66,
    // POKEMON_KADABRA
    0x387,
    // POKEMON_SIMSALA
    0x288,
    // POKEMON_MACHOLLO
    0x946,
    // POKEMON_MASCHOCK
    0x377,
    // POKEMON_MACHOMEI
    0x88,
    // POKEMON_KNOFENSA
    0x866,
    // POKEMON_ULTRIGARIA
    0x366,
    // POKEMON_SARZENIA
    0x377,
    // POKEMON_TENTACHA
    0x766,
    // POKEMON_TENTOXA
    0x78,
    // POKEMON_KLEINSTEIN
    0x1274,
    // POKEMON_GEOROK
    0x686,
    // POKEMON_GEOWAZ
    0x687,
    // POKEMON_PONITA
    0x367,
    // POKEMON_GALLOPA
    0x88,
    // POKEMON_FLEGMON
    0xf65,
    // POKEMON_LAHMUS
    0x388,
    // POKEMON_MAGNETILO
    0x1353,
    // POKEMON_MAGNETON
    0x75,
    // POKEMON_PORENTA
    0x776,
    // POKEMON_DODU
    0x567,
    // POKEMON_DODRI
    0x88,
    // POKEMON_JURBO
    0x676,
    // POKEMON_JUGONG
    0x287,
    // POKEMON_SLEIMA
    0x966,
    // POKEMON_SLEIMOK
    0x386,
    // POKEMON_MUSCHAS
    0xf55,
    // POKEMON_AUSTOS
    0x287,
    // POKEMON_NEBULAK
    0x477,
    // POKEMON_ALPOLLO
    0x187,
    // POKEMON_GENGAR
    0x876,
    // POKEMON_ONIX
    0x78,
    // POKEMON_TRAUMATO
    0x866,
    // POKEMON_HYPNO
    0x187,
    // POKEMON_KRABBY
    0xc75,
    // POKEMON_KINGLER
    0x587,
    // POKEMON_VOLTOBAL
    0xb44,
    // POKEMON_LEKTROBAL
    0x955,
    // POKEMON_OWEI
    0xb76,
    // POKEMON_KOKOWEI
    0x88,
    // POKEMON_TRAGOSSO
    0xc65,
    // POKEMON_KNOGGA
    0x887,
    // POKEMON_KICKLEE
    0x277,
    // POKEMON_NOCKCHAN
    0x167,
    // POKEMON_SCHLURP
    0x686,
    // POKEMON_SMOGON
    0x66,
    // POKEMON_SMOGMOG
    0x88,
    // POKEMON_RIHORN
    0x976,
    // POKEMON_RIZEROS
    0x488,
    // POKEMON_CHANEIRA
    0x876,
    // POKEMON_ZOBIRIS
    0x566,
    // POKEMON_KANGAMA
    0x88,
    // POKEMON_SEEPER
    0xb45,
    // POKEMON_SEEMON
    0x377,
    // POKEMON_QUABBEL
    0x66,
    // POKEMON_APOQUALLYP
    0x77,
    // POKEMON_STERNDU
    0xa66,
    // POKEMON_STARMIE
    0x767,
    // POKEMON_TRAUNFUGIL
    0x76,
    // POKEMON_SICHLOR
    0x378,
    // POKEMON_GALAGLADI
    0x66,
    // POKEMON_ELEKTEK
    0x288,
    // POKEMON_MAGMAR
    0x287,
    // POKEMON_PINSIR
    0x377,
    // POKEMON_TAUROS
    0x588,
    // POKEMON_KARPADOR
    0x577,
    // POKEMON_GARADOS
    0x88,
    // POKEMON_LAPRAS
    0x287,
    // POKEMON_DITTO
    0xf54,
    // POKEMON_EVOLI
    0xb56,
    // POKEMON_AQUANA
    0x567,
    // POKEMON_BLITZA
    0x866,
    // POKEMON_FLAMARA
    0xb76,
    // POKEMON_PORYGON
    0x656,
    // POKEMON_AMONITAS
    0xc45,
    // POKEMON_AMOROSO
    0x767,
    // POKEMON_KABUTO
    0x1154,
    // POKEMON_KABUTOPS
    0x188,
    // POKEMON_AERODACTYL
    0x88,
    // POKEMON_RELAXO
    0x287,
    // POKEMON_ARKTOS
    0x88,
    // POKEMON_ZAPDOS
    0x88,
    // POKEMON_LAVADOS
    0x88,
    // POKEMON_DRATINI
    0x975,
    // POKEMON_DRAGONIR
    0x287,
    // POKEMON_DRAGORAN
    0x88,
    // POKEMON_MEWTU
    0x88,
    // POKEMON_MEW
    0x77,
    // POKEMON_ENDIVIE
    0xb75,
    // POKEMON_LORBLATT
    0x177,
    // POKEMON_MEGANIE
    0x88,
    // POKEMON_FEURIGEL
    0xe55,
    // POKEMON_IGELAVAR
    0x776,
    // POKEMON_TORNUPTO
    0x78,
    // POKEMON_KARNIMANI
    0xe55,
    // POKEMON_TYRACROC
    0x667,
    // POKEMON_IMPERGATOR
    0x88,
    // POKEMON_IGNIVOR
    0x947,
    // POKEMON_RAMOTH
    0x67,
    // POKEMON_GLAZIOLA
    0xa55,
    // POKEMON_RESLADERO
    0x358,
    // POKEMON_LEDYBA
    0xa56,
    // POKEMON_LEDIAN
    0x67,
    // POKEMON_WEBARAK
    0x1354,
    // POKEMON_ARIADOS
    0x587,
    // POKEMON_IKSBAT
    0x88,
    // POKEMON_LAMPI
    0x975,
    // POKEMON_LANTURN
    0x887,
    // POKEMON_MAGNEZONE
    0x45,
    // POKEMON_TOGEKISS
    0x44,
    // POKEMON_FLABEBE
    0x44,
    // POKEMON_TOGEPI
    0x1034,
    // POKEMON_TOGETIC
    0x546,
    // POKEMON_NATU
    0xd44,
    // POKEMON_XATU
    0x347,
    // POKEMON_VOLTILAMM
    0xc55,
    // POKEMON_WAATY
    0x856,
    // POKEMON_AMPHAROS
    0x277,
    // POKEMON_BLUBELLA
    0xc45,
    // POKEMON_MARILL
    0xc65,
    // POKEMON_AZUMARILL
    0x376,
    // POKEMON_MOGELBAUM
    0x567,
    // POKEMON_CLAVION
    0x67,
    // POKEMON_LICHTEL
    0x566,
    // POKEMON_LATERNECTO
    0x55,
    // POKEMON_SKLELABRA
    0x77,
    // POKEMON_GRIFFEL
    0x58,
    // POKEMON_SHNEBEDECK
    0x244,
    // POKEMON_REXBLISAR
    0x156,
    // POKEMON_AMBIDIFFEL
    0x86,
    // POKEMON_FELINO
    0x1054,
    // POKEMON_MORLORD
    0x577,
    // POKEMON_PSIANA
    0x666,
    // POKEMON_NACHTARA
    0x767,
    // POKEMON_KRAMURX
    0x66,
    // POKEMON_LASCHOKING
    0x158,
    // POKEMON_KRAMSHEF
    0x55,
    // POKEMON_ICOGNITO
    0xf35,
    // POKEMON_FROSDEDJE
    0x77,
    // POKEMON_SKORGRO
    0x388,
    // POKEMON_TANNZA
    0x956,
    // POKEMON_FORSTELLKA
    0x776,
    // POKEMON_ELEVOLTEK
    0x74,
    // POKEMON_SKORGLA
    0x78,
    // POKEMON_STAHLOS
    0x88,
    // POKEMON_SNUBBULL
    0xb55,
    // POKEMON_GRANBULL
    0x557,
    // POKEMON_MAMUTEL
    0x356,
    // POKEMON_SCHEROX
    0x88,
    // POKEMON_POTTROTT
    0x966,
    // POKEMON_SKARABORN
    0x288,
    // POKEMON_KRYPPUK
    0x267,
    // POKEMON_TEDDIURSA
    0xb46,
    // POKEMON_URSARING
    0x78,
    // POKEMON_SCHNECKMAG
    0xb45,
    // POKEMON_MAGCARGO
    0x757,
    // POKEMON_QUIEKEL
    0x1243,
    // POKEMON_KEIFEL
    0x666,
    // POKEMON_CORASONN
    0xc65,
    // POKEMON_REMORAID
    0x955,
    // POKEMON_OCTILLERY
    0xa66,
    // POKEMON_BOTOGEL
    0x856,
    // POKEMON_SCHLURPLEK
    0x686,
    // POKEMON_PANZAERON
    0x88,
    // POKEMON_HUNDUSTER
    0xb56,
    // POKEMON_HUNDEMON
    0x77,
    // POKEMON_SEEDRAKING
    0x78,
    // POKEMON_PHANPY
    0xf54,
    // POKEMON_DONPHAN
    0x986,
    // POKEMON_PORYGON2
    0x55,
    // POKEMON_VOLUMINAS
    0x88,
    // POKEMON_TRAUNMAGIL
    0x477,
    // POKEMON_RABAUZ
    0x846,
    // POKEMON_KAPOERA
    0x367,
    // POKEMON_SEN_LONG
    0,
    // POKEMON_ELEKID
    0xa76,
    // POKEMON_MAGBY
    0xb45,
    // POKEMON_MILTANK
    0x777,
    // POKEMON_HEITEIRA
    0x377,
    // POKEMON_RAIKOU
    0x288,
    // POKEMON_ENTEI
    0x188,
    // POKEMON_SUICUNE
    0x88,
    // POKEMON_LARVITAR
    0x946,
    // POKEMON_PUPITAR
    0x756,
    // POKEMON_DESPOTAR
    0x88,
    // POKEMON_LUGIA
    0x88,
    // POKEMON_HO_OH
    0x88,
    // POKEMON_CELEBI
    0xb55,
    // POKEMON_BISAFLORM
    0x88,
    // POKEMON_GLURAKM
    0x88,
    // POKEMON_AQUANAM
    0x688,
    // POKEMON_BLITZAM
    0x688,
    // POKEMON_FLAMARM
    0x388,
    // POKEMON_DURENGARDA
    0x88,
    // POKEMON_IN
    0x88,
    // POKEMON_GAME
    0x88,
    // POKEMON_TURTOKM
    0x88,
    // POKEMON_AMPHARAOSM
    0x88,
    // POKEMON_GENGARM
    0x88,
    // POKEMON_BIBORM
    0x88,
    // POKEMON_ALTARIAM
    0x88,
    // POKEMON_GEOWAZM
    0x88,
    // POKEMON_SENGOM
    0x88,
    // POKEMON_VIPITISM
    0x88,
    // POKEMON_ZOBIRISM
    0x288,
    // POKEMON_tropius_mega
    0x688,
    // POKEMON_10e
    0x688,
    // POKEMON_10f
    0x688,
    // POKEMON_110
    0x688,
    // POKEMON_111
    0x688,
    // POKEMON_112
    0x688,
    // POKEMON_113
    0x688,
    // POKEMON_114
    0x688,
    // POKEMON_LOCKSCHAL
    0x866,
    // POKEMON_STICHSCHAL
    0x787,
    // POKEMON_STAHLSTICH
    0x88,
    // POKEMON_WELUNO
    0x856,
    // POKEMON_ORTHODOS
    0x288,
    // POKEMON_ZERBERTRES
    0x88,
    // POKEMON_SEEKID
    0xb56,
    // POKEMON_SEESKULL
    0x367,
    // POKEMON_SKULLYDRA
    0x88,
    // POKEMON_FIFFYEN
    0xa55,
    // POKEMON_MAGNAYEN
    0x487,
    // POKEMON_ZIGZACHS
    0xf85,
    // POKEMON_GERADAKS
    0xc78,
    // POKEMON_WAUMPEL
    0xa45,
    // POKEMON_SCHALOKO
    0xf75,
    // POKEMON_PAPINELLA
    0x986,
    // POKEMON_PANEKON
    0xe74,
    // POKEMON_PUDOX
    0x86,
    // POKEMON_LOTURZEL
    0xd65,
    // POKEMON_LOMBRERO
    0xa66,
    // POKEMON_KAPPALORES
    0x88,
    // POKEMON_SAMURZEL
    0xa46,
    // POKEMON_BLANAS
    0x656,
    // POKEMON_TENGULIST
    0x288,
    // POKEMON_NINCADA
    0x1274,
    // POKEMON_NINJASK
    0x386,
    // POKEMON_NINJATOM
    0x66,
    // POKEMON_SCHWALBINI
    0xb64,
    // POKEMON_SCHWALBOSS
    0x387,
    // POKEMON_KNILZ
    0xe54,
    // POKEMON_KAPILZ
    0x477,
    // POKEMON_PANDIR
    0x67,
    // POKEMON_WINGULL
    0x84,
    // POKEMON_PELIPPER
    0x77,
    // POKEMON_GEHWEIHER
    0xa65,
    // POKEMON_MASKEREGEN
    0x88,
    // POKEMON_WAILMER
    0xc75,
    // POKEMON_WAILORD
    0x387,
    // POKEMON_ENECO
    0xa66,
    // POKEMON_ENEKORO
    0x566,
    // POKEMON_KECLEON
    0x367,
    // POKEMON_PUPPANCE
    0x55,
    // POKEMON_LEPUMENTAS
    0x78,
    // POKEMON_NASGNET
    0x756,
    // POKEMON_MAGBRANT
    0x88,
    // POKEMON_ZWIRRFINST
    0x66,
    // POKEMON_SCHMERBE
    0x546,
    // POKEMON_WELSAR
    0x976,
    // POKEMON_LIEBISKUS
    0xe46,
    // POKEMON_KREBSCORPS
    0xa66,
    // POKEMON_KREBUTACK
    0x388,
    // POKEMON_BARSCHWA
    0x746,
    // POKEMON_MILOTIC
    0x88,
    // POKEMON_KANIVANHA
    0x667,
    // POKEMON_TOHAIDO
    0x278,
    // POKEMON_KNACKLION
    0xc54,
    // POKEMON_VIBRAVA
    0xb86,
    // POKEMON_LIBELLDRA
    0x88,
    // POKEMON_RIOLU
    0x565,
    // POKEMON_LUCARIO
    0x88,
    // POKEMON_FRIZELBLIZ
    0xe64,
    // POKEMON_VOLTENSO
    0x267,
    // POKEMON_CAMAUB
    0xa65,
    // POKEMON_CAMERUPT
    0x687,
    // POKEMON_SEEMOPS
    0xe65,
    // POKEMON_SEEJONG
    0xa86,
    // POKEMON_WALRAISA
    0x388,
    // POKEMON_TUSKA
    0xe74,
    // POKEMON_NOKTUSKA
    0x88,
    // POKEMON_SCHNEPPKE
    0xb56,
    // POKEMON_FIRNONTOR
    0x976,
    // POKEMON_LUNASTEIN
    0x866,
    // POKEMON_SONNFEL
    0x88,
    // POKEMON_AZURILL
    0xd55,
    // POKEMON_SPOINK
    0x646,
    // POKEMON_GROINK
    0x477,
    // POKEMON_PLUSLE
    0,
    // POKEMON_MINUN
    0,
    // POKEMON_FLUNKIFER
    0x876,
    // POKEMON_MEDITIE
    0x965,
    // POKEMON_MEDITALIS
    0x68,
    // POKEMON_WABLU
    0xb76,
    // POKEMON_ALTARIA
    0x288,
    // POKEMON_ISSO
    0xc55,
    // POKEMON_ZWIRRLICHT
    0x66,
    // POKEMON_ZWIRRKLOP
    0x577,
    // PORYGON_Z
    0x776,
    // POKEMON_BUMMELZ
    0xf74,
    // POKEMON_MUNTIER
    0x78,
    // POKEMON_LETARKING
    0x886,
    // POKEMON_SCHLUPPUCK
    0,
    // POKEMON_SCHLUKWECH
    0,
    // POKEMON_TROPIUS
    0x88,
    // POKEMON_KAUMALAT
    0xe55,
    // POKEMON_KNARKSEL
    0x378,
    // POKEMON_KNAKRACK
    0x188,
    // POKEMON_PERLU
    0xb55,
    // POKEMON_AALABYSS
    0x78,
    // POKEMON_SAGANABYSS
    0x86,
    // POKEMON_ABSOL
    0x68,
    // POKEMON_SHUPPET
    0x56,
    // POKEMON_BANETTE
    0x55,
    // POKEMON_VIPITIS
    0x677,
    // POKEMON_SENGO
    0x587,
    // POKEMON_RELICANTH
    0x877,
    // POKEMON_STOLLUNIOR
    0xf43,
    // POKEMON_STOLLRAK
    0xb75,
    // POKEMON_STOLLOSS
    0x188,
    // POKEMON_FORMEO
    0xf34,
    // POKEMON_WONNEIRA
    0,
    // POKEMON_MOBAI
    0,
    // POKEMON_LILIEP
    0x667,
    // POKEMON_WIELIE
    0x78,
    // POKEMON_ANORITH
    0x866,
    // POKEMON_ARMALDO
    0x88,
    // POKEMON_TRASLA
    0xa35,
    // POKEMON_KIRLIA
    0x547,
    // POKEMON_GUARDEVOIR
    0x78,
    // POKEMON_KINDWURM
    0xa56,
    // POKEMON_DRASCHEL
    0x966,
    // POKEMON_BRUTALANDA
    0x387,
    // POKEMON_TANHEL
    0x55,
    // POKEMON_METANG
    0x587,
    // POKEMON_METAGROSS
    0x987,
    // POKEMON_REGIROCK
    0x478,
    // POKEMON_REGICE
    0x288,
    // POKEMON_REGISTEEL
    0x388,
    // POKEMON_KYOGRE
    0x87,
    // POKEMON_GROUDON
    0x188,
    // POKEMON_RAYQUAZA
    0x88,
    // POKEMON_LATIAS
    0x88,
    // POKEMON_LATIOS
    0x88,
    // POKEMON_JIRACHI
    0xd66,
    // POKEMON_DEOXYS
    0x188,
    // POKEMON_PALIMPALIM
    0x337,
    // POKEMON_EGG
    0x1433,
    // POKEMON_ICOGNITO_B
    0x1034,
    // POKEMON_ICOGNITO_C
    0x1044,
    // POKEMON_ICOGNITO_D
    0x1044,
    // POKEMON_ICOGNITO_E
    0x1144,
    // POKEMON_ICOGNITO_F
    0x1144,
    // POKEMON_ICOGNITO_G
    0xe35,
    // POKEMON_ICOGNITO_H
    0x1044,
    // POKEMON_ICOGNITO_I
    0x1034,
    // POKEMON_ICOGNITO_J
    0x1134,
    // POKEMON_ICOGNITO_K
    0x1144,
    // POKEMON_ICOGNITO_L
    0x1334,
    // POKEMON_ICOGNITO_M
    0x1344,
    // POKEMON_ICOGNITO_N
    0x1443,
    // POKEMON_ICOGNITO_O
    0x1044,
    // POKEMON_ICOGNITO_P
    0x1334,
    // POKEMON_ICOGNITO_Q
    0x1543,
    // POKEMON_ICOGNITO_R
    0x1334,
    // POKEMON_ICOGNITO_S
    0xc45,
    // POKEMON_ICOGNITO_T
    0x1234,
    // POKEMON_ICOGNITO_U
    0x1244,
    // POKEMON_ICOGNITO_V
    0x1244,
    // POKEMON_ICOGNITO_W
    0x1344,
    // POKEMON_ICOGNITO_X
    0x1533,
    // POKEMON_ICOGNITO_Y
    0x1134,
    // POKEMON_ICOGNITO_Z
    0x1034,
    // POKEMON_ICOGNITO_EXCLAMATION
    0xf35,
    // POKEMON_ICOGNITO_QUESTION
    0xd35,
    // POKEMON_GROUDON
    0x188,
    // POKEMON_KECLEON
    0x367
};

u8 pokemon_altitude[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    0x0,
    // POKEMON_BISASAM
    0x0,
    // POKEMON_BISAKNOSP
    0x0,
    // POKEMON_BISAFLOR
    0x0,
    // POKEMON_GLUMANDA
    0x0,
    // POKEMON_GLUTEXO
    0x0,
    // POKEMON_GLURAK
    0x0,
    // POKEMON_SCHIGGY
    0x0,
    // POKEMON_SCHILLOK
    0x0,
    // POKEMON_TURTOK
    0x0,
    // POKEMON_DARTIRI
    0x0,
    // POKEMON_DARTIGNIS
    0xb,
    // POKEMON_FIARO
    0x8,
    // POKEMON_HORNLIU
    0x0,
    // POKEMON_KOKUNA
    0x0,
    // POKEMON_BIBOR
    0x8,
    // POKEMON_STARALILI
    0x0,
    // POKEMON_STARAVIA
    0x0,
    // POKEMON_STARAPTOR
    0x0,
    // POKEMON_BRONZEL
    0x6,
    // POKEMON_BRONZONG
    0xc,
    // POKEMON_MAEHIKEL
    0x0,
    // POKEMON_CHEVRUMM
    0x0,
    // POKEMON_PARAGONI
    0xe,
    // POKEMON_TROMBORK
    0x0,
    // POKEMON_PIKACHU
    0x0,
    // POKEMON_RAICHU
    0x0,
    // POKEMON_SANDAN
    0x0,
    // POKEMON_SANDAMER
    0x0,
    // POKEMON_NIDORANW
    0x0,
    // POKEMON_NIDORINA
    0x0,
    // POKEMON_NIDOQUEEN
    0x0,
    // POKEMON_NIDORANM
    0x0,
    // POKEMON_NIDORINO
    0x0,
    // POKEMON_NIDOKING
    0x0,
    // POKEMON_FLOETTE
    0x0,
    // POKEMON_FLORGES
    0x0,
    // POKEMON_VULPIX
    0x0,
    // POKEMON_VULNONA
    0x0,
    // POKEMON_PUMMELUFF
    0x0,
    // POKEMON_KNUDDELUFF
    0x0,
    // POKEMON_ZUBAT
    0x8,
    // POKEMON_GOLBAT
    0xc,
    // POKEMON_MYRAPLA
    0x0,
    // POKEMON_DUFLOR
    0x0,
    // POKEMON_GIFLOR
    0x0,
    // POKEMON_FOLIPURBA
    0x0,
    // POKEMON_FEELINARA
    0x0,
    // POKEMON_WATTZAPF
    0x0,
    // POKEMON_VOLTULA
    0x0,
    // POKEMON_DIGDA
    0x0,
    // POKEMON_DIGDRI
    0x0,
    // POKEMON_KASTADUR
    0x0,
    // POKEMON_TENTANTEL
    0x0,
    // POKEMON_ENTON
    0x0,
    // POKEMON_ENTORON
    0x0,
    // POKEMON_MENKI
    0x0,
    // POKEMON_RASAFF
    0x0,
    // POKEMON_FUKANO
    0x0,
    // POKEMON_ARKANI
    0x0,
    // POKEMON_GRAMOKLES
    0x3,
    // POKEMON_DUOKLES
    0x1,
    // POKEMON_DURENGARD
    0x0,
    // POKEMON_ABRA
    0x0,
    // POKEMON_KADABRA
    0x0,
    // POKEMON_SIMSALA
    0x0,
    // POKEMON_MACHOLLO
    0x0,
    // POKEMON_MASCHOCK
    0x0,
    // POKEMON_MACHOMEI
    0x0,
    // POKEMON_KNOFENSA
    0x0,
    // POKEMON_ULTRIGARIA
    0x1,
    // POKEMON_SARZENIA
    0x0,
    // POKEMON_TENTACHA
    0x0,
    // POKEMON_TENTOXA
    0x0,
    // POKEMON_KLEINSTEIN
    0x10,
    // POKEMON_GEOROK
    0x0,
    // POKEMON_GEOWAZ
    0x0,
    // POKEMON_PONITA
    0x0,
    // POKEMON_GALLOPA
    0x0,
    // POKEMON_FLEGMON
    0x0,
    // POKEMON_LAHMUS
    0x0,
    // POKEMON_MAGNETILO
    0x10,
    // POKEMON_MAGNETON
    0x8,
    // POKEMON_PORENTA
    0x0,
    // POKEMON_DODU
    0x0,
    // POKEMON_DODRI
    0x0,
    // POKEMON_JURBO
    0x0,
    // POKEMON_JUGONG
    0x0,
    // POKEMON_SLEIMA
    0x0,
    // POKEMON_SLEIMOK
    0x0,
    // POKEMON_MUSCHAS
    0x0,
    // POKEMON_AUSTOS
    0x0,
    // POKEMON_NEBULAK
    0x4,
    // POKEMON_ALPOLLO
    0x4,
    // POKEMON_GENGAR
    0x0,
    // POKEMON_ONIX
    0x0,
    // POKEMON_TRAUMATO
    0x0,
    // POKEMON_HYPNO
    0x0,
    // POKEMON_KRABBY
    0x0,
    // POKEMON_KINGLER
    0x0,
    // POKEMON_VOLTOBAL
    0xa,
    // POKEMON_LEKTROBAL
    0xc,
    // POKEMON_OWEI
    0x0,
    // POKEMON_KOKOWEI
    0x0,
    // POKEMON_TRAGOSSO
    0x0,
    // POKEMON_KNOGGA
    0x0,
    // POKEMON_KICKLEE
    0x0,
    // POKEMON_NOCKCHAN
    0x0,
    // POKEMON_SCHLURP
    0x0,
    // POKEMON_SMOGON
    0x8,
    // POKEMON_SMOGMOG
    0x8,
    // POKEMON_RIHORN
    0x0,
    // POKEMON_RIZEROS
    0x0,
    // POKEMON_CHANEIRA
    0x0,
    // POKEMON_ZOBIRIS
    0x0,
    // POKEMON_KANGAMA
    0x0,
    // POKEMON_SEEPER
    0x0,
    // POKEMON_SEEMON
    0x0,
    // POKEMON_QUABBEL
    0x0,
    // POKEMON_APOQUALLYP
    0x0,
    // POKEMON_STERNDU
    0x0,
    // POKEMON_STARMIE
    0x0,
    // POKEMON_TRAUNFUGIL
    0x6,
    // POKEMON_SICHLOR
    0x0,
    // POKEMON_GALAGLADI
    0x0,
    // POKEMON_ELEKTEK
    0x0,
    // POKEMON_MAGMAR
    0x0,
    // POKEMON_PINSIR
    0x0,
    // POKEMON_TAUROS
    0x0,
    // POKEMON_KARPADOR
    0x1,
    // POKEMON_GARADOS
    0x7,
    // POKEMON_LAPRAS
    0x0,
    // POKEMON_DITTO
    0x0,
    // POKEMON_EVOLI
    0x0,
    // POKEMON_AQUANA
    0x0,
    // POKEMON_BLITZA
    0x0,
    // POKEMON_FLAMARA
    0x0,
    // POKEMON_PORYGON
    0x1,
    // POKEMON_AMONITAS
    0x0,
    // POKEMON_AMOROSO
    0x0,
    // POKEMON_KABUTO
    0x0,
    // POKEMON_KABUTOPS
    0x0,
    // POKEMON_AERODACTYL
    0x7,
    // POKEMON_RELAXO
    0x0,
    // POKEMON_ARKTOS
    0x0,
    // POKEMON_ZAPDOS
    0xd,
    // POKEMON_LAVADOS
    0x0,
    // POKEMON_DRATINI
    0x0,
    // POKEMON_DRAGONIR
    0x0,
    // POKEMON_DRAGORAN
    0x9,
    // POKEMON_MEWTU
    0x0,
    // POKEMON_MEW
    0x8,
    // POKEMON_ENDIVIE
    0x0,
    // POKEMON_LORBLATT
    0x0,
    // POKEMON_MEGANIE
    0x0,
    // POKEMON_FEURIGEL
    0x0,
    // POKEMON_IGELAVAR
    0x0,
    // POKEMON_TORNUPTO
    0x0,
    // POKEMON_KARNIMANI
    0x0,
    // POKEMON_TYRACROC
    0x0,
    // POKEMON_IMPERGATOR
    0x0,
    // POKEMON_IGNIVOR
    0x0,
    // POKEMON_RAMOTH
    0x8,
    // POKEMON_GLAZIOLA
    0x0,
    // POKEMON_RESLADERO
    0x0,
    // POKEMON_LEDYBA
    0x0,
    // POKEMON_LEDIAN
    0x8,
    // POKEMON_WEBARAK
    0x0,
    // POKEMON_ARIADOS
    0x0,
    // POKEMON_IKSBAT
    0xb,
    // POKEMON_LAMPI
    0x0,
    // POKEMON_LANTURN
    0x0,
    // POKEMON_MAGNEZONE
    0x8,
    // POKEMON_TOGEKISS
    0x6,
    // POKEMON_FLABEBE
    0x0,
    // POKEMON_TOGEPI
    0x0,
    // POKEMON_TOGETIC
    0x0,
    // POKEMON_NATU
    0x0,
    // POKEMON_XATU
    0x0,
    // POKEMON_VOLTILAMM
    0x0,
    // POKEMON_WAATY
    0x0,
    // POKEMON_AMPHAROS
    0x0,
    // POKEMON_BLUBELLA
    0x0,
    // POKEMON_MARILL
    0x0,
    // POKEMON_AZUMARILL
    0x0,
    // POKEMON_MOGELBAUM
    0x0,
    // POKEMON_CLAVION
    0x7,
    // POKEMON_LICHTEL
    0xb,
    // POKEMON_LATERNECTO
    0xc,
    // POKEMON_SKLELABRA
    0x7,
    // POKEMON_GRIFFEL
    0x0,
    // POKEMON_SHNEBEDECK
    0x0,
    // POKEMON_REXBLISAR
    0x0,
    // POKEMON_AMBIDIFFEL
    0x0,
    // POKEMON_FELINO
    0x0,
    // POKEMON_MORLORD
    0x0,
    // POKEMON_PSIANA
    0x0,
    // POKEMON_NACHTARA
    0x0,
    // POKEMON_KRAMURX
    0xc,
    // POKEMON_LASCHOKING
    0x0,
    // POKEMON_KRAMSHEF
    0x0,
    // POKEMON_ICOGNITO
    0x8,
    // POKEMON_FROSDEDJE
    0x7,
    // POKEMON_SKORGRO
    0xb,
    // POKEMON_TANNZA
    0x0,
    // POKEMON_FORSTELLKA
    0x0,
    // POKEMON_ELEVOLTEK
    0x0,
    // POKEMON_SKORGLA
    0xa,
    // POKEMON_STAHLOS
    0x0,
    // POKEMON_SNUBBULL
    0x0,
    // POKEMON_GRANBULL
    0x0,
    // POKEMON_MAMUTEL
    0x0,
    // POKEMON_SCHEROX
    0x0,
    // POKEMON_POTTROTT
    0x0,
    // POKEMON_SKARABORN
    0x0,
    // POKEMON_KRYPPUK
    0x0,
    // POKEMON_TEDDIURSA
    0x0,
    // POKEMON_URSARING
    0x0,
    // POKEMON_SCHNECKMAG
    0x0,
    // POKEMON_MAGCARGO
    0x0,
    // POKEMON_QUIEKEL
    0x0,
    // POKEMON_KEIFEL
    0x0,
    // POKEMON_CORASONN
    0x0,
    // POKEMON_REMORAID
    0x0,
    // POKEMON_OCTILLERY
    0x0,
    // POKEMON_BOTOGEL
    0x0,
    // POKEMON_SCHLURPLEK
    0x0,
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
    0x1,
    // POKEMON_VOLUMINAS
    0x9,
    // POKEMON_TRAUNMAGIL
    0xb,
    // POKEMON_RABAUZ
    0x0,
    // POKEMON_KAPOERA
    0x0,
    // POKEMON_KUSSILLA
    0x0,
    // POKEMON_ELEKID
    0x0,
    // POKEMON_MAGBY
    0x0,
    // POKEMON_MILTANK
    0x0,
    // POKEMON_HEITEIRA
    0x0,
    // POKEMON_RAIKOU
    0x0,
    // POKEMON_ENTEI
    0x0,
    // POKEMON_SUICUNE
    0x0,
    // POKEMON_LARVITAR
    0x0,
    // POKEMON_PUPITAR
    0x0,
    // POKEMON_DESPOTAR
    0x0,
    // POKEMON_LUGIA
    0x8,
    // POKEMON_HO_OH
    0x6,
    // POKEMON_CELEBI
    0xf,
    // POKEMON_BISAFLORM
    0x0,
    // POKEMON_GLURAKM
    0x0,
    // POKEMON_AQUANAM
    0x0,
    // POKEMON_BLITZAM
    0x0,
    // POKEMON_FLAMARM
    0x0,
    // POKEMON_DURENGARDA
    0x0,
    // POKEMON_IN
    0x0,
    // POKEMON_GAME
    0x0,
    // POKEMON_TURTOKM
    0x0,
    // POKEMON_AMPHARAOSM
    0x0,
    // POKEMON_GENGARM
    0x0,
    // POKEMON_BIBORM
    0x9,
    // POKEMON_ALTARIAM
    0x9,
    // POKEMON_GEOWAZM
    0x0,
    // POKEMON_SENGOM
    0x0,
    // POKEMON_VIPITISM
    0x0,
    // POKEMON_ZOBIRISM
    0x0,
    // POKEMON_tropius_mega
    0xC,
    // POKEMON_10e
    0x0,
    // POKEMON_10f
    0x0,
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
    0x0,
    // POKEMON_STICHSCHAL
    0x0,
    // POKEMON_STAHLSTICH
    0x0,
    // POKEMON_WELUNO
    0x0,
    // POKEMON_ORTHODOS
    0x0,
    // POKEMON_ZERBERTRES
    0x0,
    // POKEMON_SEEKID
    0x0,
    // POKEMON_SEESKULL
    0x4,
    // POKEMON_SKULLYDRA
    0x8,
    // POKEMON_FIFFYEN
    0x0,
    // POKEMON_MAGNAYEN
    0x0,
    // POKEMON_ZIGZACHS
    0x0,
    // POKEMON_GERADAKS
    0x0,
    // POKEMON_WAUMPEL
    0x0,
    // POKEMON_SCHALOKO
    0x0,
    // POKEMON_PAPINELLA
    0xf,
    // POKEMON_PANEKON
    0x0,
    // POKEMON_PUDOX
    0xa,
    // POKEMON_LOTURZEL
    0x0,
    // POKEMON_LOMBRERO
    0x0,
    // POKEMON_KAPPALORES
    0x0,
    // POKEMON_SAMURZEL
    0x0,
    // POKEMON_BLANAS
    0x0,
    // POKEMON_TENGULIST
    0x0,
    // POKEMON_NINCADA
    0x0,
    // POKEMON_NINJASK
    0xa,
    // POKEMON_NINJATOM
    0x8,
    // POKEMON_SCHWALBINI
    0x0,
    // POKEMON_SCHWALBOSS
    0x0,
    // POKEMON_KNILZ
    0x0,
    // POKEMON_KAPILZ
    0x0,
    // POKEMON_PANDIR
    0x0,
    // POKEMON_WINGULL
    0x10,
    // POKEMON_PELIPPER
    0x8,
    // POKEMON_GEHWEIHER
    0x0,
    // POKEMON_MASKEREGEN
    0xa,
    // POKEMON_WAILMER
    0x0,
    // POKEMON_WAILORD
    0x0,
    // POKEMON_ENECO
    0x0,
    // POKEMON_ENEKORO
    0x0,
    // POKEMON_KECLEON
    0x0,
    // POKEMON_PUPPANCE
    0x4,
    // POKEMON_LEPUMENTAS
    0xa,
    // POKEMON_NASGNET
    0x0,
    // POKEMON_MAGBRANT
    0x0,
    // POKEMON_ZWIRRFINST
    0x8,
    // POKEMON_SCHMERBE
    0x1,
    // POKEMON_WELSAR
    0x0,
    // POKEMON_LIEBISKUS
    0x0,
    // POKEMON_KREBSCORPS
    0x0,
    // POKEMON_KREBUTACK
    0x0,
    // POKEMON_BARSCHWA
    0x0,
    // POKEMON_MILOTIC
    0x0,
    // POKEMON_KANIVANHA
    0x0,
    // POKEMON_TOHAIDO
    0x0,
    // POKEMON_KNACKLION
    0x0,
    // POKEMON_VIBRAVA
    0x0,
    // POKEMON_LIBELLDRA
    0x9,
    // POKEMON_RIOLU
    0x0,
    // POKEMON_LUCARIO
    0x0,
    // POKEMON_FRIZELBLIZ
    0x0,
    // POKEMON_VOLTENSO
    0x0,
    // POKEMON_CAMAUB
    0x0,
    // POKEMON_CAMERUPT
    0x0,
    // POKEMON_SEEMOPS
    0x0,
    // POKEMON_SEEJONG
    0x0,
    // POKEMON_WALRAISA
    0x0,
    // POKEMON_TUSKA
    0x0,
    // POKEMON_NOKTUSKA
    0x0,
    // POKEMON_SCHNEPPKE
    0x0,
    // POKEMON_FIRNONTOR
    0xc,
    // POKEMON_LUNASTEIN
    0xd,
    // POKEMON_SONNFEL
    0x8,
    // POKEMON_AZURILL
    0x0,
    // POKEMON_SPOINK
    0x0,
    // POKEMON_GROINK
    0x0,
    // POKEMON_PLUSLE
    0x0,
    // POKEMON_MINUN
    0x0,
    // POKEMON_FLUNKIFER
    0x0,
    // POKEMON_MEDITIE
    0x0,
    // POKEMON_MEDITALIS
    0x0,
    // POKEMON_WABLU
    0xc,
    // POKEMON_ALTARIA
    0x8,
    // POKEMON_KLINGPLIM
    0x8,
    // POKEMON_ZWIRRLICHT
    0x9,
    // POKEMON_ZWIRRKLOP
    0x0,
    // POKEMON_PORYGON_Z
    0x0,
    // POKEMON_BUMMELZ
    0x0,
    // POKEMON_MUNTIER
    0x0,
    // POKEMON_LETARKING
    0x0,
    // POKEMON_SCHLUPPUCK
    0x0,
    // POKEMON_SCHLUKWECH
    0x0,
    // POKEMON_TROPIUS
    0x0,
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
    0x6,
    // POKEMON_BANETTE
    0x8,
    // POKEMON_VIPITIS
    0x0,
    // POKEMON_SENGO
    0x0,
    // POKEMON_RELICANTH
    0x0,
    // POKEMON_STOLLUNIOR
    0x0,
    // POKEMON_STOLLRAK
    0x0,
    // POKEMON_STOLLOSS
    0x0,
    // POKEMON_FORMEO
    0x10,
    // POKEMON_VOLBEAT
    0,
    // POKEMON_ILLUMISE
    0,
    // POKEMON_LILIEP
    0x0,
    // POKEMON_WIELIE
    0x0,
    // POKEMON_ANORITH
    0x0,
    // POKEMON_ARMALDO
    0x0,
    // POKEMON_TRASLA
    0x0,
    // POKEMON_KIRLIA
    0x0,
    // POKEMON_GUARDEVOIR
    0x0,
    // POKEMON_KINDWURM
    0x0,
    // POKEMON_DRASCHEL
    0x0,
    // POKEMON_BRUTALANDA
    0x0,
    // POKEMON_TANHEL
    0x2,
    // POKEMON_METANG
    0x3,
    // POKEMON_METAGROSS
    0x0,
    // POKEMON_REGIROCK
    0x0,
    // POKEMON_REGICE
    0x0,
    // POKEMON_REGISTEEL
    0x0,
    // POKEMON_KYOGRE
    0x0,
    // POKEMON_GROUDON
    0x0,
    // POKEMON_RAYQUAZA
    0x8,
    // POKEMON_LATIAS
    0xa,
    // POKEMON_LATIOS
    0x8,
    // POKEMON_JIRACHI
    0xc,
    // POKEMON_DEOXYS
    0x8,
    // POKEMON_PALIMPALIM
    0xc,
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
    // POKEMON_GROUDON
    0x0,
    // POKEMON_KECLEON
    0x0,
    // POKEMON_CRYSTAL_ONIX
    0x0,
};
