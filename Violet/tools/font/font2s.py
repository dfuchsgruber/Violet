#!/usr/bin/env python3

import numpy as np
import argparse
import agb.image

def assert_glyph_image(data):
    w, h = data.shape
    if w != 256:
        raise RuntimeError(f'The image width should be 256, not {w}')
    if h % 16 != 0:
        raise RuntimeError(f'The image height should be a multiple of 16, not {h}')    
    
    if not (data < 4).all():
        raise RuntimeError(f'Fonts can only use 4 colors')


def compute_glpyh_widths(data):
    """ Calculates the glyph widths automatically from a border using the transparent color 0
    at the right of each glyph.
    
    Parameters:
    -----------
    data : ndarray, shape [width, height]
        Pixel values of the spritesheet. As it is expected to be 2bpp indexed, each value has to be < 4
    
    Returns:
    --------
    widths : ndarray, shape [num_glyphs]
        The width of each glyph.
    """
    assert_glyph_image(data)
    w, h = data.shape
    num_rows = h // 16
    buffer = [] # 8-bit values
    
    for row in range(num_rows):
        for col in range(16):
            # Each glyph is 4 tiles of size 8x8
            # [0] [1]
            # [2] [3]
            glyph = data[16 * col : 16 * (col + 1), 16 * row : 16 * (row + 1)]
            for width in range(16, 0, -1):
                if (glyph[width - 1] != 0).any():
                    break
            buffer.append(width)
    return np.array(buffer, dtype=int)


def compress(data):
    """ Compresses a spritesheet of font glyphs to 2bpp.
    
    Parameters:
    -----------
    data : ndarray, shape [width, height]
        Pixel values of the spritesheet. As it is expected to be 2bpp indexed, each value has to be < 4
    
    Returns:
    --------
    compressed : ndarray, shape [buffer_size]
        The compressed sequence
    """
    assert_glyph_image(data)
    w, h = data.shape
    num_rows = h // 16
    buffer = [] # 8-bit values
    
    for row in range(num_rows):
        for col in range(16):
            # Each glyph is 4 tiles of size 8x8
            # [0] [1]
            # [2] [3]
            for glyph_tile_idx in range(4):
                # glyphs are compressed line-wise
                # iterate through all 8 lines of the 8x8 tile and compress
                # each line into 2 bytes
                x = 16 * col + (glyph_tile_idx % 2) * 8
                for line in range(8):
                    y = (row * 16) + line + (glyph_tile_idx // 2) * 8
                    base = 4
                    mask = base**np.arange(4, dtype=int)[::-1]
                    buffer.append(
                        (data[x + 4 : x + 8, y] * mask).sum()
                    )
                    buffer.append(
                        (data[x : x + 4, y] * mask).sum()
                    )
                    
    if len(buffer) != num_rows * 16 * 64:
        raise RuntimeError(f'Did not compress enough bytes?')
    return np.array(buffer)
    

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Compiles 2bpp font spritesheets into byte sequences.')
    parser.add_argument('input', help='The input png file. Must be indexed.')
    parser.add_argument('symbol', help='The symbol of the glyph set.')
    parser.add_argument('-w', help='The symbol of the glyph widths.', default=None, dest='width_symbol')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    img, _ = agb.image.from_file(args.input)
    compressed = compress(img.data)
    widths = compute_glpyh_widths(img.data)
    width_symbol = args.width_symbol
    if width_symbol is None:
        width_symbol = f'{args.symbol}_glyph_widths'

    output = '\n'.join([
        f'.global {args.symbol}',
        f'.global {width_symbol}',
        f'.align 4',
        f'{args.symbol}:',
        f'\t.byte ' + ', '.join(map(str, compressed)),
        f'.align 4',
        f'{width_symbol}:',
        f'\t.byte ' + ', '.join(map(str, widths)),
        ''
    ])
    with open(args.output_path, 'w+') as f:
        f.write(output)