%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
	FILE* target_file;
	reg_index sum;
%}

%union{
	struct tnode *no;
	
}
%type <no> expr NUM program ID SList InputStmt OutputStmt AsgStmt Stmt
%token BEGIN0 END0 READ WRITE NUM PLUS MINUS MUL DIV ID ASSIGN STMTEND
%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN0 SList END0	{
				$$ = $2;
				printf("Writing %d\n", $2->type);
				sum = codegen(target_file, $$);
				exitcode(target_file);
				fclose(target_file);
				exit(1);
		}
		| BEGIN0 END0 {
				$$ = NULL;
				printf("WritingWithNULL\n");
				fclose(target_file);
				exitcode(target_file);
				exit(1);
		}
		;
SList	: SList Stmt {$$ = createTree(0,connectortype,NULL,$1,$2);
						printf("slist %d\n",$$->type);						
						}
		| Stmt {$$ = $1;}
		;
Stmt	: InputStmt 	{$$ = $1;}
		| OutputStmt 	{$$ = $1;}
		| AsgStmt 		{$$ = $1;}
		;
InputStmt : READ '(' ID ')' STMTEND {$$ = createTree(0,readtype,NULL,$3,NULL);}
		;
OutputStmt : WRITE '(' expr ')' STMTEND {$$ = createTree(0,writetype,NULL,$3,NULL);}
			;
AsgStmt : ID ASSIGN expr STMTEND {$$ = createTree(0,assigntype,"=",$1,$3);}
		;
expr : expr PLUS expr		{$$ = createTree(0,addtype,"+",$1,$3);}
	 | expr MINUS expr  	{$$ = createTree(0,subtype,"-",$1,$3);}
	 | expr MUL expr	{$$ = createTree(0,multype,"*",$1,$3);}
	 | expr DIV expr	{$$ = createTree(0,divtype,"/",$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM				{$$ = $1;}
	 | ID				{$$ = $1;printf("HIII\n");}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main(void) {
	target_file = fopen("expressiontree1.xsm","w");
	//printf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
	headerxexe(target_file);
	yyparse();
	
	return 0;
}
