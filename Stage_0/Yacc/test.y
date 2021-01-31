%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos=0;
%}

%token DIGIT NUM FOR ELSE THEN ENDFOR EXPR
%left '+'
%left '*'

%%

loop : FOR '(' EXPR ';' EXPR ';' EXPR ')' '{' EXPR '}'  {printf("OUTER ");}
    | FOR '(' EXPR ';' EXPR ';' EXPR ')' '{' EXPR '}'   {printf("NESTED ");}
    ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex() {
    char *in = (char *) calloc(50,sizeof(char)) ;
    scanf("%s",in) ;
    if(atoi(in)) {
        yylval = atoi(in) ;
        return NUM ;
    }
    else if(!strcmp(in,"for")) {
        return FOR ;
    }
    else if(!strcmp(in,"else")) {
        return ELSE ;
    }
    else if(!strcmp(in,"then")) {
        return THEN ;
    }
    else if(!strcmp(in,"endfor"))
        return ENDFOR ;
    else if(*in != '(' || *in!=')' || *in!=';' || *in!='{' || *in!='}')
        return EXPR ;
    else 
        return yylex() ;
}

_yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        pos++;
        return DIGIT;
    }
    else if(c == ' '){
        return yylex();
    }
    else {
        return c;
    }
}

main()
{
	yyparse();
	return 1;
}