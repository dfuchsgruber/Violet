.include "vars.s"
.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "vars.s"
.include "flags.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "ordinals.s"
.include "movements.s"
.include "items.s"


.global ow_script_blackbeard_ship_deck_person0

ow_script_blackbeard_ship_deck_person0:
    applymovement 0xFF m
    waitmovement 0
    end

m:
.byte STEP_WALK_DOWN_FACING_UP, STOP