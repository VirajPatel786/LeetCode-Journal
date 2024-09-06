class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        numsSquares = list()
        while (left <= right):
            leftSquare = nums[left] ** 2
            rightSquare = nums[right] ** 2
            if (leftSquare > rightSquare):
                numsSquares.append(leftSquare)
                left += 1
            else:
                numsSquares.append(rightSquare)
                right -= 1
        return numsSquares[::-1]
        