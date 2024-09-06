/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    // If the list is empty or has only one node, no reordering is needed.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialize pointers:
    // 'odd' points to the first node in the list (odd-indexed nodes).
    // 'even' points to the second node in the list (even-indexed nodes).
    // 'evenHead' stores the start of the even-indexed list to attach later.
    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *evenHead = even;

    // Traverse the list, reordering nodes to separate odd and even indexed nodes.
    while (even != NULL && even->next != NULL) {
        odd->next = even->next; // Link current odd node to the next odd node
        odd = odd->next;         // Move 'odd' pointer to the next odd node
        even->next = odd->next;  // Link current even node to the next even node
        even = even->next;       // Move 'even' pointer to the next even node
    }

    // After rearranging, link the end of the odd-indexed list to the start of the even-indexed list.
    odd->next = evenHead;

    // Return the modified list's head, which is still the original head node.
    return head;
}