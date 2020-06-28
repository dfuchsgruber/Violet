.include "vars.s"
.include "specials.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"

.global ow_script_0x8a0ce0
.global ow_script_map_4_0_person_0

ow_script_map_4_0_person_0:
compare TRAINERSCHOOL_DONE 0x0
gotoif EQUAL ow_script_0x8a0ce0
lock
faceplayer
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x8a0c83
callstd MSG
special 0xF
call ow_script_healing_sequence
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x8a0c66
callstd MSG
special 0xF
release
end


ow_script_0x8a0ce0:
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x8a11ed
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
str_0x8a0c83:
    .autostring 34 2 "PLAYER, du und deine Pokémon sehen sehr müde aus.\pSetz dich doch eine Weile zu mir und ruh dich etwas aus!"
str_0x8a0c66:
    .autostring 34 2 "Na also, du siehst schon wieder viel besser aus!\pPass auf dich auf, Liebling!"
str_0x8a11ed:
    .autostring 34 2 "PLAYER, beeil dich lieber.\nRIVAL wird nicht gerne warten gelassen."
.elseif LANG_EN
str_0x8a0c83:
    .autostring 34 2 "PLAYER, both you and your Pokémon look tired.\pTake moment and rest here with me, honey!"
str_0x8a0c66:
    .autostring 34 2 "See, you look a lot better now.\pTake care of yourself, honey!"
str_0x8a11ed:
    .autostring 34 2 "PLAYER, you better hurry up.\pRIVAL doesn't like waiting at all."
.endif