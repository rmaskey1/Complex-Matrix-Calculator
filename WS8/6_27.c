/**
 * Description: 6.27 LAB: Count characters - functions
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 10/21/2023
 * Creation date: 10/21/2023
 **/

/*
 * Write a program whose input is a character and a string, and whose output indicates the number of times the
 * character appears in the string. The output should include the input character and use the plural form, n's, if
 * the number of times the characters appears is not exactly 1. Assume that the string does not contain spaces and will
 * always contain less than 50 characters.

    Ex: If the input is:

    n Monday

    the output is:

    1 n

    Ex: If the input is:

    z today

    the output is:

    0 z's

    Ex: If the input is:

    p Happy

    the output is:

    2 p's

    Case matters. n is different than N.

    Ex: If the input is:

    n Nobody

    the output is:

    0 n's

    The program must define and call the following function that takes the input string and character as parameters, and returns the number of times the input character appears in the input string.
    int CalcNumCharacters(char* userString, char userChar)

 */

#include <stdio.h>
#include <string.h>

int calcNumCharacters(char* userString, char userChar) {
   int count = 0;
   for(int i = 0; i < sizeof(userString); i++) {
      if(userChar == userString[i]) {
         count++;
      }
   }
   return count;
}

int main(void) {

   printf("Input:\n");
   char str[100];
   fgets(str, 100, stdin);
   char *token = strtok(str, " ");
   char userChar = *token;
   token = strtok(NULL, " ");
   char* userString = token;
   int count = calcNumCharacters(userString, userChar);
   if(count == 1) {
      printf("%d %c\n", count, userChar);
   }
   else {
      printf("%d %c's\n", count, userChar);
   }
   return 0;
}
