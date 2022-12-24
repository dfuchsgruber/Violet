.include "overworld_script.s"
.include "vars.s"
.include "callstds.s"

.global ow_script_trash

ow_script_trash:
	loadpointer 0 str_trash_empty
	callstd 0x3
	end

.ifdef LANG_GER

	str_trash_empty:
		.string "Der Mülleimer ist leer."

.elseif LANG_EN
.endif
