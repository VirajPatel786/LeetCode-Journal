#include <stdio.h>
#include <stdlib.h>

// Define a hash set to store obstacles (using a simple hash function)
typedef struct {
    int x, y;
} Obstacle;

// A hash function to map the obstacle coordinates to a unique key
int hash(int x, int y) {
    return (x + 30000) * 60001 + (y + 30000);
}

// Comparator for sorting obstacles
int compare(const void* a, const void* b) {
    Obstacle* oa = (Obstacle*)a;
    Obstacle* ob = (Obstacle*)b;
    if (oa->x == ob->x)
        return oa->y - ob->y;
    return oa->x - ob->x;
}

// Binary search function to check if a given position is an obstacle
int isObstacle(Obstacle* obstacles, int obstaclesSize, int x, int y) {
    Obstacle target = {x, y};
    return bsearch(&target, obstacles, obstaclesSize, sizeof(Obstacle), compare) != NULL;
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    // Directions: N, E, S, W
    int dirX[4] = {0, 1, 0, -1};  // Corresponding x moves for each direction
    int dirY[4] = {1, 0, -1, 0};  // Corresponding y moves for each direction

    // Convert obstacles into an array of Obstacle structures
    Obstacle* obsArray = (Obstacle*)malloc(obstaclesSize * sizeof(Obstacle));
    for (int i = 0; i < obstaclesSize; i++) {
        obsArray[i].x = obstacles[i][0];
        obsArray[i].y = obstacles[i][1];
    }
    // Sort the obstacles for binary search use later
    qsort(obsArray, obstaclesSize, sizeof(Obstacle), compare);

    // Starting position and direction (facing north)
    int x = 0, y = 0, dir = 0;
    int maxDistSq = 0;

    // Simulate each command
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -2) {  // Turn left
            dir = (dir + 3) % 4;
        } else if (commands[i] == -1) {  // Turn right
            dir = (dir + 1) % 4;
        } else {  // Move forward
            int steps = commands[i];
            for (int j = 0; j < steps; j++) {
                int nextX = x + dirX[dir];
                int nextY = y + dirY[dir];
                if (!isObstacle(obsArray, obstaclesSize, nextX, nextY)) {
                    x = nextX;
                    y = nextY;
                    // Calculate distance squared from origin
                    int distSq = x * x + y * y;
                    if (distSq > maxDistSq) {
                        maxDistSq = distSq;
                    }
                } else {
                    // Stop if there's an obstacle
                    break;
                }
            }
        }
    }

    free(obsArray);
    return maxDistSq;
}
