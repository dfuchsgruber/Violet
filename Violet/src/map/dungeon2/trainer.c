#include "types.h"
#include "dungeon/dungeon2.h"
#include "vars.h"
#include "constants/vars.h"
#include "map/event.h"
#include "save.h"
#include "constants/species.h"
#include "prng.h"
#include "pokemon/basestat.h"
#include "pokepad/wondertrade.h"
#include "text.h"
#include "debug.h"

u16 dungeon2_trainer_species[] = {
    POKEMON_BISAFLOR, POKEMON_GLURAK, POKEMON_TURTOK, POKEMON_FIARO,
    POKEMON_BIBOR, POKEMON_STARAPTOR, POKEMON_BRONZONG, POKEMON_CHEVRUMM,
    POKEMON_TROMBORK, POKEMON_RAICHU, POKEMON_SANDAMER, POKEMON_NIDOQUEEN,
    POKEMON_NIDOKING, POKEMON_FLORGES, POKEMON_VULNONA, POKEMON_KNUDDELUFF,
    POKEMON_GIFLOR, POKEMON_FOLIPURBA, POKEMON_FEELINARA, POKEMON_VOLTULA,
    POKEMON_DIGDRI, POKEMON_TENTANTEL, POKEMON_ENTORON, POKEMON_RASAFF,
    POKEMON_ARKANI, POKEMON_SIMSALA, POKEMON_MACHOMEI, POKEMON_SARZENIA,
    POKEMON_TENTOXA, POKEMON_GEOWAZ, POKEMON_GALLOPA, POKEMON_LAHMUS,
    POKEMON_DODRI, POKEMON_JUGONG, POKEMON_SLEIMOK, POKEMON_AUSTOS, POKEMON_GENGAR,
    POKEMON_HYPNO, POKEMON_KINGLER, POKEMON_LEKTROBAL, POKEMON_KOKOWEI,
    POKEMON_KNOGGA, POKEMON_KICKLEE, POKEMON_NOCKCHAN, POKEMON_SMOGMOG,
    POKEMON_ZOBIRIS, POKEMON_KANGAMA, POKEMON_APOQUALLYP, POKEMON_STARMIE,
    POKEMON_GALAGLADI, POKEMON_PINSIR, POKEMON_TAUROS, POKEMON_GARADOS, 
    POKEMON_LAPRAS, POKEMON_AQUANA, POKEMON_BLITZA, POKEMON_FLAMARA, POKEMON_RELAXO,
    POKEMON_MEGANIE, POKEMON_IMPERGATOR, POKEMON_TORNUPTO, POKEMON_GLAZIOLA, POKEMON_RESLADERO,
    POKEMON_ARIADOS, POKEMON_IKSBAT, POKEMON_MAGNEZONE, POKEMON_LANTURN,
    POKEMON_XATU, POKEMON_AMPHAROS, POKEMON_BLUBELLA, POKEMON_AZUMARILL,
    POKEMON_CLAVION, POKEMON_SKELABRA, POKEMON_REXBLISAR, POKEMON_AMBIDIFFEL,
    POKEMON_MORLORD, POKEMON_PSIANA, POKEMON_NACHTARA, POKEMON_LASCHOKING,
    POKEMON_KRAMSHEF, POKEMON_FROSDEDJE, POKEMON_SKORGRO, POKEMON_FORSTELLKA,
    POKEMON_ELEVOLTEK, POKEMON_STAHLOS, POKEMON_GRANBULL, POKEMON_MAMUTEL,
    POKEMON_SCHEROX, POKEMON_SKARABORN, POKEMON_URSARING, POKEMON_MAGCARGO,
    POKEMON_KEIFEL, POKEMON_OCTILLERY, POKEMON_SCHLURPLEK, POKEMON_PANZAERON,
    POKEMON_HUNDEMON, POKEMON_SEEDRAKING, POKEMON_DONPHAN, POKEMON_VOLUMINAS,
    POKEMON_TRAUNMAGIL, POKEMON_KAPOERA, POKEMON_MILTANK, POKEMON_STAHLSTICH,
    POKEMON_ZERBERTRES, POKEMON_SKULLYDRA, POKEMON_MAGNAYEN, POKEMON_GERADAKS,
    POKEMON_PAPINELLA, POKEMON_PUDOX, POKEMON_KAPPALORES, POKEMON_TENGULIST,
    POKEMON_NINJASK, POKEMON_SCHWALBOSS, POKEMON_KAPILZ, POKEMON_PELIPPER,
    POKEMON_MASKEREGEN, POKEMON_WAILORD, POKEMON_ENEKORO, POKEMON_KECLEON,
    POKEMON_LEPUMENTAS, POKEMON_MAGBRANT, POKEMON_ZWIRRFINST, POKEMON_WELSAR,
    POKEMON_RIHORNIOR, POKEMON_KREBUTACK, POKEMON_TOHAIDO, POKEMON_VOLTENSO,
    POKEMON_CAMERUPT, POKEMON_WALRAISA, POKEMON_NOKTUSKA, POKEMON_FIRNONTOR,
    POKEMON_SONNFEL, POKEMON_LUNASTEIN, POKEMON_GROINK, POKEMON_FLUNKIFER,
    POKEMON_MEDITALIS, POKEMON_ALTARIA, POKEMON_LETARKING, POKEMON_TROPIUS,
    POKEMON_AALABYSS, POKEMON_SAGANABYSS, POKEMON_ABSOL, POKEMON_BANETTE,
    POKEMON_SENGO, POKEMON_RELICANTH, POKEMON_STOLLOSS, POKEMON_GUARDEVOIR,
};

