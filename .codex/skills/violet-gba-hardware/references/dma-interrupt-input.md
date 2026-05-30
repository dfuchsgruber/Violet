# DMA, Interrupts, And Input

Source: GBATEK GBA DMA, Interrupt Control, Keypad Input, and LCD status sections: https://mgba-emu.github.io/gbatek/

## DMA Channels

The GBA has four DMA channels. Priority is DMA0 highest, then DMA1, DMA2, DMA3. Lower-priority DMA pauses while higher-priority DMA runs, and the CPU is paused while active DMA transfers run.

Channel roles:

- DMA0: best for timing-critical internal transfers, including HBlank-style effects.
- DMA1/DMA2: commonly used for sound FIFO.
- DMA3: general large copies and the only DMA channel that can access Game Pak ROM/Flash. It cannot access Game Pak SRAM.

DMA start timings:

- immediate,
- VBlank,
- HBlank,
- special mode. For DMA1/DMA2 this means sound FIFO; for DMA3 it means video capture.

Violet implications:

- Use existing `dma3_*`, graphics queue, palette queue, and VBlank helpers instead of directly programming DMA registers.
- Check `dma3_busy(-1)` before transitions that rely on copied assets.
- Avoid long high-priority DMA while sound DMA is active; it can starve FIFO refills.

## Interrupts

Core interrupt registers:

- `IME`: master interrupt enable.
- `IE`: enabled interrupt sources.
- `IF`: requested interrupt flags; acknowledge by writing `1` to handled bits.

Common sources include VBlank, HBlank, VCounter, timers, serial, DMA0-3, keypad, and Game Pak external IRQ.

BIOS interrupt dispatch uses the user IRQ handler pointer near the top of IWRAM. Keep IRQ handlers short and avoid stack-heavy work.

Violet implications:

- Keep gameplay/UI logic out of IRQ handlers.
- Use vblank callbacks for flushing queued graphics/OAM/palette/DMA work.
- Do not manipulate interrupt/DMA registers casually in feature code; follow existing engine wrappers.

## Keypad

`KEYINPUT` stores button state with active-low bits: `0` means pressed, `1` means released.

GBATEK recommends reading the keypad once per frame and storing the result in memory. Normal user input should not use keypad IRQ; keypad IRQ is intended mainly for waking from low-power Stop mode.

Violet already follows this pattern through `super.keys`, `super.keys_new`, `super.keys_new_remapped`, and `super.keys_new_and_repeated`.

Violet implications:

- Use `super.keys_new` for one-shot actions.
- Use `super.keys_new_and_repeated` for held directional movement.
- Prefer input work inside big callbacks/tasks, proceeded by `generic_callback1` or the current screen pump.

