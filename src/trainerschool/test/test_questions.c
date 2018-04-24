#include "types.h"
#include "trainerschool_test.h"
#include "language.h"

u8 str_trainerschool_test_question_0[] = LANGDEP(
    PSTRING("Welches ist das\nGrößte aller\nPokémon?"),
    PSTRING("Which is the\nbiggest of all\nPokémon?"));
u8 str_trainerschool_test_question_0_answer_0[] = LANGDEP(
    PSTRING("Groudon"), PSTRING("Groudon"));
u8 str_trainerschool_test_question_0_answer_1[] = LANGDEP(
    PSTRING("Stahlos"), PSTRING("Steelix"));
u8 str_trainerschool_test_question_0_answer_2[] = LANGDEP(
    PSTRING("Wailord"), PSTRING("Wailord"));
u8 str_trainerschool_test_question_0_answer_3[] = LANGDEP(
    PSTRING("Garados"), PSTRING("Gyrados")
    );

u8 *str_trainerschool_test_question_0_answers[] = {
    str_trainerschool_test_question_0_answer_0,
    str_trainerschool_test_question_0_answer_1,
    str_trainerschool_test_question_0_answer_2,
    str_trainerschool_test_question_0_answer_3
};

u8 str_trainerschool_test_question_1[] = LANGDEP(
    PSTRING("Wie viele AP\nverliert das Ziel\ndurch die Attacke\nGroll?"),
    PSTRING("How many PP\nwill be lost\nwhen hit by\nSpite?"));
u8 str_trainerschool_test_question_1_answer_0[] = LANGDEP(
    PSTRING("Vier"), PSTRING("Four"));
u8 str_trainerschool_test_question_1_answer_1[] = LANGDEP(
    PSTRING("Hälfte"), PSTRING("Half")
    );
u8 str_trainerschool_test_question_1_answer_2[] = LANGDEP(
    PSTRING("Alle"), PSTRING("All"));
u8 str_trainerschool_test_question_1_answer_3[] = LANGDEP(
    PSTRING("Fünf"), PSTRING("Five"));

u8 *str_trainerschool_test_question_1_answers[] = {
    str_trainerschool_test_question_1_answer_0,
    str_trainerschool_test_question_1_answer_1,
    str_trainerschool_test_question_1_answer_2,
    str_trainerschool_test_question_1_answer_3
};

u8 str_trainerschool_test_question_2[] = LANGDEP(
    PSTRING("Welcher Angriff\nwird von Relaxo\nerlernt?"),
    PSTRING("Which of these\nattacks does\nSnorlax not\nlearn?"));
u8 str_trainerschool_test_question_2_answer_0[] = LANGDEP(
    PSTRING("Brüller"), PSTRING("Roar"));
u8 str_trainerschool_test_question_2_answer_1[] = LANGDEP(
    PSTRING("Slam"), PSTRING("Slam"));
u8 str_trainerschool_test_question_2_answer_2[] = LANGDEP(
    PSTRING("Bezirzer"), PSTRING("Covet"));

u8 *str_trainerschool_test_question_2_answers[] = {
    str_trainerschool_test_question_2_answer_0,
    str_trainerschool_test_question_2_answer_1,
    str_trainerschool_test_question_2_answer_2
};

u8 str_trainerschool_test_question_3[] = LANGDEP(
    PSTRING("Welches dieser\nItems hat den\nhöchsten Wert?"),
    PSTRING("Which of these\nitems is the\most valuable?"));
u8 str_trainerschool_test_question_3_answer_0[] = LANGDEP(
    PSTRING("Maronbeere"), PSTRING("Chesto Berry"));
u8 str_trainerschool_test_question_3_answer_1[] = LANGDEP(
    PSTRING("Abysszahn"), PSTRING("Deep Sea Tooth"));
u8 str_trainerschool_test_question_3_answer_2[] = LANGDEP(
    PSTRING("Sanftglocke"), PSTRING("Sooth Bell"));
u8 str_trainerschool_test_question_3_answer_3[] = LANGDEP(
    PSTRING("Laxrauch"), PSTRING("Lax Incense"));
u8 str_trainerschool_test_question_3_answer_4[] = LANGDEP(
    PSTRING("Donnerstein"), PSTRING("Thunder Stone"));

