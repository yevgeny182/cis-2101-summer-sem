#include <iostream>
#include "FCFS.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ProcessNode* main = NULL;
	int numProc, a, pid, bt, at;
	printf("Enter Total Number of Processes: ");
	scanf("%d", &numProc);
	
	
	for(a=0; a < numProc; a++){
		printf("\nEnter details of process %d:\n", a+1);
		printf("PID: ");
		scanf("%d", &pid);
		printf("Arrival Time: ");
		scanf("%d", &at);
		printf("Burst Time: ");
		scanf("%d", &bt);
		
		main = insert(main, pid, bt, at);
	}
	int wt[numProc], tat[numProc];
	calculateWaitingTime(main, wt);
	calculateTurnaroundTime(main, tat, wt);
	
	printAvgTimes(main,numProc);
	
	ProcessNode* temp;
	for(temp = main; main != NULL; main = main->next){}
	free(temp);

	

	return 0;
}
