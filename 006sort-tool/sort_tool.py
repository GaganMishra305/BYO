import sys
import re

def sort_file(filename):
    """Reads lines from a file, sorts them, and prints unique lines."""
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
        
        # Filter out empty lines, strip whitespace, and keep only words starting with a letter
        words = [line.strip().upper() for line in lines if line.strip() and re.match(r'^[a-zA-Z]', line)]
        
        # Sort and get unique words
        unique_words = sorted(list(set(words)))

        for word in unique_words:
            try:
                print(word)
            except BrokenPipeError:
                # This happens when the reading end of the pipe is closed, e.g., by `head`.
                # We can safely exit.
                sys.exit(0)

    except FileNotFoundError:
        print(f"sort: cannot read: {filename}: No such file or directory", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python sort_tool.py <file>", file=sys.stderr)
        sys.exit(1)
    
    filename = sys.argv[1]
    sort_file(filename)
