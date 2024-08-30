#define MAX_HEAP_SIZE 10000

// Structure representing a node in the min-heap
typedef struct {
    int dist; // Distance from the source node
    int node; // Node index
} MinHeapNode;

// Structure representing a min-heap (priority queue)
typedef struct {
    MinHeapNode *array; // Array of nodes in the heap
    int size;           // Current size of the heap
} MinHeap;

// Structure representing an edge in the graph
typedef struct {
    int u;      // Start node of the edge
    int v;      // End node of the edge
    int weight; // Weight of the edge
} Edge;

// Structure representing an adjacency list for a node
typedef struct {
    int **array; // Array of pairs [neighbor_node, edge_index]
    int size;    // Number of neighbors for this node
} AdjList;

// Structure to hold the result of the BFS (Dijkstra's) operation
typedef struct {
    int dist;    // Shortest distance from source to destination
    int mod_id;  // ID of the edge that was modified to achieve the target distance
} BFSResult;

// Function to create and initialize a new min-heap
MinHeap* createMinHeap(int maxSize) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->array = (MinHeapNode*)malloc(maxSize * sizeof(MinHeapNode));
    heap->size = 0;
    return heap;
}

// Function to swap two nodes in the min-heap
void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property starting from a given index
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Check if left child is smaller than the current smallest
    if (left < heap->size && heap->array[left].dist < heap->array[smallest].dist)
        smallest = left;

    // Check if right child is smaller than the current smallest
    if (right < heap->size && heap->array[right].dist < heap->array[smallest].dist)
        smallest = right;

    // If the smallest is not the current node, swap and continue heapifying
    if (smallest != idx) {
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Function to extract and return the minimum element (root) from the heap
MinHeapNode extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        MinHeapNode nullNode = { INT_MAX, -1 };
        return nullNode;
    }

    MinHeapNode root = heap->array[0]; // Get the root node

    // Move the last node to the root and reduce heap size
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;

    // Restore the heap property
    minHeapify(heap, 0);

    return root;
}

// Function to insert a new node into the min-heap
void insertMinHeap(MinHeap* heap, int dist, int node) {
    ++heap->size;
    int i = heap->size - 1;
    heap->array[i].dist = dist;
    heap->array[i].node = node;

    // Fix the min-heap property if it's violated
    while (i && heap->array[i].dist < heap->array[(i - 1) / 2].dist) {
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to create and initialize an adjacency list for a graph
AdjList* createAdjList(int n, int edgesSize) {
    AdjList* list = (AdjList*)malloc(n * sizeof(AdjList));
    for (int i = 0; i < n; ++i) {
        list[i].array = (int**)malloc(edgesSize * sizeof(int*)); // Each node can have up to edgesSize neighbors
        list[i].size = 0;
    }
    return list;
}

// Function to add an edge to the adjacency list
void addEdge(AdjList* adjList, int u, int v, int edgeIndex) {
    // Add the neighbor node and the edge index to the adjacency list
    adjList[u].array[adjList[u].size] = (int*)malloc(2 * sizeof(int));
    adjList[u].array[adjList[u].size][0] = v;        // Neighbor node
    adjList[u].array[adjList[u].size][1] = edgeIndex; // Edge index
    adjList[u].size++;
}

// Function to free the memory allocated for the adjacency list
void freeAdjList(AdjList* list, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < list[i].size; ++j) {
            free(list[i].array[j]); // Free the [neighbor, edge_index] pairs
        }
        free(list[i].array); // Free the array of neighbors
    }
    free(list); // Free the list itself
}

// Function to free the memory allocated for the min-heap
void freeMinHeap(MinHeap* heap) {
    free(heap->array); // Free the array of heap nodes
    free(heap);        // Free the heap structure
}

