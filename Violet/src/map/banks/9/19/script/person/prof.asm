.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "ordinals.s"

.global ow_script_laz_corp_secret_power_lab_prof
ow_script_laz_corp_secret_power_lab_prof:
lock
faceplayer
checkflag PLAYER_CAN_ENTER_DUNGEONS
gotoif EQUAL done
loadpointer 0 str_forscher
setvar 0x8000 0
special 0xE
loadpointer 0 str_intro
callstd MSG_KEEPOPEN
special 0xF
copyvarifnotzero 0x8000 ITEM_TM43
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
setflag PLAYER_CAN_ENTER_DUNGEONS
done:
loadpointer 0 str_forscher
setvar 0x8000 0
special 0xE
loadpointer 0 str_outro
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER

str_forscher:
	.string "Forscher"

str_intro:
	.autostring 35 2 "Ah, willkommen, junger Trainer!\pMeine Forschungsgruppe forscht hier in der Laz.Corp daran, verborgene Areale mittels der Technischen Maschine Geheimpower freizulegen.\pHast du nicht auch schon oft irgendwo lichtes Unterholz, schmale Höhleneingänge oder seltsame Felsformationen im Meer gesehen?\pHinter diesen verbergen sich oft scheinbar unerreichbare Gebiete.\pWir hier haben allerdings einen Weg gefunden, wie man diese Orte als Trainer trotzdem erreichen kann.\pLass mich dir ein Exemplar der Technischen Maschine Geheimpower anvertrauen."

str_outro:
	.autostring 35 2 "Benutze Geheimpower, wann immer du Lücken im Unterholz, kleine Risse in Felswänden oder seltsame Felsenformationen auf dem Meer entdeckst.\pOft verstecken sich in den Arealen, die du mit Geheimpower erkunden kannst, seltene Pokémon!\pIch denke, dass wir hier erstaunliche Arbeit geleistet haben, aus Geheimpower so einen Nutzen zu ziehen, meinst du nicht auch?"

.elseif LANG_EN

.endif
