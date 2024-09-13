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
    // Allocate memory for the prefix XOR array, with one extra space for prefix[0] = 0
    int* prefix = (int*)calloc(arrSize + 1, sizeof(int));
    
    // Build the prefix XOR array
    // prefix[i] contains XOR of arr[0] to arr[i-1]
    for (int i = 0; i < arrSize; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    // Allocate memory for the result array, which will store the XOR result for each query
    int* result = (int*)calloc(queriesSize, sizeof(int));
    *returnSize = queriesSize;

    // Process each query
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];  // Starting index of the query
        int right = queries[i][1]; // Ending index of the query

        // XOR of elements from arr[left] to arr[right] is prefix[right + 1] ^ prefix[left]
        result[i] = prefix[right + 1] ^ prefix[left];
    }

    // Free the memory allocated for the prefix array
    free(prefix);

    // Return the result array
    return result;
}