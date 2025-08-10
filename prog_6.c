// prog_6.c
// Implementation of Min and Max Heap from unsorted array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Min Heap structure
typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

// Max Heap structure
typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

// Function prototypes
MinHeap* create_min_heap();
MaxHeap* create_max_heap();
void build_min_heap(MinHeap* heap, int arr[], int n);
void build_max_heap(MaxHeap* heap, int arr[], int n);
void min_heapify(MinHeap* heap, int index);
void max_heapify(MaxHeap* heap, int index);
void display_min_heap(MinHeap* heap);
void display_max_heap(MaxHeap* heap);
void swap(int* a, int* b);
void print_array(int arr[], int size);

// Create a new min heap
MinHeap* create_min_heap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

// Create a new max heap
MaxHeap* create_max_heap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0;
    return heap;
}

// Swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Build min heap from array
void build_min_heap(MinHeap* heap, int arr[], int n) {
    heap->size = n;
    
    // Copy array elements to heap
    for (int i = 0; i < n; i++) {
        heap->data[i] = arr[i];
    }
    
    // Start from last non-leaf node and heapify downward
    for (int i = (n / 2) - 1; i >= 0; i--) {
        min_heapify(heap, i);
    }
}

// Build max heap from array
void build_max_heap(MaxHeap* heap, int arr[], int n) {
    heap->size = n;
    
    // Copy array elements to heap
    for (int i = 0; i < n; i++) {
        heap->data[i] = arr[i];
    }
    
    // Start from last non-leaf node and heapify downward
    for (int i = (n / 2) - 1; i >= 0; i--) {
        max_heapify(heap, i);
    }
}

// Maintain min heap property
void min_heapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;      // Left child
    int right = 2 * index + 2;     // Right child
    
    // Find smallest among root, left child, and right child
    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    
    // If smallest is not root, swap and recursively heapify
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

// Maintain max heap property
void max_heapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;      // Left child
    int right = 2 * index + 2;     // Right child
    
    // Find largest among root, left child, and right child
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    
    // If largest is not root, swap and recursively heapify
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        max_heapify(heap, largest);
    }
}

// Display min heap
void display_min_heap(MinHeap* heap) {
    printf("Min Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
    
    // Display heap structure (level by level)
    printf("Min Heap Structure:\n");
    int level = 0;
    int nodes_in_level = 1;
    int current_count = 0;
    
    for (int i = 0; i < heap->size; i++) {
        if (current_count == 0) {
            printf("Level %d: ", level);
        }
        
        printf("%d ", heap->data[i]);
        current_count++;
        
        if (current_count == nodes_in_level) {
            printf("\n");
            level++;
            nodes_in_level *= 2;
            current_count = 0;
        }
    }
    
    if (current_count > 0) {
        printf("\n");
    }
}

// Display max heap
void display_max_heap(MaxHeap* heap) {
    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
    
    // Display heap structure (level by level)
    printf("Max Heap Structure:\n");
    int level = 0;
    int nodes_in_level = 1;
    int current_count = 0;
    
    for (int i = 0; i < heap->size; i++) {
        if (current_count == 0) {
            printf("Level %d: ", level);
        }
        
        printf("%d ", heap->data[i]);
        current_count++;
        
        if (current_count == nodes_in_level) {
            printf("\n");
            level++;
            nodes_in_level *= 2;
            current_count = 0;
        }
    }
    
    if (current_count > 0) {
        printf("\n");
    }
}

// Print array
void print_array(int arr[], int size) {
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate heap operations
int main() {

    printf("MIN AND MAX HEAP IMPLEMENTATION\n");
  
    
    // Test with predefined unsorted array
    int arr1[] = {12, 11, 13, 5, 6, 7, 23, 3, 4, 18};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Test Case 1:\n");
    print_array(arr1, n1);
    
    // Build min heap
    MinHeap* min_heap1 = create_min_heap();
    build_min_heap(min_heap1, arr1, n1);
    printf("\n");
    display_min_heap(min_heap1);
    
    // Build max heap
    MaxHeap* max_heap1 = create_max_heap();
    build_max_heap(max_heap1, arr1, n1);
    printf("\n");
    display_max_heap(max_heap1);
    

    
    // Test with another array
    int arr2[] = {4, 10, 3, 5, 1, 15, 20, 7, 8, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Test Case 2:\n");
    print_array(arr2, n2);
    
    // Build min heap
    MinHeap* min_heap2 = create_min_heap();
    build_min_heap(min_heap2, arr2, n2);
    printf("\n");
    display_min_heap(min_heap2);
    
    // Build max heap
    MaxHeap* max_heap2 = create_max_heap();
    build_max_heap(max_heap2, arr2, n2);
    printf("\n");
    display_max_heap(max_heap2);
    
    // Test with user input
   
    printf("Enter your own array:\n");
    
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n > 0 && n <= MAX_SIZE) {
        int* user_arr = (int*)malloc(n * sizeof(int));
        
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &user_arr[i]);
        }
        
        print_array(user_arr, n);
        
        // Build min heap
        MinHeap* min_heap_user = create_min_heap();
        build_min_heap(min_heap_user, user_arr, n);
        printf("\n");
        display_min_heap(min_heap_user);
        
        // Build max heap
        MaxHeap* max_heap_user = create_max_heap();
        build_max_heap(max_heap_user, user_arr, n);
        printf("\n");
        display_max_heap(max_heap_user);
        
        free(user_arr);
        free(min_heap_user);
        free(max_heap_user);
    } else {
        printf("Invalid input size!\n");
    }
    
    // Clean up memory
    free(min_heap1);
    free(max_heap1);
    free(min_heap2);
    free(max_heap2);
    
    return 0;
}