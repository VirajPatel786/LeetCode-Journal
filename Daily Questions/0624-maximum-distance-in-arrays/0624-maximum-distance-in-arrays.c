int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int globalMin = arrays[0][0];
    int globalMax = arrays[0][arraysColSize[0] - 1];
    int result = 0;

    for (int i = 1; i < arraysSize; i++) {
        int localMin = arrays[i][0];
        int localMax = arrays[i][arraysColSize[i] - 1];

        // Calculate possible maximum distances
        int dist1 = abs(localMin - globalMax);
        int dist2 = abs(globalMin - localMax);

        // Update the result with the maximum of the current and previous results
        if (dist1 > result) {
            result = dist1;
        }
        if (dist2 > result) {
            result = dist2;
        }

        // Update global min and max
        if (localMin < globalMin) {
            globalMin = localMin;
        }
        if (localMax > globalMax) {
            globalMax = localMax;
        }
    }

    return result;
}