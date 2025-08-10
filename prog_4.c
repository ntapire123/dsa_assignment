#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    return newNode;  // New head
}

// Function to insert at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to find a node with given data
Node* findNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to insert after a given node
Node* insertAfterNode(Node* head, int targetData, int newData) {
    Node* targetNode = findNode(head, targetData);
    
    if (targetNode == NULL) {
        printf("Node with data %d not found!\n", targetData);
        return head;
    }
    
    Node* newNode = createNode(newData);
    if (newNode == NULL) return head;
    
    newNode->next = targetNode->next;
    newNode->prev = targetNode;
    
    if (targetNode->next != NULL) {
        targetNode->next->prev = newNode;
    }
    
    targetNode->next = newNode;
    
    printf("Node with data %d inserted after node with data %d\n", newData, targetData);
    return head;
}

// Function to delete a node
Node* deleteNode(Node* head, int data) {
    Node* nodeToDelete = findNode(head, data);
    
    if (nodeToDelete == NULL) {
        printf("Node with data %d not found!\n", data);
        return head;
    }
    
    // If it's the head node
    if (nodeToDelete == head) {
        head = nodeToDelete->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        // Update the previous node's next pointer
        nodeToDelete->prev->next = nodeToDelete->next;
    }
    
    // Update the next node's prev pointer (if it exists)
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    
    free(nodeToDelete);
    printf("Node with data %d deleted successfully\n", data);
    return head;
}

// Function to display the list forward
void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Forward traversal: NULL <-> ");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf(" <-> NULL\n");
}

// Function to display the list backward
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Go to the last node
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    printf("Backward traversal: NULL <-> ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" <-> ");
        }
        current = current->prev;
    }
    printf(" <-> NULL\n");
}

// Function to get the size of the list
int getSize(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to search for a value
void searchValue(Node* head, int value) {
    Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Value %d not found in the list\n", value);
}

// Function to free the entire list
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function to demonstrate all operations
void demonstrateOperations() {
    Node* head = NULL;
    
    printf("=== Demonstrating Doubly Linked List Operations ===\n\n");
    
    // Insert elements
    printf("1. Inserting elements at the end: 10, 20, 30, 40\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    displayForward(head);
    displayBackward(head);
    printf("List size: %d\n\n", getSize(head));
    
    // Insert at beginning
    printf("2. Inserting 5 at the beginning\n");
    head = insertAtBeginning(head, 5);
    displayForward(head);
    printf("\n");
    
    // Insert after a specific node
    printf("3. Inserting 25 after node with data 20\n");
    head = insertAfterNode(head, 20, 25);
    displayForward(head);
    printf("\n");
    
    // Insert after a non-existent node
    printf("4. Trying to insert 100 after node with data 99 (should fail)\n");
    head = insertAfterNode(head, 99, 100);
    printf("\n");
    
    // Search operations
    printf("5. Searching for values\n");
    searchValue(head, 25);
    searchValue(head, 99);
    printf("\n");
    
    // Delete operations
    printf("6. Deleting node with data 25\n");
    head = deleteNode(head, 25);
    displayForward(head);
    printf("\n");
    
    printf("7. Deleting head node (data 5)\n");
    head = deleteNode(head, 5);
    displayForward(head);
    printf("\n");
    
    printf("8. Trying to delete non-existent node (data 99)\n");
    head = deleteNode(head, 99);
    printf("\n");
    
    // Final state
    printf("9. Final list state:\n");
    displayForward(head);
    displayBackward(head);
    printf("Final list size: %d\n", getSize(head));
    
    // Free memory
    freeList(head);
}

int main() {
    Node* head = NULL;
    int choice, value, targetValue;
    
    printf("Doubly Linked List Implementation\n");
    printf("================================\n\n");
    
    // Run demonstration first
    demonstrateOperations();
    
    printf("\n\n=== Interactive Mode ===\n");
    
    while (1) {
        printf("\n=== Doubly Linked List Operations ===\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after given node\n");
        printf("4. Delete node\n");
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("7. Search value\n");
        printf("8. Get list size\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                printf("Value %d inserted at beginning.\n", value);
                break;
                
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                printf("Value %d inserted at end.\n", value);
                break;
                
            case 3:
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &targetValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAfterNode(head, targetValue, value);
                break;
                
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
                
            case 5:
                displayForward(head);
                break;
                
            case 6:
                displayBackward(head);
                break;
                
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchValue(head, value);
                break;
                
            case 8:
                printf("List size: %d\n", getSize(head));
                break;
                
            case 9:
                printf("Exiting program...\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}