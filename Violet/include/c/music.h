/* 
 * File:   music.h
 * Author: Domi
 *
 * Created on 9. Juni 2016, 11:57
 */

#ifndef MUSIC_H
#define	MUSIC_H


#include "types.h"

#define SONG_TYPE_SONG 0
#define SONG_TYPE_SOUND 1
#define SONG_TYPE_FANFARE 2
#define SONG_PLAYER_3 3


typedef struct {
    const void *mid;
    u16 type;
    u16 type2; //exact copy of type
} song;

/**
 * Plays a sound on the sound player.
 * @param sound Id of the sound to play
 */
void play_sound(u16 sound_id);

/**
 * Plays a song on the song player
 * @param song Id of the song to play
 * @feature Feature of the song
 */
void playsong1(u16 song, u8 feature);

/**
 * Plays a song of possible ?
 * @param song the song id to play
 */
void playsong2(u16 song);

/**
 * Plays a song on fanfare player
 * @param song_id id of the song to play
 */
void fanfare(u16 song_id);

/**
 * Callback that waits for the current fanfare and resumes to the normal song.
 * @param self self-reference in the big_callbacks array
 */
void fanfare_callback_wait(u8 self);

/**
 * Gets the song to play in battle
 * @param The song id to play
 */
u16 battle_get_song();

/**
 * Gets the song to play on the current map
 * @param The song id to play
 */
u16 map_get_song();

/**
 * Gets the encounter music corresponding to a trainer
 * @param trainer_id Id of the trainer
 * @return The music to play
 */
u16 trainer_get_encounter_song(u16 trainer_id);


/**
 * Sets the song player volume
 * @param a TODO
 * @param b TODO
 * @param volume the volume to set
 */
void volume_set(void *a, u16 b, u16 volume);

extern const unsigned char mus_rin_battle[];
extern const unsigned char mus_encounter_violet[];
extern const unsigned char mus_deoxys_battle[];
extern const unsigned char mus_titlescreen[];
extern const unsigned char mus_graveyard[];
extern const unsigned char mus_encounter_beethoven[];
extern const unsigned char mus_encounter_staccato[];
extern const unsigned char mus_encounter_cello[];
extern const unsigned char mus_silvania_forest[];
extern const unsigned char mus_new_day[];
extern const unsigned char mus_melancholy[];
extern const unsigned char mus_windy[];
extern const unsigned char mus_gym_leader[];
extern const unsigned char mus_trainer_battle[];
extern const unsigned char mus_wild_battle[];
extern const unsigned char mus_amonia[];
extern const unsigned char mus_jorney[];
extern const unsigned char mus_pokecenter[];
extern const unsigned char mus_violet_headquarter[];
extern const unsigned char mus_orina_city[];
extern const unsigned char mus_inferior[];
extern const unsigned char mus_victory_trainer[];
extern const unsigned char mus_kaskada_unused[];
extern const unsigned char mus_meriana_city[];
extern const unsigned char mus_encounter_rival[];
extern const unsigned char mus_volcano[];
extern const unsigned char mus_darkness[];
extern const unsigned char mus_groudon_rise[];
extern const unsigned char mus_summit[];
extern const unsigned char mus_cave[];
extern const unsigned char mus_asterisk_castle[];
extern const unsigned char mus_silvania[];
extern const unsigned char mus_aktania[];
extern const unsigned char mus_battle_violet[];
extern const unsigned char sound_step[];
extern const unsigned char mus_jeropardy[];
extern const unsigned char mus_trainerschool[];
extern const unsigned char mus_rival_battle[];
extern const unsigned char mus_desert[];
extern const unsigned char mus_revolution_battle[];
extern const unsigned char mus_kaskada[];
extern const unsigned char mus_revolution[];
extern const unsigned char mus_magmatic[];
extern const unsigned char mus_fur_elise[];
extern const unsigned char mus_dimensional_traveler[];
extern const unsigned char mus_queen_of_darkness_battle[];
extern const unsigned char mus_consuming_darkness[];
extern const unsigned char mus_blackbeard[];
extern const unsigned char mus_criminal_intentions[];
extern const unsigned char mus_mistral[];
extern const unsigned char mus_sky[];
extern const unsigned char mus_violet_sphere_v1[];
extern const unsigned char sound_hint[];
extern const unsigned char mus_mistral_battle[];
extern const unsigned char mus_ceometria[];
extern const unsigned char mus_monumental[];
extern const unsigned char mus_route_7[];
extern const unsigned char mus_glyphs[];
extern const unsigned char mus_riding_cloud[];
extern const unsigned char mus_amonia2[];
extern const unsigned char mus_gymleader_new[];
extern const unsigned char mus_laubdorf[];
extern const unsigned char mus_ceometria2[];
extern const unsigned char mus_surfer[];
extern const unsigned char mus_forest_cemetery[];
extern const unsigned char mus_haweiland[];
extern const unsigned char mus_regi_battle[];
extern const unsigned char mus_route_8[];
extern const unsigned char mus_ardeal[];
extern const unsigned char mus_lucius[];

#endif	/* MUSIC_H */

