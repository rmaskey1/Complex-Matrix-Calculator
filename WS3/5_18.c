/**
 * file: 5_18.c
 * author: Reshaj Maskey
 * description: program that returns the middle number of a list of inputted integers
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("Input:\n");
    char str[100];
    char tmp[100];
    fgets(str, 100, stdin);
    strcpy(tmp, str);
    char* token = strtok(str, " ");
    int count = 0;
    while(token != NULL) {
        if(atoi(token) < 0) {
            break;
        }
        count++;
        token = strtok(NULL, " ");
    }
    //printf("%d\n", count);
    if(count >= 11) {
        //printf("Too many numbers\n");
    }
    else {
        int middle = (count/2)+1;
        //printf("%d\n", middle);
        char* token2 = strtok(tmp, " ");
        //printf("%s\n", token2);
        int i = 0;
        while(token2 != NULL && i < middle-1) {
            //printf("%s\n", token2);
            i++;
            token2 = strtok(NULL, " ");
            //printf("%s\n", token2);
        }
        printf("Middle item: %s\n", token2);
    }
}