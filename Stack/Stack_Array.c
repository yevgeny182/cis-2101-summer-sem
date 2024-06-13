#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Stack_Array.h"

void initStack(StackArrayList *S){
	S->top = -1;
}

StackArrayList createStack(){
	StackArrayList S;
	S.top = -1;
	return S;
}

bool stack_push(StackArrayList *s, int elem){
	if(s->top < MAX){
		s->data[++(s->top)] = elem;
		return true;
	}
	return false;
}
bool stack_pop(StackArrayList *s){
	if(s->top != -1){
		s->top--;
		return true;
	}
	return false;
}
int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	printf("Inserted Values\n");
	while(s.top != - 1){
		printf("[%d]\n",s.data[s.top--]);
	}
}

void visualize(StackArrayList s){
	  printf("\n\VALUE"); printf("%-10s" "INDEX", " ", "\n");
	int a;
	for(a=s.top; a>=0; a--){
		printf("\n[%d]", s.data[a]);
		printf("%-12s", " ");
		printf("[%d]", a);
		
		if(a == s.top){
			printf("%-8s", " ");
			printf("<--top value");
		}
	}
}

StackArrayList getEven(StackArrayList *S){
	StackArrayList even = createStack();
	StackArrayList orig = createStack();
	while(S->top != -1){
		int elem = S->data[S->top--];
		if(elem % 2 == 0){
			stack_push(&even,  elem);
		}
		else{
			stack_push(&orig,  elem);
		}
	}
	while(orig.top != -1){
		stack_push(S,  orig.data[orig.top--]);
	}
	return even;
}


