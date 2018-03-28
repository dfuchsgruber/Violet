.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x91fece
ow_script_movs_0x91fece:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8ffe00
ow_script_0x8ffe00:
loadpointer 0x0 str_0x91fed1
callstd MSG
lock
sound 0x15
applymovement 0x800f ow_script_movs_0x91fece
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x91fcc4
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x90fdce
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x90fd48
callstd MSG
special 0x7
trainerbattlecont 0x1 0x64 0x0 str_0x8fff26 str_0x8fff9c ow_script_0x8ffe63

.align 4
choice:
    .word str_violet_grunt_choice_0, 0
    .word str_violet_grunt_choice_1, 0

.global ow_script_0x8ffe63
ow_script_0x8ffe63:
lock
faceplayer
loadpointer 0x0 str_0x8ffe77
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.global ow_script_0x90fdce
ow_script_0x90fdce:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x90fe3d
callstd MSG
special 0x7
loadpointer 0x0 str_0x90fdef
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end

.global str_0x91fed1

str_0x91fed1:
    .string "... Ich habe wohl den Rest der\nDivision verloren in all der\lAufregung..."
        
        
.global str_0x91fcc4

str_0x91fcc4:
    .string "Du bist doch dieser Junge aus dem\nSilvania-Wald! Was willst du von\lmir?\pVerstehst du nicht, warum wir tun,\nwas wir tun? Diese Welt ist völlig\lkrank. Menschen wie du und ich\lsind Sklaven eines Systems, gegen\ldas wir uns nicht wehren können.\pWir werden ausgebeutet und\nunterdrückt, aber reden uns ein,\les wäre nicht so.\pMein ganzes Leben lang hat man mir\ngesagt, ich würde zu nichts\ltaugen, aber Team Violet hat mir\ldas Gefühl gegeben, gebraucht zu\lwerden. Wir werden eine bessere\lWelt erschaffen, eine friedvollere\lWelt."
        
        
.global str_violet_grunt_choice_0

str_violet_grunt_choice_0:
    .string "Rüpel gehen lassen"
        
        
.global str_violet_grunt_choice_1

str_violet_grunt_choice_1:
    .string "Rüpel bekämpfen"
        
        
.global str_0x90fd48

str_0x90fd48:
    .string "Ich kann Team Violet nicht machen\nlassen, was es will. Eure Ziele\lsind nichts als Illusionen, ihr\lwollt eine ganze Welt versklaven."
        
        
.global str_0x8fff26

str_0x8fff26:
    .string "Dann ist es eben der Kampf! Ich\nhabe mir ein brandneues\lPokémon-Team zugelegt, mit welchem\lich dich bezwingen kann!"
        
        
.global str_0x8fff9c

str_0x8fff9c:
    .string "Es ist mir wohl einfach nicht\nbestimmt, dich zu besiegen..."
        
        
.global str_0x8ffe77

str_0x8ffe77:
    .string "...! Du hast mich erneut besiegt,\naber meinen Ehrgeiz hast du nur\langestachelt. Wir werden obsiegen\lund letzlich wirst auch du\leinsehen müssen, dass du falsch\lgelegen hast!"
        
        
.global str_0x90fe3d

str_0x90fe3d:
    .string "Ich werde dich nicht bekämpfen,\nwenn du nicht auf einen Kampf aus\lbist.\lAber sei gewarnt, Team Violet\lnutzt dich nicht weniger aus, als\ldas System der Pokémon-Liga. Öffne\ldeine Augen und blicke der\lWahrheit ins Gesicht. Vorerst aber\lkannst du gehen."
        
        
.global str_0x90fdef

str_0x90fdef:
    .string "... ...\pVielleicht hast du recht. Ich\nwerde über einiges nachdenken\lmüssen."
        
        