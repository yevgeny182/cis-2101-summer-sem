#include <stdio.h>
#include <stdlib.h>
#include "OpenandClose.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary mainDict;
	init(mainDict);
	int a;
	nameType name[]={
		{"Arreglo", "Eugene", "Shenzen, China"},
		{"Albano", "Yevgeny", "520, NewPort LN. Lousiana"},	
		{"Pino", "Mike", "Cabancalan, Mandaue"},	
	};
	int dataCount = sizeof(name) / sizeof(name[0]);
	for(a=0; a<dataCount; a++){
		insert(mainDict, name[a]);
	}
	display(mainDict);
	return 0;
}
