/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Recursively sums up node values at each level.
 *
 * @param root (TreeNode*): The current node.
 * @param sums (int[]): Array to store the sum of node values at each level.
 * @param lvl (int): The current level in the tree.
 */
void sumup(struct TreeNode *root, int sums[], int lvl) {
    if (!root) return;
    sums[lvl] += root->val;
    sumup(root->left, sums, lvl + 1);
    sumup(root->right, sums, lvl + 1);
}

/**
 * @brief Recursively replaces node values with their cousin sums.
 *
 * @param root (TreeNode*): The current node.
 * @param sums (int[]): Array storing the sum of node values at each level.
 * @param lvl (int): The current level in the tree.
 */
void replace(struct TreeNode *root, int sums[], int lvl) {
    if (!root) return;
    
    replace(root->left, sums, lvl + 1);
    replace(root->right, sums, lvl + 1);

    int left = root->left ? root->left->val : 0;
    int right = root->right ? root->right->val : 0;

    // Update left child's value if it exists
    if (left) root->left->val = sums[lvl + 1] - left - right;
    
    // Update right child's value if it exists
    if (right) root->right->val = sums[lvl + 1] - right - left;
}

/**
 * @brief Main function to replace node values in the tree with the sum of cousin node values.
 *
 * @param root (TreeNode*): The root of the binary tree.
 * @return TreeNode*: The modified tree with updated node values.
 */
struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    int sums[100000] = {0};  // Array to store sums of each level (assume max depth <= 100000)
    
    sumup(root, sums, 0);     // First pass: calculate the sum at each level
    replace(root, sums, 0);   // Second pass: replace node values with cousin sums
    
    root->val = 0;            // Root node has no cousins, so set its value to 0
    return root;
}
