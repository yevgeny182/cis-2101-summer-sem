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

typedef struct QNode{
	NodePtr treeNode;
	struct QNode * next;
}QNode;

typedef struct Queue{
	QNode* front;
	QNode* rear;
}Queue;

void add(NodePtr* Tree, Product prod);
void inOrder(NodePtr Tree);
void preOrder(NodePtr Tree);
void postOrder(NodePtr Tree);
void deleteNode(NodePtr *Tree, Product prod);
int member(NodePtr Tree, Product prod);

//queue

Queue* initQueue();
void enqueue(Queue* q, NodePtr treeNode);
NodePtr dequeue(Queue* q);
void bfs(NodePtr Tree);
#endif
