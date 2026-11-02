OPERATING SYSTEM PRACTICALS - Q1 TO Q22
=======================================

This set covers Sections 1 to 5 of the supplied question bank (Q1-Q22).
Questions from Section 6 onward are intentionally not included.

BASH SCRIPTS (Q1-Q12)
---------------------
Run a script in a Linux terminal with:
    bash q11_square_function.sh

Replace the filename to run another script. Q6-Q8 and Q10-Q12 ask for input
when run. Q9 always prints the numbers 1 to 10, as stated in the question.

C PROGRAMS (Q13-Q22)
--------------------
Compile an ordinary C program with:
    gcc -Wall -Wextra -std=c11 q13_fork_process_ids.c -o q13
    ./q13

Use -pthread for Q18 and Q19:
    gcc -Wall -Wextra -std=c11 q18_posix_pthread.c -o q18 -pthread
    ./q18

Replace the source and executable names for the other programs. Q20-Q22 use
Linux/POSIX process and IPC facilities.

NOTES
-----
- Q6 reports zero separately because zero is neither positive nor negative.
- Q8 checks for division by zero.
- Q12 asks for the filename to check; it does not create the file first.
- Q15-Q17 ask for process burst times. Q17 also asks for the time quantum.
- Q15-Q17 use a maximum of 20 processes. The scheduling examples assume all
  processes arrive at time zero.
- Q21 and Q22 demonstrate communication between a child and parent process.

The programs are kept close to the supplied question statements and use
runtime input where the question bank requests it.
