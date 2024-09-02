class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        sumChalk = sum(chalk)
        remainder = k % sumChalk
        print(sum(chalk), len(chalk), remainder)
        i = 0
        while i < len(chalk):
            remainder -= chalk[i]
            if remainder < 0:
                return i
            i += 1
