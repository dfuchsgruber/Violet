#include "types.h"
#include "trainer/trainer.h"
#include "overworld/script.h"
#include "save.h"

bool overworld_script_command_trainerbattle(overworld_script_state_t *state) {
    fmem.current_trainer = 0;
    state->script = trainer_configure_by_overworld_script(state->script);
    return false;
}