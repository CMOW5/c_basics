/*
 ============================================================================
 Name        : C_MatrixOPerations.c
 Author      : Cristian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int row, int col, int matrix[row][col]);

int sarrus(int row, int col, int matrix[row][col]);

void matrixMultiplication(int rowA, int colA,
		                  int rowB, int colB,
						  int matrixA[rowA][colA],
						  int matrixB[rowB][colB],
						  int matrixC[rowA][colB]);

void matrixTransponse(int row, int col, int matrix[row][col]);
int matrixDet(int row, int col, int matrix[row][col]);


int main(void) {

	puts("STARTING....");

	int det = 0;
	int matrix1[2][3] = {{1,2,3}, {4,5,6}}; //3x2 rows
	int matrix2[3][2] = {{1,2}, {3,4}, {5,6}}; //2x3
	int matrix3[2][2] = {{0,0}}; //2x2

	int matrix4[3][3] = {{1,-2,-3}, {0,2,-3}, {0,0,3}}; //3x3
	int matrix5[3][3] = {{5,0,0}, {4,-3,0}, {-2,1,5}}; //3x3
	int matrix6[3][3] = {{5,0,0}, {4,-3,0}, {-2,1,5}}; //3x3.

	int matrix7[7][3] = {{0,0,4}, {1,0,4}, {0,1,0},
						 {0,3,2}, {0,2,3}, {0,3,4},
						 {3,3,1}}; //7x3

	int matrix8[3][3] = {{1,2,3}, {1,1,-1}, {2,0,5}}; //3x3.
	det = matrixDet(3,3,matrix8);
	printf("\ndet = %d",det);
	/*
	printMatrix(2,3,matrix1);
	puts("");
	printMatrix(3,2,matrix2);
	puts("");
	matrixMultiplication(2,3,3,2,matrix1,matrix2,matrix3);
	puts("");
	matrixMultiplication(3,3,3,3,matrix4,matrix5,matrix6);
	puts("");
	printMatrix(3,3,matrix6);*/

	puts("");
	printMatrix(7,3,matrix7);
	matrixTransponse(7,3,matrix7);

	return EXIT_SUCCESS;
}

int matrixDet(int row, int col, int matrix[row][col])
{


	if(row == 1 && col == 1)
	{
		return matrix[0][0];
	}
	else if(row == 2 && col == 2)
	{
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
	}
	else if(row == 3 && col == 3)
	{
		return sarrus(3,3,matrix);
	}

	return 0;
}

int sarrus(int row, int col, int matrix[row][col])
{

	int a =  (matrix[0][0]*matrix[1][1]*matrix[2][2])
			+(matrix[1][0]*matrix[2][1]*matrix[0][2])
            +(matrix[2][0]*matrix[0][1]*matrix[1][2]);

	int b = -(matrix[0][2]*matrix[1][1]*matrix[2][0])
			-(matrix[1][2]*matrix[2][1]*matrix[0][0])
	        -(matrix[2][2]*matrix[0][1]*matrix[1][0]);

	return a+b;

}

void matrixTransponse(int row, int col, int matrix[row][col])
{
	int i = 0;
	int j = 0;
	int matrixT[col][row];

	for(i = 0; i < col; i++)
	{
		for(j = 0; j < row; j++)
		{
			matrixT[i][j] = matrix[j][i];
		}
	}

	printMatrix(col,row,matrixT);

}

void matrixMultiplication(int rowA, int colA,
		                  int rowB, int colB,
						  int matrixA[rowA][colA],
						  int matrixB[rowB][colB],
						  int matrixC[rowA][colB])

{

	int i = 0;
	int j = 0;
	int k = 0;
	int num = 0;

	for (i = 0; i < rowA; i++)
	{
		for(j = 0; j < colB; j++)
		{
			for(k = 0; k < colA; k++)
			{
				int matA = matrixA[i][k];
				int matB = matrixB[k][j];
				num+=matA*matB;
			}
			matrixC[i][j] = num;
			num = 0;
		}
	}

	printMatrix(rowA, colB, matrixC);


}

void printMatrix(int row, int col, int matrix[][col])
{

	int i = 0;
	int j = 0;

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
}
