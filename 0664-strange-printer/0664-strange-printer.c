// Helper function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

int strangePrinter(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Compress the string to remove consecutive duplicates
    char* compressed_str = (char*)malloc((n + 1) * sizeof(char));
    int compressed_len = 0;
    compressed_str[compressed_len++] = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            compressed_str[compressed_len++] = s[i];
        }
    }
    compressed_str[compressed_len] = '\0';

    // Allocate DP table
    int dp[100][100] = {0};

    // Base case: single character requires one turn
    for (int i = 0; i < compressed_len; i++) {
        dp[i][i] = 1;
    }

    // Fill the DP table
    for (int length = 2; length <= compressed_len; length++) {
        for (int i = 0; i <= compressed_len - length; i++) {
            int j = i + length - 1;
            dp[i][j] = dp[i + 1][j] + 1;  // Initial assumption: print the first character separately
            for (int k = i + 1; k <= j; k++) {
                if (compressed_str[k] == compressed_str[i]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
    }

    int result = dp[0][compressed_len - 1];

    // Free allocated memory
    free(compressed_str);

    return result;
}