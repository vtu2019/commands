%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
input: s'\n' {printf("successful grammar\n"); exit(0);}
s: A s1 B|B
s1: ; | A s1
%%
main()
{
printf("enter a string\n");
yyparse();
}
int yyerror()
{
printf("error\n");
exit(0);
}
