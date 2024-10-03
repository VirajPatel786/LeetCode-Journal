from typing import List

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        """
        Find the length of the smallest subarray whose removal makes the sum of the remaining array divisible by p.

        Parameters:
        nums (List[int]): The list of positive integers.
        p (int): The integer divisor.

        Returns:
        int: The length of the smallest subarray to remove, or -1 if impossible.
        """
        total_sum = sum(nums)
        remainder = total_sum % p
        
        if remainder == 0:
            return 0
        
        # HashMap to store prefix sum mod p and its index
        prefix_mod_map = {0: -1}
        current_sum = 0
        min_len = len(nums)
        
        for i, num in enumerate(nums):
            current_sum += num
            current_mod = current_sum % p
            
            # Check if we have seen the mod that would make this valid
            target_mod = (current_mod - remainder) % p
            
            if target_mod in prefix_mod_map:
                min_len = min(min_len, i - prefix_mod_map[target_mod])
            
            # Update the map with current prefix mod and index
            prefix_mod_map[current_mod] = i
        
        return min_len if min_len < len(nums) else -1
