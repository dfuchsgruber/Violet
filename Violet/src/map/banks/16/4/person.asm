.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_map_16_4_person_0
.global ow_script_0x937886

ow_script_map_16_4_person_0:
checkflag ROUTE_4_HM_FLY
gotoif EQUAL ow_script_0x937886
lock
faceplayer
loadpointer 0x0 str_0x937a0a
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_VM02
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x937917
callstd MSG_KEEPOPEN
closeonkeypress
setflag ROUTE_4_HM_FLY
end


ow_script_0x937886:
loadpointer 0x0 str_0x937890
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x937a0a:
    .string "Was? Du hast mein geheimes Haus\nentdeckt? Unmöglich!\pBitte sag niemandem hiervon!\nNimm das als Gegenleistung für\ldein Schweigen."



str_0x937917:
    .string "Diese Versteckte Maschine enthält\nFliegen, einen Flug-Angriff.\lUm ihn außerhalb des Kampfes zu\lbenutzen, benötigst du jedoch den\lOrden von Blütenbach.\lManus, der Arenaleiter, soll ein\lharter Brocken seinDOTS\lEr darf dieses Haus nie finden!"



str_0x937890:
    .string "Dieses Haus habe ich gebaut, um\nmeine Ruhe zu haben.\lRuhe vor den Top Vier, Ruhe vor\lden Arenaleitern.\pNiemand darf je davon wissen!"


.elseif LANG_EN

.endif