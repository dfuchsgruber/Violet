#include "types.h"
#include "save.h"
#include "vars.h"

typedef struct {
    u16 sector_id;
    u16 normal_size;
    u16 custom_size;
    u16 csave_offset;
} custom_save_block;

static const custom_save_block custom_save_blocks[] = {
    {
        .sector_id = 0,
        .normal_size = 0xF24,
        .custom_size = 0xCC,
        .csave_offset = 0,
    },
    {
        .sector_id = 4,
        .normal_size = 0xD98,
        .custom_size = 0x258,
        .csave_offset = 0xCC,
    },
    {
        .sector_id = 13,
        .normal_size = 0x450,
        .custom_size = 0xBA0,
        .csave_offset = 0x324,
    },
};

typedef char assert_save_sector_size[
    sizeof(save_sector_t) == SECTOR_SIZE ? 1 : -1];
typedef char assert_save_sector_location_size[
    sizeof(save_sector_location) == 8 ? 1 : -1];
typedef char assert_custom_memory_size[
    sizeof(custom_memory) == 0xEC4 ? 1 : -1];

static const custom_save_block *save_custom_block_get(u16 sector_id) {
    for (u32 i = 0; i < ARRAY_COUNT(custom_save_blocks); i++) {
        if (custom_save_blocks[i].sector_id == sector_id)
            return &custom_save_blocks[i];
    }
    return NULL;
}

static u8 save_test_pattern_byte(u16 offset) {
    u32 value = ((u32)offset * 73u + 41u) ^ ((u32)offset >> 3);
    return (u8)value;
}

static void save_bytes_copy(void *destination, const void *source, u16 size) {
    u8 *destination_bytes = destination;
    const u8 *source_bytes = source;

    for (u16 i = 0; i < size; i++)
        destination_bytes[i] = source_bytes[i];
}

static bool save_location_is_sane(const save_sector_location *location) {
    return location->size <= SECTOR_USED_END;
}

static void save_custom_block_load(
    const save_sector_t *sector,
    const save_sector_location *location
) {
    const custom_save_block *block = save_custom_block_get(sector->id);
    if (block == NULL || location->size != block->normal_size)
        return;

    const u8 *source = (const u8 *)sector + block->normal_size;
    u8 *destination = (u8 *)&csave + block->csave_offset;
    save_bytes_copy(destination, source, block->custom_size);
}

void save_custom_blocks_store(save_sector_t *sector) {
    const custom_save_block *block = save_custom_block_get(sector->id);
    if (block == NULL)
        return;

    u8 *destination = (u8 *)sector + block->normal_size;
    const u8 *source = (const u8 *)&csave + block->csave_offset;
    save_bytes_copy(destination, source, block->custom_size);
}

void save_test_pattern_fill(void) {
    u8 *custom_bytes = (u8 *)&csave;

    for (u16 i = 0; i < (u16)sizeof(csave); i++)
        custom_bytes[i] = save_test_pattern_byte(i);
}

void save_test_pattern_check(void) {
    u16 seen_sector_ids = 0;
    u16 physical_sector = (u16)(
        NUM_SECTORS_PER_SAVEFILE * (save_counter % NUM_SAVE_SLOTS));

    lastresult = 0;

    for (u16 i = 0; i < NUM_SECTORS_PER_SAVEFILE; i++) {
        read_flash_sector(
            (u8)(physical_sector + i),
            save_sector_buffer);

        u16 id = save_sector_buffer->id;
        if (id >= NUM_SECTORS_PER_SAVEFILE)
            return;

        u16 id_bit = (u16)(1u << id);
        if ((seen_sector_ids & id_bit) != 0)
            return;
        seen_sector_ids = (u16)(seen_sector_ids | id_bit);

        const save_section_locations_t *location =
            &save_section_locations[id];
        if (location->size > SECTOR_USED_END ||
            save_sector_buffer->signature != SECTOR_SIGNATURE ||
            save_sector_buffer->counter != save_counter ||
            save_sector_buffer->checksum != save_checksum_calculate(
                save_sector_buffer->data,
                location->size))
            return;

        const custom_save_block *block = save_custom_block_get(id);
        if (block == NULL)
            continue;
        if (location->size != block->normal_size)
            return;

        const u8 *stored_bytes =
            (const u8 *)save_sector_buffer + block->normal_size;
        for (u16 j = 0; j < block->custom_size; j++) {
            u16 pattern_offset = (u16)(block->csave_offset + j);
            if (stored_bytes[j] != save_test_pattern_byte(pattern_offset))
                return;
        }
    }

    if (seen_sector_ids == (u16)((1u << NUM_SECTORS_PER_SAVEFILE) - 1u))
        lastresult = 1;
}

u8 save_slot_data_load(
    u16 sector_id,
    const save_sector_location *locations
) {
    (void)sector_id;
    u16 physical_sector = (u16)(
        NUM_SECTORS_PER_SAVEFILE * (save_counter % NUM_SAVE_SLOTS));

    for (u16 i = 0; i < NUM_SECTORS_PER_SAVEFILE; i++) {
        read_flash_sector(
            (u8)(physical_sector + i),
            save_sector_buffer);

        u16 id = save_sector_buffer->id;
        if (id >= NUM_SECTORS_PER_SAVEFILE)
            continue;

        if (id == 0)
            last_written_sector = i;

        const save_sector_location *location = &locations[id];
        if (!save_location_is_sane(location))
            continue;

        const u8 *sector_bytes = (const u8 *)save_sector_buffer;
        u16 checksum = save_checksum_calculate(
            sector_bytes,
            location->size);

        if (save_sector_buffer->signature != SECTOR_SIGNATURE ||
            save_sector_buffer->checksum != checksum)
            continue;

        save_bytes_copy(
            location->data,
            sector_bytes,
            location->size);
        save_custom_block_load(
            save_sector_buffer,
            location);
    }

    return SAVE_STATUS_OK;
}

u8 save_sector_handle_write(
    u16 sector_id,
    const save_sector_location *locations
) {
    if (sector_id >= NUM_SECTORS_PER_SAVEFILE)
        return SAVE_STATUS_ERROR;

    u16 physical_sector = (u16)(
        (last_written_sector + sector_id) %
        NUM_SECTORS_PER_SAVEFILE);
    physical_sector = (u16)(
        physical_sector +
        NUM_SECTORS_PER_SAVEFILE * (save_counter % NUM_SAVE_SLOTS));

    const save_sector_location *location = &locations[sector_id];
    if (!save_location_is_sane(location))
        return SAVE_STATUS_ERROR;

    u8 *sector_bytes = (u8 *)save_sector_buffer;
    for (u16 i = 0; i < SECTOR_SIZE; i++)
        sector_bytes[i] = 0;

    save_sector_buffer->id = sector_id;
    save_sector_buffer->signature = SECTOR_SIGNATURE;
    save_sector_buffer->counter = save_counter;

    save_bytes_copy(
        sector_bytes,
        location->data,
        location->size);
    save_custom_blocks_store(save_sector_buffer);

    save_sector_buffer->checksum = save_checksum_calculate(
        location->data,
        location->size);

    return save_sector_try_write(
        (u8)physical_sector,
        sector_bytes);
}
