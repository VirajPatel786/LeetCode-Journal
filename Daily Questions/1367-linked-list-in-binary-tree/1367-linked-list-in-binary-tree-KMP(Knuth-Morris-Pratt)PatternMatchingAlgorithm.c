/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Helper function to perform DFS on the binary tree while matching 
 * the linked list pattern using the KMP algorithm.
 * 
 * @param pattern        Array representing the linked list values.
 * @param kmp_table      The KMP table for efficient backtracking.
 * @param pattern_len    Length of the pattern array.
 * @param root           Current binary tree node.
 * @param pattern_index  Current index in the pattern array.
 * @return               True if the pattern is found, otherwise false.
 */
bool searchInTree(int* pattern, int* kmp_table, int pattern_len, 
                  struct TreeNode* root, int pattern_index) {
    // Base case: If we've matched the entire pattern, return true.
    if (pattern_index == pattern_len) {
        return true;
    }
    
    // If the current tree node is NULL, return false (no match).
    if (root == NULL) {
        return false;
    }

    // Adjust the pattern index based on the KMP table for efficient backtracking.
    while (pattern_index >= 0 && pattern[pattern_index] != root->val) {
        pattern_index = kmp_table[pattern_index];
    }

    // Recursively search in both left and right subtrees.
    return searchInTree(pattern, kmp_table, pattern_len, root->left, pattern_index + 1) ||
           searchInTree(pattern, kmp_table, pattern_len, root->right, pattern_index + 1);
}

/**
 * Helper function to build the KMP (Knuth-Morris-Pratt) table.
 * 
 * @param pattern      Array representing the linked list values.
 * @param pattern_len  Length of the pattern array.
 * @return             KMP table for efficient pattern matching.
 */
int* buildKMPTable(int* pattern, int pattern_len) {
    // Allocate memory for the KMP table.
    int* kmp_table = (int*)malloc(pattern_len * sizeof(int));

    // First element of KMP table is always -1.
    kmp_table[0] = -1;
    
    // Handle a single-element pattern.
    if (pattern_len == 1) {
        return kmp_table;
    }

    // Build the KMP table for longer patterns.
    kmp_table[1] = 0;  // Second element is always 0.
    int i = 2, prefix_len = 0;

    // Construct the KMP table.
    while (i < pattern_len) {
        if (pattern[i - 1] == pattern[prefix_len]) {
            kmp_table[i++] = ++prefix_len;
        } else if (prefix_len > 0) {
            prefix_len = kmp_table[prefix_len];
        } else {
            kmp_table[i++] = 0;
        }
    }

    return kmp_table;
}

/**
 * Main function to check if the linked list forms a downward path
 * in the binary tree.
 * 
 * @param head  The head of the linked list.
 * @param root  The root of the binary tree.
 * @return      True if the linked list is a subpath in the binary tree, false otherwise.
 */
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    // Step 1: Convert the linked list into an array (pattern) and calculate its length.
    int pattern[10000];
    int pattern_len = 0;
    
    struct ListNode* current = head;
    while (current != NULL) {
        pattern[pattern_len++] = current->val;
        current = current->next;
    }

    // Step 2: Build the KMP table for the pattern.
    int* kmp_table = buildKMPTable(pattern, pattern_len);

    // Step 3: Use DFS to search the pattern in the binary tree.
    bool result = searchInTree(pattern, kmp_table, pattern_len, root, 0);

    // Step 4: Free dynamically allocated memory for the KMP table.
    free(kmp_table);
    
    return result;
}
