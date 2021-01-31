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
pgrm : loop ';' {
                printf("Completed \n");
                exit(0); 
                }

loop : FOR '(' EXPR ';' EXPR ';' EXPR ')' '{' EXPR '}'  {printf("OUTER ");}
    | FOR '(' EXPR ';' EXPR ';' EXPR ')' '{' loop '}'   {printf("NESTED ");}
    ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex() {
    char *in = (char *) calloc(50,sizeof(char)) ;
    scanf("%s",in) ;
    // printf("Scanned %s\n",in) ;
    if(atoi(in)) {
        yylval = atoi(in) ;
        return NUM ;
    }
    else if(!strcmp(in,"for")) {
        // printf("For ") ;
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
    else if(*in != '(' && *in!=')' && *in!=';' && *in!='{' && *in!='}'){
        // printf("Expr ") ;
        return EXPR ;
    }
    else {
        // printf("[%c] \n",*in) ;
        return *in ;
    }
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