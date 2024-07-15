#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

int main(int argc, char *argv[]) {
    int matrix[ROW][COL];
    createMatrix(ROW, COL, matrix);
    insertMatrixEdge(matrix, 0, 1);
    insertMatrixEdge(matrix, 0, 2);
    insertMatrixEdge(matrix, 0, 3);
    insertMatrixEdge(matrix, 1, 2);
    insertMatrixEdge(matrix, 1, 3);
    insertMatrixEdge(matrix, 1, 4);
    insertMatrixEdge(matrix, 2, 3);
    insertMatrixEdge(matrix, 3, 4);
    //insertMatrixEdge(ROW, COL, matrix, 6, 8);
    displayMatrix(ROW, COL, matrix);
    return 0;
}
