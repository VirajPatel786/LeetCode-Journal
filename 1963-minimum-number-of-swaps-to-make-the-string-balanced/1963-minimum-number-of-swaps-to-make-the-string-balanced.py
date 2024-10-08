class Solution:
    def minSwaps(self, s: str) -> int:
        """
        Returns the minimum number of swaps to make the string balanced.

        Parameters:
        s (str): The input string consisting of '[' and ']'.

        Returns:
        int: The minimum number of swaps required to balance the string.
        """
        unmatched_open_brackets = 0

        # Traverse the string and count unmatched open brackets.
        for bracket in s:
            if bracket == '[':
                unmatched_open_brackets += 1
            elif unmatched_open_brackets > 0:
                # Found a matching ']', decrement the unmatched open brackets count.
                unmatched_open_brackets -= 1
        
        # We need (unmatched_open_brackets // 2) swaps to balance all unmatched brackets.
        return (unmatched_open_brackets + 1) // 2
