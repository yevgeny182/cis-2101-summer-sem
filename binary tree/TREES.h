#ifndef TREES
#define TREES
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int day, month, year;
}Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
}Product;

typedef struct node{
    Product item;
    struct node *Left, *Right;
}NodeType, *NodePtr;

void add(NodePtr* Tree, Product prod);
void display(NodePtr Tree);
void deleteNode(NodePtr *Tree, Product prod);
NodeType member(NodePtr Tree, Product prod);


#endif
