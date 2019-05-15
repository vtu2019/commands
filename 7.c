#include<stdio.h>
#include<stdlib.h>
int burst[10],rem[10],wait[10],finish[10],turnaround[10],flag[10],arrival[10];
void roundrobin(int,int,int[],int[]);
void srtf(int);
int main()
{
int tq,n,choice;
int bt[10],st[10],i,j;
for (;;)
{
printf("enter the choice\n 1.round robin\n2.srtf\n3.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter no of process:\n");
scanf("%d",&n);
printf("enter brust time\n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
st[i]=bt[i];
}
printf("enter time quantum");
scanf("%d",&tq);
roundrobin(n,tq,st,bt);
break;
case 2:printf("enter no of process:\n");
scanf("%d",&n);
srtf(n);
break;
case 3:return 0;
}
}
}	
void roundrobin(int n,int tq,int st[],int bt[])
{
int time=0;
int tat[10],wt[10],i,count=0,swt=0,stat=0,temp1,sq=0;
while(1)
{
for(i=0,count=0;i<n;i++)
{
temp1=tq;
if(st[i]==0)
{
count++;
continue;
}
if(st[i]>tq)
st[i]=st[i]-tq;
else
if(st[i]>=0)
{
temp1=st[i];
st[i]=0;
}
sq=sq+temp1;
tat[i]=sq;
}
if(n==count)
break;
}
for(i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
swt=swt+wt[i];
stat=stat+tat[i];
}
printf("process_no burst time wait time turnaround time\n");
for(i=0;i<n;i++)
printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
printf("average waiting time is %f\n average turnaround time s %F\n",(float)swt/n,(float)stat/n);
}
void srtf(int n)
{
int stat=0,swt=0,time=0,count=0,i,j,min=999;
for(i=1;i<=n;i++)
{
printf("arrival of p%d:",i);
scanf("%d",&arrival[i]);
printf("burst of p%d:",i);
scanf("%d",&burst[i]);
rem[i]=burst[i];
flag[i]=0;
}
while(1)
{
for(i=1,min=999;i<=n;i++)
if(arrival[i]<=time && flag[i]==0)
if(rem[i]<min)
{
min=rem[i];
j=i;
}
time++;
rem[j]-=1;
if(rem[j]==0)
{
finish[j]=time;
flag[j]=1;
count++;
}
if(count==n)
break;
}
for(i=1;i<=n;i++)
{
turnaround[i]=finish[i]-arrival[i];
wait[i]=turnaround[i]-burst[i];
stat+=turnaround[i];
swt+=wait[i];
}
printf("the process table :\n\tprocess no.\t|finish\t|wait\t|turnaround\t\n");
for(i=1;i<=n;i++)
printf("\t%d\t%d\t%d\t%d\t%d\t%d\n",i,arrival[i],burst[i],finish[i],wait[i],turnaround[i]);
printf("averagewaittime:%f\t avgturnaroundtime:%f\n",(float)swt/n,(float)stat/n);
return;
}
