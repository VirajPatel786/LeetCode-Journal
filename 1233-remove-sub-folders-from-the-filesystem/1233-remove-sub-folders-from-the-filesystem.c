#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Compare function for sorting strings lexicographically.
 *
 * @param a (const void *): Pointer to the first string.
 * @param b (const void *): Pointer to the second string.
 *
 * @return (int): Difference in lexicographic order.
 */
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

/**
 * @brief Remove all sub-folders from the given list of folder paths.
 *
 * @param folder (char **): Array of folder paths.
 * @param folderSize (int): Number of folder paths.
 * @param returnSize (int *): Pointer to store count of non-sub-folder paths.
 *
 * @return (char **): Array of folder paths without sub-folders. The returned array must be malloced, assume caller calls free().
 */
char **removeSubfolders(char **folder, int folderSize, int *returnSize) {
    // Sort the folders lexicographically, so sub-folders follow their parent folders in order
    qsort(folder, (size_t)folderSize, sizeof(char *), compare);

    // Allocate memory for the result array, assuming a maximum of folderSize folders could be non-sub-folders
    char **result = (char **)malloc(folderSize * sizeof(char *));
    if (result == NULL) {
        *returnSize = 0; // Set returnSize to 0 if memory allocation fails
        return NULL; // Return NULL in case of memory allocation failure
    }

    int res_index = 0; // Initialize index for result array

    // Iterate through each folder path in the sorted list
    for (int i = 0; i < folderSize; i++) {
        // Check if current folder[i] is a sub-folder of the last added folder in result
        // - res_index == 0: Always add the first folder as a root
        // - strncmp check: Compare if folder[i] starts with the last root folder (result[res_index - 1])
        // - Additional check on '/' ensures folder[i] is truly a sub-folder
        if (res_index == 0 || 
            strncmp(folder[i], result[res_index - 1], strlen(result[res_index - 1])) != 0 || 
            folder[i][strlen(result[res_index - 1])] != '/') {
            result[res_index] = folder[i]; // Add folder[i] as a new root folder in result
            res_index++; // Increment result index to add new root folder
        }
    }

    // Set the returnSize to the number of root folders stored in result
    *returnSize = res_index;
    return result; // Return the array containing only non-sub-folders
}
