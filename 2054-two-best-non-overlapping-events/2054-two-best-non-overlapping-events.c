#include <stdio.h>
#include <stdlib.h>

/* Event structure to store start time, end time, and value of each event */
typedef struct {
    int start;
    int end;
    int value;
} Event;

/**
 * @brief Comparator function for sorting events by end time.
 *
 * @param a (const void*): Pointer to the first event.
 * @param b (const void*): Pointer to the second event.
 *
 * @return (int): The difference between the end times of the two events.
 */
int compare(const void *a, const void *b) {
    return ((Event*)a)->end - ((Event*)b)->end;
}

/**
 * @brief Finds the maximum sum of values from at most two non-overlapping events.
 *
 * @param events (int**): 2D array of events where each event is [start, end, value].
 * @param eventsSize (int): Number of events.
 * @param eventsColSize (int*): Number of columns for each event (should be 3).
 *
 * @return (int): The maximum sum of values of up to two non-overlapping events.
 */
int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    /* Allocate memory for the array of Event structures */
    Event *sortedEvents = malloc(eventsSize * sizeof(Event));
    int *dp = malloc(eventsSize * sizeof(int));
    int max_one_event = 0;
    int result = 0;
    int i, j;

    /* Populate the sortedEvents array with input events */
    for (i = 0; i < eventsSize; ++i) {
        sortedEvents[i].start = events[i][0];
        sortedEvents[i].end = events[i][1];
        sortedEvents[i].value = events[i][2];
    }

    /* Sort the events by their end times */
    qsort(sortedEvents, eventsSize, sizeof(Event), compare);

    /* Initialize the dp array to store the maximum event value up to each point */
    dp[0] = sortedEvents[0].value;
    for (i = 1; i < eventsSize; ++i) {
        /* dp[i] stores the maximum value of events considered up to index i */
        dp[i] = (dp[i - 1] > sortedEvents[i].value) ? dp[i - 1] : sortedEvents[i].value;
    }

    /* Iterate through each event to find the maximum sum of two non-overlapping events */
    for (i = 0; i < eventsSize; ++i) {
        int left = 0;
        int right = i - 1;
        int best = 0;

        /* Perform binary search to find the last event that ends before the current event starts */
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sortedEvents[mid].end < sortedEvents[i].start) {
                best = dp[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        /* Calculate the sum of the current event's value and the best previous event's value */
        int current_sum = best + sortedEvents[i].value;

        /* Update the result if the current sum is greater than the previous result */
        if (current_sum > result) {
            result = current_sum;
        }
    }

    /* Free allocated memory */
    free(sortedEvents);
    free(dp);

    /* Return the maximum sum of values for up to two non-overlapping events */
    return result;
}
