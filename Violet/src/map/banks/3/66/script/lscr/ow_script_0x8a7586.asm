.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x8a820e
ow_script_movs_0x8a820e:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a8214
ow_script_movs_0x8a8214:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x80358f
ow_script_movs_0x80358f:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a7f34
ow_script_movs_0x8a7f34:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a7f2b
ow_script_movs_0x8a7f2b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a794f
ow_script_movs_0x8a794f:
.byte SAY_QUESTION
.byte STOP


.global ow_script_movs_0x8a792d
ow_script_movs_0x8a792d:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a78ed
ow_script_movs_0x8a78ed:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8a7586
ow_script_0x8a7586:
applymovement 0x3 ow_script_movs_0x8a820e
applymovement 0xff ow_script_movs_0x8a8214
waitmovement 0x0
loadpointer 0x0 str_0x8a7f97
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
sound 0x15
applymovement 0x2 ow_script_movs_0x80358f
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7f3d
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x8a7f34
waitmovement 0x0
sound 0x7
checksound
applymovement 0x2 ow_script_movs_0x8a7f2b
waitmovement 0x0
loadpointer 0x0 str_0x8a7e8d
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a7dbf
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
sound 0x15
applymovement 0xff ow_script_movs_0x8a794f
applymovement 0x3 ow_script_movs_0x8a794f
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7930
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8a792d
waitmovement 0x0
loadpointer 0x0 str_0x8a78f1
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7830
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8037d2
waitmovement 0x0
loadpointer 0x0 str_0x8a77ae
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a7789
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a776a
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
goto ow_script_0x8a934f


.global ow_script_movs_0x8a7761
ow_script_movs_0x8a7761:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_IN_PLACE_LEFT
.byte STEP_IN_PLACE_LEFT
.byte STOP


.global ow_script_movs_0x8a76e4
ow_script_movs_0x8a76e4:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a774a
ow_script_movs_0x8a774a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x803489
ow_script_movs_0x803489:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8aa36d
ow_script_movs_0x8aa36d:
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x8aa1b5
ow_script_movs_0x8aa1b5:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8aa181
ow_script_movs_0x8aa181:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a9a49
ow_script_movs_0x8a9a49:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a934f
ow_script_0x8a934f:
fanfare 0x13e
loadpointer 0x0 str_0x8aa319
callstd MSG_KEEPOPEN
setflag POKEDEX
closeonkeypress
waitfanfare
applymovement 0x2 ow_script_movs_0x8a7761
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8a76e4
waitmovement 0x0
loadpointer 0x0 str_0x8a7751
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x8a774a
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x803489
waitmovement 0x0
loadpointer 0x0 str_0x8a76ee
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aabee
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
nop
nop
loadpointer 0x0 str_0x8aa57d
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aa381
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
loadpointer 0x0 str_0x8aa372
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
fanfare 0x13e
applymovement 0x2 ow_script_movs_0x8aa36d
loadpointer 0x0 str_0x8aa338
callstd MSG_KEEPOPEN
waitmovement 0x0
waitfanfare
loadpointer 0x0 str_0x8aa305
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8aa27f
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aa22a
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8aa1b8
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8aa1b5
waitmovement 0x0
loadpointer 0x0 str_0x8aa184
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8aa181
waitmovement 0x0
loadpointer 0x0 str_0x8a9f82
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
sound 0x7
checksound
loadpointer 0x0 str_0x8a9c83
callstd MSG
applymovement 0x2 ow_script_movs_0x8aa36d
call ow_script_0x8ab100
waitmovement 0x0
loadpointer 0x0 str_0x8a9a4c
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x8a9a49
waitmovement 0x0
loadpointer 0x0 str_0x8a99f1
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a9950
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
goto ow_script_0x8a9640


.global ow_script_movs_0x8ab040
ow_script_movs_0x8ab040:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8aafce
ow_script_movs_0x8aafce:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8aac32
ow_script_0x8aac32:
loadpointer 0x0 str_0x8ab043
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x8ab040
waitmovement 0x0
loadpointer 0x0 str_0x8aafd4
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT

applymovement 1 ow_script_movs_0x8aa1b5
waitmovement 0
loadpointer 0 str_tann_end
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 2 ow_script_movs_0x8a9a49
waitmovement 0
loadpointer 0x0 str_elise_end
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
applymovement 1 ow_script_movs_0x8ab040
applymovement 2 ow_script_movs_0x8ab040
waitmovement 0

loadpointer 0x0 str_elise_end2
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT


applymovement 0x2 ow_script_movs_0x8aafce
waitmovement 0x0
goto ow_script_0x8ad21f


