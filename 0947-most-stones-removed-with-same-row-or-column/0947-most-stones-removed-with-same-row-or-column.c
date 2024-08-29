#include <stdio.h>
#include <stdlib.h>

// Union-Find structure
typedef struct {
    int *parent; // Array to track the parent of each stone
    int *rank;   // Array to track the rank (size) of each set
    int size;    // Number of elements in the Union-Find structure
} UnionFind;

// Function to initialize the Union-Find structure
UnionFind* createUnionFind(int size) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(size * sizeof(int));
    uf->rank = (int*)malloc(size * sizeof(int));
    uf->size = size;

    // Initially, each stone is its own parent, and all ranks are 1
    for (int i = 0; i < size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 1;
    }

    return uf;
}

// Function to find the root parent of a stone with path compression
int find(UnionFind* uf, int i) {
    // If the stone is not its own parent, recursively find the root
    if (uf->parent[i] != i) {
        uf->parent[i] = find(uf, uf->parent[i]); // Path compression
    }
    return uf->parent[i];
}

// Function to union two sets containing stones i and j
// Returns 1 if the stones were in separate sets and are now united, 0 otherwise
int unionSets(UnionFind* uf, int i, int j) {
    int rootI = find(uf, i); // Find the root of stone i
    int rootJ = find(uf, j); // Find the root of stone j

    // If both stones have the same root, they are already in the same set
    if (rootI == rootJ) {
        return 0;
    }

    // Union by rank: attach the smaller tree under the larger tree
    if (uf->rank[rootI] > uf->rank[rootJ]) {
        uf->parent[rootJ] = rootI;       // RootJ's tree becomes part of RootI's tree
        uf->rank[rootI] += uf->rank[rootJ];
    } else {
        uf->parent[rootI] = rootJ;       // RootI's tree becomes part of RootJ's tree
        if (uf->rank[rootI] == uf->rank[rootJ]) {
            uf->rank[rootJ]++;           // If ranks were equal, increment the rank of RootJ
        }
    }
    return 1;
}

// Function to free the memory allocated for the Union-Find structure
void freeUnionFind(UnionFind* uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

// Main function to remove the maximum number of stones
int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    int removedStones = 0;
    UnionFind* uf = createUnionFind(stonesSize); // Initialize Union-Find structure

    // Hash maps to keep track of the most recent stone seen in each row and column
    int* rowMap = (int*)malloc(10001 * sizeof(int)); // Track the most recent stone in each row
    int* colMap = (int*)malloc(10001 * sizeof(int)); // Track the most recent stone in each column

    // Initialize rowMap and colMap with -1 indicating no stone has been processed yet
    for (int i = 0; i < 10001; i++) {
        rowMap[i] = -1;
        colMap[i] = -1;
    }

    // Process each stone
    for (int i = 0; i < stonesSize; i++) {
        int row = stones[i][0]; // Current stone's row
        int col = stones[i][1]; // Current stone's column

        // If there's already a stone in the same row, union the current stone with it
        if (rowMap[row] != -1) {
            removedStones += unionSets(uf, i, rowMap[row]);
        } else {
            rowMap[row] = i; // Update rowMap with the index of the current stone
        }

        // If there's already a stone in the same column, union the current stone with it
        if (colMap[col] != -1) {
            removedStones += unionSets(uf, i, colMap[col]);
        } else {
            colMap[col] = i; // Update colMap with the index of the current stone
        }
    }

    // Free the memory used by the rowMap, colMap, and Union-Find structure
    free(rowMap);
    free(colMap);
    freeUnionFind(uf);

    // Return the total number of stones that can be removed
    return removedStones;
}
