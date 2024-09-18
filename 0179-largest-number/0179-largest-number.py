from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        """
        Given a list of non-negative integers, this function arranges them to form the largest number.
        
        Parameters:
        nums (List[int]): List of non-negative integers
        
        Returns:
        str: The largest possible number formed by rearranging the integers
        """
        # Convert numbers to strings for comparison
        nums_str = list(map(str, nums))
        
        # Custom comparator to determine order
        def compare(x, y):
            # Compare based on concatenated strings
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
        
        # Sort based on custom comparator
        nums_str.sort(key=cmp_to_key(compare))
        
        # Join the numbers to form the largest number
        largest_num = ''.join(nums_str)
        
        # Edge case: if the largest number starts with '0', return '0'
        return '0' if largest_num[0] == '0' else largest_num