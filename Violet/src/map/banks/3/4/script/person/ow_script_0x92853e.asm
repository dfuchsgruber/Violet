.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x92853e
ow_script_0x92853e:
	lock
	faceplayer
	loadpointer 0 str_0
	show_mugshot MUGSHOT_IGVA alignment=MUGSHOT_RIGHT message_type=MSG_YES_NO mask_name=1
	compare LASTRESULT 0
	gotoif EQUAL said_no
	loadpointer 0 str_2
	show_mugshot MUGSHOT_IGVA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
	setflag KASKADA_BLACKMARKET_RECEIVED_PAROLE
	fadescreen 0x1
	hidesprite 0x800f
	fadescreen 0x0
	release
	end

said_no:
	loadpointer 0 str_1
	show_mugshot MUGSHOT_IGVA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
	release
	end
	

.ifdef LANG_GER
str_0:
	.autostring 34 2 "Entschuldige bitte, falls ich dich damit überrumple.\pIch habe dich vorhin beobachtet, als du mit Albus, dem Anführer der Revolution gesprochen hast.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs muss seltsam wirken, aber ich möchte dir gerne etwas zeigen.\pWenn du Interesse hast, das wahre Gesicht dieser Region zu sehenDOTS\pNaja, was sagst du?"
str_1:
	.autostring 34 2 "OhDOTS\nNa gut, vielleicht habe ich mich getäuscht.\pWenn du es dir anders überlegst, ich werde noch eine Weile in der Gegend sein."
str_2:
	.autostring 34 2 "Ich wusste es!\nIrgendetwas hat mir gesagt, dass du die Art Mensch bist, die sich auch traut, hinter die glatte Fassade der Dinge zu sehen.\pDOTS DOTS DOTS\nIm Westen der Stadt gibt es ein Klubhaus, in das man nur mit einer Parole eintritt erhält.\pIch will nichts vorwegnehmen, aber du solltest dir dieses Klubhaus auf jeden Fall ansehen.\pWie war doch gleich dein Name?\pPLAYER?\nDOTS DOTS DOTS\pFreut mich sehr!\nIch bin übrigens Igva!\pWir sehen uns im Klubhaus, PLAYER!"
.elseif LANG_EN
.endif
