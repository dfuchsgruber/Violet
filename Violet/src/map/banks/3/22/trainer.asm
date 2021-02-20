.include "callstds.s"
.include "overworld_script.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_4_trainer_0
.global ow_script_route_4_trainer_1
.global ow_script_route_4_trainer_2
.global ow_script_route_4_trainer_3
.global ow_script_route_4_trainer_4
.global ow_script_route_4_trainer_5
.global ow_script_route_4_trainer_6
.global ow_script_route_4_trainer_7
.global ow_script_route_4_trainer_8
.global ow_script_route_4_trainer_9
.global ow_script_route_4_trainer_10
.global ow_script_route_4_trainer_11
.global ow_script_route_4_trainer_12
.global ow_script_route_4_cook

ow_script_route_4_trainer_0:
    trainerbattledouble 0x4 0x16b 0 str_challange str_defeat str_one_poke
    loadpointer 0x0 str_defeat
    callstd MSG_FACE
    end
ow_script_route_4_trainer_1:
    trainerbattlestd 0x0 0x74 0x0 str_before_1 str_after_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_4_trainer_2:
    trainerbattlestd 0x0 0x76 0x0 str_before_2 str_after_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end
ow_script_route_4_trainer_3:
    trainerbattlestd 0x0 0x77 0x0 str_before_3 str_after_3
    loadpointer 0x0 str_after_3
    callstd MSG_FACE
    end
ow_script_route_4_trainer_4:
    trainerbattlestd 0x0 0x78 0x0 str_before_4 str_after_4
    loadpointer 0x0 str_after_4
    callstd MSG_FACE
    end
ow_script_route_4_trainer_5:
    trainerbattlestd 0 0x75 0 str_before_5 str_after_5
    loadpointer 0 str_after_5
    callstd MSG_FACE
    end
ow_script_route_4_trainer_6:
    trainerbattlestd 0 0x1c2 0 str_before_6 str_after_6
    loadpointer 0 str_after_6
    callstd MSG_FACE
    end
ow_script_route_4_trainer_7:
    trainerbattlestd 0 0x1c3 0 str_before_7 str_after_7
    loadpointer 0 str_after_7
    callstd MSG_FACE
    end
ow_script_route_4_trainer_8:
    trainerbattlestd 0 0x1c4 0 str_before_8 str_after_8
    loadpointer 0 str_after_8
    callstd MSG_FACE
    end
ow_script_route_4_trainer_9:
    trainerbattlestd 0 0x1c5 0 str_before_9 str_after_9
    loadpointer 0 str_after_9
    callstd MSG_FACE
    end
ow_script_route_4_trainer_10:
    trainerbattledouble 0x4 0x1c6 0 str_before_10 str_after_10 str_one_poke_10
    loadpointer 0x0 str_after_10
    callstd MSG_FACE
    end
ow_script_route_4_trainer_11:
    trainerbattlestd 0 0x1c7 0 str_before_11 str_after_11
    loadpointer 0 str_after_11
    callstd MSG_FACE
    end
ow_script_route_4_trainer_12:
    trainerbattlestd 0 0x1c8 0 str_before_12 str_after_12
    loadpointer 0 str_after_12
    callstd MSG_FACE
    end

ow_script_route_4_cook:
    lock
    faceplayer
    loadpointer 0 str_cook_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif NOT_EQUAL cook_battle
    loadpointer 0 str_cook_dont_battle
    callstd MSG_KEEPOPEN
    release
    end
cook_battle:
    trainerbattlecont 1 0x1c9 0 str_cook_before str_cook_after cook_after
cook_after:
    lock
    loadpointer 0 str_cook_give
    callstd MSG_KEEPOPEN
    fanfare 258
    loadpointer 0 str_got_recipe
    callstd MSG_KEEPOPEN
    waitfanfare
    loadpointer 0 str_after_recipe
    callstd MSG_KEEPOPEN
    closeonkeypress
    fadescreen 1
    hidesprite LASTTALKED
    fadescreen 0
    release
    end

.ifdef LANG_GER
str_challange:
    .autostring 34 2 "Mein Liebling und ich werden dich mit der Kraft unserer Liebe besiegen!"
str_defeat:
    .autostring 34 2 "Was, das kann nicht sein?\pNichts ist stärker als unsere Liebe!"
str_one_poke:
    .autostring 34 2 "Du willst allein gegen ein Liebespaar antreten?\pDas würde ich mir an deiner Stelle überlegen."
str_before_1:
    .autostring 34 2 "Ich bin so frustriert!\pMan hat mir gesagt, ich sei zu schwach, um gegen den Arenaleiter von Blütenbach zu kämpfen.\pAlso werde ich meinen ganzen Frust jetzt an dir auslassen!"
str_after_1:
    .autostring 34 2 "Was?\pIch werde selbst von einem Kind so blamiert?"
str_before_2:
    .autostring 34 2 "Meine Gabe der Vorhersehung sagt mir, dass unser Kampf nur eine Weise enden kannDOTS"
str_after_2:
    .autostring 34 2 "DOTSMeine NiederlageDOTS\pIch habe sie kommen sehenDOTS"
