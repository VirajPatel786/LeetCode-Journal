/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    int length = 1;
    struct ListNode* current = head;
    while (current->next) {
        current = current->next;
        length++;
    }
    struct ListNode* tail = current;

    k = k % length;
    if (k == 0) {
        return head;
    }
    
    tail->next = head;

    int steps_to_new_tail = length - k;
    struct ListNode* new_tail = head;

    for (int i = 0; i < steps_to_new_tail - 1; i++) {
        new_tail = new_tail->next;
    }

    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}