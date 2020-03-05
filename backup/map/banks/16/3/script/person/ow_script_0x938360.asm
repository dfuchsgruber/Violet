.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x938360
ow_script_0x938360:
trainerbattlestd 0x0 0x7f 0x0 str_0x93bc2f str_0x93bc87
loadpointer 0x0 str_0x93bc87
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93bc2f

str_0x93bc2f:
    .string "Alle meine Klassenkameradinen\nhaben bereits einen Freund!\lWie wäre es mit uns beiden?"
        
        
.global str_0x93bc87

str_0x93bc87:
    .string "Soll das heißen, du erteilst mir\neinen Korb?"
        
        
.elseif LANG_EN

.endif
