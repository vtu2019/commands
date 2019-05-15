%{
	#include<stdio.h>
	int v=0,op=0,id=0,flag=0;
%}
%%
[a-zA-Z]+[0-9A-Za-z]* {id++;printf("\n identifier:");ECHO;}
[|+|-|*|/|=] {op++;printf("\n operator:");ECHO;}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {;}
%%
int main(void)
{
	printf("enter the expression");
	yylex();
	if((op+1)==id && v==0 &&flag==0)
		printf("expression is valid\n");
	else
		printf("expression is invalid\n");
	printf("no of identifiers=%d\n",id);
	printf("no of operators=%d\n",op);
	return 0;
}
int yywrap(void)
{
	return 1;
}
