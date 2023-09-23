#include "types.h"
#include "save.h"
#include "debug.h"

EWRAM custom_memory csave = {0};

// static void csave_serialize() {
//     u8 *data = (u8*)&csave;
//     save_sector_buffer = &gp_save_sector_buffer;
//     size_t num_bytes_copied = 0;

//     for (size_t sector_id = 0; sector_id < NUM_SECTORS_PER_SAVEFILE && num_bytes_copied < sizeof(csave); sector_id++) {
//         // A bit iffy: we read the flash sector, replace the free data (the tail) with `csave`
//         // and then save the flash sector again
//         read_flash_sector(sector_id, save_sector_buffer);
//         for (size_t offset = save_section_locations[sector_id].size; 
//             offset < SECTOR_SIZE_DATA && num_bytes_copied < sizeof(csave); offset++) {
//             save_sector_buffer->data[offset] = data[num_bytes_copied++];
//         }
//     }

//     if (num_bytes_copied < sizeof(csave))
//         ERROR("Could not fully serialize csave of size %d\n", sizeof(csave));
// }

// static void csave_deserialize() {
//     u8 *data = (u8*)&csave;
//     save_sector_buffer = &gp_save_sector_buffer;
//     size_t num_bytes_copied = 0;
//     for (size_t sector_id = 0; sector_id < NUM_SECTORS_PER_SAVEFILE && num_bytes_copied < sizeof(csave); sector_id++) {
//         read_flash_sector(sector_id, save_sector_buffer);
//         for (size_t offset = save_section_locations[sector_id].size; 
//             offset < SECTOR_SIZE_DATA && num_bytes_copied < sizeof(csave); offset++) {
//             data[num_bytes_copied++] = save_sector_buffer->data[offset];
//         }
//     }
//     if (num_bytes_copied < sizeof(csave))
//         ERROR("Could not fully deserialize csave of size %d\n", sizeof(csave));
// }

// void save_serialize() {

// }

// void save_deserialize() {


// }