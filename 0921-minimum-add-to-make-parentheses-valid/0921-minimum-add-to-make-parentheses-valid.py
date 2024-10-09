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

        open_parentheses = 0  # Tracks unmatched '(' parentheses
        close_parentheses = 0  # Tracks unmatched ')' parentheses

        # Iterate through each character in the string
        for ch in s:
            if ch == '(':  # For each opening parenthesis
                open_parentheses += 1  # Increment unmatched '(' count
            elif ch == ')' and open_parentheses > 0:
                # If there's an unmatched '(', match it with the current ')'
                open_parentheses -= 1
            else:
                # If no unmatched '(', it's an unmatched closing parenthesis
                close_parentheses += 1

        # The total additions needed are the sum of unmatched '(' and unmatched ')'
        return open_parentheses + close_parentheses
