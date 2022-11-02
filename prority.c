#include<stdio.h>
#define N 20
int Q[N],Pr[N];
int r=-1,f=-1;
void enqueue(int data,int p)
{
int i;
if((f==0)&(r==N-1))
printf("queue id full");
else
{
if(f==-1)
{
f=r=0;
Q[r]=data;
Pr[r]=p;
}
else if(r==N-1)
{
for(i=f;i<=r;i++)
{
Q[i-f]=Q[i];
Pr[i-f]=Pr[i];
r=r-f;
f=0;
for(i=r;i>f;i--)
{
if(p>Pr[i])
{
Q[i+1]=Q[i];
Pr[+1]=Pr[i];
}
else
break;
Q[i+1]=data;
Pr[i+1]=p;
r++;
}
}
}
else
{
for(i=r;i>=f;i--)
{
if(p>Pr[i])
{
Q[i+1]=Q[i];
Pr[i+1]=Pr[i];
}
else
break;
}
Q[i+1]=data;
Pr[i+1]=p;
r++;
}
}
}
void print()
{
int i;
for(i=f;i<=r;i++)
{
printf("\nElement=%d\t Priority=%d",Q[i],Pr[i]);
}
}
int dequeue()
{
if(f==-1)
{
printf("queue is empty");
}
else
{
printf("deleted element=%d\t its priority=%d",Q[f],Pr[f]);
if(f==r)
f=r=-1;
else
f++;
}
}
int main()
{
int opt,n,i,data,p;
printf("Enter ypur choice:");
do{
printf("\n\n1 for insert the data in queue\n2 for show the data in queue\n3 for delete the data from the queue\n0 for exit:");
scanf("%d",&opt);
switch(opt){
case 1:
printf("\n Enter the number of data:");
scanf("%d",&n);
printf("\n Enter your data and priority of data:");
i=0;
while(i<n){
scanf("%d%d",&data,&p);
enqueue(data,p);
i++;
}
break;
case 2:
print();
break;
case 3:
dequeue();
break;
case 0:
break;
default:
printf("\n incorrect choice");
}
}
while(opt!=0);
return 0;
}



