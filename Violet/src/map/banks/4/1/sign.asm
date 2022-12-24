.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x8000a5
.global ow_script_map_4_1_sign_0
.global ow_script_0x89a168
.global ow_script_debugger

ow_script_0x8000a5:
lock
faceplayer
loadpointer 0x0 str_0x8000b2
callstd MSG
release
end


.ifdef LANG_GER

str_0x8000b2:
    .autostring 34 2 "Ich bin viel zu alt für Computerspiele.\pAuf mich wartet da draußen die echte Welt!"
.elseif LANG_EN
str_0x8000b2:
    .autostring 34 2 "I am way too old for computer games.\pOutside the real world is waiting for me!"
.endif


ow_script_map_4_1_sign_0:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x89a168
lockall
setvar 0x8004 0x20
special 0x17d
setvar 0x8004 0x1
special 0xd6
sound 0x4
loadpointer 0x0 str_0x1a8124
callstd MSG
special 0xf9
waitstate
special 0x120
clearflag TRANS_DISABLE
releaseall
end


ow_script_0x89a168:
clearflag TRANS_DISABLE
release
end


.ifdef LANG_GER
str_0x1a8124:
    .string "PLAYER schaltet den PC ein."
.elseif LANG_EN
str_0x1a8124:
    .string "PLAYER turns on the PC."
.endif

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