#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue Q;
	initQueue(&Q);
	enqueue(&Q, 30);
	enqueue(&Q, 20);
	enqueue(&Q, 15);
	enqueue(&Q, 9);
	enqueue(&Q, 4);

	dequeue(&Q);
	
	display(Q);
	
	return 0;
}
