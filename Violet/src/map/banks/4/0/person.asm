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
    .string "PLAYER! Deine Pokémon sehen sehr\nmüde aus. Setz dich doch zu mir\lund ruhe dich eine Weile aus."



str_0x8a0c66:
    .string "Pass gut auf dich auf, PLAYER."



str_0x8a11ed:
    .string "PLAYER, beeil dich lieber.\nRIVAL wird nicht gerne warten\lgelassen."


.elseif LANG_EN

.endif