// Function to perform Dijkstra's algorithm (BFS in the context of weighted graphs) 
// to find the shortest path and possibly modify edges with weight -1
BFSResult bfs(AdjList* adjList, Edge* edges, int n, int source, int dest, bool modify) {
    MinHeap* heap = createMinHeap(MAX_HEAP_SIZE); // Create a min-heap
    int* dist = (int*)malloc(n * sizeof(int)); // Array to hold shortest distances
    int* mod_id = (int*)malloc(n * sizeof(int)); // Array to hold modified edge IDs

    // Initialize distances to infinity and mod_id to INT_MAX
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        mod_id[i] = INT_MAX;
    }
    insertMinHeap(heap, 0, source); // Insert the source node into the heap with distance 0
    dist[source] = 0;

    // Main loop of Dijkstra's algorithm
    while (heap->size != 0) {
        MinHeapNode minNode = extractMin(heap); // Get the node with the smallest distance
        int d = minNode.dist;
        int i = minNode.node;

        if (d != dist[i])
            continue; // Skip nodes that have been processed with a shorter distance

        // Iterate through all neighbors of the current node
        for (int j = 0; j < adjList[i].size; ++j) {
            int v = adjList[i].array[j][0]; // Neighbor node
            int edge_id = adjList[i].array[j][1]; // Edge index
            int w = edges[edge_id].weight; // Weight of the edge
            if (modify || w != -1) { // If modification is allowed or the edge is not -1
                // Relaxation step: Update distance if a shorter path is found
                if (dist[v] > d + (w > 0 ? w : 1)) {
                    mod_id[v] = (w == -1) ? edge_id : mod_id[i]; // Record the edge ID if it's modified
                    dist[v] = d + (w > 0 ? w : 1); // Update the shortest distance
                    insertMinHeap(heap, dist[v], v); // Insert the neighbor into the heap with the new distance
                }
            }
        }
    }
    
    BFSResult result = { dist[dest], mod_id[dest] }; // Prepare the result with the shortest distance and the modified edge ID
    free(dist); // Free the distance array
    free(mod_id); // Free the modified edge ID array
    freeMinHeap(heap); // Free the min-heap
    return result;
}

// Main function to modify the graph's edges to achieve the target shortest path distance
int** modifiedGraphEdges(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination, int target, int* returnSize, int** returnColumnSizes) {
    Edge* edgeArray = (Edge*)malloc(edgesSize * sizeof(Edge)); // Array to hold all edges
    AdjList* adjList = createAdjList(n, edgesSize); // Create adjacency list for the graph

    // Populate the edgeArray and the adjacency list
    for (int i = 0; i < edgesSize; ++i) {
        edgeArray[i].u = edges[i][0];
        edgeArray[i].v = edges[i][1];
        edgeArray[i].weight = edges[i][2];
        addEdge(adjList, edgeArray[i].u, edgeArray[i].v, i);
        addEdge(adjList, edgeArray[i].v, edgeArray[i].u, i);
    }

    // Perform BFS/Dijkstra without modifying any edges
    BFSResult distMod = bfs(adjList, edgeArray, n, source, destination, false);

    // If the initial shortest distance is less than the target, it's impossible to achieve the target
    if (distMod.dist < target) {
        free(edgeArray);
        freeAdjList(adjList, n);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Modify the graph edges until the shortest path equals the target
    while (true) {
        distMod = bfs(adjList, edgeArray, n, source, destination, true);

        // If the current shortest path exceeds the target, it's impossible to achieve the target
        if (distMod.dist > target) {
            free(edgeArray);
            freeAdjList(adjList, n);
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }

        // If the shortest path equals the target, break out of the loop
        if (distMod.dist == target)
            break;

        // Modify the weight of the edge to bring the shortest path closer to the target
        edgeArray[distMod.mod_id].weight = 1 + target - distMod.dist;
    }

    // Final adjustment: Set all remaining -1 weights to 1
    for (int i = 0; i < edgesSize; ++i) {
        if (edgeArray[i].weight == -1)
            edgeArray[i].weight = 1;
        edges[i][2] = edgeArray[i].weight; // Update the original edges array
    }

    free(edgeArray); // Free the edge array
    freeAdjList(adjList, n); // Free the adjacency list

    *returnSize = edgesSize; // Set the return size
    *returnColumnSizes = (int*)malloc(edgesSize * sizeof(int)); // Allocate memory for column sizes
    for (int i = 0; i < edgesSize; ++i) {
        (*returnColumnSizes)[i] = 3; // Each edge has 3 elements: u, v, and weight
    }

    return edges; // Return the modified edges
}
