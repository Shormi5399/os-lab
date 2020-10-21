///////////////////ROUND ROBIN//////////////////////////////////////////

//simple c implemetation 

#include<stdio.h>
main()
{
int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
float awt=0,att=0,temp=0;
clrscr();
printf("Enter the no of processes -- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time for process %d -- ", i+1);
scanf("%d",&bu[i]);
ct[i]=bu[i];
}
printf("\nEnter the size of time slice -- ");
scanf("%d",&t);
max=bu[0];
for(i=1;i<n;i++)
if(max<bu[i])
max=bu[i];
for(j=0;j<(max/t)+1;j++)
for(i=0;i<n;i++)
if(bu[i]!=0)
if(bu[i]<=t) {
tat[i]=temp+bu[i];
temp=temp+bu[i];
bu[i]=0;
}
else {
bu[i]=bu[i]-t;
temp=temp+t;
}
for(i=0;i<n;i++){
wa[i]=tat[i]-
ct[i]; att+=tat[i];
awt+=wa[i];}
printf("\nThe Average Turnaround time is -- %f",att/n);
printf("\nThe Average Waiting time is -- %f ",awt/n);
printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);
getch();}
//this code is contributed by Sayan

////////////////ROUND ROBIN ////////////////////////////////////////////////////////////

int pop()
{
	if(front == rear)
		return -1;

	int return_position = queue[front];
	front = (front +1)%N;
	return return_position;
}

int main()
{
	float wait_time_total = 0.0, tat = 0.0;
	int n,time_quantum;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int remaining_time;
};

int queue[N];
int front = 0, rear = 0;
struct process proc[N];

void push(int process_id)
{

	for(int i=0; i<n; i++)
	{
		printf("Enter the arrival time for the process%d: ",i+1);
		scanf("%d", &proc[i].arrival_time);
		printf("Enter the burst time for the process%d: ",i+1);
		scanf("%d", &proc[i].burst_time);
		proc[i].process_id = i+1;
		proc[i].remaining_time = proc[i].burst_time;
	}
	printf("Enter time quantum: ");
	scanf("%d",&time_quantum);

	int time=0; 
	int processes_left=n;   

	for(int j=0; j<n; j++)
		if(proc[j].arrival_time == time)
			push(j);

	while(processes_left)
    {
        int cur=pop();
        if(cur==-1)
        {
            printf("CPU IDLE from %d to %d\n",time,time+1);
            time++;
        }
        for(int i=0;i<n;i++)
        {
            if(proc[i].arrival_time<=time&&proc[i].remaining_time!=0)
                push(i);  
        }
        if(cur!=-1)
        {   
            
            if(proc[cur].remaining_time>time_quantum)
            {
                proc[cur].remaining_time-=time_quantum;
                time+=time_quantum;
                push(cur);
                printf("P%d->",cur+1);
            }
            else if(proc[cur].remaining_time>0)
            {
                time+=proc[cur].remaining_time;
                proc[cur].remaining_time=0;
                --processes_left;
                proc[cur].turn_around_time=time-proc[cur].arrival_time;
                proc[cur].waiting_time=proc[cur].turn_around_time-proc[cur].burst_time;
                printf("P%d->",cur+1);
            }
        }
    }
	
	printf("\n");

	printf("Process\t\tArrival Time\tBurst Time\tWaiting time\tTurn around time\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t", proc[i].process_id, proc[i].arrival_time);
		printf("%d\t\t%d\t\t%d\n", proc[i].burst_time, proc[i].waiting_time, proc[i].turn_around_time);

		tat += proc[i].turn_around_time;
		wait_time_total += proc[i].waiting_time;
	}

	tat = tat/(1.0*n);
	wait_time_total = wait_time_total/(1.0*n);

	printf("\nAverage waiting time     : %f",wait_time_total);
	printf("\nAverage turn around time : %f\n", tat);
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
