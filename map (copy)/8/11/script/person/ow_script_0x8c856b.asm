.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c856b
ow_script_0x8c856b:
loadpointer 0x0 str_0x93155a
callstd MSG_FACE
end

.global str_0x93155a

str_0x93155a:
    .string "Sei gegrüßt!\pMeine Wenigkeit verkauft Protonen-\nbeschleuniger.\pMeine besten Stücke verleihen den\nTeilchen Energien von bis zu\lsieben Terra-Elektronenvolt.\pWie, du weißt nicht wovon ich\nspreche?\pVerschwinde, du Banause!"
        
        