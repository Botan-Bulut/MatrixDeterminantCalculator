/**************************************
 * Matrix Determinant Calculator      *
 * 									  *
 * DATE : 2022 - 11 - 21			  *
 * 									  *
 * ***********************************/


#include<stdio.h>
#include<stdlib.h>

double determinant_calc(int n, double *matrix){
	
	if (n == 2){

		return (matrix[0] * matrix[3]) - (matrix[1] * matrix[2]);  
	}

	
}





int main(void){

	int n, i, j, k = 0, elements; // Matrix is a square matrix (nxn).
	double **matrix, *rawmatrix, d;

// Determining the size of matrix by user input.

	printf("Enter the size of your square matrix: ");
	scanf("%d", &n);

	if (n == 1){

		printf("The determinant of 1x1 matrix is equal to the number of itself.\n");
		exit(1);

	}

	if (n < 1){

		printf("Input error. Exiting...\n");
		exit(1);

	}
	
	elements = n * n; // Total number of elements in the array.

// Dynamically allocating the memory to generate the matrix for a given user input.

	matrix = (double **) malloc(n * sizeof(double));

	if (matrix == (double **) NULL){

		printf("Memory allocation failed. Program exiting...\n");
		exit(1);

	}


	for (i = 0; i < n; i++){

		matrix[i] = (double *) malloc(n * sizeof(double));

		if (matrix[i] == (double *) NULL){

			printf("Memory allocation failed. Program exiting...\n");
			exit(1);

		}
	}

// Getting the matrix elements from the user
	
	for (i = 0; i < n; ++i){

		for(j = 0; j < n; ++j){

			printf("Enter row %d, column %d element: ", (i + 1), (j + 1));
			scanf("%lf", &matrix[i][j]);

		}
	}
	
/*Displaying the matrix (Optional)*/

	printf("\nYour matrix is:\n");


	for (i = 0; i < n; ++i){

		for(j = 0; j < n; ++j){

			if (j == 0){
				
				printf("| %.2lf ", *(*(matrix + i)+ j));
				
				
			}
			else if (j == (n - 1)){

				printf(" %.2lf |\n", *(*(matrix + i)+ j));
				
			}

			else{
				
				printf(" %.2lf ", *(*(matrix + i)+ j));
				
				
			}
		}
	}
/**********************************************************/

	rawmatrix = (double *) malloc(elements * sizeof(double));

	for (i = 0; i < n; ++i){

		for (j = 0; j < n; ++j){

			rawmatrix[k] = *(*(matrix + i) + j);

			++k;

		}

	}

/**Display Raw matrix optional
	for (i = 0; i < elements; ++i){

		printf("index %d : %.2lf\n", i, rawmatrix[i]);
	}
*/
	
	d = determinant_calc(n, rawmatrix);

	printf("Determinant is: %.2lf.\n", d);


	return 0;
}






















