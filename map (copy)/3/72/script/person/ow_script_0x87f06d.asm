.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87f06d
ow_script_0x87f06d:
loadpointer 0x0 str_0x8a05dd
callstd MSG_FACE
end

.global str_0x8a05dd

str_0x8a05dd:
    .string "Diese Statue stellt ein Pokémon\nvom Typen Stahl und Fee dar. Es\lheißt Flunkifer."
        
        