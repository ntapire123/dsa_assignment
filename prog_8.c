// prog_8.c
// Sorting algorithms with performance analysis (comparisons and swaps)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Global variables to count operations
long long comparisons = 0;
long long swaps = 0;

// Function prototypes
void generate_random_array(int arr[], int n);
void print_array(int arr[], int n, const char* title);
void reset_counters();
void print_performance(const char* algorithm_name);
void copy_array(int source[], int dest[], int n);

// Sorting algorithm prototypes
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// Utility functions
void swap(int* a, int* b);
int get_user_choice();
void display_menu();

// Generate array of N random integers in range [1, 1000]
void generate_random_array(int arr[], int n) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }
}

// Print array with title
void print_array(int arr[], int n, const char* title) {
    printf("\n%s:\n", title);

    int limit = (n > 20) ? 20 : n;

    for (int i = 0; i < limit; i++) {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    if (n > 20) {
        printf("\n... (showing first 20 elements out of %d)\n", n);
    } else if (limit % 10 != 0) {
        printf("\n");
    }
}

// Reset performance counters
void reset_counters() {
    comparisons = 0;
    swaps = 0;
}

// Print performance statistics
void print_performance(const char* algorithm_name) {
    printf("\n--- Performance Analysis for %s ---\n", algorithm_name);
    printf("Total Comparisons: %lld\n", comparisons);
    printf("Total Swaps: %lld\n", swaps);
    printf("Total Operations: %lld\n", comparisons + swaps);
}

// Copy array from source to destination
void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Swap two elements
void swap(int* a, int* b) {
    swaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Display sorting algorithm menu
void display_menu() {
    printf("\n========================================\n");
    printf("CHOOSE A SORTING ALGORITHM:\n");
    printf("========================================\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Run All Algorithms (Comparison)\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1-6): ");
}

// Get user's choice
int get_user_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Bubble Sort implementation
void bubble_sort(int arr[], int n) {
    printf("\nExecuting Bubble Sort...\n");

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// Selection Sort implementation
void selection_sort(int arr[], int n) {
    printf("\nExecuting Selection Sort...\n");

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
    }
}

// Insertion Sort implementation
void insertion_sort(int arr[], int n) {
    printf("\nExecuting Insertion Sort...\n");

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key;
        if (j + 1 != i) {
            swaps++;
        }
    }
}

// Merge Sort implementation
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Merge function for merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* left_arr = (int*)malloc(n1 * sizeof(int));
    int* right_arr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        swaps++;
        k++;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        swaps++;
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        swaps++;
        j++;
        k++;
    }

    free(left_arr);
    free(right_arr);
}

// Run all algorithms for comparison
void run_all_algorithms(int original_arr[], int n) {
    int* temp_arr = (int*)malloc(n * sizeof(int));

    printf("\n======================================================================\n");
    printf("PERFORMANCE COMPARISON OF ALL SORTING ALGORITHMS\n");
    printf("======================================================================\n");

    copy_array(original_arr, temp_arr, n);
    reset_counters();
    bubble_sort(temp_arr, n);
    print_performance("Bubble Sort");

    copy_array(original_arr, temp_arr, n);
    reset_counters();
    selection_sort(temp_arr, n);
    print_performance("Selection Sort");

    copy_array(original_arr, temp_arr, n);
    reset_counters();
    insertion_sort(temp_arr, n);
    print_performance("Insertion Sort");

    copy_array(original_arr, temp_arr, n);
    reset_counters();
    printf("\nExecuting Merge Sort...\n");
    merge_sort(temp_arr, 0, n - 1);
    print_performance("Merge Sort");

    printf("\n======================================================================\n");
    printf("SUMMARY: Best performing algorithm based on total operations:\n");
    printf("(Note: This is for the current dataset. Performance may vary with different data)\n");
    printf("======================================================================\n");

    free(temp_arr);
}

// Main function
int main() {
    printf("============================================================\n");
    printf("SORTING ALGORITHMS WITH PERFORMANCE ANALYSIS\n");
    printf("============================================================\n");

    int n;
    printf("\nEnter the number of random integers to generate (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10000) {
        printf("Invalid input! Please enter a number between 1 and 10000.\n");
        return 1;
    }

    int* original_arr = (int*)malloc(n * sizeof(int));
    int* work_arr = (int*)malloc(n * sizeof(int));

    generate_random_array(original_arr, n);
    print_array(original_arr, n, "Original Unsorted Array");

    int choice;
    do {
        display_menu();
        choice = get_user_choice();

        switch (choice) {
            case 1:
                copy_array(original_arr, work_arr, n);
                reset_counters();
                bubble_sort(work_arr, n);
                print_array(work_arr, n, "Array after Bubble Sort");
                print_performance("Bubble Sort");
                break;

            case 2:
                copy_array(original_arr, work_arr, n);
                reset_counters();
                selection_sort(work_arr, n);
                print_array(work_arr, n, "Array after Selection Sort");
                print_performance("Selection Sort");
                break;

            case 3:
                copy_array(original_arr, work_arr, n);
                reset_counters();
                insertion_sort(work_arr, n);
                print_array(work_arr, n, "Array after Insertion Sort");
                print_performance("Insertion Sort");
                break;

            case 4:
                copy_array(original_arr, work_arr, n);
                reset_counters();
                printf("\nExecuting Merge Sort...\n");
                merge_sort(work_arr, 0, n - 1);
                print_array(work_arr, n, "Array after Merge Sort");
                print_performance("Merge Sort");
                break;

            case 5:
                run_all_algorithms(original_arr, n);
                break;

            case 6:
                printf("\nThank you for using the sorting program!\n");
                break;

            default:
                printf("\nInvalid choice! Please select a number between 1-6.\n");
        }

        if (choice >= 1 && choice <= 5) {
            printf("\nPress Enter to continue...");
            getchar(); // Consume newline
            getchar(); // Wait for user input
        }

    } while (choice != 6);

    free(original_arr);
    free(work_arr);

    return 0;
}