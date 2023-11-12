/**
 * File: matrixmult_multiw.c
 * Description: This module executes multiple matrix multiplications in parallel.
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 11/12/2023
 * Creation date: 10/27/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#define ROWS 8
#define COLS 8

//This function occurs in place as it modifies matrix R1 by adding R2 to it
void addToMatrix(int R1[ROWS][COLS], int R2[ROWS][COLS]) {
	//This for loop computes the sum of two vectors
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			R1[i][j] = R1[i][j] + R2[i][j];
		}
	}
}

void make2DMatrix(FILE *fp, int arr[ROWS][COLS]) {
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
	
	// struct timespec start, finish;
	// double elapsed;
	// clock_gettime(CLOCK_MONOTONIC, &start);
		
	//Code with PID
	
	int status;
	pid_t pid;

	int childPID;
	int parentPID;

	int RSum[ROWS][COLS] = {0};
	int oldstdout = dup(1);
	
	//Used to access each W matrix text file (W1.txt, W2.txt, etc.)
	for(int i = 2; i < argc; i++){
		//char buffer[4096];

		int pipefd[2];
		//If piping fails
		if(pipe(pipefd)==-1) {
			printf("Pipe error\n");
			exit(1);
		}

		pid = fork();

		//If forking fails
		if(pid < 0){
			printf("Fork error\n");
			exit(1);
		}
		//If process is a child
		if(pid == 0){
			char *args[] = {"./matrixmult_parallel", argv[1], argv[i], NULL};
			childPID = getpid();
			parentPID = getppid();
			//Creats .out and .err file for each child PID
			char outputFile[100];
			snprintf(outputFile, sizeof(outputFile), "%d.out", getpid());
			char errorFile[100];
			snprintf(errorFile, sizeof(errorFile), "%d.err", getpid());
			int outFD = open(outputFile, O_RDWR | O_CREAT | O_APPEND, 0777);
			int errFD = open(errorFile, O_RDWR | O_CREAT | O_APPEND, 0777);
			dup2(outFD, 1); //File descriptor set to stdout
			dup2(errFD, 2); //File descriptor set to stderr
			close(outFD);
			close(errFD);

			printf("Starting command %d: child %d of parent %d\n", i-1, childPID, parentPID);
			fflush(stdout);

			char* Apath = realpath(argv[1], NULL);
			if(Apath == NULL){
			    fprintf(stderr, "cannot find file with name[%s]\n", argv[1]);
			    fflush(stderr);
			} else{
			    printf("A_filepath[%s]\n", Apath);
			    fflush(stdout);
			    free(Apath);
			}

			char* W1path = realpath(argv[i], NULL);
			if(W1path == NULL){
			    fprintf(stderr, "cannot find file with name[%s]\n", argv[i]);
			    fflush(stderr);
			} else{
			    printf("W_filepath[%s]\n", W1path);
			    fflush(stdout);
			    free(W1path);
			}

			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[0]);
			close(pipefd[1]);
			execvp(args[0], args); //Executes matrixmult_parallel with the provided arguments
			perror("Execvp failed\n");
			fprintf(stderr, "Execvp failed\n");
			fflush(stderr);
			exit(1);
			
			//fflush(stdout);
		}
		//If process is a parent
		if(pid > 0) {
			//After each child process exits until no more child
			while((pid = wait(&status)) > -1){
				childPID = pid;
				parentPID = getpid();		
				/*
				int nbytes = read(pipefd[0], buffer, sizeof(buffer));
				printf("%.*s\n", nbytes, buffer);
				char x[100];
				fgets(x, 100, fp);
				printf("\n%s\n",x);
				*/
				//If child exited sucessfully
				if (WIFEXITED(status)) {
					int es = WEXITSTATUS(status);
					childPID = pid;
					parentPID = getpid();

					close(pipefd[1]);
					FILE *fp = fdopen(pipefd[0], "r");
					int R[ROWS][COLS] = {0};
					make2DMatrix(fp, R);
					addToMatrix(RSum, R); //Adds R to Rsum in place, Rsum now has the result of Rsum + R
					//Creates .out and .err file for each child PID
					char outputFile[100];
					snprintf(outputFile, sizeof(outputFile), "%d.out", childPID);
					char errorFile[100];
					snprintf(errorFile, sizeof(errorFile), "%d.err", childPID);
					int outFD = open(outputFile, O_RDWR | O_CREAT | O_APPEND, 0777);
					int errFD = open(errorFile, O_RDWR | O_CREAT | O_APPEND, 0777);

					dup2(outFD, 1);
					dup2(errFD, 2);
					close(outFD);
					close(errFD);
					
					//If exited with error
					if(es == 1){
						fprintf(stderr, "Exited with exitcode = %d\n", es);
						fflush(stderr);
					}
					//If exited with no errors
					else {
						fprintf(stdout, "Finished child %d pid of parent %d\n", childPID, parentPID); 
	     				fprintf(stdout, "Exited with exitcode = %d\n", es);
	     				fflush(stdout);
					}
				}
				//If user enters a kill command to kill a process
				else if(WIFSIGNALED(status)){
					int es = WTERMSIG(status);

					//Creates .out and .err file for each child PID
					char outputFile[100];
					snprintf(outputFile, sizeof(outputFile), "%d.out", childPID);
					char errorFile[100];
					snprintf(errorFile, sizeof(errorFile), "%d.err", childPID);
					int outFD = open(outputFile, O_RDWR | O_CREAT | O_APPEND, 0777);
					int errFD = open(errorFile, O_RDWR | O_CREAT | O_APPEND, 0777);

					dup2(outFD, 1);
					dup2(errFD, 2);
					close(outFD);
					close(errFD);

					fprintf(stdout, "Finished child %d pid of parent %d\n", childPID, parentPID); 
	     			fprintf(stdout, "Exited with exitcode = %d\n", es);
	     			fflush(stdout);
					
					fprintf(stderr, "Killed with signal %d\n", es);
	     			fflush(stderr);
				}
				/*else{
					childPID = pid;
					parentPID = getpid();
					char reopen[100];
					sprintf(reopen, "%d.err", childPID);
					FILE *fp = fopen(reopen, "a");
					
					fprintf(fp, "Child %d pid of parent %d did not exit normally\n", childPID, parentPID); 
	     				fflush(stderr);
				}*/
			}
		}
	}
	int count = argc-1;
	char line[100];
	// char space = ' ';
	while(1) {
		if(fgets(line, sizeof(line), stdin) == NULL) {
			//strncat(line, &space, sizeof(space));
			//printf("LINE: %s\n", line);
			break;
		}
		// strncat(line, &space, sizeof(space));
		FILE *f = fopen("Rsum.txt", "w");
		if(f == NULL) {
			printf("Cannot open file");
		}
		for(int i = 0; i < ROWS; i++) {
			for(int j = 0; j < COLS; j++) {
				if(j == COLS-1) {
					fprintf(f, "%d\n", RSum[i][j]);
				}
				else {
					fprintf(f, "%d ", RSum[i][j]);
				}
			}
		}
		fclose(f);
		//Setting RSum back to all zeroes 
		for(int i = 0; i < ROWS; i++) {
			for(int j = 0; j < COLS; j++) {
				RSum[i][j] = 0;
			}
		}
		
		char *token = strtok(line, " ");
		while (token != NULL) {
			// printf("TOKEN: %s\n", token);
			int pipefd[2];
			//If piping fails
			if(pipe(pipefd)==-1) {
				printf("Pipe error\n");
				exit(1);
			}

			pid = fork();

			//If forking fails
			if(pid < 0){
				printf("Fork error\n");
				exit(1);
			}
			//If process is a child
			if(pid == 0){
				char *args[] = {"./matrixmult_parallel", "Rsum.txt", token, NULL};
				childPID = getpid();
				parentPID = getppid();
				//Creats .out and .err file for each child PID
				char outputFile[100];
				snprintf(outputFile, sizeof(outputFile), "%d.out", getpid());
				char errorFile[100];
				snprintf(errorFile, sizeof(errorFile), "%d.err", getpid());
				int outFD = open(outputFile, O_RDWR | O_CREAT | O_APPEND, 0777);
				int errFD = open(errorFile, O_RDWR | O_CREAT | O_APPEND, 0777);
				dup2(outFD, 1); //File descriptor set to stdout
				dup2(errFD, 2); //File descriptor set to stderr
				close(outFD);
				close(errFD);

				printf("Starting command %d: child %d of parent %d\n", count, childPID, parentPID);
				count = count + 1;
				fflush(stdout);

				char* RSumpath = realpath("Rsum.txt", NULL);
				if(RSumpath == NULL){
				    fprintf(stderr, "cannot find file with name[%s]\n", "Rsum.txt");
				    fflush(stderr);
				} else{
				    printf("RSum_filepath[%s]\n", RSumpath);
				    fflush(stdout);
				    free(RSumpath);
				}

				char* W2path = realpath(token, NULL);
				if(W2path == NULL){
				    fprintf(stderr, "cannot find file with name[%s]\n", token);
				    fflush(stderr);
				} else{
				    printf("W_filepath[%s]\n", W2path);
				    fflush(stdout);
				    free(W2path);
				}

				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[0]);
				close(pipefd[1]);
				execvp(args[0], args); //Executes matrixmult_parallel with the provided arguments
				perror("Execvp failed\n");
				fprintf(stderr, "Execvp failed\n");
				fflush(stderr);
				exit(1);
				
				//fflush(stdout);
			}
			if(pid > 0) {
			//After each child process exits until no more child
				while((pid = wait(&status)) > -1) {
					childPID = pid;
					parentPID = getpid();
					/*
					int nbytes = read(pipefd[0], buffer, sizeof(buffer));
					printf("%.*s\n", nbytes, buffer);
					char x[100];
					fgets(x, 100, fp);
					printf("\n%s\n",x);
					*/
					//If child exited sucessfully
					if (WIFEXITED(status)) {
						int es = WEXITSTATUS(status);
						childPID = pid;
						parentPID = getpid();

						close(pipefd[1]);
						FILE *fp = fdopen(pipefd[0], "r");
						int R[ROWS][COLS] = {0};
						make2DMatrix(fp, R);
						addToMatrix(RSum, R); //Adds R to Rsum in place, Rsum now has the result of Rsum + R
						//Creates .out and .err file for each child PID
						char outputFile[100];
						snprintf(outputFile, sizeof(outputFile), "%d.out", childPID);
						char errorFile[100];
						snprintf(errorFile, sizeof(errorFile), "%d.err", childPID);
						int outFD = open(outputFile, O_RDWR | O_CREAT | O_APPEND, 0777);
						int errFD = open(errorFile, O_RDWR | O_CREAT | O_APPEND, 0777);

						dup2(outFD, 1);
						dup2(errFD, 2);
						close(outFD);
						close(errFD);
						
						//If exited with error
						if(es == 1){
							fprintf(stderr, "Exited with exitcode = %d\n", es);
							fflush(stderr);
						}
						//If exited with no errors
						else {
							fprintf(stdout, "Finished child %d pid of parent %d\n", childPID, parentPID); 
		     				fprintf(stdout, "Exited with exitcode = %d\n", es);
		     				fflush(stdout);
						}
					}
					//If user enters a kill command to kill a process
					else if(WIFSIGNALED(status)){
						int es = WTERMSIG(status);

						//Creates .out and .err file for each child PID
						char outputFile[100];
						snprintf(outputFile, sizeof(outputFile), "%d.out", childPID);
						char errorFile[100];
						snprintf(errorFile, sizeof(errorFile), "%d.err", childPID);
						int outFD = open(outputFile, O_RDWR | O_CREAT | O_APPEND, 0777);
						int errFD = open(errorFile, O_RDWR | O_CREAT | O_APPEND, 0777);

						dup2(outFD, 1);
						dup2(errFD, 2);
						close(outFD);
						close(errFD);

						fprintf(stdout, "Finished child %d pid of parent %d\n", childPID, parentPID); 
			     			fprintf(stdout, "Exited with exitcode = %d\n", es);
			     			fflush(stdout);
						
						fprintf(stderr, "Killed with signal %d\n", es);
		     				fflush(stderr);
					}
					/*else{
						childPID = pid;
						parentPID = getpid();
						char reopen[100];
						sprintf(reopen, "%d.err", childPID);
						FILE *fp = fopen(reopen, "a");
						
						fprintf(fp, "Child %d pid of parent %d did not exit normally\n", childPID, parentPID); 
		     				fflush(stderr);
					}*/
				}
			}
			token = strtok(NULL, " ");
		}
	}	
	
	// clock_gettime(CLOCK_MONOTONIC, &finish);
	// elapsed = (finish.tv_sec - start.tv_sec);
	// printf("Runtime %.2f seconds\n", elapsed);

	dup2(oldstdout, 1);
	close(oldstdout);
	printf("\nRsum = [\n");
	//Printing out the final Rsum
 	for(int i=0;i<ROWS;i++) {
		for(int j=0;j<COLS;j++) {
			printf("%d ", RSum[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
	fflush(stdout);

	return 0;
}
