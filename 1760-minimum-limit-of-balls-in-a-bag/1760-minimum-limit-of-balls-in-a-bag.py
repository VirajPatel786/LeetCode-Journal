from typing import List

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        """
        Minimizes the maximum number of balls in any bag after at most maxOperations.

        Parameters:
        nums (List[int]): List of integers representing the number of balls in each bag.
        maxOperations (int): Maximum number of operations allowed.

        Returns:
        int: The minimum possible penalty (maximum balls in any bag).
        """

        # Binary search to find the minimum penalty
        left, right = 1, max(nums)  # The penalty can range from 1 to the largest bag size

        while left < right:
            mid = (left + right) // 2  # Middle point of the current search range
            
            # Check if the penalty 'mid' is achievable
            if self.canAchieve(nums, maxOperations, mid):
                right = mid  # Try for a smaller penalty
            else:
                left = mid + 1  # Increase the penalty to make it achievable

        # Return the smallest achievable penalty
        return left

    def canAchieve(self, nums: List[int], maxOperations: int, penalty: int) -> bool:
        """
        Determines if it is possible to achieve the given penalty with maxOperations.

        Parameters:
        nums (List[int]): List of integers representing the number of balls in each bag.
        maxOperations (int): Maximum number of operations allowed.
        penalty (int): The current penalty (maximum number of balls allowed in any bag).

        Returns:
        bool: True if the penalty is achievable, False otherwise.
        """
        operations = 0  # Initialize the number of operations performed

        # Iterate through each bag in nums
        for x in nums:
            # Calculate the number of operations needed to reduce the bag size to <= penalty
            operations += (x - 1) // penalty

            # If the operations exceed maxOperations, return False early
            if operations > maxOperations:
                return False

        # If the total operations are within maxOperations, the penalty is achievable
        return True
