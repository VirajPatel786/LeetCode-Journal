bool isPalindrome(struct ListNode* head) {
    // Edge case: if the list is empty or has only one node, it is a palindrome.
    if (!head || !head->next) {
        return true;
    }

    // Step 1: Find the middle of the linked list using the slow and fast pointers.
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list starting from the slow pointer.
    struct ListNode *prev = NULL, *nextNode = NULL;
    while (slow) {
        nextNode = slow->next; // Store the next node
        slow->next = prev;     // Reverse the link
        prev = slow;           // Move prev to the current node
        slow = nextNode;       // Move slow to the next node
    }

    // Step 3: Compare the first half and the reversed second half of the list.
    struct ListNode *firstHalf = head, *secondHalf = prev;
    while (secondHalf) {  // Compare until the end of the second half
        if (firstHalf->val != secondHalf->val) {
            return false; // Mismatch found, not a palindrome
        }
        firstHalf = firstHalf->next; // Move to the next node in the first half
        secondHalf = secondHalf->next; // Move to the next node in the second half
    }

    // Optional Step 4: Restore the second half of the list (if needed)
    // This step is only necessary if you need to preserve the original list structure
    /*
    prev = NULL;
    while (secondHalf) {
        nextNode = secondHalf->next;
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = nextNode;
    }
    */

    return true; // The list is a palindrome
}