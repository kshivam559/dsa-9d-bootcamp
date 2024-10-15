#include <stdio.h>
#include <conio.h>

#define MAXSIZE 10

int queue[MAXSIZE]; // Define the queue array
int front = 0;      // Initialize front to 0
int rear = -1;      // Initialize rear to -1

void insert();  // Function prototype for insert
void delete();  // Function prototype for delete
void display(); // Function prototype for display

void main()
{
    int choice;
    clrscr(); // Clear screen (optional, non-standard function; replace if necessary)

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit"); // Display menu
        printf("\nEnter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        switch (choice)
        {
        case 1:
            insert(); // Call insert function
            break;
        case 2:
            delete (); // Call delete function
            break;
        case 3:
            display(); // Call display function
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4); // Loop until the user chooses to exit

    getch(); // Wait for key press (optional in modern compilers)
}

// Function to insert an element into the queue
void insert()
{
    int value;
    if (rear == MAXSIZE - 1)
    { // Check if the queue is full
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the value to insert: ");
        scanf("%d", &value); // Read the value to insert
        rear++;              // Increment the rear index
        queue[rear] = value; // Insert the value at the rear of the queue
    }
}

// Function to delete an element from the queue
void delete()
{
    if (front > rear)
    { // Check if the queue is empty
        printf("Queue Underflow\n");
        front = 0; // Reset front and rear to initial state
        rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]); // Display the deleted element
        front++;                                       // Increment the front index
    }
}

// Function to display the elements in the queue
void display()
{
    if (front > rear)
    { // Check if the queue is empty
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = rear; i >= front; i--)
        {
            printf("%d ", queue[i]); // Display each element
        }
        printf("\n");
    }
}
