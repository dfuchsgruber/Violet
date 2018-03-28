.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949cfd
ow_script_0x949cfd:
checkflag ROUTE_5_CLOUD_RECEIVED
gotoif EQUAL ow_script_0x94ba17
lock
faceplayer
loadpointer 0x0 str_0x94b8ae
callstd MSG_KEEPOPEN
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x94bff4
loadpointer 0x0 str_0x949ddc
callstd MSG_KEEPOPEN
checkitem ITEM_ITEM_10B 0x1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x94c10c
closeonkeypress
release
end


.global ow_script_movs_0x94c6c7
ow_script_movs_0x94c6c7:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x94c10c
ow_script_0x94c10c:
sound 0x15
applymovement 0x800f ow_script_movs_0x94c6c7
waitmovement 0x0
goto ow_script_0x949d36


.global ow_script_0x949d36
ow_script_0x949d36:
loadpointer 0x0 str_0x94c615
callstd MSG_KEEPOPEN
fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
removeitem ITEM_ITEM_10B 0x1
loadpointer 0x0 str_0x94ba96
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
setflag ROUTE_5_CLOUD_RECEIVED
end


.global ow_script_0x94bff4
ow_script_0x94bff4:
fadesong MUS_CLOUDS
goto ow_script_0x94be7e


.global ow_script_movs_0x94be6d
ow_script_movs_0x94be6d:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x94bc7c
ow_script_movs_0x94bc7c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x94be7e
ow_script_0x94be7e:
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry
sound 0x15
applymovement 0xff ow_script_movs_0x94be6d
applymovement 0x800f ow_script_movs_0x94be6d
waitmovement 0x0
loadpointer 0x0 str_0x94be36
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
clearflag PKMNMENU
showsprite 0xd
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be24
call ow_script_0x94be70
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bdbf
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bd31
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bc7f
callstd MSG
cry POKEMON_ALTARIA 0x0
waitcry
applymovement 0x800f ow_script_movs_0x94bc7c
waitmovement 0x0
fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry
loadpointer 0x0 str_0x94bf95
callstd MSG
fadescreen 0x1
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
hidesprite 0xd
fadescreen 0x0
goto ow_script_0x94c103


.global ow_script_0x94c103
ow_script_0x94c103:
fadesong MUS_ROUTE_3_10_AND_ROUTE_16_22
goto ow_script_0x94c5f5


.global ow_script_0x94c5f5
ow_script_0x94c5f5:
loadpointer 0x0 str_0x94bb88
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
setflag PKMNMENU
setflag ROUTE_5_CLOUD_RECEIVED
release
end


.global ow_script_movs_0x94c591
ow_script_movs_0x94c591:
.byte STEP_IN_PLACE_DOWN_FAST
.byte 0x1c
.byte 0x1c
.byte STEP_DOWN
.byte STOP


.global ow_script_0x94be70
ow_script_0x94be70:
sound 0x96
applymovement 0xd ow_script_movs_0x94c591
waitmovement 0x0
return


.global ow_script_movs_0x94be33
ow_script_movs_0x94be33:
.byte STEP_DOWN_VERY_SLOW
.byte STOP


.global ow_script_0x94be24
ow_script_0x94be24:
sound 0x96
applymovement 0xd ow_script_movs_0x94be33
waitmovement 0x0
return


.global ow_script_0x94ba17
ow_script_0x94ba17:
loadpointer 0x0 str_0x94ba21
callstd MSG_FACE
end

.global str_0x94b8ae

str_0x94b8ae:
    .string "Ich bin ein Priester des\nhimmlischen Volkes.\pWir sind eine traditionsreiche\nNation, musst du wissen.\pWir beherrschen die geheime Kunst\ndes Wolkenwebens.\pMenschen können auf gewobenen\nWolken in die Lüfte steigen und\lfliegen.\p... ...\pDu willst eine gewobene Wolke\nbesitzen?\pTut mir leid, aber ich kann dir\nnicht ohne Weiteres etwas\lderartiges nicht überlassen."
        
        
.global str_0x949ddc

str_0x949ddc:
    .string "Allerdings...\n...\pWeißt du, Professor Tann, ein\nArchäologe hat ein wertvolles\lArtefakt unseres Volkes entdeckt.\pAnstatt es uns aber zu geben, hat\ner es dem Museum von Orina City\lübergeben.\pWenn du uns dieses Artefakt\nwiederbeschaffst...\pHast du deine Treue gegenüber dem\nhimmlischen Volk bewiesen und ich\lwerde dir eine gewobene Wolke\lvermachen."
        
        
.global str_0x94c615

str_0x94c615:
    .string "Oh? Du hast das Wolkenherz\ntatsächlich mitgebracht?\pIch muss mich vielmals bei dir\nbedanken, du bist ein Held.\pNun kann ich dir die gewobene\nWolke mit gutem Herzen\lüberreichen."
        
        
.global str_0x94bc55

str_0x94bc55:
    .string "PLAYER hat eine\ngewobene Wolke erhalten."
        
        
.global str_0x94ba96

str_0x94ba96:
    .string "Das Wolkenherz ist ein heiliges\nRelikt, das von Rechtswegen her\ldem Volk der Wolkenmenschen\lgehören muss.\pDie gewobene Wolke ist als\nBelohnung nur fair."
        
        
.global str_0x94c596

str_0x94c596:
    .string "Du kannst auf einer gewobenen\nWolke auch reiten, als wäre sie\lein Fahrad oder ein Skateboard."
        
        
.global str_0x94ba21

str_0x94ba21:
    .string "Wenn du am Boden den Schatten\neiner tieffliegenden Wolke siehst,\lkannst du auf deiner gewobenen\lWolke emporsteigen."
        
        
.global str_0x94be36

str_0x94be36:
    .string "Was ist das?\nEs hört sich an wie Ruf eines\lAltarias!"
        
        
.global str_0x94bdbf

str_0x94bdbf:
    .string "Das ist... das ist ...\nEin goldenes Altaria!\lDass ich das mit meinen eigenen\lAugen bewundern darf!"
        
        
.global str_0x94bd31

str_0x94bd31:
    .string "Es ... es will dir etwas sagen!\nDas goldene Altaria spricht mit\ldir...\pIch werde es übersetzten, ich kann\ndie Sprache der Wolken verstehen."
        
        
.global str_0x94bc7f

str_0x94bc7f:
    .string "Das goldene Altaria sagt, du\nhättest sein Ei beschützt, in\leiner Mühle auf Route 3.\pEs will dir seinen Dank\naussprechen und dir...\pEine von ihm selbst gewobene\nWolke schenken!"
        
        
.global str_0x94bf95

str_0x94bf95:
    .string "Das Altaria möchte sich\nverabschieden, es wird wieder in\ldie unendlichen Weiten\ldavongleiten."
        
        
.global str_0x94bb88

str_0x94bb88:
    .string "Du bist ein wahrer Glückspliz.\nNur wenige Menschen besitzen eine\lgewobene Wolke und noch weniger\leine, die von einem Altaria selbst\lgeschaffen wurde.\pDanke, dass ich diesen Augenblick\nmiterleben durfte!"
        
        