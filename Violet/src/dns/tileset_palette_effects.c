#include "types.h"
#include "rtc.h"
#include "map/footer.h"
#include "color.h"
#include "save.h"
#include "dns.h"
#include "debug.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "vars.h"
#include "bios.h"


static const color_t dns_color_light_yellow = {.rgb = {.red = 232 / 8, .green = 216 / 8, .blue = 104 / 8}};
static const color_t dns_color_light_yellow_dark = {.rgb = {.red = 216 / 8, .green = 168 / 8, .blue = 48 / 8}};
static const color_t dns_color_light_yellow_weak_dark = {.rgb = {.red = 248 / 8, .green = 200 / 8,
    .blue = 112 / 8}};
static const color_t dns_color_light_yellow_light = {.rgb = {.red = 248 / 8, .green = 232 / 8,
    .blue = 192 / 8}};
static const color_t dns_color_flame_yellow = {.rgb = {.red = 31, .green = 25, .blue = 7}};
static const color_t dns_color_flame_orange = {.rgb = {.red = 31, .green = 17, .blue = 7}};

bool tileset_primary_is_clouds(const tileset *tsp) {
    return (tsp == &maptileset_clouds) || (tsp == &maptileset_clouds_canyon) || (tsp == &maptileset_clouds_pink) || (tsp == &maptileset_clouds_dark_green);
}

