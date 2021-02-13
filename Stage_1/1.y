%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    typedef struct tnode{
          int val;  char *op; //indicates the name of the operator for a non leaf node
          struct tnode *left,*right; //left and right branches
      } tnode;
      #define YYSTYPE tnode*
%}

%union {
  char *word ;
  char op ;
}

%token <word> WORD 
%token <op> NEWLINE

%left '-' '+'
%left '*' '/' '%'

%%

start: expr NEWLINE  {
                        printf("\n%s\nComplete\n",$<word>1);
                        exit(1);
                      }
  ;

expr: expr '+' expr         {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,"+ ") ;
        strcat($<word>$,$<word>1) ;
        strcat($<word>$,$<word>3) ;
        }
  | expr '-' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,"- ") ;
        strcat($<word>$,$<word>1) ;
        strcat($<word>$,$<word>3) ;
        }
  | expr '*' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,"* ") ;
        strcat($<word>$,$<word>1) ;
        strcat($<word>$,$<word>3) ;
        }
  | expr '/' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,"/ ") ;
        strcat($<word>$,$<word>1) ;
        strcat($<word>$,$<word>3) ;
        }
  | expr '%' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,"% ") ;
        strcat($<word>$,$<word>1) ;
        strcat($<word>$,$<word>3) ;
        }
  | '(' expr ')'            
  | WORD                    {
        $<word>$ = calloc(strlen($1)+1 , sizeof(char)) ;
        strcpy($<word>$,$1);
        strcat($<word>$," ") ;
        }
  ;

%%

void yyerror(char const *s)
{
    printf("Error\n");
    return ;
}
int main()
{
  yyparse();
  return 1;
}