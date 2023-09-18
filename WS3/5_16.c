/**
 * file: 5_16.c
 * author: Reshaj Maskey
 * description: program that returns a list of inputted integers in reverse
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	printf("Input:\n");
    char str[100];
    fgets(str, 100, stdin);
    char* token = strtok(str, " ");
    int size = atoi(token);
    int arr[size];
    token = strtok(NULL, " ");
    int i = 0;
	while(token != NULL && i < size) {
		arr[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	for(int i = size-1; i >= 0; i--) {
		printf("%d,", arr[i]);
	}
	printf("\n");
}