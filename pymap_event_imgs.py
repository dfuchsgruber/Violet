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
    173 : "asset/gfx/overworld/rubys/gfx_ow_rubys_0.png",
    174 : "asset/gfx/overworld/botogel/gfx_ow_botogel_0.png",
}

def event_to_image(event, event_type, project):
    """ Provides a pilow image for the event or None if no image is associated. """
    os.chdir(os.path.dirname(project.path)) # Use the project directory as cwd for paths
    if event_type['datatype'] != 'event.person': return None
    try: 
        picture_idx = int(str(event['picture']), 0)
    except ValueError:
        return None
    if picture_idx in picture_idx_to_png:
        # Use the hard assignment table in order to provide images
        image, palette = agbimage.from_file(picture_idx_to_png[picture_idx])
        image = image.to_pil_image(palette.to_pil_palette(), transparent=0)
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
            image = image.to_pil_image(palette.to_pil_palette(), transparent=0)
        else:
            return None
    # Return shift of upper left corner of the image
    width, height = image.size
    horizontal_shift = width // 2 - 8 # Center align horizontally
    vertical_shift = 16 - height # Align such that the bottom line is aligned with the block
    return image, horizontal_shift, vertical_shift
