/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* one_step = head;
    struct ListNode* two_step = head;
    while ((two_step != NULL) && (two_step->next != NULL)) {
        two_step = two_step->next->next;
        one_step = one_step->next;
    }
    return one_step;
}