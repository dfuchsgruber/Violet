.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laz_corp_secret_power_lab_npc2
ow_script_laz_corp_secret_power_lab_npc2:
loadpointer 0 str
callstd MSG_FACE
end

.ifdef LANG_GER

str:
	.autostring 35 2 "Die Areale, die du mit Geheimpower erkunden kannst, entstehen komplett zufällig.\pDie Natur hat manchmal eigensinnige Launen!"

.elseif LANG_EN

.endif
