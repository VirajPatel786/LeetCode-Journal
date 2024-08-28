void insert(int* arr, int arrSize, int index, int val) {
    // Start from the last element and move each element one position to the right
    for (int i = arrSize - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new value at the specified index
    arr[index] = val;
}

void duplicateZeros(int* arr, int arrSize) {
    int i = 0;
    while (i < (arrSize - 1)) {
        if (arr[i] == 0) {
            insert(arr, arrSize, i, 0);
            i++;
        }
        i++;
    }
}