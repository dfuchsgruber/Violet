.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89f201
ow_script_0x89f201:
loadpointer 0x0 str_0x8a2b69
callstd MSG
end


.ifdef LANG_GER
.global str_0x8a2b69

str_0x8a2b69:
    .string "Wenn ich so über die Kronen der\nBäume blicke, werde ich ganz\lmelancholisch. Als kleines Mädchen\lhaben ich und mein Pokémon gerne\lim Unterholz gespielt..."
        
        
.elseif LANG_EN

.endif
