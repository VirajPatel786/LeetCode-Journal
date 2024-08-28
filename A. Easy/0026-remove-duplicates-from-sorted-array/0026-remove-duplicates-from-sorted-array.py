class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        i = 0  # Initialize the first pointer to track the last unique element
        
        for j in range(1, len(nums)):  # Start the second pointer from the second element
            if nums[j] != nums[i]:
                i += 1  # Move the first pointer forward
                nums[i] = nums[j]  # Update the position with the new unique element
        
        return i + 1  # The new length is index + 1
        