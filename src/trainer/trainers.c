
#include "types.h"
#include "stdbool.h"
#include "constants/trainerclasses.h"
#include "constants/trainer_ai_flags.h"
#include "constants/items.h"
#include "trainer/trainer.h"
#include "trainer/party.h"
#include "language.h"

trainer trainers[TRAINER_CNT] = {
    {
    //Trainer 0x0
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("RÜPEL"), PSTRING("RÜPEL")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x0
  },{
    //Trainer 0x1
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_STREBER,
    {0x3, false},//Encounter and gender
    0x1d,// sprite
    LANGDEP(PSTRING("Andreas"), PSTRING("Andreas")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1
  },{
    //Trainer 0x2
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER2,
    {0x6, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Maximilian"), PSTRING("Maximilian")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2
  },{
    //Trainer 0x3
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHNOESEL,
    {0x6, false},//Encounter and gender
    0xd,// sprite
    LANGDEP(PSTRING("Holger"), PSTRING("Holger")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3
  },{
    //Trainer 0x4
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x3, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel H."), PSTRING("Rüpel H.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4
  },{
    //Trainer 0x5
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER,
    {0xd, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Peter"), PSTRING("Peter")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5
  },{
    //Trainer 0x6
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x3, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel B."), PSTRING("Rüpel B.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6
  },{
    //Trainer 0x7
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x2, true},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Marleene"), PSTRING("Marleene")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7
  },{
    //Trainer 0x8
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel R."), PSTRING("Rüpel R.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8
  },{
    //Trainer 0x9
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x5, false},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Ysabell"), PSTRING("Ysabell")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9
  },{
    //Trainer 0xa
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_MECHANIKER,
    {0x5, false},//Encounter and gender
    0x5d,// sprite
    LANGDEP(PSTRING("Xaver"), PSTRING("Xaver")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa
  },{
    //Trainer 0xb
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {0x3, false},//Encounter and gender
    0x17,// sprite
    LANGDEP(PSTRING("Henrick"), PSTRING("Henrick")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xb
  },{
    //Trainer 0xc
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER,
    {0x1, false},//Encounter and gender
    0x13,// sprite
    LANGDEP(PSTRING("Tristayne"), PSTRING("Tristayne")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xc
  },{
    //Trainer 0xd
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHOENHEIT,
    {0x1, false},//Encounter and gender
    0xc,// sprite
    LANGDEP(PSTRING("Rosana"), PSTRING("Rosana")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xd
  },{
    //Trainer 0xe
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {0xd, false},//Encounter and gender
    0x10,// sprite
    LANGDEP(PSTRING("Rick"), PSTRING("Rick")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xe
  },{
    //Trainer 0xf
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {0x3, false},//Encounter and gender
    0x3d,// sprite
    LANGDEP(PSTRING("Jane"), PSTRING("Jane")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xf
  },{
    //Trainer 0x10
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x1, false},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Johanne"), PSTRING("Johanne")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x10
  },{
    //Trainer 0x11
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {0x4, false},//Encounter and gender
    0x10,// sprite
    LANGDEP(PSTRING("Luca"), PSTRING("Luca")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x11
  },{
    //Trainer 0x12
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x4, false},//Encounter and gender
    0x43,// sprite
    LANGDEP(PSTRING("Willas"), PSTRING("Willas")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x12
  },{
    //Trainer 0x13
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {0xb, false},//Encounter and gender
    0x42,// sprite
    LANGDEP(PSTRING("John"), PSTRING("John")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x13
  },{
    //Trainer 0x14
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_LADY,
    {0x0, false},//Encounter and gender
    0xb,// sprite
    LANGDEP(PSTRING("Emily"), PSTRING("Emily")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x14
  },{
    //Trainer 0x15
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GOERE,
    {0x3, false},//Encounter and gender
    0x41,// sprite
    LANGDEP(PSTRING("Sabrina"), PSTRING("Sabrina")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x15
  },{
    //Trainer 0x16
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {0x4, false},//Encounter and gender
    0x2e,// sprite
    LANGDEP(PSTRING("Alen"), PSTRING("Alen")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x16
  },{
    //Trainer 0x17
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PSYCHO,
    {0x4, false},//Encounter and gender
    0x16,// sprite
    LANGDEP(PSTRING("Cassandra"), PSTRING("Cassandra")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x17
  },{
    //Trainer 0x18
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {0xd, false},//Encounter and gender
    0x2e,// sprite
    LANGDEP(PSTRING("Valentin"), PSTRING("Valentin")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x18
  },{
    //Trainer 0x19
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_POLIZIST,
    {0xa, false},//Encounter and gender
    0x0,// sprite
    LANGDEP(PSTRING("Harrenfeld"), PSTRING("Harrenfeld")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x19
  },{
    //Trainer 0x1a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_POKEMANIAC,
    {0xa, false},//Encounter and gender
    0x20,// sprite
    LANGDEP(PSTRING("Anton"), PSTRING("Anton")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1a
  },{
    //Trainer 0x1b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x1, false},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Felizia"), PSTRING("Felizia")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1b
  },{
    //Trainer 0x1c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x0, false},//Encounter and gender
    0x26,// sprite
    LANGDEP(PSTRING("Kamille"), PSTRING("Kamille")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1c
  },{
    //Trainer 0x1d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x1, false},//Encounter and gender
    0x26,// sprite
    LANGDEP(PSTRING("Ben"), PSTRING("Ben")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1d
  },{
    //Trainer 0x1e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_EXPERTE,
    {0x0, true},//Encounter and gender
    0x23,// sprite
    LANGDEP(PSTRING("Martha"), PSTRING("Martha")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1e
  },{
    //Trainer 0x1f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHULKIND,
    {0x0, false},//Encounter and gender
    0x1e,// sprite
    LANGDEP(PSTRING("Chantal"), PSTRING("Chantal")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x1f
  },{
    //Trainer 0x20
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x9, false},//Encounter and gender
    0x26,// sprite
    LANGDEP(PSTRING("Marius"), PSTRING("Marius")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x20
  },{
    //Trainer 0x21
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x9, false},//Encounter and gender
    0x26,// sprite
    LANGDEP(PSTRING("Nils"), PSTRING("Nils")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x21
  },{
    //Trainer 0x22
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_NINJAJUNGE,
    {0x9, false},//Encounter and gender
    0x2f,// sprite
    LANGDEP(PSTRING("Kevin"), PSTRING("Kevin")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x22
  },{
    //Trainer 0x23
    true,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x4, false},//Encounter and gender
    0x9,// sprite
    LANGDEP(PSTRING("Serena"), PSTRING("Serena")),
    {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x23
  },{
    //Trainer 0x24
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TRIATHLET,
    {0x4, false},//Encounter and gender
    0x2a,// sprite
    LANGDEP(PSTRING("Nyomsa"), PSTRING("Nyomsa")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x24
  },{
    //Trainer 0x25
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER,
    {0x0, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Tino"), PSTRING("Tino")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x25
  },{
    //Trainer 0x26
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_DIEB,
    {0x0, false},//Encounter and gender
    0x5c,// sprite
    LANGDEP(PSTRING("Steffen"), PSTRING("Steffen")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x26
  },{
    //Trainer 0x27
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {0xb, false},//Encounter and gender
    0x2e,// sprite
    LANGDEP(PSTRING("Ernest"), PSTRING("Ernest")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x27
  },{
    //Trainer 0x28
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel Y."), PSTRING("Rüpel Y.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x28
  },{
    //Trainer 0x29
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x0, true},//Encounter and gender
    0x39,// sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x29
  },{
    //Trainer 0x2a
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER2,
    {0x1, true},//Encounter and gender
    0x39,// sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2a
  },{
    //Trainer 0x2b
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER2,
    {0x1, true},//Encounter and gender
    0x39,// sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2b
  },{
    //Trainer 0x2c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_POLIZIST,
    {0x1, false},//Encounter and gender
    0x0,// sprite
    LANGDEP(PSTRING("Marq"), PSTRING("Marq")),
    {ITEM_TRANK, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2c
  },{
    //Trainer 0x2d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ROCKER,
    {0x1, false},//Encounter and gender
    0x11,// sprite
    LANGDEP(PSTRING("Udo"), PSTRING("Udo")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2d
  },{
    //Trainer 0x2e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x4, true},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Annie"), PSTRING("Annie")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2e
  },{
    //Trainer 0x2f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {0x2, true},//Encounter and gender
    0x17,// sprite
    LANGDEP(PSTRING("Joachim"), PSTRING("Joachim")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x2f
  },{
    //Trainer 0x30
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER,
    {0x2, false},//Encounter and gender
    0x33,// sprite
    LANGDEP(PSTRING("Lobin"), PSTRING("Lobin")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x30
  },{
    //Trainer 0x31
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {0x4, false},//Encounter and gender
    0x30,// sprite
    LANGDEP(PSTRING("Ran"), PSTRING("Ran")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x31
  },{
    //Trainer 0x32
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x1, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Alois"), PSTRING("Alois")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x32
  },{
    //Trainer 0x33
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TRIATHLET,
    {0x1, false},//Encounter and gender
    0x29,// sprite
    LANGDEP(PSTRING("Seymour"), PSTRING("Seymour")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x33
  },{
    //Trainer 0x34
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER2,
    {0x1, false},//Encounter and gender
    0x52,// sprite
    LANGDEP(PSTRING("Nedd"), PSTRING("Nedd")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x34
  },{
    //Trainer 0x35
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHOENHEIT,
    {0x1, false},//Encounter and gender
    0x62,// sprite
    LANGDEP(PSTRING("Andrea"), PSTRING("Andrea")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x35
  },{
    //Trainer 0x36
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x0, false},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Jeyne"), PSTRING("Jeyne")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x36
  },{
    //Trainer 0x37
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER2,
    {0x0, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Phyllip"), PSTRING("Phyllip")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x37
  },{
    //Trainer 0x38
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {0x0, true},//Encounter and gender
    0x3b,// sprite
    LANGDEP(PSTRING("Maraa"), PSTRING("Maraa")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    5,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x38
  },{
    //Trainer 0x39
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER,
    {0x3, true},//Encounter and gender
    0x33,// sprite
    LANGDEP(PSTRING("Eliot"), PSTRING("Eliot")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x39
  },{
    //Trainer 0x3a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GOERE2,
    {0x0, false},//Encounter and gender
    0x54,// sprite
    LANGDEP(PSTRING("Charlie"), PSTRING("Charlie")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3a
  },{
    //Trainer 0x3b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x1, false},//Encounter and gender
    0x8,// sprite
    LANGDEP(PSTRING("Leon"), PSTRING("Leon")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3b
  },{
    //Trainer 0x3c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TRIATHLET,
    {0x0, false},//Encounter and gender
    0x2a,// sprite
    LANGDEP(PSTRING("Gerda"), PSTRING("Gerda")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3c
  },{
    //Trainer 0x3d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER,
    {0x0, false},//Encounter and gender
    0x33,// sprite
    LANGDEP(PSTRING("Lore"), PSTRING("Lore")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3d
  },{
    //Trainer 0x3e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER2,
    {0x1, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Jeff"), PSTRING("Jeff")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3e
  },{
    //Trainer 0x3f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER3,
    {0x1, false},//Encounter and gender
    0x13,// sprite
    LANGDEP(PSTRING("Miguel"), PSTRING("Miguel")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x3f
  },{
    //Trainer 0x40
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {0x1, true},//Encounter and gender
    0x3b,// sprite
    LANGDEP(PSTRING("Ismeralda"), PSTRING("Ismeralda")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    5,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x40
  },{
    //Trainer 0x41
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER2,
    {0x0, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Robert"), PSTRING("Robert")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x41
  },{
    //Trainer 0x42
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x1, true},//Encounter and gender
    0x5e,// sprite
    LANGDEP(PSTRING("Alen"), PSTRING("Alen")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x42
  },{
    //Trainer 0x43
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {0x5, true},//Encounter and gender
    0x14,// sprite
    LANGDEP(PSTRING("Merrik"), PSTRING("Merrik")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x43
  },{
    //Trainer 0x44
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x5, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel N."), PSTRING("Rüpel N.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x44
  },{
    //Trainer 0x45
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {0x7, true},//Encounter and gender
    0x3c,// sprite
    LANGDEP(PSTRING("Remus"), PSTRING("Remus")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x45
  },{
    //Trainer 0x46
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x7, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x46
  },{
    //Trainer 0x47
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_CAMPER,
    {0x7, true},//Encounter and gender
    0x57,// sprite
    LANGDEP(PSTRING("Erna"), PSTRING("Erna")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x47
  },{
    //Trainer 0x48
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x1, false},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel I."), PSTRING("Rüpel I.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x48
  },{
    //Trainer 0x49
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel P."), PSTRING("Rüpel P.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x49
  },{
    //Trainer 0x4a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0xb, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel N."), PSTRING("Rüpel N.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4a
  },{
    //Trainer 0x4b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x2, false},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel D."), PSTRING("Rüpel D.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4b
  },{
    //Trainer 0x4c
    true,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VIOLET_VORS,
    {0x4, true},//Encounter and gender
    0x1b,// sprite
    LANGDEP(PSTRING("Rin"), PSTRING("Rin")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4c
  },{
    //Trainer 0x4d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x8, false},//Encounter and gender
    0x43,// sprite
    LANGDEP(PSTRING("Barneby"), PSTRING("Barneby")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4d
  },{
    //Trainer 0x4e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER,
    {0x6, false},//Encounter and gender
    0x24,// sprite
    LANGDEP(PSTRING("Wolffie"), PSTRING("Wolffie")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4e
  },{
    //Trainer 0x4f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_CAMPER,
    {0x6, true},//Encounter and gender
    0x57,// sprite
    LANGDEP(PSTRING("Korinna"), PSTRING("Korinna")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x4f
  },{
    //Trainer 0x50
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x7, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Kalleh"), PSTRING("Kalleh")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x50
  },{
    //Trainer 0x51
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GOERE,
    {0x7, false},//Encounter and gender
    0x54,// sprite
    LANGDEP(PSTRING("Karmina"), PSTRING("Karmina")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x51
  },{
    //Trainer 0x52
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x0, false},//Encounter and gender
    0x43,// sprite
    LANGDEP(PSTRING("Walltyr"), PSTRING("Walltyr")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x52
  },{
    //Trainer 0x53
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHULKIND,
    {0x1, false},//Encounter and gender
    0x54,// sprite
    LANGDEP(PSTRING("Sophie"), PSTRING("Sophie")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x53
  },{
    //Trainer 0x54
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {0x0, false},//Encounter and gender
    0x30,// sprite
    LANGDEP(PSTRING("Maya"), PSTRING("Maya")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x54
  },{
    //Trainer 0x55
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x1, true},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Silkye"), PSTRING("Silkye")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x55
  },{
    //Trainer 0x56
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_STREBER,
    {0x7a, false},//Encounter and gender
    0x59,// sprite
    LANGDEP(PSTRING("Waynis"), PSTRING("Waynis")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x56
  },{
    //Trainer 0x57
    false,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_EXPERTE,
    {0xa, true},//Encounter and gender
    0x23,// sprite
    LANGDEP(PSTRING("Franziska"), PSTRING("Franziska")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x57
  },{
    //Trainer 0x58
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_RUINENMANIAC,
    {0xa, false},//Encounter and gender
    0x4,// sprite
    LANGDEP(PSTRING("Drago"), PSTRING("Drago")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x58
  },{
    //Trainer 0x59
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x0, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Rudolf"), PSTRING("Rudolf")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x59
  },{
    //Trainer 0x5a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_DIEB,
    {0x0, false},//Encounter and gender
    0x5c,// sprite
    LANGDEP(PSTRING("Merreck"), PSTRING("Merreck")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5a
  },{
    //Trainer 0x5b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER2,
    {0x0, false},//Encounter and gender
    0x52,// sprite
    LANGDEP(PSTRING("Thyma"), PSTRING("Thyma")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5b
  },{
    //Trainer 0x5c
    true,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x0, true},//Encounter and gender
    0x39,// sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERHEILER},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5c
  },{
    //Trainer 0x5d
    true,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x0, true},//Encounter and gender
    0x39,// sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERHEILER},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5d
  },{
    //Trainer 0x5e
    true,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x0, true},//Encounter and gender
    0x39,// sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERHEILER},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5e
  },{
    //Trainer 0x5f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GOERE,
    {0x0, true},//Encounter and gender
    0x54,// sprite
    LANGDEP(PSTRING("Janina"), PSTRING("Janina")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x5f
  },{
    //Trainer 0x60
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x0, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Gunnward"), PSTRING("Gunnward")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x60
  },{
    //Trainer 0x61
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {0x28, true},//Encounter and gender
    0x3b,// sprite
    LANGDEP(PSTRING("Henrietta"), PSTRING("Henrietta")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    5,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x61
  },{
    //Trainer 0x62
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER3,
    {0x0, false},//Encounter and gender
    0x56,// sprite
    LANGDEP(PSTRING("Sonnwald"), PSTRING("Sonnwald")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x62
  },{
    //Trainer 0x63
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_POKEMANIAC,
    {0x0, false},//Encounter and gender
    0x36,// sprite
    LANGDEP(PSTRING("Valeyntyn"), PSTRING("Valeyntyn")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x63
  },{
    //Trainer 0x64
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x64
  },{
    //Trainer 0x65
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER,
    {0x0, true},//Encounter and gender
    0x33,// sprite
    LANGDEP(PSTRING("Janie"), PSTRING("Janie")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x65
  },{
    //Trainer 0x66
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {0x0, false},//Encounter and gender
    0x3d,// sprite
    LANGDEP(PSTRING("Ismera"), PSTRING("Ismera")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x66
  },{
    //Trainer 0x67
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {0x0, false},//Encounter and gender
    0x53,// sprite
    LANGDEP(PSTRING("Eusjean"), PSTRING("Eusjean")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x67
  },{
    //Trainer 0x68
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHNOESEL,
    {0x0, false},//Encounter and gender
    0xd,// sprite
    LANGDEP(PSTRING("Rudderich"), PSTRING("Rudderich")),
    {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x68
  },{
    //Trainer 0x69
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PSYCHO,
    {0x0, false},//Encounter and gender
    0x16,// sprite
    LANGDEP(PSTRING("Attilia"), PSTRING("Attilia")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x69
  },{
    //Trainer 0x6a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x0, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Gangolf"), PSTRING("Gangolf")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6a
  },{
    //Trainer 0x6b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {0x0, false},//Encounter and gender
    0x2e,// sprite
    LANGDEP(PSTRING("Abduhl"), PSTRING("Abduhl")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6b
  },{
    //Trainer 0x6c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {0x0, false},//Encounter and gender
    0x1,// sprite
    LANGDEP(PSTRING("Gerrie"), PSTRING("Gerrie")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6c
  },{
    //Trainer 0x6d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {0x0, true},//Encounter and gender
    0x2,// sprite
    LANGDEP(PSTRING("Marja"), PSTRING("Marja")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6d
  },{
    //Trainer 0x6e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {0x0, true},//Encounter and gender
    0x2,// sprite
    LANGDEP(PSTRING("Balla"), PSTRING("Balla")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6e
  },{
    //Trainer 0x6f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_AROMALADY,
    {0x0, true},//Encounter and gender
    0x3,// sprite
    LANGDEP(PSTRING("Ruanna"), PSTRING("Ruanna")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x6f
  },{
    //Trainer 0x70
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_MECHANIKER,
    {0x0, false},//Encounter and gender
    0x5d,// sprite
    LANGDEP(PSTRING("Tommas"), PSTRING("Tommas")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x70
  },{
    //Trainer 0x71
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel S."), PSTRING("Rüpel S.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x71
  },{
    //Trainer 0x72
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {0x0, false},//Encounter and gender
    0x2,// sprite
    LANGDEP(PSTRING("Sophy"), PSTRING("Sophy")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x72
  },{
    //Trainer 0x73
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {0x0, false},//Encounter and gender
    0x1,// sprite
    LANGDEP(PSTRING("Rell"), PSTRING("Rell")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x73
  },{
    //Trainer 0x74
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {0x0, true},//Encounter and gender
    0x30,// sprite
    LANGDEP(PSTRING("Maggy"), PSTRING("Maggy")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x74
  },{
    //Trainer 0x75
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {0x1, false},//Encounter and gender
    0x68,// sprite
    LANGDEP(PSTRING("Kriss"), PSTRING("Kriss")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x75
  },{
    //Trainer 0x76
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PSYCHO,
    {0x1, false},//Encounter and gender
    0x64,// sprite
    LANGDEP(PSTRING("Coal"), PSTRING("Coal")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x76
  },{
    //Trainer 0x77
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {0x1, false},//Encounter and gender
    0x7b,// sprite
    LANGDEP(PSTRING("Fraunk"), PSTRING("Fraunk")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x77
  },{
    //Trainer 0x78
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x1, false},//Encounter and gender
    0x5e,// sprite
    LANGDEP(PSTRING("Sheldon"), PSTRING("Sheldon")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x78
  },{
    //Trainer 0x79
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {0x1, false},//Encounter and gender
    0x69,// sprite
    LANGDEP(PSTRING("Rashi"), PSTRING("Rashi")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x79
  },{
    //Trainer 0x7a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {0x1, true},//Encounter and gender
    0x30,// sprite
    LANGDEP(PSTRING("Mayama"), PSTRING("Mayama")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7a
  },{
    //Trainer 0x7b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ANGLER,
    {0x1, true},//Encounter and gender
    0x5e,// sprite
    LANGDEP(PSTRING("Doran"), PSTRING("Doran")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7b
  },{
    //Trainer 0x7c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {0x1, true},//Encounter and gender
    0x69,// sprite
    LANGDEP(PSTRING("Richard"), PSTRING("Richard")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7c
  },{
    //Trainer 0x7d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {0x1, true},//Encounter and gender
    0x2,// sprite
    LANGDEP(PSTRING("Elsa"), PSTRING("Elsa")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7d
  },{
    //Trainer 0x7e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x1, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Gerrad"), PSTRING("Gerrad")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7e
  },{
    //Trainer 0x7f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GOERE2,
    {0x1, true},//Encounter and gender
    0x54,// sprite
    LANGDEP(PSTRING("Livia"), PSTRING("Livia")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x7f
  },{
    //Trainer 0x80
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {0x1, false},//Encounter and gender
    0x30,// sprite
    LANGDEP(PSTRING("Loretta"), PSTRING("Loretta")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x80
  },{
    //Trainer 0x81
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {0x1, false},//Encounter and gender
    0x69,// sprite
    LANGDEP(PSTRING("Tobish"), PSTRING("Tobish")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x81
  },{
    //Trainer 0x82
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {0x1, true},//Encounter and gender
    0x30,// sprite
    LANGDEP(PSTRING("Christina"), PSTRING("Christina")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x82
  },{
    //Trainer 0x83
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {0x1, true},//Encounter and gender
    0x69,// sprite
    LANGDEP(PSTRING("Gerd"), PSTRING("Gerd")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x83
  },{
    //Trainer 0x84
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_FORSCHERIN,
    {0x1, true},//Encounter and gender
    0x5,// sprite
    LANGDEP(PSTRING("Elise"), PSTRING("Elise")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    6,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x84
  },{
    //Trainer 0x85
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_RUINENMANIAC,
    {0x1, true},//Encounter and gender
    0x4,// sprite
    LANGDEP(PSTRING("Fellicho"), PSTRING("Fellicho")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x85
  },{
    //Trainer 0x86
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {0x0, false},//Encounter and gender
    0x17,// sprite
    LANGDEP(PSTRING("Nikolas"), PSTRING("Nikolas")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x86
  },{
    //Trainer 0x87
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x0, false},//Encounter and gender
    0x6e,// sprite
    LANGDEP(PSTRING("Lorenz"), PSTRING("Lorenz")),
    {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x87
  },{
    //Trainer 0x88
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {0x0, false},//Encounter and gender
    0x42,// sprite
    LANGDEP(PSTRING("Richardo"), PSTRING("Richardo")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x88
  },{
    //Trainer 0x89
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WOLKENREITER,
    {0x0, true},//Encounter and gender
    0x47,// sprite
    LANGDEP(PSTRING("Alyssa"), PSTRING("Alyssa")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x89
  },{
    //Trainer 0x8a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WOLKENREITER,
    {0x0, false},//Encounter and gender
    0x48,// sprite
    LANGDEP(PSTRING("Alesion"), PSTRING("Alesion")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8a
  },{
    //Trainer 0x8b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_STREBER,
    {0x0, false},//Encounter and gender
    0x59,// sprite
    LANGDEP(PSTRING("Jesse"), PSTRING("Jesse")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8b
  },{
    //Trainer 0x8c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WOLKENREITER,
    {0x0, false},//Encounter and gender
    0x47,// sprite
    LANGDEP(PSTRING("Elya"), PSTRING("Elya")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8c
  },{
    //Trainer 0x8d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8d
  },{
    //Trainer 0x8e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel J."), PSTRING("Rüpel J.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8e
  },{
    //Trainer 0x8f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, true},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel G."), PSTRING("Rüpel G.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x8f
  },{
    //Trainer 0x90
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel S."), PSTRING("Rüpel S.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x90
  },{
    //Trainer 0x91
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x49,// sprite
    LANGDEP(PSTRING("Elite V."), PSTRING("Elite V.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x91
  },{
    //Trainer 0x92
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_HITZKOPF,
    {0x0, false},//Encounter and gender
    0x12,// sprite
    LANGDEP(PSTRING("Raphael"), PSTRING("Raphael")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x92
  },{
    //Trainer 0x93
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_CAMPER2,
    {0x0, false},//Encounter and gender
    0x56,// sprite
    LANGDEP(PSTRING("Tasso"), PSTRING("Tasso")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x93
  },{
    //Trainer 0x94
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHOENHEIT,
    {0x0, false},//Encounter and gender
    0x62,// sprite
    LANGDEP(PSTRING("Cyarla"), PSTRING("Cyarla")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x94
  },{
    //Trainer 0x95
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_CAMPER,
    {0x0, true},//Encounter and gender
    0x57,// sprite
    LANGDEP(PSTRING("Issilde"), PSTRING("Issilde")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x95
  },{
    //Trainer 0x96
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {0x2, false},//Encounter and gender
    0x17,// sprite
    LANGDEP(PSTRING("Gewert"), PSTRING("Gewert")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x96
  },{
    //Trainer 0x97
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_STREBER,
    {0x2, true},//Encounter and gender
    0x59,// sprite
    LANGDEP(PSTRING("Crissilas"), PSTRING("Crissilas")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x97
  },{
    //Trainer 0x98
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {0x2, true},//Encounter and gender
    0x3e,// sprite
    LANGDEP(PSTRING("Hedwig"), PSTRING("Hedwig")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x98
  },{
    //Trainer 0x99
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_GOERE,
    {0x2, true},//Encounter and gender
    0x54,// sprite
    LANGDEP(PSTRING("Ruth"), PSTRING("Ruth")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x99
  },{
    //Trainer 0x9a
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x2, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Ingo"), PSTRING("Ingo")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9a
  },{
    //Trainer 0x9b
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_SCHULKIND,
    {0x2, true},//Encounter and gender
    0x1e,// sprite
    LANGDEP(PSTRING("Marija"), PSTRING("Marija")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9b
  },{
    //Trainer 0x9c
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x2, true},//Encounter and gender
    0x6f,// sprite
    LANGDEP(PSTRING("Jana"), PSTRING("Jana")),
    {ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9c
  },{
    //Trainer 0x9d
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_LADY2,
    {0x2, true},//Encounter and gender
    0x92,// sprite
    LANGDEP(PSTRING("Nathalie"), PSTRING("Nathalie")),
    {ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9d
  },{
    //Trainer 0x9e
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_DIEB,
    {0x0, true},//Encounter and gender
    0x5c,// sprite
    LANGDEP(PSTRING("Rüdigar"), PSTRING("Rüdigar")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9e
  },{
    //Trainer 0x9f
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {0x0, true},//Encounter and gender
    0x3b,// sprite
    LANGDEP(PSTRING("Hannya"), PSTRING("Hannya")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    6,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_x9f
  },{
    //Trainer 0xa0
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_WANDERER,
    {0x0, false},//Encounter and gender
    0x5a,// sprite
    LANGDEP(PSTRING("Haggron"), PSTRING("Haggron")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa0
  },{
    //Trainer 0xa1
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_PICKNICKER,
    {0x0, false},//Encounter and gender
    0x56,// sprite
    LANGDEP(PSTRING("Joseppo"), PSTRING("Joseppo")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa1
  },{
    //Trainer 0xa2
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_HITZKOPF,
    {0x0, false},//Encounter and gender
    0x12,// sprite
    LANGDEP(PSTRING("Taryuk"), PSTRING("Taryuk")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa2
  },{
    //Trainer 0xa3
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa3
  },{
    //Trainer 0xa4
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel R."), PSTRING("Rüpel R.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa4
  },{
    //Trainer 0xa5
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel L."), PSTRING("Rüpel L.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa5
  },{
    //Trainer 0xa6
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel Y."), PSTRING("Rüpel Y.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa6
  },{
    //Trainer 0xa7
    true,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel D."), PSTRING("Rüpel D.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa7
  },{
    //Trainer 0xa8
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel L."), PSTRING("Rüpel L.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa8
  },{
    //Trainer 0xa9
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {0x0, true},//Encounter and gender
    0x6f,// sprite
    LANGDEP(PSTRING("Curris"), PSTRING("Curris")),
    {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xa9
  },{
    //Trainer 0xaa
    true,// Custom moves
    true,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_VIOLET_VORS,
    {0x3, false},//Encounter and gender
    0x60,// sprite
    LANGDEP(PSTRING("Mistral"), PSTRING("Mistral")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_CONSIDER_PERECNTUAL_HP,
    0x0,// field_1E
    1,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xaa
  },{
    //Trainer 0xab
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEENAGER,
    {0x3, false},//Encounter and gender
    0x52,// sprite
    LANGDEP(PSTRING("Dario"), PSTRING("Dario")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xab
  },{
    //Trainer 0xac
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_HITZKOPF,
    {0x3, false},//Encounter and gender
    0x12,// sprite
    LANGDEP(PSTRING("Gerrit"), PSTRING("Gerrit")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xac
  },{
    //Trainer 0xad
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x3, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel"), PSTRING("Rüpel")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xad
  },{
    //Trainer 0xae
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x49,// sprite
    LANGDEP(PSTRING("Elite H."), PSTRING("Elite H.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xae
  },{
    //Trainer 0xaf
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x4a,// sprite
    LANGDEP(PSTRING("Elite M."), PSTRING("Elite M.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xaf
  },{
    //Trainer 0xb0
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, true},//Encounter and gender
    0x4e,// sprite
    LANGDEP(PSTRING("Rüpel K."), PSTRING("Rüpel K.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    2,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xb0
  },{
    //Trainer 0xb1
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x0, false},//Encounter and gender
    0x6d,// sprite
    LANGDEP(PSTRING("Rüpel G."), PSTRING("Rüpel G.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    3,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xb1
  },{
    //Trainer 0xb2
    false,// Custom moves
    false,// Custom items
    0x0,// field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {0x3, true},//Encounter and gender
    0x49,// sprite
    LANGDEP(PSTRING("Elite N."), PSTRING("Elite N.")),
    {ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
    false,//Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0,// field_1E
    4,// Pokemon Count
    0x0,// field_21
    0x0,// field_22
    0x0,// field_23
    (trainer_pokemon*) trainer_party_xb2
  }
};
