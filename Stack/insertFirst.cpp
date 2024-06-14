#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char name[20];
	int idNum;
	int age;
}info;

typedef struct node{
	info data;
	struct node * head;
	struct node * next;
}Node, *NodePtr;


void insertFirst(Node* node, info IF){
	 Node* newNode = (Node*)malloc(sizeof(Node));
	 newNode->data = IF;
	 newNode->next = node->head;
	 node->head = newNode;

}

void insertLast(NodePtr* head, info IF){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = IF;
	newNode->next = NULL;
	if(*head == NULL){
		*head = newNode;
	}
	else{
		Node* trav;
		for(trav = *head; trav->next!=NULL; trav = trav->next){}
		trav->next = newNode;
	}
}



void display(Node* disp){
	Node* trav = disp->head;
	printf("------------------RECORDS--------------------------\n");
	for(; trav!=NULL; trav = trav->next){
		printf("[%s], [%d], [%d]\n", trav->data.name, trav->data.idNum, trav->data.age);
	}
	

}

int main(){
	Node mainNode;
	mainNode.head = NULL;
	
	info data[] = {
	{"Lebron James", 16101623, 24}, 
	{"Kobe Bryant", 19103080, 23}, 
	{"Max Verstappen", 222111333, 58}, 
	{"Nice User", 3136132, 20},
	};
	int dataCount = sizeof(data) / sizeof(data[0]);
	
	int a;
	for(a=0; a<dataCount; a++){
		//insertFirst(&mainNode, data[a]);
		insertLast(&mainNode.head, data[a]);
	}
	display(&mainNode);
	
}

