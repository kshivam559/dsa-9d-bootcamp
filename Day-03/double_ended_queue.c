#include <stdio.h>
#include <conio.h>

#define SIZE 5 // Define the maximum size of the deque

// Function declarations for operations on deque
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
void display();

// Initialize the deque and the front and rear pointers
int deque[SIZE], front = -1, rear = -1;

void main()
{
    int value, choice; // Variables to store user input
    clrscr();          // Clear the screen
    while (1)
    { // Infinite loop to keep showing the menu
        printf("\n\n*** DEQUE MENU ***\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit");
        printf("\nEnter your choice: "); // Ask user for a choice
        scanf("%d", &choice);
        switch (choice)
        {       // Switch based on user choice
        case 1: // Insert element at the front of deque
            printf("Enter the value to be inserted at front: ");
            scanf("%d", &value); // Take the value to be inserted
            insertFront(value);  // Call the insertFront function
            break;
        case 2: // Insert element at the rear of deque
            printf("Enter the value to be inserted at rear: ");
            scanf("%d", &value); // Take the value to be inserted
            insertRear(value);   // Call the insertRear function
            break;
        case 3:            // Delete element from the front of deque
            deleteFront(); // Call the deleteFront function
            break;
        case 4:           // Delete element from the rear of deque
            deleteRear(); // Call the deleteRear function
            break;
        case 5:        // Display all elements in the deque
            display(); // Call the display function
            break;
        case 6:      // Exit the program
            exit(0); // Exit the loop and program
        default:     // Handle invalid choice
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}

// Function to insert an element at the front of the deque
void insertFront(int value)
{
    // Check if the deque is full
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("\nDeque is Full!!! Insertion is not possible!!!");
    else
    {
        // If deque is empty, initialize front and rear
        if (front == -1)
            front = rear = 0;
        // If front is at the start, wrap it to the end of the array
        else if (front == 0)
            front = SIZE - 1;
        else
            front--; // Move front back normally

        deque[front] = value; // Insert the value at the front
        printf("\nInsertion at front success!!!");
    }
}

// Function to insert an element at the rear of the deque
void insertRear(int value)
{
    // Check if the deque is full
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("\nDeque is Full!!! Insertion is not possible!!!");
    else
    {
        // If deque is empty, initialize front and rear
        if (front == -1)
            front = rear = 0;
        // If rear is at the end, wrap it to the start of the array
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++; // Move rear forward normally

        deque[rear] = value; // Insert the value at the rear
        printf("\nInsertion at rear success!!!");
    }
}

// Function to delete an element from the front of the deque
void deleteFront()
{
    // Check if the deque is empty
    if (front == -1)
        printf("\nDeque is Empty!!! Deletion is not possible!!!");
    else
    {
        // Display the deleted value
        printf("\nDeleted from front: %d", deque[front]);
        // If deque has only one element, reset front and rear
        if (front == rear)
            front = rear = -1;
        // If front is at the end, wrap it to the start of the array
        else if (front == SIZE - 1)
            front = 0;
        else
            front++; // Move front forward normally
    }
}

// Function to delete an element from the rear of the deque
void deleteRear()
{
    // Check if the deque is empty
    if (rear == -1)
        printf("\nDeque is Empty!!! Deletion is not possible!!!");
    else
    {
        // Display the deleted value
        printf("\nDeleted from rear: %d", deque[rear]);
        // If deque has only one element, reset front and rear
        if (front == rear)
            front = rear = -1;
        // If rear is at the start, wrap it to the end of the array
        else if (rear == 0)
            rear = SIZE - 1;
        else
            rear--; // Move rear backward normally
    }
}

// Function to display the elements of the deque
void display()
{
    // Check if the deque is empty
    if (front == -1)
        printf("\nDeque is Empty!!!");
    else
    {
        printf("\nDeque elements are:\n");
        // If rear is ahead of front, print linearly
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                printf("%d ", deque[i]);
        }
        else
        { // If deque wraps around, print from front to end and then start to rear
            for (int i = front; i < SIZE; i++)
                printf("%d ", deque[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", deque[i]);
        }
    }
}
