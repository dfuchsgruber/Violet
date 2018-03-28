.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e9027
ow_script_0x8e9027:
trainerbattlestd 0x0 0x46 0x0 str_0x8efc78 str_0x8f0916
loadpointer 0x0 str_0x8f0916
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8efc78

str_0x8efc78:
    .string "Die Welt ist ein grauenvoller Ort.\nWir werden sie unter einen ewigen\lFrieden bringen!"
        
        
.global str_0x8f0916

str_0x8f0916:
    .string "Niemand kann sich gegen den\nFrieden selbst wehren, auch du\lnicht!"
        
        
.elseif LANG_EN

.endif
