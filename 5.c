#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char tset[4][3][3]={{"-","B","?"},{"+","C","D"},{"*","0","1"},{"=","A","2"}};
int main()
{
int r,c;
for(r=0;r<4;r++)
{
c=2;
if(tset[r][c][0]=='?')
{
printf("\n LD R0, %s%s",tset[r][0],tset[r][1]);
}
else
{
if(tset[r][0][0]=='+')
{
printf("\nLD R1, %s",tset[r][1]);
printf("\nLD R2, %s",tset[r][2]);
printf("\nADD R1,R1,R2");
}
else
{
if(tset[r][0][0]=='*')
{
printf("\nMUL R1,R1,R0");
}
else
printf("\n ST %s,R1",tset[r][1]);
}
}
}
printf("\n");
return 0;
}
