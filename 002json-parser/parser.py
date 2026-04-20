import sys

# state machine over character
class Lexer:
    pass

# state machine over tokens = Parser
class ParserState:
    START = 0
    KEY   = 1
    VALUE = 2
    EXIT  = 3

class Parser:
    def __init__(self, content):
        self.idx          = 0
        self.current      = ParserState.START
        self.content      = content
        self.after_comma  = False

    def parse(self):
        while self.current != ParserState.EXIT:
            ch = self.get_next()
            match self.current:
                case ParserState.START:
                    if ch == "{":
                        self.current = ParserState.KEY
                    else:
                        sys.exit(1)

                case ParserState.KEY:
                    if ch == "\"":
                        key = self.get_key()
                        self.current = ParserState.VALUE
                    elif ch == "}" and not self.after_comma:
                        sys.exit(0)
                    else:
                        sys.exit(1)

                case ParserState.VALUE:
                    if ch == ":":
                        value = self.get_value()
                        ch = self.get_next()
                        if ch == ",":
                            self.after_comma = True
                            self.current = ParserState.KEY
                        elif ch == "}":
                            sys.exit(0)
                        else:
                            sys.exit(1)
                    else:
                        sys.exit(1)

    def get_next(self):
        ch = self.content[self.idx]
        self.idx += 1
        while ch in (" ", "\n", "\t"):
            if self.idx >= len(self.content):
                sys.exit(1)
            ch = self.content[self.idx]
            self.idx += 1
        return ch

    def get_key(self):
        key = ""
        ch = self.get_next()
        while ch != "\"":
            key += ch
            ch = self.get_next()
        return key

    def get_value(self):
        value = ""
        ch = self.get_next()
        if ch != "\"":
            sys.exit(1)
        ch = self.get_next()
        while ch != "\"":
            value += ch
            ch = self.get_next()
        return value


# file opening and passing logic
file = sys.argv[1]
with open(file, 'r') as file:
    content = file.read()

# opening parser
p = Parser(content)
p.parse()