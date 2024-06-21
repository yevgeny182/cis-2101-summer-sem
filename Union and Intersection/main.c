#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SET A; 
    SET B;
    int elems, elems2;

    SET* unionSet, *diffSet, *intersectionSet;
    Initialize(A);
    Initialize(B);
  
    AddElement(A, 6);
     AddElement(A, 3);
      AddElement(A, 7);
       AddElement(A, 2);
       
       
	AddElement(B, 3);
	AddElement(B, 4);
	AddElement(B, 2);
	AddElement(B, 6);

    unionSet = UnionSet(A,B);
    diffSet = DifferenceSet(A, B);
    intersectionSet = IntersectionSet(A, B);
    
	printf("Set A ");
    DisplaySet(A);
    
    printf("Set B ");
    DisplaySet(B);
    
    printf("\n");
    //union
    printf("Union");
    DisplaySet(*unionSet);
    
    //intersection
    printf("Intersection");
    DisplaySet(*intersectionSet);
    
    //difference
     printf("Difference");
    DisplaySet(*diffSet);

    return 0;

	
	
}
