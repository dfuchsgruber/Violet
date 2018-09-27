.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "species.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x949cfd
ow_script_0x949cfd:
checkflag ROUTE_5_CLOUD_RECEIVED
gotoif EQUAL ow_script_0x94ba17
lock
faceplayer

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94b8ae
callstd MSG_KEEPOPEN
special 0xF

checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x94bff4

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x949ddc
callstd MSG_KEEPOPEN
special 0xF

checkitem ITEM_ITEM_10B 0x1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x94c10c
closeonkeypress
special 0xF
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

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94c615
callstd MSG_KEEPOPEN
special 0xF

fanfare 0x13e
additem ITEM_FAHRRAD 0x1
loadpointer 0x0 str_0x94bc55
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
removeitem ITEM_ITEM_10B 0x1


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94ba96
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
special 0xF
setflag ROUTE_5_CLOUD_RECEIVED
end




.global ow_script_movs_0x94be6d
ow_script_movs_0x94be6d:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x94bc7c
ow_script_movs_0x94bc7c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x94bff4
ow_script_0x94bff4:
fadesong MUS_CLOUDS
closeonkeypress
cry POKEMON_ALTARIA 0x0
waitcry
sound 0x15
applymovement 0xff ow_script_movs_0x94be6d
applymovement 0x800f ow_script_movs_0x94be6d
waitmovement 0x0


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94be36
callstd MSG
special 0xF

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


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bdbf
callstd MSG
special 0xF

cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bd31
callstd MSG
special 0xF

cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bc7f
callstd MSG
special 0xF

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

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bf95
callstd MSG
special 0xF
fadescreen 0x1
cry POKEMON_ALTARIA 0x0
waitcry
cry POKEMON_ALTARIA 0x0
waitcry
hidesprite 0xd
fadescreen 0x0
fadesong MUS_ROUTE_3_10_AND_ROUTE_16_22


loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94bb88
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94c596
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x94ba21
callstd MSG
special 0xF
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

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94ba21
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
.global str_0x94b8ae

str_priest:
	.string "Wolkenpriester"

str_0x94b8ae:
	.autostring 35 2 "Hallo, junger Trainer!\pIch bin ein Priester der Wolken.\pWir haben eine traditionsreiche Kultur, musst du wissen.\pAußerdem beherrschen wir die Kunst des Wolkenwebens.\pMenschen können auf gewobenen Wolken schweben.\pDOTS DOTS DOTS\pLeider kann ich dir so eine Wolke nicht einfach überlassen.\pNur, wer sich durch Hingabe als würdig erweist, erhält das Privileg, auf einer gewobenen Wolke zu fliegen."
        
.global str_0x949ddc

str_0x949ddc:
	.autostring 35 2 "Allerdings DOTS DOTS DOTS\pIch könnte eine Ausnahme machen, vorausgesetzt, du bist bereit, eine Gegenleistung zu erbringen.\pDer Archäologe Professor Tann hat vor einier Zeit ein Artefakt entdeckt, das eigentlich unsere Kultur hätte zugestanden.\pStattdessen aber hat man es in das Orina City Museum gebracht.\pWenn du uns das Wolkenherz aus dem Museum beschaffen kannst, werde ich dir im Gegenzug eine Wolke weben."

        
        
.global str_0x94c615

str_0x94c615:
	.autostring 35 2 "Oh? Du hast es tatsächlich dabei, das Wolkenherz?\pIch muss mich bei dir bedanken, du hast unserer Kultur einen großen Gefallen erwiesen.\pIch kann dir nun guten Gewissens eine Wolke weben."
        
        
.global str_0x94bc55

str_0x94bc55:
    .string "PLAYER hat eine\ngewobene Wolke erhalten."
        
        
.global str_0x94ba96

str_0x94ba96:
	.autostring 35 2 "Das Wolkenherz ist ein uraltes Relikt, das schon viele Generationen vor uns in Ehren gehalten haben.\pEs gehört den Wolkenmenschen und sollte nicht in einem Museum ausgestellt werden."

.global str_0x94c596

str_0x94c596:
    .autostring 35 2 "Du kannst auf einer Wolke wie auf einem Fahrad die Landschaft schneller erkunden."
        
        
.global str_0x94ba21

str_0x94ba21:
    .autostring 35 2 "Wenn du am Boden den Schatten einer tiefliegenden Wolke erkennst, kannst du auf deiner gewobenen Wolke in den Himmel emporsteigen."
        
        
.global str_0x94be36

str_0x94be36:
    .autostring 35 2 "Wie, was ist das?\pDer Ruf eines Altarias?"
        
        
.global str_0x94bdbf

str_0x94bdbf:
    .autostring 35 2 "Ist das ein goldenes Altaria?\pSo etwas habe ich noch nie gesehen!"
        
        
.global str_0x94bd31

str_0x94bd31:
    .autostring 35 2 "Es DOTS DOTS DOTS\nscheint sich bei dir für etwas bedanken zu wollen DOTS"
        
        
.global str_0x94bc7f

str_0x94bc7f:
	.autostring 35 2 "Weißt du, warum das Altaria in deiner Schuld steht?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pSo so! Du hast sein Ei beschützt?\pSag das doch gleich!\pJemand, der einem solchen Pokémon selbstlos seine Hilfe geschenkt hat, ist sicherlich würdig, eine gewobene Wolke zu besitzen."
        
        
.global str_0x94bf95

str_0x94bf95:
    .autostring 35 2 "Das Altaria verabschiedet sich von dir.\pEs ist ein wirklich rührender Augenblick!"
        
        
.global str_0x94bb88

str_0x94bb88:
	.autostring 35 2 "Du bist ein wirklich bemerkenswertes Kind.\pDu hast außerordentliches Glück, ein goldenes Altaria mit eigenen Augen zu sehen.\pNicht viele Menschen können das von sich behaupten."

        
.elseif LANG_EN

.endif
