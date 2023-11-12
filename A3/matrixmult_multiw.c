/**
 * File: matrixmult_multiw.c
 * Description: This module executes multiple matrix multiplications in parallel.
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 10/15/2023
 * Creation date: 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	
	// struct timespec start, finish;
	// double elapsed;
	// clock_gettime(CLOCK_MONOTONIC, &start);
		
	//Code with PID
	
	int status;
	pid_t pid;

	int childPID;
	int parentPID;
	
	//Used to access each W matrix text file (W1.txt, W2.txt, etc.)
	for(int i = 2; i < argc; i++){

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

			//Creates .out and .err file for each child PID
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

				//Creats .out and .err file for each child PID
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
				
				//If child exited sucessfully
				if (WIFEXITED(status)) {
					int es = WEXITSTATUS(status);
					childPID = pid;
					parentPID = getpid();
					
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
		
	
	// clock_gettime(CLOCK_MONOTONIC, &finish);
	// elapsed = (finish.tv_sec - start.tv_sec);
	// printf("Runtime %.2f seconds\n", elapsed);
	return 0;
}
