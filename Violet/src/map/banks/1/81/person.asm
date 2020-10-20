.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_1_81_trainer_3
.global ow_script_map_1_81_trainer_5
.global ow_script_map_1_81_trainer_0
.global ow_script_map_1_81_trainer_6
.global ow_script_map_1_81_trainer_2
.global ow_script_map_1_81_trainer_1

ow_script_map_1_81_trainer_0:
trainerbattlestd 0x0 0xa6 0x0 str_0x8643bf str_0x9660f5
loadpointer 0x0 str_0x9660f5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8643bf:
    .string "Selbst wenn du uns Fußsoldaten\nhier besiegst, erwartet dich der\lwahre Schrecken noch!"



str_0x9660f5:
    .string "Team Violets Elite tritt hier auf.\nDu wurdest gewarntDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_81_trainer_2:
trainerbattlestd 0x0 0xa3 0x0 str_0x864425 str_0x86444f
loadpointer 0x0 str_0x86444f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x864425:
    .string "Eindringling.. IchDOTS schwitze..\nKampf!"



str_0x86444f:
    .string "Die Hitze hier ist unerträglich!\nWieso sind wir überhaupt in einem\lVulkan?"


.elseif LANG_EN

.endif


ow_script_map_1_81_trainer_3:
trainerbattlestd 0x0 0xa5 0x0 str_0x947e42 str_0x9636ba
loadpointer 0x0 str_0x9636ba
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x947e42:
    .string "Diese HitzeDOTS willst du wirklich\nkämpfen? UrghDOTS"



str_0x9636ba:
    .string "UrghDOTS Verschwinde einfachDOTS\nÄchzDOTS So heißDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_81_trainer_1:
trainerbattlestd 0x0 0xa4 0x0 str_0x864949 str_0x86453a
loadpointer 0x0 str_0x86453a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x864949:
    .string "Du denkst also tatsächlich, dass\ndu es aufhalten könntest?"



str_0x86453a:
    .string "Deine Versuche werden spätestens\nan Mistral scheiternDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_81_trainer_6:
trainerbattlestd 0x0 0xa7 0x0 str_0x96612f str_0x9661bb
loadpointer 0x0 str_0x9661bb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x96612f:
    .string "Ich habe gehört, dass hier ein\nmächtiges Pokémon schläft.\pWenn wir unsere Mission erfüllt\nhaben, werde ich es mir unter den\lNagel reißen!"



str_0x9661bb:
    .string "Hey! Finger weg von dem legendären\nPokémon!"


.elseif LANG_EN

.endif


ow_script_map_1_81_trainer_5:
trainerbattlestd 0x0 0xa8 0x0 str_0x9661e8 str_0x966268
loadpointer 0x0 str_0x966268
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9661e8:
    .string "Ah, Mistral hatte uns vor dir\ngewarnt.\pDerjenige, der dich ausschaltet,\nerhält eine Beförderung.\lIch bin wohl der Glückliche!"



str_0x966268:
    .string "Oje! Keine Beförderung für michDOTS"


.elseif LANG_EN

.endif