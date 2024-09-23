#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * @brief Add two numbers represented as linked lists.
 *
 * @param l1 (struct ListNode*): Pointer to the first linked list.
 * @param l2 (struct ListNode*): Pointer to the second linked list.
 *
 * @return struct ListNode*: Pointer to the new linked list representing the sum.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Allocate a dummy node
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    int carry = 0;

    // Traverse both lists
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        // Calculate sum and update carry
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        // Create a new node for the sum
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = sum;
        current->next->next = NULL;
        current = current->next;

        // Move to the next nodes
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    // Return the new list starting from dummy->next
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}