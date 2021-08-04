.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"
.include "movements.s"

.global ow_script_route_2_scientist
.global ow_script_route_2_east_npc_0
.global ow_script_route_2_east_npc_1
.global ow_script_route_2_east_npc_2
.global ow_script_route_2_east_abra_doll_girl

ow_script_route_2_east_abra_doll_girl:
	checkflag FLAG_ROUTE_2_ABRA_DOLL_QUEST_REWARD_RECEIVED
	gotoif EQUAL abra_doll_done
	lockall
	faceplayer
	loadpointer 0 str_abra_doll_lost
	callstd MSG
	checkitem ITEM_ABRA_PUPPE 1
	compare LASTRESULT 0x1
	gotoif 1 give_abra_doll
	release
	end
give_abra_doll:
	sound 0x15
	applymovement LASTTALKED mov_exclam
	waitmovement 0
	checksound
	pause 16
	loadpointer 0 str_found_abra_doll
	callstd MSG_KEEPOPEN
	fanfare 0x13e
	lockall
	loadpointer 0 str_hand_over_abra_doll
	callstd MSG_KEEPOPEN
	waitfanfare
	setflag FLAG_ROUTE_2_ABRA_DOLL_QUEST_REWARD_RECEIVED
	loadpointer 0 str_abra_doll_reward
	callstd MSG
attempt_to_give_reward:
	lock
	copyvarifnotzero 0x8000 ITEM_SONDERBONBON
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
	compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
	loadpointer 0 str_after_receive_reward
	callstd MSG
	sound 39
	applymovement LASTTALKED mov_teleport_away
	waitmovement 0
	checksound
	hidesprite LASTTALKED
	setflag FLAG_MART_SELLS_ABRA_DOLL
	releaseall
	end

abra_doll_done:
	loadpointer 0 str_abra_doll_done
	callstd MSG_FACE
	goto attempt_to_give_reward

mov_teleport_away:
	.byte 164, STOP

.ifdef LANG_GER
str_after_receive_reward:
	.autostring 34 2 "Jetzt kann ich endlich wieder mit meiner Abra-Puppe spielen.\pSchau mal!\nWenn ich sie ganz doll knuddleDOTS"
str_abra_doll_reward:
	.autostring 34 2 "Das ist wirklich total lieb von dir!\pEndlich habe ich meine Puppe wieder.\pIch möchte dir als Dank das hier geben."
str_abra_doll_lost:
	.autostring 34 2 "Buhu! Wähhh!\pIch bin so traurig.\pIch habe meine Abra-Puppe beim Spielen verlorenDOTS\pIrgendwo hier muss sie doch seinDOTS"
str_hand_over_abra_doll:
	.autostring 34 2 "PLAYER übergibt die Abra-Puppe."
str_found_abra_doll:
	.autostring 34 2 "W-Was ist das denn?\pJa, das ist sie!\nDu hast meine Abra-Puppe gefunden."
str_abra_doll_done:
	.autostring 34 2 "Hey!\nWillst du dir mein Geschenk abholen?\pGerne doch!"
.elseif LANG_EN
.endif

ow_script_route_2_east_npc_0:
loadpointer 0 str1
callstd MSG_FACE
end

.ifdef LANG_GER

str1:
	.autostring 35 2 "Route 2 gilt als eine der längsten Routen Thetos.\pSie ist ein zentraler Knotenpunkt dieser Region, da man in alle Himmelsrichtungen angebunden ist."

.elseif LANG_EN
str1:
	.autostring 34 2 "Route 2 is said to be one of the longest routes in Theto.\pIt is a central hub of this region, since you are connected in each direction."
.endif

ow_script_route_2_east_npc_1:
loadpointer 0 str2
callstd MSG_FACE
end


.ifdef LANG_GER

str2:
	.autostring 35 2 "Irgendwo hier auf Route 2 hat Professor Tann sein Labor.\pEr ist Archäologe und das Museum in Orina City hat ihm bereits viele Ausstellungsstücke zu verdanken."
.elseif LANG_EN
str2:
	.autostring 34 2 "Somewhere here on Route 2 Professor Fig has his laboratory.\pHe is an archeologist and most of the exhibition in the Orina City Museum is due to him."
.endif

ow_script_route_2_east_npc_2:
loadpointer 0 str3
callstd MSG_FACE
end


.ifdef LANG_GER

str3:
	.autostring 35 2 "Ich finde es spannend, durch Versteckte Maschinen geheime Areale zu erkunden!\pMeinst du nicht auch, dass das aufregend ist?"

.elseif LANG_EN
str3:
	.autostring 34 2 "I think it is very exciting to explore areas using Hidden Machines.\pDon't you think so too?"
.endif
