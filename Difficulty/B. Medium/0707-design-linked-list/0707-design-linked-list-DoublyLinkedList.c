#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;  // Pointer to the previous node
    int val;            // Value stored in the node
    struct Node* next;  // Pointer to the next node
} Node;

typedef struct {
    Node* head;    // Pointer to the head node
    Node* tail;    // Pointer to the tail node for efficiency in tail operations
    int length;    // Length of the linked list
} MyLinkedList;

// Function to create a new linked list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (list == NULL) {
        fprintf(stderr, "Linked List Memory Allocation Failed");
        return NULL;
    }
    list->head = NULL;  // Initialize head and tail to NULL
    list->tail = NULL;
    list->length = 0;
    return list;
}

// Function to get the value at the given index
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length) {
        return -1;  // Return -1 if the index is invalid
    }
    Node* currentNode = obj->head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->val;
}

// Function to add a node with value `val` at the head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Node Memory Allocation Failed");
        return;
    }
    newNode->val = val;
    newNode->next = obj->head;  // New node points to the current head
    newNode->prev = NULL;       // Since it's the head, prev is NULL

    if (obj->head != NULL) {
        obj->head->prev = newNode;  // Set the current head's prev to the new node
    }
    
    obj->head = newNode;  // Update the head to be the new node
    if (obj->tail == NULL) {
        obj->tail = newNode;  // If the list was empty, the new node is also the tail
    }
    obj->length++;
}

// Function to add a node with value `val` at the tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Node Memory Allocation Failed");
        return;
    }
    newNode->val = val;
    newNode->next = NULL;  // Since it's the tail, next is NULL
    newNode->prev = obj->tail;  // New node's prev points to the current tail

    if (obj->tail != NULL) {
        obj->tail->next = newNode;  // Update current tail's next to the new node
    }
    
    obj->tail = newNode;  // Update the tail to be the new node
    if (obj->head == NULL) {
        obj->head = newNode;  // If the list was empty, the new node is also the head
    }
    obj->length++;
}

// Function to add a node with value `val` at the given index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->length) {
        return;  // Invalid index
    }
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);  // Insert at the head
    } else if (index == obj->length) {
        myLinkedListAddAtTail(obj, val);  // Insert at the tail
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            fprintf(stderr, "Node Memory Allocation Failed");
            return;
        }
        newNode->val = val;
        
        Node* currentNode = obj->head;
        for (int i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;  // Traverse to the node before the index
        }
        
        newNode->next = currentNode->next;  // New node points to the node currently at index
        newNode->prev = currentNode;        // New node's prev points to the current node
        
        if (currentNode->next != NULL) {
            currentNode->next->prev = newNode;  // Update the next node's prev pointer
        }
        currentNode->next = newNode;  // Link the current node to the new node
        
        obj->length++;
    }
}

// Function to delete the node at the given index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length) {
        return;  // Invalid index
    }
    
    Node* currentNode = obj->head;
    if (index == 0) {
        // Deleting the head
        obj->head = currentNode->next;
        if (obj->head != NULL) {
            obj->head->prev = NULL;  // Set the new head's prev to NULL
        } else {
            obj->tail = NULL;  // List becomes empty, so tail should be NULL
        }
        free(currentNode);
    } else {
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;  // Traverse to the node at the index
        }
        
        if (currentNode->prev != NULL) {
            currentNode->prev->next = currentNode->next;  // Update previous node's next pointer
        }
        
        if (currentNode->next != NULL) {
            currentNode->next->prev = currentNode->prev;  // Update next node's prev pointer
        } else {
            obj->tail = currentNode->prev;  // Update tail if we are deleting the last node
        }
        
        free(currentNode);
    }
    
    obj->length--;
}

// Function to free the linked list and its nodes
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
