/**
 * Description: WS12: Q6
 * Author names: Shannon Luu, Reshaj Maskey
 * Author emails: shannon.luu@sjsu.edu, reshaj.maskey@sjsu.edu
 * Last modified date: 11/27/2023
 * Creation date: 11/27/2023
 **/

/
 * Answer the questions in the header comments of the files. You can upload the output as .log files as well.
 * Create a program "q6.c" that allocates an array of integers (as above), frees them, and then tries to print the
 * value of one of the elements of the array. Does the program run? What happens when you use valgrind on it?
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	/* Your code here */
	int *data = malloc(sizeof(int) * 100);
	for(int i = 0; i < sizeof(data); i++) {
		data[i] = 1;
	}
	free(data);
	printf("%d\n", data[5]);
	
	return 0;
}
/**
 * The program runs and returns the input initialized in the array.
 * When running the program using valgrind, an error says that there is an invalid read of size 4 and it tells us the free'd and alloc'd blocks in our code.
 **/
