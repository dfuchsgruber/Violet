.include "ordinals.s"
.include "vars.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_5_4_sign_1
.global ow_script_map_5_4_sign_0
.global ow_script_botogel

ow_script_map_5_4_sign_0:
loadpointer 0x0 str_0x8772e2
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8772e2:
    .string "Dieses Feature ist in der Version\nnoch nicht implementiert."


.elseif LANG_EN

.endif


ow_script_mart0x95dfe9:
.hword ITEM_NONE


ow_script_map_5_4_sign_1:
setflag TRANS_DISABLE
lock
faceplayer
preparemsg str_mart_ask
waitmsg
pokemart3 ow_script_mart0x95dfe9
loadpointer 0x0 str_mart_exit
callstd MSG_KEEPOPEN
clearflag TRANS_DISABLE
release
end


ow_script_botogel:
    lock
    checkflag PRESENT_INTRODUCED
    gotoif 0 introduce
query:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_2
    callstd 4
    waitcry
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    special 0x4A
    waitstate
    lock
    clearflag TRANS_DISABLE
    compare LASTRESULT 1
    gotoif EQUAL receive_present
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    loadpointer 0 str_ow_script_botogel_3
    callstd 6
    release
    end

receive_present:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    jumpram
    end

introduce:
    cry POKEMON_BOTOGEL 0
    loadpointer 0 str_ow_script_botogel_0
    callstd 4
    waitcry
    loadpointer 0 str_ow_script_botogel_1
    callstd 6
    setflag PRESENT_INTRODUCED
    goto query



.ifdef LANG_GER

str_ow_script_botogel_0:
    .string "Botogel! Botogel!"



str_ow_script_botogel_1:
    .string "Hihi! Das Botogel scheint dich zu\nmögen.\pWeißt du, Botogel ist ein sehr\ngroßzügiges Pokémon. Es hat\lunheimlichen Spaß am Verschenken.\pWenn du ihm einen gültigen\nGeschenkcode sagst, wird es dir\letwas geben.\pWeil das Botogel dich zu\nmögen scheint, werde ich dir einen\lCode verraten.\pVersuch es mit BOTOGEL\nund achte stets auf die richtige\lGroß- und Kleinschreibung."



str_ow_script_botogel_2:
    .string "Botogel! Botogel?"



str_ow_script_botogel_3:
    .string "Oh tut mir leid! Sieht so aus, als\nwäre der Code ungültig.\pBist du dir sicher, dass du alles\nkorrekt geschrieben hast?"


.elseif LANG_EN

.endif