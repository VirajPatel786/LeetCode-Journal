/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    /**
     * @brief Flattens a multilevel doubly linked list into a single-level doubly linked list.
     * 
     * @param head (Node*): The head of the multilevel doubly linked list.
     * 
     * @return Node*: The head of the flattened doubly linked list.
     */
    Node* flatten(Node* head) {
        Node* currentNode = head;  // Pointer to traverse the main list

        // Traverse through the entire list
        while (currentNode != nullptr) {
            // If the current node has a child, we need to flatten the child list
            if (currentNode->child != nullptr) {
                // Merge the child list with the main list
                mergeChildList(currentNode);
            }

            // Move to the next node in the list
            currentNode = currentNode->next;
        }

        // Return the modified (flattened) list
        return head;
    }

private:
    /**
     * @brief Merges the child list of the current node into the main doubly linked list.
     * 
     * @param currentNode (Node*): The node whose child list needs to be merged.
     */
    void mergeChildList(Node* currentNode) {
        Node* childListHead = currentNode->child;  // Head of the child list
        Node* childListTail = childListHead;  // We will find the tail of the child list

        // Traverse the child list to find the tail node
        while (childListTail->next != nullptr) {
            childListTail = childListTail->next;
        }

        // If the current node has a next node, connect it to the tail of the child list
        if (currentNode->next != nullptr) {
            childListTail->next = currentNode->next;  // Connect tail of the child list to the next node
            currentNode->next->prev = childListTail;  // Set the prev pointer of the next node
        }

        // Connect the current node to the head of the child list
        currentNode->next = childListHead;
        childListHead->prev = currentNode;

        // Remove the child pointer since the child list has been flattened
        currentNode->child = nullptr;
    }
};
