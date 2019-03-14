.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"

.global ow_script_debugger
ow_script_debugger:
    lock
    setvar LASTRESULT 0xAF02
    loadpointer 0x0 console_text
    callstd MSG
    compare LASTRESULT 0x1337
    callif EQUAL debugger
    release
    end

debugger:
    loadpointer 0x0 debugger_text
    callstd MSG
    warp 0x4 0x3 0xFF 0x8 0xB
    waitstate
    return

console_text:
    .autostring 35 2 "PLAYER spielt gerade an seiner Wii.\pEin Spiel namens Ultraviolet ist eingelegt."

debugger_text:
    .autostring 35 2 "PLAYER hat den Debugger aktiviert."