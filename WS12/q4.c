/**
 * Description: WS12: Q6 - This program allocates memory but forgets to free it before exiting.
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 11/27/2023
 * Creation date: 11/27/2023
 **/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *data = malloc(sizeof(int) * 100);
	for(int i = 0; i < sizeof(data); i++) {
		data[i] = 0;
	}

	return 0;
}

/**
 * When running this program normally, nothing happens (program executes successfully).
 * When running this programing with gdb, no errors are caught and the program exits normally as well.
 * When running this program with valgrind, an error is printed saying that 400 bytes in 1 block are definitely lost.
 **/