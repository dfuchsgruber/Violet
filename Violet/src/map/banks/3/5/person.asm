.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_map_3_5_person_39
.global ow_script_map_3_5_person_38
.global ow_script_map_3_5_person_37
.global ow_script_map_3_5_person_16
.global ow_script_0x95a390
.global ow_script_map_3_5_person_34
.global ow_script_map_3_5_person_2
.global ow_script_map_3_5_person_14
.global ow_script_map_3_5_person_11
.global ow_script_map_3_5_person_22
.global ow_script_map_3_5_person_28
.global ow_script_map_3_5_person_8
.global ow_script_map_3_5_trainer_2
.global ow_script_map_3_5_person_7
.global ow_script_map_3_5_person_32
.global ow_script_map_3_5_trainer_1
.global ow_script_map_3_5_person_5
.global ow_script_map_3_5_person_15
.global ow_script_map_3_5_person_25
.global ow_script_0x953cb2
.global ow_script_map_3_5_person_30
.global ow_script_map_3_5_person_3
.global ow_script_map_3_5_person_12
.global ow_script_0x810ebd
.global ow_script_map_3_5_person_35
.global ow_script_map_3_5_person_9
.global ow_script_map_3_5_trainer_0
.global ow_script_map_3_5_person_24
.global ow_script_map_3_5_person_29
.global ow_script_map_3_5_person_18
.global ow_script_map_3_5_person_17
.global ow_script_map_3_5_person_1
.global ow_script_map_3_5_person_4
.global ow_script_0x95a030
.global ow_script_map_3_5_person_6
.global ow_script_map_3_5_person_27
.global ow_script_map_3_5_person_36
.global ow_script_0x95a0f6
.global ow_script_map_3_5_person_19
.global ow_script_map_3_5_person_0
.global ow_script_map_3_5_trainer_3
.global ow_script_map_3_5_person_21
.global ow_script_map_3_5_person_10
.global ow_script_map_3_5_person_23
.global ow_script_map_3_5_person_20
.global ow_script_map_3_5_person_31
.global ow_script_map_3_5_person_26
.global ow_script_map_3_5_person_33
.global ow_script_map_3_5_person_13


ow_script_map_3_5_person_37:
    loadpointer 0 str_37
    callstd MSG_FACE
    end
ow_script_map_3_5_person_38:
    loadpointer 0 str_38
    callstd MSG_FACE
    end
ow_script_map_3_5_person_39:
    loadpointer 0 str_39
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_37:
    .autostring 34 2 "Auf meiner Patroullie entgeht mir keine verdächtige Person.\pEigentlich muss man ja auch nur auf violette oder grüne Kleidung achtenDOTS"
str_38:
    .autostring 34 2 "Bei meiner Arbeit im Kraftwerk sehe ich manchmal ein großes gelbes Vogelpokémon.\pIch frage mich, ob es von der Elektrizität angezogen wird."
str_39:
    .autostring 34 2 "Das Kraftwerk versorgt die ganze Region mit Strom.\pNatürlich bekommt Orina City dabei den größten Teil ab.\pImmerhin ist das hier die größte Stadt Thetos."
.elseif LANG_EN

.endif

ow_script_map_3_5_person_13:
loadpointer 0x0 str_0x94e126
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e126:
    .string "Ich komme oft hierher, um mir die\nFossilien im Museum anzusehen.\lDass Pokémon vor so vielen\lJahrhunderten unsere Welt\lbesiedelt habenDOTS Unglaublich!"


.elseif LANG_EN

.endif


ow_script_0x810ebd:
clearflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
end


ow_script_movs_0x95a473:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_5_trainer_3:

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a476
callstd MSG
special 0xF

sound 0x15
faceplayer
applymovement 0x800f ow_script_movs_0x95a473
waitmovement 0x0
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x95a390
showmoney 0x0 0x0 0x0
loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a1e9
callstd MSG_YES_NO
special 0xF

compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95a0f6
checkmoney 0xc350 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95a030
sound 0x41
paymoney 0xc350 0x0
updatemoney 0x0 0x0 0x0
checksound
fadesong MUS_PIRATE

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959ff5
callstd MSG
special 0xF

hidemoney 0x0 0x0
lockall
copyvar 0x8004 LASTTALKED
npc_move_to LASTTALKED 0x1a 0x2e waitmovement=0
pause 0x30
fadescreen 0x1
waitmovement 0x0

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959fdb
callstd MSG
special 0xF

npc_move_to_player LASTTALKED waitmovement=0
fadescreen 0x0
waitmovement 0x0
faceplayer

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959fa0
callstd MSG_KEEPOPEN
special 0xF
copyvarifnotzero 0x8000 ITEM_WOLKENGARN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959f24
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x800f
setflag ORINA_CITY_WOLKENHERZ_STOLEN
fadesong MUS_AZURIA_CITY_AND_FEUERHOHLE_AND_FUCHSANIA_CITY
fadescreen 0x0
releaseall
end


ow_script_movs_0x95a10d:
.byte LOOK_RIGHT
.byte STOP


ow_script_0x95a030:
hidemoney 0x0 0x0
loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a047
callstd MSG
special 0xF
applymovement 0x800f ow_script_movs_0x95a10d
waitmovement 0x0
end


ow_script_0x95a0f6:
hidemoney 0x0 0x0
loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a110
callstd MSG
special 0xF
applymovement 0x800f ow_script_movs_0x95a10d
waitmovement 0x0
end


ow_script_0x95a390:
loadpointer 0x0 str_0x95a3a2
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
releaseall
end


.ifdef LANG_GER

str_pirate:
	.string "Pirat"

str_0x95a476:
    .string "Soll ich es tunDOTS\nSoll ich es tun?\lWarum sollte ich es tun?"



str_0x95a1e9:
    .string "Hey, ich bin ein Pirat aus\nBlackbeards Crew!\pIch bin gerade im Begriff DOTS\nähDOTS\pIch bin mir absolut sicher, dass\nich dieses Museum ausrauben werde!\pDOTS\nDu siehst aus, wie jemand, der an\leinem Ausstellungsstück Interesse\lhätte.\pWas sagst du dazu, wenn ich dir\ndas Wolkenherz beschaffe, das dort\lausgestellt ist?\pHAAALT! Nicht so hastig!\nMein Preis ist hoch, denn die\lArbeit ist DOTS äh DOTS gefährlich.\lSagen wir, 50.000POKEDOLLAR?"



str_0x959ff5:
    .string "Hehe! So sei es dann! Ich werde\ndir das Ding beschaffen!"



str_0x959fdb:
    .string "DOTS DOTS DOTS\nDOTS DOTS DOTS"



str_0x959fa0:
    .string "Na, du feiger Verbrecher!\nHehe! Ich habe, was du willst."



str_0x959f24:
    .string "Das ist doch ein Geschäft!\pJetzt kann ich zu Kaptain\nBlackbeard voller Stolz\lzurückkehren!\pHehe! Du Landrattfratz!\nAdieu!"



str_0x95a047:
    .string "Oh, du bist ja so pleite wie ein\nGrypheldis!\pHehehe! Ich werde dir das\nWolkenherz sicherlich nicht\lumsonst besorgen.\pLeih dir doch etwas Geld von der\nOrina City Bank! Hehe!"



str_0x95a110:
    .string "Pah! Na gut, dann werde ich eben\nwarten, bis du es dir anders\lüberlegst.\pMir scheint so, als würdest du\ndieses Wolkenherz ziemlich\ldringend gebrauchen können!\pLeih dir doch etwas Geld von der\nOrina City Bank! Hehe!"



