IMAGES_TO_PALETTE:=tools/images_to_palette/images_to_palette.py

POKEMON_ICON_GFX:=$(call rwildcard,asset/gfx/pokemon_icons/,*.png)
POKEMON_ICON_GFX_GREYSCALE:=$(POKEMON_ICON_GFX:%.png=$(BLDPATH)/%_greyscale.png)
POKEMON_ICON_GFX_GREYSCALE_C:=$(POKEMON_ICON_GFX_GREYSCALE:%.png=%.c)
POKEMON_ICON_GFX_GREYSCALE_OBJ:=$(POKEMON_ICON_GFX_GREYSCALE_C:%.c=%.o)

POKEMON_ICON_GREYSCALE_PALETTE_IMAGE:=asset/gfx/pokemon_icons_greyscale/gfx_pokemon_icon_grey.png

$(POKEMON_ICON_GFX_GREYSCALE): $(BLDPATH)/%_greyscale.png: %.png $(POKEMON_ICON_GREYSCALE_PALETTE_IMAGE) $(IMAGES_TO_PALETTE)
	@echo "Creating greyscale pokemon icon $@..."
	@mkdir -p $(dir $@)
	$(PY3) $(IMAGES_TO_PALETTE) $(POKEMON_ICON_GREYSCALE_PALETTE_IMAGE) -i $< -o $@ -c 15

$(POKEMON_ICON_GFX_GREYSCALE_C): %.c: %.png
	@echo "Creating greyscale pokemon icon C file $@..."
	@mkdir -p $(dir $@)
	$(GRIT) $< $(GRITFLAGS) -gu32 -gz! -gB 4 -gt -p! -m! -o $@

$(POKEMON_ICON_GFX_GREYSCALE_OBJ): %.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
