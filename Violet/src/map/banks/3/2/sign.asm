.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_2_sign_2
.global ow_script_map_3_2_sign_0
.global ow_script_map_3_2_sign_3
.global ow_script_map_3_2_sign_1

ow_script_map_3_2_sign_1:
loadpointer 0x0 str_0x8ca664
callstd MSG_SIGN
end


.ifdef LANG_GER
str_0x8ca664:
    .autostring 34 2 "Bruchtal Arena.\pArenaleiter: Lester."
.elseif LANG_EN
.endif


ow_script_map_3_2_sign_3:
    loadpointer 0 str_lester_house
    callstd MSG_SIGN
    end


ow_script_map_3_2_sign_0:
loadpointer 0x0 str_0x8cee15
callstd MSG_SIGN
end


.ifdef LANG_GER
str_0x8cee15:
    .autostring 34 2 "Bruchfels, die Stadt des ewigen SonnenscheinsDOTS\pDer Text ist durchgestrichenDOTS"
str_lester_house:
    .autostring 34 2 "Lesters Haus"
.elseif LANG_EN

.endif

