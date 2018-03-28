#!/usr/bin/env python3
""" Fixes all scripts by finding correct .include directives """
from pymap import project
import os

proj = project.Project.load_project("map/proj.pmp")
consts = proj.constants

def fix_file(filepath):
    """ Fixes a single .asm file """
    with open(filepath, "r") as f:
        content = f.read()
    
    labels = set()

    # Iterate over all includes
    for label in consts._constants:
        for value in consts.values(label):
            if value in content:
                labels.add(label)
    
    # Create include directives
    content = "\n".join([
        consts.get_include_directive(label, "as")
        for label in labels
    ]) + "\n" + content

    # Output file
    if len(labels):
        print("Fixing includes for {0}".format(
            filepath
        ))
        with open(filepath, "w") as f:
            f.write(content)

for root, _, files in os.walk("map"):
        for file in files:
            if file.endswith(".asm"):
                filepath = os.path.join(root, file)
                fix_file(filepath)