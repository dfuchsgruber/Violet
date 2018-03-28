.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95fb75
ow_script_0x95fb75:
loadpointer 0x0 str_0x961354
callstd MSG_FACE
end

.global str_0x961354

str_0x961354:
    .string "An machen Tagen kann man hier das\nlegendäre Pokémon Lavados treffen.\pEin großer brennender Vogel,\ndessen Ruf die Flammen entfacht."
        
        