#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//variable declaration
int at[10]={0,2,4,13},bt[10]={18,23,13,10},post[10],t1=3,t2=6,i,m=4,temp1,temp2,temp,j;

int ct[10]={0}, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[10]={18,23,13,10}, tt, wt[50]={0},x;
float att, awt;
int n=4;
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
void searchst1(int pnt,int tm){
    for(int x=pnt+1;x<n;x++){
       if(at[x]<=tm){
          rqi[noe]=x+1;
          noe++;}
    }
}

void searchst2(int pnt, int tm)
{
    for(int x=pnt+1;x<n;x++)
	{
       int fl=0;
       for(int y=0;y<noe;y++){
          if(rqi[y]==x+1){
             fl++;}}
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rqi[noe]=x+1;
          noe++;}
    }
}

void AddQue(int pnt){
    rqi[noe]=pnt+1;
    noe++;
}
int start[10]={0},end[10]={0};
void iteration1()
{
	n=m;
	do{
    if(flg==0){
       st=at[0];
     
       if(btm[0]<=3){
          tm=st+btm[0];
          btm[0]=0;
          searchst1(pnt,tm);}
       else{
          btm[0]=btm[0]-3;
          tm=st+3;
          searchst1(pnt,tm);
          AddQue(pnt);}
    }
 
    else{
       pnt=rqi[0]-1;
       st=tm;
       
       for(x=0;x<noe && noe!=1;x++){
          rqi[x]=rqi[x+1];}
       noe--;
       
       if(btm[pnt]<=3){
          tm=st+btm[pnt];
          btm[pnt]=0;
          searchst2(pnt, tm);}
       else{
         btm[pnt]=btm[pnt]-3;
          tm=st+3;
          searchst2(pnt, tm);
          AddQue(pnt);}
    }
    
    
       ct[pnt]=tm;
       printf("%d %d %d\n",st,pnt,tm);
       start[pnt]=st;
       wt[pnt]+=((start[pnt]-end[pnt]));
    end[pnt]=tm;
    
   flg++;
   
   	
}while(noe!=0&&btm[n-1]==bt[n-1]);
}
int flag1=1,tm1=0,wt1[10];
void waitf(int tm12,int index)
{
		int in1;
	for(in1=0;in1<m;in1++)
	{
		if(index!=in1)
		{
			wt1[i]+=tm12;
		}
	}
}
void iteration2()
{
	for(i=0;i<m;i++)
	{
		wt1[i]=wt[i]-at[i]+end[m-1]-end[i];
	}
	i=0;
	while(flag1==1)
	{
		tm1=0;
		if(btm[i]<=6)
		{
			tm1=btm[i];
			btm[i]=0;
		}
		else
		{
			btm[i]-=6;
			tm1=6;
		}
		waitf(tm1,i);
	i++;
	if(i==m)
	{
		flag1=0;
	}
	
	}
}
main()
{
	
//	input();
//	sort();

	iteration1();
	iteration2();
printf("\n\nPROCESS\t AT\t BT\t CT\t TT\t WT\n");
for(int x=0;x<n;x++){
    tt=ct[x]-at[x];
    printf("P%d \t %d \t %d \t %d \t %d \t %d\n",x+1,at[x],bt[x],ct[x],tt,wt1[x]);
    awt=awt+wt[x];
    att=att+tt;
}

}
