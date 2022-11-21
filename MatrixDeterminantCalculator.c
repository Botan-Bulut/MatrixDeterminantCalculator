/**************************************
 * Matrix Determinant Calculator      *
 * 									  *
 * DATE : 2022 - 11 - 21			  *
 * 									  *
 * ***********************************/


#include<stdio.h>
#include<stdlib.h>


double determinant_calc(int row, int col, double **matrix){

	int i;

	if (row == 2 && col == 2){

		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);  
	}

	else if (row == 3 && col == 3){

		double arr[3] = {}

		for (i = 0; i < 3; ++i){



		}
		
		return matrix[0][0] * determinant_calc((row -1), (col - 1))

	}
}





int main(void){

	int n, i, j; // Matrix is a square matrix (nxn).
	double **matrix, determinant;

// Determining the size of matrix by user input.

	printf("Enter the size of your square matrix: ");
	scanf("%d", &n);

	if (n == 1){

		printf("The determinant of 1x1 matrix is equal to the number of itself.\n");
		exit(1);

	}

	if (n < 1){

		printf("Input error. Exiting...");
		exit(1);

	}
	
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
	
	determinant = determinant_calc(n, n, matrix);

	printf("Determinant is: %.2lf.", determinant);

	printf("\n");

	return 0;
}






















