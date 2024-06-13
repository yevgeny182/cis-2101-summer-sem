#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} StackLinkedList;

void initStack(StackLinkedList* stack);
StackLinkedList createStack();
bool stack_push(StackLinkedList* stack, int elem);
bool stack_pop(StackLinkedList* stack);
int stack_peek(StackLinkedList stack);
void display(StackLinkedList stack);
void visualize(StackLinkedList stack);





#endif

