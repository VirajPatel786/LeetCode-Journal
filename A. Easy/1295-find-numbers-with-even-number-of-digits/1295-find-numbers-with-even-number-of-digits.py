class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        countEven = 0
        for num in nums:
            if not (len(str(num)) & 1):
                countEven += 1
        return countEven


        