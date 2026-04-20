import sys

class Lexer:
    pass

class Parser:
    def parse(content):
        if content[0] == "{" and content[-1] == "}" :
            return 0
        return 1



def main(args = None):
    # file opener
    if args is None:
        args = sys.argv[1:]
    file = args[0]
    with open(file, 'r') as file:
        content = file.read()
    
    return Parser.parse(content)

main()
