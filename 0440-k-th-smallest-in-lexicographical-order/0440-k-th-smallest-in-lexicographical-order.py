class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        current = 1  # Start at 1
        count = 1    # We've already counted '1' as the first number
        
        while count < k:
            if current * 10 <= n:
                # Go down to the next child (e.g., 1 -> 10)
                current *= 10
            elif current + 1 <= n and current % 10 != 9:
                # Go to the next sibling (e.g., 1 -> 2)
                current += 1
            else:
                # Move up the tree to parent's next sibling (e.g., 19 -> 2)
                current //= 10
                current += 1
            
            count += 1  # Increment the count as we've moved to the next number
        
        return current