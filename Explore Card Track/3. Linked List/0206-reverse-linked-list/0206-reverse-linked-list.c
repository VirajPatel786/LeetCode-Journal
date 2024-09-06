/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    // Initialize previous pointer to NULL since the new head's next will be NULL
    struct ListNode *prev = NULL;
    // Initialize current pointer to the head of the list
    struct ListNode *current = head;
    // Initialize next pointer to NULL
    struct ListNode* nextNode = NULL;

    // Traverse the list
    while (current != NULL) {
        // Store the next node before changing the link
         nextNode = current->next;
        // Reverse the current node's pointer to point to the previous node
        current->next = prev;
        // Move the previous pointer forward to the current node
        prev = current;
        // Move to the next node in the original list
        current = nextNode;
    }

    // After the loop, prev will point to the new head of the reversed list
    return prev;
}