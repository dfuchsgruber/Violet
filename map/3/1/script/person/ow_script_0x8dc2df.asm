.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8dc2df
ow_script_0x8dc2df:
loadpointer 0x0 str_0x8de4c9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8de4c9

str_0x8de4c9:
    .string "Brüder und Schwestern, lasst uns\nkämpfen für eine Welt ohne\lUngerechtigkeit und Unterdrückung!"
        
        
.elseif LANG_EN

.endif
