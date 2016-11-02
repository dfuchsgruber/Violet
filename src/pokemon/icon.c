#include "types.h"
#include "pokemon.h"

void *pokemon_icons[POKEMON_CNT] = {
    // POKEMON_POKEMON_0
    (void*) 0x8e76f50,
    // POKEMON_BISASAM
    (void*) 0x8d30180,
    // POKEMON_BISAKNOSP
    (void*) 0x8d30c80,
    // POKEMON_BISAFLOR
    (void*) 0x8d31af8,
    // POKEMON_GLUMANDA
    (void*) 0x8d3248c,
    // POKEMON_GLUTEXO
    (void*) 0x8d32f9c,
    // POKEMON_GLURAK
    (void*) 0x8d33d14,
    // POKEMON_SCHIGGY
    (void*) 0x8d346a8,
    // POKEMON_SCHILLOK
    (void*) 0x8d3520c,
    // POKEMON_TURTOK
    (void*) 0x8d35f94,
    // POKEMON_DARTIRI
    (void*) 0x87c0cd8,
    // POKEMON_DARTIGNIS
    (void*) 0x87cb520,
    // POKEMON_FIARO
    (void*) 0x87cd2e8,
    // POKEMON_HORNLIU
    (void*) 0x8d3867c,
    // POKEMON_KOKUNA
    (void*) 0x8d38fa8,
    // POKEMON_BIBOR
    (void*) 0x8780230,
    // POKEMON_STARALILI
    (void*) 0x8d3a5e8,
    // POKEMON_STARAVIA
    (void*) 0x8823654,
    // POKEMON_STARAPTOR
    (void*) 0x88247b0,
    // POKEMON_BRONZEL
    (void*) 0x87eca04,
    // POKEMON_BRONZONG
    (void*) 0x87edcb4,
    // POKEMON_MAEHIKEL
    (void*) 0x87ee7f0,
    // POKEMON_CHEVRUMM
    (void*) 0x87ef500,
    // POKEMON_PARAGONI
    (void*) 0x87efd08,
    // POKEMON_TROMBORK
    (void*) 0x8d3fed4,
    // POKEMON_PIKACHU
    (void*) 0x8d408ec,
    // POKEMON_RAICHU
    (void*) 0x8d41474,
    // POKEMON_SANDAN
    (void*) 0x8d41ee8,
    // POKEMON_SANDAMER
    (void*) 0x8d42b8c,
    // POKEMON_NIDORANW
    (void*) 0x8d43540,
    // POKEMON_NIDORINA
    (void*) 0x8d44064,
    // POKEMON_NIDOQUEEN
    (void*) 0x8d44cc4,
    // POKEMON_NIDORANM
    (void*) 0x8d456f4,
    // POKEMON_NIDORINO
    (void*) 0x8d462a4,
    // POKEMON_NIDOKING
    (void*) 0x8d4708c,
    // POKEMON_FLOETTE
    (void*) 0x8d47a68,
    // POKEMON_FLORGES
    (void*) 0x8d48550,
    // POKEMON_VULPIX
    (void*) 0x8d48ff0,
    // POKEMON_VULNONA
    (void*) 0x8d49c9c,
    // POKEMON_PUMMELUFF
    (void*) 0x8d4a5ec,
    // POKEMON_KNUDDELUFF
    (void*) 0x8d4b068,
    // POKEMON_ZUBAT
    (void*) 0x8d4ba50,
    // POKEMON_GOLBAT
    (void*) 0x8d4c51c,
    // POKEMON_MYRAPLA
    (void*) 0x8d4ce90,
    // POKEMON_DUFLOR
    (void*) 0x8d4d9e8,
    // POKEMON_GIFLOR
    (void*) 0x8d4e5f8,
    // POKEMON_FOLIPURBA
    (void*) 0x87f6f24,
    // POKEMON_FEELINARA
    (void*) 0x8d4fa70,
    // POKEMON_WATTZAPF
    (void*) 0x8d50530,
    // POKEMON_VOLTULA
    (void*) 0x8d51148,
    // POKEMON_DIGDA
    (void*) 0x8d519d4,
    // POKEMON_DIGDRI
    (void*) 0x8d5241c,
    // POKEMON_KASTADUR
    (void*) 0x8d52e5c,
    // POKEMON_TENTANTEL
    (void*) 0x8d53984,
    // POKEMON_ENTON
    (void*) 0x8d54374,
    // POKEMON_ENTORON
    (void*) 0x8d54ec8,
    // POKEMON_MENKI
    (void*) 0x8d55998,
    // POKEMON_RASAFF
    (void*) 0x8d56504,
    // POKEMON_FUKANO
    (void*) 0x8d56fd8,
    // POKEMON_ARKANI
    (void*) 0x8d57d24,
    // POKEMON_GRAMOKLES
    (void*) 0x8d58694,
    // POKEMON_DUOKLES
    (void*) 0x8d59100,
    // POKEMON_DURENGARD
    (void*) 0x8d59c28,
    // POKEMON_ABRA
    (void*) 0x8d5a638,
    // POKEMON_KADABRA
    (void*) 0x8d5b31c,
    // POKEMON_SIMSALA
    (void*) 0x8d5bfa4,
    // POKEMON_MACHOLLO
    (void*) 0x8d5c980,
    // POKEMON_MASCHOCK
    (void*) 0x8d5d50c,
    // POKEMON_MACHOMEI
    (void*) 0x8d5e2c4,
    // POKEMON_KNOFENSA
    (void*) 0x8d5ec5c,
    // POKEMON_ULTRIGARIA
    (void*) 0x8d5f6ec,
    // POKEMON_SARZENIA
    (void*) 0x8d60320,
    // POKEMON_TENTACHA
    (void*) 0x8d60d04,
    // POKEMON_TENTOXA
    (void*) 0x8d61a04,
    // POKEMON_KLEINSTEIN
    (void*) 0x8d62384,
    // POKEMON_GEOROK
    (void*) 0x8d62e64,
    // POKEMON_GEOWAZ
    (void*) 0x8d639c4,
    // POKEMON_PONITA
    (void*) 0x8d64500,
    // POKEMON_GALLOPA
    (void*) 0x8d65208,
    // POKEMON_FLEGMON
    (void*) 0x8d65bb0,
    // POKEMON_LAHMUS
    (void*) 0x8d6685c,
    // POKEMON_MAGNETILO
    (void*) 0x8d67088,
    // POKEMON_MAGNETON
    (void*) 0x8d67bb4,
    // POKEMON_PORENTA
    (void*) 0x8d686e4,
    // POKEMON_DODU
    (void*) 0x8d69150,
    // POKEMON_DODRI
    (void*) 0x8d69e64,
    // POKEMON_JURBO
    (void*) 0x8d6a8e4,
    // POKEMON_JUGONG
    (void*) 0x8d6b3b0,
    // POKEMON_SLEIMA
    (void*) 0x8d6be04,
    // POKEMON_SLEIMOK
    (void*) 0x8d6c8f4,
    // POKEMON_MUSCHAS
    (void*) 0x8d6d2e4,
    // POKEMON_AUSTOS
    (void*) 0x8d6df94,
    // POKEMON_NEBULAK
    (void*) 0x8d6eae0,
    // POKEMON_ALPOLLO
    (void*) 0x8d6f614,
    // POKEMON_GENGAR
    (void*) 0x8d7011c,
    // POKEMON_ONIX
    (void*) 0x8d70dc0,
    // POKEMON_TRAUMATO
    (void*) 0x8d717a4,
    // POKEMON_HYPNO
    (void*) 0x8d72374,
    // POKEMON_KRABBY
    (void*) 0x8d72e94,
    // POKEMON_KINGLER
    (void*) 0x8d73b08,
    // POKEMON_VOLTOBAL
    (void*) 0x8d743ec,
    // POKEMON_LEKTROBAL
    (void*) 0x8d74d30,
    // POKEMON_OWEI
    (void*) 0x8d75830,
    // POKEMON_KOKOWEI
    (void*) 0x8d764bc,
    // POKEMON_TRAGOSSO
    (void*) 0x8d76f28,
    // POKEMON_KNOGGA
    (void*) 0x8d77a2c,
    // POKEMON_KICKLEE
    (void*) 0x8d784b4,
    // POKEMON_NOCKCHAN
    (void*) 0x8d78fa8,
    // POKEMON_SCHLURP
    (void*) 0x8d79a94,
    // POKEMON_SMOGON
    (void*) 0x8d7a504,
    // POKEMON_SMOGMOG
    (void*) 0x8d7b1b4,
    // POKEMON_RIHORN
    (void*) 0x8d7bd58,
    // POKEMON_RIZEROS
    (void*) 0x8d7cb0c,
    // POKEMON_CHANEIRA
    (void*) 0x8d7d500,
    // POKEMON_ZOBIRIS
    (void*) 0x8a34c50,
    // POKEMON_KANGAMA
    (void*) 0x8d7ee30,
    // POKEMON_SEEPER
    (void*) 0x8d7f7ec,
    // POKEMON_SEEMON
    (void*) 0x8d80384,
    // POKEMON_QUABBEL
    (void*) 0x8d80ecc,
    // POKEMON_APOQUALLYP
    (void*) 0x8d81b00,
    // POKEMON_STERNDU
    (void*) 0x8d82488,
    // POKEMON_STARMIE
    (void*) 0x8d82f3c,
    // POKEMON_TRAUNFUGIL
    (void*) 0x8d83a9c,
    // POKEMON_SICHLOR
    (void*) 0x8d8474c,
    // POKEMON_GALAGLADI
    (void*) 0x88fc5a0,
    // POKEMON_ELEKTEK
    (void*) 0x8d85e4c,
    // POKEMON_MAGMAR
    (void*) 0x8d86a24,
    // POKEMON_PINSIR
    (void*) 0x8d87610,
    // POKEMON_TAUROS
    (void*) 0x8d88194,
    // POKEMON_KARPADOR
    (void*) 0x8d88c7c,
    // POKEMON_GARADOS
    (void*) 0x8d89b48,
    // POKEMON_LAPRAS
    (void*) 0x8d8a6dc,
    // POKEMON_DITTO
    (void*) 0x8d8af2c,
    // POKEMON_EVOLI
    (void*) 0x8d8b9b0,
    // POKEMON_AQUANA
    (void*) 0x8d8c47c,
    // POKEMON_BLITZA
    (void*) 0x8d8cfe8,
    // POKEMON_FLAMARA
    (void*) 0x8d8db6c,
    // POKEMON_PORYGON
    (void*) 0x8d8e544,
    // POKEMON_AMONITAS
    (void*) 0x8d8ef90,
    // POKEMON_AMOROSO
    (void*) 0x8d8fb00,
    // POKEMON_KABUTO
    (void*) 0x8d90430,
    // POKEMON_KABUTOPS
    (void*) 0x8d9104c,
    // POKEMON_AERODACTYL
    (void*) 0x8d91c10,
    // POKEMON_RELAXO
    (void*) 0x8d92670,
    // POKEMON_ARKTOS
    (void*) 0x8d93234,
    // POKEMON_ZAPDOS
    (void*) 0x8d93e30,
    // POKEMON_LAVADOS
    (void*) 0x8d94aa8,
    // POKEMON_DRATINI
    (void*) 0x8d9545c,
    // POKEMON_DRAGONIR
    (void*) 0x8d95f74,
    // POKEMON_DRAGORAN
    (void*) 0x8d96c2c,
    // POKEMON_MEWTU
    (void*) 0x8d9789c,
    // POKEMON_MEW
    (void*) 0x8d98314,
    // POKEMON_ENDIVIE
    (void*) 0x8d98cb0,
    // POKEMON_LORBLATT
    (void*) 0x8d99884,
    // POKEMON_MEGANIE
    (void*) 0x8d9a5a0,
    // POKEMON_FEURIGEL
    (void*) 0x8d9afc8,
    // POKEMON_IGELAVAR
    (void*) 0x8d9bac8,
    // POKEMON_TORNUPTO
    (void*) 0x8d9c764,
    // POKEMON_KARNIMANI
    (void*) 0x8d9d158,
    // POKEMON_TYRACROC
    (void*) 0x8d9dc80,
    // POKEMON_IMPERGATOR
    (void*) 0x8d9eb28,
    // POKEMON_IGNIVOR
    (void*) 0x8d9f518,
    // POKEMON_RAMOTH
    (void*) 0x8d9ffe4,
    // POKEMON_GLAZIOLA
    (void*) 0x8da09e0,
    // POKEMON_RESLADERO
    (void*) 0x8da1500,
    // POKEMON_LEDYBA
    (void*) 0x8da1f94,
    // POKEMON_LEDIAN
    (void*) 0x8da2ae4,
    // POKEMON_WEBARAK
    (void*) 0x8da342c,
    // POKEMON_ARIADOS
    (void*) 0x8da3fd4,
    // POKEMON_IKSBAT
    (void*) 0x8da4afc,
    // POKEMON_LAMPI
    (void*) 0x8da553c,
    // POKEMON_LANTURN
    (void*) 0x8da601c,
    // POKEMON_MAGNEZONE
    (void*) 0x8da6904,
    // POKEMON_TOGEKISS
    (void*) 0x881f480,
    // POKEMON_FLABEBE
    (void*) 0x8da7a24,
    // POKEMON_TOGEPI
    (void*) 0x8da82dc,
    // POKEMON_TOGETIC
    (void*) 0x8da8cec,
    // POKEMON_NATU
    (void*) 0x8da953c,
    // POKEMON_XATU
    (void*) 0x8daa000,
    // POKEMON_VOLTILAMM
    (void*) 0x8daaa18,
    // POKEMON_WAATY
    (void*) 0x8dab4a4,
    // POKEMON_AMPHAROS
    (void*) 0x8dabfe8,
    // POKEMON_BLUBELLA
    (void*) 0x8dac9ec,
    // POKEMON_MARILL
    (void*) 0x8dad3cc,
    // POKEMON_AZUMARILL
    (void*) 0x8daddf8,
    // POKEMON_MOGELBAUM
    (void*) 0x8dae8dc,
    // POKEMON_CLAVION
    (void*) 0x8daf344,
    // POKEMON_LICHTEL
    (void*) 0x8dafd48,
    // POKEMON_LATERNECTO
    (void*) 0x8db0720,
    // POKEMON_SKLELABRA
    (void*) 0x8db12f4,
    // POKEMON_GRIFFEL
    (void*) 0x8db1d54,
    // POKEMON_SHNEBEDECK
    (void*) 0x88fc9a0,
    // POKEMON_REXBLISAR
    (void*) 0x8db3228,
    // POKEMON_AMBIDIFFEL
    (void*) 0x888a3e4,
    // POKEMON_FELINO
    (void*) 0x8db470c,
    // POKEMON_MORLORD
    (void*) 0x8db51ec,
    // POKEMON_PSIANA
    (void*) 0x8db5c70,
    // POKEMON_NACHTARA
    (void*) 0x8db6708,
    // POKEMON_KRAMURX
    (void*) 0x8db7170,
    // POKEMON_LASCHOKING
    (void*) 0x8db7d20,
    // POKEMON_KRAMSHEF
    (void*) 0x888a000,
    // POKEMON_ICOGNITO
    (void*) 0x8db8fa8,
    // POKEMON_FROSDEDJE
    (void*) 0x88b8a8c,
    // POKEMON_SKORGRO
    (void*) 0x888a7b8,
    // POKEMON_TANNZA
    (void*) 0x8dbb04c,
    // POKEMON_FORSTELLKA
    (void*) 0x8dbbb98,
    // POKEMON_ELEVOLTEK
    (void*) 0x881e1f0,
    // POKEMON_SKORGLA
    (void*) 0x8dbd284,
    // POKEMON_STAHLOS
    (void*) 0x8dbdfc0,
    // POKEMON_SNUBBULL
    (void*) 0x8dbea2c,
    // POKEMON_GRANBULL
    (void*) 0x8dbf54c,
    // POKEMON_MAMUTEL
    (void*) 0x89ccc00,
    // POKEMON_SCHEROX
    (void*) 0x8dc0c34,
    // POKEMON_POTTROTT
    (void*) 0x8dc15c4,
    // POKEMON_SKARABORN
    (void*) 0x8dc2194,
    // POKEMON_KRYPPUK
    (void*) 0x8a3e000,
    // POKEMON_TEDDIURSA
    (void*) 0x8dc39fc,
    // POKEMON_URSARING
    (void*) 0x8dc462c,
    // POKEMON_SCHNECKMAG
    (void*) 0x8dc4ff0,
    // POKEMON_MAGCARGO
    (void*) 0x8dc5bc0,
    // POKEMON_QUIEKEL
    (void*) 0x8dc6468,
    // POKEMON_KEIFEL
    (void*) 0x8dc6e4c,
    // POKEMON_CORASONN
    (void*) 0x8dc7864,
    // POKEMON_REMORAID
    (void*) 0x8dc8250,
    // POKEMON_OCTILLERY
    (void*) 0x8dc8cac,
    // POKEMON_BOTOGEL
    (void*) 0x8dc984c,
    // POKEMON_SCHLURPLEK
    (void*) 0x88b9e1c,
    // POKEMON_PANZAERON
    (void*) 0x8dcb04c,
    // POKEMON_HUNDUSTER
    (void*) 0x8dcb9f4,
    // POKEMON_HUNDEMON
    (void*) 0x8dcc588,
    // POKEMON_SEEDRAKING
    (void*) 0x8dcd1cc,
    // POKEMON_PHANPY
    (void*) 0x8dcdb5c,
    // POKEMON_DONPHAN
    (void*) 0x8dce73c,
    // POKEMON_PORYGON2
    (void*) 0x8dcf150,
    // POKEMON_VOLUMINAS
    (void*) 0x8dcfd20,
    // POKEMON_TRAUNMAGIL
    (void*) 0x8a35f40,
    // POKEMON_RABAUZ
    (void*) 0x8dd1260,
    // POKEMON_KAPOERA
    (void*) 0x8dd1e84,
    // POKEMON_KUSSILLA
    (void*) 0x8dd29c4,
    // POKEMON_ELEKID
    (void*) 0x8dd3494,
    // POKEMON_MAGBY
    (void*) 0x8dd3e34,
    // POKEMON_MILTANK
    (void*) 0x8dd49f0,
    // POKEMON_HEITEIRA
    (void*) 0x8dd5514,
    // POKEMON_RAIKOU
    (void*) 0x8dd62a8,
    // POKEMON_ENTEI
    (void*) 0x8dd7138,
    // POKEMON_SUICUNE
    (void*) 0x8dd8008,
    // POKEMON_LARVITAR
    (void*) 0x8dd8980,
    // POKEMON_PUPITAR
    (void*) 0x8dd9418,
    // POKEMON_DESPOTAR
    (void*) 0x8dda1b0,
    // POKEMON_LUGIA
    (void*) 0x8ddaeb8,
    // POKEMON_HO_OH
    (void*) 0x8ddbd8c,
    // POKEMON_CELEBI
    (void*) 0x8ddc820,
    // POKEMON_BISAFLORM
    (void*) 0x8a03ac8,
    // POKEMON_GLURAKM
    (void*) 0x8a0708c,
    // POKEMON_AQUANAM
    (void*) 0x8a262cc,
    // POKEMON_BLITZAM
    (void*) 0x8a26694,
    // POKEMON_FLAMARM
    (void*) 0x877bba8,
    // POKEMON_DURENGARDA
    (void*) 0x8a1fb1c,
    // POKEMON_IN
    (void*) 0x8a230d4,
    // POKEMON_GAME
    (void*) 0x8a22d0c,
    // POKEMON_TURTOKM
    (void*) 0x8a22914,
    // POKEMON_AMPHARAOSM
    (void*) 0x879b3bc,
    // POKEMON_GENGARM
    (void*) 0x8a30ba8,
    // POKEMON_BIBORM
    (void*) 0x8793bfc,
    // POKEMON_ALTARIAM
    (void*) 0x8a2da24,
    // POKEMON_GEOWAZM
    (void*) 0x8a323fc,
    // POKEMON_SENGOM
    (void*) 0x8a32024,
    // POKEMON_VIPITISM
    (void*) 0x8a35044,
    // POKEMON_ZOBIRISM
    (void*) 0x8a3670c,
    // POKEMON_10d
    (void*) 0x8e76f50,
    // POKEMON_10e
    (void*) 0x8e76f50,
    // POKEMON_10f
    (void*) 0x8e76f50,
    // POKEMON_110
    (void*) 0x8e76f50,
    // POKEMON_111
    (void*) 0x8e76f50,
    // POKEMON_112
    (void*) 0x8e76f50,
    // POKEMON_113
    (void*) 0x8e76f50,
    // POKEMON_114
    (void*) 0x8e76f50,
    // POKEMON_LOCKSCHAL
    (void*) 0x8a30460,
    // POKEMON_STICHSCHAL
    (void*) 0x88ba20c,
    // POKEMON_STAHLSTICH
    (void*) 0x8a208b8,
    // POKEMON_WELUNO
    (void*) 0x87833b0,
    // POKEMON_ORTHODOS
    (void*) 0x8787758,
    // POKEMON_ZERBERTRES
    (void*) 0x88ba5f8,
    // POKEMON_SEEKID
    (void*) 0x8850274,
    // POKEMON_SEESKULL
    (void*) 0x87fafd4,
    // POKEMON_SKULLYDRA
    (void*) 0x88ba9fc,
    // POKEMON_FIFFYEN
    (void*) 0x8de3ff8,
    // POKEMON_MAGNAYEN
    (void*) 0x8de4c18,
    // POKEMON_ZIGZACHS
    (void*) 0x8de5798,
    // POKEMON_GERADAKS
    (void*) 0x8de624c,
    // POKEMON_WAUMPEL
    (void*) 0x8de6b90,
    // POKEMON_SCHALOKO
    (void*) 0x8de749c,
    // POKEMON_PAPINELLA
    (void*) 0x8de8014,
    // POKEMON_PANEKON
    (void*) 0x8de8900,
    // POKEMON_PUDOX
    (void*) 0x8de9330,
    // POKEMON_LOTURZEL
    (void*) 0x8de9ce8,
    // POKEMON_LOMBRERO
    (void*) 0x8dea76c,
    // POKEMON_KAPPALORES
    (void*) 0x8deb3bc,
    // POKEMON_SAMURZEL
    (void*) 0x8debda0,
    // POKEMON_BLANAS
    (void*) 0x8dec7c4,
    // POKEMON_TENGULIST
    (void*) 0x8ded3b4,
    // POKEMON_NINCADA
    (void*) 0x8dedd7c,
    // POKEMON_NINJASK
    (void*) 0x8dee928,
    // POKEMON_NINJATOM
    (void*) 0x8def458,
    // POKEMON_SCHWALBINI
    (void*) 0x8defd40,
    // POKEMON_SCHWALBOSS
    (void*) 0x8df08ac,
    // POKEMON_KNILZ
    (void*) 0x8df1264,
    // POKEMON_KAPILZ
    (void*) 0x8df1e9c,
    // POKEMON_PANDIR
    (void*) 0x8df2948,
    // POKEMON_WINGULL
    (void*) 0x8df3344,
    // POKEMON_PELIPPER
    (void*) 0x8df3ecc,
    // POKEMON_GEHWEIHER
    (void*) 0x8df4780,
    // POKEMON_MASKEREGEN
    (void*) 0x8df52e4,
    // POKEMON_WAILMER
    (void*) 0x8df5c18,
    // POKEMON_WAILORD
    (void*) 0x8df6664,
    // POKEMON_ENECO
    (void*) 0x8df711c,
    // POKEMON_ENEKORO
    (void*) 0x8df7cb4,
    // POKEMON_KECLEON
    (void*) 0x8df887c,
    // POKEMON_PUPPANCE
    (void*) 0x8df91a8,
    // POKEMON_LEPUMENTAS
    (void*) 0x8df9da4,
    // POKEMON_NASGNET
    (void*) 0x882f6b4,
    // POKEMON_MAGBRANT
    (void*) 0x8dfb364,
    // POKEMON_ZWIRRFINST
    (void*) 0x88257a0,
    // POKEMON_SCHMERBE
    (void*) 0x8dfc760,
    // POKEMON_WELSAR
    (void*) 0x8dfd294,
    // POKEMON_LIEBISKUS
    (void*) 0x8dfda90,
    // POKEMON_KREBSCORPS
    (void*) 0x8dfe578,
    // POKEMON_KREBUTACK
    (void*) 0x8dff25c,
    // POKEMON_BARSCHWA
    (void*) 0x8dffc90,
    // POKEMON_MILOTIC
    (void*) 0x8e00884,
    // POKEMON_KANIVANHA
    (void*) 0x8e01330,
    // POKEMON_TOHAIDO
    (void*) 0x8e01e88,
    // POKEMON_KNACKLION
    (void*) 0x8e02734,
    // POKEMON_VIBRAVA
    (void*) 0x8e0318c,
    // POKEMON_LIBELLDRA
    (void*) 0x8e03f28,
    // POKEMON_RIOLU
    (void*) 0x88271c0,
    // POKEMON_LUCARIO
    (void*) 0x8826df0,
    // POKEMON_FRIZELBLIZ
    (void*) 0x8e06028,
    // POKEMON_VOLTENSO
    (void*) 0x8e069f4,
    // POKEMON_CAMAUB
    (void*) 0x8e073f0,
    // POKEMON_CAMERUPT
    (void*) 0x8e07f3c,
    // POKEMON_SEEMOPS
    (void*) 0x8e0881c,
    // POKEMON_SEEJONG
    (void*) 0x8e09288,
    // POKEMON_WALRAISA
    (void*) 0x8e09f20,
    // POKEMON_TUSKA
    (void*) 0x8e0aa00,
    // POKEMON_NOKTUSKA
    (void*) 0x8e0b5a8,
    // POKEMON_SCHNEPPKE
    (void*) 0x8e0bfc0,
    // POKEMON_FIRNONTOR
    (void*) 0x8e0cba8,
    // POKEMON_LUNASTEIN
    (void*) 0x8e0d698,
    // POKEMON_SONNFEL
    (void*) 0x8e0e340,
    // POKEMON_AZURILL
    (void*) 0x8e0ed90,
    // POKEMON_SPOINK
    (void*) 0x8e0f6ac,
    // POKEMON_GROINK
    (void*) 0x8e10238,
    // POKEMON_PLUSLE
    (void*) 0x8e10bec,
    // POKEMON_MINUN
    (void*) 0x8e1158c,
    // POKEMON_FLUNKIFER
    (void*) 0x8e121b8,
    // POKEMON_MEDITIE
    (void*) 0x8e12ba4,
    // POKEMON_MEDITALIS
    (void*) 0x8e1367c,
    // POKEMON_WABLU
    (void*) 0x8e1417c,
    // POKEMON_ALTARIA
    (void*) 0x8e14d40,
    // POKEMON_ISSO
    (void*) 0x8e156d8,
    // POKEMON_ZWIRRLICHT
    (void*) 0x8e160e8,
    // POKEMON_ZWIRRKLOP
    (void*) 0x8e16be4,
    // POKEMON_ROSELIA
    (void*) 0x8e17788,
    // POKEMON_BUMMELZ
    (void*) 0x8e181c8,
    // POKEMON_MUNTIER
    (void*) 0x8e18cfc,
    // POKEMON_LETARKING
    (void*) 0x8e19a04,
    // POKEMON_SCHLUPPUCK
    (void*) 0x8e1a310,
    // POKEMON_SCHLUKWECH
    (void*) 0x8e1ae0c,
    // POKEMON_TROPIUS
    (void*) 0x8e1bb18,
    // POKEMON_KAUMALAT
    (void*) 0x882ca7c,
    // POKEMON_KNARKSEL
    (void*) 0x882ce4c,
    // POKEMON_KNAKRACK
    (void*) 0x8e1dec8,
    // POKEMON_PERLU
    (void*) 0x8e1e8a4,
    // POKEMON_AALABYSS
    (void*) 0x8e1f434,
    // POKEMON_SAGANABYSS
    (void*) 0x89cc000,
    // POKEMON_ABSOL
    (void*) 0x8e20a9c,
    // POKEMON_SHUPPET
    (void*) 0x89cc500,
    // POKEMON_BANETTE
    (void*) 0x8e21d7c,
    // POKEMON_VIPITIS
    (void*) 0x8e22a98,
    // POKEMON_SENGO
    (void*) 0x8e23648,
    // POKEMON_RELICANTH
    (void*) 0x8e241a4,
    // POKEMON_STOLLUNIOR
    (void*) 0x8e24a24,
    // POKEMON_STOLLRAK
    (void*) 0x8e2554c,
    // POKEMON_STOLLOSS
    (void*) 0x8e26360,
    // POKEMON_FORMEO
    (void*) 0x8e27cc0,
    // POKEMON_VOLBEAT
    (void*) 0x8e28820,
    // POKEMON_ILLUMISE
    (void*) 0x8e29320,
    // POKEMON_LILIEP
    (void*) 0x8e29e18,
    // POKEMON_WIELIE
    (void*) 0x8e2aaa0,
    // POKEMON_ANORITH
    (void*) 0x8e2b47c,
    // POKEMON_ARMALDO
    (void*) 0x8e2c2a4,
    // POKEMON_TRASLA
    (void*) 0x8e2cb80,
    // POKEMON_KIRLIA
    (void*) 0x8e2d660,
    // POKEMON_GUARDEVOIR
    (void*) 0x8e2e180,
    // POKEMON_KINDWURM
    (void*) 0x8e2eb50,
    // POKEMON_DRASCHEL
    (void*) 0x8e2f5ac,
    // POKEMON_BRUTALANDA
    (void*) 0x8e30164,
    // POKEMON_TANHEL
    (void*) 0x8e30b34,
    // POKEMON_METANG
    (void*) 0x8e31724,
    // POKEMON_METAGROSS
    (void*) 0x8e322c4,
    // POKEMON_REGIROCK
    (void*) 0x8e3303c,
    // POKEMON_REGICE
    (void*) 0x8e33be4,
    // POKEMON_REGISTEEL
    (void*) 0x8e34814,
    // POKEMON_KYOGRE
    (void*) 0x8e3536c,
    // POKEMON_GROUDON
    (void*) 0x8e361d8,
    // POKEMON_RAYQUAZA
    (void*) 0x8e36e90,
    // POKEMON_LATIAS
    (void*) 0x8e37a20,
    // POKEMON_LATIOS
    (void*) 0x8e38644,
    // POKEMON_JIRACHI
    (void*) 0x8e39160,
    // POKEMON_DEOXYS
    (void*) 0x8e3a37c,
    // POKEMON_PALIMPALIM
    (void*) 0x8e3b0ac,
    // POKEMON_EGG
    (void*) 0x8e7bb7c,
    // POKEMON_ICOGNITO_B
    (void*) 0x8e3ba7c,
    // POKEMON_ICOGNITO_C
    (void*) 0x8e3c33c,
    // POKEMON_ICOGNITO_D
    (void*) 0x8e3cb8c,
    // POKEMON_ICOGNITO_E
    (void*) 0x8e3d344,
    // POKEMON_ICOGNITO_F
    (void*) 0x8e3db54,
    // POKEMON_ICOGNITO_G
    (void*) 0x8e3e37c,
    // POKEMON_ICOGNITO_H
    (void*) 0x8e3ec84,
    // POKEMON_ICOGNITO_I
    (void*) 0x8e3f3c4,
    // POKEMON_ICOGNITO_J
    (void*) 0x8e3fb70,
    // POKEMON_ICOGNITO_K
    (void*) 0x8e40338,
    // POKEMON_ICOGNITO_L
    (void*) 0x8e40abc,
    // POKEMON_ICOGNITO_M
    (void*) 0x8e41388,
    // POKEMON_ICOGNITO_N
    (void*) 0x8e41bec,
    // POKEMON_ICOGNITO_O
    (void*) 0x8e424e4,
    // POKEMON_ICOGNITO_P
    (void*) 0x8e42c48,
    // POKEMON_ICOGNITO_Q
    (void*) 0x8e433c8,
    // POKEMON_ICOGNITO_R
    (void*) 0x8e43b34,
    // POKEMON_ICOGNITO_S
    (void*) 0x8e44370,
    // POKEMON_ICOGNITO_T
    (void*) 0x8e44ad4,
    // POKEMON_ICOGNITO_U
    (void*) 0x8e45340,
    // POKEMON_ICOGNITO_V
    (void*) 0x8e45b54,
    // POKEMON_ICOGNITO_W
    (void*) 0x8e4632c,
    // POKEMON_ICOGNITO_X
    (void*) 0x8e46ae0,
    // POKEMON_ICOGNITO_Y
    (void*) 0x8e472ac,
    // POKEMON_ICOGNITO_Z
    (void*) 0x8e47a38,
    // POKEMON_ICOGNITO_EXCLAMATION
    (void*) 0x8e48190,
    // POKEMON_ICOGNITO_QUESTION
    (void*) 0x8e4894c,
    // POKEMON_TEST
    (void*) 0x8e36e90
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
    // POKEMON_POTTROTT
    0x1,
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
    0x0,
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
    // POKEMON_KUSSILLA
    0x1,
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
    0x2,
    // POKEMON_IN
    0x1,
    // POKEMON_GAME
    0x2,
    // POKEMON_TURTOKM
    0x2,
    // POKEMON_AMPHARAOSM
    0x1,
    // POKEMON_GENGARM
    0x2,
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
    // POKEMON_10d
    0x0,
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
    // POKEMON_PLUSLE
    0x0,
    // POKEMON_MINUN
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
    0x0,
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
    // POKEMON_SCHLUPPUCK
    0x1,
    // POKEMON_SCHLUKWECH
    0x2,
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
    0x2,
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
    // POKEMON_TEST
    0x1
};