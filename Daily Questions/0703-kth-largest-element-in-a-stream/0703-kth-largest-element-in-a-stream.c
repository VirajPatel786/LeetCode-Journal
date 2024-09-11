typedef struct {
    int* heap;
    int heapSize;
    int k;
} KthLargest;

void heapifyDown(int* heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, n, smallest);
    }
}

void heapifyUp(int* heap, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && heap[parent] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        heapifyUp(heap, parent);
    }
}

void insertHeap(int* heap, int* heapSize, int val) {
    heap[(*heapSize)++] = val;
    heapifyUp(heap, *heapSize - 1);
}

int removeMin(int* heap, int* heapSize) {
    int min = heap[0];
    heap[0] = heap[--(*heapSize)];
    heapifyDown(heap, *heapSize, 0);
    return min;
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(k * sizeof(int));
    obj->heapSize = 0;
    obj->k = k;
    
    for (int i = 0; i < numsSize; ++i) {
        kthLargestAdd(obj, nums[i]);
    }
    
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->heapSize < obj->k) {
        insertHeap(obj->heap, &obj->heapSize, val);
    } else if (val > obj->heap[0]) {
        removeMin(obj->heap, &obj->heapSize);
        insertHeap(obj->heap, &obj->heapSize, val);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/