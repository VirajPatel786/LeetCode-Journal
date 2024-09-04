#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 100003  // A large prime number for the hash table size

// Structure to represent a node in the hash table
typedef struct HashNode {
    int x, y;
    struct HashNode* next;
} HashNode;

// Hash function to generate a unique key based on (x, y) coordinates
int hashFunction(int x, int y) {
    return (x * 31 + y) % HASH_SIZE;
}

// Insert an obstacle into the hash table
void insertObstacle(HashNode** hashTable, int x, int y) {
    int hashIndex = hashFunction(x, y);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->x = x;
    newNode->y = y;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// Check if a position (x, y) is an obstacle
bool isObstacle(HashNode** hashTable, int x, int y) {
    int hashIndex = hashFunction(x, y);
    HashNode* current = hashTable[hashIndex];
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Free the memory allocated for the hash table
void freeHashTable(HashNode** hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    // Directions: north, east, south, west in terms of (dx, dy) pairs
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // north, east, south, west
    int direction_idx = 0;  // Start facing north

    // Initialize the hash table to store obstacles
    HashNode* hashTable[HASH_SIZE] = {NULL};

    // Insert all obstacles into the hash table
    for (int i = 0; i < obstaclesSize; i++) {
        insertObstacle(hashTable, obstacles[i][0], obstacles[i][1]);
    }

    // Starting coordinates of the robot
    int x = 0, y = 0;
    
    // To track the maximum distance squared from the origin
    int max_distance_sq = 0;

    // Process each command
    for (int i = 0; i < commandsSize; i++) {
        int command = commands[i];

        if (command == -2) {  // Turn left 90 degrees
            direction_idx = (direction_idx + 3) % 4;  // Equivalent to (direction_idx - 1) % 4
        } else if (command == -1) {  // Turn right 90 degrees
            direction_idx = (direction_idx + 1) % 4;
        } else {  // Move forward command steps
            for (int step = 0; step < command; step++) {
                // Calculate the next position
                int next_x = x + directions[direction_idx][0];
                int next_y = y + directions[direction_idx][1];

                // If the next position is an obstacle, stop moving
                if (isObstacle(hashTable, next_x, next_y)) {
                    break;
                }

                // Otherwise, update the robot's position
                x = next_x;
                y = next_y;

                // Calculate and update the maximum distance squared from the origin
                int distance_sq = x * x + y * y;
                if (distance_sq > max_distance_sq) {
                    max_distance_sq = distance_sq;
                }
            }
        }
    }

    // Free the hash table memory
    freeHashTable(hashTable);

    // Return the maximum distance squared
    return max_distance_sq;
}
