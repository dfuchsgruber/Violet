.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x93be3f
ow_script_movs_0x93be3f:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x93bf7b
ow_script_movs_0x93bf7b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x93bf53
ow_script_movs_0x93bf53:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x93be44
ow_script_movs_0x93be44:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x93be49
ow_script_movs_0x93be49:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x93bd44
ow_script_0x93bd44:
lockall
special 0x113
applymovement 0x7f ow_script_movs_0x93be3f
waitmovement 0x0
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c76b
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c7d3
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c80f
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c62b
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c56c
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c4d7
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93c41a
callstd MSG
special 0x7
loadpointer 0x0 str_0x93c1f6
callstd MSG
call ow_script_0x8a2791
loadpointer 0x0 str_0x93bf80
callstd MSG
special 0x7
applymovement 0x17 ow_script_movs_0x93bf7b
waitmovement 0x0
sound 0x9
checksound
hidesprite 0x17
loadpointer 0x0 str_0x93bf57
callstd MSG
sound 0x15
applymovement 0x16 ow_script_movs_0x93bf53
waitmovement 0x0
loadpointer 0x0 str_0x93bf25
callstd MSG
applymovement 0x7f ow_script_movs_0x93be44
waitmovement 0x0
special 0x114
setvar 0x8004 0x16
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x93be4c
callstd MSG
setvar 0x8004 0x16
setvar 0x8005 0x18
setvar 0x8006 0x4b
special 0x24
waitmovement 0x0
applymovement 0x16 ow_script_movs_0x93be49
waitmovement 0x0
sound 0x9
hidesprite 0x16
checksound
addvar STORY_PROGRESS 0x1
releaseall
end

.global str_0x93c76b

str_0x93c76b:
    .string "Hab dich hier also\nendlich gefunden, Manus.\lDu bist der Arenaleiter von\lMeriana City, nicht?"
        
        
.global str_0x93c7d3

str_0x93c7d3:
    .string "Manus: Ganz recht, der bin ich.\nUnd wer bist du, Mädchen?"
        
        
.global str_0x93c80f

str_0x93c80f:
    .string "Oh, ich bin niemand\nbesonderes, bloß eine Künstlerin.\lMein Name ist Larissa.\pIch habe mir geschworen, Tugend\nund Ritterlichkeit zurück in die\lWelt zu bringen."
        
        
.global str_0x93c62b

str_0x93c62b:
    .string "Viel Glück dabei, Kind.\nFalls du es nicht bemerkt hast,\lmit Theto geht es bergab.\pSeit Lucius, der Champion\ngeschlagen wurde, tobt das Chaos.\lTeam Violet, eine Revolution...\pVersuch doch in einer anderen Welt\netwas zu bewirken, Mädchen.\lHier verschwendest du nur deine\lZeit, würde ich sagen."
        
        
.global str_0x93c56c

str_0x93c56c:
    .string "Nur sagt man dir nach,\nselbst eine der Ursachen für den\lZustand des Kontinents zu sein.\pIst es nicht so, dass auch du von\neinem ominösen Schwarzmarkthandel\lin Kaskada profitierst?"
        
        
.global str_0x93c4d7

str_0x93c4d7:
    .string "Was fällt dir ein?\pWeißt du eigentlich, dass du hier\nmit einem Arenaleiter sprichst?\pIch könnte dich an Ort und Stelle\nvernichten, du Göre!"
        
        
.global str_0x93c41a

str_0x93c41a:
    .string "Ich interpretiere das als\nGeständnis.\lWie mir scheint, muss einiges\lgetan werden.\lDie Korruption und Unehrlichkeit\lsind tief in die Regierung Thetos\lverstrickt, wie mir scheint."
        
        
.global str_0x93c1f6

str_0x93c1f6:
    .string "So etwas Lächerliches!\nFang\ doch am besten damit an, den\lneuen Champion zu finden.\lNachdem Lucius geschlagen und\lvertrieben wurde, hat sich das\lBalg aus dem Staub gemacht und\lTheto allein gelassen.\pNicht einmal wir Arenaleiter\nwissen, wer es überhaupt ist!\lVielleicht kann dir der Champion\lja bei deinen aberwitzigen Plänen\lhelfen.\pOder du machst bei dieser\nhirnrissigen Revolution mit.\lSchließt dich dem Verräter Albus\lan. Früher ein Top Vier Mitglied\lund jetzt will er alles bekämpfen,\lwofür er gelebt hat.\lScher\ dich doch zum Teufel!"
        
        
.global str_0x93bf80

str_0x93bf80:
    .string "... ... ...\nIch kann deinen Zorn verstehen...\lAber glaubst du nicht...\lNein...\lDu wirst noch von mir hören,\lManus."
        
        
.global str_0x93bf57

str_0x93bf57:
    .string "... ... ...\nDiese Göre ..."
        
        
.global str_0x93bf25

str_0x93bf25:
    .string "Hast du uns etwa belauscht,\nBursche?"
        
        
.global str_0x93be4c

str_0x93be4c:
    .string "Ho! Dein Gesichtsausdruck!\nDu scheinst aus einem harten Holz\lgeschnizt zu sein!\lKomm doch in meine Arena in\lMeriana City und fordere mich\lheraus!\lIch sehne mich seit langem nach\leiner echten Herausforderung."
        
        