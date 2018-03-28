.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8f3bfa
ow_script_movs_0x8f3bfa:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8f3d64
ow_script_0x8f3d64:
lock
faceplayer
checkflag POKERADAR
gotoif EQUAL ow_script_0x8efcd3
loadpointer 0x0 str_0x8f3c00
callstd MSG
setvar 0x8004 0x1
special2 0x800d 0xd4
buffernumber 0x2 0x8006
compare 0x8006 0xa
gotoif LESS ow_script_0x8f3bfd
sound 0x15
applymovement 0x800f ow_script_movs_0x8f3bfa
waitmovement 0x0
loadpointer 0x0 str_0x8f3cd9
callstd MSG
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x8f3bc4
callstd MSG_KEEPOPEN
lock
faceplayer
waitfanfare
lock
faceplayer
loadpointer 0x0 str_0x8f3a57
callstd MSG
setflag POKERADAR
release
end


.global ow_script_0x8f3bfd
ow_script_0x8f3bfd:
release
end


.global ow_script_0x8efcd3
ow_script_0x8efcd3:
loadpointer 0x0 str_0x8f39d8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f3c00

str_0x8f3c00:
    .string "Hallo, ich bin ein Assistent\nProfessor Tanns. Ich helfe\lTrainern, die den Pokedex haben,\lbei der Vervollständigung der\lDaten.\lWenn du 10 verschiedene Pokémon im\lPokedex registriert hast, erhältst\ldu eine Belohnung."
        
        
.global str_0x8f3cd9

str_0x8f3cd9:
    .string "Sehr gut, du hast bereits\nBUFFER_3 verschiedene Pokémon\lregistriert. Als Belohnung werde\lich die Pokeradar-App auf deinem\lPokepad installieren."
        
        
.global str_0x8f3bc4

str_0x8f3bc4:
    .string "Deinem Pokepad wurde die\nPokeradar-App hinzugefügt!"
        
        
.global str_0x8f3a57

str_0x8f3a57:
    .string "Das Pokeradar kann in der Nähe von\nhohem Graß benutzt werden, um\lseltene Pokémon aufzuspüren.\lSie sind sehr scheu, also gerate\lnicht in ihr Blickfeld, wenn du\lsie fangen möchtest.\lJe öfter du das Pokeradar\leinsetzt, desto höher ist die\lWahrscheinlichkeit, seltene\lPokémon anzutreffen.\lDiese Funktion sollte dir bei der\lvervollständigung des Pokedex\lenorm helfen."
        
        
.global str_0x8f39d8

str_0x8f39d8:
    .string "Das Pokeradar findet seltene\nPokémon in deiner Umgebung. Da sie\lsehr scheu sind, solltest du nicht\lin ihr Blickfeld geraten."
        
        
.elseif LANG_EN

.endif
