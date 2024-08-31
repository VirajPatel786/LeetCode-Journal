/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to simplify edge cases where the head needs to be removed.
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;      // The value of the dummy node is arbitrary.
    dummy->next = head;  // The dummy node's next pointer points to the head of the list.

    // Initialize the current pointer to traverse the list, starting from the dummy node.
    struct ListNode *current = dummy;

    // Traverse the list while the next node exists.
    while (current->next != NULL) {
        // Check if the next node's value matches the target value to be removed.
        if (current->next->val == val) {
            // Skip the next node by linking current node to the node after next.
            current->next = current->next->next;
        }
        else {
            // If the next node's value does not match, move the current pointer forward.
            current = current->next;
        }
    }

    // Store the head of the new list, which may have changed.
    head = dummy->next;

    // Free the dummy node, as it was only a placeholder.
    free(dummy);

    // Return the new head of the list.
    return head;
}