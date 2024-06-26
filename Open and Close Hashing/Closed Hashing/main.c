#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClosedHash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary mainDict;
	init(&mainDict, SIZE);
	int a;
	nameType name[]={
		{"Abad", "Toring", "Macao, China"},
		{"Arreglo", "Eugene", "Shenzen, China"},
		{"Albano", "Yevgeny", "520, NewPort LN. Lousiana"},	
		{"Pino", "Mike", "Cabancalan, Mandaue"},
		{"Zulu", "Try", "Talamban, Cebu"},	
		{"James", "Lebron", "Akron, Ohio"},
		{"Jumawan", "Kendrick", "Subangdaku, Mandaue"},		
	};
	int dataCount = sizeof(name) / sizeof(name[0]);

	for(a=0; a<dataCount; a++){
		insert(&mainDict, name[a]);
	}
	display(&mainDict);
	return 0;
}
