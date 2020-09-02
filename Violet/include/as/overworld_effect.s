.include "overworld/overworld_effects.s"

.macro loadgfx address:req
.byte 0
.word \address
.endm

.macro loadpalwithshaders address:req
.byte 1
.word \address
.endm

.macro loadpal address:req
.byte 2
.word \address
.endm

.macro callasm address:req
.byte 3
.word \address
.endm

.macro end
.byte 4
.endm

.macro loadgfx_and_pal_and_callasm tiles_address:req, palette_address:req, function_address:req
.byte 5
.word \tiles_address
.word \palette_address
.word \function_address
.endm

.macro loadgfx_and_callasm tiles_address:req, function_address:req
.byte 6
.word \tiles_address
.word \function_address
.endm

.macro loadpalwithshaders_and_callasm palette_address:req, function_address:req
.byte 7
.word \palette_address
.word \function_address
.endm
