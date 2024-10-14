#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Swap two elements in the array.
 * 
 * @param a (int*): Pointer to the first element.
 * @param b (int*): Pointer to the second element.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Heapify the subtree rooted at index i in the max-heap.
 * 
 * @param heap (int*): The heap array.
 * @param n (int): Size of the heap.
 * @param i (int): Index of the root of the subtree.
 */
void heapify(int heap[], int n, int i) {
    int largest = i;        // Initialize largest as the root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If the left child is larger than the root
    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

/**
 * @brief Perform a heappushpop operation in one step. 
 * It pushes the new value to the heap and pops the largest value.
 * 
 * @param heap (int*): The heap array.
 * @param heapSize (int*): Pointer to the size of the heap.
 * @param value (int): The value to be pushed into the heap.
 * 
 * @return (int): The largest value that is popped from the heap.
 */
int heappushpop(int heap[], int heapSize, int value) {
    // Pop the root (maximum value) and return it
    int max_value = heap[0];

    // Replace the root with the new value and heapify to maintain max-heap property
    heap[0] = value;
    heapify(heap, heapSize, 0);

    return max_value;
}

/**
 * @brief Perform k operations to maximize the score by applying the algorithm.
 * In each operation, the largest element is chosen, added to the score, and replaced by ceil(element / 3).
 * 
 * @param nums (int*): Pointer to the array of integers.
 * @param numsSize (int): Size of the nums array.
 * @param k (int): Number of operations to perform.
 * 
 * @return (long long): The maximum score obtained after k operations.
 */
long long maxKelements(int* nums, int numsSize, int k) {
    long long score = 0;  // Initialize the score to 0

    // Step 1: Build the max-heap by heapifying the entire array
    for (int i = (numsSize / 2) - 1; i >= 0; i--) {
        heapify(nums, numsSize, i);
    }

    // Step 2: Perform k operations
    for (int i = 0; i < k; i++) {
        // Extract the largest element and add it to the score
        int max_num = heappushpop(nums, numsSize, (int)ceil(nums[0] / 3.0));  // Push new value and pop the largest
        score += max_num;  // Add the largest element to the score
    }

    return score;  // Return the total score after k operations
}
