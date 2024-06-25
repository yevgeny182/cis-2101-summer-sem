#include "OpenHash.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void init(Dictionary D){
	int a;
	for(a=0; a<SIZE; a++){
		D[a] = NULL;
	}
	
}
void insert(Dictionary D, nameType person){
	nPtr* trav, temp;
	int hash = hashVal(person.LN);
	if (hash < 0 || hash >= SIZE) {
		Dictionary newDict;
        printf("Error: Hash value (%d) is out of bounds for the hash table size.\n", hash);
        return; 
    }
	if(D[hash] == NULL){
		D[hash] = (nPtr)malloc(sizeof(nodeType));
		D[hash]->person = person;
		D[hash]->next = NULL;
	}else{

		for(trav = &D[hash]; *trav!=NULL && strcmp((*trav)->person.LN, person.LN) < 0; trav = &(*trav)->next){}
		temp = (nPtr)malloc(sizeof(nodeType));
			if(temp!=NULL){
				temp->person = person;
				temp->next = D[hash];
				D[hash] = temp;
			}
	}
}
	/*
Dictionary resizeDictionary(Dictionary oldDict) {
    int newSize = 2 * SIZE; 
    Dictionary newDict = malloc(newSize * sizeof(nodeType)); 


    memset(newDict, 0, newSize * sizeof(nodeType)); 
	int i;
    for ( i = 0; i < SIZE; i++) { 
        nPtr trav = oldDict[i];
        while (trav!= NULL) {
            int newIndex = hashVal(trav->person.LN) % newSize; 
            if (newIndex < 0) newIndex += newSize; 
            if (newDict[newIndex] == NULL) {
                newDict[newIndex] = trav;
            } else {
                nPtr temp = newDict[newIndex];
                while (temp->next!= NULL && strcmp(temp->person.LN, trav->person.LN) < 0) {
                    temp = temp->next;
                }
                trav->next = newDict[newIndex];
                newDict[newIndex] = trav;
            }
            trav = trav->next;
        }
    }


    return newDict; 
}
  */

int hashVal(char* LN) {
	/*
    int hash = 0;
    int a;
    for ( a = 0; LN[a]!= '\0'; a++) {
        hash += LN[a];
    }
    return hash % SIZE; 
    */
    return LN[0] - 'A';
}

void display(Dictionary D){
	nPtr temp;
	int a;
	printf("Open Hashing\n");
	for(a=0; a<SIZE; a++){
		printf("[%d]", a);
		temp = D[a];
		for(; temp!=NULL; temp=temp->next){
			printf("%s, %s, %s || ", temp->person.LN, temp->person.FN, temp->person.address);
		}
			if(temp == NULL){
				printf(" ->NULL");
			}else{
				int hash = hashVal(temp->person.LN);
			
				
			}
			printf("\n");
	}

}
void deleteRec(Dictionary D, nameType person){
	nPtr temp, *trav;
}



