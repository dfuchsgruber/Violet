.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_3_23_trainer_4
.global ow_script_0x94bff4
.global ow_script_map_3_23_trainer_12
.global ow_script_0x94be70
.global ow_script_map_3_23_trainer_2
.global ow_script_map_3_23_trainer_10
.global ow_script_map_3_23_trainer_0
.global ow_script_map_3_23_trainer_8
.global ow_script_0x949a37
.global ow_script_0x94c10c
.global ow_script_0x94be24
.global ow_script_0x94ba17
.global ow_script_map_3_23_trainer_11
.global ow_script_map_3_23_trainer_5
.global ow_script_map_3_23_trainer_6
.global ow_script_map_3_23_trainer_9
.global ow_script_map_3_23_trainer_7
.global ow_script_map_3_23_trainer_1
.global ow_script_map_3_23_trainer_3

ow_script_map_3_23_trainer_1:
loadpointer 0 str_0
callstd MSG_FACE
end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Seit einigen Jahren ist es in Mode, auf einer Wolke zu reiten.\pIch wünschte, ich besäße so eine Wolke."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Some years ago it became a trend to ride a cloud.\pI wish I had one of those."


.endif


ow_script_map_3_23_trainer_2:
trainerbattlestd 0x0 0x85 0x0 str_0x949732 str_0x9497bd
loadpointer 0x0 str_0x9497bd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949732:
    .string "Diese Ruinen entstammen der Kultur\neines antiken Volkes.\pSie haben die Wolken und das\nsymbolisch dafür stehende Pokémon\lAltaria verehrt."



str_0x9497bd:
    .string "Noch heute findet der Kult der\nWolkenmenschen Anhänger."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_3:
loadpointer 0x0 str_0x94982e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94982e:
    .string "Hast du je von der Laz.Corp\ngehört?\pSie ist für den rapiden\ntechnischen Fortschritt unserer\lZeit verantwortlich!"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_7:
loadpointer 0x0 str_0x949bd4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949bd4:
    .string "Wir sind Wolkenpriester und\nWolkenreiter und verehren den\lHimmel.\pUnsere Tradition reicht bis zu den\nAnfängen der Geschichte zurück.\pEines Tages wird der große grüne\nDrache erneut herabsteigen und ein\lneues Zeitalter einläuten."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_0:
trainerbattlestd 0x0 0x86 0x0 str_0x948c85 str_0x9497f6
loadpointer 0x0 str_0x9497f6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x948c85:
    .string "Es tut mir im Herzen weh, wie ihr\njungen Leute das Vermächtnis\lmeiner Generation vernichtet."



str_0x9497f6:
    .string "Dass du nicht einmal den Anstand\nhast, zu verlierenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_4:
trainerbattlestd 0x0 0x87 0x0 str_0x9498a0 str_0x94994a
loadpointer 0x0 str_0x94994a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9498a0:
    .string "Hast du es schon gehört?\pDie Laz.Corp will diesen Monat\nnoch ein Produkt namens Poképad\lauf den Markt bringen.\pAls Ass-Trainer muss ich mir das\nauf jeden Fall ansehen."



str_0x94994a:
    .string "Wie, du besitzt bereits ein\nPoképad?"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_6:
trainerbattlestd 0x0 0x88 0x0 str_0x949b31 str_0x949b9d
loadpointer 0x0 str_0x949b9d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949b31:
    .string "Käferpokémon gibt es sehr viele,\nman kann sie leicht fangen.\pAber ob sie auch im Kampf\nüberzeugen können?"



str_0x949b9d:
    .string "Buhu! Du hast sie alle zerquetscht\nmeine armen Käfer."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_8:
loadpointer 0x0 str_0x949cb9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x949cb9:
    .string "Heil denen, die auf den Wolken\nwandern.\lHeil dem Volk des Himmels."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_10:
loadpointer 0x0 str_0x94c233
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94c233:
    .string "Hast du je vom weißen Albus\ngehört?\pEr war einst Mitglied der Top Vier\nund leitet jetzt die edle\lRevolutionsbewegung.\pEr ist ja so edel, so großmüßtig\nund großherzigDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_11:
loadpointer 0x0 str_0x94c2dd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94c2dd:
    .string "Besitzt du auch eine Detektor?\pIn den Optionen kannst du\neinstellen, ob du benachricht\lwerden willst, wenn du dich in die\lNähe eines versteckten Items\lbegibst."


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_12:
trainerbattlestd 0x0 0x8b 0x0 str_0x94c37e str_0x949d71
loadpointer 0x0 str_0x949d71
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94c37e:
    .string "Hast du schon deine Typentabelle\nauswendig gelernt?\pIch für meinen Teil kenne alle\nTypverhältnisse aus dem Stegreif!"



str_0x949d71:
    .string "Was? Hast du überhaupt gelernt?"


.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_5:
checkflag ROUTE_5_SANFTGLOCKE
gotoif EQUAL ow_script_0x949a37
lock
faceplayer
loadpointer 0x0 str_0x9499a7
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SANFTGLOCKE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x949a41
callstd MSG_FACE
setflag ROUTE_5_SANFTGLOCKE
end


