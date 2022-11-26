/*
 * Matrix Determinant Calculator
 * 
 * Date: 2022 - 11 - 21
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void row_swap(double **matrix, int n, int r1, int r2)
{
	int column;
	double temp;

	for(column = 0; column < n; ++column)
	{
		temp = matrix[r1][column];
		matrix[r1][column] = matrix[r2][column];
		matrix[r2][column] = temp;
	}
}

double determinant_calculator(double **matrix, int n)
{
	double value, determinant;
	int l1, l2, l3;

	for(l1 = 0; l1 < n; ++l1)
	{
		double **copymatrix, **submatrix;
		copymatrix = (double **) malloc(n * sizeof(double));

		if(copymatrix == (double **) NULL) { printf("Memory allocation unsuccessful. Program exiting...\n"); exit(1);}

		for (l2 = 0; l2 < n; ++l2)
		{
			copymatrix[l2] = (double *) malloc(n * sizeof(double));
			
			if(copymatrix[l2] == (double *) NULL) { printf("Memory allocation unsuccessful. Program exiting...\n"); exit(1);}
		}

		for(l2 = 0; l2 < n; ++l2)
		{
			for(l3 = 0; l3 < n; ++l3)
			{
				copymatrix[l2][l3] = *(*(matrix + l2) + l3);
			}
		}

		if(n == 2) { return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);}

		if((l1 != 0) && (n > 2)) { row_swap(copymatrix, n, 0, l1);}

		if(n > 2)
		{	
			submatrix = (double **) malloc((n - 1) * sizeof(double));

			if(submatrix == (double **) NULL) { printf("Memory allocation unsuccessful. Program exiting...\n"); exit(1);}

			for(l2 = 0; l2 < (n - 1); ++l2)
			{
				submatrix[l2] = (double *) malloc((n - 1) * sizeof(double));

				if(submatrix[l2] == (double *) NULL) { printf("Memory allocation unsuccessful. Program exiting...\n"); exit(1);}
			}

			for(l2 = 0; l2 < (n - 1); ++l2)
			{
				for(l3 = 0; l3 < (n - 1); ++l3)
				{
					submatrix[l2][l3] = copymatrix[l2 + 1][l3 + 1];
				}
			}
			
			for(l2 = l1; l2 > 1; --l2)
			{
				row_swap(submatrix, (n - 1), (l2 - 1), (l2 - 2));
			}
			
			if((l1 % 2) == 0) { value = (double) ((matrix[l1][0]) * (determinant_calculator(submatrix, (n - 1)))); determinant = determinant + value;}
			else { value = (double) ((matrix[l1][0]) * (determinant_calculator(submatrix, (n - 1)))); determinant = determinant - value;}
			
			free(copymatrix); free(submatrix);
		}
	}
	
	return determinant;
	
}

int main(void)
{
	int n, i, j;
	double **matrix, determinant;

	printf("Enter the matrix size (nxn): "); scanf("%d", &n);

	if(n < 1) { printf("Wrong input. Program Exiting...\n"); exit(1);}

	if(n == 1) { printf("1x1 Matrix determinant is equal to number itself.\n"); return 0;}

	matrix = (double **) malloc(n * sizeof(double));

	if (matrix == (double **) NULL) { printf("Memory allocation unsuccessful. Program exiting...\n"); exit(1);}

	
	for (i = 0; i < n; ++i) 
	{ 
		matrix[i] = (double *) malloc(n * sizeof(double));
		if(matrix[i] == (double *) NULL) { printf("Memory allocation unsuccessful. Program exiting...\n"); exit(1);}
	}

	for(i = 0; i < n; ++i)
	{ 
		for(j = 0; j < n; ++j)
		{
			printf("Enter the row %d, column %d element: ", (i + 1), (j + 1)); scanf("%lf", &matrix[i][j]);
		}
	}

	printf("\nMatrix entered is: \n\n");

	for(i = 0; i < n; ++i)
	{
		printf("\t| ");

		for(j = 0; j < n; ++j)
		{
			printf(" %.2lf ", *(*(matrix + i) + j));
		}

		printf(" |\n");
	}

	determinant = determinant_calculator(matrix, n);

	printf("\nDeterminant is: %.3lf.\n--------------------------------------------------\n\n", determinant);

	return 0;
}
