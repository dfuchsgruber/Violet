#!/usr/bin/env python3

from typing import Dict
import agb.types
import pymap.project
import argparse

def get_move_tutor_crystals(project: pymap.project.Project) -> Dict:
    """ Gets move tutor crystals in the project as a dict."""
    move_tutors = dict()

    for bank in project.headers:
        for map_idx in project.headers[bank]:
            header, label, namespace = project.load_header(bank, map_idx)
            for person_idx, person in enumerate(header['events']['persons']):
                try:
                    if person['script_std_and_in_connection']['script_std'] == 'PERSON_ACCESSIBLE_MOVE_TUTOR':
                        move_tutor_idx = person['value']['type']
                        if move_tutor_idx in move_tutors:
                            raise RuntimeError(f'Move tutor  crystal{move_tutor_idx} is used multiple times: {move_tutors[move_tutor_idx]}')
                        move_tutors[move_tutor_idx] = {
                            'bank' : bank,
                            'map_idx' : map_idx,
                            'person_idx' : person['target_index'],
                            'label' : label,
                        }
                except Exception as e:
                    print(f'Error in parsing move tutor crystal {person_idx} on map {bank},{map_idx}')
                    raise e
    return move_tutors

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Creates metadata for move tutor crystals')
    parser.add_argument('symbol', help='The symbol of the move tutor crystals')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('-o', help='The output assembly to create.', dest='output_path')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)
    move_tutors = get_move_tutor_crystals(project)

    data = []
    for i in range(len(project.constants['pokemon_types'])):
        move_tutor_idx = project.constants['pokemon_types'].inverse()[i]
        assert len(move_tutor_idx) == 1
        move_tutor_idx = move_tutor_idx[0]
        data.append(f'@ move tutor crystal {i}, {move_tutor_idx}')
        if move_tutor_idx in move_tutors:
            move_tutor = move_tutors[move_tutor_idx]
            data.append(f'\t.byte ' + ', '.join(map(str, [
                move_tutor['bank'], move_tutor['map_idx'], move_tutor['person_idx'], '0'
            ])))
        else:
            data.append('\t.byte 0xFF, 0xFF, 0xFF, 0xFF')
    blocks = [
        agb.types.label_and_align('\n'.join(data), args.symbol, 2, True),
    ]
    with open(args.output_path, 'w+') as f:
        f.write('\n\n'.join(blocks + ['']))
    