u8 *str_trainerschool_test_question_3_answers[] = {
    str_trainerschool_test_question_3_answer_0,
    str_trainerschool_test_question_3_answer_1,
    str_trainerschool_test_question_3_answer_2,
    str_trainerschool_test_question_3_answer_3,
    str_trainerschool_test_question_3_answer_4
};


u8 str_trainerschool_test_question_4[] = LANGDEP(
    PSTRING("Welches dieser\nPokémon besitzt\nden höchsten\nBasis-Angriff?"),
    PSTRING("Which of these\nPokémon has the\nhighest Base-\nAttack?")
);
u8 str_trainerschool_test_question_4_answer_0[] = LANGDEP(
    PSTRING("Flamara"), PSTRING("Flareon"));
u8 str_trainerschool_test_question_4_answer_1[] = LANGDEP(
    PSTRING("Glaziola"), PSTRING("Glazeon"));
u8 str_trainerschool_test_question_4_answer_2[] = LANGDEP(
    PSTRING("Nachtara"), PSTRING("Umbreon"));
u8 str_trainerschool_test_question_4_answer_3[] = LANGDEP(
    PSTRING("Aquana"), PSTRING("Vaporeon"));

u8 *str_trainerschool_test_question_4_answers[] = {
    str_trainerschool_test_question_4_answer_0,
    str_trainerschool_test_question_4_answer_1,
    str_trainerschool_test_question_4_answer_2,
    str_trainerschool_test_question_4_answer_3
};

u8 str_trainerschool_test_question_5[] = LANGDEP(
    PSTRING("Wie viele\nStunden benötigt\nDragoran zur\nWeltumrundung?"),
    PSTRING("How many\nhours does it\ntake Dargonite\nto circle the world?")
    );
u8 str_trainerschool_test_question_5_answer_0[] = LANGDEP(
    PSTRING("Sechzehn"), PSTRING("Sixteen"));
u8 str_trainerschool_test_question_5_answer_1[] = LANGDEP(
    PSTRING("Achtzehn"), PSTRING("Eighteen"));
u8 str_trainerschool_test_question_5_answer_2[] = LANGDEP(
    PSTRING("Fünfzehn"), PSTRING("Fifteen"));
u8 str_trainerschool_test_question_5_answer_3[] = LANGDEP(
    PSTRING("Zwanzig"), PSTRING("Twenty"));
u8 str_trainerschool_test_question_5_answer_4[] = LANGDEP(
    PSTRING("Einundzwanzig"), PSTRING("Twenty-one"));

u8 *str_trainerschool_test_question_5_answers[] = {
    str_trainerschool_test_question_5_answer_0,
    str_trainerschool_test_question_5_answer_1,
    str_trainerschool_test_question_5_answer_2,
    str_trainerschool_test_question_5_answer_3,
    str_trainerschool_test_question_5_answer_4
};

u8 str_trainerschool_test_question_6[] = LANGDEP(
    PSTRING("Welches der\nfolgenden Items\nexistiert nicht?"),
    PSTRING("Which of the\nfollowing items\ndoes not exist?"));
u8 str_trainerschool_test_question_6_answer_0[] = LANGDEP(
    PSTRING("Giefebeere"), PSTRING("Figy Berry"));
u8 str_trainerschool_test_question_6_answer_1[] = LANGDEP(
    PSTRING("Lucky-Punch"), PSTRING("Lucky Punch"));
u8 str_trainerschool_test_question_6_answer_2[] = LANGDEP(
    PSTRING("Rotstück"), PSTRING("Purple Shard"));

u8 *str_trainerschool_test_question_6_answers[] = {
    str_trainerschool_test_question_6_answer_0,
    str_trainerschool_test_question_6_answer_1,
    str_trainerschool_test_question_6_answer_2,
};

u8 str_trainerschool_test_question_7[] = LANGDEP(
    PSTRING("Welcher dieser\nAngriffe\n verursacht den\nmeisten Schaden?"),
    PSTRING("Which of these\nattacks causes\nthe most\ndamage?"));
u8 str_trainerschool_test_question_7_answer_0[] = LANGDEP(
    PSTRING("Giftzahn"), PSTRING("Poison Fang"));
