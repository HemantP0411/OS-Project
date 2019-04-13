#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//variable declaration
int arr[10],br[10],post[10],br1[10],wt[10],tarr[10],t1=3,t2=6,avgt=0,avgw=0,i,m,temp1,temp2,temp,j;
//function to take user input of burst,arrival time of processes
void input(int arrival[],int burst[],int burst1[])
{
	a:
		system("cls");
	printf("\nEnter number of processes");
	scanf("%d",&m);
	printf("\nEnter arival time of processes:");
	for(i=0;i<m;i++)
	{  printf("\nfor processes %d :",i+1);
		scanf("%d",&arrival[i]);
		post[i]=i+1;
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
	for(i=0;i<m;i++)
	{
		for(j=0;j<3;j++);
		{
			printf("\n  P%d    \t%d       \t%d",post[i],arrival[i],burst[i]);
		}
	}
	printf("\n\nIf no then press 'n' else press 'y'\n");
	char ch;
	scanf("%s",&ch);
	if(ch=='n')
	goto a;
}
//function for sorting according to arrival time
void sort()
{
	for(j=0;j<m;j++)
	{
		for(i=0;i<m-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				
				temp2=post[i];
				post[i]=post[i+1];
				post[i+1]=temp2;
				
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				
				temp1=br[i];
				br[i]=br[i+1];
				br[i+1]=temp1;
			}
		}
	}	
	system("cls");
	printf("\nFinal table after sorting according to arrival time\n\n");
	printf("Process\tArrival Time\tBurst Time");
	for(i=0;i<m;i++)
	{
		for(j=0;j<3;j++);
		{
			printf("\n  P%d    \t%d       \t%d",post[i],arr[i],br[i]);
		}
	}
system("pause");
}
main()
{
	input(arr,br,br1);
	sort();
}
