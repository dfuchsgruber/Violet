.include "overworld_script.s"

.global subscript_trainer_challange


subscript_trainer_challange:
    special 0x1A
    waitmovement 0
    special 0x34
    waitmsg
    waitkeypress
    return
