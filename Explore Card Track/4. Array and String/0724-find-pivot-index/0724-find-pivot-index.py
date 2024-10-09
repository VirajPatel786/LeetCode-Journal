class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        """
        Finds the pivot index in the list `nums` where the sum of elements to the left
        is equal to the sum of elements to the right. Returns -1 if no such index exists.

        Parameters:
        nums (List[int]): A list of integers.

        Returns:
        int: The pivot index or -1 if no such index exists.
        """
        # Calculate the total sum of the array
        total_sum = sum(nums)
        left_sum = 0

        # Iterate through the array to find the pivot index
        for i, num in enumerate(nums):
            # Check if the left sum equals the right sum (right sum is total_sum - left_sum - current num)
            if left_sum == total_sum - left_sum - num:
                return i
            # Update the left sum to include the current number
            left_sum += num

        # If no pivot index is found, return -1
        return -1
