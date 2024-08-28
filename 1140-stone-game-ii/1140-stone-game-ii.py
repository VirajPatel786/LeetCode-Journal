class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        
        # Suffix sum array to get the sum of the remaining piles efficiently
        suffix_sum = [0] * n
        suffix_sum[-1] = piles[-1]
        for i in range(n - 2, -1, -1):
            suffix_sum[i] = suffix_sum[i + 1] + piles[i]
        
        # Memoization table
        dp = [[0] * (n + 1) for _ in range(n)]
        
        def dfs(i, M):
            if i == n:
                return 0
            if dp[i][M] > 0:
                return dp[i][M]
            
            max_stones = 0
            for X in range(1, 2 * M + 1):
                if i + X <= n:
                    max_stones = max(max_stones, suffix_sum[i] - dfs(i + X, max(M, X)))
            
            dp[i][M] = max_stones
            return dp[i][M]
        
        return dfs(0, 1)
        