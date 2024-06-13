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
	
}

bool stack_push(StackArrayList *s, int elem){
	if(s->top < MAX){
		s->data[++(s->top)] = elem;
	}
}
bool stack_pop(StackArrayList *s){
	if(s->top != -1){
		s->top--;
	}
}
int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	while(s.top != - 1){
		printf("[%d]", s.data[--s.top]);
	}
}

void visualize(StackArrayList s){
	  printf("\n\nINDEX"); printf("%-10s" "VALUE", " ", "\n"); printf("%11s", "TOP", " ");
	int a;
	for(a=0; s.top != -1; a++){
		printf("\n[%d]", s.data[s.top--]);
		printf("%-12s", " ");
		printf("[%d]", s.top);
		
	}
}
