#include "types.h"
#include "abilities.h"
#include "pokemon.h"
#include "romfuncs.h"


u16 mitnahme_items[10][11] = {
  //1, 1, 3, 3, 3, 3, 3, 3, 5, 10, 30 in %
    {ITEM_NUGGET, ITEM_HYPERTRANK, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_GEGENGIFT, ITEM_TRANK},
    {ITEM_KING_STEIN, ITEM_NUGGET, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_GEGENGIFT},
    {ITEM_TOP_GENESUNG, ITEM_KING_STEIN, ITEM_NUGGET, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL, ITEM_SUPERTRANK},
    {ITEM_TOP_GENESUNG, ITEM_KING_STEIN, ITEM_AETHER, ITEM_SONDERBONBON, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL},
    {ITEM_TOP_GENESUNG, ITEM_KING_STEIN, ITEM_AETHER, ITEM_SONDERBONBON, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ},
    {ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL},
    {ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER},
    {ITEM_TOP_BELEBER, ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK},
    {ITEM_UEBERRESTE, ITEM_TOP_BELEBER, ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL},
    {ITEM_GLUECKS_EI, ITEM_UEBERRESTE, ITEM_TOP_BELEBER, ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER}
    
};

u16 *mitnahme_pick_item(pokemon *p){
    u32 l = (get_pokemons_attribute(p, ATTRIBUTE_LEVEL, 0)-1) / 10;
    u32 r = rnd16() % 100;
    if(r < 1) return &mitnahme_items[l][0];
    if(r < 2) return &mitnahme_items[l][1];
    if(r < 5) return &mitnahme_items[l][2];
    if(r < 10) return &mitnahme_items[l][3];
    if(r < 20) return &mitnahme_items[l][4];
    if(r < 30) return &mitnahme_items[l][5];
    if(r < 40) return &mitnahme_items[l][6];
    if(r < 60) return &mitnahme_items[l][7];
    if(r < 70) return &mitnahme_items[l][8];
    return &mitnahme_items[l][9];
}

void bsc_cmd_mitnahme(){
    
    int i;
    for (i = 0; i < 6; i++){
        if(!get_pokemons_attribute(&player_pokemon[i], ATTRIBUTE_ITEM, 0) && 
                !get_pokemons_attribute(&player_pokemon[i], ATTRIBUTE_IS_EGG, 0) &&
                get_pokemons_ability(&player_pokemon[i]) == MITNAHME &&
                !__aeabi_uidivmod(rnd16(), 10)){
            //Trigger 'Mitnahme' on this pokemon
            set_pokemons_attribute(&player_pokemon[i], ATTRIBUTE_ITEM, mitnahme_pick_item(&player_pokemon[i]));
        }
    }
    
    
    u8 **bsc_offset = (u8**)0x02023D74;
    (*bsc_offset)++;
}
