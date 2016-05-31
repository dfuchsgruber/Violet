.macro frame frameid
.hword \frameid
.endm

.equ COPYSET, 1
.equ COPYMAP, 2

.macro endframe
.byte 0xFF
.endm

@ends script (return on subscripts)
.macro end
.byte 0
.endm

@continues at subscript with frame = startframe
.macro call subscript startframe
.byte 1
.word \subscript
.hword \startframe
.endm

@continues at another offset with frame = startframe
.macro jump script startframe
.byte 2
.word \script
.hword \startframe
.endm

@resets bgs
.macro bg_reset
.byte 9
.endm

@performs bg setups with list to confgs
.macro bg_setup tilemode cnfglist cnfgcount
.byte 0xA
.byte \tilemode
.word \cnfglist
.byte \cnfgcount
.endm

@overrides bg tileset or tilemap on a certain bg
@source := data source comp
@size := uncompressed data size
@start := start tile on bg
@mode := SET(1) or MAP(2)
.macro bg_override id source size start mode
.byte 0xE
.byte \id
.word \source
.hword \size
.hword \start
.byte \mode
.endm

@fades count colors starting at first into target or reverse in count frames
.macro fadescreen target first count duration reverse
.byte 0x1E
.hword \target
.hword \first
.hword \count
.hword \duration
.byte \reverse
.endm

@plays cry
.macro cry cryid modulation
.byte 0x22
.hword \cryid
.byte \modulation
.endm

@sets a simply maintenance callback as callback1
.macro maintain
.byte 0x23
.endm

@releases a scripts waitstate
.macro script_notify
.byte 0x24
.endm

@field for bg setup
.macro bg_setup_cnfg id charbase mapbase size colmode priority
.word \id | (\charbase << 2) | (\mapbase << 4) | (\size << 9) | (\colmode << 11) | (\priority << 12)
.endm