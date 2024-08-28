# define HASH_MAP_SIZE 2001     // -10^3 to 10^3

int hash(int value) {
    return value + 1000;
}

bool checkIfExist(int* arr, int arrSize) {
    bool hashMap[HASH_MAP_SIZE] = {false};

    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];

        // Check if double exists in hash_map
        if (((num * 2) >= -1000) && ((num * 2) <= 1000) && (hashMap[hash(num * 2)])) {
            return true;
        }

        // Check if half exists in hash_map (only if the number is even)
        if (!(num & 1) && (hash(num / 2) >= 0) && (hash(num / 2) <= 2000) && hashMap[hash(num / 2)]) {
            return true;
        }

        hashMap[hash(num)] = true;
    }
    return false;
}