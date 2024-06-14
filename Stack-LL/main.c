#include "StackLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    StackLinkedList mainStack = createStack();
    stack_push(&mainStack, 22);
    stack_push(&mainStack, 56);
    stack_push(&mainStack, 99);
    visualize(mainStack);
    
    
    stack_pop(&mainStack);
    visualize(mainStack);
    
    int peekValue = stack_peek(mainStack);
    printf("%d", peekValue);
}
