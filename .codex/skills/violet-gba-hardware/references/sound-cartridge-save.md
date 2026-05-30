# Sound, Cartridge, And Save Hardware

Source: GBATEK GBA Sound Controller, Timers, DMA, and Cartridge sections: https://mgba-emu.github.io/gbatek/

## Sound

The GBA has:

- four PSG-style channels inherited from Game Boy hardware,
- two DMA sound channels, A and B.

DMA sound uses timers for sample rate and DMA1/DMA2 to feed FIFO registers. FIFO DMA transfers move small 32-bit bursts when the sound controller requests data.

Violet implications:

- Feature code should use existing music/sound helpers rather than programming timers, FIFOs, or sound DMA directly.
- Avoid large blocking DMA or long IRQ-disabled sections that could interfere with audio refill timing.
- UI code should use nearby sound IDs and helper calls for selection/cancel feedback.

## Timers

Timers can drive sound sample rates and game timing. Timer IRQs are hardware-level; ordinary feature scheduling should use frame callbacks or big callbacks unless the engine already exposes a timer abstraction.

## Game Pak ROM

- ROM is mapped at `0x08000000` and mirrored through wait-state regions.
- ROM bus width is 16-bit.
- DMA3 can read from Game Pak ROM/Flash; DMA0-2 cannot.

Violet implications:

- Large static assets live in ROM and are copied/decompressed into RAM/VRAM before use.
- Keep asset loads staged for UI setup.
- Do not assume direct ROM pointers are cheap inside tight per-frame loops; cache derived data when local patterns do.

## Save Region

The Game Pak SRAM/Flash address window is `0x0E000000-0x0E00FFFF` and is byte-width. EEPROM has separate protocol/timing constraints. GBATEK notes DMA restrictions for save media, especially that SRAM is CPU-only and bytewise.

Violet implications:

- Use existing save abstractions and `csave`/saveblock patterns.
- Do not write save hardware directly from feature code.
- Persistent feature state needs layout review and should not be mixed with temporary EWRAM UI state.

