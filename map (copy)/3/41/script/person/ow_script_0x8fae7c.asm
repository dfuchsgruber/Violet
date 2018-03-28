.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fae7c
ow_script_0x8fae7c:
checkflag BIBOR_QUEST_BIBOR_RECEIVED
gotoif EQUAL ow_script_0x8fb105
checkflag BIBOR_QUEST_DONE
gotoif EQUAL ow_script_0x8fb10e
checkflag BIBOR_QUEST_NOT_TRIGGERED
gotoif EQUAL ow_script_0x8fafe1
loadpointer 0x0 str_0x8dcaa4
callstd MSG_FACE
end


.global ow_script_movs_0x87bf49
ow_script_movs_0x87bf49:
.byte SAY_QUESTION
.byte STOP


.global ow_script_0x8fafe1
ow_script_0x8fafe1:
checktrainerflag 0x28
gotoif LESS ow_script_0x8fb076
lock
faceplayer
loadpointer 0x0 str_0x8dca59
callstd MSG_KEEPOPEN
fanfare 0x13e
loadpointer 0x0 str_0x8dc421
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag BIBOR_QUEST_DONE
lock
faceplayer
applymovement 0x800f ow_script_movs_0x87bf49
waitmovement 0x0
loadpointer 0x0 str_0x8dc9a6
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8fb0b2
loadpointer 0x0 str_0x8fb02d
callstd MSG_FACE
end


.global ow_script_0x8fb0b2
ow_script_0x8fb0b2:
countpokemon
compare LASTRESULT 0x6
gotoif LESS ow_script_0x8fb0c5
goto ow_script_0x8dc43a


.global ow_script_0x8dc43a
ow_script_0x8dc43a:
loadpointer 0x0 str_0x8dc8dd
callstd MSG_FACE
end


.global ow_script_0x8fb0c5
ow_script_0x8fb0c5:
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x87ae8d
callstd MSG_KEEPOPEN
waitfanfare
givepokemon POKEMON_BIBOR 0xc ITEM_BIBORNIT 0x0 0x0 0x0
bufferpokemon 0x0 POKEMON_BIBOR
bufferpokemon 0x1 POKEMON_BIBOR
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
call ow_script_0x947e82
clearflag TRANS_DISABLE
loadpointer 0x0 str_0x8dcd2f
callstd MSG_FACE
setflag BIBOR_QUEST_BIBOR_RECEIVED
end


.global ow_script_0x947e82
ow_script_0x947e82:
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x880b86
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880ba0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x880be5
end


.global ow_script_0x880be5
ow_script_0x880be5:
textcolor 0x3
loadpointer 0x0 str_0x1a8bc9
callstd MSG_KEEPOPEN
setvar LASTRESULT 0xff
return


.global ow_script_0x880ba0
ow_script_0x880ba0:
call ow_script_0x880bd9
loadpointer 0x0 str_0x1a83ae
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880bcd
return


.global ow_script_0x880bcd
ow_script_0x880bcd:
call ow_script_0x1aba65
call ow_script_0x1aba6e
return


.global ow_script_0x1aba6e
ow_script_0x1aba6e:
bufferboxname 0x0 0x4037
checkflag 0x834
callif LESS ow_script_0x1aba89
checkflag 0x834
callif EQUAL ow_script_0x1abab4
return


.global ow_script_0x1abab4
ow_script_0x1abab4:
special2 0x800d 0x165
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x1abacd
loadpointer 0x0 str_0x1a8ac7
callstd MSG_KEEPOPEN
return


.global ow_script_0x1abacd
ow_script_0x1abacd:
special2 0x800d 0x18a
bufferboxname 0x2 0x800d
loadpointer 0x0 str_0x1a8b4b
callstd MSG_KEEPOPEN
return


.global ow_script_0x1aba89
ow_script_0x1aba89:
special2 0x800d 0x165
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x1abaa2
loadpointer 0x0 str_0x1a8a83
callstd MSG_KEEPOPEN
return


.global ow_script_0x1abaa2
ow_script_0x1abaa2:
special2 0x800d 0x18a
bufferboxname 0x2 0x800d
loadpointer 0x0 str_0x1a8b08
callstd MSG_KEEPOPEN
return


.global ow_script_0x880bd9
ow_script_0x880bd9:
return


.global ow_script_0x880b86
ow_script_0x880b86:
goto ow_script_0x8c8acf


.global ow_script_0x8c8acf
ow_script_0x8c8acf:
loadpointer 0x0 str_0x1a83ae
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x931332
clearflag TRANS_DISABLE
return


.global ow_script_0x931332
ow_script_0x931332:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
countpokemon
subvar LASTRESULT 0x1
copyvar 0x8004 LASTRESULT
fadescreen 0x1
special 0x9e
waitstate
return


