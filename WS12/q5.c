/**
 * Description: WS12: Q5 - This program creates an integer array called "data" of size 100 and sets data[100] to zero.
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 11/27/2023
 * Creation date: 11/27/2023
 **/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *data = malloc(sizeof(int) * 100);
	data[100] = 0;

	return 1;
}

/**
 * When running this program WITHOUT valgrind, nothing happens (program executes successfully).
 * When running this program WITH valgrind, an error is printed telling me that there is an invalid write of size 4 at address 0x10916D and 400 bytes in 1 block are definitely lost.
 * The program is not correct and valgrind correctly catches the issue as data[100] is out of bounds of the allocated space, meaning when setting data[100] = 0, the data is untracked.
 **/