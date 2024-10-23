class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        """
        Evaluates a boolean expression and returns the result.

        Parameters:
        expression (str): A valid boolean expression string.

        Returns:
        bool: The result of evaluating the expression.
        """
        stack = []
        
        for char in expression:
            if char == ')':  # End of a sub-expression
                sub_expr = []
                
                # Pop characters until we find '('
                while stack[-1] != '(':
                    sub_expr.append(stack.pop())
                
                stack.pop()  # Remove '('
                operator = stack.pop()  # Get the operator ('!', '&', '|')
                
                if operator == '!':
                    # Apply NOT to the single sub-expression
                    result = 'f' if sub_expr[0] == 't' else 't'
                elif operator == '&':
                    # Apply AND to all sub-expressions (True if all are true)
                    result = 't' if all(x == 't' for x in sub_expr) else 'f'
                elif operator == '|':
                    # Apply OR to all sub-expressions (True if at least one is true)
                    result = 't' if any(x == 't' for x in sub_expr) else 'f'
                
                # Push the result of this sub-expression back onto the stack
                stack.append(result)
            elif char != ',':
                # Ignore commas and push everything else onto the stack
                stack.append(char)
        
        # Final result is on top of the stack
        return stack[-1] == 't'

