#ifndef QUEUE_LL
#define QUEUE_LL

#include<stdbool.h>


typedef struct node{
	int data;
	struct node * next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void enqueue(Queue *EQ, int item);
void dequeue(Queue *DQ);
//int front();
//int rear();
bool isEmpty(Queue MT);
void display(Queue disp);
void initQueue(Queue *Q);






	




#endif
