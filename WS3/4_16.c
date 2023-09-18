/**
 * file: 4_16.c
 * author: Reshaj Maskey
 * description: program that returns the max value and average of a list of inputted integers
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int max = INT_MIN;
	float avg = 0;
	int count = 1;
	char str[100];

	printf("Input:\n");
    fgets(str, 100, stdin);
    char* token = strtok(str, " ");
	while(token != NULL) {
		if(atoi(token) < 0) {
			break;
		}
		if(atoi(token) > max) {
			max = atoi(token);
		}
		avg = avg + atoi(token);
		count++;
		token = strtok(NULL, " ");
	}
	avg = avg/(count-1);
	printf("Max: %d, Average: %f \n", max, avg);
}