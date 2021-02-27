from ply import yacc
from ply import lex
import sys

tokens = [
    'ID' ,
    'OP' , 
    'EQ' ,
    'OP2' ,
    'NUM' ,
    'END' ,
    'READ' ,
    'SEMI' ,
    'WRITE' ,
    'BEGIN' ,
    'LPAREN' , 
    'RPAREN' ,
    'NEWLINE' ,
    'ENDLINE' ,
]

# literals = [';']

class Node :
    def __init__(self,token) :
        self.token = token
        self.res = None
        self.value = None
        self.left = None 
        self.right = None 
    
    def __repr__(self) :
        return f'{self.token} : {self.value}'

t_ignore = ' \t\n'

def t_SEMI(t) :
    r';'
    return t

def t_END(t):
    r'end'
    return t

def t_BEGIN(t):
    r'begin'
    return t

def t_READ(t):
    r'read'
    return t

def t_WRITE(t):
    r'write'
    return t

def t_ID(t):
    r'[a-z]'
    return t

def t_OP(t):
    r'[+|-]'
    return t

def t_EQ(t):
    r'='
    return t

def t_NUM(t): 
    r'[0-9]+'
    return t

def t_OP2(t):
    r'[*|/|%]'
    return t

def t_LPAREN(t): 
    r'\('
    return t

def t_RPAREN(t): 
    r'\)'
    return t

def t_NEWLINE(t): 
    r'\n+'
    t.lexer.lineno += len(t.value)
    return t

def t_ENDLINE(t): 
    r'\0'
    return t

def t_error(t) :
    print("Invalid Token",t.value[0])
    t.lexer.skip(1)

lexer = lex.lex()

precedence = (
    ('left','OP') ,
    ('left','OP2') ,
)

def p_prg(p) :
    '''pgm  : BEGIN Slist END SEMI
            | BEGIN END SEMI '''
    p[0] = p[2]
    print('Complete')

def p_Slist(p) :
    '''Slist : Slist Stmt
            | Stmt NEWLINE
            | Stmt '''
    if len(p) == 2 :
        p[0] = p[1]
    else :
        t = Node('Slist')
        t.left = p[1]
        t.right = p[2]
        p[0] = t
    # print(p)

def p_stmt(p) :
    '''Stmt : Input
            | Output
            | Asgmt '''
    p[0] = p[1] 
    print(p[0])
    # print(p)

def p_input(p) :
    '''Input : READ LPAREN ID RPAREN SEMI'''
    t = Node('READ') 
    t.value = p[3]
    p[0] = t
    # print("Input")

def p_output(p) :
    '''Output : WRITE LPAREN E RPAREN SEMI'''
    t = Node('WRITE')
    t.value = p[3]
    p[0] = t
    # print(p)

def p_asgmt(p) :
    '''Asgmt : ID EQ E SEMI'''
    t = Node('EQ')

    id = Node('ID')
    id.value = p[1]

    t.left = id 
    t.value = p[2]
    t.right = p[3]

    p[0] = t

def p_E(p) :
    '''E    : E OP2 E 
            | E OP E 
            | ID '''
    if len(p) == 2 :
        t = Node('ID')
        t.value = p[1]
        p[0] = t
        print(p[0])
    if len(p) == 4 :
        if p[2] in ['*','/','%'] :
            t = Node('OP2')
        elif p[2] in ['+','-'] :
            t = Node('OP')
        t.value = p[2]
        t.left = p[1]
        t.right = p[3]
        p[0] = t
        if p[2] == '%' :
            # p[0] = p[1] % p[3]
            print("MOD")
        elif p[2] == '/' :
            # p[0] = p[1] / p[3]
            print("DIV")
        elif p[2] == '*' :
            # p[0] = p[1] * p[3]
            print("MUL") 
        elif p[2] == '+' :
            # p[0] = p[1] + p[3]
            print("ADD")
        elif p[2] == '-' :
            # p[0] = p[1] - p[3]
            print("SUB")
        
        print(p[0])

def p_error(p) :
    print("Syntax Error",p)

parser = yacc.yacc()

res = parser.parse('''begin
read (a);
read (b);
d = a + c * b;
write (a+d);
end;''')
print(res)

def paren(Tree) :
    if (Tree == None) :
        # print("()",end="")
        return
    print(f'( {Tree} ',end="")
    paren(Tree.left)
    paren(Tree.right)
    print(')',end="")

paren(res)
print('')

try :
    outFile = open(sys.argv[1],"w")
except :
    outFile = sys.stdout

memMap = {}

for i in range(26) :
    memMap[chr(ord('a')+i)] = 4096 + i

def CodeGen(Tree) :
    if Tree.token == 'Slist' :
        CodeGen(Tree.left)
        CodeGen(Tree.right)
        return None
    elif Tree.token == 'READ' :
        outFile.write("MOV R0,7\n")
        outFile.write("PUSH R0\n")
        outFile.write("MOV R0,-2\n")
        outFile.write("PUSH R0\n")
        outFile.write(f"MOV R0,{memMap[Tree.value]}\n")
        outFile.write("PUSH R0\n")
        outFile.write("PUSH R0\n")
        outFile.write("PUSH R0\n")
        outFile.write("INT 6\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        return None
    elif Tree.token == 'WRITE' :
        Tree.res = CodeGen(Tree.value)
        outFile.write("MOV R0,5\n")
        outFile.write("PUSH R0\n")
        outFile.write("MOV R0,-1\n")
        outFile.write("PUSH R0\n")
        outFile.write(f"MOV R0,R{Tree.res}\n")
        outFile.write("PUSH R0\n")
        outFile.write("PUSH R0\n")
        outFile.write("PUSH R0\n")
        outFile.write("INT 7\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        outFile.write("POP R0\n")
        return None
    elif Tree.token in ['OP','OP2'] :
        Tree.res = 0
        return 0


def startCodeGen(Tree) :
    for i in ["0","2056","0","0","0","0","0","0","MOV SP,4121"] :
        outFile.write(i+'\n')
    CodeGen(Tree)
    outFile.close()

startCodeGen(res)