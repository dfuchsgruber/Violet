.include "callstds.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_map_3_19_trainer_2
.global ow_script_map_3_19_person_0
.global ow_script_0x8dce51
.global ow_script_map_3_19_trainer_0
.global ow_script_map_3_19_trainer_3
.global ow_script_map_1_59_trainer_1
.global ow_script_0x8f6111
.global ow_script_map_3_19_trainer_1
.global ow_script_map_3_19_trainer_4
.global ow_script_map_3_19_person_1

ow_script_map_3_19_person_0:
lock
faceplayer
loadpointer 0x0 str_0x804215
callstd MSG
release
end


ow_script_map_3_19_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x804215:
    .autostring 34 2 "Du willst gegen mich kämpfen?\pTja, Pech gehabt.\nIch habe gar kein Pokémon!"
str_1:
    .autostring 34 2 "Mein Pokémon ist ganz aufgeregt!\pDabei habe ich meine Abschlussprüfung doch erst in ein paar WochenDOTS"
.elseif LANG_EN
str_0x804215:
    .autostring 34 2 "You want to challange me?\pWell, I don't even have a Pokémon, so that's that."

.endif


ow_script_map_3_19_trainer_0:
trainerbattlestd 0x0 0x1 0x0 str_0x8040c2 str_0x804122
loadpointer 0x0 str_0x804122
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8040c2:
    .autostring 34 2 "Du siehst aus, als hättest du noch nicht viel Erfahrung.\pLeichte Beute für mich!"
str_0x804122:
    .autostring 34 2 "Du bist stärker, als du aussiehst."
.elseif LANG_EN
str_0x8040c2:
    .autostring 34 2 "You look like a rookie, right?\pEasy prey for me!"
str_0x804122:
    .autostring 34 2 "You're stronger than one might think."
.endif


ow_script_map_3_19_trainer_1:
trainerbattlestd 0x0 0x2 0x0 str_0x804181 str_0x8041dd
loadpointer 0x0 str_0x8041dd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x804181:
    .autostring 34 2 "Ich besiege hier andauernd irgendwelche Schulkinder, die glauben, sie wären unschlagbar.\pAlso sieh dich vor!"
str_0x8041dd:
    .autostring 34 2 "Na gut, ich schätze, du bist tatsächlich nicht allzu schwach."
.elseif LANG_EN

str_0x804181:
    .autostring 34 2 "Every day I defeat this little brats who come out of school and think they are invincible!"
str_0x8041dd:
    .autostring 34 2 "Ok, ok, I suppose you are not that weak then."
.endif


ow_script_map_3_19_trainer_2:
loadpointer 0x0 str_0x8a0b9e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a0b9e:
    .autostring 34 2 "Ich versuche, jedes verschiedene Pokémon, das mir begegnet, einzufangen.\pAuf die Weise lernt man sehr viel, musst du wissen."
.elseif LANG_EN
str_0x8a0b9e:
    .autostring 34 2 "I try to catch every single Pokémon I encounter.\pThis way I can learn so much, believe it or not."
.endif


ow_script_map_3_19_trainer_3:
trainerbattlestd 0x0 0x3 0x0 str_0x8a09e3 str_0x8a0a35
loadpointer 0x0 str_0x8a0a35
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a09e3:
    .autostring 34 2 "Ich habe mir einen Trank gekauft, um mein Pokémon im Kampf wieder aufpeppeln zu können.\pDu hast also gar keine Chance!"
str_0x8a0a35:
    .autostring 34 2 "Scheint so, als hättest du die bessere Ausrüstung gehabt."
.elseif LANG_EN
str_0x8a09e3:
    .autostring 34 2 "I bought a poition to strengthen my Pokémon in battle.\pThat means you don't stand a chance!"
str_0x8a0a35:
    .autostring 34 2 "Seems like you were better equipped after all."
.endif


ow_script_map_1_59_trainer_1:
end