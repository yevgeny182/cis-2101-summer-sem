#include <stdio.h>
#include <stdlib.h>
#include "TREES.h"

void add(NodePtr* Tree, Product prod){
	NodePtr* Trav;
	int count;
	NodePtr nNode = (NodePtr)calloc(1, sizeof(NodeType));
	for(Trav = Tree; *Trav!=NULL && strcmp((*Trav)->item.prodName, prod.prodName) != 0;){
		Trav = strcmp(prod.prodName, (*Trav)->item.prodName) < 0 ? &(*Trav)->Left : &(*Trav)->Right;
	}
	if (*Trav == NULL){
		*Trav = nNode;
		nNode->item = prod;
		nNode->Left = nNode->Right = NULL;
	}
	else{
		printf("Duplicate records are not allowed!\nDuplicate record of [%s] found!\n", prod.prodName);	
	}
	
}


void inOrder(NodePtr Tree) {
    if (Tree != NULL) {
        inOrder(Tree->Left);            
        printf("\n%-10s\t\t", Tree->item.prodName);  
        printf("%.2f\t%-10s", Tree->item.prodPrice, "");     
        printf("%-d\t\t%-3s", Tree->item.prodQty, "");       
        printf(" %d-%d-%d\t", Tree->item.expDate.day, Tree->item.expDate.month, Tree->item.expDate.year); 
        inOrder(Tree->Right);          
    }
}
void preOrder(NodePtr Tree){
	if(Tree!=NULL){
        printf("\n%-10s\t\t", Tree->item.prodName);  
        printf("%.2f\t%-10s", Tree->item.prodPrice, "");     
        printf("%-d\t\t%-3s", Tree->item.prodQty, "");       
        printf(" %d-%d-%d\t", Tree->item.expDate.day, Tree->item.expDate.month, Tree->item.expDate.year); 
        preOrder(Tree->Left); 
        preOrder(Tree->Right);      
	}
}
void postOrder(NodePtr Tree){
	if(Tree!=NULL){
		postOrder(Tree->Left); 
        postOrder(Tree->Right);    
        printf("\n%-10s\t\t", Tree->item.prodName);  
        printf("%.2f\t%-10s", Tree->item.prodPrice, "");     
        printf("%-d\t\t%-3s", Tree->item.prodQty, "");       
        printf(" %d-%d-%d\t", Tree->item.expDate.day, Tree->item.expDate.month, Tree->item.expDate.year); 
	}
}

void deleteNode(NodePtr *Tree, Product prod){
	NodePtr *Trav, temp, *Trav2;
	for(Trav = Tree; *Trav!=NULL && strcmp((*Trav)->item.prodName, prod.prodName) != 0;){
		Trav = strcmp(prod.prodName, (*Trav)->item.prodName) < 0? &(*Trav)->Left : &(*Trav)->Right;
	}
	if(*Trav != NULL){
		if((*Trav)->Left == NULL){
			printf("\n[%s] is at the RIGHT and is now removed\n\n", prod.prodName);
			temp = *Trav;
			*Trav = temp->Right;
			free(temp);
		}
		else if((*Trav)->Right == NULL){
			printf("\n[%s] is at the LEFT and is now removed\n\n", prod.prodName);
			temp = *Trav;
			*Trav = temp->Left;
			free(temp);
		}
		else{
			printf("\n[%s] is a PARENT node now removed\n\n", prod.prodName);
			for(Trav2 = &(*Trav)->Right; (*Trav2)->Left != NULL; Trav2 = &(*Trav)->Left){}
			temp = *Trav2;
			*Trav2 = temp->Right;
			(*Trav)->item = temp->item;
			free(temp);
		}
	}	
}
/*
int member(NodePtr Tree, Product prod){
	NodePtr trav;
	for(trav = Tree; trav!=NULL && strcmp(trav->item.prodName, prod.prodName) !=0; ){
		trav = strcmp(trav->item.prodName, prod.prodName) < 0 ? trav->Left : trav->Right;
	}
	return trav == NULL ? 0 : 1;
}
*/

//queue

Queue* initQueue(){
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	Q->front = Q->rear = NULL;
	return Q;
}

void enqueue(Queue* q, NodePtr treeNode){
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->treeNode = treeNode;
	temp->next = NULL;
	if(q->rear != NULL){
		q->rear->next = temp;
		q->rear = temp;
	}
	else{
		q->front = q->rear = temp;
	}
}
NodePtr dequeue(Queue* q){
		QNode* temp = q->front;
		NodePtr treeNode = temp->treeNode;
		q->front = q->front->next;
		
		if(q->front == NULL){
			q->rear = NULL;
		}
	
	free(temp);
	return treeNode;
}

void bfs(NodePtr Tree){
	if(Tree == NULL){
		return;
	}
	Queue* newQueue = initQueue();
	enqueue(newQueue, Tree);
	while(newQueue->front != NULL){
		NodePtr current = dequeue(newQueue);
		printf("\n%-10s\t\t", current->item.prodName);  
        printf("%.2f\t%-10s", current->item.prodPrice, "");     
        printf("%-d\t\t%-3s", current->item.prodQty, "");       
        printf(" %d-%d-%d\t", current->item.expDate.day, current->item.expDate.month, current->item.expDate.year);
        if(current->Left != NULL){
        	enqueue(newQueue, current->Left);
		}
		if(current->Right != NULL){
			enqueue(newQueue, current->Right);
		}
		
	}
	
	while(newQueue->front != NULL){
		dequeue(newQueue);
	}
}



