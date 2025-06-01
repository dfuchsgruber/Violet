.include "overworld_script.s"
.include "callstds.s"
.include "constants/items.s"

.global ow_script_0x8d4a13@// No idea why this was here tho
.global ow_script_graduate_hat

ow_script_0x8d4a13:
end

ow_script_graduate_hat:
    setvar 0x8000 ITEM_GRADUIERTENHUT
    setvar 0x8001 1
    callstd ITEM_FIND
    pause 24
    loadpointer 0 str_note
    callstd MSG
    end

.ifdef LANG_GER
str_note:
    .autostring 34 2 "Da liegt ein Zettel mit der Aufschrift:\pHerzlichen Glückwunsch zu deinem Abschluss, PLAYER!\pIch bin mir sicher, du wirst ein großartiger Trainer werden.\pPass auf dich auf!\pAlles Liebe - Mama"
.elseif LANG_ENG
str_note:
    .autostring 34 2 "There is a note that reads:\pCongratulations on your graduation, PLAYER!\pI am sure you will be a great Trainer.\pTake care of yourself!\pLove - Mom"
.endif