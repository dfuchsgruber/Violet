.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x916258
ow_script_0x916258:
call ow_script_0x89e33c
loadpointer 0x0 str_0x931d8f
callstd MSG
faceplayer
loadpointer 0x0 str_0x931bb9
callstd MSG_FACE
special 0x7
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.ifdef LANG_GER
.global str_0x931d8f

str_0x931d8f:
    .string "... ... ...\n... ... ..."
        
        
.global str_0x931bb9

str_0x931bb9:
    .string "PLAYER.\nDich hätte ich sicherlich nicht\lhier erwartet.\pDu hast dich weiterentwickelt, das\nist unverkennbar.\pDu bist als Trainer und Mensch\ngewachsen, wie ich.\pDieser Ort ist mir ein Dorn im\nAuge, denn er wurde von meinem\lVater ins Leben gerufen.\pEr ist ein mächtiger Trainer,\nmächtiger noch als Faun, dieser\lalte Narr.\pUnd ich werde ihn stürzen.\nEines Tages...\pVergiss nie, dass Macht in dieser\nWelt alles ist. Sieh dir diesen\lOrt an und werde dir dessen\lbewusst."
        
        
.elseif LANG_EN

.endif
