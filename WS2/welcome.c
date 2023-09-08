/**
 * file: welcome.c
 * author: Reshaj Maskey
 * description: program that reads the input (user's first name) and outputs a welcoming message with the inputted name
 */

#include <stdio.h>
#include <string.h>

int main(void) {
	char name[100];
	printf("Enter your first name:\n");
	fgets(name, sizeof(name), stdin);
	size_t ln = strlen(name) - 1;
	if (name[ln] == '\n') {
		name[ln] = '\0';
	}
	printf("Hey %s!\nWelcome to zyBooks!", name);

	return 0;
}