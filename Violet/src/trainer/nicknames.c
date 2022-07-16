#include "types.h"
#include "language.h"
#include "trainer/nickname.h"

// Nicknames can not be included in `include/c/data/trainer_parties.h` as header files are not pre-processed by the custom
// python extension this project uses. Therefore, we define names in a separate c file that is compiled correctly

u8 trainer_pokemon_nickname_test[POKEMON_NAME_LENGTH + 1] = LANGDEP(PSTRING("Test"), PSTRING("Test"));