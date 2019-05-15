#include<stdio.h>
#include<stdlib.h>
void FIFO(){
char s[200];
char F[200];
int l,f,j=0,i,k,flag=0,cnt=0;
printf("enter the no of frames");
scanf("%d",&f);
printf("enter the length of string");
scanf("%d",&l);
printf("enter the sting");
scanf("%s",s);
for(i=0;i<f;i++)
F[i]=' ';
printf("\n\tPAGE\t\tFRAMES\t\t\tFAULTS");
for(i=0;i<l;i++){
for(k=0;k<f;k++)
if(F[k]==s[i])
flag=1;
if(flag==0)
{
printf("\n\t%c\t",s[i]);
F[j]=s[i];
j++;
for(k=0;k<f;k++)
printf("\t%c",F[k]);
printf("\tpage_fault %d",cnt);
cnt++;
}
else{
flag=0;
printf("\n\t%c\t",s[i]);
for(k=0;k<f;k++)
printf("\t%c",F[k]);
printf("\tno page_fault");
}
if(j==f)
j=0;
}
}
int findLRU(int time[],int n){
int i,minimum=time[0],pos=0;
for(i=0;i<n;i++)
{
if(time[i]<minimum){
minimum=time[i];
pos=i;
}
}
return pos;
}
int lru(){
int no_of_frames,no_of_pages,frames[10],counter=0;
int time[10],flag1,flag2,i,j,pos,page;int faults=0;
char s[200];
printf("\n enter no of frames");
scanf("%d",&no_of_frames);
printf("\nenter no of pages:");
scanf("%d",&no_of_pages);
printf("\n enter reference string");
scanf("%s",s);
for(i=0;i<no_of_frames;++i)
frames[i]=-1;
for(i=0;i<no_of_pages;++i){
flag1=flag2=0;
page=s[i]-'0';
for(j=0;j<no_of_frames;++j)
{
if(frames[j]==page){
counter++;
time[j]=counter;
flag1=flag2=1;
break;
}
}
if(flag1==0){
for(j=0;j<no_of_frames;++j){
if(frames[j]==-1){
counter++;
faults++;
frames[j]=page;
time[j]=counter;
flag2=1;
break;
}
}
}
if(flag2==0){
pos=findLRU(time,no_of_frames);
counter++;
faults++;
frames[pos]=page;
time[pos]=counter;
}
printf("\n");
for(j=0;j<no_of_frames;++j)
printf("%d\t",frames[j]);
}
printf("\n\ntotal page fault = %d",faults);
return (0);
}
int main(){
int ch,yn=1,i,l,f;
char F[10],s[25];
do{
printf("\noptions:");
printf("\n\n1:FIFO\n2:LRU\n3:EXIT");
printf("\nenter your choice");
scanf("%d",&ch);
switch(ch){
case 1:FIFO();break;
case 2:lru();break;
default: exit(0);
}
printf("\n\n press 1to continue, 0 to exit");
scanf("%d",&yn);
}while(yn==1);
return(0);
}
