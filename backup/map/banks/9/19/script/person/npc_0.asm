.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laz_corp_secret_power_lab_npc0
ow_script_laz_corp_secret_power_lab_npc0:
loadpointer 0 str
callstd MSG_FACE
end

.ifdef LANG_GER

str:
	.autostring 35 2 "Ich befasse mich mit dem Einsatz von Geheimpower auf dem Meer.\pOft findet man eine seltsame Felsenformation, welche man dann mit Geheimpower überwinden kann."

.elseif LANG_EN

.endif
