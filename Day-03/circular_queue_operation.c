#include <stdio.h>
#include <conio.h>

#define SIZE 5 // Define the maximum size of the queue

// Function declarations
void enqueue(int);
void dequeue();
void display();

// Initialize the queue and the front and rear pointers
int queue[SIZE], front = -1, rear = -1;

void main()
{
    int value, choice; // Variables to store user input
    clrscr();          // Clear the screen
    while (1)          // Infinite loop to continuously display the menu
    {
        printf("\n\n*** CIRCULAR QUEUE MENU ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: "); // Prompt the user for a choice
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Case for enqueue operation
            printf("Enter the value to be inserted: ");
            scanf("%d", &value); // Get the value to be inserted into the queue
            enqueue(value);      // Call enqueue function
            break;
        case 2:        // Case for dequeue operation
            dequeue(); // Call dequeue function
            break;
        case 3:        // Case for displaying the queue elements
            display(); // Call display function
            break;
        case 4:      // Case for exiting the program
            exit(0); // Exit the program
        default:
            printf("\nWrong selection!!! Try again!!!"); // Handle invalid choices
        }
    }
}

// Function to insert an element into the circular queue
void enqueue(int value)
{
    // Check if the queue is full
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
        printf("\nQueue is Full!!! Insertion is not possible!!!");
    else
    {
        // If the queue is empty, initialize front and rear
        if (front == -1)
            front = rear = 0;
        // If rear reaches the end of the array but the queue is not full
        else if (rear == SIZE - 1 && front != 0)
            rear = 0;
        else
            rear++; // Increment rear in normal cases

        queue[rear] = value; // Insert the value into the queue
        printf("\nInsertion success!!!");
    }
}

// Function to remove an element from the circular queue
void dequeue()
{
    // Check if the queue is empty
    if (front == -1)
        printf("\nQueue is Empty!!! Deletion is not possible!!!");
    else
    {
        printf("\nDeleted : %d", queue[front]); // Print the deleted value
        // If the queue has only one element, reset front and rear
        if (front == rear)
        {
            front = rear = -1;
        }
        // Move front to the beginning if it reaches the end
        else if (front == SIZE - 1)
            front = 0;
        else
            front++; // Increment front in normal cases
    }
}

// Function to display the elements of the circular queue
void display()
{
    // Check if the queue is empty
    if (front == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        printf("\nQueue elements are:\n");
        // If rear is ahead of or equal to front, print all elements linearly
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        else
        {
            // If the queue wraps around, print from front to end of the array
            for (int i = front; i < SIZE; i++)
                printf("%d ", queue[i]);
            // Print from the beginning of the array to the rear
            for (int i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
    }
}
