class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        countMax, countTemp = 0, 0
        for num in nums:
            if num == 1:
                countTemp += 1
            else:
                if countTemp > countMax:
                    countMax = countTemp
                countTemp = 0
        if countTemp > countMax:
                    countMax = countTemp
        return countMax 
        