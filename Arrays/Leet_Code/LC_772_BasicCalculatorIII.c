/**
 * Basic Calculator III using Stacks
 * 
 * Approach:
 * This program evaluates a mathematical expression represented as a string
 * containing non-negative integers, the operators '+', '-', '*', '/', and parentheses '(' and ')'.
 * The approach involves using two stacks to handle operator precedence and parentheses.
 * The expression is processed one character at a time, updating the current number for digits,
 * and performing operations for operators.
 * 
 * - When encountering a digit, the current number is built by accumulating it.
 * - When encountering '(', the current operation and result are pushed onto stacks and reset.
 * - When encountering ')', the expression within the parentheses is evaluated.
 * - For '+', '-', '*', '/', the current number and operation are processed based on precedence.
 * - After processing the entire string, the stack is popped to sum all values, yielding the final result.
 * 
 * Time Complexity:
 * O(n), where n is the length of the string. The string is traversed once, and each
 * character is processed in constant time.
 * 
 * Space Complexity:
 * O(n), in the worst case, where all numbers and operators are pushed onto the stacks.
 * The stack size is proportional to the number of elements in the expression.
 * 
 * @param s - A string representing the mathematical expression to evaluate.
 * @return The evaluated result of the expression.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100000 // Maximum size of the stack

// Stack implementation for numbers
int numStack[MAX_SIZE];
int numTop = -1;

// Function to push a number onto the stack
void pushNum(int num) {
    if (numTop < MAX_SIZE - 1) {
        numStack[++numTop] = num;
    }
}

// Function to pop a number from the stack
int popNum() {
    if (numTop > -1) {
        return numStack[numTop--];
    }
    return 0;
}

// Stack implementation for operators
char opStack[MAX_SIZE];
int opTop = -1;

// Function to push an operator onto the stack
void pushOp(char op) {
    if (opTop < MAX_SIZE - 1) {
        opStack[++opTop] = op;
    }
}

// Function to pop an operator from the stack
char popOp() {
    if (opTop > -1) {
        return opStack[opTop--];
    }
    return '\0';
}

// Function to perform arithmetic operations
int performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to evaluate the expression based on the current stacks
int evaluate() {
    int result = popNum();
    while (opTop >= 0) {
        int b = popNum();
        char op = popOp();
        result = performOperation(b, result, op);
    }
    return result;
}

// Main function to calculate the result of the expression
int calculate(char * s) {
    int currentNumber = 0;
    char operation = '+';
    int i = 0;

    while (s[i] != '\0') {
        // Build the current number if the character is a digit
        if (isdigit(s[i])) {
            currentNumber = (currentNumber * 10) + (s[i] - '0');
        }

        // Handle operators, parentheses, and the end of the string
        if (!isdigit(s[i]) && !isspace(s[i]) || s[i+1] == '\0') {
            if (s[i] == '(') {
                // Push current result and operation onto stacks and reset them
                pushNum(currentNumber);
                pushOp(operation);
                currentNumber = 0;
                operation = '+';
            } else if (s[i] == ')') {
                // Evaluate the expression within parentheses
                if (operation == '+') {
                    pushNum(currentNumber);
                } else if (operation == '-') {
                    pushNum(-currentNumber);
                } else if (operation == '*') {
                    pushNum(popNum() * currentNumber);
                } else if (operation == '/') {
                    pushNum(popNum() / currentNumber);
                }
                currentNumber = evaluate();
                operation = popOp();
            } else {
                // Process current number and operation based on precedence
                if (operation == '+') {
                    pushNum(currentNumber);
                } else if (operation == '-') {
                    pushNum(-currentNumber);
                } else if (operation == '*') {
                    pushNum(popNum() * currentNumber);
                } else if (operation == '/') {
                    pushNum(popNum() / currentNumber);
                }
                operation = s[i];
                currentNumber = 0;
            }
        }
        i++;
    }

    // Process the last number and operation
    if (operation == '+') {
        pushNum(currentNumber);
    } else if (operation == '-') {
        pushNum(-currentNumber);
    } else if (operation == '*') {
        pushNum(popNum() * currentNumber);
    } else if (operation == '/') {
        pushNum(popNum() / currentNumber);
    }

    // Evaluate the final result by summing up the stack
    return evaluate();
}

int main() {
    // Test cases
    char expression1[] = "2*(5+5*2)/3+(6/2+8)";
    int result1 = calculate(expression1);
    printf("Result of \"%s\": %d\n", expression1, result1);

    char expression2[] = "(2+6* 3+5- (3*14/7+2)*5)+3";
    int result2 = calculate(expression2);
    printf("Result of \"%s\": %d\n", expression2, result2);

    return 0;
}
