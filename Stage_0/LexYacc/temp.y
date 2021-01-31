
%{
#include<stdio.h>
#include<stdlib.h>

void print_operator(char op);
void Exit(void);
int pos=0;
%}

%token DIGIT
%left '+'
%left '*'

%%

start : expr '\n'		{Exit();}
      ;

expr: expr '+' expr     {print_operator('+');}
    | expr '*' expr     {print_operator('*');}
    | '(' expr ')'
    | DIGIT             {printf("NUM%d ",pos);}
    ;

%%

void print_operator(char c){
    switch(c){
        case '+'  : printf("PLUS ");
                    break;
        case '*'  : printf("MUL ");
                    break;
    }
    return;
}

void Exit(void) {
    printf("\n") ;
    exit(0) ;
}

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

main()
{
	yyparse();
	return 1;
}