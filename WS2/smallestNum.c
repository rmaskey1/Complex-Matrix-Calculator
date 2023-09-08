/**
 * file: smallestNum.c
 * author: Reshaj Maskey
 * description: program that reads three integer inputs and outputs the smallest of the three
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char values[100];
	printf("Enter 3 numbers (in format 'num1 num2 num3'):\n");
	fgets(values, 100, stdin);
	char *tok = strtok(values, " ");
	int min = atoi(tok);
	while(tok != NULL) {
		int num = atoi(tok);
		if(num < min) {
			min = num;
		}
		tok = strtok(NULL, " ");
	}
	printf("%d\n", min);

	return 0;
}