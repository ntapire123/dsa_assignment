# Documentation for prog_7.c - Dijkstra's Algorithm for Shortest Path

## Data Structure Definition

The weighted graph is implemented using an **adjacency matrix** representation:

```c
typedef struct {
    int vertices;                                    // Number of vertices in the graph
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];     // 2D array to store edge weights
} WeightedGraph;
```

### Key Components:
- **vertices**: Total number of vertices in the graph
- **adj_matrix**: 2D integer array where `adj_matrix[i][j]` stores the weight of edge from vertex i to vertex j
- **Weight 0**: Indicates no direct edge between vertices (except diagonal elements)
- **MAX_VERTICES**: Constant defining maximum vertices (set to 20)
- **INF**: Represents infinity using `INT_MAX` for unreachable vertices

## Functions Implemented

### Graph Creation and Management

1. **`WeightedGraph* create_weighted_graph(int vertices)`**
   - Purpose: Creates weighted graph with specified number of vertices
   - Initializes adjacency matrix with 0 (no edges)
   - Sets diagonal elements to 0 (distance from vertex to itself)
   - Returns pointer to created graph structure

2. **`void add_weighted_edge(WeightedGraph* g, int src, int dest, int weight)`**
   - Purpose: Adds directed weighted edge from source to destination
   - Sets `adj_matrix[src][dest] = weight`
   - Includes validation for vertex bounds and positive weights
   - Note: Creates directed edge (for undirected, would need both directions)

3. **`void display_weighted_graph(WeightedGraph* g)`**
   - Purpose: Displays adjacency matrix with weights
   - Shows ∞ symbol for non-existent edges
   - Formatted table with vertex indices as headers

### Dijkstra's Algorithm Implementation

4. **`void dijkstra(WeightedGraph* g, int source)`**
   - Purpose: Finds shortest paths from source to all other vertices
   - Implements classic Dijkstra's algorithm using adjacency matrix
   - Maintains distance array, visited array, and parent array
   - Provides step-by-step execution details
   - Time Complexity: O(V²) where V is number of vertices

5. **`int find_min_distance(int dist[], bool visited[], int vertices)`**
   - Purpose: Finds unvisited vertex with minimum distance
   - Linear search through distance array
   - Returns index of vertex with minimum distance
   - Used in each iteration of Dijkstra's algorithm

### Path Reconstruction and Display

6. **`void print_shortest_path(int parent[], int target, int source)`**
   - Purpose: Recursively prints shortest path from source to target
   - Uses parent array to backtrack from target to source
   - Displays path in format: source -> intermediate -> ... -> target

7. **`void print_solution(int dist[], int parent[], int vertices, int source)`**
   - Purpose: Displays complete shortest path solution
   - Shows distance and path from source to each vertex
   - Formatted table with columns for vertex, distance, and path
   - Handles unreachable vertices (distance = ∞)

## Algorithm Details

### Dijkstra's Algorithm Steps:
1. **Initialization**:
   - Set distance to source as 0, all others as infinity
   - Mark all vertices as unvisited
   - Initialize parent array for path reconstruction

2. **Main Loop** (V-1 iterations):
   - Select unvisited vertex with minimum distance
   - Mark selected vertex as visited
   - Update distances of all adjacent unvisited vertices

3. **Distance Update** (Relaxation):
   - For each adjacent vertex v of current vertex u:
   - If `dist[u] + weight(u,v) < dist[v]`:
     - Update `dist[v] = dist[u] + weight(u,v)`
     - Set `parent[v] = u`

## Main Function Organization

The `main()` function demonstrates Dijkstra's algorithm with comprehensive examples:

### Example Graph 1 (6 vertices):
- **Vertices**: 0, 1, 2, 3, 4, 5
- **Edges with weights**:
  - 0→1 (4), 0→2 (2), 1→2 (1), 1→3 (5)
  - 2→3 (8), 2→4 (10), 3→4 (2), 3→5 (6), 4→5 (3)

### Example Graph 2 (5 vertices):
- **Different structure** to show algorithm versatility
- **Vertices**: 0, 1, 2, 3, 4
- **Various weighted connections** demonstrating different path scenarios

### Execution Flow:
1. **Graph Creation**: Initialize weighted graph
2. **Edge Addition**: Add weighted edges with validation
3. **Matrix Display**: Show adjacency matrix representation
4. **Algorithm Execution**: Run Dijkstra with step-by-step output
5. **Results Display**: Show shortest distances and paths
6. **Multiple Tests**: Different source vertices and graph structures



## Key Features

### Algorithm Properties:
- **Optimal Solution**: Guarantees shortest paths for non-negative weights
- **Greedy Approach**: Makes locally optimal choices
- **Time Complexity**: O(V²) with adjacency matrix implementation
- **Space Complexity**: O(V) for distance, visited, and parent arrays

### Implementation Features:
- **Step-by-step Visualization**: Shows algorithm execution process
- **Path Reconstruction**: Displays actual shortest paths, not just distances
- **Multiple Examples**: Different graph structures and source vertices
- **Input Validation**: Checks for valid vertices and positive weights
- **Formatted Output**: Clear tabular display of results
- **Memory Management**: Proper allocation and cleanup
