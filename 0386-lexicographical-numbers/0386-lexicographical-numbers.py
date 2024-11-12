from typing import List

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        """
        Generates numbers from 1 to n in lexicographical order using an iterative approach.
        
        Parameters:
        n (int): The upper limit of numbers to be included in lexicographical order.

        Returns:
        List[int]: A list of integers from 1 to n in lexicographical order.
        """
        result = []
        current = 1
        
        for _ in range(n):
            # Append the current number to the result list
            result.append(current)
            
            # Try to go to the next lexicographical "child" by multiplying by 10
            if current * 10 <= n:
                current *= 10
            else:
                # If no child is possible, try the next sibling by incrementing
                if current >= n:
                    current //= 10  # Move up to a level where incrementing is possible
                current += 1
                
                # Remove trailing 9s to ensure proper lexicographical order
                while current % 10 == 0:
                    current //= 10
        
        return result
