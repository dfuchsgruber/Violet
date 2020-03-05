.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x87bdc8
ow_script_0x87bdc8:
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


.global ow_script_0x87c774
ow_script_0x87c774:
loadpointer 0x0 str_0x87c77f
callstd MSG_FACE
release
end


.global ow_script_0x87c2b9
ow_script_0x87c2b9:
checkflag AKTANIA_GEODUDE_FOUGHT
gotoif EQUAL ow_script_0x87c2cd
loadpointer 0x0 str_0x87c738
callstd MSG_FACE
release
end


.global ow_script_0x87c2cd
ow_script_0x87c2cd:
loadpointer 0x0 str_0x87c5fa
callstd MSG_FACE
setflag AKTANIA_GEODUDE_DONE
release
end


.global ow_script_0x87c2db
ow_script_0x87c2db:
loadpointer 0x0 str_0x87c492
callstd MSG_FACE
release
end


.ifdef LANG_GER
.global str_0x87c7c7

str_0x87c7c7:
    .string "Hallo! Ich bin ein\nleidenschaftlicher Höhlenbauer. In\ldieser hier bin ich auf einen\lseltsamen Stein gestoßen, den ich\lzuerst für ein Goldnugget hielt,\laber er lässt sich einfach nicht\labbauen. Willst du ihn dir einmal\lansehen?"
        
        
.global str_0x87c738

str_0x87c738:
    .string "Sieh ihn dir einfach an, ich werde\ndaraus nicht schlauDOTS"
        
        
.global str_0x87c77f

str_0x87c77f:
    .string "Wie du willst. Ich werde diesen\nseltsamen Stein weiter\luntersuchenDOTS"
        
        
.global str_0x87c5fa

str_0x87c5fa:
    .string ". . . !\nWas? Der Stein war in Wirklichkeit\lein schillerndes Kleinstein! Das\list ja Wahnsinn! Und ich dachte es\lwäre ein Nugget!"
        
        
.global str_0x87c492

str_0x87c492:
    .string "Immer weiter schuften! Schuften!\nSchuften! Das ist mein Motto!\lGraben, graben, immer weiter\lschuften!"
        
        
.elseif LANG_EN

.endif
