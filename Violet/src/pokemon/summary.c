/*
 * summary.c
 *
 *  Created on: Mar 3, 2019
 *      Author: dominik
 */

#include "types.h"
#include "overworld/summary.h"
#include "constants/pokemon_attributes.h"
#include "language.h"
#include "text.h"

u8 str_summary_egg_memo_daycare[] = LANGDEP(PSTRING("Seltsames Ei, das die\nPensionsleitung fand."),
		PSTRING("Strange egg found by the\ndaycare people."));

u8 str_summary_egg_memo_overworld_egg[] = LANGDEP(
		PSTRING("Ein Ei, das offenbar ein\nwildes Pokémon gelegt hat."),
		PSTRING("An egg, that was appearently\nlaid by a wild Pokémon."));

u8 str_summary_egg_memo_special_egg[] = LANGDEP(
		PSTRING("Ei, das als Geschenk\nüberreicht wurde."),
		PSTRING("Egg that was given\nas present."));

void summary_print_egg_memo() {
	u8 *text = str_summary_egg_memo_daycare;
	// Oversimplify this extremly since there are no link trades
	int catch_location = pokemon_get_attribute(&summary_state->current_pokemon,
			ATTRIBUTE_CATCH_LOCATION, 0);
	if (!summary_state->sanity) {
		if (catch_location == CATCH_LOCATION_OVERWORLD_EGG)
			text = str_summary_egg_memo_overworld_egg;
		else if (catch_location == CATCH_LOCATION_SPECIAL_EGG)
			text = str_summary_egg_memo_special_egg;
	}
	tbox_print_string(summary_state->tbox_memo, 2, 0, 3, 0, 0,
			&summary_egg_memo_fontcolmap, 0xFF, text);
}

u8 str_summary_egg_memo_duration_very_long[] = LANGDEP(
		PSTRING("Das Ei braucht\nnoch lange, bis\nes schlüpft!"),
		PSTRING("This egg takes\nyet a long time\nuntil it hatches!"));

u8 str_summary_egg_memo_duration_long[] = LANGDEP(
		PSTRING("Was ist in dem Ei?\nGedulde dich\nnoch ein wenig."),
		PSTRING("What is inside this\negg? Have a litle\npatience."));

u8 str_summary_egg_memo_duration_soon[] = LANGDEP(
		PSTRING("Es bewegt sich\nmanchmal. Es könnte\nbald schlüpfen!"),
		PSTRING("It sometimes moves.\nIt might hatch\nsoon!"));

u8 str_summary_egg_memo_duration_very_soon[] = LANGDEP(
		PSTRING("Es sind schon Laute\nzu hören. Es wird\nbald schlüpfen!"),
		PSTRING("You can hear sounds\nfrom it. It will\nhatch soon!")
		);
