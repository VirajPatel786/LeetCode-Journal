#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_MULTIPLIER 60013
#define HASH_SIZE 10007  // Size of the hash table for storing obstacles

// Structure for hash table nodes
typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

// Function to calculate the hash key for coordinates (x, y)
int hashCoordinates(int x, int y) {
    return (x + HASH_MULTIPLIER * y) % HASH_SIZE;
}

// Insert an obstacle into the hash table
void insertObstacle(Node** hashTable, int x, int y) {
    int hashKey = hashCoordinates(x, y);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = hashTable[hashKey];
    hashTable[hashKey] = newNode;
}

// Check if an obstacle exists at coordinates (x, y)
bool isObstacle(Node** hashTable, int x, int y) {
    int hashKey = hashCoordinates(x, y);
    Node* current = hashTable[hashKey];
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Free the hash table memory
void freeHashTable(Node** hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Main function to simulate the robot's movement
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    // Initialize hash table for obstacles
    Node* hashTable[HASH_SIZE] = {NULL};
    
    // Insert obstacles into the hash table
    for (int i = 0; i < obstaclesSize; i++) {
        insertObstacle(hashTable, obstacles[i][0], obstacles[i][1]);
    }

    // Direction vectors: North, East, South, West
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // Initialize robot's position and direction (facing North)
    int x = 0, y = 0, dir = 0;
    int maxDistanceSquared = 0;

    // Process each command
    for (int i = 0; i < commandsSize; i++) {
        int command = commands[i];

        if (command == -1) {
            // Turn right
            dir = (dir + 1) % 4;
        } else if (command == -2) {
            // Turn left
            dir = (dir + 3) % 4;
        } else {
            // Move forward 'command' steps
            for (int step = 0; step < command; step++) {
                int nextX = x + directions[dir][0];
                int nextY = y + directions[dir][1];
                
                // Check if the next position is an obstacle
                if (isObstacle(hashTable, nextX, nextY)) {
                    break;
                }

                // Update the robot's position
                x = nextX;
                y = nextY;

                // Calculate the current distance squared from origin
                int distanceSquared = x * x + y * y;
                if (distanceSquared > maxDistanceSquared) {
                    maxDistanceSquared = distanceSquared;
                }
            }
        }
    }

    // Free the memory used by the hash table
    freeHashTable(hashTable);

    return maxDistanceSquared;
}