#include<stdio.h>
#include<stdlib.h>
//variable declaration
int at[10],bt[10],post[10],t1=3,t2=6,i,m,temp1,temp2,temp,temp12,temp11,j;

int ct[10]={0}, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[10]={0}, tt, wt[50]={0},x,flag1=1,tm1=0,wt1[10],start[10]={0},end[10]={0};
float att=0, awt=0;
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
void searchst1(int pnt,int tm)
{
	int x;
    for(x=pnt+1;x<n;x++){
       if(at[x]<=tm){
          rqi[noe]=x+1;
          noe++;}
    }
}
void searchst2(int pnt, int tm)
{  
	int x;
	for(x=pnt+1;x<n;x++)
	{
       int fl=0;
       int y;
       for(y=0;y<noe;y++)
	{
      	if(rqi[y]==x+1)
	  	{
        	fl++;
	  	}
	}
			 
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rqi[noe]=x+1;
          noe++;}
    }
    
}
void addqueue(int pnt)
{
    rqi[noe]=pnt+1;
    noe++;
}
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
          addqueue(pnt);}
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
          addqueue(pnt);}
}
       ct[pnt]=tm;
       start[pnt]=st;
       wt[pnt]+=((start[pnt]-end[pnt]));
    end[pnt]=tm;
   flg++;  	
}while(noe!=0&&btm[n-1]==bt[n-1]);
}
void waitf(int tm12,int index)
{
		int in1;
	for(in1=0;in1<m;in1++)
	{
		if(index!=in1&&btm[in1]>0)
		{
			wt1[in1]+=tm12;
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
void sort(int al)
{
	if(al==1)
	{
for(i=0;i<m;i++)
{
for(j=0;j<m-1;j++)
	{
		if(btm[j]>btm[j+1])
		{
				temp2=post[j];
				post[j]=post[j+1];
				post[j+1]=temp2;
				
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				
				temp1=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp1;
				
				temp12=btm[j];
				btm[j]=btm[j+1];
				btm[j+1]=temp12;
				
				temp11=wt1[j];
				wt1[j]=wt1[j+1];
				wt1[j+1]=temp11;	
		}
	}
	}
}
else
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
}
void fcfs()
{
	sort(1);
	i=0;
	while(i<m)
	{
		while(btm[i]>0)
		{
			waitf(1,i);
			btm[i]-=1;
		}
		i++;
	}
}
void display()
{
	system("cls");
	printf("After completion of all processes (in order of their completion time)\n\n");
	printf("\n\nPROCESS\t AT\t BT\t CT\t TAT\t WT\t\n");
	int x;
	for( x=0;x<n;x++)
	{
    tt=wt1[x]+bt[x];
    printf("P%d \t %d \t %d \t %d \t %d \t %d\t\n",post[x],at[x],bt[x],tt+at[x],tt,wt1[x]);
    awt=awt+wt1[x];
    att=att+tt;
	}
	printf("\n\n Average waiting time is : %f\nAverage turn around time is : %f\n",awt/m,att/m);
}
main()
{
	input();
	sort(0);
	iteration1();
	iteration2();
	fcfs();
	display();
}
