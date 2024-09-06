class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        numsLength = len(nums)
        result = list()
        numsSet = set(nums)
        for i in range(1, numsLength + 1):
            if (i not in numsSet):
                result.append(i)
        return result
