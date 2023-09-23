#include "types.h"
#include "tile/tv.h"
#include "constants/vars.h"
#include "language.h"
#include "vars.h"

//Text format :=…Es laufen [XXX]:YYYYYYY…
//Beispiel: …Es läuft eine Doku: Blablabla…

void load_tv_text() {

    const u8 **ptrbank0 = (const u8**) 0x03000f14;
    *ptrbank0 = get_tv_text();

}

const u8 str_tv_albus[];
const u8 str_tv_violet[];
const u8 str_tv_champion_report[];
const u8 str_tv_primus[];
const u8 str_tv_aktania[];


const u8 *get_tv_text() {

    u16 story_prog = *var_access(STORY_PROGRESS);
    if (story_prog < 0xB) {
        return str_tv_champion_report; //Sendung Uli und Klaus
    }
    if (story_prog < 0x15) {
        return str_tv_primus; //Nachrichten: Primus entfuehrt
    }
    if (story_prog < 0x1D) {
        return str_tv_aktania; //History-Doku: Bruchfels Reportage
    }
    if (story_prog < 0x22){
        return str_tv_albus;
    }
    return str_tv_violet;
}

const u8 str_tv_albus[] = LANGDEP(
		PSTRING(
				"DOTSEs läuft eine Exklusiv-Sendung\nder Theto-Polizei:\pBürger Thetos, der "
				"gefährliche\nAnführer der Revolutionsbewegung\lAblus wurde nahe Kaskada\l"
				"gesichtet.\pEr gilt als gefährlichste\nPersönlichkeit des Kontinents.\pAls "
				"ehemaliges Mitglied der Top\nVier ist größte Vorsicht geboten.\pJeder "
				"Hinweis, der zur Ergreifung\ndienlich ist, wird hoch belohnt.\pHalten Sie "
				"sich dennoch fern von\njeder grün gekleideten Gestalt!"
				),
		PSTRING(
				"DOTSAn exclusive report of the\nTheto police department:\lDear citizens, the "
				"most dangerous\lleader of the Revolutionary\lMovement Albus is claimed to be\l"
				"seen in Kaskada.\pHe is known for being the most\nwanted personality on the "
				"entire\lcontinent.\pAs former member of the Elite Four\nhe is to be met with "
				"greatest\lcaution.\pEvery hint leading to his capture\nwill be highly "
				"rewarded.\pIn general stay away from every\ngreen cloaked person!"
				)
		);

const u8 str_tv_violet[] = LANGDEP(
		PSTRING("DOTSEs läuft eine Theto-Polizei\nSondersendung:\pOberwachtmeister Harren: Lassen\n"
				"Sie uns über die Organsation Team\lViolet sprechen.\pDie verbrecherische "
				"Organisation\nist in drei Fraktionen unterteilt,\lan deren Spitze jeweils "
				"mächtige\lVorstände stehen.\pReporter: Drei Vorstände also?\nUnd wer sind diese "
				"Verbrecher?\pOberwachtmeister Harren:\nDie dritte Division wird von Rin\l"
				"angeführt, einer berüchtigten\lGanovin, die als äußert brutal\lgilt.\pDie zweite "
				"Division leitet\nMistral, ein Emporkömmling, der\lsich zuvor als Mitglied der\l"
				"Revolution einen Namen gemacht\lhat.\pEr gilt wegen seiner berechnenden\nArt als "
				"besonders gefährlich.\pReporter: Und wer befehligt die\nerste Division?\p"
				"Oberwachtmeister Harren: Nun, das\nist eine gute Frage.\pUnsere arbeiten Bereits "
				"an der\nLösung dieses Rätsels.\lGerüchten zufolge soll dieser\lominöse erste "
				"Vorstand auch der\lstärkste in den Reihen der\lOrganisation sein.\pLeider aber "
				"hält er sich, ebenso\nwie der Anührer der Bande, sehr\lbedeckt."
				),
		PSTRING("DOTSAn exclusive report of the\nTheto police department:\pChief Harren: Let us "
				"talk about\nthe criminal organisation Team\lViolet.\pThey are organzied as three\n"
				"seperate divisions led by an\lpowerfull Admin.\pReporter: So three Admins? And "
				"who\nare those dangerous criminals?\pChief Harren: The third division\nis led by "
				"Rin, an infamous villain\lthat is said be extremly brutal.\pThe second Admins is "
				"called\nMistral, an upstart that before\lwas part of the Revolutionary\lMovement. "
				"Because of his\lcalculating nature he is claimed\lto be most dangerous.\p"
				"Reporter: And who is in charge of\nthe first division?\pChief Harren: Well, that "
				"we do not\nknow.\pOur staff is currently engaged to\nsolve this puzzle.\pRumors "
				"say the first Admin also is\nto be the most powerfull among\lthem.\pUnfortunatley "
				"he as well as Team\nViolets prime leader is hiding in\lthe shadows, waiting."
				)
		);

const u8 str_tv_champion_report[] = LANGDEP(
		PSTRING("DOTSEs läuft eine Talkshow:\pKlaus: Nun, Uli, wissen wir denn\nschon etwas über "
				"unseren neuen\lChampion?\pNein, Klaus, ich fürchte, dass\nsich der neue Champion "
				"äußerst\lbedeckt hält. Ich habe aber\lgehört, er solle noch sehr jung\lsein.\p"
				"Klaus: Er? Ich hörte von einer\nFrau…"
				),
		PSTRING("Not translated yet.")
		);

const u8 str_tv_primus[] = LANGDEP(
		PSTRING("DOTSEs laufen die Nachrichten:\pSprecher: Noch immer haben wir\nkeine Neuigkeiten "
				"vom vermissten\lProfessor Primus.\pEr gilt seit vier Tagen als\nvermisst. "
				"Zeugenangaben zufolge\lwurde er von Schergen der\lOrganisation Team Violet "
				"enführt.\pPrimus gilt als führender\nWissenschaftler auf dem Gebiet der\l"
				"Zeitforschung.\pDie Polizei nimmt jeden\nhilfreichen Hinweis entgegen."
				),
		PSTRING("Not translated yet.")
		);

const u8 str_tv_aktania[] = LANGDEP(
		PSTRING("DOTSEs läuft eine History-Doku:\pErzähler: Das Verhängnis von\nBruchfels, eine "
				"Tragödie, die den\lganzen Kontinent ergriffen hat.\pAls ein Meteorit aus dem all "
				"vor\nder Küste des einstigen\lFerienparadises Bruchfels einschlug,\lsollte sich das "
				"Leben auf der\lInsel für immer verändern.\pViele Menschen fielen der\nKatastrophe "
				"zum Opfer, so auch der\lArenaleiter der Stadt, Harren.\pDer zuständige Regent von "
				"den Top\nVier kommentierte das Unglück wie\lfolgt:\pHarren war ein großer Mann, "
				"sein\nTod ist bedauernswert. Ich hätte\lmir niemand besseren als\lArenaleiter von "
				"Bruchfels wünschen\lkönnen und so bin ich zumindest\lerleichtert, dass die Aufgabe "
				"nun\lseinem Sohn Lester zuteil wird."
				),
		PSTRING("Not translated yet.")
		);
