#ifndef Graph
#define Graph

#define ROW 5
#define COL 5

void createMatrix(int row, int col, int matrix[row][col]);
void insertMatrixEdge(int matrix[ROW][COL], int v1, int v2);
void displayMatrix(int row, int col, int matrix[row][col]);

#endif