void dungeon2_init_trainer(u16 trainer_idx) {
    u8 level_mean = 0, level_std = 0;
    dungeon2_get_wild_pokemon_level_distribution(&level_mean, &level_std);
    fmem.gp_rng = cmem.dg2.initial_seed ;

    for (u16 i = trainer_idx; i < 0x1e4; i++)
        gp_rnd16(); // Advance the rng
    if (trainer_idx == 0x1e1 || trainer_idx == 0x1e3) {
        strcpy(fmem.dynamic_trainer_name, person_names[PERSON_NAME_FEMALE][gp_rnd16() % ARRAY_COUNT(person_names[PERSON_NAME_FEMALE])]);
    } else {
        strcpy(fmem.dynamic_trainer_name, person_names[PERSON_NAME_MALE][gp_rnd16() % ARRAY_COUNT(person_names[PERSON_NAME_MALE])]);
    }
    trainer_pokemon_default_item_default_attacks *trainer_party = (trainer_pokemon_default_item_default_attacks *)fmem.dynamic_trainer_party;
    int species_picked = 0;
    while (species_picked < 3) {
        u16 species = dungeon2_trainer_species[gp_rnd16() % ARRAY_COUNT(dungeon2_trainer_species)];
        bool duplicate = false;
        int type_matches = 0;
        for (int i = 0; i < species_picked; i++) {
            u16 other_species = fmem.dynamic_trainer_party[i].species;
            if (other_species == species)
                duplicate = true;
            if (basestats[species].type1 == basestats[other_species].type1 ||
                basestats[species].type2 == basestats[other_species].type1 || 
                basestats[species].type1 == basestats[other_species].type2 ||
                basestats[species].type2 == basestats[other_species].type2)
                type_matches++;
        }
        if (duplicate)
            continue;
        if (type_matches > (gp_rnd16()) % 3)
            continue;
        trainer_party[species_picked].species = species;
        trainer_party[species_picked].level = (u8)MIN(100, MAX(5, level_mean - level_std + (gp_rnd16() % 2 * level_std)));
        trainer_party[species_picked].ivs = 17;
        species_picked++;
    }
}