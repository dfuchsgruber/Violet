.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8dcf8a
ow_script_movs_0x8dcf8a:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8dcf31
ow_script_movs_0x8dcf31:
.byte STEP_UP
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8dcf2e
ow_script_movs_0x8dcf2e:
.byte STEP_UP
.byte STOP


.global ow_script_0x8dce86
ow_script_0x8dce86:
lockall
loadpointer 0x0 str_0x8dcf8d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8de230
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x28 ow_script_movs_0x8dcf8a
waitmovement 0x0
loadpointer 0x0 str_0x8dcf36
callstd MSG_KEEPOPEN
applymovement 0x28 ow_script_movs_0x8dcf31
waitmovement 0x0
setdooropened 0x2e 0x14
doorchange
applymovement 0x28 ow_script_movs_0x8dcf2e
waitmovement 0x0
hidesprite 0x28
setdoorclosed 0x2e 0x14
doorchange
loadpointer 0x0 str_0x8dcee9
callstd MSG
fadescreen 0x1
hidesprite 0x27
clearflag MERIANA_CITY_DUDE
fadescreen 0x0
addvar MERIANA_CITY_REVOLUTIONARY 0x1
releaseall
end


.ifdef LANG_GER
.global str_0x8dcf8d

str_0x8dcf8d:
    .string "Mann: Damit kommen Sie nicht\ndurch. Wenn die Top Vier davon\lerfahren, werden Sie dafür büßen."
        
        
.global str_0x8de230

str_0x8de230:
    .string "Polizist: Ha! Ich weiß nicht,\nwovon Sie reden. Sie unterstellen\lder Polizei ungeheuerliche Dinge!\lIch könnte Sie inhaftieren wegen\lsolcher Anschuldigungen..."
        
        
.global str_0x8dcf36

str_0x8dcf36:
    .string "Mann: Was fällt Ihnen ein?\nKorruptes Gesindel... Schon gut,\lich gehe, ich gehe..."
        
        
.global str_0x8dcee9

str_0x8dcee9:
    .string "Polizist: Verdammter Bengel! ...\nIch sollte mich darum kümmern ..."
        
        
.elseif LANG_EN

.endif
