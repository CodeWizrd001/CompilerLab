%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"

	int number;

%}

%%

[0-9]+	{number = atoi(yytext); yylval.no = createTree(number,numtype,NULL,NULL,NULL); return NUM;}
[a-z] {yylval.no = createTree(0,idtype,yytext,NULL,NULL); return ID;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"<"	{return DIV;}
"=" {return ASSIGN;}
"begin" {return BEGIN0;}
"end" {return END0;}
"read" {return READ;}
"write"  {return WRITE;}
";" {return STMTEND;}
[()] {return *yytext;}
[ \t]	{}
[\n]	{}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
