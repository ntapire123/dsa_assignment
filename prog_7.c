// prog_7.c
// Implementation of Dijkstra's algorithm for shortest path

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define INF INT_MAX

// Structure to represent weighted graph
typedef struct {
    int vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} WeightedGraph;

// Function prototypes
WeightedGraph* create_weighted_graph(int vertices);
void add_weighted_edge(WeightedGraph* g, int src, int dest, int weight);
void display_weighted_graph(WeightedGraph* g);
void dijkstra(WeightedGraph* g, int source);
int find_min_distance(int dist[], bool visited[], int vertices);
void print_shortest_path(int parent[], int target, int source);
void print_solution(int dist[], int parent[], int vertices, int source);

// Create a new weighted graph
WeightedGraph* create_weighted_graph(int vertices) {
    WeightedGraph* g = (WeightedGraph*)malloc(sizeof(WeightedGraph));
    g->vertices = vertices;
    
    // Initialize adjacency matrix with 0 (no edge)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                g->adj_matrix[i][j] = 0; // Distance from vertex to itself is 0
            } else {
                g->adj_matrix[i][j] = 0; // No edge initially
            }
        }
    }
    
    return g;
}

// Add a weighted edge between two vertices
void add_weighted_edge(WeightedGraph* g, int src, int dest, int weight) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices && weight > 0) {
        g->adj_matrix[src][dest] = weight;
        // For undirected graph, add edge in both directions
        // g->adj_matrix[dest][src] = weight;
        printf("Edge added: %d -> %d (weight: %d)\n", src, dest, weight);
    } else {
        printf("Invalid edge: %d -> %d (weight: %d)\n", src, dest, weight);
    }
}

// Display the weighted adjacency matrix
void display_weighted_graph(WeightedGraph* g) {
    printf("\nWeighted Adjacency Matrix:\n");
    printf("     ");
    for (int i = 0; i < g->vertices; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < g->vertices; j++) {
            if (g->adj_matrix[i][j] == 0 && i != j) {
                printf("  ∞ ");
            } else {
                printf("%4d", g->adj_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Find vertex with minimum distance that hasn't been visited
int find_min_distance(int dist[], bool visited[], int vertices) {
    int min_dist = INF;
    int min_index = -1;
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min_dist) {
            min_dist = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Print the shortest path from source to target
void print_shortest_path(int parent[], int target, int source) {
    if (target == source) {
        printf("%d", source);
        return;
    }
    
    if (parent[target] == -1) {
        printf("No path exists");
        return;
    }
    
    print_shortest_path(parent, parent[target], source);
    printf(" -> %d", target);
}

// Print the complete solution
void print_solution(int dist[], int parent[], int vertices, int source) {

    printf("SHORTEST PATHS FROM SOURCE VERTEX %d\n", source);

    printf("Vertex\tDistance\tPath\n");
    printf("------\t--------\t----\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%d\t", i);
        
        if (dist[i] == INF) {
            printf("∞\t\tNo path");
        } else {
            printf("%d\t\t", dist[i]);
            print_shortest_path(parent, i, source);
        }
        printf("\n");
    }
}

// Dijkstra's algorithm implementation
void dijkstra(WeightedGraph* g, int source) {
    if (source < 0 || source >= g->vertices) {
        printf("Invalid source vertex!\n");
        return;
    }
    
    int vertices = g->vertices;
    int dist[MAX_VERTICES];      // Distance array
    bool visited[MAX_VERTICES];  // Visited array
    int parent[MAX_VERTICES];    // Parent array to store path
    
    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    // Distance from source to itself is 0
    dist[source] = 0;
    
    printf("\nExecuting Dijkstra's Algorithm...\n");
    printf("Step-by-step execution:\n");
    
    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Find minimum distance vertex from unvisited vertices
        int u = find_min_distance(dist, visited, vertices);
        
        if (u == -1) break; // All remaining vertices are unreachable
        
        // Mark the picked vertex as visited
        visited[u] = true;
        
        printf("\nStep %d: Selected vertex %d (distance: %d)\n", count + 1, u, dist[u]);
        
        // Update distance of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            // Update dist[v] if:
            // 1. v is not visited
            // 2. there is an edge from u to v
            // 3. total weight of path from source to v through u is smaller than current dist[v]
            if (!visited[v] && g->adj_matrix[u][v] > 0 && 
                dist[u] != INF && dist[u] + g->adj_matrix[u][v] < dist[v]) {
                
                int old_dist = dist[v];
                dist[v] = dist[u] + g->adj_matrix[u][v];
                parent[v] = u;
                
                printf("  Updated distance to vertex %d: %d -> %d (via %d)\n", 
                       v, (old_dist == INF ? -1 : old_dist), dist[v], u);
            }
        }
        
        // Print current distances
        printf("  Current distances: ");
        for (int i = 0; i < vertices; i++) {
            if (dist[i] == INF) {
                printf("∞ ");
            } else {
                printf("%d ", dist[i]);
            }
        }
        printf("\n");
    }
    
    // Print the final solution
    print_solution(dist, parent, vertices, source);
}

// Main function to demonstrate Dijkstra's algorithm
int main() {
    printf("DIJKSTRA'S ALGORITHM FOR SHORTEST PATH\n");

    
    // Create a weighted graph with 6 vertices
    WeightedGraph* g = create_weighted_graph(6);
    
    printf("Creating weighted directed graph with 6 vertices (0-5)\n\n");
    printf("Adding weighted edges:\n");
    
    // Add weighted edges to create example graph
    add_weighted_edge(g, 0, 1, 4);
    add_weighted_edge(g, 0, 2, 2);
    add_weighted_edge(g, 1, 2, 1);
    add_weighted_edge(g, 1, 3, 5);
    add_weighted_edge(g, 2, 3, 8);
    add_weighted_edge(g, 2, 4, 10);
    add_weighted_edge(g, 3, 4, 2);
    add_weighted_edge(g, 3, 5, 6);
    add_weighted_edge(g, 4, 5, 3);
    
    // Display the weighted adjacency matrix
    display_weighted_graph(g);
    
    // Run Dijkstra's algorithm from vertex 0
    dijkstra(g, 0);
    
    // Test with different source vertex
    
    printf("Testing with different source vertex (vertex 1):\n");
    dijkstra(g, 1);
    
    // Create another example graph
   
    printf("ANOTHER EXAMPLE - Different Graph Structure\n");
    
    
    WeightedGraph* g2 = create_weighted_graph(5);
    
    printf("\nCreating another weighted graph with 5 vertices (0-4)\n\n");
    printf("Adding weighted edges:\n");
    
    add_weighted_edge(g2, 0, 1, 10);
    add_weighted_edge(g2, 0, 4, 3);
    add_weighted_edge(g2, 1, 2, 2);
    add_weighted_edge(g2, 1, 4, 4);
    add_weighted_edge(g2, 2, 3, 9);
    add_weighted_edge(g2, 3, 2, 7);
    add_weighted_edge(g2, 4, 1, 1);
    add_weighted_edge(g2, 4, 2, 8);
    add_weighted_edge(g2, 4, 3, 2);
    
    display_weighted_graph(g2);
    dijkstra(g2, 0);
    
    // Clean up memory
    free(g);
    free(g2);
    
    return 0;
}
