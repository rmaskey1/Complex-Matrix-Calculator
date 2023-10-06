/*
 * Description: 5.28 LAB: Palindrome
 * Author names: Shannon Luu, Reshaj Maskey
 * Author emails: shannon.luu@sjsu.edu, reshaj.maskey@sjsu.edu
 * Last modified date: 10/4/2023
 * Creation date: 10/4/2023
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
     * TODO: Choose this one or 5_27.c
     * A palindrome is a word or a phrase that is the same when read both forward and backward. Examples are: "bob," "sees," or "never odd or even" (ignoring spaces). Write a program whose input is a word or phrase, and that outputs whether the input is a palindrome. You may assume that the input string will not exceed 50 characters.

    Ex: If the input is bob, the output is:

    palindrome: bob

    Ex: If the input is bobby, the output is:

    not a palindrome: bobby

    Hint: Start by just handling single-word input, and submit for grading. Once passing single-word test cases, extend the program to handle phrases. If the input is a phrase, remove or ignore spaces.

     */

    /* Type your code here. */

int main(void) {
	
	char str[100];
	int count = 0;
	char reversed[100];
	
	fgets(str, sizeof(str), stdin);
	int size = strlen(str) - 1;
	str[size] = '\0';
	
	for(int i = size-1; i >= 0; i--) {
		reversed[count] = str[i];
		count++;
	}
	reversed[count] = '\0';
	
	if (strcmp(str, reversed) == 0){
		printf("palindrome: %s\n", str);
	} else{
		printf("not a palindrome: %s\n", str);
	}
	
	return 0;
}
