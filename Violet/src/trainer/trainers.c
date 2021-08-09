#include "types.h"
#include "stdbool.h"
#include "constants/trainerclasses.h"
#include "constants/trainer_ai_flags.h"
#include "constants/items.h"
#include "trainer/trainer.h"
#include "trainer/parties.h"
#include "language.h"
#include "save.h"
#include "battle/state.h"
#include "battle/ai.h"

trainer_pokemon_custom_item_custom_attacks maike_test[2];
trainer trainers[TRAINER_CNT] = {
  {
    //Trainer 0x0
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel"), PSTRING("Rüpel")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x0
  },
  {
    //Trainer 0x1
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_STREBER,
    {
      0x3,
      false
    }, //Encounter and gender
    0x1d, // sprite
    LANGDEP(PSTRING("Andreas"), PSTRING("Andreas")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1
  },
  {
    //Trainer 0x2
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER2,
    {
      0x6,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Maximilian"), PSTRING("Maximilian")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2
  },
  {
    //Trainer 0x3
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHNOESEL,
    {
      0x6,
      false
    }, //Encounter and gender
    0xd, // sprite
    LANGDEP(PSTRING("Holger"), PSTRING("Holger")),
    {
      ITEM_TRANK,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3
  },
  {
    //Trainer 0x4
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x3,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel H."), PSTRING("Rüpel H.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4
  },
  {
    //Trainer 0x5
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER,
    {
      0xd,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Peter"), PSTRING("Peter")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5
  },
  {
    //Trainer 0x6
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x3,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rpel B."), PSTRING("Rüpel B.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6
  },
  {
    //Trainer 0x7
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x2,
      true
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Marleene"), PSTRING("Marleene")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7
  },
  {
    //Trainer 0x8
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel R."), PSTRING("Rüpel R.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8
  },
  {
    //Trainer 0x9
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x5,
      false
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Ysabell"), PSTRING("Ysabell")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9
  },
  {
    //Trainer 0xa
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_MECHANIKER,
    {
      0x5,
      false
    }, //Encounter and gender
    0x5d, // sprite
    LANGDEP(PSTRING("Xaver"), PSTRING("Xaver")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa
  },
  {
    //Trainer 0xb
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {
      0x2,
      false
    }, //Encounter and gender
    0x17, // sprite
    LANGDEP(PSTRING("Henrick"), PSTRING("Henrick")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xb
  },
  {
    //Trainer 0xc
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x13, // sprite
    LANGDEP(PSTRING("Tristayne"), PSTRING("Tristayne")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xc
  },
  {
    //Trainer 0xd
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHOENHEIT,
    {
      0x1,
      false
    }, //Encounter and gender
    0xc, // sprite
    LANGDEP(PSTRING("Rosana"), PSTRING("Rosana")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xd
  },
  {
    //Trainer 0xe
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {
      0xd,
      false
    }, //Encounter and gender
    0x10, // sprite
    LANGDEP(PSTRING("Rick"), PSTRING("Rick")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xe
  },
  {
    //Trainer 0xf
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {
      0x3,
      false
    }, //Encounter and gender
    0x3d, // sprite
    LANGDEP(PSTRING("Jane"), PSTRING("Jane")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xf
  },
  {
    //Trainer 0x10
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x1,
      false
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Johanne"), PSTRING("Johanne")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x10
  },
  {
    //Trainer 0x11
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {
      0x4,
      false
    }, //Encounter and gender
    0x10, // sprite
    LANGDEP(PSTRING("Luca"), PSTRING("Luca")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x11
  },
  {
    //Trainer 0x12
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x4,
      false
    }, //Encounter and gender
    0x43, // sprite
    LANGDEP(PSTRING("Willas"), PSTRING("Willas")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x12
  },
  {
    //Trainer 0x13
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {
      0xb,
      false
    }, //Encounter and gender
    0x42, // sprite
    LANGDEP(PSTRING("John"), PSTRING("John")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x13
  },
  {
    //Trainer 0x14
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_LADY,
    {
      0x0,
      false
    }, //Encounter and gender
    0xb, // sprite
    LANGDEP(PSTRING("Emily"), PSTRING("Emily")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x14
  },
  {
    //Trainer 0x15
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GOERE,
    {
      0x3,
      false
    }, //Encounter and gender
    0x41, // sprite
    LANGDEP(PSTRING("Sabrina"), PSTRING("Sabrina")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x15
  },
  {
    //Trainer 0x16
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {
      0x4,
      false
    }, //Encounter and gender
    0x2e, // sprite
    LANGDEP(PSTRING("Alen"), PSTRING("Alen")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x16
  },
  {
    //Trainer 0x17
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PSYCHO,
    {
      0x4,
      false
    }, //Encounter and gender
    0x16, // sprite
    LANGDEP(PSTRING("Cassandra"), PSTRING("Cassandra")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x17
  },
  {
    //Trainer 0x18
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {
      0xd,
      false
    }, //Encounter and gender
    0x2e, // sprite
    LANGDEP(PSTRING("Valentin"), PSTRING("Valentin")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x18
  },
  {
    //Trainer 0x19
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_POLIZIST,
    {
      0xa,
      false
    }, //Encounter and gender
    26, // sprite
    LANGDEP(PSTRING("Harrenfeld"), PSTRING("Harrenfeld")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x19
  },
  {
    //Trainer 0x1a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_POKEMANIAC,
    {
      0xa,
      false
    }, //Encounter and gender
    0x20, // sprite
    LANGDEP(PSTRING("Anton"), PSTRING("Anton")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1a
  },
  {
    //Trainer 0x1b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x1,
      false
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Felizia"), PSTRING("Felizia")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1b
  },
  {
    //Trainer 0x1c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x26, // sprite
    LANGDEP(PSTRING("Kamille"), PSTRING("Kamille")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1c
  },
  {
    //Trainer 0x1d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x26, // sprite
    LANGDEP(PSTRING("Ben"), PSTRING("Ben")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1d
  },
  {
    //Trainer 0x1e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_EXPERTE,
    {
      0x0,
      true
    }, //Encounter and gender
    0x23, // sprite
    LANGDEP(PSTRING("Martha"), PSTRING("Martha")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1e
  },
  {
    //Trainer 0x1f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHULKIND,
    {
      0x0,
      false
    }, //Encounter and gender
    0x1e, // sprite
    LANGDEP(PSTRING("Chantal"), PSTRING("Chantal")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x1f
  },
  {
    //Trainer 0x20
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x9,
      false
    }, //Encounter and gender
    0x26, // sprite
    LANGDEP(PSTRING("Marius"), PSTRING("Marius")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x20
  },
  {
    //Trainer 0x21
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x9,
      false
    }, //Encounter and gender
    0x26, // sprite
    LANGDEP(PSTRING("Nils"), PSTRING("Nils")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x21
  },
  {
    //Trainer 0x22
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_NINJAJUNGE,
    {
      0x9,
      false
    }, //Encounter and gender
    0x2f, // sprite
    LANGDEP(PSTRING("Kevin"), PSTRING("Kevin")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x22
  },
  {
    //Trainer 0x23
    true, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {
      0x4,
      false
    }, //Encounter and gender
    0x9, // sprite
    LANGDEP(PSTRING("Serena"), PSTRING("Serena")),
    {
      ITEM_TOP_GENESUNG,
      ITEM_TOP_GENESUNG,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x23
  },
  {
    //Trainer 0x24
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TRIATHLET,
    {
      0x4,
      false
    }, //Encounter and gender
    0x2a, // sprite
    LANGDEP(PSTRING("Nyomsa"), PSTRING("Nyomsa")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x24
  },
  {
    //Trainer 0x25
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Tino"), PSTRING("Tino")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x25
  },
  {
    //Trainer 0x26
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_DIEB,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5c, // sprite
    LANGDEP(PSTRING("Steffen"), PSTRING("Steffen")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x26
  },
  {
    //Trainer 0x27
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {
      0xb,
      false
    }, //Encounter and gender
    0x2e, // sprite
    LANGDEP(PSTRING("Ernest"), PSTRING("Ernest")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x27
  },
  {
    //Trainer 0x28
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel Y."), PSTRING("Rüpel Y.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x28
  },
  {
    //Trainer 0x29
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_TRAINER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x39, // sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {
      ITEM_TRANK,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x29
  },
  {
    //Trainer 0x2a
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
    {
      0x1,
      true
    }, //Encounter and gender
    0x39, // sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {
      ITEM_TRANK,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2a
  },
  {
    //Trainer 0x2b
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
    {
      0x1,
      true
    }, //Encounter and gender
    0x39, // sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {
      ITEM_TRANK,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2b
  },
  {
    //Trainer 0x2c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_POLIZIST,
    {
      0x1,
      false
    }, //Encounter and gender
    0x0, // sprite
    LANGDEP(PSTRING("Marq"), PSTRING("Marq")),
    {
      ITEM_TRANK,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2c
  },
  {
    //Trainer 0x2d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ROCKER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x11, // sprite
    LANGDEP(PSTRING("Udo"), PSTRING("Udo")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2d
  },
  {
    //Trainer 0x2e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x4,
      true
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Annie"), PSTRING("Annie")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2e
  },
  {
    //Trainer 0x2f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {
      0x2,
      true
    }, //Encounter and gender
    0x17, // sprite
    LANGDEP(PSTRING("Joachim"), PSTRING("Joachim")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x2f
  },
  {
    //Trainer 0x30
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER,
    {
      0x2,
      false
    }, //Encounter and gender
    0x33, // sprite
    LANGDEP(PSTRING("Lobin"), PSTRING("Lobin")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x30
  },
  {
    //Trainer 0x31
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {
      0x4,
      false
    }, //Encounter and gender
    0x30, // sprite
    LANGDEP(PSTRING("Ran"), PSTRING("Ran")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x31
  },
  {
    //Trainer 0x32
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Alois"), PSTRING("Alois")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x32
  },
  {
    //Trainer 0x33
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TRIATHLET,
    {
      0x1,
      false
    }, //Encounter and gender
    0x29, // sprite
    LANGDEP(PSTRING("Seymour"), PSTRING("Seymour")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x33
  },
  {
    //Trainer 0x34
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER2,
    {
      0x1,
      false
    }, //Encounter and gender
    0x52, // sprite
    LANGDEP(PSTRING("Nedd"), PSTRING("Nedd")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x34
  },
  {
    //Trainer 0x35
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHOENHEIT,
    {
      0x1,
      false
    }, //Encounter and gender
    0x62, // sprite
    LANGDEP(PSTRING("Andrea"), PSTRING("Andrea")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x35
  },
  {
    //Trainer 0x36
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x0,
      false
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Jeyne"), PSTRING("Jeyne")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x36
  },
  {
    //Trainer 0x37
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER2,
    {
      0x0,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Phyllip"), PSTRING("Phyllip")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x37
  },
  {
    //Trainer 0x38
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x3b, // sprite
    LANGDEP(PSTRING("Mara"), PSTRING("Mara")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    5, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x38
  },
  {
    //Trainer 0x39
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER,
    {
      0x3,
      true
    }, //Encounter and gender
    0x33, // sprite
    LANGDEP(PSTRING("Eliot"), PSTRING("Eliot")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x39
  },
  {
    //Trainer 0x3a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GOERE2,
    {
      0x0,
      false
    }, //Encounter and gender
    0x54, // sprite
    LANGDEP(PSTRING("Charlie"), PSTRING("Charlie")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3a
  },
  {
    //Trainer 0x3b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x8, // sprite
    LANGDEP(PSTRING("Leon"), PSTRING("Leon")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3b
  },
  {
    //Trainer 0x3c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TRIATHLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x2a, // sprite
    LANGDEP(PSTRING("Gerda"), PSTRING("Gerda")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3c
  },
  {
    //Trainer 0x3d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x33, // sprite
    LANGDEP(PSTRING("Lore"), PSTRING("Lore")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3d
  },
  {
    //Trainer 0x3e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER2,
    {
      0x1,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Jeff"), PSTRING("Jeff")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3e
  },
  {
    //Trainer 0x3f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER3,
    {
      0x1,
      false
    }, //Encounter and gender
    0x13, // sprite
    LANGDEP(PSTRING("Miguel"), PSTRING("Miguel")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x3f
  },
  {
    //Trainer 0x40
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {
      0x1,
      true
    }, //Encounter and gender
    0x3b, // sprite
    LANGDEP(PSTRING("Ismeralda"), PSTRING("Ismeralda")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    5, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x40
  },
  {
    //Trainer 0x41
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER2,
    {
      0x0,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Robert"), PSTRING("Robert")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x41
  },
  {
    //Trainer 0x42
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x1,
      true
    }, //Encounter and gender
    0x5e, // sprite
    LANGDEP(PSTRING("Alen"), PSTRING("Alen")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x42
  },
  {
    //Trainer 0x43
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {
      0x5,
      true
    }, //Encounter and gender
    0x14, // sprite
    LANGDEP(PSTRING("Merrik"), PSTRING("Merrik")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x43
  },
  {
    //Trainer 0x44
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x5,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel N."), PSTRING("Rüpel N.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x44
  },
  {
    //Trainer 0x45
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {
      0x7,
      true
    }, //Encounter and gender
    0x3c, // sprite
    LANGDEP(PSTRING("Remus"), PSTRING("Remus")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x45
  },
  {
    //Trainer 0x46
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x7,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x46
  },
  {
    //Trainer 0x47
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_CAMPER,
    {
      0x7,
      true
    }, //Encounter and gender
    0x57, // sprite
    LANGDEP(PSTRING("Erna"), PSTRING("Erna")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x47
  },
  {
    //Trainer 0x48
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x1,
      false
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel I."), PSTRING("Rüpel I.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x48
  },
  {
    //Trainer 0x49
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel P."), PSTRING("Rüpel P.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x49
  },
  {
    //Trainer 0x4a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0xb,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel N."), PSTRING("Rüpel N.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4a
  },
  {
    //Trainer 0x4b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x2,
      false
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel D."), PSTRING("Rüpel D.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4b
  },
  {
    //Trainer 0x4c
    true, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VIOLET_VORS,
    {
      0x4,
      true
    }, //Encounter and gender
    0x1b, // sprite
    LANGDEP(PSTRING("Rin"), PSTRING("Rin")),
    {
      ITEM_HYPERTRANK,
      ITEM_HYPERHEILER,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4c
  },
  {
    //Trainer 0x4d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x8,
      false
    }, //Encounter and gender
    0x43, // sprite
    LANGDEP(PSTRING("Barneby"), PSTRING("Barneby")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4d
  },
  {
    //Trainer 0x4e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER,
    {
      0x6,
      false
    }, //Encounter and gender
    0x24, // sprite
    LANGDEP(PSTRING("Wolffie"), PSTRING("Wolffie")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4e
  },
  {
    //Trainer 0x4f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_CAMPER,
    {
      0x6,
      true
    }, //Encounter and gender
    0x57, // sprite
    LANGDEP(PSTRING("Korinna"), PSTRING("Korinna")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x4f
  },
  {
    //Trainer 0x50
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x7,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Kalleh"), PSTRING("Kalleh")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x50
  },
  {
    //Trainer 0x51
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GOERE,
    {
      0x7,
      false
    }, //Encounter and gender
    0x54, // sprite
    LANGDEP(PSTRING("Karmina"), PSTRING("Karmina")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x51
  },
  {
    //Trainer 0x52
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x43, // sprite
    LANGDEP(PSTRING("Walltyr"), PSTRING("Walltyr")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x52
  },
  {
    //Trainer 0x53
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHULKIND,
    {
      0x1,
      false
    }, //Encounter and gender
    0x54, // sprite
    LANGDEP(PSTRING("Sophie"), PSTRING("Sophie")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x53
  },
  {
    //Trainer 0x54
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {
      0x0,
      false
    }, //Encounter and gender
    0x30, // sprite
    LANGDEP(PSTRING("Maya"), PSTRING("Maya")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x54
  },
  {
    //Trainer 0x55
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x1,
      true
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Silkye"), PSTRING("Silkye")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x55
  },
  {
    //Trainer 0x56
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_STREBER,
    {
      0x7a,
      false
    }, //Encounter and gender
    0x59, // sprite
    LANGDEP(PSTRING("Waynis"), PSTRING("Waynis")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x56
  },
  {
    //Trainer 0x57
    false, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_EXPERTE,
    {
      0xa,
      true
    }, //Encounter and gender
    0x23, // sprite
    LANGDEP(PSTRING("Franziska"), PSTRING("Franziska")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x57
  },
  {
    //Trainer 0x58
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_RUINENMANIAC,
    {
      0xa,
      false
    }, //Encounter and gender
    0x4, // sprite
    LANGDEP(PSTRING("Drago"), PSTRING("Drago")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x58
  },
  {
    //Trainer 0x59
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Rudolf"), PSTRING("Rudolf")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x59
  },
  {
    //Trainer 0x5a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_DIEB,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5c, // sprite
    LANGDEP(PSTRING("Merreck"), PSTRING("Merreck")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5a
  },
  {
    //Trainer 0x5b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER2,
    {
      0x0,
      false
    }, //Encounter and gender
    0x52, // sprite
    LANGDEP(PSTRING("Thyma"), PSTRING("Thyma")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5b
  },
  {
    //Trainer 0x5c
    true, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x39, // sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {
      ITEM_SUPERTRANK,
      ITEM_SUPERTRANK,
      ITEM_HYPERHEILER,
      ITEM_HYPERHEILER
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5c
  },
  {
    //Trainer 0x5d
    true, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x39, // sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {
      ITEM_SUPERTRANK,
      ITEM_SUPERTRANK,
      ITEM_HYPERHEILER,
      ITEM_HYPERHEILER
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5d
  },
  {
    //Trainer 0x5e
    true, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
	TRAINERCLASS_PKMN_TRAINER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x39, // sprite
    LANGDEP(PSTRING("Maike"), PSTRING("Maike")),
    {
      ITEM_SUPERTRANK,
      ITEM_SUPERTRANK,
      ITEM_HYPERHEILER,
      ITEM_HYPERHEILER
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_PREFER_CERTAIN_MOVES,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5e
  },
  {
    //Trainer 0x5f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GOERE,
    {
      0x0,
      true
    }, //Encounter and gender
    0x54, // sprite
    LANGDEP(PSTRING("Janina"), PSTRING("Janina")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x5f
  },
  {
    //Trainer 0x60
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Gunnward"), PSTRING("Gunnward")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x60
  },
  {
    //Trainer 0x61
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {
      0x28,
      true
    }, //Encounter and gender
    0x3b, // sprite
    LANGDEP(PSTRING("Henrietta"), PSTRING("Henrietta")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    5, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x61
  },
  {
    //Trainer 0x62
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER3,
    {
      0x0,
      false
    }, //Encounter and gender
    0x56, // sprite
    LANGDEP(PSTRING("Sonnwald"), PSTRING("Sonnwald")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x62
  },
  {
    //Trainer 0x63
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_POKEMANIAC,
    {
      0x0,
      false
    }, //Encounter and gender
    0x36, // sprite
    LANGDEP(PSTRING("Valeyntyn"), PSTRING("Valeyntyn")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x63
  },
  {
    //Trainer 0x64
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x64
  },
  {
    //Trainer 0x65
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x33, // sprite
    LANGDEP(PSTRING("Janie"), PSTRING("Janie")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x65
  },
  {
    //Trainer 0x66
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x3d, // sprite
    LANGDEP(PSTRING("Ismera"), PSTRING("Ismera")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x66
  },
  {
    //Trainer 0x67
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x53, // sprite
    LANGDEP(PSTRING("Eusjean"), PSTRING("Eusjean")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x67
  },
  {
    //Trainer 0x68
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHNOESEL,
    {
      0x0,
      false
    }, //Encounter and gender
    0xd, // sprite
    LANGDEP(PSTRING("Rudderich"), PSTRING("Rudderich")),
    {
      ITEM_TOP_GENESUNG,
      ITEM_TOP_GENESUNG,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x68
  },
  {
    //Trainer 0x69
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PSYCHO,
    {
      0x0,
      false
    }, //Encounter and gender
    0x16, // sprite
    LANGDEP(PSTRING("Attilia"), PSTRING("Attilia")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x69
  },
  {
    //Trainer 0x6a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Gangolf"), PSTRING("Gangolf")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6a
  },
  {
    //Trainer 0x6b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x2e, // sprite
    LANGDEP(PSTRING("Abduhl"), PSTRING("Abduhl")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6b
  },
  {
    //Trainer 0x6c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x1, // sprite
    LANGDEP(PSTRING("Gerrie"), PSTRING("Gerrie")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6c
  },
  {
    //Trainer 0x6d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x2, // sprite
    LANGDEP(PSTRING("Marja"), PSTRING("Marja")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6d
  },
  {
    //Trainer 0x6e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x2, // sprite
    LANGDEP(PSTRING("Balla"), PSTRING("Balla")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6e
  },
  {
    //Trainer 0x6f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_AROMALADY,
    {
      0x0,
      true
    }, //Encounter and gender
    0x3, // sprite
    LANGDEP(PSTRING("Ruanna"), PSTRING("Ruanna")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x6f
  },
  {
    //Trainer 0x70
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_MECHANIKER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5d, // sprite
    LANGDEP(PSTRING("Tommas"), PSTRING("Tommas")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x70
  },
  {
    //Trainer 0x71
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x2, // sprite
    LANGDEP(PSTRING("Hannah"), PSTRING("Hannah")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x71
  },
  {
    //Trainer 0x72
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x2, // sprite
    LANGDEP(PSTRING("Sophy"), PSTRING("Sophy")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x72
  },
  {
    //Trainer 0x73
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x1, // sprite
    LANGDEP(PSTRING("Rell"), PSTRING("Rell")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x73
  },
  {
    //Trainer 0x74
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {
      0x0,
      true
    }, //Encounter and gender
    0x30, // sprite
    LANGDEP(PSTRING("Maggy"), PSTRING("Maggy")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x74
  },
  {
    //Trainer 0x75
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VOGELFAENGER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x68, // sprite
    LANGDEP(PSTRING("Kriss"), PSTRING("Kriss")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x75
  },
  {
    //Trainer 0x76
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PSYCHO,
    {
      0x1,
      false
    }, //Encounter and gender
    0x64, // sprite
    LANGDEP(PSTRING("Coal"), PSTRING("Coal")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x76
  },
  {
    //Trainer 0x77
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {
      0x1,
      false
    }, //Encounter and gender
    0x7b, // sprite
    LANGDEP(PSTRING("Fraunk"), PSTRING("Fraunk")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x77
  },
  {
    //Trainer 0x78
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x5e, // sprite
    LANGDEP(PSTRING("Sheldon"), PSTRING("Sheldon")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x78
  },
  {
    //Trainer 0x79
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {
      0x1,
      false
    }, //Encounter and gender
    0x69, // sprite
    LANGDEP(PSTRING("Rashi"), PSTRING("Rashi")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x79
  },
  {
    //Trainer 0x7a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {
      0x1,
      true
    }, //Encounter and gender
    0x30, // sprite
    LANGDEP(PSTRING("Mayama"), PSTRING("Mayama")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7a
  },
  {
    //Trainer 0x7b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ANGLER,
    {
      0x1,
      true
    }, //Encounter and gender
    0x5e, // sprite
    LANGDEP(PSTRING("Doran"), PSTRING("Doran")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7b
  },
  {
    //Trainer 0x7c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {
      0x1,
      true
    }, //Encounter and gender
    0x69, // sprite
    LANGDEP(PSTRING("Richard"), PSTRING("Richard")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7c
  },
  {
    //Trainer 0x7d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_REVOLUTIONAER,
    {
      0x1,
      true
    }, //Encounter and gender
    0x2, // sprite
    LANGDEP(PSTRING("Elsa"), PSTRING("Elsa")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7d
  },
  {
    //Trainer 0x7e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x1,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Gerrad"), PSTRING("Gerrad")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7e
  },
  {
    //Trainer 0x7f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GOERE2,
    {
      0x1,
      true
    }, //Encounter and gender
    0x54, // sprite
    LANGDEP(PSTRING("Livia"), PSTRING("Livia")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x7f
  },
  {
    //Trainer 0x80
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {
      0x1,
      false
    }, //Encounter and gender
    0x30, // sprite
    LANGDEP(PSTRING("Loretta"), PSTRING("Loretta")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x80
  },
  {
    //Trainer 0x81
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {
      0x1,
      false
    }, //Encounter and gender
    0x69, // sprite
    LANGDEP(PSTRING("Tobish"), PSTRING("Tobish")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x81
  },
  {
    //Trainer 0x82
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEMPFERIN,
    {
      0x1,
      true
    }, //Encounter and gender
    0x30, // sprite
    LANGDEP(PSTRING("Christina"), PSTRING("Christina")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x82
  },
  {
    //Trainer 0x83
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHWARZGURT,
    {
      0x1,
      true
    }, //Encounter and gender
    0x69, // sprite
    LANGDEP(PSTRING("Gerd"), PSTRING("Gerd")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x83
  },
  {
    //Trainer 0x84
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_FORSCHERIN,
    {
      0x1,
      true
    }, //Encounter and gender
    0x5, // sprite
    LANGDEP(PSTRING("Elise"), PSTRING("Elise")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    6, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x84
  },
  {
    //Trainer 0x85
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_RUINENMANIAC,
    {
      0x1,
      true
    }, //Encounter and gender
    0x4, // sprite
    LANGDEP(PSTRING("Fellicho"), PSTRING("Fellicho")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x85
  },
  {
    //Trainer 0x86
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {
      0x0,
      false
    }, //Encounter and gender
    0x17, // sprite
    LANGDEP(PSTRING("Nikolas"), PSTRING("Nikolas")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x86
  },
  {
    //Trainer 0x87
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6e, // sprite
    LANGDEP(PSTRING("Lorenz"), PSTRING("Lorenz")),
    {
      ITEM_TOP_GENESUNG,
      ITEM_TOP_GENESUNG,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x87
  },
  {
    //Trainer 0x88
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_KAEFERSAMMLER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x42, // sprite
    LANGDEP(PSTRING("Richardo"), PSTRING("Richardo")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x88
  },
  {
    //Trainer 0x89
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WOLKENREITER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x47, // sprite
    LANGDEP(PSTRING("Alyssa"), PSTRING("Alyssa")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x89
  },
  {
    //Trainer 0x8a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WOLKENREITER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x48, // sprite
    LANGDEP(PSTRING("Alesion"), PSTRING("Alesion")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8a
  },
  {
    //Trainer 0x8b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_STREBER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x59, // sprite
    LANGDEP(PSTRING("Jesse"), PSTRING("Jesse")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8b
  },
  {
    //Trainer 0x8c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WOLKENREITER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x47, // sprite
    LANGDEP(PSTRING("Elya"), PSTRING("Elya")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8c
  },
  {
    //Trainer 0x8d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8d
  },
  {
    //Trainer 0x8e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel J."), PSTRING("Rüpel J.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8e
  },
  {
    //Trainer 0x8f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      true
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel G."), PSTRING("Rüpel G.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x8f
  },
  {
    //Trainer 0x90
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel S."), PSTRING("Rüpel S.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x90
  },
  {
    //Trainer 0x91
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x49, // sprite
    LANGDEP(PSTRING("Elite V."), PSTRING("Elite V.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x91
  },
  {
    //Trainer 0x92
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_HITZKOPF,
    {
      0x0,
      false
    }, //Encounter and gender
    0x12, // sprite
    LANGDEP(PSTRING("Raphael"), PSTRING("Raphael")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x92
  },
  {
    //Trainer 0x93
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_CAMPER2,
    {
      0x0,
      false
    }, //Encounter and gender
    0x56, // sprite
    LANGDEP(PSTRING("Tasso"), PSTRING("Tasso")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x93
  },
  {
    //Trainer 0x94
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHOENHEIT,
    {
      0x0,
      false
    }, //Encounter and gender
    0x62, // sprite
    LANGDEP(PSTRING("Cyarla"), PSTRING("Cyarla")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x94
  },
  {
    //Trainer 0x95
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_CAMPER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x57, // sprite
    LANGDEP(PSTRING("Issilde"), PSTRING("Issilde")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x95
  },
  {
    //Trainer 0x96
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GENTLEMAN,
    {
      0x2,
      false
    }, //Encounter and gender
    0x17, // sprite
    LANGDEP(PSTRING("Gewert"), PSTRING("Gewert")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x96
  },
  {
    //Trainer 0x97
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_STREBER,
    {
      0x2,
      true
    }, //Encounter and gender
    0x59, // sprite
    LANGDEP(PSTRING("Crissilas"), PSTRING("Crissilas")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x97
  },
  {
    //Trainer 0x98
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_RANGER,
    {
      0x2,
      true
    }, //Encounter and gender
	0x3d, // sprite
    LANGDEP(PSTRING("Hedwig"), PSTRING("Hedwig")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x98
  },
  {
    //Trainer 0x99
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_GOERE,
    {
      0x2,
      true
    }, //Encounter and gender
    0x54, // sprite
    LANGDEP(PSTRING("Ruth"), PSTRING("Ruth")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x99
  },
  {
    //Trainer 0x9a
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x2,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Ingo"), PSTRING("Ingo")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9a
  },
  {
    //Trainer 0x9b
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_SCHULKIND,
    {
      0x2,
      true
    }, //Encounter and gender
    0x1e, // sprite
    LANGDEP(PSTRING("Marija"), PSTRING("Marija")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9b
  },
  {
    //Trainer 0x9c
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {
      0x2,
      true
    }, //Encounter and gender
    0x6f, // sprite
    LANGDEP(PSTRING("Jana"), PSTRING("Jana")),
    {
      ITEM_TOP_GENESUNG,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9c
  },
  {
    //Trainer 0x9d
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_LADY2,
    {
      0x2,
      true
    }, //Encounter and gender
    0x92, // sprite
    LANGDEP(PSTRING("Nathalie"), PSTRING("Nathalie")),
    {
      ITEM_TOP_GENESUNG,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9d
  },
  {
    //Trainer 0x9e
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_DIEB,
    {
      0x0,
      true
    }, //Encounter and gender
    0x5c, // sprite
    LANGDEP(PSTRING("Rüdigar"), PSTRING("Rüdigar")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9e
  },
  {
    //Trainer 0x9f
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PKMN_ZUECHTER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x3b, // sprite
    LANGDEP(PSTRING("Hannya"), PSTRING("Hannya")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    6, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_x9f
  },
  {
    //Trainer 0xa0
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_WANDERER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x5a, // sprite
    LANGDEP(PSTRING("Haggron"), PSTRING("Haggron")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa0
  },
  {
    //Trainer 0xa1
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_PICKNICKER,
    {
      0x0,
      false
    }, //Encounter and gender
    0x56, // sprite
    LANGDEP(PSTRING("Joseppo"), PSTRING("Joseppo")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa1
  },
  {
    //Trainer 0xa2
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_HITZKOPF,
    {
      0x0,
      false
    }, //Encounter and gender
    0x12, // sprite
    LANGDEP(PSTRING("Taryuk"), PSTRING("Taryuk")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa2
  },
  {
    //Trainer 0xa3
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel M."), PSTRING("Rüpel M.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa3
  },
  {
    //Trainer 0xa4
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel R."), PSTRING("Rüpel R.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa4
  },
  {
    //Trainer 0xa5
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel L."), PSTRING("Rüpel L.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa5
  },
  {
    //Trainer 0xa6
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel Y."), PSTRING("Rüpel Y.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa6
  },
  {
    //Trainer 0xa7
    true, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel D."), PSTRING("Rüpel D.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa7
  },
  {
    //Trainer 0xa8
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel L."), PSTRING("Rüpel L.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    1, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa8
  },
  {
    //Trainer 0xa9
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_ASS_TRAINER,
    {
      0x0,
      true
    }, //Encounter and gender
    0x6f, // sprite
    LANGDEP(PSTRING("Curris"), PSTRING("Curris")),
    {
      ITEM_TOP_GENESUNG,
      ITEM_TOP_GENESUNG,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_STRATEGY_NONE,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xa9
  },
  {
    //Trainer 0xaa
    true, // Custom moves
    true, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_VIOLET_VORS,
    {
      0x3,
      false
    }, //Encounter and gender
    0x60, // sprite
    LANGDEP(PSTRING("Mistral"), PSTRING("Mistral")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    BATTLE_WITH_HANDICAP | BATTLE_DOUBLE,
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_CONSIDER_PERECNTUAL_HP,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xaa
  },
  {
    //Trainer 0xab
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEENAGER,
    {
      0x3,
      false
    }, //Encounter and gender
    0x52, // sprite
    LANGDEP(PSTRING("Dario"), PSTRING("Dario")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    4, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xab
  },
  {
    //Trainer 0xac
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_HITZKOPF,
    {
      0x3,
      false
    }, //Encounter and gender
    0x12, // sprite
    LANGDEP(PSTRING("Gerrit"), PSTRING("Gerrit")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xac
  },
  {
    //Trainer 0xad
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x3,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel"), PSTRING("Rüpel")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xad
  },
  {
    //Trainer 0xae
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x49, // sprite
    LANGDEP(PSTRING("Elite H."), PSTRING("Elite H.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xae
  },
  {
    //Trainer 0xaf
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x4a, // sprite
    LANGDEP(PSTRING("Elite M."), PSTRING("Elite M.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xaf
  },
  {
    //Trainer 0xb0
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      true
    }, //Encounter and gender
    0x4e, // sprite
    LANGDEP(PSTRING("Rüpel K."), PSTRING("Rüpel K.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    2, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xb0
  },
  {
    //Trainer 0xb1
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x0,
      false
    }, //Encounter and gender
    0x6d, // sprite
    LANGDEP(PSTRING("Rüpel G."), PSTRING("Rüpel G.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xb1
  },
  {
    //Trainer 0xb2
    false, // Custom moves
    false, // Custom items
    0x0, // field_0_filler
    TRAINERCLASS_TEAM_VIOLET,
    {
      0x3,
      true
    }, //Encounter and gender
    0x49, // sprite
    LANGDEP(PSTRING("Elite N."), PSTRING("Elite N.")),
    {
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE,
      ITEM_NONE
    },
    false, //Dual battle
    TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
    0x0, // field_1E
    3, // Pokemon Count
    0x0, // field_21
    0x0, // field_22
    0x0, // field_23
    (trainer_pokemon * ) trainer_party_xb2
  },
  {
    //Trainer 0xb3
    false, false, 0,
	TRAINERCLASS_RIVALE,
	{},
	106,
	LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	0, // no dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_SUPER_EFFECTIVE,
	0,
	2, // pkmn cnt
	0, 0, 0,
	(trainer_pokemon*) trainer_party_xb3
  },
  {
    //Trainer 0xb4
    false, false, 0,
	TRAINERCLASS_RIVALE,
	{},
	106,
	LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	0, // no dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_SUPER_EFFECTIVE,
	0,
	2, // pkmn cnt
	0, 0, 0,
	(trainer_pokemon*) trainer_party_xb4
  },
  {
    //Trainer 0xb5
    false, false, 0,
	TRAINERCLASS_RIVALE,
	{},
	106,
	LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
	{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
	0, // no dual battle
	TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_SUPER_EFFECTIVE,
	0,
	2, // pkmn cnt
	0, 0, 0,
	(trainer_pokemon*) trainer_party_xb5
  },{
		//Trainer 0xb6
		true,// Custom moves
		true,// Custom items
		0x0,// field_0_filler
		TRAINERCLASS_ARENALEITER,
		{0x0, false},//Encounter and gender
		0x74,// sprite
		LANGDEP(PSTRING("Lester"), PSTRING("Lester")),
		{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_NONE, ITEM_NONE},
		BATTLE_WITH_HANDICAP,
		TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
		0x0,// field_1E
		3,// Pokemon Count
		0x0,// field_21
		0x0,// field_22
		0x0,// field_23
		(trainer_pokemon*) trainer_party_xb6
	},{
		//Trainer 0xb7
		true,// Custom moves
		true,// Custom items
		0x0,// field_0_filler
		TRAINERCLASS_ARENALEITER,
		{0x1, true},//Encounter and gender
		0x75,// sprite
		LANGDEP(PSTRING("Rosalie"), PSTRING("Rosalie")),
		{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER},
		BATTLE_WITH_HANDICAP,
		TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
		0x0,// field_1E
		4,// Pokemon Count
		0x0,// field_21
		0x0,// field_22
		0x0,// field_23
		(trainer_pokemon*) trainer_party_xb7
	},{
		//Trainer 0xb8
		true,// Custom moves
		true,// Custom items
		0x0,// field_0_filler
		TRAINERCLASS_ARENALEITER,
		{0x0, false},//Encounter and gender
		0x76,// sprite
		LANGDEP(PSTRING("Manuel"), PSTRING("Manuel")),
		{ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERTRANK, ITEM_SUPERTRANK},
		BATTLE_WITH_HANDICAP,
		TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
		0x0,// field_1E
		ARRAY_COUNT(trainer_party_xb8),// Pokemon Count
		0x0,// field_21
		0x0,// field_22
		0x0,// field_23
		(trainer_pokemon*) trainer_party_xb8
	},{
		//Trainer 0xb9
		true,// Custom moves
		true,// Custom items
		0x0,// field_0_filler
		TRAINERCLASS_RIVALE,
		{0x0, false},//Encounter and gender
		0x6a,// sprite
		LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
		{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
		false,//Dual battle
		TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
		0x0,// field_1E
		3,// Pokemon Count
		0x0,// field_21
		0x0,// field_22
		0x0,// field_23
		(trainer_pokemon*) trainer_party_xb9
	},{
		//Trainer 0xba
		true,// Custom moves
		true,// Custom items
		0x0,// field_0_filler
		TRAINERCLASS_RIVALE,
		{0x0, false},//Encounter and gender
		0x6a,// sprite
		LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
		{ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
		false,//Dual battle
		TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
		0x0,// field_1E
		3,// Pokemon Count
		0x0,// field_21
		0x0,// field_22
		0x0,// field_23
		(trainer_pokemon*) trainer_party_xba
	},{
		//Trainer 0xbb
		true,// Custom moves
		true,// Custom items
		0x0,// field_0_filler
		TRAINERCLASS_RIVALE,
		{0x0, false},//Encounter and gender
		0x6a,// sprite
		LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
		{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
		false,//Dual battle
		TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
		0x0,// field_1E
		3,// Pokemon Count
		0x0,// field_21
		0x0,// field_22
		0x0,// field_23
		(trainer_pokemon*) trainer_party_xbb
	},{
			//Trainer 0xbc
			true,// Custom moves
			true,// Custom items
			0x0,// field_0_filler
			TRAINERCLASS_RIVALE,
			{0x0, false},//Encounter and gender
			0x6a,// sprite
			LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
			{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
			false,//Dual battle
			TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
			0x0,// field_1E
			4,// Pokemon Count
			0x0,// field_21
			0x0,// field_22
			0x0,// field_23
			(trainer_pokemon*) trainer_party_xbc
		},{
			//Trainer 0xbd
			true,// Custom moves
			true,// Custom items
			0x0,// field_0_filler
			TRAINERCLASS_RIVALE,
			{0x0, false},//Encounter and gender
			0x6a,// sprite
			LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
			{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
			false,//Dual battle
			TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
			0x0,// field_1E
			4,// Pokemon Count
			0x0,// field_21
			0x0,// field_22
			0x0,// field_23
			(trainer_pokemon*) trainer_party_xbd
		},{
			//Trainer 0xbe
			true,// Custom moves
			true,// Custom items
			0x0,// field_0_filler
			TRAINERCLASS_RIVALE,
			{0x0, false},//Encounter and gender
			0x6a,// sprite
			LANGDEP(PSTRING("Björn"), PSTRING("Björn")),
			{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE},
			false,//Dual battle
			TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
			0x0,// field_1E
			4,// Pokemon Count
			0x0,// field_21
			0x0,// field_22
			0x0,// field_23
			(trainer_pokemon*) trainer_party_xbe
		},
		[0xbf] = {
				.trainerclass = TRAINERCLASS_HITZKOPF, .sprite = 0x12,
				.encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Frenzis"),
						PSTRING("Frencis")), .pokemon_cnt = 3,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_xbf_inferior_gym
		},
		[0xc0] = {
				.trainerclass = TRAINERCLASS_SCHOENHEIT, .sprite = 0xC,
				.encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Iylsa"),
						PSTRING("Iylsa")), .pokemon_cnt = 1,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_xc0_inferior_gym
		},
		[0xc1] = {
				.trainerclass = TRAINERCLASS_PICKNICKER3, .sprite = 0x56,
				.encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Ferrys"),
						PSTRING("Ferrys")), .pokemon_cnt = 2,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_xc1_inferior_gym
		},
		[0xc2] = {
				.trainerclass = TRAINERCLASS_GENTLEMAN, .sprite = 0x17,
				.encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Olaver"),
						PSTRING("Olaver")), .pokemon_cnt = 3,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_xc2_inferior_gym
		},
		[0xc3] = {
				.trainerclass = TRAINERCLASS_DRACHENPROFI, .sprite = 45,
				.encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Vismayr"),
						PSTRING("Vismayr")), .pokemon_cnt = 1,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_xc3_inferior_gym
		},
		[0xc4] = {
				.trainerclass = TRAINERCLASS_ARENALEITER, .sprite = 121,
				.encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Igva"),
						PSTRING("Igva")), .pokemon_cnt = 4,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
				.items = {ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_SUPERTRANK, ITEM_NONE},
				.party = (trainer_pokemon*) trainer_party_xc4_inferior_gymleader,
				.uses_custom_items = true, .uses_custom_moves = true,
        .battle_state = BATTLE_WITH_HANDICAP,
		},
		[0xc5] = {
		    .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 16,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Puk"),
            PSTRING("Puc")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xc5_route_8_trainer_0
		},
    [0xc6] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Lanzelod"),
            PSTRING("Lancelod")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xc6_route_8_trainer_1
    },
    [0xc7] = {
        .trainerclass = TRAINERCLASS_KAEFERSAMMLER, .sprite = 66,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Myrko"),
            PSTRING("Myrco")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xc7_route_8_trainer_2
    },
    [0xc8] = {
        .trainerclass = TRAINERCLASS_PKMN_ZUECHTER, .sprite = 59,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Kathy"),
            PSTRING("Kathy")), .pokemon_cnt = 5,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xc8_route_8_trainer_3
    },
    [0xc9] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 42,
        .encounter_and_gender = {4, 1}, .name = LANGDEP(PSTRING("Nyna"),
            PSTRING("Nyna")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xc9_route_8_trainer_4
    },
    [0xCA] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Thereza"),
            PSTRING("Thereza")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xcA_route_9_trainer_0
    },
    [0xCB] = {
        .trainerclass = TRAINERCLASS_PLANSCHER, .sprite = 7,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Weyrner"),
            PSTRING("Weyrner")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xcb_route_9_trainer_1
    },
    [0xCC] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Kylian"),
            PSTRING("Kylian")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xcc_route_9_trainer_2
    },
    [0xCD] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Selena"),
            PSTRING("Selena")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xcd_route_9_trainer_3
    },
    [0xCE] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Doug"),
            PSTRING("Doug")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xce_route_9_trainer_4
    },
    [0xCF] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 41,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Jeyns"),
            PSTRING("Jeyns")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xcf_route_9_trainer_5
    },
    [0xD0] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Maara"),
            PSTRING("Maara")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd0_route_9_trainer_6
    },
    [0xD1] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Olyvia"),
            PSTRING("Olyvia")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd1_route_9_trainer_7
    },
    [0xD2] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Meysut"),
            PSTRING("Meysut")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd2_route_9_trainer_8
    },
    [0xD3] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Kyarl"),
            PSTRING("Kyarl")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd3_route_9_trainer_9
    },
    [0xD4] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Ozlav"),
            PSTRING("Ozlav")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd4_route_9_trainer_10
    },
    [0xD5] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Kreanita"),
            PSTRING("Creanita")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd5_route_9_trainer_11
    },
    [0xD6] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Nimba"),
            PSTRING("Nimba")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd6_route_9_trainer_12
    },
    [0xD7] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Myatt"),
            PSTRING("Myatt")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd7_route_9_trainer_13
    },
    [0xD8] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Joyanna"),
            PSTRING("Joyanna")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd8_route_10_trainer_0
    },
    [0xD9] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Mats"),
            PSTRING("Mats")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xd9_route_10_trainer_1
    },
    [0xDA] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Jaycob"),
            PSTRING("Jaycob")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xda_route_10_trainer_2
    },
    [0xDB] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Jesper"),
            PSTRING("Jesper")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xdb_route_10_trainer_3
    },
    [0xDC] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 44,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Irma"),
            PSTRING("Irma")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xdc_route_10_trainer_4
    },
    [0xDD] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Heleyna"),
            PSTRING("Heleyna")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xdd_route_10_trainer_5
    },
    [0xDE] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 43,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Herybert"),
            PSTRING("Herybert")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xde_route_10_trainer_6
    },
    [0xDF] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 16,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Wazzly"),
            PSTRING("Wazzly")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xdf_route_10_trainer_7
    },
    [0xE0] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 71,
        .encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Namira"),
            PSTRING("Namira")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe0_route_10_trainer_8
    },
    [0xE1] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Shev"),
            PSTRING("Shev")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe1_route_11_trainer_0
    },
    [0xE2] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 41,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Claus"),
            PSTRING("Claus")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe2_route_11_trainer_1
    },
    [0xE3] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Herra"),
            PSTRING("Herra")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe3_route_11_trainer_2
    },
    [0xE4] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Antonin"),
            PSTRING("Antonin")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe4_route_11_trainer_3
    },
    [0xE5] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Myrra"),
            PSTRING("Myrra")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe5_route_11_trainer_4
    },
    [0xE6] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Petrim"),
            PSTRING("Petrim")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe6_route_11_trainer_5
    },
    [0xE7] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 44,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Cory"),
            PSTRING("Cory")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe7_route_11_trainer_6
    },
    [0xE8] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Voyja"),
            PSTRING("Voyja")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe8_route_11_trainer_7
    },
    [0xE9] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Luccini"),
            PSTRING("Luccini")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xe9_route_11_trainer_8
    },
    [0xEA] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Elsa"),
            PSTRING("Elsa")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xea_forest_cemetery_trainer_0
    },
    [0xEB] = {
        .trainerclass = TRAINERCLASS_KAEFERSAMMLER, .sprite = 66,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Distas"),
            PSTRING("Distas")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xeb_forest_cemetery_trainer_1
    },
    [0xEC] = {
        .trainerclass = TRAINERCLASS_EXORZISTIN, .sprite = 126,
        .encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Ureia"),
            PSTRING("Ureya")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xec_forest_cemetery_trainer_2
    },
    [0xED] = {
        .trainerclass = TRAINERCLASS_ASS_TRAINER, .sprite = 8,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Deiter"),
            PSTRING("Deiter")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_SUPER_EFFECTIVE | TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xed_forest_cemetery_trainer_3,
        .items = {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE}
    },
    [0xEE] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Erica"),
            PSTRING("Erica")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xee_forest_cemetery_trainer_4
    },
    [0xEF] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Nepumuk"),
            PSTRING("Nepumuk")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xef_forest_cemetery_trainer_5
    },
    [0xF0] = {
        .trainerclass = TRAINERCLASS_EXORZISTIN, .sprite = 126,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Aurelia"),
            PSTRING("Aurelia")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xf0_forest_cemetery_trainer_6
    },
    [0xF1] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 78,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Rüpel H."),
            PSTRING("Grunt H.")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xf1_forest_cemetery_trainer_7
    },
    [0xF2] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 109,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Rüpel F."),
            PSTRING("Grunt F.")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xf2_forest_cemetery_trainer_8
    },
    [0xF3] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Nemo"),
            PSTRING("Nemo")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xF4] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Myrko"),
            PSTRING("Myrko")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xF5] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Obrast"),
            PSTRING("Obrast")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xF6] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Johayn"),
            PSTRING("Johayn")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xF7] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Gulyra"),
            PSTRING("Gulyra")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xF8] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Cassna"),
            PSTRING("Cassna")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xF9] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Ana"),
            PSTRING("Ana")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xFA] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Andreaza"),
            PSTRING("Andreaza")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xFB] = {
        .trainerclass = TRAINERCLASS_GENTLEMAN, .sprite = 23,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Sergej"),
            PSTRING("Sergej")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0xFC] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Debora"),
            PSTRING("Debora")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xfc_route_12_trainer_0
    },
    [0xFD] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Eron"),
            PSTRING("Eron")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xfd_route_12_trainer_1
    },
    [0xFE] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Garciala"),
            PSTRING("Garciala")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_xfe_route_12_trainer_2
    },
    [0xFF] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Obola"),
            PSTRING("Obola")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_xff_route_12_trainer_3,
        .items = {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE}
    },
    [0x100] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Opeter"),
            PSTRING("Opeter")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x100_route_12_trainer_4
    },
    [0x101] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Nadyine"),
            PSTRING("Nadyine")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x101_route_12_trainer_5,
    },
    [0x102] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Kid"),
            PSTRING("Kid")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x102_route_12_trainer_6,
    },
    [0x103] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Cordula"),
            PSTRING("Cordula")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x103_route_12_trainer_7,
    },
    [0x104] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Joshhua"),
            PSTRING("Joshhua")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x104_route_12_trainer_8
    },
    [0x105] = {
        .trainerclass = TRAINERCLASS_VOGELFAENGER, .sprite = 0x68,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Royman"),
            PSTRING("Royman")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x105_route_12_trainer_9
    },
    [0x106] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Basil"),
            PSTRING("Basil")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x106_route_12_trainer_10,
    },
    [0x107] = {
        .trainerclass = TRAINERCLASS_MATROSE, .sprite = 53,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Popei"),
            PSTRING("Popei")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x107_route_12_trainer_11,
    },
    [0x108] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Carmena"),
            PSTRING("Carmena")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x108_route_12_trainer_12,
    },
    [0x109] = {
        .trainerclass = TRAINERCLASS_SCHNOESEL, .sprite = 0xD,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Deytar"),
            PSTRING("Deytar")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x109_route_12_trainer_13,
        .items = {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_NONE, ITEM_NONE}
    },
    [0x10a] = {
        .trainerclass = TRAINERCLASS_PLANSCHER, .sprite = 6,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Alaisya"),
            PSTRING("Alaisya")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x10a_route_12_trainer_14
    },
    [0x10b] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Tormen"),
            PSTRING("Tormen")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x10b_route_12_trainer_15,
    },
    [0x10c] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3c,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Maira"),
            PSTRING("Maira")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x10c_route_12_trainer_16,
    },
    [0x10d] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Hanneys"),
            PSTRING("Hanneys")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x10d_route_12_trainer_17,
    },
    [0x10e] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Balana"),
            PSTRING("Balana")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x10e_route_12_trainer_18,
    },
    [0x10f] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Byanca"),
            PSTRING("Byanca")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x10f_route_12_trainer_19,
    },
    [0x110] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Taufel"),
            PSTRING("Taufel")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x110_route_12_trainer_20,
    },
    [0x111] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x47,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Laurena"),
            PSTRING("Laurena")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x111_route_2_clouds_trainer_0,
    },
    [0x112] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Luc"),
            PSTRING("Luc")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x112_route_2_clouds_trainer_1,
    },
    [0x113] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Adam"),
            PSTRING("Adam")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x113_route_2_clouds_trainer_2,
    },
    [0x114] = {
        .trainerclass = TRAINERCLASS_EXPERTE, .sprite = 0x57,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Aygna"),
            PSTRING("Aygna")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x114_route_2_clouds_trainer_3,
    },
    [0x115] = {
        .trainerclass = TRAINERCLASS_VOGELFAENGER, .sprite = 0x2e,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Magnus"),
            PSTRING("Magnus")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x115_route_2_clouds_trainer_4,
    },
    [0x116] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 0x29,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Sakim"),
            PSTRING("Sakim")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x116_route_5_clouds_trainer_2,
    },
    [0x117] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Jonathis"),
            PSTRING("Jonathis")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x117_orina_city_clouds_trainer_0,
    },
    [0x118] = {
        .trainerclass = TRAINERCLASS_ASS_TRAINER, .sprite = 0x6f,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Margot"),
            PSTRING("Margot")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x118_orina_city_clouds_trainer_1,
        .items = {ITEM_TOP_GENESUNG, ITEM_HYPERTRANK, ITEM_HYPERHEILER}
    },
    [0x119] = {
        .trainerclass = TRAINERCLASS_RUINENMANIAC, .sprite = 0x4,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Makaf"),
            PSTRING("Makaf")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x119_orina_city_clouds_trainer_2,
        .items = {ITEM_TOP_GENESUNG, ITEM_HYPERTRANK, ITEM_HYPERHEILER}
    },
    [0x11A] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Katje"),
            PSTRING("Katje")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x11a_route_6_clouds_trainer_0,
    },
    [0x11B] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Richavid"),
            PSTRING("Richavid")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x11b_route_6_clouds_trainer_1,
    },
    [0x11C] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x47,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Missa"),
            PSTRING("Missa")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x11c_inferior_clouds_trainer_0,
    },
    [0x11D] = {
        .trainerclass = TRAINERCLASS_GOERE, .sprite = 0x41,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Birta"),
            PSTRING("Birta")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x11d_route_4_clouds_trainer_0,
    },
    [0x11E] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x47,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Clary"),
            PSTRING("Clary")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x11e_route_4_clouds_trainer_1,
    },
    [0x11F] = {
        .trainerclass = TRAINERCLASS_RUINENMANIAC, .sprite = 0x4,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Loxodon"),
            PSTRING("Loxodon")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x11f_kaskada_clouds_trainer_0,
    },
    [0x120] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 0x52,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Fritz"),
            PSTRING("Fritz")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x120_kaskada_clouds_trainer_1,
    },
    [0x121] = {
        .trainerclass = TRAINERCLASS_GOERE, .sprite = 0x41,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Schika"),
            PSTRING("Schika")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x121_felsige_oednis_clouds_trainer_0,
    },
    [0x122] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Horatio"),
            PSTRING("Horatio")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x122_felsige_oednis_clouds_trainer_1,
    },
    [0x123] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x47,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Kaja"),
            PSTRING("Kaja")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x123_silvania_clouds_trainer_0,
    },
    [0x124] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Thurben"),
            PSTRING("Thurben")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x124_route_3_clouds_trainer_0,
    },
    [0x125] = {
        .trainerclass = TRAINERCLASS_KAEFERSAMMLER, .sprite = 66,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Johlton"),
            PSTRING("Johlton")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x125_silvania_wald_clouds_trainer_0,
    },
    [0x126] = {
        .trainerclass = TRAINERCLASS_AROMALADY, .sprite = 3,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Kaja"),
            PSTRING("Kaja")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x126_silvania_wald_clouds_trainer_1,
    },
    [0x127] = {
        .trainerclass = TRAINERCLASS_VOGELFAENGER, .sprite = 0x2e,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Xebec"),
            PSTRING("Xebec")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x127_route_8_clouds_trainer_0,
    },
		[0x128] = {
				.trainerclass = TRAINERCLASS_SCHOENHEIT, .sprite = 0xC,
				.encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Natasha"),
						PSTRING("Natasha")), .pokemon_cnt = 3,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_x128_laubdorf_clouds_trainer_0
		},
    [0x129] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Angelos"),
            PSTRING("Angelos")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x129_route_9_clouds_trainer_0
    },
    [0x12A] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x47,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Petra"),
            PSTRING("Petra")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x12a_route_9_clouds_trainer_1
    },
		[0x12B] = {
				.trainerclass = TRAINERCLASS_HITZKOPF, .sprite = 0x12,
				.encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Leoh"),
						PSTRING("Leoh")), .pokemon_cnt = 2,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_x12b_route_9_clouds_trainer_2
		},
    [0x12C] = {
        .trainerclass = TRAINERCLASS_RUINENMANIAC, .sprite = 0x4,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Stephen"),
            PSTRING("Stephen")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x12c_aktania_clouds_trainer_0,
    },
    [0x12D] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Evalya"),
            PSTRING("Evalya")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x12d_kuestenberg_clouds_trainer_0,
    },
    [0x12E] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Florentin"),
            PSTRING("Florentin")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x12e_route_11_clouds_trainer_0,
    },
    [0x12F] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Nathalien"),
            PSTRING("Nathalien")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x12f_ceometria_clouds_trainer_0,
    },
    [0x130] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 0x34,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Korbinius"),
            PSTRING("Korbinius")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x130_route_12_clouds_trainer_0,
    },
    [0x131] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Roy"),
            PSTRING("Roy")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x131_route_12_clouds_trainer_1,
    },
    [0x132] = {
        .trainerclass = TRAINERCLASS_GITARRIST, .sprite = 17,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Paul"),
            PSTRING("Paul")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x132_route_12_clouds_trainer_2,
    },
    [0x133] = {
        .trainerclass = TRAINERCLASS_RUINENMANIAC, .sprite = 0x4,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Glenn"),
            PSTRING("Stephen")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x133_haweiland_clouds_trainer_0,
    },
    [0x134] = {
        .trainerclass = TRAINERCLASS_WOLKENREITER, .sprite = 0x47,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Vanda"),
            PSTRING("Vanda")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x134_haweiland_clouds_trainer_1,
    },
    [0x135] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Jaden"),
            PSTRING("Jaden")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x135_haweiland_cargo_hall_trainer_0,
    },
    [0x136] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Don Carlo"),
            PSTRING("Don Carlo")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x136_haweiland_cargo_hall_trainer_1,
    },
    [0x137] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Marquez"),
            PSTRING("Marquez")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x137_haweiland_cargo_hall_trainer_2,
    },
    [0x138] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Juan"),
            PSTRING("Juan")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x138_haweiland_cargo_hall_trainer_3,
    },
    [0x139] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Pablo"),
            PSTRING("Pablo")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x139_haweiland_cargo_hall_trainer_4,
    },
    [0x13a] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Enrico"),
            PSTRING("Enrico")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x13a_haweiland_cargo_hall_trainer_5,
    },
    [0x13b] = {
        .trainerclass = TRAINERCLASS_PKMN_TRAINER, .sprite = 0x39,.encounter_and_gender = {2, 1}, 
        .name = LANGDEP(PSTRING("Maike"), PSTRING("May")), 
        .pokemon_cnt = 4,
        .uses_custom_moves = true, .uses_custom_items = true,
        .items = {ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER},
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x13b_haweiland_may
    },
    [0x13c] = {
        .trainerclass = TRAINERCLASS_PKMN_TRAINER, .sprite = 0x39,.encounter_and_gender = {2, 1}, 
        .name = LANGDEP(PSTRING("Maike"), PSTRING("May")), 
        .pokemon_cnt = 4,
        .uses_custom_moves = true, .uses_custom_items = true,
        .items = {ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER},
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x13c_haweiland_may
    },
    [0x13d] = {
        .trainerclass = TRAINERCLASS_PKMN_TRAINER, .sprite = 0x39,.encounter_and_gender = {2, 1}, 
        .name = LANGDEP(PSTRING("Maike"), PSTRING("May")), 
        .pokemon_cnt = 4,
        .uses_custom_moves = true, .uses_custom_items = true,
        .items = {ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER},
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x13d_haweiland_may
    },
		[0x13E] = {
				.trainerclass = TRAINERCLASS_ARENALEITER, .sprite = 119,
				.encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Teah"),
						PSTRING("Teah")), .pokemon_cnt = 4,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
				.items = {ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_NONE},
				.party = (trainer_pokemon*) trainer_party_ceometria_gym_leader,
				.uses_custom_items = true, .uses_custom_moves = true,
        .battle_state = BATTLE_WITH_HANDICAP,
		},
    [0x13F] = {
        .trainerclass = TRAINERCLASS_HITZKOPF, .sprite = 18,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Zyrus"),
            PSTRING("Zyrus")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x13f_route_7_trainer_0,
    },
    [0x140] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Sully"),
            PSTRING("Sully")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x140_route_7_trainer_1,
    },
    [0x141] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x5D,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Herion"),
            PSTRING("Herion")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x141_route_7_trainer_2,
    },
    [0x142] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x68,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Hop"),
            PSTRING("Hop")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x142_route_7_trainer_3,
    },
    [0x143] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Konja"),
            PSTRING("Konja")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x143_route_7_trainer_4,
    },
    [0x144] = {
        .trainerclass = TRAINERCLASS_SCHNOESEL, .sprite = 13,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Urs"),
            PSTRING("Urs")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x144_route_7_trainer_5,
    },
    [0x145] = {
        .trainerclass = TRAINERCLASS_SCHNOESEL, .sprite = 3,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Betina"),
            PSTRING("Betina")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x145_route_7_trainer_6,
        .items = {ITEM_TOP_GENESUNG, ITEM_TOP_TRANK}
    },
    [0x146] = {
        .trainerclass = TRAINERCLASS_VOGELFAENGER, .sprite = 0x2e,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Romayn"),
            PSTRING("Romayn")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x146_route_7_trainer_7,
    },
    [0x147] = {
        .trainerclass = TRAINERCLASS_GENTLEMAN, .sprite = 23,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Heribart"),
            PSTRING("Heribart")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x147_route_7_trainer_8,
    },
    [0x148] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 0x2A,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Andrea"),
            PSTRING("Andrea")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x148_route_7_trainer_9,
    },
    [0x149] = {
        .trainerclass = TRAINERCLASS_TRIATHLET, .sprite = 7,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Eric"),
            PSTRING("Eric")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x149_route_7_trainer_10,
    },
    [0x14A] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Perseus"),
            PSTRING("Perseus")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x14a_route_7_trainer_11,
    },
    [0x14B] = {
        .trainerclass = TRAINERCLASS_PICKNICKER, .sprite = 51,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Carly"),
            PSTRING("Carly")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x14b_route_7_trainer_12,
    },
    [0x14C] = {
        .trainerclass = TRAINERCLASS_MATROSE, .sprite = 53,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Cliff"),
            PSTRING("Cliff")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x14c_route_7_trainer_13,
    },
    [0x14D] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Arnulf"),
            PSTRING("Arnulf")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x14d_route_7_trainer_14,
    },
    [0x14E] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Pablo"),
            PSTRING("Pablo")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x14e_route_7_trainer_15,
    },
    [0x14F] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 36,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Pablo"),
            PSTRING("Pablo")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x14f_route_7_trainer_16,
    },
    [0x150] = {
        .trainerclass = TRAINERCLASS_GENTLEMAN, .sprite = 23,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Paulus"),
            PSTRING("Paulus")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x150_route_7_trainer_17,
    },
    [0x151] = {
        .trainerclass = TRAINERCLASS_MATROSE, .sprite = 53,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Gaban"),
            PSTRING("Gaban")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x151_route_7_trainer_18,
    },
    [0x152] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Angelika"),
            PSTRING("Angelika")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x152_route_7_trainer_19,
    },
    [0x153] = {
        .trainerclass = TRAINERCLASS_PLANSCHER, .sprite = 6,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Gizem"),
            PSTRING("Gizem")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x153_route_7_trainer_20,
    },
    [0x154] = {
        .trainerclass = TRAINERCLASS_STREBER, .sprite = 89,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Norman"),
            PSTRING("Norman")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x154_route_7_trainer_21,
    },
    [0x155] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Julio"),
            PSTRING("Julio")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x155_route_7_trainer_22,
    },
    [0x156] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Karlo"),
            PSTRING("Karlo")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x156_route_7_trainer_23,
    },
    [0x157] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Pepe"),
            PSTRING("Pepe")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x157_route_7_trainer_24,
    },
    [0x158] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Adriana"),
            PSTRING("Adriana")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x158_route_7_trainer_25,
    },
    [0x159] = {
        .trainerclass = TRAINERCLASS_BUTLER, .sprite = 24,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Alfred"),
            PSTRING("Alfred")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x159_ardeal_trainer_0,
    },
    [0x15a] = {
        .trainerclass = TRAINERCLASS_BUTLER, .sprite = 24,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Thomis"),
            PSTRING("Thomis")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x15a_ardeal_trainer_1,
    },
    [0x15b] = {
        .trainerclass = TRAINERCLASS_BUTLER, .sprite = 24,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Gerimas"),
            PSTRING("Gerimas")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x15b_ardeal_trainer_2,
    },
    [0x15c] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 0x49,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Elite N."),
            PSTRING("Elite N.")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x15c_ardeal_trainer_3,
    },
    [0x15d] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 0x4a,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Elite J."),
            PSTRING("Elite J.")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x15d_ardeal_trainer_4,
    },
    [0x15e] = {
        .trainerclass = TRAINERCLASS_VIOLET_VORS, .sprite = 28,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Lucius"),
            PSTRING("Lucius")), .pokemon_cnt = 6,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
				.items = {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
				.party = (trainer_pokemon*) trainer_party_x15e_ardeal_lucius,
				.uses_custom_items = true, .uses_custom_moves = true,
        // .battle_state = BATTLE_DOUBLE,
    },
    [0x15f] = {
        .trainerclass = TRAINERCLASS_RIVALE, .sprite = 106,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Björn"),
            PSTRING("Björn")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x15f_route_2_rival_plant_starter,
				.uses_custom_items = true, .uses_custom_moves = true,
        .items = {ITEM_TRANK, 0, 0, 0},
    },
    [0x160] = {
        .trainerclass = TRAINERCLASS_RIVALE, .sprite = 106,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Björn"),
            PSTRING("Björn")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x160_route_2_rival_fire_starter,
				.uses_custom_items = true, .uses_custom_moves = true,
        .items = {ITEM_TRANK, 0, 0, 0},
    },
    [0x161] = {
        .trainerclass = TRAINERCLASS_RIVALE, .sprite = 106,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Björn"),
            PSTRING("Björn")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x161_route_2_rival_water_starter,
				.uses_custom_items = true, .uses_custom_moves = true,
        .items = {ITEM_TRANK, 0, 0, 0},
    },
    [0x162] = {
        .trainerclass = TRAINERCLASS_KAEFERSAMMLER, .sprite = 66,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Patt"),
            PSTRING("Patt")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x162_route_2_east_trainer_0,
    },
    [0x163] = {
        .trainerclass = TRAINERCLASS_ROCKER, .sprite = 17,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Erwin"),
            PSTRING("Erwin")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x163_route_2_trainer_0,
    },
    [0x164] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 78,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Rüpel H."),
            PSTRING("Grunt H.")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x164_route_2_grunt_second,
    },
    [0x165] = {
        .trainerclass = TRAINERCLASS_ZWIL, .sprite = 127,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Amy u. Lea"),
            PSTRING("Amy u. Lea")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x165_route_2_twins,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x166] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 82,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Jeremy"),
            PSTRING("Jeremy")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x166_route_2_trainer_1,
    },
    [0x167] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 0x69,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Guz"),
            PSTRING("Guz")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x167_route_3_trainer_0
    },
    [0x168] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Sebastian"),
            PSTRING("Sebastian")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x168_felsige_oednis_trainer_0,
    },
    [0x169] = {
        .trainerclass = TRAINERCLASS_PKMN_TRAINER, .sprite = 0,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Felix"),
            PSTRING("Felix")), .pokemon_cnt = 3,
				.uses_custom_items = true, .uses_custom_moves = true,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
        .party = (trainer_pokemon*) trainer_party_x169_kuestenberg_felix,
    },
    [0x16A] = {
        .trainerclass = TRAINERCLASS_REVOLUTIONAER, .sprite = 1,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Cornelius"),
            PSTRING("Cornelius")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x16a_kuestenberg_revolutionaer,
    },
    [0x16B] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Jule u. Jan"),
            PSTRING("Jule u. Jan")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x16b_route_4_trainer_couple),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,

        .party = (trainer_pokemon*) trainer_party_x16b_route_4_trainer_couple,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x16C] = {
        .trainerclass = TRAINERCLASS_POKEMANIAC, .sprite = 32,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Kristov"),
            PSTRING("Kristov")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,

        .party = (trainer_pokemon*) trainer_party_x16c_route_5_trainer_0,
    },
    [0x16D] = {
        .trainerclass = TRAINERCLASS_ZWIL, .sprite = 127,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Eva u. Ella"),
            PSTRING("Eva u. Ella")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x16d_route_5_twins,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x16E] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Jutta"),
            PSTRING("Jutta")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x16e_route_6_trainer_0,
    },
    [0x16F] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Bea u. Ben"),
            PSTRING("Bea u. Ben")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x16f_route_6_couple,
        .battle_state = BATTLE_DOUBLE,
    },
		[0x170] = {
				.trainerclass = TRAINERCLASS_ARENALEITER, .sprite = 121,
				.encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Igva"),
						PSTRING("Igva")), .pokemon_cnt = 3,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
				.items = {ITEM_HYPERTRANK, ITEM_HYPERTRANK, ITEM_SUPERTRANK, ITEM_NONE},
				.party = (trainer_pokemon*) trainer_party_x170_volcano_igva_ally,
				.uses_custom_items = true, .uses_custom_moves = true
		},
    [0x171] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 78,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Rüpel H."),
            PSTRING("Grunt H.")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x171_volcano_grunt_0,
    },
    [0x172] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 109,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Rüpel B."),
            PSTRING("Grunt B.")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x172_volcano_grunt_1,
    },
    [0x173] = {
        .trainerclass = TRAINERCLASS_TEAM_VIOLET, .sprite = 74,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Elite F."),
            PSTRING("Elite F.")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x173_volcano_grunt_2,
    },
    [0x174] = {
        .trainerclass = TRAINERCLASS_SCHWIMMERIN, .sprite = 50,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Angela"),
            PSTRING("Angela")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x174_route_9_swimmer_0
    },
    [0x175] = {
        .trainerclass = TRAINERCLASS_SCHWIMMER, .sprite = 15,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Moby"),
            PSTRING("Moby")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x175_route_9_swimmer_1,
    },
    [0x176] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 21,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Albert"),
            PSTRING("Albert")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x176_route_8_psycho_0
    },
    [0x177] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Max u. Mara"),
            PSTRING("Max a. Mara")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x177_route_8_couple,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x178] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Leo u. Lisa"),
            PSTRING("Leo a. Lisa")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x178_route_10_couple,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x179] = {
        .trainerclass = TRAINERCLASS_ZWIL, .sprite = 127,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Dany u. Daj"),
            PSTRING("Dany a. Daj")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x179_route_7_twins,
        .battle_state = BATTLE_DOUBLE,
    },
		[0x17a] = {
				.trainerclass = TRAINERCLASS_SCHOENHEIT, .sprite = 0xC,
				.encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Janaina"),
						PSTRING("Janaina")), .pokemon_cnt = 2,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_x17a_route_7_beatuy
		},
		[0x17b] = {
				.trainerclass = TRAINERCLASS_PICKNICKER3, .sprite = 0x56,
				.encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Engelbert"),
						PSTRING("Engelbert")), .pokemon_cnt = 2,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_x17b_route_7_picknicker
		},
    [0x17c] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Udo u. Irma"),
            PSTRING("Udo a. Irma")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x17c_route_12_couple,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x17d] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Ken u. Pia"),
            PSTRING("Ken a. Pia")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x17d_route_11_couple,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x17e] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Mariba"),
            PSTRING("Mariba")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x17e_ceometria_clouds_witch_0,
    },
    [0x17f] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Waltraud"),
            PSTRING("Waltraud")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x17f_ceometria_clouds_witch_1,
    },
    [0x180] = {
        .trainerclass = TRAINERCLASS_RUINENMANIAC, .sprite = 0x4,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Paulus"),
            PSTRING("Paulus")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x180_ceometria_clouds_ruin_maniac_0,
    },
    [0x181] = {
        .trainerclass = TRAINERCLASS_EXORZISTIN, .sprite = 126,
        .encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Karena"),
            PSTRING("Karena")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x181_dark_tower_trainer_0,
    },
    [0x182] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Bianca"),
            PSTRING("Bianca")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x182_dark_tower_trainer_1,
    },
    [0x183] = {
        .trainerclass = TRAINERCLASS_EXORZISTIN, .sprite = 126,
        .encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Amara"),
            PSTRING("Amara")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x183_dark_tower_trainer_2,
    },
    [0x184] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Pip"),
            PSTRING("Pip")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x184_bbship_storage_pirate_0,
    },
    [0x185] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Tarinbert"),
            PSTRING("Tarinbert")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x185_bbship_storage_pirate_1,
    },
    [0x186] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Gimbard"),
            PSTRING("Gimbard")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x186_bbship_storage_pirate_2,
    },
    [0x187] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Friedrich"),
            PSTRING("Friedrich")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x187_bbship_storage_pirate_3,
    },
    [0x188] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Samuel"),
            PSTRING("Samuel")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x188_bbship_storage_pirate_4,
    },
    [0x189] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Kurt"),
            PSTRING("Kurt")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x189_bbship_storage_pirate_5,
    },
    [0x18a] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Willbert"),
            PSTRING("Willbert")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x18a_bbship_cells_pirate0
    },
    [0x18b] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Erkay"),
            PSTRING("Erkay")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x18b_bbship_canon_room_pirate0,
    },
    [0x18c] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Tristan"),
            PSTRING("Tristan")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x18c_bbship_cabin_pirate0,
    },
    [0x18d] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Kevin"),
            PSTRING("Kevin")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x18d_bbship_cabin_pirate1,
    },
    [0x18e] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Oliver"),
            PSTRING("Oliver")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x18e_bbship_cabins_pirate0,
    },
    [0x18f] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Keesiu"),
            PSTRING("Keesiu")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x18f_bbship_cabins_pirate1,
    },
    [0x190] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Timothy"),
            PSTRING("Timothy")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x190_bbship_cabins_pirate2,
    },
    [0x191] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Mathias"),
            PSTRING("Mathias")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x191_bbship_cabins_pirate3,
    },
    [0x192] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Dominic"),
            PSTRING("Dominic")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x192_bbship_deck_pirate0,
    },
    [0x193] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Samuel"),
            PSTRING("Samuel")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x193_bbship_deck_pirate1,
    },
    [0x194] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Ingo"),
            PSTRING("Ingo")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x194_bbship_deck_pirate2,
    },
    [0x195] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Fritz"),
            PSTRING("Fritz")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x195_bbship_deck_pirate3,
    },
    [0x196] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Armin"),
            PSTRING("Armin")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x196_bbship_deck_pirate4,
    },
    [0x197] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Raphael"),
            PSTRING("Raphael")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x197_bbship_deck_pirate5,
    },
    [0x198] = {
        .trainerclass = TRAINERCLASS_PIRATE, .sprite = 25,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Sigmar"),
            PSTRING("Sigmar")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x198_bbship_deck_pirate6,
    },
    [0x199] = {
        .trainerclass = TRAINERCLASS_KAPITAEN, .sprite = 62,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Blackbeard"),
            PSTRING("Blackbeard")), .pokemon_cnt = 5,
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS |  TRAINER_AI_VARIABILITY |
				TRAINER_AI_SUPER_EFFECTIVE,
				.items = {ITEM_HYPERTRANK, ITEM_HYPERHEILER, ITEM_HYPERTRANK, 0},
				.party = (trainer_pokemon*) trainer_party_x199_bbship_blackbeard,
				.uses_custom_items = true, .uses_custom_moves = true,
        // .battle_state = BATTLE_DOUBLE,
    },
    [0x19A] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 0x69,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Marco"),
            PSTRING("Marco")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x19a_meriana_city_blackbelt_in_front_of_gym,
    },
    [0x19B] = {
        .trainerclass = TRAINERCLASS_STREBER, .sprite = 0x1d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Sicilion"),
            PSTRING("Sicilion")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x19b_route_2_streber,
    },
    [0x19C] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Harold"),
            PSTRING("Harold")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x19c_route_2_cave_hiker,
    },
    [0x19d] = {
        .trainerclass = TRAINERCLASS_SCHULKIND, .sprite = 0x1e,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Felicitas"),
            PSTRING("Felicitas")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x19d_route_2_cave_school_kid,
    },
    [0x19e] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 0x52,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Fynn"),
            PSTRING("Fynn")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x19e_route_2_cave_teenager,
    },
    [0x19f] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 0x52,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Paimon"),
            PSTRING("Paimon")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x19f_bruchfels_gym_trainer1,
    },
    [0x1A0] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Memet"),
            PSTRING("Memet")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1a0_bruchfels_gym_trainer2,
    },
    [0x1A1] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_ARENALEITER, .encounter_and_gender = {1, 0} , .sprite = 0x74,
      .name = LANGDEP(PSTRING("Lester"), PSTRING("Lester")),
      .items = {ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_NONE, ITEM_NONE},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = BATTLE_WITH_HANDICAP, .pokemon_cnt = 4, .party = (trainer_pokemon*)trainer_party_x1a1_lester_difficulty_normal,
	  },
    [0x1A2] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_ARENALEITER, .encounter_and_gender = {1, 0} , .sprite = 0x74,
      .name = LANGDEP(PSTRING("Lester"), PSTRING("Lester")),
      .items = {ITEM_GOLDAPFEL, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = BATTLE_WITH_HANDICAP, .pokemon_cnt = 4, .party = (trainer_pokemon*) trainer_party_x1a2_lester_difficulty_hard,
	  },
    [0x1A3] = {
      .trainerclass = TRAINERCLASS_CHEFKOCH, .encounter_and_gender = {1, 0} , .sprite = 75,
      .name = LANGDEP(PSTRING("Gordon"), PSTRING("Gordon")),
      .items = {ITEM_GOLDAPFEL, ITEM_APFEL, ITEM_APFEL, 0},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = 0, .pokemon_cnt = 4, .party = (trainer_pokemon*) trainer_party_x1a3_felsige_oednis_koch,
	  },
    [0x1A4] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_ARENALEITER, .encounter_and_gender = {1, 0} , .sprite = 0x75,
      .name = LANGDEP(PSTRING("Rosalie"), PSTRING("Rosalie")),
      .items = {ITEM_SUPERTRANK, ITEM_SUPERTRANK, ITEM_HYPERHEILER, ITEM_SUPERTRANK},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = BATTLE_WITH_HANDICAP, .pokemon_cnt = 5, .party = (trainer_pokemon*)trainer_party_x1a4_rosalie_difficulty_normal,
	  },
    [0x1A5] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_ARENALEITER, .encounter_and_gender = {1, 0} , .sprite = 0x75,
      .name = LANGDEP(PSTRING("Rosalie"), PSTRING("Rosalie")),
      .items = {ITEM_GOLDAPFEL, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = BATTLE_WITH_HANDICAP, .pokemon_cnt = 6, .party = (trainer_pokemon*) trainer_party_x1a5_rosalie_difficulty_hard,
	  },
    [0x1A6] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Pia u. Pete"),
            PSTRING("Pia u. Pete")), .pokemon_cnt = 4,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,

        .party = (trainer_pokemon*) trainer_party_x1a6_felsige_oednis_cave_trainer_0,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x1A7] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Jimbo"),
            PSTRING("Jimbo")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1a7_felsige_oednis_cave_trainer_1,
    },
    [0x1A8] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Karl"),
            PSTRING("Karl")), .pokemon_cnt = 2,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1a8_felsige_oednis_cave_trainer_2,
    },
    [0x1A9] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x5d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Dean"),
            PSTRING("Dean")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1a9_felsige_oednis_cave_trainer_3,
    },
    [0x1AA] = {
        .trainerclass = TRAINERCLASS_HEXE, .sprite = 10,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Olyvia"),
            PSTRING("Olyvia")), .pokemon_cnt = 1,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1aa_felsige_oednis_cave_trainer_4,
        .uses_custom_items = true,
    },
    [0x1AB] = {
        .trainerclass = TRAINERCLASS_KAEFERMANIAC, .sprite = 20,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Jeremias"),
            PSTRING("Jeremy")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ab_tafelberg_lower_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1ab_tafelberg_lower_trainer_0,
    },
    [0x1AC] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Horst"),
            PSTRING("Horst")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ac_tafelberg_lower_trainer_1),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1ac_tafelberg_lower_trainer_1,
    },
    [0x1AD] = {
        .trainerclass = TRAINERCLASS_VOGELFAENGER, .sprite = 0x2e,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Eduard"),
            PSTRING("Eduard")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ad_tafelberg_lower_trainer_2),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1ad_tafelberg_lower_trainer_2,
    },
    [0x1AE] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3d,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Bert"),
            PSTRING("Bert")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ae_tafelberg_lower_trainer_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1ae_tafelberg_lower_trainer_3,
        .items = {ITEM_SUPERTRANK, ITEM_APFEL},
    },
    [0x1AF] = {
        .trainerclass = TRAINERCLASS_FORSCHER, .sprite = 107,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Helge"),
            PSTRING("Helge")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1af_tafelberg_lower_trainer_4),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1af_tafelberg_lower_trainer_4,
    },
    [0x1B0] = {
        .trainerclass = TRAINERCLASS_GOERE, .sprite = 0x41,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Yvette"),
            PSTRING("Yvette")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b0_tafelberg_lower_trainer_5),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b0_tafelberg_lower_trainer_5,
    },
    [0x1B1] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Nils u. Eva"),
            PSTRING("Nils u. Eve")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b1_tafelberg_lower_trainer_6),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b1_tafelberg_lower_trainer_6,
    },
    [0x1B2] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Sophie"),
            PSTRING("Sophy")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b2_felsige_oednis_east_caves_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b2_felsige_oednis_east_caves_trainer_0,
    },
    [0x1B3] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Isibald"),
            PSTRING("Isybald")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b3_felsige_oednis_east_caves_trainer_1),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b3_felsige_oednis_east_caves_trainer_1,
    },
    [0x1B4] = {
        .trainerclass = TRAINERCLASS_POKEMANIAC, .sprite = 32,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Christian"),
            PSTRING("Christian")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b4_felsige_oednis_east_caves_trainer_2),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b4_felsige_oednis_east_caves_trainer_2,
    },
    [0x1B5] = {
        .trainerclass = TRAINERCLASS_CAMPER, .sprite = 86,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Manfred"),
            PSTRING("Manfred")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b5_felsige_oednis_east_caves_trainer_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b5_felsige_oednis_east_caves_trainer_3,
    },
    [0x1B6] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 0x52,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Ludvig"),
            PSTRING("Ludvig")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b6_tafelberg_lapis_cave_trainer_1),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b6_tafelberg_lapis_cave_trainer_1,
    },
    [0x1B7] = {
        .trainerclass = TRAINERCLASS_GENTLEMAN, .sprite = 23,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Salomon"),
            PSTRING("Salomon")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b7_tafelberg_lapis_cave_trainer_2),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b7_tafelberg_lapis_cave_trainer_2,
    },
    [0x1B8] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Hannah"),
            PSTRING("Hannah")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b8_tafelberg_lapis_cave_trainer_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b8_tafelberg_lapis_cave_trainer_3,
    }, 
    [0x1B9] = {
        .trainerclass = TRAINERCLASS_MATROSE, .sprite = 53,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Donald"),
            PSTRING("Donald")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1b9_tafelberg_lapis_cave_trainer_4),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1b9_tafelberg_lapis_cave_trainer_4,
    }, 
    [0x1BA] = {
        .trainerclass = TRAINERCLASS_REVOLUTIONAER, .sprite = 2,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Elfie"),
            PSTRING("Elfie")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ba_tafelberg_revolutionary_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1ba_tafelberg_revolutionary_3,
    }, 
    [0x1BB] = {
        .trainerclass = TRAINERCLASS_KAEFERMANIAC, .sprite = 0x42,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Stephen"),
            PSTRING("Stephen")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1bb_tafelberg_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1bb_tafelberg_trainer_0,
    }, 
    [0x1BC] = {
        .trainerclass = TRAINERCLASS_TEENAGER, .sprite = 0x24,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Jester"),
            PSTRING("Jester")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1bc_tafelberg_trainer_1),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1bc_tafelberg_trainer_1,
    },
		[0x1BD] = {
				.trainerclass = TRAINERCLASS_SCHOENHEIT, .sprite = 0xC,
				.encounter_and_gender = {1, 1}, .name = LANGDEP(PSTRING("Anna"),
						PSTRING("Anna")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1bd_tafelberg_trainer_2),
				.ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
				.party = (trainer_pokemon*) trainer_party_x1bd_tafelberg_trainer_2
		},
    [0x1BE] = {
        .trainerclass = TRAINERCLASS_ZWIL, .sprite = 127,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Isy u. Alma"),
            PSTRING("Isy u. Alma")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1be_tafelberg_trainer_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1be_tafelberg_trainer_3,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x1BF] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Jakob"),
            PSTRING("Jakob")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1bf_tafelberg_trainer_4),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1bf_tafelberg_trainer_4,
    }, 
    [0x1C0] = {
        .trainerclass = TRAINERCLASS_REVOLUTIONAER, .sprite = 2,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Hermann"),
            PSTRING("Hermann")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c0_tafelberg_trainer_5),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c0_tafelberg_trainer_5,
    },
    [0x1C1] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 0x69,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Jack"),
            PSTRING("Jack")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c1_route_4_north_cave_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c1_route_4_north_cave_trainer_0,
    },
    [0x1C2] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 0x69,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Fynn"),
            PSTRING("Fynn")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c2_route_4_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c2_route_4_trainer_0,
    },
    [0x1c3] = {
        .trainerclass = TRAINERCLASS_VOGELFAENGER, .sprite = 0x2e,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Thomas"),
            PSTRING("Thomas")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c3_route_4_trainer_1),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c3_route_4_trainer_1,
    },
    [0x1c4] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x5d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("James"),
            PSTRING("James")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c4_route_4_trainer_2),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c4_route_4_trainer_2,
    }, 
    [0x1c5] = {
        .trainerclass = TRAINERCLASS_KAEFERMANIAC, .sprite = 0x42,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Stephen"),
            PSTRING("Stephen")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c5_route_4_trainer_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c5_route_4_trainer_3,
    },
    [0x1c6] = {
        .trainerclass = TRAINERCLASS_ZWIL, .sprite = 127,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Kate u. Bea"),
            PSTRING("Kate u. Bea")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c6_route_4_trainer_4),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c6_route_4_trainer_4,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x1c7] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Merope"),
            PSTRING("Merope")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c7_route_4_trainer_5),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c7_route_4_trainer_5,
    },
    [0x1c8] = {
        .trainerclass = TRAINERCLASS_SCHNOESEL, .sprite = 3,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Igor"),
            PSTRING("Igor")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c8_route_4_trainer_6),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1c8_route_4_trainer_6,
        .items = {ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG}
    },
    [0x1c9] = {
      .trainerclass = TRAINERCLASS_CHEFKOCH, .encounter_and_gender = {1, 0} , .sprite = 75,
      .name = LANGDEP(PSTRING("Jamie"), PSTRING("Jamie")),
      .items = {ITEM_GOLDAPFEL, ITEM_APFEL, ITEM_APFEL, 0},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = 0, .pokemon_cnt = ARRAY_COUNT(trainer_party_x1c9_route_4_trainer_7), .party = (trainer_pokemon*) trainer_party_x1c9_route_4_trainer_7,
	  },
    [0x1ca] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_MALERIN, .encounter_and_gender = {1, 1} , .sprite = 147,
      .name = LANGDEP(PSTRING("Jamie"), PSTRING("Jamie")),
      .items = {ITEM_SUPERTRANK, ITEM_GEGENGIFT, ITEM_APFEL, 0},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = 0, .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ca_route_4_cave_south_painter), .party = (trainer_pokemon*) trainer_party_x1ca_route_4_cave_south_painter,
	  },
    [0x1cb] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_ARENALEITER, .encounter_and_gender = {1, 0} , .sprite = 76,
      .name = LANGDEP(PSTRING("Manuel"), PSTRING("Manuel")),
      .items = {ITEM_HYPERTRANK, ITEM_SUPERTRANK, ITEM_NONE, ITEM_NONE},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = 0, .pokemon_cnt = ARRAY_COUNT(trainer_party_x1cb_bluetenbach_gym_manus_easy), .party = (trainer_pokemon*)trainer_party_x1cb_bluetenbach_gym_manus_easy,
	  },
    [0x1cc] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_ARENALEITER, .encounter_and_gender = {1, 0} , .sprite = 76,
      .name = LANGDEP(PSTRING("Manuel"), PSTRING("Manuel")),
      .items = {ITEM_TOP_GENESUNG, ITEM_GOLDAPFEL, ITEM_TOP_GENESUNG, ITEM_HYPERHEILER},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = BATTLE_WITH_HANDICAP, .pokemon_cnt = ARRAY_COUNT(trainer_party_x1cc_bluetenbach_gym_manus_hard), .party = (trainer_pokemon*)trainer_party_x1cc_bluetenbach_gym_manus_hard,
	  },
    [0x1cd] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Brigitte"),
            PSTRING("Brigitte")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1cd_bluetenbach_gym_trainer_4),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1cd_bluetenbach_gym_trainer_4,
    },
    [0x1ce] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 0x69,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Volker"),
            PSTRING("Volker")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1ce_bluetenbach_gym_trainer_5),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1ce_bluetenbach_gym_trainer_5,
    },
    [0x1cf] = {
        .trainerclass = TRAINERCLASS_KAEMPFERIN, .sprite = 48,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Isolde"),
            PSTRING("Isolde")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1cf_bluetenbach_gym_trainer_6),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1cf_bluetenbach_gym_trainer_6,
    },
    [0x1d0] = {
        .trainerclass = TRAINERCLASS_SCHWARZGURT, .sprite = 0x69,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Herbert"),
            PSTRING("Herbert")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d0_bluetenbach_gym_trainer_7),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d0_bluetenbach_gym_trainer_7,
    },
    [0x1d1] = {
        .trainerclass = TRAINERCLASS_PSYCHO, .sprite = 0x16,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Helena"),
            PSTRING("Helena")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d1_route_5_trainer_6),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d1_route_5_trainer_6
    },
    [0x1d2] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Alfred"),
            PSTRING("Alfred")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d2_route_5_trainer_7),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d2_route_5_trainer_7,
    },
    [0x1d3] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Omar"),
            PSTRING("Omar")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d3_route_5_trainer_8),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d3_route_5_trainer_8,
    },
    [0x1d4] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Egon"),
            PSTRING("Egon")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d4_route_5_trainer_9),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d4_route_5_trainer_9,
    },
    [0x1d5] = {
        .trainerclass = TRAINERCLASS_RUINENMANIAC, .sprite = 4,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Tobias"),
            PSTRING("Tobias")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d5_anemonia_clouds_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d5_anemonia_clouds_trainer_0,
    },
    [0x1d6] = {
        .trainerclass = TRAINERCLASS_AROMALADY, .sprite = 3,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING("Elsa"),
            PSTRING("Elsa")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d6_route_4_clouds_trainer_2),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d6_route_4_clouds_trainer_2,
    },
    [0x1d7] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x5d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Maurice"),
            PSTRING("Maurice")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d7_route_4_clouds_trainer_3),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d7_route_4_clouds_trainer_3,
    },
    [0x1d8] = {
        .trainerclass = TRAINERCLASS_ANGLER, .sprite = 0x26,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING("Rolf"),
            PSTRING("Rolf")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d8_route_4_clouds_trainer_4),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d8_route_4_clouds_trainer_4,
    },
    [0x1d9] = {
        .trainerclass = TRAINERCLASS_WANDERER, .sprite = 0x43,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Antonin"),
            PSTRING("Antonin")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1d9_route_4_clouds_trainer_5),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1d9_route_4_clouds_trainer_5,
    },
    [0x1da] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_PKMN_TRAINER, .encounter_and_gender = {1, 0} , .sprite = 77,
      .name = LANGDEP(PSTRING("Ikarus"), PSTRING("Ikarus")),
      .items = {ITEM_HYPERTRANK, ITEM_HYPERHEILER, 0, 0},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = 0, .pokemon_cnt = ARRAY_COUNT(trainer_party_x1da_route_5_icarus_party), .party = (trainer_pokemon*)trainer_party_x1da_route_5_icarus_party,
	  },
    [0x1db] = {
        .trainerclass = TRAINERCLASS_FORSCHER, .sprite = 107,
        .encounter_and_gender = {1, 0}, .name = LANGDEP(PSTRING("Albert"),
            PSTRING("Albert")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1db_power_plant_inside_trainer_0),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1db_power_plant_inside_trainer_0,
    },
    [0x1dc] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x5d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Antonio"),
            PSTRING("Antonio")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1dc_power_plant_inside_trainer_1),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1dc_power_plant_inside_trainer_1,
    },
    [0x1dd] = {
        .trainerclass = TRAINERCLASS_MECHANIKER, .sprite = 0x5d,
        .encounter_and_gender = {2, 0}, .name = LANGDEP(PSTRING("Marvin"),
            PSTRING("Marvin")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1dd_power_plant_inside_trainer_2),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1dd_power_plant_inside_trainer_2,
    },
    [0x1de] = {
        .trainerclass = TRAINERCLASS_JUNGES_GLUECK, .sprite = 68,
        .encounter_and_gender = {0, 1}, .name = LANGDEP(PSTRING("Eli u. Erik"),
            PSTRING("Eli u. Erik")), .pokemon_cnt = ARRAY_COUNT(trainer_party_x1de_route_7_north_couple),
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) trainer_party_x1de_route_7_north_couple,
        .battle_state = BATTLE_DOUBLE,
    },
    [0x1df] = {
      .trainerclass = TRAINERCLASS_CHEFKOCH, .encounter_and_gender = {1, 0} , .sprite = 75,
      .name = LANGDEP(PSTRING("Alfons"), PSTRING("Alfons")),
      .uses_custom_moves = true, .uses_custom_items = true,
      .items = {ITEM_GOLDAPFEL, ITEM_APFEL, ITEM_APFEL, 0},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = 0, .pokemon_cnt = ARRAY_COUNT(trainer_party_x1df_route_7_north_cook), .party = (trainer_pokemon*) trainer_party_x1df_route_7_north_cook,
	  },
    [0x1e0] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3d,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING(""),
            PSTRING("")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0x1e1] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3c,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING(""),
            PSTRING("")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party,
    },
    [0x1e2] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3d,
        .encounter_and_gender = {0, 0}, .name = LANGDEP(PSTRING(""),
            PSTRING("")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party
    },
    [0x1e3] = {
        .trainerclass = TRAINERCLASS_PKMN_RANGER, .sprite = 0x3c,
        .encounter_and_gender = {2, 1}, .name = LANGDEP(PSTRING(""),
            PSTRING("")), .pokemon_cnt = 3,
        .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS,
        .party = (trainer_pokemon*) &fmem.dynamic_trainer_party,
    },

    [0x300] = {
      .uses_custom_moves = true, .uses_custom_items = true,
      .trainerclass = TRAINERCLASS_CHEFKOCH, .encounter_and_gender = {1, 0} , .sprite = 0x74,
      .name = LANGDEP(PSTRING("Lester"), PSTRING("Lester")),
      .items = {ITEM_GOLDAPFEL, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG, ITEM_TOP_GENESUNG},
      .ai = TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS | TRAINER_AI_VARIABILITY | TRAINER_AI_SUPER_EFFECTIVE,
      .battle_state = BATTLE_DOUBLE, .pokemon_cnt = 2, .party = (trainer_pokemon*) trainer_party_test,
	  },
}; 
