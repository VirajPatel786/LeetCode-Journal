#include <limits.h>
#include <stdlib.h>

/**
 * @brief Structure representing a node in the heap.
 */
typedef struct {
    int value;     // The value of the element.
    int listIdx;   // The index of the list the element belongs to.
    int elemIdx;   // The index of the element in the list.
} HeapNode;

/**
 * @brief Compare two heap nodes based on their values.
 *
 * @param a (const void*): Pointer to the first node.
 * @param b (const void*): Pointer to the second node.
 *
 * @return (int): Returns the difference between the values of the two nodes.
 */
int compare(const void* a, const void* b) {
    return ((HeapNode*)a)->value - ((HeapNode*)b)->value;
}

/**
 * @brief Swap two heap nodes.
 *
 * @param a (HeapNode*): Pointer to the first node.
 * @param b (HeapNode*): Pointer to the second node.
 */
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;  // Temporary storage for swapping
    *a = *b;
    *b = temp;
}

/**
 * @brief Restore the heap property by heapifying the subtree rooted at index i.
 *
 * @param heap (HeapNode[]): The heap array.
 * @param n (int): The number of elements in the heap.
 * @param i (int): The index of the subtree to heapify.
 */
void heapify(HeapNode heap[], int n, int i) {
    int smallest = i;  // Initialize smallest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child exists and is smaller than root
    if (left < n && compare(&heap[left], &heap[smallest]) < 0) {
        smallest = left;
    }

    // If right child exists and is smaller than smallest so far
    if (right < n && compare(&heap[right], &heap[smallest]) < 0) {
        smallest = right;
    }

    // If the smallest is not the root, swap and continue heapifying
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);  // Recursively heapify the affected subtree
    }
}

/**
 * @brief Push a new node into the heap while maintaining heap property.
 *
 * @param heap (HeapNode[]): The heap array.
 * @param n (int*): The current size of the heap.
 * @param value (HeapNode): The new node to be added to the heap.
 */
void pushHeap(HeapNode heap[], int* n, HeapNode value) {
    heap[*n] = value;  // Add new value at the end
    int i = *n;
    (*n)++;  // Increase heap size

    // Fix the heap property if violated (bubble-up)
    while (i != 0 && compare(&heap[i], &heap[(i - 1) / 2]) < 0) {
        swap(&heap[i], &heap[(i - 1) / 2]);  // Swap with parent
        i = (i - 1) / 2;  // Move up to parent index
    }
}

/**
 * @brief Remove and return the smallest element (root) from the heap.
 *
 * @param heap (HeapNode[]): The heap array.
 * @param n (int*): The current size of the heap.
 *
 * @return (HeapNode): The root node, which is the smallest element in the heap.
 */
HeapNode popHeap(HeapNode heap[], int* n) {
    HeapNode root = heap[0];  // Store the root element
    heap[0] = heap[--(*n)];  // Replace root with the last element
    heapify(heap, *n, 0);    // Restore heap property
    return root;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @brief Find the smallest range that includes at least one number from each of the lists.
 *
 * @param nums (int**): A 2D array where each row represents a sorted list.
 * @param numsSize (int): The number of lists.
 * @param numsColSize (int*): Array representing the size of each list.
 * @param returnSize (int*): The size of the result array (which is always 2).
 *
 * @return (int*): An array of size 2 representing the smallest range [start, end].
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    HeapNode* minHeap = (HeapNode*)malloc(numsSize * sizeof(HeapNode));  // Min-heap to store the smallest elements
    int curMax = INT_MIN;  // Current maximum element across all lists
    int heapSize = 0;

    // Initialize heap with the first element from each list
    for (int i = 0; i < numsSize; i++) {
        HeapNode node = {nums[i][0], i, 0};  // Initialize node with first element of each list
        pushHeap(minHeap, &heapSize, node);  // Push the node into the heap
        if (nums[i][0] > curMax) {
            curMax = nums[i][0];  // Update current maximum element
        }
    }

    int* smallRange = (int*)malloc(2 * sizeof(int));  // Array to store the result range
    smallRange[0] = 0;
    smallRange[1] = INT_MAX;  // Initialize the range with the maximum possible value

    // Process the heap until it becomes empty
    while (heapSize > 0) {
        HeapNode curr = popHeap(minHeap, &heapSize);  // Extract the smallest element
        int curMin = curr.value, listIdx = curr.listIdx, elemIdx = curr.elemIdx;

        // Update the smallest range if the current range is smaller
        if ((curMax - curMin < smallRange[1] - smallRange[0]) ||
            (curMax - curMin == smallRange[1] - smallRange[0] && curMin < smallRange[0])) {
            smallRange[0] = curMin;
            smallRange[1] = curMax;
        }

        // If there are more elements in the current list, push the next element into the heap
        if (elemIdx + 1 < numsColSize[listIdx]) {
            int nextVal = nums[listIdx][elemIdx + 1];
            HeapNode nextNode = {nextVal, listIdx, elemIdx + 1};
            pushHeap(minHeap, &heapSize, nextNode);  // Push the next element into the heap
            if (nextVal > curMax) {
                curMax = nextVal;  // Update the current maximum value
            }
        } else {
            break;  // If no more elements in the current list, exit the loop
        }
    }

    *returnSize = 2;  // The result size is always 2
    free(minHeap);    // Free the heap memory
    return smallRange;
}
