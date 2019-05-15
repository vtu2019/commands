#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char STACK[20]="\0";
int TOP=-1,flag=0;
int B_ptr=0;
char BUFFER[20],G_prod[20];
char table[3][3][10]={"NT","a","b",
                      "A","aBa","Error",
                      "B","I#","bB"};
char pop()
{
 char ch;
 ch=STACK[TOP--];
 return ch;
}
void push(char ch)
{
 STACK[++TOP]=ch;
}
void stack_content()
{
 if(TOP!=-1)
 {
  int i=0;
  printf("\nStack content:");
  while(i<=TOP)
  {
   printf("%c",STACK[i++]);
  }
  printf("\n");
 }
 return;
}
int isterm(char c)
{
 if(c>='a' && c<='z')
  return 1;
 else
  return 0;
}
int Parser_table(char stack_top,char buf_value,int flag)
{
 int r,c;
 switch(stack_top)
 {
  case 'A':r=1;break;
  case 'B':if(flag<=5)r=2;
  else r=3;
 }
 switch(buf_value)
 {
  case 'a':c=1;break;
  case 'b':c=2;
 }
 if(strcmp(table[r][r],"error")==0)
  return 0;
 if(strcmp(table[r][c],"I#")!=0)
 {
  strcpy(G_prod,table[r][c]);
 }
 return 1;
}
int main()
{
 int i,j,stln;
 printf("LL(1) PARSER TABLE\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%s\t",table[i][j]);
  }
  printf("\n");
 }
 printf("\n");
 printf("Enter the string into the buffer and also give a ';' as the terminator;");
 scanf("%s",BUFFER);
 printf("\nThe string in the Buffer is %s",BUFFER);
 if(BUFFER[strlen(BUFFER)-1]!=';')
 {
  printf("End of string Marker should be ';'");
  exit(0);
 }
 push('$');
 push('A');
 while(STACK[TOP]!='$')
 {
  flag++;
  if(STACK[TOP]==BUFFER[B_ptr])
  {
   printf("\n 1.The poped item is -%c,",pop());
   B_ptr++;
   printf("\t buffer cont -%.*s",strlen(BUFFER),BUFFER+B_ptr);
  }
  else if(isterm(STACK[TOP]))
  {
   printf("\n 2.$%c",STACK[TOP]);
   printf("\tError in parsing\n");
  }
  else
  if(!Parser_table(STACK[TOP],BUFFER[B_ptr],flag))
   printf("3.Error Entry in Parse table");
  else
  if(Parser_table(STACK[TOP],BUFFER[B_ptr],flag))
  {
   if(flag<6 && strcmp (G_prod,"I#")!=0)
   {
    printf("\n 4.1 flag=%d,prod id-%s*\t",flag,G_prod);
    pop();
    stln=strlen(G_prod);
    for(i=stln-1;i>=0;i--)
     push(G_prod[i]);
     stack_content();
   }
   else
   {
    stack_content();
    printf("\n 4.2 flag=%d * reduce by %s*",flag,"B->I#");
    pop();
    printf("\t buffer content is %c",BUFFER[B_ptr]);
   }
  }
 }
 if(STACK[TOP]=='$' && BUFFER[B_ptr]==';')
  printf("\n ** The string is accepted **");
 else
  printf("\n ** The string is not accepted **");
}
