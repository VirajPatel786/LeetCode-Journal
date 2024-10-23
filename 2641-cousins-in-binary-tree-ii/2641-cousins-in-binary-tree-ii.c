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
 * @brief Replace each node value with the sum of its cousins' values in the binary tree.
 *
 * This function modifies the binary tree by replacing the value of each node with
 * the sum of all its cousins' values. Two nodes are cousins if they are at the same
 * depth but have different parents.
 *
 * @param root (struct TreeNode*): The root of the binary tree.
 * 
 * @return struct TreeNode*: The modified binary tree with updated node values.
 */
struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    if (!root) {
        return NULL;
    }

    // Define the queue for level order traversal (BFS)
    struct TreeNode** queue = (struct TreeNode**)malloc(100000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    
    // Initialize queue with the root node and set root value to 0 since it has no cousins
    queue[rear++] = root;
    root->val = 0;  // The root node has no cousins, so set its value to 0

    // Loop through the tree using breadth-first search (BFS)
    while (front < rear) {
        int level_size = rear - front;  // Number of nodes at the current level
        int level_sum = 0;  // Sum of all nodes' values at the current level
        
        // Temporary array to hold nodes for this level
        struct TreeNode** temp_nodes = (struct TreeNode**)malloc(level_size * sizeof(struct TreeNode*));
        
        // First pass: calculate the sum of the current level and store nodes in the temp array
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = queue[front++];
            temp_nodes[i] = node;
            
            // Add the children to the queue for the next level
            if (node->left) {
                queue[rear++] = node->left;
                level_sum += node->left->val;
            }
            if (node->right) {
                queue[rear++] = node->right;
                level_sum += node->right->val;
            }
        }
        
        // Second pass: update node values based on the cousin sum
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = temp_nodes[i];
            int sibling_sum = 0;

            // Calculate the sibling sum (sum of children of the current node)
            if (node->left) {
                sibling_sum += node->left->val;
            }
            if (node->right) {
                sibling_sum += node->right->val;
            }

            // Update the values of the left and right children with the cousin sum
            if (node->left) {
                node->left->val = level_sum - sibling_sum;
            }
            if (node->right) {
                node->right->val = level_sum - sibling_sum;
            }
        }
        
        // Free temporary storage
        free(temp_nodes);
    }

    // Free the queue used for BFS
    free(queue);
    
    return root;
}
