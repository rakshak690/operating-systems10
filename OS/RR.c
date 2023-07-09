#include<stdio.h>  
1.	#include<conio.h>  
2.	  
3.	void main()  
4.	{  
5.	    // initlialize the variable name  
6.	    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
7.	    float avg_wt, avg_tat;  
8.	    printf(" Total number of process in the system: ");  
9.	    scanf("%d", &NOP);  
10.	    y = NOP; // Assign the number of process to variable y  
11.	  
12.	// Use for loop to enter the details of the process like Arrival time and the Burst Time  
13.	for(i=0; i<NOP; i++)  
14.	{  
15.	printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
16.	printf(" Arrival time is: \t");  // Accept arrival time  
17.	scanf("%d", &at[i]);  
18.	printf(" \nBurst time is: \t"); // Accept the Burst time  
19.	scanf("%d", &bt[i]);  
20.	temp[i] = bt[i]; // store the burst time in temp array  
21.	}  
22.	// Accept the Time qunat  
23.	printf("Enter the Time Quantum for the process: \t");  
24.	scanf("%d", &quant);  
25.	// Display the process No, burst time, Turn Around Time and the waiting time  
26.	printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
27.	for(sum=0, i = 0; y!=0; )  
28.	{  
29.	if(temp[i] <= quant && temp[i] > 0) // define the conditions   
30.	{  
31.	    sum = sum + temp[i];  
32.	    temp[i] = 0;  
33.	    count=1;  
34.	    }     
35.	    else if(temp[i] > 0)  
36.	    {  
37.	        temp[i] = temp[i] - quant;  
38.	        sum = sum + quant;    
39.	    }  
40.	    if(temp[i]==0 && count==1)  
41.	    {  
42.	        y--; //decrement the process no.  
43.	        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
44.	        wt = wt+sum-at[i]-bt[i];  
45.	        tat = tat+sum-at[i];  
46.	        count =0;     
47.	    }  
48.	    if(i==NOP-1)  
49.	    {  
50.	        i=0;  
51.	    }  
52.	    else if(at[i+1]<=sum)  
53.	    {  
54.	        i++;  
55.	    }  
56.	    else  
57.	    {  
58.	        i=0;  
59.	    }  
60.	}  
61.	// represents the average waiting time and Turn Around time  
62.	avg_wt = wt * 1.0/NOP;  
63.	avg_tat = tat * 1.0/NOP;  
64.	printf("\n Average Turn Around Time: \t%f", avg_wt);  
65.	printf("\n Average Waiting Time: \t%f", avg_tat);  
66.	getch();  
67.	}  
