// prog_8.c
// Sorting algorithms with performance analysis (comparisons and swaps)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }
}

// Print array with title
void print_array(int arr[], int n, const char* title) {
    printf("\n%s:\n", title);
    
    // Print first 20 elements if array is large
    int limit = (n > 20) ? 20 : n;
    
    for (int i = 0; i < limit; i++)