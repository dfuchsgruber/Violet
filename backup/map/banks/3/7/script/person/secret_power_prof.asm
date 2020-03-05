.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "items.s"

.global ow_script_route_2_scientist
ow_script_route_2_scientist:
lock
faceplayer
loadpointer 0 str_forscher
setvar 0x8000 0
special 0xE
loadpointer 0 str_intro
callstd MSG_KEEPOPEN
checkitem ITEM_ZUGANGSKARTE 1
compare LASTRESULT 0x1
gotoif EQUAL has_card
loadpointer 0 str_no_card
callstd MSG
special 0xF
release
end

has_card:
closeonkeypress
special 0xF
fanfare 0x13E
setflag SECRET_POWER_LAB_ACCESS
loadpointer 0 str_got
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0 str_forscher
setvar 0x8000 0
special 0xE
loadpointer 0 str_outro
callstd MSG
special 0xF
fadescreen 1
hidesprite LASTTALKED
fadescreen 0
release
end


.ifdef LANG_GER

str_forscher:
	.string "Forscher"

str_intro:
	.autostring 35 2 "Hallo, junger Trainer!\pIch bin ein Mitarbeiter der Laz.Corp.\pHast du dich je gefragt, was jenseits der dichten Wälder, hohen Berge und starken Meeresströmungen liegt, welche man abseits der Routen findet?\pMeine Forschungsgruppe arbeitet an einer Möglichkeit, noch mehr Gebiete zugänglich zu machen.\pKomm mich doch in der Laz.Corp einmal besuchen und ich erkläre dir, was ich damit meine.\pLass mich deiner Zugangskarte die entsprechenden Berechtigungen hinzufügen DOTS"

str_no_card:
	.autostring 35 2 "Oh, du besitzt ja gar keine Zugangskarte!\pWie schade aber auch!\pSolltest du jemals in den Besitz einer Zugangskarte für die Laz.Corp gelangen, kannst du einfach wieder zu mir kommen.\pDu weißt ja, wo du mich findest!"

str_got:
	.autostring 35 2 "PLAYER hat nun Zugang zum Geheimpower-Labor der Laz.Corp!"

str_outro:
	.autostring 35 2 "Prima!\pIch freue mich schon, wenn wir uns in der Laz.Corp wiedersehen!"

.elseif LANG_EN

.endif
