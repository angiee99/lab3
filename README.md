# Evaluating an arithmetic expression
## Shunting yard

The code solves the problem of calculating the result of a mathematical expression that is passed to the program input through the command line arguments. 
For example, if the program is compiled into the file lab3.exe, it should be run through the command line as follows:

> lab3.exe 1 + 2 * 4+1 [Enter].
Result: 10
Spaces may be present or absent. 

Note: The input data is not checked for correctness, but a syntax tree (AST) should be built to implement it. 

To solve the problem, the sorting station algorithm (shunting yard) is implemented, which allows you to calculate the value of the entered arithmetic expression. 
A custom stack and queue (structs) are used.

The processing of negative numbers, brackets and powers has been added (also without checking for correct input).

###Input and output data

The program is given the arithmetic expression (2 + 4*3) as input through the command line arguments, 
consisting of numbers and symbols +,-,*,/,^,%,(,). 

The output is the result of the calculation (14).


