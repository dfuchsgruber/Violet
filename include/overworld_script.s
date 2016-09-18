
.macro end
.byte 0x2
.endm

.macro return
.byte 0x3
.endm

.macro gotoif cond label
.byte 0x6
.byte \cond
.word \label
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

.macro setvar var value
.byte 0x16
.hword \var
.hword \value
.endm

.macro addvar var value
.byte 0x17
.hword \var
.hword \value
.endm

.macro copyvar dest src
.byte 0x19
.hword \dest
.hword \src
.endm

.macro compare var value
.byte 0x21
.hword \var
.hword \value
.endm

.macro special specialid
.byte 0x25
.hword \specialid
.endm

.macro pause frames
.byte 0x28
.hword \frames
.endm

.macro clearflag flag
.byte 0x2A
.hword \flag
.endm

.macro checkflag flag
.byte 0x2B
.hword \flag
.endm

.macro sound id
.byte 0x2F
.hword \id
.endm

.macro checksound
.byte 0x30
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

.macro hidesprite pers
.byte 0x53
.hword \pers
.endm

.macro showsprite pers
.byte 0x55
.hword \pers
.endm

.macro faceplayer
.byte 0x5A
.endm

.macro waitmsg
.byte 0x66
.endm

.macro lockall
.byte 0x69
.endm

.macro waitkeypress
.byte 0x6D
.endm

.macro random mod
.byte 0x8F
.hword \mod
.endm

.macro fadescreen effect
.byte 0x97
.byte \effect
.endm

.macro cry id effect
.byte 0xA1
.hword \id
.hword \effect
.endm

.macro dowildbattle
.byte 0xB7
.endm

.macro waitcry
.byte 0xC5
.endm

.macro singlemovement persid movement
.byte 0xD5
.hword \persid
.hword \movement
.endm
