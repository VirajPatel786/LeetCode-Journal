long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long maxArray(long long* arr, int arrSize) {
    long long maxValue = arr[0];
    for (int i = 1; i < arrSize; i++) {
        maxValue = max(arr[i], maxValue);
    }
    return maxValue;
}

long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int m = pointsSize, n = pointsColSize[0];
    long long dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = points[0][i];
    }

    for (int r = 1; r < m; r++) {
        long long left[n];
        long long right[n];

        // Calculate left array
        left[0] = dp[0];
        for (int c = 1; c < n; c++) {
            left[c] = max(left[c - 1] - 1, dp[c]);
        }

        // Calculate right array
        right[n - 1] = dp[n - 1];
        for (int c = n - 2; c >= 0; c--) {
            right[c] = max(right[c + 1] - 1, dp[c]);
        }

        // Update dp array
        for (int c = 0; c < n; c++) {
            dp[c] = points[r][c] + max(left[c], right[c]);
        }
    }
    
    return maxArray(dp, n);
}