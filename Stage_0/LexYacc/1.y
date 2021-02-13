%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token CHAR NEWLINE
%left '-' '+'
%left '*' '/' '%'

%%

start: expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr: expr '+' expr         {printf("+");}
  | expr '-' expr           {printf("-");}
  | expr '*' expr           {printf("*");}
  | expr '/' expr           {printf("/");}
  | expr '%' expr           {printf("%");}
  | '(' expr ')'
  | CHAR                   {printf("%c",$1);}
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