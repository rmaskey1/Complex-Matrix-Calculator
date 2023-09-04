/**
 * file: asciiArt.c
 * author: Reshaj Maskey
 * description: program that draws a tree and a cat using ASCII characters
 */

#include <stdio.h>

void printTree() {
    printf("   *    \n");
    printf("  ***   \n");
    printf(" *****  \n");
    printf("******* \n");
    printf("  ***   \n");
}
void printCat() {
    printf("/\\   /\\\n");
    printf("  o o   \n");
    printf(" =   =  \n");
    printf("  ---   \n");
}
int main(void) {
    printTree();
    printf("\n");
    printf("\n");
    printCat();
}