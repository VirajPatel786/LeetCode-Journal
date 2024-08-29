/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if ((headA == NULL) || (headB == NULL)) {
        return NULL;
    }
    struct ListNode *pointerA = headA, *pointerB = headB;

    while (pointerA != pointerB) {
        pointerA = (pointerA != NULL) ? pointerA->next : headB;
        pointerB = (pointerB != NULL) ? pointerB->next : headA;
    }

    return pointerA;
}