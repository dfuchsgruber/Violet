.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_map_6_14_person_0
.global ow_script_map_6_14_person_1
.global ow_script_0x8cafa0
.global ow_script_0x8cee08

ow_script_map_6_14_person_0:
loadpointer 0x0 str_0x8ced64
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ced64:
    .string "Es heißt, dass die ersten Menschen\nüberhaupt den Tempel auf dieser\lInsel erbaut haben sollen.\pEine Schande, dass er nun mehr in\neinem derartigen Zustand verweilt."


.elseif LANG_EN

.endif


ow_script_map_6_14_person_1:
lock
faceplayer
loadpointer 0x0 str_0x8ceca3
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8cafa0
goto ow_script_0x8cee08


ow_script_0x8cee08:
loadpointer 0x0 str_0x8ceaf8
callstd MSG_KEEPOPEN
goto ow_script_0x8cafa0


ow_script_0x8cafa0:
loadpointer 0x0 str_0x8ced19
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ceca3:
    .string "Hallo, mein Junge. Ich lese für\nmein Leben gerne Bücher und\lerzähle Geschichten. Möchtest du\leine Geschichte hören?"



str_0x8ceaf8:
    .string "Einst formte der Gigant, der die\nKontinente mit bloßen Händen zog,\ldrei Soldaten, denen er den Schutz\lder Welt anvertraute.\lEinen Wächter schuf er aus dem\lGestein der Berge, einen Wächter\lschuf er aus dem Eis eines\lGletschers und den dritten Wächter\lschuf er aus den Metallen im\lHerzen der Erde.\lIm Tempel hier huldigen wir den\ldrei Wächtern, die vor wenigen\lJahren nur unsere Welt vor der\lBedrohung aus dem All beschützten."



str_0x8ced19:
    .string "Komm gerne wieder, ich erzähle dir\njederzeit Geschichten, wenn du\lwillst."


.elseif LANG_EN

.endif