#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>  // For INT_MAX

/**
 * @brief Converts a time string in "HH:MM" format to the number of minutes since midnight.
 * 
 * @param time The time string in the format "HH:MM". (char*)
 * @return The number of minutes since midnight. (int)
 */
int convert_to_minutes(const char* time) {
    // Extract hours from the first two characters of the string (e.g., "12" -> 12)
    int hours = (time[0] - '0') * 10 + (time[1] - '0');
    
    // Extract minutes from characters at index 3 and 4 (e.g., "30" -> 30)
    int minutes = (time[3] - '0') * 10 + (time[4] - '0');
    
    // Return total minutes since midnight (hours * 60 + minutes)
    return hours * 60 + minutes;
}

/**
 * @brief Comparison function for use with qsort.
 *        It compares two integers and returns their difference.
 * 
 * @param a Pointer to the first integer. (const void*)
 * @param b Pointer to the second integer. (const void*)
 * @return The difference between the two integers. (int)
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // Compare two integers by dereferencing them
}

/**
 * @brief Finds the minimum difference between any two time points in minutes.
 *        The time points are in "HH:MM" format, stored as strings.
 * 
 * @param timePoints An array of strings, each representing a time in "HH:MM" format. (char**)
 * @param timePointsSize The number of elements in the timePoints array. (int)
 * @return The minimum difference in minutes between any two time points. (int)
 */
int findMinDifference(char** timePoints, int timePointsSize) {
    // If there are less than 2 time points, return 0 (though this case is not expected based on the problem constraints).
    if (timePointsSize < 2) return 0;

    // Array to store the converted times in minutes.
    int minutes[timePointsSize];
    
    // Convert each time point from "HH:MM" format to total minutes since midnight
    for (int i = 0; i < timePointsSize; i++) {
        minutes[i] = convert_to_minutes(timePoints[i]);
    }
    
    // Sort the time points (in minutes) to make it easier to compute consecutive differences
    qsort(minutes, timePointsSize, sizeof(int), compare);
    
    // Initialize the minimum difference to the largest possible value (infinity)
    int min_diff = INT_MAX;
    
    // Find the minimum difference between consecutive time points after sorting
    for (int i = 1; i < timePointsSize; i++) {
        // Compute the difference between the current time point and the previous one
        int diff = minutes[i] - minutes[i - 1];
        
        // Update min_diff if the current difference is smaller
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    // Calculate the circular difference between the last and first time points across midnight
    // There are 1440 minutes in a day, so we compute the difference as 1440 + first_time - last_time.
    int circular_diff = 1440 + minutes[0] - minutes[timePointsSize - 1];
    
    // Update min_diff if the circular difference is smaller than the current minimum
    if (circular_diff < min_diff) {
        min_diff = circular_diff;
    }
    
    // Return the smallest difference in minutes
    return min_diff;
}