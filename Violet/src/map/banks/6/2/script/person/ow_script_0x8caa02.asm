.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8caa02
ow_script_0x8caa02:
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x8caa15
loadpointer 0x0 str_aktania_gym_referee
callstd MSG_FACE
end


.global ow_script_0x8caa15
ow_script_0x8caa15:
loadpointer 0 str_0x8cab11
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8cab11:
    .autostring 34 2 "Gute Arbeit!\nManus zu besiegen, ist kein Leichtes!\pDass du an seiner harten Verteidigungslinie vorbeigekommen bist, zeugt von deinem Talent, Kindchen!"
        
        
.elseif LANG_EN

.endif
