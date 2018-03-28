.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d3b4
ow_script_0x93d3b4:
loadpointer 0x0 str_0x94982e
callstd MSG_FACE
end

.global str_0x94982e

str_0x94982e:
    .string "Hast du je von der Laz.Corp\ngehört?\pSie ist für den rapiden\ntechnischen Fortschritt unserer\lZeit verantwortlich!"
        
        