.include "overworld_script.s"
.include "callstds.s"

.global ow_script_haweiland_pokestop_person_0
.global ow_script_haweiland_pokestop_person_1
.global ow_script_haweiland_pokestop_person_2

ow_script_haweiland_pokestop_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_haweiland_pokestop_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_haweiland_pokestop_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Bevor Blackbeard zum Gesetzlosen wurde, ist er hier auf Haweiland aufgewachsen.\pManche haben sogar gehofft, er würde eines Tages unser Bürgermeister werden.\pAls er dann alles hingeworfen hat und zum Piraten wurde, waren die Bewohner schockiert."
str_1:
    .autostring 34 2 "Meine Pokémon sind vom vielen Schwimmen ganz erschöpft.\pVielleicht sollte ich im Strandhaus Erfrischungen kaufenDOTS"
str_2:
    .autostring 34 2 "Jeden Tag suche ich am Strand nach Müll, um ihn ordentlich zu entsorgen.\pAber egal, wie viel Mühe ich gebe, ich scheine nie hinterherzukommenDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Before Blackbeard became an outlaw, he was an inhabitant of Haweiland.\pMany had even hoped that one day he would become our mayor.\pWhen he quit everything and turned to piracy all inhabitants of this town were shocked."
str_1:
    .autostring 34 2 "My Pokémon are exhausted because of all the swimming we did.\pMaybe I should buy refreshments in the beach houseDOTS"
str_2:
    .autostring 34 2 "Every day I am looking for trash at the beach to properly get rid of it.\pBut no matter how much effort I put into it, I never seem to be able to catch upDOTS"

.endif