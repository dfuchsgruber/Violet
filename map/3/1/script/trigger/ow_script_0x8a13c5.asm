.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8a17e7
ow_script_movs_0x8a17e7:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a17e3
ow_script_movs_0x8a17e3:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1604
ow_script_movs_0x8a1604:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a1603
ow_script_movs_0x8a1603:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a13c5
ow_script_0x8a13c5:
lockall
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
special 0x0
applymovement 0x7f ow_script_movs_0x8a17e7
waitmovement 0x0
loadpointer 0x0 str_0x8a17ec
callstd MSG
sound 0x15
applymovement 0x3 ow_script_movs_0x8a17e3
applymovement 0x4 ow_script_movs_0x8a17e3
waitmovement 0x0
loadpointer 0x0 str_0x8a1608
callstd MSG
applymovement 0x3 ow_script_movs_0x8a1604
applymovement 0x7f ow_script_movs_0x8a1603
waitmovement 0x0
special 0x113
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a15f3
trainerbattlecont 0x1 0x4 0x0 str_0x8a158f str_0x8a15bf ow_script_0x8a1433


.global ow_script_movs_0x8a14a9
ow_script_movs_0x8a14a9:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a1433
ow_script_0x8a1433:
loadpointer 0x0 str_0x8a14b2
callstd MSG
applymovement 0x3 ow_script_movs_0x8a14a9
waitmovement 0x0
hidesprite 0x3
loadpointer 0x0 str_0x8a146b
callstd MSG
applymovement 0x4 ow_script_movs_0x8a14a9
waitmovement 0x0
hidesprite 0x4
goto ow_script_0x8a1af3


.global ow_script_movs_0x8a27a5
ow_script_movs_0x8a27a5:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a1e5c
ow_script_movs_0x8a1e5c:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1cc6
ow_script_movs_0x8a1cc6:
.byte SAY_SMILE
.byte STOP


.global ow_script_movs_0x8a1c28
ow_script_movs_0x8a1c28:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8a1af3
ow_script_0x8a1af3:
showsprite 0x5
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a27ae
applymovement 0x5 ow_script_movs_0x8a27a5
waitmovement 0x0
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2375
callstd MSG
special 0x7
sound 0x15
applymovement 0x5 ow_script_movs_0x8a1e5c
waitmovement 0x0
checksound
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2c1e
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a1cdd
callstd MSG
special 0x7
sound 0x5
applymovement 0x5 ow_script_movs_0x8a1cc6
waitmovement 0x0
checksound
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2c62
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8a1c28
waitmovement 0x0
hidesprite 0x5
setvar STORY_PROGRESS 0xc
releaseall
end


.global ow_script_0x8a2791
ow_script_0x8a2791:
setvar 0x8000 0x1
setvar 0x8001 0x17
setvar 0x8002 0xe
special 0x6
return


.global ow_script_movs_0x8a27ba
ow_script_movs_0x8a27ba:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8a27ae
ow_script_0x8a27ae:
applymovement 0x5 ow_script_movs_0x8a27ba
waitmovement 0x0
return


.global ow_script_movs_0x8a15ff
ow_script_movs_0x8a15ff:
.byte STEP_DOWN
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a15f3
ow_script_0x8a15f3:
applymovement 0x3 ow_script_movs_0x8a15ff
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8a17ec

str_0x8a17ec:
    .string "Wir sollten uns beeilen. Rin\nund die anderen Rüpel werden\llängst in Silvania sein.\pIch habe da eine viel bessere\nIdee!\pLass hören.\pAuf Route 2 soll der\nArcheologe Professor Tann sein\lLabor haben. Denkst du nicht auch,\ldass er uns etwas über den Stein\lwissen könnte?\pJa, das klingt einleuchtend.\nRin wird uns reichlich entlohnen,\lwenn wir ihr die Informationen\lbesorgen, die sie sucht.\pDann ist das beschlossen. Wir\nwerden dem Professor zusetzen und\ldann -"
        
        
.global str_0x8a1608

str_0x8a1608:
    .string "Der Junge da hat uns\nbelauscht!\lJa, genau! Du da, du Knirps!\lWeißt du überhaupt, wer wir sind?\lMitglieder des Team Violet\lnatürlich. Unsere Organisation\lwird schon bald die Herrschaft\lüber diese Region erlangt haben\lund da können wir Rotzlöffel wie\ldich nicht gebrauchen.\lDu solltest ihn erledigen,\lehe er jemanden von unserem\lVorhaben erzählen kann.\lDas werde ich tun, keine\lSorge. Jetzt wirst du erleben, was\les heißt, sich mit Team Violet\lanzulegen!"
        
        
.global str_0x8a158f

str_0x8a158f:
    .string "Fürchte uns! Spüre das Ausmaß\nunserer Stärke!"
        
        
.global str_0x8a15bf

str_0x8a15bf:
    .string "Ein Bengel hat mich geschlagen?\nWie erniedrigend!"
        
        
.global str_0x8a14b2

str_0x8a14b2:
    .string "I... Ich ... du ... wie konnte ich\ngegen einen Grünschnabel wie dich\lverlieren?\l...\lAber das ist ja auch\lnebensächlich. Ich habe einen Plan\lauszuführen.\lDu hast nicht das letzte Mal von\luns gehört, das schwöre ich dir!"
        
        
.global str_0x8a146b

str_0x8a146b:
    .string "Und ich habe keine Zeit, mich mit\nGören zu befassen! Adieu!"
        
        
.global str_0x8f2375

str_0x8f2375:
    .string "Keine schlechte Vorstellung,\nJunge. Du scheinst zwar noch nicht\llange ein Trainer zu sein, doch\lkannst du eine Pokémon mit Eleganz\lführen.\pErlaube mir, mich vorzustellen.\nIch bin Larissa, meines Zeichens\lKünstlerin. Diese Plage namens\lTeam Violet treibt schon seit\lgeraumer Zeit ihr Unwesen in der\lRegion, doch scheinen sie in den\lletzten Wochen aggressiver\lgeworden zu sein.\pDa du nun ohnehin zu ihren Feinden\nzählst, könntest du sicherlich\lhelfen, diese niederträchtigen\lKreaturen in ihre Schranken zu\lweisen."
        
        
.global str_0x8f2c1e

str_0x8f2c1e:
    .string "Hu? Du zögerst? Fehlt es dir an\nMut? Habe ich mich in dir geirrt?"
        
        
.global str_0x8a1cdd

str_0x8a1cdd:
    .string "Den bösen Machenschaften von Team\nViolet muss ich Einhalt gebieten.\lDu kannst auf mich zählen!"
        
        
.global str_0x8f2c62

str_0x8f2c62:
    .string "Ehrenhaft und nobel\ngesprochen, Junge. Die Welt\lbraucht mehr von euch ehrgeizigen\lRittern.\pWohin sind Tugend und Eleganz\nverschwunden? Ich werde sie\lzurückbringen, das versichere ich\ldir.\pWir werden uns wiedersehen, ich\nkann es in deinen Augen lesen."
        
        
.elseif LANG_EN

.endif
