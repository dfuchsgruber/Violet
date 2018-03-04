/* 
 * File:   trainer_parties.c
 * Author: Domi
 *
 * Created on 12. April 2017, 16:22
 */

#include "types.h"
#include "basestats.h"
#include "romfuncs.h"
#include "item.h"
#include "trainer.h"
#include "attack.h"

trainer_pokemon_default_item_default_attacks trainer_party_x0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,4,POKEMON_FIFFYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,100,POKEMON_DEOXYS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,4,POKEMON_ZIGZACHS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,4,POKEMON_DARTIRI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_SANDAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_TRAUMATO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_SAMURZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_MYRAPLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,11,POKEMON_SLEIMA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,11,POKEMON_FLABEBE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_VOLTOBAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_DARTIRI)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_VOLTILAMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_PONITA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_ENECO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,11,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,12,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,12,POKEMON_RIOLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,13,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_CAMAUB)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,12,POKEMON_KNILZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,13,POKEMON_BISASAM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,12,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,12,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_MENKI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,13,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_NASGNET)
};

trainer_pokemon_default_item_default_attacks trainer_party_x13[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_WATTZAPF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_WAUMPEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x14[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_FLABEBE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_EVOLI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x15[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_ZIGZACHS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x16[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_RESLADERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_SCHWALBINI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x17[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_TRASLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_ABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x18[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,13,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_DARTIRI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x19[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_CLAVION),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_FUKANO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_MINUN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_PLUSLE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,13,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_BISASAM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_FLABEBE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_STERNDU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_KREBSCORPS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_KAUMALAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_DRATINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_KINDWURM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_VOLTILAMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MAEHIKEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x20[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_FLEGMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_BARSCHWA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_QUABBEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x22[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_RABAUZ)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x23[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,17,POKEMON_DARTIGNIS,ITEM_NONE,ATTACK_GLUT,ATTACK_SCHNABEL,ATTACK_STAHLFLUEGEL,ATTACK_TACKLE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,18,POKEMON_TYRACROC,ITEM_ZAUBERWASSER,ATTACK_EISHIEB,ATTACK_KASKADE,ATTACK_KRATZER,ATTACK_DRACHENTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,16,POKEMON_BLANAS,ITEM_NONE,ATTACK_MOGELHIEB,ATTACK_FINTE,ATTACK_GIGASAUGER,ATTACK_SONDERSENSOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,18,POKEMON_KADABRA,ITEM_TSITRUBEERE,ATTACK_PSYSTRAHL,ATTACK_NONE,ATTACK_FOKUSSTOSS,ATTACK_ZAUBERSCHEIN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x24[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_WABLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x25[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_GRIFFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_NIDORANM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_KRAMURX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_DARTIRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_WABLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_BIBOR)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x29[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_STARALILI,ITEM_TSITRUBEERE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_SEEKID,ITEM_TSITRUBEERE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2a[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_STARALILI,ITEM_TSITRUBEERE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_LOCKSCHAL,ITEM_TSITRUBEERE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_STARALILI,ITEM_TSITRUBEERE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_WELUNO,ITEM_TSITRUBEERE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_FIFFYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_VOLTOBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_MAGNETILO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_BISAKNOSP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_MYRAPLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_KIRLIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x30[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_MEDITIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x31[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x32[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_ONIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x33[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_SKORGLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x34[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_TANNZA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_PHANPY)
};

trainer_pokemon_default_item_default_attacks trainer_party_x35[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_PORYGON_Z),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x36[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_FLABEBE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x37[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_BUMMELZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,9,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_KNILZ)
};

trainer_pokemon_default_item_default_attacks trainer_party_x38[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_WAATY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_SCHWALBINI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x39[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_SANDAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_SNUBBULL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_PINSIR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_VULPIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_ELEKTEK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_TUSKA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_KIRLIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_ULTRIGARIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_KNILZ)
};

trainer_pokemon_default_item_default_attacks trainer_party_x3f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_LORBLATT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x40[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_LOCKSCHAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_ULTRIGARIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_MAEHIKEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x41[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_NIDORINA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x42[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_KREBSCORPS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_KARPADOR)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x43[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_PUDOX,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_PAPINELLA,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_IGNIVOR,ITEM_TSITRUBEERE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x44[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_GOLBAT,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_KRAMURX,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_SCHLUPPUCK,ITEM_NONE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x45[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_VULPIX,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_STARAVIA,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_FRIZELBLIZ,ITEM_NONE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x46[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_SPOINK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_WAATY)
};

trainer_pokemon_default_item_default_attacks trainer_party_x47[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_KAUMALAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_WABLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x48[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_PUPPANCE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x49[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NIDORINO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x4a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x4b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NIDORINA)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x4c[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x5,0x0,true,false,24,POKEMON_EVOLI,ITEM_BLENDPUDER,ATTACK_LICHTSCHILD,ATTACK_DOPPELTEAM,ATTACK_REFLEKTOR,ATTACK_FRUSTRATION),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,26,POKEMON_GARADOS,ITEM_TSITRUBEERE,ATTACK_DRACHENTANZ,ATTACK_BISS,ATTACK_NASSCHWEIF,ATTACK_EISZAHN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,28,POKEMON_VIPITIS,ITEM_PRUNUSBEERE,ATTACK_GIFTSCHWEIF,ATTACK_EISENSCHWEIF,ATTACK_NACHTHIEB,ATTACK_NASSCHWEIF)
};

trainer_pokemon_default_item_default_attacks trainer_party_x4d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_STOLLUNIOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x4e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_MAGNAYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x4f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_NIDORINA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x50[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KLEINSTEIN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x51[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_SNUBBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_SCHWALBINI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x52[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_GEOROK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x53[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_DARTIGNIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x54[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_NOCKCHAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KICKLEE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x55[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_LOMBRERO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x56[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x6,0x0,true,false,24,POKEMON_SCHLURP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x6,0x0,true,false,24,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x6,0x0,true,false,23,POKEMON_WATTZAPF)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x57[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_AERODACTYL,ITEM_NONE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x58[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_DIGDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SKORGLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x59[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RESLADERO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x5a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_TUSKA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_ZOBIRIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x5b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_ENEKORO)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x5c[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_STARAVIA,ITEM_NONE,ATTACK_STAHLFLUEGEL,ATTACK_AERO_ASS,ATTACK_NOTSITUATION,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,30,POKEMON_SEESKULL,ITEM_TSITRUBEERE,ATTACK_DRACHENTANZ,ATTACK_NASSCHWEIF,ATTACK_EISENSCHWEIF,ATTACK_GIFTSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,29,POKEMON_DUFLOR,ITEM_SINELBEERE,ATTACK_SCHLAFPUDER,ATTACK_ENERGIEBALL,ATTACK_MATSCHBOMBE,ATTACK_SYNTHESE)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x5d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_STARAVIA,ITEM_NONE,ATTACK_STAHLFLUEGEL,ATTACK_AERO_ASS,ATTACK_NOTSITUATION,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,30,POKEMON_STICHSCHAL,ITEM_TSITRUBEERE,ATTACK_LAUBKLINGE,ATTACK_FLUCH,ATTACK_ZORNKLINGE,ATTACK_GEDULD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,29,POKEMON_FUKANO,ITEM_NONE,ATTACK_BISS,ATTACK_FEUERZAHN,ATTACK_NAHKAMPF,ATTACK_EISENSCHWEIF)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x5e[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_STARAVIA,ITEM_NONE,ATTACK_STAHLFLUEGEL,ATTACK_AERO_ASS,ATTACK_NOTSITUATION,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,30,POKEMON_ORTHODOS,ITEM_TSITRUBEERE,ATTACK_FLAMMENRAD,ATTACK_BISS,ATTACK_SCHAUFLER,ATTACK_EISENSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,29,POKEMON_TENTACHA,ITEM_NONE,ATTACK_MATSCHBOMBE,ATTACK_AQUAWELLE,ATTACK_ABSCHLAG,ATTACK_AURORASTRAHL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x5f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_TUSKA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_DIGDA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x60[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_ONIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x61[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_FEURIGEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_ABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_TRASLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_KUSSILLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x62[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_LOMBRERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_RIOLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x63[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_FLUNKIFER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x64[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_WABLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_RESLADERO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x65[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,27,POKEMON_EVOLI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,26,POKEMON_PIKACHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x66[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_WAATY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_VULNONA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x67[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_WEBARAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_LEDIAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x68[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SKORGRO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x69[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_FLEGMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_KIRLIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_NASGNET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_RIOLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_WABLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_LEDIAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_KANGAMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_DARTIGNIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MASKEREGEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_PERLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_MOGELBAUM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_PAPINELLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_VOLTENSO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x6f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_KAPILZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x70[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_ELEKTEK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x71[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_ULTRIGARIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_ENEKORO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x72[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x73[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KINDWURM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_RESLADERO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x74[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x75[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SCHWALBOSS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x76[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_SPOINK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_BRONZEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x77[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_PANDIR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x78[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x79[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1f,0x1,true,true,32,POKEMON_KICKLEE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MENKI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KREBSCORPS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_RIOLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GERADAKS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_TROPIUS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_PONITA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GEOROK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x7f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_PAPINELLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x80[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_MEDITIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x81[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SKARABORN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x82[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_RASAFF)
};

trainer_pokemon_default_item_default_attacks trainer_party_x83[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x84[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_SEEJONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_GRANBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_VULNONA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_HYPNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x85[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_BRONZEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x86[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_VOLTENSO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x87[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_ELEVOLTEK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_NOKTUSKA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x88[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_PAPINELLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SICHLOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x89[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_KRAMURX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_FORMEO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_NASGNET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_SCHLUPPUCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_SONNFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_LUNASTEIN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MEDITALIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_SHUPPET)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x8f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x90[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x91[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_FROSDEDJE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_LEPUMENTAS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x92[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GLUTEXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_CAMAUB)
};

trainer_pokemon_default_item_default_attacks trainer_party_x93[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MAGBY)
};

trainer_pokemon_default_item_default_attacks trainer_party_x94[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_VULPIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x95[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_SCHNECKMAG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_MAGMAR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_GEOROK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x96[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_HUNDEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x97[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_ORTHODOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_MAGNETON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x98[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_ARKANI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_GRANBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_PANZAERON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x99[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_FUKANO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SCHNECKMAG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_FUKANO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_PAPINELLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_CAMERUPT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_NIDOQUEEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_MEDITALIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_ENEKORO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x9f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_NIDORANW),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_PANDIR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_FLUNKIFER)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SCHNECKMAG)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_DIGDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_PUPPANCE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_ORTHODOS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SPOINK)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MAGNAYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_NIDORINA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_xa7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,27,POKEMON_LATERNECTO,ATTACK_NITROLADUNG,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x2,0x1,false,false,108,POKEMON_POKEMON_0,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_STOLLRAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_xa9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_URSARING),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_XATU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_SEESKULL)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_xaa[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,60,POKEMON_GROUDON, ITEM_MAGMAHERZ,ATTACK_FEUERSTURM,ATTACK_ERDBEBEN,ATTACK_SOLARSTRAHL,ATTACK_HYPERSTRAHL)
};

trainer_pokemon_default_item_default_attacks trainer_party_xab[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GLUTEXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_ORTHODOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_MAGMAR)
};

trainer_pokemon_default_item_default_attacks trainer_party_xac[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SCHNECKMAG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_CAMAUB)
};

trainer_pokemon_default_item_default_attacks trainer_party_xad[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_SPOINK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_BRONZEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_xae[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_TENTOXA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_AMPHAROS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_NOKTUSKA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xaf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_LEPUMENTAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_DUOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_SLEIMA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MAGNETON)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_NIDOQUEEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_HUNDEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_IKSBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_GALAGLADI)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_TENTOXA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_SEEDRAKING)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GALLOPA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_KRAMSHEF)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_TENTOXA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_WAILMER)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_BARSCHWA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_FLEGMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xb9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_RIOLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_xba[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_AZUMARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_LIEBISKUS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_SEEMOPS)
};

trainer_pokemon_default_item_custom_attacks trainer_party_xbb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,35,POKEMON_GEOROK,ATTACK_INTENSITAET,ATTACK_STEINWURF,ATTACK_LEHMSUHLER,ATTACK_EINIGLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,35,POKEMON_ONIX,ATTACK_HAERTNER,ATTACK_STEINWURF,ATTACK_KLAMMERGRIFF,ATTACK_KREIDESCHREI)
};

trainer_pokemon_default_item_default_attacks trainer_party_xbc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GARADOS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xbd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_DRATINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_DRAGONIR)
};

trainer_pokemon_default_item_default_attacks trainer_party_xbe[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_SEEDRAKING)
};

trainer_pokemon_default_item_default_attacks trainer_party_xbf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_ARKANI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_MAGCARGO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_CAMERUPT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_MAGMAR)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_BANETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_ZWIRRKLOP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_KRYPPUK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GLUMANDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_WELUNO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_FEURIGEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SCHNECKMAG)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_ZWIRRLICHT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_KRAMSHEF)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_KRAMSHEF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_SMOGMOG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_VIPITIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_ZWIRRLICHT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_KRAMSHEF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_SMOGMOG)
};

trainer_pokemon_default_item_default_attacks trainer_party_xc8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ZWIRRKLOP)
};

trainer_pokemon_custom_item_default_attacks trainer_party_xc9[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_MAGNAYEN,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_IKSBAT,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x1f,0x1,true,true,43,POKEMON_FROSDEDJE,ITEM_TSITRUBEERE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xca[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_SMOGMOG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_SMOGMOG)
};

trainer_pokemon_default_item_default_attacks trainer_party_xcb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_HYPNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xcc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_xcd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_HYPNO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_GERADAKS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xce[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_QUABBEL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_xcf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_SLEIMA,ATTACK_KREIDESCHREI,ATTACK_KOMPRIMATOR,ATTACK_SCHLAMMBAD,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_xd0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SLEIMA,ATTACK_KREIDESCHREI,ATTACK_KOMPRIMATOR,ATTACK_SCHLAMMBAD,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SLEIMA,ATTACK_KREIDESCHREI,ATTACK_KOMPRIMATOR,ATTACK_SCHLAMMBAD,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_xd1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,29,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,29,POKEMON_SLEIMOK,ATTACK_KREIDESCHREI,ATTACK_KOMPRIMATOR,ATTACK_SCHLAMMBAD,ATTACK_AUSSETZER)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RABAUZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_SKARABORN)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RIOLU)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_VULNONA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_PONITA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_FUKANO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GLUMANDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GLUTEXO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xd9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,44,POKEMON_TOGEKISS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xda[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ZWIRRLICHT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_SHUPPET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xdb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_BANETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,40,POKEMON_GENGAR)
};

trainer_pokemon_default_item_default_attacks trainer_party_xdc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,40,POKEMON_ZWIRRKLOP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_ALPOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_QUABBEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_xdd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,43,POKEMON_SIMSALA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xde[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_SHUPPET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_BANETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,40,POKEMON_MAGNETON)
};

trainer_pokemon_default_item_default_attacks trainer_party_xdf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,40,POKEMON_ALPOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,40,POKEMON_ZWIRRLICHT)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_xe0[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,41,POKEMON_APOQUALLYP,ITEM_NONE,ATTACK_SURFER,ATTACK_SPUKBALL,ATTACK_GENESUNG,ATTACK_IRRLICHT),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,42,POKEMON_STARAPTOR,ITEM_NONE,ATTACK_STURZFLUG,ATTACK_NAHKAMPF,ATTACK_BODYCHECK,ATTACK_STAHLFLUEGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_ZERBERTRES,ITEM_TSITRUBEERE,ATTACK_HITZEKOLLER,ATTACK_SPUKBALL,ATTACK_NONE,ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,39,POKEMON_MEGANIE,ITEM_NONE,ATTACK_GIGASAUGER,ATTACK_SYNTHESE,ATTACK_LICHTSCHILD,ATTACK_REFLEKTOR)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_xe1[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,41,POKEMON_KOKOWEI,ITEM_NONE,ATTACK_NONE,ATTACK_GIGASAUGER,ATTACK_REFLEKTOR,ATTACK_SYNTHESE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,42,POKEMON_STARAPTOR,ITEM_NONE,ATTACK_STURZFLUG,ATTACK_NAHKAMPF,ATTACK_BODYCHECK,ATTACK_STAHLFLUEGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_SKULLYDRA,ITEM_TSITRUBEERE,ATTACK_SURFER,ATTACK_EISSTRAHL,ATTACK_NONE,ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,39,POKEMON_TORNUPTO,ITEM_NONE,ATTACK_HITZEKOLLER,ATTACK_FLAMMENWURF,ATTACK_SOLARSTRAHL,ATTACK_FOKUSSTOSS)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_xe2[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,41,POKEMON_VULNONA,ITEM_NONE,ATTACK_SONNENTAG,ATTACK_SOLARSTRAHL,ATTACK_HITZEKOLLER,ATTACK_FLAMMENWURF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,42,POKEMON_STARAPTOR,ITEM_NONE,ATTACK_STURZFLUG,ATTACK_NAHKAMPF,ATTACK_BODYCHECK,ATTACK_STAHLFLUEGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_STAHLSTICH,ITEM_TSITRUBEERE,ATTACK_NADELRAKETE,ATTACK_ERDBEBEN,ATTACK_NAHKAMPF,ATTACK_STAHLSTREICH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,39,POKEMON_IMPERGATOR,ITEM_NONE,ATTACK_DRACHENTANZ,ATTACK_ERDBEBEN,ATTACK_EISHIEB,ATTACK_KASKADE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,0,POKEMON_POKEMON_0),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,0,POKEMON_POKEMON_0)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,0,POKEMON_POKEMON_0),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,0,POKEMON_ALPOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ZWIRRKLOP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_BANETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_ZWIRRLICHT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_SHUPPET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_NEBULAK)
};

trainer_pokemon_custom_item_default_attacks trainer_party_xe6[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,10,POKEMON_BIBOR,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,11,POKEMON_BIBOR,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,12,POKEMON_BIBOR,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_BIBOR,ITEM_TSITRUBEERE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KARPADOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_QUABBEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_xe9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KARPADOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_xea[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MUSCHAS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xeb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_MUSCHAS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xec[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STERNDU)
};

trainer_pokemon_default_item_default_attacks trainer_party_xed[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_DUOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_xee[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_QUABBEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_xef[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MUSCHAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SEEPER)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_TENTOXA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_MUSCHAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_AUSTOS)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_STERNDU)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SEEPER)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_TENTOXA)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_xf9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xfa[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xfb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_xfc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_RASAFF)
};

trainer_pokemon_default_item_default_attacks trainer_party_xfd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MACHOMEI)
};

trainer_pokemon_default_item_default_attacks trainer_party_xfe[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_xff[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MACHOMEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x100[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x101[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_TENTOXA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x102[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_SEEPER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x103[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_MYRAPLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x104[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_VOLTOBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_MAGNETILO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x105[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_VULPIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x106[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_DUOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_x107[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x108[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_VULPIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x109[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_KNOFENSA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KNOFENSA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_OWEI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_BRONZEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KASTADUR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x10f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_MUSCHAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_MUSCHAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_AUSTOS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x110[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x111[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KNUDDELUFF)
};

trainer_pokemon_default_item_default_attacks trainer_party_x112[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_BISASAM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_BISAKNOSP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x113[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_ULTRIGARIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_ULTRIGARIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x114[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_GRAMOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_x115[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x116[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STERNDU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x117[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x118[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,31,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,31,POKEMON_FLEGMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,31,POKEMON_TRAUNFUGIL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,31,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x119[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,34,POKEMON_TRAUNFUGIL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,34,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,33,POKEMON_FLEGMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,33,POKEMON_FLEGMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,33,POKEMON_LAHMUS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,38,POKEMON_LAHMUS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_VOLTOBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_VOLTOBAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_VOLTOBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_LEKTROBAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_TRAUNFUGIL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x11f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_HYPNO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,41,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x120[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_TRAUMATO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x121[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_HYPNO)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x122[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,48,POKEMON_TRAUNFUGIL,ATTACK_PSYCHOKINESE,ATTACK_ROLLENTAUSCH,ATTACK_DUPLEXHIEB,ATTACK_ZUGABE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x123[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_VOLTOBAL,ATTACK_STERNSCHAUER,ATTACK_LICHTSCHILD,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_VOLTOBAL,ATTACK_STERNSCHAUER,ATTACK_LICHTSCHILD,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,47,POKEMON_LEKTROBAL,ATTACK_STERNSCHAUER,ATTACK_FUNKENSPRUNG,ATTACK_FINALE,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,48,POKEMON_TRAUNFUGIL,ATTACK_PSYCHOKINESE,ATTACK_ROLLENTAUSCH,ATTACK_REFLEKTOR,ATTACK_ZUGABE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x124[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_HYPNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x125[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x126[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,34,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,34,POKEMON_TROMBORK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x127[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,33,POKEMON_TROMBORK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,33,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,33,POKEMON_TROMBORK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x128[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,43,POKEMON_RIHORN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x129[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,39,POKEMON_TROMBORK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,39,POKEMON_TAUROS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,44,POKEMON_TENTANTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,44,POKEMON_ENTORON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,42,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,42,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,42,POKEMON_TROMBORK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,42,POKEMON_TAUROS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_MAEHIKEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x12f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_PORENTA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x130[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x131[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_PORENTA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_STARALILI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x132[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_DODU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x133[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x134[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_DODRI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x135[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MAEHIKEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x136[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x137[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x138[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_PORENTA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,39,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x139[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x13a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x13b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x13c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_CHEVRUMM)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x13d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_KICKLEE,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x13e[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,31,POKEMON_MENKI,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,31,POKEMON_MENKI,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,31,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x13f[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,32,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,32,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x140[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,36,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x141[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,31,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,31,POKEMON_MENKI,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,31,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x142[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,40,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,40,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x143[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,43,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x144[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x145[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,43,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,43,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,43,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x146[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_WELUNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x147[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_SEEKID)
};

trainer_pokemon_default_item_default_attacks trainer_party_x148[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_LOCKSCHAL)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x149[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x7,0x0,false,false,20,POKEMON_BISAKNOSP,ITEM_TSITRUBEERE,ATTACK_SCHLAFPUDER,ATTACK_EGELSAMEN,ATTACK_SAEURE,ATTACK_ENERGIEBALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0xb,0x0,false,false,21,POKEMON_ORTHODOS,ITEM_TSITRUBEERE,ATTACK_GLUT,ATTACK_BISS,ATTACK_ZERSCHNEIDER,ATTACK_KRATZER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x2,0x0,false,false,20,POKEMON_KAUMALAT,ITEM_TSITRUBEERE,ATTACK_DRACHENWUT,ATTACK_SCHAUFLER,ATTACK_KRATZER,ATTACK_BODYCHECK)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x14a[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,20,POKEMON_GLUTEXO,ITEM_TSITRUBEERE,ATTACK_METALLKLAUE,ATTACK_FEUERSCHLAG,ATTACK_DRACHENTANZ,ATTACK_STEINHAGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x3,0x0,false,false,21,POKEMON_SEESKULL,ITEM_TSITRUBEERE,ATTACK_FINTE,ATTACK_AURORASTRAHL,ATTACK_AQUAWELLE,ATTACK_KONFUSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0xb,0x0,false,false,20,POKEMON_KINDWURM,ITEM_TSITRUBEERE,ATTACK_GLUT,ATTACK_TACKLE,ATTACK_KOPFNUSS,ATTACK_DRACHENKLAUE)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x14b[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x5,0x0,false,false,20,POKEMON_SCHILLOK,ITEM_TSITRUBEERE,ATTACK_AQUAWELLE,ATTACK_AURORASTRAHL,ATTACK_AURASPHAERE,ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0xc,0x0,false,false,21,POKEMON_STICHSCHAL,ITEM_TSITRUBEERE,ATTACK_LAUBKLINGE,ATTACK_NATUR_KRAFT,ATTACK_EISENABWEHR,ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0xd,0x0,false,false,19,POKEMON_DRATINI,ITEM_TSITRUBEERE,ATTACK_DONNERWELLE,ATTACK_DRACHENWUT,ATTACK_WINDHOSE,ATTACK_SURFER)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x14c[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x7,0x0,false,false,36,POKEMON_BISAFLOR,ITEM_NONE,ATTACK_SCHLAFPUDER,ATTACK_EGELSAMEN,ATTACK_SYNTHESE,ATTACK_ENERGIEBALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,35,POKEMON_AZUMARILL,ITEM_NONE,ATTACK_KNUDDLER,ATTACK_NASSCHWEIF,ATTACK_KRAFTKOLOSS,ATTACK_EISHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x3,0x0,false,false,38,POKEMON_ZERBERTRES,ITEM_TSITRUBEERE,ATTACK_ZORNFEUER,ATTACK_FINSTERAURA,ATTACK_SONDERSENSOR,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x2,0x0,false,false,37,POKEMON_KNARKSEL,ITEM_NONE,ATTACK_TACKLE,ATTACK_DRACHENKLAUE,ATTACK_STEINHAGEL,ATTACK_SCHLITZER)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x14d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,36,POKEMON_GLURAK,ITEM_NONE,ATTACK_FLAMMENWURF,ATTACK_FLIEGEN,ATTACK_STEINHAGEL,ATTACK_DUNKELKLAUE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x7,0x0,false,false,35,POKEMON_KOKOWEI,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_REFLEKTOR,ATTACK_LICHTSCHILD,ATTACK_ENERGIEBALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x3,0x0,false,false,38,POKEMON_SKULLYDRA,ITEM_TSITRUBEERE,ATTACK_TSUNAMI,ATTACK_DRACHENPULS,ATTACK_FINSTERAURA,ATTACK_EISENSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,37,POKEMON_DRASCHEL,ITEM_NONE,ATTACK_DRACHENKLAUE,ATTACK_SCHUTZSCHILD,ATTACK_BODYCHECK,ATTACK_GLUT)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x14e[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0xc,0x0,false,false,36,POKEMON_TURTOK,ITEM_NONE,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_SCHAEDELWUMME,ATTACK_AURASPHAERE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,38,POKEMON_STAHLSTICH,ITEM_TSITRUBEERE,ATTACK_SAMENBOMBE,ATTACK_STAHLSTREICH,ATTACK_SCHLITZER,ATTACK_SCHWERTTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x2,0x0,false,false,35,POKEMON_MAGMAR,ITEM_NONE,ATTACK_FLAMMENWURF,ATTACK_KONFUSTRAHL,ATTACK_FOKUSSTOSS,ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0xd,0x0,false,false,37,POKEMON_DRAGONIR,ITEM_NONE,ATTACK_DONNERWELLE,ATTACK_DONNERBLITZ,ATTACK_DRACHENPULS,ATTACK_SURFER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x14f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_PONITA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_MAGMAR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x150[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GLUTEXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GLUTEXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_GLUTEXO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x151[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_GLURAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x152[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_IGELAVAR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_TORNUPTO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x153[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_TORNUPTO)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x154[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,37,POKEMON_GALLOPA,ATTACK_FLAMMENWURF,ATTACK_FEUERWIRBEL,ATTACK_TURBOTEMPO,ATTACK_GLUT)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x155[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,25,POKEMON_VOLTOBAL,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL,ATTACK_KREIDESCHREI,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,25,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,25,POKEMON_MAGNETON,ATTACK_DONNERWELLE,ATTACK_ULTRASCHALL,ATTACK_SUPERSCHALL,ATTACK_DONNERSCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,25,POKEMON_MAGNETILO,ATTACK_DONNERWELLE,ATTACK_ULTRASCHALL,ATTACK_SUPERSCHALL,ATTACK_DONNERSCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,25,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_FINALE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x156[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_LEKTROBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x157[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SLEIMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_LEKTROBAL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x158[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_VOLTOBAL,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL,ATTACK_KREIDESCHREI,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_TACKLE,ATTACK_SMOG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_MAGNETON,ATTACK_FUNKENSPRUNG,ATTACK_DONNERWELLE,ATTACK_ULTRASCHALL,ATTACK_SUPERSCHALL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x159[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SMOGON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x15a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_VOLTOBAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x15b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_LEKTROBAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x15c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,25,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,24,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,29,POKEMON_KANGAMA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x15d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,37,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,35,POKEMON_KANGAMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,37,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x1,true,true,41,POKEMON_NIDOQUEEN)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x15e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,45,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_FELSWURF,ATTACK_GRIMASSE,ATTACK_ERDBEBEN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,42,POKEMON_DIGDRI,ATTACK_SCHLITZER,ATTACK_SANDGRAB,ATTACK_LEHMSCHELLE,ATTACK_ERDBEBEN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,44,POKEMON_NIDOQUEEN,ATTACK_BODYSLAM,ATTACK_DOPPELKICK,ATTACK_GIFTSTACHEL,ATTACK_ERDBEBEN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,45,POKEMON_NIDOKING,ATTACK_FUCHTLER,ATTACK_DOPPELKICK,ATTACK_GIFTSTACHEL,ATTACK_ERDBEBEN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,50,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_FELSWURF,ATTACK_GRIMASSE,ATTACK_ERDBEBEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x15f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x160[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x161[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_KANIVANHA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x162[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_SANDAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x163[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_TRAUMATO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x164[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x165[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_FIFFYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x166[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x167[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_SLEIMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_GLAZIOLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x168[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_FIFFYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x169[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_FIFFYEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x16a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_GLAZIOLA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x16b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,17,POKEMON_ZUBAT,ATTACK_BISS,ATTACK_ERSTAUNER,ATTACK_SUPERSCHALL,ATTACK_BLUTSAUGER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,17,POKEMON_SMOGON,ATTACK_SMOG,ATTACK_TACKLE,ATTACK_GIFTWOLKE,ATTACK_NONE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,17,POKEMON_SLEIMA,ATTACK_SCHLAMMBAD,ATTACK_AUSSETZER,ATTACK_HAERTNER,ATTACK_PFUND),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,17,POKEMON_ZUBAT,ATTACK_BISS,ATTACK_ERSTAUNER,ATTACK_SUPERSCHALL,ATTACK_BLUTSAUGER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,17,POKEMON_BRONZONG,ATTACK_HYPERZAHN,ATTACK_RUCKZUCKHIEB,ATTACK_RUTENSCHLAG,ATTACK_TACKLE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x16c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_TRAUMATO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x16d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x16e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_ZIGZACHS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x16f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x170[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x171[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_GLAZIOLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x172[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_TRAUMATO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x173[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,16,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,15,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_SPOINK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x174[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_SMOGON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x175[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_GLAZIOLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x176[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,21,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_VIPITIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x177[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_HYPNO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x178[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_TRAUMATO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x179[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_TRAGOSSO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x17a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_TROMBORK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x17b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_HYPNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x17c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x17d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x17e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_BRONZONG,ATTACK_GRIMASSE,ATTACK_HYPERZAHN,ATTACK_RUCKZUCKHIEB,ATTACK_RUTENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_TROMBORK,ATTACK_GIFTBLICK,ATTACK_BISS,ATTACK_GIFTSTACHEL,ATTACK_SILBERBLICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_GOLBAT,ATTACK_FLUEGELSCHLAG,ATTACK_BISS,ATTACK_ERSTAUNER,ATTACK_SUPERSCHALL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x17f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_TRAGOSSO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_TRAGOSSO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x180[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SANDAMER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x181[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,26,POKEMON_BRONZEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x182[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGMOG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x183[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SLEIMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MACHOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x184[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_HYPNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x185[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x186[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,25,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x187[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_TRAGOSSO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,32,POKEMON_KNOGGA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x188[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,37,POKEMON_SANDAMER,ATTACK_SCHLITZER,ATTACK_STERNSCHAUER,ATTACK_SANDWIRBEL,ATTACK_GIFTSTACHEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,37,POKEMON_SANDAMER,ATTACK_SCHLITZER,ATTACK_STERNSCHAUER,ATTACK_SANDWIRBEL,ATTACK_GIFTSTACHEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_FELSWURF,ATTACK_FURIENSCHLAG,ATTACK_GRIMASSE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,39,POKEMON_NIDORINO,ATTACK_FURIENSCHLAG,ATTACK_HORNATTACKE,ATTACK_GIFTSTACHEL,ATTACK_DOPPELKICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,39,POKEMON_NIDOKING,ATTACK_FUCHTLER,ATTACK_DOPPELKICK,ATTACK_GIFTSTACHEL,ATTACK_ENERGIEFOKUS)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x189[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_KOKOWEI,ATTACK_EIERBOMBE,ATTACK_KONFUSION,ATTACK_STACHELSPORE,ATTACK_SCHLAFPUDER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_SANDAMER,ATTACK_KRATZFURIE,ATTACK_STERNSCHAUER,ATTACK_GIFTSTACHEL,ATTACK_SANDWIRBEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_AUSTOS,ATTACK_DORNKANONE,ATTACK_STACHLER,ATTACK_AURORASTRAHL,ATTACK_SUPERSCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_LEKTROBAL,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL,ATTACK_KREIDESCHREI,ATTACK_LICHTSCHILD),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_ARKANI,ATTACK_FLAMMENRAD,ATTACK_BRUELLER,ATTACK_BISS,ATTACK_BODYCHECK)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x18a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,41,POKEMON_KINGLER,ATTACK_GUILLOTINE,ATTACK_STAMPFER,ATTACK_LEHMSCHUSS,ATTACK_BLUBBER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_DUOKLES,ATTACK_BODYSLAM,ATTACK_DUPLEXHIEB,ATTACK_AQUAKNARRE,ATTACK_HYPNOSE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_TENTOXA,ATTACK_BARRIERE,ATTACK_WICKEL,ATTACK_BLUBBSTRAHL,ATTACK_SAEURE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_SEEMON,ATTACK_AQUAKNARRE,ATTACK_RAUCHWOLKE,ATTACK_WINDHOSE,ATTACK_SILBERBLICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,43,POKEMON_TURTOK,ATTACK_AQUAKNARRE,ATTACK_BISS,ATTACK_TURBODREHER,ATTACK_REGENTANZ)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x18b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_FLEGMON,ATTACK_KOPFNUSS,ATTACK_KONFUSION,ATTACK_AQUAKNARRE,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_MUSCHAS,ATTACK_AURORASTRAHL,ATTACK_SCHNAPPER,ATTACK_SUPERSCHALL,ATTACK_SILBERBLICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_KINGLER,ATTACK_GUILLOTINE,ATTACK_STAMPFER,ATTACK_LEHMSCHUSS,ATTACK_BLUBBER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_STARMIE,ATTACK_BLUBBSTRAHL,ATTACK_STERNSCHAUER,ATTACK_GENESUNG,ATTACK_TURBODREHER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_ENTORON,ATTACK_KONFUSION,ATTACK_KRATZER,ATTACK_KREIDESCHREI,ATTACK_AUSSETZER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x18c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_BRONZONG,ATTACK_SUPERZAHN,ATTACK_VERFOLGUNG,ATTACK_GRIMASSE,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_BISAKNOSP,ATTACK_RASIERBLATT,ATTACK_SCHLAFPUDER,ATTACK_LOCKDUFT,ATTACK_SYNTHESE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_SCHILLOK,ATTACK_AQUAKNARRE,ATTACK_BISS,ATTACK_TURBODREHER,ATTACK_RUTENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_GLUTEXO,ATTACK_FLAMMENWURF,ATTACK_SCHLITZER,ATTACK_RAUCHWOLKE,ATTACK_GRIMASSE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_GLURAK,ATTACK_FLAMMENWURF,ATTACK_FLUEGELSCHLAG,ATTACK_RAUCHWOLKE,ATTACK_GRIMASSE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x18d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_STARAVIA,ATTACK_FLUEGELSCHLAG,ATTACK_DAUNENREIGEN,ATTACK_WIRBELWIND,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_CHEVRUMM,ATTACK_BOHRSCHNABEL,ATTACK_SPIEGELTRICK,ATTACK_VERFOLGUNG,ATTACK_SILBERBLICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_TENTANTEL,ATTACK_ZAHLTAG,ATTACK_FINTE,ATTACK_KREIDESCHREI,ATTACK_BISS),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_SCHLURP,ATTACK_SLAM,ATTACK_AUSSETZER,ATTACK_WICKEL,ATTACK_SUPERSCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_TAUROS,ATTACK_HORNATTACKE,ATTACK_GRIMASSE,ATTACK_ANGEBEREI,ATTACK_RUTENSCHLAG)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x18e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_NIDORINO,ATTACK_KRATZER,ATTACK_GIFTSTACHEL,ATTACK_DOPPELKICK,ATTACK_BISS),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_NIDORINA,ATTACK_HORNATTACKE,ATTACK_GIFTSTACHEL,ATTACK_DOPPELKICK,ATTACK_SILBERBLICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_BRONZONG,ATTACK_SUPERZAHN,ATTACK_VERFOLGUNG,ATTACK_GRIMASSE,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_SANDAMER,ATTACK_KRATZFURIE,ATTACK_STERNSCHAUER,ATTACK_SCHLITZER,ATTACK_GIFTSTACHEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_RIHORN,ATTACK_FELSWURF,ATTACK_GRIMASSE,ATTACK_STAMPFER,ATTACK_RUTENSCHLAG)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x18f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_JUROB,ATTACK_BODYCHECK,ATTACK_AURORASTRAHL,ATTACK_EISSTURM,ATTACK_HEULER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_GEOROK,ATTACK_FELSWURF,ATTACK_INTENSITAET,ATTACK_STEINWURF,ATTACK_LEHMSUHLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_KINGLER,ATTACK_GUILLOTINE,ATTACK_STAMPFER,ATTACK_LEHMSCHUSS,ATTACK_BLUBBER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_ONIX,ATTACK_SLAM,ATTACK_SANDSTURM,ATTACK_FEUERODEM,ATTACK_STEINWURF),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_AUSTOS,ATTACK_DORNKANONE,ATTACK_AURORASTRAHL,ATTACK_SUPERSCHALL,ATTACK_SCHUTZSCHILD)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x190[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_SANDAMER,ATTACK_SCHLITZER,ATTACK_STERNSCHAUER,ATTACK_SANDWIRBEL,ATTACK_GIFTSTACHEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_GEOROK,ATTACK_FELSWURF,ATTACK_INTENSITAET,ATTACK_LEHMSUHLER,ATTACK_EINIGLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_ONIX,ATTACK_FEUERODEM,ATTACK_SANDSTURM,ATTACK_STEINWURF,ATTACK_KLAMMERGRIFF),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_GEOROK,ATTACK_FELSWURF,ATTACK_INTENSITAET,ATTACK_WALZER,ATTACK_EINIGLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_KNOGGA,ATTACK_KNOCHMERANG,ATTACK_KOPFNUSS,ATTACK_SILBERBLICK,ATTACK_HEULER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x191[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,37,POKEMON_KNOGGA,ATTACK_KNOCHMERANG,ATTACK_KOPFNUSS,ATTACK_SILBERBLICK,ATTACK_HEULER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,37,POKEMON_KNOGGA,ATTACK_KNOCHMERANG,ATTACK_KOPFNUSS,ATTACK_SILBERBLICK,ATTACK_HEULER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,38,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_FELSWURF,ATTACK_FURIENSCHLAG,ATTACK_GRIMASSE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,39,POKEMON_NIDORINA,ATTACK_KRATZFURIE,ATTACK_BISS,ATTACK_GIFTSTACHEL,ATTACK_DOPPELKICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,39,POKEMON_NIDOQUEEN,ATTACK_BODYSLAM,ATTACK_BISS,ATTACK_GIFTSTACHEL,ATTACK_DOPPELKICK)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x192[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,22,POKEMON_KNOFENSA,ATTACK_WICKEL,ATTACK_STACHELSPORE,ATTACK_GIFTPUDER,ATTACK_WACHSTUM),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,22,POKEMON_MYRAPLA,ATTACK_GIFTPUDER,ATTACK_STACHELSPORE,ATTACK_ABSORBER,ATTACK_LOCKDUFT),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,22,POKEMON_ULTRIGARIA,ATTACK_RANKENHIEB,ATTACK_STACHELSPORE,ATTACK_GIFTPUDER,ATTACK_WACHSTUM),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,22,POKEMON_DUFLOR,ATTACK_ABSORBER,ATTACK_STACHELSPORE,ATTACK_GIFTPUDER,ATTACK_LOCKDUFT),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,22,POKEMON_BISAKNOSP,ATTACK_RASIERBLATT,ATTACK_SCHLAFPUDER,ATTACK_RANKENHIEB,ATTACK_EGELSAMEN)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x193[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_KNOFENSA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_STACHELSPORE,ATTACK_GIFTPUDER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_ULTRIGARIA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_SCHLAFPUDER,ATTACK_GIFTPUDER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_SARZENIA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_STACHELSPORE,ATTACK_SCHLAFPUDER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_FOLIPURBA,ATTACK_WACHSTUM,ATTACK_SCHLITZER,ATTACK_BLUTSAUGER,ATTACK_STACHELSPORE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_FEELINARA,ATTACK_PILZSPORE,ATTACK_SCHLITZER,ATTACK_BLUTSAUGER,ATTACK_GIFTPUDER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x194[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_FLOETTE,ATTACK_LICHTSCHILD,ATTACK_KOSMIK_KRAFT,ATTACK_DUPLEXHIEB,ATTACK_ZUGABE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_PUMMELUFF,ATTACK_GESANG,ATTACK_BODYSLAM,ATTACK_WALZER,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_TENTANTEL,ATTACK_ZAHLTAG,ATTACK_FINTE,ATTACK_BISS,ATTACK_KREIDESCHREI),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_JUGONG,ATTACK_EISESKAELTE,ATTACK_BODYCHECK,ATTACK_ERHOLUNG,ATTACK_AURORASTRAHL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_CHANEIRA,ATTACK_GESANG,ATTACK_EIERBOMBE,ATTACK_WEICHEI,ATTACK_KOMPRIMATOR)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x195[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_BIBOR,ATTACK_NADELRAKETE,ATTACK_DUONADEL,ATTACK_AGILITAET,ATTACK_VERFOLGUNG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_FIARO,ATTACK_BODYGUARD,ATTACK_PSYSTRAHL,ATTACK_WINDSTOSS,ATTACK_SUPERSCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_FEELINARA,ATTACK_PILZSPORE,ATTACK_BLUTSAUGER,ATTACK_SCHLITZER,ATTACK_WACHSTUM),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_WATTZAPF,ATTACK_PSYSTRAHL,ATTACK_STACHELSPORE,ATTACK_BLUTSAUGER,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_VOLTULA,ATTACK_PSYSTRAHL,ATTACK_WINDSTOSS,ATTACK_SUPERSCHALL,ATTACK_BLUTSAUGER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x196[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_TENTANTEL,ATTACK_KRATZFURIE,ATTACK_KREIDESCHREI,ATTACK_FINTE,ATTACK_ZAHLTAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_PONITA,ATTACK_AGILITAET,ATTACK_BODYCHECK,ATTACK_FEUERWIRBEL,ATTACK_STAMPFER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_GALLOPA,ATTACK_FURIENSCHLAG,ATTACK_FEUERWIRBEL,ATTACK_STAMPFER,ATTACK_HEULER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_VULPIX,ATTACK_FLAMMENWURF,ATTACK_KONFUSTRAHL,ATTACK_RUCKZUCKHIEB,ATTACK_BEGRENZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_VULNONA,ATTACK_BODYGUARD,ATTACK_IRRLICHT,ATTACK_KONFUSTRAHL,ATTACK_FEUERWIRBEL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x197[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_ZOBIRIS,ATTACK_SLAM,ATTACK_KLAMMERGRIFF,ATTACK_MEGASAUGER,ATTACK_VERWURZLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_DUFLOR,ATTACK_SAEURE,ATTACK_MONDSCHEIN,ATTACK_SCHLAFPUDER,ATTACK_STACHELSPORE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_GIFLOR,ATTACK_MEGASAUGER,ATTACK_SAEURE,ATTACK_STACHELSPORE,ATTACK_AROMAKUR),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_BISAKNOSP,ATTACK_RASIERBLATT,ATTACK_LOCKDUFT,ATTACK_HEULER,ATTACK_EGELSAMEN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_BISAFLOR,ATTACK_RASIERBLATT,ATTACK_WACHSTUM,ATTACK_SCHLAFPUDER,ATTACK_GIFTPUDER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x198[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_RIHORN,ATTACK_HORNBOHRER,ATTACK_FELSWURF,ATTACK_GRIMASSE,ATTACK_STAMPFER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_NIDORINA,ATTACK_DOPPELKICK,ATTACK_KRATZFURIE,ATTACK_BISS,ATTACK_SCHMEICHLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_NIDOQUEEN,ATTACK_BODYSLAM,ATTACK_DOPPELKICK,ATTACK_BISS,ATTACK_HEULER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_NIDORINO,ATTACK_HORNATTACKE,ATTACK_GIFTSTACHEL,ATTACK_ENERGIEFOKUS,ATTACK_SILBERBLICK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_NIDOKING,ATTACK_FUCHTLER,ATTACK_DOPPELKICK,ATTACK_GIFTSTACHEL,ATTACK_SCHNABEL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x199[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_TENTANTEL,ATTACK_KRATZFURIE,ATTACK_BISS,ATTACK_KREIDESCHREI,ATTACK_FINTE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_VULNONA,ATTACK_FLAMMENWURF,ATTACK_IRRLICHT,ATTACK_KONFUSTRAHL,ATTACK_NACHSPIEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_GALLOPA,ATTACK_FURIENSCHLAG,ATTACK_FEUERWIRBEL,ATTACK_BODYCHECK,ATTACK_AGILITAET),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_PIKACHU,ATTACK_DONNERBLITZ,ATTACK_DONNERWELLE,ATTACK_DOPPELTEAM,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,42,POKEMON_RAICHU,ATTACK_DONNER,ATTACK_DONNERWELLE,ATTACK_SLAM,ATTACK_DOPPELTEAM)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x19a[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,52,POKEMON_JUGONG,ITEM_NONE,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_HAGELSTURM,ATTACK_BODYGUARD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,51,POKEMON_AUSTOS,ITEM_NONE,ATTACK_STACHLER,ATTACK_SCHUTZSCHILD,ATTACK_HAGELSTURM,ATTACK_TAUCHER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,52,POKEMON_LAHMUS,ITEM_NONE,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_AMNESIE,ATTACK_GAEHNER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_GALAGLADI,ITEM_NONE,ATTACK_EISHIEB,ATTACK_DUPLEXHIEB,ATTACK_TODESKUSS,ATTACK_ANZIEHUNG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_LAPRAS,ITEM_TSITRUBEERE,ATTACK_KONFUSTRAHL,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_BODYSLAM)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x19b[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,51,POKEMON_ONIX,ITEM_NONE,ATTACK_ERDBEBEN,ATTACK_FELSGRAB,ATTACK_EISENSCHWEIF,ATTACK_BRUELLER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,53,POKEMON_NOCKCHAN,ITEM_NONE,ATTACK_HIMMELHIEB,ATTACK_TEMPOHIEB,ATTACK_FELSGRAB,ATTACK_KONTER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,53,POKEMON_KICKLEE,ITEM_NONE,ATTACK_MEGAKICK,ATTACK_GESICHTE,ATTACK_DURCHBRUCH,ATTACK_FASSADE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_ONIX,ITEM_NONE,ATTACK_RISIKOTACKLE,ATTACK_ERDBEBEN,ATTACK_EISENSCHWEIF,ATTACK_SANDGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,56,POKEMON_MACHOMEI,ITEM_TSITRUBEERE,ATTACK_KREUZHIEB,ATTACK_PROTZER,ATTACK_GRIMASSE,ATTACK_FELSGRAB)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x19c[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_GENGAR,ITEM_NONE,ATTACK_FINSTERFAUST,ATTACK_KONFUSTRAHL,ATTACK_TOXIN,ATTACK_DOPPELTEAM),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_GOLBAT,ITEM_NONE,ATTACK_KONFUSTRAHL,ATTACK_GIFTZAHN,ATTACK_WINDSCHNITT,ATTACK_BISS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,53,POKEMON_ALPOLLO,ITEM_NONE,ATTACK_HYPNOSE,ATTACK_TRAUMFRESSER,ATTACK_FLUCH,ATTACK_HORRORBLICK),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,56,POKEMON_TROMBORK,ITEM_NONE,ATTACK_MATSCHBOMBE,ATTACK_KREIDESCHREI,ATTACK_EISENSCHWEIF,ATTACK_BISS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,58,POKEMON_GENGAR,ITEM_TSITRUBEERE,ATTACK_SPUKBALL,ATTACK_MATSCHBOMBE,ATTACK_HYPNOSE,ATTACK_NACHTMAHR)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x19d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,56,POKEMON_GARADOS,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_DRACHENWUT,ATTACK_WINDHOSE,ATTACK_BISS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_DRAGONIR,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_BODYGUARD,ATTACK_DRACHENWUT,ATTACK_WUTANFALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,54,POKEMON_DRAGONIR,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_BODYGUARD,ATTACK_DONNERWELLE,ATTACK_WUTANFALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,58,POKEMON_AERODACTYL,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_ANTIK_KRAFT,ATTACK_FLUEGELSCHLAG,ATTACK_GRIMASSE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,60,POKEMON_DRAGORAN,ITEM_TSITRUBEERE,ATTACK_HYPERSTRAHL,ATTACK_BODYGUARD,ATTACK_WUTANFALL,ATTACK_FLUEGELSCHLAG)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x19e[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x6,0x1,false,false,15,POKEMON_ONIX,ITEM_SINELBEERE,ATTACK_FELSGRAB,ATTACK_STEINPOLITUR,ATTACK_KLAMMERGRIFF,ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x6,0x0,false,false,16,POKEMON_GEOROK,ITEM_LYDZIBEERE,ATTACK_INTENSITAET,ATTACK_STEINPOLITUR,ATTACK_FELSGRAB,ATTACK_FINALE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x6,0x0,false,false,17,POKEMON_STOLLUNIOR,ITEM_TSITRUBEERE,ATTACK_BODYCHECK,ATTACK_INTENSITAET,ATTACK_FELSGRAB,ATTACK_METALLKLAUE)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x19f[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x7,0x0,false,false,23,POKEMON_BISAKNOSP,ITEM_TSITRUBEERE,ATTACK_EGELSAMEN,ATTACK_GIGASAUGER,ATTACK_TOXIN,ATTACK_MATSCHBOMBE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1,0x0,false,false,24,POKEMON_KAPILZ,ITEM_NONE,ATTACK_TEMPOHIEB,ATTACK_PILZSPORE,ATTACK_KOPFNUSS,ATTACK_SAMENBOMBE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x7,0x0,false,false,23,POKEMON_KASTADUR,ITEM_TSITRUBEERE,ATTACK_EGELSAMEN,ATTACK_VERWURZLER,ATTACK_GIGASAUGER,ATTACK_SCHUTZSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x3,0x0,false,false,25,POKEMON_KAPPALORES,ITEM_BLENDPUDER,ATTACK_DOPPELTEAM,ATTACK_EGELSAMEN,ATTACK_AQUAWELLE,ATTACK_GIGASAUGER)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x1a0[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,34,POKEMON_MEDITALIS,ITEM_NONE,ATTACK_ZEN_KOPFSTOSS,ATTACK_PROTZER,ATTACK_POWER_PUNCH,ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,35,POKEMON_MACHOMEI,ITEM_NONE,ATTACK_WUCHTSCHLAG,ATTACK_STEINKANTE,ATTACK_ERDBEBEN,ATTACK_DONNERSCHLAG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,35,POKEMON_SKARABORN,ITEM_PRUNUSBEERE,ATTACK_VIELENDER,ATTACK_NAHKAMPF,ATTACK_STEINKANTE,ATTACK_POWER_PUNCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,36,POKEMON_LUCARIO,ITEM_TSITRUBEERE,ATTACK_NAHKAMPF,ATTACK_EISENSCHWEIF,ATTACK_ERDBEBEN,ATTACK_PROTZER)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x1a1[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,41,POKEMON_APOQUALLYP,ITEM_NONE,ATTACK_SURFER,ATTACK_SPUKBALL,ATTACK_GENESUNG,ATTACK_IRRLICHT),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,42,POKEMON_GENGAR,ITEM_NONE,ATTACK_SPUKBALL,ATTACK_ENERGIEBALL,ATTACK_DONNERBLITZ,ATTACK_FOKUSSTOSS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,44,POKEMON_ZWIRRFINST,ITEM_TSITRUBEERE,ATTACK_LEIDTEILER,ATTACK_SPUKBALL,ATTACK_IRRLICHT,ATTACK_DONNERSCHLAG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_BANETTE,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SPUKBALL,ATTACK_FLUCH,ATTACK_NACHSPIEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_KRYPPUK,ITEM_NONE,ATTACK_LEIDTEILER,ATTACK_IRRLICHT,ATTACK_SPUKBALL,ATTACK_TIEFSCHLAG)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1a2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,37,POKEMON_SMOGON,ATTACK_FINALE,ATTACK_SCHLAMMBAD,ATTACK_RAUCHWOLKE,ATTACK_TOXIN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,39,POKEMON_SLEIMOK,ATTACK_KOMPRIMATOR,ATTACK_SCHLAMMBAD,ATTACK_SAEUREPANZER,ATTACK_TOXIN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,37,POKEMON_SMOGON,ATTACK_FINALE,ATTACK_SCHLAMMBAD,ATTACK_RAUCHWOLKE,ATTACK_TOXIN),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_SMOGMOG,ATTACK_TACKLE,ATTACK_SCHLAMMBAD,ATTACK_RAUCHWOLKE,ATTACK_TOXIN)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1a3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,38,POKEMON_ARKANI,ATTACK_BISS,ATTACK_SONNENTAG,ATTACK_BODYCHECK,ATTACK_HITZEKOLLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,40,POKEMON_CAMERUPT,ATTACK_ERDBEBEN,ATTACK_HITZEKOLLER,ATTACK_STEINHAGEL,ATTACK_FEUERSTURM),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,42,POKEMON_MAGBRANT,ATTACK_HITZEKOLLER,ATTACK_SONNENTAG,ATTACK_SOLARSTRAHL,ATTACK_DONNERBLITZ),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,40,POKEMON_GLURAK,ATTACK_BISS,ATTACK_ERDBEBEN,ATTACK_DRACHENKLAUE,ATTACK_HITZEKOLLER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1a4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,38,POKEMON_KADABRA,ATTACK_PSYSTRAHL,ATTACK_REFLEKTOR,ATTACK_SEHER,ATTACK_GEDANKENGUT),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,37,POKEMON_TRAUNFUGIL,ATTACK_BARRIERE,ATTACK_PSYSTRAHL,ATTACK_STAFETTE,ATTACK_GEDANKENGUT),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,38,POKEMON_VOLTULA,ATTACK_PSYSTRAHL,ATTACK_WINDSTOSS,ATTACK_BLUTSAUGER,ATTACK_SUPERSCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,43,POKEMON_SIMSALA,ATTACK_PSYCHOKINESE,ATTACK_GENESUNG,ATTACK_SEHER,ATTACK_GEDANKENGUT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1a5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,18,POKEMON_FUKANO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1a6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_NIDORANW)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1a7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_PIKACHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1a8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_TENTANTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1a9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_PONITA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1aa[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,19,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,16,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,18,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,20,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ab[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,19,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,16,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,18,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,20,POKEMON_BISAKNOSP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ac[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,19,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,16,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,18,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,20,POKEMON_GLUTEXO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ad[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,25,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,23,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,22,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,20,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,25,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ae[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,25,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,23,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,22,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,20,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,25,POKEMON_BISAKNOSP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1af[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,25,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,23,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,22,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,20,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,25,POKEMON_GLUTEXO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1b0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,35,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,35,POKEMON_SIMSALA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,40,POKEMON_TURTOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1b1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,35,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,35,POKEMON_SIMSALA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,40,POKEMON_BISAFLOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1b2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,35,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,35,POKEMON_SIMSALA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,40,POKEMON_GLURAK)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1b3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,47,POKEMON_STARAPTOR,ATTACK_DAUNENREIGEN,ATTACK_FLUEGELSCHLAG,ATTACK_WINDSTOSS,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_HORNBOHRER,ATTACK_FELSWURF,ATTACK_FURIENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_FUKANO,ATTACK_FLAMMENRAD,ATTACK_BODYCHECK,ATTACK_SILBERBLICK,ATTACK_AGILITAET),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_OWEI,ATTACK_SOLARSTRAHL,ATTACK_SCHLAFPUDER,ATTACK_GIFTPUDER,ATTACK_STACHELSPORE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,47,POKEMON_SIMSALA,ATTACK_PSYCHOKINESE,ATTACK_GEDANKENGUT,ATTACK_SEHER,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,53,POKEMON_TURTOK,ATTACK_AQUAKNARRE,ATTACK_REGENTANZ,ATTACK_BISS,ATTACK_TURBODREHER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1b4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,47,POKEMON_STARAPTOR,ATTACK_DAUNENREIGEN,ATTACK_FLUEGELSCHLAG,ATTACK_WINDSTOSS,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_HORNBOHRER,ATTACK_FELSWURF,ATTACK_FURIENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_GARADOS,ATTACK_HYDROPUMPE,ATTACK_WINDHOSE,ATTACK_SILBERBLICK,ATTACK_REGENTANZ),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_FUKANO,ATTACK_FLAMMENRAD,ATTACK_BODYCHECK,ATTACK_SILBERBLICK,ATTACK_AGILITAET),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,47,POKEMON_SIMSALA,ATTACK_PSYCHOKINESE,ATTACK_GEDANKENGUT,ATTACK_SEHER,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,53,POKEMON_BISAFLOR,ATTACK_RASIERBLATT,ATTACK_LOCKDUFT,ATTACK_WACHSTUM,ATTACK_SYNTHESE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1b5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,47,POKEMON_STARAPTOR,ATTACK_DAUNENREIGEN,ATTACK_FLUEGELSCHLAG,ATTACK_WINDSTOSS,ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_RIHORN,ATTACK_BODYCHECK,ATTACK_HORNBOHRER,ATTACK_FELSWURF,ATTACK_FURIENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_OWEI,ATTACK_SOLARSTRAHL,ATTACK_SCHLAFPUDER,ATTACK_GIFTPUDER,ATTACK_STACHELSPORE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,45,POKEMON_GARADOS,ATTACK_HYDROPUMPE,ATTACK_WINDHOSE,ATTACK_SILBERBLICK,ATTACK_REGENTANZ),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x16,0x0,false,true,47,POKEMON_SIMSALA,ATTACK_PSYCHOKINESE,ATTACK_GEDANKENGUT,ATTACK_SEHER,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1a,0x1,true,true,53,POKEMON_GLURAK,ATTACK_FLAMMENWURF,ATTACK_FLUEGELSCHLAG,ATTACK_SCHLITZER,ATTACK_GRIMASSE)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x1b6[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_STARAPTOR,ITEM_NONE,ATTACK_AERO_ASS,ATTACK_DAUNENREIGEN,ATTACK_SANDWIRBEL,ATTACK_WIRBELWIND),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,57,POKEMON_SIMSALA,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SEHER,ATTACK_GENESUNG,ATTACK_REFLEKTOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_RIZEROS,ITEM_NONE,ATTACK_BODYCHECK,ATTACK_ERDBEBEN,ATTACK_FELSGRAB,ATTACK_GRIMASSE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_ARKANI,ITEM_NONE,ATTACK_TURBOTEMPO,ATTACK_FLAMMENWURF,ATTACK_BRUELLER,ATTACK_BISS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,61,POKEMON_KOKOWEI,ITEM_NONE,ATTACK_GIGASAUGER,ATTACK_EIERBOMBE,ATTACK_SCHLAFPUDER,ATTACK_LICHTSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,63,POKEMON_TURTOK,ITEM_TSITRUBEERE,ATTACK_HYDROPUMPE,ATTACK_REGENTANZ,ATTACK_SCHAEDELWUMME,ATTACK_BISS)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x1b7[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_STARAPTOR,ITEM_NONE,ATTACK_AERO_ASS,ATTACK_DAUNENREIGEN,ATTACK_SANDWIRBEL,ATTACK_WIRBELWIND),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,57,POKEMON_SIMSALA,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SEHER,ATTACK_GENESUNG,ATTACK_REFLEKTOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_RIZEROS,ITEM_NONE,ATTACK_BODYCHECK,ATTACK_ERDBEBEN,ATTACK_FELSGRAB,ATTACK_GRIMASSE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_GARADOS,ITEM_NONE,ATTACK_HYDROPUMPE,ATTACK_DRACHENWUT,ATTACK_BISS,ATTACK_FUCHTLER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,61,POKEMON_ARKANI,ITEM_NONE,ATTACK_TURBOTEMPO,ATTACK_FLAMMENWURF,ATTACK_BRUELLER,ATTACK_BISS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,63,POKEMON_BISAFLOR,ITEM_TSITRUBEERE,ATTACK_SOLARSTRAHL,ATTACK_SYNTHESE,ATTACK_SONNENTAG,ATTACK_WACHSTUM)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x1b8[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_STARAPTOR,ITEM_NONE,ATTACK_AERO_ASS,ATTACK_DAUNENREIGEN,ATTACK_SANDWIRBEL,ATTACK_WIRBELWIND),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,57,POKEMON_SIMSALA,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SEHER,ATTACK_GENESUNG,ATTACK_REFLEKTOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_RIZEROS,ITEM_NONE,ATTACK_BODYCHECK,ATTACK_ERDBEBEN,ATTACK_FELSGRAB,ATTACK_GRIMASSE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,59,POKEMON_KOKOWEI,ITEM_NONE,ATTACK_GIGASAUGER,ATTACK_EIERBOMBE,ATTACK_SCHLAFPUDER,ATTACK_LICHTSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,61,POKEMON_GARADOS,ITEM_NONE,ATTACK_HYDROPUMPE,ATTACK_DRACHENWUT,ATTACK_BISS,ATTACK_FUCHTLER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,63,POKEMON_GLURAK,ITEM_TSITRUBEERE,ATTACK_FEUERSTURM,ATTACK_AERO_ASS,ATTACK_SCHLITZER,ATTACK_FEUERWIRBEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1b9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ba[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1bb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1bc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1bd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1be[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1bf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_ALPOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_KADABRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1c9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ca[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1cb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1cc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1cd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NEBULAK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ce[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1cf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_ALPOLLO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_ONIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_SEEPER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_KASTADUR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_GRAMOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,27,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1d6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGMOG,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGON,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,28,POKEMON_SMOGMOG,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,14,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,31,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1d9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_SEEPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_JUROB)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1da[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,20,POKEMON_STARALILI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1db[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,19,POKEMON_KNOFENSA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1dc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1dd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_NIDORINO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1de[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_ZOBIRIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1df[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,28,POKEMON_MYRAPLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_RAICHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,23,POKEMON_PIKACHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,17,POKEMON_PONITA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,22,POKEMON_PUMMELUFF)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x1e5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,45,POKEMON_NIDOQUEEN,ATTACK_KRAFTKOLOSS,ATTACK_BODYSLAM,ATTACK_DOPPELKICK,ATTACK_GIFTSTACHEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,45,POKEMON_NIDOKING,ATTACK_VIELENDER,ATTACK_FUCHTLER,ATTACK_DOPPELKICK,ATTACK_GIFTSTACHEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_NIDORANW)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_GLUMANDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_SCHIGGY)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x1e8[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,29,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,29,POKEMON_KICKLEE,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1e9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_GALLOPA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,29,POKEMON_VULNONA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ea[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,30,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1eb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ec[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,6,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_WELUNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ed[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_SEEKID)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ee[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_LOCKSCHAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ef[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,48,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,48,POKEMON_TROMBORK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,20,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,20,POKEMON_SANDAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,20,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,20,POKEMON_NIDORANW)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_NIDORINA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,19,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,19,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,19,POKEMON_ZUBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1f9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_TROMBORK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1fa[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_TROMBORK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_SANDAN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1fb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,20,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,20,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1fc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1fd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_TROMBORK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_SANDAMER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1fe[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,25,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,25,POKEMON_GEOROK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x1ff[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x200[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,70,POKEMON_DEOXYS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x201[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x202[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x203[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x204[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_HUNDUSTER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x205[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_NATU,ATTACK_NACHTNEBEL,ATTACK_KONFUSTRAHL,ATTACK_SEHER,ATTACK_WUNSCHTRAUM),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_LAHMUS,ATTACK_PSYCHOKINESE,ATTACK_KOPFNUSS,ATTACK_AMNESIE,ATTACK_GAEHNER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,49,POKEMON_KADABRA,ATTACK_PSYCHOKINESE,ATTACK_SEHER,ATTACK_GENESUNG,ATTACK_REFLEKTOR)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x206[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,37,POKEMON_MENKI,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,37,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x207[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_GRAMOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_x208[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,48,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,48,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,48,POKEMON_MARILL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x209[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,51,POKEMON_ULTRIGARIA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_LOCKDUFT,ATTACK_WICKEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,51,POKEMON_SARZENIA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_SCHLAFPUDER,ATTACK_STACHELSPORE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x20a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,51,POKEMON_DUFLOR,ATTACK_BLAETTERTANZ,ATTACK_SAEURE,ATTACK_LOCKDUFT,ATTACK_GIFTPUDER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,51,POKEMON_GIFLOR,ATTACK_BLAETTERTANZ,ATTACK_MONDSCHEIN,ATTACK_SAEURE,ATTACK_STACHELSPORE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x20b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_ULTRIGARIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x20c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_GEOROK)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x20d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_LICHTEL,ITEM_STERNENSTAUB),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_LATERNECTO,ITEM_STERNENSTAUB)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x20e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,50,POKEMON_TRAUNMAGIL,ATTACK_WUCHTSCHLAG,ATTACK_IRRSCHLAG,ATTACK_POWER_PUNCH,ATTACK_MEGAHIEB)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x20f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,37,POKEMON_SMOGON,ATTACK_DUNKELNEBEL,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_TACKLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,37,POKEMON_SLEIMA,ATTACK_SAEUREPANZER,ATTACK_KREIDESCHREI,ATTACK_KOMPRIMATOR,ATTACK_SCHLAMMBAD)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x210[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,38,POKEMON_SMOGON,ATTACK_DUNKELNEBEL,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_TACKLE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x211[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_SLEIMA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x212[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,5,POKEMON_PARAGONI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x213[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_DARTIRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,8,POKEMON_DARTIRI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x214[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_DARTIGNIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_DARTIRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,7,POKEMON_DARTIGNIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x215[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_PUMMELUFF)
};

trainer_pokemon_default_item_default_attacks trainer_party_x216[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_BRONZONG)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x217[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,13,POKEMON_GLUTEXO,ITEM_TRANK,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE,ATTACK_GIFTWOLKE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,26,POKEMON_GLUTEXO,ITEM_TRANK,ATTACK_SCHLAMMBAD,ATTACK_SMOG,ATTACK_TACKLE,ATTACK_GIFTWOLKE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x218[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_SLEIMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,24,POKEMON_SLEIMA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x219[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_TRAGOSSO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_KNOGGA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_SANDAMER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_GOLBAT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_SLEIMOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_HYPNO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_HYPNO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x21f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,22,POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,21,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,25,POKEMON_ABSOL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x220[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x8,0x0,true,true,53,POKEMON_GOLBAT,ATTACK_KONFUSTRAHL,ATTACK_MATSCHBOMBE,ATTACK_WINDSCHNITT,ATTACK_SPUKBALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x8,0x0,true,true,54,POKEMON_SMOGMOG,ATTACK_MATSCHBOMBE,ATTACK_DONNERBLITZ,ATTACK_EXPLOSION,ATTACK_SPUKBALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x8,0x0,true,true,55,POKEMON_HUNDEMON,ATTACK_FLAMMENWURF,ATTACK_KNIRSCHER,ATTACK_EISENSCHWEIF,ATTACK_SPUKBALL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x221[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_VOLTOBAL,ATTACK_STERNSCHAUER,ATTACK_KREIDESCHREI,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_LEKTROBAL,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL,ATTACK_KREIDESCHREI,ATTACK_LADEVORGANG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_MAGNETILO,ATTACK_KREIDESCHREI,ATTACK_STERNSCHAUER,ATTACK_FUNKENSPRUNG,ATTACK_DONNERWELLE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_MAGNETON,ATTACK_TRIPLETTE,ATTACK_FUNKENSPRUNG,ATTACK_DONNERWELLE,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,46,POKEMON_PORYGON,ATTACK_TRIPLETTE,ATTACK_UMWANDLUNG,ATTACK_GENESUNG,ATTACK_PSYSTRAHL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x222[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_JUROB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_JUROB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_JUGONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x223[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x224[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_ENTON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_ENTON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_ENTORON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x225[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x226[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_MUSCHAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_AUSTOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x227[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,33,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_APOQUALLYP)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x228[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,38,POKEMON_KICKLEE,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,38,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x229[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x22a[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_MACHOLLO,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,37,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x22b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_SANDAMER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x22c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,35,POKEMON_FLOETTE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x22d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,39,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,39,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x22e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_BISASAM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_BISAKNOSP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,36,POKEMON_BISAKNOSP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x22f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KRABBY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,34,POKEMON_KRABBY)
};

trainer_pokemon_default_item_default_attacks trainer_party_x230[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,37,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x231[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,38,POKEMON_KINGLER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x232[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,50,POKEMON_TRAUNMAGIL,ATTACK_FLIEGEN,ATTACK_SCHAUFLER,ATTACK_TAUCHER,ATTACK_SPRUNGFEDER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x233[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,50,POKEMON_TRAUNMAGIL,ATTACK_KREUZHIEB,ATTACK_VIELENDER,ATTACK_RISIKOTACKLE,ATTACK_FINALE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x234[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_VOLTILAMM,ITEM_STERNENSTAUB),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_VOLTILAMM,ITEM_STERNENSTAUB),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_WAATY,ITEM_NUGGET)
};

trainer_pokemon_default_item_default_attacks trainer_party_x235[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x236[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_TENTOXA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x237[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_SLEIMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x238[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,49,POKEMON_SMOGON,ATTACK_MEMENTO_MORI,ATTACK_DUNKELNEBEL,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,49,POKEMON_SMOGMOG,ATTACK_DUNKELNEBEL,ATTACK_RAUCHWOLKE,ATTACK_SCHLAMMBAD,ATTACK_FINALE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x239[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,48,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,48,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,48,POKEMON_DUFLOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x23a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x23b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x23c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_GLAZIOLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_RESLADERO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x23d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_MAMUTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_MAMUTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x23e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_KINGLER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x23f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_MARILL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x240[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x241[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_SHNEBEDECK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_REXBLISAR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x242[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_GARADOS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x243[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_LAMPI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_LANTURN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x244[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_PIKACHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x245[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x246[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_GEOWAZ)
};

trainer_pokemon_default_item_default_attacks trainer_party_x247[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x248[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_MOGELBAUM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x249[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,49,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,49,POKEMON_KANGAMA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x24a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,52,POKEMON_SKORGRO,ATTACK_KNIRSCHER,ATTACK_PSYSTRAHL,ATTACK_SCHNUEFFLER,ATTACK_AGILITAET)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x24b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_NATU,ATTACK_NACHTNEBEL,ATTACK_KONFUSTRAHL,ATTACK_WUNSCHTRAUM,ATTACK_SEHER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_TRAUMATO,ATTACK_PSYCHOKINESE,ATTACK_AUSSETZER,ATTACK_PSYCHO_PLUS,ATTACK_SEHER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,50,POKEMON_HYPNO,ATTACK_PSYCHOKINESE,ATTACK_HYPNOSE,ATTACK_PSYCHO_PLUS,ATTACK_SEHER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x24c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_BLUBELLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_BLUBELLA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x24d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_ENTORON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_ENTON)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x24e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,47,POKEMON_VOLTOBAL,ATTACK_STERNSCHAUER,ATTACK_LICHTSCHILD,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,47,POKEMON_TANNZA,ATTACK_STACHLER,ATTACK_GEDULD,ATTACK_TURBODREHER,ATTACK_BODYCHECK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,47,POKEMON_VOLTOBAL,ATTACK_STERNSCHAUER,ATTACK_LICHTSCHILD,ATTACK_FUNKENSPRUNG,ATTACK_ULTRASCHALL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,47,POKEMON_TANNZA,ATTACK_STACHLER,ATTACK_GEDULD,ATTACK_TURBODREHER,ATTACK_EXPLOSION)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x24f[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,48,POKEMON_RASAFF,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,48,POKEMON_KAPOERA,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,48,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x250[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,38,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x12,0x1,false,false,38,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x251[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,48,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,48,POKEMON_SCHLURP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,49,POKEMON_URSARING)
};

trainer_pokemon_default_item_default_attacks trainer_party_x252[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x0,true,false,33,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x0,true,false,33,POKEMON_SCHLURP)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x253[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,37,POKEMON_OWEI,ATTACK_SCHLAFPUDER,ATTACK_GIFTPUDER,ATTACK_STACHELSPORE,ATTACK_KONFUSION),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,40,POKEMON_KOKOWEI,ATTACK_EIERBOMBE,ATTACK_STAMPFER,ATTACK_KONFUSION,ATTACK_HYPNOSE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x254[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,49,POKEMON_ZOBIRIS,ATTACK_SLAM,ATTACK_MEGASAUGER,ATTACK_KLAMMERGRIFF,ATTACK_VERWURZLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,49,POKEMON_OWEI,ATTACK_KONFUSION,ATTACK_GIFTPUDER,ATTACK_STAKKATO,ATTACK_REFLEKTOR),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,49,POKEMON_KOKOWEI,ATTACK_KONFUSION,ATTACK_EIERBOMBE,ATTACK_SCHLAFPUDER,ATTACK_STAMPFER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x255[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,38,POKEMON_DUFLOR)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x256[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,52,POKEMON_CHANEIRA,ATTACK_EIERBOMBE,ATTACK_EINIGLER,ATTACK_KOMPRIMATOR,ATTACK_WEICHEI)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x257[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,47,POKEMON_RIZEROS,ATTACK_BODYCHECK,ATTACK_HORNBOHRER,ATTACK_FELSWURF,ATTACK_GRIMASSE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_LAHMUS,ATTACK_PSYCHOKINESE,ATTACK_KOPFNUSS,ATTACK_AMNESIE,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,47,POKEMON_KANGAMA,ATTACK_IRRSCHLAG,ATTACK_BISS,ATTACK_AUSDAUER,ATTACK_GEGENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_MASCHOCK,ATTACK_KREUZHIEB,ATTACK_UEBERWURF,ATTACK_VERGELTUNG,ATTACK_GEOWURF),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,50,POKEMON_URSARING,ATTACK_SCHLITZER,ATTACK_FINTE,ATTACK_SCHNARCHER,ATTACK_ERHOLUNG)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x258[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,47,POKEMON_TENTANTEL,ATTACK_SCHLITZER,ATTACK_KREIDESCHREI,ATTACK_FINTE,ATTACK_BISS),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,47,POKEMON_JUGONG,ATTACK_EISSTRAHL,ATTACK_BODYCHECK,ATTACK_EISSTURM,ATTACK_HEULER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_VULNONA,ATTACK_FLAMMENWURF,ATTACK_KONFUSTRAHL,ATTACK_IRRLICHT,ATTACK_NACHSPIEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,48,POKEMON_GALLOPA,ATTACK_SPRUNGFEDER,ATTACK_AGILITAET,ATTACK_FEUERWIRBEL,ATTACK_BODYCHECK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,50,POKEMON_SKORGRO,ATTACK_KNIRSCHER,ATTACK_PSYSTRAHL,ATTACK_STAMPFER,ATTACK_SCHNUEFFLER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x259[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,52,POKEMON_MILTANK,ATTACK_BODYSLAM,ATTACK_MILCHGETRAENK,ATTACK_HEULER,ATTACK_EINIGLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x4,0x1,true,false,52,POKEMON_TAUROS,ATTACK_FUCHTLER,ATTACK_HORNATTACKE,ATTACK_VERFOLGUNG,ATTACK_ANGEBEREI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x25a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_ONIX)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x25b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,48,POKEMON_KLEINSTEIN,ATTACK_ERDBEBEN,ATTACK_FELSWURF,ATTACK_WALZER,ATTACK_FINALE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,48,POKEMON_GEOROK,ATTACK_ERDBEBEN,ATTACK_FELSWURF,ATTACK_STEINWURF,ATTACK_FINALE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,48,POKEMON_GEOROK,ATTACK_ERDBEBEN,ATTACK_FELSWURF,ATTACK_STEINWURF,ATTACK_FINALE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x25c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,50,POKEMON_TRAUNMAGIL,ATTACK_MOGELHIEB,ATTACK_TURBOTEMPO,ATTACK_SCHUTZSCHILD,ATTACK_RUCKZUCKHIEB)
};

trainer_pokemon_default_item_default_attacks trainer_party_x25d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_KNOGGA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_ENTORON)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x25e[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,49,POKEMON_TENTANTEL,ITEM_NUGGET,ATTACK_ZAHLTAG,ATTACK_BISS,ATTACK_VERHOEHNER,ATTACK_FOLTERKNECHT),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0,0x0,false,false,49,POKEMON_TENTANTEL,ITEM_NUGGET,ATTACK_ZAHLTAG,ATTACK_KRATZER,ATTACK_FOLTERKNECHT,ATTACK_VERHOEHNER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x25f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_KNOGGA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x260[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,48,POKEMON_NATU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,48,POKEMON_NATU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x4,0x1,true,false,49,POKEMON_XATU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x261[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,50,POKEMON_CHANEIRA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x262[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,48,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,48,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1e,0x0,false,false,48,POKEMON_FLORGES)
};

trainer_pokemon_default_item_default_attacks trainer_party_x263[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_SKARABORN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x264[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,45,POKEMON_AMBIDIFFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,45,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,46,POKEMON_AMBIDIFFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_BIBOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x265[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_WATTZAPF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_VOLTULA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x266[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_ULTRIGARIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_ULTRIGARIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_SARZENIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x267[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_PORENTA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_PORENTA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x268[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,46,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,47,POKEMON_LATERNECTO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_LATERNECTO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x269[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_SNUBBULL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_PINSIR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,50,POKEMON_SKARABORN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_FOLIPURBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_FOLIPURBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,49,POKEMON_FEELINARA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,48,POKEMON_SANDAMER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,21,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,21,POKEMON_NIDORANW)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_NIDORINA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x26f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_NIDORINA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x270[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,22,POKEMON_SCHIGGY)
};

trainer_pokemon_default_item_default_attacks trainer_party_x271[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x272[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_SCHILLOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x273[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,21,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,21,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x274[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x275[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x276[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,21,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,21,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,18,POKEMON_STARALILI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x277[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,26,POKEMON_STARAVIA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x278[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,50,POKEMON_STARAPTOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x279[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,22,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,22,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,22,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_BRONZONG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_MAGNETON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_VULPIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,24,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,24,POKEMON_GLUMANDA)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,29,POKEMON_GLUTEXO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x27f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_ARKANI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_GLUTEXO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x280[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,25,POKEMON_KASTADUR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x281[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_TENTANTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x282[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_TENTANTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x283[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_ONIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x284[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,54,POKEMON_RIZEROS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,54,POKEMON_SCHLURP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x285[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x0,true,false,29,POKEMON_KNOGGA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1a,0x0,true,false,29,POKEMON_LAHMUS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x286[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,54,POKEMON_KNOGGA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,54,POKEMON_LAHMUS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x287[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,31,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,31,POKEMON_GEOROK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x288[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,22,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,22,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,23,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,21,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x8,0x1,false,false,22,POKEMON_PIKACHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x289[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,46,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_TENTANTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_RAICHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_SLEIMOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_SLEIMOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_VULPIX)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_SLEIMOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_AUSTOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,33,POKEMON_LEKTROBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,33,POKEMON_LEKTROBAL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x28f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_TENTANTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x290[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x291[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x292[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_KASTADUR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x293[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_TENTANTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_TENTANTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x294[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_TENTANTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_RAICHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_TENTANTEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x295[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_SLEIMOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_SMOGMOG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x296[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,32,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,32,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x297[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x298[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x299[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x29a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_KNUDDELUFF)
};

trainer_pokemon_default_item_default_attacks trainer_party_x29b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_DODU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x29c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_DODRI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x29d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,32,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,32,POKEMON_RAICHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x29e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_RAICHU)
};

trainer_pokemon_default_item_default_attacks trainer_party_x29f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_RAICHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_RAICHU)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2a0[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xe,0x1,true,false,33,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xe,0x1,true,false,33,POKEMON_KICKLEE,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2a1[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,51,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,51,POKEMON_KICKLEE,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2a2[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,56,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,56,POKEMON_KICKLEE,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_SMOGMOG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_SMOGMOG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,48,POKEMON_SMOGMOG)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_SMOGMOG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_SLEIMOK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_MACHOMEI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_MACHOMEI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,28,POKEMON_MAEHIKEL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2a9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2aa[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2ab[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2ac[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2ad[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_APOQUALLYP)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2ae[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_KARPADOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2af[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,50,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2b0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,50,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,50,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2b1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_STARMIE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2b2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,50,POKEMON_STARMIE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b3[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,50,POKEMON_MENKI,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,50,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b4[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,55,POKEMON_RASAFF,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,55,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b5[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,50,POKEMON_KICKLEE,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,50,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b6[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,55,POKEMON_KICKLEE,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,55,POKEMON_NOCKCHAN,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b7[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0,0x0,false,false,1,POKEMON_BISASAM,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b8[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x1c,0x0,true,true,55,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x1c,0x0,true,true,55,POKEMON_MACHOMEI,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2b9[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x14,0x1,false,true,50,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x14,0x1,false,true,50,POKEMON_MASCHOCK,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2ba[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x1c,0x0,true,true,55,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x1c,0x0,true,true,55,POKEMON_MACHOMEI,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2bb[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,51,POKEMON_MASCHOCK,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x2,0x0,false,true,51,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2bc[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,56,POKEMON_MACHOMEI,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,56,POKEMON_RASAFF,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2bd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,47,POKEMON_DUOKLES)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2be[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_FLOETTE)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2bf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x18,0x1,true,false,54,POKEMON_TRAUNMAGIL,ATTACK_KREUZHIEB,ATTACK_VIELENDER,ATTACK_RISIKOTACKLE,ATTACK_FINALE)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,53,POKEMON_BRONZONG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,53,POKEMON_STARAPTOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,53,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,53,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,53,POKEMON_MARILL)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,30,POKEMON_NIDORINO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_NIDOKING),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_NIDOQUEEN)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,53,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_STARAPTOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,53,POKEMON_CHEVRUMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_CHEVRUMM)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,53,POKEMON_RESLADERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_RESLADERO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_MARILL)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2c8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,52,POKEMON_NATU,ATTACK_PSYCHOKINESE,ATTACK_KONFUSTRAHL,ATTACK_SEHER,ATTACK_WUNSCHTRAUM),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,52,POKEMON_LAHMUS,ATTACK_PSYCHOKINESE,ATTACK_KOPFNUSS,ATTACK_AMNESIE,ATTACK_GAEHNER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,54,POKEMON_KADABRA,ATTACK_PSYCHOKINESE,ATTACK_SEHER,ATTACK_GENESUNG,ATTACK_REFLEKTOR)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2c9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,55,POKEMON_GARADOS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2ca[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_MACHOMEI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2cb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_MASCHOCK)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2cc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,55,POKEMON_RIZEROS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x16,0x0,false,true,55,POKEMON_KANGAMA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2cd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,56,POKEMON_SKORGRO,ATTACK_KNIRSCHER,ATTACK_PSYSTRAHL,ATTACK_SCHNUEFFLER,ATTACK_AGILITAET)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2ce[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,53,POKEMON_NATU,ATTACK_PSYCHOKINESE,ATTACK_KONFUSTRAHL,ATTACK_WUNSCHTRAUM,ATTACK_SEHER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,53,POKEMON_HYPNO,ATTACK_PSYCHOKINESE,ATTACK_AUSSETZER,ATTACK_PSYCHO_PLUS,ATTACK_SEHER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,53,POKEMON_HYPNO,ATTACK_PSYCHOKINESE,ATTACK_HYPNOSE,ATTACK_PSYCHO_PLUS,ATTACK_SEHER)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2cf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_LEKTROBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_TANNZA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_LEKTROBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,52,POKEMON_TANNZA)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,55,POKEMON_SARZENIA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_STACHELSPORE,ATTACK_WICKEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,55,POKEMON_SARZENIA,ATTACK_RASIERBLATT,ATTACK_SAEURE,ATTACK_SCHLAFPUDER,ATTACK_SLAM)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,55,POKEMON_GIFLOR,ATTACK_BLAETTERTANZ,ATTACK_MONDSCHEIN,ATTACK_SAEURE,ATTACK_SCHLAFPUDER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,55,POKEMON_GIFLOR,ATTACK_BLAETTERTANZ,ATTACK_MONDSCHEIN,ATTACK_SAEURE,ATTACK_STACHELSPORE)
};

trainer_pokemon_custom_item_default_attacks trainer_party_x2d2[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,54,POKEMON_RASAFF,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,54,POKEMON_KAPOERA,ITEM_SCHWARZGURT),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0xa,0x1,false,true,54,POKEMON_MACHOMEI,ITEM_SCHWARZGURT)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2d3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x1,false,true,52,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x1,false,true,52,POKEMON_SCHLURP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0,0x1,false,true,55,POKEMON_URSARING)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,53,POKEMON_ZOBIRIS,ATTACK_SLAM,ATTACK_MEGASAUGER,ATTACK_KLAMMERGRIFF,ATTACK_VERWURZLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,54,POKEMON_KOKOWEI,ATTACK_KONFUSION,ATTACK_EIERBOMBE,ATTACK_STACHELSPORE,ATTACK_REFLEKTOR),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,55,POKEMON_KOKOWEI,ATTACK_KONFUSION,ATTACK_EIERBOMBE,ATTACK_SCHLAFPUDER,ATTACK_STAMPFER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,56,POKEMON_CHANEIRA,ATTACK_EIERBOMBE,ATTACK_EINIGLER,ATTACK_KOMPRIMATOR,ATTACK_WEICHEI)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,52,POKEMON_RIZEROS,ATTACK_ERDBEBEN,ATTACK_HORNBOHRER,ATTACK_FELSWURF,ATTACK_GRIMASSE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,54,POKEMON_LAHMUS,ATTACK_PSYCHOKINESE,ATTACK_KOPFNUSS,ATTACK_AMNESIE,ATTACK_AUSSETZER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,52,POKEMON_KANGAMA,ATTACK_IRRSCHLAG,ATTACK_BISS,ATTACK_AUSDAUER,ATTACK_GEGENSCHLAG),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,52,POKEMON_MACHOMEI,ATTACK_KREUZHIEB,ATTACK_UEBERWURF,ATTACK_VERGELTUNG,ATTACK_GEOWURF),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,55,POKEMON_URSARING,ATTACK_SCHLITZER,ATTACK_FINTE,ATTACK_SCHNARCHER,ATTACK_ERHOLUNG)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,53,POKEMON_TENTANTEL,ATTACK_SCHLITZER,ATTACK_KREIDESCHREI,ATTACK_FINTE,ATTACK_BISS),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,53,POKEMON_JUGONG,ATTACK_EISSTRAHL,ATTACK_BODYCHECK,ATTACK_EISSTURM,ATTACK_EISESKAELTE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,54,POKEMON_VULNONA,ATTACK_FLAMMENWURF,ATTACK_KONFUSTRAHL,ATTACK_IRRLICHT,ATTACK_NACHSPIEL),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,54,POKEMON_GALLOPA,ATTACK_SPRUNGFEDER,ATTACK_AGILITAET,ATTACK_FEUERWIRBEL,ATTACK_BODYCHECK),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,56,POKEMON_SKORGRO,ATTACK_KNIRSCHER,ATTACK_PSYSTRAHL,ATTACK_STAMPFER,ATTACK_SCHNUEFFLER)
};

trainer_pokemon_default_item_custom_attacks trainer_party_x2d8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,57,POKEMON_MILTANK,ATTACK_BODYSLAM,ATTACK_MILCHGETRAENK,ATTACK_HEULER,ATTACK_EINIGLER),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x1c,0x0,true,true,57,POKEMON_TAUROS,ATTACK_BODYCHECK,ATTACK_GRIMASSE,ATTACK_VERFOLGUNG,ATTACK_ANGEBEREI)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2d9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,19,POKEMON_DARTIGNIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,19,POKEMON_HORNLIU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x14,0x0,false,false,19,POKEMON_DARTIGNIS)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2da[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_FIARO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_KOKUNA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x1c,0x1,false,false,27,POKEMON_FIARO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2db[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,51,POKEMON_FIARO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,54,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x18,0x1,true,false,51,POKEMON_FIARO)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2dc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_DURENGARD)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2dd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_SEEMON)
};

trainer_pokemon_default_item_default_attacks trainer_party_x2de[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_DUOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x10,0x0,true,false,49,POKEMON_APOQUALLYP)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2df[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,64,POKEMON_JUGONG,ITEM_NONE,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_AMPELLEUCHTE,ATTACK_DOPPELTEAM),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,63,POKEMON_AUSTOS,ITEM_NONE,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_SUPERSCHALL,ATTACK_REGENTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,63,POKEMON_KEIFEL,ITEM_NONE,ATTACK_BLIZZARD,ATTACK_ERDBEBEN,ATTACK_RISIKOTACKLE,ATTACK_STEINHAGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_GALAGLADI,ITEM_NONE,ATTACK_EISSTRAHL,ATTACK_PSYCHOKINESE,ATTACK_TODESKUSS,ATTACK_ANZIEHUNG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_LAPRAS,ITEM_AMRENABEERE,ATTACK_EISSTRAHL,ATTACK_SURFER,ATTACK_PSYCHOKINESE,ATTACK_DONNER)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e0[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,65,POKEMON_STAHLOS,ITEM_NONE,ATTACK_ERDBEBEN,ATTACK_EISENSCHWEIF,ATTACK_KNIRSCHER,ATTACK_FELSGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,65,POKEMON_NOCKCHAN,ITEM_NONE,ATTACK_HIMMELHIEB,ATTACK_TEMPOHIEB,ATTACK_STEINHAGEL,ATTACK_KONTER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,65,POKEMON_KICKLEE,ITEM_NONE,ATTACK_MEGAKICK,ATTACK_GESICHTE,ATTACK_ERDBEBEN,ATTACK_STEINHAGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_STAHLOS,ITEM_NONE,ATTACK_ERDBEBEN,ATTACK_EISENSCHWEIF,ATTACK_KNIRSCHER,ATTACK_FEUERODEM),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,68,POKEMON_MACHOMEI,ITEM_PERSIMBEERE,ATTACK_KREUZHIEB,ATTACK_ERDBEBEN,ATTACK_DURCHBRUCH,ATTACK_STEINHAGEL)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e1[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_GENGAR,ITEM_NONE,ATTACK_SPUKBALL,ATTACK_PSYCHOKINESE,ATTACK_KONFUSTRAHL,ATTACK_HYPNOSE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_IKSBAT,ITEM_NONE,ATTACK_MATSCHBOMBE,ATTACK_WINDSCHNITT,ATTACK_SPUKBALL,ATTACK_KONFUSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,65,POKEMON_KRAMSHEF,ITEM_NONE,ATTACK_SPUKBALL,ATTACK_PSYCHOKINESE,ATTACK_DONNERBLITZ,ATTACK_ANZIEHUNG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,68,POKEMON_TROMBORK,ITEM_NONE,ATTACK_MATSCHBOMBE,ATTACK_ERDBEBEN,ATTACK_GIGASAUGER,ATTACK_DOPPELTEAM),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,70,POKEMON_GENGAR,ITEM_MARONBEERE,ATTACK_SPUKBALL,ATTACK_PSYCHOKINESE,ATTACK_DONNERBLITZ,ATTACK_MATSCHBOMBE)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e2[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,68,POKEMON_GARADOS,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_DRACHENTANZ,ATTACK_ERDBEBEN,ATTACK_DONNERWELLE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_DRAGORAN,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_ERDBEBEN,ATTACK_DRACHENKLAUE,ATTACK_FLAMMENWURF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,66,POKEMON_SEEDRAKING,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_DRACHENTANZ,ATTACK_SURFER,ATTACK_EISSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,70,POKEMON_AERODACTYL,ITEM_NONE,ATTACK_HYPERSTRAHL,ATTACK_ANTIK_KRAFT,ATTACK_AERO_ASS,ATTACK_ERDBEBEN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_DRAGORAN,ITEM_PERSIMBEERE,ATTACK_HYPERSTRAHL,ATTACK_WUTANFALL,ATTACK_DONNERBLITZ,ATTACK_EISSTRAHL)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e3[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_SKARABORN,ITEM_NONE,ATTACK_VIELENDER,ATTACK_ERDBEBEN,ATTACK_KONTER,ATTACK_FELSGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_SIMSALA,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SPUKBALL,ATTACK_GEDANKENGUT,ATTACK_REFLEKTOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_DESPOTAR,ITEM_NONE,ATTACK_KNIRSCHER,ATTACK_ERDBEBEN,ATTACK_DONNERBLITZ,ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_ARKANI,ITEM_NONE,ATTACK_TURBOTEMPO,ATTACK_HITZEKOLLER,ATTACK_AERO_ASS,ATTACK_EISENSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_KOKOWEI,ITEM_NONE,ATTACK_GIGASAUGER,ATTACK_PSYCHOKINESE,ATTACK_SCHLAFPUDER,ATTACK_LICHTSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,75,POKEMON_TURTOK,ITEM_TSITRUBEERE,ATTACK_HYDROPUMPE,ATTACK_EISSTRAHL,ATTACK_ERDBEBEN,ATTACK_REGENTANZ)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e4[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_SKARABORN,ITEM_NONE,ATTACK_VIELENDER,ATTACK_ERDBEBEN,ATTACK_KONTER,ATTACK_FELSGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_SIMSALA,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SPUKBALL,ATTACK_GEDANKENGUT,ATTACK_REFLEKTOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_DESPOTAR,ITEM_NONE,ATTACK_KNIRSCHER,ATTACK_ERDBEBEN,ATTACK_DONNERBLITZ,ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_GARADOS,ITEM_NONE,ATTACK_HYDROPUMPE,ATTACK_DRACHENTANZ,ATTACK_ERDBEBEN,ATTACK_HYPERSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_ARKANI,ITEM_NONE,ATTACK_TURBOTEMPO,ATTACK_HITZEKOLLER,ATTACK_AERO_ASS,ATTACK_EISENSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,75,POKEMON_BISAFLOR,ITEM_TSITRUBEERE,ATTACK_SOLARSTRAHL,ATTACK_MATSCHBOMBE,ATTACK_ERDBEBEN,ATTACK_SONNENTAG)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e5[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_SKARABORN,ITEM_NONE,ATTACK_VIELENDER,ATTACK_ERDBEBEN,ATTACK_KONTER,ATTACK_FELSGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_SIMSALA,ITEM_NONE,ATTACK_PSYCHOKINESE,ATTACK_SPUKBALL,ATTACK_GEDANKENGUT,ATTACK_REFLEKTOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,72,POKEMON_DESPOTAR,ITEM_NONE,ATTACK_KNIRSCHER,ATTACK_ERDBEBEN,ATTACK_DONNERBLITZ,ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_KOKOWEI,ITEM_NONE,ATTACK_GIGASAUGER,ATTACK_PSYCHOKINESE,ATTACK_SCHLAFPUDER,ATTACK_LICHTSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,73,POKEMON_GARADOS,ITEM_NONE,ATTACK_HYDROPUMPE,ATTACK_DRACHENTANZ,ATTACK_ERDBEBEN,ATTACK_HYPERSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x1f,0x1,true,true,75,POKEMON_GLURAK,ITEM_TSITRUBEERE,ATTACK_FEUERSTURM,ATTACK_DRACHENKLAUE,ATTACK_AERO_ASS,ATTACK_ERDBEBEN)
};

trainer_pokemon_custom_item_custom_attacks trainer_party_x2e6[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,1,POKEMON_BISAFLOR,ITEM_BISAFLORNIT,ATTACK_PLATSCHER,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x12,0x1,false,false,39,POKEMON_SLEIMOK,ITEM_NONE,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE)
};

