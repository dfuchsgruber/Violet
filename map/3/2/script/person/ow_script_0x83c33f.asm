.include "overworld_script.s"

.include "std.s"

.global ow_script_0x83c33f
ow_script_0x83c33f:
loadpointer 0x0 str_0x8c0c34
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c0c34

str_0x8c0c34:
    .string "Man hat mir gesagt, dass es viele\nWingulls zu sehen gebe, auf dieser\lregnerischen Insel.\pOb man mich vereppelt hat? Das\neinzige weit und breit sind\lschwarze Wolken über uns und keine\lVögel!"
        
        
.elseif LANG_EN

.endif
