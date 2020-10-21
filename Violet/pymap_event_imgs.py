# Backend for pymap's event images
from agb import agbrom
from PIL import Image
import os
from agb import image as agbimage
from agb import palette as agbpalette
import struct

base = './base/bprd.gba'
sprite_table = 0x39FC74
palette_table = 0x3A501C

# Load the rom
with open(base, 'rb') as f:
    rom = f.read()

picture_idx_to_png = {
    0 : 'asset/gfx/overworld/npcs/hiro/gfx_ow_hiro_0.png',
    1 : 'asset/gfx/overworld/npcs/hiro_cloud/gfx_pskate_0.png',
    2 : 'asset/gfx/overworld/npcs/hiro_sit/gfx_ow_hiro_sit_0.png',
    3 : 'asset/gfx/overworld/npcs/hiro_call/gfx_ow_hiro_call_0.png',
    4 : 'asset/gfx/overworld/npcs/hiro_rod/gfx_ow_hiro_rod_0.png',
    5 : 'asset/gfx/overworld/npcs/hiro_call2/gfx_ow_hiro_call2_0.png',
    6 : 'asset/gfx/overworld/npcs/hiro_call_bike/gfx_ow_hiro_call_bike_0.png',
    7 : 'asset/gfx/overworld/npcs/hiroine/gfx_ow_hiroine_0.png',
    8 : 'asset/gfx/overworld/npcs/hiro_cloud/gfx_pskatef_0.png',
    9 : 'asset/gfx/overworld/npcs/hiroine_sit/gfx_ow_hiroine_sit_0.png',
    10 : 'asset/gfx/overworld/npcs/hiroine_call/gfx_ow_hiroine_call_0.png',
    11 : 'asset/gfx/overworld/npcs/hiroine_rod/gfx_ow_hiroine_rod_0.png',
    12 : 'asset/gfx/overworld/npcs/hiroine_call/gfx_ow_hiroine_call_0.png',
    47 : 'asset/gfx/overworld/npcs/primus/gfx_ow_primus_0.png',
    49 : 'asset/gfx/overworld/npcs/violet_grunt_m/gfx_ow_violet_grunt_m_0.png',
    50 : 'asset/gfx/overworld/npcs/violet_grunt_f/gfx_ow_violet_grunt_f_0.png',
    53 : 'asset/gfx/overworld/npcs/butler/gfx_ow_butler_0.png',
    66 : 'asset/gfx/overworld/npcs/albus/gfx_ow_albus_0.png',
    67 : 'asset/gfx/overworld/npcs/blackbeard/gfx_ow_blackbeard.png.display',
    69 : 'asset/gfx/overworld/npcs/felix/gfx_ow_felix_0.png',
    70 : 'asset/gfx/overworld/npcs/harrenfeld/gfx_ow_harrenfeld_0.png',
    71 : 'asset/gfx/overworld/npcs/tann/gfx_ow_tann_0.png',
    72 : 'asset/gfx/overworld/npcs/rival/gfx_ow_rival_0.png',
    73 : 'asset/gfx/overworld/npcs/lucius/gfx_ow_lucius_0.png',
    75 : 'asset/gfx/overworld/npcs/narcissa/gfx_ow_narcissa.png.display',
    78 : 'asset/gfx/overworld/npcs/revolutionary/gfx_ow_revolutionary_0.png',
    79 : 'asset/gfx/overworld/npcs/faun/gfx_ow_faun_0.png',
    80 : 'asset/gfx/overworld/npcs/lester/gfx_ow_lester.png',
    81 : 'asset/gfx/overworld/npcs/gfx_ow_rosalie.png',
    82 : 'asset/gfx/overworld/npcs/manus/gfx_ow_manus_0.png',
    83 : 'asset/gfx/overworld/npcs/teah/gfx_ow_teah.png.display',
    86 : 'asset/gfx/overworld/npcs/igva/gfx_ow_igva_0.png',
    88 : 'asset/gfx/overworld/npcs/mother/gfx_ow_mother_0.png',
    89 : 'asset/gfx/overworld/npcs/blaise/gfx_ow_blaise_0.png',
    90 : 'asset/gfx/overworld/npcs/rin/gfx_ow_rin_0.png',
    93 : 'asset/gfx/overworld/npcs/gfx_ow_mega_stone.png',
    101 : 'asset/gfx/overworld/npcs/egg/gfx_ow_egg_0.png',
    103 : 'asset/gfx/overworld/npcs/faun_young/gfx_ow_faun_young_0.png',
    105 : 'asset/gfx/overworld/npcs/elise/gfx_ow_elise_0.png',
    106 : 'asset/gfx/overworld/npcs/larissa/gfx_ow_larissa_0.png',
    110 : 'asset/gfx/overworld/npcs/staralili/gfx_ow_staralili_0.png',
    111 : 'asset/gfx/overworld/npcs/voltilamm/gfx_ow_voltilamm_0.png',
    113 : 'asset/gfx/overworld/npcs/groudon/gfx_ow_groudon_0.png',
    133 : 'asset/gfx/overworld/npcs/regirock/gfx_ow_regirock_0.png',
    134 : 'asset/gfx/overworld/npcs/regice/gfx_ow_regice_0.png',
    135 : 'asset/gfx/overworld/npcs/registeel/gfx_ow_registeel_0.png',
    137 : 'asset/gfx/overworld/npcs/moltres/gfx_ow_moltres_0.png',
    150 : 'asset/gfx/overworld/npcs/deoxys_normal/gfx_ow_deoxys_normal_0.png',
    152 : 'asset/gfx/overworld/npcs/blackbeardship/gfx_ow_bbship.png',
    153 : 'asset/gfx/overworld/npcs/male_pirate/gfx_ow_mpirate_0.png',
    154 : 'asset/gfx/overworld/npcs/pokeradar/shape_0_animal/gfx_ow_shape_animal_0.png',
    155 : 'asset/gfx/overworld/npcs/pokeradar/shape_1_human/gfx_ow_shape_human_0.png',
    156 : 'asset/gfx/overworld/npcs/pokeradar/shape_2_tail/gfx_ow_shape_tail_0.png',
    157 : 'asset/gfx/overworld/npcs/pokeradar/shape_3_snake/gfx_ow_shape_snake_0.png',
    158 : 'asset/gfx/overworld/npcs/pokeradar/shape_4_winged_insect/gfx_ow_shape_winsect_0.png',
    159 : 'asset/gfx/overworld/npcs/pokeradar/shape_5_winged/gfx_ow_shape_winged_0.png',
    160 : 'asset/gfx/overworld/npcs/pokeradar/shape_6_insect/gfx_ow_shape_insect_0.png',
    161 : 'asset/gfx/overworld/npcs/pokeradar/shape_7_head/gfx_ow_shape_head_0.png',
    162 : 'asset/gfx/overworld/npcs/pokeradar/shape_8_arms/gfx_ow_shape_arms_0.png',
    163 : 'asset/gfx/overworld/npcs/pokeradar/shape_9_legs/gfx_ow_shape_legs_0.png',
    164 : 'asset/gfx/overworld/npcs/pokeradar/shape_10_tentacles/gfx_ow_shape_tentacles_0.png',
    165 : 'asset/gfx/overworld/npcs/pokeradar/shape_11_fish/gfx_ow_shape_fish_0.png',
    166 : 'asset/gfx/overworld/npcs/pokeradar/shape_12_ball/gfx_ow_shape_ball_0.png',
    167 : 'asset/gfx/overworld/npcs/pokeradar/shape_13_multi/gfx_ow_shape_multi_0.png',
    168 : "asset/gfx/overworld/npcs/mistral/gfx_ow_mistral_0.png",
    169 : "asset/gfx/overworld/npcs/golden_altaria/gfx_ow_altaria_0.png",
    170 : "asset/gfx/overworld/npcs/cloudrider/gfx_ow_cloudrider_fem_0.png",
    171 : "asset/gfx/overworld/npcs/cloudrider/gfx_ow_cloudrider_male_0.png",
    172 : "asset/gfx/overworld/npcs/diserakt/gfx_ow_diserakt_0.png",
    173 : "asset/gfx/overworld/npcs/rubys/gfx_ow_rubys_0.png",
    174 : "asset/gfx/overworld/npcs/botogel/gfx_ow_botogel_0.png",
    175 : "asset/gfx/overworld/npcs/drampa/gfx_ow_drampa.png.display",
    176 : "asset/gfx/overworld/npcs/gfx_ow_lucky.png",
    177 : "asset/gfx/overworld/npcs/gfx_ow_chef.png",
    178 : "asset/gfx/overworld/npcs/gfx_ow_lester_young.png",
    179 : "asset/gfx/overworld/npcs/gfx_ow_roman.png",
    180 : "asset/gfx/overworld/npcs/rival/gfx_ow_rival_beaten.png",
}

