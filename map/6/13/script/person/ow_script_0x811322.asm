.include "overworld_script.s"

.include "std.s"

.global ow_script_0x811322
ow_script_0x811322:
loadpointer 0x0 str_0x8cb542
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8cb542

str_0x8cb542:
    .string "Ben? Bist du es? Bist du mein\nkleiner Ben? Oh Ben! Warst du mit\ldeinen kleinen Freunden am Strand\lspielen?"
        
        
.elseif LANG_EN

.endif
