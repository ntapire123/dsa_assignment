# Question 4: Doubly Linked List Implementation

## Data Structure Definition

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
```
- **data**: Integer value stored in the node
- **next**: Pointer to the next node in the list
- **prev**: Pointer to the previous node in the list

## Functions Implemented

### Core Operations
1. **createNode(int data)**: Allocates memory and initializes a new node
2. **insertAtBeginning(Node* head, int data)**: Inserts a new node at the start
3. **insertAtEnd(Node* head, int data)**: Inserts a new node at the end
4. **findNode(Node* head, int data)**: Searches for a node with given data

### Specialized Insert/Delete Operations
1. **insertAfterNode(Node* head, int targetData, int newData)**:
   - Finds the node with targetData
   - Inserts a new node with newData after the target node
   - Updates all necessary pointers (next and prev)
   
2. **deleteNode(Node* head, int data)**:
   - Finds the node with given data
   - Handles three cases:
     - Deleting head node
     - Deleting middle node
     - Deleting tail node
   - Updates pointers of adjacent nodes

### Utility Functions
1. **displayForward(Node* head)**: Traverses and displays list from head to tail
2. **displayBackward(Node* head)**: Traverses and displays list from tail to head
3. **getSize(Node* head)**: Returns the number of nodes in the list
4. **searchValue(Node* head, int value)**: Searches for a value and returns position
5. **freeList(Node* head)**: Deallocates all nodes to prevent memory leaks

### Demonstration Function
**demonstrateOperations()**: Automated demonstration showing all operations

## Main Method Organization

1. **Automated Demonstration**: Shows all operations with sample data
2. **Interactive Mode**: Menu-driven interface allowing user to:
   - Insert nodes at various positions
   - Delete specific nodes
   - Display list in both directions
   - Search for values
   - Get list statistics

## Key Implementation Details

### Insert After Given Node Algorithm
```c
1. Find the target node using findNode()
2. Create new node
3. Set new node's next to target's next
4. Set new node's prev to target
5. If target has a next node, update its prev pointer
6. Set target's next to new node
```

### Delete Node Algorithm
```c
1. Find the node to delete
2. Handle special case: deleting head node
3. Update previous node's next pointer
4. Update next node's prev pointer (if exists)
5. Free the deleted node's memory
```

## Sample Output

```
Doubly Linked List Implementation
================================

=== Demonstrating Doubly Linked List Operations ===

1. Inserting elements at the end: 10, 20, 30, 40
Forward traversal: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> NULL
Backward traversal: NULL <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL
List size: 4

2. Inserting 5 at the beginning
Forward traversal: NULL <-> 5 <-> 10 <-> 20 <-> 30 <-> 40 <-> NULL

3. Inserting 25 after node with data 20
Node with data 25 inserted after node with data 20
Forward traversal: NULL <-> 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> NULL

4. Trying to insert 100 after node with data 99 (should fail)
Node with data 99 not found!

5. Searching for values
Value 25 found at position 4
Value 99 not found in the list

6. Deleting node with data 25
Node with data 25 deleted successfully
Forward traversal: NULL <-> 5 <-> 10 <-> 20 <-> 30 <-> 40 <-> NULL
```

## Advantages of Doubly Linked List

1. **Bidirectional Traversal**: Can traverse in both directions
2. **Efficient Deletion**: Can delete a node in O(1) time if node reference is given
3. **Better Insert Operations**: Easier to insert before a given node
4. **Flexible Navigation**: Can move backward without maintaining additional pointers



**Note**: Insert at end can be O(1) if we maintain a tail pointer.