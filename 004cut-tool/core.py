#!/usr/bin/env python3
import sys

def process_stream(stream, fields, deli):
    for line in stream:
        parts = line.rstrip('\n').split(deli)
        selected_parts = []
        for field in fields:
            idx = field - 1
            if idx < len(parts):
                selected_parts.append(parts[idx])
        print(deli.join(selected_parts))

def cut(filename, fields, deli):
    with open(filename) as f:
        process_stream(f, fields, deli)

if __name__ == '__main__':
    fields = [1]
    files = []
    deli = "\t"
    for arg in sys.argv[1:]:
        if arg.startswith('-f'):
            fields_str = arg[2:]
            if fields_str.count(","):
                fields = [int(f) for f in fields_str.split(',')]
            elif fields_str.count(" "):
                fields = [int(f) for f in fields_str.split(' ')]
        elif arg.startswith("-d"):
            deli = arg[2:]
        else:
            files.append(arg)
    
    if not files or files == ['-']:
        process_stream(sys.stdin, fields, deli)
    else:
        for f in files:
            if f == "-":
                process_stream(sys.stdin, fields, deli)
            else:
                cut(f, fields, deli)
