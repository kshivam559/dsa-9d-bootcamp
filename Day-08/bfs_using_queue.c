#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum number of vertices in the graph

// Structure to represent a Queue for BFS
struct Queue
{
    int items[MAX]; // Array to store the queue elements
    int front;      // Front index of the queue
    int rear;       // Rear index of the queue
};

// Function to create a new queue and initialize front and rear
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue)); // Allocate memory for the queue
    q->front = -1;                                                  // Initialize front index as -1 (queue is empty)
    q->rear = -1;                                                   // Initialize rear index as -1 (queue is empty)
    return q;                                                       // Return the created queue
}

// Function to check if the queue is full
int isFull(struct Queue *q)
{
    return q->rear == MAX - 1; // Queue is full if rear reaches the maximum size
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == -1 || q->front > q->rear; // Queue is empty if front is -1 or front has passed rear
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    { // Check if the queue is full
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
    { // If queue is initially empty, set front to 0
        q->front = 0;
    }
    q->rear++;                 // Increment rear to point to the next empty position
    q->items[q->rear] = value; // Insert the new value at the rear of the queue
}

// Function to remove an element from the queue
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    { // Check if the queue is empty
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front]; // Get the value at the front of the queue
    q->front++;                    // Move the front pointer to the next element
    return item;                   // Return the dequeued value
}

// Function to perform Breadth-First Search (BFS) traversal of a graph
void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n)
{
    struct Queue *q = createQueue(); // Create a new queue for BFS
    enqueue(q, start);               // Enqueue the starting vertex
    visited[start] = 1;              // Mark the starting vertex as visited

    // Continue BFS traversal until the queue is empty
    while (!isEmpty(q))
    {
        int current = dequeue(q); // Dequeue the current vertex
        printf("%d ", current);   // Print the current vertex

        // Check all adjacent vertices of the current vertex
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {                   // If there is an edge and vertex is not visited
                enqueue(q, i);  // Enqueue the adjacent vertex
                visited[i] = 1; // Mark the adjacent vertex as visited
            }
        }
    }
    free(q); // Free the allocated memory for the queue
}

int main()
{
    int n, start;                            // Variables for number of vertices and starting vertex
    int graph[MAX][MAX], visited[MAX] = {0}; // Adjacency matrix and visited array

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix for the graph
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]); // Fill the adjacency matrix
        }
    }

    // Input the starting vertex for BFS traversal
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    // Perform BFS traversal starting from the given vertex
    printf("BFS traversal starting from vertex %d: ", start);
    bfs(graph, visited, start, n); // Call BFS function
    printf("\n");

    return 0;
}
