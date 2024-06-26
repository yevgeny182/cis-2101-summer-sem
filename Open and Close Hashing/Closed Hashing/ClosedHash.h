#ifndef Closed
#define Closed

#define SIZE 10
#define THRESHOLD 0.65
#define EMPTY ((nPtr)-1)
#define DELETED ((nPtr)-2)

typedef struct {
    char LN[16], FN[24];
    char address[50];
} nameType;

typedef struct node {
    nameType person;
} nodeType, *nPtr;

typedef struct {
    nPtr *table;
    int size;
    int count;
} Dictionary;

int hashVal(char* LN, int size);
void init(Dictionary *D, int size);
void resize(Dictionary *D);
void insert(Dictionary *D, nameType person);
void display(Dictionary *D);
void deleteRec(Dictionary *D, nameType person);


#endif

