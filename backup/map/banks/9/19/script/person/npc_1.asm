.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laz_corp_secret_power_lab_npc1
ow_script_laz_corp_secret_power_lab_npc1:
loadpointer 0 str
callstd MSG_FACE
end

.ifdef LANG_GER

str:
	.autostring 35 2 "Ursprünglich wurde Geheimpower verwendet, um geeignete Plätze für Geheimbasen zu erreichen.\pWir haben das volle Potenzial dieser Technik erkannt und sie weiterentwickelt!"

.elseif LANG_EN

.endif
