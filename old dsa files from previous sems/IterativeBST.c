#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int data;
    struct cell* left;
    struct cell* right;
} * BST;

typedef struct StackNode {
    BST node;
    struct StackNode* next;
} StackNode;

StackNode* createStackNode(BST node) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

void push(StackNode** stack, BST node) {
    StackNode* stackNode = createStackNode(node);
    stackNode->next = *stack;
    *stack = stackNode;
}

BST pop(StackNode** stack) {
    if (*stack == NULL) {
        return NULL;
    }
    BST popped = (*stack)->node;
    StackNode* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return popped;
}
void insert(BST* T, int num) {
    if (*T == NULL) {
        *T = (BST)malloc(sizeof(struct cell));
        (*T)->data = num;
        (*T)->left = (*T)->right = NULL;
    } else if (num < (*T)->data) {
        insert(&(*T)->left, num);
    } else {
        insert(&(*T)->right, num);
    }
}

BST popList(int num[], int size) {
    BST root = NULL;
    int i;
    for (i = 0; i < size; i++) {
        insert(&root, num[i]);
    }
    return root;
}


void preorder(BST T) {
    if (T == NULL) {
        return;
    }

    StackNode* stack = NULL;
    BST current = T;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            printf("%d ", current->data);

            if (current->right != NULL) {
                push(&stack, current->right);
            }
            current = current->left;
        }
        current = pop(&stack);
    }
}


void inorder(BST T) {
    if (T == NULL) {
        return;
    }

    StackNode* stack = NULL;
    BST current = T;
    while (current != NULL || stack != NULL) {
        while (current != NULL) {

            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}


void postorder(BST T) {
    if (T == NULL) {
        return;
    }

    StackNode* stack1 = NULL;
    StackNode* stack2 = NULL;

    push(&stack1, T);
    while (stack1 != NULL) {

        BST current = pop(&stack1);
        push(&stack2, current);
        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }
    while (stack2 != NULL) {
        BST current = pop(&stack2);
        printf("%d ", current->data);
    }
}


int main() {
    int numbers[] = {12, 3, 9, 14, 8, 26, 4};
	int retVal, size = 7;
	BST b;
	b = popList(numbers, size);
	printf("pre order "); preorder(b); printf("\n");
	printf("in order "); inorder(b); printf("\n");
	printf("post order "); postorder(b); printf("\n");

 
    return 0;
}

