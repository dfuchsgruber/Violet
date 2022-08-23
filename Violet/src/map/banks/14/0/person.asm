.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_10_clouds_person_0
.global ow_script_route_10_clouds_person_1
.global ow_script_route_10_clouds_person_2
.global ow_script_route_10_clouds_person_3

ow_script_route_10_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_route_10_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_route_10_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
    
ow_script_route_10_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Unter den Wolkenreitern erzählt man sich von einem großen grünen Drachen, der durch die Ozonschicht streift.\pIch würde zugerne wissen, ob an der Legende etwas Wahres istDOTS"
str_1:
    .autostring 34 2 "Die Höhlensysteme in dieser Schlucht gleichen einem Labyrinth.\pIch habe mich dort einmal für mehrere Tage verirrtDOTS"
str_2:
    .autostring 34 2 "Ich habe wirklich vorhin den Schrei eines Ursaring gehörtDOTS\pJetzt bloß keine falschen BewegungenDOTS"
str_3:
    .autostring 34 2 "Diese Schlucht ist wirklich ein beeindruckendes Naturschauspiel.\pDie schwebenden Inseln hier oben sind wirklich etwas anderes, als die Welt unten auf dem BodenDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "A story among cloud riders tells about a great grean dragon that wanders through the ozon.\pI really want to know if there is any truth to this legendDOTS"
.endif
