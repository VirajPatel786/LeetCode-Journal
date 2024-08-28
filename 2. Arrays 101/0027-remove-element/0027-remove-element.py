class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        numsLength = len(nums) - 1
        while (numsLength >= 0):
            if (nums[numsLength] == val):
                nums.pop(numsLength)
            numsLength -= 1
        return len(nums)
        