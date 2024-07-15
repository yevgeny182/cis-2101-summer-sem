#include <stdio.h>
#include <string.h>
#include "Graph.h"

#define ROW 5
#define COL 5
#define NODE 65

void createMatrix(int row, int col, int matrix[row][col]){
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            matrix[i][j] = 0;
        }
    }
}

void insertMatrixEdge(int matrix[ROW][COL], int v1, int v2){
    if(v1>ROW||v1<0||v1>COL||v2>ROW||v2<0||v2>COL){
        printf("OUT OF BOUNDS.\n");
    }
    else{
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    
}

void displayMatrix(int row, int col, int matrix[row][col]){
    int i, j, d;
    int v1 = NODE;
    int v2 = NODE;
    printf("DISPLAYING THE ADJACENCY MATRIX: \n  ");
    //printf("  ");
    for(d=0; d<col; d++){
        printf("%c ", v2);
        v2++;
    }
    printf("\n");
    for(i=0; i<row; i++){
        printf("%c ", v1);
        for(j=0; j<col; j++){
            
            printf("%d ", matrix[i][j]);
        }
        v1++;
        printf("\n");
    }
}
