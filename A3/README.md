# Matrix Multiplication #

### Purpose ###

The purpose of this repository is to implement a missing operation from the default Linux libraries, matrix multiplication. The program will carry out matrix operations (multiplication and addition) to calculate R = A * W + B, where A is the inputted vector, W is the weights matrix, B is the bias, and R is the resulting vector.

### How to Run Test Cases ###

* Test cases are present in the "test" folder of this directory
* To compile C file in terminal: **gcc -o matrixmult matrixmult -Wall -Werror**
    * "-Wall" enables all warning messages and "-Werror" makes all warnings into errors
* To run the program with test cases in terminal: **./matrixmult test/A1.txt test/W1.txt test/B1.txt**
    * "1" in the text file names will be replaced by the corresponding test case (1, 2, 3, or 4)
    * Use A, W, and B test files of same number/group, do not mix them when testing

### Expected Test Case Results ###

* There are 4 test cases:
    * Result of A1 * W1 + B1 = \[ 111  191  391  51  11 \]
    * Result of A2 * W2 + B2 = \[ 701  151  191  51  11 \]
    * Result of A3 * W3 + B3 = \[ 11  19  39  55  55 \]
    * Result of A4 * W4 + B4 = \[ 201  1  0  0  1 \]

### Last Modified ###

* Last modified: 9/11/2023

### Contributors + Contact ###

* Reshaj Maskey: reshaj.maskey@sjsu.edu
* Shannon Luu: shannon.luu@sjsu.edu