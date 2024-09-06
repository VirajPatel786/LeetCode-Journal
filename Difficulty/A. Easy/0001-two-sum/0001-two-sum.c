#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

// Define a structure for the hash table nodes
typedef struct {
    int key;   // Stores the element value
    int value; // Stores the index of the element
} HashNode;

// Hash function to map values to keys
int hashFunction(int key, int size) {
    return abs(key) % size;
}

// Find the index of the key in the hash table (or return -1 if not found)
int find(HashNode* hashTable, int size, int key) {
    int hashIndex = hashFunction(key, size);
    while (hashTable[hashIndex].key != INT_MIN) {
        if (hashTable[hashIndex].key == key) {
            return hashTable[hashIndex].value;
        }
        hashIndex = (hashIndex + 1) % size;
    }
    return -1;
}

// Insert a key-value pair into the hash table
void insert(HashNode* hashTable, int size, int key, int value) {
    int hashIndex = hashFunction(key, size);
    while (hashTable[hashIndex].key != INT_MIN) {
        hashIndex = (hashIndex + 1) % size;
    }
    hashTable[hashIndex].key = key;
    hashTable[hashIndex].value = value;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate space for the result (2 indices)
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Create a hash table with size approximately 2 times the input array
    HashNode* hashTable = (HashNode*)malloc(numsSize * 2 * sizeof(HashNode));
    
    // Initialize the hash table keys to INT_MIN to indicate empty slots
    for (int i = 0; i < numsSize * 2; i++) {
        hashTable[i].key = INT_MIN;
        hashTable[i].value = -1;
    }

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Try to find the complement in the hash table
        int complementIndex = find(hashTable, numsSize * 2, complement);
        if (complementIndex != -1) {
            // If complement is found, return the indices
            result[0] = complementIndex;
            result[1] = i;
            free(hashTable); // Free the allocated hash table memory
            return result;
        }

        // Insert the current number and its index into the hash table
        insert(hashTable, numsSize * 2, nums[i], i);
    }

    // Free the hash table
    free(hashTable);

    // If no solution is found (though problem guarantees one solution)
    return NULL;
}
