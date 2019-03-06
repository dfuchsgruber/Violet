.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8645db
ow_script_0x8645db:
trainerbattlestd 0x0 0xac 0x0 str_0x966317 str_0x96638a
loadpointer 0x0 str_0x96638a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x966317

str_0x966317:
    .string "Hast du schon einmal einen so\nheißen Ort gesehen?\pIch auch nicht! Und diese Hitze\nwird dich in die Knie zwingen!"
        
        
.global str_0x96638a

str_0x96638a:
    .string "Du kannst die Hitze noch besser\nbeherrschen als ich! Wahnsinn!"
        
        
.elseif LANG_EN

.endif
