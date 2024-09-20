class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        """
        Compute all possible results from different ways to group numbers and operators.
        
        Parameters:
        expression (str): A string representing the mathematical expression.
        
        Returns:
        List[int]: A list of all possible results.
        """
        # Memoization to store previously computed results for subexpressions
        memo = {}

        def helper(expr):
            if expr in memo:
                return memo[expr]
            
            results = []
            for i, char in enumerate(expr):
                if char in "+-*":
                    # Recursively split and solve for left and right sides
                    left = helper(expr[:i])
                    right = helper(expr[i+1:])
                    
                    # Combine results from left and right using the operator
                    for l in left:
                        for r in right:
                            if char == '+':
                                results.append(l + r)
                            elif char == '-':
                                results.append(l - r)
                            elif char == '*':
                                results.append(l * r)

            # Base case: If the expression is a number, just return it as a list
            if not results:
                results = [int(expr)]

            memo[expr] = results
            return results

        return helper(expression)
        