#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge with a source, destination, and weight
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a graph with V vertices and E edges
struct Graph
{
    int V, E;
    struct Edge *edge; // Array of edges
};

// Structure to represent a subset for union-find
struct Subset
{
    int parent;
    int rank;
};

// Function to create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph)); // Allocate memory for graph
    graph->V = V;                                                       // Set number of vertices
    graph->E = E;                                                       // Set number of edges
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));       // Allocate memory for edges
    return graph;
}

// Function to find the parent of an element i (using path compression)
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent); // Recursively find the parent and compress the path
    }
    return subsets[i].parent; // Return the root parent
}

// Function to perform union of two subsets by rank
void unionSet(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x); // Find root of x
    int yroot = find(subsets, y); // Find root of y

    // Attach the smaller rank tree under the root of the higher rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot; // If ranks are the same, make one root and increment its rank
        subsets[xroot].rank++;
    }
}

// Comparison function to sort edges based on weight (used in qsort)
int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight > ((struct Edge *)b)->weight;
}

// Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
void kruskalMST(struct Graph *graph)
{
    int V = graph->V;      // Number of vertices in the graph
    struct Edge result[V]; // Array to store the resulting MST edges
    int e = 0;             // Index for result[]
    int i = 0;             // Index for sorted edges

    // Sort all the edges in increasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for creating V subsets (used for union-find)
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Create initial subsets with each vertex being its own parent and rank 0
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Pick the smallest edge and check if it forms a cycle
    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++]; // Get the next edge
        int x = find(subsets, next_edge.src);     // Find the root of src
        int y = find(subsets, next_edge.dest);    // Find the root of dest

        // If including this edge does not cause a cycle, include it in the result
        if (x != y)
        {
            result[e++] = next_edge;
            unionSet(subsets, x, y); // Union the sets
        }
    }

    // Print the edges included in the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; j++)
    {
        printf("%d -- %d == %d\n", result[j].src, result[j].dest, result[j].weight);
    }

    free(subsets); // Free the memory allocated for subsets
}

int main()
{
    int V, E;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Create a graph with V vertices and E edges
    struct Graph *graph = createGraph(V, E);

    // Input the edges: source, destination, and weight
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    // Call Kruskal's algorithm to find the MST
    kruskalMST(graph);

    // Free the allocated memory for the graph
    free(graph->edge);
    free(graph);

    return 0;
}
