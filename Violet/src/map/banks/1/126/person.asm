.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_1_126_trainer_2
.global ow_script_map_1_126_trainer_0
.global ow_script_map_1_126_trainer_1
.global ow_script_map_1_126_trainer_3
.global ow_script_map_1_126_trainer_4

ow_script_map_1_126_trainer_1:
loadpointer 0x0 str_0x864574
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x864574:
    .string "Ich würde dir nicht empfehlen,\nnoch tiefer in den Vulkan zu\lwandern.\pNicht, dass es einen Weg gäbeDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_126_trainer_4:
loadpointer 0x0 str_0x9663ca
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9663ca:
    .string "Ich habe das Magmaherz an diesem\nOrt gefunden, aber Archäologen\lhaben es sofort beschlagnahmt und\lin das Orina City Museum gebracht.\pWo liegt da die Gerechtigkeit?"


.elseif LANG_EN

.endif


ow_script_map_1_126_trainer_0:
trainerbattlestd 0x0 0xa9 0x0 str_0x8646a4 str_0x864721
loadpointer 0x0 str_0x864721
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8646a4:
    .string "Ich habe es mir ausgesucht, ein\nRanger zu sein, also kann ich mich\lnicht darüber beschweren, nun an\lsolchen Orten zu sein!"



str_0x864721:
    .string "UrghDOTS Diese vernichtende,\nzermürbende HitzeDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_126_trainer_2:
trainerbattlestd 0x0 0xab 0x0 str_0x96628c str_0x9662f7
loadpointer 0x0 str_0x9662f7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x96628c:
    .string "Keke! Was ein kleiner Junge in\neinem Vulkan zu suchen hat?\pWas hat ein großer Junge hier\nverloren? Keke!"



str_0x9662f7:
    .string "Na gut, ich gehe nach HauseDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_126_trainer_3:
trainerbattlestd 0x0 0xac 0x0 str_0x966317 str_0x96638a
loadpointer 0x0 str_0x96638a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x966317:
    .string "Hast du schon einmal einen so\nheißen Ort gesehen?\pIch auch nicht! Und diese Hitze\nwird dich in die Knie zwingen!"



str_0x96638a:
    .string "Du kannst die Hitze noch besser\nbeherrschen als ich! Wahnsinn!"


.elseif LANG_EN

.endif