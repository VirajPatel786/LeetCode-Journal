class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        """
        Count the number of subsets whose bitwise OR equals the maximum possible bitwise OR.
        
        Parameters:
        nums (List[int]): List of integers to form subsets from.
        
        Returns:
        int: The count of subsets with the maximum bitwise OR value.
        """
        # Calculate the maximum possible OR value for the entire array
        max_or = 0
        for num in nums:
            max_or |= num

        # Initialize a count to track how many subsets reach the max OR
        count = 0

        # Backtracking function to explore subsets
        def backtrack(index, current_or):
            nonlocal count

            # If the current OR equals max OR, increment count
            if current_or == max_or:
                count += 1

            # Explore further subsets
            for i in range(index, len(nums)):
                # Include nums[i] in the subset and update current_or
                backtrack(i + 1, current_or | nums[i])

        # Start backtracking from the first element, with an initial OR of 0
        backtrack(0, 0)

        return count
