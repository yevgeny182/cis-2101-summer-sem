#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "Stack_Array.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList mainStack = createStack();
	
	initStack(&mainStack);
	//createStack();
	stack_push(&mainStack, 22);
	stack_push(&mainStack, 41);
	stack_push(&mainStack, 97);
	stack_push(&mainStack, 100);
	stack_push(&mainStack, 44);
	stack_push(&mainStack, 71);
	stack_push(&mainStack, 77);
	stack_push(&mainStack, 56);
	display(mainStack);
	
	int retVal = stack_peek(mainStack);
	printf("\n \ntop returned value: [%d]", retVal);
	
	visualize(mainStack);
	
	
	printf("\n\nGet Even Values");
	StackArrayList evenVal = getEven(&mainStack);
	visualize(evenVal);
	
	return 0;
}
