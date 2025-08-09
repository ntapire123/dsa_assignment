#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
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
    return newNode;
}

// Function to insert at the beginning of the list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = head;
    return newNode;
}

// Function to insert at the end of the list
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
    return head;
}

// Function to display the linked list (forward)
void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Forward traversal: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

// Method 1: Reverse traversal using recursion
void reverseTraversalRecursive(Node* head) {
    if (head == NULL) {
        return;
    }
    
    // Recursive call first
    reverseTraversalRecursive(head->next);
    
    // Print after recursive call (this prints in reverse)
    printf("%d", head->data);
    if (head != NULL) {
        printf(" <- ");
    }
}

// Method 2: Reverse traversal using stack
void reverseTraversalStack(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Create an array to act as stack
    int stack[1000];  // Assuming max 1000 nodes
    int top = -1;
    
    // Push all elements to stack
    Node* current = head;
    while (current != NULL) {
        stack[++top] = current->data;
        current = current->next;
    }
    
    printf("Reverse traversal (using stack): ");
    // Pop and print all elements
    while (top >= 0) {
        printf("%d", stack[top--]);
        if (top >= 0) {
            printf(" <- ");
        }
    }
    printf(" <- NULL\n");
}

// Method 3: Reverse traversal by reversing the list temporarily
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;    // Store next
        current->next = prev;    // Reverse the link
        prev = current;          // Move prev forward
        current = next;          // Move current forward
    }
    
    return prev;  // New head
}

void reverseTraversalByReversing(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Reverse the list
    Node* reversedHead = reverseList(head);
    
    printf("Reverse traversal (by reversing list): ");
    displayForward(reversedHead);
    
    // Reverse back to original
    Node* originalHead = reverseList(reversedHead);
}

// Function to get the length of the list
int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Method 4: Reverse traversal using array indexing
void reverseTraversalArray(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    int length = getLength(head);
    int* arr = (int*)malloc(length * sizeof(int));
    
    // Store all elements in array
    Node* current = head;
    int i = 0;
    while (current != NULL) {
        arr[i++] = current->data;
        current = current->next;
    }
    
    printf("Reverse traversal (using array): ");
    // Print array in reverse order
    for (i = length - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf(" <- ");
        }
    }
    printf(" <- NULL\n");
    
    free(arr);
}

// Function to free the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    int choice, value;
    
    printf("Linked List Reverse Traversal Implementation\n");
    printf("==========================================\n\n");
    
    // Create a sample linked list
    printf("Creating sample linked list with values: 10, 20, 30, 40, 50\n\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    
    while (1) {
        printf("\n=== Linked List Operations ===\n");
        printf("1. Display list (forward)\n");
        printf("2. Reverse traversal (recursive)\n");
        printf("3. Reverse traversal (using stack)\n");
        printf("4. Reverse traversal (using array)\n");
        printf("5. Reverse traversal (by reversing list)\n");
        printf("6. Insert at beginning\n");
        printf("7. Insert at end\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayForward(head);
                break;
                
            case 2:
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("Reverse traversal (recursive): ");
                    reverseTraversalRecursive(head);
                    printf("NULL\n");
                }
                break;
                
            case 3:
                reverseTraversalStack(head);
                break;
                
            case 4:
                reverseTraversalArray(head);
                break;
                
            case 5:
                reverseTraversalByReversing(head);
                break;
                
            case 6:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                printf("Value %d inserted at beginning.\n", value);
                break;
                
            case 7:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                printf("Value %d inserted at end.\n", value);
                break;
                
            case 8:
                printf("Exiting program...\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}