#include <stdio.h>
#include <stdlib.h>
#include "OpenHash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary mainDict;
	init(mainDict);
	int a, deleteIndex;
	nameType name[]={
		//delete according to record
		{"Arreglo", "Eugene", "Shenzen, China"}, //1
		{"Albano", "Yevgeny", "520, NewPort LN. Lousiana"},	//2
		{"Pino", "Mike", "Cabancalan, Mandaue"}, //3
		{"Kilo", "Terry", "Cabancalan, Mandaue"},	//4	
	};

	int dataCount = sizeof(name) / sizeof(name[0]);
	
	for(a=0; a<dataCount; a++){
		insert(mainDict, name[a]);
	}
	display(mainDict);
	
	
	printf("\n");
	printf("Enter record to Delete: ");
	scanf("%d", &deleteIndex);
	if(deleteIndex >= 0 && deleteIndex < dataCount){
		deleteRec(mainDict, name[deleteIndex]);
	}else{
		printf("Cannot delete record!\n");
	}

	
	printf("Deleting a record \n");
	display(mainDict);
	return 0;
}