.global ow_script_0x8ad21f
ow_script_0x8ad21f:
setflag ROUTE_2_RIVAL_INSIDE_LAB
setvar STORY_PROGRESS 0xf
end


.global ow_script_0x8a9640
ow_script_0x8a9640:
goto ow_script_0x8aac32


.global ow_script_0x8ab100
ow_script_0x8ab100:
fanfare 0x13e
additem ITEM_POKEBALL 0x5
loadpointer 0x0 str_0x8ad201
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
return


.global ow_script_movs_0x8037d2
ow_script_movs_0x8037d2:
.byte FACE_DOWN
.byte STOP


.ifdef LANG_GER
.global str_0x8a7f97

str_0x8a7f97:
	.autostring 34 2 "PLAYER und mein eigener Sohn!\pZwei frisch gebackene Trainer!\pUnd schon stark genug, diesen alten Herren aus einer misslichen Lage zu befreien.\pDiese Team Violet Rüpel werden zu einem echten Problem in Theto.\pIn letzter Zeit gehen sie immer agressiver gegen die Bürger vor.\pUnd was dieser Wirbel um einen Zeitstein bedeuten soll, kann ich mir auch nicht recht erklären.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWie dem auch sei.\nDa ihr nun endlich die Trainerschule und den alten Faun hinter euch gelassen habt, will ich euch auf dem Weg, den ihr nun bestreitet, unterstützen.\pElise, würdest du bitteDOTS"
.global str_0x8a7f3d

str_0x8a7f3d:
    .autostring 34 2 "Natürlich, Professor Tann.\pIch bin schon unterwegsDOTS"
        
        
.global str_0x8a7e8d

str_0x8a7e8d:
	.autostring 34 2 "Darf ich vorstellen?\nMeine Assistentin Elise.\pSie ist die Tochte eines befreundeten Professors und selbst ein wahres Forschungass.\pSie forscht in der Laz.Corp an der Virtualisierung von Pokémon-Daten.\pScheinbar sind dazu auch die Ergebnisse meiner Forschung relevant.\pDOTS DOTS DOTS"
        
.global str_0x8a7dbf

str_0x8a7dbf:
	.autostring 34 2 "Freut mich außerordentlich!\pIch sammle allerlei Daten, um auch Pokémon auch in die virtuelle Welt zu bringen!\pDamit trage ich maßgeblich zur Entwicklung des Poképads bei!"
        
        
.global str_0x8a7930

str_0x8a7930:
    .autostring 34 2 "Ihr kennt das Poképad nicht?"
        
        
.global str_0x8a78f1

str_0x8a78f1:
    .autostring 34 2 "Ist es denn überhaupt schon im Laden erhältlich?"
        
        
.global str_0x8a7830

str_0x8a7830:
	.autostring 34 2 "Oh, natürlich!\nIch Dummerchen!\pDas Poképad ist ein Höhepunkt unserer modernen Technologie.\pEin Muss für jeden Trainer!\pMit einer Vielzahl an nützlichen Apps wird eine Trainerlaufbahn ohne dieses Gerät in naher Zukunft gar nicht mehr vorzustellen sein!"

.global str_0x8a77ae

str_0x8a77ae:
    .autostring 34 2 "Ganz richtig!\nEin beeindruckendes Ding!\pUnd als Starthilfe will ich euch beiden jeweils eines dieser Geräte schenken."
        
        
.global str_0x8a7789

str_0x8a7789:
    .autostring 34 2 "Wirklich? Fantastisch, Papi!\nJuhu!"
        
        
.global str_0x8a776a

str_0x8a776a:
    .autostring 34 2 "Vielen Dank, Professor Tann."
        
        
.global str_0x8aa319

str_0x8aa319:
    .autostring 34 2 "PLAYER hat das Poképad erhalten!"
        
        
.global str_0x8a7751

str_0x8a7751:
    .autostring 34 2 "Danke, Elise!"
        
        
.global str_0x8a76ee

str_0x8a76ee:
    .autostring 34 2 "Das ganze ist allerdings mit einer Bitte verbunden."
        
        
.global str_0x8aabee

str_0x8aabee:
    .autostring 34 2 "Och, du bist ein immer so ein Spielverderber, Papi!"
        
        
.global str_0x8aa57d

str_0x8aa57d:
    .autostring 34 2 "Habe ich mich da verhört?\pDein Vater schenkt dir ein exklusives Gadget, da könntest du ruhig etwas dankbarer sein!"
        
        
.global str_0x8aa381

