/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>

/**
 * @brief Determine if two binary trees are flip equivalent.
 *
 * @param root1 (struct TreeNode*): The root of the first binary tree.
 * @param root2 (struct TreeNode*): The root of the second binary tree.
 *
 * @return (bool): True if the trees are flip equivalent, otherwise False.
 */
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    // Base cases
    if (!root1 && !root2) return true;
    if (!root1 || !root2 || root1->val != root2->val) return false;
    
    // Check if trees are flip equivalent without flip and with flip
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}
