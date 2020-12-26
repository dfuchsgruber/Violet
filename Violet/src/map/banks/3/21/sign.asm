.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"
.include "callstds.s"
.include "unown_messages.s"
.include "vars.s"
.include "map_adjacency_types.s"
.include "map_connections.s"
.include "species.s"
.include "items.s"

.global ow_script_felsige_oednis_regirock_cave_entrance
.global ow_script_felsige_oednis_desert_sign_0
.global ow_script_felsige_oednis_desert_sign_1
.global ow_script_felsige_oednis_desert_sign_2

ow_script_felsige_oednis_desert_sign_0:
    loadpointer 0 str_sign0
    callstd MSG_SIGN
    end
ow_script_felsige_oednis_desert_sign_1:
    loadpointer 0 str_sign1
    callstd MSG_SIGN
    end
ow_script_felsige_oednis_desert_sign_2:
    loadpointer 0 str_sign2
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_sign0:
    .autostring 34 2 "UP_ARROW Felsige Ödnis\pAchtung\nDunkel!"
str_sign1:
    .autostring 34 2 "UP_ARROW Tafelberg\pAchtung\nDunkel!"
str_sign2:
    .autostring 34 2 "Expeditionszelt von Professor Tann."
.elseif LANG_EN
.endif

ow_script_felsige_oednis_regirock_cave_entrance:
    lock
    checkflag FLAG_REGIROCK_CAVE_OPENED
    gotoif EQUAL opened
    setvar 0x8004 UNOWN_MESSAGE_ROCK
    special SPECIAL_UNOWN_MESSAGE_PRINT
    waitstate
    special SPECIAL_UNOWN_MESSAGE_REMOVE
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_SPELLS_UNOWN_MESSAGE
    compare LASTRESULT 0
    gotoif EQUAL end_script
    setvar 0x8004 0x2
    setvar 0x8005 0x2
    setvar 0x8006 0xA
    setvar 0x8007 0x3
    special SPECIAL_EARTHQUAKE
    pause 0x3C
    setvar 0x8004 0x3
    setvar 0x8005 0x3
    setvar 0x8006 0xC
    setvar 0x8007 0x2
    special SPECIAL_EARTHQUAKE
    pause 0x3C
    call ow_script_felsige_oednis_open_regirock_cave
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 0x21
    checksound
    setflag FLAG_REGIROCK_CAVE_OPENED
    goto opened
end_script:
    release
    end

opened:
    loadpointer 0 str_0
    callstd MSG_SIGN
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ein Höhleneingang ist erschienen!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "A cave entrance has appeared!"
.endif

.global ow_script_map_3_21_sign_1
.global ow_script_map_3_21_sign_0
.global ow_script_0x8ffcc2
.global ow_script_0x926c09
.global ow_script_0x8ffc8a
.global ow_script_0x8ffcbb

ow_script_map_3_21_sign_0:
    loadpointer 0x0 str_0x926b0a
    callstd MSG_SIGN
    end

fadescreen 0x1
fanfare 0x100
waitfanfare
fadescreen 0x0
special SPECIAL_HEAL
loadpointer 0x0 str_0x926b6d
callstd MSG
end


.ifdef LANG_GER

str_0x926b0a:
    .autostring 34 2 "Ein Brunnen!\nVielleicht finde ich im Inneren des Zeltes etwas zu trinkenDOTS\pDas dürfte meinen Pokémon wieder auf die Beine helfen."
    //.string "Ein Brunnen! Das frische Wasser\nwird den erschöpften Pokémon\lhelfen."



str_0x926b6d:
    .string "Die Pokémon von PLAYER wurden\nvollständig geheilt."


.elseif LANG_EN

.endif


ow_script_map_3_21_sign_1:
loadpointer 0x0 str_0x926b9d
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8ffcc2
random 0x4
compare LASTRESULT 0x1
gotoif LESS_OR_EQUAL ow_script_0x926c09
random 0x19
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8ffc8a
setwildbattle POKEMON_TUSKA 0x19 ITEM_NONE
dowildbattle
end


ow_script_0x8ffc8a:
random 0x3
compare LASTRESULT 0x1
callif EQUAL ow_script_0x8ffcbb
setwildbattle POKEMON_NOKTUSKA 0x1e ITEM_NONE
dowildbattle
setvar NEXT_POKEMON_SHINY 0x0
end


ow_script_0x8ffcbb:
setvar NEXT_POKEMON_SHINY 0x1
return


ow_script_0x926c09:
loadpointer 0x0 str_0x926c53
callstd MSG
end


ow_script_0x8ffcc2:
loadpointer 0x0 str_0x926beb
callstd MSG
end


.ifdef LANG_GER

str_0x926b9d:
    .string "Der Katkus schimmert golden in der\nWüstensonne. Möchtest du an ihm\lrütteln?"



str_0x926c53:
    .string "Nichts passiertDOTS"



str_0x926beb:
    .string "PLAYER lässt den Kaktus in\nRuhe."


.elseif LANG_EN

.endif