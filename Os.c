#include<stdio.h>
struct post2
{
	int ar,bs,pid;
};

int uvt=0; //universal time
int n,time;	//number of processes and time quantum
int arr[10],a1=0;
int bur[10],b1=0,bur1[10];
int i,flag=1,flagav=0;
int exe[10],ex1=0;
int post[10],post2[10],p1=0,p2=0;
int pro[10],pro1=0;


void proz(int a[])
{
	int x=(sizeof(arr)/4)-1;
	pro1=x;
	int i=0;
	for(i=0;i<x;i++)
	{
		a[i]=a[i+1];
	}
}
int main()
{
struct post2 p[10];
printf("\n Enter number of processes (max 15): ");
scanf("%d",&n);
int num=n;
printf("\n Enter the time quantum: ");
scanf("%d",&time);
for(i=0;i<n;i++)
{
post[i]=i+1;
printf("\n Enter arrival time and burst time for P[%d]: ",post[i]);
scanf("%d",&arr[i]);
scanf("%d",&bur[i]);
bur1[i]=bur[i];
}
for(i=0;i<n;i++)
{
p[i].ar=arr[i];
p[i].bs=bur[i];
p[i].pid=post[i];	
}
}
