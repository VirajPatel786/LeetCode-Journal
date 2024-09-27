#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* single_booked;
    int* double_booked;
    int single_size;
    int double_size;
    int single_capacity;
    int double_capacity;
} MyCalendarTwo;

/**
 * @brief Creates and initializes a new MyCalendarTwo object.
 * 
 * @return MyCalendarTwo* Pointer to the created calendar object.
 */
MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->single_capacity = 10;
    obj->double_capacity = 10;
    obj->single_size = 0;
    obj->double_size = 0;
    obj->single_booked = (int*)malloc(sizeof(int) * obj->single_capacity * 2); // [start1, end1, start2, end2, ...]
    obj->double_booked = (int*)malloc(sizeof(int) * obj->double_capacity * 2); // same format
    return obj;
}

/**
 * @brief Dynamically grows the given array if necessary.
 * 
 * @param arr Pointer to the array.
 * @param size Current size of the array.
 * @param capacity Current capacity of the array.
 * @return int* The new pointer to the (possibly reallocated) array.
 */
int* growArrayIfNeeded(int* arr, int* size, int* capacity) {
    if (*size >= *capacity) {
        *capacity *= 2;
        arr = (int*)realloc(arr, sizeof(int) * (*capacity) * 2);
    }
    return arr;
}

/**
 * @brief Checks for overlaps between intervals and the range [start, end).
 * 
 * @param arr Pointer to the intervals array.
 * @param size Number of intervals in the array.
 * @param start Start of the new interval.
 * @param end End of the new interval.
 * @return true if there's an overlap, false otherwise.
 */
bool hasOverlap(int* arr, int size, int start, int end) {
    for (int i = 0; i < size; i += 2) {
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
 * @param size Pointer to the number of intervals in the array.
 * @param capacity Pointer to the capacity of the array.
 * @param start Start of the new interval.
 * @param end End of the new interval.
 */
void addInterval(int** arr, int* size, int* capacity, int start, int end) {
    *arr = growArrayIfNeeded(*arr, size, capacity);
    (*arr)[*size] = start;
    (*arr)[*size + 1] = end;
    *size += 2;
}

/**
 * @brief Attempts to book a new event in the calendar.
 * 
 * The function ensures that no triple bookings occur.
 * 
 * @param obj Pointer to the MyCalendarTwo object.
 * @param start Start time of the event.
 * @param end End time of the event.
 * @return true if the booking is successful, false if it would cause a triple booking.
 */
bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // Check if there is an overlap with the double-booked intervals (triple booking)
    if (hasOverlap(obj->double_booked, obj->double_size, start, end)) {
        return false;
    }

    // Find overlaps with single-booked intervals and add them to double-booked intervals
    for (int i = 0; i < obj->single_size; i += 2) {
        if (start < obj->single_booked[i + 1] && end > obj->single_booked[i]) {  // Overlapping condition
            int overlap_start = (start > obj->single_booked[i]) ? start : obj->single_booked[i];
            int overlap_end = (end < obj->single_booked[i + 1]) ? end : obj->single_booked[i + 1];
            addInterval(&(obj->double_booked), &(obj->double_size), &(obj->double_capacity), overlap_start, overlap_end);
        }
    }

    // Add the event to the single-booked intervals
    addInterval(&(obj->single_booked), &(obj->single_size), &(obj->single_capacity), start, end);
    return true;
}

/**
 * @brief Frees the allocated memory for the MyCalendarTwo object.
 * 
 * @param obj Pointer to the MyCalendarTwo object.
 */
void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->single_booked);
    free(obj->double_booked);
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 * 
 * myCalendarTwoFree(obj);
 */
