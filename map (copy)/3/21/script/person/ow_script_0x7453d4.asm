.include "overworld_script.s"

.include "std.s"

.global ow_script_0x7453d4
ow_script_0x7453d4:
trainerbattlestd 0x0 0x62 0x0 str_0x81fc71 str_0x8ffccf
loadpointer 0x0 str_0x8ffccf
callstd MSG_FACE
end

.global str_0x81fc71

str_0x81fc71:
    .string "Ich hätte mir einen besseren Ort\nfür mein Picknick aussuchen\lkönnen."
        
        
.global str_0x8ffccf

str_0x8ffccf:
    .string "Doch wer kann schon von sich\nbehaupten, in der Wüste ein\lPicknick veranstaltet zu haben?"
        
        