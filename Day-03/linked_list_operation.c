#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the linked list
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

struct Node *head = NULL; // Initialize head of the linked list as NULL

// Function declarations
void create(int value);
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAfterNode(int value, int afterValue);
void deleteFromBeginning();
void deleteFromEnd();
void deleteSpecificNode(int value);
void display();

void main()
{
    int choice, value, afterValue;

    while (1)
    { // Infinite loop for the menu-driven program
        printf("\n\n*** LINKED LIST MENU ***\n");
        printf("1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert After Node\n5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n8. Display\n9. Exit");
        printf("\nEnter your choice: "); // Prompt user for choice
        scanf("%d", &choice);

        // Switch case to handle user's choice
        switch (choice)
        {
        case 1: // Create a new node in the linked list
            printf("Enter the value to create a new node: ");
            scanf("%d", &value);
            create(value);
            break;
        case 2: // Insert a node at the beginning
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 3: // Insert a node at the end
            printf("Enter the value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 4: // Insert a node after a specific node
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the value after which to insert: ");
            scanf("%d", &afterValue);
            insertAfterNode(value, afterValue);
            break;
        case 5: // Delete a node from the beginning
            deleteFromBeginning();
            break;
        case 6: // Delete a node from the end
            deleteFromEnd();
            break;
        case 7: // Delete a specific node by value
            printf("Enter the value of the node to delete: ");
            scanf("%d", &value);
            deleteSpecificNode(value);
            break;
        case 8: // Display the linked list
            display();
            break;
        case 9: // Exit the program
            exit(0);
        default: // Handle invalid choice
            printf("\nWrong choice! Please try again.");
        }
    }
}

// Function to create a new node in the linked list
void create(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = value;                                             // Assign data to the new node
    newNode->next = NULL;                                              // New node will be the last node, so set next as NULL

    // If the list is empty, set the new node as the head
    if (head == NULL)
    {
        head = newNode;
        printf("\nNode created successfully!");
    }
    else
    {
        printf("\nLinked List already created!");
    }
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = value;                                             // Assign value to the new node
    newNode->next = head;                                              // Point new node's next to the current head
    head = newNode;                                                    // Update head to point to the new node
    printf("\nNode inserted at beginning!");
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = value;                                             // Assign value to the new node
    newNode->next = NULL;                                              // New node will be the last node, so set next as NULL

    // If the list is empty, set the new node as the head
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        // Traverse to the end of the list
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Set the last node's next to the new node
    }
    printf("\nNode inserted at end!");
}

// Function to insert a node after a specific node in the linked list
void insertAfterNode(int value, int afterValue)
{
    struct Node *temp = head;
    // Traverse the list to find the node with afterValue
    while (temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nNode with value %d not found!", afterValue);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
        newNode->data = value;                                             // Assign value to the new node
        newNode->next = temp->next;                                        // Point new node's next to the node after the found node
        temp->next = newNode;                                              // Insert the new node after the found node
        printf("\nNode inserted after %d!", afterValue);
    }
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("\nList is empty, nothing to delete!");
    }
    else
    {
        struct Node *temp = head; // Temporary node to store the current head
        head = head->next;        // Update head to the next node
        printf("\nDeleted node with value: %d", temp->data);
        free(temp); // Free memory of the deleted node
    }
}

// Function to delete a node from the end of the linked list
void deleteFromEnd()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("\nList is empty, nothing to delete!");
    }
    else if (head->next == NULL)
    { // If the list has only one node
        printf("\nDeleted node with value: %d", head->data);
        free(head);  // Free the single node
        head = NULL; // Set head to NULL as list is now empty
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;

        // Traverse to the end of the list
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL; // Set the second last node's next to NULL
        printf("\nDeleted node with value: %d", temp->data);
        free(temp); // Free memory of the deleted node
    }
}

// Function to delete a specific node by value
void deleteSpecificNode(int value)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("\nList is empty, nothing to delete!");
    }
    else if (head->data == value)
    {                             // If the node to be deleted is the head
        struct Node *temp = head; // Temporary node to store the current head
        head = head->next;        // Update head to the next node
        printf("\nDeleted node with value: %d", temp->data);
        free(temp); // Free memory of the deleted node
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;

        // Traverse the list to find the node with the specified value
        while (temp != NULL && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        // If node with the specified value is not found
        if (temp == NULL)
        {
            printf("\nNode with value %d not found!", value);
        }
        else
        {
            prev->next = temp->next; // Remove the node from the list
            printf("\nDeleted node with value: %d", temp->data);
            free(temp); // Free memory of the deleted node
        }
    }
}

// Function to display the linked list
void display()
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        struct Node *temp = head;
        printf("\nLinked List elements are: ");
        // Traverse the list and print each node's data
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL"); // Mark the end of the list
    }
}
