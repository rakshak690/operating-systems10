#include<stdio.h>
 int main()
{
    int burst_time[20],p[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_waiting_time,avg_tat;
    printf("please enter number of process: ");
    scanf("%d",&n);
    printf("\n enter the Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;         
    }
   // from here, burst times sorted
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    waiting_time[0]=0;            
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }
    avg_waiting_time=(float)total/n;      
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],waiting_time[i],tat[i]);
    }
    avg_tat=(float)total/n;    
    printf("\n\n the average Waiting Time=%f",avg_waiting_time);
    printf("\n  the average Turnaround Time=%f\n",avg_tat);
}



/*OUTPUT:please enter number of process: 4

 enter the Burst Time:
p1:5
p2:4
p3:2
p4:1

Process     Burst Time          Waiting Time    Turnaround Time
p4                1                 0                   1
p3                2                 1                   3
p2                4                 3                   7
p1                5                 7                   12

 the average Waiting Time=2.750000
  the average Turnaround Time=5.750000*/
