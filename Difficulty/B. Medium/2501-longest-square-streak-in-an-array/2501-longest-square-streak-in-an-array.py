class Solution:
    def longestSquareStreak(self, nums: list[int]) -> int:
        """
        Find the length of the longest square streak in nums.

        Parameters:
        nums (List[int]): List of integers.

        Returns:
        int: Length of the longest square streak, or -1 if no streak exists.
        """
        # Sort the array to ensure we process elements in increasing order
        nums.sort()
        
        # Store numbers in a set for O(1) lookups
        num_set = set(nums)
        max_streak = 0  # Track the maximum streak length
        
        # Iterate through each number to find possible square chains
        for num in nums:
            current_length = 0  # Initialize current streak length
            current_num = num  # Start the streak with the current number
            
            # Try to build a chain where each next number is the square of the previous
            while current_num in num_set:
                current_length += 1  # Increment the streak length
                current_num *= current_num  # Move to the next square in the chain
            
            # Update max_streak if the current chain is the longest so far and meets the criteria
            if current_length >= 2:
                max_streak = max(max_streak, current_length)
        
        # Return -1 if no valid streak found, otherwise return max streak length
        return max_streak if max_streak >= 2 else -1
