.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_trainerschool_blaise_outside
ow_script_trainerschool_blaise_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_faun_appear
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL has_received_pkmn


make_faun_appear:
lock
faceplayer
call ow_script_0x89e33c
loadpointer 0 str_before_faun_appeared
callstd MSG
special 0x7
setflag TRAINERSCHOOL_TALKED_TO_BLAISE
checkflag TRAINERSCHOOL_TALKED_TO_FELIX
gotoif EQUAL ow_script_trainerschool_outside_faun_appears
release
end

has_received_pkmn:
call ow_script_0x89e33c
loadpointer 0 str_has_received_pkmn
callstd MSG_FACE
special 0x7
end

mov_exclam:
	.byte LOOK_DOWN, SAY_EXCLAM, STOP

.ifdef LANG_GER
str_before_faun_appeared:
	.autostring 35 2 "Wirklich eine Unverschämtheit, dass uns der Knacker nach diesem Test auch noch warten lässtDOTS\pMein Vater hätte mich nie auf diese Schule schicken dürfenDOTS"

str_has_received_pkmn:
	.autostring 35 2 "Scheint, als hätte diese Schule doch ihr Gutes.\pEin solches Pokémon sieht man nicht alle TageDOTS"

.elseif LANG_EN

.endif
