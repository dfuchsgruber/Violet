.include "overworld_script.s"
.include "mugshot.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_ceometria_gym_teah
ow_script_ceometria_gym_teah:
    checkflag FRBADGE_5
    gotoif EQUAL badge_obtained
    lock
    faceplayer
    loadpointer 0x0 str_before
    show_mugshot MUGSHOT_TEAH MUGSHOT_LEFT
    warpmuted 19 10 255 14 8
    waitstate
    release
    end

badge_obtained:
    loadpointer 0x0 str_after
    show_mugshot MUGSHOT_TEAH MUGSHOT_LEFT MSG_FACE
    end

.ifdef LANG_GER
str_before:
    .autostring 34 2 "PLAYER, ich freue mich, dass du endlich hier bist.\pSeit unserer Begegnung am Waldfriedhof kann ich es schon gar nicht mehr erwarten, gegen dich zu kämpfen.\pJemand ohne eine vorherbestimmte Zukunft ist sicherlich ein interessanter Gegner."
str_after:
    .autostring 34 2 "Eine Niederlage, die ich nicht vorhergesehen habeDOTS\pDu bist wirklich etwas besonderes.\pAuch ohne meine Gabe, in die Zukunft zu sehen, weiß ich, dass du Großes vollbringen wirst."
.elseif LANG_EN
str_before:
    .autostring 34 2 "PLAYER, I am glad that you are finally here.\pEver since we met at the Forest Cemetery I couldn't wait to battle you.\pSomeone without a predestined future surely makes for an interesting opponent."
str_after:
    .autostring 34 2 "A defeat I have not foreseen.\pYou really are something special.\pEven without my gift to see into the future I am certain that you will do great things."

.endif