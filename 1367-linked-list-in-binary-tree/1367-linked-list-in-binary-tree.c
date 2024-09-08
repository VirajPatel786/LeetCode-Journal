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
 
// Function to build the pattern array and KMP prefix table from the linked list
void buildPatternAndPrefixTable(struct ListNode* head, int** pattern, int** prefixTable, int* length) {
    // Count the length of the linked list
    struct ListNode* temp = head;
    *length = 0;
    while (temp) {
        (*length)++;
        temp = temp->next;
    }

    // Allocate memory for the pattern and prefix table
    *pattern = (int*)malloc(sizeof(int) * (*length));
    *prefixTable = (int*)malloc(sizeof(int) * (*length));

    // Build the pattern array (linked list values)
    int i = 0;
    while (head) {
        (*pattern)[i] = head->val;
        head = head->next;
        i++;
    }

    // Build the KMP prefix table
    (*prefixTable)[0] = 0;  // First value is always 0
    int patternIndex = 0;  // Tracks matching prefix
    for (i = 1; i < *length; i++) {
        // Adjust patternIndex to the last matched prefix
        while (patternIndex > 0 && (*pattern)[i] != (*pattern)[patternIndex]) {
            patternIndex = (*prefixTable)[patternIndex - 1];
        }

        // If the current characters match, increment the prefix length
        if ((*pattern)[i] == (*pattern)[patternIndex]) {
            patternIndex++;
        }
        (*prefixTable)[i] = patternIndex;  // Set prefix length
    }
}

// DFS search function to find if the pattern exists in the tree
bool searchInTree(struct TreeNode* node, int patternIndex, int* pattern, int* prefixTable, int patternLength) {
    // Base case: if node is NULL, return false
    if (!node) {
        return false;
    }

    // Step 1: Match the current tree node value with the current pattern value
    while (patternIndex > 0 && node->val != pattern[patternIndex]) {
        patternIndex = prefixTable[patternIndex - 1];  // Backtrack in the pattern
    }

    // If values match, move to the next index in the pattern
    if (node->val == pattern[patternIndex]) {
        patternIndex++;
    }

    // Step 2: Check if the entire pattern has been matched
    if (patternIndex == patternLength) {
        return true;  // Full match found
    }

    // Step 3: Recursively search in the left and right subtrees
    return searchInTree(node->left, patternIndex, pattern, prefixTable, patternLength) ||
           searchInTree(node->right, patternIndex, pattern, prefixTable, patternLength);
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    // Step 1: Build the pattern array and KMP prefix table from the linked list
    int* pattern;
    int* prefixTable;
    int patternLength;

    buildPatternAndPrefixTable(head, &pattern, &prefixTable, &patternLength);

    // Step 2: Perform DFS to search for the pattern in the tree
    bool result = searchInTree(root, 0, pattern, prefixTable, patternLength);

    // Free allocated memory
    free(pattern);
    free(prefixTable);

    return result;
}