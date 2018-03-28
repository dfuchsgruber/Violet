.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d59c
ow_script_0x93d59c:
lock
faceplayer
call ow_script_0x8a7f80
loadpointer 0x0 str_0x949632
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x949573
setvar BATTLE_SONG_OVERRIDE 0x165
trainerbattlecont 0x1 0x84 0x0 str_0x94948c str_0x949515 ow_script_0x93d5e1


.global ow_script_0x93d5e1
ow_script_0x93d5e1:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x94918c
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x800f
setflag ROUTE_5_VIOLET_GRUNTS
fadescreen 0x0
release
end


.global ow_script_0x8a7f80
ow_script_0x8a7f80:
setvar 0x8000 0x1
setvar 0x8001 0xf
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x949573
ow_script_0x949573:
loadpointer 0x0 str_0x949581
callstd MSG
special 0x7
release
end


.ifdef LANG_GER
.global str_0x949632

str_0x949632:
    .string "Oh, hallo PLAYER!\nIch wollte dich nicht überrumpeln.\lWie ich sehe, hast du gerade die\lArena von Meriana City gemeistert.\lIch habe ich mich in letzter Zeit\lselbst etwas am Kämpfen versucht.\lWie wäre es mit einem Kampf?"
        
        
.global str_0x94948c

str_0x94948c:
    .string "Ich habe mir eine Reihe ganz\nnetter Pokémon aus dem\lWundertausch zusammengestellt.\pSehen wir mal, ob ich als Trainer\nauch etwas tauge."
        
        
.global str_0x949515

str_0x949515:
    .string "Ich habe mich in dir keine Sekunde\nlang getäuscht.\pDu bist ein beeindruckender\nTrainer, PLAYER."
        
        
.global str_0x94918c

str_0x94918c:
    .string "Ich habe es kommen sehen.\nAber schlecht habe ich mich nicht\lgeschlagen, oder?\pVielleicht mache ich das Kämpfen\nja zu meinem neuen Hobby, neben\lder ganzen Forschung.\pWo wir gerade beim Thema sind:\nLaz. Corp, die Firma, bei der ich\lbeschäftigt bin, hat ein komplett\lvirtuelles Pokémon kreiert.\pDu solltest dir das unbedingt\nansehen.\pEs wird auch Professor Tann im\nHinblick auf den Pokédex helfen.\pDer Hauptsitz der Laz.Corp ist in\nOrina City. Das liegt westlich von\lRoute 2, wo das Labor von\lProfessor Tann ist.\lWenn du dich an der Kreuzung, die\lnördlich zur Route 3 führt,\lwestlich bewegst, solltest du\lfrüher oder später Orina City\lerreichen.\pVon mir hast du aber nicht\nerfahren, dass es gelungen ist,\lein künstliches Pokémon zu\lerschaffen, ja?\pBis dann, PLAYER."
        
        
.global str_0x949581

str_0x949581:
    .string "Oh, ich verstehe schon.\nDu willst deinen erschöpften\lPokémon sicherlich eine Pause\lgönnen.\pVergiss mich aber nicht!\pWenn du mich schlägst, verrate ich\ndir auch ein Geheimnis!"
        
        
.elseif LANG_EN

.endif
