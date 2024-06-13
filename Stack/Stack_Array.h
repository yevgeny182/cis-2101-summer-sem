#ifndef STACK_ARRAY
#define STACK_ARRAY
#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} StackArrayList;

void initStack(StackArrayList *S);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);

void display(StackArrayList s);

void visualize(StackArrayList s);

StackArrayList getEven(StackArrayList *S);

//Others
//Create a function that would get all even numbers 
//and return as a new stack removing from the old stack

#endif
