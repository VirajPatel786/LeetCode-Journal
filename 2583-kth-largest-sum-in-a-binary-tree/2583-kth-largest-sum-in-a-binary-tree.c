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

/**
 * @brief Helper function for BFS to find level sums.
 *
 * @param root (struct TreeNode*): The root of the binary tree.
 * @param level_sums (long long*): An array to store the level sums.
 * @param level_count (int*): Pointer to store the number of levels.
 */
void bfsLevelSum(struct TreeNode* root, long long* level_sums, int* level_count) {
    struct TreeNode* queue[100000];  // A large queue for BFS
    int front = 0, back = 0;
    
    if (root == NULL) return;
    
    queue[back++] = root;
    while (front < back) {
        long long level_sum = 0;
        int level_size = back - front;
        
        // Process all nodes at the current level
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = queue[front++];
            level_sum += node->val;
            
            if (node->left) queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }
        level_sums[*level_count] = level_sum;
        (*level_count)++;
    }
}

/**
 * @brief Comparison function for sorting in descending order.
 *
 * @param a (const void*): Pointer to first element.
 * @param b (const void*): Pointer to second element.
 * 
 * @return int: The comparison result for sorting.
 */
int compare(const void* a, const void* b) {
    if (*(long long*)b > *(long long*)a) return 1;
    else if (*(long long*)b < *(long long*)a) return -1;
    return 0;
}

/**
 * @brief Find the kth largest level sum in a binary tree.
 *
 * @param root (struct TreeNode*): The root of the binary tree.
 * @param k (int): The rank of the largest sum to find.
 *
 * @return long long: The kth largest level sum, or -1 if fewer than k levels.
 */
long long kthLargestLevelSum(struct TreeNode* root, int k) {
    if (!root) return -1;
    
    long long level_sums[100000];
    int level_count = 0;
    
    // Perform BFS to get the level sums
    bfsLevelSum(root, level_sums, &level_count);
    
    // Sort the level sums in descending order
    qsort(level_sums, level_count, sizeof(long long), compare);
    
    // Return the kth largest sum if there are at least k levels
    if (level_count >= k) {
        return level_sums[k - 1];
    } else {
        return -1;
    }
}
