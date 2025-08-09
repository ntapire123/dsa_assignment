# Question 3: Reverse Traversal of Linked List

## Data Structure Definition

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```
- **data**: Integer value stored in the node
- **next**: Pointer to the next node in the list

## Functions Implemented

### Basic Linked List Operations
1. **createNode(int data)**: Allocates memory and creates a new node
2. **insertAtBeginning(Node* head, int data)**: Inserts node at the start of list
3. **insertAtEnd(Node* head, int data)**: Inserts node at the end of list
4. **displayForward(Node* head)**: Displays list in normal forward order
5. **getLength(Node* head)**: Returns the number of nodes in the list
6. **freeList(Node* head)**: Frees all allocated memory

### Reverse Traversal Methods

#### Method 1: Recursive Approach
**Function**: `reverseTraversalRecursive(Node* head)`
- Uses recursion to traverse to the end first
- Prints data during the return phase of recursion
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) due to recursion stack

#### Method 2: Stack-based Approach
**Function**: `reverseTraversalStack(Node* head)`
- Uses an array as a stack to store all node values
- Traverses list once to push values, then pops to print in reverse
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) for stack array

#### Method 3: Array-based Approach
**Function**: `reverseTraversalArray(Node* head)`
- Stores all values in an array during forward traversal
- Prints array contents in reverse order
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) for array

#### Method 4: List Reversal Approach
**Function**: `reverseTraversalByReversing(Node* head)`
- Temporarily reverses the entire linked list
- Displays the reversed list
- Reverses back to original order
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### Helper Function
**reverseList(Node* head)**: Reverses the linked list by changing pointers

## Main Method Organization

1. **Initialization**: Creates a sample linked list with values 10, 20, 30, 40, 50
2. **Menu System**: Interactive menu allowing user to:
   - Display list normally
   - Test different reverse traversal methods
   - Add new elements
   - Exit program
3. **Memory Management**: Properly frees allocated memory before exit

## Sample Output

```
Linked List Reverse Traversal Implementation
==========================================

Creating sample linked list with values: 10, 20, 30, 40, 50

=== Linked List Operations ===
1. Display list (forward)
2. Reverse traversal (recursive)
3. Reverse traversal (using stack)
4. Reverse traversal (using array)
5. Reverse traversal (by reversing list)
6. Insert at beginning
7. Insert at end
8. Exit
Enter your choice: 1

Forward traversal: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

Enter your choice: 2
Reverse traversal (recursive): 50 <- 40 <- 30 <- 20 <- 10 <- NULL

Enter your choice: 3
Reverse traversal (using stack): 50 <- 40 <- 30 <- 20 <- 10 <- NULL

Enter your choice: 4
Reverse traversal (using array): 50 <- 40 <- 30 <- 20 <- 10 <- NULL
```

