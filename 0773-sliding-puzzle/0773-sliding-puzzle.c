#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 362880 // 9! for safety as maximum states are 6! = 720

/**
 * @brief Solves the sliding puzzle problem using BFS to find the shortest path to the solution.
 *
 * @param board (int**): The initial 2x3 board configuration.
 * @param boardSize (int): Number of rows in the board.
 * @param boardColSize (int*): Array representing the number of columns in each row.
 * @return (int): Minimum number of moves to solve the puzzle, or -1 if unsolvable.
 */
typedef struct {
    char state[7];  // State as a string
    int zero_idx;   // Position of '0'
    int steps;      // Number of steps taken so far
} Node;

typedef struct {
    Node queue[QUEUE_SIZE];  // BFS queue
    int front;               // Queue front pointer
    int rear;                // Queue rear pointer
} Queue;

/**
 * @brief Enqueue a node into the queue.
 *
 * @param q (Queue*): Pointer to the queue.
 * @param node (Node): Node to enqueue.
 */
void enqueue(Queue* q, Node node) {
    q->queue[q->rear++] = node;
}

/**
 * @brief Dequeue a node from the queue.
 *
 * @param q (Queue*): Pointer to the queue.
 * @return (Node): Dequeued node.
 */
Node dequeue(Queue* q) {
    return q->queue[q->front++];
}

/**
 * @brief Check if the queue is empty.
 *
 * @param q (Queue*): Pointer to the queue.
 * @return (bool): True if the queue is empty, false otherwise.
 */
bool is_empty(Queue* q) {
    return q->front == q->rear;
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    char start[7] = {0};    // String representation of the board
    int zero_idx = 0;       // Position of '0' in the board

    // Convert the board into a string and locate the '0' position
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            start[i * 3 + j] = board[i][j] + '0';  // Convert integer to character
            if (board[i][j] == 0) {
                zero_idx = i * 3 + j;
            }
        }
    }
    start[6] = '\0';  // Null-terminate the string

    // Define the goal state
    char* goal = "123450";

    // Valid moves for each position of '0'
    int moves[6][3] = {
        {1, 3, -1},  // Index 0: can move to indices 1 and 3
        {0, 2, 4},   // Index 1: can move to indices 0, 2, and 4
        {1, 5, -1},  // Index 2: can move to indices 1 and 5
        {0, 4, -1},  // Index 3: can move to indices 0 and 4
        {1, 3, 5},   // Index 4: can move to indices 1, 3, and 5
        {2, 4, -1}   // Index 5: can move to indices 2 and 4
    };

    // BFS setup
    Queue q = {.front = 0, .rear = 0};
    Node start_node = {.steps = 0};
    strcpy(start_node.state, start);
    start_node.zero_idx = zero_idx;
    enqueue(&q, start_node);

    // Visited states
    char visited[QUEUE_SIZE][7];  // Array to store visited states
    int visited_count = 0;
    strcpy(visited[visited_count++], start);

    while (!is_empty(&q)) {
        Node current = dequeue(&q);

        // Check if the current state matches the goal
        if (strcmp(current.state, goal) == 0) {
            return current.steps;
        }

        // Generate next states
        for (int i = 0; i < 3; i++) {
            int move = moves[current.zero_idx][i];
            if (move == -1) continue;  // Skip invalid moves

            // Swap '0' with the adjacent position
            char new_state[7];
            strcpy(new_state, current.state);
            char temp = new_state[current.zero_idx];
            new_state[current.zero_idx] = new_state[move];
            new_state[move] = temp;

            // Check if the new state is already visited
            bool already_visited = false;
            for (int j = 0; j < visited_count; j++) {
                if (strcmp(visited[j], new_state) == 0) {
                    already_visited = true;
                    break;
                }
            }

            // Add the new state to the queue if not visited
            if (!already_visited) {
                strcpy(visited[visited_count++], new_state);
                Node next_node = {.steps = current.steps + 1};
                strcpy(next_node.state, new_state);
                next_node.zero_idx = move;
                enqueue(&q, next_node);
            }
        }
    }

    // If the goal state is not reachable
    return -1;
}
