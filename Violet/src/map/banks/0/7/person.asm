.include "callstds.s"
.include "overworld_script.s"

.global ow_script_tafelberg_lapis_cave_person_0

ow_script_tafelberg_lapis_cave_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die azurfarbenen Felsen in dieser Höhle sind so wunderschön, findest du nicht?\pDer Tafelberg ist wirklich ein beeindruckendes Stück Natur!"
.elseif LANG_EN
.endif