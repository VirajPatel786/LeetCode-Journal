#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 11  // Maximum length of the key + 1 for null terminator
#define HASH_SIZE 100003  // Large prime number to reduce collisions

// Doubly Linked List Node structure to store frequency and keys
typedef struct Node {
    int freq;                 // Frequency of keys in this node
    struct Node* prev;         // Pointer to the previous node
    struct Node* next;         // Pointer to the next node
    char** keys;               // Dynamic array of keys
    int key_count;             // Number of keys stored in the node
    int key_capacity;          // Capacity of the dynamic keys array
} Node;

// Hash map entry structure to map key to its corresponding node
typedef struct {
    char* key;    // Pointer to the key string (no strdup to save memory)
    Node* node;   // Pointer to the node where the key is stored
} HashEntry;

// AllOne structure to manage the doubly linked list and hash table
typedef struct {
    Node* head;   // Dummy head node for the doubly linked list
    Node* tail;   // Dummy tail node for the doubly linked list
    HashEntry* hash_table[HASH_SIZE];  // Hash table for mapping keys to nodes
} AllOne;

/**
 * @brief Hash function to compute the hash value for a given key.
 * 
 * @param key (const char*): The string key to be hashed.
 * 
 * @return (unsigned int): The computed hash value.
 */
unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key != '\0') {
        hash = (hash * 31U) + (unsigned int)(*key);
        key++;
    }
    return hash % HASH_SIZE;
}

/**
 * @brief Creates a new node with the given frequency.
 * 
 * @param freq (int): The frequency value for the new node.
 * 
 * @return (Node*): A pointer to the newly created node.
 */
Node* createNode(int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->freq = freq;
    node->prev = node->next = NULL;
    node->keys = (char**)malloc(sizeof(char*) * 2);  // Initial capacity of 2 keys
    node->key_capacity = 2;
    node->key_count = 0;
    return node;
}

/**
 * @brief Adds a key to the specified node.
 * 
 * @param node (Node*): The node where the key is added.
 * @param key (const char*): The key to be added to the node.
 */
void addKeyToNode(Node* node, const char* key) {
    // Resize the dynamic array if it's full
    if (node->key_count == node->key_capacity) {
        node->key_capacity *= 2;
        node->keys = (char**)realloc(node->keys, sizeof(char*) * node->key_capacity);
    }
    // Store the pointer to the key (no strdup, use original pointer)
    node->keys[node->key_count] = (char*)key;
    node->key_count++;
}

/**
 * @brief Removes a key from the specified node.
 * 
 * @param node (Node*): The node from which the key is removed.
 * @param key (const char*): The key to be removed from the node.
 */
void removeKeyFromNode(Node* node, const char* key) {
    for (int i = 0; i < node->key_count; ++i) {
        // Find the key and remove it by replacing it with the last key
        if (strcmp(node->keys[i], key) == 0) {
            node->keys[i] = node->keys[node->key_count - 1];
            node->key_count--;
            return;
        }
    }
}

/**
 * @brief Inserts a new node after a specified node in the doubly linked list.
 * 
 * @param new_node (Node*): The new node to be inserted.
 * @param prev_node (Node*): The node after which the new node will be inserted.
 */
void addNodeAfter(Node* new_node, Node* prev_node) {
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
}

/**
 * @brief Removes a node if it contains no keys.
 * 
 * @param node (Node*): The node to be removed if it is empty.
 */
void removeNodeIfEmpty(Node* node) {
    if (node->key_count == 0) {
        // Update pointers of adjacent nodes to bypass this node
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
        // Free the dynamic array and the node itself
        free(node->keys);
        free(node);
    }
}

/**
 * @brief Initializes the AllOne structure.
 * 
 * @return (AllOne*): A pointer to the newly initialized AllOne structure.
 */
