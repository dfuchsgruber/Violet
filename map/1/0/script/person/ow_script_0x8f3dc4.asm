.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8f4252
ow_script_movs_0x8f4252:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8f3dc4
ow_script_0x8f3dc4:
lock
faceplayer
loadpointer 0x0 str_0x8f3e79
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f3e4a
checkattack ATTACK_NATUR_KRAFT
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x8f3e54
sound 0x15
applymovement 0x800f ow_script_movs_0x8f4252
waitmovement 0x0
loadpointer 0x0 str_0x8f3f3e
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f3e5e
loadpointer 0x0 str_0x8f3fd0
callstd MSG
copyvar 0x8012 0x8013
setvar 0x8005 0x9
call ow_script_0x8f3e68
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f3e5e
loadpointer 0x0 str_0x8f400a
callstd MSG
release
end


.global ow_script_0x8f3e5e
ow_script_0x8f3e5e:
loadpointer 0x0 str_0x8f41db
callstd MSG_FACE
end


.global ow_script_0x8f3e68
ow_script_0x8f3e68:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
special 0x18d
waitstate
lock
faceplayer
clearflag TRANS_DISABLE
return


.global ow_script_0x8f3e54
ow_script_0x8f3e54:
loadpointer 0x0 str_0x8f4148
callstd MSG_FACE
end


.global ow_script_0x8f3e4a
ow_script_0x8f3e4a:
loadpointer 0x0 str_0x8f40f6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f3e79

str_0x8f3e79:
    .string "Die Natur ist ein beeindruckendes\nKunstwerk...\lWenn du mir ein Pokémon zeigst,\ldass Natur-Kraft beherrscht, werde\lich mich erkenntlich zeigen.\lKennt eines deiner Pokémon die\lAttacke Natur-Kraft?"
        
        
.global str_0x8f3f3e

str_0x8f3f3e:
    .string "Du hast tatsächlich Pokémon bei\ndir, welches die Attacke\lNatur-Kraft beherrscht.\pSoll ich zum Dank einem deiner\nPokémon Energieball beibringen?"
        
        
.global str_0x8f3fd0

str_0x8f3fd0:
    .string "Welchem deiner Pokémon soll ich\nEnergieball beibringen?"
        
        
.global str_0x8f400a

str_0x8f400a:
    .string "Energieball ist ein starker\nPflanzen-Angriff der speziellen\lKlasse. Er kann die\lSpezial-Verteidigung des Gegners\lreduzieren."
        
        
.global str_0x8f41db

str_0x8f41db:
    .string "Schade! Wenn du es dir anders\nüberlegst komm jederzeit wieder\lund zeige mir ein Pokémon, das\lNatur-Kraft beherrscht."
        
        
.global str_0x8f4148

str_0x8f4148:
    .string "Keines deiner Pokémon beherrscht\ndie Attacke Natur-Kraft.\pZeige mir ein Pokémon, dass die\nAttacke beherrscht, und ich werde\lmich dankbar zeigen."
        
        
.global str_0x8f40f6

str_0x8f40f6:
    .string "Komm wieder, wenn du mir ein\nPokémon zeigen kannst, das\lNatur-Kraft beherrscht."
        
        
.elseif LANG_EN

.endif
