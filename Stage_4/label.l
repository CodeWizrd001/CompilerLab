%{
	#include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
	
    int global_variable;
	FILE *f1 ;
    FILE *f2 ;
    FILE *f3 ;
    int c = 0 ;
    int tr = 0 ;
	int flag = 0 ;
	int words = 0 ;
	int lines = 0 ;
    int label = 0 ;
	int characters = 0 ;

    typedef struct Label {
        char *labelName ;
        int address ;
    } Label ; 

    Label *labelTable = NULL ;

    void addLabel(char *labelName,int lineNo) ;
    int searchLabel(char *labelName) ;

    void translate(void) ;
%}

letters     [a-zA-Z.]+
number      [0-9]+
op          [-|+|*|/|^|=]
openPar     [(]
closePar    [)]
space       [ ]+
eol         [\n|\0
lineChars   [\"a-zA-Z0-9., \[\]\-]+
labelChars  [_a-zA-Z0-9,]+

%%


{labelChars}[:][\n]         {
                                if(!tr)
                                {
                                    label += 1;
                                    // printf("Len :%d\n",strlen(yytext)) ;
                                    yytext[strlen(yytext)-1] = '\0' ;
                                    // printf("Len :%d\n",strlen(yytext)) ;
                                    yytext[strlen(yytext)-1] = '\0' ;
                                    // printf("Len :%d\n",strlen(yytext)) ;
                                    addLabel(yytext,lines) ;
                                    // printf("LABELDEC [%s %d %d]\n",yytext,label,labelTable[label-1].address) ;
                                }
                            }
"JMP "{labelChars}[\n]      { 
                            if(!tr)
                            {
                                lines += 1;
                                printf("JMP [%s]\n",yytext) ;
                            }
                            else 
                            {
                                yytext[strlen(yytext)-1] = '\0' ;
                                // printf("JMP [%s]\n",yytext) ;
                                fprintf(f2,"JMP %d\n",searchLabel(yytext+4)) ;
                            }
                        }
"JZ "{labelChars}[\n]      {
                            if(!tr)
                            {
                                lines += 1;
                                printf("JZ [%s]\n",yytext) ;
                            }
                            else
                            {
                                c = 0 ;
                                char *start = (char*) calloc(1,strlen(yytext)) ;
                                strcpy(start,yytext) ;

                                while(yytext[c]!=',') c += 1 ;
                                yytext += c + 1;
                                start[c] = '\0' ;
                                yytext[strlen(yytext)-1] = '\0' ;
                                
                                // printf("%s,%d\n",start,searchLabel(yytext)) ;
                                fprintf(f2,"%s,%d\n",start,searchLabel(yytext)) ;
                            }
                        }
"JNZ "{labelChars}[\n]  {
                            if(!tr)
                            {
                                lines += 1;
                                printf("JNZ [%s]\n",yytext) ;
                            }
                            else
                            {
                                c = 0 ;
                                char *start = (char*) calloc(1,strlen(yytext)) ;
                                strcpy(start,yytext) ;

                                while(yytext[c]!=',') c += 1 ;
                                yytext += c + 1;
                                start[c] = '\0' ;
                                yytext[strlen(yytext)-1] = '\0' ;

                                // printf("JNZ %d [%s]\n",c,yytext) ;
                                fprintf(f2,"%s,%d\n",start,searchLabel(yytext)) ;
                            }
                        }
"CALL "{labelChars}[\n]      {
                            if(!tr)
                            {
                                lines += 1;
                                printf("CALL [%s]\n",yytext) ;
                            }
                            else 
                            {
                                yytext[strlen(yytext)-1] = '\0' ;
                                fprintf(f2,"CALL %d\n",searchLabel(yytext)) ;
                            }
                        }
{lineChars}[\n] {
                if(!tr)
                {
                    lines += 1 ;
                    // printf("LINE [%s %d] \n",yytext,lines);
                }
                else
                {
                    fprintf(f2,"%s",yytext) ;
                }
            }

.           {
                printf("Other : %s\n",yytext) ;
            }

%%
int yywrap(void)
{
	if(!tr)
    {
        yyin = f3 ;
        tr = 1 ;
        return 0 ;
    }
    else 
        return 1 ;
}

void addLabel(char *labelName,int lineno) 
{
    if(labelTable==NULL)
        labelTable = (Label*) calloc(1,sizeof(Label)) ;
    else 
        labelTable = (Label*) realloc(labelTable,label*sizeof(Label)) ;
    labelTable[label-1].labelName = (char*) calloc(5,sizeof(5)) ;
    strcpy(labelTable[label-1].labelName,labelName) ;
    labelTable[label-1].address = 2048 + lineno*2 - 8;
}

int searchLabel(char *labelName)
{   
    for(int i=0;i<label;i+=1)
    {
        // printf("Search :%s \tMatch :%s \tAddr :%d Label\n",labelName,labelTable[i].labelName,labelTable[i].address) ;
        if(!strcmp(labelTable[i].labelName,labelName))
            return labelTable[i].address ;
    }

    return 100 ;
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		f1 = fopen(argv[1],"r");
        f3 = fopen(argv[1],"r") ;
		if(f1)
			yyin = f1;
	}

    f2 = fopen("Temp.xsm","w") ;
	int num = yylex();
    tr = 1 ;
	printf("Found: %d\n",num);
	printf("Chars : %d \nWords : %d \nLines : %d\n",characters,words,lines) ;
    printf("Here") ;
    num = yylex() ;
    printf("Here\n") ;
    char *outputName = calloc(100,sizeof(char)) ;
    strcat(outputName,"Temp_") ;
    strcat(outputName,argv[1]) ;
    printf("Output : %s\n",outputName) ;
    char *command = calloc(100,sizeof(char)) ;
    strcat(command,"mv Temp.xsm ") ;
    strcat(command,outputName) ;
    printf("Command : %s\n",command) ;
    system(command) ;
	return 0; 
}