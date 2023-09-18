/**
 * file: 5_19.c
 * author: Reshaj Maskey
 * description: program that returns all values between a two numbers from a list of inputted integers
 */


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Input:\n");
    char str[100];
    fgets(str, 100, stdin);
    char* token = strtok(str, " ");
    int size = atoi(token);
    int arr[size];
    token = strtok(NULL, " ");
    int i = 0;
    while(token != NULL && i < size) {
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    
    printf("Enter range (in format 'lowerBound upperBound'):\n");
    int lower, upper;
    scanf("%d %d", &lower, &upper);

    for(int i = 0; i < size; i++) {
        if(arr[i] <= upper && arr[i] >= lower) {
            printf("%d,", arr[i]);
        }
    }
    printf("\n");
}