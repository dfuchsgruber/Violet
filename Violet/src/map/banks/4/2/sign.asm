.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_4_2_sign_0
.global ow_script_rival_bookshelf

ow_script_map_4_2_sign_0:
loadpointer 0x0 str_0x8f4eff
callstd MSG_SIGN
end

ow_script_rival_bookshelf:
    loadpointer 0x0 str_bookshelf
    callstd MSG_SIGN
    end

.ifdef LANG_GER

str_0x8f4eff:
    .autostring 34 2 "Dieser Computer gehört RIVAL.\pIch sollte nicht in seinen Sachen herumstöbern."
str_bookshelf:
    .autostring 34 2 "Das sind eine Menge BücherDOTS\pSchwer vorstellbar, dass RIVAL auch nur eines davon gelesen hat."

.elseif LANG_EN
str_0x8f4eff:
    .autostring 34 2 "This computer belongs to RIVAL.\pI shouldn't snoop around in his stuff."
str_bookshelf:
    .autostring 34 2 "These are a lot of booksDOTS\pHard to imagine that RIVAL has read even one of them."
.endif