#include <stdio.h>
#include <limits.h>

#define MAX 100     // Maximum number of vertices
#define INF INT_MAX // Infinity value to represent unreachable distances

// Function to find the vertex with the minimum distance value from the set of vertices that haven't been visited yet
int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index;

    // Traverse all vertices to find the minimum distance vertex
    for (int v = 0; v < n; v++)
    {
        // If the vertex is not visited and has a smaller distance, update min
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index; // Return the index of the vertex with the minimum distance
}

// Function to implement Dijkstra's algorithm for finding the shortest paths from the source vertex to all other vertices
void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX];    // Array to hold the shortest distances from the source to each vertex
    int visited[MAX]; // Array to track visited vertices

    // Initialize all distances as infinity and all vertices as unvisited
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance of the source vertex to itself is always 0
    dist[src] = 0;

    // Loop over all vertices to find the shortest path
    for (int count = 0; count < n - 1; count++)
    {
        // Select the vertex with the minimum distance that hasn't been visited yet
        int u = minDistance(dist, visited, n);

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update the distance values of the adjacent vertices of the selected vertex
        for (int v = 0; v < n; v++)
        {
            // Update the distance only if the vertex hasn't been visited, there's an edge, and the new distance is shorter
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the calculated shortest distances from the source vertex
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[MAX][MAX], n, src;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix of the graph
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the source vertex from where the shortest path should be calculated
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Call the Dijkstra function to find and display the shortest paths from the source vertex
    dijkstra(graph, n, src);

    return 0;
}
