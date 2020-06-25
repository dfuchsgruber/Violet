.include "overworld_script.s"
.include "callstds.s"

.global ow_script_crafting_cauldron

ow_script_crafting_cauldron:
    loadpointer 0 str_cauldron
    callstd MSG_KEEPOPEN
    fadescreen 1
    callasm crafting_ui_initialize
    waitstate
    releaseall
    end

.ifdef LANG_GER
str_cauldron:
    .autostring 34 2 "Ein Laz.-Kessel!"
.elseif LANG_EN
str_cauldron:
    .autostring 34 2 "A Laz.-Cauldron!"
.endif
