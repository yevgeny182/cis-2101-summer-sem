#ifndef OpenHash
#define OpenHash
#define SIZE 10

typedef struct{
	char LN[16], FN[24];
	char address[50];
}nameType;


typedef struct node{
	nameType person;
	struct node *next;
}nodeType, *nPtr;

typedef nPtr Dictionary[SIZE];
typedef enum{TRUE,FALSE}Boolean;


void init(Dictionary D);
void insert(Dictionary D, nameType person);
int hash(char LN[]);
void display(Dictionary D);
void deleteRec(Dictionary D, nameType person);
//Dictionary resizeDictionary(Dictionary oldDict);


#endif

