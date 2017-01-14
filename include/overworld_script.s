
.macro end
.byte 0x2
.endm

.macro return
.byte 0x3
.endm

.macro call label
.byte 0x4
.word \label
.endm

.macro goto label
.byte 0x5
.word \label
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

.macro special2 var specialid
.byte 0x26
.hword \var
.hword \specialid
.endm

.macro waitstate
.byte 0x27
.endm

.macro pause frames
.byte 0x28
.hword \frames
.endm

.macro setflag flag
.byte 0x29
.hword \flag
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

.macro fanfare id
.byte 0x31
.hword \id
.endm

.macro playsong id mode
.byte 0x33
.hword \id
.byte \mode
.endm

.macro getplayerpos x y
.byte 0x42
.hword \x
.hword \y
.endm

.macro additem item cnt
.byte 0x44
.hword \item
.hword \cnt
.endm

.macro removeitem item cnt
.byte 0x45
.hword \item
.hword \cnt
.endm

.macro checkitem item cnt
.byte 0x47
.hword \item
.hword \cnt
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

.macro spriteface owid dir
.byte 0x5B
.hword \owid
.byte \dir
.endm

.macro waitmsg
.byte 0x66
.endm

.macro closeonkeypress
.byte 0x68
.endm

.macro lockall
.byte 0x69
.endm

.macro releaseall
.byte 0x6B
.endm

.macro waitkeypress
.byte 0x6D
.endm

.macro bufferitem buf item
.byte 0x80
.byte \buf
.hword \item
.endm

.macro buffernumber buf var
.byte 0x83
.byte \buf
.hword \var
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

