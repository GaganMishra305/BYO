#!/usr/bin/env python3
import sys

def cut(filename, field):
    with open(filename) as f:
        for line in f:
            parts = line.rstrip('\n').split('\t')
            idx = field - 1
            print(parts[idx] if idx < len(parts) else '')

if __name__ == '__main__':
    # parse -f2 style arg
    field = 1
    files = []
    for arg in sys.argv[1:]:
        if arg.startswith('-f'):
            field = int(arg[2:])
        else:
            files.append(arg)
    
    for f in files:
        cut(f, field)
