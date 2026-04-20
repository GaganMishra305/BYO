import sys

# state machine over character
class Lexer:
    pass

# state machine over tokens
class Parser:
    def parse(self, content):
        if content[0] == "{" and content[-1] == "}" :
            return 0
        return 1

# file opening and passing logic
file = sys.argv[1]
with open(file, 'r') as file:
    content = file.read()

# opening parser
p = Parser()
p.parse(content)
