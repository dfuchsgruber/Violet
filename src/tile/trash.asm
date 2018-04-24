.include "overworld_script.s"
.include "vars.s"

.global trash_script

trash_script:
compare 0x8000 0x0
gotoif 1 empty
copyvarifnotzero 0x8001 1
callstd 0
compare LASTRESULT 0x0
gotoif 1 nospace
special 0x17
closeonkeypress
end

empty:
loadpointer 0 str_trash_empty
callstd 0x3
end

nospace:
lock
faceplayer
loadpointer 0 str_trash_full
callstd 0x6
release
end

.ifdef LANG_GER

	str_trash_empty:
		.string "Der Mülleimer ist leer."

	str_trash_full:
		.string "Sieht so aus, als hättest du für\nBUFFER_2 keinen Platz!\pKomm wieder, wenn du das Item\naufnehmen kannst."

.elseif LANG_EN
.endif
