.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"

movs:
.byte LOOK_UP
.byte STOP


.global ow_script_0x92de82
ow_script_0x92de82:
lock
faceplayer
loadpointer 0x0 str_0
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL no_story
playsong MUS_DARK_QUEEN 0x0
applymovement LASTTALKED movs
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
