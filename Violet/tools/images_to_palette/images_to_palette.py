#!/usr/bin/env python3

import agb.image
import argparse
from pathlib import Path

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Puts images into a one palette')
    parser.add_argument('target_palette_image', help='The image that has the palette other images should be put into.')
    parser.add_argument('-i', help='Input image', dest='input_image')
    parser.add_argument('-o', help='The output png to create.', dest='output_path')
    parser.add_argument('-c', help='How many colors of the target palette to use', dest='num_target_colors', type=int, default=None)
    args = parser.parse_args()
    
    _, target_palette = agb.image.from_file(args.target_palette_image)
    if args.num_target_colors is not None:
        target_palette = target_palette[:args.num_target_colors]
    
    path = Path(args.input_image)
    image, palette = agb.image.from_file(path)
    image.apply_palette(palette, target_palette)
    image.save(
        args.output_path,
        target_palette.to_pil_palette()
    )
