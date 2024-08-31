/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head) return NULL;  // Base case: if the list is empty, return NULL
    
    // Recursively call removeElements on the next node
    head->next = removeElements(head->next, val);
    
    // If the current node's value matches 'val', skip this node by returning head->next
    if (head->val == val) return head->next;
    
    // Otherwise, return the current head
    return head;
}