.include "overworld_script.s"
.include "callstds.s"

.global ow_script_flavor_text_inside_piano
.global ow_script_flavor_text_inside_fridge
.global ow_script_flavor_text_inside_bookshelf_0
.global ow_script_flavor_text_inside_bookshelf_1
.global ow_script_flavor_text_inside_bookshelf_2
.global ow_script_flavor_text_inside_bookshelf_3
.global ow_script_flavor_text_inside_showcase
.global ow_script_flavor_text_inside_clock
.global ow_script_flavor_text_inside_vase
.global ow_script_flavor_text_inside_picture_frame_0
.global ow_script_flavor_text_inside_picture_frame_1
.global ow_script_flavor_text_inside_picture_frame_2
.global ow_script_flavor_text_inside_picture_frame_3
.global ow_script_flavor_text_inside_picture_waves
.global ow_script_flavor_text_inside_sink
.global ow_script_flavor_text_inside_stove
.global ow_script_flavor_text_inside_kitchen_cupboard
.global ow_script_flavor_text_inside_wardrobe
.global ow_script_flavor_text_inside_bed
.global ow_script_flavor_text_inside_drawers
.global ow_script_flavor_text_inside_flower_pot
.global ow_script_flavor_text_inside_lamp

ow_script_flavor_text_inside_piano:
    loadpointer 0 str_piano
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_fridge:
    loadpointer 0 str_fridge
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_bookshelf_0:
    loadpointer 0 str_bookshelf_0
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_bookshelf_1:
    loadpointer 0 str_bookshelf_1
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_bookshelf_2:
    loadpointer 0 str_bookshelf_2
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_bookshelf_3:
    loadpointer 0 str_bookshelf_3
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_showcase:
    loadpointer 0 str_showcase
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_clock:
    loadpointer 0 str_clock
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_vase:
    loadpointer 0 str_vase
    callstd MSG_SIGN
    end 
ow_script_flavor_text_inside_picture_frame_0:
    loadpointer 0 str_picture_frame_0
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_picture_frame_1:
    loadpointer 0 str_picture_frame_1
    callstd MSG_SIGN
    end 
ow_script_flavor_text_inside_picture_frame_2:
    loadpointer 0 str_picture_frame_2
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_picture_frame_3:
    loadpointer 0 str_picture_frame_3
    callstd MSG_SIGN
    end 
ow_script_flavor_text_inside_picture_waves:
    loadpointer 0 str_picture_waves
    callstd MSG_SIGN 
    end
ow_script_flavor_text_inside_sink:
    loadpointer 0 str_sink
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_stove:
    loadpointer 0 str_stove
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_kitchen_cupboard:
    loadpointer 0 str_kitchen_cupboard
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_wardrobe:
    loadpointer 0 str_wardrobe
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_bed:
    loadpointer 0 str_bed
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_drawers:
    loadpointer 0 str_drawers
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_flower_pot:
    loadpointer 0 str_flower_pot
    callstd MSG_SIGN
    end
ow_script_flavor_text_inside_lamp:
    loadpointer 0 str_lamp
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_piano:
    .autostring 34 2 "Ein Klavier einer teuren Marke.\pEs scheint bereits länger nicht mehr gestimmt worden zu seinDOTS"
str_fridge:
    .autostring 34 2 "Vom Kühlschrank geht ein stechender Geruch aus.\pEs riecht wie verdorbene Owei."
str_bookshelf_0:
    .autostring 34 2 "Ein Regal voller verstaubter Bücher.\pDarunter ist eine Band über eine antike Zivilisation der RegionDOTS"
str_bookshelf_1:
    .autostring 34 2 "Ein Regal voller verstaubter Bücher.\pDarunter ist die neuste Ausgabe eines Kochbuchs der RegionDOTS"
str_bookshelf_2:
    .autostring 34 2 "Im Regal steht die Büste eines Mannes mit langem Haar.\pEin Schild darunter sagt, dass es sich um den ersten Champion der Region handeltDOTS"
str_bookshelf_3:
    .autostring 34 2 "Im Regal sind einige Zeitschriften.\pEin Tratsch-Magazin enthüllt die Entgleisungen der Schwester eines Mitglieds der Top Vier."
str_showcase:
    .autostring 34 2 "In der Vitrine befinden sich mehrere Pokébälle.\pWelche Pokémon wohl darin sind?"
str_clock:
    .autostring 34 2 "Eine unaufällige Wanduhr.\pSie tickt leise vor sich hinDOTS"
str_vase:
    .autostring 34 2 "Eine Vase mit einem schönen Muster.\pSie erinnert an eine Vase, die Mutter früher hatteDOTS"
str_picture_frame_0:
    .autostring 34 2 "Im Bilderrahmen ist ein Foto der ergiebigen Weiden nördlich von Sonnaufeld."
str_picture_frame_1:
    .autostring 34 2 "Im Bilderrahmen ist ein Foto der Burg Ardeal, die einem heftigen Gewitter trotzt."
