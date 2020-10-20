.include "callstds.s"
.include "overworld_script.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_map_3_1_sign_0
.global ow_script_map_3_1_sign_1
.global ow_script_map_3_1_sign_2

ow_script_map_3_1_sign_0:
loadpointer 0x0 str_0
callstd MSG_SIGN
end

ow_script_map_3_1_sign_1:
loadpointer 0x0 str_1
callstd MSG_SIGN
end

ow_script_map_3_1_sign_2:
loadpointer 0x0 str_2
callstd MSG_SIGN
end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Blütenbach Arena.\pArenaleiter: Manuel"
str_1:
    .autostring 34 2 "Blütenbach\pFrieden durch Kraft und Fokus."
str_2:
    .autostring 34 2 "LEFT_ARROW Route 2"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Petalcreek Gym.\pGymleader: Manuel"
str_1:
    .autostring 34 2 "Petalcreek\pPeace by focus and discipline."
str_2:
    .autostring 34 2 "LEFT_ARROW Route 2"
.endif

