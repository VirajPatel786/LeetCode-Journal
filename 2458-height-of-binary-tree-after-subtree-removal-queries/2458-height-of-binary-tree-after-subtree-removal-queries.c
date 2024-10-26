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
#include <limits.h>

#define MAX_NODES 100005  // Define the maximum nodes limit

// Global variables for depth, height, and max height data at each depth level
int depth[MAX_NODES];  // Stores depth of each node
int height[MAX_NODES];  // Stores height of the subtree rooted at each node
int max_depth_with_removal[MAX_NODES][2];  // Stores top two heights at each depth level
int max_tree_height = 0;  // Overall height of the tree

/**
 * @brief Initializes global arrays before each run.
 */
void initialize_globals() {
    max_tree_height = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        depth[i] = 0;
        height[i] = 0;
        max_depth_with_removal[i][0] = -1;
        max_depth_with_removal[i][1] = -1;
    }
}

/**
 * @brief Calculates the depth and height of each node in the tree.
 *
 * @param node (struct TreeNode*): Pointer to the current node.
 * @param d (int): Depth of the current node.
 *
 * @return int: The height of the subtree rooted at the current node.
 */
int dfs(struct TreeNode* node, int d) {
    if (!node) return -1;  // Base case: empty node has height -1
    depth[node->val] = d;  // Store depth of the current node
    // Recursively calculate height of left and right subtrees
    int left_height = dfs(node->left, d + 1);
    int right_height = dfs(node->right, d + 1);
    // Height of the current node is 1 + max height of its children
    height[node->val] = 1 + (left_height > right_height ? left_height : right_height);
    // Update the overall max tree height
    if (height[node->val] > max_tree_height) {
        max_tree_height = height[node->val];
    }
    return height[node->val];
}

/**
 * @brief Adjusts max height data for each depth level.
 *
 * @param node (struct TreeNode*): Pointer to the current node.
 */
void dfs_depth_levels(struct TreeNode* node) {
    if (!node) return;
    int h = height[node->val];  // Height of current subtree
    int d = depth[node->val];  // Depth level of current node
    // Update the two largest heights at this depth
    if (h > max_depth_with_removal[d][0]) {  // Current height is the largest at this depth
        max_depth_with_removal[d][1] = max_depth_with_removal[d][0];  // Move max to second max
        max_depth_with_removal[d][0] = h;  // Set new max height
    } else if (h > max_depth_with_removal[d][1]) {  // Current height is second largest
        max_depth_with_removal[d][1] = h;  // Update second max height
    }
    // Recursive calls for left and right subtrees
    dfs_depth_levels(node->left);
    dfs_depth_levels(node->right);
}

/**
 * @brief Calculates the height of the tree after removing each specified subtree.
 *
 * This function first precomputes the depth and height of each node in the tree,
 * then processes each query to determine the height of the tree after removing
 * the subtree rooted at each queried node.
 *
 * @param root (struct TreeNode*): Pointer to the root node of the binary tree.
 * @param queries (int*): Array of queries representing nodes whose subtrees will be removed.
 * @param queriesSize (int): Number of queries in the `queries` array.
 * @param returnSize (int*): Pointer to an integer to store the size of the returned array.
 *
 * @return int*: Array of resulting tree heights after each subtree removal query.
 *               The caller is responsible for freeing this memory.
 */
int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;  // Set return size to number of queries
    int *result = (int *)malloc(queriesSize * sizeof(int));  // Allocate result array

    // Initialize global arrays before processing
    initialize_globals();

    // Step 1: Calculate depth and height for each node
    dfs(root, 0);  // Initial DFS call to compute depth and height
    
    // Step 2: Calculate max heights per depth level ignoring each node
    dfs_depth_levels(root);

    // Step 3: Process each query to compute resulting tree heights
    for (int i = 0; i < queriesSize; i++) {
        int q = queries[i];  // Query node
        int q_depth = depth[q];  // Depth of the queried node
        int q_height = height[q];  // Height of the subtree rooted at the queried node
        // If the queried height is the maximum at its depth, use the second maximum
        if (max_depth_with_removal[q_depth][0] == q_height) {
            result[i] = max_tree_height - q_height + max_depth_with_removal[q_depth][1];
        } else {
            result[i] = max_tree_height;  // No adjustment if not the max at its level
        }
    }
    return result;  // Return the results array
}
