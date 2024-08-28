class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [0] * n
        dp[0] = 1

        i2, i3, i5 = 0, 0, 0  # Initializing pointers for multiples of 2, 3, and 5

        for i in range(1, n):
            next_ugly = min(2 * dp[i2], 3 * dp[i3], 5 * dp[i5])
            dp[i] = next_ugly

            if next_ugly == 2 * dp[i2]:
                i2 += 1
            if next_ugly == 3 * dp[i3]:
                i3 += 1
            if next_ugly == 5 * dp[i5]:
                i5 += 1

        return dp[-1]
