#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

struct Node *head = NULL; // Initialize the head of the linked list as NULL

// Function to insert a new node at the end of the linked list
void insertAtEnd(int value)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Assign the value to the new node and set its next pointer to NULL (since it will be the last node)
    newNode->data = value;
    newNode->next = NULL;

    // Check if the list is empty
    if (head == NULL)
    {
        // If empty, make the new node the head
        head = newNode;
    }
    else
    {
        // Traverse to the last node
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Set the next of the last node to the new node
        temp->next = newNode;
    }
    printf("\nNode with value %d inserted at the end!\n", value);
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
        printf("1. Insert at End\n2. Display\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle the user's choice
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(value); // Call function to insert the node at end
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
