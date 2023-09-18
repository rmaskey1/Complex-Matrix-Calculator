/**
 * file: 4_14.c
 * author: Reshaj Maskey
 * description: program that takes an integer input and outputs the reverse binary of that number
 */

#include <stdio.h>

int main(void) {
	int input;
	printf("Enter a number to find the reverse binary of:\n");
	scanf("%d", &input);

	while(input > 0) {
		printf("%d", input%2);
		input = input/2;
	}
	printf("\n");
}