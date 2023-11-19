

#include "types.h"
#include "stdbool.h"
#include "pokepad/pokepad2.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/basestat.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "fading.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "language.h"
#include "io.h"
#include "flags.h"
#include "vars.h"
#include "music.h"
#include "bios.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "pokepad/pokedex/state.h"
#include "pokepad/pokedex/pages/evolution.h"
#include "dma.h"
#include "menu_indicators.h"
#include "pokemon/names.h"
#include "abilities.h"
#include "item/pokeball.h"
#include "pokemon/cry.h"

extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_ui_tboxTiles;

bool pokedex_entry_page_evolution_setup() {
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
    (void) caught;
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_DATA_SETUP: {
            pokedex_entry_state->page_initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_TBOXES:
            pokedex_entry_state->page_initialization_state++;
            break;
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_OAM:
            pokedex_entry_state->page_initialization_state++;
            break;
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS: {
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        default:
            return false;
    }
    return true;
}

void pokedex_entry_page_evolution_destroy() {
    pokedex_entry_page_free_tboxes();
}

bool pokedex_entry_page_evolution_handle_inputs(u8 self) {
    if (fading_control.active || dma3_busy(-1)) {
        return false;
    }
    (void)self;
    return false;
}