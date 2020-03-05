.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"

.global ow_script_debugger
ow_script_debugger:
    lock
    checkgender
    compare LASTRESULT 0x0
    callif EQUAL load_m
    callif NOT_EQUAL load_f
    setvar LASTRESULT 0xAF02
    callstd MSG
    compare LASTRESULT 0x1337
    callif EQUAL debugger
    release
    end

load_m:
    loadpointer 0x0 console_text_m
    return

load_f:
    loadpointer 0x0 console_text_f
    return

debugger:
    loadpointer 0x0 debugger_text
    callstd MSG
    warp 0x4 0x3 0xFF 0x8 0xB
    waitstate
    return

console_text_m:
    .autostring 35 2 "PLAYER spielt gerade an seiner Konsole.\pEin Spiel namens Ultraviolet ist eingelegt."

console_text_f:
    .autostring 35 2 "PLAYER spielt gerade an ihrer Konsole.\pEin Spiel namens Ultraviolet ist eingelegt."

debugger_text:
    .autostring 35 2 "PLAYER hat den Debugger aktiviert."