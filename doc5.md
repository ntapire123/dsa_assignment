# Documentation for prog_5.c - Undirected Graph with BFS and DFS

## Data Structure Definition

The undirected graph is implemented using an **adjacency matrix** representation with the following structure:

```c
typedef struct {
    int vertices;                                    // Number of vertices in the graph
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];     // 2D array to store edges
} Graph;
```

### Key Components:
- **vertices**: Stores the total number of vertices in the graph
- **adj_matrix**: A 2D integer array where `adj_matrix[i][j] = 1` indicates an edge between vertex i and vertex j
- **MAX_VERTICES**: Constant defining maximum number of vertices (set to 20)

### Queue Structure for BFS:
```c
typedef struct {
    int items[MAX_VERTICES];    // Array to store queue elements
    int front;                  // Index of front element
    int rear;                   // Index of rear element
} Queue;
```

## Functions Implemented

### Graph Creation and Management
1. **`Graph* create_graph(int vertices)`**
   - Purpose: Creates a new graph with specified number of vertices
   - Initializes adjacency matrix with zeros
   - Returns pointer to the created graph

2. **`void add_edge(Graph* g, int src, int dest)`**
   - Purpose: Adds an undirected edge between two vertices
   - Sets both `adj_matrix[src][dest]` and `adj_matrix[dest][src]` to 1
   - Includes input validation for vertex bounds

3. **`void display_graph(Graph* g)`**
   - Purpose: Displays the adjacency matrix in formatted table
   - Shows vertex indices and corresponding connections

### Graph Traversal Algorithms
4. **`void bfs(Graph* g, int start_vertex)`**
   - Purpose: Performs Breadth-First Search traversal
   - Uses queue data structure to visit vertices level by level
   - Prints each visited vertex in order
   - Time Complexity: O(V²) where V is number of vertices

5. **`void dfs(Graph* g, int start_vertex)`**
   - Purpose: Initiates Depth-First Search traversal
   - Calls recursive helper function `dfs_recursive`
   - Time Complexity: O(V²) where V is number of vertices

6. **`void dfs_recursive(Graph* g, int vertex, bool visited[])`**
   - Purpose: Recursive helper for DFS implementation
   - Visits current vertex and recursively explores unvisited neighbors
   - Uses call stack implicitly for backtracking

### Queue Operations (for BFS)
7. **`Queue* create_queue()`** - Creates and initializes empty queue
8. **`void enqueue(Queue* q, int value)`** - Adds element to rear of queue
9. **`int dequeue(Queue* q)`** - Removes and returns front element
10. **`bool is_empty(Queue* q)`** - Checks if queue is empty

## Main Function Organization

The `main()` function is organized as follows:

1. **Graph Creation**: Creates a graph with 6 vertices (0-5)
2. **Edge Addition**: Adds predefined edges to create an example graph:
   - 0-1, 0-2, 1-3, 1-4, 2-5, 3-5
3. **Display**: Shows the adjacency matrix representation
4. **BFS Demonstration**: Performs BFS starting from vertex 0
5. **DFS Demonstration**: Performs DFS starting from vertex 0
6. **Additional Testing**: Tests both algorithms with different starting vertex (vertex 2)
7. **Memory Cleanup**: Frees allocated memory

## Sample Output

UNDIRECTED GRAPH WITH BFS AND DFS TRAVERSAL


Creating graph with 6 vertices (0-5)

Adding edges:
Edge added: 0 - 1
Edge added: 0 - 2
Edge added: 1 - 3
Edge added: 1 - 4
Edge added: 2 - 5
Edge added: 3 - 5

Adjacency Matrix:
    0  1  2  3  4  5 
0:  0  1  1  0  0  0 
1:  1  0  0  1  1  0 
2:  1  0  0  0  0  1 
3:  0  1  0  0  0  1 
4:  0  1  0  0  0  0 
5:  0  0  1  1  0  0 

BFS Traversal starting from vertex 0:
Visited: 0
Visited: 1
Visited: 2
Visited: 4
Visited: 3
Visited: 5
BFS Result: [0, 1, 2, 4, 3, 5]

DFS Traversal starting from vertex 0:
Visited: 0
Visited: 1
Visited: 3
Visited: 5
Visited: 2
Visited: 4
DFS Result: [0, 1, 3, 5, 2, 4]
```

## Key Features

- **Undirected Graph**: Edges work in both directions
- **Adjacency Matrix**: Efficient for dense graphs and checking edge existence
- **BFS Implementation**: Uses iterative approach with queue
- **DFS Implementation**: Uses recursive approach for simplicity
- **Memory Management**: Proper allocation and deallocation of resources
- **Input Validation**: Checks for valid vertex indices
- **Comprehensive Testing**: Demonstrates both algorithms with different starting points