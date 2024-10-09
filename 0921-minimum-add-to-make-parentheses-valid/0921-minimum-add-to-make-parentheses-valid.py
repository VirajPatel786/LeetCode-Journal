class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        """
        Function to calculate the minimum number of parentheses additions
        required to make the string valid.

        Parameters:
        s (str): A string consisting of '(' and ')'

        Returns:
        int: The minimum number of parentheses to be added
        """

        open_parentheses = 0  # Counter for unbalanced '(' parentheses
        close_parentheses = 0  # Counter for unbalanced ')' parentheses

        # Iterate through each character in the string
        for ch in s:
            if ch == '(':  # If it's an opening parenthesis
                open_parentheses += 1  # Increase the count for '('
            elif ch == ')':
                if open_parentheses > 0:
                    # If there's an unmatched '(', match it with the current ')'
                    open_parentheses -= 1
                else:
                    # If no unmatched '(', increment the ')' counter
                    close_parentheses += 1

        # The total number of unmatched parentheses is the sum of unmatched '(' and ')'
        return open_parentheses + close_parentheses
