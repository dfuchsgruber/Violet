.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8951c4
ow_script_0x8951c4:
lockall
faceplayer
call ow_script_0x895cf9
loadpointer 0x0 str_0x843a47
callstd MSG
special 0x7
fadescreen 0x1
sound 0x119
special 0x0
fadescreen 0x2
fadescreen 0x1
fadescreen 0x2
fadescreen 0x1
fadescreen 0x0
checkflag MERIANA_CITY_VIOLET_GRUNTS
playsong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY 0x0
call ow_script_0x895cf9
loadpointer 0x0 str_0x843aba
callstd MSG_FACE
special 0x7
releaseall
end


.global ow_script_0x895cf9
ow_script_0x895cf9:
setvar 0x8000 0x1
setvar 0x8001 0xb
setvar 0x8002 0xe
special 0x6
return


.ifdef LANG_GER
.global str_0x843a47

str_0x843a47:
    .string "Oh, du und deine Pokémon sehen ja\nschrecklich erschöpft aus! Setzt\leuch doch erstmal zu mir und ruht\leuch aus."
        
        
.global str_0x843aba

str_0x843aba:
    .string "Oh, schon viel besser, PLAYER!\nUnd jetzt gib alles, zeig es der\lWelt!"
        
        
.elseif LANG_EN

.endif
