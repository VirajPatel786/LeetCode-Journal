class Solution:
    def strangePrinter(self, s: str) -> int:
        # Compress the string to remove consecutive duplicates
        compressed_str = []
        for char in s:
            if not compressed_str or compressed_str[-1] != char:
                compressed_str.append(char)

        n = len(compressed_str)
        
        # Initialize the DP table
        dp = [[0] * n for _ in range(n)]
        
        # Base case: single character requires one turn
        for i in range(n):
            dp[i][i] = 1
        
        # Fill the DP table
        for length in range(2, n + 1):  # length of the substring
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = dp[i + 1][j] + 1  # Initial assumption: print the first character separately
                for k in range(i + 1, j + 1):
                    if compressed_str[k] == compressed_str[i]:
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j])
        
        return dp[0][n - 1]