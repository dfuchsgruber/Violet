.include "overworld_script.s"
.include "std.s"

.global ow_script_botogel

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
.global str_ow_script_botogel_0

str_ow_script_botogel_0:
    .string "Botogel! Botogel!"
        
        
.global str_ow_script_botogel_1

str_ow_script_botogel_1:
    .string "Hihi! Das Botogel scheint dich zu\nmögen.\pWeißt du, Botogel ist ein sehr\ngroßzügiges Pokémon. Es hat\lunheimlichen Spaß am Verschenken.\pWenn du ihm einen gültigen\nGeschenkcode sagst, wird es dir\letwas geben.\pWeil das Botogel dich zu\nmögen scheint, werde ich dir einen\lCode verraten.\pVersuch es mit BOTOGEL\nund achte stets auf die richtige\lGroß- und Kleinschreibung."
        
        
.global str_ow_script_botogel_2

str_ow_script_botogel_2:
    .string "Botogel! Botogel?"
        
        
.global str_ow_script_botogel_3

str_ow_script_botogel_3:
    .string "Oh tut mir leid! Sieht so aus, als\nwäre der Code ungültig.\pBist du dir sicher, dass du alles\nkorrekt geschrieben hast?"
        
        
.elseif LANG_EN

.endif
