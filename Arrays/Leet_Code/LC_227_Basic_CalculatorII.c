/**
 * Basic Calculator II using Stack
 * 
 * Approach:
 * This program evaluates a mathematical expression represented as a string
 * containing non-negative integers and the operators '+', '-', '*', and '/'.
 * The approach involves using a stack to handle operator precedence and store
 * intermediate results. The expression is processed one character at a time,
 * updating the current number for digits, and performing operations for operators.
 * 
 * - When a '+' or '-' operator is encountered, the current number (or its negative)
 *   is pushed onto the stack.
 * - For '*' or '/', the top element of the stack is popped, the operation is performed,
 *   and the result is pushed back onto the stack.
 * - After processing the entire string, the stack is popped to sum all values, 
 *   yielding the final result.
 * 
 * Time Complexity:
 * O(n), where n is the length of the string. The string is traversed once, and each
 * character is processed in constant time.
 * 
 * Space Complexity:
 * O(n), in the worst case, where all numbers are pushed onto the stack (e.g., a sequence
 * of additions). The stack size is proportional to the number of elements in the expression.
 * 
 * @param s - A string representing the mathematical expression to evaluate.
 * @return The evaluated result of the expression.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100000 // Maximum size of the stack

int stack[MAX_SIZE];
int top = -1;

void push(int num) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = num;
    }
}

int pop() {
    if (top > -1) {
        return stack[top--];
    }
    return 0;
}

int calculate(char * s) {
    long currentNumber = 0;
    char operation = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            currentNumber = (currentNumber * 10) + (s[i] - '0');
        }

        if (!isdigit(s[i]) && !isspace(s[i]) || s[i+1] == '\0') {
            if (operation == '+') {
                push(currentNumber);
            } else if (operation == '-') {
                push(-currentNumber);
            } else if (operation == '*') {
                int num = pop();
                push(num * currentNumber);
            } else if (operation == '/') {
                int num = pop();
                push(num / currentNumber);
            }
            operation = s[i];
            currentNumber = 0;
        }
        i++;
    }

    int result = 0;
    while (top > -1) {
        result += pop();
    }

    return result;
}
int main() {
    char expression1[] = "3+2*2";
    int result1 = calculate(expression1);
    printf("Result of \"%s\": %d\n", expression1, result1);

    char expression2[] = " 3/2 ";
    int result2 = calculate(expression2);
    printf("Result of \"%s\": %d\n", expression2, result2);

    char expression3[] = " 3+5 / 2 ";
    int result3 = calculate(expression3);
    printf("Result of \"%s\": %d\n", expression3, result3);

    return 0;
}
