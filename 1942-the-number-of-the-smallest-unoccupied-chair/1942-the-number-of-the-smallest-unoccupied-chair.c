#include <stdio.h>
#include <stdlib.h>

// Structure to represent an event (friend arrives and leaves)
typedef struct Event {
    int time;
    int friendIdx;
    int isArrival;  // 1 for arrival, 0 for departure
} Event;

/**
 * @brief Structure to represent a min-heap.
 *
 * @param array (int*): Array representing the heap elements.
 * @param size (int): Current number of elements in the heap.
 * @param capacity (int): Maximum capacity of the heap.
 */
typedef struct Heap {
    int* array;
    int size;
    int capacity;
} Heap;

/**
 * @brief Function to create a min-heap.
 *
 * @param capacity (int): The capacity of the heap.
 * 
 * @return (Heap*): A pointer to the created heap.
 */
Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

/**
 * @brief Swaps two integers.
 *
 * @param a (int*): Pointer to the first integer.
 * @param b (int*): Pointer to the second integer.
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Heapifies a node to maintain the min-heap property.
 *
 * @param heap (Heap*): Pointer to the heap.
 * @param i (int): Index of the node to heapify.
 */
void heapify(Heap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if the left child is smaller than the current node
    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }

    // Check if the right child is smaller than the smallest node so far
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }

    // If the smallest is not the current node, swap and heapify recursively
    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

/**
 * @brief Inserts a new value into the min-heap.
 *
 * @param heap (Heap*): Pointer to the heap.
 * @param value (int): The value to insert into the heap.
 */
void insertHeap(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        return; // If the heap is full, we do not insert the new value.
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    // Fix the min-heap property if it's violated
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/**
 * @brief Extracts the minimum value from the heap.
 *
 * @param heap (Heap*): Pointer to the heap.
 * 
 * @return (int): The extracted minimum value.
 */
int extractMin(Heap* heap) {
    if (heap->size <= 0)
        return -1;  // If the heap is empty, return an invalid value
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];  // If only one element, return it
    }

    // Store the minimum value (root) and move the last element to root
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);  // Restore the min-heap property

    return root;
}

/**
 * @brief Function to compare two events for sorting by time.
 *
 * @param a (const void*): Pointer to the first event.
 * @param b (const void*): Pointer to the second event.
 *
 * @return (int): Comparison result.
 */
int compareEvents(const void* a, const void* b) {
    Event* event1 = (Event*)a;
    Event* event2 = (Event*)b;
    return event1->time - event2->time;
}

/**
 * @brief Function to find the smallest chair for the target friend.
 *
 * @param times (int**): 2D array where each row contains the arrival and leaving times.
 * @param timesSize (int): Number of friends (rows in the times array).
 * @param timesColSize (int*): Array of column sizes (should always be 2).
 * @param targetFriend (int): The friend for whom we need to find the chair.
 *
 * @return (int): The chair number assigned to the target friend.
 */
int smallestChair(int** times, int timesSize, int* timesColSize, int targetFriend) {
    // Create heaps for available chairs and events for when people leave
    Heap* availableChairs = createHeap(timesSize);
    Heap* leavingChairs = createHeap(timesSize);

    // Initialize all chairs (0 to timesSize - 1) as available
    for (int i = 0; i < timesSize; i++) {
        insertHeap(availableChairs, i);
    }

    // Create an array of events (arrivals and departures)
    Event* events = (Event*)malloc(2 * timesSize * sizeof(Event));
    for (int i = 0; i < timesSize; i++) {
        // Arrival event
        events[2 * i].time = times[i][0];
        events[2 * i].friendIdx = i;
        events[2 * i].isArrival = 1;

        // Departure event
        events[2 * i + 1].time = times[i][1];
        events[2 * i + 1].friendIdx = i;
        events[2 * i + 1].isArrival = 0;
    }

    // Sort the events by time
    qsort(events, 2 * timesSize, sizeof(Event), compareEvents);

    // Chair assignment array to track which chair each friend has
    int* friendToChair = (int*)malloc(timesSize * sizeof(int));

    // Process events in sorted order
    for (int i = 0; i < 2 * timesSize; i++) {
        Event event = events[i];

        if (event.isArrival) {
            // If it's an arrival event, assign the smallest available chair
            int assignedChair = extractMin(availableChairs);
            friendToChair[event.friendIdx] = assignedChair;

            // If it's the target friend, return the chair
            if (event.friendIdx == targetFriend) {
                // Cleanup
                free(friendToChair);
                free(events);
                free(availableChairs->array);
                free(availableChairs);
                free(leavingChairs->array);
                free(leavingChairs);
                return assignedChair;
            }

            // Add departure event with the assigned chair
            insertHeap(leavingChairs, times[event.friendIdx][1]);
        } else {
            // If it's a departure event, make the chair available again
            int leavingChair = friendToChair[event.friendIdx];
            insertHeap(availableChairs, leavingChair);
        }
    }

    // Cleanup
    free(friendToChair);
    free(events);
    free(availableChairs->array);
    free(availableChairs);
    free(leavingChairs->array);
    free(leavingChairs);

    // Should never reach this point
    return -1;
}