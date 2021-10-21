#include "stdbool.h"
#include "trainer/trainer.h"
#include "types.h"

extern u8 trainer_class_names[][13];

u8 *trainer_get_class_name(int unkown, u16 trainer_id) {
    (void)(unkown);
    return trainer_class_names[trainers[trainer_id].trainerclass];
}
