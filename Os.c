#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//variable declaration
int at[10],bt[10],post[10],tat[10],t1=3,t2=6,avgt=0,avgw=0,i,m,temp1,temp2,temp,j;

int ct[50]={0}, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[10], tt, wt,x;
float att, awt;
int n;
//function to take user input of bt,at time of processes
void input()
{
	a:
		system("cls");
	printf("\nEnter number of processes: ");
	scanf("%d",&m);
	printf("\nEnter arival time of processes:  ");
	for(i=0;i<m;i++)
	{  printf("\nfor processes %d :",i+1);
		scanf("%d",&at[i]);
		post[i]=i+1;
	}
	printf("\nenter bt time for processes:");
	for(i=0;i<m;i++)
	{
		printf("\nfor processes %d:",i+1);
		scanf("%d",&bt[i]);
		btm[i]=bt[i];	
	}
	system("cls");
	printf("Is this your final table?\n\n");
	printf("Process\tArrival Time\tBurst Time\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<3;j++);
		{
			printf("  P%d    \t%d       \t%d\n",post[i],at[i],bt[i]);
		}
	}
	printf("\n\nIf no then press 'n' else press 'y'\n");
	char ch;
	scanf("%s",&ch);
	if(ch=='n')
	goto a;
}
//function for iteration 1 i.e. time quantum 3 unit
void sort()
{
	for(j=0;j<m;j++)
	{
		for(i=0;i<m-1;i++)
		{
			if(at[i]>at[i+1])
			{
				
				temp2=post[i];
				post[i]=post[i+1];
				post[i+1]=temp2;
				
				temp=at[i];
				at[i]=at[i+1];
				at[i+1]=temp;
				
				temp1=bt[i];
				bt[i]=bt[i+1];
				bt[i+1]=temp1;
//				btm[i]=bt[i];
			}
		}
	}	
	system("cls");
	printf("\nFinal table after sorting according to at time\n\n");
	printf("Process\tArrival Time\tBurst Time\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<3;j++);
		{
			printf("  P%d    \t%d       \t%d\n",post[i],at[i],btm[i]);
		}
	}
system("pause");
}
void SearchStack01(int pnt,int tm){
    for(int x=pnt+1;x<n;x++){
       if(at[x]<=tm){
          rqi[noe]=x+1;
          noe++;}
    }//for
}//void

void SearchStack02(int pnt, int tm){
    for(int x=pnt+1;x<n;x++){
       //---CheckQue
       int fl=0;
       for(int y=0;y<noe;y++){
          if(rqi[y]==x+1){
             fl++;}}
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rqi[noe]=x+1;
          noe++;}
    }//for
}//void

void AddQue(int pnt){
    rqi[noe]=pnt+1;
    noe++;
}//void

void iteration1()
{
	n=m;
	do{
    if(flg==0){
       st=at[0];
       //---ReduceBT
       if(btm[0]<=3){
          tm=st+btm[0];
          btm[0]=0;
          SearchStack01(pnt,tm);}
       else{
          btm[0]=btm[0]-3;
          tm=st+3;
          SearchStack01(pnt,tm);
          AddQue(pnt);}
    }//if
 
    else{
       pnt=rqi[0]-1;
       st=tm;
       //---DeleteQue
       for(x=0;x<noe && noe!=1;x++){
          rqi[x]=rqi[x+1];}
       noe--;
       //---ReduceBT
       if(btm[pnt]<=3){
          tm=st+btm[pnt];
          btm[pnt]=0;
          SearchStack02(pnt, tm);}
       else{
         btm[pnt]=btm[pnt]-3;
          tm=st+3;
          SearchStack02(pnt, tm);
          AddQue(pnt);}
    }//else

    //AssignCTvalue
    if(btm[pnt]==0){
       ct[pnt]=tm;
    }//if

   flg++;
   printf("P%d-",pnt+1);
}while(noe!=0&&btm[n-1]==bt[n-1]);
//printf("\n%d   %d",bt[m],btm[m]);
for(x=0;x<n;x++)
{
	printf("%d",btm[x]);
}
}


main()
{
	input();
	sort();
//	printf("%d   %d",bt[m],btm[m]);
	iteration1();
}
