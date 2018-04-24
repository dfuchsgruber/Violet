.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x937a8c
ow_script_0x937a8c:
lock
faceplayer
checkflag POKEDEX_FEATURE_HABITAT
gotoif EQUAL ow_script_0x937c8a
loadpointer 0x0 str_0x937bb1
callstd MSG_KEEPOPEN
setvar 0x8004 0x1
special2 0x800d 0xd4
buffernumber 0x2 0x8006
compare 0x8006 25
gotoif LESS ow_script_0x8f3bfd
sound 0x15
applymovement 0x800f ow_script_movs_0x8f3bfa
waitmovement 0x0
loadpointer 0x0 str_0x937ae9
callstd MSG_KEEPOPEN
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x937b72
callstd MSG_KEEPOPEN
lock
faceplayer
waitfanfare
lock
faceplayer
setflag POKEDEX_FEATURE_HABITAT
goto ow_script_0x937c8a


.global ow_script_0x937c8a
ow_script_0x937c8a:
lock
faceplayer
loadpointer 0x0 str_0x9381b7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93814a
loadpointer 0x0 str_0x937ed4
callstd MSG_FACE
end


.global ow_script_0x93814a
ow_script_0x93814a:
loadpointer 0x0 str_0x938154
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x937bb1

str_0x937bb1:
    .string "Hallo, ich bin ein Assistent\nProfessor Tanns. Ich helfe\lTrainern, die den Pokedex haben,\lbei der Vervollständigung der\lDaten.\lWenn du 25 verschiedene Pokémon im\lPokedex registriert hast, erhältst\ldu eine Belohnung."
        
        
.global str_0x937ae9

str_0x937ae9:
    .string "Sehr gut, du hast bereits\nBUFFER_3 verschiedene Pokémon\lregistriert.\pAls Belohnung werde ich deinem\nPokédex die Habitat-Funktion\lhinzufügen."
        
        
.global str_0x937b72

str_0x937b72:
    .string "Der Pokédex von PLAYER wurde\num die Habitats-Funktion\lerweitert!"
        
        
.global str_0x9381b7

str_0x9381b7:
    .string "Soll ich dir erklären, wie man die\nHabitats-Funktion benutzt?"
        
        
.global str_0x937ed4

str_0x937ed4:
    .string "Wenn du dir den Pokédex-Eintrag zu\neiner bestimmten Spezies ansiehst,\lkannst mithilfe von KEY_A\ldie Habitate der Spezies\lbetrachten.\lDiese leuchten rot auf. Wenn du\lmit dem Cursor auf eines der\lGebiete gehst, wird dir angezeigt,\lwie häufig die Spezies dort\lanzutreffen ist.\pJe größer der Kreis, desto höher\ndie Wahrscheinlichkeit dem Pokémon\lzu begegnen.\lPokémon in Höhlen werden ebenfalls\ldem Gras-Reiter zugeordnet.\pDer Angel-Reiter zeigt an, ob das\nPokémon mit der Angel, Profiangel\loder Superangel zu finden ist.\pDurch die Habitat-Funktion findest\ndu sicherlich jedes Pokémon!\pDu wirst Professor Tann eine große\nHilfe sein!"
        
        
.global str_0x938154

str_0x938154:
    .string "Komm jederzeit wieder, wenn du\nHilfe brauchst, die\lHabitats-Funktion deines Pokédex\lzu benutzen."
        
        
.elseif LANG_EN

.endif
