%{
#include<stdio.h>
#include<stdlib.h>
int id=0,dig=0,key=0,op=0;
%}
%token DIGIT ID KEY OP
%%
input:
DIGIT input {dig++;}
|ID input {id++;}
|KEY input {key++;}
|OP input {op++;}
|DIGIT {dig++;}
|ID {id++;}
|KEY {key++;}
|OP {op++;}
;
%%
#include<stdio.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
main()
{
FILE *myfile=fopen("input.c","r");
if(!myfile){printf("I can't open input.c!");
return -1;
}
yyin=myfile;
do{
yyparse();
}while(!feof(yyin));
printf("Numbers = %d\nKeywords = %d\nIdentifiers = %d\nOperators=%d\n",dig,key,id,op);
}
void yyerror(){
printf("EEK,parse error! Message:");
exit(-1);
}
int yywrap(void)
{
return 1;
}
