#include <stdio.h>
#include <stdlib.h>
#include "TREES.h"

void add(NodePtr* Tree, Product prod){
	NodePtr* Trav;
	NodePtr nNode = (NodePtr)calloc(1, sizeof(NodeType));
	for(Trav = Tree; *Trav!=NULL && strcmp((*Trav)->item.prodName, prod.prodName) != 0;){
		int cmp = strcmp((*Trav)->item.prodName, prod.prodName);
		Trav = (cmp < 0) ? &(*Trav)->Left : &(*Trav)->Right;
	}
	if (*Trav == NULL){
		*Trav = nNode;
		nNode->item = prod;
		nNode->Left = nNode->Right = NULL;
	}
	else{
		printf("Exit, Item Exists\n");
	}
	
}


void display(NodePtr Tree) {
    if (Tree != NULL) {
        display(Tree->Left);            
        printf("\n%s\t\t", Tree->item.prodName);  
        printf("%.2f\t\t    ", Tree->item.prodPrice);     
        printf("%d\t\t", Tree->item.prodQty);       
        printf("\t%d-%d-%d\t", Tree->item.expDate.day, Tree->item.expDate.month, Tree->item.expDate.year); 
        display(Tree->Right);          
    }
}
void deleteNode(NodePtr *Tree, Product prod){
	
}
NodeType member(NodePtr Tree, Product prod){
	
}




