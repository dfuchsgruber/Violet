---
name: violet-charmap
description: Work with Violet text encoding, PSTRING/autostring text, key glyphs, control tokens, and special escape sequences defined in Violet/charmap.txt.
---

# Violet Charmap

Use this when adding or reviewing encoded game text in C, assembly, scripts, or generated strings.

- The authoritative encoding table is `Violet/charmap.txt`; check it when you need a glyph, symbol, key icon, control code, or special token.
- `PSTRING("...")`, `.string`, `.autostring`, and script text are encoded through the charmap, so named tokens can be embedded directly in strings.
- Key glyphs are charmap tokens such as `KEY_A`, `KEY_B`, `KEY_START`, `KEY_SELECT`, `KEY_DPAD`, `KEY_LEFT_RIGHT`, and `KEY_UP_DOWN`.
- Other useful named sequences include text controls such as `COLOR`, `COLOR_HIGHLIGHT_SHADOW`, `PAUSE`, `PAUSE_UNTIL_PRESS`, `ESCAPE`, `PLAYER`, and `RIVAL`.
- Prefer existing named tokens from `charmap.txt` over raw byte escapes. Use raw byte escapes only when a token is missing or when matching nearby code.
- When rendering key prompts in UI callbacks, keep the string short and cache whether it is visible; text rendering is costly, so only redraw or clear the prompt when its state changes.
