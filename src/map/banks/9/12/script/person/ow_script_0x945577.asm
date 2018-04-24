.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x945577
ow_script_0x945577:
lock
faceplayer
loadpointer 0x0 str_0x945f3c
callstd MSG_KEEPOPEN
call ow_script_0x945619
gotoif EQUAL ow_script_0x9460a5
closeonkeypress
release
end


.global ow_script_0x9460a5
ow_script_0x9460a5:
applymovement 0x800f ow_script_movs_0x8f511a
waitmovement 0x0
lock
faceplayer
loadpointer 0x0 str_0x946118
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x94610c
loadpointer 0x0 str_0x9461a3
callstd MSG
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8005 0x7
call ow_script_0x1c9086
clearflag TRANS_DISABLE
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x94610c
call ow_script_0x9455aa
loadpointer 0x0 str_0x94618b
callstd MSG
end


.global ow_script_0x94610c
ow_script_0x94610c:
loadpointer 0x0 str_0x9461dd
callstd MSG_KEEPOPEN
closeonkeypress
release
end


.ifdef LANG_GER
.global str_0x945f3c

str_0x945f3c:
    .string "Ich bin ein Forscher der Laz.Corp\nund fasziniert von der\lBeschaffenheit des Lichts.\pDie Lichtkanone ist der Angriff\nmeiner Wahl!\pAber ich bin auch sein Sammler.\nWenn du mir entweder 3 Minipilze\loder einen Riesenpilz bringst,\lkann ich im Gegenzug dafür einem\ldeiner Pokémon Lichtkanone\lbeibringen."
        
        
.global str_0x946118

str_0x946118:
    .string "Vorzüglich!\nDu hast BUFFER_1-mal\lBUFFER_1 dabei!\pSoll ich nun einem deiner Pokémon\ndie Lichtkanone beibringen?"
        
        
.global str_0x9461a3

str_0x9461a3:
    .string "Welchem deiner Pokémon soll ich\nLichtkanone beibringen?"
        
        
.global str_0x9461dd

str_0x9461dd:
    .string "Wie unverhofft!\nSolltest du deine Einstellung\ländern und meine Faszination für\lLicht teilen, weißt du ja, wo du\lmich findest!"
        
        
.elseif LANG_EN

.endif
