/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Processes XOR queries on an input array.
 * 
 * This function computes the XOR of elements between two indices (inclusive) 
 * for each query in the given array of queries. The XOR results for each query 
 * are returned in a dynamically allocated array.
 *
 * @param int* arr Pointer to the input array of integers.
 * @param int arrSize Size of the input array.
 * @param int** queries 2D array where each row contains two integers representing 
 *                     the start and end indices of the query.
 * @param int queriesSize Number of queries.
 * @param int* queriesColSize Pointer to an array that contains the number of columns 
 *                            for each query (always 2).
 * @param int* returnSize Pointer to an integer where the size of the result array 
 *                        will be stored.
 * 
 * @return int* A dynamically allocated array containing the XOR result for each query. 
 *         The caller is responsible for freeing the returned array.
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    
    // Initialize the prefix XOR array in-place for faster computation
    int prefix[arrSize];
    prefix[0] = arr[0]; // First element is the same as in arr

    // Compute the prefix XOR array in a single pass
    for (int i = 1; i < arrSize; i++) {
        prefix[i] = prefix[i - 1] ^ arr[i];
    }

    // Allocate memory for the result array, each element storing the XOR result for a query
    int* ans = (int*)malloc(queriesSize * sizeof(int));

    // Process each query
    for (int i = 0; i < queriesSize; i++) {
        // If the query starts at index 0, the result is just the prefix at the end index
        if (queries[i][0] == 0) {
            ans[i] = prefix[queries[i][1]];
        } 
        // Otherwise, the result is the XOR of two prefix elements
        else {
            ans[i] = prefix[queries[i][0] - 1] ^ prefix[queries[i][1]];
        }
    }

    // Set the returnSize to the number of queries
    *returnSize = queriesSize;

    // Return the result array
    return ans;
}