class Solution:
    def minimumDeletions(self, s: str) -> int:
        ans = count = 0
        for ch in s:
            if (ch == 'b'):
                count += 1
            elif (count > 0):
                ans += 1
                count -= 1
        return ans

        