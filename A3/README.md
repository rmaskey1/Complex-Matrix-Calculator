# Matrix Multiplication #

### Purpose ###

The purpose of this repository is to execute multiple matrix multiplication operations in parallel. If the given files for matrices are 'A1.txt W1.txt W2.txt W3.txt', the operations that will occur simultaneously are A1\*W1, A1\*W2, A1\*W3.

### How to Run Test Cases ###

* Test cases are present in the "test" folder of this directory
* To compile C file in terminal: **gcc -o matrixmult_multiw matrixmult_multiw.c -Wall -Werror**
    * "-Wall" enables all warning messages and "-Werror" makes all warnings into errors
* To run the program with test cases in terminal: **./matrixmult_multiw test/A1.txt test/W1.txt test/W2.txt test/W3.txt**
    * "1" in the text file names can vary by test file names

### Expected Test Case Results ###

* The following is the test case result of the test case provided above:
    *   \$ cat 10767.err\
        \$ cat 10767.out\
            Starting command 1: child 10767 of parent 10766\
            A1.txt = \[\
            10      30      40      50      0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            W1.txt = \[\
            1       3       4       5       1       0       0       0\
            2       4       5       0       0       0       0       0\
            1       1       5       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            R = \[\
            110     190     390     50      10      0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            Finished child 10767 pid of parent 10766\
            Exited with exitcode = 0\
        \$ cat 10776.err\
        \$ cat 10776.out\
            Starting command 2: child 10776 of parent 10766\
            A1.txt = \[\
            10      30      40      50      0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            W2.txt = \[\
            10      3       4       5       1       0       0       0\
            20      4       5       0       0       0       0       0\
            10      1       5       0       0       0       0       0\
            10      0       0       0       0       0       0       0\
            20      0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            R = \[\
            1600    190     390     50      10      0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            Finished child 10776 pid of parent 10766\
            Exited with exitcode = 0\
        \$ cat 10785.err\
        \$ cat 10785.out\
            Starting command 3: child 10785 of parent 10766\
            A1.txt = \[\
            10      30      40      50      0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            \]\
            W3.txt = [\
            1       3       4       5       1       0       0       0\
            2       4       5       2       2       0       0       0\
            1       1       5       11      12      0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            ]\
            R = [\
            110     190     390     550     550     0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            0       0       0       0       0       0       0       0\
            ]\
            Finished child 10785 pid of parent 10766\
            Exited with exitcode = 0\

### Last Modified ###

* Last modified: 9/11/2023

### Contributors + Contact ###

* Reshaj Maskey: reshaj.maskey@sjsu.edu
* Shannon Luu: shannon.luu@sjsu.edu