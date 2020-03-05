.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "specials.s"

.global ow_script_whiteout_mother

ow_script_whiteout_mother:
lockall
applymovement 0x1 mov_look_down_delayed
waitmovement 0x0
loadpointer 0x0 str_0x89ba8d
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_mother_before
callstd MSG_KEEPOPEN
call ow_script_healing_sequence
loadpointer 0x0 str_mother_after
callstd MSG_KEEPOPEN
special 0xF
songfadedefault
releaseall
end


.global ow_script_healing_sequence
ow_script_healing_sequence:
fadescreen 0x1
fanfare 0x100
waitfanfare
special SPECIAL_HEAL
fadescreen 0x0
return


.global ow_script_whiteout_joy

ow_script_whiteout_joy:
lockall
loadpointer 0x0 str_joy_before
callstd MSG_KEEPOPEN
call ow_script_joy_healing_sequence
loadpointer 0x0 str_joy_after
callstd MSG_KEEPOPEN
applymovement 0x800f mov_joy_bow_down
waitmovement 0x0
songfadedefault
releaseall
end

ow_script_joy_healing_sequence:
applymovement 0x800f mov_look_left_delayed
waitmovement 0x0
doanimation 0x19
nop
checkanimation 0x19
applymovement 0x800f mov_look_down_delayed
waitmovement 0x0
special SPECIAL_HEAL
return

mov_joy_bow_down:
	.byte 0x5b
	.byte 0x1a
	.byte STOP

mov_look_left_delayed:
	.byte LOOK_LEFT_DELAYED
	.byte STOP

mov_look_down_delayed:
	.byte LOOK_DOWN_DELAYED
	.byte STOP

.ifdef LANG_GER
str_mother_before:
	.autostring 35 2 "PLAYER!\pDu hast sicherlich viel erlebt!\pDu solltest dich kurz hier ausruhen."

str_mother_after:
	.autostring 35 2 "Fantastisch!\pDeine Pokémon sehen wieder fit aus!"

str_joy_before:
	.autostring 35 2 "Zunächst solltest du deine Pokémon vollständig heilen."

str_joy_after:
	.autostring 35 2 "Deine Pokémon wurden vollständig geheilt.\pWir hoffen, du kommst groß raus!"

.global str_whiteout
str_whiteout:
	.string "PLAYER rannte zu einem Pokéstop\nund beschützte die\nerschöpften und besiegten\nPokémon vor weiterem SchadenDOTS\p"

.elseif LANG_EN

.endif
