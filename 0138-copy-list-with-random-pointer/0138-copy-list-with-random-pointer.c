#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

/**
 * @brief Structure to represent a simple hash map (linked list style) to store original node to copy node mapping.
 */
struct HashMap {
    struct Node* original; // Pointer to the original node.
    struct Node* copy;     // Pointer to the corresponding copied node.
    struct HashMap* next;  // Pointer to the next mapping in the hash map (linked list style).
};

/**
 * @brief Function to create a new Node with a given value.
 *
 * @param val The integer value to be assigned to the new Node.
 * @return struct Node* A pointer to the newly created Node.
 */
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node.
    newNode->val = val;      // Set the node's value.
    newNode->next = NULL;    // Initialize the next pointer to NULL.
    newNode->random = NULL;  // Initialize the random pointer to NULL.
    return newNode;          // Return the new node.
}

/**
 * @brief Inserts a mapping (original node -> copy node) into the hash map.
 *
 * @param map Pointer to the pointer to the head of the hash map.
 * @param original Pointer to the original node.
 * @param copy Pointer to the copied node.
 */
void insertHashMap(struct HashMap** map, struct Node* original, struct Node* copy) {
    struct HashMap* newEntry = (struct HashMap*)malloc(sizeof(struct HashMap));  // Create a new hash map entry.
    newEntry->original = original;   // Set the original node.
    newEntry->copy = copy;           // Set the copy node.
    newEntry->next = *map;           // Link the new entry to the existing hash map.
    *map = newEntry;                 // Update the map to point to the new entry.
}

/**
 * @brief Finds the copy node corresponding to an original node in the hash map.
 *
 * @param map The head of the hash map.
 * @param original The original node to find.
 * @return struct Node* The copied node corresponding to the original node.
 */
struct Node* findInHashMap(struct HashMap* map, struct Node* original) {
    while (map) {
        if (map->original == original) {  // If the original node matches the one in the map.
            return map->copy;             // Return the corresponding copied node.
        }
        map = map->next;  // Move to the next entry in the hash map.
    }
    return NULL;  // Return NULL if the original node is not found.
}

/**
 * @brief Frees the memory allocated for the hash map.
 *
 * @param map The head of the hash map to be freed.
 */
void freeHashMap(struct HashMap* map) {
    struct HashMap* temp;
    while (map) {
        temp = map;          // Store the current map entry.
        map = map->next;     // Move to the next entry in the map.
        free(temp);          // Free the current entry.
    }
}

/**
 * @brief Creates a deep copy of a linked list with random pointers.
 *
 * @param head Pointer to the head of the original linked list.
 * @return struct Node* Pointer to the head of the deep-copied linked list.
 */
struct Node* copyRandomList(struct Node* head) {
    if (!head) {
        return NULL;  // If the input list is empty, return NULL.
    }
    
    struct HashMap* map = NULL;  // Hash map to store the mapping from original nodes to copied nodes.
    struct Node* current = head; // Pointer to traverse the original linked list.

    // First pass: Create copies of each node and store the original->copy mapping in the hash map.
    while (current) {
        struct Node* copyNode = createNode(current->val);  // Create a copy of the current node.
        insertHashMap(&map, current, copyNode);            // Store the mapping in the hash map.
        current = current->next;  // Move to the next node in the original list.
    }
    
    // Second pass: Set the next and random pointers for each copied node.
    current = head;  // Reset the current pointer to the head of the original list.
    while (current) {
        struct Node* copyNode = findInHashMap(map, current);  // Find the copied node for the current original node.
        
        // Set the next pointer for the copied node.
        if (current->next) {
            copyNode->next = findInHashMap(map, current->next);  // Set the copied node's next pointer.
        }
        
        // Set the random pointer for the copied node.
        if (current->random) {
            copyNode->random = findInHashMap(map, current->random);  // Set the copied node's random pointer.
        }
        
        current = current->next;  // Move to the next node in the original list.
    }
    
    // Return the head of the copied linked list.
    struct Node* copiedHead = findInHashMap(map, head);

    // Free the memory used by the hash map to prevent memory leaks.
    freeHashMap(map);
    
    return copiedHead;
}
