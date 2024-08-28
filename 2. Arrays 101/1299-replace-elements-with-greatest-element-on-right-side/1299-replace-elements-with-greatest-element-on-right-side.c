/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int* result = (int*)malloc(arrSize * sizeof(int));
    int largest = -1;
    for (int i = arrSize - 1; i >= 0; i--) {
        result[i] = largest;
        if (arr[i] > largest) largest = arr[i];
    }
    return result;
}