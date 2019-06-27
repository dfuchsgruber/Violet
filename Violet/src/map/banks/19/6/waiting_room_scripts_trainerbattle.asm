.include "overworld_script.s"
.include "specials.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_ceometria_gym_trainer_variant_0
.global ow_script_ceometria_gym_trainer_variant_1
.global ow_script_ceometria_gym_trainer_variant_2
.global ow_script_ceometria_gym_trainer_variant_3
.global ow_script_ceometria_gym_trainer_variant_4
.global ow_script_ceometria_gym_trainer_variant_5
.global ow_script_ceometria_gym_trainer_variant_6
.global ow_script_ceometria_gym_trainer_variant_7

ow_script_ceometria_gym_trainer_variant_0:
   trainerbattlestd 0 0xF3 0 str_before_0 str_after_0
   loadpointer 0 str_after_0
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_1:
   trainerbattlestd 0 0xF4 0 str_before_1 str_after_1
   loadpointer 0 str_after_1
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_2:
   trainerbattlestd 0 0xF5 0 str_before_2 str_after_2
   loadpointer 0 str_after_2
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_3:
   trainerbattlestd 0 0xF6 0 str_before_3 str_after_3
   loadpointer 0 str_after_3
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_4:
   trainerbattlestd 0 0xF7 0 str_before_4 str_after_4
   loadpointer 0 str_after_4
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_5:
   trainerbattlestd 0 0xF8 0 str_before_5 str_after_5
   loadpointer 0 str_after_5
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_6:
   trainerbattlestd 0 0xF9 0 str_before_6 str_after_6
   loadpointer 0 str_after_6
   callstd MSG_FACE
   end
ow_script_ceometria_gym_trainer_variant_7:
   trainerbattlestd 0 0xFA 0 str_before_7 str_after_7
   loadpointer 0 str_after_7
   callstd MSG_FACE
   end



.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Ich ruhe mich hier nur aus, bis meine Pokémon wieder fit genug sind, Teah herauszufordern!\pWie sieht es mit ein wenig Aufwärmen aus?"
str_after_0:
    .autostring 34 2 "UffDOTS\nJetzt muss ich wohl noch ein Weilchen warten."
str_before_1:
    .autostring 34 2 "Die Vorhersehung hat dich zu mir gebracht.\pNun bist aber du es, der dafür büßen muss."
str_after_1:
    .autostring 34 2 "Die Vorhersehung ist eine ungerechte BestieDOTS"
str_before_2:
    .autostring 34 2 "Hier im Warteraum ist es so öde.\pEin Kampf würde die Atmosphäre aufheitern!"
str_after_2:
    .autostring 34 2 "Auch wenn ich verloren habe, ist das Warten deutlich erträglicher geworden."
str_before_3:
    .autostring 34 2 "Die Geister die ich riefDOTS\pDOTSwerden dich besiegen!"
str_after_3:
    .autostring 34 2 "So ist es also nun gekommenDOTS"
str_before_4:
    .autostring 34 2 "Dass du mich angesprochen hast, war Schicksal."
str_after_4:
    .autostring 34 2 "Meine Niederlage, auch sie war vorherbestimmt."
str_before_5:
    .autostring 34 2 "Hörst du die Musik der Stille?\pIhr Gesang klingt rückwärts gegen die ZeitDOTS"
str_after_5:
    .autostring 34 2 "Es ist eine liebliche StimmeDOTS"
str_before_6:
    .autostring 34 2 "Teah ist die einzige, die in der Lage ist, stets den richtigen Pfad zu erkennen.\pVielleicht stärkt ein Kampf meine Fähigkeiten!"
str_after_6:
    .autostring 34 2 "Du bist nicht von schlechten Eltern!"
str_before_7:
    .autostring 34 2 "Die verschiedenen Räume in dieser Arena sind tückisch!\pSo wie die Menschen hier!"
str_after_7:
    .autostring 34 2 "Bist wirklich du mir in die Falle getappt, oder ich stattdessen dir?"

.elseif LANG_EN
str_before_0:
    .autostring 34 2 "I just rest until my Pokémon are fit to battle Teah!\pHow about some warm up?"
str_after_0:
    .autostring 34 2 "UffDOTS\nNow I got to wait a while."
str_before_1:
    .autostring 34 2 "It was foreseen that you would come at me.\pNow however you are the one that has to pay for that."
str_after_1:
    .autostring 34 2 "What an unjust beast destiny is."
str_before_2:
    .autostring 34 2 "It is so dull here in the waiting room.\pA battle would improve the atmosphere!"
str_after_2:
    .autostring 34 2 "Even though I lost waiting just became way more endurable."
str_before_3:
    .autostring 34 2 "The ghosts I called forDOTS\pDOTSwill now defeat you."
str_after_3:
    .autostring 34 2 "So that's to what it has comeDOTS"
str_before_4:
    .autostring 34 2 "That you spoke to meDOTS\nDOTSit was destiny."
str_after_4:
    .autostring 34 2 "My defeat, even it was predestined."
str_before_5:
    .autostring 34 2 "Can you hear the song of silence?\pIt's sound goes backwards in time."
str_after_5:
    .autostring 34 2 "What a lovely voiceDOTS"
str_before_6:
    .autostring 34 2 "Teah is the only one who always knows the right path beforehand.\pMaybe a battle will strengthen my abilities as well!"
str_after_6:
    .autostring 34 2 "Not half bad kid."
str_before_7:
    .autostring 34 2 "The different rooms in this gym are treacherous.\pBut so are the people!"
str_after_7:
    .autostring 34 2 "Have you really fallen for my trap or was it rather me falling for yours?"
.endif