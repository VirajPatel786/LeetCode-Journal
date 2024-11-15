from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        """
        Removes all occurrences of a specified value from the list in-place.

        Parameters:
        nums (List[int]): List of integers to process.
        val (int): The value to remove from the list.

        Returns:
        int: The new length of the list after removing the specified value.
        """
        # Start iterating from the end of the list
        index = len(nums) - 1

        # Traverse the list backwards to avoid shifting elements unnecessarily
        while index >= 0:
            if nums[index] == val:
                nums.pop(index)  # Remove the element at the current index
            index -= 1  # Decrement the index to check the next element

        # Return the new length of the list
        return len(nums)
