.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a5564
ow_script_0x8a5564:
lock
faceplayer
checkflag WONDERTRADE
gotoif EQUAL ow_script_0x8a5ccb
call ow_script_0x8a7343
release
end


.global ow_script_0x8a7343
ow_script_0x8a7343:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aac71
callstd MSG
special 0x7
fanfare 0x13e
loadpointer 0x0 str_0x8aa801
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
setflag WONDERTRADE
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8ab119
callstd MSG_FACE
special 0x7
setvar STORY_PROGRESS 0x10
return


.global ow_script_0x8a5ccb
ow_script_0x8a5ccb:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7951
callstd MSG
special 0x7
release
end

.global str_0x8aac71

str_0x8aac71:
    .string "Oh, PLAYER. Ich hätte es beinahe\nvergessen, dass auch ich für euch\lbeide ein Geschenk habe.\lSeit geraumer Zeit arbeite ich\lnämlich an einem System, dass\lhelfen soll, Trainer von überall\lmiteinander zu verbinden, den\lWundertausch.\lDie ganze Sache ist sehr aufregend\lund einfach zugleich: Man bietet\lein Pokémon aus seinem Team zum\lTausch an - dann wird dieses an\leinen Trainer irgendwo auf der\lWelt versandt und mal selbst\lerhält dessen verschicktes\lPokémon. Das Lustige dabei ist,\ldass du nie weißt, wo dein Pokémon\lhingeschickt wird und woher die\lPokémon, die man selbst erhält,\lwirklich stammen.\lIch werde die App auf deinem\lPokepad installieren, wenn du\lerlaubst."
        
        
.global str_0x8aa801

str_0x8aa801:
    .string "Elise hat die Wundertausch-App auf\ndem Pokepad installiert!"
        
        
.global str_0x8ab119

str_0x8ab119:
    .string "Je öfter du den Wundertausch\ndurchführst, desto höher steigt\lder Level der App. Ist dieser erst\lgroß genug, steigen auch die\lChancen seltene Pokémon zu\lerhalten. Manche von ihnen sind\lvon Züchtern herangezogen worden,\landere tragen seltene Items oder\lkennen ungewöhnliche Attacken, die\landere Trainer sie gelehrt haben.\pMein Traum ist es, die Barrieren\nder Räumlichkeit zwischen den\lTrainern zu durchbrechen und die\lWelt zu vereinigen. Es würde mich\lfreuen, wenn du mir dabei hilfst,\lindem du den Wundertausch oft\lbenutzt."
        
        
.global str_0x8a7951

str_0x8a7951:
    .string "In naher Zukunft schon werden\nviele Trainer den Wundertausch\lnutzen. Davon bin ich überzeugt!"
        
        