.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_4_clouds_person_0
.global ow_script_route_4_clouds_person_1
.global ow_script_route_4_clouds_person_2
.global ow_script_route_4_clouds_person_3
.global ow_script_route_4_clouds_person_4
.global ow_script_route_4_clouds_person_5

ow_script_route_4_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_4_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_4_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_4_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_4_clouds_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_route_4_clouds_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Es hat Tradition, auf Wolken, welche von Altaria gewoben wurden, zu fliegen.\pDie Kunst des Wolkenwebens beherrschen nur wenige Menschen."
str_1:
    .autostring 34 2 "Seitdem Lucius nicht länger Champion ist, trifft man viel weniger Menschen auf den Wolken."
str_2:
    .autostring 34 2 "Ich laufe hier über den Wolken, weil du Luft dünner ist.\pSo werden meine Lungen viel stärker!"
str_3:
    .autostring 34 2 "Als ich das Wolkenreiten gelernt habe, war ich total überrascht, wie viel es über dem Festland zu erkunden gibt."
str_4:
    .autostring 34 2 "Ist es nicht aufregend, dass hier oben einmal Menschen Städte erbaut haben?\pIch frage mich, wie das Leben zu dieser Zeit wohl gewesen sein muss."
str_5:
    .autostring 34 2 "Wenn man auf Wolken unterwegs ist, muss man tierisch aufpassen, wo man hintritt.\pEin falscher Schritt und man fällt in sein Verderben."
.elseif LANG_EN
str_0:
    .autostring 34 2 "It is a long tradition to fly on clouds made by Altaria.\pThe art of cloud weaving is only known to a few people."
str_1:
    .autostring 34 2 "Ever since Lucius' fame has vanished, you see way less people up here on the clouds."
str_2:
    .autostring 34 2 "I go running above the clouds because of the thin air.\pThis way my lungs get much stronger!"
.endif