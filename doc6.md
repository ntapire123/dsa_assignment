# Documentation for prog_6.c - Min and Max Heap Implementation

## Data Structure Definition

The program implements both Min Heap and Max Heap data structures using the following definitions:

### Min Heap Structure:
```c
typedef struct {
    int data[MAX_SIZE];    // Array to store heap elements
    int size;              // Current number of elements in heap
} MinHeap;
```

### Max Heap Structure:
```c
typedef struct {
    int data[MAX_SIZE];    // Array to store heap elements
    int size;              // Current number of elements in heap
} MaxHeap;
```

### Key Properties:
- **MAX_SIZE**: Constant defining maximum heap capacity (set to 100)
- **Array-based implementation**: Uses complete binary tree representation
- **Parent-child relationships**: For element at index i:
  - Parent: `(i-1)/2`
  - Left child: `2*i + 1`
  - Right child: `2*i + 2`

## Functions Implemented

### Heap Creation and Management

1. **`MinHeap* create_min_heap()`**
   - Purpose: Creates and initializes an empty min heap
   - Allocates memory and sets size to 0
   - Returns pointer to created heap structure

2. **`MaxHeap* create_max_heap()`**
   - Purpose: Creates and initializes an empty max heap
   - Similar to min heap creation but for max heap

### Heap Building Functions

3. **`void build_min_heap(MinHeap* heap, int arr[], int n)`**
   - Purpose: Constructs min heap from unsorted array
   - Copies array elements to heap structure
   - Calls `min_heapify()` from last non-leaf node upwards
   - Time Complexity: O(n)

4. **`void build_max_heap(MaxHeap* heap, int arr[], int n)`**
   - Purpose: Constructs max heap from unsorted array
   - Similar process but maintains max heap property
   - Time Complexity: O(n)

### Heapify Functions

5. **`void min_heapify(MinHeap* heap, int index)`**
   - Purpose: Maintains min heap property at given index
   - Compares element with left and right children
   - Swaps with smallest child if heap property is violated
   - Recursively applies heapify down the tree
   - Time Complexity: O(log n)

6. **`void max_heapify(MaxHeap* heap, int index)`**
   - Purpose: Maintains max heap property at given index
   - Finds largest among parent, left child, and right child
   - Swaps and recursively heapifies if necessary
   - Time Complexity: O(log n)

### Display Functions

7. **`void display_min_heap(MinHeap* heap)`**
   - Purpose: Displays min heap in two formats:
     - Linear array representation
     - Level-by-level tree structure
   - Shows heap elements organized by levels

8. **`void display_max_heap(MaxHeap* heap)`**
   - Purpose: Similar to min heap display but for max heap
   - Provides clear visualization of heap structure

### Utility Functions

9. **`void swap(int* a, int* b)`**
   - Purpose: Swaps two integer values
   - Used during heapify operations

10. **`void print_array(int arr[], int size)`**
    - Purpose: Displays original unsorted array
    - Used for comparison before heap construction

## Main Function Organization

The `main()` function demonstrates heap operations through multiple test cases:

### Test Case Structure:
1. **Predefined Test Cases**: 
   - Uses two different unsorted arrays
   - Shows original array, min heap, and max heap for each

2. **User Input Test**:
   - Prompts user for array size and elements
   - Builds and displays both heap types
   - Validates input size limits

### Execution Flow:
1. **Array Display**: Shows original unsorted array
2. **Min Heap Construction**: Builds and displays min heap
3. **Max Heap Construction**: Builds and displays max heap
4. **Structure Visualization**: Shows level-wise heap organization
5. **Memory Management**: Proper cleanup of allocated resources

## Sample Output

```
=======================================
MIN AND MAX HEAP IMPLEMENTATION
=======================================

Test Case 1:
Original Array: 12 11 13 5 6 7 23 3 4 18 

Min Heap: 3 4 7 5 6 13 23 12 11 18 
Min Heap Structure:
Level 0: 3 
Level 1: 4 7 
Level 2: 5 6 13 23 
Level 3: 12 11 18 

Max Heap: 23 18 13 12 6 7 11 3 4 5 
Max Heap Structure:
Level 0: 23 
Level 1: 18 13 
Level 2: 12 6 7 11 
Level 3: 3 4 5 

==================================================

Test Case 2:
Original Array: 4 10 3 5 1 15 20 7 8 2 

Min Heap: 1 2 3 5 4 15 20 7 8 10 
Min Heap Structure:
Level 0: 1 
Level 1: 2 3 
Level 2: 5 4 15 20 
Level 3: 7 8 10 

Max Heap: 20 10 15 8 4 3 5 7 1 2 
Max Heap Structure:
Level 0: 20 
Level 1: 10 15 
Level 2: 8 4 3 5 
Level 3: 7 1 2 
```

## Key Features

### Algorithm Efficiency:
- **Build Heap**: O(n) time complexity using bottom-up approach
- **Heapify**: O(log n) time complexity for single operation
- **Space**: O(1) additional space (in-place heap construction)

### Heap Properties Maintained:
- **Min Heap**: Parent ≤ both children for all nodes
- **Max Heap**: Parent ≥ both children for all nodes
- **Complete Binary Tree**: All levels filled except possibly the last
- **Array Representation**: Efficient storage without explicit pointers

### Program Features:
- **Dual Implementation**: Both min and max heaps in single program
- **Visual Structure Display**: Level-by-level tree representation
- **Multiple Test Cases**: Comprehensive testing with different datasets
- **User Interaction**: Allows custom input arrays
- **Memory Safety**: Proper allocation and deallocation
- **Input Validation**: Checks for valid array sizes