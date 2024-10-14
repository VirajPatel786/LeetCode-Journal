#include <stdio.h>
#include <stdlib.h>

// Structure to represent an event (either the start or the end of an interval)
typedef struct {
    int time; // Time of the event (start or end of an interval)
    int type; // +1 for start, -1 for end
} Event;

/**
 * @brief Compares two events for sorting. First by time, then by type (-1 for end comes before +1 for start).
 *
 * @param a (const void*): Pointer to the first event.
 * @param b (const void*): Pointer to the second event.
 *
 * @return (int): The comparison result used for sorting.
 */
int compareEvents(const void *a, const void *b) {
    Event *eventA = (Event *)a;
    Event *eventB = (Event *)b;
    
    // If times are the same, process 'end' (-1) before 'start' (+1) to avoid counting overlaps incorrectly
    if (eventA->time == eventB->time) {
        return eventA->type - eventB->type;
    }
    // Otherwise, sort by time (earlier times come first)
    return eventA->time - eventB->time;
}

/**
 * @brief Finds the minimum number of groups needed for non-overlapping intervals.
 *
 * @param intervals (int**): Array of intervals where each interval is represented as [start, end].
 * @param intervalsSize (int): Number of intervals.
 * @param intervalsColSize (int*): Array containing the size of each interval (always 2).
 *
 * @return (int): The minimum number of groups required.
 */
int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    int eventCount = intervalsSize * 2; // Each interval generates two events: one for start and one for end
    Event *events = (Event *)malloc(eventCount * sizeof(Event)); // Allocate memory to hold all events
    
    // Create events for each interval's start and end times
    int index = 0;
    for (int i = 0; i < intervalsSize; i++) {
        // Add start event
        events[index].time = intervals[i][0]; // Start time of the interval
        events[index].type = 1;  // +1 indicates start of an interval
        index++;
        
        // Add end event (we add +1 to the end time to make the interval exclusive)
        events[index].time = intervals[i][1] + 1; // End time (exclusive, so we add +1)
        events[index].type = -1; // -1 indicates end of an interval
        index++;
    }
    
    // Sort the events by time. If times are equal, 'end' events (-1) are processed before 'start' events (+1)
    qsort(events, eventCount, sizeof(Event), compareEvents);
    
    // Variables to track the number of active intervals and the maximum number of groups required
    int active_intervals = 0; // Current count of overlapping intervals
    int max_groups = 0; // Maximum number of overlapping intervals at any point
    
    // Process each event in the sorted order
    for (int i = 0; i < eventCount; i++) {
        // Update active intervals count based on the event type (start or end)
        active_intervals += events[i].type; // +1 for start, -1 for end
        
        // Keep track of the maximum number of active intervals (i.e., maximum groups needed)
        if (active_intervals > max_groups) {
            max_groups = active_intervals;
        }
    }
    
    // Free allocated memory for events
    free(events);
    
    // Return the maximum number of overlapping intervals, which is the minimum number of groups required
    return max_groups;
}
