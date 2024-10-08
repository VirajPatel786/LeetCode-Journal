class Solution:
    def minSwaps(self, s: str) -> int:
        """
        Returns the minimum number of swaps to make the string balanced.
        
        Parameters:
        s (str): The input string consisting of '[' and ']'.
        
        Returns:
        int: The minimum number of swaps required to balance the string.
        """
        balance = 0
        min_balance = 0
        
        # Traverse the string to calculate the balance
        for char in s:
            if char == '[':
                balance += 1
            else:
                balance -= 1
            
            # Track the minimum balance encountered
            min_balance = min(min_balance, balance)
        
        # The number of swaps needed is the ceiling of half the negative imbalance
        return (-min_balance + 1) // 2
