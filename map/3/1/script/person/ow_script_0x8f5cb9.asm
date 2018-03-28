.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f5cb9
ow_script_0x8f5cb9:
special 0x3b
playsong MUS_KAMPF_GEGEN_ARENALEITER_HOENN 0x0
trainerbattlecont 0x1 0x88 0x0 str_0x8f5cda str_0x8f5cda ow_script_0x8f5cd8


.global ow_script_0x8f5cd8
ow_script_0x8f5cd8:
end


.ifdef LANG_GER
.global str_0x8f5cda

str_0x8f5cda:
    .string "t"
        
        
.elseif LANG_EN

.endif
