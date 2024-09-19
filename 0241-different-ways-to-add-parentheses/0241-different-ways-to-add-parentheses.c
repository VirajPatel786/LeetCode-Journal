#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure to store the result array and its size.
 * 
 * This structure holds an array of integers (`data`) and the number of elements (`size`) in the array.
 */
typedef struct {
    int *data;  ///< Dynamically allocated array to hold results
    int size;   ///< Number of elements in the result array
} ResultArray;

/**
 * @brief Adds a result to the ResultArray structure.
 * 
 * @param arr Pointer to the ResultArray where results are stored.
 * @param result The integer result to be added to the array.
 */
void add_result(ResultArray *arr, int result) {
    arr->data = (int *)realloc(arr->data, (arr->size + 1) * sizeof(int));  // Resize array
    arr->data[arr->size++] = result;  // Add the result and increment the size
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
 * @param expression A string representing the mathematical expression (e.g., "2*3-4*5").
 * @param returnSize Pointer to an integer where the size of the returned result array will be stored.
 * 
 * @return A dynamically allocated array of integers containing all possible results. 
 * The size of the array is stored in `returnSize`. The caller is responsible for freeing the returned array.
 */
int* diffWaysToCompute(char* expression, int* returnSize) {
    // Initialize a ResultArray structure to store the results
    ResultArray results;
    results.data = NULL;
    results.size = 0;

    int length = strlen(expression);  // Length of the input expression string

    // Iterate through the expression to find operators and split at each one
    for (int i = 0; i < length; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            // Split the expression into left and right parts
            char left_expr[20], right_expr[20];  // Buffers for left and right sub-expressions
            strncpy(left_expr, expression, i);   // Copy left part of the expression
            left_expr[i] = '\0';                 // Null-terminate left expression
            strcpy(right_expr, expression + i + 1);  // Copy right part of the expression

            // Recursively compute results for the left and right sub-expressions
            int leftSize, rightSize;
            int* left = diffWaysToCompute(left_expr, &leftSize);
            int* right = diffWaysToCompute(right_expr, &rightSize);

            // Combine the results from left and right using the current operator
            for (int j = 0; j < leftSize; j++) {
                for (int k = 0; k < rightSize; k++) {
                    int result;
                    if (expression[i] == '+') {
                        result = left[j] + right[k];
                    } else if (expression[i] == '-') {
                        result = left[j] - right[k];
                    } else if (expression[i] == '*') {
                        result = left[j] * right[k];
                    }
                    add_result(&results, result);  // Store the combined result
                }
            }

            // Free memory allocated for the left and right sub-expression results
            free(left);
            free(right);
        }
    }

    // Base case: If no operators are found, treat the expression as a number
    if (results.size == 0) {
        int value = atoi(expression);  // Convert the expression to an integer
        add_result(&results, value);   // Add the number to the results array
    }

    // Set the return size and return the result array
    *returnSize = results.size;
    return results.data;
}