/**
 * file: mathFunctions.c
 * author: Reshaj Maskey, Shannon Luu
 * description: a program that takes a float input x, y, and z and does multiple math operations with them:
 * 				- x^z
 * 				- x^(y^2)
 * 				- |y|
 * 				- ((xy)^z)^(1/2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float x;
	float y;
	float z;
	printf("Enter a floating-point value for x, y, and z (in format 'x y z'):");
	scanf("%f %f %f", &x, &y, &z);
	//x^z
	printf("%0.2f\n", pow(x,z));
	//x^(y^2)
	printf("%0.2f\n", pow(x,pow(y,2)));
	//|y|
	printf("%0.2f\n", fabs(y));
	//((xy)^z)^(1/2)
	printf("%0.2f\n", pow(pow(x*y,z),0.5f));

	return 0;
}