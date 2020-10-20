.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_silvania_wald_shrine

ow_script_silvania_wald_shrine:
    loadpointer 0 str_0
    callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_read
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
dont_read:
    closeonkeypress
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In den Schrein scheint jemand vor langer Zeit etwas eingeritzt zu haben.\pDie Schrift ist beinahe verblasstDOTS\pMöchtest du den Text lesen?"
str_1:
    .autostring 34 2 "Die Dunkle Königin stahl einst den Stein der Zeit aus diesem Schrein.\pAls Strafe für deren Hochmut ward der Dunklen Königin Edelstein zerschmettert.\pDes Wetters grimmige Gebieter wachen nun mehr unablässig über des Steines Trümmer, auf dass niemals wieder ein Sterblicher seiner Verlockung verfalle.\pMahnung sei dieser Schrein all jenen, die ersuchen, seine Kraft zu erlangen.\pGrausam ist der Richtspruch derer, die unser Königreich vernichteten.\pUnendlich hoch der Blutpreis, mit wir den Stein bezahlten.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDer Text ist unterzeichnet vom letzten König der Stadt Atlantea."
.elseif LANG_EN
.endif