ow_script_0x949a37:
loadpointer 0x0 str_0x949a41
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9499a7:
    .string "Du siehst mir aus wie jemand, der\nsich darum bemüht, ein enges Band\lzu seinen Pokémon aufzubauen.\pNimm dieses Item, es wird dir\ndabei helfen."



str_0x949a41:
    .string "Trägt ein Pokémon die Sanftglocke,\nso wird es zutraulicher."

.elseif LANG_EN

.endif


ow_script_map_3_23_trainer_9:
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


ow_script_movs_0x94c6c7:
.byte SAY_EXCLAM
.byte STOP


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




ow_script_movs_0x94be6d:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x94bc7c:
.byte FACE_DOWN
.byte STOP


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


ow_script_movs_0x94c591:
.byte STEP_IN_PLACE_DOWN_FAST
.byte 0x1c
.byte 0x1c
.byte STEP_DOWN
.byte STOP


ow_script_0x94be70:
sound 0x96
applymovement 0xd ow_script_movs_0x94c591
waitmovement 0x0
return


ow_script_movs_0x94be33:
.byte STEP_DOWN_VERY_SLOW
.byte STOP


ow_script_0x94be24:
sound 0x96
applymovement 0xd ow_script_movs_0x94be33
waitmovement 0x0
return


ow_script_0x94ba17:

loadpointer 0 str_priest
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94ba21
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER

str_priest:
	.string "Wolkenpriester"

str_0x94b8ae:
	.autostring 35 2 "Hallo, junger Trainer!\pIch bin ein Priester der Wolken.\pWir haben eine traditionsreiche Kultur, musst du wissen.\pAußerdem beherrschen wir die Kunst des Wolkenwebens.\pMenschen können auf gewobenen Wolken schweben.\pDOTS DOTS DOTS\pLeider kann ich dir so eine Wolke nicht einfach überlassen.\pNur, wer sich durch Hingabe als würdig erweist, erhält das Privileg, auf einer gewobenen Wolke zu fliegen."


str_0x949ddc:
	.autostring 35 2 "Allerdings DOTS DOTS DOTS\pIch könnte eine Ausnahme machen, vorausgesetzt, du bist bereit, eine Gegenleistung zu erbringen.\pDer Archäologe Professor Tann hat vor einier Zeit ein Artefakt entdeckt, das eigentlich unsere Kultur hätte zugestanden.\pStattdessen aber hat man es in das Orina City Museum gebracht.\pWenn du uns das Wolkenherz aus dem Museum beschaffen kannst, werde ich dir im Gegenzug eine Wolke weben."




str_0x94c615:
	.autostring 35 2 "Oh? Du hast es tatsächlich dabei, das Wolkenherz?\pIch muss mich bei dir bedanken, du hast unserer Kultur einen großen Gefallen erwiesen.\pIch kann dir nun guten Gewissens eine Wolke weben."



str_0x94bc55:
    .string "PLAYER hat eine\ngewobene Wolke erhalten."



str_0x94ba96:
	.autostring 35 2 "Das Wolkenherz ist ein uraltes Relikt, das schon viele Generationen vor uns in Ehren gehalten haben.\pEs gehört den Wolkenmenschen und sollte nicht in einem Museum ausgestellt werden."


str_0x94c596:
    .autostring 35 2 "Du kannst auf einer Wolke wie auf einem Fahrad die Landschaft schneller erkunden."



str_0x94ba21:
    .autostring 35 2 "Wenn du am Boden den Schatten einer tiefliegenden Wolke erkennst, kannst du auf deiner gewobenen Wolke in den Himmel emporsteigen."



str_0x94be36:
    .autostring 35 2 "Wie, was ist das?\pDer Ruf eines Altarias?"



str_0x94bdbf:
    .autostring 35 2 "Ist das ein goldenes Altaria?\pSo etwas habe ich noch nie gesehen!"



str_0x94bd31:
    .autostring 35 2 "Es DOTS DOTS DOTS\nscheint sich bei dir für etwas bedanken zu wollen DOTS"



str_0x94bc7f:
	.autostring 35 2 "Weißt du, warum das Altaria in deiner Schuld steht?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pSo so! Du hast sein Ei beschützt?\pSag das doch gleich!\pJemand, der einem solchen Pokémon selbstlos seine Hilfe geschenkt hat, ist sicherlich würdig, eine gewobene Wolke zu besitzen."



str_0x94bf95:
    .autostring 35 2 "Das Altaria verabschiedet sich von dir.\pEs ist ein wirklich rührender Augenblick!"



str_0x94bb88:
	.autostring 35 2 "Du bist ein wirklich bemerkenswertes Kind.\pDu hast außerordentliches Glück, ein goldenes Altaria mit eigenen Augen zu sehen.\pNicht viele Menschen können das von sich behaupten."


.elseif LANG_EN

.endif