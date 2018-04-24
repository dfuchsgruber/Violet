.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x937859
ow_script_0x937859:
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


.global ow_script_0x937886
ow_script_0x937886:
loadpointer 0x0 str_0x937890
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x937a0a

str_0x937a0a:
    .string "Was? Du hast mein geheimes Haus\nentdeckt? Unmöglich!\pBitte sag niemandem hiervon!\nNimm das als Gegenleistung für\ldein Schweigen."
        
        
.global str_0x937917

str_0x937917:
    .string "Diese Versteckte Maschine enthält\nFliegen, einen Flug-Angriff.\lUm ihn außerhalb des Kampfes zu\lbenutzen, benötigst du jedoch den\lOrden von Meriana City.\lManus, der Arenaleiter, soll ein\lharter Brocken sein...\lEr darf dieses Haus nie finden!"
        
        
.global str_0x937890

str_0x937890:
    .string "Dieses Haus habe ich gebaut, um\nmeine Ruhe zu haben.\lRuhe vor den Top Vier, Ruhe vor\lden Arenaleitern.\pNiemand darf je davon wissen!"
        
        
.elseif LANG_EN

.endif
