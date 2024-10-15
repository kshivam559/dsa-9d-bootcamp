#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Define the maximum size of the queue
#define MAX_FLOORS 10      // Define the number of floors in the building

// Queue structure to store the floor requests
struct Queue
{
    int floors[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue *q)
{
    return (q->front == -1);
}

// Function to check if the queue is full
int isQueueFull(struct Queue *q)
{
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

// Function to enqueue (add) a floor request
void enqueue(struct Queue *q, int floor)
{
    if (isQueueFull(q))
    {
        printf("Queue is full! Cannot add more floor requests.\n");
        return;
    }
    if (q->front == -1)
        q->front = 0; // Set front to 0 if it's the first element
    q->rear++;
    q->floors[q->rear] = floor;
}

// Function to dequeue (remove) a floor request
int dequeue(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty! No requests to process.\n");
        return -1; // Return -1 if queue is empty
    }
    int floor = q->floors[q->front];
    if (q->front == q->rear)
    {
        // Queue becomes empty after this dequeue
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return floor;
}

// Function to move the lift to a requested floor
void moveLift(int currentFloor, int targetFloor)
{
    if (targetFloor > currentFloor)
    {
        printf("Moving up from floor %d to floor %d\n", currentFloor, targetFloor);
        for (int i = currentFloor + 1; i <= targetFloor; i++)
        {
            printf("Floor %d...\n", i);
        }
    }
    else if (targetFloor < currentFloor)
    {
        printf("Moving down from floor %d to floor %d\n", currentFloor, targetFloor);
        for (int i = currentFloor - 1; i >= targetFloor; i--)
        {
            printf("Floor %d...\n", i);
        }
    }
    else
    {
        printf("You are already on floor %d!\n", currentFloor);
    }
}

int main()
{
    struct Queue liftQueue; // Create a queue to manage floor requests
    initializeQueue(&liftQueue);

    int currentFloor = 0; // Lift starts at ground floor (floor 0)
    int targetFloor;
    int choice;

    printf("Welcome to Lift Management System!\n");

    do
    {
        printf("\nYou are currently on floor %d\n", currentFloor);
        printf("1. Request Lift to a Floor\n");
        printf("2. Process Lift Requests\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the floor you want to go to (0 to %d): ", MAX_FLOORS - 1);
            scanf("%d", &targetFloor);
            if (targetFloor >= 0 && targetFloor < MAX_FLOORS)
            {
                enqueue(&liftQueue, targetFloor); // Add the request to the queue
                printf("Floor %d request added to the queue.\n", targetFloor);
            }
            else
            {
                printf("Invalid floor! Please enter a floor between 0 and %d.\n", MAX_FLOORS - 1);
            }
            break;

        case 2:
            if (!isQueueEmpty(&liftQueue))
            {
                // Process each floor request in the queue
                while (!isQueueEmpty(&liftQueue))
                {
                    targetFloor = dequeue(&liftQueue); // Get the next floor request from the queue
                    moveLift(currentFloor, targetFloor);
                    currentFloor = targetFloor; // Update the current floor after moving
                }
                printf("All requests have been processed.\n");
            }
            else
            {
                printf("No floor requests to process.\n");
            }
            break;

        case 3:
            printf("Exiting Lift Management System. Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
