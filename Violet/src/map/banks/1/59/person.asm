.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "songs.s"

.global ow_script_kuestenberg_harrenfeld

ow_script_kuestenberg_harrenfeld:
    loadpointer 0x0 str_0
    show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER!\nDu kommst gerade recht!\pDiese Revolutionäre sind verflixt hartnäckig!\pAber Faun ist bereits weiter vorgedrungen, um den Revolutionsführer Albus zu stellen!"

.elseif LANG_EN
.endif