#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Structure to represent the MyCalendar object.
 * 
 * This structure holds an array of events where each event is represented by an 
 * array of two integers: [start, end]. It also stores the current size of the array (number of booked events) 
 * and the current capacity (how many events the array can hold before resizing).
 */
typedef struct {
    int **events;     // Dynamic array to store events, each event is an array of two integers [start, end].
    int size;         // Current number of events booked.
    int capacity;     // Maximum number of events the array can hold before needing to resize.
} MyCalendar;

/**
 * @brief Helper function to implement the behavior of bisect_left.
 * 
 * This function finds the position to insert a new event (start, end) while keeping the events sorted by start time.
 * 
 * @param events int**: Array of events (each event is [start, end]).
 * @param size int: Current number of events in the array.
 * @param start int: The start time of the new event.
 * 
 * @return int: The index where the new event should be inserted.
 */
int bisect_left(int **events, int size, int start) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (events[mid][0] < start) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

/**
 * @brief Creates a new MyCalendar object.
 *
 * Allocates memory for the MyCalendar structure and initializes its event array
 * with a starting capacity of 10 events.
 *
 * @return MyCalendar*: Pointer to the newly created MyCalendar object.
 */
MyCalendar* myCalendarCreate() {
    MyCalendar *calendar = (MyCalendar *)malloc(sizeof(MyCalendar));
    calendar->size = 0;
    calendar->capacity = 10; // Initial capacity of 10 events
    calendar->events = (int **)malloc(calendar->capacity * sizeof(int *));
    return calendar;
}

/**
 * @brief Books a new event if it does not overlap with existing events.
 *
 * The function checks for any overlap between the new event (start, end) and the already 
 * booked events. If there is no overlap, the event is added to the calendar.
 * If the dynamic array reaches its capacity, it is resized to accommodate more events.
 *
 * @param obj MyCalendar*: Pointer to the MyCalendar object.
 * @param start int: Start time of the event.
 * @param end int: End time of the event (exclusive).
 * 
 * @return bool: Returns true if the event can be booked, false if it overlaps with existing events.
 */
bool myCalendarBook(MyCalendar* obj, int start, int end) {
    // Find the correct position to insert using bisect_left logic
    int index = bisect_left(obj->events, obj->size, start);

    // Check for overlap with the event before the insertion point (if it exists)
    if (index > 0 && obj->events[index - 1][1] > start) {
        return false;  // Overlap found with the previous event
    }

    // Check for overlap with the event after the insertion point (if it exists)
    if (index < obj->size && obj->events[index][0] < end) {
        return false;  // Overlap found with the next event
    }

    // Resize the events array if needed
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;  // Double the capacity
        obj->events = (int **)realloc(obj->events, obj->capacity * sizeof(int *));
    }

    // Shift events to make room for the new event
    for (int i = obj->size; i > index; i--) {
        obj->events[i] = obj->events[i - 1];
    }

    // Insert the new event at the correct position
    obj->events[index] = (int *)malloc(2 * sizeof(int));
    obj->events[index][0] = start;
    obj->events[index][1] = end;
    obj->size++;

    return true;  // Successfully booked
}

/**
 * @brief Frees the memory allocated for the MyCalendar object and its events.
 *
 * This function deallocates all dynamically allocated memory for events and 
 * then frees the MyCalendar object itself.
 *
 * @param obj MyCalendar*: Pointer to the MyCalendar object to be freed.
 */
void myCalendarFree(MyCalendar* obj) {
    for (int i = 0; i < obj->size; i++) {
        free(obj->events[i]);  // Free each event (array of [start, end])
    }
    free(obj->events);  // Free the dynamic array of event pointers
    free(obj);  // Free the MyCalendar object itself
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/