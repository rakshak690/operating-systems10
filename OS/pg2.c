#include<stdio.h>

void fcfs(int processes[],int n,int burst_time[]){
    int waiting_time[n],turnaround_time[n],total_waiting_time=0,total_turn_around_time=0;
    waiting_time[0]=0;
    for (int i=0;i<n;i++){
    turnaround_time[i]=burst_time[i]+waiting_time[i];
    total_turn_around_time += turnaround_time[i];
}
printf("First-come,Firs-served(FCFS) Scheduling Algorithm\n");
printf("---------------------------------------------\n");
printf("Process\tBurst Time\twaiting Time\tTurnaround Timer\n");

for(int i=0;i<n;i++){
    printf("%d\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],waiting_time[i],turnaround_time[i]);
}

printf("Average waiting time : %.2f\n",(float)total_waiting_time/n);
printf("Average Turnaround time: %.2f\n",(float)total_turn_around_time/n);
printf("\n");
}

void sjf(int processes[],int n,int burst_time[]){
    int waiting_time[n],turnaround_time[n],completion_time[n],total_waiting_time=0,total_turnaround_time=0;

    for(int i=0;i<n;i++){
        int shortest_job_index=i;

        for(int j=i+1;j<n;j++){
            if(burst_time[j]<burst_time[shortest_job_index])
            shortest_job_index=j;
        }
        int temp=burst_time[i];
        burst_time[i]=burst_time[shortest_job_index];
        burst_time[shortest_job_index]=temp;

        temp=processes[i];
        processes[i]=processes[shortest_job_index];
        processes[shortest_job_index]=temp;
    }
    waiting_time[0]=0;
    for(int i=1;i<n;i++){
        waiting_time[i]=burst_time[i-1]+waiting_time[i-1];
        total_waiting_time+=waiting_time[i];
    }
    for(int i=0;i<n;i++){
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }
    printf("shortest Job First(SJF) scheduling algorithm\n");
    printf("---------------------------------------------\n");
    printf("Process\tBurst Time\twaiting Time\tTurnaround Time\n");

    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],waiting_time[i],turnaround_time[i]);
    }
    printf("Average waiting time : %.2f\n",(float)total_waiting_time/n);
    printf("Average Turnaround time: %.2f\n",(float)total_turnaround_time/n);
    printf("\n");
}

void roundRobin(int processes[],int n,int burst_time[],int quantum){
    int remaining_time[n],waiting_time[n],turnaround_time[n],completion_time[n],total_waiting_time=0,total_turnaround_time=0;
    int time=0;
    while(1){
        int all_processes_completed=1;
        for(int i=0;i<n;i++){
            if(remaining_time[i]>0){
                all_processes_completed=0;
                if(remaining_time[i]>quantum){
                    time+=quantum;
                }else{
                    time+=remaining_time[i];
                    waiting_time[i]=time-burst_time[i];
                    remaining_time[i]=0;
                }
            }
        }
        if(all_processes_completed){
            break;
        }
    }
    for(int i=0;i<n;i++){
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        total_waiting_time=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }

printf("Round Robin scheduling algorithm\n");
    printf("---------------------------------------------\n");
    printf("Process\tBurst Time\twaiting Time\tTurnaround Time\n");

    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],waiting_time[i],turnaround_time[i]);
    }
    printf("Average waiting time : %.2f\n",(float)total_waiting_time/n);
    printf("Average Turnaround time: %.2f\n",(float)total_turnaround_time/n);
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int processes[n],burst_time[n];
    printf("Enter the burst time for each process:\n");
    for(int i=0;i<n;i++){
        printf("Process %d:",i+1);
        scanf("%d",&burst_time[i]);
        processes[i]=i+1;
    }
    int quantum;
    printf("Enter the time quantum for round robin: ");
    scanf("%d",&quantum);

    printf("\n");

    fcfs(processes,n,burst_time);
    sjf(processes,n,burst_time);
    roundRobin(processes,n,burst_time,quantum);

    return 0;
}