str_before_3:
    .autostring 34 2 "Oh, ich will Sie ja wirklich nicht bedrängenDOTS\pAber dürfte ich Sie zu einem Kampf herausfordern?"
str_after_3:
    .autostring 34 2 "Ich versteheDOTS\pSie haben wirklich hervorragend gekämpft.\pIch ziehe meinen Hut vor ihren Fähigkeiten."
str_before_4:
    .autostring 34 2 "Das Wasser in diesem Fluss ist extrem sauber.\pHier ist jeder Fang ein Hauptgewinn!"
str_after_4:
    .autostring 34 2 "Na, was soll's.\pDas nächste Pokémon, das ich an Land ziehe, hätte es locker mit deinen aufnehmen können."
str_before_5:
    .autostring 34 2 "Mein Geist ist der eines Flug-Pokémons!\pEs gibt keinen Käfig, der groß genug wäre, meine Seele einzusperren!"
str_after_5:
    .autostring 34 2 "Na, vielleicht habe ich etwas zu große Töne gespucktDOTS"
str_before_6:
    .autostring 34 2 "Um in der Arena von Manuel in Blütenbach trainieren zu dürfen, muss man sein Können unter Beweis stellen.\pIch bin kurz davor, es zu schaffen!"
str_after_6:
    .autostring 34 2 "Argh!\nIch bin wohl doch noch nicht stark genug, um in der Blütenbach-Arena zu trainieren."
str_before_7:
    .autostring 34 2 "Eines Tages werden meine Flug-Pokémon mich bis über die Wolken tragen.\pEs heißt, dort oben gibt es schwebende Inseln!"
str_after_7:
    .autostring 34 2 "Wir müssen noch viel stärker werden, meine Pokémon und ich."
str_before_8:
    .autostring 34 2 "Ich verstehe wirklich nicht, warum so viele Menschen auf uns Mechaniker herabsehen.\pDas ist wirklich frustrierend!"
str_after_8:
    .autostring 34 2 "Na gut, als Mechaniker muss man auch nicht unbedingt gut kämpfen können, oder?"
str_before_9:
    .autostring 34 2 "Im Unterholz herumzukriechen finden viele abstoßend.\pAber genau dort findet man die stärksten Käfer-Pokémon!"
str_after_9:
    .autostring 34 2 "Soll das heißen, ich habe mich ganz umsonst schmutzig gemacht?"
str_before_10:
    .autostring 34 2 "Meine Schwester hat das süßeste Pokémon auf der ganzen Welt gefangen.\pDa werden einem die Knie weich."
str_after_10:
    .autostring 34 2 "W-Was?\nAber sind unsere Pokémon nicht knuffig?"
str_one_poke_10:
    .autostring 34 2 "Meine Schwester und ich haben unglaublich süße Pokémon.\pAber wir zeigen sie dir nur, wenn du gegen uns beide gleichzeitig antrittst, verstanden?"
str_before_11:
    .autostring 34 2 "Diese Berge sind der ideale Ort, seinen mentalen Fokus zu traineren.\pDas ist für eine Kämpferin schon die halbe Miete!"
str_after_11:
    .autostring 34 2 "Scheinbar war deine mentale Kraft zu groß für michDOTS"
str_before_12:
    .autostring 34 2 "Es gibt nichts auf dieser Welt, das mir Vaters Geld nicht kaufen könnte.\pAber um gegen dich zu gewinnen, muss ich nicht einmal etwas ausgeben."
str_after_12:
    .autostring 34 2 "Moment, warte!\pWie viel muss ich dir bezahlen, dass du unseren nächsten Kampf verlierst?"
str_cook_ask:
    .autostring 34 2 "Huh?\nWas bildest du dir denn ein, so einfach mit mir zu sprechen?\pWeißt du denn nicht, wer ich bin?\pAlle Welt kennt meinen Namen!\pIch bin berühmt für meine Rezepte!\pIn Sachen Eiern kann mir keiner etwas vormachen.\pDenkst du, du kannst es mit mir aufnehmen?"
str_cook_before:
    .autostring 34 2 "Aus dir mache ich Omlettt, Kindchen!"
str_cook_after:
    .autostring 34 2 "Impossible!\pWie konnte ich gegen einen Amateurkoch verlieren?"
str_cook_dont_battle:
    .autostring 34 2 "Ganz richtig, so, ja?\pUnd jetzt mach, dass du mir aus den Augen kommst, du verzogenes Gör!"
str_cook_give:
    .autostring 34 2 "Das war nicht übel, Kindchen.\pVielleicht habe ich dich unterschätzt, huh?\pIch werde dir als Zeichen meiner Wertschätzugn und Anerkennung meine wertvollen Rezepte anvertrauen, ja?\pAber dass du gut darauf aufpasst, Kindchen!"
str_got_recipe:
    .autostring 34 2 "PLAYER hat ein Rezept erhalten!"
str_after_recipe:
    .autostring 34 2 "Mit diesem Rezept kannst du Wetter-Eier herstellen.\pDas kann dir im Kampf einen entscheidenen Vorteil bringen.\pIch werde mich daran setzen, diese Rezepte noch weiter zu verfeinern, ja?"
.elseif LANG_EN

.endif




