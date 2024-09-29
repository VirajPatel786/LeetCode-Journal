#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 11  // Maximum length of the key is 10, plus 1 for the null-terminator
#define HASH_SIZE 10007  // A large prime number for the hash table size

// Doubly Linked List Node structure
typedef struct Node {
    int freq;                 // The frequency this node represents
    struct Node* prev;         // Pointer to the previous node
    struct Node* next;         // Pointer to the next node
    char** keys;               // Dynamic array of keys
    int key_count;             // Number of keys in this node
    int key_capacity;          // Capacity of the keys array
} Node;

// Hash Map entry
typedef struct {
    char key[MAX_KEY_SIZE];    // The key itself (null-terminated string)
    Node* node;                // Pointer to the node that holds the key
} HashEntry;

// AllOne structure
typedef struct {
    Node* head;                // Dummy head node of the doubly linked list
    Node* tail;                // Dummy tail node of the doubly linked list
    HashEntry* hash_table[HASH_SIZE];  // Hash table to map keys to their nodes
} AllOne;

/**
 * @brief Computes a hash value for a given key.
 * 
 * @param key (const char*): The string key to be hashed.
 * @return (unsigned int): The hash value.
 */
unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % HASH_SIZE;
}

/**
 * @brief Creates a new node for the doubly linked list with a given frequency.
 * 
 * @param freq (int): The frequency value for the node.
 * @return (Node*): A pointer to the newly created node.
 */
Node* createNode(int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->freq = freq;
    node->prev = node->next = NULL;
    node->keys = (char**)malloc(sizeof(char*) * 2);  // Initial capacity for 2 keys
    node->key_capacity = 2;
    node->key_count = 0;
    return node;
}

/**
 * @brief Adds a key to a given node.
 * 
 * @param node (Node*): The node to which the key is added.
 * @param key (const char*): The key to be added.
 */
void addKeyToNode(Node* node, const char* key) {
    if (node->key_count == node->key_capacity) {
        node->key_capacity *= 2;
        node->keys = (char**)realloc(node->keys, sizeof(char*) * node->key_capacity);  // Double the capacity
    }
    node->keys[node->key_count] = strdup(key);  // Copy the key string into the node
    node->key_count++;
}

/**
 * @brief Removes a key from a node.
 * 
 * @param node (Node*): The node from which the key will be removed.
 * @param key (const char*): The key to be removed.
 */
void removeKeyFromNode(Node* node, const char* key) {
    for (int i = 0; i < node->key_count; ++i) {
        if (strcmp(node->keys[i], key) == 0) {
            free(node->keys[i]);  // Free the key memory
            node->keys[i] = node->keys[node->key_count - 1];  // Move the last key to this position
            node->key_count--;
            return;
        }
    }
}

/**
 * @brief Adds a new node after a given previous node in the doubly linked list.
 * 
 * @param new_node (Node*): The new node to add.
 * @param prev_node (Node*): The node after which the new node should be inserted.
 */
void addNodeAfter(Node* new_node, Node* prev_node) {
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    if (prev_node->next) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
}

/**
 * @brief Removes a node if it has no keys associated with it.
 * 
 * @param node (Node*): The node to be removed.
 */
void removeNodeIfEmpty(Node* node) {
    if (node->key_count == 0) {
        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }
        free(node->keys);  // Free the dynamic array of keys
        free(node);        // Free the node itself
    }
}

/**
 * @brief Initializes the AllOne structure.
 * 
 * @return (AllOne*): A pointer to the newly created AllOne structure.
 */
AllOne* allOneCreate() {
    AllOne* obj = (AllOne*)malloc(sizeof(AllOne));
    obj->head = createNode(0);  // Dummy head node
    obj->tail = createNode(0);  // Dummy tail node
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    memset(obj->hash_table, 0, sizeof(obj->hash_table));  // Initialize the hash table
    return obj;
}

