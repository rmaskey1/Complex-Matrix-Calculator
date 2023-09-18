/**
 * file: 5_19.c
 * author: Reshaj Maskey
 * description: program that returns the two smallest values of an inputted integer list
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Input (first number is size of int list):\n");
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
    int small1 = INT_MAX;
    int small2 = INT_MAX;
    for(int i = 0; i < size; i++) {
        if(arr[i] < small1) {
            small1 = arr[i];
        }
    }
    for(int i = 0; i < size; i++) {
        if(arr[i] < small2 && arr[i] > small1) {
            small2 = arr[i];
        }
    }
    printf("%d and %d\n", small1, small2);

}