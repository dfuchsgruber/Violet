.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x897e33
ow_script_movs_0x897e33:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x83093d
ow_script_movs_0x83093d:
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x830940
ow_script_movs_0x830940:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x830943
ow_script_movs_0x830943:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x89472b
ow_script_0x89472b:
special 0x113
applymovement 0x7f ow_script_movs_0x897e33
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x83093d
waitmovement 0x0
loadpointer 0x0 str_0x8cae89
callstd MSG
applymovement 0x1 ow_script_movs_0x830940
applymovement 0xff ow_script_movs_0x830943
waitmovement 0x0
call ow_script_0x893aca
trainerbattlecont 0x1 0xb6 0x0 str_0x8cafb5 str_0x8cb08b ow_script_0x8947e3


.global ow_script_0x8947e3
ow_script_0x8947e3:
call ow_script_0x893aca
loadpointer 0x0 str_0x8cb101
callstd MSG
special 0x7
fanfare 0x104
loadpointer 0x0 str_0x897c8a
callstd MSG
waitfanfare
call ow_script_0x893aca
loadpointer 0x0 str_0x8cb1cc
callstd MSG
special 0x7
copyvarifnotzero 0x8000 ITEM_TM39
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
call ow_script_0x893aca
goto ow_script_0x899429


.global ow_script_0x899429
ow_script_0x899429:
loadpointer 0x0 str_0x8cb281
callstd MSG
special 0x7
setflag FRBADGE_1
setvar STORY_PROGRESS 0x14
warpmuted 0x3 0x2 0x4 0x2d 0x22
release
end


.global ow_script_0x893aca
ow_script_0x893aca:
setvar 0x8000 0x0
setvar 0x8001 0xd
setvar 0x8002 0xf
special 0x6
return


.ifdef LANG_GER

.global str_0x8cae89

str_0x8cae89:
	.autostring 35 2 "Es beginnt nun der Kampf zwischen Lester und PLAYER um den Antikorden.\pIch erwarte einen fairen Kampf!"
        
        
.global str_0x8cafb5

str_0x8cafb5:
	.autostring 35 2 "Auch wenn du mir sympatisch bist, werde ich mich nicht zurückhalten.\pMeine Gestein-Pokémon werden dich das fürchten lehren!"
        
.global str_0x8cb08b

str_0x8cb08b:
    .autostring 35 2 "Beeindruckend gekämpft!\pSelbst meine felsenharten Gestein-Pokémon konnten dir nichts entgegensetzen."
        
        
.global str_0x8cb101

str_0x8cb101:
	.autostring 35 2 "Du hast hervorragend gekämpft!\pDen Antikorden hast du dir redlich verdient!"
        
.global str_0x897c8a

str_0x897c8a:
    .autostring 35 2 "PLAYER hat den Antikorden von Lester erhalten!"
        
        
.global str_0x8cb1cc

str_0x8cb1cc:
	.autostring 35 2 "Dieser Orden erlaubt es dir, die Versteckte Maschine Blitz außerhalb des Kampfes zu nutzen.\pZudem gehorchen dir getauschte Pokémon bis Level 30.\pDOTS DOTS DOTS\pDarüber hinaus will ich dir noch etwas als Symbol meiner persönlichen Wertschätzung überreichen."
        
.global str_0x8cb281

str_0x8cb281:
	.autostring 35 2 "Diese Technische Maschine enthält die Attacke Felsgrab.\pSie ist eine meiner Lieblingsattacken, weil sie den Gegner schadet und gleichzeitig verlangsamt.\pEin idealer Angriff für langsamere Pokémon, wie etwa meine Gestein-Typen.\pIch hoffe, sie wird dir auf deiner Reise nützen.\pBegleite mich nun bitte aus der Untergrund-Arena."
        
.elseif LANG_EN

.endif
