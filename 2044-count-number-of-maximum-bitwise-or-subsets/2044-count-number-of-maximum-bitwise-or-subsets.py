import functools
import operator

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_bitwise_or = functools.reduce(operator.or_, nums)
        count = 0
        for i in range(1, len(nums) + 1):
            for subset in itertools.combinations(nums, i):
                subset_bitwise_or = functools.reduce(operator.or_, subset)
                if subset_bitwise_or == max_bitwise_or:
                    count += 1
        return count