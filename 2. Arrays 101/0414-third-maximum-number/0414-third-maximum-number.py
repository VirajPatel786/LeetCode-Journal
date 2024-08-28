class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        Max1 = Max2 = Max3 = -(2**31) - 1

        for num in nums:
            if((num == Max1) or (num == Max2) or (num == Max3)):
                continue
            
            if (num > Max1):
                Max3 = Max2
                Max2 = Max1
                Max1 = num
            elif (num > Max2):
                Max3 = Max2
                Max2 = num
            elif (num > Max3):
                Max3 = num
        
        if (Max3 == -(2**31) - 1):
            return Max1
        return Max3
        
        