.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1f10
ow_script_0x8f1f10:
loadpointer 0x0 str_0x926cf8
callstd MSG_FACE
end

.global str_0x926cf8

str_0x926cf8:
    .string "Mann, ich würde zu gerne die\nParole kennen, um in dieses Haus\lzu kommen!\pOb sie geheime Tee-Klub Treffen\nabhalten?"
        
        