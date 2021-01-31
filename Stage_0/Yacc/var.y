%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos=0;
%}

%token ALPHA DIGIT
%left '+'
%left '*'

%%
pgrm : var ';' {
                printf("Completed \n");
                exit(0); 
                }

var : ALPHA     {printf("Start ");}
    | var ALPHA {printf("MidAl ");}
    | var DIGIT {printf("MidDig ");}
    ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex() {
    // char *in = (char *) calloc(50,sizeof(char)) ;
    // scanf("%s",in) ;
    char c = getchar() ;
    printf("[%c] ",c) ;
    if(isalpha(c)) {
        // printf("Alpha ") ;
        return ALPHA ;
    }
    else if(c=='_') {
        return ALPHA ;
    }
    else if(isalnum(c)) {
        // printf("Alnum ") ;
        return DIGIT ;
    }
    else if(c == ' ') {
        return yylex() ;
    }
    else {
        return c ;
    }
}

main()
{
	yyparse();
	return 1;
}