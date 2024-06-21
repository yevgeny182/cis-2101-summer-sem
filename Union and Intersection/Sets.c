#include "Sets.h"
#include<stdio.h>
#include<stdlib.h>

void AddElement(SET add, int element){
	if(element >= 0 && element < MAX){
		add[element] = 1;
	}
}
void DisplaySet(SET set){
	int a;
	for(a=0; a<MAX; a++){
		printf("| %d  ", set[a]);
	}
	printf("\n");
}
void DeleteElement(SET del , int element){
	 if(element >= 0 && element < MAX){
        del[element] = 0;
    }
}
void Initialize(SET set){
	int a;
	for(a=0; a<MAX; a++){
		set[a] = 0;
	}
}

//Operations
SET * UnionSet(SET A , SET B){
		SET * newSet = (SET *)malloc(sizeof(SET));
		int i;
		if(newSet != NULL){
				for(i=0; i<MAX; i++){
				(*newSet)[i] = A[i] || B[i];
				}
		}
		
		return newSet;
}
SET * IntersectionSet(SET A , SET B){
		SET * newSet = (SET *)malloc(sizeof(SET));
		int i;
		if(newSet != NULL){
				for(i=0; i<MAX; i++){
				(*newSet)[i] = A[i] && B[i];
			}
		}
		return newSet;
}
SET * DifferenceSet(SET A , SET B){
		SET * newSet = (SET *)malloc(sizeof(SET));
		int i;
		if(newSet != NULL){
				for(i=0; i<MAX; i++){
				(*newSet)[i] = A[i] && !B[i];
				}
		}
		return newSet;
}
