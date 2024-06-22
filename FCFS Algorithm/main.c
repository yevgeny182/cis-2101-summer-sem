#include <iostream>
#include "FCFS.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ProcessNode* mainNode = NULL;
	int numProc, a, pid, bt, at;
	printf("Enter Total Number of Processes: ");
	scanf("%d", &numProc);
	
	
	for(a=0; a < numProc; a++){
		printf("\nEnter details of process %d:\n", a+1);
		printf("PID: ");
		scanf("%d", &pid);
		printf("Burst Time: ");
		scanf("%d", &bt);
		printf("Arrival Time: ");
		scanf("%d", &at);
		
		mainNode = insert(mainNode, pid, bt, at);
	}
	int wt[numProc], tat[numProc];
	calculateWaitingTime(mainNode, wt);
	calculateTurnaroundTime(mainNode, tat);
	
	printAvgTimes(mainNode,numProc);
	

	return 0;
}
