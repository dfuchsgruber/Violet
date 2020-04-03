.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_3_2_person_0
.global ow_script_0x8127f3
.global ow_script_map_3_2_person_8
.global ow_script_0x8cee77
.global ow_script_map_3_2_person_10
.global ow_script_map_3_2_person_7
.global ow_script_map_3_2_person_12
.global ow_script_0x8bfdcb
.global ow_script_map_3_2_person_14
.global ow_script_map_3_2_person_6
.global ow_script_map_3_2_person_3
.global ow_script_map_3_2_person_11
.global ow_script_map_3_2_person_2
.global ow_script_map_3_2_person_1
.global ow_script_map_3_2_person_5
.global ow_script_map_3_2_person_13
.global ow_script_0x8c1233
.global ow_script_map_3_2_person_9
.global ow_script_0x89bda0
.global ow_script_map_3_2_person_4

ow_script_map_3_2_person_6:
loadpointer 0x0 str_0x8cb3d6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8cb3d6:
    .string "Wusstest du, dass sich in Muscheln\nwertvolle Perlen verstecken\lkönnen?"


.elseif LANG_EN

.endif


ow_script_map_3_2_person_0:
lock
faceplayer
loadpointer 0 str_rick
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8127cb
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8127f3
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x89bda0
end


ow_script_0x89bda0:
loadpointer 0x0 str_0x8dc0e4
callstd MSG_KEEPOPEN
setweather 0
doweather
cry POKEMON_STARAPTOR 0x0
waitcry
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0xf
special 0x19
waitstate
setflag MAP_BGN_AUTO_ALIGN_OFF
waitstate

clearflag TRANS_DISABLE
clearflag MAP_BGN_AUTO_ALIGN_OFF
warpmuted 0xf 0x1 0x1 0x6 0x4
end


ow_script_0x8127f3:
loadpointer 0x0 str_0x8127fe
callstd MSG_FACE
special 0xF
release
end


.ifdef LANG_GER



str_0x8127cb:
    .autostring 35 2 "Willst du wieder zurück nach Route 3?"



str_0x8dc0e4:
    .autostring 35 2 "Mein Staraptor wird dich jetzt zurückbringen."

str_rick:
	.string "Rick"



str_0x8127fe:
    .autostring 35 2 "Solltest du deine Meinung ändern, weißt du ja, wo du mich findest."


.elseif LANG_EN

.endif


ow_script_map_3_2_person_13:
goto ow_script_0x8cee77


ow_script_0x8cee77:
pause 0x10
callasm 0x919c301
end


ow_script_map_3_2_person_1:
loadpointer 0x0 str_0x847089
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x847089:
    .string "Einst war dieser Ort ein\nFerienparadies. Jeden Tag\lSonnenschein und Schwärme von\lWingull an den Stränden."


.elseif LANG_EN

.endif


ow_script_map_3_2_person_4:
loadpointer 0x0 str_0x8470f4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8470f4:
    .string "Früher einmal lebten ich und meine\nFamilie gemeinsam auf dieser\lInsel. Nachdem der Meteor jedoch\leingeschlagen hat, sind mein Sohn\lund meine Enkel nach Kaskada\lgezogen."


.elseif LANG_EN

.endif


ow_script_map_3_2_person_3:
loadpointer 0x0 str_0x8c0c34
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c0c34:
    .string "Man hat mir gesagt, dass es viele\nWingulls zu sehen gebe, auf dieser\lregnerischen Insel.\pOb man mich vereppelt hat? Das\neinzige weit und breit sind\lschwarze Wolken über uns und keine\lVögel!"


.elseif LANG_EN

.endif


ow_script_map_3_2_person_8:
loadpointer 0x0 str_0x8c0eba
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c0eba:
    .string "Einst war Harren Bürgermeister\ndieser Stadt. Er und seine Gestein\lPokémon waren eine Berühmtheit.\pNach dem Meteoriteneinschlag aber\nübernahm sein Sohn Lester das Amt\ldes Bürgermeisters und\lArenaleiters."


