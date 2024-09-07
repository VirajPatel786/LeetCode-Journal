#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;  // Pointer to the previous node
    int val;            // Value stored in the node
    struct Node* next;  // Pointer to the next node
} Node;

typedef struct {
    Node* head;    // Dummy head node
    Node* tail;    // Dummy tail node
    int length;    // Length of the linked list (excluding dummy nodes)
} MyLinkedList;

// Helper function to create a new node
Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Node Memory Allocation Failed");
        return NULL;
    }
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to create a new linked list with dummy nodes
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (list == NULL) {
        fprintf(stderr, "Linked List Memory Allocation Failed");
        return NULL;
    }
    // Initialize dummy nodes
    list->head = createNode(-1);  // Dummy head node with arbitrary value
    list->tail = createNode(-1);  // Dummy tail node with arbitrary value

    if (list->head == NULL || list->tail == NULL) {
        free(list);
        return NULL;
    }

    // Link the dummy nodes to each other
    list->head->next = list->tail;
    list->tail->prev = list->head;

    list->length = 0;  // Initialize length to 0
    return list;
}

// Function to get the value at the given index (0-based)
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length) {
        return -1;  // Return -1 for an invalid index
    }
    
    Node* currentNode = obj->head->next;  // Start from the first real node (after the dummy head)
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->val;
}

// Function to add a node with value `val` at the head (index 0)
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    if (newNode == NULL) return;

    Node* firstRealNode = obj->head->next;  // The first real node after the dummy head

    // Insert newNode between the head dummy and the first real node
    newNode->next = firstRealNode;
    newNode->prev = obj->head;
    
    obj->head->next = newNode;
    firstRealNode->prev = newNode;

    obj->length++;
}

// Function to add a node with value `val` at the tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    if (newNode == NULL) return;

    Node* lastRealNode = obj->tail->prev;  // The last real node before the dummy tail

    // Insert newNode between the last real node and the tail dummy
    newNode->next = obj->tail;
    newNode->prev = lastRealNode;
    
    lastRealNode->next = newNode;
    obj->tail->prev = newNode;

    obj->length++;
}

// Function to add a node with value `val` at the given index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->length) {
        return;  // Invalid index
    }

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);  // Insert at head
    } else if (index == obj->length) {
        myLinkedListAddAtTail(obj, val);  // Insert at tail
    } else {
        Node* newNode = createNode(val);
        if (newNode == NULL) return;

        Node* currentNode = obj->head->next;  // Start from the first real node
        for (int i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }

        // Insert newNode between currentNode and currentNode->next
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        
        currentNode->next->prev = newNode;
        currentNode->next = newNode;

        obj->length++;
    }
}

// Function to delete the node at the given index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length) {
        return;  // Invalid index
    }

    Node* currentNode = obj->head->next;  // Start from the first real node
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }

    // Update the previous and next pointers to remove the currentNode
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;

    free(currentNode);  // Free the memory of the deleted node
    obj->length--;
}

// Function to free the entire linked list, including dummy nodes
void myLinkedListFree(MyLinkedList* obj) {
    Node* currentNode = obj->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);  // Free each node
        currentNode = nextNode;
    }
    free(obj);  // Free the linked list structure
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
