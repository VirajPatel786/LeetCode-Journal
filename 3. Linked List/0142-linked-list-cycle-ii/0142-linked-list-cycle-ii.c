/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (!(head) || !(head->next)) {
        return NULL;
    }

    struct ListNode *slow = head, *fast = head;
    int flag = 0;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = 1;
            break;
        }
    }
    if (!flag) {
        return NULL;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}