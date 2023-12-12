# Threading - Multiple Parallel Matrix Multiplications #

### Purpose ###

The purpose of this repository is to get the matrix sum of a series of executions of multiple matrix multiplication operations in parallel using threads.

### How to Run Test Cases ###

* Test cases are present in the "Test" folder of this directory
* To compile C file in terminal:
    **gcc -o matrixmult_multiwa matrixmult_multiwa.c -Wall -Werror**<br />
    **gcc -o matrixmult_threaded matrixmult_threaded.c -Wall -Werror -pthread**<br />
    * "-Wall" enables all warning messages and "-Werror" makes all warnings into errors
* To run the program with test cases in terminal, use "< cmds.txt" to feed the program inputs:
    * **./matrixmult_multiwa Test/A1.txt Test/W1.txt Test/W2.txt Test/W3.txt < cmds.txt<br />**
    * The numbers in the W.text file names can vary by valid test file names

### Expected Test Case Results ###

* The following is the test case result of the test case provided above:
    *   **cat childpid1.out**<br />
            Starting command 1: child 5069 of parent 5068<br />
            A1 = Test/A1.txt<br />
            W1 = Test/W1.txt<br />
            R = \[<br />
            110 190 390 50 10  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            70 150 190 50 10  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            11 19 39  5  1  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            110 190 390 50 10  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            ]<br />
            Finished child 5069 pid of parent 5068<br />
            Exited with exitcode = 0<br />

        **cat childpid2.out**<br />
            Starting command 2: child 5070 of parent 5068<br />
            A1 = Test/A1.txt<br />
            W1 = Test/W2.txt<br />
            R = \[<br />
            1600 190 390 50 10  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            700 150 190 50 10  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            280 19 39  5  1  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            1600 190 390 50 10  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            ]<br />
            Finished child 5070 pid of parent 5068<br />
            Exited with exitcode = 0<br />

        **cat childpid3.out**<br />
            Starting command 3: child 5071 of parent 5068<br />
            A1 = Test/A1.txt<br />
            W1 = Test/W3.txt<br />
            R = \[<br />
            110 190 390 550 550  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            70 150 190 110 70  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            11 19 39 55 55  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            110 190 390 550 550  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            0  0  0  0  0  0  0  0 <br />
            ]<br />
            Finished child 5071 pid of parent 5068<br />
            Exited with exitcode = 0<br />

    * If the program is killed at any point, a PID.err file saying "Killed with signal 15" will be printed to the PID.err file for the killed process
    * It will look similar to this:<br />
        **$ cat 10785.err<br />**
        **Killed with signal 15**
    * The average runtime of three trials for this program was **0.00 seconds**

### Last Modified ###

* Last modified: 12/06/2023

### Contributors + Contact ###

* Reshaj Maskey: reshaj.maskey@sjsu.edu
* Shannon Luu: shannon.luu@sjsu.edu