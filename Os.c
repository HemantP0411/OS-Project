#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void input(int arrival[],int burst[],int burst1[])
{
	int i,m;
	a:
		system("cls");
	printf("\nEnter number of processes");
	scanf("%d",&m);
	printf("\nEnter arival time of processes:");
	for(i=0;i<m;i++)
	{  printf("\nfor processes %d :",i+1);
		scanf("%d",&arrival[i]);
	}
	printf("\nenter burst time for processes:");
	for(i=0;i<m;i++)
	{
		printf("\nfor processes %d:",i+1);
		scanf("%d",&burst[i]);
		burst1[i]=burst[i];	
	}
	system("cls");
	printf("Is this your final table?\n\n");
	printf("Process\tArrival Time\tBurst Time");
	int j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<3;j++);
		{
			printf("\n  P%d    \t%d       \t%d",i+1,arrival[i],burst[i]);
		}
	}
	printf("\n\nIf no then press 'n' else press 'y'\n");
	char ch;
	scanf("%s",&ch);
	if(ch=='n')
	goto a;
}
main()
{
	int arrival[10],burst[10],burst1[10],waiting[10],tarrival[10],t1=3,t2=6,avgtime=0,avgwait=0;
	input(arrival,burst,burst1);
}
