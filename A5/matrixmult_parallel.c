/**
 * File: matrixmult_parallel.c
 * Description: This program takes 2 matrices and utilizes parallel processes
 * to compute their dot product (used in matrixmult_multiw)
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 10/29/2023
 * Creation date: 10/27/2023
 **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#define ROWS 8
#define COLS 8
#define MAX_FILENAME_LENGTH 100


//lock_t lockRealloc;

typedef struct
{
	int data[ROWS][COLS];
} Matrix;

/**
 * This function takes in the matrix filename and procudes a 2D matrix
 * All empty spaces are filled with zeroes
**/ 
int make2DMatrix(char *filename, int arr[ROWS][COLS]) {
	FILE *fp = fopen(filename, "r");
	//This if statement ensures that the file exists
	if(fp == NULL) {
		fprintf(stderr, "Cannot open file (from matrixmult_parallel)\n");
		exit(1);
	}

	int val1, val2, val3, val4, val5, val6, val7, val8;
	char line[100];
	int i = 0;
	//This while loop gets and scans the file for 2D array inputs
	while(fgets(line, 100, fp) != NULL && i < 8) {
	    	val1 = 0;
	    	val2 = 0;
	    	val3 = 0;
	    	val4 = 0;
	    	val5 = 0;
	    	val6 = 0;
	    	val7 = 0;
	    	val8 = 0;
	    	sscanf(line, "%d %d %d %d %d %d %d %d", &val1, &val2, &val3, &val4, &val5, &val6, &val7, &val8);
		arr[i][0] = val1;
		arr[i][1] = val2;
		arr[i][2] = val3;
		arr[i][3] = val4;
		arr[i][4] = val5;
		arr[i][5] = val6;
		arr[i][6] = val7;
		arr[i][7] = val8;
		i++;
	}
	return 0;
}

/**
 * This function is used to reallocate space for the next 8 rows added to the R matrix.
 */

void reallocateMatrix(int ***result, int *currentSize, int sizeIncrease) {
	*currentSize += sizeIncrease;

	*result = (int **)realloc(*result, *currentSize * sizeof(int *));
	if (*result == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	//Allocating 8 * 4 (int) bytes of memory for matrix line
	for (int i = *currentSize - sizeIncrease; i < *currentSize; i++) {
		(*result)[i] = (int *)malloc(8 * sizeof(int));
		if ((*result)[i] == NULL) {
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < 8; j++) {
			(*result)[i][j] = 0;
		}
	}
}

int matrixMult(int (*A)[8], int (*W)[8], int **R)
{
	int fd[8][2];
	//Checks if any pipes failed
	for (int i = 0; i < 8; i++) {
		if (pipe(fd[i]) == -1) {
			fprintf(stderr, "error: pipe failed \n");
			fprintf(stderr, "Terminating exit code 1\n");
			return 1;
		}
	}

	fflush(stdout);
	fflush(stderr);

	//Computing dot product of two arrays in nested loop fashion
	for (int i = 0; i < ROWS; i++) {
	//Creates 8 processes (one process for every row)
		pid_t pid = fork();
		if (pid == -1) {
			fprintf(stderr, "error: fork failed \n");
			fprintf(stderr, "Terminating exit code 1\n");
			fflush(stderr);
			return 1;
		}
		//Child
		else if (pid == 0) {
			close(0);
			close(fd[i][0]);
			int finalRow[ROWS];
			for (int j = 0; j < ROWS; j++) {
				finalRow[j] = 0;
				for (int k = 0; k < COLS; k++) {
					finalRow[j] += A[i][k] * W[k][j];
				}
			}
			//Writes results to pipe
			if (write(fd[i][1], finalRow, sizeof(int) * 8) < 0) {
				fprintf(stderr, "error: write failed \n");
				fprintf(stderr, "Terminating exit code 1\n");
				fflush(stdout);
				return 1;
			}
			close(fd[i][1]);
			exit(0);
		}
		//Parent
		else if (pid > 0) {
			close(fd[i][1]);
			//Reads results from pipe into finalMatrix
			if (read(fd[i][0], R[i], sizeof(int) * 8) < 0) {
				fprintf(stderr, "error: read failed \n");
				fprintf(stderr, "Terminating exit code 1\n");
				fflush(stderr);
				return 1;
			}
			close(fd[i][0]);
			wait(NULL);
		}
	}
	return 0;
}

int main(int argc, char *argv[]) { 
	//Takes command-line arguments as an array of strings
	freopen("cmds.txt", "r", stdin);
	if (argc != 3) {
		fprintf(stderr, "error: expecting exactly 2 files as input\n");
		fprintf(stderr, "Terminating, exit code 1\n");
		return 1;
	}

	//Defines matrices A, W, and result matrix with 0s as default
	char input[MAX_FILENAME_LENGTH];
	int A[ROWS][COLS] = {0};
	int W[ROWS][COLS] = {0};
	int result_size = 8;
	int **R = NULL;

	if (make2DMatrix(argv[1], A)) {
		return 1;
	}

	if (make2DMatrix(argv[2], W)) {
		return 1;
	}

	printf("A1 = %s\n", argv[1]);
	printf("W1 = %s\n", argv[2]);

	R = (int **)malloc(8 * sizeof(int *));
	if (R == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	//For loop to allocate 8 * 4 (int) bytes of memory for matrix line
	for (int i = 0; i < ROWS; i++) {
		R[i] = (int *)malloc(8 * sizeof(int));
		if (R[i] == NULL) {
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < COLS; j++) {
			R[i][j] = 0;
		}
	}

	if (matrixMult(A, W, R)) {
		return 1;
	}

	//While (!feof(stdin))
	while (fgets(input, MAX_FILENAME_LENGTH, stdin) != NULL) {
		input[strcspn(input, "\n")] = 0;

		if (make2DMatrix(input, A)) {
			return 1;
		}

		reallocateMatrix(&R, &result_size, 8);

		//Pointer arithmetic to write into the last 8 rows
		if (matrixMult(A, W, R + result_size - 8)) {
			return 1;
		}
	}

	//Prints R matrix
	printf("R = [\n");
	for (int i = 0; i < result_size; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%2d ", R[i][j]);
		}
	printf("\n");
	}
	printf("]\n");

	//Free() all the pointers inside the double pointer, then free double pointer
	for(int i=0; i<result_size; i++){
		free(R[i]);
	}
	free(R);

    

	return 0;
}
