.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "songs.s"
.include "ordinals.s"

.global ow_script_tafelberg_witch
.global ow_script_tafelberg_person_0
.global ow_script_tafelberg_person_1
.global ow_script_tafelberg_person_2
.global ow_script_tafelberg_person_3
.global ow_script_tafelberg_person_4
.global ow_script_tafelberg_revolutionary_0
.global ow_script_tafelberg_revolutionary_1
.global ow_script_tafelberg_revolutionary_2
.global ow_script_tafelberg_policeman_0
.global ow_script_tafelberg_policeman_1
.global ow_script_tafelberg_policeman_2
.global ow_script_tafelberg_revolutionary_3
.global ow_script_tafelberg_revolutionary_4
.global ow_script_tafelberg_felix

ow_script_tafelberg_person_0:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_tafelberg_person_1:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_tafelberg_person_2:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_tafelberg_person_3:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_tafelberg_person_4:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_tafelberg_revolutionary_0:
    loadpointer 0 str_7
    callstd MSG
    end
ow_script_tafelberg_revolutionary_1:
    loadpointer 0 str_8
    callstd MSG
    end
ow_script_tafelberg_revolutionary_2:
    loadpointer 0 str_9
    callstd MSG
    end
ow_script_tafelberg_policeman_0:
    loadpointer 0 str_10
    callstd MSG
    end
ow_script_tafelberg_policeman_1:
    loadpointer 0 str_11
    callstd MSG
    end
ow_script_tafelberg_policeman_2:
    loadpointer 0 str_12
    callstd MSG
    end
ow_script_tafelberg_revolutionary_3:
    loadpointer 0 str_13
    callstd MSG_FACE
    end
ow_script_tafelberg_revolutionary_4:
    loadpointer 0 str_14
    callstd MSG_FACE
    end
ow_script_tafelberg_felix:
    loadpointer 0 str_15
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG
    end

ow_script_tafelberg_witch:
    lock
    faceplayer
    loadpointer 0x0 str_0
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL no_story
    playsong MUS_DARK_QUEEN 0x0
    applymovement LASTTALKED mov_fu
    waitmovement 0x0
    setvar 0x8004 0x1
    special SPECIAL_CUTSCENE_SHOW
    waitstate
    loadpointer 0x0 str_story
    callstd MSG
    setvar 0x8004 0x2
    special SPECIAL_CUTSCENE_SHOW
    waitstate
    fadesong MUS_ROUTE_24_25
    loadpointer 0x0 str_after
    callstd MSG_FACE
    end

no_story:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hehe!\pWer ich bin?\pEine Hexe natürlich, was sonst?\pMöchtest du eine spannende Geschichte hören?"
str_1:
    .autostring 34 2 "Wie auch immerDOTS\pSolltest du deine Meinung ändern, findest du mich hierDOTS"
str_story:
    .autostring 34 2 "Vor vielen Jahren herrschte eine dunkle Königin über diese Region, lange noch, bevor es die Top Vier überhaupt gab.\pSie war eine tyrannische, machtsüchtige Frau, und unfassbar mächtig.\pSie bändigte eigenhändig zahlreiche legendäre Pokémon und kein Mensch war im Stande, ihr Einhalt zu gebieten.\pEines Tages erklärte sie dann den Göttern unserer Welt den Krieg.\pLetztlich wurde sie für ihren Hochmut bestraft und vernichtet.\pEs heißt, dass ihr unsterblicher Geist noch immer umherirrt."
str_after:
    .autostring 34 2 "Viele Hexen sind auf der Suche nach dem Geist der dunklen Königin.\pSie gilt als die Mutter des Hexentums."
str_2:
    .autostring 34 2 "Nach einem Besuch im Teehaus von Kaskada gibt es doch nichts Besseres als einen ausgedehnten Spaziergang auf den Gipfel des Tafelbergs."
str_3:
    .autostring 34 2 "Dass der Tafelberg direkt an der Küste liegt, macht ihn für Besucher noch interessanter.\pBei gutem Wetter kann man von hier bis weit in den Norden nach Bruchfels sehen."
str_4:
    .autostring 34 2 "Ich komme gerne hier an den Strand, um Muscheln zu sammeln.\pVon Zeit zu Zeit spült das Meer hier den ein oder anderen Schatz an."
str_5:
    .autostring 34 2 "Ich bin ein wirklicher Vogel-Pokémon Liebhaber.\pHier am Tafelberg kann man oft Schwärme von Natu beobachten.\pEs heißt, dass bereits die Azteken dieses Pokémon und seine Entwicklung Xatu verehrt haben."
str_6:
    .autostring 34 2 "Ich bin hier mit einer Freundin verabredetDOTS\pAllerdings wollten wir uns bereits vor über einer Stunde hier treffen.\pBei dem Ausblick bin ich aber gar nicht traurig, versetzt worden zu sein."
str_7:
    .autostring 34 2 "Dieser verdammte Cop!\pIch lasse mich von den Lakaien der Pokémon-Liga nicht herumschubsen, verstanden?"
str_8:
    .autostring 34 2 "Ich lasse mich von euch nicht kleinkriegen!\pWir werden euer korruptes System zerschlagen, koste es, was es wolle!"
str_9:
    .autostring 34 2 "Langsam geht meinem Pokémon die Puste ausDOTS\pKomm schon, wir dürfen uns nicht geschlagen geben!"
str_10:
    .autostring 34 2 "Ihr seid wirklich ein Haufen unbelehrbarer Punks.\pEuch werden wir die Schlagkraft unseres Gesetzes schon zeigen."
str_11:
    .autostring 34 2 "Glaubt ja nicht, dass ihr Revolutionäre tun uns lassen könnt, was ihr wollt.\pDie Polizei wird die Bürger dieser Region vor euch beschützen."
str_12:
    .autostring 34 2 "Dieser Kampf geht schon viel zu langeDOTS\pAber wenn ich diesen Raudis klein bei gebe, hält das Chaos Einzug in ThetoDOTS"
str_13:
    .autostring 34 2 "Du und dein kleiner Polizistenfreund mögt uns ja besiegt habenDOTS\pAber unser Anführer ist noch einmal eine andere Hausnummer!"
str_14:
    .autostring 34 2 "Ihr seid wohl recht siegessicher, was?\pAber warte ab, unser Anführer war selbst früher ein Mitglied der Top Vier!"
str_15:
    .autostring 34 2 "Opi!\pWas genau geht hier vor sich?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Hehe!\pWho I am?\pWhy, a witch of course, what else?\pDo you want to hear a compelling story?"
str_1:
    .autostring 34 2 "WhateverDOTS\pIf you change your mind you can find me right hereDOTS"
str_story:
    .autostring 34 2 "Many years ago a dark queen ruled over this region, long before the Elite Four even were thing.\pShe was a tyrant and her lust for power was without any limit.\pAbove all however, she was unmatched in power.\pShe tamed many legendary Pokémon on her own and nobody was able to stand up to her.\pSome day she declared war on the gods of this world.\pFor this grandeure she was punished in the end and utterly destroyed.\pIt is said that her spirit wanders arround in this world to this very day."
str_after:
    .autostring 34 2 "Many witches are still searching for the spirit of the dark queen.\pShe is considered to be the mother of witchcraft."

.endif

