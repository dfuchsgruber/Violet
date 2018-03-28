.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899d47
ow_script_0x899d47:
loadpointer 0x0 str_0x8a27bc
callstd MSG_FACE
end

.global str_0x8a27bc

str_0x8a27bc:
    .string "Der Wassertunnel verbindet Meriana\nCity mit Kaskada, der Stadt des\lWassers. Von dort aus erhält auch\ldieser Ort hier seine Versorgung\lmit frischem Wasser."
        
        