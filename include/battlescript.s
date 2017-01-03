.macro attackstring
.byte 0x2
.endm

.macro ppreduce
.byte 0x3
.endm


.macro pause frames
.byte 0x39
.hword \frames
.endm

.macro printstring id
.byte 0x10
.hword \id
.endm

.macro waitmessage frames
.byte 0x12
.hword \frames
.endm

.macro goto off
.byte 0x28
.word \off
.endm
