# Deep Learning Multiple Parallel Matrix Multiplications #

### Purpose ###

The purpose of this repository is to get the matrix sum of a series of executions of multiple matrix multiplication operations in parallel.

### How to Run Test Cases ###

* Test cases are present in the "test" folder of this directory
* To compile C file in terminal: **gcc -o matrixmult_multiw_deep matrixmult_multiw_deep.c -Wall -Werror**
    * "-Wall" enables all warning messages and "-Werror" makes all warnings into errors
* To run the program with test cases in terminal, the first line will be treated as a command line command and the following lines will be treated as standard inputs prompted by the program:
    * **./matrixmult_multiw_deep test/A1.txt test/W1.txt test/W2.txt test/W3.txt<br />**
      **test/W4.txt test/W5.txt test/W6.txt test/W7.txt<br />**
      **test/W8.txt<br />**
    * IMPORTANT NOTE: For each line of input following the first line, add a space at the end for functionality reasons
    * The numbers in the W.text file names can vary by valid test file names

### Expected Test Case Results ###

* The following is the test case result of the test case provided above:
    *       RSum = \[<br />
            71350   54770   54770   54770   54770   54770   54770   97080<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            0       0       0       0       0       0       0       0<br />
            ]<br />
            
    * Each PID.out file will consist of a starting message, the file paths of the A/Rsum text file and W text file, and a finishing + exit message
    * It will look similar to this:<br />
        **$ cat 12702.out<br/ >**
        **Starting command 3: child 12702 of parent 12683<br />**
        **A_filepath\[/mnt/c/Users/maske/Desktop/cs149/cs149/A4/test/A1.txt\]<br />**
        **W_filepath\[/mnt/c/Users/maske/Desktop/cs149/cs149/A4/test/W3.txt\]<br />**
        **Finished child 12702 pid of parent 12683<br />**
        **Exited with exitcode = 0**
    * If the program is killed at any point, a PID.err file saying "Killed with signal 15" will be printed to the PID.err file for the killed process
    * It will look similar to this:<br />
        **$ cat 10785.err<br />**
        **Killed with signal 15**
    * The average runtime of three trials for this program was **0.00 seconds**

### Last Modified ###

* Last modified: 11/07/2023

### Contributors + Contact ###

* Reshaj Maskey: reshaj.maskey@sjsu.edu
* Shannon Luu: shannon.luu@sjsu.edu