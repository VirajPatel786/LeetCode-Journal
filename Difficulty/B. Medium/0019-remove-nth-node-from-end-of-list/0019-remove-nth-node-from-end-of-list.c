/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node and point it to head to handle edge cases easily
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode *first = dummy, *second = dummy;

    // Move first pointer n+1 steps ahead
    for (int i = 0; i < (n + 1); i++) {
        first = first->next;
    }

    // Move both first and second pointers until first reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // Now, second is at the node before the one we want to remove
    second->next = second->next->next;

    // Return the modified list, dummy.next is the new head
    return dummy->next;
}