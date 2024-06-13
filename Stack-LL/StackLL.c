#include <stdio.h>
#include <stdlib.h>
#include "StackLL.h"


void initStack(StackLinkedList* s){
	s->top = NULL;
}
StackLinkedList createStack(){
	StackLinkedList create;
	create.top = NULL;
	return create;
}

bool stack_push(StackLinkedList* s, int elem){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		return false;
	}else{
		newNode->data = elem;
		newNode->next = s->top;
		s->top = newNode;
		return true;
	}
}
bool stack_pop(StackLinkedList* s){
	if(s->top == NULL){
		return false;
	}else{
		Node* temp = s->top;
		s->top = s->top->next;
		free(temp);
		return true;
	}
}
int stack_peek(StackLinkedList s){
	if(s.top == NULL){
		return -1;
	}
	else{
		return s.top->data;
	}
}
void display(StackLinkedList s){
	int a;
	Node* trav;
	for(trav = s.top; trav!=NULL; trav = trav->next){
		printf("[%d]\n", trav->data);
	}
}
void visualize(StackLinkedList s){
	int index;
	Node *trav;
	for(index =0, trav = s.top; trav!=NULL; trav=trav->next, index++){
		 printf("%-7d [%d]", index, trav->data);
		if(trav == s.top){
			printf("<-- top");
		}
	}

}