str_0x95a3a2:
    .string "Nein, ich kann kein Musem\nausrauben, ohne dafür einen\lwirklichen Grund zu habenDOTS\pWer weiß, ob ich mit der Beute\nüberhaupt Geld verdienen könnte.\pDanke, du hast mir bei dir\nrichtigen Entscheidung geholfen!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_0:
loadpointer 0x0 str_0x94dbda
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94dbda:
    .string "Orina City ist die größte Stadt\nThetos.\pAußerdem ist sie der westlichste\nBereich, der Fauns Kontrolle\lunterliegt."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_1:
loadpointer 0x0 str_0x94dc4d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94dc4d:
    .string "Selbst nach den vielen Jahren, die\nich nun in Orina City lebe, bin\lich von den Hochhausschluchten\lnoch immmer fasziniert."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_2:
loadpointer 0x0 str_0x94dcc8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94dcc8:
    .string "Das Museum von Orina City sollte\nein Punkt auf jeder guten\lSightseeing-Tour sein.\pDie Nachbildungen antiker Pokémon\nsind schlichtweg beeindruckend."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_3:
loadpointer 0x0 str_0x94dd5d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94dd5d:
    .string "Findest du es etwa witzig, dass\nich als emertierte Trainerin\lmeinen Unterhalt mit dem Sammeln\lvon Pfandflaschen machen muss?"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_4:
loadpointer 0x0 str_0x94dddb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94dddb:
    .string "Hast du je vom berüchtigten\nPiraten Blackbeard gehört?\pEr handelt mit gestohlenen Pokémon\nund karpert Handelsschiffe.\pAuf seine Ergreifung wurde eine\nhohe Belohnung ausgesetzt."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_5:
loadpointer 0x0 str_0x94de8d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94de8d:
    .string "Ich halte Ausschau nach\nzwielichten Gestalten!\pWenn ich einen Verbrecher\nergreife, werde ich befördert!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_6:
loadpointer 0x0 str_0x94def6
callstd MSG
end


.ifdef LANG_GER

str_0x94def6:
    .string "Mann: Cecilia, du bist die Wärme\nund das Licht in meinem Leben.\lOhne dich herrscht Winter in\lmeinem Herzen und ich will keine\lSekunde mehr frieren müssen für\lden Rest meines Lebens.\lDOTS\pWillst du meine Frau werden?\pFrau: Oh, das kommt DOTS\nüberraschendDOTS\pMann: Was soll das heißen?"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_7:
loadpointer 0x0 str_0x94e011
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e011:
    .string "Ich bin Teil einer berüchtigten\nMotorrad Gang, den den\lGiratina-Bikern!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_8:
loadpointer 0x0 str_0x94e05a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e05a:
    .string "Im Museum stellen sie eines meiner\nGemälde aus. Es zeigt den großen\lDrachen Rayquaza, den Herrscher\ldes Himmels.\pIch bin so stolz!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_10:
loadpointer 0x0 str_0x94d9e4
callstd MSG
end


.ifdef LANG_GER

str_0x94d9e4:
    .string "Los, Staralili! Ruckzuckhieb!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_9:
loadpointer 0x0 str_0x94e0de
callstd MSG
end


.ifdef LANG_GER

str_0x94e0de:
    .string "Mit deinem Flug-Pokémon hast du\nkeine Chance!\lVoltilamm, Donnerschock!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_11:
cry POKEMON_STARALILI 0x0
loadpointer 0x0 str_0x94da03
callstd MSG
end


.ifdef LANG_GER

str_0x94da03:
    .string "Stara! Staralili! Staaar!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_12:
cry POKEMON_VOLTILAMM 0x0
loadpointer 0x0 str_0x94da65
callstd MSG
end


.ifdef LANG_GER

str_0x94da65:
    .string "Vol! Voltilamm!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_14:
