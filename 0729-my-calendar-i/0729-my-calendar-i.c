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
    // Check for overlap with existing events
    for (int i = 0; i < obj->size; i++) {
        int* event = obj->events[i];
        int event_start = event[0];
        int event_end = event[1];
        if (start < event_end && end > event_start) {
            return false;  // Overlap found, cannot book
        }
    }

    // Resize the events array if needed
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;  // Double the capacity
        obj->events = (int **)realloc(obj->events, obj->capacity * sizeof(int *));
    }

    // Add the new event to the list of events
    obj->events[obj->size] = (int *)malloc(2 * sizeof(int));
    obj->events[obj->size][0] = start;
    obj->events[obj->size][1] = end;
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