#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE     0xC    //size of Virtual Heap
#define OPEN_DSIZE  0xA    //size of Open Hash Table
#define CLOSE_DSIZE 0xC    //size of Close Hash Table
#define LIST_SIZE   0xF    //size of the array implementation of List

/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {
    char name[24];          // Chocolate name
    int  weight;            // Chocolate weight in grams
} chocoDesc;

typedef struct {
    char prodID[8];         //  product ID uniquely identifies the products; EMPTY or DELETED
    chocoDesc prodDesc;     //  product description
    float prodPrice;        //  product price
    int prodQty;            //  product count or quantity
} product;                  //  product record

typedef struct {
    product elem;
    int next;
} prodNode;                 // Product node, used in cursor-based implementation of Set

/************************
 * Virtual Heap         *
 ************************/
typedef struct {
    prodNode VH_node[VH_SIZE];
    int avail;
} VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
    int elemIndex;        // index of the 1st element in the set
    int count;            // holds the actual number of elements in the set
    VHeap *VHptr;         // holds the pointer to the virtual heap
} cursorSet;

/********************************************
 * Open Hashing Implementation of Dictionary*
 ********************************************/
typedef struct {
    int header[OPEN_DSIZE];  // array of sets
    int count;               // total number of elements in the dictionary
    VHeap *dicVHptr;         // holds the pointer to the virtual heap
} openDic;

/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY   "empty"     // stored in product ID field
#define DELETED  "del"      // stored in product ID field

typedef product closeDic[CLOSE_DSIZE];   //Definition of the closed hash dictionary

typedef struct {
    product prod[LIST_SIZE];
    int last;   //index of the last element; -1 if list is empty
} List;

/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void initVHeap(VHeap *VH);
cursorSet initCursorSet(VHeap *VH);
void displayVHeap(VHeap V);
void displaySet(cursorSet A);

//---Problem #2 ---
int mallocInVHeap(VHeap *VH);
void insertSorted(cursorSet *A, product P);
void populateSet(cursorSet *A);

//---Problem #3 ---
int openHash(char *IDen);
openDic initOpenDict(VHeap *VH);
openDic convertToOpenDict(cursorSet *A);
void displayOpenDict(openDic D);

//---Problem #4 ---
void freeInVHeap(VHeap *VH, int ndx);
void deleteDict(openDic *D, char *IDen);

//---Problem #5 ---
int closeHash(char *ID);
void initCloseDict(closeDic CD);
closeDic *convertToCloseDict(openDic *D);
void displayCloseDict(closeDic CD);

/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *
 *   3)  Write your answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *                                                                                  *
 ***********************************************************************************/
