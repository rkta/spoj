Input specification

The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

Each test case represents one sequence of button presses for a pocket calculator. The sequence consists of non-negative integers and arithmetic operators and ends with an equal sign. It may also contain spaces to improve readability.

The operator / represents integer division, rounded down. You may assume that no test case contains division by zero and that in all test cases all intermediate results are non-negative.

Tip: long long int in C/C++, long in Java or int64 in Pascal is enough for this problem.
Output specification

For each sequence from the input file output the number that would be displayed on the calculator.
Example

Input:
4

1 + 1 * 2 =

29 / 5 =

103 * 103 * 5 =

50 * 40 * 250 + 791 =

Output:
4
5
53045
500791

Hint

The first test case shows that there is no operator precedence.

The second one shows that integer division always rounds down.

The last two outputs are the answers to the two riddles in the problem statement: "shoes" (53045 upside down), and "igloos"(500791 upside down).


https://www.spoj.com/problems/ARITH2/
