typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int length;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (list == NULL) {
        fprintf(stderr, "Linked List Memory Allocation Failed");
        return NULL;
    }
    list->head = NULL;
    list->length = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if ((index < 0) || (index >= obj->length)) {
        return -1;
    }
    else {
        Node* currentNode = obj->head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->val;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Node Memory Allocation Failed");
        return;
    }
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->length++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Node Memory Allocation Failed");
        return;
    }
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    }
    else {
        Node* currentNode = obj->head;
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    obj->length++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if ((index < 0) || (index > obj->length)) {
        return;
    }
    else if (index == 0) {
        myLinkedListAddAtHead(obj, val);
    }
    else if (index == obj->length) {
        myLinkedListAddAtTail(obj, val);
    }
    else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            fprintf(stderr, "Node Memory Allocation Failed");
            return;
        }
        newNode->val = val;
        newNode->next = NULL;
        Node* currentNode = obj->head;
        for (int i = 0; i < (index - 1); i++) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        obj->length++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if ((index < 0) || (index >= obj->length)) {
        return;
    }
    Node* currentNode = obj->head;
    if (index == 0) {
        obj->head = currentNode->next;
        free(currentNode);
    }
    else {
        Node* previousNode = NULL;
        for (int i = 0; i < index; i++) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        previousNode->next = currentNode->next;
        free(currentNode);
    }
    obj->length--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* currentNode = obj->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(obj);
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