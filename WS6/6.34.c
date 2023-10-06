/*
 * Description: 6.34 LAB: Multiples of ten in an array
 * Author names: Shannon Luu, Reshaj Maskey
 * Author emails: shannon.luu@sjsu.edu, reshaj.maskey@sjsu.edu
 * Last modified date: 10/4/2023
 * Creation date: 10/4/2023
 */

#include <stdio.h>
#include <stdbool.h>

    /*
     * TODO: Choose this one or 6_34.c
     * Write a program that reads a list of integers, and outputs whether the list contains all multiples of 10, no multiples of 10, or mixed values. Define a function named IsArrayMult10 that takes an array as a parameter, representing the list, and an integer as a parameter, representing the size of the list. IsArrayMult10() returns a boolean that represents whether the list contains all multiples of ten. Define a function named IsArrayNoMult10 that takes an array as a parameter, representing the list, and an integer as a parameter, representing the size of the list. IsArrayNoMult10() returns a boolean that represents whether the list contains no multiples of ten.

    Then, write a main program that takes an integer, representing the size of the list, followed by the list values. The first integer is not in the list. Assume that the list will always contain less than 20 integers.

    Ex: If the input is:

    5 20 40 60 80 100

    the output is:

    all multiples of 10

    Ex: If the input is:

    5 11 -32 53 -74 95

    the output is:

    no multiples of 10

    Ex: If the input is:

    5 10 25 30 40 55

    the output is:

    mixed values

    The program must define and call the following two functions. IsArrayMult10 returns true if all integers in the array are multiples of 10 and false otherwise. IsArrayNoMult10 returns true if no integers in the array are multiples of 10 and false otherwise.
    bool IsArrayMult10(int inputVals[], int numVals)
    bool IsArrayNoMult10(int inputVals[], int numVals)

     */

    /* Type your code here. Remember to include the bool library*/
    
bool IsArrayMult10(int inputVals[], int numVals){
	
	for(int i = 0; i < numVals; i++){
		if(inputVals[i] % 10 != 0){
			return false;
		}
	}
	
	return true;
}

bool IsArrayNoMult10(int inputVals[], int numVals){
	
	for(int i = 0; i < numVals; i++){
		if(inputVals[i] % 10 == 0){
			return false;
		}
	}
	
	return true;
}
    

int main(void) {
	

	int count = 0;
	int size = 1;
	int input[20];
	while(count <= size){
		if(count == 0){
		scanf("%d", &size);
		} else {
		scanf("%d", &input[count-1]);
		}
		count++;
	}
	
	printf("the output is: \n");
	
	if (IsArrayMult10(input, size)){
		printf("all multiples of 10\n");
	} else if (IsArrayNoMult10(input, size)) {
		printf("no multiples of 10\n");
	} else {
		printf("mixed values\n");
	}
	
	return 0;
}
