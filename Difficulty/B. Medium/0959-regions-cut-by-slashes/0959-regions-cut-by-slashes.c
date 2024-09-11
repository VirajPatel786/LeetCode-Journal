// Helper function to find the root of a node with path compression
int find(int* parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);  // Path compression
    }
    return parent[x];
}

// Helper function to unite two sets
void union_sets(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        // Union by rank to keep the tree flat
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;
    int size = 4 * n * n;
    int* parent = (int*)malloc(size * sizeof(int));
    int* rank = (int*)calloc(size, sizeof(int));  // Rank array for union by rank
    
    // Initialize the parent array
    for (int i = 0; i < size; ++i) {
        parent[i] = i;
    }
    
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int root = 4 * (r * n + c);
            char val = grid[r][c];
            
            if (val == '/') {
                union_sets(parent, rank, root + 0, root + 3);
                union_sets(parent, rank, root + 1, root + 2);
            } else if (val == '\\') {
                union_sets(parent, rank, root + 0, root + 1);
                union_sets(parent, rank, root + 2, root + 3);
            } else {  // space ' '
                union_sets(parent, rank, root + 0, root + 1);
                union_sets(parent, rank, root + 1, root + 2);
                union_sets(parent, rank, root + 2, root + 3);
            }
            
            // Union with the right cell
            if (c + 1 < n) {
                union_sets(parent, rank, root + 1, 4 * (r * n + c + 1) + 3);
            }
            // Union with the bottom cell
            if (r + 1 < n) {
                union_sets(parent, rank, root + 2, 4 * ((r + 1) * n + c) + 0);
            }
        }
    }
    
    // Count the number of distinct regions
    int regions = 0;
    for (int i = 0; i < size; ++i) {
        if (find(parent, i) == i) {
            ++regions;
        }
    }
    
    free(parent);
    free(rank);
    return regions;
}