.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x933e11
ow_script_movs_0x933e11:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x933e0d
ow_script_movs_0x933e0d:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x933c58
ow_script_movs_0x933c58:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x933c5d
ow_script_movs_0x933c5d:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x933ac1
ow_script_0x933ac1:
checkflag KASKADA_BLACKMARKET_PRIMUS
gotoif LESS ow_script_0x933fe1
checkflag KASKADA_BLACKMARKET_BLAISE
gotoif LESS ow_script_0x933fe1
checkflag KASKADA_BLACKMARET_BB_SHIP
gotoif LESS ow_script_0x933fe1
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x933f08
callstd MSG
special 0x7
showsprite 0x1d
showsprite 0x1e
showsprite 0x1f
setflag PKMNMENU
applymovement 0x1d ow_script_movs_0x933e11
applymovement 0x1e ow_script_movs_0x933e11
applymovement 0x1f ow_script_movs_0x933e11
waitmovement 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x933e0d
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x933c60
callstd MSG
special 0x7
applymovement 0x1d ow_script_movs_0x933c58
waitmovement 0x0
applymovement 0xff ow_script_movs_0x933c5d
waitmovement 0x0
goto ow_script_0x935a41


.global ow_script_0x935a41
ow_script_0x935a41:
setflag BLACKOUT_BYPASS
loadpointer 0x0 str_0x933bb4
callstd MSG
trainerbattlelosable 0x9 0x73 0x0 str_0x933c29 str_0x935b22
goto ow_script_0x936ffe


.global ow_script_movs_0x935b64
ow_script_movs_0x935b64:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x935c46
ow_script_movs_0x935c46:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x937090
ow_script_movs_0x937090:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_0x936ffe
ow_script_0x936ffe:
clearflag BLACKOUT_BYPASS
applymovement 0xff ow_script_movs_0x935b64
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x93661f
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x935c46
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x9365b7
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x935b64
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9362bd
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x1d
hidesprite 0x1e
hidesprite 0x1f
fadescreen 0x0
applymovement 0xff ow_script_movs_0x935c46
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x9360fc
callstd MSG
special 0x7
applymovement 0x20 ow_script_movs_0x937090
waitmovement 0x0
hidesprite 0x20
releaseall
end


.global ow_script_0x933fe1
ow_script_0x933fe1:
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x9359bb
callstd MSG
special 0x7
release
end

.global str_0x933f08

str_0x933f08:
    .string "Begreifst du jetzt, was für\nein Ort das ist, PLAYER?\lPiraten, Händler und Schurken\lziehen hier die Fäden, im\lUntergrund.\lIch frage dich ganz offen:\lWie kann jemand ein derartiges\lSystem unterstützen, verteidigen?"
        
        
.global str_0x933c60

str_0x933c60:
    .string "PLAYER und Igva!\nDas hätte ich mir denken können,\ldass ihr einander findet.\pDich hätte ich an einem solchen\nOrt allerdings nicht erwartet,\lPLAYER, zugegeben.\pJetzt, wo du diesen Ort gesehen\nhast, willst du mich da immer noch\lbekämpfen?\p... ...\n... ...\pWie nobel von dir, du bist durch\nund durch Fauns Schüler.\lIch muss mir aber erst ein Bild\lvon deinen Kräften machen.\pWie wäre es, wenn du stattdessen\ngegen ihn hier antrittst?"
        
        
.global str_0x933bb4

str_0x933bb4:
    .string "Lord Albus Ansichten sind der\nSchlüssel zu einer besseren Welt.\pIch werde alles tun, um diese Welt\nherbeizuführen."
        
        
.global str_0x933c29

str_0x933c29:
    .string "Vergebt mir, Lord Albus.\nIch war zu schwach."
        
        
.global str_0x935b22

str_0x935b22:
    .string "Lord Albus, ich habe das Kind\nbesiegt, seid Ihr jetzt zufrieden?"
        
        
.global str_0x93661f

str_0x93661f:
    .string "Oh, keine schlechte\nVorstellung.\pIch sehe nun, was dich für Faun so\ninteressant gemacht hat.\pAber deinem Kampfstil konnte ich\nauch Zweifel aberkennen.\lDeine Überzeugung, für die Top\lVier zu kämpfen, bröckelt, nicht?"
        
        
.global str_0x9365b7

str_0x9365b7:
    .string "PLAYER! Schließe dich\nunserer Sache an!\pLord Albus wird dich unterweisen,\ndu wirst Großes bewirken!"
        
        
.global str_0x9362bd

str_0x9362bd:
    .string "Überstürze nichts, Igva.\pSiehst du nicht, dass der Junge im\nBegriff ist, seine Welt zu\lhinterfragen?\pDachtest du, dass diese Welt\nperfekt ist? Dass das alles hier\lbloß ein dummer Film oder ein\lSpiel ist?\pMenschen sind selbstsüchtig, und\nwenn man nicht im Laufe der\lJahrhunderte wieder und wieder\lgegen diese Selbstsucht\lrebelliert, wird Leid die Oberhand\lgewinnen.\pIch will dich nicht länger\nbelehren, du sollst aus freien\lStücken zu deinen Handlungen\lkommen.\pBedenke aber, dass du hinter\nallem, was du tust, stehen musst.\lSei dir jeder Konsequenz bewusst.\p...\pVielleicht kann ich dich eines\nTages in meinen Reihen begrüßen.\pVielleicht stehen wir uns auf dem\nletzten Schlachtfeld gegenüber.\pWer weiß, was die Zeit bringt?\pViel Glück bei deinem Weg,\nPLAYER."
        
        
.global str_0x9360fc

str_0x9360fc:
    .string "PLAYER...\pLord Albus ist ein guter Mensch.\nUnd das bist du auch.\p...\pDu hättest ihn nicht besiegen\nkönnen, völlig ausgeschlossen.\pIch werde seinen Worten Folge\nleisten und dich ziehen lassen.\pNur einen Tipp will ich dir geben:\nWenn du mehr von der Schattenseite\lThetos sehen möchtest, solltest du\lManus, den Arenaleiter von Meriana\lCity herausfordern.\pDu erreichst den Ort sehr schnell\nüber den Wasserpfad, südlich von\lKaskada.\pAuf Wiedersehen!"
        
        
.global str_0x9359bb

str_0x9359bb:
    .string "PLAYER, du solltest dich hier\netwas umsehen.\pDieser Ort ist der dunkle Spiegel\nunserer Gesellschaft.\pEntreiße der Welt ihre Maske!"
        
        