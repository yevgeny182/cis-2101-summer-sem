#include "FCFS.h"
#include<stdlib.h>
#include<stdio.h>

ProcessNode* insert(ProcessNode* head, int pid, int burstTime, int arrivTime){
	ProcessNode* trav;
	ProcessNode*  newProc = (ProcessNode*)malloc(sizeof(ProcessNode));	
	newProc->pid = pid;
	newProc->BT = burstTime;
	newProc->TAT = 0;
	newProc->WT = 0;
	newProc->AT = arrivTime;
	newProc->next = NULL;
	
	if(head == NULL)
		return newProc;
	for(trav = head; trav->next!=NULL; trav = trav->next){}
	trav->next = newProc;
	return head;
	
	
}
/*
ProcessNode* insert(ProcessNode* head, int pid, int burstTime, int arrivTime){
	ProcessNode* trav;
	
	for(trav = head; trav!=NULL; trav = trav->next){
		if(trav->pid == pid && trav->BT == burstTime && trav->AT == arrivTime){
			return head;
		}
	}
	insertFirst(head,  pid,  burstTime,  arrivTime);
}
*/
void calculateWaitingTime(ProcessNode* head, int *wt){
	ProcessNode* temp;
	int remainTime = 0, currTime = 0;
 	for (temp = head; temp != NULL; temp = temp->next) {
        if (currTime < temp->AT) {
            currTime = temp->AT;  // If CPU is idle until process arrives
        }
        wt[temp->pid - 1] = currTime - temp->AT;
        currTime += temp->BT;
    }
}
void calculateTurnaroundTime(ProcessNode* head, int *tat, int *wt) {
    ProcessNode* temp;
     for (temp = head; temp != NULL; temp = temp->next) {
        tat[temp->pid - 1] = temp->BT + wt[temp->pid - 1];
    }
}


void printAvgTimes(ProcessNode* head, int n) {
    int wt[n], tat[n], totalWait = 0, totalTAT = 0;
    int i;
    calculateWaitingTime(head, wt);
    calculateTurnaroundTime(head, tat, wt);

    for( i = 0; i < n; i++) {
        totalWait += wt[i];
        totalTAT += tat[i]; 
    }

    // Display processes along with all details-
    printf("Processes ID\tBT\tAT\tWT\tTAT\n");
    ProcessNode* temp = head;
    int currentTime = 0;
    for( i = 0; temp!= NULL; i++, temp = temp->next) {
        printf("%d\t\t%d\t%d\t%d\t%d\n", temp->pid, temp->BT, temp->AT, wt[temp->pid - 1], tat[temp->pid - 1]);

    }
    printf("\n"); printf("\n");
    printf("Total Waiting Time: %d\n", totalWait);
    printf("Total Turn Around Time: %d\n", totalTAT);

	printf("\n"); printf("\n");
    float avgWaitTime = (float)totalWait / n;
    float avgTurnAroundTime = (float)totalTAT / n;
   
    printf("Average Waiting Time = %.2f\n", avgWaitTime);
    printf("Average Turn Around Time = %.2f\n", avgTurnAroundTime);

    // Gantt Chart Visualization
    printf("\nGantt Chart:\n");
    int currTime = 0;
    for(temp = head; temp != NULL; temp = temp->next) {
        if (currTime < temp->AT) {
            currTime = temp->AT;
        }
        printf("Process ID %d | Time: %d to %d\n", temp->pid, currTime, currTime + temp->BT);
        currTime += temp->BT;
    }
}


