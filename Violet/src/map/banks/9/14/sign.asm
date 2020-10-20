.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_9_14_sign_0

ow_script_map_9_14_sign_0:
loadpointer 0x0 str_0x95c862
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95c862:
    .string "Herzlich willkommen bei der\nLaz.Corp.\pUnser Motto lautet: Wir machen\nZukunft zur Gegenwart."


.elseif LANG_EN

.endif