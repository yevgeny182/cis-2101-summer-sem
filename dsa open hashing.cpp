#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Max size of the dictionary

typedef struct node {
    int elem;
    struct node *next;
} *SET;

typedef SET Dict[MAX];
typedef enum { FALSE, TRUE  } Boolean;

void InitDictionary(Dict dictionary) {
    int i;
    for (i = 0; i < MAX; i++) {
        dictionary[i] = NULL;
    }
}

void displayDictionary(Dict dictionary) {
    int i;
	SET Trav;
    printf("Dictionary Contents:\n");
    for (i = 0; i < MAX; i++) {
        SET current = dictionary[i];
        printf("%d\t", i);
        
        if(current == NULL){
        	printf("\n");
		}
		
		else {
   		 for (Trav = current; Trav != NULL ; Trav = Trav->next) {
        printf("%d", Trav->elem);
           if(Trav->next != NULL){
           	 printf(", ");
		   }
		}
		 printf("\n");
		}
    }
   
}

int hash(int elem) {
    return elem % MAX;
}

Boolean isMember(Dict dictionary, int elem) {
    int index = hash(elem);
    SET current = dictionary[index];
    SET Trav;
    for (Trav = current; Trav != NULL && Trav->elem != elem;  Trav = Trav->next) {}
    return Trav != NULL ? TRUE : FALSE;
}

void insert(Dict dictionary, int elem) {
    int index = hash(elem);
    SET newNode = (SET)malloc(sizeof(struct node));
    newNode->elem = elem;
    newNode->next = dictionary[index];
    dictionary[index] = newNode;
}


void DeleteNode(Dict D, int num){
			int index  = hash(num);
			SET *trav2;
			SET temp;
			
			for(trav2 = &D[index]; *trav2 != NULL && (*trav2)->elem != num; trav2 = &(*trav2)->next){}
			
			if(*trav2 != NULL){
				temp = *trav2;
				*trav2 = temp->next;
				free(temp);
			}
}


int main() {
    Dict dictionary;
    InitDictionary(dictionary);
	insert(dictionary, 20);	
	insert(dictionary, 21);	
	insert(dictionary, 22);
	insert(dictionary, 23);
	insert(dictionary, 24);
	insert(dictionary, 10);
	insert(dictionary, 15);


 	

    printf("After insertions:\n");
    displayDictionary(dictionary);


	if(isMember(dictionary, 20)){
		printf("data is a member of a dictionary\n");
	}
	else{
		printf("data is not a member of a dictionary\n");
	}
		DeleteNode(dictionary, 15);
		DeleteNode(dictionary, 20);
		DeleteNode(dictionary, 21);
		displayDictionary(dictionary);
    return 0;
}
