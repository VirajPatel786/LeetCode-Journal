/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

#define LIM 100001  // Maximum limit for nodes in the binary tree, based on problem constraints
#define MAX(a, b) ((a) > (b) ? (a) : (b))  // Macro to compute the maximum of two values

typedef struct TreeNode TreeNode;

/**
 * @brief Main function to compute tree heights after subtree removals for given queries.
 *
 * This function first precomputes the heights and maximum achievable heights for each node
 * in the binary tree using two DFS traversals, then processes each query to return the
 * height of the tree after removing the specified subtree.
 *
 * @param root (TreeNode*): Pointer to the root node of the binary tree.
 * @param queries (int*): Array of queries representing nodes to remove.
 * @param queriesSize (int): Number of queries in the `queries` array.
 * @param returnSize (int*): Pointer to an integer to store the size of the returned array.
 *
 * @return int*: Array of resulting tree heights after each subtree removal query.
 *               The caller is responsible for freeing this memory.
 */
int* treeQueries(TreeNode* root, int* queries, int queriesSize, int* returnSize) {
    // Set the return size to the number of queries
    *returnSize = queriesSize;
    int* answer = malloc(sizeof(int) * queriesSize);  // Array to store results

    // Arrays to store subtree heights and max heights after subtree removal
    int heights[LIM] = {0};  // Heights of subtrees rooted at each node
    int max_height_after_removal[LIM] = {0};  // Max achievable heights after subtree removal

    /**
     * @brief Computes the height of each subtree in the binary tree.
     *
     * This recursive inline function calculates the height of each node's subtree and
     * stores it in the `heights` array. The height of a node is defined as the maximum
     * depth of its left or right subtree plus one.
     *
     * @param node (TreeNode*): Pointer to the current node in the binary tree.
     *
     * @return int: Height of the subtree rooted at the current node.
     */
    inline int calculate_heights(TreeNode* node) {
        if (!node) return 0;  // Base case: empty node has height 0
        // Recursively calculate the height of left and right subtrees
        int left_height = calculate_heights(node->left);
        int right_height = calculate_heights(node->right);
        // Store the calculated height for the current node
        heights[node->val] = MAX(left_height, right_height) + 1;
        return heights[node->val];
    }
    calculate_heights(root);  // Initial call to calculate all heights

    /**
     * @brief Calculates the maximum tree height achievable after removing each subtree.
     *
     * This recursive inline DFS function calculates the maximum achievable height for the
     * tree if the subtree rooted at each node is removed. It uses the precomputed heights
     * of each subtree and stores the result in the `max_height_after_removal` array.
     *
     * @param node (TreeNode*): Pointer to the current node in the binary tree.
     * @param current_depth (int): Depth of the current node from the root.
     * @param current_max_height (int): Maximum height achievable from the root excluding
     *                                  the current subtree.
     */
    inline void calculate_max_heights(TreeNode* node, int current_depth, int current_max_height) {
        if (!node) return;  // Base case: no node to process

        // Store the maximum height achievable if the subtree rooted at `node` is removed
        max_height_after_removal[node->val] = current_max_height;

        // Get heights of left and right subtrees, or zero if subtree is absent
        int left_subtree_height = (node->left) ? heights[node->left->val] : 0;
        int right_subtree_height = (node->right) ? heights[node->right->val] : 0;

        // Calculate new max heights for left and right child nodes if subtree is removed
        int max_height_if_left_removed = MAX(current_max_height, current_depth + 1 + right_subtree_height);
        int max_height_if_right_removed = MAX(current_max_height, current_depth + 1 + left_subtree_height);

        // Recursively process left and right children
        calculate_max_heights(node->left, current_depth + 1, max_height_if_left_removed);
        calculate_max_heights(node->right, current_depth + 1, max_height_if_right_removed);
    }
    calculate_max_heights(root, 0, 0);  // Initial call to calculate max heights

    // Step 3: Process each query to get the result from precomputed values
    for (int i = 0; i < queriesSize; i++) {
        answer[i] = max_height_after_removal[queries[i]] - 1;  // Convert node height to edge count
    }
    return answer;
}
