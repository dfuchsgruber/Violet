.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x87c2b9
.global ow_script_0x87c774
.global ow_script_map_6_15_person_0
.global ow_script_0x87c2cd
.global ow_script_0x87c2db

ow_script_map_6_15_person_0:
lock
faceplayer
checkflag AKTANIA_GEODUDE_DONE
gotoif EQUAL ow_script_0x87c2db
checkflag AKTANIA_GEODUDE_ACCEPTED
gotoif EQUAL ow_script_0x87c2b9
loadpointer 0x0 str_0x87c7c7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87c774
loadpointer 0x0 str_0x87c738
callstd MSG_FACE
setflag AKTANIA_GEODUDE_ACCEPTED
release
end


ow_script_0x87c774:
loadpointer 0x0 str_0x87c77f
callstd MSG_FACE
release
end


ow_script_0x87c2b9:
checkflag AKTANIA_GEODUDE_FOUGHT
gotoif EQUAL ow_script_0x87c2cd
loadpointer 0x0 str_0x87c738
callstd MSG_FACE
release
end


ow_script_0x87c2cd:
loadpointer 0x0 str_0x87c5fa
callstd MSG_FACE
setflag AKTANIA_GEODUDE_DONE
release
end


ow_script_0x87c2db:
loadpointer 0x0 str_0x87c492
callstd MSG_FACE
release
end


.ifdef LANG_GER

str_0x87c7c7:
    .string "Hallo! Ich bin ein\nleidenschaftlicher Höhlenbauer. In\ldieser hier bin ich auf einen\lseltsamen Stein gestoßen, den ich\lzuerst für ein Goldnugget hielt,\laber er lässt sich einfach nicht\labbauen. Willst du ihn dir einmal\lansehen?"



str_0x87c738:
    .string "Sieh ihn dir einfach an, ich werde\ndaraus nicht schlauDOTS"



str_0x87c77f:
    .string "Wie du willst. Ich werde diesen\nseltsamen Stein weiter\luntersuchenDOTS"



str_0x87c5fa:
    .string ". . . !\nWas? Der Stein war in Wirklichkeit\lein schillerndes Kleinstein! Das\list ja Wahnsinn! Und ich dachte es\lwäre ein Nugget!"



str_0x87c492:
    .string "Immer weiter schuften! Schuften!\nSchuften! Das ist mein Motto!\lGraben, graben, immer weiter\lschuften!"


.elseif LANG_EN

.endif