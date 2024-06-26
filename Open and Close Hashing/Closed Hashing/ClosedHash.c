#include "ClosedHash.h"
#include<stdlib.h>
#include<stdio.h>

int hashVal(char* LN, int size) {
    return (LN[0] - 'A') % size;
}
void init(Dictionary *D, int size) {
    int a;
    D->table = (nPtr *)malloc(size * sizeof(nPtr));
    for (a = 0; a < size; a++) {
        D->table[a] = EMPTY;
    }
    D->size = size;
    D->count = 0;
}
void resize(Dictionary *D) {
    int newSize = D->size * 2;
    int a;
    nPtr *newTable = (nPtr *)malloc(sizeof(nPtr) * newSize);
    for (a = 0; a < newSize; a++) {
        newTable[a] = EMPTY;
    }

    for (a = 0; a < D->size && D->table[a] != EMPTY && D->table[a] != DELETED; a++) {
            int hash = hashVal(D->table[a]->person.LN, newSize);
            int originalHash = hash;
            while (newTable[hash] != EMPTY) {
                hash = (hash + 1) % newSize;
                if (hash == originalHash) {
                    printf("Error: Resizing failed\n");
                    exit(0);
                }
            }
            newTable[hash] = D->table[a];
    }

    free(D->table);
    D->table = newTable;
    D->size = newSize;
}

void insert(Dictionary *D, nameType person){
	if((float)D->count / D->size > THRESHOLD){
		resize(D);
	}
	int hash = hashVal(person.LN, D->size);
	int origHash = hash;
	for(; D->table[hash]!=EMPTY && D->table[hash]!=DELETED; ){
		hash = (hash + 1) % D->size;
		if(hash == origHash){
			printf("Cannot insert %s record\n", person.LN);
		}
	}
	D->table[hash] = (nPtr)malloc(sizeof(nodeType));
	if(D->table[hash] != NULL){
		D->table[hash]->person = person;
		D->count++;
	}

}
void display(Dictionary *D){
	printf("Closed Hashing\n");
    int a;
    for ( a = 0; a < D->size; a++) {
        printf("[%d]", a);
        if (D->table[a] == EMPTY) {
            printf(" -> EMPTY");
        } else if (D->table[a] == DELETED) {
            printf(" -> DELETED");
        } else {
            printf(" %s, %s, %s", D->table[a]->person.LN, D->table[a]->person.FN, D->table[a]->person.address);
        }
        printf("\n");
    }
}
void deleteRec(Dictionary *D, nameType person){
	 int hash = hashVal(person.LN, D->size);
    int originalHash = hash;
    for (; D->table[hash] != EMPTY && D->table[hash] != DELETED && strcmp(D->table[hash]->person.LN, person.LN) == 0;) {
            free(D->table[hash]);
            D->table[hash] = DELETED;
            D->count--;
        hash = (hash + 1) % D->size;
    }
}
