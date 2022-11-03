#include<stdio.h>
#include<stdlib.h>
#define Max 20
void printsparse(int b[Max][3]);
void readsparse(int b[Max][3]);
void addsparse(int b1[Max][3],int b2[Max][3],int b3[Max][3]);
void main()
{
int b1[Max][3],b2[Max][3],b3[Max][3];
readsparse(b1);
readsparse(b2);
addsparse(b1,b2,b3);
printsparse(b3);
}
void readsparse(int b[Max][3])
{
int i,t,m,n;
printf("Enter no.of rows and columns:");
scanf("%d%d",&m,&n);
printf("no.of non zero triples:");
scanf("%d",&t);
b[0][0]=m;
b[0][1]=n;
b[0][2]=t;
for(i=1;i<=t;i++)
{
printf("Enter the triples(row,column,value):");
scanf("%d %d %d",&b[i][0],&b[i][1],&b[i][2]);
}
}
void addsparse(int b1[Max][3],int b2[Max][3],int b3[Max][3])
{
int t1,t2,i,j,k;
if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
{
printf("You have entered invalid matrix!!size must be equal");
exit(0);
}
t1=b1[0][2];
t2=b2[0][2];
i=j=k=0;
b3[0][0]=b1[0][0];
b3[0][1]=b1[0][1];
while(i<=t1&&j<=t2)
{
if(b1[i][0]<b2[j][0])
{
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2];
k++;
i++;
}
else if(b2[j][0]<b1[i][0])
{
b3[k][0]=b2[j][0];
b3[k][1]=b2[j][1];
b3[k][2]=b2[j][2];
k++;
j++;
}
else if(b1[i][1]<b1[j][1])
{
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2];
k++;
i++;
}
else if(b2[j][1]<b1[i][1])
{
b3[k][0]=b2[j][0];
b3[k][1]=b2[j][1];
b3[k][2]=b2[j][2];
k++;
j++;
}
else
{
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2]+b2[j][2];
k++;
i++;
j++;
}
}
while(i<=t1)
{
b3[k][0]=b1[i][0];
b3[k][1]=b1[i][1];
b3[k][2]=b1[i][2];
i++;
k++;
}
while(j<=t2)
{
b3[k][0]=b2[j][0];
b3[k][1]=b2[j][1];
b3[k][2]=b2[j][2];
j++;
k++;
}
b3[0][2]=k-1;
}
void printsparse(int b[Max][3])
{
int i,t;
t=b[0][2];
printf("\n row \tcolumn \t value");
for(i=1;i<=t;i++)
{
printf("\n %d\t%d \t%d",b[i][0],b[i][1],b[i][2]);
}
}




