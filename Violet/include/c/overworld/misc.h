#ifndef H_OVERWORLD_MISC
#define H_OVERWORLD_MISC

#include "constants/overworld/misc.h"
#include "save.h"
#include "types.h"

/**
 * "Regrows" (i.e. makes them reappear) the mushrooms and shells. That is, all flags are simply cleared.
 */
void overworld_misc_intialize();

/**
 * Gets the stage of a mushroom
 * @param mushroom_idx the mushroom to get the stage of
 * @return the mushroom's stage
 */
u16 mushroom_get_stage(u16 mushroom_idx);

/**
 * Gets the stage of a shell
 * @param shell_idx the shell to get the stage of
 * @return the shell's stage
 */
u16 shell_get_stage(u16 shell_idx);

/**
 * Gets the content of a trash can
 * @param trash_idx the trash can to check
 * @return content of the trash can
 */
u16 trash_get_type(u16 trash_idx);

#endif
