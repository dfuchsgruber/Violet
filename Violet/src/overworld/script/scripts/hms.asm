.include "ordinals.s"
.include "vars.s"
.include "attacks.s"
.include "move_tutor.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_cut_tree
.global ow_script_rock_smash

ow_script_cut_tree:
    special 0x187
    compare LASTRESULT 0x2
    gotoif EQUAL end_cut_tree
    lockall
    checkflag FRBADGE_2
    gotoif LESS cut_tree_no_cut_available
    checkattack ATTACK_ZERSCHNEIDER
    compare LASTRESULT 0x6
    gotoif EQUAL cut_tree_no_cut_available
    setanimation 0x0 0x800d
    bufferpartypokemon 0x0 0x800d
    bufferattack 0x1 ATTACK_ZERSCHNEIDER
    loadpointer 0x0 str_ask_cut
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL end_cut_tree_close_box
    loadpointer 0x0 str_use_move
    callstd MSG_KEEPOPEN
    closeonkeypress
    doanimation 0x2
    waitstate
    goto cut_tree_animation_and_hidesprite
cut_tree_animation_and_hidesprite:
    applymovement LASTTALKED mov_cut_tree
    waitmovement 0x0
    hidesprite LASTTALKED
    releaseall
    end

cut_tree_no_cut_available:
    loadpointer 0x0 str_cut_tree_no_cut_available
    callstd MSG_SIGN
    releaseall
    end

end_cut_tree_close_box:
    closeonkeypress
end_cut_tree:
    release
    end

mov_cut_tree:
    .byte 0x69, STOP


ow_script_rock_smash:
    special 0x187
    compare LASTRESULT 0x2
    gotoif EQUAL end_cut_tree
    lockall
    checkflag FRBADGE_6
    gotoif LESS rock_smash_not_avilable
    checkattack ATTACK_ZERTRUEMMERER
    compare LASTRESULT 0x6
    gotoif EQUAL rock_smash_not_avilable
    setanimation 0x0 0x800d
    bufferpartypokemon 0x0 0x800d
    bufferattack 0x1 ATTACK_ZERTRUEMMERER
    loadpointer 0x0 str_ask_rock_smash
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL end_cut_tree_close_box
    loadpointer 0x0 str_use_move
    callstd MSG_KEEPOPEN
    closeonkeypress
    doanimation 0x25
    waitstate
    goto rock_smash_animation_and_hidesprite


rock_smash_animation_and_hidesprite:
    applymovement LASTTALKED mov_rock_smash
    waitmovement 0x0
    hidesprite LASTTALKED
    waitstate
    releaseall
    end

rock_smash_not_avilable:
    loadpointer 0x0 str_rock_smash_not_avilable
    callstd MSG_SIGN
    end

mov_rock_smash:
    .byte 0x68, STOP



.ifdef LANG_GER
str_ask_cut:
    .autostring 34 2 "Du kannst den Zerschneider hier einsetzen!\pMöchtest du den Zerschneider einsetzen?"
str_cut_tree_no_cut_available:
    .autostring 34 2 "Der Zerschneider kann hier eingesetzt werden."
str_rock_smash_not_avilable:
    .autostring 34 2 "Ein großer Felsen.\nEin Pokémon könnte ihn vielleicht zertrümmern."
str_ask_rock_smash:
    .autostring 34 2 "Dieser Fels sieht zerbrechlich aus.\pSoll Zertrümmerer eingesetzt werden?"
str_use_move:
    .autostring 34 2 "BUFFER_1 setzt\nBUFFER_2 ein."
.elseif LANG_EN
str_ask_cut:
    .autostring 34 2 "Cut can be used to cut down this tree.\pDo you want to use cut?"
str_cut_tree_no_cut_available:
    .autostring 34 2 "Cut can be used to cut down this tree."
str_rock_smash_not_avilable:
    .autostring 34 2 "A large rock.\pA Pokémon might be able to smash it."
str_ask_rock_smash:
    .autostring 34 2 "This rock looks fragile.\pDo you want to use Rock Smash?"
str_use_move:
    .autostring 34 2 "BUFFER_1 uses\nBUFFER_2."
.endif