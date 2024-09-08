/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    // Step 1: Calculate the length of the linked list
    int length = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    // Step 2: Calculate the size of each part
    int baseSize = length / k;
    int extraNodes = length % k;

    // Step 3: Create an array to hold the result
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    
    current = head;
    
    // Step 4: Split the list into parts
    for (int i = 0; i < k; i++) {
        result[i] = current;
        int currentPartSize = baseSize + (i < extraNodes ? 1 : 0);
        
        // Move current to the end of the current part
        for (int j = 0; j < currentPartSize - 1; j++) {
            if (current != NULL) {
                current = current->next;
            }
        }
        
        // Break the link to the next part
        if (current != NULL) {
            struct ListNode* nextPart = current->next;
            current->next = NULL;
            current = nextPart;
        }
    }
    
    *returnSize = k;
    return result;
}