# Images that hold an entire spritesheet
spritesheet_images = {
    80 : (16, 32),
    81 : (16, 32),
    93 : (16, 16),
    176 : (16, 32),
    177 : (16, 32),
    178 : (16, 32),
    179 : (16, 32),
    180 : (32, 16),
}


class Event_to_image:
    """ Class to lazily load the images. """
    def __init__(self):
        self.images = {}

    def event_to_image(self, event, event_type, project):
        """ Provides a pilow image for the event or None if no image is associated. """
        os.chdir(os.path.dirname(project.path)) # Use the project directory as cwd for paths
        if event_type['datatype'] != 'event.person': return None
        try: 
            picture_idx = int(str(event['picture']), 0)
        except ValueError:
            return None

        if picture_idx in (238, 239): # Pokemon Overworlds
            species = str(event['value']['species'])[8:].lower() # Use the species as idx instead of a numerical value
            path = 'asset/gfx/overworld/pokemon/gfx_ow_' + species + '.png'
            if picture_idx == 238:
                box = ((0, 2 * 32, 32, 3 * 32))
            elif picture_idx == 239:
                box = ((0, 2 * 64, 64, 3 * 64))
            picture_idx = path
        elif picture_idx == 236: # Misc overworlds
            script_std = event['script_std']
            box = ((0, 16, 16, 32))
            if script_std == 'PERSON_MUSHROOM':
                path = os.path.join('asset', 'gfx', 'overworld', 'misc', 'gfx_ow_mushroom.png')
            elif script_std == 'PERSON_SHELL':
                path = os.path.join('asset', 'gfx', 'overworld', 'misc', 'gfx_ow_shell.png')
            else:
                return None
            picture_idx = path
        if picture_idx in self.images and self.images[picture_idx] is not None:
            image = self.images[picture_idx]
        elif picture_idx in picture_idx_to_png:
            # Use the hard assignment table in order to provide images
            image, palette = agbimage.from_file(picture_idx_to_png[picture_idx])
            image = image.to_pil_image(palette.to_pil_palette(), transparent=0)
            if picture_idx in spritesheet_images:
                w, h = spritesheet_images[picture_idx]
                image = image.crop((0, 0, w, h))
        elif isinstance(picture_idx, str):
            path = picture_idx
            if not os.path.exists(path):
                return None
            image, palette = agbimage.from_file(path)
            image = image.to_pil_image(palette.to_pil_palette(), transparent=0)
            image = image.crop(box)
        else:
            # Use the rom to retrieve sprites
            if picture_idx in range(152):
                overworld_struct_offset = struct.unpack_from('<I', rom, offset=sprite_table + 4 * picture_idx)[0] - 0x8000000
                gfx_struct_offset = struct.unpack_from('<I', rom, offset=overworld_struct_offset + 28)[0] - 0x8000000
                gfx_offset = struct.unpack_from('<I', rom, offset=gfx_struct_offset)[0] - 0x8000000
                width = struct.unpack_from('<H', rom, offset=overworld_struct_offset + 8)[0]
                height = struct.unpack_from('<H', rom, offset=overworld_struct_offset + 10)[0]
                pal_tag = struct.unpack_from('<H', rom, offset=overworld_struct_offset + 2)[0]
                # Search for the palette offset
                pal_offset = None
                for pal_idx in range(32): # Maximal 32 iterations to find a palette
                    tag = struct.unpack_from('<H', rom, offset=palette_table + 8 * pal_idx + 4)[0]
                    if tag == 0x11FF:
                        break # No palette associated with the overworlds tag
                    if tag == pal_tag:
                        pal_offset = struct.unpack_from('<I', rom, offset=palette_table + 8 * pal_idx)[0] - 0x8000000
                        break
                if pal_offset is None: return None
                image = agbimage.Image(rom[gfx_offset : gfx_offset + (width * height // 2)], width, height, depth=4)
                palette = agbpalette.from_data(rom[pal_offset : pal_offset + 16 * 2])
                # print(f'{hex(gfx_offset)}, {hex(pal_offset)}, {picture_idx}, {pal_tag}')
                image = image.to_pil_image(palette.to_pil_palette(), transparent=0)
            else:
                return None
        self.images[picture_idx] = image
        # Return shift of upper left corner of the image
        width, height = image.size
        horizontal_shift = 8 -  width // 2 # Center align horizontally
        vertical_shift = 16 - height # Align such that the bottom line is aligned with the block
        return image, horizontal_shift, vertical_shift

def get_event_to_image():
    return Event_to_image()