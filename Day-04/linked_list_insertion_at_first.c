#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

struct Node *head = NULL; // Initialize the head of the linked list as NULL

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int value)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Assign the value to the new node
    newNode->data = value;

    // Point the new node's next to the current head
    newNode->next = head;

    // Update the head to point to the new node
    head = newNode;

    printf("\nNode with value %d inserted at the beginning!\n", value);
}

// Function to display all nodes in the linked list
void display()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("\nThe list is empty!\n");
    }
    else
    {
        struct Node *temp = head; // Temporary pointer to traverse the list
        printf("\nLinked list elements: ");

        // Traverse the list and print each node's data
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n"); // Indicate the end of the linked list
    }
}

int main()
{
    int value, choice;

    // Menu-driven program to insert nodes and display the list
    while (1)
    {
        printf("\n\n*** LINKED LIST MENU ***\n");
        printf("1. Insert at Beginning\n2. Display\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle the user's choice
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &value);
            insertAtBeginning(value); // Call function to insert the node
            break;
        case 2:
            display(); // Call function to display the list
            break;
        case 3:
            exit(0); // Exit the program
        default:
            printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}
