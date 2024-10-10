class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        """
        Function to calculate the maximum width ramp in the given list.

        Parameters:
        nums (List[int]): List of integers where we need to find the ramp.

        Returns:
        int: Maximum width of the ramp.
        """
        # Initialize a stack to store potential candidates for the smallest index.
        stack = list()

        # Traverse the list and build a decreasing stack to track indices of potential minima.
        for i, num in enumerate(nums):
            # If the stack is empty or the current number is smaller than the number at the index 
            # on the top of the stack, push the current index onto the stack.
            # This ensures we store potential ramp starting points.
            if not stack or nums[stack[-1]] > num:
                stack.append(i)

        # Initialize the result to store the maximum width of the ramp found.
        result = 0

        # Traverse the list in reverse order to find the widest ramp.
        for i, num in reversed(tuple(enumerate(nums))):
            # While the current number can form a valid ramp with the top index of the stack,
            # update the result with the maximum width ramp and pop the index from the stack.
            while stack and nums[stack[-1]] <= num:
                result = max(result, i - stack.pop())

            # If the stack becomes empty, we can stop early as no wider ramp is possible.
            if not stack:
                break

        # Return the maximum width of the ramp found.
        return result
