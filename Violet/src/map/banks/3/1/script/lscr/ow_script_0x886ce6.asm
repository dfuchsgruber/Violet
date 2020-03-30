.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "songs.s"
.include "overworld_script.s"


.global ow_script_0x886ce6
ow_script_0x886ce6:
goto ow_script_0x88abb8


.global ow_script_movs_0x8a136f
ow_script_movs_0x8a136f:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_NORTH_EAST
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a133b
ow_script_movs_0x8a133b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_NORTH_EAST

.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT

.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888e47
ow_script_movs_0x888e47:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a13a1
ow_script_movs_0x8a13a1:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x88abb8
ow_script_0x88abb8:
lockall
loadpointer 0x0 str_0x886d49
callstd MSG
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
applymovement 0x2 ow_script_movs_0x8a136f
applymovement 0xff ow_script_movs_0x8a133b
waitmovement 0x0
loadpointer 0x0 str_0x888a45
callstd MSG
applymovement 0x2 ow_script_movs_0x888e47
waitmovement 0x0
fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
loadpointer 0x0 str_0x888cd2
callstd MSG
applymovement 0x2 ow_script_movs_0x8a13a1
waitmovement 0x0
hidesprite 0x2
setvar STORY_PROGRESS 0xb
releaseall
end


.ifdef LANG_GER
.global str_0x886d49

str_0x886d49:
    .string "Einen letzten Ort solltest du als\nTrainer noch unbedingt kennen.\lFolge mir einfach wie bisher!"
        
        
.global str_0x888a45

str_0x888a45:
    .string "Das ist eine Pokémon-Arena. In\nganz Theto gibt es acht davon.\lJede von ihnen hat einen\lArenaleiter, der nicht nur sehr\lstark ist, sondern sich auch auf\lden Kampf mit einem bestimmten\lPokémon-Typen versteht. Der\lArenaleiter dieser Stadt, Manus,\lbeispielsweise ist auf\lKampf-Pokémon spezialsiert. Soviel\lich weiß, ist er jedoch außer Haus\lund repariert den Durchgang im\lWassertunnel, der kürzlich bei\leinem Erdbeben eingestürzt ist.\lBesiegst du einen Arenaleiter, so\lerhältst du einen Arena-Orden.\lSammle alle acht Orden ein, und du\ldarfst dich zu den besten\lTrainern überhaupt zählen. Jeder\lTrainer sollte das Ziel haben,\lalle Orden einzusammeln."
        
        
.global str_0x888cd2

str_0x888cd2:
    .string "Diese Orte solltest du als\nPokémon-Trainer auf jeden Fall\lkennen und auch nutzen. Du\lbrauchst mir für meine Hilfe nicht\lzu danken, ich habe gerne Anteil\lam Glück anderer. Viel Glück auf\ldeiner Reise, ich habe bereits\lzuvor gemerkt, dass du das gewisse\lEtwas hast, das ein\lPokémon-Trainer braucht."
        
        
.elseif LANG_EN

.endif
