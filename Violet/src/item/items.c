	
#include "types.h"
#include "item/item.h"
#include "constants/pokemon_types.h"
#include "constants/item_pockets.h"
#include "constants/item_hold_effects.h"
#include "constants/item_weather_rock_types.h"
#include "language.h"
#include "constants/items.h"
#include "item/custom.h"


static u8 str_item_none_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_meisterball_description[] = LANGDEP(
	PSTRING("Der Ball mit bester Erfolgsquote.\nFängt jedes Pokémon garantiert."),
	PSTRING("The best Ball with the ultimate\nperformance. It will catch any wild\nPokémon without fail.")
);
static u8 str_item_hyperball_description[] = LANGDEP(
	PSTRING("Ein Ball mit hoher Erfolgsquote.\nDem Superball in allen\nPunkten überlegen."),
	PSTRING("A very high-grade Ball that offers\na higher Pokémon catch rate than\na Great Ball.")
);
static u8 str_item_superball_description[] = LANGDEP(
	PSTRING("Ein Ball mit guter Erfolgsquote.\nDem Pokéball in allen\nPunkten überlegen."),
	PSTRING("A good, quality Ball that offers\na higher Pokémon catch rate than\na standard Poké Ball.")
);
static u8 str_item_pokeball_description[] = LANGDEP(
	PSTRING("Damit fängst du wilde Pokémon.\nDas Design ähnelt einer\nKapsel."),
	PSTRING("A Ball thrown to catch a wild\nPokémon. It is designed in a\ncapsule style.")
);
static u8 str_item_safariball_description[] = LANGDEP(
	PSTRING("Ein Ball, der nur in der Safari-\nZone eingesetzt wird. Er besticht\ndurch sein Tarnfarbenmuster."),
	PSTRING("A special Ball that is used only in\nthe Safari Zone. It is finished in\na camouflage pattern.")
);
static u8 str_item_netzball_description[] = LANGDEP(
	PSTRING("Ein Ball, der Pokémon der\nElementklassen Wasser\nund Käfer besser fängt."),
	PSTRING("A somewhat different Ball that\nworks especially well on Water- and\nBug-type Pokémon.")
);
static u8 str_item_tauchball_description[] = LANGDEP(
	PSTRING("Ein Ball, mit dem sich\nPokémon vom Meeresgrund\nbesser fangen lassen."),
	PSTRING("A somewhat different Ball that\nworks especially well on Pokémon\ndeep in the sea.")
);
static u8 str_item_nestball_description[] = LANGDEP(
	PSTRING("Ein Ball, dessen Erfolgsquote\nbesonders bei schwächeren\nPokémon sehr hoch ist."),
	PSTRING("A somewhat different Ball that\nworks especially well on weaker\nPokémon.")
);
static u8 str_item_wiederball_description[] = LANGDEP(
	PSTRING("Ein Ball, der für bereits\ngefangene Pokémon besser\ngeeignet ist."),
	PSTRING("A somewhat different Ball that\nworks especially well on Pokémon\ncaught before.")
);
static u8 str_item_timerball_description[] = LANGDEP(
	PSTRING("Ein Ball, der mit zunehmender\nKampfdauer effektiver wird."),
	PSTRING("A somewhat different Ball that\nbecomes progressively better the\nmore turns there are in a battle.")
);
static u8 str_item_luxusball_description[] = LANGDEP(
	PSTRING("Ein behaglicher Ball, der\nPokémon veranlasst, nach\ndem Fang freundlicher zu werden."),
	PSTRING("A comfortable Ball that makes a\ncaptured wild Pokémon quickly grow\nfriendly.")
);
static u8 str_item_premierball_description[] = LANGDEP(
	PSTRING("Ein seltener Ball, der als\nReminiszenz an irgendein\nEreignis hergestellt wurde."),
	PSTRING("A rare Ball that has been\nspecially made to commemorate an\nevent of some sort.")
);
static u8 str_item_trank_description[] = LANGDEP(
	PSTRING("Die KP eines Pokémon\nwerden um 20 Punkte aufgefüllt."),
	PSTRING("A spray-type wound medicine.\nIt restores the HP of one Pokémon\nby 20 points.")
);
static u8 str_item_gegengift_description[] = LANGDEP(
	PSTRING("Heilt Vergiftungen bei Pokémon."),
	PSTRING("A spray-type medicine.\nIt heals one Pokémon from a\npoisoning.")
);
static u8 str_item_feuerheiler_description[] = LANGDEP(
	PSTRING("Heilt Verbrennungen bei Pokémon."),
	PSTRING("A spray-type medicine.\nIt heals one Pokémon of a burn.")
);
static u8 str_item_eisheiler_description[] = LANGDEP(
	PSTRING("Taut ein eingefrorenes\nPokémon wieder auf."),
	PSTRING("A spray-type medicine.\nIt defrosts a frozen Pokémon.")
);
static u8 str_item_aufwecker_description[] = LANGDEP(
	PSTRING("Weckt ein schlafendes\nPokémon wieder auf."),
	PSTRING("A spray-type medicine.\nIt awakens a sleeping Pokémon.")
);
static u8 str_item_para_heiler_description[] = LANGDEP(
	PSTRING("Heilt Paralyse bei Pokémon."),
	PSTRING("A spray-type medicine.\nIt heals one Pokémon from\nparalysis.")
);
static u8 str_item_top_genesung_description[] = LANGDEP(
	PSTRING("Stellt gesamte KP und Status\neines Pokémon wieder her."),
	PSTRING("A medicine that fully restores the\nHP and heals any status problems\nof one Pokémon.")
);
static u8 str_item_top_trank_description[] = LANGDEP(
	PSTRING("Füllt die KP eines Pokémon\nvollständig auf."),
	PSTRING("A spray-type wound medicine.\nIt fully restores the HP of one\nPokémon.")
);
static u8 str_item_hypertrank_description[] = LANGDEP(
	PSTRING("Füllt die KP eines Pokémon um\n200 Punkte auf."),
	PSTRING("A spray-type wound medicine.\nIt restores the HP of one Pokémon\nby 200 points.")
);
static u8 str_item_supertrank_description[] = LANGDEP(
	PSTRING("Füllt die KP eines Pokémon um\n50 Punkte auf."),
	PSTRING("A spray-type wound medicine.\nIt restores the HP of one Pokémon\nby 50 points.")
);
static u8 str_item_hyperheiler_description[] = LANGDEP(
	PSTRING("Beseitigt alle Statusprobleme\neines Pokémon."),
	PSTRING("A spray-type medicine.\nIt heals all the status problems of\none Pokémon.")
);
static u8 str_item_beleber_description[] = LANGDEP(
	PSTRING("Belebt ein Pokémon und füllt\ndessen KP zur Hälfte wieder auf."),
	PSTRING("A medicine that revives a fainted\nPokémon, restoring HP by half the\nmaximum amount.")
);
static u8 str_item_top_beleber_description[] = LANGDEP(
	PSTRING("Belebt ein Pokémon und füllt\ndie KP vollständig wieder auf."),
	PSTRING("A medicine that revives a fainted\nPokémon, restoring HP fully.")
); 
static u8 str_item_co_mix_description[] = LANGDEP(
	PSTRING("Ein Mischgetränk, das die KP\neines Pokémon um die Hälfte\ndes Maximalwertes auffüllt."),
	PSTRING("A mixed drink that\nrestores the HP by\nhalf its maximum amount.")
);
static u8 str_item_c_saft_description[] = LANGDEP(
	PSTRING("Ein süßer Saft, der die AP\naller Attacken eines Pokémon um\n5 Punkte auffüllt."),
	PSTRING("A juice that recovers\n5 pp of every move of\na Pokémon.")
);
static u8 str_item_c_serum_description[] = LANGDEP(
	PSTRING("Ein super süßes Getränk, das\ndie KP eines Pokémon um 225\nPunkte auffüllt."),
	PSTRING("A super-sweet serum that\nrecovers 225 HP of a\nPokémon.")
);
static u8 str_item_kuhmuh_milch_description[] = LANGDEP(
	PSTRING("Vitaminreiche Milch, welche die KP\neines Pokémon um\n100 Punkte auffüllt."),
	PSTRING("Highly nutritious milk.\nIt restores the HP of one Pokémon\nby 100 points.")
);
static u8 str_item_energiestaub_description[] = LANGDEP(
	PSTRING("Ein bitteres Pulver, das die KP\neines Pokémon um\n50 Punkte auffüllt."),
	PSTRING("A very bitter medicine powder.\nIt restores the HP of one Pokémon\nby 50 points.")
);
static u8 str_item_kraftwurzel_description[] = LANGDEP(
	PSTRING("Eine bittere Wurzel, welche die KP\neines Pokémon um\n200 Punkte auffüllt."),
	PSTRING("A very bitter root.\nIt restores the HP of one Pokémon\nby 200 points.")
);
static u8 str_item_heilpuder_description[] = LANGDEP(
	PSTRING("Ein bitteres Pulver, das alle\nStatusprobleme eines Pokémon \nbeseitigt."),
	PSTRING("A very bitter medicine powder.\nIt heals all the status problems of\none Pokémon.")
);
static u8 str_item_vitalkraut_description[] = LANGDEP(
	PSTRING("Ein bitteres Kraut, das besiegte\nPokémon belebt und die KP\nvollständig auffüllt."),
	PSTRING("A very bitter medicinal herb.\nIt revives a fainted Pokémon,\nrestoring HP fully.")
);
static u8 str_item_aether_description[] = LANGDEP(
	PSTRING("Füllt AP einer ausgewählten Attacke\neines Pokémon um 10 Punkte auf."),
	PSTRING("Restores a selected move’s PP by\n10 points for one Pokémon.")
);
static u8 str_item_top_aether_description[] = LANGDEP(
	PSTRING("Füllt AP einer ausgewählten Attacke\neines Pokémon vollständig auf."),
	PSTRING("Fully restores a selected move’s PP\nfor one Pokémon.")
);
static u8 str_item_elixier_description[] = LANGDEP(
	PSTRING("Füllt alle AP aller Attacken eines\nPokémon um 10 Punkte auf."),
	PSTRING("Restores the PP of all moves for\none Pokémon by 10 points each.")
);
static u8 str_item_top_elixier_description[] = LANGDEP(
	PSTRING("Füllt alle AP aller Attacken eines\nPokémon vollständig auf."),
	PSTRING("Fully restores the PP of all moves\nfor one Pokémon.")
);
static u8 str_item_lavakeks_description[] = LANGDEP(
	PSTRING("Eine Spezialität aus Bad\nLavastadt, die alle\nStatusprobleme eines Pokémon heilt."),
	PSTRING("Lavaridge Town’s local specialty.\nIt heals all the status problems of\none Pokémon.")
);
static u8 str_item_blaue_floete_description[] = LANGDEP(
	PSTRING("Eine blaue, gläserne Flöte, die\nschlafende Pokémon aufweckt."),
	PSTRING("A blue glass flute that awakens\na sleeping Pokémon.")
);
static u8 str_item_gelbe_floete_description[] = LANGDEP(
	PSTRING("Eine gelbe, gläserne Flöte, die\nverwirrte Pokémon heilt."),
	PSTRING("A yellow glass flute that snaps one\nPokémon out of confusion.")
);
static u8 str_item_rote_floete_description[] = LANGDEP(
	PSTRING("Eine rote, gläserne Flöte, die\nPokémon von Anziehung heilt."),
	PSTRING("A red glass flute that snaps one\nPokémon out of infatuation.")
);
static u8 str_item_schw_floete_description[] = LANGDEP(
	PSTRING("Eine schwarze, gläserne Flöte, die\nwilde Pokémon vom Angriff\nabhalten kann."),
	PSTRING("A black glass flute.\nWhen blown, it makes wild Pokémon\nless likely to appear.")
);
static u8 str_item_weisse_floete_description[] = LANGDEP(
	PSTRING("Eine durchsichtige, gläserne Flöte,\ndie wilde Pokémon anziehen kann."),
	PSTRING("A white glass flute.\nWhen blown, it makes wild Pokémon\nmore likely to appear.")
);
static u8 str_item_beerensaft_description[] = LANGDEP(
	PSTRING("Reiner Fruchtsaft, der die KP eines\nPokémon um 75 Punkte auffüllt."),
	PSTRING("A 100% pure juice.\nIt restores the HP of one Pokémon\nby 75 points.")
);
static u8 str_item_zauberasche_description[] = LANGDEP(
	PSTRING("Belebt und erfrischt alle besiegten\nPokémon und füllt deren KP\nvollständig wieder auf."),
	PSTRING("Revives all fainted Pokémon,\nrestoring HP fully.")
);
static u8 str_item_kuestensalz_description[] = LANGDEP(
	PSTRING("Salz, das sich tief in der Küsten-\nHöhle befand. Es ist extrem salzig!"),
	PSTRING("Pure salt obtained from deep inside\nthe Shoal Cave. It is extremely\nsalty.")
);
static u8 str_item_kuestenschale_description[] = LANGDEP(
	PSTRING("Eine schöne Muschelschale, die\nsich in der Küstenhöhle befand.\nSie ist blau und weiß gestreift."),
	PSTRING("A pretty seashell found deep inside\nthe Shoal Cave. It is striped in\nblue and white.")
);
static u8 str_item_purpurstueck_description[] = LANGDEP(
	PSTRING("Eine rote Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small red shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_indigostueck_description[] = LANGDEP(
	PSTRING("Eine blaue Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small blue shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_gelbstueck_description[] = LANGDEP(
	PSTRING("Eine gelbe Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small yellow shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_gruenstueck_description[] = LANGDEP(
	PSTRING("Eine grüne Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small green shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_magmaisierer_description[] = LANGDEP(
	PSTRING("Eine Schachtel voller Magmaenergie.\nDas Lieblingsstück eines\nbestimmten Pokémon."),
	PSTRING("?????")
);
static u8 str_item_stromisierer_description[] = LANGDEP(
	PSTRING("Ein Item, das Elektek zur\nEntwicklung benötigt."),
	PSTRING("?????")
);
static u8 str_item_schoenschuppe_description[] = LANGDEP(
	PSTRING("Ein Item, das Barschwa zur\nEntwicklung benötigt."),
	PSTRING("?????")
);
static u8 str_item_dubiosdisc_description[] = LANGDEP(
	PSTRING("Ein Item, das Porygon2 zur\nEntwicklung benötigt."),
	PSTRING("?????")
);
static u8 str_item_duesterumhang_description[] = LANGDEP(
	PSTRING("Ein Item, das Zwirrklop zur\nEntwicklung benötigt."),
	PSTRING("?????")
);
static u8 str_item_schuetzer_description[] = LANGDEP(
	PSTRING("Ein Item, das Rizeros zur\nEntwicklung benötigt."),
	PSTRING("?????")
);
static u8 str_item_leben_orb_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt Attacken, aber jede\nAttacke kostet KP."),
	PSTRING("?????")
);
static u8 str_item_evolith_description[] = LANGDEP(
	PSTRING("Ein mysteriöser Klumpen, der Vert.\nund Sp.Vert. von Pokémon steigert,\ndie sich noch entwickeln können."),
	PSTRING("?????")
);
static u8 str_item_scharfzahn_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen. Verursacht der\nTräger Schaden, erschrickt der\nGegner eventuell."),
	PSTRING("An item to hold. If the user\ncauses damage the target may\nflinch.")
);
static u8 str_item_ovaler_stein_description[] = LANGDEP(
	PSTRING("Dieeser besondere, eiförmige Stein\nhilft manchen Pokémon bei ihrer\nEvolution."),
	PSTRING("This special, oval rock helps\nsome Pokémon with their evolution.")
);
static u8 str_item_item_3e_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_kp_plus_description[] = LANGDEP(
	PSTRING("Ein gehaltvolles Getränk, das die\nKp-Anzeige eines Pokémon erhöht."),
	PSTRING("A nutritious drink for Pokémon.\nIt raises the base HP of one\nPokémon.")
);
static u8 str_item_protein_description[] = LANGDEP(
	PSTRING("Ein gehaltvolles Getränk, das den\nAngr.-Wert eines Pokémon hebt."),
	PSTRING("A nutritious drink for Pokémon.\nIt raises the base Attack stat of\none Pokémon.")
);
static u8 str_item_eisen_description[] = LANGDEP(
	PSTRING("Ein gehaltvolles Getränk, das den\nVert.-Wert eines Pokémon hebt."),
	PSTRING("A nutritious drink for Pokémon.\nIt raises the base Defense stat of\none Pokémon.")
);
static u8 str_item_carbon_description[] = LANGDEP(
	PSTRING("Ein gehaltvolles Getränk, das den\nInit.-Wert eines Pokémon hebt."),
	PSTRING("A nutritious drink for POKéMON.\nIt raises the base Speed stat of\none POKéMON.")
);
static u8 str_item_kalzium_description[] = LANGDEP(
	PSTRING("Ein gehaltvolles Getränk, das den\nSp. Ang.-Wert eines Pokémon\nhebt."),
	PSTRING("A nutritious drink for Pokémon.\nIt raises the base SP. Atk stat\nof one Pokémon.")
);
static u8 str_item_sonderbonbon_description[] = LANGDEP(
	PSTRING("Ein energiereiches Bonbon, das\nden Level eines Pokémon um\neins anhebt."),
	PSTRING("A candy that is packed with energy.\nIt raises the level of a Pokémon\nby one.")
);
static u8 str_item_ap_plus_description[] = LANGDEP(
	PSTRING("Hebt die maximale Anzahl der AP\neiner Attacke eines Pokémon."),
	PSTRING("Slightly raises the maximum PP of\na selected move for one Pokémon.")
);
static u8 str_item_zink_description[] = LANGDEP(
	PSTRING("Ein gehaltvolles Getränk, das den\nSp. Ver.-Wert eines Pokémon\nhebt."),
	PSTRING("A nutritious drink for Pokémon.\nIt raises the base SP. Def stat\nof one Pokémon.")
);
static u8 str_item_ap_top_description[] = LANGDEP(
	PSTRING("Maximiert die Anzahl der AP\neiner Attacke eines Pokémon."),
	PSTRING("Raises the PP of a selected move\nto its maximum level for one\nPokémon.")
);
static u8 str_item_goldbonbon_description[] = LANGDEP(
	PSTRING("Ein besonderes Bonbon, das\nden Level eines Pokémon um\nbis zu drei anhebt."),
	PSTRING("A special candy. It raises\nthe level of a Pokémon by up to\nthree.")
);
static u8 str_item_megablock_description[] = LANGDEP(
	PSTRING("Eine mögliche Statusänderung der\nPokémon im Team wird für\nfünf Runden verhindert."),
	PSTRING("An item that prevents stat reduction\namong party Pokémon for five turns\nafter use.")
);
static u8 str_item_angriffplus_description[] = LANGDEP(
	PSTRING("Hebt die Volltrefferquote des PKMN\nim Kampf. Die Wirkung wird mit\ndem Tausch des Pokémon beendet."),
	PSTRING("Raises the critical-hit ratio of\nPokémon in battle. Wears off if the\nPokémon is withdrawn.")
);
static u8 str_item_x_angriff_description[] = LANGDEP(
	PSTRING("Hebt den Angr.-Wert eines PKMN\nim Kampf. Die Wirkung wird mit dem\nTausch des Pokémon beendet."),
	PSTRING("Raises the Attack stat of Pokémon\nin battle. Wears off if the Pokémon\nis withdrawn.")
);
static u8 str_item_x_abwehr_description[] = LANGDEP(
	PSTRING("Hebt den Vert.-Wert eines PKMN\nim Kampf. Die Wirkung wird mit dem\nTausch des Pokémon beendet."),
	PSTRING("Raises the Defense stat of Pokémon\nin battle. Wears off if the Pokémon\nis withdrawn.")
);
static u8 str_item_x_tempo_description[] = LANGDEP(
	PSTRING("Hebt den Init.-Wert eines PKMN\nim Kampf. Die Wirkung wird mit dem\nTausch des Pokémon beendet."),
	PSTRING("Raises the Speed stat of POKéMON\nin battle. Wears off if the POKéMON\nis withdrawn.")
);
static u8 str_item_x_treffer_description[] = LANGDEP(
	PSTRING("Hebt die Genauigkeit eines PKMN\nim Kampf. Die Wirkung wird mit dem\nTausch des Pokémon beendet."),
	PSTRING("Raises the accuracy stat of\nPokémon in battle. Wears off if the\nPokémon is withdrawn.")
);
static u8 str_item_x_spezial_description[] = LANGDEP(
	PSTRING("Hebt den SP. Ang.-Wert eines PKMN\nim Kampf. Die Wirkung wird mit dem\nTausch des Pokémon beendet."),
	PSTRING("Raises the SP. Atk stat of\nPokémon in battle. Wears off if the\nPokémon is withdrawn.")
);
static u8 str_item_pokepuppe_description[] = LANGDEP(
	PSTRING("Eine hübsche Puppe. Sie ermöglicht\ndie Flucht im Kampf gegen wilde\nPokémon."),
	PSTRING("An attractive doll.\nUse it to flee from any battle with\na wild Pokémon.")
);
static u8 str_item_eneco_rute_description[] = LANGDEP(
	PSTRING("Ein tolles Item. Fliehe damit aus\njedem Kampf mit einem wilden\nPokémon."),
	PSTRING("An attractive item.\nUse it to flee from any battle with\na wild Pokémon.")
);
static u8 str_item_suessbonbon_description[] = LANGDEP(
	PSTRING("Ein zuckersüßes Bonbon, das\nein Pokémon zutraulicher\nmacht."),
	PSTRING("A very sweet candy that\nmakes a Pokémon happier.")
);
static u8 str_item_superschutz_description[] = LANGDEP(
	PSTRING("Hält 200 Schritte lang schwache, \nwilde Pokémon ab."),
	PSTRING("Prevents weak wild Pokémon from\nappearing for 200 steps.")
);
static u8 str_item_top_schutz_description[] = LANGDEP(
	PSTRING("Hält 250 Schritte lang schwache, \nwilde Pokémon ab."),
	PSTRING("Prevents weak wild Pokémon from\nappearing for 250 steps.")
);
static u8 str_item_fluchtseil_description[] = LANGDEP(
	PSTRING("Ein langes, festes Seil, das die\nsofortige Flucht aus Höhlen oder\nÄhnlichem ermöglicht."),
	PSTRING("A long, durable rope.\nUse it to escape instantly from a\ncave or a dungeon.")
);
static u8 str_item_schutz_description[] = LANGDEP(
	PSTRING("Hält 100 Schritte lang schwache, \nwilde Pokémon ab."),
	PSTRING("Prevents weak wild Pokémon from\nappearing for 100 steps.")
);
static u8 str_item_wunderstaub_description[] = LANGDEP(
	PSTRING("Weißer Puder, der Beeren\nwachsen lässt."),
	PSTRING("White powder that makes\ngrow.")
);
static u8 str_item_nullsaft_description[] = LANGDEP(
	PSTRING("Geschmackloser Saft, der alle\nverteilten Fleiß-Punkte zurücksetzt."),
	PSTRING("Tasteless juice that resets\nall distributed effort values.")
);
static u8 str_item_item_59_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_5a_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_5b_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_5c_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_sonnenstein_description[] = LANGDEP(
	PSTRING("Dieser spezielle Stein löst bei be-\nstimmten Pokémon die Entwicklung\naus. Er ist rot wie die Sonne."),
	PSTRING("A peculiar stone that makes certain\nspecies of Pokémon evolve.\nIt is as red as the sun.")
);
static u8 str_item_mondstein_description[] = LANGDEP(
	PSTRING("Dieser spezielle Stein löst bei be-\nstimmten Pokémon die Entwicklung\naus. Er ist schwarz wie die Nacht."),
	PSTRING("A peculiar stone that makes certain\nspecies of Pokémon evolve.\nIt is as black as the night sky.")
);
static u8 str_item_feuerstein_description[] = LANGDEP(
	PSTRING("Dieser spezielle Stein löst bei\nbestimmten Pokémon die\nEntwicklung aus. Er ist orange."),
	PSTRING("A peculiar stone that makes certain\nspecies of Pokémon evolve.\nIt is colored orange.")
);
static u8 str_item_donnerstein_description[] = LANGDEP(
	PSTRING("Dieser spezielle Stein löst bei be-\nstimmten Pokémon die Entwicklung\naus. Er hat ein Blitzmuster."),
	PSTRING("A peculiar stone that makes certain\nspecies of Pokémon evolve.\nIt has a thunderbolt pattern.")
);
static u8 str_item_wasserstein_description[] = LANGDEP(
	PSTRING("Dieser spezielle Stein löst bei\nbestimmten Pokémon die\nEntwicklung aus. Er ist hellblau."),
	PSTRING("A peculiar stone that makes certain\nspecies of Pokémon evolve.\nIt is a clear light blue.")
);
static u8 str_item_blattstein_description[] = LANGDEP(
	PSTRING("Dieser spezielle Stein löst bei be-\nstimmten Pokémon die Entwicklung\naus. Er hat ein Blattmuster."),
	PSTRING("A peculiar stone that makes certain\nspecies of Pokémon evolve.\nIt has a leaf pattern.")
);
static u8 str_item_linkkabel_description[] = LANGDEP(
	PSTRING("Eine Box, die einen Pokémon Tausch\nsimuliert. Manche Pokémon benötigen\nein Item zum Tragen."),
	PSTRING("?????")
);
static u8 str_item_finsterstein_description[] = LANGDEP(
	PSTRING("Dieser besondere, düstere\nStein hilft manchen Pokémon\nbei ihrer Evolution."),
	PSTRING("?????")
);
static u8 str_item_leuchtstein_description[] = LANGDEP(
	PSTRING("Dieser besondere, hell leuchtende\nStein hilft manchen Pokémon\nbei ihrer Evolution."),
	PSTRING("?????")
);
static u8 str_item_funkelstein_description[] = LANGDEP(
	PSTRING("Dieser besondere, funkelnde\nStein hilft manchen Pokémon\nbei ihrer Evolution."),
	PSTRING("?????")
);
static u8 str_item_minipilz_description[] = LANGDEP(
	PSTRING("Ein kleiner und seltener Pilz, der \nseine Liebhaber hat."),
	PSTRING("A small and rare mushroom.\nIt is quite popular among certain\npeople.")
);
static u8 str_item_riesenpilz_description[] = LANGDEP(
	PSTRING("Ein großer und seltener Pilz, der \nseine Liebhaber hat."),
	PSTRING("A large and rare mushroom.\nIt is very popular among certain\npeople.")
);
static u8 str_item_spv_orb_n_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das die\nspezielle Verteidigung eines\nPokémon langasmer steigen lässt."),
	PSTRING("A bitter herb that makes the special\ndefense of a Pokémon grow slower.")
);
static u8 str_item_perle_description[] = LANGDEP(
	PSTRING("Eine relativ kleine Perle, die in\nschönem Silber funkelt. Sie ist von\ngeringem Wert."),
	PSTRING("A relatively small pearl that\nsparkles in a pretty silver color.\nIt can be sold cheaply.")
);
static u8 str_item_riesenperle_description[] = LANGDEP(
	PSTRING("Eine relativ große Perle, die in\nschönem Silber funkelt. Sie ist von\nhohem Wert."),
	PSTRING("A quite-large pearl that sparkles\nin a pretty silver color.\nIt can be sold at a high price.")
);
static u8 str_item_sternenstaub_description[] = LANGDEP(
	PSTRING("Schöner, roter Sand, der sich\nseidenweich anfühlt. Er ist von\nhohem Wert."),
	PSTRING("A pretty red sand with a loose,\nsilky feel.\nIt can be sold at a high price.")
);
static u8 str_item_sternenstueck_description[] = LANGDEP(
	PSTRING("Ein schöner, roter Edelstein,\nder einen hohen Preis erzielen kann."),
	PSTRING("A shard of a pretty gem that\nsparkles in a red color.\nIt can be sold at a high price.")
);
static u8 str_item_nugget_description[] = LANGDEP(
	PSTRING("Ein Nugget aus purem Gold, das\neinen schimmernden Glanz besitzt. \nEs ist von großem Wert."),
	PSTRING("A nugget of pure gold that gives\noff a lustrous gleam.\nIt can be sold at a high price.")
);
static u8 str_item_herzschuppe_description[] = LANGDEP(
	PSTRING("Eine hübsche, herzförmige, sehr\nseltene Schuppe. Sie erstrahlt in\nden Farben des Regenbogens."),
	PSTRING("A pretty, heart-shaped scale that\nis extremely rare. It glows faintly\nin the colors of a rainbow.")
);
static u8 str_item_angr_orb_p_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das den Angriff\neines Pokémon schneller steigen\nlässt."),
	PSTRING("A bitter herb that makes the\nattack of a Pokémon grow faster.")
);
static u8 str_item_angr_orb_n_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das den Angriff\neines Pokémon langsamer steigen\nlässt."),
	PSTRING("A bitter herb that makes the\nattackof a Pokémon grow slower.")
);
static u8 str_item_vert_orb_p_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das die \nVerteidigung eines Pokémon\nschneller steigen lässt."),
	PSTRING("A bitter herb that makes the\ndefense of a Pokémon grow faster.")
);
static u8 str_item_vert_orb_n_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das die \nVerteidigung eines Pokémon\nlangsamer steigen lässt."),
	PSTRING("A bitter herb that makes the\ndefense of a Pokémon grow slower.")
);
static u8 str_item_init_orb_p_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das die Initiative\neines Pokémon schneller steigen\nlässt."),
	PSTRING("A bitter herb that makes the speed\nof a Pokémon grow faster.")
);
static u8 str_item_init_orb_n_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das die Initiative\neines Pokémon langsamer steigen\nlässt."),
	PSTRING("A bitter herb that makes the speed\nof a Pokémon grow slower.")
);
static u8 str_item_spa_orb_p_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das den\nspeziellen Angriff eines Pokémon\nschneller steigen lässt."),
	PSTRING("A bitter herb that makes the special\nattack of a Pokémon grow faster.")
);
static u8 str_item_spa_orb_n_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das den\nspeziellen Angriff eines Pokémon\nlangsamer steigen lässt."),
	PSTRING("A bitter herb that makes the special\nattack of a Pokémon grow slower.")
);
static u8 str_item_spv_orb_p_description[] = LANGDEP(
	PSTRING("Bitteres Kraut, das die\nspezielle Verteidigung eines\nPokémon schneller steigen lässt."),
	PSTRING("A bitter herb that makes the special\ndefense of a Pokémon grow faster.")
);
static u8 str_item_79_description[] = LANGDEP(
	PSTRING("Ein Brief mit Zigzachs-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nZigzagoon print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_hafenbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Wingull-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nWingull print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_glitzerbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Pikachu-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nPikachu print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_eilbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Magnetilo-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nMagnemite print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_waldbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Bummelz-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nSlakoth print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_wellenbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Wailmer-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nWailmer print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_perlenbrief_description[] = LANGDEP(
	PSTRING("Ein Brief, der von einem Pokémon\ngetragen werden kann und als\nAufdruck den Träger hat."),
	PSTRING("A piece of Mail to be held by a\nPokémon. It will bear the print of\nthe Pokémon holding it.")
);
static u8 str_item_dunkelbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Zwirrlicht-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nDuskull print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_tropenbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit Blubella-Aufdruck.\nEr kann von einem Pokémon\ngetragen werden."),
	PSTRING("A piece of Mail featuring a cute\nBellossom print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_traumbrief_description[] = LANGDEP(
	PSTRING("Ein Brief, der von einem Pokémon\ngetragen werden kann und als\nAufdruck den Träger hat."),
	PSTRING("A piece of Mail to be held by a\nPokémon. It will bear the print of\nthe Pokémon holding it.")
);
static u8 str_item_edelbrief_description[] = LANGDEP(
	PSTRING("Ein Brief mit einem bezaubernden,\nextravaganten Aufdruck. Er kann\nvon einem Pokémon getragen werden."),
	PSTRING("A piece of Mail featuring a\ngorgeous, extravagant print.\nIt is to be held by a Pokémon.")
);
static u8 str_item_retrobrief_description[] = LANGDEP(
	PSTRING("Brief mit dem Aufdruck dreier\nniedlicher, possierlicher\nPokémon-Gesichter."),
	PSTRING("A piece of Mail featuring a print\nof three cute Pokémon.\nIt is to be held by a Pokémon.")
);
static u8 str_item_amrenabeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) bewirkt im Kampf\nSelbstheilung bei Paralyse."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to heal paralysis.")
);
static u8 str_item_maronbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) weckt schlafendes\nPokémon im Kampf."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to wake up.")
);
static u8 str_item_pirsifbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) bewirkt im Kampf\nSelbstheilung bei Vergiftung."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to cure poison.")
);
static u8 str_item_fragiabeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) bewirkt im Kampf\nSelbstheilung bei Verbrennung."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to heal a burn.")
);
static u8 str_item_wilbirbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) bewirkt im Kampf\nSelbstheilung bei Frost."),
	PSTRING("When held by a Pokémon, it will be\nused in battle for defrosting.")
);
static u8 str_item_jonagobeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt AP im Kampf um\n10 Punkte auf."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to restore 10 PP.")
);
static u8 str_item_sinelbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt KP im Kampf um\n10 Punkte auf."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to restore 10 HP.")
);
static u8 str_item_persimbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) bewirkt im Kampf\nSelbstheilung bei Verwirrung."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to lift confusion.")
);
static u8 str_item_prunusbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) bewirkt im Kampf\nSelbstheilung bei Statusproblem."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to heal any problem.")
);
static u8 str_item_tsitrubeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt KP im Kampf um\n30 Punkte auf."),
	PSTRING("When held by a Pokémon, it will be\nused in battle to restore 30 HP.")
);
static u8 str_item_giefebeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt im Kampf KP\nauf, bewirkt aber evtl. Verwirrung."),
	PSTRING("A hold item that restores HP but\nmay cause confusion when used.")
);
static u8 str_item_wikibeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt im Kampf KP\nauf, bewirkt aber evtl. Verwirrung."),
	PSTRING("A hold item that restores HP but\nmay cause confusion when used.")
);
static u8 str_item_magobeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt im Kampf KP\nauf, bewirkt aber evtl. Verwirrung."),
	PSTRING("A hold item that restores HP but\nmay cause confusion when used.")
);
static u8 str_item_gauvebeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt im Kampf KP\nauf, bewirkt aber evtl. Verwirrung."),
	PSTRING("A hold item that restores HP but\nmay cause confusion when used.")
);
static u8 str_item_yapabeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) füllt im Kampf KP\nauf, bewirkt aber evtl. Verwirrung."),
	PSTRING("A hold item that restores HP but\nmay cause confusion when used.")
);
static u8 str_item_himmihbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nNormal Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Normal\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_morbbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nKampf Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Kampf\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_nanabbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nFlug Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Flug\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_nirbebeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nGift Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Gift\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_sananabeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nBoden Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Boden\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_granabeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nGestein Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Gestein\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_setangbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nKaefer Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Kaefer\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_qualotbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nGeist Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Geist\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_honmelbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nStahl Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Stahl\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_labrusbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nFee Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Fee\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_tamotbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nFeuer Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Feuer\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_saimbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nWasser Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Wasser\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_magostbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nPflanze Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Pflanze\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_rabutabeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nElektro Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Elektro\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_tronzibeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nPsycho Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Psycho\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_kiwanbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nEis Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Eis\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_pallmbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nDrache Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Drache\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_wasmelbeere_description[] = LANGDEP(
	PSTRING("Schwächt gegnerische sehr effektive\nUnlicht Angriffe, wenn es\ngetragen wird."),
	PSTRING("Weakens very effective Unlicht\nattacks of opponents when\nbeing hold.")
);
static u8 str_item_durinbeere_description[] = LANGDEP(
	PSTRING("Kann zu einem Pulver gemahlen\nwerden, um Medizin herzustellen."),
	PSTRING("Can be ground up into a powder as\nan ingredient for medicine.")
);
static u8 str_item_myrtilbeere_description[] = LANGDEP(
	PSTRING("Kann zu einem Pulver gemahlen\nwerden, um Medizin herzustellen."),
	PSTRING("Can be ground up into a powder as\nan ingredient for medicine.")
);
static u8 str_item_lydzibeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt Angr.-Wert\nin einer Notlage."),
	PSTRING("When held by a Pokémon, it raises\nthe Attack stat in a pinch.")
);
static u8 str_item_linganbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt Vert.-Wert\nin einer Notlage."),
	PSTRING("When held by a Pokémon, it raises\nthe Defense stat in a pinch.")
);
static u8 str_item_salkabeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt Init.-Wert\nin einer Notlage."),
	PSTRING("When held by a POKéMON, it raises\nthe Speed stat in a pinch.")
);
static u8 str_item_tahaybeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt SP. Ang.-Wert\nin einer Notlage."),
	PSTRING("When held by a Pokémon, it raises\nthe SP. Atk stat in a pinch.")
);
static u8 str_item_apikobeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt SP. Ver.-Wert\nin einer Notlage."),
	PSTRING("When held by a Pokémon, it raises\nthe SP. Def stat in a pinch.")
);
static u8 str_item_lansatbeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt Volltrefferquote\nin einer Notlage."),
	PSTRING("When held by a Pokémon, it raises\nthe critical-hit ratio in a pinch.")
);
static u8 str_item_krambobeere_description[] = LANGDEP(
	PSTRING("Item (Tragen) hebt einen Statuswert\nin einer Notlage."),
	PSTRING("When held by a Pokémon, it sharply\nraises one stat in a pinch.")
);
static u8 str_item_enigmabeere_description[] = LANGDEP(
	PSTRING("Kann zu einem Pulver gemahlen\nwerden, um Medizin herzustellen."),
	PSTRING("Can be ground up into a powder as\nan ingredient for medicine.")
);
static u8 str_item_item_b0_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_wahlglas_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_wahlschal_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_blendpuder_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nsenkt die Genauigkeit des Gegners."),
	PSTRING("An item to be held by a Pokémon.\nIt casts a tricky glare that lowers\nthe opponent’s accuracy.")
);
static u8 str_item_schlohkraut_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nhebt jede Statusveränderung auf."),
	PSTRING("An item to be held by a Pokémon.\nIt restores any lowered stat in\nbattle. It can be used only once.")
);
static u8 str_item_machoband_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nfördert Wachstum, aber senkt Init."),
	PSTRING("An item to be held by a POKéMON.\nIt promotes strong growth but\nlowers Speed while it is held.")
);
static u8 str_item_ep_teiler_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nteilt die Kampf-E.-Punkte."),
	PSTRING("An item to be held by a Pokémon.\nThe holder gets a share of Exp.\npoints without having to battle.")
);
static u8 str_item_flinkklaue_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nhebt die Erstschlagquote."),
	PSTRING("An item to be held by a Pokémon.\nA light and sharp claw. The holder\nmay be able to strike first.")
);
static u8 str_item_sanftglocke_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nbesänftigt und fördert Sympathie."),
	PSTRING("An item to be held by a Pokémon.\nA bell with a comforting chime that\nmakes the holder calm and friendly.")
);
static u8 str_item_mentalkraut_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nerlöst Pokémon von Anziehung."),
	PSTRING("An item to be held by a Pokémon.\nIt snaps the holder out of\ninfatuation. It can be used once.")
);
static u8 str_item_wahlband_description[] = LANGDEP(
	PSTRING("Ein Item, das ein Pokémon tragen\nkann. Es stärkt eine Attacke. Aber\nnur diese ist einsetzbar."),
	PSTRING("An item to be held by a Pokémon.\nIt powers up one move, which\nbecomes the only usable one.")
);
static u8 str_item_king_stein_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nkann Gegner zurückweichen lassen."),
	PSTRING("An item to be held by a Pokémon.\nIt may cause the foe to flinch\nupon taking damage.")
);
static u8 str_item_silberstaub_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverbessert Käfer-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA shiny silver powder that boosts\nthe power of Bug-type moves.")
);
static u8 str_item_muenzamulett_description[] = LANGDEP(
	PSTRING("Ein Item, das ein Pokémon trägt\nund das doppeltes Preisgeld bringt,\nwenn der Träger am Kampf teilnimmt."),
	PSTRING("An item to be held by a Pokémon.\nIt doubles the battle money if the\nholding Pokémon takes part.")
);
static u8 str_item_schutzband_description[] = LANGDEP(
	PSTRING("Ein Item, das ein Pokémon trägt. Es\nkann wilde Pokémon abhalten, wenn\nder Träger an erster Stelle steht."),
	PSTRING("An item to be held by a Pokémon.\nIt repels wild Pokémon if the\nholder is first in the party.")
);
static u8 str_item_seelentau_description[] = LANGDEP(
	PSTRING("Ein Item, das von Latios oder\nLatias getragen werden kann. Es\nhebt SP. Ang. & SP. Ver."),
	PSTRING("An orb to be held by a Latios or\nLatias. It raises the SP. Atk\nand SP. Def stats.")
);
static u8 str_item_abysszahn_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nhebt SP. Ang. für Perlu!"),
	PSTRING("An item to be held by a Pokémon.\nA fang that gleams a sharp silver.\nIt raises the SP. Atk stat.")
);
static u8 str_item_abyssplatte_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nhebt SP. Ver. für Perlu!"),
	PSTRING("An item to be held by a Pokémon.\nA scale that shines a faint pink.\nIt raises the SP. Def stat.")
);
static u8 str_item_rauchball_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann.\nFluchtgarantie vor wilden Pokémon."),
	PSTRING("An item to be held by a Pokémon.\nThe holding Pokémon can flee from\nany wild Pokémon for sure.")
);
static u8 str_item_ewigstein_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nbewirkt Entwicklungsstopp."),
	PSTRING("An item to be held by a Pokémon.\nThe holding Pokémon is prevented\nfrom evolving.")
);
static u8 str_item_fokus_band_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nkann manchmal ein K.O. verhindern."),
	PSTRING("An item to be held by a Pokémon.\nThe holding Pokémon may endure an\nattack, leaving just 1 HP.")
);
static u8 str_item_gluecks_ei_description[] = LANGDEP(
	PSTRING("Ein Item, das ein Pokémon\nträgt, um Extra-E.-Punkte\nim Kampf zu erhalten."),
	PSTRING("An item to be held by a Pokémon.\nAn egg filled with happiness that\nearns extra Exp. points in battle.")
);
static u8 str_item_scope_linse_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nerhöht die Volltrefferquote."),
	PSTRING("An item to be held by a Pokémon.\nA lens that boosts the critical-hit\nratio of the holding Pokémon.")
);
static u8 str_item_metallmantel_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Stahl-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA special metallic film that boosts\nthe power of Steel-type moves.")
);
static u8 str_item_ueberreste_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nfüllt im Kampf stetig KP auf."),
	PSTRING("An item to be held by a Pokémon.\nThe holding Pokémon gradually\nregains HP during battle.")
);
static u8 str_item_drachenhaut_description[] = LANGDEP(
	PSTRING("Seltsame Haut zum Tragen\nfür Pokémon der Elementklasse\nDrache."),
	PSTRING("A thick and tough scale.\nA Dragon-type Pokémon may be\nholding it.")
);
static u8 str_item_kugelblitz_description[] = LANGDEP(
	PSTRING("Ein Item, das von Pikachu\ngetragen werden kann. Es erhöht\nseinen SP. Ang.-Wert."),
	PSTRING("An orb to be held by a Pikachu\nthat raises the SP. Atk stat.\nTouching it may cause a shock.")
);
static u8 str_item_pudersand_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Boden-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA loose, silky sand that boosts the\npower of Ground-type moves.")
);
static u8 str_item_granitstein_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Gestein-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nAn unbreakable stone that boosts\nthe power of Rock-type moves.")
);
static u8 str_item_wundersaat_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Pflanzen-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA seed imbued with life that boosts\nthe power of Grass-type moves.")
);
static u8 str_item_schattenglas_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Unlicht-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA shady-looking pair of glasses\nthat boosts Dark-type moves.")
);
static u8 str_item_schwarzgurt_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Kampf-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA belt that boosts determination\nand Fighting-type moves.")
);
static u8 str_item_magnet_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Elektro-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA powerful magnet that boosts the\npower of Electric-type moves.")
);
static u8 str_item_zauberwasser_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Wasser-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA teardrop-shaped gem that boosts\nthe power of Water-type moves.")
);
static u8 str_item_hackattack_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Flug-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA long, sharp beak that boosts the\npower of Flying-type moves.")
);
static u8 str_item_giftstich_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Gift-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA small, poisonous barb that boosts\nthe power of Poison-type moves.")
);
static u8 str_item_ewiges_eis_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Eis-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA piece of ice that repels heat\nand boosts Ice-type moves.")
);
static u8 str_item_bannsticker_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Geist-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA sinister, eerie tag that boosts\nGhost-type moves.")
);
static u8 str_item_kruemmloeffel_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Psycho-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA spoon imbued with telekinetic\npower boosts Psychic-type moves.")
);
static u8 str_item_holzkohle_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Feuer-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA combustible fuel that boosts the\npower of Fire-type moves.")
);
static u8 str_item_drachenzahn_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Drache-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA hard and sharp fang that boosts\nthe power of Dragon-type moves.")
);
static u8 str_item_seidenschal_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Normal-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nA sumptuous scarf that boosts the\npower of Normal-type moves.")
);
static u8 str_item_up_grade_description[] = LANGDEP(
	PSTRING("Ein Softwareupdate für das\nvirtuelle Pokémon Porygon."),
	PSTRING("A transparent device filled with all\nsorts of data.\nIt is made by Silph Co.")
);
static u8 str_item_seegesang_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nfüllt im Kampf stetig KP auf."),
	PSTRING("An item to be held by a Pokémon.\nThe holding Pokémon regains some\nHP upon striking the foe.")
);
static u8 str_item_seerauch_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nverstärkt Wasser-Attacken."),
	PSTRING("An item to be held by a Pokémon.\nIt slightly boosts the power of\nWater-type moves.")
);
static u8 str_item_laxrauch_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nsenkt Genauigkeit des Gegners."),
	PSTRING("An item to be held by a Pokémon.\nIts tricky aroma slightly reduces\nthe foe’s accuracy.")
);
static u8 str_item_lucky_punch_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nerhöht Chaneiras Volltrefferquote."),
	PSTRING("A glove to be held by a Chansey.\nIt raises Chansey’s critical-hit\nratio.")
);
static u8 str_item_metallstaub_description[] = LANGDEP(
	PSTRING("Ein Item, das einem Pokémon zum\nTragen gegeben werden kann. Es\nerhöht den Vert.-Wert von Ditto."),
	PSTRING("A fine, hard powder to be held by\na Ditto.\nIt raises Ditto’s Defense stat.")
);
static u8 str_item_kampfknochen_description[] = LANGDEP(
	PSTRING("Ein harter Knochen, der den Angr.-\nWert von Tragosso oder Knogga\nerhöht, wenn sie ihn tragen."),
	PSTRING("A hard bone of some sort to be\nheld by a Cubone or Marowak.\nIt raises the Attack stat.")
);
static u8 str_item_lauchstange_description[] = LANGDEP(
	PSTRING("Diese Lauchstange erhöht die\nVolltrefferquote, wenn Porenta\nsie trägt."),
	PSTRING("A stick of leek to be held by a\nFarfetch’D. It raises Farfetch’D’s\ncritical-hit ratio.")
);
static u8 str_item_bisaflornit_description[] = LANGDEP(
	PSTRING("Wird er von einem Bisaflor\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("?????")
);
static u8 str_item_gluraknit_description[] = LANGDEP(
	PSTRING("Wird er von einem Glurak\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("?????")
);
static u8 str_item_turtoknit_description[] = LANGDEP(
	PSTRING("Wird er von einem Turtok\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("?????")
);
static u8 str_item_terrasornit_description[] = LANGDEP(
	PSTRING("Einer der seltenen Mega-Steine.\nGetragen von Terasorus könnte man\nmittels des Mega-Amuletts..."),
	PSTRING("?????")
);
static u8 str_item_zerbernit_description[] = LANGDEP(
	PSTRING("Einer der seltenen Mega-Steine.\nGetragen von Zerbertres könnte man\nmittels des Mega-Amuletts..."),
	PSTRING("?????")
);
static u8 str_item_skullydranit_description[] = LANGDEP(
	PSTRING("Einer der seltenen Mega-Steine.\nGetragen von Skullydra könnte man\nmittels des Mega-Amuletts..."),
	PSTRING("?????")
);
static u8 str_item_aquananit_description[] = LANGDEP(
	PSTRING("Einer der seltenen Mega-Steine.\nGetragen von Aquana könnte man\nmittels des Mega-Amuletts..."),
	PSTRING("?????")
);
static u8 str_item_flamaranit_description[] = LANGDEP(
	PSTRING("Einer der seltenen Mega-Steine.\nGetragen von Flamara könnte man\nmittels des Mega-Amuletts..."),
	PSTRING("?????")
);
static u8 str_item_blitzanit_description[] = LANGDEP(
	PSTRING("Einer der seltenen Mega-Steine.\nGetragen von Blitza könnte man\nmittels des Mega-Amuletts..."),
	PSTRING("?????")
);
static u8 str_item_ampharosnit_description[] = LANGDEP(
	PSTRING("Wird er von einem Ampharos\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("?????")
);
static u8 str_item_gengarnit_description[] = LANGDEP(
	PSTRING("Wird er von einem Gengar\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("?????")
);
static u8 str_item_bibornit_description[] = LANGDEP(
	PSTRING("Wird er von einem Bibor\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("?????")
);
static u8 str_item_magmaherz_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_geowaznit_description[] = LANGDEP(
	PSTRING("Wird er von einem Geowaz\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("If held by a Golem in\nbattle it can perform\na mega evolution.")
);
static u8 str_item_tropiusnit_description[] = LANGDEP(
	PSTRING("Wird er von einem Tropius\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("If held by a Tropius in\nbattle it can perform\na mega evolution.")
);
static u8 str_item_octillerynit_description[] = LANGDEP(
	PSTRING("Wird er von einem Octillery\ngetragen, kann es im Kampf eine\nMega-Entwicklung durchführen."),
	PSTRING("If held by an Octillery in\nbattle it can perform\na mega evolution.")
);
static u8 str_item_item_f2_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_f3_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_f4_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_f5_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_f6_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_item_f7_description[] = LANGDEP(
	PSTRING(" ????"),
	PSTRING("?????")
);
static u8 str_item_lahmrauch_description[] = LANGDEP(
	PSTRING("Ein Item, das den Träger\nstets später angreifen lässt."),
	PSTRING("An item to be held by a Pokémon\nto make it attack last.")
);
static u8 str_item_eisbrocken_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen, das die\nDauer von Hagelsturm verlängert."),
	PSTRING("An item to be held by a Pokémon.\nIt extends the duration of hail.")
);
static u8 str_item_nassbrocken_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen, das die\nDauer von Regentanz verlängert."),
	PSTRING("An item to be held by a Pokémon.\nIt extends the duration of rain.")
);
static u8 str_item_glattbrocken_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen, das die\nDauer von Sandsturm verlängert."),
	PSTRING("An item to be held by a Pokémon.\nIt extends the duration of sandstrom.")
);
static u8 str_item_heissbrocken_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen, das die\nDauer von Sonnentag verlängert."),
	PSTRING("An item to be held by a Pokémon.\nIt extends the duration of sunshine.")
);
static u8 str_item_lichtlehm_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen. Verlängert\ndie Dauer von Lichtschild und\nReflektor."),
	PSTRING("An item to be held by a Pokémon.\nExtends the duration of Light Screen\nand Reflect.")
);
static u8 str_item_steinrauch_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen, welches\nGestein Attacken verstärkt."),
	PSTRING("An item to be held by a Pokémon.\pIt boosts Rock type attacks.")
);
static u8 str_item_scheuchrauch_description[] = LANGDEP(
	PSTRING("Ein Item, das ein Pokémon trägt. Es\nkann wilde Pokémon abhalten, wenn\nder Träger an erster Stelle steht."),
	PSTRING("An item to be held by a Pokémon.\pIt mitigates wild encounters.")
);
static u8 str_item_gluecksrauch_description[] = LANGDEP(
	PSTRING("Wird es im Kampf getragen, geben\nTrainer mehr Preisgeld."),
	PSTRING("An item to be held by a Pokémon.\pDoubles the price money reward.")
);
static u8 str_item_koeder_description[] = LANGDEP(
	PSTRING("Erhöht beim Angeln die Chance,\ndass starke Pokémon anbeißen."),
	PSTRING("Increases the chance to find\nstrong Pokémon when fishing.")
);
static u8 str_item_goldkoeder_description[] = LANGDEP(
	PSTRING("Erhöht beim Angeln drastisch\ndie Chance, dass starke Pokémon\nanbeißen."),
	PSTRING("Drastically increases the\nchance of finding strong\nPokémon when fishing.")
);
static u8 str_item_leuchtkoeder_description[] = LANGDEP(
	PSTRING("Legendärer Köder, der\nbeim Angeln schillernde Pokémon\nanlockt."),
	PSTRING("A legendary bait that\nis used to catch shiny\nPokémon when fishing.")
);
static u8 str_item_muenzkorb_description[] = LANGDEP(
	PSTRING("Im Korb finden bis zu 9999\nMünzen für die Spielhalle\nPlatz."),
	PSTRING("A case for holding Coins obtained\nat the Game Corner.\nIt holds up to 9,999 Coins.")
);
static u8 str_item_detektor_description[] = LANGDEP(
	PSTRING("Ein Gerät, das verborgene Items\nvia Schallwellen ortet."),
	PSTRING("A device used for finding items.\nIf there is a hidden item nearby\nwhen it is used, it emits a signal.")
);
static u8 str_item_angel_description[] = LANGDEP(
	PSTRING("Damit kannst du in jedem Gewässer\nnach Pokémon angeln."),
	PSTRING("An old and beat-up fishing rod.\nUse it by any body of water to \nfish for wild Pokémon.")
);
static u8 str_item_profiangel_description[] = LANGDEP(
	PSTRING("Eine recht gute Angel, um Pokémon\nzu fangen."),
	PSTRING("A new, good-quality fishing rod.\nUse it by any body of water to \nfish for wild Pokémon.")
);
static u8 str_item_superangel_description[] = LANGDEP(
	PSTRING("Eine wundervoll gefertigte Angel.\nDie beste Angel, um nach\nPokémon zu fischen."),
	PSTRING("An awesome, high-tech fishing rod.\nUse it by any body of water to fish\nfor wild Pokémon.")
);
static u8 str_item_bootsticket_description[] = LANGDEP(
	PSTRING("Ein Ticket, um auf der M.S. Anne\nzu fahren. Eine Zeichnung der\nFähre ist auf dem Ticket zu sehen."),
	PSTRING("The ticket required for sailing on\nthe ferry S.S. Anne.\nIt has a drawing of a ship on it.")
);
static u8 str_item_wettb_karte_description[] = LANGDEP(
	PSTRING("Ausweis zur Teilnahme an Pokémon-\nWettbewerben. Die Zeichnung\neines Bandes ist aufgedruckt."),
	PSTRING("The pass required for entering\nPokémon Contests. It has a\ndrawing of an award ribbon on it.")
);
static u8 str_item_item_10b_description[] = LANGDEP(
	PSTRING("Ein antikes Relikt, das zwar aus\nStein ist, sich aber weich anfühlt."),
	PSTRING("?????")
);
static u8 str_item_wailmerkanne_description[] = LANGDEP(
	PSTRING("Ein Gegenstand zum Gießen von\nPflanzen, wie beispielsweise Beeren."),
	PSTRING("A nifty watering pail.\nUse it to promote strong growth in\nBerries planted in soft soil.")
);
static u8 str_item_devon_waren_description[] = LANGDEP(
	PSTRING("Ein Päckchen, das Maschinenteile\nder Devon Corp. enthält."),
	PSTRING("A package that contains mechanical\nparts of some sort made by the\nDevon Corporation.")
);
static u8 str_item_aschetasche_description[] = LANGDEP(
	PSTRING("Ein Säckchen zum Sammeln und\nAufbewahren von Vulkanasche."),
	PSTRING("A sack used to collect volcanic\nash automatically during walks\nover deep ash.")
);
static u8 str_item_geisterschluessel_description[] = LANGDEP(
	PSTRING("Mysteriöser Schlüssel, der\näußerst alt wirkt."),
	PSTRING("The key to New Mauville, which\nwas constructed beneath Mauville\nCity.")
);
static u8 str_item_kunstrad_description[] = LANGDEP(
	PSTRING("Dieses Klapprad ermöglicht Sprünge\nund Wheelies."),
	PSTRING("A folding bicycle that is capable\nof stunts like jumps and wheelies.")
);
static u8 str_item_box_description[] = LANGDEP(
	PSTRING("Box für , die im Beerenmixer\nhergestellt werden. Wird sie ge-\nschüttelt, spendet sie einen Riegel."),
	PSTRING("A case for holding Pokéblocks made\nwith a Berry Blender. It releases\none Pokéblock when shaken.")
);
static u8 str_item_brief_description[] = LANGDEP(
	PSTRING("Ein äußerst wichtiger Brief an Troy,\nvom Präsidenten der Devon Corp."),
	PSTRING("An extremely important letter to\nSteven from the President of the\nDevon Corporation.")
);
static u8 str_item_aeon_ticket_description[] = LANGDEP(
	PSTRING("Das Bootsticket zu einer fernen\nInsel im Süden. Eine Zeichnung\nder Insel ist aufgedruckt."),
	PSTRING("The ticket required for sailing on a\nferry to a distant southern island.\nIt features a drawing of an island.")
);
static u8 str_item_spiritkern_description[] = LANGDEP(
	PSTRING("Ein merkwürdiger Gesteinsbrocken,\numgeben von etwas Bösem."),
	PSTRING("An orb that glows red.\nIt is said to contain an incredible\npower from ancient times.")
);
static u8 str_item_blaue_kugel_description[] = LANGDEP(
	PSTRING("Eine blau glühende Kugel, die eine\nuralte Macht bergen soll."),
	PSTRING("An orb that glows blue.\nIt is said to contain an incredible\npower from ancient times.")
);
static u8 str_item_scanner_description[] = LANGDEP(
	PSTRING("Ein Gerät, mit dem man im Wasser\nnach Lebewesen sucht. Seine\nBedienung ist schwierig."),
	PSTRING("A device used to search for\nlife-forms in water.\nIt looks too difficult to use.")
);
static u8 str_item_wuestenglas_description[] = LANGDEP(
	PSTRING("Eine Schutzbrille, die es Trainern\nermöglicht, selbst bei Sandstürmen\nWüsten zu durchqueren."),
	PSTRING("A pair of protective goggles.\nThey enable a Trainer to travel\nthrough even desert sandstorms.")
);
static u8 str_item_meteorit_description[] = LANGDEP(
	PSTRING("Ein Meteorit, der im Mondberg\naufschlug. Ein sehr harter Klumpen."),
	PSTRING("A meteorite that fell from space\nonto MT. Moon long ago.\nIt is very lumpy and hard.")
);
static u8 str_item_goldschluessel_description[] = LANGDEP(
	PSTRING("Ein goldener Schlüssel, der\ndas Tor zum Turm des Schlosses\nArdeal öffnet."),
	PSTRING("A key that opens the door to the\ntower of the castle Ardeal.")
);
static u8 str_item_zellenschluessel_description[] = LANGDEP(
	PSTRING("Ein Schlüsselbund für Zellen\nauf der Schattenflut."),
	PSTRING("A key that unlocks\nthe cells on the Shadow Flood.")
);
static u8 str_item_k4_schluessel_description[] = LANGDEP(
	PSTRING("Der Schlüssel zur Kabine 4\nauf dem Schiffswrack. Er sieht\nalt und zerbrechlich aus."),
	PSTRING("A key that opens the door to Room\n4 inside the Abandoned Ship.\nIt is old and looks easily broken.")
);
static u8 str_item_k6_schluessel_description[] = LANGDEP(
	PSTRING("Der Schlüssel zur Kabine 6\nauf dem Schiffswrack. Er sieht\nalt und zerbrechlich aus."),
	PSTRING("A key that opens the door to Room\n6 inside the Abandoned Ship.\nIt is old and looks easily broken.")
);
static u8 str_item_l_schluessel_description[] = LANGDEP(
	PSTRING("Der Schlüssel zum Lagerraum im\nSchiffswrack. Er sieht alt und\nzerbrechlich aus."),
	PSTRING("A key that opens the storage hold\ninside the Abandoned Ship.\nIt is old and looks easily broken.")
);
static u8 str_item_wurzelfossil_description[] = LANGDEP(
	PSTRING("Das Fossil eines uralten Pokémon,\ndas in der Tiefsee lebte. Es sieht\nwie eine Pflanzenwurzel aus."),
	PSTRING("A fossil of an ancient, seafloor-\ndwelling Pokémon. It appears to be\npart of a plant root.")
);
static u8 str_item_klauenfossil_description[] = LANGDEP(
	PSTRING("Das Fossil eines uralten Pokémon,\ndas in der Tiefsee lebte. Es sieht\nwie eine Klaue aus."),
	PSTRING("A fossil of an ancient, seafloor-\ndwelling Pokémon. It appears to be\npart of a claw.")
);
static u8 str_item_devon_scope_description[] = LANGDEP(
	PSTRING("Ein Gerät der Devon Corp., \ndas unsichtbare Pokémon\nentlarvt."),
	PSTRING("A scope that signals the presence\nof any unseeable Pokémon.\nIt is made by the Devon Corp.")
);
static u8 str_item_tm01_description[] = LANGDEP(
	PSTRING(" ngriff, der zu-\nletzt erfolgt. Der\nAnwender schreckt\nevtl. zurück."),
	PSTRING("An attack that is\nexecuted last.\nThe user flinches\nif hit beforehand.")
);
static u8 str_item_tm02_description[] = LANGDEP(
	PSTRING("Der Gegner wird mit\nriesigen, scharfen\nKlauen stark\nverletzt."),
	PSTRING("Sharp, huge claws\nhook and slash the\nfoe quickly and\nwith great power.")
);
static u8 str_item_tm03_description[] = LANGDEP(
	PSTRING(" ngriff mit Wasser-\nwelle, die den\nGegner evtl.\nverwirren kann."),
	PSTRING("An attack with a\npulsing blast of\nwater. It may also\nconfuse the foe.")
);
static u8 str_item_tm04_description[] = LANGDEP(
	PSTRING("Erhöht SP. Ang.\nund SP. Ver.\ndurch\nKonzentration."),
	PSTRING("The user focuses\nits mind to raise\nthe SP. Atk and\nSP. Def stats.")
);
static u8 str_item_tm05_description[] = LANGDEP(
	PSTRING("Verjagt den Gegner\nund beendet den\nKampf in der\nWildnis."),
	PSTRING("The foe is made to\nswitch out with an\nally. In the wild,\nthe battle ends.")
);
static u8 str_item_tm06_description[] = LANGDEP(
	PSTRING(" ergiftet den\nGegner mit\neinem potenten\nToxin."),
	PSTRING("A move that badly\npoisons the foe.\nIts poison damage\nworsens every turn.")
);
static u8 str_item_tm07_description[] = LANGDEP(
	PSTRING("Hagelsturm für 5\nRunden. Schadet\nallen, außer\nEis-Pokémon."),
	PSTRING("A hailstorm lasting\nfive turns damages\nall Pokémon except\nthe Ice-type.")
);
static u8 str_item_tm08_description[] = LANGDEP(
	PSTRING("Pumpt den Körper\nauf, um den Angr.\nund die Vert. \nzu erhöhen."),
	PSTRING("The user bulks up\nits body to boost\nboth its Attack and\nDefense stats.")
);
static u8 str_item_tm09_description[] = LANGDEP(
	PSTRING("Verschießt 2 bis 5\nSamen gleichzeitig\nauf den Gegner."),
	PSTRING("The user shoots\nseeds at the foe.\nTwo to five seeds\nare shot at once.")
);
static u8 str_item_tm10_description[] = LANGDEP(
	PSTRING("Die Wirkung und\nElementklasse der\nAttacke hängt\nvom Benutzer ab."),
	PSTRING("An attack that\nvaries in type and\nintensity depending\non the user.")
);
static u8 str_item_tm11_description[] = LANGDEP(
	PSTRING(" rhöht Stärke\nvon Feuer-\nAttacken 5\nRunden lang."),
	PSTRING("The sun blazes for\nfive turns, powering\nup Fire-type\nmoves.")
);
static u8 str_item_tm12_description[] = LANGDEP(
	PSTRING("Legt den Gegner\nrein. Er benutzt\nnur noch Angriffe."),
	PSTRING("The foe is taunted\ninto a rage that\nallows it to use\nonly attack moves.")
);
static u8 str_item_tm13_description[] = LANGDEP(
	PSTRING(" er Gegner wird von\neinem Eisstrahl\ngetroffen und\nfriert evtl. ein."),
	PSTRING("The foe is struck\nwith an icy beam.\nIt may freeze the\nfoe solid.")
);
static u8 str_item_tm14_description[] = LANGDEP(
	PSTRING("Ein Schneesturm,\nder den Gegner\neinfrieren kann,\nwütet."),
	PSTRING("The foe is blasted\nwith a blizzard.\nIt may freeze the\nfoe solid.")
);
static u8 str_item_tm15_description[] = LANGDEP(
	PSTRING("Starke Attacke, die\nden Angreifer\nzwingt, eine Runde\nauszusetzen."),
	PSTRING("A severely damaging\nattack that makes\nthe user rest on\nthe next turn.")
);
static u8 str_item_tm16_description[] = LANGDEP(
	PSTRING("Erzeugt Lichtwand\nund senkt Schaden\ndurch SP. Ang.\nfür 5 Runden."),
	PSTRING("A wall of light\ncuts damage from\nSP. Atk attacks\nfor five turns.")
);
static u8 str_item_tm17_description[] = LANGDEP(
	PSTRING("Anwender weicht\njeder Attacke aus.\nScheitert evtl. bei\nWiederholung."),
	PSTRING("Enables the user to\nevade all attacks.\nIt may fail if used\nin succession.")
);
static u8 str_item_tm18_description[] = LANGDEP(
	PSTRING("Erhöht Stärke\nvon Wasser-\nAttacken 5 \nRunden lang."),
	PSTRING("A heavy rain falls\nfor five turns,\npowering up Water-\ntype moves.")
);
static u8 str_item_tm19_description[] = LANGDEP(
	PSTRING(" tarke Attacke!\nAbsorbiert die\nHälfte des ange-\nrichteten Schadens."),
	PSTRING("A harsh attack that\nabsorbs half the\ndamage it inflicted\nto restore HP.")
);
static u8 str_item_tm20_description[] = LANGDEP(
	PSTRING(" eam d. Anwenders\nist 5 Runden vor\nStatusproblemen\ngeschützt."),
	PSTRING("It protects the\nuser’s party from\nall status problems\nfor five turns.")
);
static u8 str_item_tm21_description[] = LANGDEP(
	PSTRING("Die Attacke ist\nstärker bei\nverhassten\nTRAINERn."),
	PSTRING("This attack move\ngrows more powerful\nthe less the user\nlikes its Trainer.")
);
static u8 str_item_tm22_description[] = LANGDEP(
	PSTRING("Absorbiert Licht in\nder 1. Runde.\nIn Runde 2\nerfolgt der Angriff."),
	PSTRING("A 2-turn move that\nblasts the foe with\nabsorbed energy in\nthe 2nd turn.")
);
static u8 str_item_tm23_description[] = LANGDEP(
	PSTRING("Attacke mit hartem\nEisenschweif.\nSenkt evtl. den\nVert.-Wert."),
	PSTRING("An attack with a\nsteel-hard tail.\nIt may lower the\nfoe’s Defense stat.")
);
static u8 str_item_tm24_description[] = LANGDEP(
	PSTRING("Eine starke\nElektro-Attacke,\ndie den Gegner\nevtl. paralysiert."),
	PSTRING("A strong electrical\nattack that may\nalso leave the foe\nparalyzed.")
);
static u8 str_item_tm25_description[] = LANGDEP(
	PSTRING("Eine verheerende\nElektro-Attacke,\ndie den Gegner\nevtl. paralysiert."),
	PSTRING("A brutal lightning\nattack that may\nalso leave the foe\nparalyzed.")
);
static u8 str_item_tm26_description[] = LANGDEP(
	PSTRING("Ein mächtiges\nBeben, das außer\nfliegende Gegner\nalle trifft."),
	PSTRING("An earthquake that\nstrikes all Pokémon\nin battle excluding\nthe user.")
);
static u8 str_item_tm27_description[] = LANGDEP(
	PSTRING("Angriff, dessen\nKraft bei Freund-\nschaft zum Trai-\nner größer wird."),
	PSTRING("This attack move\ngrows more powerful\nthe more the user\nlikes its Trainer.")
);
static u8 str_item_tm28_description[] = LANGDEP(
	PSTRING("1. Runde eingrab-\nen und 2. an-\ngreifen. Flucht\naus Höhlen möglich."),
	PSTRING("An attack that hits\non the 2nd turn.\nCan also be used\nto exit dungeons.")
);
static u8 str_item_tm29_description[] = LANGDEP(
	PSTRING("Starke Psycho-\nAttacke, die evtl.\ndie SP. Ver.\nsenkt."),
	PSTRING("A strong telekinetic\nattack. It may also\nlower the foe’s\nSP. Def stat.")
);
static u8 str_item_tm30_description[] = LANGDEP(
	PSTRING("Bewirft Gegner mit\ngruseligem Ball\nund senkt evtl.\ndie SP. Ver."),
	PSTRING("A shadowy blob is\nhurled at the foe.\nMay also lower the\nfoe’s SP. Def.")
);
static u8 str_item_tm31_description[] = LANGDEP(
	PSTRING("Durchbricht Barri-\neren wie Licht-\nschild und\nReflektor."),
	PSTRING("An attack that also\nbreaks any barrier\nlike Light Screen\nand Reflect.")
);
static u8 str_item_tm32_description[] = LANGDEP(
	PSTRING("Erzeugt Eben-\nbilder, um \nFluchtwert\nzu erhöhen."),
	PSTRING("The user creates\nillusory copies of\nitself to raise its\nevasiveness.")
);
static u8 str_item_tm33_description[] = LANGDEP(
	PSTRING("Lichtwand, die\n5 Runden leicht\nvor physischen\nAngriffen schützt."),
	PSTRING("A wall of light\ncuts damage from\nphysical attacks\nfor five turns.")
);
static u8 str_item_tm34_description[] = LANGDEP(
	PSTRING("Angriff mit schnel-\nlem Elektro-Schlag.\nAusweichen nicht\nmöglich."),
	PSTRING("A rapid jolt of\nelectricity strikes\nthe foe. It can’t\nbe evaded.")
);
static u8 str_item_tm35_description[] = LANGDEP(
	PSTRING("Starke Feuer-\nAttacke, die evtl.\nden Gegner\nverbrennt."),
	PSTRING("The foe is scorched\nwith intense flames.\nThe foe may suffer\na burn.")
);
static u8 str_item_tm36_description[] = LANGDEP(
	PSTRING("Gegner wird mit \ndreckigem Schlamm\nbeworfen,\nvergiftet ihn evtl."),
	PSTRING("Filthy sludge is\nhurled at the foe.\nIt may poison the\ntarget.")
);
static u8 str_item_tm37_description[] = LANGDEP(
	PSTRING("Sandsturm für 5\nRunden. Kein Ef-\nfekt bei Gestein,\nBoden und Stahl."),
	PSTRING("A 5-turn sandstorm\nthat damages all\ntypes except Rock,\nGround, and Steel.")
);
static u8 str_item_tm38_description[] = LANGDEP(
	PSTRING("Feuersbrunst, die\nalles versengt.\nVerbrennt den\nGegner evtl."),
	PSTRING("The foe is hit with\nan intense flame.\nIt may leave the\ntarget with a burn.")
);
static u8 str_item_tm39_description[] = LANGDEP(
	PSTRING("Angriff mit Felsen.\nBei Erfolg wird\nder Init.-Wert des\nGegners gesenkt."),
	PSTRING("Boulders are hurled\nat the foe. It also\nlowers the foe’s\nSpeed if it hits.")
);
static u8 str_item_tm40_description[] = LANGDEP(
	PSTRING("Eine extrem\nschnelle und\nunausweichbare\nAttacke."),
	PSTRING("An extremely fast\nattack against one\ntarget. It can’t be\nevaded.")
);
static u8 str_item_tm41_description[] = LANGDEP(
	PSTRING("Erzürnt Gegner, um\nwiederholten Ein-\nsatz derselben Att.\nzu verhindern."),
	PSTRING("It enrages the foe,\nmaking it incapable\nof using the same\nmove successively.")
);
static u8 str_item_tm42_description[] = LANGDEP(
	PSTRING("Erhöht Angr. nach\nVerbrennung,\nParalyse oder\nVergiftung."),
	PSTRING("An attack that is\nboosted if user is\nburned, poisoned,\nor paralyzed.")
);
static u8 str_item_tm43_description[] = LANGDEP(
	PSTRING(" ngriff, der ab-\nhängig vom Ort\nnoch einen\nZusatzeffekt hat."),
	PSTRING("An attack that may\nhave an additional\neffect that varies\nwith the terrain.")
);
static u8 str_item_tm44_description[] = LANGDEP(
	PSTRING("Anwender schläft 2\nRunden, um KP\nund Status voll\nzu erneuern."),
	PSTRING("The user sleeps for\ntwo turns to fully\nrestore HP and heal\nany status problem.")
);
static u8 str_item_tm45_description[] = LANGDEP(
	PSTRING("Angriff des anderen\nGeschlechts\nunwahrscheinlich."),
	PSTRING("If it is the other\ngender, the foe is\nmade infatuated and\nunlikely to attack.")
);
static u8 str_item_tm46_description[] = LANGDEP(
	PSTRING("Das vom Gegner\ngehaltene Item\nkann gestohlen\nwerden."),
	PSTRING("An attack that may\ntake the foe’s held\nitem if the user\nisn’t holding one.")
);
static u8 str_item_tm47_description[] = LANGDEP(
	PSTRING("Trifft den Gegner\nmit Stahlflügeln.\nAnwenders Vert.\nsteigt evtl."),
	PSTRING("The foe is hit with\nwings of steel.\nIt may also raise\nthe user’s Defense.")
);
static u8 str_item_tm48_description[] = LANGDEP(
	PSTRING("Anwender tauscht\nSpezialfähigkeit mit\ngegnerischem\nPokémon."),
	PSTRING("The user employs\nits psychic power\nto swap abilities\nwith the foe.")
);
static u8 str_item_tm49_description[] = LANGDEP(
	PSTRING("Raubt den Effekt\nder gegn. heilenden\noder Status ver-\nändernden Attacke."),
	PSTRING("Steals the effects\nof the foe’s\nhealing or status-\nchanging move.")
);
static u8 str_item_tm50_description[] = LANGDEP(
	PSTRING("Angriff mit voller\nKraft, der den SP.\nAng. d. Anwenders \ndeutlich senkt."),
	PSTRING("An intense attack\nthat also sharply\nreduces the user’s\nSP. Atk stat.")
);
static u8 str_item_vm01_description[] = LANGDEP(
	PSTRING("Ein Basisangriff.\nDamit können\nkleine Bäume\ngefällt werden."),
	PSTRING("A basic attack.\nIt can be used to\ncut down thin trees\nand grass.")
);
static u8 str_item_vm02_description[] = LANGDEP(
	PSTRING("Sttigt in der 1.\nRunde empor und\ntrifft den Gegner\nin Runde 2."),
	PSTRING("A 2-turn move that\nhits on the 2nd\nturn. Use it to fly\nto any known town.")
);
static u8 str_item_vm03_description[] = LANGDEP(
	PSTRING("Eine Welle bricht\nüber den Gegner\nherein. Surfen\ndamit möglich."),
	PSTRING("A big wave crashes\ndown on the foe.\nCan also be used\nfor crossing water.")
);
static u8 str_item_vm04_description[] = LANGDEP(
	PSTRING("Gegner wird extrem\nstark getroffen. \nVerschieben von\nFelsen möglich."),
	PSTRING("The foe is slugged\nat maximum power.\nCan also be used\nto move boulders.")
);
static u8 str_item_vm05_description[] = LANGDEP(
	PSTRING("Erzeugt helles\nLicht, das nie\nverfehlt."),
	PSTRING("A blast of light\nthat cuts the foe’s\naccuracy. It also\nilluminates caves.")
);
static u8 str_item_vm06_description[] = LANGDEP(
	PSTRING("Zertrümmernder An-\ngriff, auch bei\nSteinen. Senkt evtl.\ndie Vert."),
	PSTRING("An attack that may\nalso cut Defense.\nIt can also smash\ncracked boulders.")
);
static u8 str_item_vm07_description[] = LANGDEP(
	PSTRING("Eine mächtige\nAttacke. Wasser-\nfälle können damit\nerklommen werden."),
	PSTRING("A powerful charge\nattack. It can also\nbe used to climb\na waterfall.")
);
static u8 str_item_vm08_description[] = LANGDEP(
	PSTRING("Erklimmt Felswände und\nverwirrt den Gegner\neventuell."),
	PSTRING("Climbs rock faces\nand possibly confuses\nthe opponent.")
);
static u8 str_item_schwarzpulver_description[] = LANGDEP(
	PSTRING("Verstärkt Explosionen. Träger\nexplodiert, wenn von\nFeuer getroffen."),
	PSTRING("Boosts explosions. Holder explodes\nthemselves when hit by\nfire.")
);
static u8 str_item_vierblatt_description[] = LANGDEP(
	PSTRING("Erhöht die Chance, dass wilde\nPokémon Items fallen lassen,\nwenn es getragen wird."),
	PSTRING("Increases the chance of\nwild pokémon dropping\nitems when held.")
);
static u8 str_item_zugangskarte_description[] = LANGDEP(
	PSTRING("Eine hochentwickelte Zugangs-\nKarte zum Gebäude der Laz.Corp."),
	PSTRING("A parcel to be delivered to Prof.\nOak from Viridian City’s Pokémon\nMart.")
);
static u8 str_item_pokefloete_description[] = LANGDEP(
	PSTRING("Eine Flöte, deren lieblicher Klang\njedes schlafende Pokémon\nsofort aufweckt."),
	PSTRING("A flute that is said to instantly\nawaken any Pokémon. It has a\nlovely tone.")
);
static u8 str_item__oeffner_description[] = LANGDEP(
	PSTRING("Der Schlüssel zur Arena der\nZinnoberinsel. Er ist rot und\nreich verziert."),
	PSTRING("The key to Cinnabar Island Gym’s\nfront door. It is colored red and\ndecorated.")
);
static u8 str_item_alte_karte_description[] = LANGDEP(
	PSTRING("Eine offenbar sehr alte\nSeekarte. Wohin sie einen wohl\nführt?"),
	PSTRING("An appearently very old\nsea chart. Where would it lead\nyou?")
);
static u8 str_item_pkmcorder_description[] = LANGDEP(
	PSTRING("Ein Kameragadget mit Wi-fi Empfang.\nEr kann sogar in Höhlen Bilder\nsenden.\n"),
	PSTRING("A set of false teeth lost by the\nSafari Zone’s Warden. It makes his\nsmile sparkle.")
);
static u8 str_item_altbernstein_description[] = LANGDEP(
	PSTRING("Ein Stück Bernstein, in dem die Gene\neines antiken Pokémon enthalten\nsind. Es ist durchsichtig!"),
	PSTRING("A piece of amber that contains\nthe genes of an ancient Pokémon.\nIt is clear with a reddish tint.")
);
static u8 str_item_tueroeffner_description[] = LANGDEP(
	PSTRING("Eine Art Schlüsselkarte, mit der die\nTüren im Hauptsitz der Silph\nCo. in Saffronia geöffnet werden."),
	PSTRING("A card-type key that unlocks doors\nin Silph Co.’s Head Office in\nSaffron City.")
);
static u8 str_item_liftoeffner_description[] = LANGDEP(
	PSTRING("Ein Schlüssel, mit dem der Aufzug\nim Versteck von Team Rocket\naktiviert wird."),
	PSTRING("A key that operates the elevator\nin Team Rocket’s Hideout.\nIt bears the Team Rocket logo.")
);
static u8 str_item_helixfossil_description[] = LANGDEP(
	PSTRING("Ein Fossil eines antiken\nPokémon, das am Meeresgrund\nlebte. Es sieht wie ein Panzer aus."),
	PSTRING("A fossil of an ancient, seafloor-\ndwelling Pokémon. It appears to be\npart of a seashell.")
);
static u8 str_item_domfossil_description[] = LANGDEP(
	PSTRING("Ein Fossil eines antiken\nPokémon, das am Meeresgrund\nlebte. Es sieht wie ein Panzer aus."),
	PSTRING("A fossil of an ancient, seafloor-\ndwelling Pokémon. It appears to be\npart of a shell.")
);
static u8 str_item_silph_scope_description[] = LANGDEP(
	PSTRING("Eine Linse, mit der unsichtbare PKMN\nsichtbar werden. Sie wurde von\nder Silph Co. hergestellt."),
	PSTRING("A scope that makes unseeable\nPokémon visible.\nIt is made by Silph Co.")
);
static u8 str_item_fahrrad_description[] = LANGDEP(
	PSTRING("Eine gewobene Wolke von watte-\nartier Konsistenz. Sie schwebt in\nBodennähe und kann Menschen tragen."),
	PSTRING("A folding bicycle that allows\nfaster movement than the Running\nShoes.")
);
static u8 str_item_karte_description[] = LANGDEP(
	PSTRING("Eine praktische Karte, die jederzeit\naufgerufen werden kann. Dein aktu-\neller Standort wird auch angezeigt."),
	PSTRING("A very convenient map that can be\nviewed anytime. It even shows your \npresent location.")
);
static u8 str_item_kampffahnder_description[] = LANGDEP(
	PSTRING("Ein Gerät, das rückkampfwillige\nTrainer ausfindig macht. Die\nBatterie lädt sich beim Reisen auf."),
	PSTRING("A device that indicates Trainers\nwho want to battle. The battery\ncharges while traveling.")
);
static u8 str_item_ruhmesdatei_description[] = LANGDEP(
	PSTRING("Ein Gerät, das dir Infos über\nwichtige Personen, die dir\nbegegnet sind, ins Gedächtnis ruft."),
	PSTRING("A device that enables you to\nrecall what you’ve heard and seen\nabout famous people.")
);
static u8 str_item_vmtm_box_description[] = LANGDEP(
	PSTRING("Eine Box, in der Vms und Tms\naufbewahrt werden. Sie ist in\ndeinen Beutel integriert."),
	PSTRING("A case that holds TMs and HMs.\nIt is attached to the Bag’s\ncompartment for important items.")
);
static u8 str_item_beerentuete_description[] = LANGDEP(
	PSTRING("Eine Tüte, in der Beeren\naufbewahrt werden. Sie ist in\ndeinen Beutel integriert."),
	PSTRING("A pouch for carrying Berries.\nIt is attached to the Bag’s\ncompartment for important items.")
);
static u8 str_item_lehrkanal_description[] = LANGDEP(
	PSTRING("Eine Sendung, die dem Anfänger-\nTrainer mit nützlichen Tipps\nzur Seite steht."),
	PSTRING("A television set that is tuned to\na program with useful tips for\nnovice Trainers.")
);
static u8 str_item_tri_pass_description[] = LANGDEP(
	PSTRING("Ein Pass für die Fähren zwischen\nEiland Eins, Zwei und Drei. Es\nsind drei Inseln aufgedruckt."),
	PSTRING("A pass for ferries between One,\nTwo, and Three Island.\nIt has a drawing of three islands.")
);
static u8 str_item_bunt_pass_description[] = LANGDEP(
	PSTRING("Ein Pass für die Fähren zwischen\nOrania und den Sevii Eilanden.\nEs ist ein Regenbogen aufgedruckt."),
	PSTRING("A pass for ferries between\nVermilion and the Sevii Islands.\nIt features a drawing of a rainbow.")
);
static u8 str_item_mega_amulett_description[] = LANGDEP(
	PSTRING("Ein goldenes Amulett, in das ein\nEdelstein eingesetzt ist. Es\nscheint von innen zu leuchten."),
	PSTRING("An aromatic tea prepared by an old\nlady. It will slake even the worst\nthirst.")
);
static u8 str_item_geheimticket_description[] = LANGDEP(
	PSTRING("Eine Fahrkarte für das Schiff zum\nNabelfelsen. Sie leuchtet\ngeheimnisvoll."),
	PSTRING("A ticket required to board the ship\nto Navel Rock.\nIt glows with a mystic light.")
);
static u8 str_item_auroraticket_description[] = LANGDEP(
	PSTRING("Eine Fahrkarte für das Schiff zur\nEntstehungsinsel. Sie\nleuchtet wundervoll."),
	PSTRING("A ticket required to board the ship\nto Birth Island.\nIt glows beautifully.")
);
static u8 str_item_puderdoeschen_description[] = LANGDEP(
	PSTRING("Ein Glas, um Beerenpuder,\nder mit der Beerenmühle\nhergestellt wurde, aufzubewahren."),
	PSTRING("A jar for storing Berry Powder\nmade using a Berry Crusher.")
);
static u8 str_item_rubin_description[] = LANGDEP(
	PSTRING("Ein ausgesprochen schönes Juwel,\ndas rötlich schimmert. Es\nsymbolisiert Leidenschaft."),
	PSTRING("An exquisitely beautiful gem that\nhas a red glow.\nIt symbolizes passion.")
);
static u8 str_item_saphir_description[] = LANGDEP(
	PSTRING("Ein ausgesprochen schönes Juwel,\ndas blau schimmert. Es\nsymbolisiert Ehrlichkeit."),
	PSTRING("An exquisitely beautiful gem that\nhas a blue glow.\nIt symbolizes honesty.")
);
static u8 str_normaljuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Normal\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Normal attacks\nonce.")
);
static u8 str_kampfjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Kampf\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Kampf attacks\nonce.")
);
static u8 str_flugjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Flug\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Flug attacks\nonce.")
);
static u8 str_giftjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Gift\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Gift attacks\nonce.")
);
static u8 str_bodenjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Boden\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Boden attacks\nonce.")
);
static u8 str_gesteinjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Gestein\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Gestein attacks\nonce.")
);
static u8 str_kaeferjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Kaefer\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Kaefer attacks\nonce.")
);
static u8 str_geistjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Geist\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Geist attacks\nonce.")
);
static u8 str_stahljuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Stahl\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Stahl attacks\nonce.")
);
static u8 str_feejuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Fee\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Fee attacks\nonce.")
);
static u8 str_feuerjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Feuer\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Feuer attacks\nonce.")
);
static u8 str_wasserjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Wasser\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Wasser attacks\nonce.")
);
static u8 str_pflanzejuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Pflanze\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Pflanze attacks\nonce.")
);
static u8 str_elektrojuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Elektro\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Elektro attacks\nonce.")
);
static u8 str_psychojuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Psycho\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Psycho attacks\nonce.")
);
static u8 str_eisjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Eis\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Eis attacks\nonce.")
);
static u8 str_drachejuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Drache\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Drache attacks\nonce.")
);
static u8 str_unlichtjuwel_description[] = LANGDEP(
	PSTRING("Ein Item zum Tragen.\nVerstärkt einmalig Unlicht\nAngriffe."),
	PSTRING("An item to be held by a Pokémon.\nBoosts Unlicht attacks\nonce.")
);
static u8 str_item_solarstueck_description[] = LANGDEP(
	PSTRING("Eine orangene Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small orange shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_lunarstueck_description[] = LANGDEP(
	PSTRING("Eine graue Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small grey shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_duesterstueck_description[] = LANGDEP(
	PSTRING("Eine dunkle Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small dark shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_glitzerstueck_description[] = LANGDEP(
	PSTRING("Eine funkelnde Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small sparkling shard.\nIt appears to be from some sort of\na tool made long ago.")
);
static u8 str_item_lichtstueck_description[] = LANGDEP(
	PSTRING("Eine leuchtende Scherbe eines antiken\nWerkzeugs, das vor langer Zeit\nangefertigt wurde."),
	PSTRING("A small shining shard.\nIt appears to be from some sort of\na tool made long ago.")
);


item items[] = {
	{
		//ITEM_NONE
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_none_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MEISTERBALL
		LANGDEP(PSTRING("Meisterball"), PSTRING("Master Ball")),
		0x1, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_meisterball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		0, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HYPERBALL
		LANGDEP(PSTRING("Hyperball"), PSTRING("Ultra Ball")),
		0x2, //index
		1200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_hyperball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERBALL
		LANGDEP(PSTRING("Superball"), PSTRING("Great Ball")),
		0x3, //index
		600, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_superball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		2, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_POKEBALL
		LANGDEP(PSTRING("Pokéball"), PSTRING("Poké Ball")),
		0x4, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_pokeball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		3, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SAFARIBALL
		LANGDEP(PSTRING("Safariball"), PSTRING("Safari Ball")),
		0x5, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_safariball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		4, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NETZBALL
		LANGDEP(PSTRING("Netzball"), PSTRING("Net Ball")),
		0x6, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_netzball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		5, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAUCHBALL
		LANGDEP(PSTRING("Tauchball"), PSTRING("Dive Ball")),
		0x7, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tauchball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		6, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NESTBALL
		LANGDEP(PSTRING("Nestball"), PSTRING("Nest Ball")),
		0x8, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_nestball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		7, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WIEDERBALL
		LANGDEP(PSTRING("Wiederball"), PSTRING("Repeat Ball")),
		0x9, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wiederball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		8, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TIMERBALL
		LANGDEP(PSTRING("Timerball"), PSTRING("Timer Ball")),
		0xa, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_timerball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		9, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LUXUSBALL
		LANGDEP(PSTRING("Luxusball"), PSTRING("Luxury Ball")),
		0xb, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_luxusball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		10, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PREMIERBALL
		LANGDEP(PSTRING("Premierball"), PSTRING("Premier Ball")),
		0xc, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_premierball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_POKEBALLS, //pocket
		11, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		item_pokeball_battle, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRANK
		LANGDEP(PSTRING("Trank"), PSTRING("Potion")),
		0xd, //index
		300, //price
		0, //holding_effect_id
		20, //holding_effect_param
		str_item_trank_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GEGENGIFT
		LANGDEP(PSTRING("Gegengift"), PSTRING("Antidote")),
		0xe, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_gegengift_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FEUERHEILER
		LANGDEP(PSTRING("Feuerheiler"), PSTRING("Burn Heal")),
		0xf, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_feuerheiler_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EISHEILER
		LANGDEP(PSTRING("Eisheiler"), PSTRING("Ice Heal")),
		0x10, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_eisheiler_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AUFWECKER
		LANGDEP(PSTRING("Aufwecker"), PSTRING("Awakening")),
		0x11, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_aufwecker_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PARA_HEILER
		LANGDEP(PSTRING("Para-Heiler"), PSTRING("Parlyz Heal")),
		0x12, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_para_heiler_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_GENESUNG
		LANGDEP(PSTRING("Top-Genesung"), PSTRING("Full Restore")),
		0x13, //index
		3000, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_top_genesung_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_TRANK
		LANGDEP(PSTRING("Top-Trank"), PSTRING("Max Potion")),
		0x14, //index
		2500, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_top_trank_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HYPERTRANK
		LANGDEP(PSTRING("Hypertrank"), PSTRING("Hyper Potion")),
		0x15, //index
		1200, //price
		0, //holding_effect_id
		200, //holding_effect_param
		str_item_hypertrank_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERTRANK
		LANGDEP(PSTRING("Supertrank"), PSTRING("Super Potion")),
		0x16, //index
		700, //price
		0, //holding_effect_id
		50, //holding_effect_param
		str_item_supertrank_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HYPERHEILER
		LANGDEP(PSTRING("Hyperheiler"), PSTRING("Full Heal")),
		0x17, //index
		600, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_hyperheiler_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BELEBER
		LANGDEP(PSTRING("Beleber"), PSTRING("Revive")),
		0x18, //index
		1500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_beleber_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_BELEBER
		LANGDEP(PSTRING("Top-Beleber"), PSTRING("Max Revive")),
		0x19, //index
		4000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_top_beleber_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAFELWASSER
		LANGDEP(PSTRING("C.O.-Mix"), PSTRING("C.O.-Mix")),
		0x1a, //index
		900, //price
		0, //holding_effect_id
		50, //holding_effect_param
		str_item_co_mix_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPRUDEL
		LANGDEP(PSTRING("C-Saft"), PSTRING("C-Juice")),
		0x1b, //index
		1250, //price
		0, //holding_effect_id
		60, //holding_effect_param
		str_item_c_saft_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LIMONADE
		LANGDEP(PSTRING("C-Serum"), PSTRING("C-Serum")),
		0x1c, //index
		1000, //price
		0, //holding_effect_id
		80, //holding_effect_param
		str_item_c_serum_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUHMUH_MILCH
		LANGDEP(PSTRING("Kuhmuh-Milch"), PSTRING("Moomoo Milk")),
		0x1d, //index
		500, //price
		0, //holding_effect_id
		100, //holding_effect_param
		str_item_kuhmuh_milch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ENERGIESTAUB
		LANGDEP(PSTRING("Energiestaub"), PSTRING("Energypowder")),
		0x1e, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_energiestaub_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KRAFTWURZEL
		LANGDEP(PSTRING("Kraftwurzel"), PSTRING("Energy Root")),
		0x1f, //index
		800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kraftwurzel_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HEILPUDER
		LANGDEP(PSTRING("Heilpuder"), PSTRING("Heal Powder")),
		0x20, //index
		450, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_heilpuder_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VITALKRAUT
		LANGDEP(PSTRING("Vitalkraut"), PSTRING("Revival Herb")),
		0x21, //index
		2800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vitalkraut_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AETHER
		LANGDEP(PSTRING("Äther"), PSTRING("Ether")),
		0x22, //index
		1200, //price
		0, //holding_effect_id
		10, //holding_effect_param
		str_item_aether_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_AETHER
		LANGDEP(PSTRING("Top-Äther"), PSTRING("Max Ether")),
		0x23, //index
		2000, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_top_aether_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ELIXIER
		LANGDEP(PSTRING("Elixier"), PSTRING("Elixir")),
		0x24, //index
		3000, //price
		0, //holding_effect_id
		10, //holding_effect_param
		str_item_elixier_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_ELIXIER
		LANGDEP(PSTRING("Top-Elixier"), PSTRING("Max Elixir")),
		0x25, //index
		4500, //price
		0, //holding_effect_id
		255, //holding_effect_param
		str_item_top_elixier_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LAVAKEKS
		LANGDEP(PSTRING("Lavakeks"), PSTRING("Lava Cookie")),
		0x26, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_lavakeks_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLAUE_FLOETE
		LANGDEP(PSTRING("Blaue Flöte"), PSTRING("Blue Flute")),
		0x27, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_blaue_floete_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GELBE_FLOETE
		LANGDEP(PSTRING("Gelbe Flöte"), PSTRING("Yellow Flute")),
		0x28, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_gelbe_floete_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ROTE_FLOETE
		LANGDEP(PSTRING("Rote Flöte"), PSTRING("Red Flute")),
		0x29, //index
		300, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_rote_floete_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHW_FLOETE
		LANGDEP(PSTRING("Schw. Flöte"), PSTRING("Black Flute")),
		0x2a, //index
		400, //price
		0, //holding_effect_id
		50, //holding_effect_param
		str_item_schw_floete_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1b81, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WEISSE_FLOETE
		LANGDEP(PSTRING("Weisse Flöte"), PSTRING("White Flute")),
		0x2b, //index
		500, //price
		0, //holding_effect_id
		150, //holding_effect_param
		str_item_weisse_floete_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1b81, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BEERENSAFT
		LANGDEP(PSTRING("Beerensaft"), PSTRING("Berry Juice")),
		0x2c, //index
		100, //price
		1, //holding_effect_id
		75, //holding_effect_param
		str_item_beerensaft_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZAUBERASCHE
		LANGDEP(PSTRING("Zauberasche"), PSTRING("Sacred Ash")),
		0x2d, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_zauberasche_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1859, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUESTENSALZ
		LANGDEP(PSTRING("Küstensalz"), PSTRING("Shoal Salt")),
		0x2e, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kuestensalz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUESTENSCHALE
		LANGDEP(PSTRING("Küstenschale"), PSTRING("Shoal Shell")),
		0x2f, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kuestenschale_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PURPURSTUECK
		LANGDEP(PSTRING("Purpurstück"), PSTRING("Red Shard")),
		0x30, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_purpurstueck_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_INDIGOSTUECK
		LANGDEP(PSTRING("Indigostück"), PSTRING("Blue Shard")),
		0x31, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_indigostueck_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GELBSTUECK
		LANGDEP(PSTRING("Gelbstück"), PSTRING("Yellow Shard")),
		0x32, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_gelbstueck_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRUENSTUECK
		LANGDEP(PSTRING("Grünstück"), PSTRING("Green Shard")),
		0x33, //index
		200, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_gruenstueck_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGMAISIERER
		LANGDEP(PSTRING("Magmaisierer"), PSTRING("????????")),
		0x34, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_magmaisierer_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_STROMISIERER
		LANGDEP(PSTRING("Stromisierer"), PSTRING("????????")),
		0x35, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_stromisierer_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHOENSCHUPPE
		LANGDEP(PSTRING("Schönschuppe"), PSTRING("????????")),
		0x36, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_schoenschuppe_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DUBIOSDISK
		LANGDEP(PSTRING("Dubiosdisc"), PSTRING("????????")),
		0x37, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_dubiosdisc_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DUESTERUMHANG
		LANGDEP(PSTRING("Düsterumhang"), PSTRING("????????")),
		0x38, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_duesterumhang_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHUETZER
		LANGDEP(PSTRING("Schützer"), PSTRING("????????")),
		0x39, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_schuetzer_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LEBEN_ORB
		LANGDEP(PSTRING("Leben-Orb"), PSTRING("????????")),
		0x3a, //index
		200, //price
		HOLD_EFFECT_LIFE_ORB, //holding_effect_id
		10, //holding_effect_param
		str_item_leben_orb_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EVOLITH
		LANGDEP(PSTRING("Evolith"), PSTRING("????????")),
		0x3b, //index
		200, //price
		HOLD_EFFECT_EVOLITE, //holding_effect_id
		0, //holding_effect_param
		str_item_evolith_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHARFZAHN
		LANGDEP(PSTRING("Scharfzahn"), PSTRING("????????")),
		0x3c, //index
		0, //price
		30, //holding_effect_id
		10, //holding_effect_param
		str_item_scharfzahn_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_3D
		LANGDEP(PSTRING("Ovaler Stein"), PSTRING("Oval Rock")),
		0x3d, //index
		6000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_ovaler_stein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_3E
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_3e_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KP_PLUS
		LANGDEP(PSTRING("KP-Plus"), PSTRING("HP Up")),
		0x3f, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kp_plus_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PROTEIN
		LANGDEP(PSTRING("Protein"), PSTRING("Protein")),
		0x40, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_protein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EISEN
		LANGDEP(PSTRING("Eisen"), PSTRING("Iron")),
		0x41, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_eisen_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_CARBON
		LANGDEP(PSTRING("Carbon"), PSTRING("Carbos")),
		0x42, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_carbon_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KALZIUM
		LANGDEP(PSTRING("Kalzium"), PSTRING("Calcium")),
		0x43, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kalzium_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SONDERBONBON
		LANGDEP(PSTRING("Sonderbonbon"), PSTRING("Rare Candy")),
		0x44, //index
		4800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_sonderbonbon_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1821, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AP_PLUS
		LANGDEP(PSTRING("AP-Plus"), PSTRING("PP Up")),
		0x45, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_ap_plus_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1805, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZINK
		LANGDEP(PSTRING("Zink"), PSTRING("Zinc")),
		0x46, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_zink_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AP_TOP
		LANGDEP(PSTRING("AP-Top"), PSTRING("PP Max")),
		0x47, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_ap_top_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1805, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GOLDBONBON
		LANGDEP(PSTRING("Goldbonbon"), PSTRING("Gold Candy")),
		0x48, //index
		14400, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_goldbonbon_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a1821, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MEGABLOCK
		LANGDEP(PSTRING("Megablock"), PSTRING("Guard Spec.")),
		0x49, //index
		700, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_megablock_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGRIFFPLUS
		LANGDEP(PSTRING("Angriffplus"), PSTRING("Dire Hit")),
		0x4a, //index
		650, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_angriffplus_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_ANGRIFF
		LANGDEP(PSTRING("X-Angriff"), PSTRING("X Attack")),
		0x4b, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_x_angriff_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_ABWEHR
		LANGDEP(PSTRING("X-Abwehr"), PSTRING("X Defend")),
		0x4c, //index
		550, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_x_abwehr_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_TEMPO
		LANGDEP(PSTRING("X-Tempo"), PSTRING("X Speed")),
		0x4d, //index
		350, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_x_tempo_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_TREFFER
		LANGDEP(PSTRING("X-Treffer"), PSTRING("X Accuracy")),
		0x4e, //index
		950, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_x_treffer_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_X_SPEZIAL
		LANGDEP(PSTRING("X-Spezial"), PSTRING("X Special")),
		0x4f, //index
		350, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_x_spezial_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f69, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_POKEPUPPE
		LANGDEP(PSTRING("Poképuppe"), PSTRING("Poké Doll")),
		0x50, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_pokepuppe_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a20fd, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ENECO_RUTE
		LANGDEP(PSTRING("Eneco-Rute"), PSTRING("Fluffy Tail")),
		0x51, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_eneco_rute_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a20fd, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUESSBONBON
		LANGDEP(PSTRING("Süßbonbon"), PSTRING("Sweet Candy")),
		0x52, //index
		2800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_suessbonbon_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SUPERSCHUTZ
		LANGDEP(PSTRING("Superschutz"), PSTRING("Super Repel")),
		0x53, //index
		500, //price
		0, //holding_effect_id
		200, //holding_effect_param
		str_item_superschutz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1a85, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TOP_SCHUTZ
		LANGDEP(PSTRING("Top-Schutz"), PSTRING("Max Repel")),
		0x54, //index
		700, //price
		0, //holding_effect_id
		250, //holding_effect_param
		str_item_top_schutz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1a85, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FLUCHTSEIL
		LANGDEP(PSTRING("Fluchtseil"), PSTRING("Escape Rope")),
		0x55, //index
		550, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_fluchtseil_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1c99, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHUTZ
		LANGDEP(PSTRING("Schutz"), PSTRING("Repel")),
		0x56, //index
		350, //price
		0, //holding_effect_id
		100, //holding_effect_param
		str_item_schutz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1a85, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		// ITEM_KRAFTSTAUB
		LANGDEP(PSTRING("Wunderstaub"), PSTRING("Wonder Powder")),
		0x57, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wunderstaub_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NULLSAFT
		LANGDEP(PSTRING("Nullsaft"), PSTRING("Null Syrup")),
		0x58, //index
		10000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_nullsaft_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		item_field_null_syrup, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_59
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_59_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_5A
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_5a_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_5B
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_5b_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_5C
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_5c_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SONNENSTEIN
		LANGDEP(PSTRING("Sonnenstein"), PSTRING("Sun Stone")),
		0x5d, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_sonnenstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MONDSTEIN
		LANGDEP(PSTRING("Mondstein"), PSTRING("Moon Stone")),
		0x5e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_mondstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FEUERSTEIN
		LANGDEP(PSTRING("Feuerstein"), PSTRING("Fire Stone")),
		0x5f, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_feuerstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DONNERSTEIN
		LANGDEP(PSTRING("Donnerstein"), PSTRING("Thunderstone")),
		0x60, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_donnerstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WASSERSTEIN
		LANGDEP(PSTRING("Wasserstein"), PSTRING("Water Stone")),
		0x61, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wasserstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLATTSTEIN
		LANGDEP(PSTRING("Blattstein"), PSTRING("Leaf Stone")),
		0x62, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_blattstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LINKKABEL
		LANGDEP(PSTRING("Linkkabel"), PSTRING("????????")),
		0x63, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_linkkabel_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FINSTERSTEIN
		LANGDEP(PSTRING("Finsterstein"), PSTRING("????????")),
		0x64, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_finsterstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LEUCHTSTEIN
		LANGDEP(PSTRING("Leuchtstein"), PSTRING("????????")),
		0x65, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_leuchtstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FUNKELSTEIN
		LANGDEP(PSTRING("Funkelstein"), PSTRING("????????")),
		0x66, //index
		2100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_funkelstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x80a183d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MINIPILZ
		LANGDEP(PSTRING("Minipilz"), PSTRING("Tinymushroom")),
		0x67, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_minipilz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RIESENPILZ
		LANGDEP(PSTRING("Riesenpilz"), PSTRING("Big Mushroom")),
		0x68, //index
		5000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_riesenpilz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPV_ORB_N
		LANGDEP(PSTRING("Wirrminze"), PSTRING("Weird Mint")),
		0x69, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_spv_orb_n_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PERLE
		LANGDEP(PSTRING("Perle"), PSTRING("Pearl")),
		0x6a, //index
		1400, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_perle_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RIESENPERLE
		LANGDEP(PSTRING("Riesenperle"), PSTRING("Big Pearl")),
		0x6b, //index
		7500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_riesenperle_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_STERNENSTAUB
		LANGDEP(PSTRING("Sternenstaub"), PSTRING("Stardust")),
		0x6c, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_sternenstaub_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_STERNENSTUECK
		LANGDEP(PSTRING("Sternenstück"), PSTRING("Star Piece")),
		0x6d, //index
		9800, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_sternenstueck_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NUGGET
		LANGDEP(PSTRING("Nugget"), PSTRING("Nugget")),
		0x6e, //index
		10000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_nugget_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HERZSCHUPPE
		LANGDEP(PSTRING("Herzschuppe"), PSTRING("Heart Scale")),
		0x6f, //index
		100, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_herzschuppe_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGR_ORB_P
		LANGDEP(PSTRING("Wutminze"), PSTRING("Aggro Mint")),
		0x70, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_angr_orb_p_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGR_ORB_N
		LANGDEP(PSTRING("Ruheminze"), PSTRING("Calm Mint")),
		0x71, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_angr_orb_n_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VERT_ORB_P
		LANGDEP(PSTRING("Eisenminze"), PSTRING("Iron Mint")),
		0x72, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vert_orb_p_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VERT_ORB_N
		LANGDEP(PSTRING("Fragilminze"), PSTRING("Fragile Mint")),
		0x73, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vert_orb_n_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_INIT_ORB_P
		LANGDEP(PSTRING("Mobilminze"), PSTRING("Mobile Mint")),
		0x74, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_init_orb_p_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_INIT_ORB_N
		LANGDEP(PSTRING("Schwerminze"), PSTRING("Heavy Mint")),
		0x75, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_init_orb_n_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPA_ORB_P
		LANGDEP(PSTRING("Fokusminze"), PSTRING("Focus Mint")),
		0x76, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_spa_orb_p_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPA_ORB_N
		LANGDEP(PSTRING("Achtlosminze"), PSTRING("Careless Mint")),
		0x77, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_spa_orb_n_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPV_ORB_P
		LANGDEP(PSTRING("Gedankenminze"), PSTRING("Mind Mint")),
		0x78, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_spv_orb_p_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		1, //type
		(void(*)(u8))0x9008d01, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_79
		LANGDEP(PSTRING("Zigzachsbrief"), PSTRING("Orange Mail")),
		0x79, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_79_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HAFENBRIEF
		LANGDEP(PSTRING("Hafenbrief"), PSTRING("Harbor Mail")),
		0x7a, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_hafenbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GLITZERBRIEF
		LANGDEP(PSTRING("Glitzerbrief"), PSTRING("Glitter Mail")),
		0x7b, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_glitzerbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EILBRIEF
		LANGDEP(PSTRING("Eilbrief"), PSTRING("Mech Mail")),
		0x7c, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_eilbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WALDBRIEF
		LANGDEP(PSTRING("Waldbrief"), PSTRING("Wood Mail")),
		0x7d, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_waldbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WELLENBRIEF
		LANGDEP(PSTRING("Wellenbrief"), PSTRING("Wave Mail")),
		0x7e, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wellenbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PERLENBRIEF
		LANGDEP(PSTRING("Perlenbrief"), PSTRING("Bead Mail")),
		0x7f, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_perlenbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DUNKELBRIEF
		LANGDEP(PSTRING("Dunkelbrief"), PSTRING("Shadow Mail")),
		0x80, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_dunkelbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TROPENBRIEF
		LANGDEP(PSTRING("Tropenbrief"), PSTRING("Tropic Mail")),
		0x81, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tropenbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRAUMBRIEF
		LANGDEP(PSTRING("Traumbrief"), PSTRING("Dream Mail")),
		0x82, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_traumbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EDELBRIEF
		LANGDEP(PSTRING("Edelbrief"), PSTRING("Fab Mail")),
		0x83, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_edelbrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RETROBRIEF
		LANGDEP(PSTRING("Retrobrief"), PSTRING("Retro Mail")),
		0x84, //index
		50, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_retrobrief_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		0, //type
		(void(*)(u8))0x80a12d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AMRENABEERE
		LANGDEP(PSTRING("Amrenabeere"), PSTRING("Cheri Berry")),
		0x85, //index
		20, //price
		2, //holding_effect_id
		0, //holding_effect_param
		str_item_amrenabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MARONBEERE
		LANGDEP(PSTRING("Maronbeere"), PSTRING("Chesto Berry")),
		0x86, //index
		20, //price
		3, //holding_effect_id
		0, //holding_effect_param
		str_item_maronbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PIRSIFBEERE
		LANGDEP(PSTRING("Pirsifbeere"), PSTRING("Pecha Berry")),
		0x87, //index
		20, //price
		4, //holding_effect_id
		0, //holding_effect_param
		str_item_pirsifbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FRAGIABEERE
		LANGDEP(PSTRING("Fragiabeere"), PSTRING("Rawst Berry")),
		0x88, //index
		20, //price
		5, //holding_effect_id
		0, //holding_effect_param
		str_item_fragiabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WILBIRBEERE
		LANGDEP(PSTRING("Wilbirbeere"), PSTRING("Aspear Berry")),
		0x89, //index
		20, //price
		6, //holding_effect_id
		0, //holding_effect_param
		str_item_wilbirbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_JONAGOBEERE
		LANGDEP(PSTRING("Jonagobeere"), PSTRING("Leppa Berry")),
		0x8a, //index
		20, //price
		7, //holding_effect_id
		10, //holding_effect_param
		str_item_jonagobeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))0x80a17e9, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20e1, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SINELBEERE
		LANGDEP(PSTRING("Sinelbeere"), PSTRING("Oran Berry")),
		0x8b, //index
		20, //price
		1, //holding_effect_id
		10, //holding_effect_param
		str_item_sinelbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PERSIMBEERE
		LANGDEP(PSTRING("Persimbeere"), PSTRING("Persim Berry")),
		0x8c, //index
		20, //price
		8, //holding_effect_id
		0, //holding_effect_param
		str_item_persimbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PRUNUSBEERE
		LANGDEP(PSTRING("Prunusbeere"), PSTRING("Lum Berry")),
		0x8d, //index
		20, //price
		9, //holding_effect_id
		0, //holding_effect_param
		str_item_prunusbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TSITRUBEERE
		LANGDEP(PSTRING("Tsitrubeere"), PSTRING("Sitrus Berry")),
		0x8e, //index
		20, //price
		1, //holding_effect_id
		30, //holding_effect_param
		str_item_tsitrubeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		1, //type
		(void(*)(u8))item_field_by_effect_table, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a20a9, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GIEFEBEERE
		LANGDEP(PSTRING("Giefebeere"), PSTRING("Figy Berry")),
		0x8f, //index
		20, //price
		10, //holding_effect_id
		8, //holding_effect_param
		str_item_giefebeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WIKIBEERE
		LANGDEP(PSTRING("Wikibeere"), PSTRING("Wiki Berry")),
		0x90, //index
		20, //price
		11, //holding_effect_id
		8, //holding_effect_param
		str_item_wikibeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGOBEERE
		LANGDEP(PSTRING("Magobeere"), PSTRING("Mago Berry")),
		0x91, //index
		20, //price
		12, //holding_effect_id
		8, //holding_effect_param
		str_item_magobeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GAUVEBEERE
		LANGDEP(PSTRING("Gauvebeere"), PSTRING("Aguav Berry")),
		0x92, //index
		20, //price
		13, //holding_effect_id
		8, //holding_effect_param
		str_item_gauvebeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_YAPABEERE
		LANGDEP(PSTRING("Yapabeere"), PSTRING("Iapapa Berry")),
		0x93, //index
		20, //price
		14, //holding_effect_id
		8, //holding_effect_param
		str_item_yapabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HIMMIHBEERE
		LANGDEP(PSTRING("Himmihbeere"), PSTRING("Razz Berry")),
		0x94, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_NORMAL, //holding_effect_param
		str_item_himmihbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MORBBEERE
		LANGDEP(PSTRING("Morbbeere"), PSTRING("Bluk Berry")),
		0x95, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_KAMPF, //holding_effect_param
		str_item_morbbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NANABBEERE
		LANGDEP(PSTRING("Nanabbeere"), PSTRING("Nanab Berry")),
		0x96, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_FLUG, //holding_effect_param
		str_item_nanabbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_NIRBEBEERE
		LANGDEP(PSTRING("Nirbebeere"), PSTRING("Wepear Berry")),
		0x97, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_GIFT, //holding_effect_param
		str_item_nirbebeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SANANABEERE
		LANGDEP(PSTRING("Sananabeere"), PSTRING("Pinap Berry")),
		0x98, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_BODEN, //holding_effect_param
		str_item_sananabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRANABEERE
		LANGDEP(PSTRING("Granabeere"), PSTRING("Pomeg Berry")),
		0x99, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_GESTEIN, //holding_effect_param
		str_item_granabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SETANGBEERE
		LANGDEP(PSTRING("Setangbeere"), PSTRING("Kelpsy Berry")),
		0x9a, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_KAEFER, //holding_effect_param
		str_item_setangbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_QUALOTBEERE
		LANGDEP(PSTRING("Qualotbeere"), PSTRING("Qualot Berry")),
		0x9b, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_GEIST, //holding_effect_param
		str_item_qualotbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HONMELBEERE
		LANGDEP(PSTRING("Honmelbeere"), PSTRING("Hondew Berry")),
		0x9c, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_STAHL, //holding_effect_param
		str_item_honmelbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LABRUSBEERE
		LANGDEP(PSTRING("Labrusbeere"), PSTRING("Grepa Berry")),
		0x9d, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_FEE, //holding_effect_param
		str_item_labrusbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAMOTBEERE
		LANGDEP(PSTRING("Tamotbeere"), PSTRING("Tamato Berry")),
		0x9e, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_FEUER, //holding_effect_param
		str_item_tamotbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SAIMBEERE
		LANGDEP(PSTRING("Saimbeere"), PSTRING("Cornn Berry")),
		0x9f, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_WASSER, //holding_effect_param
		str_item_saimbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGOSTBEERE
		LANGDEP(PSTRING("Magostbeere"), PSTRING("Magost Berry")),
		0xa0, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_PFLANZE, //holding_effect_param
		str_item_magostbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RABUTABEERE
		LANGDEP(PSTRING("Rabutabeere"), PSTRING("Rabuta Berry")),
		0xa1, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_ELEKTRO, //holding_effect_param
		str_item_rabutabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRONZIBEERE
		LANGDEP(PSTRING("Tronzibeere"), PSTRING("Nomel Berry")),
		0xa2, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_PSYCHO, //holding_effect_param
		str_item_tronzibeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KIWANBEERE
		LANGDEP(PSTRING("Kiwanbeere"), PSTRING("Spelon Berry")),
		0xa3, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_EIS, //holding_effect_param
		str_item_kiwanbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PALLMBEERE
		LANGDEP(PSTRING("Pallmbeere"), PSTRING("Pamtre Berry")),
		0xa4, //index
		20, //price
		HOLD_EFFECT_TYPE_BERRY, //holding_effect_id
		TYPE_DRACHE, //holding_effect_param
		str_item_pallmbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WASMELBEERE
		LANGDEP(PSTRING("Wasmelbeere"), PSTRING("Watmel Berry")),
		0xa5, //index
		20, //price
		TYPE_UNLICHT, //holding_effect_id
		TYPE_DRACHE, //holding_effect_param
		str_item_wasmelbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DURINBEERE
		LANGDEP(PSTRING("Durinbeere"), PSTRING("Durin Berry")),
		0xa6, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_durinbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MYRTILBEERE
		LANGDEP(PSTRING("Myrtilbeere"), PSTRING("Belue Berry")),
		0xa7, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_myrtilbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LYDZIBEERE
		LANGDEP(PSTRING("Lydzibeere"), PSTRING("Liechi Berry")),
		0xa8, //index
		20, //price
		15, //holding_effect_id
		4, //holding_effect_param
		str_item_lydzibeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LINGANBEERE
		LANGDEP(PSTRING("Linganbeere"), PSTRING("Ganlon Berry")),
		0xa9, //index
		20, //price
		16, //holding_effect_id
		4, //holding_effect_param
		str_item_linganbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SALKABEERE
		LANGDEP(PSTRING("Salkabeere"), PSTRING("Salac Berry")),
		0xaa, //index
		20, //price
		17, //holding_effect_id
		4, //holding_effect_param
		str_item_salkabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TAHAYBEERE
		LANGDEP(PSTRING("Tahaybeere"), PSTRING("Petaya Berry")),
		0xab, //index
		20, //price
		18, //holding_effect_id
		4, //holding_effect_param
		str_item_tahaybeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_APIKOBEERE
		LANGDEP(PSTRING("Apikobeere"), PSTRING("Apicot Berry")),
		0xac, //index
		20, //price
		19, //holding_effect_id
		4, //holding_effect_param
		str_item_apikobeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LANSATBEERE
		LANGDEP(PSTRING("Lansatbeere"), PSTRING("Lansat Berry")),
		0xad, //index
		20, //price
		20, //holding_effect_id
		4, //holding_effect_param
		str_item_lansatbeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KRAMBOBEERE
		LANGDEP(PSTRING("Krambobeere"), PSTRING("Starf Berry")),
		0xae, //index
		20, //price
		21, //holding_effect_id
		4, //holding_effect_param
		str_item_krambobeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ENIGMABEERE
		LANGDEP(PSTRING("Enigmabeere"), PSTRING("Enigma Berry")),
		0xaf, //index
		20, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_enigmabeere_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_BERRIES, //pocket
		4, //type
		(void(*)(u8))0x80a2155, //field_usage
		(void(*)(u8))0x1, //battle_usage1
		(void(*)(u8))0x80a2281, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_B0
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_b0_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAHLGLAS
		LANGDEP(PSTRING("Wahlglas"), PSTRING("????????")),
		0xb1, //index
		100, //price
		29, //holding_effect_id
		CHOICE_ITEM_SPECS, //holding_effect_param
		str_item_wahlglas_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAHLSCHAL
		LANGDEP(PSTRING("Wahlschal"), PSTRING("????????")),
		0xb2, //index
		100, //price
		29, //holding_effect_id
		CHOICE_ITEM_SCARF, //holding_effect_param
		str_item_wahlschal_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLENDPUDER
		LANGDEP(PSTRING("Blendpuder"), PSTRING("Brightpowder")),
		0xb3, //index
		10, //price
		22, //holding_effect_id
		10, //holding_effect_param
		str_item_blendpuder_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHLOHKRAUT
		LANGDEP(PSTRING("Schlohkraut"), PSTRING("White Herb")),
		0xb4, //index
		100, //price
		23, //holding_effect_id
		0, //holding_effect_param
		str_item_schlohkraut_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MACHOBAND
		LANGDEP(PSTRING("Machoband"), PSTRING("Macho Brace")),
		0xb5, //index
		3000, //price
		24, //holding_effect_id
		0, //holding_effect_param
		str_item_machoband_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EP_TEILER
		LANGDEP(PSTRING("EP-Teiler"), PSTRING("Exp. Share")),
		0xb6, //index
		3000, //price
		25, //holding_effect_id
		0, //holding_effect_param
		str_item_ep_teiler_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FLINKKLAUE
		LANGDEP(PSTRING("Flinkklaue"), PSTRING("Quick Claw")),
		0xb7, //index
		100, //price
		26, //holding_effect_id
		20, //holding_effect_param
		str_item_flinkklaue_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SANFTGLOCKE
		LANGDEP(PSTRING("Sanftglocke"), PSTRING("Soothe Bell")),
		0xb8, //index
		100, //price
		27, //holding_effect_id
		0, //holding_effect_param
		str_item_sanftglocke_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MENTALKRAUT
		LANGDEP(PSTRING("Mentalkraut"), PSTRING("Mental Herb")),
		0xb9, //index
		100, //price
		28, //holding_effect_id
		0, //holding_effect_param
		str_item_mentalkraut_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAHLBAND
		LANGDEP(PSTRING("Wahlband"), PSTRING("Choice Band")),
		0xba, //index
		100, //price
		29, //holding_effect_id
		CHOICE_ITEM_BAND, //holding_effect_param
		str_item_wahlband_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KING_STEIN
		LANGDEP(PSTRING("King-Stein"), PSTRING("King\'s Rock")),
		0xbb, //index
		100, //price
		30, //holding_effect_id
		10, //holding_effect_param
		str_item_king_stein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SILBERSTAUB
		LANGDEP(PSTRING("Silberstaub"), PSTRING("Silverpowder")),
		0xbc, //index
		100, //price
		31, //holding_effect_id
		10, //holding_effect_param
		str_item_silberstaub_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MUENZAMULETT
		LANGDEP(PSTRING("Münzamulett"), PSTRING("Amulet Coin")),
		0xbd, //index
		100, //price
		32, //holding_effect_id
		10, //holding_effect_param
		str_item_muenzamulett_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHUTZBAND
		LANGDEP(PSTRING("Schutzband"), PSTRING("Cleanse Tag")),
		0xbe, //index
		200, //price
		33, //holding_effect_id
		0, //holding_effect_param
		str_item_schutzband_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEELENTAU
		LANGDEP(PSTRING("Seelentau"), PSTRING("Soul Dew")),
		0xbf, //index
		200, //price
		34, //holding_effect_id
		0, //holding_effect_param
		str_item_seelentau_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ABYSSZAHN
		LANGDEP(PSTRING("Abysszahn"), PSTRING("Deepseatooth")),
		0xc0, //index
		200, //price
		35, //holding_effect_id
		0, //holding_effect_param
		str_item_abysszahn_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ABYSSPLATTE
		LANGDEP(PSTRING("Abyssplatte"), PSTRING("Deepseascale")),
		0xc1, //index
		200, //price
		36, //holding_effect_id
		0, //holding_effect_param
		str_item_abyssplatte_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RAUCHBALL
		LANGDEP(PSTRING("Rauchball"), PSTRING("Smoke Ball")),
		0xc2, //index
		200, //price
		37, //holding_effect_id
		0, //holding_effect_param
		str_item_rauchball_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EWIGSTEIN
		LANGDEP(PSTRING("Ewigstein"), PSTRING("Everstone")),
		0xc3, //index
		200, //price
		38, //holding_effect_id
		0, //holding_effect_param
		str_item_ewigstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FOKUS_BAND
		LANGDEP(PSTRING("Fokus-Band"), PSTRING("Focus Band")),
		0xc4, //index
		200, //price
		39, //holding_effect_id
		10, //holding_effect_param
		str_item_fokus_band_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GLUECKS_EI
		LANGDEP(PSTRING("Glücks-Ei"), PSTRING("Lucky Egg")),
		0xc5, //index
		200, //price
		40, //holding_effect_id
		0, //holding_effect_param
		str_item_gluecks_ei_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCOPE_LINSE
		LANGDEP(PSTRING("Scope-Linse"), PSTRING("Scope Lens")),
		0xc6, //index
		200, //price
		41, //holding_effect_id
		0, //holding_effect_param
		str_item_scope_linse_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_METALLMANTEL
		LANGDEP(PSTRING("Metallmantel"), PSTRING("Metal Coat")),
		0xc7, //index
		100, //price
		42, //holding_effect_id
		10, //holding_effect_param
		str_item_metallmantel_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_UEBERRESTE
		LANGDEP(PSTRING("Überreste"), PSTRING("Leftovers")),
		0xc8, //index
		200, //price
		43, //holding_effect_id
		10, //holding_effect_param
		str_item_ueberreste_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DRACHENHAUT
		LANGDEP(PSTRING("Drachenhaut"), PSTRING("Dragon Scale")),
		0xc9, //index
		2100, //price
		44, //holding_effect_id
		20, //holding_effect_param
		str_item_drachenhaut_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUGELBLITZ
		LANGDEP(PSTRING("Kugelblitz"), PSTRING("Light Ball")),
		0xca, //index
		100, //price
		45, //holding_effect_id
		0, //holding_effect_param
		str_item_kugelblitz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PUDERSAND
		LANGDEP(PSTRING("Pudersand"), PSTRING("Soft Sand")),
		0xcb, //index
		100, //price
		46, //holding_effect_id
		20, //holding_effect_param
		str_item_pudersand_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GRANITSTEIN
		LANGDEP(PSTRING("Granitstein"), PSTRING("Hard Stone")),
		0xcc, //index
		100, //price
		47, //holding_effect_id
		20, //holding_effect_param
		str_item_granitstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WUNDERSAAT
		LANGDEP(PSTRING("Wundersaat"), PSTRING("Miracle Seed")),
		0xcd, //index
		100, //price
		48, //holding_effect_id
		20, //holding_effect_param
		str_item_wundersaat_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHATTENGLAS
		LANGDEP(PSTRING("Schattenglas"), PSTRING("Blackglasses")),
		0xce, //index
		100, //price
		49, //holding_effect_id
		20, //holding_effect_param
		str_item_schattenglas_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHWARZGURT
		LANGDEP(PSTRING("Schwarzgurt"), PSTRING("Black Belt")),
		0xcf, //index
		100, //price
		50, //holding_effect_id
		20, //holding_effect_param
		str_item_schwarzgurt_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MAGNET
		LANGDEP(PSTRING("Magnet"), PSTRING("Magnet")),
		0xd0, //index
		100, //price
		51, //holding_effect_id
		20, //holding_effect_param
		str_item_magnet_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZAUBERWASSER
		LANGDEP(PSTRING("Zauberwasser"), PSTRING("Mystic Water")),
		0xd1, //index
		100, //price
		52, //holding_effect_id
		20, //holding_effect_param
		str_item_zauberwasser_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HACKATTACK
		LANGDEP(PSTRING("Hackattack"), PSTRING("Sharp Beak")),
		0xd2, //index
		100, //price
		53, //holding_effect_id
		20, //holding_effect_param
		str_item_hackattack_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GIFTSTICH
		LANGDEP(PSTRING("Giftstich"), PSTRING("Poison Barb")),
		0xd3, //index
		100, //price
		54, //holding_effect_id
		20, //holding_effect_param
		str_item_giftstich_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EWIGES_EIS
		LANGDEP(PSTRING("Ewiges Eis"), PSTRING("Nevermeltice")),
		0xd4, //index
		100, //price
		55, //holding_effect_id
		20, //holding_effect_param
		str_item_ewiges_eis_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BANNSTICKER
		LANGDEP(PSTRING("Bannsticker"), PSTRING("Spell Tag")),
		0xd5, //index
		100, //price
		56, //holding_effect_id
		20, //holding_effect_param
		str_item_bannsticker_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KRUEMMLOEFFEL
		LANGDEP(PSTRING("Krümmlöffel"), PSTRING("Twistedspoon")),
		0xd6, //index
		100, //price
		57, //holding_effect_id
		20, //holding_effect_param
		str_item_kruemmloeffel_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HOLZKOHLE
		LANGDEP(PSTRING("Holzkohle"), PSTRING("Charcoal")),
		0xd7, //index
		9800, //price
		58, //holding_effect_id
		20, //holding_effect_param
		str_item_holzkohle_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DRACHENZAHN
		LANGDEP(PSTRING("Drachenzahn"), PSTRING("Dragon Fang")),
		0xd8, //index
		100, //price
		59, //holding_effect_id
		20, //holding_effect_param
		str_item_drachenzahn_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEIDENSCHAL
		LANGDEP(PSTRING("Seidenschal"), PSTRING("Silk Scarf")),
		0xd9, //index
		100, //price
		60, //holding_effect_id
		20, //holding_effect_param
		str_item_seidenschal_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_UP_GRADE
		LANGDEP(PSTRING("Up-Grade"), PSTRING("Up-Grade")),
		0xda, //index
		2100, //price
		61, //holding_effect_id
		0, //holding_effect_param
		str_item_up_grade_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEEGESANG
		LANGDEP(PSTRING("Seegesang"), PSTRING("Shell Bell")),
		0xdb, //index
		200, //price
		62, //holding_effect_id
		8, //holding_effect_param
		str_item_seegesang_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SEERAUCH
		LANGDEP(PSTRING("Seerauch"), PSTRING("Sea Incense")),
		0xdc, //index
		9600, //price
		52, //holding_effect_id
		5, //holding_effect_param
		str_item_seerauch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LAXRAUCH
		LANGDEP(PSTRING("Laxrauch"), PSTRING("Lax Incense")),
		0xdd, //index
		9600, //price
		22, //holding_effect_id
		5, //holding_effect_param
		str_item_laxrauch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LUCKY_PUNCH
		LANGDEP(PSTRING("Lucky Punch"), PSTRING("Lucky Punch")),
		0xde, //index
		10, //price
		63, //holding_effect_id
		0, //holding_effect_param
		str_item_lucky_punch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_METALLSTAUB
		LANGDEP(PSTRING("Metallstaub"), PSTRING("Metal Powder")),
		0xdf, //index
		10, //price
		64, //holding_effect_id
		0, //holding_effect_param
		str_item_metallstaub_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KAMPFKNOCHEN
		LANGDEP(PSTRING("Kampfknochen"), PSTRING("Thick Club")),
		0xe0, //index
		500, //price
		65, //holding_effect_id
		0, //holding_effect_param
		str_item_kampfknochen_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LAUCHSTANGE
		LANGDEP(PSTRING("Lauchstange"), PSTRING("Stick")),
		0xe1, //index
		200, //price
		66, //holding_effect_id
		0, //holding_effect_param
		str_item_lauchstange_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BISAFLORNIT
		LANGDEP(PSTRING("Bisaflornit"), PSTRING("????????")),
		0xe2, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_bisaflornit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GLURAKNIT
		LANGDEP(PSTRING("Gluraknit"), PSTRING("????????")),
		0xe3, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_gluraknit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TURTOKNIT
		LANGDEP(PSTRING("Turtoknit"), PSTRING("????????")),
		0xe4, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_turtoknit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TERRASORNIT
		LANGDEP(PSTRING("Terrasornit"), PSTRING("????????")),
		0xe5, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_terrasornit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZERBERNIT
		LANGDEP(PSTRING("Zerbernit"), PSTRING("????????")),
		0xe6, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_zerbernit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SKULLYDRANIT
		LANGDEP(PSTRING("Skullydranit"), PSTRING("????????")),
		0xe7, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_skullydranit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AQUANANIT
		LANGDEP(PSTRING("Aquananit"), PSTRING("????????")),
		0xe8, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_aquananit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FLAMARANIT
		LANGDEP(PSTRING("Flamaranit"), PSTRING("????????")),
		0xe9, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_flamaranit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLITZANIT
		LANGDEP(PSTRING("Blitzanit"), PSTRING("????????")),
		0xea, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_blitzanit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AMPHAROSNIT
		LANGDEP(PSTRING("Ampharosnit"), PSTRING("????????")),
		0xeb, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_ampharosnit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GENGARNIT
		LANGDEP(PSTRING("Gengarnit"), PSTRING("????????")),
		0xec, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_gengarnit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BIBORNIT
		LANGDEP(PSTRING("Bibornit"), PSTRING("????????")),
		0xed, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_bibornit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_EE
		LANGDEP(PSTRING("Magmaherz"), PSTRING("Magma Soul")),
		0xee, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_magmaherz_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_EF
		LANGDEP(PSTRING("Geowaznit"), PSTRING("Golemnite")),
		0xef, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_geowaznit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TROPIUSNIT
		LANGDEP(PSTRING("Tropiusnit"), PSTRING("Tropiusnite")),
		0xf0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tropiusnit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_OCTILLERYNIT
		LANGDEP(PSTRING("Octanit"), PSTRING("Octanite")),
		0xf1, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_octillerynit_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F2
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_f2_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F3
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_f3_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F4
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_f4_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket 
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F5
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_f5_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F6
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_f6_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F7
		LANGDEP(PSTRING("????????"), PSTRING("????????")),
		0x0, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_f7_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F8
		LANGDEP(PSTRING("Lahmrauch"), PSTRING("Full Incense")),
		0xF8, //index
		5000, //price
		HOLD_EFFECT_FULL_INCENSE, //holding_effect_id
		0, //holding_effect_param
		str_item_lahmrauch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_F9
		LANGDEP(PSTRING("Eisbrocken"), PSTRING("Ice Rock")),
		0xF9, //index
		200, //price
		HOLD_EFFECT_WEATHER_ROCK, //holding_effect_id
		WEATHER_ROCK_HAIL, //holding_effect_param
		str_item_eisbrocken_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FA
		LANGDEP(PSTRING("Nassbrocken"), PSTRING("Damp Rock")),
		0xFA, //index
		200, //price
		HOLD_EFFECT_WEATHER_ROCK, //holding_effect_id
		WEATHER_ROCK_RAIN, //holding_effect_param
		str_item_nassbrocken_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FB
		LANGDEP(PSTRING("Glattbrocken"), PSTRING("Smooth Rock")),
		0xFB, //index
		200, //price
		HOLD_EFFECT_WEATHER_ROCK, //holding_effect_id
		WEATHER_ROCK_SANDSTORM, //holding_effect_param
		str_item_glattbrocken_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FC
		LANGDEP(PSTRING("Heißbrocken"), PSTRING("Heat Rock")),
		0xFC, //index
		200, //price
		HOLD_EFFECT_WEATHER_ROCK, //holding_effect_id
		WEATHER_ROCK_SUN, //holding_effect_param
		str_item_heissbrocken_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_FD
		LANGDEP(PSTRING("Lichtlehm"), PSTRING("Light Clay")),
		0xFD, //index
		200, //price
		HOLD_EFFECT_LIGHT_CLAY, //holding_effect_id
		0, //holding_effect_param
		str_item_lichtlehm_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ROTER_SCHAL
		LANGDEP(PSTRING("Steinrauch"), PSTRING("Rock Incense")),
		0xfe, //index
		9600, //price
		HOLD_EFFECT_ROCK_POWER, //holding_effect_id
		20, //holding_effect_param
		str_item_steinrauch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLAUER_SCHAL
		LANGDEP(PSTRING("Scheuchrauch"), PSTRING("Pure Incense")),
		0xff, //index
		9600, //price
		HOLD_EFFECT_REPEL, //holding_effect_id
		0, //holding_effect_param
		str_item_scheuchrauch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ROSA_SCHAL
		LANGDEP(PSTRING("Glücksrauch"), PSTRING("Luck Incense")),
		0x100, //index
		9600, //price
		HOLD_EFFECT_DOUBLE_PRIZE, //holding_effect_id
		0, //holding_effect_param
		str_item_gluecksrauch_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KOEDER
		LANGDEP(PSTRING("Köder"), PSTRING("Bait")),
		0x101, //index
		250, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_koeder_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GOLDENER_KOEDER
		LANGDEP(PSTRING("Goldköder"), PSTRING("Golden Bait")),
		0x102, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_goldkoeder_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//
		LANGDEP(PSTRING("Leuchtköder"), PSTRING("Shining Bait")),
		0x103, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_leuchtkoeder_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MUENZKORB
		LANGDEP(PSTRING("Münzkorb"), PSTRING("Coin Case")),
		0x104, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_muenzkorb_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a154d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DETEKTOR
		LANGDEP(PSTRING("Detektor"), PSTRING("Itemfinder")),
		0x105, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_detektor_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1525, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ANGEL
		LANGDEP(PSTRING("Angel"), PSTRING("Old Rod")),
		0x106, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_angel_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1425, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PROFIANGEL
		LANGDEP(PSTRING("Profiangel"), PSTRING("Good Rod")),
		0x107, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_profiangel_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1425, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x1, //field_28
	},{
		//ITEM_SUPERANGEL
		LANGDEP(PSTRING("Superangel"), PSTRING("Super Rod")),
		0x108, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_superangel_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1425, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x2, //field_28
	},{
		//ITEM_BOOTSTICKET
		LANGDEP(PSTRING("Bootsticket"), PSTRING("S.S. Ticket")),
		0x109, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_bootsticket_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WETTB_KARTE
		LANGDEP(PSTRING("Wettb.-Karte"), PSTRING("Contest Pass")),
		0x10a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wettb_karte_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ITEM_10B
		LANGDEP(PSTRING("Wolkenherz"), PSTRING("????????")),
		0x10b, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_item_10b_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WAILMERKANNE
		LANGDEP(PSTRING("Wailmerkanne"), PSTRING("Wailmer Pail")),
		0x10c, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wailmerkanne_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DEVON_WAREN
		LANGDEP(PSTRING("Devon-Waren"), PSTRING("Devon Goods")),
		0x10d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_devon_waren_description,
		2, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ASCHETASCHE
		LANGDEP(PSTRING("Aschetasche"), PSTRING("Soot Sack")),
		0x10e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_aschetasche_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))item_ashbag_field, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GEISTERSCHLUESSEL
		LANGDEP(PSTRING("Geist-Schl."), PSTRING("Ghost Key")),
		0x10f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_geisterschluessel_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KUNSTRAD
		LANGDEP(PSTRING("Kunstrad"), PSTRING("Acro Bike")),
		0x110, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kunstrad_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1319, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BOX
		LANGDEP(PSTRING("Box"), PSTRING("Pokéblock Case")),
		0x111, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_box_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BRIEF
		LANGDEP(PSTRING("Brief"), PSTRING("Letter")),
		0x112, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_brief_description,
		2, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AEON_TICKET
		LANGDEP(PSTRING("Äon-Ticket"), PSTRING("Eon Ticket")),
		0x113, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_aeon_ticket_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SPIRITKERN
		LANGDEP(PSTRING("Spiritkern"), PSTRING("Red Orb")),
		0x114, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_spiritkern_description,
		2, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BLAUE_KUGEL
		LANGDEP(PSTRING("Blaue Kugel"), PSTRING("Blue Orb")),
		0x115, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_blaue_kugel_description,
		2, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCANNER
		LANGDEP(PSTRING("Scanner"), PSTRING("Scanner")),
		0x116, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_scanner_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WUESTENGLAS
		LANGDEP(PSTRING("Wüstenglas"), PSTRING("Go-Goggles")),
		0x117, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wuestenglas_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_METEORIT
		LANGDEP(PSTRING("Meteorit"), PSTRING("Meteorite")),
		0x118, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_meteorit_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		// ITEM_GOLDSCHLUESSEL
		LANGDEP(PSTRING("Goldschlüssel"), PSTRING("Golden Key")),
		0x119, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_goldschluessel_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ZELLENSCHUESSEL
		LANGDEP(PSTRING("Zellenschl."), PSTRING("Cell Keys")),
		0x11a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_zellenschluessel_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_K4_SCHLUESSEL
		LANGDEP(PSTRING("K4-Schlüssel"), PSTRING("RM. 4 Key")),
		0x11b, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_k4_schluessel_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_K6_SCHLUESSEL
		LANGDEP(PSTRING("K6-Schlüssel"), PSTRING("RM. 6 Key")),
		0x11c, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_k6_schluessel_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_L_SCHLUESSEL
		LANGDEP(PSTRING("L.-Schlüssel"), PSTRING("Storage Key")),
		0x11d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_l_schluessel_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_WURZELFOSSIL
		LANGDEP(PSTRING("Wurzelfossil"), PSTRING("Root Fossil")),
		0x11e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_wurzelfossil_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KLAUENFOSSIL
		LANGDEP(PSTRING("Klauenfossil"), PSTRING("Claw Fossil")),
		0x11f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_klauenfossil_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DEVON_SCOPE
		LANGDEP(PSTRING("Devon-Scope"), PSTRING("Devon Scope")),
		0x120, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_devon_scope_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM01
		LANGDEP(PSTRING("TM01"), PSTRING("TM01")),
		0x121, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm01_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM02
		LANGDEP(PSTRING("TM02"), PSTRING("TM02")),
		0x122, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm02_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM03
		LANGDEP(PSTRING("TM03"), PSTRING("TM03")),
		0x123, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm03_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM04
		LANGDEP(PSTRING("TM04"), PSTRING("TM04")),
		0x124, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm04_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM05
		LANGDEP(PSTRING("TM05"), PSTRING("TM05")),
		0x125, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm05_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM06
		LANGDEP(PSTRING("TM06"), PSTRING("TM06")),
		0x126, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm06_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM07
		LANGDEP(PSTRING("TM07"), PSTRING("TM07")),
		0x127, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm07_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM08
		LANGDEP(PSTRING("TM08"), PSTRING("TM08")),
		0x128, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm08_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM09
		LANGDEP(PSTRING("TM09"), PSTRING("TM09")),
		0x129, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm09_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM10
		LANGDEP(PSTRING("TM10"), PSTRING("TM10")),
		0x12a, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm10_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM11
		LANGDEP(PSTRING("TM11"), PSTRING("TM11")),
		0x12b, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm11_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM12
		LANGDEP(PSTRING("TM12"), PSTRING("TM12")),
		0x12c, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm12_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM13
		LANGDEP(PSTRING("TM13"), PSTRING("TM13")),
		0x12d, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm13_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM14
		LANGDEP(PSTRING("TM14"), PSTRING("TM14")),
		0x12e, //index
		5500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm14_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM15
		LANGDEP(PSTRING("TM15"), PSTRING("TM15")),
		0x12f, //index
		7500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm15_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM16
		LANGDEP(PSTRING("TM16"), PSTRING("TM16")),
		0x130, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm16_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM17
		LANGDEP(PSTRING("TM17"), PSTRING("TM17")),
		0x131, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm17_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM18
		LANGDEP(PSTRING("TM18"), PSTRING("TM18")),
		0x132, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm18_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM19
		LANGDEP(PSTRING("TM19"), PSTRING("TM19")),
		0x133, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm19_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM20
		LANGDEP(PSTRING("TM20"), PSTRING("TM20")),
		0x134, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm20_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM21
		LANGDEP(PSTRING("TM21"), PSTRING("TM21")),
		0x135, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm21_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM22
		LANGDEP(PSTRING("TM22"), PSTRING("TM22")),
		0x136, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm22_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM23
		LANGDEP(PSTRING("TM23"), PSTRING("TM23")),
		0x137, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm23_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM24
		LANGDEP(PSTRING("TM24"), PSTRING("TM24")),
		0x138, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm24_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM25
		LANGDEP(PSTRING("TM25"), PSTRING("TM25")),
		0x139, //index
		5500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm25_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM26
		LANGDEP(PSTRING("TM26"), PSTRING("TM26")),
		0x13a, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm26_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM27
		LANGDEP(PSTRING("TM27"), PSTRING("TM27")),
		0x13b, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm27_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM28
		LANGDEP(PSTRING("TM28"), PSTRING("TM28")),
		0x13c, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm28_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM29
		LANGDEP(PSTRING("TM29"), PSTRING("TM29")),
		0x13d, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm29_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM30
		LANGDEP(PSTRING("TM30"), PSTRING("TM30")),
		0x13e, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm30_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM31
		LANGDEP(PSTRING("TM31"), PSTRING("TM31")),
		0x13f, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm31_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM32
		LANGDEP(PSTRING("TM32"), PSTRING("TM32")),
		0x140, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm32_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM33
		LANGDEP(PSTRING("TM33"), PSTRING("TM33")),
		0x141, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm33_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM34
		LANGDEP(PSTRING("TM34"), PSTRING("TM34")),
		0x142, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm34_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM35
		LANGDEP(PSTRING("TM35"), PSTRING("TM35")),
		0x143, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm35_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM36
		LANGDEP(PSTRING("TM36"), PSTRING("TM36")),
		0x144, //index
		1000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm36_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM37
		LANGDEP(PSTRING("TM37"), PSTRING("TM37")),
		0x145, //index
		2000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm37_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM38
		LANGDEP(PSTRING("TM38"), PSTRING("TM38")),
		0x146, //index
		5500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm38_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM39
		LANGDEP(PSTRING("TM39"), PSTRING("TM39")),
		0x147, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm39_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM40
		LANGDEP(PSTRING("TM40"), PSTRING("TM40")),
		0x148, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm40_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM41
		LANGDEP(PSTRING("TM41"), PSTRING("TM41")),
		0x149, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm41_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM42
		LANGDEP(PSTRING("TM42"), PSTRING("TM42")),
		0x14a, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm42_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM43
		LANGDEP(PSTRING("TM43"), PSTRING("TM43")),
		0x14b, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm43_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM44
		LANGDEP(PSTRING("TM44"), PSTRING("TM44")),
		0x14c, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm44_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM45
		LANGDEP(PSTRING("TM45"), PSTRING("TM45")),
		0x14d, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm45_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM46
		LANGDEP(PSTRING("TM46"), PSTRING("TM46")),
		0x14e, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm46_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM47
		LANGDEP(PSTRING("TM47"), PSTRING("TM47")),
		0x14f, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm47_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM48
		LANGDEP(PSTRING("TM48"), PSTRING("TM48")),
		0x150, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm48_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM49
		LANGDEP(PSTRING("TM49"), PSTRING("TM49")),
		0x151, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm49_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TM50
		LANGDEP(PSTRING("TM50"), PSTRING("TM50")),
		0x152, //index
		3000, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tm50_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM01
		LANGDEP(PSTRING("VM01"), PSTRING("HM01")),
		0x153, //index
		500, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm01_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM02
		LANGDEP(PSTRING("VM02"), PSTRING("HM02")),
		0x154, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm02_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM03
		LANGDEP(PSTRING("VM03"), PSTRING("HM03")),
		0x155, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm03_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM04
		LANGDEP(PSTRING("VM04"), PSTRING("HM04")),
		0x156, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm04_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM05
		LANGDEP(PSTRING("VM05"), PSTRING("HM05")),
		0x157, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm05_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM06
		LANGDEP(PSTRING("VM06"), PSTRING("HM06")),
		0x158, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm06_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM07
		LANGDEP(PSTRING("VM07"), PSTRING("HM07")),
		0x159, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm07_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VM08
		LANGDEP(PSTRING("VM08"), PSTRING("HM08")),
		0x15a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vm08_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_TM_HM, //pocket
		1, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SCHWARZPULVER
		LANGDEP(PSTRING("Schwarzpulver"), PSTRING("Gun Powder")),
		0x15b, //index
		150, //price
		HOLD_EFFECT_GUN_POWDER, //holding_effect_id
		25, //holding_effect_param
		str_item_schwarzpulver_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		// ITEM_VIERBLATT
		LANGDEP(PSTRING("Vierblatt"), PSTRING("Four Leaf")),
		0x15c, //index
		500, //price
		HOLD_EFFECT_FOUR_LEAF, //holding_effect_id
		0, //holding_effect_param
		str_item_vierblatt_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_EICHS_PAKET
		LANGDEP(PSTRING("Zugangskarte"), PSTRING("Oak\'s Parcel")),
		0x15d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_zugangskarte_description,
		2, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_POKEFLOETE
		LANGDEP(PSTRING("Pok▶löte"), PSTRING("Poké Flute")),
		0x15e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_pokefloete_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1659, //field_usage
		(void(*)(u8))0x2, //battle_usage1
		(void(*)(u8))0x80a1f51, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM__OEFFNER
		LANGDEP(PSTRING("?-öffner"), PSTRING("Secret Key")),
		0x15f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item__oeffner_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RAD_COUPON
		LANGDEP(PSTRING("Alte Karte"), PSTRING("Old Map")),
		0x160, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_alte_karte_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PKMCORDER
		LANGDEP(PSTRING("Pkmcorder"), PSTRING("Gold Teeth")),
		0x161, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_pkmcorder_description,
		2, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x0, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_ALTBERNSTEIN
		LANGDEP(PSTRING("Altbernstein"), PSTRING("Old Amber")),
		0x162, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_altbernstein_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TUEROEFFNER
		LANGDEP(PSTRING("Türöffner"), PSTRING("Card Key")),
		0x163, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tueroeffner_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LIFTOEFFNER
		LANGDEP(PSTRING("Liftöffner"), PSTRING("Lift Key")),
		0x164, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_liftoeffner_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_HELIXFOSSIL
		LANGDEP(PSTRING("Helixfossil"), PSTRING("Helix Fossil")),
		0x165, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_helixfossil_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_DOMFOSSIL
		LANGDEP(PSTRING("Domfossil"), PSTRING("Dome Fossil")),
		0x166, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_domfossil_description,
		0, // Importance
		0, // exits_bag_on_use
		POCKET_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SILPH_SCOPE
		LANGDEP(PSTRING("Silph Scope"), PSTRING("Silph Scope")),
		0x167, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_silph_scope_description,
		1, // Importance
		0, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_FAHRRAD
		LANGDEP(PSTRING("Wolke"), PSTRING("Bicycle")),
		0x1ff, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_fahrrad_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1319, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KARTE
		LANGDEP(PSTRING("Karte"), PSTRING("Town Map")),
		0x169, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_karte_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1d4d, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_KAMPFFAHNDER
		LANGDEP(PSTRING("Kampffahnder"), PSTRING("VS Seeker")),
		0x16a, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_kampffahnder_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a1e89, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RUHMESDATEI
		LANGDEP(PSTRING("Ruhmesdatei"), PSTRING("Fame Checker")),
		0x16b, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_ruhmesdatei_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1de5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_VMTM_BOX
		LANGDEP(PSTRING("Vm/Tm-Box"), PSTRING("TM Case")),
		0x16c, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_vmtm_box_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a1875, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BEERENTUETE
		LANGDEP(PSTRING("Beerentüte"), PSTRING("Berry Pouch")),
		0x16d, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_beerentuete_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a190d, //field_usage
		(void(*)(u8))0x3, //battle_usage1
		(void(*)(u8))0x80a19a5, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_LEHRKANAL
		LANGDEP(PSTRING("Lehrkanal"), PSTRING("Teachy TV")),
		0x16e, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_lehrkanal_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		2, //type
		(void(*)(u8))0x80a19d9, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_TRI_PASS
		LANGDEP(PSTRING("Tri-Pass"), PSTRING("Tri-Pass")),
		0x16f, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_tri_pass_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_BUNT_PASS
		LANGDEP(PSTRING("Bunt-Pass"), PSTRING("Rainbow Pass")),
		0x170, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_bunt_pass_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_MEGA_AMULETT
		LANGDEP(PSTRING("Mega-Amulett"), PSTRING("Mega-Locket")),
		0x171, //index
		0, //price
		HOLD_EFFECT_KEYSTONE, //holding_effect_id
		0, //holding_effect_param
		str_item_mega_amulett_description,
		1, // Importance
		0, // Exits Bag on
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0xe, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_GEHEIMTICKET
		LANGDEP(PSTRING("Geheimticket"), PSTRING("Mysticticket")),
		0x172, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_geheimticket_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_AURORATICKET
		LANGDEP(PSTRING("Auroraticket"), PSTRING("Auroraticket")),
		0x173, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_auroraticket_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_PUDERDOESCHEN
		LANGDEP(PSTRING("Puderdöschen"), PSTRING("Powder Jar")),
		0x174, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_puderdoeschen_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a15d5, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_RUBIN
		LANGDEP(PSTRING("Rubin"), PSTRING("Ruby")),
		0x175, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_rubin_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},{
		//ITEM_SAPHIR
		LANGDEP(PSTRING("Saphir"), PSTRING("Sapphire")),
		0x176, //index
		0, //price
		0, //holding_effect_id
		0, //holding_effect_param
		str_item_saphir_description,
		1, // Importance
		1, // exits_bag_on_use
		POCKET_KEY_ITEMS, //pocket
		4, //type
		(void(*)(u8))0x80a2325, //field_usage
		(void(*)(u8))0x0, //battle_usage1
		(void(*)(u8))0x0, //battle_usage2
		(void(*)(u8))0x0, //field_28
	},
	[ITEM_NORMALJUWEL] = {
		.name = LANGDEP(PSTRING("Normaljuwel"), PSTRING("Normalgem")),
		.index = 0x178, .price = 200, 
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_NORMAL,
		.description = str_normaljuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_KAMPFJUWEL] = {
		.name = LANGDEP(PSTRING("Kampfjuwel"), PSTRING("Kampfgem")),
		.index = 0x179, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_KAMPF,
		.description = str_kampfjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_FLUGJUWEL] = {
		.name = LANGDEP(PSTRING("Flugjuwel"), PSTRING("Fluggem")),
		.index = 0x17a, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_FLUG,
		.description = str_flugjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_GIFTJUWEL] = {
		.name = LANGDEP(PSTRING("Giftjuwel"), PSTRING("Giftgem")),
		.index = 0x17b, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_GIFT,
		.description = str_giftjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_BODENJUWEL] = {
		.name = LANGDEP(PSTRING("Bodenjuwel"), PSTRING("Bodengem")),
		.index = 0x17c, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_BODEN,
		.description = str_bodenjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_GESTEINJUWEL] = {
		.name = LANGDEP(PSTRING("Gesteinjuwel"), PSTRING("Gesteingem")),
		.index = 0x17d, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_GESTEIN,
		.description = str_gesteinjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_KAEFERJUWEL] = {
		.name = LANGDEP(PSTRING("Kaeferjuwel"), PSTRING("Kaefergem")),
		.index = 0x17e, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_KAEFER,
		.description = str_kaeferjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_GEISTJUWEL] = {
		.name = LANGDEP(PSTRING("Geistjuwel"), PSTRING("Geistgem")),
		.index = 0x17f, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_GEIST,
		.description = str_geistjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_STAHLJUWEL] = {
		.name = LANGDEP(PSTRING("Stahljuwel"), PSTRING("Stahlgem")),
		.index = 0x180, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_STAHL,
		.description = str_stahljuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_FEEJUWEL] = {
		.name = LANGDEP(PSTRING("Feejuwel"), PSTRING("Feegem")),
		.index = 0x181, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_FEE,
		.description = str_feejuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_FEUERJUWEL] = {
		.name = LANGDEP(PSTRING("Feuerjuwel"), PSTRING("Feuergem")),
		.index = 0x182, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_FEUER,
		.description = str_feuerjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_WASSERJUWEL] = {
		.name = LANGDEP(PSTRING("Wasserjuwel"), PSTRING("Wassergem")),
		.index = 0x183, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_WASSER,
		.description = str_wasserjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_PFLANZEJUWEL] = {
		.name = LANGDEP(PSTRING("Pflanzejuwel"), PSTRING("Pflanzegem")),
		.index = 0x184, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_PFLANZE,
		.description = str_pflanzejuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_ELEKTROJUWEL] = {
		.name = LANGDEP(PSTRING("Elektrojuwel"), PSTRING("Elektrogem")),
		.index = 0x185, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_ELEKTRO,
		.description = str_elektrojuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_PSYCHOJUWEL] = {
		.name = LANGDEP(PSTRING("Psychojuwel"), PSTRING("Psychogem")),
		.index = 0x186, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_PSYCHO,
		.description = str_psychojuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_EISJUWEL] = {
		.name = LANGDEP(PSTRING("Eisjuwel"), PSTRING("Eisgem")),
		.index = 0x187, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_EIS,
		.description = str_eisjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_DRACOJUWEL] = {
		.name = LANGDEP(PSTRING("Drachejuwel"), PSTRING("Drachegem")),
		.index = 0x0, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_DRACHE,
		.description = str_drachejuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_UNLICHTJUWEL] = {
		.name = LANGDEP(PSTRING("Unlichtjuwel"), PSTRING("Unlichtgem")),
		.index = 0x189, .price = 200,
		.holding_effect_id = HOLD_EFFECT_GEM, .holding_effect_param = TYPE_UNLICHT,
		.description = str_unlichtjuwel_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_LUNARSTUECK] = {
		.name = LANGDEP(PSTRING("Lunarstueck"), PSTRING("Lunar Piece")),
		.index = 0x18a, .price = 200,
		.description = str_item_lunarstueck_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_SOLARSTUECK] = {
		.name = LANGDEP(PSTRING("Solarstueck"), PSTRING("Solar Piece")),
		.index = 0x18b, .price = 200,
		.description = str_item_solarstueck_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_DUESTERSTUECK] = {
		.name = LANGDEP(PSTRING("Düsterstuck"), PSTRING("Dusk Piece")),
		.index = 0x18c, .price = 200,
		.description = str_item_duesterstueck_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_GLITZERSTUECK] = {
		.name = LANGDEP(PSTRING("Glitzerstueck"), PSTRING("Sparkle Piece")),
		.index = 0x18c, .price = 200,
		.description = str_item_glitzerstueck_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
	[ITEM_LICHTSTUECK] = {
		.name = LANGDEP(PSTRING("Lichtstueck"), PSTRING("Light Piece")),
		.index = 0x18c, .price = 200,
		.description = str_item_lichtstueck_description, .pocket = POCKET_ITEMS, .type = 4,
		.field_usage = (void(*)(u8))0x80a2325,
	},
};

u16 item_idx_saniztize(u16 item_idx) {
	if (item_idx >= ITEM_CNT)
		return ITEM_NONE;
	return item_idx;
}
