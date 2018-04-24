.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810c06
ow_script_0x810c06:
trainerbattlestd 0x0 0x74 0x0 str_0x935b6f str_0x932010
loadpointer 0x0 str_0x932010
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x935b6f

str_0x935b6f:
    .string "Südwärts gelangst du über den\nWasserpfad nach Meriana City.\pDort trainiert der größte aller\nKämpfer, Manus!"
        
        
.global str_0x932010

str_0x932010:
    .string "Eines Tages werde ich in seiner\nArena arbeiten!"
        
        
.elseif LANG_EN

.endif
