#include<stdio.h>
#define N 20
int Q[N],pr[N];
int r=-1,f=-1;
void enqueue(int data,int p)
{
int i;
if((f==0)&&(r==N-1))
printf("queue is full");
else{
if(f==-1)
{
f=r=0;
Q[r]=data;
pr[r]=p;
}
else if(r==N-1)
{
for(i=f;i<=r;i++)
{
Q[i-f]=Q[i];
pr[i-f]=pr[i];
r=r-f;
f=0;
for(i=r;i>f;i--)
{
if(p>pr[i])
{
Q[i+1]=Q[i];
pr[i+1]=pr[i];
}
else
break;
Q[i+1]=data;
pr[i+1]=p;
r++;
}
}
}
else
{
for(i=r;i>=f;i--)
{
if(p>pr[i])
{
Q[i+1]=Q[i];
pr[i+1]=pr[i];
}
else
break;
}
Q[i+1]=data;
pr[i+1]=p;
r++;
}
}
}
void print()
{
int i;
for(i=f;i<=r;i++);
{
printf("\n element = %d\t priority=%d",Q[i],pr[i]);
}
}
int dequeue()
{if(f==-1)
{
printf("queue is empty");
}
else
{printf("deleted elemnt =%d/t its priority=%d",Q[f],pr[f]);
if(f==r)
f=r=-1;
else
f++;
}
}
int main()
{ int opt,n,i,data,p;
printf("enter your choise");
do
{
printf("\n\n1 for insert the data in queue\n2 for show the data in queue \n3 for delet the data from the queue\n0 for exit ");
scanf("%d",&opt);
switch(opt)
{
case 1: 
printf("\nenter the number of data");
scanf("%d",&n);
printf("\n enter your data and priority of data");
i=0;
while(i<n)
{
scanf("%d%d",&data,&p);
enqueue(data,p);
i++;
}break;
case 2:
print();
break;
case 3:
dequeue();
break;
case 0:
break;
default:
printf("\n incorrect choise");
}
}
while(opt!=0);
return 0;
}
