#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Performs the computation based on the given operator.
 * 
 * @param leftOperand: int The first operand.
 * @param rightOperand: int The second operand.
 * @param operator: char The operator ('+', '-', '*').
 * 
 * @return int The result of the computation.
 */
int compute(int leftOperand, int rightOperand, char operator) {
    switch (operator) {
    case '+':
        return leftOperand + rightOperand;
    case '-':
        return leftOperand - rightOperand;
    case '*':
        return leftOperand * rightOperand;
    }
    return 0;  // Should not reach here if the operator is valid
}

/**
 * @brief Checks if the given character is a mathematical operator.
 * 
 * @param c: char The character to check.
 * 
 * @return int 1 if the character is an operator, otherwise 0.
 */
int isOperator(char c) { 
    return c == '+' || c == '-' || c == '*'; 
}

/**
 * @brief Converts a substring of digits into an integer.
 * 
 * @param expression: char* The string containing the digits.
 * @param start: int The starting index of the number in the string.
 * @param end: int The ending index (exclusive) of the number in the string.
 * 
 * @return int The integer represented by the substring.
 */
int parseNumber(char* expression, int start, int end) {
    int number = 0;
    for (int i = start; i < end; i++) {
        number = number * 10 + (expression[i] - '0');  // Convert character to integer
    }
    return number;
}

/**
 * @brief Recursively computes all possible results from different groupings of sub-expressions.
 * 
 * @param expression: char* The string representing the mathematical expression.
 * @param left: int The starting index of the current sub-expression.
 * @param right: int The ending index of the current sub-expression.
 * @param resultSize: int* A pointer to store the number of results found.
 * 
 * @return int* An array of integers containing all possible results.
 */
int* computeWays(char* expression, int left, int right, int* resultSize) {
    // Allocate memory for storing possible results
    int* results = (int*)malloc(10000 * sizeof(int));  // Assuming a fixed size for simplicity
    *resultSize = 0;  // Initialize the size of results

    // Check if the current sub-expression is just a number
    int isNumber = 1;
    for (int i = left; i <= right; i++) {
        if (isOperator(expression[i])) {
            isNumber = 0;
            break;
        }
    }

    // If the sub-expression is a number, convert and return it
    if (isNumber) {
        results[(*resultSize)++] = parseNumber(expression, left, right + 1);  // Parse the number
        return results;
    }

    // Iterate through the sub-expression and split it at each operator
    for (int i = left; i <= right; i++) {
        if (isOperator(expression[i])) {
            int leftResultSize, rightResultSize;

            // Recursively calculate results for the left and right sub-expressions
            int* leftResults = computeWays(expression, left, i - 1, &leftResultSize);
            int* rightResults = computeWays(expression, i + 1, right, &rightResultSize);

            // Combine results from left and right sub-expressions using the current operator
            for (int m = 0; m < leftResultSize; m++) {
                for (int n = 0; n < rightResultSize; n++) {
                    results[(*resultSize)++] = compute(leftResults[m], rightResults[n], expression[i]);
                }
            }

            // Free memory for the left and right results
            free(leftResults);
            free(rightResults);
        }
    }

    return results;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Computes all possible results from different ways to group numbers and operators.
 * 
 * This function recursively evaluates the expression by considering all possible ways to group
 * the numbers and operators. It returns an array of results that the caller must free.
 * 
 * @param expression: char* A string representing the mathematical expression (e.g., "2*3-4*5").
 * @param returnSize: int* Pointer to an integer where the size of the returned result array will be stored.
 * 
 * @return int* A dynamically allocated array of integers containing all possible results. 
 * The size of the array is stored in `returnSize`. The caller is responsible for freeing the returned array.
 */
int* diffWaysToCompute(char* expression, int* returnSize) {
    // Call the recursive function to compute the results
    return computeWays(expression, 0, strlen(expression) - 1, returnSize);
}