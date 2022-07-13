#include "types.h"
#include "trainer/trainer.h"
#include "constants/trainerclasses.h"

u8 trainer_class_money_multipliers[TRAINERCLASS_CNT] = {
    [TRAINERCLASS_PKMN_TRAINER] = 1,
    [TRAINERCLASS_PKMN_TRAINER2] = 1,
    [TRAINERCLASS_POLIZIST] = 20,
    [TRAINERCLASS_REVOLUTIONAER] = 5,
    [TRAINERCLASS_AROMALADY] = 10,
    [TRAINERCLASS_RUINENMANIAC] = 15,
    [TRAINERCLASS_FORSCHERIN] = 12,
    [TRAINERCLASS_PLANSCHER] = 1,
    [TRAINERCLASS_BUTLER] = 1,
    [TRAINERCLASS_ASS_TRAINER] = 12,
    [TRAINERCLASS_HEXE] = 6,
    [TRAINERCLASS_LADY] = 50,
    [TRAINERCLASS_SCHOENHEIT] = 20,
    [TRAINERCLASS_SCHNOESEL] = 50,
    [TRAINERCLASS_POKEMANIAC] = 15,
    [TRAINERCLASS_SCHWIMMER] = 2,
    [TRAINERCLASS_SCHWARZGURT] = 8,
    [TRAINERCLASS_GITARRIST] = 8,
    [TRAINERCLASS_HITZKOPF] = 8,
    [TRAINERCLASS_CAMPER] = 4,
    [TRAINERCLASS_KAEFERMANIAC] = 15,
    [TRAINERCLASS_PSYCHO] = 6,
    [TRAINERCLASS_GENTLEMAN] = 20,
    [TRAINERCLASS_TOP_VIER] = 25,
    [TRAINERCLASS_LEITERALD] = 25,
    [TRAINERCLASS_SCHULKIND] = 5,
    [TRAINERCLASS_SEN_AND_JUN] = 4,
    [TRAINERCLASS_POKEFAN] = 20,
    [TRAINERCLASS_EXPERTE] = 10,
    [TRAINERCLASS_TEENAGER] = 4,
    [TRAINERCLASS_CHAMP] = 50,
    [TRAINERCLASS_ANGLER] = 10,
    [TRAINERCLASS_TRIATHLET] = 10,
    [TRAINERCLASS_DRACHENPROFI] = 12,
    [TRAINERCLASS_VOGELFAENGER] = 8,
    [TRAINERCLASS_NINJAJUNGE] = 3,
    [TRAINERCLASS_KAEMPFERIN] = 6,
    [TRAINERCLASS_SCHIRMDAME] = 10,
    [TRAINERCLASS_SCHWIMMERIN] = 2,
    [TRAINERCLASS_PICKNICKER] = 4,
    [TRAINERCLASS_ZWIL] = 3,
    [TRAINERCLASS_MATROSE] = 8,
    [TRAINERCLASS_SNOWBOARDER] = 1,
    [TRAINERCLASS_PKMN_SAMMLER] = 15,
    [TRAINERCLASS_KRYPTIKER] = 15,
    [TRAINERCLASS_PKMN_ZUECHTER] = 10,
    [TRAINERCLASS_PKMN_RANGER] = 12,
    [TRAINERCLASS_CHEFKOCH] = 7,
    [TRAINERCLASS_PIRATE] = 5,
    [TRAINERCLASS_GOERE] = 4,
    [TRAINERCLASS_KAEFERSAMMLER] = 4,
    [TRAINERCLASS_PICKNICKER3] = 10,
    [TRAINERCLASS_JUNGES_GLUECK] = 8,
    [TRAINERCLASS_ALTES_PAAR] = 10,
    [TRAINERCLASS_GESCHWISTER] = 3,
    [TRAINERCLASS_WOLKENREITER] = 10,
    [TRAINERCLASS_VIOLET_VORS] = 10,
    [TRAINERCLASS_TEENAGER2] = 4,
    [TRAINERCLASS_KAEFERSAMMLER2] = 3,
    [TRAINERCLASS_GOERE2] = 4,
    [TRAINERCLASS_MATROSE2] = 8,
    [TRAINERCLASS_CAMPER2] = 5,
    [TRAINERCLASS_PICKNICKER2] = 5,
    [TRAINERCLASS_POKEMANIAC2] = 12,
    [TRAINERCLASS_STREBER] = 6,
    [TRAINERCLASS_WANDERER] = 9,
    [TRAINERCLASS_BIKER] = 5,
    [TRAINERCLASS_DIEB] = 22,
    [TRAINERCLASS_MECHANIKER] = 12,
    [TRAINERCLASS_ANGLER3] = 9,
    [TRAINERCLASS_SCHWIMMER2] = 1,
    [TRAINERCLASS_GLATZKOPF] = 6,
    [TRAINERCLASS_SPIELER] = 18,
    [TRAINERCLASS_SCHOENHEIT2] = 18,
    [TRAINERCLASS_SCHWIMMERIN2] = 1,
    [TRAINERCLASS_PSYCHO2] = 5,
    [TRAINERCLASS_ROCKER] = 6,
    [TRAINERCLASS_KAPITAEN] = 20,
    [TRAINERCLASS_DOMPTEUR] = 10,
    [TRAINERCLASS_VOGELFAENGER2] = 6,
    [TRAINERCLASS_SCHWARZGURT2] = 6,
    [TRAINERCLASS_RIVALE] = 4,
    [TRAINERCLASS_FORSCHER] = 12,
    [TRAINERCLASS_BOSS] = 25,
    [TRAINERCLASS_ARENALEITER] = 25,
    [TRAINERCLASS_TEAM_VIOLET] = 8,
    [TRAINERCLASS_ASS_TRAINER2] = 9,
    [TRAINERCLASS_TOP_VIER2] = 25,
    [TRAINERCLASS_GENTLEMAN2] = 18,
    [TRAINERCLASS_RIVALE2] = 9,
    [TRAINERCLASS_CHAMP2] = 25,
    [TRAINERCLASS_EXORZISTIN] = 8,
    [TRAINERCLASS_ZWIL2] = 3,
    [TRAINERCLASS_PRIMAPAAR] = 6,
    [TRAINERCLASS_JUNGES_GLUECK2] = 7,
    [TRAINERCLASS_MUEHLENSIPPE] = 6,
    [TRAINERCLASS_GESCHWISTER2] = 1,
    [TRAINERCLASS_ANTIKE_WACHE] = 25,
    [TRAINERCLASS_SPIELER2] = 1,
    [TRAINERCLASS_MUEHLENMAEDEL] = 6,
    [TRAINERCLASS_PLANSCHER3] = 1,
    [TRAINERCLASS_PKMN_ZUECHTER2] = 7,
    [TRAINERCLASS_PKMN_RANGER2] = 9,
    [TRAINERCLASS_AROMALADY2] = 7,
    [TRAINERCLASS_RUINENMANIAC2] = 12,
    [TRAINERCLASS_LADY2] = 50,
    [TRAINERCLASS_MALERIN] = 4,
};