.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ee13
ow_script_0x95ee13:
trainerbattlestd 0x0 0x98 0x0 str_0x95f49e str_0x95f53d
loadpointer 0x0 str_0x95f53d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95f49e

str_0x95f49e:
    .string "Wir Ranger sind eine von den Top\nVier unabhängige Gruppe, die sich\lum das Wohl Thetos sorgt.\lBesonders in gefährlichen Gebieten\lmüssen wir auf der Hut sein!"
        
        
.global str_0x95f53d

str_0x95f53d:
    .string "Du scheinst recht zäh zu sein,\nverbrenn\ dich nicht."
        
        
.elseif LANG_EN

.endif
