/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * @brief Rotates a singly linked list to the right by k positions.
 * 
 * @param head (struct ListNode*): Pointer to the head of the linked list.
 * @param k (int): Number of positions to rotate the list to the right.
 * @return struct ListNode*: Pointer to the new head of the rotated linked list.
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    // Edge case: If the list is empty or k is 0 (no rotation needed), return the original list.
    if (head == NULL || k == 0) {
        return head;
    }

    // Step 1: Find the length of the list and identify the last node (tail).
    int length = 1;  // Initialize the length of the list to 1 (account for the head node).
    struct ListNode* current = head;  // Start traversing from the head.

    // Traverse the list to calculate the length and find the last node.
    while (current->next) {
        current = current->next;  // Move to the next node.
        length++;  // Increment the length.
    }
    struct ListNode* tail = current;  // 'current' is now pointing to the last node (tail).

    // Step 2: Calculate the effective number of rotations using k mod length.
    k = k % length;  // If k is greater than the length, reduce it to within the list's length.
    if (k == 0) {
        return head;  // If no effective rotations needed (k == 0), return the original list.
    }

    // Step 3: Form a circular list by connecting the last node (tail) to the head.
    tail->next = head;  // Create a circular link by connecting the tail to the head.

    // Step 4: Find the new tail, which is at (length - k) steps from the start (old head).
    int steps_to_new_tail = length - k;  // Calculate how many steps to the new tail.
    struct ListNode* new_tail = head;  // Start from the head node.

    // Move the 'new_tail' pointer (length - k - 1) steps forward to get the new tail node.
    for (int i = 0; i < steps_to_new_tail - 1; i++) {
        new_tail = new_tail->next;  // Move to the next node.
    }

    // Step 5: The new head is the node immediately after the new tail.
    struct ListNode* new_head = new_tail->next;

    // Step 6: Break the circular link by setting the new tail's next pointer to NULL.
    new_tail->next = NULL;

    // Step 7: Return the new head of the rotated list.
    return new_head;
}
