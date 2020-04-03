.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_6_2_person_0
.global ow_script_map_6_2_trainer_0
.global ow_script_map_6_2_trainer_1
.global ow_script_0x8f6d7a
.global ow_script_0x8caa15
.global ow_script_0x8ca829

ow_script_movs_0x8ca8f6:
.byte STEP_UP
.byte STOP


ow_script_map_6_2_person_0:
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x8ca829
loadpointer 0x0 str_0x8ca8f9
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
applymovement 0x800f ow_script_movs_0x8ca8f6
waitmovement 0x0
hidesprite 0x800f
goto ow_script_0x8f6d7a


ow_script_0x8f6d7a:
setvar STORY_PROGRESS 0x12
clearflag AKTANIA_LESTER_ARENA
warp 0x6 0x1 0x0 0x0 0x0
end


ow_script_0x8ca829:
loadpointer 0x0 str_0x8ca83f
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
end


.ifdef LANG_GER

str_0x8ca8f9:
	.autostring 35 2 "Vor langer Zeit erbauten meine Vorfahren diesen Tempel und die Wunderwerke darin.\pIch werde dich jetzt in die Kampfarena im Untergrund führen."



str_0x8ca83f:
	.autostring 35 2 "Ich werde auch in Zukunft über diesen Ort wachen, wie es die Tradition meiner Familie ist.\pAuf dieses Vermächtnis bin ich äußerst stolz."

.elseif LANG_EN

.endif


ow_script_map_6_2_trainer_1:
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x8caa15
loadpointer 0x0 str_aktania_gym_referee
callstd MSG_FACE
end


ow_script_0x8caa15:
loadpointer 0 str_0x8cab11
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8cab11:
    .autostring 34 2 "Gute Arbeit!\nManus zu besiegen, ist kein Leichtes!\pDass du an seiner harten Verteidigungslinie vorbeigekommen bist, zeugt von deinem Talent, Kindchen!"


.elseif LANG_EN

.endif


ow_script_map_6_2_trainer_0:
trainerbattlestd 0x0 0x12 0x0 str_0x8cac8d str_0x8cad12
loadpointer 0x0 str_0x8cad12
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8cac8d:
    .string "In diesem Tempel fühle ich mich\nmeinen Gestein-Pokémon sehr nahe.\lIch bin Lester dankbar für diesen\lOrt und werde ihn verteidigen!"



str_0x8cad12:
    .string "Lester erwartet dich bereits. Du\nkannst es sicherlich mit ihm\laufnehmen, aber ob du gewinnen\lwirst, ist eine andere SacheDOTS"


.elseif LANG_EN

.endif