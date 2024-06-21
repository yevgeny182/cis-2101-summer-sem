#ifndef Sets
#define Sets
#define MAX 8

typedef int SET[MAX];

void AddElement(SET P, int element);
void DisplaySet(SET set);
void DeleteElement(SET P , int element);
void Initialize(SET set);

//Operations
SET * UnionSet(SET A , SET B);
SET * IntersectionSet(SET A , SET B);
SET * DifferenceSet(SET A , SET B);







#endif
