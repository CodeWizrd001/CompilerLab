%{
    #include <stdio.h>
    #include <stdlib.h>
	  //#include "y.tab.h"
%}

%token DIGIT NEWLINE
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
  | '(' expr ')'
  | DIGIT                   {printf("%d",yylval);}
  ;

%%

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
  yyparse();
  return 1;
}