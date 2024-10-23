#include <stdbool.h>
#include <string.h>

/**
 * @brief Parses and evaluates a boolean expression.
 *
 * The boolean expression can contain 't' for true, 'f' for false, and the logical operators
 * '!', '&', and '|' enclosed by parentheses. It evaluates the expression following the logical rules.
 *
 * @param expression (char*): A valid boolean expression string to be evaluated.
 *
 * @return (bool): Returns true if the expression evaluates to true, false otherwise.
 */
bool parseBoolExpr(char* expression) {
    // Stack to hold characters.
    char stack[20000];
    int top = -1;  // Stack pointer
    
    // Iterate over each character in the expression.
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        
        if (ch == ')') {  // End of a sub-expression.
            // We'll collect all the sub-expression results.
            bool hasTrue = false, hasFalse = false;
            
            // Pop the stack until we find '('
            while (stack[top] != '(') {
                char val = stack[top--];  // Pop the stack
                if (val == 't') hasTrue = true;
                if (val == 'f') hasFalse = true;
            }
            
            // Pop '(' from the stack
            top--;
            
            // Get the operator from the stack
            char op = stack[top--];
            
            // Process according to the operator
            char result;
            if (op == '!') {
                result = hasTrue ? 'f' : 't';  // NOT operation
            } else if (op == '&') {
                result = hasFalse ? 'f' : 't';  // AND operation (true if no 'f')
            } else if (op == '|') {
                result = hasTrue ? 't' : 'f';  // OR operation (true if any 't')
            }
            
            // Push the result back onto the stack
            stack[++top] = result;
        }
        else if (ch != ',') {
            // Push every character except commas
            stack[++top] = ch;
        }
    }
    
    // The final result is on top of the stack
    return stack[top] == 't';
}
