#include <stdio.h>

void main(int argc,char **argv) 
{
    FILE *target_file = fopen(argv[1],"w") ;
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(target_file, "BRKP\n");
    fprintf(target_file, "MOV R0, 3\n");
    fprintf(target_file, "MOV R1, 2\n");
    fprintf(target_file, "ADD R0, R1\n");
}