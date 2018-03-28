.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95880b
ow_script_0x95880b:
trainerbattlestd 0x0 0x8d 0x0 str_0x958823 str_0x9588a4
loadpointer 0x0 str_0x9588a4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x958823

str_0x958823:
    .string "Unser Kommandant interessiert sich\nfür ein Artefakt in dem Musem.\pUnd du wirst ihn nicht stören,\nwährend er es sich beschafft!"
        
        
.global str_0x9588a4

str_0x9588a4:
    .string "Nagh! Verdammt!\nAber der wahre Schrecken lauert im\lInneren, mein Junge!"
        
        
.elseif LANG_EN

.endif
