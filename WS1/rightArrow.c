/**
 * file: rightArrow.c
 * author: Reshaj Maskey
 * description: program that prints a right arrow given two input integers; first integer makes up the arrow body and the second integer makes up the arrowhead
 */

#include <stdio.h>

void makeArrow(int body, int head) {
    printf("    %d\n", head);
    printf("    %d%d\n", head, head);
    printf("%d%d%d%d%d%d%d\n", body, body, body, body, head, head, head);
    printf("%d%d%d%d%d%d%d%d\n", body, body, body, body, head, head, head, head);
    printf("%d%d%d%d%d%d%d\n", body, body, body, body, head, head, head);
    printf("    %d%d\n", head, head);
    printf("    %d\n", head);
}

int main(void) {
    int body;
    int head;
    printf("Choose number for arrow body and head (enter numbers in format 'num1 num2'): ");
    scanf("%d %d", &body, &head);
    makeArrow(body,head);
}