#include "FCFS.h"
#include<stdlib.h>
#include<stdio.h>

ProcessNode* insert(ProcessNode* head, int pid, int burst_time, int arriv_time){
	ProcessNode*  newProc = (ProcessNode*)malloc(sizeof(ProcessNode));
	
	newProc->pid = pid;
	newProc->BT = burst_time;
	newProc->TAT = 0;
	newProc->WT = 0;
	newProc->AT = arriv_time;
	newProc->next = head;
	head = newProc;
	return head;
	
}

void calculateWaitingTime(ProcessNode* head, int *wt){
	ProcessNode* temp;
	int remainTime = 0, currTime = 0;
	for(temp = head; temp!=NULL; temp = temp->next){
		currTime = temp->AT > currTime ? temp->AT : currTime + remainTime;
        remainTime = currTime - temp->AT; 
        
        if (remainTime >= temp->BT) {
            remainTime -= temp->BT;
            wt[temp->pid - 1] = remainTime;
        } else {
            wt[temp->pid - 1] = remainTime;
            remainTime = 0;
        }	
	}
}
void calculateTurnaroundTime(ProcessNode* head, int *tat) {
    ProcessNode* temp;
    int remainTime = 0, currTime = 0;
    for (temp = head; temp!= NULL; temp = temp->next) {
       
        currTime = temp->AT > currTime? temp->AT : currTime + remainTime;
        remainTime = currTime - temp->AT; 

        if (currTime >= temp->AT) {
            tat[temp->pid - 1] = currTime + remainTime - temp->AT; 
        }
    }
}


void printAvgTimes(ProcessNode* head, int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    calculateWaitingTime(head, wt);
    calculateTurnaroundTime(head, tat);

    // Calculate total waiting time and total turnaround time
    for(int i = 0; i < n; i++) {
        total_wt += wt[i]; // Correctly accumulate total waiting time
        total_tat += tat[i]; // Correctly accumulate total turnaround time
    }

    // Display processes along with all details
    printf("Processes\tBurst time\tArrival time\tWaiting time\tTurn around time\n");
    ProcessNode* temp = head;
    int currentTime = 0;
    for(int i = 0; temp!= NULL; i++, temp = temp->next) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, temp->BT, temp->AT, wt[i], tat[i]); // Correctly display waiting time and turnaround time
        currentTime += temp->BT;
    }

    // Calculate and display average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average waiting time = %.2f\n", avg_wt);
    printf("Average turn around time = %.2f\n", avg_tat);

    // Gantt Chart Visualization
    printf("\nGantt Chart:\n");
    printf("  ");
    for(int j = 0; j < currentTime; j++) {
        printf("|");
    }
    printf("\n");
    
    for(temp = head; temp!= NULL; temp = temp->next) {
        printf("%d ", temp->pid);
        for(int j = 0; j < temp->BT; j++) {
            printf("|");
        }
        printf("\n");
    }
}


