#include "types.h"
#include "overworld/script.h"
#include "music.h"
#include "debug.h"

static const fanfare_t fanfares[] = {
    { MUS_ITEM_GEFUNDEN,      80 },
    { MUS_ITEM_ERHALTEN,     160 },
    { MUS_POKEMON_GEFANGEN,     220 },
    { MUS_BASISITEM_ERHALTEN,    220 },
    { MUS_POKEMON_WERDEN_GEHEILT,     160 },
    { MUS_ORDEN_ERHALTEN,   340 },
    { MUS_VERRUCKTER_SOUND,  180 },
    { MUS_BEERE_WURDE_GEPFLUCKT,  120 },
    { MUS_SOUND_GLUCKWUNSCH,   250 },
    { MUS_SOUND_GLUCKWUNSCH2, 150 },
    { MUS_VERRUCKTER_SOUND2,  160 },
    { MUS_POKEMON_FLOTE,    450 },
    { MUS_BASISITEM_ERHALTEN_VERSION_2,       170 },
    { MUS_SOUND_317,       196 },
    { FANFARE_GONG, 80},
};

void fanfare_by_fanfare_idx(u8 fanfare_idx) {
    // Omit Quest-Log stuff
    mplay_stop(mplay_info_background_music);
    fanfare_delay = fanfares[fanfare_idx].duration;
    DEBUG("Playing song idx %d as fanfare\n", fanfares[fanfare_idx].song_idx);
    mplay_start_song(fanfares[fanfare_idx].song_idx);
}

void fanfare_stop_by_fanfare_idx(u8 fanfare_idx) {
    mplay_stop_song(fanfares[fanfare_idx].song_idx);
}

void fanfare(u16 song_idx) {
    for (u8 i = 0; i < ARRAY_COUNT(fanfares); i++) {
        if (fanfares[i].song_idx == song_idx) {
            fanfare_by_fanfare_idx(i);
            fanfare_callback_wait_new();
            return;
        }
    }
    // Default fanfare
    fanfare_by_fanfare_idx(0);
    fanfare_callback_wait_new();
}