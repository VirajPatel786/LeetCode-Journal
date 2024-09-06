// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int heightChecker(int* heights, int heightsSize) {
    int count = 0;

    // Allocate memory for expectedHeights and copy the original heights array
    int* expectedHeights = (int*)malloc(heightsSize * sizeof(int));
    for (int i = 0; i < heightsSize; i++) {
        expectedHeights[i] = heights[i];
    }

    // Sort the expectedHeights array
    qsort(expectedHeights, heightsSize, sizeof(int), compare);

    // Count the number of differences between sorted and original arrays
    for (int i = 0; i < heightsSize; i++) {
        if (expectedHeights[i] != heights[i]) {
            count++;
        }
    }

    // Free the allocated memory
    free(expectedHeights);

    return count;
}