.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"

.global ow_script_stop_debugger
ow_script_stop_debugger:
    lock
    loadpointer 0x0 leave_text
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    callif EQUAL leave 
    release
    end

leave:
    warp 0x4 0x1 0xFF 0xC 0x11
    waitstate
    return

leave_text:
    .autostring 35 2 "Willst du den\nUltraviolet Debugger verlassen?"