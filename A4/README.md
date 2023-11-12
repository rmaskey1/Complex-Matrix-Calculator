# Multiple Parallel Matrix Multiplications #

### Purpose ###

The purpose of this repository is to execute multiple matrix multiplication operations in parallel. If the given files for matrices are 'A1.txt W1.txt W2.txt W3.txt', the operations that will occur simultaneously are A1\*W1, A1\*W2, A1\*W3.

### How to Run Test Cases ###

* Test cases are present in the "test" folder of this directory
* To compile C file in terminal: **gcc -o matrixmult_multiw matrixmult_multiw.c -Wall -Werror**
    * "-Wall" enables all warning messages and "-Werror" makes all warnings into errors
* To run the program with test cases in terminal: **./matrixmult_multiw test/A1.txt test/W1.txt test/W2.txt test/W3.txt**
    * "The numbers in the text file names can vary by test file names

### Expected Test Case Results ###

* The following is the test case result of the test case provided above:
    *   $ cat 10767.err<br />
        $ cat 10767.out<br />
            Starting command 1: child 10767 of parent 10766<br />
            A1.txt = \[<br />
            10      30      40      50      0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            ]<br />
            W1.txt = \[<br />
            1       3       4       5       1       0       0       0<br />
            2       4       5       0       0       0       0       0<br />
            1       1       5       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            \]<br />
            R = \[<br />
            110     190     390     50      10      0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            \]<br />
            Finished child 10767 pid of parent 10766<br />
            Exited with exitcode = 0<br />
        $ cat 10776.err<br />
        $ cat 10776.out<br />
            Starting command 2: child 10776 of parent 10766<br />
            A1.txt = \[<br />
            10      30      40      50      0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            \]<br />
            W2.txt = \[<br />
            10      3       4       5       1       0       0       0<br />
            20      4       5       0       0       0       0       0<br />
            10      1       5       0       0       0       0       0<br />
            10      0       0       0       0       0       0       0<br />
            20      0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            \]<br />
            R = \[<br />
            1600    190     390     50      10      0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            \]<br />
            Finished child 10776 pid of parent 10766<br />
            Exited with exitcode = 0<br />
        $ cat 10785.err<br />
        $ cat 10785.out<br />
            Starting command 3: child 10785 of parent 10766<br />
            A1.txt = \[<br />
            10      30      40      50      0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            \]<br />
            W3.txt = \[<br />
            1       3       4       5       1       0       0       0<br />
            2       4       5       2       2       0       0       0<br />
            1       1       5       11      12      0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            ]<br />
            R = \[<br />
            110     190     390     550     550     0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            ]<br />
            Finished child 10785 pid of parent 10766<br />
            Exited with exitcode = 0<br />
    * If the program is killed at any point, an .err file saying "Killed with signal 15" will be printed to the .err file for the killed process
    * It will look similar to this:<br />
        **$ cat 10785.err<br />**
        **Killed with signal 15**
    * The average runtime of three trials for this program was **0.00 seconds**

### Last Modified ###

* Last modified: 10/15/2023

### Contributors + Contact ###

* Reshaj Maskey: reshaj.maskey@sjsu.edu
* Shannon Luu: shannon.luu@sjsu.edu