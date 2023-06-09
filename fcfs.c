//FCFS Scheduling algorithm..

#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid,at,bt,tt,ct,wt;
};

typedef struct process p;

float tot_tt = 0;
float tot_wt = 0;

void sort(p *a,int n)
{
	p temp;
	for(int i = 0;i<n-1;i++)
	{
		for(int j =0;j<n-i-1;j++)
		{
			if(a[j].at > a[j+1].at)
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void printGanttChart(p*p,int n)
{
	for(int i=0;i<n;i++)
	{
		if(p[i].at>p[i-1].ct)
		printf("|IDLE (%d) %d",p[i].at,p[i-1].ct);
		printf("|%d (%d) %d",p[i].pid, p[i].bt,p[i].ct);
	}
	printf("\n");
}


void CT(p*a,int n)
{
	int ct;
	a[0].ct = a[0].at +a[0].bt;
	ct = a[0].ct;
	
	for(int i = 1;i<n;i++)
	{
		if(ct< a[i].at)
		{
			ct = a[i].at;
		}
		ct += a[i].bt;
		a[i].ct = ct;		
	}
}

void TT(p*a,int n)
{
	for(int i = 0;i<n;i++)
	{
		a[i].tt = a[i].ct - a[i].at;
		tot_tt += a[i].tt;
	}
}

void WT(p*a,int n)
{
	for(int i =0;i<n;i++)
	{
		a[i].wt = a[i].tt - a[i].bt;
		tot_wt += a[i].wt;
	}
}

int main()
{
	int n;
	printf("Enter the Number of Process : ");
	scanf("%d",&n);
	
	p*a = (p*)calloc(n,sizeof(p));
	
	for(int i =0;i<n;i++)
	{
		a[i].pid = i+1;
		printf("AT of p%d : ",i+1);
		scanf("%d",&a[i].at);
		printf("BT of p%d : ",i+1);
		scanf("%d",&a[i].bt);
	}
	
	sort(a,n);
	CT(a,n);
	TT(a,n);
	WT(a,n);
	printGanttChart(a,n);
	
	printf("PID\tAT\tBT\tWT\tTT\tCT\n");
	
	for(int i = 0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i].pid,a[i].at,a[i].bt,a[i].wt,a[i].tt,a[i].ct);
	}
	printf("\nThe Average Total Time is %f\n",(tot_tt/n));
	printf("\nThe Average Waiting Time is %f\n",(tot_wt/n));
}
