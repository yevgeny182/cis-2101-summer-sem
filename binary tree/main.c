#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	NodePtr mainNode = NULL;

	int a, deleteIndex;
	Product data [] = {{"Mango", 25.00, 50, {01, 07, 2024}},
                     {"Banana", 30.00, 25, {31, 07, 2024}},
                     {"Pineapple", 70.00, 50, {31, 07, 2024}},
                     {"Watermelon", 100.00, 50, {31, 07, 2024}},
                     {"Sardines", 50.00, 50, {31, 07, 2024}},
                     {"Broccoli", 40.00, 50, {31, 07, 2024}},
                     {"Cantaloupe", 80.00, 50, {31, 07, 2024}},
                     {"Rice", 20.00, 50, {31, 07, 2024}},
                     {"Peach", 35.00, 50, {31, 07, 2024}},
                     {"Strawberry", 150.00, 100, {31, 07, 2024}},
                     //{"Strawberry", 150.00, 100, {31, 07, 2024}}
    
    };
	printf("The following data has been populated!\n");

	int dataCount = sizeof(data) / sizeof(data[0]);

	for(a=0; a<dataCount; a++){
		add(&mainNode, data[a]);
	}


		int num;
	do{
	printf("\n\nSelect type of traversal to display:\n1. In Order\n2. Pre Order\n3. Post order\n4. Delete a record\n5. BFS\n0. End the program\n");
	scanf("%d", &num);

		switch(num){
		case 1:
				printf("IN ORDER Display\n\n");
				printf("Product Name:%9s  Price:\t%9s Quantity%9s Expiration Date (DD/MM/YY)", "", "", ""); 
				inOrder(mainNode);
			break;
		case 2:
				printf("PRE ORDER Display\n\n");
				printf("Product Name:%9s  Price:\t%9s Quantity%9s Expiration Date (DD/MM/YY)", "", "", ""); 
				preOrder(mainNode);			
			break;
		case 3:
				printf("POST ORDER Display\n\n");
				printf("Product Name:%9s  Price:\t%9s Quantity%9s Expiration Date (DD/MM/YY)", "", "", ""); 
				postOrder(mainNode);	
			break;
		case 4:
				printf("Where to delete? ");
				scanf("%d", &deleteIndex);
				printf("Displaying in inOrder\n");
				deleteNode(&mainNode, data[deleteIndex]);
				printf("Product Name:%9s  Price:\t%9s Quantity%9s Expiration Date (DD/MM/YY)", "", "", ""); 
				inOrder(mainNode);
			break;
		case 5:
			printf("Displaying in BFS\n");
			printf("Product Name:%9s  Price:\t%9s Quantity%9s Expiration Date (DD/MM/YY)", "", "", "");
			bfs(mainNode);
			break;
		default:
			printf("End of Program!");	
	}
	
	}while(num!=0);
	
	
	
	return 0;
}
