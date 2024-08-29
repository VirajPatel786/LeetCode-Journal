#include <stdlib.h>
#include <stdbool.h>

// Union-Find data structure
typedef struct {
    int* parent;
    int* rank;
} UnionFind;

// Function to create and initialize Union-Find structure
UnionFind* createUnionFind(int size) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(size * sizeof(int));
    uf->rank = (int*)calloc(size, sizeof(int)); // rank is initialized to 0
    for (int i = 0; i < size; i++) {
        uf->parent[i] = i; // Initially, each element is its own parent
    }
    return uf;
}

// Function to free the Union-Find structure
void destroyUnionFind(UnionFind* uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

// Find function with path compression
int find(UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]); // Path compression
    }
    return uf->parent[x];
}

// Union function with union by rank
void unionSets(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX == rootY) return; // Already in the same set

    // Union by rank
    if (uf->rank[rootX] > uf->rank[rootY]) {
        uf->parent[rootY] = rootX;
    } else if (uf->rank[rootX] < uf->rank[rootY]) {
        uf->parent[rootX] = rootY;
    } else {
        uf->parent[rootY] = rootX;
        uf->rank[rootX]++;
    }
}

// Function to calculate the maximum number of stones that can be removed
int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    int maxRow = 0, maxCol = 0;

    // Find maximum row and column values
    for (int i = 0; i < stonesSize; i++) {
        if (stones[i][0] > maxRow) maxRow = stones[i][0];
        if (stones[i][1] > maxCol) maxCol = stones[i][1];
    }

    int totalSize = maxRow + maxCol + 2; // +2 because we're indexing from 0
    UnionFind* uf = createUnionFind(totalSize);

    // Union stones in the same row or column
    for (int i = 0; i < stonesSize; i++) {
        unionSets(uf, stones[i][0], stones[i][1] + maxRow + 1);
    }

    int uniqueComponents = 0;
    bool* visited = (bool*)calloc(totalSize, sizeof(bool));

    // Count the number of unique connected components
    for (int i = 0; i < stonesSize; i++) {
        int root = find(uf, stones[i][0]);
        if (!visited[root]) {
            visited[root] = true;
            uniqueComponents++;
        }
    }

    free(visited);
    destroyUnionFind(uf);

    // The number of stones that can be removed
    return stonesSize - uniqueComponents;
}
