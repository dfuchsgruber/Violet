.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "unown_messages.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_kaskada_clouds_ruins_entrance_sign

ow_script_kaskada_clouds_ruins_entrance_sign:
    checkflag FLAG_UNOWN_ENABLED
    gotoif NOT_EQUAL ow_script_unown_not_enabled
    lockall
    setvar 0x8004 UNOWN_MESSAGE_BY_HEADER
    setvar 0x8005 8
    setvar 0x8006 2
    special SPECIAL_UNOWN_MESSAGE_PRINT
    waitstate
    special SPECIAL_UNOWN_MESSAGE_REMOVE
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Seltsam.\nAuf dem Schild steht gar nichts geschriebenDOTS"
.elseif LANG_EN
.endif
