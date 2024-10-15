#include <stdio.h>
#include <conio.h>

#define MAXSIZE 10

int stack[MAXSIZE]; // Define the stack array
int top = -1;       // Initialize top to -1

void push(); // Declare function prototypes
void pop();
void display();

int main() // Fix the return type for main function
{
    int choice; // Remove parentheses after choice
    clrscr();   // Clear the screen (Note: clrscr() is non-standard; may need to replace)

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n"); // Fix formatting in printf
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the choice input

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4); // Loop until user chooses to exit

    getch();  // Wait for a key press
    return 0; // Return from main function
}

// Function to push an element onto the stack
void push()
{
    int n;
    if (top == MAXSIZE - 1)
    {
        printf("Stack Overflow\n"); // Check if the stack is full (overflow condition)
    }
    else
    {
        printf("Enter an element: ");
        scanf("%d", &n); // Get the element from user
        top++;           // Increment the top index
        stack[top] = n;  // Add the element to the stack
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n"); // Check if the stack is empty (underflow condition)
    }
    else
    {
        printf("Popped element: %d\n", stack[top]); // Display the popped element
        top--;                                      // Decrease the top index
    }
}

// Function to display the elements of the stack
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n"); // Check if the stack is empty
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]); // Print each element from top to bottom
        }
    }
}
