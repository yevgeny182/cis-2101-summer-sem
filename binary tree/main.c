#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	
	NodePtr mainNode = NULL;

	int a, deleteIndex;
	Product data[] = {
		    {"Pepsi", 210.00, 1, {12, 10, 2024}},
		    {"Coke", 200.00, 21, {11, 10, 2024}},
		    {"Kit Kat", 125.00, 50, {9, 30, 2024}},
		    {"Piattos", 85.00, 200, {12, 31, 2024}},
		    {"Piattos", 85.00, 200, {12, 31, 2024}},
	};
	
	int dataCount = sizeof(data) / sizeof(data[0]);
	for(a=0; a<dataCount; a++){
		add(&mainNode, data[a]);
	}
	printf("Product Name:\t Price:\t\t Quantity\t Expiration Date (DD/MM/YY)");  
	display(mainNode);
 
	return 0;
}
