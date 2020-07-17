.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_map_5_12_person_5
.global ow_script_map_5_12_person_4
.global ow_script_map_5_12_person_0
.global ow_script_map_5_12_person_2
.global ow_script_map_5_12_person_1
.global ow_script_map_5_12_person_3

ow_script_map_5_12_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_map_5_12_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_map_5_12_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_map_5_12_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_map_5_12_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_map_5_12_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Als meine Schwiegereltern hier eingezogen sind, hatte ich ja zunächst recht große BedenkenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNein, meine Meinung hat sich seitdem nicht geändertDOTS"
str_1:
    .autostring 34 2 "Früher haben meine Eltern in Aktania gelebt.\pAber weil bei dem großen Unglück vor einigen Jahren deren Haus vollkommen zerstört wurde, sind sie bei meinem Mann und mir eingezogen.\pIch werde den Eindruck nicht los, dass er davon nicht allzu begeistert istDOTS"
str_2:
    .autostring 34 2 "In den vielen Jahren, die ich nun schon in dieser Region gelebt habe, kommt doch noch immer nichts den Kirschbäumen aus Blütenbach auch nur nahe."
str_3:
    .autostring 34 2 "Trotz unseres hohen Alters sind mein Mann und ich aus Aktania zu unserer Tochter hierher gezogen.\pVon Zeit zu Zeit fehlt mir die salzige Luft aber schon.\pDafür kann man hier in Blütenbach die wunderschönen Kirschbäume betrachten."
str_4:
    .autostring 34 2 "Ich finde es klasse, dass Opi bei uns lebt!\pEr erzählt die spannendsten Geschichten.\pWusstest du, dass es hoch oben über den Wolken schwebende Inseln gibt?\pDoch, ehrlich!\nOpi hat mir von ihnen erzählt.\pIrgendwann einmal will ich diese Inseln mit eigenen Augen sehen!"
str_5:
    .autostring 34 2 "Zu dieser Jahreszeit gehe ich gerne mit meinen Pokémon Kirschblüten sammeln.\pFlabébé liebt es, in den Blüten herumzutollen."
.elseif LANG_EN
str_0:
    .autostring 34 2 "When my parents-in-law moved in here, I was not really convincedDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNo, my mind hasn't changed since then, unfortunatelyDOTS"
str_1:
    .autostring 34 2 "My parents used to live in Aktania.\pBut ever since the big catastrophy there destroyed their home they moved in with me and my husband.\pI just have a feeling that he doesn't really like having my parents arroundDOTS"
str_2:
    .autostring 34 2 "In all these many years I have now lived in this region nothing even comes close to the magificent cherry trees of Petal Creek."
str_3:
    .autostring 34 2 "Regardless of our high age I and my husband moved in with my daughter.\pFrom time to time I really miss the salty air of Aktania.\pIn return, here in Petal Creek you have those beautiful cherry trees to watch."
str_4:
    .autostring 34 2 "I am so glad that gramps is living with us now!\pHe tells the best stories.\pDid you know, that high above the clouds there are floating islands?\pYeah, it's true!\pGramps told me about them.\pSome day I will go to see them myself!"
str_5:
    .autostring 34 2 "During this time of the year I enjoy collecting cherry blossoms with my Pokémon.\pMy Flabébe loves to play arround in the big piles of blossoms."
.endif