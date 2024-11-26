#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the unique champion team in a tournament if it exists.
 *
 * @param n (int): Number of teams (nodes).
 * @param edges (int**): Directed edges representing team strengths.
 * @param edgesSize (int): Number of edges.
 * @param edgesColSize (int*): Array representing the size of each edge (always 2).
 * @return (int): The team number of the champion, or -1 if no unique champion exists.
 */
int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    // Step 1: Allocate and initialize the in-degree array
    int* in_degree = (int*)calloc(n, sizeof(int));
    
    // Step 2: Populate the in-degree array based on edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        in_degree[v]++;
    }
    
    // Step 3: Find nodes with in-degree 0
    int champion = -1;
    int count_zero_indegree = 0;
    
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            count_zero_indegree++;
            if (count_zero_indegree > 1) {
                free(in_degree);
                return -1;  // More than one node with in-degree 0
            }
            champion = i;
        }
    }

    // Step 4: Check for a unique champion
    free(in_degree);
    return count_zero_indegree == 1 ? champion : -1;
}