.global ow_script_0x8fb076
ow_script_0x8fb076:
lock
faceplayer
loadpointer 0x0 str_0x8dcba5
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8dcb4e
loadpointer 0x0 str_0x8dcb0a
callstd MSG
clearflag BIBOR_QUEST_NOT_TRIGGERED
release
end


.global ow_script_0x8dcb4e
ow_script_0x8dcb4e:
loadpointer 0x0 str_0x8dcb58
callstd MSG_FACE
end


.global ow_script_0x8fb10e
ow_script_0x8fb10e:
lock
faceplayer
loadpointer 0x0 str_0x8fcddd
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8dc94e
goto ow_script_0x8fb0b2


.global ow_script_0x8dc94e
ow_script_0x8dc94e:
loadpointer 0x0 str_0x8dc958
callstd MSG_FACE
end


.global ow_script_0x8fb105
ow_script_0x8fb105:
loadpointer 0x0 str_0x8dcd4c
callstd MSG_FACE
end

.global str_0x8dcaa4

str_0x8dcaa4:
    .string "Der Rüpel ist wohl nach Norden\ngerannt, in Richtung Route 3!"
        
        
.global str_0x8dca59

str_0x8dca59:
    .string "Oh, du hast meine Bibor\nzurückgebracht! Vielen, vielen\lDank!"
        
        
.global str_0x8dc421

str_0x8dc421:
    .string "PLAYER übergibt die Bibor!"
        
        
.global str_0x8dc9a6

str_0x8dc9a6:
    .string "Was ist das? Sieht so aus, als\nwolle eines der Bibor bei dir\lbleiben. Willst du das Bibor in\ldein Team aufnehmen?"
        
        
.global str_0x8fb02d

str_0x8fb02d:
    .string "Das ist aber schade! Komm wieder,\nwenn du es dir anders überlegt\lhast."
        
        
.global str_0x8dc8dd

str_0x8dc8dd:
    .string "Sieht so aus, als hättest du nicht\ngenug Platz in deinem Team.\pKomm wieder, wenn du Platz in\ndeinem Team hast."
        
        
.global str_0x87ae8d

str_0x87ae8d:
    .string "PLAYER hat Bibor erhalten!"
        
        
.global str_0x8dcd2f

str_0x8dcd2f:
    .string "Kümmere dich gut um Bibor!"
        
        
.global str_0x1a8bc9

str_0x1a8bc9:
    .string "Es ist kein Platz mehr für Pokémon\nvorhanden!\pDie Pokémon BOXEN sind voll und\nes kann kein Pokémon mehr\labgelegt werden!"
        
        
.global str_0x1a8ac7

str_0x1a8ac7:
    .string "BUFFER_2 wurde auf BILLs PC\nübertragen.\pEs wurde in BOX\nQUOTEBUFFER_1QUOTE abgelegt."
        
        
.global str_0x1a8b4b

str_0x1a8b4b:
    .string "BOX QUOTEBUFFER_3QUOTE in\nBILLs PC ist voll.\pBUFFER_2 wurde in BOX\nQUOTEBUFFER_1QUOTE übertragen."
        
        
.global str_0x1a8a83

str_0x1a8a83:
    .string "BUFFER_2 wurde auf JEMANDES PC\nübertragen.\pEs wurde in BOX\nQUOTEBUFFER_1QUOTE abgelegt."
        
        
.global str_0x1a8b08

str_0x1a8b08:
    .string "BOX QUOTEBUFFER_3QUOTE in\nJEMANDES PC ist voll.\pBUFFER_2 wurde in BOX\nQUOTEBUFFER_1QUOTE übertragen."
        
        
.global str_0x8dcba5

str_0x8dcba5:
    .string "Oh, du siehst aus wie ein Trainer!\nEiner dieser Schurken von Team\lViolet hat mich kurzerhand aller\lmeiner gezüchteten Bibor beraubt.\pIch selbst bin kein Trainer, wärst\ndu also so freundlichen, sie mir\lwiederzuholen?"
        
        
.global str_0x8dcb0a

str_0x8dcb0a:
    .string "Wie überaus rühmlich von dir! Ich\nbin auf deine Hilfe angewiesen!"
        
        
.global str_0x8dcb58

str_0x8dcb58:
    .string "Wie jammerschade! Was soll ich\ndenn als Imker nun tun, so ganz\lohne Bibor?"
        
        
.global str_0x8fcddd

str_0x8fcddd:
    .string "Bist du gekommen, um das Bibor in\ndein Team aufzunehmen?"
        
        
.global str_0x8dc958

str_0x8dc958:
    .string "Das ist aber schade! Solltest du\ndeine Meinung ändern, komm einfach\lzu mir."
        
        
.global str_0x8dcd4c

str_0x8dcd4c:
    .string "Ich möchte dir vielmals danken,\ndass du mir meine Bibor\lzurückgebracht hast.\pSie sind mein ganzer Stolz, musst\ndu wissen!"
        
        