void overworld_tilesets_apply_palette_effects(const map_footer_t *foot) {

    if (dns_on()) {
        if (foot->tileset1 == &maptileset0 || foot->tileset1 == &maptileset0_kaskada ||
            foot->tileset1 == &maptileset0_aktania || foot->tileset1 == &maptileset0_route_4) {
            //Tileset1 = 0
            pal_restore[0x21] = dns_color_light_yellow;
            pal_restore[0x22] = dns_color_light_yellow;
            pal_restore[0x25] = dns_color_light_yellow_dark;
        } else if (tileset_primary_is_clouds(foot->tileset1)) {
            pal_restore[2 * 16 + 14] = dns_color_flame_yellow;
            pal_restore[2 * 16 + 15] = dns_color_flame_orange;
        }
        if (foot->tileset2 == &maptileset_orina_city) {
            //Orina City TS2
            pal_restore[7*16+7] = dns_color_light_yellow_weak_dark;
            pal_restore[7*16+6] = dns_color_light_yellow;
            pal_restore[7*16+13] = dns_color_light_yellow;
            pal_restore[7*16+14] = dns_color_light_yellow_dark;
            pal_restore[7*16+10] = dns_color_light_yellow_dark;
            
            pal_restore[11*16+7] = dns_color_light_yellow_weak_dark;
            pal_restore[11*16+6] = dns_color_light_yellow;
            pal_restore[11*16+13] = dns_color_light_yellow;
            pal_restore[11*16+14] = dns_color_light_yellow_dark;
            pal_restore[11*16+10] = dns_color_light_yellow_dark;
            
            pal_restore[8*16+8] = dns_color_light_yellow;
            pal_restore[8*16+13] = dns_color_light_yellow;
            pal_restore[8*16+14] = dns_color_light_yellow;
            pal_restore[8*16+15] = dns_color_light_yellow_dark;
            
            pal_restore[9*16+12] = dns_color_light_yellow;
            pal_restore[9*16+15] = dns_color_light_yellow;
            pal_restore[9*16+11] = dns_color_light_yellow_dark;
        } else if (foot->tileset2 == &maptileset4) {
            //Route 5, enlighten torches
            pal_restore[8*16+14].value = 0x05DB;
            pal_restore[8*16+15].value = 0x0ADE;
        } else if (foot->tileset2 == &maptileset1) {
            //Route 1, Trainerschool
            pal_restore[8*16+3] = dns_color_light_yellow_dark;
            pal_restore[8*16+4] = dns_color_light_yellow;
            pal_restore[8*16+5] = dns_color_light_yellow;
            pal_restore[8*16+6] = dns_color_light_yellow_weak_dark;
        } else if (foot->tileset2 == &maptileset249598) {
            //Bruchfels
            pal_restore[8*16+4] = dns_color_light_yellow_weak_dark;
            pal_restore[8*16+5] = dns_color_light_yellow_dark;
            pal_restore[8*16+14] = dns_color_light_yellow;
        } else if (foot->tileset2 == &maptileset2) {
            // Route 2, Sonnaufeld
            pal_restore[7*16+12] = dns_color_light_yellow;
            pal_restore[7*16+9] = dns_color_light_yellow_dark;
            pal_restore[10*16+10] = dns_color_light_yellow_dark;
            pal_restore[10*16+11] = dns_color_light_yellow;
            pal_restore[10*16+12] = dns_color_light_yellow;
            pal_restore[10*16+13] = dns_color_light_yellow_weak_dark;
        } else if (foot->tileset2 == &maptileset3) {
            //Route 3
            pal_restore[10*16+10] = dns_color_light_yellow;
            pal_restore[10*16+12] = dns_color_light_yellow_dark;
        } else if (foot->tileset2 == &maptileset302795) {
            //Kranzdorf
            pal_restore[8*16+2] = dns_color_light_yellow_dark;
            pal_restore[8*16+11] = dns_color_light_yellow;
        } else if (foot->tileset2 == &maptileset242637) {
            pal_restore[11*16+2] = dns_color_light_yellow;
            pal_restore[11*16+7] = dns_color_light_yellow_dark;
        } else if (foot->tileset2 == &maptileset251828) {
            //Inferior, Route 6, Vulcano, Ashhain
            pal_restore[11*16+2].value = 0x0CFA;
            pal_restore[11*16+9].value = 0x1A3F;
            pal_restore[11*16+10].value = 0x0D5D;
            pal_restore[11*16+12].value = 0x12BF;
            pal_restore[7*16+5].value = 0x21DF;
            pal_restore[7*16+6].value = 0x21DC;
            pal_restore[7*16+7].value = 0x2D96;
            pal_restore[7*16+8].value = 0x2954;
            pal_restore[7*16+9].value = 0x00D9;
            pal_restore[7*16+10].value = 0x00D2;
            pal_restore[7*16+11].value = 0x0C7E;
            pal_restore[7*16+12].value = 0x025E;
        } else if (foot->tileset2 == &maptileset_laubdorf) {
            pal_restore[7 * 16 + 14] = dns_color_light_yellow_dark;
            pal_restore[7 * 16 + 15] = dns_color_light_yellow;
            pal_restore[8 * 16 + 13] = dns_color_light_yellow_dark;
            pal_restore[8 * 16 + 14] = dns_color_light_yellow;
            pal_restore[8 * 16 + 15] = dns_color_light_yellow_light;
            pal_restore[9 * 16 + 13] = dns_color_light_yellow_dark;
            pal_restore[9 * 16 + 14] = dns_color_light_yellow;
            pal_restore[9 * 16 + 15] = dns_color_light_yellow_light;
        } else if (foot->tileset2 == &maptileset_cloud_ruins) {
            pal_restore[9 * 16 + 8] = dns_color_flame_orange;
            pal_restore[9 * 16 + 8] = dns_color_flame_yellow;
        } else if (foot->tileset2 == &maptileset_blackbeard_ship) {
            // Copy the entire palette (yes, I "wasted" an entire palette for this effect)
            cpuset(maptileset_blackbeard_ship.colors, pal_restore + 10 * 16, CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
        }
    }
}


void tileset_load_pal_as_primary(const map_footer_t *foot){
    fmem.current_tileset_1 = foot->tileset1;
    overworld_load_tileset_pal(foot->tileset1, 0, 0xE0);

}

void tileset_load_pal_as_secondary(const map_footer_t *foot){
    fmem.current_tileset_2 = foot->tileset2;
    overworld_load_tileset_pal(foot->tileset2, 0x70, 0xC0);
}

void overworld_load_tileset_pals(const map_footer_t *footer) {
    if (footer) {
        tileset_load_pal_as_primary(footer);
        tileset_load_pal_as_secondary(footer);
        overworld_tilesets_apply_palette_effects(footer);
    }
}

static void overworld_load_tileset_pal_without_palette_effect(const tileset *ts, u16 dst_color, u16 size) {
    pal_copy(ts->info.color_section ? ts->colors + 7 * 16 : ts->colors, dst_color, size);
}

void overworld_load_tileset_pals_without_palette_effects(const map_footer_t *footer) {
    if (footer) {
        overworld_load_tileset_pal_without_palette_effect(footer->tileset1, 0, sizeof(color_t) * 7 * 16);
        overworld_load_tileset_pal_without_palette_effect(footer->tileset2, 7 * 16, sizeof(color_t) * 6 * 16);
    }
}

void map_transition_update_tilesets() {
    const map_footer_t *footer = mapheader_virtual.footer;
    if (footer) {
        tileset_load_pal_as_primary(footer);
        if (fmem.current_tileset_2 != footer->tileset2) {
            tileset_load_pal_as_secondary(footer);
            overworld_tilesets_apply_palette_effects(footer);
        }
        overworld_load_tilesets(footer);
    }
}
