.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x8ec5cb
ow_script_movs_0x8ec5cb:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8e6a88
ow_script_0x8e6a88:
lockall
sound 0x15
applymovement 0x800f ow_script_movs_0x8ec5cb
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x8ec458
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
loadpointer 0x0 str_0x8e8f9d
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
loadpointer 0x0 str_0x8e8da8
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
fadescreen 0x1
hidesprite 0x800f
clearflag SILVANIA_FAUN_AND_MIA
addvar STORY_PROGRESS 0x1
fadescreen 0x0
releaseall
end


.ifdef LANG_GER
.global str_0x8ec458

str_0x8ec458:
	.autostring 35 2 "PLAYER!\nIch habe alle Hände voll zu tun.\pMan hat Albus, den Anführer der Revolutionsbewegung hier gesichtet.\pDie Revolutionäre sind die wohl gefährlichste Gruppe unserer Zeit.\pWenn es ihnen gelingt, die Regierung zu stürzen, versinkt der Kontinent im Chaos.\pNoch dazu belagert eine Kommandantin dieser Violet Punks den Silvania-Wald.\pDOTS DOTS DOTS\nIch kann mich nicht beiden Problemen gleichzeitig widmen DOTS"
        
.global str_0x8e8f9d

str_0x8e8f9d:
    .autostring 35 2 "Ich kann mich ja der Kommandantin von Team Violet annehmen."
        
        
.global str_0x8e8da8

str_0x8e8da8:
    .autostring 35 2 "PLAYER!\nIch habe volles Vertrauen in dich, aber ich denke nicht, dass du einem Kommandanten von Team Violet gewachsen bist.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWenn ich es mir recht überlege, sollten wir das mit der Arenaleiterin von Silvania absprechen.\pWir treffen uns in ihrem Haus in Silvania.\pIch zähle auf dich, PLAYER."

.elseif LANG_EN

.endif
