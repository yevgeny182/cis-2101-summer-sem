#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Max size of the dictionary

typedef struct node {
    int elem;
    struct node *next;
} *SET;

typedef SET Dict[MAX];
typedef enum { TRUE, FALSE } Boolean;

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
   		 for (Trav = current; current != NULL ; current = current->next) {
        printf("%d", current->elem);
           if(current->next != NULL){
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
    for (Trav = current; current != NULL && current->elem == elem;  current = current->next) { }
    return current != NULL ? TRUE : FALSE;
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
			SET CurrentData = D[index];
			SET Trav, Prev = NULL;

			for(Trav = CurrentData; Trav!=NULL && Trav->elem != num; Trav = Trav->next){
				Prev = CurrentData;
			}
			if(Trav == NULL){
			return;
				}
			if(Prev == NULL){
			D[index] = Trav->next;
			}
				else{
					Prev->next = Trav->next;
				}
			free(Trav);
}


int main() {
    Dict dictionary;
    InitDictionary(dictionary);
	insert(dictionary, 20);	
	insert(dictionary, 21);	
	insert(dictionary, 22);
	insert(dictionary, 23);
	insert(dictionary, 24);
 
 	
	if(isMember(dictionary, 15)){
		printf("data is a member of a dictionary\n");
	}
	else{
		printf("data is not a member of a dictionary\n");
	}
    printf("After insertions:\n");
    displayDictionary(dictionary);


    //Delete(dictionary, 15);
	DeleteNode(dictionary, 15);
    printf("After deletion of 15:\n");
    displayDictionary(dictionary);

    return 0;
}

