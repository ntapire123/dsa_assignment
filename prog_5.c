// prog_5.c
// Implementation of undirected graph using adjacency matrix with BFS and DFS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Structure to represent the graph
typedef struct {
    int vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Function prototypes
Graph* create_graph(int vertices);
void add_edge(Graph* g, int src, int dest);
void display_graph(Graph* g);
void bfs(Graph* g, int start_vertex);
void dfs(Graph* g, int start_vertex);
void dfs_recursive(Graph* g, int vertex, bool visited[]);
Queue* create_queue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool is_empty(Queue* q);

// Create a new graph with given number of vertices
Graph* create_graph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = vertices;
    
    // Initialize adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    
    return g;
}

// Add an edge between two vertices (undirected)
void add_edge(Graph* g, int src, int dest) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
        g->adj_matrix[src][dest] = 1;
        g->adj_matrix[dest][src] = 1; // Undirected graph
        printf("Edge added: %d - %d\n", src, dest);
    } else {
        printf("Invalid vertices: %d, %d\n", src, dest);
    }
}

// Display the adjacency matrix
void display_graph(Graph* g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->vertices; j++) {
            printf("%2d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Create a new queue
Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Add element to queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;
    q->items[q->rear] = value;
}

// Remove element from queue
int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int item = q->items[q->front];
    q->front++;
    
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    
    return item;
}

// Check if queue is empty
bool is_empty(Queue* q) {
    return q->front == -1;
}

// Breadth-First Search traversal
void bfs(Graph* g, int start_vertex) {
    if (start_vertex < 0 || start_vertex >= g->vertices) {
        printf("Invalid starting vertex!\n");
        return;
    }
    
    bool visited[MAX_VERTICES] = {false};
    Queue* q = create_queue();
    
    printf("\nBFS Traversal starting from vertex %d:\n", start_vertex);
    
    // Mark start vertex as visited and enqueue it
    visited[start_vertex] = true;
    enqueue(q, start_vertex);
    
    while (!is_empty(q)) {
        int current = dequeue(q);
        printf("Visited: %d\n", current);
        
        // Check all adjacent vertices
        for (int i = 0; i < g->vertices; i++) {
            if (g->adj_matrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
    
    free(q);
}

// Depth-First Search traversal (recursive)
void dfs(Graph* g, int start_vertex) {
    if (start_vertex < 0 || start_vertex >= g->vertices) {
        printf("Invalid starting vertex!\n");
        return;
    }
    
    bool visited[MAX_VERTICES] = {false};
    
    printf("\nDFS Traversal starting from vertex %d:\n", start_vertex);
    dfs_recursive(g, start_vertex, visited);
}

// Recursive helper function for DFS
void dfs_recursive(Graph* g, int vertex, bool visited[]) {
    // Mark current vertex as visited
    visited[vertex] = true;
    printf("Visited: %d\n", vertex);
    
    // Visit all unvisited adjacent vertices
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj_matrix[vertex][i] == 1 && !visited[i]) {
            dfs_recursive(g, i, visited);
        }
    }
}

// Main function to demonstrate graph operations
int main() {

    printf("UNDIRECTED GRAPH WITH BFS AND DFS TRAVERSAL\n");
 
    
    // Create a graph with 6 vertices
    Graph* g = create_graph(6);
    
    printf("Creating graph with 6 vertices (0-5)\n\n");
    printf("Adding edges:\n");
    
    // Add edges to create example graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 5);
    add_edge(g, 3, 5);
    
    // Display the adjacency matrix
    display_graph(g);
    
    // Perform BFS traversal from vertex 0
    bfs(g, 0);
    
    // Perform DFS traversal from vertex 0
    dfs(g, 0);
    
    // Test with different starting vertex
    printf("\n--- Testing with different starting vertex ---\n");
    bfs(g, 2);
    dfs(g, 2);
    
    free(g);
    
    return 0;
}