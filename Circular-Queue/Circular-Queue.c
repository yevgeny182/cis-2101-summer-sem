#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 6
typedef struct{
	int data[MAX];
	int front;
	int rear;
}CircularQ;

void initQueue(CircularQ *Q){
	Q->front = 1;
	Q->rear = 0;
	printf("Initialized!\n");
}
bool isFull(CircularQ *Q){
	return (Q->rear + 2) % MAX == Q->front ? 1 : 0;
}
bool isEmpty(CircularQ *Q){
	return (Q->rear + 1) % MAX == Q->front ? 1 : 0;
}

void Enqueue(CircularQ *Q, int num){
	// initalize isFull
	if(isFull(Q) == 1){
		printf("Queue is Full Value:[%d] cannot be inserted!\n", num);
		return;
	}
	else{
		Q->rear = (Q->rear + 1) % MAX;
		Q->data[Q->rear] = num;
	}

	printf("Index Value: [%d] [%d]\n",Q->rear, num);

}
void Dequeue(CircularQ *Q){
	//initalize isEmpty
	if(isEmpty(Q) == 1){
		printf("Queue is Empty\n");
		return;
	} 
	else{
		Q->front = (Q->front + 1) % MAX;
		printf("Value Deququed: [%d]\n", Q->data[Q->front]);
	}
}


void Display(CircularQ Q){
	printf("\nFront Element:[%d]\nRear Element[%d]\n", Q.data[Q.front], Q.data[Q.rear]);
}



int main(){
	CircularQ mainQ;
	initQueue(&mainQ);
	printf("Enququed Values\n");
	Enqueue(&mainQ, 35);
	Enqueue(&mainQ, 70);
	Enqueue(&mainQ, 105);
	Enqueue(&mainQ, 140);
	Enqueue(&mainQ, 175);
	Display(mainQ);
	
	
	printf("\n\nDeleting Values\n");
	Dequeue(&mainQ);
	Display(mainQ);
	
	
}