/**
 * @brief Increments the frequency of a given key in the AllOne structure.
 * If the key does not exist, it is added with a frequency of 1.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @param key (char*): The key whose frequency is incremented.
 */
void allOneInc(AllOne* obj, char* key) {
    unsigned int h = hash(key);
    HashEntry* entry = obj->hash_table[h];

    if (entry && strcmp(entry->key, key) == 0) {
        Node* current_node = entry->node;
        Node* next_node = current_node->next;

        // Remove the key from the current node
        removeKeyFromNode(current_node, key);

        // Move to the next frequency node
        if (next_node == obj->tail || next_node->freq != current_node->freq + 1) {
            next_node = createNode(current_node->freq + 1);
            addNodeAfter(next_node, current_node);
        }
        addKeyToNode(next_node, key);
        entry->node = next_node;

        // Remove the current node if it's empty
        removeNodeIfEmpty(current_node);
    } else {
        // Add a new key with frequency 1
        Node* first_node = obj->head->next;
        if (first_node == obj->tail || first_node->freq != 1) {
            first_node = createNode(1);
            addNodeAfter(first_node, obj->head);
        }

        // Create a new entry in the hash table
        if (!entry) {
            entry = (HashEntry*)malloc(sizeof(HashEntry));
            obj->hash_table[h] = entry;
        }
        strcpy(entry->key, key);
        entry->node = first_node;
        addKeyToNode(first_node, key);
    }
}

/**
 * @brief Decrements the frequency of a given key in the AllOne structure.
 * If the frequency reaches 0, the key is removed from the structure.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @param key (char*): The key whose frequency is decremented.
 */
void allOneDec(AllOne* obj, char* key) {
    unsigned int h = hash(key);
    HashEntry* entry = obj->hash_table[h];

    if (entry && strcmp(entry->key, key) == 0) {
        Node* current_node = entry->node;
        Node* prev_node = current_node->prev;

        // Remove the key from the current node
        removeKeyFromNode(current_node, key);

        if (current_node->freq == 1) {
            // Remove the key completely from the structure
            free(entry);
            obj->hash_table[h] = NULL;
        } else {
            // Move to the previous frequency node
            if (prev_node == obj->head || prev_node->freq != current_node->freq - 1) {
                prev_node = createNode(current_node->freq - 1);
                addNodeAfter(prev_node, current_node->prev);
            }
            addKeyToNode(prev_node, key);
            entry->node = prev_node;
        }

        // Remove the current node if it's empty
        removeNodeIfEmpty(current_node);
    }
}

/**
 * @brief Returns one of the keys with the maximum frequency in the AllOne structure.
 * If no key exists, an empty string is returned.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @return (char*): A key with the maximum frequency or an empty string if no key exists.
 */
char* allOneGetMaxKey(AllOne* obj) {
    if (obj->tail->prev == obj->head) {
        return "";
    }
    return obj->tail->prev->keys[0];  // Return any key from the node with the highest frequency
}

/**
 * @brief Returns one of the keys with the minimum frequency in the AllOne structure.
 * If no key exists, an empty string is returned.
 * 
 * @param obj (AllOne*): The AllOne structure.
 * @return (char*): A key with the minimum frequency or an empty string if no key exists.
 */
char* allOneGetMinKey(AllOne* obj) {
    if (obj->head->next == obj->tail) {
        return "";
    }
    return obj->head->next->keys[0];  // Return any key from the node with the lowest frequency
}

/**
 * @brief Frees the memory used by the AllOne structure.
 * 
 * @param obj (AllOne*): The AllOne structure to be freed.
 */
void allOneFree(AllOne* obj) {
    Node* current = obj->head;
    while (current) {
        Node* next = current->next;
        for (int i = 0; i < current->key_count; i++) {
            free(current->keys[i]);  // Free each key
        }
        free(current->keys);  // Free the dynamic array of keys
        free(current);        // Free the node
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