#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100 // Define the maximum number of vertices in the graph

// Define the structure for a Graph
struct Graph
{
    int adj[MAX][MAX]; // Adjacency matrix to store edges and weights between vertices
    int n;             // Number of vertices in the graph
};

// Function to initialize the graph with a given number of vertices
void initGraph(struct Graph *g, int vertices)
{
    g->n = vertices; // Set the number of vertices
    // Initialize the adjacency matrix with 0 (no edges)
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g->adj[i][j] = 0;
        }
    }
}

// Function to insert an edge between two vertices u and v with a given weight
void insertEdge(struct Graph *g, int u, int v, int weight)
{
    g->adj[u][v] = weight; // Insert edge from u to v with weight
    g->adj[v][u] = weight; // Since it's an undirected graph, insert edge from v to u as well
}

// Function to delete an edge between two vertices u and v
void deleteEdge(struct Graph *g, int u, int v)
{
    g->adj[u][v] = 0; // Set the adjacency matrix entry to 0 (no edge)
    g->adj[v][u] = 0; // Remove the reverse edge as well
}

// Function to search for an edge between two vertices u and v
int searchEdge(struct Graph *g, int u, int v)
{
    return g->adj[u][v]; // Return the weight if there's an edge, otherwise 0
}

// Function to perform Breadth-First Search (BFS) from a starting vertex
void BFS(struct Graph *g, int start)
{
    int visited[MAX] = {0};               // Array to keep track of visited vertices
    int queue[MAX], front = 0, rear = -1; // Queue for BFS traversal
    queue[++rear] = start;                // Enqueue the starting vertex
    visited[start] = 1;                   // Mark the starting vertex as visited

    // BFS traversal
    while (front <= rear)
    {
        int v = queue[front++]; // Dequeue the vertex
        printf("%d ", v);       // Print the vertex

        // Explore all adjacent vertices of the current vertex
        for (int i = 0; i < g->n; i++)
        {
            if (g->adj[v][i] && !visited[i])
            {                      // If there's an edge and the vertex is not visited
                queue[++rear] = i; // Enqueue the adjacent vertex
                visited[i] = 1;    // Mark it as visited
            }
        }
    }
}

// Helper function for Depth-First Search (DFS)
void DFSUtil(struct Graph *g, int v, int visited[])
{
    visited[v] = 1;   // Mark the current vertex as visited
    printf("%d ", v); // Print the vertex

    // Explore all adjacent vertices of the current vertex
    for (int i = 0; i < g->n; i++)
    {
        if (g->adj[v][i] && !visited[i])
        {
            DFSUtil(g, i, visited); // Recursively visit unvisited adjacent vertices
        }
    }
}

// Function to perform Depth-First Search (DFS) from a starting vertex
void DFS(struct Graph *g, int start)
{
    int visited[MAX] = {0};     // Array to keep track of visited vertices
    DFSUtil(g, start, visited); // Start DFS traversal
}

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(struct Graph *g, int src)
{
    int dist[MAX], visited[MAX]; // Arrays for distances and visited vertices

    // Initialize distances as infinite and visited array as false
    for (int i = 0; i < g->n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0; // Distance to the source vertex is 0

    // Loop to find the shortest path for all vertices
    for (int count = 0; count < g->n - 1; count++)
    {
        int min = INT_MAX, u;

        // Find the vertex with the minimum distance that hasn't been visited yet
        for (int v = 0; v < g->n; v++)
        {
            if (!visited[v] && dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1; // Mark the chosen vertex as visited

        // Update the distance values of adjacent vertices
        for (int v = 0; v < g->n; v++)
        {
            if (!visited[v] && g->adj[u][v] && dist[u] != INT_MAX && dist[u] + g->adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    // Print the result of the shortest paths from the source vertex
    printf("Vertex Distance from Source %d:\n", src);
    for (int i = 0; i < g->n; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main()
{
    struct Graph g;                     // Graph structure
    int vertices, choice, u, v, weight; // Variables for vertices, choices, and weights

    // Input the number of vertices in the graph
    printf("Enter number of vertices in the graph: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices); // Initialize the graph with the specified number of vertices

    // Menu-driven loop for graph operations
    while (1)
    {
        // Display the menu
        printf("\n*** GRAPH MENU ***\n");
        printf("1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. BFS\n5. DFS\n6. Dijkstra's Shortest Path\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice)
        {
        case 1:
            printf("Enter the vertices (u, v) and weight to insert an edge: ");
            scanf("%d %d %d", &u, &v, &weight);
            insertEdge(&g, u, v, weight); // Insert an edge with weight between vertices u and v
            break;
        case 2:
            printf("Enter the vertices (u, v) to delete an edge: ");
            scanf("%d %d", &u, &v);
            deleteEdge(&g, u, v); // Delete the edge between vertices u and v
            break;
        case 3:
            printf("Enter the vertices (u, v) to search for an edge: ");
            scanf("%d %d", &u, &v);
            if (searchEdge(&g, u, v))
            {
                printf("Edge exists between %d and %d\n", u, v); // Edge found
            }
            else
            {
                printf("Edge does not exist between %d and %d\n", u, v); // Edge not found
            }
            break;
        case 4:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &u);
            printf("BFS traversal: ");
            BFS(&g, u); // Perform BFS traversal starting from vertex u
            printf("\n");
            break;
        case 5:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &u);
            printf("DFS traversal: ");
            DFS(&g, u); // Perform DFS traversal starting from vertex u
            printf("\n");
            break;
        case 6:
            printf("Enter source vertex for Dijkstra's shortest path: ");
            scanf("%d", &u);
            dijkstra(&g, u); // Perform Dijkstra's algorithm starting from vertex u
            break;
        case 7:
            exit(0); // Exit the program
        default:
            printf("Invalid choice! Try again.\n"); // Handle invalid input
        }
    }

    return 0;
}
