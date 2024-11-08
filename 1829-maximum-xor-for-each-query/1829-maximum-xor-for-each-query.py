from typing import List

class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        """
        Computes the maximum XOR for each query by reversing the order and removing elements
        from the cumulative XOR value without modifying nums directly.
        
        Parameters:
        nums (List[int]): Sorted array of non-negative integers.
        maximumBit (int): Maximum bit length for XOR results.
        
        Returns:
        List[int]: List of integers representing the maximum XOR values for each query.
        """
        # Max possible value with maximumBit bits set to 1
        max_mask = (1 << maximumBit) - 1
        
        # Initialize cumulative XOR
        current_xor = 0
        answer = []
        
        # Traverse nums to calculate cumulative XOR and results
        for num in nums:
            current_xor ^= num  # Update cumulative XOR
            answer.append(max_mask ^ current_xor)  # Compute maximum XOR and store result
        
        # Return results in reverse order
        return answer[::-1]
