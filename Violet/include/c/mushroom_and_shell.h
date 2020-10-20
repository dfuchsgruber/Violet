#ifndef H_MUSHROOM_AND_SHELL
#define H_MUSHROOM_AND_SHELL

#include "types.h"
#include "save.h"
#include "constants/mushroom_and_shell.h"

/**
 * "Regrows" (i.e. makes them reappear) the mushrooms and shells. That is, all flags are simply cleared.
 **/
void mushroom_and_shell_regrow();

/**
 * Gets the stage of a mushroom
 * @param mushroom_idx the mushroom to get the stage of
 * @return the mushroom's stage
 **/
u16 mushroom_get_stage(u16 mushroom_idx);

/**
 * Gets the stage of a shell
 * @param shell_idx the shell to get the stage of
 * @return the shell's stage
 **/
u16 shell_get_stage(u16 shell_idx);

#endif