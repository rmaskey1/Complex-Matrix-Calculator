/**
 * File: matrixmult_parallel.c
 * Description: This module implements 2D array multiplication in a parallel fashion using multiple processes
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 09/25/2023
 * Creation date: 09/23/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define ROWS 8
#define COLS 8

/**
 * This function establishes a 2D matrix with the given file
 * Assumption: Matrix has dimensions of 8x8
 * Input parameters: filename, int arr[ROWS][COLS]
**/ 
void make2DMatrix(char *filename, int arr[ROWS][COLS]) {
	FILE *fp = fopen(filename, "r");
	//This if statement ensures that the file exists
	if(fp == NULL) {
		fprintf(stderr, "Cannot open file\n");
		exit(1);
	}

	int val1, val2, val3, val4, val5, val6, val7, val8;
	char line[100];
	int i = 0;
	//This while loop gets and scans the file for 2D array inputs
	while(fgets(line, 100, fp) != NULL && i < ROWS) {
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
}


int main(int argc, char* argv[]) {
	
	int A[ROWS][COLS] = {0};
	int W[ROWS][COLS] = {0};
	int r[ROWS][COLS] = {0};
		
	make2DMatrix(argv[1], A);
	make2DMatrix(argv[2], W);
	
	int status;
	pid_t id;
	int pipefd[2];
	//Processing 8 times for each row
	for(int i = 0; i < ROWS; i++){
		pipe(pipefd);
		//Error with pipe
		if(pipefd < 0){
			printf("Pipe error\n");
		}
		id = fork();
		//Error with fork
		if(id < 0){
			printf("Fork error\n");
			exit(1);
		}
		//Child
		if(id == 0){
			close(pipefd[0]);
			//Computing dot product of two arrays in nested loop fashion
			for(int j = 0; j < ROWS; j++){
				int sum = 0;
				for(int k = 0; k < COLS; k++){
					sum += A[i][k] * W[k][j];
				}
				r[i][j] = sum;
			}
			write(pipefd[1], r[i], sizeof(int)*COLS);
			close(pipefd[1]);
			exit(0);
		}
		//Parent
		if(id > 0) {
			//After each child process exits until no more child
			while((id = wait(&status)) > -1){
				//If child exited sucessfully
				if (WIFEXITED(status)) {
					close(pipefd[1]);
     					//const int es = WEXITSTATUS(status); 
     					//printf("exit status was %d\n", es); 
     					read(pipefd[0], r[i], sizeof(int)*COLS);
     					close(pipefd[0]);
				}
			}
		}
	}
	
	//Printing out matrix results
	printf("%s = [\n", strrchr(argv[1], 'A'));
 	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLS;j++) {
			printf("%d\t",A[i][j]);
		}
	printf("\n");
	}
	printf("]\n");
	
	printf("%s = [\n", strrchr(argv[2], 'W'));
 	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLS;j++) {
			printf("%d\t",W[i][j]);
		}
	printf("\n");
	}
	printf("]\n");
	
	printf("R = [\n");
 	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLS;j++) {
			printf("%d\t",r[i][j]);
		}
	printf("\n");
	}
	printf("]\n");
	
	return 0;
}
