#include <stdio.h>

/**
 * @brief Computes the Greatest Common Divisor (GCD) of two integers.
 * 
 * This function calculates the GCD of two integers `a` and `b` using 
 * the iterative Euclidean algorithm. It returns the largest integer 
 * that divides both `a` and `b` without leaving a remainder.
 * 
 * @param a (int) The first integer.
 * @param b (int) The second integer.
 * 
 * @return (int) The GCD of `a` and `b`.
 */
int gcd(int a, int b) {
    // Continue looping until the remainder becomes 0
    // The loop will run as long as 'b' is not 0
    while (b != 0) {
        // Store the value of 'b' temporarily
        int temp = b;

        // Update 'b' to be the remainder of a divided by b (a % b)
        b = a % b;

        // Assign the value of 'temp' (which holds the old value of 'b') to 'a'
        a = temp;
    }

    // When b becomes 0, 'a' holds the GCD of the original numbers
    return a;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /**
 * @brief Inserts nodes with the GCD of consecutive nodes in a linked list.
 * 
 * This function traverses a singly linked list and inserts a new node 
 * between each pair of consecutive nodes. The new node contains the 
 * Greatest Common Divisor (GCD) of the values of the two consecutive nodes.
 * 
 * @param head (struct ListNode*) The head pointer to the singly linked list.
 * 
 * @return (struct ListNode*) The modified linked list with GCD nodes inserted.
 */
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    // Pointer to traverse the linked list, starting from the head
    struct ListNode* currentNode = head;
    
    // Continue looping as long as the current node and the next node are not NULL
    while ((currentNode != NULL) && (currentNode->next != NULL)) {
        
        // Allocate memory for a new node that will store the GCD of current and next node's values
        struct ListNode* gcdNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        // Calculate the GCD of the current node's value and the next node's value
        gcdNode->val = gcd(currentNode->val, currentNode->next->val);
        
        // Link the new GCD node to point to the current node's next node
        gcdNode->next = currentNode->next;
        
        // Insert the new GCD node between the current node and the next node
        currentNode->next = gcdNode;
        
        // Move the currentNode pointer forward by two nodes (skip over the inserted GCD node)
        currentNode = currentNode->next->next;
    }
    
    // Return the modified linked list with GCD nodes inserted
    return head;
}