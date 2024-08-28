#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the priority queue (max heap)
typedef struct {
    int node;
    double probability;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MaxHeap;

// Function to swap two heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for the max heap
void heapify(MaxHeap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left].probability > heap->data[largest].probability)
        largest = left;

    if (right < heap->size && heap->data[right].probability > heap->data[largest].probability)
        largest = right;

    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        heapify(heap, largest);
    }
}

// Function to extract the maximum element from the heap
HeapNode extractMax(MaxHeap* heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapify(heap, 0);
    return root;
}

// Function to resize the heap's capacity
void resizeHeap(MaxHeap* heap) {
    heap->capacity *= 2;
    heap->data = (HeapNode*)realloc(heap->data, heap->capacity * sizeof(HeapNode));
    if (!heap->data) {
        perror("Heap reallocation failed");
        exit(EXIT_FAILURE);
    }
}

// Function to insert a new element into the heap
void insertHeap(MaxHeap* heap, HeapNode newNode) {
    if (heap->size == heap->capacity) {
        resizeHeap(heap);
    }

    int i = heap->size++;
    heap->data[i] = newNode;

    while (i != 0 && heap->data[(i - 1) / 2].probability < heap->data[i].probability) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Graph representation using adjacency list
typedef struct AdjListNode {
    int node;
    double probability;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    AdjListNode** head;
} Graph;

// Function to create a new adjacency list node
AdjListNode* createAdjListNode(int node, double probability) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->node = node;
    newNode->probability = probability;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->head = (AdjListNode**)malloc(n * sizeof(AdjListNode*));

    for (int i = 0; i < n; ++i) {
        graph->head[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, double probability) {
    AdjListNode* newNode = createAdjListNode(dest, probability);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;

    newNode = createAdjListNode(src, probability);
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

// Main function to find the maximum probability path
double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node) {
    // Create a graph
    Graph* graph = createGraph(n);
    for (int i = 0; i < edgesSize; ++i) {
        addEdge(graph, edges[i][0], edges[i][1], succProb[i]);
    }

    // Initialize the max heap (priority queue)
    MaxHeap heap;
    heap.capacity = n;
    heap.size = 0;
    heap.data = (HeapNode*)malloc(heap.capacity * sizeof(HeapNode));

    // Array to store the maximum probability to reach each node
    double* maxProb = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; ++i) {
        maxProb[i] = 0.0;
    }
    maxProb[start_node] = 1.0;

    // Push the start node with a probability of 1.0
    HeapNode start = { start_node, 1.0 };
    insertHeap(&heap, start);

    // Dijkstra-like algorithm
    while (heap.size > 0) {
        HeapNode current = extractMax(&heap);
        int currentNode = current.node;
        double currentProb = current.probability;

        if (currentNode == end_node) {
            free(heap.data);
            free(maxProb);
            return currentProb;
        }

        AdjListNode* neighbor = graph->head[currentNode];
        while (neighbor != NULL) {
            double newProb = currentProb * neighbor->probability;
            if (newProb > maxProb[neighbor->node]) {
                maxProb[neighbor->node] = newProb;
                HeapNode nextNode = { neighbor->node, newProb };
                insertHeap(&heap, nextNode);
            }
            neighbor = neighbor->next;
        }
    }

    free(heap.data);
    free(maxProb);
    return 0.0;
}