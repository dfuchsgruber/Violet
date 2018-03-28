.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8521
ow_script_0x8c8521:
loadpointer 0x0 str_0x8c8aec
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c8aec

str_0x8c8aec:
    .string "Der Untergrund-Markt ist\nunantastbar.\pWenn man den Gerüchten glaubt,\nsteht an seiner Spitze ein\lMitglied der Top Vier selbst."
        
        
.elseif LANG_EN

.endif
