.include "flags.s"
.include "vars.s"


.global ow_script_0x953cf2

ow_script_0x953cf2:
clearflag 0x896d
setvar SONG_OVERRIDE 0xffff
sound 0x64
checksound
warpmuted 0x0 0xd 0xff 0x11 0x1a
waitstate
end
