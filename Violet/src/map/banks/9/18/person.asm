.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x95d7ed
.global ow_script_map_9_18_person_3
.global ow_script_0x95d6af
.global ow_script_map_9_18_person_0
.global ow_script_0x95d53e
.global ow_script_map_9_18_person_2
.global ow_script_0x95d703
.global ow_script_map_9_18_person_1
.global ow_script_0x95d64e

ow_script_movs_0x95d7ea:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_9_18_person_0:
lock
faceplayer
loadpointer 0x0 str_0x95d7f0
callstd MSG
checkitem ITEM_HERZSCHUPPE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95d7ed
sound 0x15
applymovement 0x800f ow_script_movs_0x95d7ea
waitmovement 0x0
loadpointer 0x0 str_0x95d771
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95d703
goto ow_script_0x95d53e


ow_script_0x95d53e:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x95d618
callstd MSG_KEEPOPEN
special 0xdb
waitstate
clearflag TRANS_DISABLE
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x95d703
special 0x148
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95d6af
compare 0x8005 0x0
gotoif EQUAL ow_script_0x95d64e
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x95d5ee
callstd MSG_KEEPOPEN
special 0xe0
waitstate
clearflag TRANS_DISABLE
compare 0x8004 0x0
gotoif EQUAL ow_script_0x95d53e
removeitem ITEM_HERZSCHUPPE 0x1
loadpointer 0x0 str_0x95d5a7
callstd MSG
release
end


ow_script_0x95d64e:
loadpointer 0x0 str_0x95d659
callstd MSG
release
end


ow_script_0x95d6af:
loadpointer 0x0 str_0x95d6ba
callstd MSG
release
end


ow_script_0x95d703:
loadpointer 0x0 str_0x95d70e
callstd MSG
release
end


ow_script_0x95d7ed:
release
end


.ifdef LANG_GER

str_0x95d7f0:
    .string "Ich bin der Attacken-Erinnerer.\nMeine Fähigkeit ist es, Pokémon\lwieder an verlernte Attacken zu\lerinnern.\pIm Gegenzu verlange ich dafür\nallerdins eine Herzschuppe."



str_0x95d771:
    .string "Wie aufregend! Du hast eine\nHerzschuppe bei dir!\pSoll ich einem deiner Pokémon zu\neiner vergessenen Attacke\lverhelfen?"



str_0x95d618:
    .string "Welches Pokémon soll sich an eine\nAttacke erinnern?"



str_0x95d5ee:
    .string "Welche Attacke soll ich ihm\nbeibringen?"



str_0x95d5a7:
    .string "Na das hat doch wunderbar\ngeklappt!\pVielen Dank für die Herzschuppe!"



str_0x95d659:
    .string "HmmDOTS\nEs sieht so aus, als könnte sich\ldieses Pokémon an keine Attacke\lerinnernDOTS"



str_0x95d6ba:
    .string "Das ist ja ein Ei!\nWie soll ich einem Ei denn eine\lAttacke beibringen?"



str_0x95d70e:
    .string "Das ist außerordentlich schade!\nKomm gerne wieder vorbei, wenn du\lmeine Hilfe brauchen solltest."


.elseif LANG_EN

.endif


ow_script_map_9_18_person_2:
loadpointer 0x0 str_0x95d89f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d89f:
    .string "Viele Leute werfen Beeren oder\nandere Dinge in den Müll.\pIch habe gehört, dass man im Laufe\neiner Woche sehr viele neue Dinge\lfinden kann."


.elseif LANG_EN

.endif


ow_script_map_9_18_person_3:
loadpointer 0x0 str_0x95d935
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d935:
    .string "Wir dicken Leute haben nicht viele\nFreunde, musst du wissen.\pBloß die kleinen Kinder verachten\nuns nicht wegen unserer FigurDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_18_person_1:
loadpointer 0x0 str_0x95d9c0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d9c0:
    .string "Die Königin der Finsternis ist die\ngrößte aller Hexen.\pIhre Magie hat hunderte\nverfluchte Seelen an ein\lmächtiges Pokémon gebunden, so die\lLegendeDOTS"


.elseif LANG_EN

.endif