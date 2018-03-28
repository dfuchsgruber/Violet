.include "overworld_script.s"

.include "std.s"

.global ow_script_0x88c2c0
ow_script_0x88c2c0:
loadpointer 0x0 str_0x8a06ea
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a06ea

str_0x8a06ea:
    .string "Die Typenverhältnisse der\nPokémonwelt zu kennen, ist von\lgroßem Vorteil. So kann man seine\lAngriffe effektiv einsetzen!"
        
        
.elseif LANG_EN

.endif
