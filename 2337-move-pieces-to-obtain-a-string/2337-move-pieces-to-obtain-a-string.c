#include <stdbool.h>
#include <string.h>

/**
 * @brief Determines if the string target can be obtained from start.
 *
 * @param start (char*): The starting configuration.
 * @param target (char*): The target configuration.
 * @return (bool): True if target can be obtained, False otherwise.
 */
bool canChange(char* start, char* target) {
    int n = strlen(start);
    int i = 0, j = 0;  // Pointers for start and target

    while (i < n || j < n) {
        // Skip underscores in start
        while (i < n && start[i] == '_') {
            i++;
        }
        // Skip underscores in target
        while (j < n && target[j] == '_') {
            j++;
        }

        // Both strings should end together
        if (i == n && j == n) {
            return true;
        }

        // If one string ends before the other
        if (i == n || j == n) {
            return false;
        }

        // Mismatch of characters
        if (start[i] != target[j]) {
            return false;
        }

        // Validate movement constraints
        if (start[i] == 'L' && i < j) {
            return false;  // 'L' cannot move to the right
        }
        if (start[i] == 'R' && i > j) {
            return false;  // 'R' cannot move to the left
        }

        // Move both pointers
        i++;
        j++;
    }

    return true;
}