AllOne* allOneCreate() {
    AllOne* obj = (AllOne*)malloc(sizeof(AllOne));
    obj->head = createNode(0);  // Create a dummy head node
    obj->tail = createNode(0);  // Create a dummy tail node
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    memset(obj->hash_table, 0, sizeof(obj->hash_table));  // Initialize the hash table
    return obj;
}

/**
 * @brief Increments the frequency of a key. If the key doesn't exist, it is added with frequency 1.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @param key (char*): The key whose frequency is incremented.
 */
void allOneInc(AllOne* obj, char* key) {
    unsigned int h = hash(key);
    HashEntry* entry = obj->hash_table[h];

    if (entry != NULL && strcmp(entry->key, key) == 0) {
        // If the key exists, increment its frequency
        Node* current_node = entry->node;
        Node* next_node = current_node->next;

        removeKeyFromNode(current_node, key);  // Remove from current node

        // Create a new node if the next node's frequency is not one more than the current
        if (next_node == obj->tail || next_node->freq != current_node->freq + 1) {
            next_node = createNode(current_node->freq + 1);
            addNodeAfter(next_node, current_node);
        }
        addKeyToNode(next_node, key);
        entry->node = next_node;

        // Remove the current node if it becomes empty
        removeNodeIfEmpty(current_node);
    } else {
        // If the key doesn't exist, add it with frequency 1
        Node* first_node = obj->head->next;
        if (first_node == obj->tail || first_node->freq != 1) {
            first_node = createNode(1);
            addNodeAfter(first_node, obj->head);
        }
        if (entry == NULL) {
            entry = (HashEntry*)malloc(sizeof(HashEntry));
            obj->hash_table[h] = entry;
        }
        entry->key = key;  // Store pointer to the key
        entry->node = first_node;
        addKeyToNode(first_node, key);
    }
}

/**
 * @brief Decrements the frequency of a key. If its frequency reaches 0, the key is removed.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @param key (char*): The key whose frequency is decremented.
 */
void allOneDec(AllOne* obj, char* key) {
    unsigned int h = hash(key);
    HashEntry* entry = obj->hash_table[h];

    if (entry != NULL && strcmp(entry->key, key) == 0) {
        Node* current_node = entry->node;
        Node* prev_node = current_node->prev;

        removeKeyFromNode(current_node, key);  // Remove the key from the current node

        if (current_node->freq == 1) {
            // If frequency is 1, remove the key completely
            free(entry);
            obj->hash_table[h] = NULL;
        } else {
            // Otherwise, move the key to the previous frequency node
            if (prev_node == obj->head || prev_node->freq != current_node->freq - 1) {
                prev_node = createNode(current_node->freq - 1);
                addNodeAfter(prev_node, current_node->prev);
            }
            addKeyToNode(prev_node, key);
            entry->node = prev_node;
        }

        // Remove the current node if it becomes empty
        removeNodeIfEmpty(current_node);
    }
}

/**
 * @brief Returns one key with the maximum frequency. If no key exists, returns an empty string.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @return (char*): A key with the maximum frequency or an empty string if no key exists.
 */
char* allOneGetMaxKey(AllOne* obj) {
    if (obj->tail->prev == obj->head) {
        return "";
    }
    return obj->tail->prev->keys[0];
}

/**
 * @brief Returns one key with the minimum frequency. If no key exists, returns an empty string.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @return (char*): A key with the minimum frequency or an empty string if no key exists.
 */
char* allOneGetMinKey(AllOne* obj) {
    if (obj->head->next == obj->tail) {
        return "";
    }
    return obj->head->next->keys[0];
}

/**
 * @brief Frees the memory used by the AllOne structure.
 * 
 * @param obj (AllOne*): The AllOne structure to be freed.
 */
void allOneFree(AllOne* obj) {
    Node* current = obj->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current->keys);  // Free the dynamic array of keys
        free(current);        // Free the node itself
        current = next;
    }
    free(obj);  // Free the AllOne structure
}


/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char* param_3 = allOneGetMaxKey(obj);
 
 * char* param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/