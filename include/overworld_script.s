
.macro end
.byte 0x2
.endm

.macro return
.byte 0x3
.endm

.macro callstd num
.byte 0x9
.byte \num
.endm

.macro loadpointer bank pointer
.byte 0xF
.byte \bank
.word \pointer
.endm

.macro special specialid
.byte 0x25
.hword \specialid
.endm

.macro applymovement persid movement
.byte 0x4f
.hword \persid
.word \movement
.endm

.macro waitmovement unkown
.byte 0x51
.hword \unkown
.endm

.macro waitmsg
.byte 0x66
.endm

.macro waitkeypress
.byte 0x6D
.endm
