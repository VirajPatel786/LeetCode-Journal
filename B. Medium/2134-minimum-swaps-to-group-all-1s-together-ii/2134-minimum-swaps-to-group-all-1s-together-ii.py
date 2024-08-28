class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        nTotalOnes = sum(nums)
        if (nTotalOnes == 0) or (nTotalOnes == n):
            return 0
        nMaxOnesSW = nOnesSW = sum(nums[-nTotalOnes:]) 
        for i in range(n):
            nOnesSW += nums[i] - nums[i-nTotalOnes]
            if nOnesSW > nMaxOnesSW:
                nMaxOnesSW = nOnesSW
        return nTotalOnes-nMaxOnesSW
        