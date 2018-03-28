#!/usr/bin/env python3

from pokestring import pstring
import pstringold
import os

#############################################################
# Fix langdep for the already 'fixed' assemblies
for root, _, files in os.walk("./map"):
        for file in files:
            if file.endswith(".asm"):
                filepath = os.path.join(root, file)
                with open(filepath, "r") as f:
                    content = f.read()
                if ".string" in content:
                    # Find the first string directive
                    i = content.index(".global str_")
                    new_content = content[:i]
                    new_content += "\n.ifdef LANG_GER\n"
                    new_content += content[i:]
                    new_content += "\n.elseif LANG_EN\n\n.endif\n"
                    with open(filepath, "w") as f:
                        f.write(new_content)

exit(0)

#############################################################

table = pstringold.parse_table("../backup/Violet_Sources/table.tbl")
ps = pstring.Pstring("charmap.txt", terminator=0xFF)


def _mkdirs(dir):
    if not os.path.exists(dir):
        print("Creating directory {0}".format(dir))
        os.makedirs(dir)

def stream_from_string(bytes):
    """ Creates an agbromlike stream from a byteschain """
    class Stream:
        def __init__(self, bytes):
            self.bytes = bytes
        def u8(self, offset):
            return self.bytes[offset]
    return Stream(bytes)

def bytes_to_string(bytes):
    """ Parses the bytes and translates them back to
    a string. """
    return ps.hex2str(stream_from_string(bytes), 0)

def fix_file(filepath):
    """ Fixes a certain file and returns the fixed content """
    with open(filepath, "r") as f:
        content = f.read()
    
    return parse_file(content)
    
    

def parse_file(content):
    """ Parses a string file and retrieves all strings """
    lines = content.splitlines()
    strings = {"GER" : {}, "EN" : {}}
    arrays = {"GER" : {}, "EN" : {}}
    i = 0
    while i < len(lines):
        line = remove_comments(lines[i])
        i += 1
        if not len(line):
            continue
        # Remove commentes
        tokens = line.split()
        if tokens[0] == ".string":
            # Regular string directive
            label = tokens[1]
            language = tokens[2]
            if language == "ENG": language = "EN" # Silly me...
            line = remove_comments(lines[i])
            bytes = pstringold.parse_str(line[line.index("=") + 1:],
                table, 0xFF)
            string = bytes_to_string(bytes)
            line = remove_comments(lines[i + 1])
            if not line.startswith(".end"):
                raise Exception("Expected .end directive, got \
                {0}".format(line))
            i += 2

            if language == "_":
                # Must be added for all languages
                langs = strings.keys()
            else:
                langs = (language,)

            for language in langs:
                if label in strings[language]:
                    raise Exception("Label {0} for language {1} redefined!".format(
                        label, language))
                strings[language][label] = string 
        elif tokens[0] == ".array":
            # String array directive
            label = tokens[1]
            language = tokens[2]
            if language == "ENG": language = "EN" # Silly me...
            size = int(tokens[3])
            members = []
            while True:
                # Parse lines until .end directive reached
                line = remove_comments(lines[i])
                i += 1
                if not len(line):
                    continue
                if line.startswith(".end"):
                    break
                # Expect ...=value
                bytes = pstringold.parse_str(line[line.index("=") + 1:],
                    table, 0xFF)
                string = bytes_to_string(bytes)
                members.append(string)

            if language == "_":
                # Must be added for all languages
                langs = strings.keys()
            else:
                langs = (language,)

            for language in langs:
                if label in arrays[language]:
                    raise Exception("Label {0} for language {1} redefined!".format(label, language))
                arrays[language][label] = members, size
    return strings, arrays

def remove_comments(line):
    """ Removes comments from line and strips """
    if "#" in line:
        line = line[:line.index("#")].strip()
    return line.strip()



#testfile = "../backup/Violet_Sources/asset/string/ability/ability_names_de.txt"
#testfile = "../backup/Violet_Sources/asset/string/mega.txt"

outdir = "src/string"

for root, _, files in os.walk("../backup/Violet_Sources/asset/string"):
        for file in files:
            if file.endswith(".txt"):
                filepath = os.path.join(root, file)
                base, extension = os.path.splitext(file)
                outbase = os.path.join(outdir, base)
                print("Fixing {0}...".format(filepath))
                print("Output base is {0}...".format(outbase))
                strings, arrays = fix_file(filepath)

                # Parse .string directives
                if len(strings["GER"]) or len(strings["EN"]):
                    outfile = outbase + ".asm"
                    output = ""

                    # German strings
                    output += ".ifdef LANG_GER\n"
                    for label in strings["GER"]:
                        output += ".global {0}\n\n{0}:\n\t.string \"{1}\"\n\n\n".format(
                            label, strings["GER"][label]
                        )

                    # English strings
                    output += ".elseif LANG_EN\n"
                    for label in strings["EN"]:
                        output += "\t.global {0}\n\n\t{0}:\n\t\t.string \"{1}\"\n\n".format(
                            label, strings["EN"][label]
                        )

                    output += ".endif\n"

                    print("Creating file {0}...".format(outfile))
                    with open(outfile, "w+") as f:
                        f.write(output)

                
                # Parse .array directives
                if len(arrays["GER"]) or len(arrays["EN"]):
                    outfile = outbase + ".c"
                    output = ""

                    # German strings
                    output += "#include \"types.h\"\n#include \"pstring.h\"\n"
                    for label in arrays["GER"]:
                        members_ger, size = arrays["GER"][label]
                        members_en, _ = arrays["EN"][label]
                        
                        output += "u8 {0}[{1}][] = ".format(label, size)
                        output += "{\n"
                        for member_ger, member_en in zip(members_ger, members_en):
                            output += "\tLANGDEP(PSTRING(\"{0}\"), PSTRING(\"{1}\")),\n".format(
                                member_ger, member_en
                            )

                    output += "};"
                    print("Creating file {0}...".format(outfile))
                    with open(outfile, "w+") as f:
                        f.write(output)