str_picture_frame_2:
    .autostring 34 2 "Im Bilderrahmen ist ein Foto der Stadt Orina City, deren Wolkenkratzer hoch in den Himmel ragen."
str_picture_frame_3:
    .autostring 34 2 "Im Bilderrahmen ist ein Gemälde der höchsten Gipfel der Region."
str_picture_waves:
    .autostring 34 2 "Das berühmte Gemälde Der Großen Welle.\pIhre schäumende Kraft zieht regelrecht in den Bann."
str_sink:
    .autostring 34 2 "Jemand hat das Spülbecken nicht sauber gemacht.\pEs riecht nach altem Spülmittel und abgestandenem Wasser."
str_stove:
    .autostring 34 2 "Der Induktionsherd ist nagelneu.\pEr scheint noch nicht oft benutzt worden zu sein."
str_kitchen_cupboard:
    .autostring 34 2 "Ein Vorratsschrank voller Gewürze und Konserven.\pEr ist gut gefüllt, aber es fehlt an frischen Lebensmitteln."
str_wardrobe:
    .autostring 34 2 "Ein Kleiderschrank voller Kleidung.\pEs gehört sich zwar nicht, hineinzusehen, aberDOTS\pEs sind auffällig viele bunte Klamotten darin."
str_bed:
    .autostring 34 2 "Das Bett ist ordentlich gemacht.\pEs lädt gerade dazu ein, sich darauf zu legen und ein ausgiebiges Nickerchen zu machen."
str_drawers:
    .autostring 34 2 "Die Schubladen sind voll mit Socken und Unterwäsche.\pEs ist nicht gerade höflich, darin zu wühlenDOTS"
str_flower_pot:
    .autostring 34 2 "Ein Blumentopf mit einer schönen Pflanze.\pVon ihr geht ein äußerst angenehmer Duft aus."
str_lamp:
    .autostring 34 2 "Eine einfache Zimmerlampe.\pVon Zeit zu Zeit flackert sie etwas."
.elseif LANG_EN 
str_piano:
    .autostring 34 2 "A piano of a high-quality brand.\pIt seems to have not been tuned in a whileDOTS"
str_fridge:
    .autostring 34 2 "A pungent smell comes from the fridge.\pIt smells like spoiled Exeggcute."
str_bookshelf_0:
    .autostring 34 2 "A shelf full of dusty books.\pAmong them is a volume about an ancient civilization of the regionDOTS"
str_bookshelf_1:
    .autostring 34 2 "A shelf full of dusty books.\pAmong them is the latest issue of a cookbook of the regionDOTS"
str_bookshelf_2:
    .autostring 34 2 "On the shelf is a bust of a man with long hair.\pA plaque underneath says that it is the first champion of the regionDOTS"
str_bookshelf_3:
    .autostring 34 2 "On the shelf are some magazines.\pA gossip magazine reveals the escapades of the sister of a member of the Elite Four."
str_showcase:
    .autostring 34 2 "In the display case are several Poké Balls.\pWhat Pokémon could be inside them?"
str_clock:
    .autostring 34 2 "An unremarkable wall clock.\pIt ticks quietly to itselfDOTS"
str_vase:
    .autostring 34 2 "A vase with a beautiful pattern.\pIt reminds me of a vase that Mother used to haveDOTS"
str_picture_frame_0:
    .autostring 34 2 "In the picture frame is a photo of the fertile meadows north of Sunnyfield."
str_picture_frame_1:
    .autostring 34 2 "In the picture frame is a photo of Ardeal Castle weathering a fierce storm."
str_picture_frame_2:
    .autostring 34 2 "In the picture frame is a photo of Orina City, whose skyscrapers reach high into the sky."
str_picture_frame_3:
    .autostring 34 2 "In the picture frame is a painting of the highest peaks in the region."
str_picture_waves:
    .autostring 34 2 "The famous painting The Great Wave.\pIts foaming power is truly captivating."
str_sink:
    .autostring 34 2 "Someone didn't clean the sink properly.\pIt smells like old dish soap and stagnant water."
str_stove:
    .autostring 34 2 "The induction stove is brand new.\pIt doesn't seem to have been used very often."
str_kitchen_cupboard:
    .autostring 34 2 "A pantry full of spices and canned goods.\pIt's well stocked, but lacks fresh food."
str_wardrobe:
    .autostring 34 2 "A wardrobe full of clothing.\pIt's not proper to look inside, butDOTS\pThere are noticeably many colorful clothes in it."
str_bed:
    .autostring 34 2 "The bed is neatly made.\pIt's just inviting you to lie down and take a long nap."
str_drawers:
    .autostring 34 2 "The drawers are full of socks and underwear.\pIt's not exactly polite to rummage through themDOTS"
str_flower_pot:
    .autostring 34 2 "A flower pot with a beautiful plant.\pIt gives off a very pleasant scent."
str_lamp:
    .autostring 34 2 "A simple room lamp.\pFrom time to time it flickers a bit."
.endif