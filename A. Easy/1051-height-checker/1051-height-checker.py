class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        count = 0
        expectedHeights = sorted(heights)
        for expectedHeight, height in zip(expectedHeights, heights):
            if (expectedHeight != height):
                count += 1
        return count
        