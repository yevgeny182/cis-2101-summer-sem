#include<stdlib.h>
#include<stdio.h>
#include "QueueLL.h"

void initQueue(Queue *Q){
	Q->front = Q->rear = NULL;
}
void enqueue(Queue *N, int item){
	NodePtr temp;
	temp = (NodePtr)malloc(sizeof(NodePtr));
	if(temp != NULL){
		temp->data = item;
	if(N->front == NULL){
		N->front = N->rear = temp;
	}else{
		N->rear->next = temp;
		N->rear = temp;
		}
	}
	N->rear->next = NULL;
	printf("Enqueued: %d\n", item);
}

void display(Queue disp){
	if(disp.front!=NULL){
		printf("Front: [%d] Back: [%d]\n", disp.front->data, disp.rear->data);
	}
}
void dequeue(Queue *DQ){
	NodePtr temp;
	if(DQ->front != NULL){
		temp = DQ->front;
		DQ->front = DQ->front->next;
		free(temp);
	}
}
bool isEmpty(Queue MT){
	return (MT.front == NULL) ? 1 : 0;
}
