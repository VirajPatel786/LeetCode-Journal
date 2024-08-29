/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // If either list is empty, there is no intersection
    if ((headA == NULL) || (headB == NULL)) {
        return NULL;
    }

    // Initialize two pointers, starting at the heads of each list
    struct ListNode *pointerA = headA;
    struct ListNode *pointerB = headB;

    // Traverse through both lists
    while (pointerA != pointerB) {
        // Move pointerA to the next node in list A,
        // or to the head of list B if pointerA has reached the end of list A
        pointerA = (pointerA != NULL) ? pointerA->next : headB;

        // Move pointerB to the next node in list B,
        // or to the head of list A if pointerB has reached the end of list B
        pointerB = (pointerB != NULL) ? pointerB->next : headA;
    }

    // When pointerA equals pointerB, they have either met at the intersection node
    // or both are NULL (meaning there is no intersection)
    return pointerA;
}
