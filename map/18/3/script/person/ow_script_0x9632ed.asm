.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9632ed
ow_script_0x9632ed:
checkflag ROUTE_6_ASH_PRESENT
gotoif EQUAL ow_script_0x963590
checkflag ASHBAG_RECEIVED
gotoif LESS ow_script_0x963483
lock
faceplayer
loadpointer 0x0 str_0x9633f9
callstd MSG_KEEPOPEN
compare ASH 0xc15c
gotoif HIGHER ow_script_0x96334b
fanfare 0x13e
loadpointer 0x0 str_0x96332e
callstd MSG_KEEPOPEN
waitfanfare
setflag ROUTE_6_ASH_PRESENT
addvar ASH 0x1f4
goto ow_script_0x963590


.global ow_script_0x963590
ow_script_0x963590:
loadpointer 0x0 str_0x96359a
callstd MSG_FACE
end


.global ow_script_0x96334b
ow_script_0x96334b:
loadpointer 0x0 str_0x963356
callstd MSG
release
end


.global ow_script_0x963483
ow_script_0x963483:
loadpointer 0x0 str_0x96348d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9633f9

str_0x9633f9:
    .string "Hui! Asche sammeln macht Spaß!\nUnd weißt du, was noch mehr Spaß\lmacht?\pDie gesammelte Asche zu teilen.\nIch werde dir etwas Asche geben!"
        
        
.global str_0x96332e

str_0x96332e:
    .string "PLAYER hat 500 Asche erhalten."
        
        
.global str_0x96359a

str_0x96359a:
    .string "Der nette Mann im Aschhain stellt\nheilsame Flöten aus Asche her.\pDu solltest ihm deine Asche\nbringen."
        
        
.global str_0x963356

str_0x963356:
    .string "Oh! Deine Aschetasche scheint ja\nganz schön voll zu sein!\pAm besten gibst du dem netten Mann\nim Aschhain etwas davon, dann kann\ler dir eine Flöte daraus machen!"
        
        
.global str_0x96348d

str_0x96348d:
    .string "Findest du nicht, dass das Asche\nsammeln Spaß macht?\pAber du scheinst ja gar keine\nAschetasche zu besitzen, wie\lwillst du denn dann Asche sammeln?\pBesuch doch den netten Mann im\nAschhain und seinen Sohn.\lDort wird man dir sicherlich eine\lAschetasche geben."
        
        
.elseif LANG_EN

.endif
