IMAGES_TO_PALETTE:=tools/images_to_palette/images_to_palette.py

POKEMON_ICON_GFX:=$(call rwildcard,asset/gfx/pokemon_icons/,*.png)
POKEMON_ICON_GREYSCALE_OBJ:=$(BLDPATH)/pokemon_icons_greyscale.o
POKEMON_ICON_GREYSCALE_SUFFIX:=_greyscaleTiles
POKEMON_ICON_GREYSCALE_PALETTE_IMAGE:=asset/gfx/pokemon_icons_greyscale/gfx_pokemon_icon_grey.png

# Pokemon icon greyscale
$(POKEMON_ICON_GREYSCALE_OBJ): $(POKEMON_ICON_GREYSCALE_PALETTE_IMAGE)
	@echo "Creating greyscale pokemon icon palette..."
	$(PY3) $(IMAGES_TO_PALETTE) $(POKEMON_ICON_GREYSCALE_PALETTE_IMAGE) -o $(BLDPATH)/pokemon_icons_greyscale.s -s $(POKEMON_ICON_GREYSCALE_SUFFIX) -i $(POKEMON_ICON_GFX) -c 15
	$(AS) $(ASFLAGS) $(BLDPATH)/pokemon_icons_greyscale.s -o $(POKEMON_ICON_GREYSCALE_OBJ)
