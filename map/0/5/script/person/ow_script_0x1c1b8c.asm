.include "overworld_script.s"

.include "std.s"

.global ow_script_0x1c1b8c
ow_script_0x1c1b8c:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
lockall
checkflag FRBADGE_4
gotoif LESS ow_script_0x1c1bf4
checkflag STRENGTH_USED
gotoif EQUAL ow_script_0x1c1bfd
checkattack ATTACK_STAERKE
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x1c1bf4
setanimation 0x0 0x800d
loadpointer 0x0 str_0x1c1c09
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c1c06
closeonkeypress
doanimation 0x28
nop
waitstate
goto ow_script_0x1c1be8


.global ow_script_0x1c1be8
ow_script_0x1c1be8:
setflag STRENGTH_USED
loadpointer 0x0 str_0x1c1c5a
callstd MSG_SIGN
end


.global ow_script_0x1c1c06
ow_script_0x1c1c06:
closeonkeypress
releaseall
end


.global ow_script_0x1c1bf4
ow_script_0x1c1bf4:
loadpointer 0x0 str_0x1c1ca3
callstd MSG_SIGN
end


.global ow_script_0x1c1bfd
ow_script_0x1c1bfd:
loadpointer 0x0 str_0x1c1cd6
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x1c1c09

str_0x1c1c09:
    .string "Ein Pokémon kann diesen Felsen\nvielleicht bewegen.\pMöchtest du STÄRKE einsetzen?"
        
        
.global str_0x1c1c5a

str_0x1c1c5a:
    .string "BUFFER_1 setzt STÄRKE ein.\pSTÄRKE von BUFFER_1 ermöglicht\nes, den Felsen zu bewegen."
        
        
.global str_0x1c1ca3

str_0x1c1ca3:
    .string "Ein Pokémon kann diesen Felsen\nvielleicht bewegen."
        
        
.global str_0x1c1cd6

str_0x1c1cd6:
    .string "STÄRKE ermöglicht es, Felsen zu\nbewegen."
        
        
.elseif LANG_EN

.endif
