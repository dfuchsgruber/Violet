#ifndef H_OVERWORLD_STEP_CALLBACK
#define H_OVERWORLD_STEP_CALLBACK

#include "callbacks.h"
#include "constants/overworld/step_callback.h"
#include "types.h"

enum {
    OVERWORLD_STEP_CALLBACK_IDX = 0,
    OVERWORLD_STEP_CALLBACK_STATE = 1,
};

/**
 * Callback that is exectued every frame and is supposed to act on the tile the player is on. Usually set via levelscripts
 * @param self self-reference
 */
void overworld_step_callback_proceed(u8 self);

#endif
