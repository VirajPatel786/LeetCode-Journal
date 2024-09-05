class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Create a dictionary to store the numbers and their indices
        seen = {}
        
        # Iterate over the array
        for i, num in enumerate(nums):
            # Calculate the complement
            complement = target - num
            
            # If complement exists in the hash map, return the indices
            if complement in seen:
                return [seen[complement], i]
            
            # Otherwise, add the number and its index to the hash map
            seen[num] = i