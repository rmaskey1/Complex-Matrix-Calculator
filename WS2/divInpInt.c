/**
 * file: divInpInt.c
 * author: Reshaj Maskey
 * description: program that reads integers userNum and divNum as parameters and outputs userNum/divNum three times
 */

#include <stdio.h>

void divideInteger(int userNum, int divNum) {
	for(int i = 0; i < 3; i++) {
		userNum = userNum/divNum;
		printf("%d\n",userNum);
	}
}

int main(void) {
	int userNum;
	int divNum;
	printf("Enter dividend and divisor (in format 'dividend divisor'):\n");
	scanf("%d %d", &userNum, &divNum);
	divideInteger(userNum, divNum);
	return 0;
}