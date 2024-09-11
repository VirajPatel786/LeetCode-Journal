int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    int dp[booksSize + 1];
    dp[0] = 0;

    for (int i = 1; i <= booksSize; ++i) {
        int width = 0;
        int height = 0;
        dp[i] = INT_MAX;
        for (int j = i; j > 0; j--) {
            width += books[j - 1][0];
            if (width > shelfWidth) {
                break;
            }
            height = height > books[j - 1][1] ? height : books[j - 1][1];
            dp[i] = dp[i] < dp[j - 1] + height ? dp[i] : dp[j - 1] + height;
        }
    }

    return dp[booksSize];
}