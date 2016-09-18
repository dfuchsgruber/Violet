#include "types.h"
#include "pokedex.h"
#include "map.h"

int pokedex_get_namespaces_of_species(pokedex_habitat_pair *dst, u16 species){
    int cnt = 0;
    int i = 0;
    wild_pokemon_data *wild_data = *wild_pokemon_data_ptr;
    while(wild_data[i].bank != 0xFF){
        
        u8 namespace = (u8)(get_mapheader(wild_data[i].bank, wild_data[i].map)->name_bank);
        
        //now we check each table if it contains the pokemon and if it does add it to the list
        //Grass table
        int j;
        for(j = 0; j < 12 && wild_data[i].grass; j++){
            if(wild_data[i].grass->data[j].species == species){
                u8 probability = 0; //rare
                if (j < 6)
                    probability++;
                if (j < 2)
                    
                    probability++;
               //check if the namespace is already registered with this style
                cnt = pokedex_get_namespace_of_species_add_pair_if_not_present(dst, cnt, namespace, probability, HABITAT_TYPE_GRASS);
            }
        }
        
        //Water table
        for(j = 0; j < 5 && wild_data[i].water; j++){
            if(wild_data[i].water->data[j].species == species){
                u8 probability = 0; //rare
                if (j < 2)
                    probability++;
                if (j < 1)
                    probability++;
                //check if the namespace is already registered with this style
                cnt = pokedex_get_namespace_of_species_add_pair_if_not_present(dst, cnt, namespace, probability, HABITAT_TYPE_WATER);
            }
        }
        
        //Rod
        for(j = 0; j < 10 && wild_data[i].rod; j++){
            if(wild_data[i].rod->data[j].species == species){
                u8 probability = 0; //rare
                if (j < 2)
                    probability++;
                if (j < 5)
                    probability++;
                //check if the namespace is already registered with this style
                cnt = pokedex_get_namespace_of_species_add_pair_if_not_present(dst, cnt, namespace, probability, HABITAT_TYPE_ROD);
            }
        }
        
        //Radar
        for(j = 0; j < 5 && wild_data[i].other; j++){
            if(wild_data[i].other->data[j].species == species){
                u8 probability = 0; //rare
                if (j < 1)
                    probability++;
                if (j < 2)
                    probability++;
                //check if the namespace is already registered with this style
                cnt = pokedex_get_namespace_of_species_add_pair_if_not_present(dst, cnt, namespace, probability, HABITAT_TYPE_RADAR);
            }
        }
        i++;
    }
    
    return cnt;
}

int pokedex_get_namespace_of_species_add_pair_if_not_present(pokedex_habitat_pair *dst, int cnt, u8 namespace, u8 propability, u8 type){
    int i;
    for(i = 0; i < cnt; i++){
        if(dst[i].namespace == namespace && dst[i].type == type && (type != HABITAT_TYPE_ROD || dst[i].propabilty == propability)){ // we only tolerate multiple entries for different propabilities in case of type == ROD
            if (dst[i].propabilty < propability)
                dst[i].propabilty = propability;
            //List was not enlarged but updated
            return cnt;
        }
    }
    dst[cnt].namespace = namespace;
    dst[cnt].propabilty = propability;
    dst[cnt].type = type;
    return cnt+1;
}