.elseif LANG_EN

.endif


ow_script_map_3_2_person_11:
loadpointer 0x0 str_0x88034f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x88034f:
    .string "Graben und Minen sind meine\nLeidenschaft! Ich werde bald hier\ldamit beginnen! Warts ab!"


.elseif LANG_EN

.endif


ow_script_map_3_2_person_10:
loadpointer 0x0 str_0x8cb5ae
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8cb5ae:
    .string "Was würde ich nur für einen\nRegenschirm gebenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_2_person_9:
loadpointer 0x0 str_0x8c0f86
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c0f86:
    .string "Wenn ich ein Pokémon hätte, das\nSurfer beherrscht, dann könnte ich\lauf ihm gen Westen reiten!"


.elseif LANG_EN

.endif


ow_script_map_3_2_person_5:
loadpointer 0x0 str_0x8c0ff2
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c0ff2:
    .string "Aktania, die Insel der ewigen\nSonne!\lDOTS\pKaum zu glauben, dass dieser Ort\nmal ein Strandresort war, oder?"


.elseif LANG_EN

.endif


ow_script_map_3_2_person_2:
loadpointer 0x0 str_0x8c105d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c105d:
    .string "Nick und Rick nutzen Vögel, um\nhierher zu gelangen. Ihre\lStaraptor sind so gut trainiert,\ldass sie selbst durch die\lGewitterstürme fliegen können."


.elseif LANG_EN

.endif


ow_script_map_3_2_person_7:
checkflag AKTANIA_ROD
gotoif EQUAL ow_script_0x8bfdcb
lock
faceplayer
loadpointer 0x0 str_0x8c16a7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c1233
loadpointer 0x0 str_0x8c1201
callstd MSG
copyvarifnotzero 0x8000 ITEM_ANGEL
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
setflag AKTANIA_ROD
loadpointer 0x0 str_0x8c1179
callstd MSG
release
end


ow_script_0x8c1233:
loadpointer 0x0 str_0x8c1638
callstd MSG
release
end


ow_script_0x8bfdcb:
loadpointer 0x0 str_0x8c1179
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c16a7:
    .string "Angeln! Immer zu das Angeln!\nIch liebe es!\lFindest du nicht auch, dass Angeln\lein toller Sport ist?"



str_0x8c1201:
    .string "Du weißt, worauf es im ankommt!\nHier, nimm das."



str_0x8c1179:
    .string "Wirf einfach den Köder ins Wasser,\nund warte bis etwas anbeißt.\lDie interessantesten Wasserpokemon\lbeißen an verschiedensten Orte an."



str_0x8c1638:
    .string "Du bist ein Ignorant! Das Angeln\nist das einzig Wahre. Komm wieder,\lwenn du deine Einstellung geändert\lhast!"


.elseif LANG_EN

.endif


ow_script_movs_0x8ca7be:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_map_3_2_person_12:
loadpointer 0x0 str_0x8ca6c5
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
applymovement 0x800f ow_script_movs_0x8ca7be
waitmovement 0x0
hidesprite 0x800f
end


.ifdef LANG_GER

str_0x8ca6c5:
	.autostring 35 2 "Sehr schön, du bist also gekommen.\pIch bin von echtem Kampfgeist fasnziniert.\pVor vielen Jahrhunderten hat man in diesem Tempel den Golem-Pokémon gehuldigt.\pSeit dem Vorfall vor einiger Zeit ist von den einst beeindruckenden Kunstwerken nicht mehr viel zu sehen.\pDaher habe ich im Untergrund eine Kampfarena ausgehoben.\pDort werden wirst du mich herausfordern!"

.elseif LANG_EN

.endif


ow_script_map_3_2_person_14:
setflag TRANS_DISABLE
loadpointer 0x0 str_0x8cb5e0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8cb5e0:
    .string "Bonus"


.elseif LANG_EN

.endif