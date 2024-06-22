#ifndef FCFS
#define FCFS

typedef struct ProcessNode {
    int pid;          // Process ID
    int BT;   // Burst Time
    int WT; // Waiting Time
    int TAT; // Turnaround Time
    int AT;
    struct ProcessNode* next; // Pointer to the next node
} ProcessNode;


ProcessNode* insert(ProcessNode* head, int pid, int burst_time, int arriv_time);

void calculateWaitingTime(ProcessNode* head, int *wt);

void calculateTurnaroundTime(ProcessNode* head, int *tat);

void printAvgTimes(ProcessNode* head, int n);

#endif
