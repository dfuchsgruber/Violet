.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x95f474
ow_script_0x95f474:
lockall
clearflag PKMNMENU
setvar LASTTALKED 0xb
showsprite 0xb
setvar 0x8004 0xb
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x95e7e5
callstd MSG_KEEPOPEN
goto ow_script_0x95e6bd


.global ow_script_0x95e6bd
ow_script_0x95e6bd:
loadpointer 0x0 str_0x95eb33
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95e771
special 0x7
sound 0x15
applymovement 0x800f ow_script_movs_0x8a1cc6
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x95e710
callstd MSG
special 0x7
setvar 0x8004 0xb
setvar 0x8005 0x1d
setvar 0x8006 0x17
special 0x24
waitmovement 0x0
hidesprite 0x800f
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x95e771
ow_script_0x95e771:
loadpointer 0x0 str_0x95e77f
callstd MSG_KEEPOPEN
goto ow_script_0x95e6bd


.ifdef LANG_GER
.global str_0x95e7e5

str_0x95e7e5:
    .string "Willkommen in meiner Welt,\nPLAYER!\pHattest du mich hier nicht\nerwartet?\pDabei bin ich doch selbst in\ndieser Gegend aufgewachsen...\pHabe ich nicht erwähnt, dass ich\naus Inferior stamme?\p... ...\nUnd dass ich Arenaleiterin der\lStadt bin weißt du also auch\lnicht?\pHuch, entschuldige bitte...\nDas bleibt aber unter uns, ja?\lDass ein Arenaleiter sich gegen\ldie Top Vier stellt und insgeheim\ldie Revolution unterstützt...\pNunja...\nDa wären wir auch schon wieder an\ldem Punkt angekommen, an dem ich\ldich um deine Hilfe bitten muss.\pIch kann und möchte mich nicht auf\ndie Top Vier verlassen, das kannst\ldu sicherlich verstehen.\pEin hochrangiges Mitglied des Team\nViolet hat unsere Stadt besetzt.\pIhr Anführer heißt Mistral und ich\nweiß nicht, ob ich alleine mit ihm\lfertig werde.\pAber zusammen - hihi - ähm, werden\nwir ihn sicherlich besiegen\lkönnen."
        
        
.global str_0x95eb33

str_0x95eb33:
    .string "Was sagst du dazu?\nHilfst du mir?"
        
        
.global str_0x95e710

str_0x95e710:
    .string "Ich wusste, dass ich auf dich\nzählen kann, PLAYER.\pWir treffen uns in Inferior,\nwestlich von hier!"
        
        
.global str_0x95e77f

str_0x95e77f:
    .string "Hey! Du kannst mich nicht einfach\nso im Stich lassen, PLAYER!\lWir sind doch - äh - Freunde?\lOder nicht?"
        
        
.elseif LANG_EN

.endif
