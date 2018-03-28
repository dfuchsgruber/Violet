.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95cb4c
ow_script_0x95cb4c:
loadpointer 0x0 str_0x95cb56
callstd MSG_FACE
end

.global str_0x95cb56

str_0x95cb56:
    .string "Glaubst du an einen Gott?\nManche verehren Arceus, den\lSchöpfer aller Dinge...\pIch weiß nicht, ob ich an etwas\nderart abstraktes glauben kann..."
        
        