# Documentation for prog_8.c - Sorting Algorithms with Performance Analysis

## Data Structure Definition

The program uses simple integer arrays and global counters for performance tracking:

### Global Performance Counters:
```c
long long comparisons = 0;    // Counts comparison operations
long long swaps = 0;          // Counts swap/assignment operations
```

### Array Management:
- **original_arr**: Stores the initial random array (unchanged)
- **work_arr**: Working copy for sorting operations
- **Dynamic allocation**: Uses `malloc()` for flexible array sizes
- **Range**: Random integers between 1 and 1000

## Functions Implemented

### Array Generation and Management

1. **`void generate_random_array(int arr[], int n)`**
   - Purpose: Generates N random integers in range [1, 1000]
   - Uses `srand(time(NULL))` for different sequences each run
   - Fills array with `rand() % 1000 + 1`

2. **`void print_array(int arr[], int n, const char* title)`**
   - Purpose: Displays array with descriptive title
   - Shows first 20 elements if array is large (>20 elements)
   - Formats output in rows of 10 elements each

3. **`void copy_array(int source[], int dest[], int n)`**
   - Purpose: Creates exact copy of source array
   - Used to preserve original array for multiple sorting tests
   - Enables fair comparison between algorithms

### Performance Tracking

4. **`void reset_counters()`**
   - Purpose: Resets global performance counters to zero
   - Called before each sorting algorithm execution
   - Ensures accurate measurement for each algorithm

5. **`void print_performance(const char* algorithm_name)`**
   - Purpose: Displays performance statistics for given algorithm
   - Shows total comparisons, swaps, and combined operations
   - Provides comparative analysis data

### User Interface

6. **`void display_menu()`**
   - Purpose: Shows interactive menu of sorting algorithms
   - Lists all available options with clear formatting
   - Includes option to run all algorithms for comparison

7. **`int get_user_choice()`**
   - Purpose: Reads and returns user's menu selection
   - Simple input handling for menu navigation

### Utility Functions

8. **`void swap(int* a, int* b)`**
   - Purpose: Swaps two integer values and increments swap counter
   - Used by all sorting algorithms that perform swaps
   - Automatically tracks swap operations for performance analysis

## Sorting Algorithms Implementation

### 1. Bubble Sort
```c
void bubble_sort(int arr[], int n)
```
- **Algorithm**: Repeatedly compares adjacent elements and swaps if out of order
- **Optimization**: Early termination if no swaps occur in a pass
- **Time Complexity**: 
  - Best Case: O(n) - when array is already sorted
  - Average/Worst Case: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Stable sorting algorithm

### 2. Selection Sort
```c
void selection_sort(int arr[], int n)
```
- **Algorithm**: Finds minimum element and places it at beginning, repeat for remaining array
- **Process**: 
  - Find minimum in unsorted portion
  - Swap with first element of unsorted portion
  - Move boundary between sorted and unsorted portions
- **Time Complexity**: O(n²) in all cases
- **Space Complexity**: O(1)
- **Stability**: Not stable (can change relative order of equal elements)

### 3. Insertion Sort
```c
void insertion_sort(int arr[], int n)
```
- **Algorithm**: Builds sorted array one element at a time
- **Process**: 
  - Take element from unsorted portion
  - Find correct position in sorted portion
  - Shift elements and insert
- **Time Complexity**: 
  - Best Case: O(n) - when array is already sorted
  - Average/Worst Case: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Stable sorting algorithm

### 4. Merge Sort
```c
void merge_sort(int arr[], int left, int right)
void merge(int arr[], int left, int mid, int right)
```
- **Algorithm**: Divide-and-conquer approach
- **Process**: 
  - Recursively divide array into halves
  - Sort each half independently
  - Merge sorted halves back together
- **Time Complexity**: O(n log n) in all cases
- **Space Complexity**: O(n) - requires additional array space
- **Stability**: Stable sorting algorithm

## Performance Analysis Features

### Comprehensive Comparison Mode
The program includes a special mode that runs all algorithms on the same dataset:

```c
void run_all_algorithms(int original_arr[], int n)
```

This function:
- Tests each algorithm with identical input data
- Measures and displays performance metrics for each
- Provides side-by-side comparison of all algorithms
- Helps identify best-performing algorithm for given dataset

### Metrics Tracked:
- **Comparisons**: Number of element comparisons performed
- **Swaps**: Number of swap/assignment operations
- **Total Operations**: Sum of comparisons and swaps
- **Execution Flow**: Step-by-step algorithm execution display

## Main Function Organization

### Program Flow:
1. **User Input**: 
   - Prompts for array size (N)
   - Validates input range (1-10000)

2. **Array Generation**: 
   - Creates random array of specified size
   - Displays original unsorted array

3. **Interactive Menu Loop**:
   - Shows sorting algorithm options
   - Processes user selection
   - Executes chosen sorting algorithm
   - Displays results and performance metrics

4. **Algorithm Execution**:
   - Copies original array to working array
   - Resets performance counters
   - Runs selected sorting algorithm
   - Shows sorted array and performance statistics

5. **Memory Management**:
   - Proper allocation and deallocation
   - Cleanup before program termination

## Sample Output

```
============================================================
SORTING ALGORITHMS WITH PERFORMANCE ANALYSIS
============================================================

Enter the number of random integers to generate (N): 10

Original Unsorted Array:
 342  156  789  234   67  891  445  123  678  900

========================================
CHOOSE A SORTING ALGORITHM:
========================================
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Run All Algorithms (Comparison)
6. Exit
========================================
Enter your choice (1-6): 1

Executing Bubble Sort...

Array after Bubble Sort:
  67  123  156  234  342  445  678  789  891  900

--- Performance Analysis for Bubble Sort ---
Total Comparisons: 45
Total Swaps: 25
Total Operations: 70

========================================
Enter your choice (1-6): 5

======================================================================
PERFORMANCE COMPARISON OF ALL SORTING ALGORITHMS
======================================================================

Executing Bubble Sort...
--- Performance Analysis for Bubble Sort ---
Total Comparisons: 45
Total Swaps: 25
Total Operations: 70

Executing Selection Sort...
--- Performance Analysis for Selection Sort ---
Total Comparisons: 45
Total Swaps: 9
Total Operations: 54

Executing Insertion Sort...
--- Performance Analysis for Insertion Sort ---
Total Comparisons: 25
Total Swaps: 26
Total Operations: 51

Executing Merge Sort...
--- Performance Analysis for Merge Sort ---
Total Comparisons: 19
Total Swaps: 32
Total Operations: 51

======================================================================
SUMMARY: Best performing algorithm based on total operations:
(Note: This is for the current dataset. Performance may vary with different data)
======================================================================
```

## Key Features

### Educational Aspects:
- **Algorithm Comparison**: Side-by-side performance analysis
- **Complexity Demonstration**: Shows practical time complexity differences
- **Interactive Learning**: User can experiment with different algorithms
- **Visual Feedback**: Clear display of before/after arrays

### Technical Features:
- **Accurate Counting**: Precise measurement of operations
- **Memory Efficiency**: Proper memory management
- **Input Validation**: Robust error handling
- **Flexible Testing**: Support for various array sizes
- **Fair Comparison**: Same input data for all algorithms

### Performance Insights:
- **Best Case Scenarios**: Shows when certain algorithms excel
- **Worst Case Analysis**: Demonstrates quadratic behavior
- **Practical Understanding**: Real-world performance measurement
- **Algorithm Selection**: Helps choose appropriate algorithm for given scenario