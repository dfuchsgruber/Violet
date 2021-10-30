#include "types.h"
#include "language.h"

u8 ability_names[][13] = {
	LANGDEP(PSTRING("--------"), PSTRING("-------")),
	LANGDEP(PSTRING("Duftnote"), PSTRING("Stench")),
	LANGDEP(PSTRING("Niesel"), PSTRING("Drizzle")),
	LANGDEP(PSTRING("Temposchub"), PSTRING("Speed boost")),
	LANGDEP(PSTRING("Kampfpanzer"), PSTRING("Battle armor")),
	LANGDEP(PSTRING("Robustheit"), PSTRING("Sturdy")),
	LANGDEP(PSTRING("Feuchtigkeit"), PSTRING("Damp")),
	LANGDEP(PSTRING("Flexibilität"), PSTRING("Limber")),
	LANGDEP(PSTRING("Sandschleier"), PSTRING("Sand veil")),
	LANGDEP(PSTRING("Statik"), PSTRING("Static")),
	LANGDEP(PSTRING("Voltabsorber"), PSTRING("Volt absorb")),
	LANGDEP(PSTRING("H2o-absorber"), PSTRING("Water absorb")),
	LANGDEP(PSTRING("Dösigkeit"), PSTRING("Oblivious")),
	LANGDEP(PSTRING("Wolke sieben"), PSTRING("Cloud nine")),
	LANGDEP(PSTRING("Facettenauge"), PSTRING("Compoundeyes")),
	LANGDEP(PSTRING("Insomnia"), PSTRING("Insomnia")),
	LANGDEP(PSTRING("Farbwechsel"), PSTRING("Color change")),
	LANGDEP(PSTRING("Immunität"), PSTRING("Immunity")),
	LANGDEP(PSTRING("Feuerfänger"), PSTRING("Flash fire")),
	LANGDEP(PSTRING("Puderabwehr"), PSTRING("Shield dust")),
	LANGDEP(PSTRING("Tempomacher"), PSTRING("Own tempo")),
	LANGDEP(PSTRING("Saugnapf"), PSTRING("Suction cups")),
	LANGDEP(PSTRING("Bedroher"), PSTRING("Intimidate")),
	LANGDEP(PSTRING("Wegsperre"), PSTRING("Shadow tag")),
	LANGDEP(PSTRING("Rauhaut"), PSTRING("Rough skin")),
	LANGDEP(PSTRING("Wunderwache"), PSTRING("Wonder guard")),
	LANGDEP(PSTRING("Schwebe"), PSTRING("Levitate")),
	LANGDEP(PSTRING("Sporenwirt"), PSTRING("Effect spore")),
	LANGDEP(PSTRING("Synchro"), PSTRING("Synchronize")),
	LANGDEP(PSTRING("Neutraltorso"), PSTRING("Clear body")),
	LANGDEP(PSTRING("Innere kraft"), PSTRING("Natural cure")),
	LANGDEP(PSTRING("Blitzfänger"), PSTRING("Lightningrod")),
	LANGDEP(PSTRING("Edelmut"), PSTRING("Serene grace")),
	LANGDEP(PSTRING("Wassertempo"), PSTRING("Swift swim")),
	LANGDEP(PSTRING("Chlorophyll"), PSTRING("Chlorophyll")),
	LANGDEP(PSTRING("Erleuchtung"), PSTRING("Illuminate")),
	LANGDEP(PSTRING("Fährte"), PSTRING("Trace")),
	LANGDEP(PSTRING("Kraftkoloss"), PSTRING("Huge power")),
	LANGDEP(PSTRING("Giftdorn"), PSTRING("Poison point")),
	LANGDEP(PSTRING("Konzentrator"), PSTRING("Inner focus")),
	LANGDEP(PSTRING("Magmapanzer"), PSTRING("Magma armor")),
	LANGDEP(PSTRING("Aquahülle"), PSTRING("Water veil")),
	LANGDEP(PSTRING("Magnetfalle"), PSTRING("Magnet pull")),
	LANGDEP(PSTRING("Lärmschutz"), PSTRING("Soundproof")),
	LANGDEP(PSTRING("Regengenuss"), PSTRING("Rain dish")),
	LANGDEP(PSTRING("Sandsturm"), PSTRING("Sand stream")),
	LANGDEP(PSTRING("Erzwinger"), PSTRING("Pressure")),
	LANGDEP(PSTRING("Speckschicht"), PSTRING("Thick fat")),
	LANGDEP(PSTRING("Frühwecker"), PSTRING("Early bird")),
	LANGDEP(PSTRING("Flammkörper"), PSTRING("Flame body")),
	LANGDEP(PSTRING("Angsthase"), PSTRING("Run away")),
	LANGDEP(PSTRING("Adlerauge"), PSTRING("Keen eye")),
	LANGDEP(PSTRING("Scherenmacht"), PSTRING("Hyper cutter")),
	LANGDEP(PSTRING("Mitnahme"), PSTRING("Pickup")),
	LANGDEP(PSTRING("Schnarchnase"), PSTRING("Truant")),
	LANGDEP(PSTRING("übereifer"), PSTRING("Hustle")),
	LANGDEP(PSTRING("Charmebolzen"), PSTRING("Cute charm")),
	LANGDEP(PSTRING("Plus"), PSTRING("Plus")),
	LANGDEP(PSTRING("Minus"), PSTRING("Minus")),
	LANGDEP(PSTRING("Prognose"), PSTRING("Forecast")),
	LANGDEP(PSTRING("Wertehalter"), PSTRING("Sticky hold")),
	LANGDEP(PSTRING("Expidermis"), PSTRING("Shed skin")),
	LANGDEP(PSTRING("Adrenalin"), PSTRING("Guts")),
	LANGDEP(PSTRING("Notschutz"), PSTRING("Marvel scale")),
	LANGDEP(PSTRING("Kloakensosse"), PSTRING("Liquid ooze")),
	LANGDEP(PSTRING("Notdünger"), PSTRING("Overgrow")),
	LANGDEP(PSTRING("Grossbrand"), PSTRING("Blaze")),
	LANGDEP(PSTRING("Sturzbach"), PSTRING("Torrent")),
	LANGDEP(PSTRING("Hexaplaga"), PSTRING("Swarm")),
	LANGDEP(PSTRING("Steinhaupt"), PSTRING("Rock head")),
	LANGDEP(PSTRING("Dürre"), PSTRING("Drought")),
	LANGDEP(PSTRING("Auswegslos"), PSTRING("Arena trap")),
	LANGDEP(PSTRING("Munterkeit"), PSTRING("Vital spirit")),
	LANGDEP(PSTRING("Pulverrauch"), PSTRING("White smoke")),
	LANGDEP(PSTRING("Mentalkraft"), PSTRING("Pure power")),
	LANGDEP(PSTRING("Panzerhaut"), PSTRING("Shell armor")),
	LANGDEP(PSTRING("Kakophony"), PSTRING("Cacophony")),
	LANGDEP(PSTRING("Klimaschutz"), PSTRING("Air lock")),
	LANGDEP(PSTRING("Frostschicht"), PSTRING("Frostschicht")),
	LANGDEP(PSTRING("Zenithaut"), PSTRING("Zenithaut")),
	LANGDEP(PSTRING("Donneraura"), PSTRING("Donneraura")),
	LANGDEP(PSTRING("Multischuppe"), PSTRING("Multischuppe")),
	LANGDEP(PSTRING("Kämpferherz"), PSTRING("Kämpferherz")),
	LANGDEP(PSTRING("Techniker"), PSTRING("Techniker")),
	LANGDEP(PSTRING("Solarkraft"), PSTRING("Solarkraft")),
	LANGDEP(PSTRING("Regenmut"), PSTRING("Regenmut")),
	LANGDEP(PSTRING("Kältewahn"), PSTRING("Kältewahn")),
	LANGDEP(PSTRING("Sandherz"), PSTRING("Sandherz")),
	LANGDEP(PSTRING("Wandlungsk."), PSTRING("Wandlungsk.")),
	LANGDEP(PSTRING("Tollwut"), PSTRING("Tollwut")),
	LANGDEP(PSTRING("Zeitspiel"), PSTRING("Zeitspiel")),
	LANGDEP(PSTRING("Strolch"), PSTRING("Strolch")),
	LANGDEP(PSTRING("Orkanschw."), PSTRING("Orkanschw.")),
	LANGDEP(PSTRING("Dunkle magie"), PSTRING("Dunkle magie")),
	LANGDEP(PSTRING("Lernfähig"), PSTRING("Lernfähig")),
	LANGDEP(PSTRING("Hagelalarm"), PSTRING("Hagelalarm")),
	LANGDEP(PSTRING("Hochmut"), PSTRING("Hochmut")),
	LANGDEP(PSTRING("AP-sparer"), PSTRING("AP-sparer")),
	LANGDEP(PSTRING("Taktikwechs."), PSTRING("Taktikwechs.")),
	LANGDEP(PSTRING("Luzid"), PSTRING("Luzid")),
	LANGDEP(PSTRING("Ungebrochen"), PSTRING("Ungebrochen")),
	LANGDEP(PSTRING("Lebensräuber"), PSTRING("Lebensräuber")),
	LANGDEP(PSTRING("Filter"), PSTRING("Filter")),
	LANGDEP(PSTRING("Felsenkern"), PSTRING("Felsenkern")),
	LANGDEP(PSTRING("Barriere"), PSTRING("Barriere")),
	LANGDEP(PSTRING("Anpassung"), PSTRING("Anpassung")),
	LANGDEP(PSTRING("Aufwertung"), PSTRING("Aufwertung")),
	LANGDEP(PSTRING("Allrounder"), PSTRING("Allrounder")),
	LANGDEP(PSTRING("Hitzewahn"), PSTRING("Hitzewahn")),
	LANGDEP(PSTRING("Giftwahn"), PSTRING("Giftwahn")),
	LANGDEP(PSTRING("R.Kaiseraura"), PSTRING("R.Kaiseraura")),
	LANGDEP(PSTRING("B.Kaiseraura"), PSTRING("B.Kaiseraura")),
	LANGDEP(PSTRING("G.Kaiseraura"), PSTRING("G.Kaiseraura")),
	LANGDEP(PSTRING("Photogenese"), PSTRING("Photorecover")),
	LANGDEP(PSTRING("Extradorn"), PSTRING("Extrathorn")),
	LANGDEP(PSTRING("Curator"), PSTRING("Curator")),
	LANGDEP(PSTRING("Frühzünder"), PSTRING("Early Fuze")),
	LANGDEP(PSTRING("Reiche Ernte"), PSTRING("Harvest")),
	LANGDEP(PSTRING("Achtlos"), PSTRING("Reckless")),
	LANGDEP(PSTRING("Hacker"), PSTRING("Hacker")),
	LANGDEP(PSTRING("Fluffig"), PSTRING("Fluffy")),
	LANGDEP(PSTRING("Superschütze"), PSTRING("Sniper")),
	LANGDEP(PSTRING("Glückspilz"), PSTRING("Super Luck")),
	LANGDEP(PSTRING("Eschat"), PSTRING("Eschat")),
	LANGDEP(PSTRING("Gegenwind"), PSTRING("Head Wind")),
	LANGDEP(PSTRING("Tintenschuss"), PSTRING("Ink Shot")),
	LANGDEP(PSTRING("Krallenwucht"), PSTRING("Tough Claw")),
	LANGDEP(PSTRING("Giftnebel"), PSTRING("Toxic Mist")),
};