u8 str_trainerschool_test_question_7_answer_1[] = LANGDEP(
    PSTRING("Antik-Kraft"), PSTRING("Ancient Power"));
u8 str_trainerschool_test_question_7_answer_2[] = LANGDEP(
    PSTRING("Aurorastrahl"), PSTRING("Aurora Beam"));
u8 str_trainerschool_test_question_7_answer_3[] = LANGDEP(
    PSTRING("Ampelleuchte"), PSTRING("Signal Beam"));

u8 *str_trainerschool_test_question_7_answers[] = {
    str_trainerschool_test_question_7_answer_0,
    str_trainerschool_test_question_7_answer_1,
    str_trainerschool_test_question_7_answer_2,
    str_trainerschool_test_question_7_answer_3,
};

u8 str_trainerschool_test_question_8[] = LANGDEP(
    PSTRING("Welches dieser\nPokémon benötigt\nam längsten\nzum Schlüpfen?"),
    PSTRING("Which of these\nPokémon takes\nthe longsest\nto hatch?"));
u8 str_trainerschool_test_question_8_answer_0[] = LANGDEP(
    PSTRING("Shuppet"), PSTRING("Shuppet"));
u8 str_trainerschool_test_question_8_answer_1[] = LANGDEP(
    PSTRING("Wailmer"), PSTRING("Wailmer"));
u8 str_trainerschool_test_question_8_answer_2[] = LANGDEP(
    PSTRING("Kabuto"), PSTRING("Kabuto"));
u8 str_trainerschool_test_question_8_answer_3[] = LANGDEP(
    PSTRING("Seeper"), PSTRING("Horsea"));

u8 *str_trainerschool_test_question_8_answers[] = {
    str_trainerschool_test_question_8_answer_0,
    str_trainerschool_test_question_8_answer_1,
    str_trainerschool_test_question_8_answer_2,
    str_trainerschool_test_question_8_answer_3,
};

u8 str_trainerschool_test_question_9[] = LANGDEP(
    PSTRING("Welche dieser\nPaare besitzen\ndas gleiche\nGewicht?"),
    PSTRING("Which of these\npairs share\nthe same\nweight?"));
u8 str_trainerschool_test_question_9_answer_0[] = LANGDEP(
    PSTRING("Larvitar, Bronzel"), ("Larvitar", "Bronzor"));
u8 str_trainerschool_test_question_9_answer_1[] = LANGDEP(
    PSTRING("Vipitis, Perlu"), PSTRING("Seviper, Clamperl"));
u8 str_trainerschool_test_question_9_answer_2[] = LANGDEP(
    PSTRING("Pudox, Reptain"), PSTRING("Dustox,Grovyle"));
u8 str_trainerschool_test_question_9_answer_3[] = LANGDEP(
    PSTRING("Voltenso, Kadabra"), PSTRING("Manectric, Kadabra"));

u8 *str_trainerschool_test_question_9_answers[] = {
    str_trainerschool_test_question_9_answer_0,
    str_trainerschool_test_question_9_answer_1,
    str_trainerschool_test_question_9_answer_2,
    str_trainerschool_test_question_9_answer_3,
};

trainerschool_test_question trainerschool_test_questions [] = {
    {
        4, 2, str_trainerschool_test_question_0, 
                str_trainerschool_test_question_0_answers
    },{
        4, 0, str_trainerschool_test_question_1, 
                str_trainerschool_test_question_1_answers
    },{
        3, 2, str_trainerschool_test_question_2, 
                str_trainerschool_test_question_2_answers
    },{
        5, 3, str_trainerschool_test_question_3, 
                str_trainerschool_test_question_3_answers
    },{
        4, 0, str_trainerschool_test_question_4, 
                str_trainerschool_test_question_4_answers
    },{
        5, 0, str_trainerschool_test_question_5, 
                str_trainerschool_test_question_5_answers
    },{
        3, 2, str_trainerschool_test_question_6, 
                str_trainerschool_test_question_6_answers
    },{
        4, 3, str_trainerschool_test_question_7, 
                str_trainerschool_test_question_7_answers
    },{
        4, 1, str_trainerschool_test_question_8, 
                str_trainerschool_test_question_8_answers
    },{
        4, 1, str_trainerschool_test_question_9, 
                str_trainerschool_test_question_9_answers
    }
};


