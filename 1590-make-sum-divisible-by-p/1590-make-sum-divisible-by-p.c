#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Structure for a hash map node (key-value pair)
 */
typedef struct HashNode {
    int key;               // The key (prefix sum modulo p)
    int value;             // The value (index in the array)
    struct HashNode* next; // Pointer to the next node in case of collisions
} HashNode;

/**
 * @brief Hash map structure
 */
typedef struct HashMap {
    int size;            // Size of the hash table
    HashNode** table;    // Array of pointers to hash nodes
} HashMap;

/**
 * @brief Hash function to calculate the index from the key.
 * 
 * @param key (int): The key (e.g., prefix sum modulo p).
 * @param size (int): Size of the hash table.
 * 
 * @return (unsigned int): The index corresponding to the key.
 */
unsigned int hash(int key, int size) {
    return (unsigned int)(key % size);
}

/**
 * @brief Create a hash map with the specified size.
 * 
 * @param size (int): Size of the hash map.
 * 
 * @return (HashMap*): Pointer to the created hash map.
 */
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->table = (HashNode**)malloc(size * sizeof(HashNode*));
    
    // Initialize all slots of the hash table to NULL
    for (int i = 0; i < size; i++) {
        map->table[i] = NULL;
    }
    return map;
}

/**
 * @brief Insert a key-value pair into the hash map.
 * 
 * @param map (HashMap*): Pointer to the hash map.
 * @param key (int): Key to insert.
 * @param value (int): Value associated with the key.
 */
void insertHashMap(HashMap* map, int key, int value) {
    int index = hash(key, map->size);
    
    // Create a new hash node
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = map->table[index]; // Insert at the beginning of the linked list
    map->table[index] = node;
}

/**
 * @brief Get the value associated with a key in the hash map.
 * 
 * @param map (HashMap*): Pointer to the hash map.
 * @param key (int): The key to search for.
 * 
 * @return (int): The value associated with the key, or -2 if not found.
 */
int getHashMap(HashMap* map, int key) {
    int index = hash(key, map->size);
    HashNode* node = map->table[index];
    
    // Traverse the linked list to find the key
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -2; // Key not found
}

/**
 * @brief Free the memory allocated for the hash map.
 * 
 * @param map (HashMap*): Pointer to the hash map.
 */
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        HashNode* node = map->table[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);  // Free each node in the linked list
        }
    }
    free(map->table); // Free the table itself
    free(map);        // Free the map structure
}

/**
 * @brief Finds the minimum length of subarray that can be removed to make the sum of the array divisible by p.
 * 
 * @param nums (int*): Array of integers.
 * @param numsSize (int): Size of the nums array.
 * @param p (int): The divisor.
 * 
 * @return (int): The length of the smallest subarray to remove, or -1 if not possible.
 */
int minSubarray(int* nums, int numsSize, int p) {
    int totalSum = 0;

    // Calculate total sum modulo p
    for (int i = 0; i < numsSize; i++) {
        totalSum = (totalSum + nums[i]) % p;
    }

    // If total sum is already divisible by p, no need to remove any subarray
    if (totalSum == 0) {
        return 0;
    }

    // Create a hash map for storing (prefix sum mod p) -> index
    int hashSize = numsSize > 100 ? numsSize : 100; // Use numsSize or 100 as hash map size
    HashMap* modMap = createHashMap(hashSize);

    insertHashMap(modMap, 0, -1);  // Initialize for prefix sum mod 0 before the array starts
    int prefixSum = 0;
    int minLength = numsSize;

    // Traverse the array and calculate prefix sums
    for (int i = 0; i < numsSize; i++) {
        // Update prefix sum modulo p
        prefixSum = (prefixSum + nums[i]) % p;

        // Calculate the required modulo to form a valid subarray
        int requiredMod = (prefixSum - totalSum + p) % p;

        // Look for the required prefix sum in the hash map
        int requiredIndex = getHashMap(modMap, requiredMod);
        if (requiredIndex != -2) {
            // If found, update the minimum subarray length
            minLength = (i - requiredIndex < minLength) ? i - requiredIndex : minLength;
        }

        // Insert the current prefix sum and index into the hash map
        insertHashMap(modMap, prefixSum, i);
    }

    freeHashMap(modMap);  // Free the hash map after usage
    return minLength < numsSize ? minLength : -1;  // Return -1 if no valid subarray is found
}

