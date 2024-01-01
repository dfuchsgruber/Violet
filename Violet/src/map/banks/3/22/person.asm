.include "callstds.s"
.include "overworld_script.s"
.include "ordinals.s"
.include "vars.s"
.include "songs.s"
.include "cutscenes.s"
.include "specials.s"
.include "pathfinding.s"
.include "flags.s"

.global ow_script_route_4_person_0
.global ow_script_route_4_person_1
.global ow_script_route_4_person_2
.global ow_script_route_4_person_3
.global ow_script_route_4_person_4
.global ow_script_route_4_person_5
.global ow_script_route_4_person_6
.global ow_script_route_4_person_7
.global ow_script_route_4_person_8
.global ow_script_route_4_person_9
.global ow_script_route_4_person_10
.global ow_script_route_4_painter

ow_script_route_4_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_4_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_4_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_4_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_4_person_4:
    loadpointer 0 str_4
    callstd MSG
    end
ow_script_route_4_person_5:
    loadpointer 0 str_5
    callstd MSG
    end
ow_script_route_4_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_route_4_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_route_4_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end
ow_script_route_4_person_9:
    loadpointer 0 str_9
    callstd MSG_FACE
    end
ow_script_route_4_person_10:
    loadpointer 0 str_10
    callstd MSG_FACE
    end
ow_script_route_4_painter:
    lock
    faceplayer
    loadpointer 0 str_painter_0
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL painter_no
    closeonkeypress
    applymovement LASTTALKED mov_fu
    waitmovement 0
    playsong MUS_TANN_SPEECH 0
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0x16
    setvar 0x8005 0x53
    setvar 0x8006, A_STAR_SPEED_SLOW
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    setvar 0x8004 CUTSCENE_ELITE_FOUR_FOUNDERS
    special SPECIAL_CUTSCENE_SHOW
    waitstate
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0xFF
    special SPECIAL_PERSON_GET_POSITION
    setvar 0x8006, A_STAR_SPEED_SLOW
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    copyvar 0x8004 LASTTALKED
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    lock
    faceplayer
	trainerbattlecont 0x1 0x1ca 0 str_painter_1 str_painter_after painter_continuation
painter_continuation:
    lock
    faceplayer
    loadpointer 0 str_painter_2
    callstd MSG_KEEPOPEN
    fanfare 258
    loadpointer 0 str_got_wallpaper
    callstd MSG_KEEPOPEN
    waitfanfare
painter_done:
    loadpointer 0 str_painter_3
    callstd MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_POKEPAD_WALLPAPER_LEGENDS
    release
    end


painter_no:
    loadpointer 0 str_painter_no
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    end

.ifdef LANG_GER
str_painter_0:
    .autostring 34 2 "Ich bin eine Malerin aus Blütenbach.\pEigentlich wollte ich hier die Landschaft malen, aber mir geht ein Motiv nicht mehr aus dem KopfDOTS\pSoll ich dir erzählen, was mich beschäftigt?"
str_painter_1:
    .autostring 34 2 "Diese dreiDOTS\pSie haben diese Region geprägt wie niemand sonst.\pIch habe sie oft gemalt, aber das Motiv verliert für mich seinen Reiz überhaupt nicht.\pIch schlage dir etwas vor.\pVielleicht bringt mich ein Kampf auf andere Ideen.\pWenn du mich besiegen kannst, gebe ich dir eines meiner Bilder!"
str_painter_after:
    .autostring 34 2 "Ich habe dich unterschätzt!\pWas für ein inspirierender Kampf!"
str_painter_2:
    .autostring 34 2 "Unglaublich!\pEinen solchen Kampf, muss man auf die Leinwand bringen!\pWie abgemacht, erhältst du eines meiner Bilder als Belohnung."
str_got_wallpaper:
    .autostring 34 2 "PLAYER erhält ein Poképad-Motiv!\pEs zeigt die drei Gründer der Pokémon-Liga."
str_painter_3:
    .autostring 34 2 "Das Bild der drei Gründer der Pokémon-Liga ist mein großes Meisterwerk.\pIch hoffe, es macht dir Freude.\pIch widme mich jetzt neuen MotivenDOTS"
str_painter_no:
    .autostring 34 2 "Schade, ich hätte dir eine spannende Geschichte erzähltDOTS"
str_0:
    .autostring 34 2 "Der Osten Thetos gefällt mir am Besten.\pHier ist die Landschaft einfach malerisch, findest du nicht?"
str_1:
    .autostring 34 2 "Auf dieser Route trifft man viele Trainer mit Kampf-Pokémon.\pDie meisten von ihnen trainieren, um entweder mit Manuel, dem Arenaleiter von Blütenbach, zu trainieren oder ihn herauszufordern."
str_2:
    .autostring 34 2 "Mein Karnimani liebt es, in diesem Fluss zu planschen.\pAlso komme ich fast jeden Tag mit ihm hierher."
str_3:
    .autostring 34 2 "Ich habe schon öfter gesehen, dass irgendetwas im Himmel einen Schatten auf den Boden wirft.\pIch frage mich, was es damit auf sich hatDOTS"
str_4:
    .autostring 34 2 "Wie oft soll ich es dir noch sagen?\pWenn wir ihn Manuels Arena aufgenommen werden wollen, müssen wir an unseren Tritten arbeiten!"
str_5:
    .autostring 34 2 "Du hast doch überhaupt keine Ahnung!\pWenn wir unsere Schlagtechnik nicht verbessern, werden wir niemals in Manuels Arena kommen!"
str_6:
    .autostring 34 2 "Mein ganzes Leben lang habe ich hart geschuftetDOTS\pJetzt bin ich froh, meinen Lebensabend an einem so wundervollen Ort verbringen zu können."
str_7:
    .autostring 34 2 "Ich komme hier oft zum Beerenpflücken her.\pIch habe die Vermutung, dass das saubere Flusswasser den Beeren hier beim Wachsen hilft.\pZumindest sehen die Beerensträucher hier stets kerngesund aus."
str_8:
    .autostring 34 2 "Sind dir die Revolutionäre ein Begriff?\pDieses ungehobelte Pack ist eben hier vorbeigekommen.\pHalten sich wohl für etwas Besseres, diese Unruhestifter mit ihren grünen RobenDOTS"
str_9:
    .autostring 34 2 "Ich habe die beste große Schwester auf der ganzen Welt!\pWir gehen nämlich oft zusammen Blütensammeln!"
str_10:
    .autostring 34 2 "Mein kleiner Bruder ist ganz verrückt danach, in Blütenbach Kirschblüten zu sammelnDOTS\pUnd meine Eltern haben mich dazu degradiert, ihn dabei zu begleitenDOTS"
.elseif LANG_EN
.endif