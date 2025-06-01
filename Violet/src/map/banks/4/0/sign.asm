
.include "callstds.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_bookshelf_mum_0
.global ow_script_bookshelf_mum_1


ow_script_bookshelf_mum_0:
    loadpointer 0 str_bookshelf0
    callstd MSG_SIGN
    end
ow_script_bookshelf_mum_1:
    loadpointer 0 str_bookshelf1
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_bookshelf0:
    .autostring 34 2 "Die Lieblingsbücher deiner Mama.\pAm meisten hat sie immer die Geschichte über einen Trainer, der die ganze Welt bereist hat, gemocht."
str_bookshelf1:
    .autostring 34 2 "Eine Menge Bücher über Legenden rund um Theto.\pManche handeln von einer alten Zivilisation, die vor langer Zeit auf schwebenden Inseln über den Wolken gelebt haben soll."
.elseif LANG_EN
str_bookshelf0:
    .autostring 34 2 "Mom's favorite books.\pShe always liked the story about a Trainer who traveled the whole world the most."
str_bookshelf1:
    .autostring 34 2 "A lot of books about legends around Theto.\pSome are about an ancient civilization that is said to have lived on floating islands above the clouds a long time ago."
.endif