loadpointer 0x0 str_0x94e1bd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e1bd:
    .string "Hast du schon vom Poképad gehört?\nEs soll ein Entwicklungsprojekt\lder Laz.Corp sein und das\lTrainerdasein für immer\lrevolutionieren!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_15:
loadpointer 0x0 str_0x94e243
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e243:
    .string "Die Technologie, die in der\nLaz.Corp entwickelt wird, ist\lihrer Zeit ein halbes Jahrhundert\lvorraus."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_16:
loadpointer 0x0 str_0x94e2b3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e2b3:
    .string "Hast du von Devin, der dunklen\nSeite der Top Vier gehört?\pEr ist ein unnahbares Phantom und\nman sagt ihm nach, auch in den\lRegierungsbezirken der anderen\lDrei kräft mitzumischen."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_17:
loadpointer 0x0 str_0x94e371
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e371:
    .string "Faun setzt sich für die Sauberkeit\nauf den Straßen von Orina City\lein.\pErst durch seine Herrschaft ist\ndieser Ort wirklich schön\lgeworden."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_18:
loadpointer 0x0 str_0x94e407
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e407:
    .string "Das kupferfarbene Gebäude im\nNorden der Stadt ist eine Bank.\pAber wenn du mich fragst, solltest\ndu dir von diesen Leuten kein Geld\lleihenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_19:
loadpointer 0x0 str_0x94e49f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e49f:
    .string "Der Kontrast aus Blumen und Metall\nmacht Orina City zu dem schönen\lOrt, der es ist."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_20:
loadpointer 0x0 str_0x94e4fe
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e4fe:
    .string "Die Schurken, die von den Top Vier\nper Steckbrief gesucht werden,\lsind wahre Ganoven."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_21:
loadpointer 0x0 str_0x94e55f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e55f:
    .string "Gerüchten zufolge wird die\nLaz.Corp ihren giftigen Müll\leinfach durchs Abwasser los.\pIch frage mich, ob da etwas dran\nistDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_22:
loadpointer 0x0 str_0x94e5e7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e5e7:
    .string "Mami! Können wir noch ins Museum\ngehen?"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_23:
loadpointer 0x0 str_0x94e61a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e61a:
    .string "Aber sicher doch! Es wundert mich,\ndass ein Junge in deinem Alter\lüberhaupt Interesse an soetwas\lzeigtDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_24:
loadpointer 0x0 str_0x94e68f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e68f:
    .string "Professor Primus ist der genialste\nKopf des Landes.\pMit seinen Abhandlungen über\ninterstellares Reisen hat er unser\lWeltbild im Bezug auf das All\lentscheidend verändert."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_25:
loadpointer 0x0 str_0x94e744
callstd MSG
end


.ifdef LANG_GER

str_0x94e744:
    .string "Verkatert und pleiteDOTS\nIch fühle mich fast wieder wie ein\lStudentDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_26:
loadpointer 0x0 str_0x94e795
callstd MSG
end


.ifdef LANG_GER

str_0x94e795:
    .string "Steh auf, du versoffener Hund!\nWo warst du nur wieder die ganze\lNacht?"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_27:
loadpointer 0x0 str_0x94e7e7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e7e7:
    .string "Die Orina City Bank ist gerissen.\nNimmst du dir einen Kredit,\lverlangen sie ein Fünftel als\lZinssatz.\pUnd sie kapseln es klammheimlich\nvon deinem gewonnen Preisgeld ab!\lUnverschämtheit!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_28:
loadpointer 0x0 str_0x94e8ac
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e8ac:
    .string "Diese Schweine von Bankiers haben\nmich bis auf letzten POKEDOLLAR\lausgenommen!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_29:
loadpointer 0x0 str_0x94e8fd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e8fd:
    .string "Kennst du die Tochter von\nProfessor Primus?\pSie ist ein wirklich bezauberndes\nMädchenDOTS\pAber ich traue mich nicht, ihr\nmeine Bewunderung zu gestehenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_30:
