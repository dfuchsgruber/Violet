.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8ef7d5
ow_script_0x8ef7d5:
loadpointer 0x0 str_0x8f45a3
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f45a3

str_0x8f45a3:
    .string "Wenn eines meiner Pokémon die\nAttacke Surfer beherrschen würde,\lkönnte ich diesen Fluss nach\lKaskada hinaufschwimmen."
        
        
.elseif LANG_EN

.endif
