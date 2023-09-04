/**
 * file: basicOptWVar.c
 * author: Reshaj Maskey
 * description: program that takes the first user input, prints it, squares it, and cubes it, and then takes another user input and adds/multiplies it with the previous user input
 */

#include <stdio.h>

int main(void) {
    int first;
	printf("Enter integer: \n");
    scanf("%d",&first);
    printf("%d squared is %d\n",first,first*first);
    printf("%d cubed is %d!!\n",first,first*first*first);

    int second;
    printf("Enter another integer: \n");
    scanf("%d",&second);
    printf("%d + %d is %d\n",first,second,first+second);
    printf("%d * %d is %d\n",first,second,first*second);

    return 0;
}