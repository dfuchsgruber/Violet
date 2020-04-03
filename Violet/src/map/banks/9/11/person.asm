.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_9_11_person_1
.global ow_script_map_9_11_person_2
.global ow_script_map_9_11_person_3
.global ow_script_map_9_11_person_0

ow_script_map_9_11_person_0:
loadpointer 0x0 str_0x95cf0e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cf0e:
    .string "Wer du nicht sein kannst, der\nsollst du auch nicht sein.\pDas ist eine Weisheit, die ich\njedem auf den Weg mitgeben will."


.elseif LANG_EN

.endif


ow_script_map_9_11_person_1:
loadpointer 0x0 str_0x95cf92
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cf92:
    .string "Dass meine Frau ihren Vater bei\nuns wohnen lässt, stört mich\lprinzipiell zwar nichtDOTS\pAber diese schrecklichen\nLebensweisheiten, mit denen er die\lFamilie bei Langeweile hältDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_11_person_3:
loadpointer 0x0 str_0x95d04f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d04f:
    .string "Mein Mann hat insgeheim ein\nProblem mit meinem Vater.\pEr gibt es zwar nicht zu, aber er\nkann ihn nicht ausstehen."


.elseif LANG_EN

.endif


ow_script_map_9_11_person_2:
loadpointer 0x0 str_0x95d0cc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d0cc:
    .string "Papi findet Opi ganz doll öde!\nDer öde Opi! Juhu!"


.elseif LANG_EN

.endif