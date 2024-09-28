#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct MyCalendarTwo
 * @brief Struct to hold the booked intervals and manage double bookings.
 *
 * - single_booked: A dynamic array of intervals representing single bookings.
 * - double_booked: A dynamic array of intervals representing double bookings.
 * - single_size: Current size of the single_booked array.
 * - double_size: Current size of the double_booked array.
 * - single_capacity: Current capacity of the single_booked array.
 * - double_capacity: Current capacity of the double_booked array.
 */
typedef struct {
    int* single_booked;    // Array to store single bookings in [start1, end1, start2, end2,...] format
    int* double_booked;    // Array to store double bookings in the same format
    int single_size;       // Number of elements (intervals) in single_booked
    int double_size;       // Number of elements (intervals) in double_booked
    int single_capacity;   // Current capacity of single_booked array
    int double_capacity;   // Current capacity of double_booked array
} MyCalendarTwo;

/**
 * @brief Creates and initializes a new MyCalendarTwo object.
 * 
 * @return MyCalendarTwo* Pointer to the created calendar object.
 * Initializes the arrays with a starting capacity of 10 intervals.
 */
MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->single_capacity = 10; // Initial capacity for single_booked intervals
    obj->double_capacity = 10; // Initial capacity for double_booked intervals
    obj->single_size = 0;      // Initially no single bookings
    obj->double_size = 0;      // Initially no double bookings
    // Allocate memory for both booking arrays
    obj->single_booked = (int*)malloc(sizeof(int) * obj->single_capacity * 2); // Stores intervals [start1, end1, start2, end2,...]
    obj->double_booked = (int*)malloc(sizeof(int) * obj->double_capacity * 2); // Same format for double bookings
    return obj;
}

/**
 * @brief Dynamically grows the given array if necessary.
 * 
 * @param arr Pointer to the array that needs to be resized.
 * @param size Current size of the array.
 * @param capacity Current capacity of the array.
 * @return int* Pointer to the resized array if the capacity was increased.
 * This function doubles the capacity if the size reaches the current capacity.
 */
int* growArrayIfNeeded(int* arr, int* size, int* capacity) {
    if (*size >= *capacity) {
        *capacity *= 2;  // Double the capacity
        arr = (int*)realloc(arr, sizeof(int) * (*capacity) * 2); // Reallocate with new capacity
    }
    return arr;
}

/**
 * @brief Checks for overlaps between existing intervals in the array and a new interval [start, end).
 * 
 * @param arr Pointer to the intervals array.
 * @param size Number of elements in the intervals array.
 * @param start Start time of the new interval.
 * @param end End time of the new interval.
 * @return true if there is an overlap, false otherwise.
 * Checks whether any intervals in the array overlap with the new event's interval [start, end).
 */
bool hasOverlap(int* arr, int size, int start, int end) {
    for (int i = 0; i < size; i += 2) {
        // Check if the new interval [start, end) overlaps with the existing interval arr[i, i+1)
        if (start < arr[i + 1] && end > arr[i]) {  // Overlapping condition
            return true;
        }
    }
    return false;
}

/**
 * @brief Adds a new interval to the given intervals array.
 * 
 * @param arr Pointer to the intervals array.
 * @param size Pointer to the current number of elements in the array.
 * @param capacity Pointer to the capacity of the array.
 * @param start Start time of the new interval.
 * @param end End time of the new interval.
 * 
 * Dynamically grows the array if necessary and appends the new interval to the array.
 */
void addInterval(int** arr, int* size, int* capacity, int start, int end) {
    // Ensure the array has enough capacity to add a new interval
    *arr = growArrayIfNeeded(*arr, size, capacity);
    (*arr)[*size] = start;       // Add start time
    (*arr)[*size + 1] = end;     // Add end time
    *size += 2;                  // Increase the size by 2 to account for the new interval
}

/**
 * @brief Attempts to book a new event in the calendar.
 * 
 * @param obj Pointer to the MyCalendarTwo object.
 * @param start Start time of the event.
 * @param end End time of the event.
 * @return true if the booking is successful and does not cause a triple booking, false otherwise.
 * 
 * First checks if the new event would overlap with any double-booked intervals (which would cause a triple booking).
 * If no triple booking is detected, it adds overlapping intervals from the single bookings to double_booked.
 * Finally, the new event is added to the single_booked array.
 */
bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // Check if there is an overlap with the double-booked intervals (triple booking)
    if (hasOverlap(obj->double_booked, obj->double_size, start, end)) {
        return false;
    }

    // Find overlaps with single-booked intervals and add the overlapping parts to double_booked
    for (int i = 0; i < obj->single_size; i += 2) {
        if (start < obj->single_booked[i + 1] && end > obj->single_booked[i]) {  // Overlapping condition
            int overlap_start = (start > obj->single_booked[i]) ? start : obj->single_booked[i];
            int overlap_end = (end < obj->single_booked[i + 1]) ? end : obj->single_booked[i + 1];
            // Add the overlapping interval to the double_booked list
            addInterval(&(obj->double_booked), &(obj->double_size), &(obj->double_capacity), overlap_start, overlap_end);
        }
    }

    // Add the new event to the single_booked intervals
    addInterval(&(obj->single_booked), &(obj->single_size), &(obj->single_capacity), start, end);
    return true;
}

/**
 * @brief Frees the allocated memory for the MyCalendarTwo object.
 * 
 * @param obj Pointer to the MyCalendarTwo object.
 * Frees memory for both the single_booked and double_booked arrays, as well as the MyCalendarTwo object itself.
 */
void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->single_booked);  // Free memory for single_booked array
    free(obj->double_booked);  // Free memory for double_booked array
    free(obj);                 // Free the MyCalendarTwo object
}


/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 * 
 * myCalendarTwoFree(obj);
 */
