#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node for the stack
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

struct Node *top = NULL; // Initialize the top of the stack as NULL (stack is empty)

// Function to push a new value onto the stack
void push(int value)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation failed (stack overflow)
    if (newNode == NULL)
    {
        printf("\nStack Overflow!"); // Stack is full, no more insertions
        return;
    }

    // Assign value to the new node and set it as the new top of the stack
    newNode->data = value;
    newNode->next = top;            // Point the new node's next to the current top
    top = newNode;                  // Update the top to the new node
    printf("\nInserted %d", value); // Notify that value is inserted
}

// Function to pop a value from the stack
void pop()
{
    // Check if the stack is empty (stack underflow)
    if (top == NULL)
    {
        printf("\nStack Underflow!"); // Stack is empty, nothing to pop
        return;
    }

    // Store the top node temporarily and update the top to the next node
    struct Node *temp = top;
    printf("\nPopped %d", top->data); // Notify that value is popped
    top = top->next;                  // Move the top to the next node
    free(temp);                       // Free the memory of the popped node
}

// Function to display all elements in the stack
void display()
{
    // Check if the stack is empty
    if (top == NULL)
    {
        printf("\nStack is Empty!"); // No elements to display
        return;
    }

    // Traverse the stack from the top and print all elements
    struct Node *temp = top;
    printf("\nStack elements are:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data); // Print the data of each node
        temp = temp->next;          // Move to the next node
    }
}

// Main function to provide a menu-driven interface for the stack operations
void main()
{
    int choice, value;

    // Infinite loop to continuously show menu and process user's input
    while (1)
    {
        printf("\n\n*** STACK MENU ***\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user's choice
        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value); // Call function to push value onto stack
            break;
        case 2:
            pop(); // Call function to pop value from stack
            break;
        case 3:
            display(); // Call function to display stack elements
            break;
        case 4:
            exit(0); // Exit the program
        default:
            printf("\nInvalid choice! Try again."); // Handle wrong input
        }
    }
}
