#!/usr/bin/env python3
from pathlib import Path
import re


TRAINER_C = Path(__file__).resolve().parents[1] / "src/overworld/restaurant/trainer.c"
ARRAY_DECL = "const restaurant_species_t *const restaurant_species[NUM_TYPES]"
GENERATED_DECL = "const restaurant_species_t restaurant_species_min_levels[]"
BEGIN_MARKER = "/* BEGIN GENERATED RESTAURANT SPECIES MIN LEVELS */"
END_MARKER = "/* END GENERATED RESTAURANT SPECIES MIN LEVELS */"


def find_initializer_end(text, decl):
    start = text.index(decl)
    brace = text.index("{", start)
    depth = 0
    for idx in range(brace, len(text)):
        if text[idx] == "{":
            depth += 1
        elif text[idx] == "}":
            depth -= 1
            if depth == 0:
                semi = text.index(";", idx)
                return start, semi + 1
    raise ValueError(f"Could not find end of {decl}")


def level_value(level):
    match = re.fullmatch(r"RESTAURANT_LEVEL_(\d+)", level)
    if not match:
        raise ValueError(f"Unexpected restaurant level: {level}")
    return int(match.group(1))


def parse_species_levels(block):
    entry_pattern = re.compile(
        r"\{\s*(?:"
        r"(POKEMON_[A-Z0-9_]+)\s*,\s*(RESTAURANT_LEVEL_\d+)"
        r"|"
        r"\.species\s*=\s*(POKEMON_[A-Z0-9_]+)\s*,\s*"
        r"\.appears_at_level\s*=\s*(RESTAURANT_LEVEL_\d+)"
        r")\s*\}"
    )

    minimums = {}
    order = []
    for match in entry_pattern.finditer(block):
        species = match.group(1) or match.group(3)
        level = match.group(2) or match.group(4)
        if species not in minimums:
            order.append(species)
            minimums[species] = level
        elif level_value(level) < level_value(minimums[species]):
            minimums[species] = level

    return [(species, minimums[species]) for species in order]


def render_array(entries):
    lines = [
        BEGIN_MARKER,
        f"{GENERATED_DECL} = {{",
    ]
    lines.extend(f"    {{{species}, {level}}}," for species, level in entries)
    lines.extend([
        "    {0xFFFF, 0}",
        "};",
        END_MARKER,
    ])
    return "\n".join(lines)


def replace_generated_array(text, generated):
    if BEGIN_MARKER in text:
        start = text.index(BEGIN_MARKER)
        end = text.index(END_MARKER, start) + len(END_MARKER)
        return text[:start] + generated + text[end:]

    _, array_end = find_initializer_end(text, ARRAY_DECL)
    return text[:array_end] + "\n\n" + generated + text[array_end:]


def update_all_types_lookup(text):
    old = """        for (size_t j = 0; j < NUM_TYPES; j++) {
            const restaurant_species_t *species = restaurant_species[j];
            for (size_t i = 0; species[i].species != 0xFFFF; i++) {
                if (species[i].appears_at_level <= level) {
                    list[num_found++] = species[i].species;
                }
            }
        }"""
    new = """        for (size_t i = 0; restaurant_species_min_levels[i].species != 0xFFFF; i++) {
            if (restaurant_species_min_levels[i].appears_at_level <= level) {
                list[num_found++] = restaurant_species_min_levels[i].species;
            }
        }"""
    if old in text:
        return text.replace(old, new, 1)
    if new in text:
        return text
    raise ValueError("Could not find restaurant_get_random_species all-types loop")


def main():
    text = TRAINER_C.read_text()
    start, end = find_initializer_end(text, ARRAY_DECL)
    entries = parse_species_levels(text[start:end])
    text = replace_generated_array(text, render_array(entries))
    text = update_all_types_lookup(text)
    TRAINER_C.write_text(text)
    print(f"Wrote {len(entries)} unique species to {TRAINER_C}")


if __name__ == "__main__":
    main()
