int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int nthUglyNumber(int n) {
    int* dp = (int*)malloc(n * sizeof(int));  // Dynamically allocate memory for dp array
    dp[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < n; i++) {
        int nextUgly = min(2 * dp[i2], 3 * dp[i3], 5 * dp[i5]);
        dp[i] = nextUgly;

        if (nextUgly == (2 * dp[i2])) {
            i2++;
        }
        if (nextUgly == (3 * dp[i3])) {
            i3++;
        }
        if (nextUgly == (5 * dp[i5])) {
            i5++;
        }
    }

    int result = dp[n - 1];
    free(dp);  // Free the dynamically allocated memory
    return result;
}