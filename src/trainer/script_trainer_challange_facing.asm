.include "overworld_script.s"

.global subscript_trainer_challange


subscript_trainer_challange:
    special 0x1A
    applymovement 0xFF 0x020370D0
    waitmovement 0
    special 0x34
    waitmsg
    waitkeypress
    return
