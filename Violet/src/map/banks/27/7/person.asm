

.include "overworld_script.s"
.include "callstds.s"

.global ow_script_indoor_3_person_0
.global ow_script_indoor_3_person_1
.global ow_script_indoor_3_person_2
.global ow_script_indoor_3_person_3
.global ow_script_indoor_3_person_4

ow_script_indoor_3_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_indoor_3_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_indoor_3_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_indoor_3_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_indoor_3_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Vor sechzig Jahren habe ich meine Frau gefragt, ob sie mich heiraten möchte, genau hier an diesem Ort.\pHeute haben wir an der Stelle ein Haus, und unsere Familie lebt darin.\pDas Leben ist manchmal auch einfach unvergleichlich perfekt."
str_1:
    .autostring 34 2 "Meine Mutter hat mir oft erzählt, dass wir von einem alten Volk aus Atlantea abstammen.\pIch habe solche Märchen viele Jahre lang geglaubtDOTS"
str_2:
    .autostring 34 2 "Mein Onkel ist der berüchtigte Pirat Blackbeard!\pMeine Eltern schimpfen mich zwar immer, wenn ich sagen will, dass ich eines Tages so werdeDOTS\pAber davon abhalten, eines Tages in See zu stechen können sie mich nicht!"
str_3:
    .autostring 34 2 "Was soll nur aus unserem Sohn werden, wo er jetzt schon davon träumt, ein gesetzloser Pirat zu werdenDOTS"
str_4:
    .autostring 34 2 "Mein Bruder, dieser Taugenichts, hat es zum berüchtigsten Piraten der Region gebrachtDOTS\pUm ehrlich zu sein, kann man da schon etwas neidisch werdenDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Sixty years ago I asked my wife if she wanted to marry me, at this very place.\pToday we own a house at this spot and our family lives in it.\pSometimes life is miraculously perfect."
str_1:
    .autostring 34 2 "My mother often told me that our ancestors were people of the ancient Atlantea.\pFor a long time I believed in fairy tales like thisDOTS"
str_2:
    .autostring 34 2 "My uncle is the renown pirate Blackbeard!\pEven though my parents are always angry with me when I claim that one day I will be the sameDOTS\pBut they can't keep me from setting sails eventually!"
str_3:
    .autostring 34 2 "What only should become of my son as he already dreams of becoming a lawless pirate one dayDOTS"
str_4:
    .autostring 34 2 "My brother, this good-for-nothing, managed to became the most feared pirate of the RegionDOTS\pTo be honest with you, one can get somewhat jealous of himDOTS"

.endif