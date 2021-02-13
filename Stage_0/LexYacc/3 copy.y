%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
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
        printf("Plus") ;
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,strcat("+ ",strcat($<word>1,$<word>3))) ;
        printf("APlus") ;
        }
  | expr '-' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,strcat("+ ",strcat($<word>1,$<word>3))) ;
        }
  | expr '*' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,strcat("+ ",strcat($<word>1,$<word>3))) ;
        }
  | expr '/' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,strcat("+ ",strcat($<word>1,$<word>3))) ;
        }
  | expr '%' expr           {
        $<word>$ = calloc(strlen($<word>1)+strlen($<word>3)+1 , sizeof(char)) ;
        strcpy($<word>$,strcat("+ ",strcat($<word>1,$<word>3))) ;
        }
  | '(' expr ')'            
  | WORD                    {
        printf("Here") ;
        $<word>$ = calloc(strlen($1)+1 , sizeof(char)) ;
        strcpy($<word>$,$1);
        printf("Also") ;
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