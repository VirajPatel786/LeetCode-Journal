from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        """
        This function arranges a list of non-negative integers such that they form the largest number possible.
        
        Parameters:
        nums (List[int]): List of non-negative integers
        
        Returns:
        str: The largest possible number formed by arranging the input numbers
        """
        # Convert all numbers to strings
        str_nums = list(map(str, nums))
        
        # Sort the string numbers using lexicographical comparison with repetition (x*10)
        sorted_str_nums = sorted(str_nums, key=lambda x: x * 10, reverse=True)
        
        # Edge case: if the largest number is "0", return "0"
        if sorted_str_nums[0] == "0":
            return "0"
        
        # Join the sorted string numbers to form the largest number
        return ''.join(sorted_str_nums)
