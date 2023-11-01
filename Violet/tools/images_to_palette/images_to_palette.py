#!/usr/bin/env python3

import agb.image
import argparse
from pathlib import Path
from tqdm import tqdm

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Puts images into a one palette')
    parser.add_argument('target_palette_image', help='The image that has the palette other images should be put into.')
    parser.add_argument('-i', help='Input images', nargs='+', dest='input_images')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    parser.add_argument('-s', help='The suffix to append to the image file name to create a symbol', dest='suffix')
    args = parser.parse_args()
    
    _, target_palette = agb.image.from_file(args.target_palette_image)
    assembly = []
    for path in tqdm(args.input_images):
        path = Path(path)
        image, palette = agb.image.from_file(path)
        image.apply_palette(palette, target_palette)
        assembly.append('.align 4')
        symbol = path.stem + args.suffix
        assembly.append(f'.global {symbol}')
        assembly.append(f'@ from "{path}" to palette of "{args.target_palette_image}"')
        assembly.append(f'{symbol}:')
        assembly.append('\t.byte ' + ', '.join(map(str, list(image.to_binary()))))
        assembly.append('')
    
    with open(args.output_path, 'w+') as f:
        f.write('\n'.join(assembly))
    