str_0x8aa381:
	.autostring 34 2 "Haha!\pMein Sohn kann solche Dinge nicht immer wirklich gut zum Ausdruck bringen.\pGanz genauso, wie es bei mir der Fall ist.\pAber keine Sorge, meine Bitte ist mit einer Menge an Spaß verbunden!\pEs geht darum, dass ihr Elise helfen sollt, Daten über allerlei Arten von Pokémon zu sammeln.\pDie dafür entwickelte Pokédex-App speichert Informationen zu allen Pokémon, die ihr eingefangen habt.\pWenn euch also eine Spezies begegnet, die ihr interessant findet, dann zögert nicht, sie einzufangen!"

        
.global str_0x8aa372

str_0x8aa372:
    .autostring 34 2 "Geht in Ordnung, Papi!"
        
        
.global str_0x8aa338

str_0x8aa338:
    .autostring 34 2 "Die Pokedex-App wurde auf dem Poképad installiert!"
        
        
.global str_0x8aa305

str_0x8aa305:
    .autostring 34 2 "Dankesehr, Elise."
        
        
.global str_0x8aa27f

str_0x8aa27f:
	.autostring 34 2 "Sehr schön!\pIch wusste, dass ich mich auf euch verlassen kann.\pIch nehme an, ihr beiden habt in der Trainerschule gelernt, wie man Pokémon fängt?"
        
.global str_0x8aa22a

str_0x8aa22a:
    .autostring 34 2 "Natürlich Papi!\pHerr Faun hat uns alles beigebracht, was ein Trainer wissen muss!"
        
        
.global str_0x8aa1b8

str_0x8aa1b8:
    .autostring 34 2 "Euer Lehrer war der große Faun, der in der VergangenheitDOTS"
        
        
.global str_0x8aa184

str_0x8aa184:
    .autostring 34 2 "Haha!\nKennst du etwa noch einen anderen Faun, Elise?"
        
        
.global str_0x8a9f82

str_0x8a9f82:
	.autostring 34 2 "Ihr müsst wissen, dass Faun eine wahre Trainerlegende gewesen ist.\pAber irgendwann im Leben kommt wohl einmal der Punkt, an dem man erkennt, dass es mehr gibt, als bloß Ruhm und Ansehen.\pDeswegen bildet er nun selbst eine neue Generation von Trainern aus.\pUnd ihr habt als seine Schützlinge sicherlich die besten Voraussetzungen zu einer erfolgreichen Trainerkarriere.\pUnd womit könnte man die besser starten, als ein paar Pokémon einzufangen?\pNatürlich benötigt ihr dafür Pokébälle, von denen ich euch freundlicherweise ein paar schenken will."
        
.global str_0x8a9c83

str_0x8a9c83:
    .autostring 34 2 "RIVAL hat 5 Pokebälle erhalten!"
        
        
.global str_0x8a9a4c

str_0x8a9a4c:
    .autostring 34 2 "Hach!\nDa wird man ganz sentimental, wenn man euch beide so ansieht."
        
        
.global str_0x8a99f1

str_0x8a99f1:
    .autostring 34 2 "Als Schüler von Faun wird man von euch viel erwarten!"
        
        
.global str_0x8a9950

str_0x8a9950:
    .autostring 34 2 "Das kommt mir gerade recht!\pImmerhin werde ich der größte Trainer aller Zeiten werden!"

        
str_0x8ad201:
    .autostring 34 2 "PLAYER hat fünf\nPokébälle erhalten!"
        
.global str_0x8ab043

str_0x8ab043:
    .autostring 34 2 "Es ist gut, große Träume zu haben!\pNur so kann man über sich hinauswachsen."
        
.global str_0x8aafd4

str_0x8aafd4:
	.autostring 34 2 "RIVAL kommt wirklich ganz nach seinem Vater.\pProfessor Tanns Ziel ist es, die sagenumwobene versunkene Stadt Atlantea zu finden.\pJeder Archäologe träumt davon, aber die meisten sind sich darin einig, dass dieser Ort nicht einmal existiertDOTS"

str_tann_end:
    .autostring 34 2 "Unsinn, Elise!\pNur wenn man fest daran glaubt, dass die eigenen Ziele auch verwirklicht werden können, erreicht man Großes!\pUnd deshalb werde ich mich bald auf eine Expedition begeben."

str_elise_end:
    .autostring 34 2 "Was soll man sagen, der Apfel fällt nicht weit vom StammDOTS"
str_elise_end2:
    .autostring 34 2 "Wie dem auch sei, wünsche auch ich euch beiden viel Erfolg auf eurer Reise.\pDas Trainerdasein ist nicht immer leicht, aber ich bin überzeugt, dass ihr das Zeug dazu habt!"    
        
.elseif LANG_EN

.endif
