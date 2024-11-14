from typing import List

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        """
        Computes the maximum sum of minimum values of n pairs formed from the input array.
        
        Parameters:
        nums (List[int]): List of integers where 2n elements form n pairs.
        
        Returns:
        int: Maximum possible sum of minimum values of each pair.
        """
        
        # Sort the array in ascending order
        nums.sort()
        
        # Initialize the result sum
        result = 0
        
        # Iterate through the sorted array, taking every second element
        # (i.e., the minimum in each consecutive pair in the sorted list)
        for i in range(0, len(nums), 2):
            # Add nums[i], which is the minimum in the sorted (nums[i], nums[i+1]) pair
            result += nums[i]
        
        # Return the final accumulated sum
        return result