int main() {
    /*---------------------------------------------------------------------------------
     * 	Problem #1 ::  1) Initializes the virtual heap and the cursor Set             *
     *                 2) Displays the contents  virtual heap and cursor Set          *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #1:: ");
    printf("\n------------");
   	VHeap V;
	cursorSet cursor;
	initVHeap(&V);
	displayVHeap(V);
	cursor = initCursorSet(&V);

    /*---------------------------------------------------------------------------------
     * 	Problem #2 ::  1) Populates the Cursor set which is sorted in ascending order *
     *                    according to ID                                             *
     *                 2) Displays the Cursor set                                     *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #2:: ");
    printf("\n------------");
	populateSet(&cursor);
	displaySet(cursor);
    /*---------------------------------------------------------------------------------
     * 	Problem #3 ::  1) Converts the Cursor set into an Open Hash Dictionary        *
     *                 2) Displays the Open Hash Dictionary                           *
     *                 3) Displays the empty Cursor set.                              *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #3:: ");
    printf("\n------------");
    openDic op;
    op = convertToOpenDict(&cursor);
	displayOpenDict(op);
	displaySet(cursor);
	
    /*---------------------------------------------------------------------------------
     * 	Problem #4 ::  1) Perform 3 delete operations on the Open Hash Dictionary     *
     *                 2) Displays the Open Hash Dictionary                           *
     *                 3) Displays the Virtual Heap                                   *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #4:: ");
    printf("\n------------");
    char delete01[] = "1703";
    char delete02[] = "1358";
    char delete03[] = "1601";
 	deleteDict(&op, delete01);
 	deleteDict(&op, delete02);
 	deleteDict(&op, delete03);
 	displayOpenDict(op);
 	displayVHeap(V);

    /*------------------------------------------------------------------------------------
     * 	Problem #5 :: 1) Converts the Open Hash Dictionary into a Closed Hash Dictionary *
     *                2) Displays the Closed Hash Dictionary                             *
     *                3) Displays the virtual heap                                       *
     *---------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #5:: ");
    printf("\n------------");
    closeDic * CD;
    CD = convertToCloseDict(&op);
    displayCloseDict(*CD) ;

  
    return 0;
}

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
 void pause() {
    printf("\n\nPress any key to continue...\n");
    getchar();
    system("clear");
}

void initVHeap(VHeap *V) {
	int a;
	for(a=0; a<VH_SIZE; a++){
		strcpy(V->VH_node[a].elem.prodID, "    ");
		V->VH_node[a].next = a - 1;
	}
	V->avail = VH_SIZE - 1;
}

cursorSet initCursorSet(VHeap *VH) {
   return (cursorSet) {-1, 0, VH};
}

void displayVHeap(VHeap V) {
    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", V.avail);
    printf("\nVHeap Address    ::  %p", V.VH_node);
    printf("\n\n%10s", "Index");
    printf("%10s", "Prod ID");
    printf("%15s", "Next Field");
    printf("\n%10s%10s%15s", "-----", "-------", "----------");
  
  	int a;
  	for(a=0; a<VH_SIZE; a++){
  		printf("\n%8d\t%s\t%7d", a, V.VH_node[a].elem.prodID, V.VH_node[a].next);
	  }	
  
    printf("\n\n");
    pause();
}

void displaySet(cursorSet A) {
    printf("\n\nDetails of the Set :: ");
    printf("\n---------------------");
    printf("\nNo. of elements ::  %d", A.count);
    printf("\n\n%-7s", "ID");
    printf("%-12s", "Choco Name");
    printf("%-15s", "Choco Weight");
    printf("%-10s", "VHeap Index");
    printf("\n%-7s%-12s%-15s%-10s", "--", "----------", "------------", "-----------");
     int i;
    
    for(i=A.elemIndex; i!=-1; i = A.VHptr->VH_node[i].next){
    	printf("\n%5s%10s%13d%8d", A.VHptr->VH_node[i].elem.prodID, A.VHptr->VH_node[i].elem.prodDesc.name,  A.VHptr->VH_node[i].elem.prodDesc.weight, i);
	}
 
    printf("\n\n");
    pause();
}

/************************************************************
 *  Problem 2:: Function Definitions                         *
 ************************************************************/
int mallocInVHeap(VHeap *VH) {
 	int index = VH->avail;
 	if(index!=-1){
 		VH->avail = VH->VH_node[index].next;
	 }
	 return index;
}

void insertSorted(cursorSet *A, product P) {
  	if(A->count < VH_SIZE){
  		int *x;
  		for(x=&A->elemIndex; *x!=-1 && strcmp(A->VHptr->VH_node[*x].elem.prodID, P.prodID)<0; x = &A->VHptr->VH_node[*x].next){}
  			if(strcmp(A->VHptr->VH_node[*x].elem.prodID, P.prodID) == 0){
  				printf("\nProduct with ID: %s already exists in the set.", P.prodID);
		 	 }
		 	 else{
		 	 	int Nnode = mallocInVHeap(A->VHptr);
		 	 		if(Nnode!=-1){
		 	 			A->count++;
		 	 			A->VHptr->VH_node[Nnode].elem = P;
		 	 			A->VHptr->VH_node[Nnode].next = *x;
		 	 			*x = Nnode;
					  }
			  }
		  }
	else{
	  printf("\nNo available space. Product with ID: %s cannot be inserted", P.prodID);	
	}
	  
}

void populateSet(cursorSet *A) {
    const int COUNT = 15;
    product data[] = {{"1701", {"Toblerone", 135}, 150.75, 20},
                      {"1356", {"Ferrero", 200}, 250.75, 85},
                      {"1109", {"Patchi", 50}, 99.75, 35},
                      {"1550", {"Cadbury", 120}, 200.00, 30},
                      {"1807", {"Mars", 100}, 150.75, 20},
                      {"1201", {"Kitkat", 50}, 97.75, 40},
                      {"1450", {"Ferrero", 100}, 150.50, 50},
                      {"1701", {"Toblerone", 50}, 90.75, 80},
                      {"1601", {"Meiji", 75}, 75.50, 60},
                      {"1310", {"Nestle", 100}, 124.50, 70},
                      {"1807", {"Valor", 120}, 149.50, 90},
                      {"1455", {"Tango", 75}, 49.50, 100},
                      {"1703", {"Toblerone", 100}, 125.75, 60},
                      {"1284", {"Lindt", 100}, 250.75, 15},
                      {"1688", {"Guylian", 50}, 99.75, 35},
    };
	
	int a;
	for(a=0; a<COUNT; a++){
		insertSorted(A, data[a]);
	}
 
}

/************************************************************
 *  Problem 3:: Function Definitions                        *
 ************************************************************/
int openHash(char *prodID) {
    // Sample hashing function
    int a, value = 0;
    for(a=0; prodID[a]!='\0'; a++){
    	if(prodID[a]>='0' || prodID[a]<='9'){
    		value += prodID[a]-'0';
		}
	}
	int hashVal = value % OPEN_DSIZE;
	return hashVal;

}

openDic initOpenDict(VHeap *VH) {
  int a;
  openDic op;
  op.count = 0;
  op.dicVHptr = VH;
  for(a=0; a<OPEN_DSIZE; a++){
  		op.header[a] = -1;	
  }
  return op;
}

openDic convertToOpenDict(cursorSet *A) {
  		openDic op  = initOpenDict(A->VHptr);
  		int a;
  		for(a=0; a<VH_SIZE; a++){
  			  int hashVal = openHash(A->VHptr->VH_node[a].elem.prodID);
  			  int *trav;
  			for(trav = &op.header[hashVal]; *trav!=-1 && strcmp(A->VHptr->VH_node[a].elem.prodID, A->VHptr->VH_node[*trav].elem.prodID) > 0; trav = &op.dicVHptr->VH_node[*trav].next){}
				if(*trav == -1 || strcmp(A->VHptr->VH_node[a].elem.prodID, A->VHptr->VH_node[*trav].elem.prodID) != 0){
					A->VHptr->VH_node[a].next = *trav;
					*trav = a; 
					op.count++;
					A->count--;
				}  
			}
			A->elemIndex = -1;
			return op; 
 }
		

void displayOpenDict(openDic D) {
    printf("\n\nDetails of the Open Hash Dictionary:: ");
    printf("\n-------------------------------------");
    printf("\nNo. of elements :: %d", D.count);
    printf("\n\n%-7s", "GROUPS");
    printf("%15s", "ID Numbers");
    printf("\n%-7s%15s", "------", "----------");
     int i,j;
 	
 	for(i=0; i<OPEN_DSIZE; i++){
 			printf("\nGroup:[%d]::", i);
 		for(j = D.header[i]; j!=-1; j = D.dicVHptr->VH_node[j].next)
 				printf("%7s\t", D.dicVHptr->VH_node[j].elem.prodID);
	
 	
	 }
    printf("\n\n");
}

/************************************************************
 *  Problem 4:: Function Definitions                        *
 ************************************************************/
void freeInVHeap(VHeap *VH, int ndx) {
    // Just marking the node as deleted by setting its next pointer to -1
    VH->VH_node[ndx].next = -1;
    if(ndx > -1 && ndx < VH_SIZE){
    	strcpy(VH->VH_node[ndx].elem.prodID, "    ");
    	VH->avail = VH->VH_node[ndx].next;
    	VH->avail = ndx;
	}

}

void deleteDict(openDic *D, char *IDen) {
    int hashVal = openHash(IDen);
    int *trav;
    for(trav = &D->header[hashVal]; *trav!=-1 && strcmp(D->dicVHptr->VH_node[*trav].elem.prodID, IDen) !=0; trav = &D->dicVHptr->VH_node[*trav].next){
	}
	if(*trav!=-1){
	int temp = *trav;
	*trav = D->dicVHptr->VH_node[temp].next;
	freeInVHeap(D->dicVHptr,temp);
	}

}

/************************************************************
 *  Problem 5:: Function Definitions                        *
 ************************************************************/
int closeHash(char *ID) {
	int a, value = 0;
	for(a=0; ID[a]!='\0';  a++){
		if(ID[a]>='0' || ID[a]<='9'){
			value += ID[a]- '0';
		}
	}

	return (value % CLOSE_DSIZE);

}


void initCloseDict(closeDic CD) {
	int a;
	for(a=0; a<CLOSE_DSIZE; a++){
		strcpy(CD[a].prodID, EMPTY);
		strcpy(CD[a].prodDesc.name, "    ");
	}
}

closeDic *convertToCloseDict(openDic *D) {
   List newList;
   closeDic *newCloseDic = (closeDic*)malloc(sizeof(closeDic));
   newList.last = -1;
   int a, b, hashVal;
   if(newCloseDic!=NULL){
   	initCloseDict(*newCloseDic);
   		int *trav, temp;
   		for(a=0; a<OPEN_DSIZE; a++){
   		for(trav = &D->header[a]; *trav!=-1;){
   			hashVal = closeHash(D->dicVHptr->VH_node[*trav].elem.prodID);
   			temp = *trav;
   			if((strcmp((*newCloseDic)[hashVal].prodID, EMPTY))==0){
   				(*newCloseDic)[hashVal] = D->dicVHptr->VH_node[*trav].elem;
			   }
			   else{
			   	if(newList.last < LIST_SIZE){
			   			newList.prod[newList.last++] = D->dicVHptr->VH_node[*trav].elem;
				   }
			   }
			   D->count--;
			   *trav = D->dicVHptr->VH_node[temp].next;
			   freeInVHeap(D->dicVHptr, temp);
		   }
		}
		   for(a=0; a <= newList.last; a++){
		   		hashVal = closeHash(newList.prod[a].prodID);
		   		for(b = 0; b < CLOSE_DSIZE && strcmp((*newCloseDic)[hashVal].prodID, EMPTY) != 0 && strcmp((*newCloseDic)[hashVal].prodID, DELETED) !=0; hashVal = (hashVal + 1) % CLOSE_DSIZE, b++){}
				  	if(b < CLOSE_DSIZE){
				  		(*newCloseDic)[hashVal] = newList.prod[a];
					  }
				   }
		   }
		   return newCloseDic;
   }
   


void displayCloseDict(closeDic CD) {
  	int x;
 	
	printf("\n\nDetails of Closed Hash Dictionary :: ");
	printf("\n-------------------------------------");
	printf("\n\n%-6s", "Index");
	printf("%-10s", "ChocoID");
	printf("%-15s", "Choco Name");
	printf("\n%-6s%-10s%-15s", "-----", "-------", "----------"); 
	
	//Write your code here
	for(x = 0; x<CLOSE_DSIZE; x++){
		printf("\n%2d%10s%13s", x, CD[x].prodID, CD[x].prodDesc.name);
	}
    printf("\n\n");
}


