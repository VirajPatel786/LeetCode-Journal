int* createSet(int* arr, int arrSize, int maxValue) {
    // Step 1: Check if there is a larger value in the `nums` array.
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];  // Update `maxValue` if `arr[i]` is larger.
        }
    }

    // Step 2: Allocate memory for the set array using `calloc`.
    // `maxValue + 1` ensures we can mark elements from 0 up to `maxValue`.
    int* arrSet = (int*)calloc(maxValue + 1, sizeof(int));

    // Step 3: Mark the values present in the input array `arr`.
    for (int i = 0; i < arrSize; i++) {
        arrSet[arr[i]] = 1;  // Mark the presence of arr[i] in the set array.
    }

    // Step 4: Return the set array.
    return arrSet;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    // Step 1: Find the maximum value in the linked list.
    int maxValue = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        if (temp->val > maxValue) {
            maxValue = temp->val;  // Update maxValue with the largest value from the linked list.
        }
        temp = temp->next;
    }

    // Step 2: Create a set from the `nums` array using the maximum value from the linked list.
    // The createSet function will adjust `maxValue` if any value in `nums` is larger.
    int* numsSet = createSet(nums, numsSize, maxValue);

    // Step 3: Create a dummy node to handle cases where the head of the list needs to be removed.
    struct ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyNode->val = 0;  // Dummy node's value is arbitrary (not used).
    dummyNode->next = head;

    // Step 4: Initialize a pointer to traverse the list (starting from the dummy node).
    struct ListNode* currNode = dummyNode;

    // Step 5: Traverse the linked list and remove nodes with values present in `numsSet`.
    while (currNode->next != NULL) {
        // If the next node's value is in `numsSet`, remove the node by skipping it.
        if (numsSet[currNode->next->val]) {
            temp = currNode->next;  // Temporarily store the node to be deleted.
            currNode->next = currNode->next->next;   // Remove the node by updating the `next` pointer.
            free(temp);  // Free the removed node's memory.
        } 
        else {
            currNode = currNode->next;  // Move to the next node if no removal occurs.
        }
    }

    // Step 6: Get the head of the modified list (skipping the dummy node).
    struct ListNode* newHead = dummyNode->next;

    // Step 7: Free the dummy node and `numsSet` array to avoid memory leaks.
    free(dummyNode);
    free(numsSet);

    // Step 8: Return the modified list's head.
    return newHead;
}