.include "flags.s"
.include "songs.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x95ef61
ow_script_0x95ef61:
lockall
clearflag PKMNMENU
showsprite 0x3
setflag PKMNMENU
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
setvar 0x8004 0x3
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x89ba6e
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x95efaa
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x95efbe
trainerbattlecont 0x1 0x14e 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.global ow_script_0x95f001
ow_script_0x95f001:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x95f255
callstd MSG_KEEPOPEN
special 0x7
copyvarifnotzero 0x8000 ITEM_VM03
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x89ba6e
loadpointer 0x0 str_0x95f051
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x3
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x95efbe
ow_script_0x95efbe:
trainerbattlecont 0x1 0x14d 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.global ow_script_0x95efaa
ow_script_0x95efaa:
trainerbattlecont 0x1 0x14c 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.ifdef LANG_GER
.global str_0x95f326

str_0x95f326:
    .string "PLAYER!\nLange nicht gesehen, du altes\lBumelz!\p... Bist du etwa auf dem Weg nach\nInferior, um dir einen Orden zu\lergattern?\pDa bin ich dir wohl schon zuvor\ngekommen.\pMeine Pokémon haben Igva in Grund\nund Boden gestampft!\pUnd jetzt werden wir das gleiche\nmit dir tun! "
        
        
.global str_0x95efd2

str_0x95efd2:
    .string "Unmöglich!\nWieso besiegst du mich jedes Mal?"
        
        
.global str_0x95f255

str_0x95f255:
    .string "Nicht schlecht!\nHmm... Aber ich habe natürlich\lauch nicht alles gegeben.\pIch habe dich gewinnen lassen, ja\nso ist das tatsächlich.\pDu brauchst auf jeden Fall ein\nwenig Unterstützung im Kampf gegen\lIgva."
        
        
.global str_0x95f051

str_0x95f051:
    .string "Diese Versteckte Maschine enthält\nSurfer, einen mächtigen\lWasserangriff.\pIch gebe ihn dir, damit du eine\nChance hast, Igva zu besiegen,\lnicht, weil ich nett sein will...\pDu bist mein Erzrivale, ja?\nIch helfe meinen Gegner nicht...\pWie auch immer...\nUm Surfer auch außerhalb des\lKampfes benutzen zu können und\ldamit über die Ozeane zu gleiten,\lmusst du zuerst den Hitzeorden\lerrungen haben.\pViel Glück, und beim nächsten Mal\nwerde ich siegen - äh ...\pIch meine, beim nächsten Mal werde\nich mich nicht zurückhalten!"
        
        
.elseif LANG_EN

.endif
