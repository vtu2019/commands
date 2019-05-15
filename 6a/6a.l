%{
	#include<stdio.h>
	int c_count=0;
%}
%%
"/*"[n*/]*"*/" {c_count++;}
"//".* {c_count++;}
%%
int main (int argc,char **argv)
{
	FILE *f1,*f2;
	if(argc>1)
	{
		f1=fopen(argv[1],"r");
		if(!f1)
		{
			printf("file error\n");
			exit(1);
		}
		yyin=f1;
		f2=fopen(argv[2],"w");
		if(!f2)
		{
			printf("file error\n");
			exit(1);
		}
		yyout=f2;
		yylex();
		printf("no of comment lies:%d\n",c_count);
	}
	return 0;
}
int yywrap(void)
{
	return 1;
}
	
