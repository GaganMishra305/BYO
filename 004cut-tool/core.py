#!/usr/bin/env python3
import sys

def cut(filename, field, deli):
    with open(filename) as f:
        for line in f:
            parts = line.rstrip('\n').split(deli)
            idx = field - 1
            print(parts[idx] if idx < len(parts) else '')

if __name__ == '__main__':
    field = 1
    files = []
    deli = "\t"
    for arg in sys.argv[1:]:
        if arg.startswith('-f'):
            field = int(arg[2:])
        elif arg.startswith("-d"):
            deli = arg[2:]
        else:
            files.append(arg)
    
    for f in files:
        cut(f, field, deli)
