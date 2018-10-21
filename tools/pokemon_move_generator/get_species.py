#!/usr/bin/env python3

# Module to print all relevant species on the command line.
# This is to be used in the makefile.

import argparse
import pymap.project

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Prints all species constants.')
    parser.add_argument('project', help='The pymap project.')
    parser.add_argument('species_table', help='The name of the species table')
    args = parser.parse_args()

    project = pymap.project.Project(args.project)
    print(' '.join(project.constants[args.species_table]))
