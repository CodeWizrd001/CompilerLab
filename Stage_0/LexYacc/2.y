%{
    #include <stdio.h>
    #include <stdlib.h>
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
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr: expr '+' expr         {printf("+ ");}
  | expr '-' expr           {printf("- ");}
  | expr '*' expr           {printf("* ");}
  | expr '/' expr           {printf("/ ");}
  | expr '%' expr           {printf("%% ");}
  | '(' expr ')'
  | WORD                   {printf("%s ",$1);}
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