loadpointer 0x0 str_0x94e9a1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e9a1:
    .string "Ob ich in den Blumenkästen\nKäfer-Pokémon finde?"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_31:
loadpointer 0x0 str_0x94e9dc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x94e9dc:
    .string "Es ist wichtig, einfach einmal\nabzuschalten und den Geist wandern\lzu lassenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_32:
loadpointer 0x0 str_0x953aa8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x953aa8:
    .string "Wenn ich erwachsen bin, werde ich\nmich der Physik widmen, wie\lProfessor Primus.\lEr ist so klug! So toll!\lJa, Professor Primus!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_33:
loadpointer 0x0 str_0x953b28
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x953b28:
    .string "Eigentlich ist es mir verboten,\ndarüber zu sprechen, aber ich bin\lso aufgeregt!\pDie Laz.Corp arbeitet seit langem\nan der Synthese künstlicher\lPokémon und vor einigen Tagen ist\luns endlich der Durchbruch\lgelungen."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_34:
loadpointer 0x0 str_0x953c08
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x953c08:
    .string "Der Architekt dieses Gebäudes\ngehört wahrlich ausgezeichnet.\lUnd das sage ich nicht nur, weil\lich zufällig eben dieser bin!"


.elseif LANG_EN

.endif


ow_script_map_3_5_person_35:
checkflag ORINA_CITY_TM_MATSCHBOMBE
gotoif EQUAL ow_script_0x953cb2
lock
faceplayer
loadpointer 0x0 str_0x9552a7
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM36
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x955217
callstd MSG
setflag ORINA_CITY_TM_MATSCHBOMBE
release
end


ow_script_0x953cb2:
loadpointer 0x0 str_0x9551cc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9552a7:
    .string "Ich bin fertig mit der Laz.Corp.\nProfessor Primus\' Wahn von einem\linterdimensionalen Portal geht\lentschieden zu weit.\lDass er die radioaktiven Abfälle\leinfach so unverfroren entsorgtDOTS\lSo kann ich nicht arbeiten."



str_0x955217:
    .string "Nimm diese Technische Maschine,\nsie ist das Sinnbild für die\lUmweltverschmutzung durch die\lLaz.Corp.\pIch will damit nichts mehr zu tun\nhaben."



str_0x9551cc:
    .string "Matschbombe vergiftet den Gegner,\nwie die Laz.Corp die Umwelt\lvergiftet."


.elseif LANG_EN

.endif


ow_script_map_3_5_person_36:
loadpointer 0x0 str_0x9586a8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9586a8:
    .string "Hey, du Pimpf! Bist du uns etwa\nvon Route 2 bis hierher gefolgt?\pVerschwinde, ehe unser Anführer\nmit dir den Boden aufwischt!"


.elseif LANG_EN

.endif


ow_script_map_3_5_trainer_2:
loadpointer 0x0 str_0x958731
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958731:
    .string "Wir gehören zur zweiten Division\nvon Team Violet.\pUnser Anführer ist noch viel\ngefährlicher als Rin."


.elseif LANG_EN

.endif


ow_script_map_3_5_trainer_1:
loadpointer 0x0 str_0x9587a1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9587a1:
    .string "Hey, verschwinde von hier!\nMistral hat Dinge im Museum zu\lerledigen, die dich nichts\langehen, du Bengel!"


.elseif LANG_EN

.endif


ow_script_map_3_5_trainer_0:
trainerbattlestd 0x0 0x8d 0x0 str_0x958823 str_0x9588a4
loadpointer 0x0 str_0x9588a4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958823:
    .string "Unser Kommandant interessiert sich\nfür ein Artefakt in dem Musem.\pUnd du wirst ihn nicht stören,\nwährend er es sich beschafft!"



str_0x9588a4:
    .string "Nagh! Verdammt!\nAber der wahre Schrecken lauert im\lInneren, mein Junge!"


.elseif LANG_EN

.endif