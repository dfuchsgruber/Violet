.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8310cc
ow_script_movs_0x8310cc:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8310d3
ow_script_movs_0x8310d3:
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8310d6
ow_script_movs_0x8310d6:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8310d9
ow_script_movs_0x8310d9:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x83103c
ow_script_0x83103c:
lock
pause 0x10
special 0x113
applymovement 0x7f ow_script_movs_0x8310cc
waitmovement 0x0
special 0x114
pause 0x10
applymovement 0x4 ow_script_movs_0x8310d3
waitmovement 0x0
loadpointer 0x0 str_0x8310dc
callstd MSG
applymovement 0x3 ow_script_movs_0x8310d6
applymovement 0xff ow_script_movs_0x8310d9
waitmovement 0x0
trainerbattlecont 0x1 0x19f 0x0 str_0x83114c str_0x8311a8 ow_script_0x83108d


.global ow_script_0x83108d
ow_script_0x83108d:
loadpointer 0x0 str_0x8311c0
callstd MSG
fanfare 0x104
loadpointer 0x0 str_0x8f2a1f
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag FRBADGE_2
call ow_script_0x85fc97
end


.global ow_script_0x85fc97
ow_script_0x85fc97:
clearflag FRBADGE_3
clearflag FRBADGE_4
loadpointer 0x0 str_0x8f36ad
callstd MSG
copyvarifnotzero 0x8000 ITEM_TM19
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x85f329
end


.global ow_script_0x85f329
ow_script_0x85f329:
loadpointer 0x0 str_0x8f3750
callstd MSG
warpmuted 0x3 0x3 0x8 0x20 0x12
release
end

.global str_0x8310dc

str_0x8310dc:
    .string "Nun gut! Der Kampf in der\nSilvania-Arena möge nun beginnen!\lDer Herausforderer PLAYER tritt\lgegen Mia an."
        
        
.global str_0x83114c

str_0x83114c:
    .string "Denke nicht, dass ich mich\nzurückhalte! Ich gebe alles!"
        
        
.global str_0x8311a8

str_0x8311a8:
    .string "Unfassbar, unglaublich!"
        
        
.global str_0x8311c0

str_0x8311c0:
    .string "Dieser Kampf war wirklich\nüberragend! Den Ranken-Orden\lhast du dir redlich verdient!"
        
        
.global str_0x8f2a1f

str_0x8f2a1f:
    .string "PLAYER hat den Ranken-Orden\nerhalten!"
        
        
.global str_0x8f36ad

str_0x8f36ad:
    .string "Nun hast du wirklich bewiesen,\ndass du es mit Team Violet\laufnehmen kannst.\lNimm außerdem noch diese\pTechnische Maschine, sie wird\ndeine Pokémon stärker machen."
        
        
.global str_0x8f3750

str_0x8f3750:
    .string "Diese Technische Maschine enthält\nGigasauger. Sie fügt deinem Gegner\lSchaden zu und stellt die Kraft\ldes Anwenders gleichzeitig wieder\lher. Die perfekte Waffe im Kampf\lgegen Team Violet.\lIch bitte dich, rette den Wald,\lvertreibe diese bösen Menschen!"
        
        