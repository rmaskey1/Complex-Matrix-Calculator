/**
 * File: matrixmult.c
 * Description: 
 * 		This module implements matrix operations (multiplication and addition)
 * 		on matrices and vectors. It computes the vector resulting from the equation R = A * W + B,
 * 		where A is the input, W is the weights matrix, B is the bias, and R is the resulting vector.
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 09/11/2023
 * Creation date: 09/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * This function establishes a 2D matrix with the given file
 * Assumption: Matrix has dimensions of 3x5
 * Input parameters: filename, int arr[3][5]
**/ 
void make2DMatrix(char *filename, int arr[3][5]) {
	FILE *fp = fopen(filename, "r");
	//This if statement ensures that the file exists
	if(fp == NULL) {
		printf("cannot open file\n");
		exit(1);
	}

	int val1, val2, val3, val4, val5;
	char line[100];
	int i = 0;
	//This while loop scans line by line from the file and inputs matrix data into a 2D array
	while(fgets(line, 100, fp) != NULL && i < 3) {
    	val1 = 0;
    	val2 = 0;
    	val3 = 0;
    	val4 = 0;
    	val5 = 0;
    	sscanf(line, "%d %d %d %d %d", &val1, &val2, &val3, &val4, &val5);
		arr[i][0] = val1;
		arr[i][1] = val2;
		arr[i][2] = val3;
		arr[i][3] = val4;
		arr[i][4] = val5;
		i++;
	}
}

/**
 * This function establishes a 1D matrix with the given file
 * Assumption: Matrix has dimensions of 1x3 or 1x5
 * Input parameters: filename, int arr[], int size
**/ 
void makeMatrix(char *filename, int arr[], int size) {
	FILE *fp = fopen(filename, "r");
	//This if statement ensures that the file exists
	if(fp == NULL) {
		printf("cannot open file\n");
		exit(1);
	}
	//This if statement establishes if the matrix dimension is 1x3 and creates a 1x3 array
	if(size == 3) {
		int val1, val2, val3 = 0;
		fscanf(fp, "%d %d %d", &val1, &val2, &val3);
		arr[0] = val1;
		arr[1] = val2;
		arr[2] = val3;
	}
	//If not 1x3, then 1x5 and creates a 1x5 array
	else {
		int val1, val2, val3, val4, val5 = 0;
		fscanf(fp, "%d %d %d %d %d", &val1, &val2, &val3, &val4, &val5); //10 30 40 50
		arr[0] = val1;
		arr[1] = val2;
		arr[2] = val3;
		arr[3] = val4;
		arr[4] = val5;
	}
}

/**
 * This function performs a multiplication of two matrices
 * Assumption: Matrices has dimensions of 1x3 and 3x5
 * Input parameters: int A[], int W[][]
 * Returns: a vector
**/ 
int* multMatrices(int A[], int W[3][5]) {
	static int arr[5];
	//This nested for loop computes the dot product of two vectors
	for(int i = 0; i < 5; i++) {
		int result = 0;
		for(int j = 0; j < 3; j++) {
			result += A[j] * W[j][i];
		}
		arr[i] = result;
	}	
	return arr;
}

/**
 * This function performs an addition of two matrices
 * Assumption: Matrices has dimensions of 1x5
 * Input parameters: int AW[], int B[]
 * Returns: a vector
**/ 
int* addMatrices(int AW[], int B[]) {
	static int arr[5];
	//This for loop computes the sum of two vectors
	for(int i = 0; i < 5; i++) {
		arr[i] = AW[i] + B[i];
	}
	return arr;
}

int main(int argc, char* argv[]) {
	
	//Matrix initialization
	int A[3] = {0};
	int W[3][5] = {0};
	int B[5] = {0};
	
	//Converts text file data to matrices
	makeMatrix(argv[1], A, 3);
	make2DMatrix(argv[2], W);
	makeMatrix(argv[3], B, 5);

	//Computes A*W+B
	int* R = addMatrices(multMatrices(A,W),B);
	
	printf("Result of A*W+B = [");
	//This for loop prints the array result values
	for(int i = 0; i < 5; i++) {
		printf(" %d ",R[i]);
	}
	printf("]\n");

	return 0;
}