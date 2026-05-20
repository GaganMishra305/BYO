#!/usr/bin/env python3
import sys

def cut(filename, fields, deli):
    with open(filename) as f:
        for line in f:
            parts = line.rstrip('\n').split(deli)
            selected_parts = []
            for field in fields:
                idx = field - 1
                if idx < len(parts):
                    selected_parts.append(parts[idx])
            print(deli.join(selected_parts))

if __name__ == '__main__':
    fields = [1]
    files = []
    deli = "\t"
    for arg in sys.argv[1:]:
        if arg.startswith('-f'):
            fields_str = arg[2:]
            fields = [int(f) for f in fields_str.split(',')]
        elif arg.startswith("-d"):
            deli = arg[2:]
        else:
            files.append(arg)
    
    for f in files:
        cut(f, fields, deli)
