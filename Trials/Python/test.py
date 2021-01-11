from sly import Lexer

class SLexer(Lexer) :
    tokens = {
        LETTERS,
        NUMS,
        OP,
        OPEN,
        CLOSE,
        SPACE,
    }

    LETTERS = r'[a-zA-Z]+'
    NUMS = r'[0-9]+'
    OP = r'[+|-|*|/|%|=]'
    
    OPEN = r'[(]'
    CLOSE = r'[)]'

    ignore = ' \t'

if __name__ == '__main__':
    lexer = SLexer()
    while True :
        x = input()
        for tok in lexer.tokenize(x) :
            if x == 'exit' :
                exit()
            print('type=%r, value=%r' % (tok.type, tok.value))