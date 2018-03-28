.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948c3a
ow_script_0x948c3a:
loadpointer 0x0 str_0x94c233
callstd MSG_FACE
end

.global str_0x94c233

str_0x94c233:
    .string "Hast du je vom weißen Albus\ngehört?\pEr war einst Mitglied der Top Vier\nund leitet jetzt die edle\lRevolutionsbewegung.\pEr ist ja so edel, so großmüßtig\nund großherzig..."
        
        