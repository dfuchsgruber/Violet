.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_7_person_0
.global ow_script_route_7_person_1
.global ow_script_route_7_person_smoke_ball
.global ow_script_route_7_person_2
.global ow_script_route_7_person_3
.global ow_script_route_7_person_4

ow_script_route_7_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_7_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_7_person_smoke_ball:
    checkflag FLAG_ROUTE_7_SMOKE_BALL
    gotoif EQUAL smoke_ball_done
    lock
    faceplayer
    loadpointer 0 str_smoke_ball_give
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_RAUCHBALL
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL smoke_ball_no_space
    setflag FLAG_ROUTE_7_SMOKE_BALL
smoke_ball_done:
    loadpointer 0 str_smoke_ball_done
    callstd MSG_FACE
    end
smoke_ball_no_space:
    loadpointer 0 str_no_space
    callstd MSG_FACE
    end
ow_script_route_7_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_7_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_7_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wusstest du, dass Lucius höchstpersönlich hier in der Nähe ein Schloss bewohnt?\pEr ist wirklich ein beeindruckender Mann."
str_1:
    .autostring 34 2 "Die Laz. Corp hat ein Feldlabor so weit draußen.\pDiese Firma gibt wirklich alles!"
str_smoke_ball_give:
    .autostring 34 2 "Ich bin total fasiziniert von dem Rauch, der aus der Lava aufsteigt.\pHier, das möchte ich dir geben, um auch deine Begeisterung zu wecken."
str_smoke_ball_done:
    .autostring 34 2 "Mit dem Rauchball kannst du einen Moment Verwirrung stiften und jedem noch so schwierigen Kampf entkommen."
str_no_space:
    .autostring 34 2 "Oh, es sieht so aus, als hättest du gar keinen Platz dafür!\pKomm wieder, wenn du Platz in deinem Beutel hast."
str_2:
    .autostring 34 2 "Hast du schon von Geheimpower gehört?\pDamit kannst du versteckte Areale erkunden.\pIch finde das sehr spannend."
str_3:
    .autostring 34 2 "Als Käfersammler hat man in der Nähe eines inaktiven Vulkans nicht sonderlich viel GlückDOTS"
str_4:
    .autostring 34 2 "Ich vermisse die alten ZeitenDOTS\pFrüher, als man zu Leuten wie dem Pinken Faun voller Aufregung aufgesehen hatDOTS\pUnd wen haben wir heute?\pWir kennen nicht einmal den Namen unseres neuen ChampionsDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Did you know, that Lucius himself lives in a castle nearby?\pHe really is an impressive man."
str_1:
    .autostring 34 2 "The Laz. Corp has a field laboratory this far out.\pThe company really gives it all."
str_smoke_ball_give:
    .autostring 34 2 "I am most fascinated by the smoke that rises from the lava.\pHere, I want to give you this to get you excited about this as well."
str_smoke_ball_done:
    .autostring 34 2 "The smoke ball allows you to create a brief moment of confusion which you can use to escape the most difficult situation."
str_no_space:
    .autostring 34 2 "Oh, it looks like you don't have space for that!\pYou can come to once you have made room in your bag."
str_2:
    .autostring 34 2 "Did you hear of Secret Power?\pWith that you can explore hidden areals.\pI think that's very exciting."
str_3:
    .autostring 34 2 "You won't find many Pokémon nearby an inactive vulcano if you are a bug catcherDOTS"
str_4:
    .autostring 34 2 "I miss the old timesDOTS\pBack then, when you could look up to folks like the Pink Faun, filled with excitementDOTS\pAnd who do we have nowadays?\pWe don't even know the name of our champDOTS"


.endif