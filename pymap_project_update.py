#!/usr/bin/python3

import os
import json
import pymap.project
import pymap.model.event, pymap.model.connection, pymap.model.header, pymap.model.tileset
import pymap.model.backend
import numpy as np

# This script adjusts the format of pymap files from version < 2.0 to version 2.0

def restructure(old, member_map):
    """ Renames the keys of a dictionary basically... """
    new = dict()
    for member in member_map:
        new[member_map[member]] = old[member]
    return new

def assert_structure_equality(structure, type):
    # Get the members of the structure
    members = set((member for member, _ in type.structure))
    if not (set(structure.keys()) == members):
        print(set(structure.keys()))
        print(members)
        print(set(structure.keys()).symmetric_difference(members))
        raise AssertionError

def blocks_typecast(blocks):
    """ Splits the values of a 2d block array into lists for bitfields. """
    return [
        [
            [block & (1 << 10), block >> 10] for block in line
        ] for line in blocks
    ]

def person_typecast(person):
    """ Typecasts an old person type into a new person type. """
    person = person.copy()
    # Remove unneccesary keys
    del person['is_trainer_padding']
    del person['type']
    del person['field_17']
    person['field_D'] = person.pop('field_d')
    person['field_B'] = person.pop('field_b')
    assert_structure_equality(person, pymap.model.event.person_type)
    return person

def warp_typecast(warp):
    """ Typecasts an old warp type into a new warp type. """
    warp = warp.copy()
    del warp['type']
    warp['target_warp_idx'] = warp.pop('target_warp')
    assert_structure_equality(warp, pymap.model.event.warp_type)
    return warp

def trigger_typecast(trigger):
    """ Typecasts an old trigger type into a new trigger type. """
    trigger = trigger.copy()
    del trigger['type']
    trigger['field_A'] = trigger.pop('field_a')
    trigger['field_B'] = trigger.pop('field_b')
    trigger['var'] = trigger.pop('variable')
    assert_structure_equality(trigger, pymap.model.event.trigger_type)
    return trigger

def signpost_typecast(signpost):
    """ Typecasts an old signpost type into a new signpost type. """
    signpost = signpost.copy()
    del signpost['type']
    del signpost['structure']
    signpost['type'] = signpost.pop('sign_type')
    # Fix according to structure
    value = {
        'script' : signpost.pop('script'),
        'item' : [
            signpost.pop('item_id'),
            signpost.pop('hidden'),
            int(signpost['count']) & 31,
            int(signpost.pop('count')) >> 5
        ]
    }
    signpost['value'] = value
    assert_structure_equality(signpost, pymap.model.event.signpost_type)
    return signpost

def connection_typecast(connection):
    """ Typecasts an old connection type into a new connection type. """
    connection = connection.copy()
    connection['field_A'] = connection.pop('fieldA')
    connection['field_B'] = connection.pop('fieldB')
    connection['map_idx'] = connection.pop('mapid')
    assert_structure_equality(connection, pymap.model.connection.connection_type)
    return connection

project = pymap.project.Project('proj.pmp')

# Fix map headers and extract map footers
"""
project.footers = {}

for bank in project.banks:
    for map_idx in project.banks[bank]:
        label, path, namespace, footer_idx = project.banks[bank][map_idx]
        dir_path = os.path.dirname(os.path.realpath(path))
        with open(path) as f:
            header_old = json.load(f)
        
        # Build the footer instance
        footer_old = header_old['footer']
        footer_new = restructure(footer_old, {
            'borders' : 'border',
            'tsp' : 'tileset_primary',
            'tss' : 'tileset_secondary',
            'blocks' : 'blocks',
        })
        width, height = footer_old['size']
        border_width, border_height = footer_old['border_size']
        footer_new['width'], footer_new['height'] = width, height
        footer_new['border_width'], footer_new['border_height'] = border_width, border_height
        footer_new['field_1A'] = 0
        footer_new['blocks'] = blocks_typecast(footer_new['blocks'])
        footer_new['border'] = blocks_typecast(footer_new['border'])

        output_path = os.path.join(dir_path, f'map_footer_{footer_idx}.pmf')
        with open(output_path, 'w+') as f:
            json.dump({
                'type' : 'footer',
                'label' : f'map_footer_{footer_idx}',
                'data' : footer_new
            }, f, indent='\t')

        project.footers[f'map_footer_{footer_idx}'] = (footer_idx, output_path)

        # Fix the map instance
        persons = list(map(person_typecast, header_old['persons']))
        warps = list(map(warp_typecast, header_old['warps']))
        triggers = list(map(trigger_typecast, header_old['triggers']))
        signposts = list(map(signpost_typecast, header_old['signposts']))
        event_header = {
            'person_cnt' : len(persons),
            'warp_cnt' : len(warps),
            'trigger_cnt' : len(triggers),
            'signpost_cnt' : len(signposts),
            'persons' : persons,
            'warps' : warps,
            'triggers' : triggers,
            'signposts' : signposts
        }

        # Fix the map connections
        connections = list(map(connection_typecast, header_old['connections']))
        connection_header = {
            'connection_cnt' : len(connections),
            'connections' : connections
        }

        header = {
            'footer' : f'map_footer_{footer_idx}',
            'events' : event_header,
            'levelscripts' : header_old['levelscript_header'],
            'connections' : connection_header,
            'music' : header_old['music'],
            'footer_idx' : footer_idx,
            'namespace' : header_old['name_bank'],
            'flash_type' : header_old['flash_type'],
            'weather' : header_old['weather'],
            'type' : header_old['type'],
            'field_18' : header_old['field_18'],
            'show_name' : header_old['show_name'],
            'field_1A' : header_old['field_1a'],
            'battle_style' : header_old['battle_style']
        }

        # Try to assembly header (ensures correctness of typings...)
        pymap.model.header.header_type.to_assembly(header, [])

        with open(path, 'w+') as f:
            json.dump({
                'type' : 'header',
                'label' : label,
                'data' : header
            }, f, indent='\t')

        #print(json.dumps(header, indent=1))
        #print(json.dumps(pymap.model.header.header_type([]), indent=1))
"""
# Fix tilesets
for label in project.tilesets:
    with open(project.tilesets[label]) as f:
        tileset_old = json.load(f)
    
    
    # Reshape the palette using np
    palette = np.array(tileset_old['palettes']).reshape((-1, 16, 3))
    # print(label, palette.shape)
    palette = palette.tolist()

    tileset = tileset_old.copy()
    tileset['gfx_compressed'] = 1 # I guess...
    tileset['field_2'] = 0
    tileset['field_3'] = 0
    tileset['animation_initialize'] = tileset.pop('init_func')
    del tileset['symbol']
    tileset['palettes'] = palette

    # Fix blocks
    blocks = np.array(tileset['blocks']).reshape((-1, ))
    blocks = list(map((lambda block: [
            block & 1023,
            (block >> 10) & 1,
            (block >> 11) & 1,
            (block >> 12) & 15
        ]), blocks.tolist()))
    blocks = np.array(blocks).reshape((-1, 8, 4))
    tileset['blocks'] = blocks.tolist()

    assert_structure_equality(tileset, pymap.model.tileset.tileset_type)
    # Try to assembly the tileset
    pymap.model.tileset.tileset_type.to_assembly(tileset, project, [])

    with open(project.tilesets[label], 'w+') as f:
        json.dump({
            'type' : 'tileset',
            'label' : label,
            'data' : tileset
        }, f, indent='\t')



project.save('proj.pmp')


