bool validMountainArray(int* arr, int arrSize){
    if (arrSize < 3) {
        return false;
    }

    int i = 0, j = arrSize - 1;

    while ((i < (arrSize - 1)) && (arr[i] < arr[i + 1])) {
        i++;
    }

    while ((j > 0) && (arr[j] < arr[j - 1])) {
        j--;
    }

    return ((i==j) && (i != 0) && (j != (arrSize - 1)));
}